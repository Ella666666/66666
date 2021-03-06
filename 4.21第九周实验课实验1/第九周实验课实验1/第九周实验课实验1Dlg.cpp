
// 第九周实验课实验1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "第九周实验课实验1.h"
#include "第九周实验课实验1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include"string"
#include"iostream"
#include"fstream"
using namespace std;


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


// C第九周实验课实验1Dlg 对话框



C第九周实验课实验1Dlg::C第九周实验课实验1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C第九周实验课实验1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C第九周实验课实验1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &C第九周实验课实验1Dlg::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT1, &C第九周实验课实验1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &C第九周实验课实验1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &C第九周实验课实验1Dlg::OnBnClickedCancel)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// C第九周实验课实验1Dlg 消息处理程序

BOOL C第九周实验课实验1Dlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	filename = _T("");
	// 将“关于...”菜单项添加到系统菜单中。
	CString filter, strtext;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	if (dlg.DoModal() == IDOK) 
	{
		CString str;
		CStdioFile file;
		filename = dlg.GetPathName();
		if (!file.Open(filename, CFile::modeRead)) 
		{
			::AfxMessageBox(_T("文件打开失败。"));
		}
		strtext = _T("");
		while (file.ReadString(strtext))
		{
			list.AddString(strtext);
		}
	}
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

void C第九周实验课实验1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C第九周实验课实验1Dlg::OnPaint()
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
HCURSOR C第九周实验课实验1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C第九周实验课实验1Dlg::OnLbnSelchangeList1()
{
	UpdateData(true);
	int i = list.GetCurSel();
	CString str;
	list.GetText(i, str);
	s = str;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void C第九周实验课实验1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void C第九周实验课实验1Dlg::OnBnClickedButton1()
{
	UpdateData(true);
	int i = list.GetCurSel();
	list.DeleteString(i);
	list.InsertString(i, s);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void C第九周实验课实验1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void C第九周实验课实验1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	if (filename != _T(""))
	{
		ofstream out(filename);
		CString r;
		int i = list.GetCount();
		//out.flush();
		for (int k = 0; k < i; k++)
		{
			list.GetText(k, r);
			out << CT2A(r.GetString()) << endl;   //这种输出流是默认刷新文件的
		}
		out.flush();
		out.close();
	}
	AfxMessageBox(_T("系统已自动保存更改"));
	// TODO: 在此处添加消息处理程序代码
}
