// MOD_DLG.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验三.h"
#include "MOD_DLG.h"
#include "afxdialogex.h"


// MOD_DLG 对话框

IMPLEMENT_DYNAMIC(MOD_DLG, CDialogEx)

MOD_DLG::MOD_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MOD, pParent)
	, i(0)
{

}

MOD_DLG::~MOD_DLG()
{
}

void MOD_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, i);
}


BEGIN_MESSAGE_MAP(MOD_DLG, CDialogEx)
END_MESSAGE_MAP()


// MOD_DLG 消息处理程序
