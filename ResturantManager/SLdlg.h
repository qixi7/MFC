#if !defined(AFX_SLDLG_H__0B7FABF0_0792_440A_B340_7166447F1236__INCLUDED_)
#define AFX_SLDLG_H__0B7FABF0_0792_440A_B340_7166447F1236__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SLdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSLdlg dialog

class CSLdlg : public CDialog
{
// Construction
public:
	CSLdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSLdlg)
	enum { IDD = IDD_SHULIANG };
	CString	m_ShuLiang;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSLdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSLdlg)
	afx_msg void OnButtonok();
	afx_msg void OnButton2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLDLG_H__0B7FABF0_0792_440A_B340_7166447F1236__INCLUDED_)
