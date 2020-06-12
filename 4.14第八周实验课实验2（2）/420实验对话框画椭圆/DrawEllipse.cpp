// DrawEllipse.cpp : 实现文件
//

#include "stdafx.h"
#include "420实验对话框画椭圆.h"
#include "DrawEllipse.h"
#include "afxdialogex.h"


// DrawEllipse 对话框

IMPLEMENT_DYNAMIC(DrawEllipse, CDialogEx)

DrawEllipse::DrawEllipse(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x1(0)
	, y1(0)
	, x2(0)
	, y2(0)
{

}

DrawEllipse::~DrawEllipse()
{
}

void DrawEllipse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT2, y1);
	DDX_Text(pDX, IDC_EDIT3, x2);
	DDX_Text(pDX, IDC_EDIT4, y2);
}


BEGIN_MESSAGE_MAP(DrawEllipse, CDialogEx)
END_MESSAGE_MAP()


// DrawEllipse 消息处理程序
