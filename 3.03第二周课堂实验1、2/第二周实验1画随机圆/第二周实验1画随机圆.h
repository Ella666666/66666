
// �ڶ���ʵ��1�����Բ.h : �ڶ���ʵ��1�����Բ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڶ���ʵ��1�����ԲApp:
// �йش����ʵ�֣������ �ڶ���ʵ��1�����Բ.cpp
//

class C�ڶ���ʵ��1�����ԲApp : public CWinAppEx
{
public:
	C�ڶ���ʵ��1�����ԲApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڶ���ʵ��1�����ԲApp theApp;
