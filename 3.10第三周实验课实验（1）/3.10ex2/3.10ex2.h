
// 3.10ex2.h : 3.10ex2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy310ex2App:
// �йش����ʵ�֣������ 3.10ex2.cpp
//

class CMy310ex2App : public CWinApp
{
public:
	CMy310ex2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy310ex2App theApp;
