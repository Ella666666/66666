
// �ڰ���ʵ���ʵ��2.3.h : �ڰ���ʵ���ʵ��2.3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڰ���ʵ���ʵ��23App:
// �йش����ʵ�֣������ �ڰ���ʵ���ʵ��2.3.cpp
//

class C�ڰ���ʵ���ʵ��23App : public CWinAppEx
{
public:
	C�ڰ���ʵ���ʵ��23App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڰ���ʵ���ʵ��23App theApp;
