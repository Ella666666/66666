
// ��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����View.h : C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����View ��Ľӿ�
//

#pragma once


class C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����View : public CView
{
protected: // �������л�����
	C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����View();
	DECLARE_DYNCREATE(C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����View)

// ����
public:
	C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����View.cpp �еĵ��԰汾
inline C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����Doc* C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����View::GetDocument() const
   { return reinterpret_cast<C��һ��ʵ��1��Doc���м��ַ������Ա����ʼ��Ϊѧ�����֣������������ʾ����Doc*>(m_pDocument); }
#endif

