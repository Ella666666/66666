
// 318Pra2.h : 318Pra2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy318Pra2App:
// �йش����ʵ�֣������ 318Pra2.cpp
//

class CMy318Pra2App : public CWinApp
{
public:
	CMy318Pra2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy318Pra2App theApp;
