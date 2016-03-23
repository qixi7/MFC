#if !defined(AFX_SPINFO_H__49F9591F_D46A_4C56_951C_77983B2BED2D__INCLUDED_)
#define AFX_SPINFO_H__49F9591F_D46A_4C56_951C_77983B2BED2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpInfo dialog

class CSpInfo : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;
	BOOL OnInitDialog();
	CSpInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSpInfo)
	enum { IDD = IDD_SPinfo };
	CListCtrl	m_Grid;
	CString	m_Name;
	CString	m_Price;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSpInfo)
	afx_msg void OnBUTTONadd();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONchange();
	afx_msg void OnBUTTONdel();
	afx_msg void OnBUTTONreturn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINFO_H__49F9591F_D46A_4C56_951C_77983B2BED2D__INCLUDED_)
