// EnlargeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ����.h"
#include "EnlargeDlg.h"
#include "afxdialogex.h"


// EnlargeDlg �Ի���

IMPLEMENT_DYNAMIC(EnlargeDlg, CDialogEx)

EnlargeDlg::EnlargeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}
BOOL EnlargeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	InvalidateRect(rect);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
EnlargeDlg::~EnlargeDlg()
{
}

void EnlargeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EnlargeDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// EnlargeDlg ��Ϣ�������


void EnlargeDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	draw_pic(filepath);
}
void  EnlargeDlg::draw_pic(CString filename)
{
	CImage img;
	img.Load(filename);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_radio = 1.0 * rect.Width() / rect.Height();
	float image_radio = 1.0 * img.GetWidth() / img.GetHeight();

	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);

}