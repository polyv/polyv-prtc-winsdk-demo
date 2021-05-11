#pragma once
#include "afxwin.h"


// CConfigDlg �Ի���

class CConfigDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConfigDlg)

public:
	CConfigDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConfigDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONFIG_DIALOG
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButtonSave();

	CEdit m_seckey;
	CButton m_autopub;
	CButton m_autosub;
	CButton m_pubvideo;
	CButton m_pubaudio;
	CButton m_pubscreen;
	CButton m_rolepub;
	CButton m_rolesub;
	CEdit m_appid;
	CButton m_audioonly;

	CComboBox m_videoprofile;
	CComboBox m_codectype;
    CComboBox m_audioprofile;
	int m_sdkmode;
	int m_chtype;
	afx_msg void OnBnClickedRadioNormal();
	afx_msg void OnBnClickedRadioChC();
	CStatic m_sectxt;
	afx_msg void OnBnClickedCheckAudioonly();
	afx_msg void OnStnClickedSecKey();
	afx_msg void OnBnClickedCheckPubrole();
	afx_msg void OnBnClickedCheckSubrole();
};
