#pragma once
#include<string>
using std::string;

// alterDlg 对话框

class alterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(alterDlg)

public:
	alterDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~alterDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_alter };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	string strSong;
	string strSinger;
	string strPinyin;
public:
	afx_msg void OnBnClickedOk();
	CEdit EditSong;
	CEdit EditSinger;
	CEdit EditPinyin;
	string getSong();
	string getSinger();
	string getPinyin();
};
