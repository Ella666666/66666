
// 421���ݵ����л�.h : 421���ݵ����л� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy421���ݵ����л�App:
// �йش����ʵ�֣������ 421���ݵ����л�.cpp
//

class CMy421���ݵ����л�App : public CWinApp
{
public:
	CMy421���ݵ����л�App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy421���ݵ����л�App theApp;
