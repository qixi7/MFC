#if !defined(AFX_COPYDLG_H__378F304F_3C6C_4FC8_9CDF_639F4906FFE7__INCLUDED_)
#define AFX_COPYDLG_H__378F304F_3C6C_4FC8_9CDF_639F4906FFE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Copydlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCopydlg dialog

class CCopydlg : public CDialog
{
// Construction
public:
	CCopydlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCopydlg)
	enum { IDD = IDD_COPY };
	CEdit	m_Edit;
	CString	m_Name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCopydlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCopydlg)
	afx_msg void OnBUTTONcheckml();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPYDLG_H__378F304F_3C6C_4FC8_9CDF_639F4906FFE7__INCLUDED_)
