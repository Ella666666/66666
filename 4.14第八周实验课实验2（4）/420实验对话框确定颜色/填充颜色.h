#pragma once


// �����ɫ �Ի���

class �����ɫ : public CDialogEx
{
	DECLARE_DYNAMIC(�����ɫ)

public:
	�����ɫ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~�����ɫ();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	int z;
};
