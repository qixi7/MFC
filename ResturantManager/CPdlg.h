#if !defined(AFX_CPDLG_H__1EE9027C_D3A1_4175_8A8B_2C6CB0F2F489__INCLUDED_)
#define AFX_CPDLG_H__1EE9027C_D3A1_4175_8A8B_2C6CB0F2F489__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CPdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCPdlg dialog

class CCPdlg : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;
	BOOL OnInitDialog();
	CCPdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCPdlg)
	enum { IDD = IDD_CPinfo };
	CListCtrl	m_CpList;
	CString	m_Name;
	CString	m_Price;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCPdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCPdlg)
	afx_msg void OnButtonadd();
	afx_msg void OnButton2();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONchange();
	afx_msg void OnBUTTONdel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPDLG_H__1EE9027C_D3A1_4175_8A8B_2C6CB0F2F489__INCLUDED_)
