#ifndef _IPRTC_MEDIA_DEVICE_CPP_H_
#define _IPRTC_MEDIA_DEVICE_CPP_H_
#include "PRTCComDefine.h"


class  _EXPORT_API PRTCAudioLevelListener
{
public:
	///�ص���Ƶ����
	///@param volume
	virtual void onMicAudioLevel(int volume) {}
};

class _EXPORT_API IPRTCMediaDevice 
{
public:
	static IPRTCMediaDevice *sharedInstance();
	static void destory();

	///��ʼ����Ƶģ��
	///@return 0 succ
	virtual int InitAudioMoudle() =0;

	///�ͷ���Ƶģ��
	///@return 0 succ
	virtual int UnInitAudioMoudle() = 0;

	///��ʼ����Ƶģ��
	///@return 0 succ
	virtual int InitVideoMoudle() = 0;

	///�ͷ���Ƶģ��
	///@return 0 succ
	virtual int UnInitVideoMoudle() = 0;

	///��ȡ����ͷ��Ŀ
	///@return ��Ŀ
	virtual int getCamNums() = 0;

	///��ȡ¼���豸��Ŀ
	///@return ��Ŀ
	virtual int getRecordDevNums() = 0;

	///��ȡ�����豸��Ŀ
	///@return ��Ŀ
	virtual int getPlayoutDevNums() = 0;

	///��ȡ����ͷ��Ϣ
	///@param index id
	///@param out info �豸��Ϣ
	///@return 0 succ
	virtual int getVideoDevInfo(int index, tPRTCDeviceInfo* info) = 0;

	///��ȡ¼���豸��Ϣ
	///@param index id
	///@param out info �豸��Ϣ
	///@return 0 succ
	virtual int getRecordDevInfo(int index, tPRTCDeviceInfo* info) = 0;

	///��ȡ�����豸��Ϣ
	///@param index id
	///@param out info �豸��Ϣ
	///@return 0 succ
	virtual int getPlayoutDevInfo(int index, tPRTCDeviceInfo* info) = 0;

	///��ȡ��ǰ����ͷ
	///@param out info �豸��Ϣ
	///@return 0 succ
	virtual int getCurCamDev(tPRTCDeviceInfo* info) = 0;

	///��ȡ��ǰ¼���豸
	///@param out info �豸��Ϣ
	///@return 0 succ
	virtual int getCurRecordDev(tPRTCDeviceInfo* info) = 0;

	///��ȡ��ǰ�����豸
	///@param out info �豸��Ϣ
	///@return 0 succ
	virtual int getCurPlayoutDev(tPRTCDeviceInfo* info) = 0;

	///������Ƶ�豸��Ϣ
	///@param in info �豸��Ϣ
	///@return 0 succ
	virtual int setVideoDevice(tPRTCDeviceInfo* info) = 0;

	///����¼���豸��Ϣ
	///@param in info �豸��Ϣ
	///@return 0 succ
	virtual int setRecordDevice(tPRTCDeviceInfo* info) = 0;

	///���ò����豸��Ϣ
	///@param in info �豸��Ϣ
	///@return 0 succ
	virtual int setPlayoutDevice(tPRTCDeviceInfo* info) = 0;

	///��ȡ��������
	virtual int getPlaybackDeviceVolume(int *volume) = 0;
	virtual int setPlaybackDeviceVolume(int volume) = 0;

	///��ȡ¼������
	virtual int getRecordingDeviceVolume(int *volume) = 0;
	virtual int setRecordingDeviceVolume(int volume) = 0;

	///����cam����
	///@param  deviceId �豸ID
	///@param  profile profile
	///@param  hwnd ���
	///@return 0 succ
	virtual int startCamTest(const char deviceId[MAX_DEVICE_ID_LENGTH], 
		ePRTCVideoProfile profile,
		void* hwnd) = 0;

	///ֹͣ����ͷ����
	///@return 0 succ
	virtual int stopCamTest() = 0;

	///����¼������
	///@param  audiolevel �ص�ʵ��
	virtual int startRecordingDeviceTest(PRTCAudioLevelListener* audiolevel) = 0;

	///ֹͣ¼������
	virtual int stopRecordingDeviceTest() = 0;

	///���������豸����
	///@param  testAudioFilePath �ļ�·��
	virtual int startPlaybackDeviceTest(const char* testAudioFilePath) = 0;

	///ֹͣ�����豸����
	virtual int stopPlaybackDeviceTest() = 0;

	///��������ͷCapture����
	///@param  profile �ֱ���
	///@param  observer �ص�ʵ��
	virtual int startCaptureFrame(ePRTCVideoProfile profile,
		PRTCVideoFrameObserver* observer) = 0;

	///ֹͣ����ͷCapture����
	virtual int stopCaptureFrame() = 0;
protected:
	IPRTCMediaDevice() { }
	virtual ~IPRTCMediaDevice() {}
};

#endif






