
// 2.2.3View.h : CMy223View ��Ľӿ�
//

#pragma once


class CMy223View : public CView
{
protected: // �������л�����
	CMy223View();
	DECLARE_DYNCREATE(CMy223View)

// ����
public:
	CMy223Doc* GetDocument() const;

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
	virtual ~CMy223View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 2.2.3View.cpp �еĵ��԰汾
inline CMy223Doc* CMy223View::GetDocument() const
   { return reinterpret_cast<CMy223Doc*>(m_pDocument); }
#endif

