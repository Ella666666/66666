
// �ھ��ܿ���ʵ��1��.h : �ھ��ܿ���ʵ��1�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ھ��ܿ���ʵ��1��App:
// �йش����ʵ�֣������ �ھ��ܿ���ʵ��1��.cpp
//

class C�ھ��ܿ���ʵ��1��App : public CWinAppEx
{
public:
	C�ھ��ܿ���ʵ��1��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ھ��ܿ���ʵ��1��App theApp;
