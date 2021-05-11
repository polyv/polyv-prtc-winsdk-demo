#ifndef _UMEETING_PRTCEventHandler_H_
#define _UMEETING_PRTCEventHandler_H_

#include "IPRTCEngine.h"
#include "RTCDefine.h"
#include "RTCEventDefine.h"
#include <string>

class PRTCEventHandler : public PRTCEventListener {
public:
	PRTCEventHandler();
	virtual ~PRTCEventHandler();
	virtual void initEventHandler(void* callback);
	virtual void onServerDisconnect();
	virtual void onJoinRoom(int code, const char* msg, const char* uid, const char* roomid);
	virtual void onLeaveRoom(int code, const char* msg, const char* uid, const char* roomid);
	virtual void onRejoining(const char* uid, const char* roomid);
	virtual void onReJoinRoom(const char* uid, const char* roomid);
	virtual void onRemoteUserJoin(const char* uid);
	virtual void onRemoteUserLeave(const char* uid, int reson);
	virtual void onRemotePublish(tPRTCStreamInfo& info);
	virtual void onRemoteUnPublish(tPRTCStreamInfo& info);
	virtual void onLocalPublish(const int code, const char* msg, tPRTCStreamInfo& info);
	virtual void onLocalUnPublish(const int code, const char* msg, tPRTCStreamInfo& info);
	virtual void onSubscribeResult(const int code, const char* msg, tPRTCStreamInfo& info);
	virtual void onUnSubscribeResult(const int code, const char* msg, tPRTCStreamInfo& info);
	virtual void onLocalStreamMuteRsp(const int code, const char* msg,
		ePRTCMeidaType mediatype, ePRTCTrackType tracktype, bool mute);
	virtual void onRemoteStreamMuteRsp(const int code, const char* msg, const char* uid,
		ePRTCMeidaType mediatype, ePRTCTrackType tracktype, bool mute);
	virtual void onRemoteTrackNotify(const char* uid,
		ePRTCMeidaType mediatype, ePRTCTrackType tracktype, bool mute);
	virtual void onError(int code);
	virtual void onKickoff(int code);
	virtual void onStartRecord(const int code, const char* msg, tPRTCRecordInfo& info);
	virtual void onStopRecord(const int code, const char* msg, const char* recordid);
	virtual void onRemoteAudioLevel(const char* uid, int volume);
	virtual void onLocalAudioLevel(int volume);
	virtual void onSendRTCStats(tPRTCStreamStats& rtstats);
	virtual void onRemoteRTCStats(tPRTCStreamStats rtstats);
	virtual void onNetworkQuality(const char* uid, ePRTCNetworkQuality&rtype, ePRTCQualityType& Quality);
	virtual void onRtmpStreamingStateChanged(const int 	state, const char* url, int code);

private:
	void dispatchEvent(int eventid, std::string jsonmsg);

	void* mCallback;
};

#endif
