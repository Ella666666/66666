
// 331pra.h : 331pra Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy331praApp:
// �йش����ʵ�֣������ 331pra.cpp
//

class CMy331praApp : public CWinAppEx
{
public:
	CMy331praApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy331praApp theApp;
