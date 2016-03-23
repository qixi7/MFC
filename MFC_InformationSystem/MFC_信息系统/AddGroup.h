#pragma once


// CAddGroup 对话框

class CAddGroup : public CDialogEx
{
	DECLARE_DYNAMIC(CAddGroup)

public:
	CAddGroup(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddGroup();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedAddGroup();
};
