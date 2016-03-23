#if !defined(AFX_LOGIN1_H__B3B1FDCA_AE5D_45B7_97D2_9F335CB2DAC7__INCLUDED_)
#define AFX_LOGIN1_H__B3B1FDCA_AE5D_45B7_97D2_9F335CB2DAC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogin1 dialog

class CLogin1 : public CDialog
{
// Construction
public:
	void OnOK();
	_RecordsetPtr m_pRs;
	CLogin1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogin1)
	enum { IDD = IDD_Logindlg };
	CString	m_Uname;
	CString	m_Upasswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogin1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogin1)
	afx_msg void OnStaticCancel();
	afx_msg void OnStaticCancel1();
	afx_msg void OnStaticOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN1_H__B3B1FDCA_AE5D_45B7_97D2_9F335CB2DAC7__INCLUDED_)
