// 填充颜色.cpp : 实现文件
//

#include "stdafx.h"
#include "420实验对话框确定颜色.h"
#include "填充颜色.h"
#include "afxdialogex.h"


// 填充颜色 对话框

IMPLEMENT_DYNAMIC(填充颜色, CDialogEx)

填充颜色::填充颜色(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, z(0)
{

}

填充颜色::~填充颜色()
{
}

void 填充颜色::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDV_MinMaxInt(pDX, x, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDV_MinMaxInt(pDX, y, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, z);
	DDV_MinMaxInt(pDX, z, 0, 255);
}


BEGIN_MESSAGE_MAP(填充颜色, CDialogEx)
END_MESSAGE_MAP()


// 填充颜色 消息处理程序
