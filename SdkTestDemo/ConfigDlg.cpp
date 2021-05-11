// ConfigDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "resource.h"
#include "ConfigDlg.h"
#include "afxdialogex.h"
#include "PRTCConfig.h"
#include "SdkUtil.h"


// CConfigDlg 对话框

IMPLEMENT_DYNAMIC(CConfigDlg, CDialogEx)

CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONFIG_DIALOG, pParent)
{
}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SECKEY, m_seckey);
	DDX_Control(pDX, IDC_CHECK_AUTOPUB, m_autopub);
	DDX_Control(pDX, IDC_CHECK_AUTOSUB, m_autosub);
	DDX_Control(pDX, IDC_CHECK_AUTOPUBV, m_pubvideo);
	DDX_Control(pDX, IDC_CHECK_AUTOPUBA, m_pubaudio);
	DDX_Control(pDX, IDC_CHECK_AUTOPUBS, m_pubscreen);
	DDX_Control(pDX, IDC_CHECK_PUBROLE, m_rolepub);
	DDX_Control(pDX, IDC_CHECK_SUBROLE, m_rolesub);
	DDX_Control(pDX, IDC_EDIT_APPID, m_appid);
	DDX_Control(pDX, IDC_CHECK_AUDIOONLY, m_audioonly);
	DDX_Control(pDX, IDC_COM_PROFILE, m_videoprofile);
	DDX_Radio(pDX, IDC_RADIO_NORMAL, m_sdkmode);
	DDX_Radio(pDX, IDC_RADIO_CH_C, m_chtype);
	DDX_Control(pDX, IDC_SEC_KEY, m_sectxt);
	DDX_Control(pDX, IDC_COM_CODEC, m_codectype);
    DDX_Control(pDX, IDC_COM_AUDIO_PROFILE, m_audioprofile);
}

BOOL CConfigDlg::OnInitDialog()
{
	ePRTCChannelType chtype = PRTCConfig::getInstance()->getChannelType();
	if (chtype == PRTC_CHANNEL_TYPE_COMMUNICATION)
	{
		m_chtype = 0;
	}
	else
	{
		m_chtype = 1;
	}

	ePRTCSdkMode sdkmode = PRTCConfig::getInstance()->getSdkMode();
	if (sdkmode == PRTC_SDK_MODE_NORMAL)
	{
		m_sdkmode = 0;
	}
	else
	{
		m_sdkmode = 1;
	}
	CDialogEx::OnInitDialog();
	m_videoprofile.InsertString(0, L"320*180");
	m_videoprofile.InsertString(1, L"320*240");
	m_videoprofile.InsertString(2, L"640*360");
	m_videoprofile.InsertString(3, L"640*480");
	m_videoprofile.InsertString(4, L"1280*720");
	m_videoprofile.InsertString(5, L"1920*1080");
	int select = ((int)PRTCConfig::getInstance()->getVideoProfile() ) -1;
	if (select<0 || select>5)
	{
		select = 0;
	}
	m_videoprofile.SetCurSel(select);

	m_seckey.SetWindowTextW(Ansi2WChar(PRTCConfig::getInstance()->getSecKey().data()).data());
	m_appid.SetWindowTextW(Ansi2WChar(PRTCConfig::getInstance()->getAppId().data()).data());

	bool audioonly = PRTCConfig::getInstance()->isAudioOnly();
	m_audioonly.SetCheck(audioonly? 1:0);
	if (audioonly)
	{
		m_videoprofile.EnableWindow(FALSE);
		m_pubscreen.EnableWindow(FALSE);
		m_pubvideo.EnableWindow(FALSE);

		m_pubaudio.SetCheck(PRTCConfig::getInstance()->isAutoPubAudio() ? 1 : 0);
	}
	else 
	{
		m_pubscreen.SetCheck(PRTCConfig::getInstance()->isAutoPubScreen()? 1:0);
		m_pubvideo.SetCheck(PRTCConfig::getInstance()->isAutoPubVideo() ? 1 : 0);
		m_pubaudio.SetCheck(PRTCConfig::getInstance()->isAutoPubAudio() ? 1 : 0);
	}

	m_autopub.SetCheck(PRTCConfig::getInstance()->isAutoPublish() ? 1 : 0);
	m_autosub.SetCheck(PRTCConfig::getInstance()->isAutoSubscribe() ? 1 : 0);

	ePRTCUserStreamRole role = PRTCConfig::getInstance()->getStreamRole();
	switch (role)
	{
	case PRTC_USER_STREAM_ROLE_PUB :
	{
		m_rolesub.SetCheck(0);
		m_rolepub.SetCheck(1);
	}
		break;
	case  PRTC_USER_STREAM_ROLE_SUB :
	{
		m_rolesub.SetCheck(1);
		m_rolepub.SetCheck(0);
	}
		break;
	case PRTC_USER_STREAM_ROLE_BOTH :
	{
		m_rolesub.SetCheck(1);
		m_rolepub.SetCheck(1);
	}
		break;
	default:
	{
		m_rolesub.SetCheck(1);
		m_rolepub.SetCheck(0);
	}
		break;
	}
	if (sdkmode == 0)
	{
		m_sectxt.ShowWindow(FALSE);
		m_seckey.ShowWindow(FALSE);
	}
	else
	{
		m_sectxt.ShowWindow(TRUE);
		m_seckey.ShowWindow(TRUE);
	}

	m_codectype.InsertString(0, L"VP8");
	m_codectype.InsertString(1, L"H264");

	m_codectype.SetCurSel(1);

    m_audioprofile.InsertString(0, L"Default");
    m_audioprofile.InsertString(1, L"Stand");
    m_audioprofile.InsertString(2, L"Stand_Stereo");
    m_audioprofile.InsertString(3, L"Hight"); 
    m_audioprofile.InsertString(4, L"Hight_Stereo");
    m_audioprofile.InsertString(5, L"Stand_Stereo_Disable_2A");
    m_audioprofile.InsertString(6, L"Hight_Disable_2A");
    m_audioprofile.InsertString(7, L"Hight_Stereo_Disable_2A");

    m_audioprofile.SetCurSel(PRTCConfig::getInstance()->getAudioProfile());
	return TRUE;
}

BEGIN_MESSAGE_MAP(CConfigDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CConfigDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_RADIO_NORMAL, &CConfigDlg::OnBnClickedRadioNormal)
	ON_BN_CLICKED(IDC_RADIO_TRIVAL, &CConfigDlg::OnBnClickedRadioNormal)
	ON_BN_CLICKED(IDC_RADIO_CH_C, &CConfigDlg::OnBnClickedRadioChC)
	ON_BN_CLICKED(IDC_RADIO_LIVE, &CConfigDlg::OnBnClickedRadioChC)
	ON_BN_CLICKED(IDC_CHECK_AUDIOONLY, &CConfigDlg::OnBnClickedCheckAudioonly)
	ON_STN_CLICKED(IDC_SEC_KEY, &CConfigDlg::OnStnClickedSecKey)
	ON_BN_CLICKED(IDC_CHECK_PUBROLE, &CConfigDlg::OnBnClickedCheckPubrole)
	ON_BN_CLICKED(IDC_CHECK_SUBROLE, &CConfigDlg::OnBnClickedCheckSubrole)
END_MESSAGE_MAP()


// CConfigDlg 消息处理程序
void CConfigDlg::OnPaint()
{
	CDialogEx::OnPaint();
}

void CConfigDlg::OnBnClickedButtonSave()
{
	PRTCConfig::getInstance()->setSdkMode((ePRTCSdkMode)m_sdkmode);
	PRTCConfig::getInstance()->setChannelType((ePRTCChannelType)m_chtype);
	CString appid;
	m_appid.GetWindowTextW(appid);
	std::string appistr = WChatToUTF8Str(appid.GetBuffer());
	if (appistr.length()>0)
	{
		PRTCConfig::getInstance()->setAppId(appistr);
	}

	if (m_sdkmode == 1)
	{
		CString seckey;
		m_seckey.GetWindowTextW(seckey);
		std::string keystr = WChatToUTF8Str(seckey.GetBuffer());
		if (keystr.length() > 0)
		{
			PRTCConfig::getInstance()->setSecKey(keystr);
		}
	}

	PRTCConfig::getInstance()->setVideoProfile((ePRTCVideoProfile)
		(m_videoprofile.GetCurSel() +1) );

	int pubrcheck = m_rolepub.GetCheck();
	int subrcheck = m_rolesub.GetCheck();

	if (m_chtype == 1)
	{
		if (pubrcheck && subrcheck)
		{
			PRTCConfig::getInstance()->setStreamRole(PRTC_USER_STREAM_ROLE_BOTH);
		}
		else if (pubrcheck)
		{
			PRTCConfig::getInstance()->setStreamRole(PRTC_USER_STREAM_ROLE_PUB);
		}
		else if (subrcheck)
		{
			PRTCConfig::getInstance()->setStreamRole(PRTC_USER_STREAM_ROLE_SUB);
		}
		else
		{
			PRTCConfig::getInstance()->setStreamRole(PRTC_USER_STREAM_ROLE_SUB);
		}
		
	}
	else {
		if (pubrcheck && subrcheck)
		{
			PRTCConfig::getInstance()->setStreamRole(PRTC_USER_STREAM_ROLE_BOTH);
		}else if (pubrcheck)
		{
			PRTCConfig::getInstance()->setStreamRole(PRTC_USER_STREAM_ROLE_PUB);
		}else if (subrcheck)
		{
			PRTCConfig::getInstance()->setStreamRole(PRTC_USER_STREAM_ROLE_SUB);
		}
		else 
		{
			PRTCConfig::getInstance()->setStreamRole(PRTC_USER_STREAM_ROLE_SUB);
		}
	}

	int audioonly = m_audioonly.GetCheck();
	if (audioonly)
	{
		PRTCConfig::getInstance()->setAudioOnly(true);
	}
	else {
		PRTCConfig::getInstance()->setAudioOnly(false);
	}

	int autopub = m_autopub.GetCheck();
	if (autopub)
	{
		PRTCConfig::getInstance()->setAutoPublish(true);
	}
	else {
		PRTCConfig::getInstance()->setAutoPublish(false);
	}

	int autosub = m_autosub.GetCheck();
	if (autosub)
	{
		PRTCConfig::getInstance()->setAutoSubscribe(true);
	}
	else {
		PRTCConfig::getInstance()->setAutoSubscribe(false);
	}

	int pubvideo = m_pubvideo.GetCheck();
	if (pubvideo)
	{
		PRTCConfig::getInstance()->setAutoPubVideo(true);
	}
	else {
		PRTCConfig::getInstance()->setAutoPubVideo(false);
	}

	int pubaudio = m_pubaudio.GetCheck();
	if (pubaudio)
	{
		PRTCConfig::getInstance()->setAutoPubAudio(true);
	}
	else {
		PRTCConfig::getInstance()->setAutoPubAudio(false);
	}

	int pubscreen = m_pubscreen.GetCheck();
	if (pubscreen)
	{
		PRTCConfig::getInstance()->setAutoPubScreen(true);
	}
	else {
		PRTCConfig::getInstance()->setAutoPubScreen(false);
	}

	PRTCConfig::getInstance()->setCodecType((ePRTCVideoCodec)
		(m_codectype.GetCurSel() + 1));
	
    PRTCConfig::getInstance()->setAudioProfile((ePRTCAudioProfile)m_audioprofile.GetCurSel());
	CDialogEx::OnOK();
}


void CConfigDlg::OnBnClickedRadioNormal()
{
	UpdateData(TRUE);
	if (m_sdkmode == 1)
	{
		m_sectxt.ShowWindow(TRUE);
		m_seckey.ShowWindow(TRUE);
	}
	else 
	{
		m_sectxt.ShowWindow(FALSE);
		m_seckey.ShowWindow(FALSE);
	}
}


void CConfigDlg::OnBnClickedRadioChC()
{
	UpdateData(TRUE);
	int pubrcheck = m_rolepub.GetCheck();
	int subrcheck = m_rolesub.GetCheck();


	m_rolepub.SetCheck(1);
	m_rolesub.SetCheck(1);

}


void CConfigDlg::OnBnClickedCheckAudioonly()
{
	UpdateData(TRUE);
	int checked = m_audioonly.GetCheck();
	if (checked == 0)
	{
		m_videoprofile.EnableWindow(TRUE);
		m_pubscreen.EnableWindow(TRUE);
		m_pubvideo.EnableWindow(TRUE);
	}
	else 
	{
		m_videoprofile.EnableWindow(FALSE);
		m_pubscreen.EnableWindow(FALSE);
		m_pubvideo.EnableWindow(FALSE);
	}
}


void CConfigDlg::OnStnClickedSecKey()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CConfigDlg::OnBnClickedCheckPubrole()
{
	/*if (m_chtype == 1)
	{
		if (m_rolesub.GetCheck())
		{
			m_rolesub.SetCheck(0);
		}
	}*/
}


void CConfigDlg::OnBnClickedCheckSubrole()
{
	/*if (m_chtype == 1)
	{
		if (m_rolepub.GetCheck())
		{
			m_rolepub.SetCheck(0);
		}
	}*/
}
