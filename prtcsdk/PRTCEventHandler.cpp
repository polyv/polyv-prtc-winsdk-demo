#include "PRTCEventHandler.h"
#include "RTCEventDefine.h"
#include "RTCDefine.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"  
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <windows.h>
#include <string>

static void AddMemberToObj_Str(rapidjson::Value & Obj,
	const std::string & key,
	const std::string & value,
	rapidjson::Document::AllocatorType & allocator) {
	rapidjson::Value str_key(rapidjson::Type::kStringType);
	str_key.SetString(key.c_str(), allocator);

	rapidjson::Value str_value(rapidjson::Type::kStringType);
	str_value.SetString(value.c_str(), allocator);

	Obj.AddMember(str_key, str_value, allocator);
}

PRTCEventHandler::PRTCEventHandler()
{
	mCallback = nullptr;
}

PRTCEventHandler::~PRTCEventHandler() 
{
	mCallback = nullptr;
}
void PRTCEventHandler::initEventHandler(void* callback)
{
	mCallback = callback;
}
void PRTCEventHandler::onServerDisconnect()
{
	dispatchEvent(PRTC_EVENT_MSG_ONSERVERDIS,"" );
}

void PRTCEventHandler::onJoinRoom(int code, const char* msg, const char* uid, const char* roomid)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("roomid");
	writer.String(roomid);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_JOINROOM_RSP, strBuf.GetString());
}
void PRTCEventHandler::onLeaveRoom(int code, const char* msg, const char* uid, const char* roomid)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);

	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("roomid");
	writer.String(roomid);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_LEAVEROOM_RSP, strBuf.GetString());
}

void PRTCEventHandler::onRejoining(const char* uid, const char* roomid)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();

	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("roomid");
	writer.String(roomid);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REJOINING, strBuf.GetString());
}

void PRTCEventHandler::onReJoinRoom(const char* uid, const char* roomid)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();

	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("roomid");
	writer.String(roomid);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REJOINED, strBuf.GetString());
}

void PRTCEventHandler::onRemoteUserJoin(const char* uid)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();

	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("cmd");
	writer.String("join");
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REMOTEUSERJOIN, strBuf.GetString() );
}

void PRTCEventHandler::onRemoteUserLeave(const char* uid, int reson)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();

	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("cmd");
	writer.String("leave");
	writer.Key("reson");
	writer.Int(reson);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REMOTEUSERLEAVE, strBuf.GetString() );
}

void PRTCEventHandler::onRemotePublish(tPRTCStreamInfo& info)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();

	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(info.mUserId);
	writer.Key("cmd");
	writer.String("add");
	writer.Key("mtype");
	writer.Int(info.mStreamMtype);
	writer.Key("audio");
	writer.Bool(info.mEnableAudio);
	writer.Key("audio");
	writer.Bool(info.mEnableAudio);
	writer.Key("video");
	writer.Bool(info.mEnableVideo);
	writer.Key("data");
	writer.Bool(info.mEnableData);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REMOTEPUBLISH, strBuf.GetString() );
}

void PRTCEventHandler::onRemoteUnPublish(tPRTCStreamInfo& info)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();

	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(info.mUserId);
	writer.Key("cmd");
	writer.String("remove");
	writer.Key("mtype");
	writer.Int(info.mStreamMtype);
	writer.Key("audio");
	writer.Bool(info.mEnableAudio);
	writer.Key("audio");
	writer.Bool(info.mEnableAudio);
	writer.Key("video");
	writer.Bool(info.mEnableVideo);
	writer.Key("data");
	writer.Bool(info.mEnableData);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REMOTEUNPUBLISH, strBuf.GetString());
}

void PRTCEventHandler::onLocalPublish(const int code, const char* msg, tPRTCStreamInfo& info)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(info.mUserId);
	writer.Key("cmd");
	writer.String("add");
	writer.Key("mtype");
	writer.Int(info.mStreamMtype);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_LOCALPUBLISH_RSP,strBuf.GetString());

}

void PRTCEventHandler::onLocalUnPublish(const int code, const char* msg, tPRTCStreamInfo& info)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(info.mUserId);
	writer.Key("mtype");
	writer.Int(info.mStreamMtype);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_LOCALUNPUBLISH_RSP, strBuf.GetString());
}

void PRTCEventHandler::onSubscribeResult(const int code, const char* msg, tPRTCStreamInfo& info)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(info.mUserId);
	writer.Key("mtype");
	writer.Int(info.mStreamMtype);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REMOTESUB_RSP, strBuf.GetString());
}

void PRTCEventHandler::onUnSubscribeResult(const int code, const char* msg, tPRTCStreamInfo& info)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(info.mUserId);
	writer.Key("mtype");
	writer.Int(info.mStreamMtype);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REMOTEUNSUBE_RSP, strBuf.GetString());
}

void PRTCEventHandler::onLocalStreamMuteRsp(const int code, const char* msg,
	ePRTCMeidaType mediatype, ePRTCTrackType tracktype, bool mute)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.Key("data");
	writer.StartObject();
	writer.Key("mtype");
	writer.Int(mediatype);
	writer.Key("ttype");
	writer.Int(tracktype);
	writer.Key("mute");
	writer.Bool(mute);
	writer.EndObject();

	writer.EndObject();
	dispatchEvent(PRTC_EVENT_MSG_LOCALSTREAMMUTE_RSP, strBuf.GetString() );
}
void PRTCEventHandler::onRemoteStreamMuteRsp(const int code, const char* msg, const char* uid,
	ePRTCMeidaType mediatype, ePRTCTrackType tracktype, bool mute)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("mtype");
	writer.Int(mediatype);
	writer.Key("ttype");
	writer.Int(tracktype);
	writer.Key("mute");
	writer.Bool(mute);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REMOTESTREAMMUTE_RSP, strBuf.GetString());
}

void PRTCEventHandler::onRemoteTrackNotify(const char* uid,
	ePRTCMeidaType mediatype, ePRTCTrackType tracktype, bool mute)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("mtype");
	writer.Int(mediatype);
	writer.Key("ttype");
	writer.Int(tracktype);
	writer.Key("mute");
	writer.Bool(mute);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_REMOTETRACKST, strBuf.GetString());
}

void PRTCEventHandler::onError(int code)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.EndObject();
	dispatchEvent(PRTC_EVENT_MSG_ERRORMSG, strBuf.GetString());
}

void PRTCEventHandler::onKickoff(int code)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_KICKOFF, strBuf.GetString());
}
void PRTCEventHandler::onStartRecord(const int code, const char* msg, tPRTCRecordInfo& info)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.Key("data");
	writer.StartObject();
	writer.Key("recordid");
	writer.String(info.mRecordId);
	writer.Key("filename");
	writer.String(info.mFileName);
	writer.Key("bucket");
	writer.String(info.mBucket);
	writer.Key("region");
	writer.String(info.mRegion);
	writer.Key("roomid");
	writer.String(info.mRoomid);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_ELEC_STARTRECORD,strBuf.GetString());

}

void PRTCEventHandler::onStopRecord(const int code, const char* msg, const char* recordid)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("code");
	writer.Int(code);
	writer.Key("msg");
	writer.String(msg);
	writer.EndObject();
	dispatchEvent(PRTC_EVENT_MSG_ELEC_STOPRECORD, strBuf.GetString());
}


void PRTCEventHandler::onRemoteAudioLevel(const char* uid, int volume)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("vol");
	writer.Int(volume);
	writer.EndObject();

	writer.EndObject();
	dispatchEvent(PRTC_EVENT_MSG_REMOTE_AUDIOVOL, strBuf.GetString());
}

void PRTCEventHandler::onLocalAudioLevel(int volume)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("data");
	writer.StartObject();
	writer.Key("vol");
	writer.Int(volume);
	writer.EndObject();

	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_LOCAL_AUDIOVOL, strBuf.GetString());
}

void PRTCEventHandler::onSendRTCStats(tPRTCStreamStats& rtstats)
{

	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("data");
	writer.StartObject();
	writer.Key("mtype");
	writer.Int(rtstats.mStreamMtype);
	writer.Key("ttype");
	writer.Int(rtstats.mTracktype);

	if (rtstats.mTracktype == PRTC_TRACKTYPE_AUDIO)
	{
		writer.Key("bitrate");
		writer.Int(rtstats.mAudioBitrate);
		writer.Key("lostrate");
		writer.Int(rtstats.mPacketLostRate);
	}
	else
	{
		writer.Key("bitrate");
		writer.Int(rtstats.mVideoBitrate);
		writer.Key("lostrate");
		writer.Int(rtstats.mPacketLostRate);
		writer.Key("height");
		writer.Int(rtstats.mVideoHeight);
		writer.Key("width");
		writer.Int(rtstats.mVideoWidth);
		writer.Key("framerate");
		writer.Int(rtstats.mVideoFrameRate);
	}

	writer.EndObject();

	writer.EndObject();
	dispatchEvent(PRTC_EVENT_MSG_LOCAL_ST_UPDATE, strBuf.GetString());
}

void PRTCEventHandler::onRemoteRTCStats(tPRTCStreamStats rtstats)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(rtstats.mUserId);
	writer.Key("mtype");
	writer.Int(rtstats.mStreamMtype);
	writer.Key("ttype");
	writer.Int(rtstats.mTracktype);

	if (rtstats.mTracktype == PRTC_TRACKTYPE_AUDIO)
	{
		writer.Key("bitrate");
		writer.Int(rtstats.mAudioBitrate);
		writer.Key("lostrate");
		writer.Int(rtstats.mPacketLostRate);
	}
	else
	{
		writer.Key("bitrate");
		writer.Int(rtstats.mVideoBitrate);
		writer.Key("lostrate");
		writer.Int(rtstats.mPacketLostRate);
		writer.Key("height");
		writer.Int(rtstats.mVideoHeight);
		writer.Key("width");
		writer.Int(rtstats.mVideoWidth);
		writer.Key("framerate");
		writer.Int(rtstats.mVideoFrameRate);
	}

	writer.EndObject();

	writer.EndObject();
	dispatchEvent(PRTC_EVENT_MSG_REMOTE_ST_UPDATE, strBuf.GetString());
}

void PRTCEventHandler::onNetworkQuality(const char* uid, ePRTCNetworkQuality&rtype, ePRTCQualityType& Quality)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("data");
	writer.StartObject();
	writer.Key("uid");
	writer.String(uid);
	writer.Key("rtype");
	writer.Int(rtype);
	writer.Key("quality");
	writer.Int(Quality);

	writer.EndObject();
	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_NETWORK_QUA, strBuf.GetString());
}

void PRTCEventHandler::onRtmpStreamingStateChanged(const int 	state, const char* url, int code)
{
	rapidjson::StringBuffer strBuf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
	writer.StartObject();
	writer.Key("data");
	writer.StartObject();
	writer.Key("state");
	writer.Int(state);	
	writer.Key("url");
	writer.String(url);
	writer.Key("code");
	writer.Int(code);
	writer.EndObject();
	writer.EndObject();

	dispatchEvent(PRTC_EVENT_MSG_RTMP, strBuf.GetString());
}

void PRTCEventHandler::dispatchEvent(int eventid, std::string jsonmsg)
{
	if (mCallback)
	{
		tEventMsg* eventmsg = new tEventMsg;
		eventmsg->mEventid = eventid;
		eventmsg->mJsonMsg = jsonmsg;

		HWND msgwnd = (HWND)mCallback;
		PostMessage(msgwnd, RTC_EVENT_PRTC, (WPARAM)eventmsg, 0);
	}
	
}