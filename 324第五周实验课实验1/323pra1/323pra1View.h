
// 323pra1View.h : CMy323pra1View ��Ľӿ�
//

#pragma once


class CMy323pra1View : public CView
{
protected: // �������л�����
	CMy323pra1View();
	DECLARE_DYNCREATE(CMy323pra1View)

// ����
public:
	CMy323pra1Doc* GetDocument() const;

	void Onsize(CDC * pDC);

// ����
public: CMenu size;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy323pra1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onsize(CDC* pDC);
};

#ifndef _DEBUG  // 323pra1View.cpp �еĵ��԰汾
inline CMy323pra1Doc* CMy323pra1View::GetDocument() const
   { return reinterpret_cast<CMy323pra1Doc*>(m_pDocument); }
#endif

