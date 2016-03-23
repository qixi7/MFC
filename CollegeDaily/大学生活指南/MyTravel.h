#pragma once
#include "afxcmn.h"


// CMyTravel 对话框

class CMyTravel : public CDialogEx
{
	DECLARE_DYNAMIC(CMyTravel)

public:
	CMyTravel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyTravel();

// 对话框数据
	enum { IDD = IDD_MYTRAVEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_travelTree;
	virtual BOOL OnInitDialog();

	HTREEITEM quxian;
	HTREEITEM temp_quxian[20];
	HTREEITEM scenic;
	afx_msg void OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);
};
