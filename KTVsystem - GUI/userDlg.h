#pragma once


// userDlg 对话框

class userDlg : public CDialogEx
{
	DECLARE_DYNAMIC(userDlg)

public:
	userDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~userDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_userDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl UserSongList;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeeditsearch();
	CEdit EditSearch;
	afx_msg void OnBnClickedsearch();

	void UpdateList();
	afx_msg void OnBnClickedStickontop();
	afx_msg void OnBnClickedDeleteasong();
	afx_msg void OnBnClickedRateasong();
	afx_msg void OnBnClickeduserexist();
	afx_msg void OnBnClickedNextsong();
};
