#pragma once


// PIC_DLG �Ի���

class PIC_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(PIC_DLG)

public:
	PIC_DLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PIC_DLG();
	CString path;
	CString filepath;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		void draw_pic();
	void OnPaint();
};
