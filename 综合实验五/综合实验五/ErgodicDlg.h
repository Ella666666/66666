#pragma once


// ErgodicDlg �Ի���

class ErgodicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ErgodicDlg)

public:
	ErgodicDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ErgodicDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString er;
};
