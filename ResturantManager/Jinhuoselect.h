#if !defined(AFX_JINHUOSELECT_H__C96FCEFE_E0CF_493A_BBE1_015E1835DB3E__INCLUDED_)
#define AFX_JINHUOSELECT_H__C96FCEFE_E0CF_493A_BBE1_015E1835DB3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Jinhuoselect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJinhuoselect dialog

class CJinhuoselect : public CDialog
{
// Construction
public:
	void OnOK();
	_RecordsetPtr m_pRs;
	CJinhuoselect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CJinhuoselect)
	enum { IDD = IDD_jinhuoselect };
	CListCtrl	m_Jinhuoinfo;
	CComboBox	m_Yearcombo;
	CComboBox	m_Monthcombo;
	CComboBox	m_Daycombo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJinhuoselect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJinhuoselect)
	virtual BOOL OnInitDialog();
	afx_msg void OnChaxunButton();
	afx_msg void OnTuichuButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JINHUOSELECT_H__C96FCEFE_E0CF_493A_BBE1_015E1835DB3E__INCLUDED_)
