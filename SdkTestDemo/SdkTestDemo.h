
// SdkTestDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSdkTestDemoApp: 
// �йش����ʵ�֣������ SdkTestDemo.cpp
//

class CSdkTestDemoApp : public CWinApp
{
public:
	CSdkTestDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSdkTestDemoApp theApp;