
// 3.9ex1.h : 3.9ex1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy39ex1App:
// �йش����ʵ�֣������ 3.9ex1.cpp
//

class CMy39ex1App : public CWinApp
{
public:
	CMy39ex1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy39ex1App theApp;
