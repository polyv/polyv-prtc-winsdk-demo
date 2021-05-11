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

//���뷽ʽ����
typedef enum
{
	PRTC_SERVER_GET_FROM_UTECH = 1,
	PRTC_SERVER_GET_FROM_USER_GATEWAY,
	PRTC_SERVER_GET_FROM_USER_DIRECT
}ePRTCServerGetFrom;

//�豸��Ϣ
typedef struct {
	//�豸����
	char mDeviceName[MAX_DEVICE_ID_LENGTH];
	//�豸ID
	char mDeviceId[MAX_DEVICE_ID_LENGTH];
}tPRTCDeviceInfo;

//ý������
typedef struct {
	//ʹ��video
	bool mVideoEnable;
	//ʹ��audio
	bool mAudioEnable;
}tPRTCMediaConfig;

//��������
typedef struct
{
	//��Ļ����
	long mScreenindex;
	//x����
	int  mXpos;
	//y����
	int mYpos;
	//���
	int mWidth;
	//����
	int mHeight;
}tPRTCScreenPargram;

//��������
typedef enum {
	//��Ļ
	PTRC_DESKTOPTYPE_SCREEN = 1,
	//����
	PTRC_DESKTOPTYPE_WINDOW
}ePRTCDesktopType;

//���洰����Ϣ
typedef struct
{
	//��������
	ePRTCDesktopType mType;
	//����id
	int mDesktopId;
	int mScreenW;
	int mScreenH;
	//����
	char mDesktopTitle[MAX_WINDOWS_TILE_LEN];
}tPRTCDeskTopInfo;

//�������
typedef enum {
	PRTC_TRACKTYPE_AUDIO = 1,
	PRTC_TRACKTYPE_VIDEO 
}ePRTCTrackType;

//ý������
typedef enum {
	//��
	PRTC_MEDIATYPE_NONE = 0,
	//����ͷ��(�������Ƶ��)
	PRTC_MEDIATYPE_VIDEO = 1,
	//����
	PRTC_MEDIATYPE_SCREEN = 2
}ePRTCMeidaType;

//����Ϣ
typedef struct {
	//�û�ID
	const char* mUserId;
	//��ID
	const char* mStreamId;
	//ʹ��VIDEO
	bool mEnableVideo;
	//ʹ��AUDIO
	bool mEnableAudio;
	//ʹ��Data
	bool mEnableData;
	//mute video״̬
	bool mMuteVideo;
	//mute audio״̬
	bool mMuteAudio;
	//ý������
	ePRTCMeidaType mStreamMtype;
}tPRTCStreamInfo;

//mute ״̬
typedef struct {
	//�û�ID
	const char* mUserId;
	//��ID
	const char* mStreamId;
	//�Ƿ�mute
	bool mMute;
	//ý������
	ePRTCMeidaType mStreamMtype;
}tPRTCMuteSt;

//¼�Ƶ�profile
typedef enum {
	PRTC_RECORDPROFILE_SD = 1, 
	PRTC_RECORDPROFILE_HD, 
	PRTC_RECORDPROFILE_HDPLUS, 
}ePRTCRecordProfile;

//¼������
typedef enum {
	//����Ƶģʽ
	PRTC_RECORDTYPE_AUDIOONLY = 1, 
	//����Ƶģʽ
	PRTC_RECORDTYPE_AUDIOVIDEO
}ePRTCRecordType;

//ˮӡλ��
typedef enum {
	PRTC_WATERMARKPOS_LEFTTOP = 1,
	PRTC_WATERMARKPOS_LEFTBOTTOM,
	PRTC_WATERMARKPOS_RIGHTTOP,
	PRTC_WATERMARKPOS_RIGHTBOTTOM
}ePRTCWaterMarkPos;

//ˮӡ����
typedef enum {
	//Ĭ����
	PRTC_WATERMARK_TYPE_NONE = 0,
	//ʱ��ˮӡ
	PRTC_WATERMARK_TYPE_TIME = 1,
	//ͼƬˮӡ
	PRTC_WATERMARK_TYPE_PIC,
	//����ˮӡ
	PRTC_WATERMARK_TYPE_TEXT,
}ePRTCWaterMarkType;

//ת��ģʽ
typedef enum {
	//�Զ�
	PRTC_AUTO = 1,
	//�ֶ�
	PRTC_MANAUL = 2,
}ePRTCRelayMode;

//��Ⱦ��������
typedef enum {
	//default full
	PRTC_RENDER_MODE_DEFAULT = 0,
	//fit ģʽ
	PRTC_RENDER_MODE_FIT = 1,
	//fillģʽ
	PRTC_RENDER_MODE_FILL = 2 
} ePRTCRenderMode;

//��Ⱦ����
typedef enum {
	//GDI
	PRTC_RENDER_TYPE_GDI = 1,
	//D3D
	PRTC_RENDER_TYPE_D3D = 2,
	//�ⲿ��Ⱦ
	PRTC_RENDER_TYPE_EXTEND = 3,
} ePRTCRenderType;

//��־����
typedef enum {
	PRTC_LOG_LEVEL_DEBUG,
	PRTC_LOG_LEVEL_INFO,
	PRTC_LOG_LEVEL_WARN,
	PRTC_LOG_LEVEL_ERROR,
	PRTC_LOG_LEVEL_NONE,
} ePRTCLogLevel;

//��Ƶprofile
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

//����profile
typedef enum {
	PRTC_SCREEN_PROFILE_LOW = 1,
	PRTC_SCREEN_PROFILE_MIDDLE = 2,
	PRTC_SCREEN_PROFILE_HIGH = 3,
	PRTC_SCREEN_PROFILE_HIGH_PLUS = 4,
	PRTC_SCREEN_PROFILE_HIGH_1 = 5,     //���2m���� 25֡
	PRTC_SCREEN_PROFILE_HIGH_PLUS_1 = 6, //���2.5m���� 25֡
	PRTC_SCREEN_PROFILE_HIGH_0 = 7,     //���1.6m���� 15֡
	PRTC_SCREEN_PROFILE_HIGH_PLUS_0 = 8 //���2m���� 18֡
} ePRTCScreenProfile;

//Ӧ������
typedef enum {
	//��Ƶ����ģʽ
	PRTC_CHANNEL_TYPE_COMMUNICATION,
	//ֱ��ģʽ
	PRTC_CHANNEL_TYPE_BROADCAST
}ePRTCChannelType;

//Ȩ������
typedef enum {
	// ����Ȩ��
	PRTC_USER_STREAM_ROLE_PUB, 
	// ����Ȩ��
	PRTC_USER_STREAM_ROLE_SUB,
	// ������
	PRTC_USER_STREAM_ROLE_BOTH 
} ePRTCUserStreamRole;

//SDK ģʽ
typedef enum {
	//��ʽģʽ token��appserver����
	PRTC_SDK_MODE_NORMAL, 
	//����ģʽ sdk�ڲ����� ������appkey
	PRTC_SDK_MODE_TRIVAL, 
} ePRTCSdkMode;

//��Ƶ��������
typedef enum {
	PRTC_CODEC_VP8 = 1, 
	PRTC_CODEC_H264 
} ePRTCVideoCodec;

//��Ƶ��������
typedef enum {
	PRTC_CODEC_OPUS = 1, //default
} ePRTCAudioCodec;

//FRAME ����
typedef enum {
	PRTC_VIDEO_FRAME_TYPE_I420 = 1,
	PRTC_VIDEO_FRAME_TYPE_RGB24,
	PRTC_VIDEO_FRAME_TYPE_BGR24,
	PRTC_VIDEO_FRAME_TYPE_RGBA,
	PRTC_VIDEO_FRAME_TYPE_ARGB,
}ePRTCVideoFrameType;

//��������������
typedef enum {
	//����
	PRTC_NETWORK_TX = 1, 
	//����
	PRTC_NETWORK_RX = 2,  
}ePRTCNetworkQuality;

//��������
typedef enum {
	//δ֪
	PRTC_QUALITY_UNKNOWN = 0, 
	//�ܻ�
	PRTC_QUALITY_DOWN = 5,  
	//��ǿ�ܹ�ͨ����˳��
	PRTC_QUALITY_BAD = 4,  
	//�û����۸�����覴õ���Ӱ�칵ͨ
	PRTC_QUALITY_POOR =  3, 
	// �û����۸о��� excellent ���
	PRTC_QUALITY_GOOD = 2, 
	//������������
	PRTC_QUALITY_EXCELLENT = 1, 
}ePRTCQualityType;

//rtmp״̬
typedef enum {
	//����δ��ʼ��ֹͣ
	PRTC_RTMP_STREAM_PUBLISH_STATE_IDLE ,   
	//��������
	PRTC_RTMP_STREAM_PUBLISH_STATE_RUNNING, 
	//����ʧ�� ���code
	PRTC_RTMP_STREAM_PUBLISH_STATE_FAILURE ,
	//ֹͣ����ʧ�� ���code
	PRTC_RTMP_STREAM_PUBLISH_STATE_STOPFAILURE, 
	//�쳣ֹͣ����(������ʱֹͣ)
	PRTC_RTMP_STREAM_PUBLISH_STATE_EXCEPTIONSTOP, 
	//���²��ֽ��
	PRTC_RTMP_STREAM_PUBLISH_STATE_UPDATECONFIGRES,  //code Ϊ0ʱ����succ
}ePRTCRtmpState;

// ��Ⱦ��ͼ
typedef struct
{
	//������ͼ
	void* mVideoView;
	//�û�id
	const char* mUserId;
	//��ID
	const char* mStreamId;
	//������
	ePRTCMeidaType mStreamMtype;
	//��Ⱦ����ģʽ
	ePRTCRenderMode mRenderMode;
	//��Ⱦ����
	ePRTCRenderType mRenderType;
	//when extend render this decide callback frametype
	ePRTCVideoFrameType mVideoFrameType;
}tPRTCVideoCanvas;

//��Ȩ��Ϣ
typedef struct
{
	const char* mAppId = nullptr;
	const char* mRoomId = nullptr;
	const char* mUserId = nullptr;
	const char* mUserToken = nullptr;
	const char* mServerUrl = nullptr;
}tPRTCAuth;

//����Ϣ
typedef struct {
	//�û�id
	const char* mUserId;
	//��id
	const char* mStreamId;
	//������
	int mStreamMtype;
	//track���� 1 audio 2 video
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
	//������
	float mPacketLostRate = 0.0f;
}tPRTCStreamStats;

//¼����Ϣ
typedef struct {
	//¼��ID
	const char* mRecordId;
	//¼���ļ���
	const char* mFileName;
	//region
	const char* mRegion;
	//bucket
	const char* mBucket;
	//����id
	const char* mRoomid;
}tPRTCRecordInfo;

//��Ƶ֡��Ϣ
typedef struct {
	//�û�id
	const char* mUserId;
	//��ID
	const char* mStreamId;
	//audio ����
	void* mAudioData;
	int mBytePerSimple;
	//������
	int mSimpleRate;
	//������
	int mChannels;
	int mNumSimples;
	long long renderTimeMs;
}tPRTCAudioFrame;

//��Ƶ֡��Ϣ
typedef struct {
	//��Ƶ����
	unsigned char* mDataBuf;
	int mWidth;
	int mHeight;
	//frametype
	ePRTCVideoFrameType mVideoType;
	long long renderTimeMs;
}tPRTCVideoFrame;

//��Ƶ��Ϣ����
typedef struct {
	int mWidth;
	int mHeight;
	//֡��
	int mFrameRate;
    int mBitrate; //kbps
}tPRTCVideoConfig;

//��������ɫ����
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
    PRTC_Audio_Profile_Default = 0,  //Ĭ��ģʽ�� �������� 32K����
    PRTC_Audio_Profile_Stand,  //��׼ģʽ�� �������� 64K����
    PRTC_Audio_Profile_Stand_Stereo, //��׼�������� ˫������ 80K����
    PRTC_Audio_Profile_Hight,   //������ģʽ�� �������� 96K����
    PRTC_Audio_Profile_Hight_Stereo, //�������������� ˫������ 128K����
    PRTC_Audio_Profile_Stand_Stereo_Disable_2A, // ��׼�������� ˫������ 80K���ʣ� ����AEC�� AGC
    PRTC_Audio_Profile_Hight_Disable_2A,   //������ģʽ�� �������� 96K���ʣ� ����AEC�� AGC
    PRTC_Audio_Profile_Hight_Stereo_Disable_2A, //�������������� ˫������ 128K���ʣ� ����AEC�� AGC
}ePRTCAudioProfile;

//��Ƶ��������
typedef enum {
	PRTC_QUALITY_CB = 0, //CB
	PRTC_QUALITY_B,
	PRTC_QUALITY_M,
	PRTC_QUALITY_E,
	PRTC_QUALITY_H
}ePRTCQualityLevel;

//ת�ƻ�����������
typedef enum {
	_RTMP_STREAM_ADD,	 //���
	_RTMP_STREAM_REMOVE,  //ɾ��
}ePRTCRtmpOpration;

//ת�Ƶ���
typedef struct RelayStream {
	const char* mUid;
	ePRTCMeidaType mType;
	RelayStream() {
		mUid = nullptr;
		mType = PRTC_MEDIATYPE_NONE;
	}
}tPRTCRelayStream;

//ת�ƻ�����������
typedef enum {
	PRTC_MIX_LAYOUT_OLD,       //����֮ǰģ��
	PRTC_MIX_LAYOUT_FLOW,	  //��ʽ����
	PRTC_MIX_LAYOUT_TEACH,	  //���β���
	PRTC_MIX_LAYOUT_CUSTOM,    //�Զ���
	PRTC_MIX_LAYOUT_ADAPTION1, //����ģʽ
	PRTC_MIX_LAYOUT_ADAPTION2, //����ģʽ
	PRTC_MIX_LAYOUT_ADAPTION3, //����ģʽ
}ePRTCMixLayout;

typedef int LayoutLsit[3];
//ת������
typedef struct TranscodeConfig {
	//����ɫ
	tPRTCBackgroundColor mbgColor; 
	//֡��
	int mFramerate;
	//����
	int mBitrate;   
	//�����˵�uid
	const char*  mMainViewUid; 
	//�����˷��õ�ý������
	int mMainviewType; 
	//����ֱ��ʿ��
	int mWidth; 
	//����ֱ��ʸ߶�
	int mHeight; 
	//�����б�
	LayoutLsit mlayouts;
	//��ǰʹ�õò��� 1.��ʽ���� 2.����ģʽ 3.�Զ��岼�� 4.ģ������Ӧ1 5.ģ������Ӧ2 6.����ģʽ
	ePRTCMixLayout mLayout;
	//mLayout=3 ʱ�Զ���������
	const char*  mStyle; 
	//�������û�
	tPRTCRelayStream *mStreams; 
	//�����û���
	int mStreamslength;
	//ˮӡλ��
	ePRTCWaterMarkPos mWatermarkPos;
	//ˮӡ����
	ePRTCWaterMarkType mWaterMarkType;
	//ˮӡurl  ΪͼƬˮӡʱ
	const char* mWatermarkUrl;
	//�Ƿ���Ƶ
	bool mIsAudio;
	//ģʽ
	ePRTCRelayMode mMode;
	//������(����������״̬����1���� ת���Զ�ֹͣ)
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

//¼����Ϣ
typedef struct RecordConfig {
	//¼�Ƶ������û�id
	const char* mMainviewuid;   
	//�洢bucket
	const char* mBucket;    
	//�洢region
	const char* mBucketRegion;  
	//¼��profile
	ePRTCRecordProfile mProfile;  
	//¼������
	ePRTCRecordType mRecordType;
	//ˮӡλ��
	ePRTCWaterMarkPos mWatermarkPos;
	//������ý������
	ePRTCMeidaType mMainviewmediatype; 
	//ˮӡ����
	ePRTCWaterMarkType mWaterMarkType;  
	//ˮӡurl  ΪͼƬˮӡʱ
	const char* mWatermarkUrl;	
	//�Ƿ���� (true .��ʽ���֣�false:����ģʽ)
	bool mIsaverage;		
	//ģ������
	int mMixerTemplateType;			

	//�������û�
	tPRTCRelayStream *mStreams;
	//�������û�����
	int mStreamslength; 
	// 0.ȡ����mIsaverage 1.��ʽ���� 2.����ģʽ 3.�Զ��岼�� 4.ģ������Ӧ1 5.ģ������Ӧ2
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
	PRTC_DEVICE_VIDEO,      //��Ƶ�豸
	PRTC_DEVICE_AUDIO,	 //��Ƶ�豸
}ePRTCDeviceType;

typedef struct 
{
	bool mIsInline;
	const char* mLogPath;
	const char* mLogName;
	ePRTCLogLevel mLogLevel;
	int mMaxReconnect;
}tPRTCInitContext;

//�豸��λص�
class _EXPORT_API PRTCDeviceChanged
{
public:
	///�����豸
	///@param dtype �豸����
	///@param dccname ����
	///@param len ����
	virtual void onInterfaceArrival(ePRTCDeviceType dtype,const char* dccname, int len) {}

	///�Ƴ��豸
	///@param dtype �豸����
	///@param dccname ����
	///@param len ����
	virtual void onInterfaceRemoved(ePRTCDeviceType dtype, const char* dccname, int len) {}

	///�豸���Ըı�
	///@param dtype �豸����
	///@param dccname �豸����
	///@param len ����
	virtual void onInterfaceChangeValue(ePRTCDeviceType dtype, const char* dccname, int len) {}
	virtual ~PRTCDeviceChanged() {}
};

//��Ƶ�����ص�
class  _EXPORT_API PRTCAudioFrameCallback
{
public:
	///������ƵԴ����callback
	///@param audioframe ��Ƶ����
	virtual void onLocalAudioFrame(tPRTCAudioFrame* audioframe) {}
	///Զ����ƵԴ����callback
	///@param audioframe ��Ƶ����
	virtual void onRemoteMixAudioFrame(tPRTCAudioFrame* audioframe) {}
	///���غ�Զ����ƵԴ����callback
	///@param audioframe ��Ƶ����
	virtual void onLoaclRemoteMixAudioFrame(tPRTCAudioFrame* audioframe) {}
};

//�ⲿ��ƵԴ(�ѷ��� ����IAudioFrameObserver )
class  _EXPORT_API PRTCExtendAudioCaptureSource
{
public:
	virtual ~PRTCExtendAudioCaptureSource() {}
	///��ƵԴ���� �ڲ����Զ����ô˽ӿ�
	///@param audioframe ��Ƶ����
	virtual  bool doCaptureAudioFrame(tPRTCAudioFrame* audioframe) = 0;
};

//�ⲿ��ƵԴ���ѷ��� ����IVideoFrameObserver��
class  _EXPORT_API PRTCExtendVideoCaptureSource
{
public:
	///��ƵԴ���� �ڲ����Զ����ô˽ӿ�
	///@param videoframe ��Ƶ֡
	virtual  bool doCaptureVideoFrame(tPRTCVideoFrame* videoframe) = 0;
};

//��Ƶ�豸startcapture�����ص�
class _EXPORT_API PRTCVideoFrameObserver 
{
public:
	///��Ƶ�ɼ����ݻص�
	///@param videoframe ��Ƶ����
	///@param buflen ����
	virtual  void onCaptureFrame(unsigned char* videoframe, int buflen) = 0;
};

//�ⲿ��Ⱦ
class _EXPORT_API PRTCExtendVideoRender
{
public:
	///�ⲿ��Ⱦ
	///@param videoframe �³�����Ƶ֡
	virtual  void onRemoteFrame(const tPRTCVideoFrame* videoframe) = 0;
};



//��Ƶ�����ص�
class _EXPORT_API PRTCIVideoFrameObserver
{
public:
	///��Ƶ�ɼ���ÿһ֡�ûص�
	///@param videoframe ��Ƶ����
	virtual  bool onCaptureFrame(tPRTCVideoFrame *videoFrame) = 0;
};

//��Ƶ�����ص�
class _EXPORT_API PRTCIAudioFrameObserver
{
public:
	///��Ƶ�ɼ���ÿһ֡�ûص�
	///@param  audioFrame ��Ƶ����
	virtual  bool onCaptureFrame(tPRTCAudioFrame* audioFrame) = 0;

};

#endif

