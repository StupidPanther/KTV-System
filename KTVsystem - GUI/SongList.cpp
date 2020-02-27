// SongList.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "SongList.h"
#include "afxdialogex.h"

#include"control.h"
#include"service.h"

#include"askDlg.h"
#include"alterDlg.h"
#include"infDlg.h"


// SongList 对话框

IMPLEMENT_DYNAMIC(SongList, CDialogEx)

SongList::SongList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SongList, pParent)
{

}

SongList::~SongList()
{
}

void SongList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SongList, ListSongList);
}


BEGIN_MESSAGE_MAP(SongList, CDialogEx)
	ON_BN_CLICKED(IDC_Alter, &SongList::OnBnClickedAlter)
	ON_BN_CLICKED(IDC_Del, &SongList::OnBnClickedDel)
END_MESSAGE_MAP()


// SongList 消息处理程序


BOOL SongList::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	int num_wide = 7;
	CRect rect;
	tolist list;
	vector<string> strlist = list.get();

	// 获取编程语言列表视图控件的位置和大小   
	ListSongList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	ListSongList.SetExtendedStyle(ListSongList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加列
	int i;
	for (i = 0; i < num_wide; i++)
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		ListSongList.InsertColumn(i, CstrTemp, LVCFMT_CENTER, rect.Width() / num_wide, 0);
	}

	// 在列表视图控件中插入列表项，并设置列表子项文本
	int row = 0;
	while (i < strlist.size())
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		ListSongList.InsertItem(row, CstrTemp);
		for (int j = 0; j < num_wide; j++, i++)
		{
			CString CstrTemp;
			CstrTemp = (strlist[i]).c_str();
			ListSongList.SetItemText(row, j, CstrTemp);
		}
		row++;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void SongList::OnBnClickedAlter()
{
	// TODO: 在此添加控件通知处理程序代码


	int Cur = ListSongList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

	if (Cur >= 0)
	{
		alterDlg alter;
		alter.DoModal();

		if (alter.getSong() != ""&&alter.getSinger() != ""&& alter.getPinyin() != "")
		{
			{
				admin Admin;
				Admin.AlterSong(Cur, alter.getSong(), alter.getSinger(), alter.getPinyin());
			}
			UpdateList();
			infDlg inf;
			inf.DoModal();
		}
	}
}


void SongList::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cur = ListSongList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

	if (Cur >= 0)
	{
		askDlg ask;
		ask.DoModal();
		bool Sure = ask.getSure();

		if (Sure)
		{
			admin Admin;
			Admin.DeleteSong(Cur);
		}

		UpdateList();
	}
}


void SongList::UpdateList()
{
	if (true)
	{
		admin Admin;
		Admin.SearchSongInfor();
	}

	ListSongList.DeleteAllItems();

	int num_wide = 7;
	CRect rect;
	tolist list;
	vector<string> strlist = list.get();

	// 获取编程语言列表视图控件的位置和大小   
	ListSongList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	//ListSongList.SetExtendedStyle(ListSongList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加列
	int i;
	for (i = 0; i < num_wide; i++)
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		//ListSongList.InsertColumn(i, CstrTemp, LVCFMT_CENTER, rect.Width() / num_wide, 0);
	}

	// 在列表视图控件中插入列表项，并设置列表子项文本
	int row = 0;
	while (i < strlist.size())
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		ListSongList.InsertItem(row, CstrTemp);
		for (int j = 0; j < num_wide; j++, i++)
		{
			CString CstrTemp;
			CstrTemp = (strlist[i]).c_str();
			ListSongList.SetItemText(row, j, CstrTemp);
		}
		row++;
	}
}
