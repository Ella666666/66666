
// ������ʵ���ʵ��3.h : ������ʵ���ʵ��3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C������ʵ���ʵ��3App:
// �йش����ʵ�֣������ ������ʵ���ʵ��3.cpp
//

class C������ʵ���ʵ��3App : public CWinAppEx
{
public:
	C������ʵ���ʵ��3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C������ʵ���ʵ��3App theApp;
