
// 421��̬����ͼ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy421��̬����ͼ��App: 
// �йش����ʵ�֣������ 421��̬����ͼ��.cpp
//

class CMy421��̬����ͼ��App : public CWinApp
{
public:
	CMy421��̬����ͼ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy421��̬����ͼ��App theApp;