
// 421���ݵ����л�Doc.h : CMy421���ݵ����л�Doc ��Ľӿ�
//


#pragma once
class student :public CObject
{
public:
	CString name; int age;
	virtual void Serialize(CArchive&ar)
	{
		if (ar.IsStoring())
			ar << name << age;
		else
			ar >> name >> age;
	}

};

class CMy421���ݵ����л�Doc : public CDocument
{
protected: // �������л�����
	CMy421���ݵ����л�Doc();
	DECLARE_DYNCREATE(CMy421���ݵ����л�Doc)

// ����
public:
	int a;
	CString s;
	CArray<int, int&>ca;
	student st;
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
	virtual ~CMy421���ݵ����л�Doc();
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
