
// 413ʵ��.h : 413ʵ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy413ʵ��App:
// �йش����ʵ�֣������ 413ʵ��.cpp
//

class CMy413ʵ��App : public CWinAppEx
{
public:
	CMy413ʵ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy413ʵ��App theApp;
