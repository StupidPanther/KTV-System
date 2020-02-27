#pragma once


// rateDlg 对话框

class rateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(rateDlg)

public:
	rateDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~rateDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_rateDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit EditRate;
	afx_msg void OnBnClickedOkrate();
	int getRate();
private:
	int rating;
};
