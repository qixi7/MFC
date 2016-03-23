#pragma once
#include "afxcmn.h"


// CBeiWangDlg 对话框

class CBeiWangDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBeiWangDlg)

public:
	CBeiWangDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBeiWangDlg();

// 对话框数据
	enum { IDD = IDD_BEIWANG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTreeCtrl m_beiwangTree;
	afx_msg void OnClickedSave();

	CString title;
	CString m_beiwang;
	
	afx_msg void OnDblclkTreeBeiwang(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedRemove();
	afx_msg void OnClickedClear();
};
