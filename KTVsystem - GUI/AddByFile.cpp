// AddByFile.cpp: 实现文件
//

#include "stdafx.h"
#include "KTVsystem - GUI.h"
#include "AddByFile.h"
#include "afxdialogex.h"

#include"control.h"


// AddByFile 对话框

IMPLEMENT_DYNAMIC(AddByFile, CDialogEx)

AddByFile::AddByFile(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AddByFile, pParent)
{

}

AddByFile::~AddByFile()
{
}

void AddByFile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITPath, EditPath);
}


BEGIN_MESSAGE_MAP(AddByFile, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddByFile::OnBnClickedOk)
END_MESSAGE_MAP()


// AddByFile 消息处理程序


void AddByFile::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strRating;
	EditPath.GetWindowText(strRating);
	strPath = CW2A(strRating.GetString());

	SendMessage(WM_CLOSE);

	CDialogEx::OnOK();
}


string AddByFile::getPath()
{
	// TODO: 在此处添加实现代码.
	return strPath;
}
