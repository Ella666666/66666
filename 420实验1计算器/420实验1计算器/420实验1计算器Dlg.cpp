
// 420ʵ��1������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "420ʵ��1������.h"
#include "420ʵ��1������Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy420ʵ��1������Dlg �Ի���



CMy420ʵ��1������Dlg::CMy420ʵ��1������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY4201_DIALOG, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy420ʵ��1������Dlg::SaveValu1()
{
	UpdateData(TRUE);
	m_fNumber1 = atof(m_str);   //�༭����ʾ��һ��������
	m_str = "";       //�����ϲ������󽫱༭������Ϊ��
	UpdateData(FALSE);
}

void CMy420ʵ��1������Dlg::Calulator()
{
	UpdateData(TRUE);
	m_fNumber2 = atof(m_str);      //��õڶ�������������ʾ�ڱ༭����
	double f = 0.0f;    //f�����ʼ�������ڱ���������
	switch (m_iSign)   //����m_iSign��־��ת
	{
	case 0:
		f = m_fNumber1 + m_fNumber2;//��
		break;
 	case 1:
		f = m_fNumber1 - m_fNumber2;//��
		break;
	case 2:
		f = m_fNumber1 * m_fNumber2;//��
		break;
	case 3:
		if (m_fNumber2 == 0.0f)  //�����з�ĸ����Ϊ0��Ϊ0ʱ��Ҫ�������²���
		{
			MessageBox("��������Ϊ0!");  //������ʾ��Ϣ��
			f = m_fNumber1;
			//����Ϊ0ʱֱ�ӽ���һ�������������������ʾ�ڶ������������㣬ֱ�Ӽ�����һ������
		}
		else
		{
			f = m_fNumber1 / m_fNumber2;//��
		}
		break;
	case 6:
		f = pow(m_fNumber1, m_fNumber2); //ָ��
		break;
	default:
		break;
	}
	//����������
	//�����������ʵ�Ǹ�����
	if (f - int(f) <= 1e-5)
	{
		m_str.Format("%d", (int)f);
	}
	else
	{
		m_str.Format("%f", f);  //double�͵�����תΪCstring��
	}
	UpdateData(FALSE);
}

void CMy420ʵ��1������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CMy420ʵ��1������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON19, &CMy420ʵ��1������Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON14, &CMy420ʵ��1������Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON18, &CMy420ʵ��1������Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON17, &CMy420ʵ��1������Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON15, &CMy420ʵ��1������Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMy420ʵ��1������Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON12, &CMy420ʵ��1������Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy420ʵ��1������Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy420ʵ��1������Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy420ʵ��1������Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy420ʵ��1������Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy420ʵ��1������Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy420ʵ��1������Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy420ʵ��1������Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy420ʵ��1������Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMy420ʵ��1������Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMy420ʵ��1������Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON20, &CMy420ʵ��1������Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy420ʵ��1������Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON13, &CMy420ʵ��1������Dlg::OnBnClickedButton13)
END_MESSAGE_MAP()


// CMy420ʵ��1������Dlg ��Ϣ�������

BOOL CMy420ʵ��1������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy420ʵ��1������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy420ʵ��1������Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy420ʵ��1������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy420ʵ��1������Dlg::OnBnClickedButton19()//�����ť
{
	UpdateData(TRUE);
	if (!m_str.IsEmpty())
	{
		m_str = m_str.Left(m_str.GetLength() - 1);  //�Ƴ����ұ�һ���ַ�
	}
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton14()//��հ�ť
{
	UpdateData(TRUE);
	m_str = "";         //���Ի�����Ϊ�գ����ﵽ�����Ч��
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton18()//��
{
	SaveValu1();
	m_iSign = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton17()//��
{
	SaveValu1();
	m_iSign = 1;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton15()//��
{
	SaveValu1();
	m_iSign = 2;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton16()//��
{
	SaveValu1();
	m_iSign = 3;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton12()//��ƽ��
{
	UpdateData(TRUE);
	m_fNumber1 = atof(m_str);
	double f = sqrt(m_fNumber1);
	if (m_fNumber1 <= 0)
		MessageBox("���������0����");
	//�����������ʵ�Ǹ�����
	if (f - int(f) <= 1e-5)
	{
		m_str.Format("%d", (int)f);
	}
	else
	{
		m_str.Format("%f", f);
	}
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton1()//1
{
	UpdateData(TRUE);
	m_str = m_str + "1";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton2()//0
{
	UpdateData(TRUE);
	m_str = m_str + "0";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton4()//2
{
	UpdateData(TRUE);
	m_str = m_str + "2";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton5()//3
{
	UpdateData(TRUE);
	m_str = m_str + "3";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton6()//4
{
	UpdateData(TRUE);
	m_str = m_str + "4";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton7()//5
{
	UpdateData(TRUE);
	m_str = m_str + "5";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton8()//5
{
	UpdateData(TRUE);
	m_str = m_str + "6";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton9()//7
{
	UpdateData(TRUE);
	m_str = m_str + "7";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton10()//8
{
	UpdateData(TRUE);
	m_str = m_str + "8";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton11()//9
{
	UpdateData(TRUE);
	m_str = m_str + "9";
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton20()//=
{
	UpdateData(TRUE);
	//m_iSign=0~3�ֱ��Ӧ��+����-�����������¡�
	if (m_iSign != 0 && m_iSign != 1 && m_iSign != 2 && m_iSign != 3)
	{
		m_fNumber1 = atof(m_str);
	}
	//����������ĳһ����ֵ��û�е�����������ť����+����-�����������¡�����ֱ�ӵ�����=��ʱ�������ϱ�����ʾ��һ��������
	else
		Calulator();
	UpdateData(FALSE);
	
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton3()//С����
{
	UpdateData(TRUE);
	//���û��С���㣬�����һ��С���㣬�������С����ͺ��Դ˴ε�С���㣬��֤���ֻ��1��
	if (-1 == m_str.Find('.'))
	{
		m_str = m_str + ".";
	}
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMy420ʵ��1������Dlg::OnBnClickedButton13()//1/x
{
	UpdateData(TRUE);
	m_fNumber1 = atof(m_str);
	m_fNumber1= 1 / (m_fNumber1)-m_fNumber1;
	double f =m_fNumber1;
	UpdateData(FALSE);
	if (m_fNumber1 == 0)
		MessageBox("����������������");

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
