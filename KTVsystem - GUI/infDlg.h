#pragma once


// infDlg 对话框

class infDlg : public CDialogEx
{
	DECLARE_DYNAMIC(infDlg)

public:
	infDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~infDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_infDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
