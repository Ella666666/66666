#pragma once


// ModDlg �Ի���

class ModDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ModDlg)

public:
	ModDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ModDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
