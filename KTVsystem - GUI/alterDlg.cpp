// alterDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "alterDlg.h"
#include "afxdialogex.h"


// alterDlg 对话框

IMPLEMENT_DYNAMIC(alterDlg, CDialogEx)

alterDlg::alterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_alter, pParent)
{

}

alterDlg::~alterDlg()
{
}

void alterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITSong, EditSong);
	DDX_Control(pDX, IDC_EDITSinger, EditSinger);
	DDX_Control(pDX, IDC_EDITPinyin, EditPinyin);
}


BEGIN_MESSAGE_MAP(alterDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &alterDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// alterDlg 消息处理程序


void alterDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString inputSong;
	EditSong.GetWindowText(inputSong);
	strSong = CW2A(inputSong.GetString());
	CString inputSinger;
	EditSinger.GetWindowText(inputSinger);
	strSinger = CW2A(inputSinger.GetString());
	CString inputPinyin;
	EditPinyin.GetWindowText(inputPinyin);
	strPinyin = CW2A(inputPinyin.GetString());

	CDialogEx::OnOK();
}


string alterDlg::getSong()
{
	// TODO: 在此处添加实现代码.
	return strSong;
}


string alterDlg::getSinger()
{
	// TODO: 在此处添加实现代码.
	return strSinger;
}


string alterDlg::getPinyin()
{
	// TODO: 在此处添加实现代码.
	return strPinyin;
}
