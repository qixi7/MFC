#if !defined(AFX_SHULIANGDLG_H__7B2A407C_16FB_41F9_AC21_949C1B00D7DE__INCLUDED_)
#define AFX_SHULIANGDLG_H__7B2A407C_16FB_41F9_AC21_949C1B00D7DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Shuliangdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShuliangdlg dialog

class CShuliangdlg : public CDialog
{
// Construction
public:
	CShuliangdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShuliangdlg)
	enum { IDD = IDD_SHULIANG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShuliangdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShuliangdlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHULIANGDLG_H__7B2A407C_16FB_41F9_AC21_949C1B00D7DE__INCLUDED_)
