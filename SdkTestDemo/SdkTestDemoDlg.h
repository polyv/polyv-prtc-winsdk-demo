
// SdkTestDemoDlg.h : ͷ�ļ�
//

#pragma once

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

#include "VideoWnd.h"
#include "VideoFullDlg.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "RTCEngineFactory.h"
#include "VideoPackageQueue.h"
#include "PRTCComDefine.h"
#include "IPRTCMediaDevice.h"
#include "ExtendMediaCaptuer.h"
// CSdkTestDemoDlg �Ի���
class CSdkTestDemoDlg : 
	public CDialogEx, 
	public CVideoWndCallback,
	public PRTCVideoFrameObserver,
	public PRTCExtendVideoCaptureSource,
	public PRTCDeviceChanged
{
// ����
public:
	CSdkTestDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

	//cvideowndcallback
	void OnMuteAudio(std::string userid, ePRTCMeidaType mediatype, bool mute);
	void OnMuteVideo(std::string userid, ePRTCMeidaType mediatype, bool mute);
	void OnCloseMedia(std::string type, std::string id);

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum {IDD = IDD_SFU};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg LRESULT OnPRTCMsg(WPARAM data, LPARAM lp);
	afx_msg LRESULT OnVideoFrameCallback(WPARAM data, LPARAM lp);

	afx_msg void OnBnClickedButtonPubC();
	afx_msg void OnBnClickedButtonLeaveroom();
	afx_msg void OnBnClickedButtonPubs();

	//PRTCvideoframeobserver
	virtual  void onCaptureFrame(unsigned char* videoframe, int buflen);

	//extendcapture
	virtual  bool doCaptureVideoFrame(tPRTCVideoFrame* videoframe);

	//device change call back
	virtual void onInterfaceArrival(const char* dccname, int len);
	virtual void onInterfaceRemoved(const char* dccname, int len);


private:
	CVideoWnd* CreateVideoWindow(ePRTCMeidaType type, int x, int y, int w, int h);

	void InitPRTCConfig();

	void OnJoinRoomHandler(std::string jsonmsg);
	void OnReJoinFailHandler(std::string jsonmsg);
	void OnReJoinRoomHandler(std::string jsonmsg);
	void OnLeaveRoomHandler(std::string jsonmsg);

	void OnPulibshStreamHandler(std::string jsonmsg);
	void OnPulibshCamStreamHandler(std::string jsonmsg);
	void OnPulibshScreenStreamHandler(std::string jsonmsg);

	void OnUnPulibshStreamHandler(std::string jsonmsg);
	void OnUnPulibshStreamScreenHandler(std::string jsonmsg);
	void OnUnPulibshStreamCamHandler(std::string jsonmsg);

	void OnSubStreamHandler(std::string jsonmsg);
	void OnUnSubStreamHandler(std::string jsonmsg);

	void OnStreamStHandler(std::string jsonmsg);
	void OnUserStHandler(std::string jsonmsg);

	void OnServerReconnectingHandler(std::string jsonmsg);
	void OnServerDisconnectHandler(std::string jsonmsg);

	void OnSdkErrorHandler(std::string jsonmsg);
	void OnKickoffHandler(std::string jsonmsg);

	void OnLocalStreamMuteHandler(std::string jsonmsg);
	void OnRemoteStreamMuteHandler(std::string jsonmsg);
	void OnRemoteTrackStNotify(std::string jsonmsg);

	void OnRemoteAudioVolHandler(std::string jsonmsg);
	void OnLocalAudioVolHandler(std::string jsonmsg);

	void OnRemoteStHandler(std::string jsonmsg);
	void OnSendStHandler(std::string jsonmsg);

	void OnStartRecord(std::string jsonmsg);
	void OnStopRecord(std::string jsonmsg);

	void OnRecvNetworkQuality(std::string jsonmsg);
	void OnRtmpStateChanged(std::string jsonmsg);

	//�û��뿪 �ͷ�������Դ
	void ReleaseUserAllRes();
	void SubscribeAllStream();
	void SubscribeStream(int mediatype, std::string uid);
	void UnSubscribeStream(int mediatype, std::string uid);
	void UserLeave(std::string uid);
	void OnLeaveRoom();
	void OnMessageShow(std::string msg);

    void UpdateCDN();
public:
	CListBox m_msglist;
	CButton m_videocheck;
	CButton m_audiocheck;

	VideoFullDlg* _pFullScreenDlg;
	RTCEngineBase* m_rtcengine;

	std::string m_userid;      // �Լ��û�id
	std::string m_roomid;     // roomid
	std::string m_roomtoken; //��֤token

	std::map<std::string, tUserInfo*>   m_hashSessions;//userid<---> userinfo
	std::map<std::string, tStreamInfo*> m_streamsmap;//userid+mediatype<---> streaminfo �����б��Ӧ
	std::map<std::string, CVideoWnd*>   m_mapRenders; //userid+mediatype<----> videorender
	CVideoWnd *m_localWnd;
	CVideoWnd *m_screenWnd;
	std::list<CVideoWnd*> m_remoteWnds; //����wnd Ԥ����
	bool m_campub;
	bool m_screenpub;
	bool m_leaveroom;
	bool m_isclose;
	bool m_startrecord;
	bool m_startaudiomix;
	bool m_startrelay;
	afx_msg void OnBnClickedButtonRecord();
	afx_msg void OnBnClickedButtonMixfile();
	afx_msg void OnBnClickedButtonRelay();
	CEdit m_rtsp1;
	CEdit m_rtsp2;
	unsigned char* m_lpImageBuffer;
	IPRTCMediaDevice* m_mediadevice;
	HANDLE m_audiopushthread;
	
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnBnClickedButtonLianmai();
    std::vector<std::string> playout_devices;
};
