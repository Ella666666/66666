
// 317pra1.h : 317pra1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy317pra1App:
// �йش����ʵ�֣������ 317pra1.cpp
//

class CMy317pra1App : public CWinApp
{
public:
	CMy317pra1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy317pra1App theApp;
