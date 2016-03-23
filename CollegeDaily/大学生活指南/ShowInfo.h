#pragma once


// CShowInfo 对话框

class CShowInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CShowInfo)

public:
	CShowInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CShowInfo();

// 对话框数据
	enum { IDD = IDD_SHOWINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();


public:
	CString Show_Name;
	CString Show_Sex;
	CString Show_Tel;
	CString Show_Email;
	afx_msg void OnClickedOk();
};
