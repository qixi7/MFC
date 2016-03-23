#if !defined(AFX_RETURNDLG_H__AF3A8426_F087_4378_A52D_D1E010479F74__INCLUDED_)
#define AFX_RETURNDLG_H__AF3A8426_F087_4378_A52D_D1E010479F74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Returndlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReturndlg dialog

class CReturndlg : public CDialog
{
// Construction
public:
	CReturndlg(CWnd* pParent = NULL);   // standard constructor
	char buf[256];
// Dialog Data
	//{{AFX_DATA(CReturndlg)
	enum { IDD = IDD_DIALOG_retrun };
	CEdit	m_Edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturndlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReturndlg)
	afx_msg void OnButtonliulan();
	afx_msg void OnBUTTONreturn();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNDLG_H__AF3A8426_F087_4378_A52D_D1E010479F74__INCLUDED_)
