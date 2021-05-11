#include "PRTCEngineImpl.h"
#include "PRTCConfig.h"
#include "windows.h"

//#define PUSH_MODE 1
//#define SEI_ONLY 1

PRTCEngineImpl::PRTCEngineImpl()
{
	m_eventhandler = new PRTCEventHandler;
}

PRTCEngineImpl::~PRTCEngineImpl()
{
	UnInitRTCEngine();
}

int PRTCEngineImpl::InitRTCEngine(void* callback)
{
	m_eventhandler->initEventHandler(callback);
    tPRTCInitContext context;
	SYSTEMTIME m_time;
	GetLocalTime(&m_time);
	char szDateTime[30] = { 0 };
	sprintf(szDateTime, "%02d%02d%02d%02d%02d%02d", m_time.wYear, m_time.wMonth,
		m_time.wDay, m_time.wHour, m_time.wMinute, m_time.wSecond);
	std::string time(szDateTime);

	context.mLogPath = "./";
	context.mLogName = time.data();
	context.mMaxReconnect = 999;
	context.mLogLevel = PRTC_LOG_LEVEL_INFO;
	context.mIsInline = true;
	m_rtcengine = IPRTCEngine::sharedInstance(&context);
	m_rtcengine->regRtcEventListener(m_eventhandler);
	m_rtcengine->setChannelType(PRTCConfig::getInstance()->getChannelType());
	m_rtcengine->setStreamRole(PRTCConfig::getInstance()->getStreamRole());
	m_rtcengine->setTokenSecKey(PRTCConfig::getInstance()->getSecKey().data());
	m_rtcengine->setAudioOnlyMode(PRTCConfig::getInstance()->isAudioOnly());
	m_rtcengine->setAutoPublishSubscribe(PRTCConfig::getInstance()->isAutoPublish(), 
		PRTCConfig::getInstance()->isAutoSubscribe());
	m_rtcengine->configLocalAudioPublish(PRTCConfig::getInstance()->isAutoPubAudio());
	m_rtcengine->configLocalCameraPublish(PRTCConfig::getInstance()->isAutoPubVideo());
	m_rtcengine->configLocalScreenPublish(PRTCConfig::getInstance()->isAutoPubScreen());
	tPRTCVideoConfig videoconfig;
	videoconfig.mWidth = 720;
	videoconfig.mHeight = 480;
	videoconfig.mFrameRate = 20;
    videoconfig.mBitrate = 1000;
	m_rtcengine->setVideoProfile(PRTC_VIDEO_PROFILE_NONE, videoconfig);
	m_rtcengine->setDesktopProfile(PRTC_SCREEN_PROFILE_HIGH_PLUS);
	m_rtcengine->setSdkMode(PRTCConfig::getInstance()->getSdkMode());
    m_rtcengine->setVideoCodec(PRTCConfig::getInstance()->getCodecType());
    enableExtendAudiocapture(true, nullptr);

	return 0;
}

int PRTCEngineImpl::UnInitRTCEngine()
{
#ifdef PUSH_MODE
    stop_push_thread_ = true;
    if (push_thread_.joinable())
        push_thread_.join();
#endif // PUSH_MODE

	if (m_rtcengine)
	{
		m_rtcengine->destroy();
		m_rtcengine = nullptr;
	}

	if (m_eventhandler)
	{
		delete m_eventhandler;
		m_eventhandler = nullptr;
	}
	return 0;
}

std::string PRTCEngineImpl::getSdkVersion()
{
	if (m_rtcengine)
	{
		return m_rtcengine->getSdkVersion();
	}
	return "";
}

void PRTCEngineImpl::RegDeviceChangeCallback(PRTCDeviceChanged* callback)
{
	m_rtcengine->regDeviceChangeCallback(callback);
}

int PRTCEngineImpl::EnableRtspSource(int mediatype, bool enable, std::string rtspurl)
{
	if (m_rtcengine)
	{
		return m_rtcengine->enableExtendRtspVideocapture((ePRTCMeidaType)mediatype,
			enable, rtspurl.data());
	}
	return -1;
}

int PRTCEngineImpl::JoinRoom(tRTCAuthInfo& auth)
{
	if (m_rtcengine)
	{
		tPRTCAuth uauth;
		uauth.mAppId = auth.mAppid.data();
		uauth.mUserId = auth.mUserid.data();
		uauth.mRoomId = auth.mRoomid.data();
		uauth.mUserToken = auth.mToken.data();
		return m_rtcengine->joinChannel(uauth);
	}
	return -1;
}

int PRTCEngineImpl::LeaveRoom(std::string& roomid)
{
	if (m_rtcengine)
	{
		return m_rtcengine->leaveChannel();
	}
	return -1;
}

int PRTCEngineImpl::SetCodecType(int codec)
{
	if (m_rtcengine)
	{
		return m_rtcengine->setVideoCodec((ePRTCVideoCodec)codec);
	}
	return -1;
}

int PRTCEngineImpl::MuteCamBeforeJoin(bool mute)
{
	if (m_rtcengine)
	{
		return m_rtcengine->muteCamBeforeJoin(mute);
	}
	return -1;
}

int PRTCEngineImpl::MuteMicBeforeJoin(bool mute)
{
	if (m_rtcengine)
	{
		return m_rtcengine->muteMicBeforeJoin(mute);
	}
	return -1;
}

int PRTCEngineImpl::enableExtendVideoSource(bool enable, PRTCExtendVideoCaptureSource* source)
{
	if (m_rtcengine)
	{
		return m_rtcengine->enableExtendVideocapture(enable, source);
	}
	return -1;
}

int PRTCEngineImpl::enableExtendAudiocapture(bool enable, PRTCExtendAudioCaptureSource* source)
{
	if (m_rtcengine)
	{
		return m_rtcengine->enableExtendAudiocapture(enable, source);
	}
	return -1;
}

int PRTCEngineImpl::PublishStream(tRTCStreamInfo& streaminfo)
{
	if (m_rtcengine)
	{
#ifdef PUSH_MODE 
#ifndef SEI_ONLY
        m_rtcengine->enableExtendVideocapture(true, nullptr);
        m_rtcengine->enableExtendAudiocapture(true, nullptr);
        m_rtcengine->SetExtendMediaDataMode(PRTC_EMDM_PUSH);
#endif //SEI_ONLY
        stop_push_thread_ = false;
        if (!push_thread_.joinable())
            push_thread_ = std::thread(&PRTCEngineImpl::PushDataProc, this);
#endif // PUSH_MODE

		return m_rtcengine->publish((ePRTCMeidaType)streaminfo.mStreamMtype, streaminfo.mEnableVideo, streaminfo.mEnableAudio);
	}
	return -1;
}
int PRTCEngineImpl::UnPublishStream(tRTCStreamInfo& streaminfo)
{
	if (m_rtcengine)
	{
#ifdef PUSH_MODE
        stop_push_thread_ = true;
        if (push_thread_.joinable())
            push_thread_.join();
#endif // PUSH_MODE
		return m_rtcengine->unPublish((ePRTCMeidaType)streaminfo.mStreamMtype);
	}
	return -1;
}
int PRTCEngineImpl::StartLocalRender(tRTCRenderView& renderview)
{
	if (m_rtcengine)
	{
		tPRTCVideoCanvas canvas;
		canvas.mUserId = renderview.mUserid.data();
		canvas.mStreamMtype = (ePRTCMeidaType)renderview.mStreamMtype;
		canvas.mRenderMode = PRTC_RENDER_MODE_FIT;
		canvas.mVideoView = renderview.mVidoview;
		canvas.mRenderType = (ePRTCRenderType)renderview.mRenderType;
		return m_rtcengine->startPreview(canvas);
	}
	return -1;
}
int PRTCEngineImpl::StopLocalRender(tRTCRenderView& renderview)
{
	if (m_rtcengine)
	{
		tPRTCVideoCanvas canvas;
		canvas.mStreamMtype = (ePRTCMeidaType)renderview.mStreamMtype;
		return m_rtcengine->stopPreview(canvas);
	}
	return -1;
}
int PRTCEngineImpl::MuteLocalCamVideo(tRTCStreamMute& mute)
{
	if (m_rtcengine)
	{
		return m_rtcengine->muteLocalVideo(mute.mMute, PRTC_MEDIATYPE_VIDEO);
	}
	return -1;
}
int PRTCEngineImpl::MuteLocalCamAudio(tRTCStreamMute& mute)
{
	if (m_rtcengine)
	{
		return m_rtcengine->muteLocalMic(mute.mMute);
	}
	return -1;
}

int PRTCEngineImpl::MuteLocalScreenAudio(tRTCStreamMute& mute) {
	if (m_rtcengine)
	{
		return m_rtcengine->muteLocalMic(mute.mMute, PRTC_MEDIATYPE_SCREEN);
	}
	return -1;
}

int PRTCEngineImpl::MuteLocalScreen(tRTCStreamMute& mute)
{
	if (m_rtcengine)
	{
		return m_rtcengine->muteLocalVideo(mute.mMute, PRTC_MEDIATYPE_SCREEN);
	}
	return -1;
}

int PRTCEngineImpl::SubRemoteStream(tRTCStreamInfo& streaminfo)
{
	if (m_rtcengine)
	{
		tPRTCStreamInfo info;
		info.mUserId = streaminfo.mUserid.data();
		info.mStreamMtype = (ePRTCMeidaType)streaminfo.mStreamMtype;
		info.mEnableVideo = streaminfo.mEnableVideo;
		info.mEnableAudio = streaminfo.mEnableAudio;
		info.mEnableData = false;
		return m_rtcengine->subscribe(info);
	}
	return -1;
}
int PRTCEngineImpl::UnSubRemoteStream(tRTCStreamInfo& streaminfo)
{
	if (m_rtcengine)
	{
		tPRTCStreamInfo info;
		info.mUserId = streaminfo.mUserid.data();
		info.mStreamMtype = (ePRTCMeidaType)streaminfo.mStreamMtype;
		info.mEnableVideo = streaminfo.mEnableVideo;
		info.mEnableAudio = streaminfo.mEnableAudio;
		info.mEnableData = false;
		return m_rtcengine->unSubscribe(info);
	}
	return -1;
}
int PRTCEngineImpl::StartRemoteRender(tRTCRenderView& renderview)
{
	if (m_rtcengine)
	{
		tPRTCVideoCanvas canvas;
		canvas.mUserId = renderview.mUserid.data();
		canvas.mStreamMtype = (ePRTCMeidaType)renderview.mStreamMtype;
		canvas.mRenderMode = PRTC_RENDER_MODE_FIT;
		canvas.mVideoView = renderview.mVidoview;
		canvas.mRenderType = (ePRTCRenderType)renderview.mRenderType;
		return m_rtcengine->startRemoteView(canvas);
	}
	return -1;
}
int PRTCEngineImpl::StopRemoteRender(tRTCRenderView& renderview) 
{
	if (m_rtcengine)
	{
		tPRTCVideoCanvas canvas;
		canvas.mUserId = renderview.mUserid.data();
		canvas.mStreamMtype = (ePRTCMeidaType)renderview.mStreamMtype;
		canvas.mRenderMode = PRTC_RENDER_MODE_FIT;
		canvas.mVideoView = renderview.mVidoview;
		return m_rtcengine->stopRemoteView(canvas);
	}
	return -1;
}
int PRTCEngineImpl::MuteRemoteCamVideo(tRTCStreamMute& mute)
{
	if (m_rtcengine)
	{
		tPRTCMuteSt mutest;
		mutest.mMute = mute.mMute;
		mutest.mUserId = mute.mUserid.data();
		mutest.mStreamMtype = PRTC_MEDIATYPE_VIDEO;
		return m_rtcengine->muteRemoteVideo(mutest, mute.mMute);
	}
	return -1;
}

int PRTCEngineImpl::MuteRemoteCamAudio(tRTCStreamMute& mute)
{
	if (m_rtcengine)
	{
		tPRTCMuteSt mutest;
		mutest.mMute = mute.mMute;
		mutest.mUserId = mute.mUserid.data();
		mutest.mStreamMtype = PRTC_MEDIATYPE_VIDEO;
		return m_rtcengine->muteRemoteAudio(mutest, mute.mMute);
	}
	return -1;
}

int PRTCEngineImpl::MuteRemoteScreen(tRTCStreamMute& mute)
{
	if (m_rtcengine)
	{
		tPRTCMuteSt mutest;
		mutest.mMute = mute.mMute;
		mutest.mUserId = mute.mUserid.data();
		mutest.mStreamMtype = PRTC_MEDIATYPE_SCREEN;
		return m_rtcengine->muteRemoteVideo(mutest, mute.mMute);
	}
	return -1;
}

int PRTCEngineImpl::StartRecord(tRecordConfig& config)
{
	if (m_rtcengine)
	{
		tPRTCRecordConfig uconfig;
		uconfig.mMainviewmediatype = (ePRTCMeidaType)config.mMainviewmediatype;
		uconfig.mMainviewuid = config.mMainviewuid;
		uconfig.mProfile = (ePRTCRecordProfile)config.mProfile;
		uconfig.mRecordType = (ePRTCRecordType)config.mRecordType;
		uconfig.mWatermarkPos = (ePRTCWaterMarkPos)config.mWatermarkPos;
		uconfig.mBucket = "urtc-test";
		uconfig.mBucketRegion = "cn-bj";

		uconfig.mWaterMarkType = PRTC_WATERMARK_TYPE_TIME;
		uconfig.mWatermarkUrl = "";
		uconfig.mIsaverage = false;
		uconfig.mMixerTemplateType = 9;
		return m_rtcengine->startRecord(uconfig);
	}
	return -1;
}

int PRTCEngineImpl::StopRecord()
{
	if (m_rtcengine)
	{
		return m_rtcengine->stopRecord();
	}
	return -1;
}

int PRTCEngineImpl::StartMixFile(const char* filepath, bool replace, bool loop, float musicvol)
{
	if (m_rtcengine)
	{
		return m_rtcengine->startAudioMixing(filepath, replace, loop, musicvol);
	}
	return -1;
}

int PRTCEngineImpl::StopMixFile()
{
	if (m_rtcengine)
	{
		return m_rtcengine->stopAudioMixing();
	}
	return -1;
}

int PRTCEngineImpl::StartPushCDN(const char* url, tPRTCTranscodeConfig *config)
{
	if (m_rtcengine)
	{
		m_rtcengine->addPublishStreamUrl(url, config);
	}
	return -1;
}

int PRTCEngineImpl::UpdatePushCDN(const char* url, tPRTCTranscodeConfig *config) {
    if (m_rtcengine)
    {
        m_rtcengine->updateTranscodeConfig(url, config);
    }
    return -1;
}

int PRTCEngineImpl::StopPushCDN(const char* url)
{
	if (m_rtcengine)
	{
		return m_rtcengine->removePublishStreamUrl(url);
	}
	return -1;
}

int  PRTCEngineImpl::SetStreamRole(int role)
{
	if (m_rtcengine)
	{
		return m_rtcengine->setStreamRole((ePRTCUserStreamRole)role);
	}
	return -1;
 }

void PRTCEngineImpl::SetVideoProfile(ePRTCVideoProfile profile) {
    if (m_rtcengine)
    {
        tPRTCVideoConfig config;
        m_rtcengine->setVideoProfile(profile, config);
    }
}

int PRTCEngineImpl::setAudioProfile(ePRTCAudioProfile audio_profile) {
    if (m_rtcengine)
    {
       return  m_rtcengine->setAudioProfile(audio_profile);
    }
    return -1;
}

int PRTCEngineImpl::switchSpeaker(tPRTCDeviceInfo& info) {
    if (m_rtcengine)
    {
        return  m_rtcengine->switchSpeaker(info);
    }
    return -1;
}

void DA(const char* strOutputString, ...)
{
    char strBuffer[4000] = { 0 };
    va_list vlArgs;
    va_start(vlArgs, strOutputString);
    _vsnprintf_s(strBuffer, sizeof(strBuffer) - 1, strOutputString, vlArgs);
    va_end(vlArgs);

    char outbuffer[4096] = { 0 };
    sprintf(outbuffer, "time:%d threadid:%d %s\r\n", GetTickCount(), GetCurrentThreadId(), strBuffer);
    OutputDebugStringA((outbuffer));
}

void   PRTCEngineImpl::PushDataProc() {
    if (m_rtcengine == nullptr) return;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

#ifndef SEI_ONLY
    FILE *video_file = fopen("d:\\video_640_360_420.yuv", "rb");
    FILE *audio_file = fopen("d:\\lm.pcm", "rb");
    if (!video_file || !audio_file) return;

    uint32_t deliver_sample_size = 480;
    uint32_t read_audio_size = deliver_sample_size * 2 * 2;
    uint32_t read_video_size = 640 * 360 * 3 / 2;
    uint8_t *video_buf = new uint8_t[read_video_size];
    uint8_t *audio_buf = new uint8_t[read_audio_size];
#endif // SEI_ONLY
    uint32_t pre_audio_time = 0;
    uint32_t pre_video_time = 0;
    uint32_t pre_sei_time = 0;

    //uint32_t video_intervel = 40;
    uint32_t audio_intervel = 1;
    uint32_t sei_intervel = 1000;

    while (m_rtcengine && !stop_push_thread_) {
        uint32_t current_time = GetTickCount();
#ifndef SEI_ONLY
        if ((current_time - pre_audio_time) >= audio_intervel) {
            for (int i = 0; i < 2; i++) {
                auto size = fread(audio_buf, 1, read_audio_size, audio_file);
                if (size != read_audio_size) {
                    fseek(audio_file, 0, SEEK_SET);
                    fread(audio_buf, 1, read_audio_size, audio_file);
                }

                //DA("AAAAAA cur: %d  pre_audio_time : %d  diff : %d ", current_time, pre_audio_time, current_time - pre_audio_time);
                tPRTCAudioFrame audio_frame;
                audio_frame.mAudioData = audio_buf;
                audio_frame.mChannels = 2;
                audio_frame.mNumSimples = deliver_sample_size;
                audio_frame.mBytePerSimple = 4;
                audio_frame.mSimpleRate = 48000;
                audio_frame.renderTimeMs = 0;
                m_rtcengine->pushAudioFrameData(&audio_frame);
            }
            pre_audio_time = current_time;
        } else if ((current_time - pre_video_time) >= video_intervel) {
            //DA("VVVVVV cur: %d  pre_video_time : %d  diff : %d ", current_time, pre_video_time, current_time - pre_video_time);
            pre_video_time = current_time;
            auto size = fread(video_buf, 1, read_video_size, video_file);
            if (size != read_video_size) {
                fseek(video_file, 0, SEEK_SET);
                fread(video_buf, 1, read_video_size, video_file);
            }
            tPRTCVideoFrame video_frame;
            video_frame.mDataBuf = video_buf;
            video_frame.mHeight = 360;
            video_frame.mWidth = 640;
            video_frame.mVideoType = PRTC_VIDEO_FRAME_TYPE_I420;
            //video_frame.renderTimeMs = 0;
            video_frame.renderTimeMs = GetTickCount();
            m_rtcengine->pushVideoFrameData(&video_frame);
        } 
#endif // SEI_ONLY
        if((current_time - pre_sei_time) >= sei_intervel){

            pre_sei_time = current_time;
            uint64_t time = current_time;
            m_rtcengine->setSEIData((unsigned char*)&time, sizeof(uint64_t));
            //unsigned char content[1024];
            //memset(content, 0x77, 1024);
            //m_rtcengine->setSEIData((unsigned char*)content, 1000);
        } else {
            Sleep(1);
        }
    }

#ifndef SEI_ONLY
    delete[] audio_buf;
    delete[] video_buf;

    fclose(video_file);
    fclose(audio_file);
#endif // SEI_ONLY
}