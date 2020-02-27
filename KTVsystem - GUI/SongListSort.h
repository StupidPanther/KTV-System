#pragma once


// SongListSort 对话框

class SongListSort : public CDialogEx
{
	DECLARE_DYNAMIC(SongListSort)

public:
	SongListSort(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SongListSort();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SongListSort };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl SongListS;
	virtual BOOL OnInitDialog();
};
