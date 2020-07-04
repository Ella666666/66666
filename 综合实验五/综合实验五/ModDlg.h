#pragma once


// ModDlg 对话框

class ModDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ModDlg)

public:
	ModDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ModDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	CString name1;
	CString num1;
	CString specia1;
	CString sex1;
	double birth1;
	CString phone;
	CString address1;
	CString picpath1;
};
