
// �ڶ���ʵ���1.h : �ڶ���ʵ���1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڶ���ʵ���1App:
// �йش����ʵ�֣������ �ڶ���ʵ���1.cpp
//

class C�ڶ���ʵ���1App : public CWinAppEx
{
public:
	C�ڶ���ʵ���1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڶ���ʵ���1App theApp;
