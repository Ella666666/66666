#pragma once


// ErgodicDlg 对话框

class ErgodicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ErgodicDlg)

public:
	ErgodicDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ErgodicDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString er;
};
