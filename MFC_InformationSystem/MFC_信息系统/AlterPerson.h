#pragma once
#include "afxwin.h"


// CAlterPerson 对话框

class CAlterPerson : public CDialogEx
{
	DECLARE_DYNAMIC(CAlterPerson)

public:
	CAlterPerson(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAlterPerson();

// 对话框数据
	enum { IDD = IDD_ALTER_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedEnsureAlter();
	CString Alter_Name;
	CString Alter_Sex;
	CString Alter_Tel;
	CString Alter_Email;
	CButton Boy_Selected;
//	CButton Girl_Selected;
	virtual BOOL OnInitDialog();     //添加的对话框初始化虚函数
	CEdit CEdit_Name;
	CEdit CEdit_Tel;
	CEdit CEdit_Email;
	CButton Girl_Selected;
};
