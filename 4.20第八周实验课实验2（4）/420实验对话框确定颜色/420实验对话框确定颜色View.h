
// 420ʵ��Ի���ȷ����ɫView.h : CMy420ʵ��Ի���ȷ����ɫView ��Ľӿ�
//

#pragma once


class CMy420ʵ��Ի���ȷ����ɫView : public CView
{
protected: // �������л�����
	CMy420ʵ��Ի���ȷ����ɫView();
	DECLARE_DYNCREATE(CMy420ʵ��Ի���ȷ����ɫView)

// ����
public:
	CMy420ʵ��Ի���ȷ����ɫDoc* GetDocument() const;

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
	virtual ~CMy420ʵ��Ի���ȷ����ɫView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnInputrgb();
};

#ifndef _DEBUG  // 420ʵ��Ի���ȷ����ɫView.cpp �еĵ��԰汾
inline CMy420ʵ��Ի���ȷ����ɫDoc* CMy420ʵ��Ի���ȷ����ɫView::GetDocument() const
   { return reinterpret_cast<CMy420ʵ��Ի���ȷ����ɫDoc*>(m_pDocument); }
#endif

