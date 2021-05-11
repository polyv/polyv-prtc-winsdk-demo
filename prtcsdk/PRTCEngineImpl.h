#ifndef _UMEETING_PRTCEngineImpl_H_
#define _UMEETING_PRTCEngineImpl_H_

#include "IPRTCEngine.h"
#include "RTCEngineBase.h"
#include "PRTCEventHandler.h"
#include <thread>



class PRTCEngineImpl : public RTCEngineBase{
public:
	PRTCEngineImpl();
	virtual ~PRTCEngineImpl();

	virtual int InitRTCEngine(void* callback) ;
	virtual int UnInitRTCEngine() ;

	virtual std::string getSdkVersion();
	virtual int EnableRtspSource(int mediatype, bool enable, std::string rtspurl);

	virtual int JoinRoom(tRTCAuthInfo& auth);
	virtual int LeaveRoom(std::string& roomid);
	virtual int SetCodecType(int codec);

	virtual int MuteCamBeforeJoin(bool mute);
	virtual int MuteMicBeforeJoin(bool mute);
	virtual int enableExtendVideoSource(bool enable, PRTCExtendVideoCaptureSource* source);
	virtual int enableExtendAudiocapture(bool enable, PRTCExtendAudioCaptureSource* source);
	virtual void RegDeviceChangeCallback(PRTCDeviceChanged* callback);
	virtual int PublishStream(tRTCStreamInfo& streaminfo) ;
	virtual int UnPublishStream(tRTCStreamInfo& streaminfo) ;
	virtual int StartLocalRender(tRTCRenderView& renderview);
	virtual int StopLocalRender(tRTCRenderView& renderview);
	virtual int MuteLocalCamVideo(tRTCStreamMute& mute) ;
	virtual int MuteLocalCamAudio(tRTCStreamMute& mute);

	virtual int MuteLocalScreenAudio(tRTCStreamMute& mute);
	virtual int MuteLocalScreen(tRTCStreamMute& mute);

	virtual int SubRemoteStream(tRTCStreamInfo& streaminfo);
	virtual int UnSubRemoteStream(tRTCStreamInfo& streaminfo);
	virtual int StartRemoteRender(tRTCRenderView& renderview);
	virtual int StopRemoteRender(tRTCRenderView& renderview);
	virtual int MuteRemoteCamVideo(tRTCStreamMute& mute);
	virtual int MuteRemoteCamAudio(tRTCStreamMute& mute);
	virtual int MuteRemoteScreen(tRTCStreamMute& mute) ;

	virtual int StartRecord(tRecordConfig& config);
	virtual int StopRecord() ;

	virtual int StartMixFile(const char* filepath, bool replace, bool loop, float musicvol);
	virtual int StopMixFile();


	virtual int StartPushCDN(const char* url, tPRTCTranscodeConfig *config);
    virtual int UpdatePushCDN(const char* url, tPRTCTranscodeConfig *config);
	virtual int StopPushCDN(const char* url) ;

	virtual int SetStreamRole(int role);
    virtual void SetVideoProfile(ePRTCVideoProfile profile);
    virtual int setAudioProfile(ePRTCAudioProfile audio_profile);
    virtual int switchSpeaker(tPRTCDeviceInfo& info);
private:
    void   PushDataProc();
private:

	IPRTCEngine*   m_rtcengine;
	PRTCEventHandler* m_eventhandler;

    std::thread       push_thread_;
    bool              stop_push_thread_ = false;

    int video_intervel = 33;
};

#endif

