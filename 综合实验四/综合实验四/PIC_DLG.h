#pragma once


// PIC_DLG 对话框

class PIC_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(PIC_DLG)

public:
	PIC_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PIC_DLG();
	CString path;
	CString filepath;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		void draw_pic();
	void OnPaint();
};
