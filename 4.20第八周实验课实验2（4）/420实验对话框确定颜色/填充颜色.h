#pragma once


// 填充颜色 对话框

class 填充颜色 : public CDialogEx
{
	DECLARE_DYNAMIC(填充颜色)

public:
	填充颜色(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~填充颜色();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	int z;
};
