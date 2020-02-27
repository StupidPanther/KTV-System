#pragma once
#include"core.h"

// loginDlg 对话框

class loginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(loginDlg)
	int times;

public:
	loginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~loginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_loginDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedlogin();
	CEdit EditID;
	CEdit EditPW;
};

class LogIn :protected admin_infor
{
public:
	bool login(string inputID, string inputPW);
};