
// 421���в�ʧ������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy421���в�ʧ������App: 
// �йش����ʵ�֣������ 421���в�ʧ������.cpp
//

class CMy421���в�ʧ������App : public CWinApp
{
public:
	CMy421���в�ʧ������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy421���в�ʧ������App theApp;