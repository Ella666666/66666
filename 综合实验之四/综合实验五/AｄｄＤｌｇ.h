#pragma once


// A���ģ�� �Ի���

class A���ģ�� : public CDialogEx
{
	DECLARE_DYNAMIC(A���ģ��)

public:
	A���ģ��(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~A���ģ��();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString l;
	CString num2;
	CString name2;
	CString specia2;
	CString sex;
	double birth2;
	CString phone2;
	CString address;
	CString picpath2;
};
