
// ��һ��ʵ��2������ͳ���Ҽ������ʾ.h : ��һ��ʵ��2������ͳ���Ҽ������ʾ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��һ��ʵ��2������ͳ���Ҽ������ʾApp:
// �йش����ʵ�֣������ ��һ��ʵ��2������ͳ���Ҽ������ʾ.cpp
//

class C��һ��ʵ��2������ͳ���Ҽ������ʾApp : public CWinAppEx
{
public:
	C��һ��ʵ��2������ͳ���Ҽ������ʾApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��һ��ʵ��2������ͳ���Ҽ������ʾApp theApp;
