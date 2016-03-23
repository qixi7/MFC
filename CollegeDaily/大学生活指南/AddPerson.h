#pragma once
#include "afxwin.h"


// CAddPerson 对话框

class CAddPerson : public CDialogEx
{
	DECLARE_DYNAMIC(CAddPerson)

public:
	CAddPerson(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddPerson();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedAdd();
	CButton Boy_ADD;
	CButton Girl_ADD;
	
};
