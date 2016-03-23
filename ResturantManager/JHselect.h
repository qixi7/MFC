#if !defined(AFX_JHSELECT_H__482155D7_1B78_43D0_95F5_62691E48F55F__INCLUDED_)
#define AFX_JHSELECT_H__482155D7_1B78_43D0_95F5_62691E48F55F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JHselect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJHselect dialog

class CJHselect : public CDialog
{
// Construction
public:
	CJHselect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CJHselect)
	enum { IDD = IDD_jinhuoselect };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJHselect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJHselect)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JHSELECT_H__482155D7_1B78_43D0_95F5_62691E48F55F__INCLUDED_)
