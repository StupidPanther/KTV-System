#pragma once


// adminDlg 对话框

class adminDlg : public CDialogEx
{
	DECLARE_DYNAMIC(adminDlg)

public:
	adminDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~adminDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_adminDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPrintlist();
	afx_msg void OnBnClickedAddbyhand();
	afx_msg void OnBnClickedAddbytxt();
	afx_msg void OnBnClickedRanking();
};
