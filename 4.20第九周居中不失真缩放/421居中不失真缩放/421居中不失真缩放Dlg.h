
// 421���в�ʧ������Dlg.h : ͷ�ļ�
//

#pragma once


// CMy421���в�ʧ������Dlg �Ի���
class CMy421���в�ʧ������Dlg : public CDialogEx
{
// ����
public:
	CMy421���в�ʧ������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY421_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void CMy421���в�ʧ������Dlg::foo(CImage& img, int &sx, int&sy, int&w, int&h);
};
