
// 420ʵ��Ի���ȷ����ɫ.h : 420ʵ��Ի���ȷ����ɫ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy420ʵ��Ի���ȷ����ɫApp:
// �йش����ʵ�֣������ 420ʵ��Ի���ȷ����ɫ.cpp
//

class CMy420ʵ��Ի���ȷ����ɫApp : public CWinAppEx
{
public:
	CMy420ʵ��Ի���ȷ����ɫApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy420ʵ��Ի���ȷ����ɫApp theApp;
