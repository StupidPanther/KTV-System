#pragma once


// searchDlg 对话框

class searchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(searchDlg)

public:
	searchDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~searchDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_searchDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl SearchList;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPlaythesong();
};
