#if !defined(AFX_JIACAIDLG_H__6739D1E8_4CD5_4545_8326_4367AF55A988__INCLUDED_)
#define AFX_JIACAIDLG_H__6739D1E8_4CD5_4545_8326_4367AF55A988__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Jiacaidlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJiacaidlg dialog

class CJiacaidlg : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;
	CJiacaidlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CJiacaidlg)
	enum { IDD = IDD_jiacai };
	CComboBox	m_ZhuohaoCombo;
	CListCtrl	m_CaidanCheck;
	CListCtrl	m_CaidanList;
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
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnButtonadd();
	afx_msg void OnButtonsub();
	afx_msg void OnButtonOK();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIACAIDLG_H__6739D1E8_4CD5_4545_8326_4367AF55A988__INCLUDED_)
