
// 2.2.4View.h : CMy224View ��Ľӿ�
//

#pragma once


class CMy224View : public CView
{
protected: // �������л�����
	CMy224View();
	DECLARE_DYNCREATE(CMy224View)

// ����
public:
	CMy224Doc* GetDocument() const;

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
	virtual ~CMy224View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 2.2.4View.cpp �еĵ��԰汾
inline CMy224Doc* CMy224View::GetDocument() const
   { return reinterpret_cast<CMy224Doc*>(m_pDocument); }
#endif

