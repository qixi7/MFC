#pragma once
#include "afxwin.h"


// CAddPersonDlg 对话框

class CAddPersonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddPersonDlg)

public:
	CAddPersonDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddPersonDlg();

// 对话框数据
	enum { IDD = IDD_ADDPERSON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedAddOk();
	CButton Boy_ADD;
	CButton Girl_ADD;
};
