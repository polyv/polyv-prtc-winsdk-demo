// VideoFullDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VideoFullDlg.h"
#include "afxdialogex.h"


// VideoFullDlg �Ի���

IMPLEMENT_DYNAMIC(VideoFullDlg, CDialogEx)

VideoFullDlg::VideoFullDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(VideoFullDlg::IDD, pParent)
{

}

VideoFullDlg::~VideoFullDlg()
{
}

void VideoFullDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(VideoFullDlg, CDialogEx)
END_MESSAGE_MAP()


// VideoFullDlg ��Ϣ�������


BOOL VideoFullDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	int cx,cy; 
	cx = GetSystemMetrics(SM_CXSCREEN); 
	cy = GetSystemMetrics(SM_CYSCREEN); 
	CRect rcTemp; 
	rcTemp.BottomRight() = CPoint(cx, cy); 
	rcTemp.TopLeft() = CPoint(0, 0); 
	MoveWindow(&rcTemp);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
//
void VideoFullDlg::BindChild(CVideoWnd* pDlg)
{
	if (NULL != pDlg)
	{
		CRect rc;
		GetClientRect(&rc);
		::SetParent(pDlg->GetVideoHwnd(), this->GetSafeHwnd());
		::MoveWindow(pDlg->GetVideoHwnd(), rc.left, rc.top,
			(rc.right - rc.left), (rc.bottom - rc.top), false);
	}
}


BOOL VideoFullDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
	{
		//�ж��Ƿ��¼���Enter��
		if(pMsg->wParam== VK_ESCAPE)
		{
			//Do anything what you want to
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
