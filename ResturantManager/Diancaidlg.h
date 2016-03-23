#if !defined(AFX_DIANCAIDLG_H__B1FF22CE_C3A9_4AEB_AEAB_76D0FD024908__INCLUDED_)
#define AFX_DIANCAIDLG_H__B1FF22CE_C3A9_4AEB_AEAB_76D0FD024908__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Diancaidlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDiancaidlg dialog

class CDiancaidlg : public CDialog
{
// Construction
public:
	void OnOK();
	BOOL OnInitDialog();
	_RecordsetPtr m_pRs;
	CDiancaidlg(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CDiancaidlg)
	enum { IDD = IDD_diancai };
	CListCtrl	m_CaidanCheck;
	CListCtrl	m_CaidanList;
	CString	m_ZhuoHao;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiancaidlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDiancaidlg)
	afx_msg void OnButtonadd();
	afx_msg void OnBUTTONsub();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIANCAIDLG_H__B1FF22CE_C3A9_4AEB_AEAB_76D0FD024908__INCLUDED_)
