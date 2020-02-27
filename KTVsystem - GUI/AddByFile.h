#pragma once
#include<string>
using std::string;

// AddByFile 对话框

class AddByFile : public CDialogEx
{
	DECLARE_DYNAMIC(AddByFile)

public:
	AddByFile(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddByFile();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddByFile };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit EditPath;
	afx_msg void OnBnClickedOk();

public:
	string getPath();
private:
	string strPath;
};
