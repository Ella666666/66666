
// 420实验1计算器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "420实验1计算器.h"
#include "420实验1计算器Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy420实验1计算器Dlg 对话框



CMy420实验1计算器Dlg::CMy420实验1计算器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY4201_DIALOG, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy420实验1计算器Dlg::SaveValu1()
{
	UpdateData(TRUE);
	m_fNumber1 = atof(m_str);   //编辑框显示第一个操作数
	m_str = "";       //做完上步操作后将编辑框设置为空
	UpdateData(FALSE);
}

void CMy420实验1计算器Dlg::Calulator()
{
	UpdateData(TRUE);
	m_fNumber2 = atof(m_str);      //获得第二个操作数并显示在编辑框中
	double f = 0.0f;    //f必须初始化，用于保留计算结果
	switch (m_iSign)   //根据m_iSign标志跳转
	{
	case 0:
		f = m_fNumber1 + m_fNumber2;//加
		break;
 	case 1:
		f = m_fNumber1 - m_fNumber2;//减
		break;
	case 2:
		f = m_fNumber1 * m_fNumber2;//乘
		break;
	case 3:
		if (m_fNumber2 == 0.0f)  //除法中分母不能为0，为0时需要进行如下操作
		{
			MessageBox("除数不能为0!");  //弹出提示消息框
			f = m_fNumber1;
			//除数为0时直接将第一个操作数赋给结果，表示第二个操作数不算，直接继续下一步操作
		}
		else
		{
			f = m_fNumber1 / m_fNumber2;//除
		}
		break;
	case 6:
		f = pow(m_fNumber1, m_fNumber2); //指数
		break;
	default:
		break;
	}
	//计算结果处理
	//如果浮点数其实是个整数
	if (f - int(f) <= 1e-5)
	{
		m_str.Format("%d", (int)f);
	}
	else
	{
		m_str.Format("%f", f);  //double型的数据转为Cstring型
	}
	UpdateData(FALSE);
}

void CMy420实验1计算器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CMy420实验1计算器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON19, &CMy420实验1计算器Dlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON14, &CMy420实验1计算器Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON18, &CMy420实验1计算器Dlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON17, &CMy420实验1计算器Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON15, &CMy420实验1计算器Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMy420实验1计算器Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON12, &CMy420实验1计算器Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy420实验1计算器Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy420实验1计算器Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy420实验1计算器Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy420实验1计算器Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy420实验1计算器Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy420实验1计算器Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy420实验1计算器Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy420实验1计算器Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMy420实验1计算器Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMy420实验1计算器Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON20, &CMy420实验1计算器Dlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy420实验1计算器Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON13, &CMy420实验1计算器Dlg::OnBnClickedButton13)
END_MESSAGE_MAP()


// CMy420实验1计算器Dlg 消息处理程序

BOOL CMy420实验1计算器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy420实验1计算器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy420实验1计算器Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy420实验1计算器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy420实验1计算器Dlg::OnBnClickedButton19()//清除按钮
{
	UpdateData(TRUE);
	if (!m_str.IsEmpty())
	{
		m_str = m_str.Left(m_str.GetLength() - 1);  //移除最右边一个字符
	}
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton14()//清空按钮
{
	UpdateData(TRUE);
	m_str = "";         //将对话框设为空，即达到清零的效果
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton18()//加
{
	SaveValu1();
	m_iSign = 0;
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton17()//减
{
	SaveValu1();
	m_iSign = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton15()//乘
{
	SaveValu1();
	m_iSign = 2;
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton16()//除
{
	SaveValu1();
	m_iSign = 3;
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton12()//开平方
{
	UpdateData(TRUE);
	m_fNumber1 = atof(m_str);
	double f = sqrt(m_fNumber1);
	if (m_fNumber1 <= 0)
		MessageBox("请输入大于0的数");
	//如果浮点数其实是个整数
	if (f - int(f) <= 1e-5)
	{
		m_str.Format("%d", (int)f);
	}
	else
	{
		m_str.Format("%f", f);
	}
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton1()//1
{
	UpdateData(TRUE);
	m_str = m_str + "1";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton2()//0
{
	UpdateData(TRUE);
	m_str = m_str + "0";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton4()//2
{
	UpdateData(TRUE);
	m_str = m_str + "2";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton5()//3
{
	UpdateData(TRUE);
	m_str = m_str + "3";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton6()//4
{
	UpdateData(TRUE);
	m_str = m_str + "4";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton7()//5
{
	UpdateData(TRUE);
	m_str = m_str + "5";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton8()//5
{
	UpdateData(TRUE);
	m_str = m_str + "6";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton9()//7
{
	UpdateData(TRUE);
	m_str = m_str + "7";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton10()//8
{
	UpdateData(TRUE);
	m_str = m_str + "8";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton11()//9
{
	UpdateData(TRUE);
	m_str = m_str + "9";
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton20()//=
{
	UpdateData(TRUE);
	//m_iSign=0~3分别对应“+”“-”“×”“÷”
	if (m_iSign != 0 && m_iSign != 1 && m_iSign != 2 && m_iSign != 3)
	{
		m_fNumber1 = atof(m_str);
	}
	//当单击输入某一个数值而没有单击操作符按钮（“+”“-”“×”“÷”）、直接单击“=”时，界面上保持显示第一个操作数
	else
		Calulator();
	UpdateData(FALSE);
	
	
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton3()//小数点
{
	UpdateData(TRUE);
	//如果没有小数点，则加上一个小数点，如果已有小数点就忽略此次的小数点，保证最多只有1个
	if (-1 == m_str.Find('.'))
	{
		m_str = m_str + ".";
	}
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CMy420实验1计算器Dlg::OnBnClickedButton13()//1/x
{
	UpdateData(TRUE);
	m_fNumber1 = atof(m_str);
	m_fNumber1= 1 / (m_fNumber1)-m_fNumber1;
	double f =m_fNumber1;
	UpdateData(FALSE);
	if (m_fNumber1 == 0)
		MessageBox("请输入除零以外的数");

	// TODO: 在此添加控件通知处理程序代码
}
