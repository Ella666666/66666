#pragma once


// Adddlg 对话框

class Adddlg : public CDialogEx
{
	DECLARE_DYNAMIC(Adddlg)

public:
	Adddlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Adddlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CString Num;
	CString Name;
	CString PicPath;
	int Money;
	CComboBox Cbox;
	
	DECLARE_MESSAGE_MAP()
	BOOL OnInitDialog();
};

BOOL Adddlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//MessageBox(_T("添加记录时一定要填学号"));

	CString s;
	for (int i = 100; i>0; i--)
	{
		s.Format(_T("%d"), i);
		Cbox.AddString(s);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}