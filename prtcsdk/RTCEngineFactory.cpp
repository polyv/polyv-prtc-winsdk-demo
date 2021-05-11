#include "RTCEngineFactory.h"
#include "PRTCEngineImpl.h"

RTCEngineBase* RTCEngineFactory::createRtcEngine(RTC_CHANNEL_TYPE chtype)
{
	RTCEngineBase* realengine = nullptr;
	switch (chtype)
	{
	case RTC_CHANNELTYPE_PRTC:
		realengine = new PRTCEngineImpl;
		break;
	case RTC_CHANNELTYPE_AGORA:
		break;
	case RTC_CHANNELTYPE_ZEGO:
		break;
	default:
		break;
	}
	return realengine;
}
