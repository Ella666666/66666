#pragma once


// MOD_DLG 对话框

class MOD_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(MOD_DLG)

public:
	MOD_DLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MOD_DLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
