#ifndef _UMEETING_URTCONFIG_H_
#define _UMEETING_URTCONFIG_H_

#include "PRTCComDefine.h"

#include <string>
#include <map>
#include <list>

class PRTCConfig
{
public:
	static PRTCConfig* getInstance();

	void setVideoProfile(ePRTCVideoProfile profile);
	ePRTCVideoProfile getVideoProfile();

	void setSecKey(std::string key);
	std::string getSecKey();

	void setMuteCamBeforeJoin(bool mute);
	bool getMuteCamBeforeJoin();

	void setMuteMicBeforeJoin(bool mute);
	bool getMuteMicBeforeJoin();

	void setAutoPublish(bool isauto);
	bool isAutoPublish();

	void setAutoSubscribe(bool isauto);
	bool isAutoSubscribe();

	void setAutoPubVideo(bool isauto);
	bool isAutoPubVideo();

	void setAutoPubAudio(bool isauto);
	bool isAutoPubAudio();

	void setAutoPubScreen(bool isauto);
	bool isAutoPubScreen();

	void setAudioOnly(bool only);
	bool isAudioOnly();

	void setStreamRole(ePRTCUserStreamRole role);
	ePRTCUserStreamRole getStreamRole();

	void setChannelType(ePRTCChannelType chtype);
	ePRTCChannelType getChannelType();

	void setSdkMode(ePRTCSdkMode mode);
	ePRTCSdkMode getSdkMode();

	void setCodecType(ePRTCVideoCodec codec);
	ePRTCVideoCodec getCodecType();

	void setAppId(std::string appid);
	std::string getAppId();

	void setUserId(std::string uid);
	std::string getUserId();

	void setRoomId(std::string rid);
	std::string getRoomId();

    void setAudioProfile(ePRTCAudioProfile audio_profile);
    ePRTCAudioProfile getAudioProfile();
protected:
	PRTCConfig();
	~PRTCConfig();
private:
	static PRTCConfig* mSInstance;

	ePRTCVideoProfile mVideoprofile;
	std::string mSeckey;

	bool mAutoPub;
	bool mAutoSub;

	bool mPubVideo;
	bool mPubAudio;
	bool mPubScreen;

	bool mMuteCamBeforeJoin;
	bool mMuteMicBeforeJoin;

	bool mAudioOnly;

	ePRTCUserStreamRole mRole;
	ePRTCSdkMode mSdkMode;

	ePRTCChannelType mChannelType;
	ePRTCVideoCodec mCodec;
	std::string mAppid;

	std::string mUserid;
	std::string mRoomid;

    ePRTCAudioProfile  mAudioProfile = PRTC_Audio_Profile_Default;
};

#endif
