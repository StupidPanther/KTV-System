// loginDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "loginDlg.h"
#include "afxdialogex.h"
#include<string>

#include"core.h"
#include"adminDlg.h"

using std::string;

// loginDlg 对话框

IMPLEMENT_DYNAMIC(loginDlg, CDialogEx)

loginDlg::loginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_loginDlg, pParent)
{
	times = 0;
}

loginDlg::~loginDlg()
{
}

void loginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_editID, EditID);
	DDX_Control(pDX, IDC_editPW, EditPW);
}


BEGIN_MESSAGE_MAP(loginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_login, &loginDlg::OnBnClickedlogin)
END_MESSAGE_MAP()


// loginDlg 消息处理程序



void loginDlg::OnBnClickedlogin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString inputID;
	EditID.GetWindowText(inputID);
	string strID=CW2A(inputID.GetString());
	CString inputPW;
	EditPW.GetWindowText(inputPW);
	string strPW = CW2A(inputPW.GetString());

	LogIn login;
	if (login.login(strID, strPW) == true)
	{
		SendMessage(WM_CLOSE);
		adminDlg adminUI;
		adminUI.DoModal();
	}
	else
	{
		times++;
		AfxMessageBox(_T("用户名或密码错误！"));
	}

	if (times == 3)
	{
		AfxMessageBox(_T("三次输入错误，退出登录程序！"));
		SendMessage(WM_CLOSE);
	}
		
}


bool LogIn::login(string inputID, string inputPW)
{
	return SignIn(inputID, inputPW);
}