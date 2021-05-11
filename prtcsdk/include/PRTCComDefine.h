#ifndef _PRTC_COMMON_DEFINE_H_
#define _PRTC_COMMON_DEFINE_H_

#ifdef _EXPORT
#define _EXPORT_API __declspec(dllexport)
#define _EXPORT_API_C extern "C" __declspec(dllexport)
#else
#define _EXPORT_API __declspec(dllimport)
#define _EXPORT_API_C  extern "C" __declspec(dllimport)
#endif

#define  C_API extern "C"
#define MAX_DEVICE_ID_LENGTH 512 
#define MAX_WINDOWS_TILE_LEN 256

//接入方式设置
typedef enum
{
	PRTC_SERVER_GET_FROM_UTECH = 1,
	PRTC_SERVER_GET_FROM_USER_GATEWAY,
	PRTC_SERVER_GET_FROM_USER_DIRECT
}ePRTCServerGetFrom;

//设备信息
typedef struct {
	//设备名称
	char mDeviceName[MAX_DEVICE_ID_LENGTH];
	//设备ID
	char mDeviceId[MAX_DEVICE_ID_LENGTH];
}tPRTCDeviceInfo;

//媒体配置
typedef struct {
	//使能video
	bool mVideoEnable;
	//使能audio
	bool mAudioEnable;
}tPRTCMediaConfig;

//桌面配置
typedef struct
{
	//屏幕索引
	long mScreenindex;
	//x坐标
	int  mXpos;
	//y坐标
	int mYpos;
	//宽度
	int mWidth;
	//长度
	int mHeight;
}tPRTCScreenPargram;

//桌面类型
typedef enum {
	//屏幕
	PTRC_DESKTOPTYPE_SCREEN = 1,
	//窗口
	PTRC_DESKTOPTYPE_WINDOW
}ePRTCDesktopType;

//桌面窗口信息
typedef struct
{
	//桌面类型
	ePRTCDesktopType mType;
	//桌面id
	int mDesktopId;
	int mScreenW;
	int mScreenH;
	//标题
	char mDesktopTitle[MAX_WINDOWS_TILE_LEN];
}tPRTCDeskTopInfo;

//轨道类型
typedef enum {
	PRTC_TRACKTYPE_AUDIO = 1,
	PRTC_TRACKTYPE_VIDEO 
}ePRTCTrackType;

//媒体类型
typedef enum {
	//无
	PRTC_MEDIATYPE_NONE = 0,
	//摄像头流(音轨和视频轨)
	PRTC_MEDIATYPE_VIDEO = 1,
	//桌面
	PRTC_MEDIATYPE_SCREEN = 2
}ePRTCMeidaType;

//流信息
typedef struct {
	//用户ID
	const char* mUserId;
	//流ID
	const char* mStreamId;
	//使能VIDEO
	bool mEnableVideo;
	//使能AUDIO
	bool mEnableAudio;
	//使能Data
	bool mEnableData;
	//mute video状态
	bool mMuteVideo;
	//mute audio状态
	bool mMuteAudio;
	//媒体类型
	ePRTCMeidaType mStreamMtype;
}tPRTCStreamInfo;

//mute 状态
typedef struct {
	//用户ID
	const char* mUserId;
	//流ID
	const char* mStreamId;
	//是否mute
	bool mMute;
	//媒体类型
	ePRTCMeidaType mStreamMtype;
}tPRTCMuteSt;

//录制的profile
typedef enum {
	PRTC_RECORDPROFILE_SD = 1, 
	PRTC_RECORDPROFILE_HD, 
	PRTC_RECORDPROFILE_HDPLUS, 
}ePRTCRecordProfile;

//录制类型
typedef enum {
	//纯音频模式
	PRTC_RECORDTYPE_AUDIOONLY = 1, 
	//音视频模式
	PRTC_RECORDTYPE_AUDIOVIDEO
}ePRTCRecordType;

//水印位置
typedef enum {
	PRTC_WATERMARKPOS_LEFTTOP = 1,
	PRTC_WATERMARKPOS_LEFTBOTTOM,
	PRTC_WATERMARKPOS_RIGHTTOP,
	PRTC_WATERMARKPOS_RIGHTBOTTOM
}ePRTCWaterMarkPos;

//水印类型
typedef enum {
	//默认无
	PRTC_WATERMARK_TYPE_NONE = 0,
	//时间水印
	PRTC_WATERMARK_TYPE_TIME = 1,
	//图片水印
	PRTC_WATERMARK_TYPE_PIC,
	//文字水印
	PRTC_WATERMARK_TYPE_TEXT,
}ePRTCWaterMarkType;

//转推模式
typedef enum {
	//自动
	PRTC_AUTO = 1,
	//手动
	PRTC_MANAUL = 2,
}ePRTCRelayMode;

//渲染缩放类型
typedef enum {
	//default full
	PRTC_RENDER_MODE_DEFAULT = 0,
	//fit 模式
	PRTC_RENDER_MODE_FIT = 1,
	//fill模式
	PRTC_RENDER_MODE_FILL = 2 
} ePRTCRenderMode;

//渲染类型
typedef enum {
	//GDI
	PRTC_RENDER_TYPE_GDI = 1,
	//D3D
	PRTC_RENDER_TYPE_D3D = 2,
	//外部渲染
	PRTC_RENDER_TYPE_EXTEND = 3,
} ePRTCRenderType;

//日志级别
typedef enum {
	PRTC_LOG_LEVEL_DEBUG,
	PRTC_LOG_LEVEL_INFO,
	PRTC_LOG_LEVEL_WARN,
	PRTC_LOG_LEVEL_ERROR,
	PRTC_LOG_LEVEL_NONE,
} ePRTCLogLevel;

//视频profile
typedef enum {
	PRTC_VIDEO_PROFILE_NONE = -1, 
	PRTC_VIDEO_PROFILE_320_180 = 1,
	PRTC_VIDEO_PROFILE_320_240 = 2,
	PRTC_VIDEO_PROFILE_640_360 = 3,
	PRTC_VIDEO_PROFILE_640_480 = 4,
	PRTC_VIDEO_PROFILE_1280_720 = 5,
	PRTC_VIDEO_PROFILE_1920_1080 = 6,
	PRTC_VIDEO_PROFILE_240_180 = 7,
	PRTC_VIDEO_PROFILE_480_360 = 8,
	PRTC_VIDEO_PROFILE_960_720 = 9
} ePRTCVideoProfile;

//桌面profile
typedef enum {
	PRTC_SCREEN_PROFILE_LOW = 1,
	PRTC_SCREEN_PROFILE_MIDDLE = 2,
	PRTC_SCREEN_PROFILE_HIGH = 3,
	PRTC_SCREEN_PROFILE_HIGH_PLUS = 4,
	PRTC_SCREEN_PROFILE_HIGH_1 = 5,     //最大2m码率 25帧
	PRTC_SCREEN_PROFILE_HIGH_PLUS_1 = 6, //最大2.5m码率 25帧
	PRTC_SCREEN_PROFILE_HIGH_0 = 7,     //最大1.6m码率 15帧
	PRTC_SCREEN_PROFILE_HIGH_PLUS_0 = 8 //最大2m码率 18帧
} ePRTCScreenProfile;

//应用类型
typedef enum {
	//视频会议模式
	PRTC_CHANNEL_TYPE_COMMUNICATION,
	//直播模式
	PRTC_CHANNEL_TYPE_BROADCAST
}ePRTCChannelType;

//权限设置
typedef enum {
	// 推流权限
	PRTC_USER_STREAM_ROLE_PUB, 
	// 拉流权限
	PRTC_USER_STREAM_ROLE_SUB,
	// 推拉流
	PRTC_USER_STREAM_ROLE_BOTH 
} ePRTCUserStreamRole;

//SDK 模式
typedef enum {
	//正式模式 token有appserver生成
	PRTC_SDK_MODE_NORMAL, 
	//测试模式 sdk内部生成 需设置appkey
	PRTC_SDK_MODE_TRIVAL, 
} ePRTCSdkMode;

//视频编码类型
typedef enum {
	PRTC_CODEC_VP8 = 1, 
	PRTC_CODEC_H264 
} ePRTCVideoCodec;

//音频编码类型
typedef enum {
	PRTC_CODEC_OPUS = 1, //default
} ePRTCAudioCodec;

//FRAME 类型
typedef enum {
	PRTC_VIDEO_FRAME_TYPE_I420 = 1,
	PRTC_VIDEO_FRAME_TYPE_RGB24,
	PRTC_VIDEO_FRAME_TYPE_BGR24,
	PRTC_VIDEO_FRAME_TYPE_RGBA,
	PRTC_VIDEO_FRAME_TYPE_ARGB,
}ePRTCVideoFrameType;

//网络上下型类型
typedef enum {
	//上行
	PRTC_NETWORK_TX = 1, 
	//下行
	PRTC_NETWORK_RX = 2,  
}ePRTCNetworkQuality;

//网络评分
typedef enum {
	//未知
	PRTC_QUALITY_UNKNOWN = 0, 
	//很坏
	PRTC_QUALITY_DOWN = 5,  
	//勉强能沟通但不顺畅
	PRTC_QUALITY_BAD = 4,  
	//用户主观感受有瑕疵但不影响沟通
	PRTC_QUALITY_POOR =  3, 
	// 用户主观感觉和 excellent 差不多
	PRTC_QUALITY_GOOD = 2, 
	//网络质量极好
	PRTC_QUALITY_EXCELLENT = 1, 
}ePRTCQualityType;

//rtmp状态
typedef enum {
	//推流未开始或停止
	PRTC_RTMP_STREAM_PUBLISH_STATE_IDLE ,   
	//正在推流
	PRTC_RTMP_STREAM_PUBLISH_STATE_RUNNING, 
	//推流失败 详见code
	PRTC_RTMP_STREAM_PUBLISH_STATE_FAILURE ,
	//停止推流失败 详见code
	PRTC_RTMP_STREAM_PUBLISH_STATE_STOPFAILURE, 
	//异常停止推流(无流超时停止)
	PRTC_RTMP_STREAM_PUBLISH_STATE_EXCEPTIONSTOP, 
	//更新布局结果
	PRTC_RTMP_STREAM_PUBLISH_STATE_UPDATECONFIGRES,  //code 为0时更新succ
}ePRTCRtmpState;

// 渲染视图
typedef struct
{
	//窗口视图
	void* mVideoView;
	//用户id
	const char* mUserId;
	//流ID
	const char* mStreamId;
	//流类型
	ePRTCMeidaType mStreamMtype;
	//渲染缩放模式
	ePRTCRenderMode mRenderMode;
	//渲染类型
	ePRTCRenderType mRenderType;
	//when extend render this decide callback frametype
	ePRTCVideoFrameType mVideoFrameType;
}tPRTCVideoCanvas;

//鉴权信息
typedef struct
{
	const char* mAppId = nullptr;
	const char* mRoomId = nullptr;
	const char* mUserId = nullptr;
	const char* mUserToken = nullptr;
	const char* mServerUrl = nullptr;
}tPRTCAuth;

//流信息
typedef struct {
	//用户id
	const char* mUserId;
	//流id
	const char* mStreamId;
	//流类型
	int mStreamMtype;
	//track类型 1 audio 2 video
	int mTracktype; 
	// audio bitrate,unit:bps
	int mAudioBitrate = 0;  
	// video bitrate 
	int mVideoBitrate = 0;
	// video width
	int mVideoWidth = 0;   
	// video height
	int mVideoHeight = 0;     
	// video frames per secon
	int mVideoFrameRate = 0;     
	//丢包率
	float mPacketLostRate = 0.0f;
}tPRTCStreamStats;

//录制信息
typedef struct {
	//录制ID
	const char* mRecordId;
	//录制文件名
	const char* mFileName;
	//region
	const char* mRegion;
	//bucket
	const char* mBucket;
	//房间id
	const char* mRoomid;
}tPRTCRecordInfo;

//音频帧信息
typedef struct {
	//用户id
	const char* mUserId;
	//流ID
	const char* mStreamId;
	//audio 数据
	void* mAudioData;
	int mBytePerSimple;
	//采用率
	int mSimpleRate;
	//声道数
	int mChannels;
	int mNumSimples;
	long long renderTimeMs;
}tPRTCAudioFrame;

//视频帧信息
typedef struct {
	//视频数据
	unsigned char* mDataBuf;
	int mWidth;
	int mHeight;
	//frametype
	ePRTCVideoFrameType mVideoType;
	long long renderTimeMs;
}tPRTCVideoFrame;

//视频信息配置
typedef struct {
	int mWidth;
	int mHeight;
	//帧率
	int mFrameRate;
    int mBitrate; //kbps
}tPRTCVideoConfig;

//合流背景色配置
typedef struct  {
	int mRed;
	int mGreen;
	int mBlue;
}tPRTCBackgroundColor;

typedef enum {
    PRTC_EMDM_UNKNOWN = 0,
    PRTC_EMDM_PUSH,   
    PRTC_EMDM_PULL,
}ePRTCExtendMediaDataMode;

typedef enum {
    PRTC_Audio_Profile_Default = 0,  //默认模式， 单声道， 32K码率
    PRTC_Audio_Profile_Stand,  //标准模式， 单声道， 64K码率
    PRTC_Audio_Profile_Stand_Stereo, //标准立体声， 双声道， 80K码率
    PRTC_Audio_Profile_Hight,   //高音质模式， 单声道， 96K码率
    PRTC_Audio_Profile_Hight_Stereo, //高音质立体声， 双声道， 128K码率
    PRTC_Audio_Profile_Stand_Stereo_Disable_2A, // 标准立体声， 双声道， 80K码率， 禁用AEC， AGC
    PRTC_Audio_Profile_Hight_Disable_2A,   //高音质模式， 单声道， 96K码率， 禁用AEC， AGC
    PRTC_Audio_Profile_Hight_Stereo_Disable_2A, //高音质立体声， 双声道， 128K码率， 禁用AEC， AGC
}ePRTCAudioProfile;

//视频编码质量
typedef enum {
	PRTC_QUALITY_CB = 0, //CB
	PRTC_QUALITY_B,
	PRTC_QUALITY_M,
	PRTC_QUALITY_E,
	PRTC_QUALITY_H
}ePRTCQualityLevel;

//转推混流操作类型
typedef enum {
	_RTMP_STREAM_ADD,	 //添加
	_RTMP_STREAM_REMOVE,  //删除
}ePRTCRtmpOpration;

//转推的流
typedef struct RelayStream {
	const char* mUid;
	ePRTCMeidaType mType;
	RelayStream() {
		mUid = nullptr;
		mType = PRTC_MEDIATYPE_NONE;
	}
}tPRTCRelayStream;

//转推混流操作类型
typedef enum {
	PRTC_MIX_LAYOUT_OLD,       //兼容之前模板
	PRTC_MIX_LAYOUT_FLOW,	  //流式布局
	PRTC_MIX_LAYOUT_TEACH,	  //讲课布局
	PRTC_MIX_LAYOUT_CUSTOM,    //自定义
	PRTC_MIX_LAYOUT_ADAPTION1, //主讲模式
	PRTC_MIX_LAYOUT_ADAPTION2, //多人模式
	PRTC_MIX_LAYOUT_ADAPTION3, //单人模式
}ePRTCMixLayout;

typedef int LayoutLsit[3];
//转推配置
typedef struct TranscodeConfig {
	//背景色
	tPRTCBackgroundColor mbgColor; 
	//帧率
	int mFramerate;
	//码率
	int mBitrate;   
	//主讲人的uid
	const char*  mMainViewUid; 
	//主讲人放置的媒体类型
	int mMainviewType; 
	//输出分辨率宽度
	int mWidth; 
	//输出分辨率高度
	int mHeight; 
	//布局列表
	LayoutLsit mlayouts;
	//当前使用得布局 1.流式布局 2.讲课模式 3.自定义布局 4.模板自适应1 5.模板自适应2 6.单人模式
	ePRTCMixLayout mLayout;
	//mLayout=3 时自定义风格内容
	const char*  mStyle; 
	//混流的用户
	tPRTCRelayStream *mStreams; 
	//混流用户数
	int mStreamslength;
	//水印位置
	ePRTCWaterMarkPos mWatermarkPos;
	//水印类型
	ePRTCWaterMarkType mWaterMarkType;
	//水印url  为图片水印时
	const char* mWatermarkUrl;
	//是否纯音频
	bool mIsAudio;
	//模式
	ePRTCRelayMode mMode;
	//控制人(若此人无流状态超过1分钟 转推自动停止)
	const char*  mKeyUid;
	TranscodeConfig()
	{
		mlayouts[0] = PRTC_MIX_LAYOUT_ADAPTION1;
		mlayouts[1] = PRTC_MIX_LAYOUT_ADAPTION2;
		mlayouts[2] = PRTC_MIX_LAYOUT_ADAPTION3;
		mMode = PRTC_AUTO;
		mIsAudio = false;
		mLayout = PRTC_MIX_LAYOUT_TEACH;
		mKeyUid = nullptr;
		mMainViewUid = nullptr;
		mStreams = nullptr;
		mStyle = nullptr;
		mStreamslength = 0;
		mWatermarkUrl = nullptr;
		mWaterMarkType = PRTC_WATERMARK_TYPE_NONE;
	}
}tPRTCTranscodeConfig;

//录制信息
typedef struct RecordConfig {
	//录制的主流用户id
	const char* mMainviewuid;   
	//存储bucket
	const char* mBucket;    
	//存储region
	const char* mBucketRegion;  
	//录制profile
	ePRTCRecordProfile mProfile;  
	//录制类型
	ePRTCRecordType mRecordType;
	//水印位置
	ePRTCWaterMarkPos mWatermarkPos;
	//主流的媒体类型
	ePRTCMeidaType mMainviewmediatype; 
	//水印类型
	ePRTCWaterMarkType mWaterMarkType;  
	//水印url  为图片水印时
	const char* mWatermarkUrl;	
	//是否均分 (true .流式布局，false:讲课模式)
	bool mIsaverage;		
	//模板类型
	int mMixerTemplateType;			

	//混流的用户
	tPRTCRelayStream *mStreams;
	//混流的用户长度
	int mStreamslength; 
	// 0.取决于mIsaverage 1.流式布局 2.讲课模式 3.自定义布局 4.模板自适应1 5.模板自适应2
	int mLayout; 
	RecordConfig() {
		mWatermarkUrl = nullptr;
		mMainviewuid = nullptr;
		mBucket = nullptr;
		mBucketRegion = nullptr;
		mStreams = nullptr;
		mLayout = PRTC_MIX_LAYOUT_OLD;
	}
}tPRTCRecordConfig;

typedef enum {
	PRTC_DEVICE_VIDEO,      //视频设备
	PRTC_DEVICE_AUDIO,	 //音频设备
}ePRTCDeviceType;

typedef struct 
{
	bool mIsInline;
	const char* mLogPath;
	const char* mLogName;
	ePRTCLogLevel mLogLevel;
	int mMaxReconnect;
}tPRTCInitContext;

//设备插拔回调
class _EXPORT_API PRTCDeviceChanged
{
public:
	///发现设备
	///@param dtype 设备类型
	///@param dccname 名称
	///@param len 长度
	virtual void onInterfaceArrival(ePRTCDeviceType dtype,const char* dccname, int len) {}

	///移除设备
	///@param dtype 设备类型
	///@param dccname 名称
	///@param len 长度
	virtual void onInterfaceRemoved(ePRTCDeviceType dtype, const char* dccname, int len) {}

	///设备属性改变
	///@param dtype 设备类型
	///@param dccname 设备名称
	///@param len 长度
	virtual void onInterfaceChangeValue(ePRTCDeviceType dtype, const char* dccname, int len) {}
	virtual ~PRTCDeviceChanged() {}
};

//音频监听回调
class  _EXPORT_API PRTCAudioFrameCallback
{
public:
	///本地音频源数据callback
	///@param audioframe 音频数据
	virtual void onLocalAudioFrame(tPRTCAudioFrame* audioframe) {}
	///远端音频源数据callback
	///@param audioframe 音频数据
	virtual void onRemoteMixAudioFrame(tPRTCAudioFrame* audioframe) {}
	///本地和远端音频源数据callback
	///@param audioframe 音频数据
	virtual void onLoaclRemoteMixAudioFrame(tPRTCAudioFrame* audioframe) {}
};

//外部音频源(已废弃 采用IAudioFrameObserver )
class  _EXPORT_API PRTCExtendAudioCaptureSource
{
public:
	virtual ~PRTCExtendAudioCaptureSource() {}
	///音频源数据 内部会自动调用此接口
	///@param audioframe 音频数据
	virtual  bool doCaptureAudioFrame(tPRTCAudioFrame* audioframe) = 0;
};

//外部视频源（已废弃 采用IVideoFrameObserver）
class  _EXPORT_API PRTCExtendVideoCaptureSource
{
public:
	///视频源数据 内部会自动调用此接口
	///@param videoframe 视频帧
	virtual  bool doCaptureVideoFrame(tPRTCVideoFrame* videoframe) = 0;
};

//视频设备startcapture监听回调
class _EXPORT_API PRTCVideoFrameObserver 
{
public:
	///视频采集数据回调
	///@param videoframe 视频数据
	///@param buflen 长度
	virtual  void onCaptureFrame(unsigned char* videoframe, int buflen) = 0;
};

//外部渲染
class _EXPORT_API PRTCExtendVideoRender
{
public:
	///外部渲染
	///@param videoframe 吐出的视频帧
	virtual  void onRemoteFrame(const tPRTCVideoFrame* videoframe) = 0;
};



//视频监听回调
class _EXPORT_API PRTCIVideoFrameObserver
{
public:
	///视频采集到每一帧得回调
	///@param videoframe 视频数据
	virtual  bool onCaptureFrame(tPRTCVideoFrame *videoFrame) = 0;
};

//音频监听回调
class _EXPORT_API PRTCIAudioFrameObserver
{
public:
	///音频采集到每一帧得回调
	///@param  audioFrame 音频数据
	virtual  bool onCaptureFrame(tPRTCAudioFrame* audioFrame) = 0;

};

#endif

