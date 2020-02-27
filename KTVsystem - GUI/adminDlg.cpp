// adminDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "adminDlg.h"
#include "afxdialogex.h"

#include"control.h"

#include"infDlg.h"
#include"SongList.h"
#include"AddByHand.h"
#include"AddByFile.h"
#include"SongListSort.h"


// adminDlg 对话框

IMPLEMENT_DYNAMIC(adminDlg, CDialogEx)

adminDlg::adminDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_adminDlg, pParent)
{
	
}

adminDlg::~adminDlg()
{
}

void adminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(adminDlg, CDialogEx)
	ON_BN_CLICKED(IDC_PrintList, &adminDlg::OnBnClickedPrintlist)
	ON_BN_CLICKED(IDC_AddByHand, &adminDlg::OnBnClickedAddbyhand)
	ON_BN_CLICKED(IDC_AddByTxt, &adminDlg::OnBnClickedAddbytxt)
	ON_BN_CLICKED(IDC_Ranking, &adminDlg::OnBnClickedRanking)
END_MESSAGE_MAP()


// adminDlg 消息处理程序


void adminDlg::OnBnClickedPrintlist()
{
	// TODO: 在此添加控件通知处理程序代码
	if (true)
	{
		admin Admin;
		Admin.SearchSongInfor();
	}

	SongList Songlist;
	Songlist.DoModal();
}


void adminDlg::OnBnClickedAddbyhand()
{
	// TODO: 在此添加控件通知处理程序代码
	AddByHand add;
	add.DoModal();
}


void adminDlg::OnBnClickedAddbytxt()
{
	// TODO: 在此添加控件通知处理程序代码
	AddByFile addf;
	addf.DoModal();

	string pathname = addf.getPath();
	if (pathname != "")
	{
		admin Admin;
		Admin.AddByFile(pathname);

		infDlg inf;
		inf.DoModal();
	}

	
}


void adminDlg::OnBnClickedRanking()
{
	// TODO: 在此添加控件通知处理程序代码
	{
		admin Admin;
		Admin.PrintRanking();
	}

	SongListSort list;
	list.DoModal();
}
