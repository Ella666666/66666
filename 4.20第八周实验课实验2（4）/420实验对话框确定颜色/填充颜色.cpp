// �����ɫ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "420ʵ��Ի���ȷ����ɫ.h"
#include "�����ɫ.h"
#include "afxdialogex.h"


// �����ɫ �Ի���

IMPLEMENT_DYNAMIC(�����ɫ, CDialogEx)

�����ɫ::�����ɫ(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, z(0)
{

}

�����ɫ::~�����ɫ()
{
}

void �����ɫ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDV_MinMaxInt(pDX, x, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDV_MinMaxInt(pDX, y, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, z);
	DDV_MinMaxInt(pDX, z, 0, 255);
}


BEGIN_MESSAGE_MAP(�����ɫ, CDialogEx)
END_MESSAGE_MAP()


// �����ɫ ��Ϣ�������
