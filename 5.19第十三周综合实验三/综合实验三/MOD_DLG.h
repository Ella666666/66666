#pragma once


// MOD_DLG �Ի���

class MOD_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(MOD_DLG)

public:
	MOD_DLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MOD_DLG();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
