#pragma once


// Adddlg �Ի���

class Adddlg : public CDialogEx
{
	DECLARE_DYNAMIC(Adddlg)

public:
	Adddlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Adddlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CString Num;
	CString Name;
	CString PicPath;
	int Money;
	CComboBox Cbox;
	
	DECLARE_MESSAGE_MAP()
	BOOL OnInitDialog();
};

BOOL Adddlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//MessageBox(_T("��Ӽ�¼ʱһ��Ҫ��ѧ��"));

	CString s;
	for (int i = 100; i>0; i--)
	{
		s.Format(_T("%d"), i);
		Cbox.AddString(s);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}