
// 323pra1.h : 323pra1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy323pra1App:
// �йش����ʵ�֣������ 323pra1.cpp
//

class CMy323pra1App : public CWinApp
{
public:
	CMy323pra1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy323pra1App theApp;
