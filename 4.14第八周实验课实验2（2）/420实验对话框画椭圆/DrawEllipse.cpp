// DrawEllipse.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "420ʵ��Ի�����Բ.h"
#include "DrawEllipse.h"
#include "afxdialogex.h"


// DrawEllipse �Ի���

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


// DrawEllipse ��Ϣ�������
