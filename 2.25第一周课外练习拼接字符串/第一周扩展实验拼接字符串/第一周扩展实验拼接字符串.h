
// ��һ����չʵ��ƴ���ַ���.h : ��һ����չʵ��ƴ���ַ��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��һ����չʵ��ƴ���ַ���App:
// �йش����ʵ�֣������ ��һ����չʵ��ƴ���ַ���.cpp
//

class C��һ����չʵ��ƴ���ַ���App : public CWinAppEx
{
public:
	C��һ����չʵ��ƴ���ַ���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��һ����չʵ��ƴ���ַ���App theApp;
