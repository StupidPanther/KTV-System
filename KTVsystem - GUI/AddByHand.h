#pragma once


// AddByHand 对话框

class AddByHand : public CDialogEx
{
	DECLARE_DYNAMIC(AddByHand)

public:
	AddByHand(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddByHand();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddByHand };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit EditSong;
	CEdit EditSinger;
	CEdit EditPinyin;
	afx_msg void OnBnClickedOk();

	afx_msg void OnBnClickedCancel();
};
