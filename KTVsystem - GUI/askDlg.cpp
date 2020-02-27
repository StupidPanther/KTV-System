// askDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "askDlg.h"
#include "afxdialogex.h"


// askDlg 对话框

IMPLEMENT_DYNAMIC(askDlg, CDialogEx)

askDlg::askDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_askDlg, pParent)
{
	Sure = false;
}

askDlg::~askDlg()
{
}

void askDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(askDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &askDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &askDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// askDlg 消息处理程序


void askDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Sure = true;
	CDialogEx::OnOK();
}


bool askDlg::getSure()
{
	// TODO: 在此处添加实现代码.
	return Sure;
}


void askDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	Sure = false;
	CDialogEx::OnCancel();
}
