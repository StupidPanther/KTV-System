// AddByHand.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "AddByHand.h"
#include "afxdialogex.h"

#include"control.h"
#include"infDlg.h"

#include"string"

using std::string;


// AddByHand 对话框

IMPLEMENT_DYNAMIC(AddByHand, CDialogEx)

AddByHand::AddByHand(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AddByHand, pParent)
{

}

AddByHand::~AddByHand()
{
}

void AddByHand::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITSong, EditSong);
	DDX_Control(pDX, IDC_EDITSinger, EditSinger);
	DDX_Control(pDX, IDC_EDITPinyin, EditPinyin);
}


BEGIN_MESSAGE_MAP(AddByHand, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddByHand::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &AddByHand::OnBnClickedCancel)
END_MESSAGE_MAP()


// AddByHand 消息处理程序


void AddByHand::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString inputSong;
	EditSong.GetWindowText(inputSong);
	string strSong = CW2A(inputSong.GetString());
	CString inputSinger;
	EditSinger.GetWindowText(inputSinger);
	string strSinger = CW2A(inputSinger.GetString());
	CString inputPinyin;
	EditPinyin.GetWindowText(inputPinyin);
	string strPinyin = CW2A(inputPinyin.GetString());

	if (strSong != ""&&strSinger != ""&&strPinyin != "")
	{
		admin Admin;
		Admin.AddByHand(strSong, strSinger, strPinyin);

		infDlg inf;
		inf.DoModal();

		CDialogEx::OnOK();
	}
}


void AddByHand::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
