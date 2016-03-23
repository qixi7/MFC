#pragma once
#include "afxwin.h"


// CSelectPerson 对话框

class CSelectPerson : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectPerson)

public:
	CSelectPerson(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectPerson();

// 对话框数据
	enum { IDD = IDD_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedFind();
	CButton Girl_Select;
	CButton Boy_Select;

	CString Select_Name;
	CString Select_Sex;
	CString Select_Tel;
	CString Select_Email;
};
