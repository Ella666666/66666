#pragma once


// AｄｄＤｌｇ 对话框

class AｄｄＤｌｇ : public CDialogEx
{
	DECLARE_DYNAMIC(AｄｄＤｌｇ)

public:
	AｄｄＤｌｇ(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AｄｄＤｌｇ();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString l;
	CString num2;
	CString name2;
	CString specia2;
	CString sex;
	double birth2;
	CString phone2;
	CString address;
	CString picpath2;
};
