// PIC_DLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ����.h"
#include "PIC_DLG.h"
#include "afxdialogex.h"


// PIC_DLG �Ի���

IMPLEMENT_DYNAMIC(PIC_DLG, CDialogEx)

PIC_DLG::PIC_DLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

PIC_DLG::~PIC_DLG()
{
}

void PIC_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PIC_DLG, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// PIC_DLG ��Ϣ�������

void PIC_DLG::draw_pic()
{
	CRect rect;
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//IDC_pictureΪpicture�ؼ�ID
	pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С
	CImage img;
	img.Load(path);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	if (!img.IsNull())
	{
		int w, h, sx, sy;
		float r_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
		if (r_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
		img.Draw(pDC->m_hDC, sx, sy, w, h);
	}

	else
	{
		pDC->TextOutW(20, 20, _T("ͼƬ������"));
	}
}

void PIC_DLG::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	draw_pic();
}
