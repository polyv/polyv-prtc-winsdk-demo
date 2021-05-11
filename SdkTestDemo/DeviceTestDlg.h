#pragma once


// CDeviceTestDlg dialog
#include "PRTCComDefine.h"
#include "IPRTCMediaDevice.h"

#include "VideoWnd.h"
#include <vector>
#include "afxwin.h"
#include "afxcmn.h"

class MediaCallback : public PRTCAudioLevelListener {
public:
	virtual void onMicAudioLevel(int volume) {
		::PostMessage(msgwnd, 10001, volume, 0);
	}

	MediaCallback(HWND wnd) {
		this->msgwnd = wnd;
	}
	HWND msgwnd;
};

class CDeviceTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeviceTestDlg)

public:
	CDeviceTestDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDeviceTestDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum {
		IDD = IDD_DEVICE_DIALOG
};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void  OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	DECLARE_MESSAGE_MAP()

	std::vector<tPRTCDeviceInfo> m_videolist;
	std::vector<tPRTCDeviceInfo> m_miclist;
	std::vector<tPRTCDeviceInfo> m_spkeakerlist;
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonCamTest();
	afx_msg void OnBnClickedButtonMicTest();
	afx_msg void OnBnClickedButtonSpeakerTest();

	afx_msg LRESULT OnAudioVol(WPARAM data, LPARAM lp);

	CComboBox m_videocom;
	CComboBox m_miccom;
	CProgressCtrl m_micenypro;
	CStatic m_videoview;
	CVideoWnd* m_videownd;

	bool m_videotest;
	bool m_mictest;
	bool m_speakertest;

	CListBox m_userlist;
	MediaCallback* m_mediacallback;
	IPRTCMediaDevice* m_mediadevice;
	
	CComboBox m_speaker;
	CSliderCtrl m_micvol;
	CSliderCtrl m_speakervol;
};
