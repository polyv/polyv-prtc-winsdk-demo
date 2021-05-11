#pragma once
#include "VideoWnd.h"

// VideoFullDlg �Ի���

class VideoFullDlg : public CDialogEx
{
	DECLARE_DYNAMIC(VideoFullDlg)

public:
	VideoFullDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~VideoFullDlg();

// �Ի�������
	enum 
	{
		IDD = IDD_VIDEO_WND_FULL
	};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void BindChild(CVideoWnd* pDlg);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
