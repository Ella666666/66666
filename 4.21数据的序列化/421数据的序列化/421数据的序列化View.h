
// 421���ݵ����л�View.h : CMy421���ݵ����л�View ��Ľӿ�
//

#pragma once


class CMy421���ݵ����л�View : public CView
{
protected: // �������л�����
	CMy421���ݵ����л�View();
	DECLARE_DYNCREATE(CMy421���ݵ����л�View)

// ����
public:
	CMy421���ݵ����л�Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy421���ݵ����л�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChange();
};

#ifndef _DEBUG  // 421���ݵ����л�View.cpp �еĵ��԰汾
inline CMy421���ݵ����л�Doc* CMy421���ݵ����л�View::GetDocument() const
   { return reinterpret_cast<CMy421���ݵ����л�Doc*>(m_pDocument); }
#endif

