#pragma once


// EnlargeDlg �Ի���

class EnlargeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EnlargeDlg)

public:
	EnlargeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	BOOL OnInitDialog();
	virtual ~EnlargeDlg();
	CString filepath;
	CRect rect;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void draw_pic(CString filename);
};
