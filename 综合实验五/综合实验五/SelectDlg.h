#pragma once


// SelectDlg 对话框

class SelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectDlg)

public:
	SelectDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SelectDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString sele;
};
