// SongListSort.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "SongListSort.h"
#include "afxdialogex.h"

#include"service.h"


// SongListSort 对话框

IMPLEMENT_DYNAMIC(SongListSort, CDialogEx)

SongListSort::SongListSort(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SongListSort, pParent)
{

}

SongListSort::~SongListSort()
{
}

void SongListSort::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SongListS, SongListS);
}


BEGIN_MESSAGE_MAP(SongListSort, CDialogEx)
END_MESSAGE_MAP()


// SongListSort 消息处理程序


BOOL SongListSort::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	int num_wide = 7;
	CRect rect;
	tolist list;
	vector<string> strlist = list.get();

	// 获取编程语言列表视图控件的位置和大小   
	SongListS.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	SongListS.SetExtendedStyle(SongListS.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加列
	int i;
	for (i = 0; i < num_wide; i++)
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		SongListS.InsertColumn(i, CstrTemp, LVCFMT_CENTER, rect.Width() / num_wide, 0);
	}

	// 在列表视图控件中插入列表项，并设置列表子项文本
	int row = 0;
	while (i < strlist.size())
	{
		CString CstrTemp;
		CstrTemp = (strlist[i]).c_str();
		SongListS.InsertItem(row, CstrTemp);
		for (int j = 0; j < num_wide; j++, i++)
		{
			CString CstrTemp;
			CstrTemp = (strlist[i]).c_str();
			SongListS.SetItemText(row, j, CstrTemp);
		}
		row++;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
