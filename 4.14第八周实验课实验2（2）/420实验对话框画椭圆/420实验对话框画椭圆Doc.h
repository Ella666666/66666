
// 420ʵ��Ի�����ԲDoc.h : CMy420ʵ��Ի�����ԲDoc ��Ľӿ�
//


#pragma once


class CMy420ʵ��Ի�����ԲDoc : public CDocument
{
protected: // �������л�����
	CMy420ʵ��Ի�����ԲDoc();
	DECLARE_DYNCREATE(CMy420ʵ��Ի�����ԲDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy420ʵ��Ի�����ԲDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
