#pragma once


// SongList 对话框

class SongList : public CDialogEx
{
	DECLARE_DYNAMIC(SongList)

public:
	SongList(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SongList();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SongList };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl ListSongList;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAlter();
	afx_msg void OnBnClickedDel();
	void UpdateList();
};
