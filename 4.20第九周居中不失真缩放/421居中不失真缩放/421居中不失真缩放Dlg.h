
// 421居中不失真缩放Dlg.h : 头文件
//

#pragma once


// CMy421居中不失真缩放Dlg 对话框
class CMy421居中不失真缩放Dlg : public CDialogEx
{
// 构造
public:
	CMy421居中不失真缩放Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY421_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	afx_msg void CMy421居中不失真缩放Dlg::foo(CImage& img, int &sx, int&sy, int&w, int&h);
};
