#if !defined(AFX_JIACAIDLG1_H__F266D2DB_4A84_47C3_8C4B_3871EA2EAD95__INCLUDED_)
#define AFX_JIACAIDLG1_H__F266D2DB_4A84_47C3_8C4B_3871EA2EAD95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Jiacaidlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJiacaidlg dialog

class CJiacaidlg1 : public CDialog
{
// Construction
public:
	CJiacaidlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CJiacaidlg)
	enum { IDD = IDD_jiacai };
	CListCtrl	m_CaidanCheck;
	CListCtrl	m_CaidanList;
	CComboBox	m_ZhuohaoCombo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJiacaidlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJiacaidlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIACAIDLG1_H__F266D2DB_4A84_47C3_8C4B_3871EA2EAD95__INCLUDED_)
