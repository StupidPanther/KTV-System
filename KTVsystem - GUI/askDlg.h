#pragma once


// askDlg 对话框

class askDlg : public CDialogEx
{
	DECLARE_DYNAMIC(askDlg)

public:
	askDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~askDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_askDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	bool Sure;
public:
	bool getSure();
	afx_msg void OnBnClickedCancel();
};
