
// 421exp1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy421exp1App: 
// �йش����ʵ�֣������ 421exp1.cpp
//

class CMy421exp1App : public CWinApp
{
public:
	CMy421exp1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy421exp1App theApp;