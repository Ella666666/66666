#pragma once


// SortDlg �Ի���

class SortDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SortDlg)

public:
	SortDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SortDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString sort;
};
