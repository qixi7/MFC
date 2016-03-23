#if !defined(AFX_LOGINDLG_H__4107626E_E917_4FD5_9B0E_1CAD1BFBE351__INCLUDED_)
#define AFX_LOGINDLG_H__4107626E_E917_4FD5_9B0E_1CAD1BFBE351__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Logindlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogindlg dialog

class CLogindlg : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;
	CLogindlg(CWnd* pParent = NULL);   // standard constructor
	int i;
// Dialog Data
	//{{AFX_DATA(CLogindlg)
	enum { IDD = IDD_Logindlg };
	CString	m_Uname;
	CString	m_Upasswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogindlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogindlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__4107626E_E917_4FD5_9B0E_1CAD1BFBE351__INCLUDED_)
