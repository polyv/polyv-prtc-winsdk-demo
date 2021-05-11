#include "PRTCConfig.h"
#include "SdkUtil.h"

PRTCConfig* PRTCConfig::mSInstance = new PRTCConfig();
PRTCConfig* PRTCConfig::getInstance()
{
	return mSInstance;
}

PRTCConfig::PRTCConfig()
{
	mVideoprofile = PRTC_VIDEO_PROFILE_640_360;
    mSeckey = "9129304dbf8c5c4bf68d70824462409f";
    mAppid = "URtc-h4r1txxy";

    //mSeckey = "463fb1e9f967160afae8d8ada69fbe17";
    //mAppid = "urtc-sonv3xgi";

	mAutoPub = false;
	mAutoSub = true;

	mPubVideo = true;
	mPubAudio = true;
	mPubScreen = false;

	mAudioOnly = false;

	mRole = PRTC_USER_STREAM_ROLE_BOTH;
	mSdkMode = PRTC_SDK_MODE_TRIVAL;

	mChannelType = PRTC_CHANNEL_TYPE_BROADCAST;
	mUserid = "win_" + get_randrom_string(8);
	mRoomid = "2224";

    mCodec = PRTC_CODEC_H264;
}
PRTCConfig::~PRTCConfig()
{
}

void PRTCConfig::setVideoProfile(ePRTCVideoProfile profile)
{
	this->mVideoprofile = profile;
}

ePRTCVideoProfile PRTCConfig::getVideoProfile()
{
	return this->mVideoprofile;
}

void PRTCConfig::setSecKey(std::string key)
{
	this->mSeckey = key;
}
std::string PRTCConfig::getSecKey()
{
	return this->mSeckey;
}

void PRTCConfig::setMuteCamBeforeJoin(bool mute)
{
	this->mMuteCamBeforeJoin = mute;
}

bool PRTCConfig::getMuteCamBeforeJoin()
{
	return this->mMuteCamBeforeJoin ;
}

void PRTCConfig::setMuteMicBeforeJoin(bool mute)
{
	this->mMuteMicBeforeJoin = mute;
}

bool PRTCConfig::getMuteMicBeforeJoin()
{
	return this->mMuteMicBeforeJoin;
}

void PRTCConfig::setAutoPublish(bool isauto)
{
	this->mAutoPub = isauto;
}
bool PRTCConfig::isAutoPublish()
{
	return this->mAutoPub;
}

void PRTCConfig::setAutoSubscribe(bool isauto)
{
	this->mAutoSub = isauto;
}
bool PRTCConfig::isAutoSubscribe()
{
	return this->mAutoSub;
}

void PRTCConfig::setAutoPubVideo(bool isauto)
{
	this->mPubVideo = isauto;
}
bool PRTCConfig::isAutoPubVideo()
{
	return this->mPubVideo;
}

void PRTCConfig::setAutoPubAudio(bool isauto)
{
	this->mPubAudio = isauto;
}
bool PRTCConfig::isAutoPubAudio()
{
	return this->mPubAudio;
}

void PRTCConfig::setAutoPubScreen(bool isauto)
{
	this->mPubScreen = isauto;
}
bool PRTCConfig::isAutoPubScreen()
{
	return this->mPubScreen;
}

void PRTCConfig::setAudioOnly(bool only)
{
	this->mAudioOnly = only;
}
bool PRTCConfig::isAudioOnly()
{
	return this->mAudioOnly;
}

void PRTCConfig::setStreamRole(ePRTCUserStreamRole role)
{
	this->mRole = role;
}
ePRTCUserStreamRole PRTCConfig::getStreamRole()
{
	return this->mRole;
}

void PRTCConfig::setChannelType(ePRTCChannelType chtype)
{
	this->mChannelType = chtype;
}
ePRTCChannelType PRTCConfig::getChannelType()
{
	return this->mChannelType;
}

void PRTCConfig::setSdkMode(ePRTCSdkMode mode)
{
	this->mSdkMode = mode;
}
ePRTCSdkMode PRTCConfig::getSdkMode()
{
	return this->mSdkMode;
}

void PRTCConfig::setCodecType(ePRTCVideoCodec codec)
{
	this->mCodec = codec;
}

ePRTCVideoCodec PRTCConfig::getCodecType()
{
	return this->mCodec;
}

void PRTCConfig::setAppId(std::string appid)
{
	this->mAppid = appid;
}
std::string PRTCConfig::getAppId()
{
	return this->mAppid;
}

void PRTCConfig::setUserId(std::string uid)
{
	this->mUserid = uid;
}
std::string PRTCConfig::getUserId()
{
	return this->mUserid;
}

void PRTCConfig::setRoomId(std::string rid)
{
	this->mRoomid = rid;
}
std::string PRTCConfig::getRoomId()
{
	return this->mRoomid;
}

void PRTCConfig::setAudioProfile(ePRTCAudioProfile audio_profile) {
    mAudioProfile = audio_profile;
}

ePRTCAudioProfile PRTCConfig::getAudioProfile() {
    return mAudioProfile;
}