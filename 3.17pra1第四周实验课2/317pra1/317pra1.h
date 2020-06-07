
// 317pra1.h : 317pra1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMy317pra1App:
// 有关此类的实现，请参阅 317pra1.cpp
//

class CMy317pra1App : public CWinApp
{
public:
	CMy317pra1App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy317pra1App theApp;
