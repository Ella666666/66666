
// ��һ����չʵ��ƴ���ַ���View.h : C��һ����չʵ��ƴ���ַ���View ��Ľӿ�
//

#pragma once


class C��һ����չʵ��ƴ���ַ���View : public CView
{
protected: // �������л�����
	C��һ����չʵ��ƴ���ַ���View();
	DECLARE_DYNCREATE(C��һ����չʵ��ƴ���ַ���View)

// ����
public:
	C��һ����չʵ��ƴ���ַ���Doc* GetDocument() const;

// ����
public:
	CString b;
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
	virtual ~C��һ����չʵ��ƴ���ַ���View();
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

#ifndef _DEBUG  // ��һ����չʵ��ƴ���ַ���View.cpp �еĵ��԰汾
inline C��һ����չʵ��ƴ���ַ���Doc* C��һ����չʵ��ƴ���ַ���View::GetDocument() const
   { return reinterpret_cast<C��һ����չʵ��ƴ���ַ���Doc*>(m_pDocument); }
#endif

