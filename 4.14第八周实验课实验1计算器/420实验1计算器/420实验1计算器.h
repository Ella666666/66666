
// 420ʵ��1������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy420ʵ��1������App: 
// �йش����ʵ�֣������ 420ʵ��1������.cpp
//

class CMy420ʵ��1������App : public CWinApp
{
public:
	CMy420ʵ��1������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy420ʵ��1������App theApp;