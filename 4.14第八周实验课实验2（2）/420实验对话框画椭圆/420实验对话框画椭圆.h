
// 420ʵ��Ի�����Բ.h : 420ʵ��Ի�����Բ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy420ʵ��Ի�����ԲApp:
// �йش����ʵ�֣������ 420ʵ��Ի�����Բ.cpp
//

class CMy420ʵ��Ի�����ԲApp : public CWinAppEx
{
public:
	CMy420ʵ��Ի�����ԲApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy420ʵ��Ի�����ԲApp theApp;
