#pragma once
#include "afxcmn.h"


// CMyStudy 对话框

class CMyStudy : public CDialogEx
{
	DECLARE_DYNAMIC(CMyStudy)

public:
	CMyStudy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyStudy();

// 对话框数据
	enum { IDD = IDD_MYSTUDY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_studyTree;
//	afx_msg void OnBnClickedButton1();
//	afx_msg void OnEnChangeEdit2();
	afx_msg void OnClickedAddStudy();
	afx_msg void OnClickedRemove();
//	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);

	HTREEITEM xueyuan;
	HTREEITEM temp_xuyuan[13];
	HTREEITEM course;

	virtual BOOL OnInitDialog();
};
