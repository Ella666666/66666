// A���ģ��.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ����.h"
#include "A���ģ��.h"
#include "afxdialogex.h"


// A���ģ�� �Ի���

IMPLEMENT_DYNAMIC(A���ģ��, CDialogEx)

A���ģ��::A���ģ��(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, l(_T(""))
	, num2(_T(""))
	, name2(_T(""))
	, specia2(_T(""))
	, sex(_T(""))
	, birth2(0)
	, phone2(_T(""))
	, address(_T(""))
	, picpath2(_T(""))
{

}

A���ģ��::~A���ģ��()
{
}

void A���ģ��::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, l);
	DDX_Text(pDX, IDC_EDIT3, num2);
	DDX_Text(pDX, IDC_EDIT10, name2);
	DDX_Text(pDX, IDC_EDIT2, specia2);
	DDX_Text(pDX, IDC_EDIT4, sex);
	DDX_Text(pDX, IDC_EDIT7, birth2);
	DDX_Text(pDX, IDC_EDIT6, phone2);
	DDX_Text(pDX, IDC_EDIT8, address);
	DDX_Text(pDX, IDC_EDIT9, picpath2);
}


BEGIN_MESSAGE_MAP(A���ģ��, CDialogEx)
END_MESSAGE_MAP()


// A���ģ�� ��Ϣ�������
