
// 3.16Pra1.h : 3.16Pra1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy316Pra1App:
// �йش����ʵ�֣������ 3.16Pra1.cpp
//

class CMy316Pra1App : public CWinApp
{
public:
	CMy316Pra1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy316Pra1App theApp;
