
// 420实验1计算器Dlg.h : 头文件
//

#pragma once


// CMy420实验1计算器Dlg 对话框
class CMy420实验1计算器Dlg : public CDialogEx
{
// 构造
public:
	CMy420实验1计算器Dlg(CWnd* pParent = NULL);	// 标准构造函数
	double m_fNumber1;
	double m_fNumber2;
	int m_iSign;
	void SaveValu1();
	void Calulator();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY4201_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_str;
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton13();
};
