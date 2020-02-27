// userDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "userDlg.h"
#include "afxdialogex.h"

#include"searchDlg.h"
#include"rateDlg.h"
#include"infDlg.h"

#include"control.h"
#include"service.h"

// userDlg 对话框

IMPLEMENT_DYNAMIC(userDlg, CDialogEx)

userDlg::userDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_userDlg, pParent)
{

}

userDlg::~userDlg()
{
}

void userDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_usersonglist, UserSongList);
	DDX_Control(pDX, IDC_editSearch, EditSearch);
}


BEGIN_MESSAGE_MAP(userDlg, CDialogEx)
	ON_BN_CLICKED(IDC_search, &userDlg::OnBnClickedsearch)
	ON_BN_CLICKED(StickOnTop, &userDlg::OnBnClickedStickontop)
	ON_BN_CLICKED(DeleteASong, &userDlg::OnBnClickedDeleteasong)
	ON_BN_CLICKED(IDC_RateASong, &userDlg::OnBnClickedRateasong)
	ON_BN_CLICKED(IDC_userexist, &userDlg::OnBnClickeduserexist)
	ON_BN_CLICKED(IDC_NextSong, &userDlg::OnBnClickedNextsong)
END_MESSAGE_MAP()


void userDlg::UpdateList()
{
	user User(101);

	UserSongList.DeleteAllItems();

	int num_wide = 8;
	CRect rect;
	tolist list;
	vector<string> strlist = list.get();

	// 获取编程语言列表视图控件的位置和大小   
	UserSongList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	UserSongList.SetExtendedStyle(UserSongList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加列
	int i;
	for (i = 0; i < num_wide; i++)
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		//UserSongList.InsertColumn(i, CstrTemp, LVCFMT_CENTER, rect.Width() / num_wide, 0);
	}

	// 在列表视图控件中插入列表项，并设置列表子项文本
	int row = 0;
	while (i < strlist.size())
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		UserSongList.InsertItem(row, CstrTemp);
		for (int j = 0; j < num_wide; j++, i++)
		{
			CString CstrTemp;
			CstrTemp = (strlist[i]).c_str();
			UserSongList.SetItemText(row, j, CstrTemp);
		}
		row++;
	}
}

// userDlg 消息处理程序


BOOL userDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	user User(101);
	

	int num_wide = 8;
	CRect rect;
	tolist list;
	vector<string> strlist = list.get();

	// 获取编程语言列表视图控件的位置和大小   
	UserSongList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	UserSongList.SetExtendedStyle(UserSongList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加列
	int i;
	for (i = 0; i < num_wide; i++)
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		UserSongList.InsertColumn(i, CstrTemp, LVCFMT_CENTER, rect.Width() / num_wide, 0);
	}

	// 在列表视图控件中插入列表项，并设置列表子项文本
	int row = 0;
	while (i < strlist.size())
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		UserSongList.InsertItem(row, CstrTemp);
		for (int j = 0; j < num_wide; j++, i++)
		{
			CString CstrTemp;
			CstrTemp = (strlist[i]).c_str();
			UserSongList.SetItemText(row, j, CstrTemp);
		}
		row++;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}




void userDlg::OnBnClickedsearch()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strSearch;
	EditSearch.GetWindowText(strSearch);
	string str=CW2A(strSearch.GetString());
	if (true)
	{
		user User(101);
		User.SearchASong(str);
	}

	searchDlg searchdlg;
	searchdlg.DoModal();

	UpdateList();
}


void userDlg::OnBnClickedStickontop()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cur = UserSongList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	{
		user User(101);
		User.StickTop(Cur);
	}
	UpdateList();
}


void userDlg::OnBnClickedDeleteasong()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cur = UserSongList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

	if (Cur >= 0)
	{
		if (true)
		{
			user User(101);
			User.DelASong(Cur);
		}
	}

	UpdateList();
}


void userDlg::OnBnClickedRateasong()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cur = UserSongList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	CString c_num = UserSongList.GetItemText(Cur, 1);
	int num = _ttoi(c_num);

	if (Cur >= 0)
	{
		rateDlg rate;
		rate.DoModal();

		int rating = rate.getRate();
		if (rating == 1 || rating == 2 || rating == 3 || rating == 4 || rating == 5)
		{
			user User(101);
			User.RateASong(num, rating);

			infDlg Inf;
			Inf.DoModal();
		}
	}
}


void userDlg::OnBnClickeduserexist()
{
	// TODO: 在此添加控件通知处理程序代码
	user User(101);
	User.Exist();

	SendMessage(WM_CLOSE);
}


void userDlg::OnBnClickedNextsong()
{
	// TODO: 在此添加控件通知处理程序代码
	{
		user User(101);
		User.NextSong();
	}

	UpdateList();
}
