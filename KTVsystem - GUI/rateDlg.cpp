// rateDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "rateDlg.h"
#include "afxdialogex.h"

#include"control.h"

#include<string>
using std::string;

// rateDlg 对话框

IMPLEMENT_DYNAMIC(rateDlg, CDialogEx)

rateDlg::rateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_rateDlg, pParent)
{

	//Rating = 0.0;
}

rateDlg::~rateDlg()
{
}

void rateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EditRate, EditRate);
}


BEGIN_MESSAGE_MAP(rateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OKRate, &rateDlg::OnBnClickedOkrate)
END_MESSAGE_MAP()


// rateDlg 消息处理程序


void rateDlg::OnBnClickedOkrate()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strRating;
	EditRate.GetWindowText(strRating);
	rating = _ttoi(strRating);

	if (rating == 1 || rating == 2 || rating == 3 || rating == 4 || rating == 5)
	SendMessage(WM_CLOSE);
}


int rateDlg::getRate()
{
	// TODO: 在此处添加实现代码.
	return rating;
}
