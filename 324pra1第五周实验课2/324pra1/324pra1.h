
// 324pra1.h : 324pra1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy324pra1App:
// �йش����ʵ�֣������ 324pra1.cpp
//

class CMy324pra1App : public CWinAppEx
{
public:
	CMy324pra1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy324pra1App theApp;
