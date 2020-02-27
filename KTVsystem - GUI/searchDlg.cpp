// searchDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "searchDlg.h"
#include "afxdialogex.h"

#include"infDlg.h"

#include"service.h"
#include"control.h"

// searchDlg 对话框

IMPLEMENT_DYNAMIC(searchDlg, CDialogEx)

searchDlg::searchDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_searchDlg, pParent)
{

}

searchDlg::~searchDlg()
{
}

void searchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SearchList, SearchList);
}


BEGIN_MESSAGE_MAP(searchDlg, CDialogEx)
	ON_BN_CLICKED(IDC_PlayTheSong, &searchDlg::OnBnClickedPlaythesong)
END_MESSAGE_MAP()


// searchDlg 消息处理程序


BOOL searchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	int num_wide = 7;
	CRect rect;
	tolist list;
	vector<string> strlist = list.get();

	// 获取编程语言列表视图控件的位置和大小   
	SearchList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	SearchList.SetExtendedStyle(SearchList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加列
	int i;
	for (i = 0; i < num_wide; i++)
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		SearchList.InsertColumn(i, CstrTemp, LVCFMT_CENTER, rect.Width() / num_wide, 0);
	}

	// 在列表视图控件中插入列表项，并设置列表子项文本
	int row = 0;
	while (i < strlist.size())
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		SearchList.InsertItem(row, CstrTemp);
		for (int j = 0; j < num_wide; j++, i++)
		{
			CString CstrTemp;
			CstrTemp = (strlist[i]).c_str();
			SearchList.SetItemText(row, j, CstrTemp);
		}
		row++;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void searchDlg::OnBnClickedPlaythesong()
{
	// TODO: 在此添加控件通知处理程序代码
	int Cur = SearchList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	CString c_num = SearchList.GetItemText(Cur, 0);
	int num = _ttoi(c_num);
	
	if (Cur >= 0)
	{
		user User(101);
		User.PlayASong(num);

		infDlg Inf;
		Inf.DoModal();

		SendMessage(WM_CLOSE);
	}
}
