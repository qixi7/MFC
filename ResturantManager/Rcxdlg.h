#if !defined(AFX_RCXDLG_H__9CBC8254_2803_42A5_9935_9111BA0793E8__INCLUDED_)
#define AFX_RCXDLG_H__9CBC8254_2803_42A5_9935_9111BA0793E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Rcxdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRcxdlg dialog

class CRcxdlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	_RecordsetPtr m_pRs;
	BOOL OnInitDialog();
	CRcxdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRcxdlg)
	enum { IDD = IDD_RSRCX };
	CComboBox	m_Daycombo;
	CComboBox	m_Monthcombo;
	CComboBox	m_Yearcombo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRcxdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRcxdlg)
	afx_msg void OnButtonChaxun();
	afx_msg void OnBUTTONtuichu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RCXDLG_H__9CBC8254_2803_42A5_9935_9111BA0793E8__INCLUDED_)
