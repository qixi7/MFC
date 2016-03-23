#if !defined(AFX_QUANXIANDLG_H__6D1A02F6_40F9_40F4_BD41_6465CA57EA95__INCLUDED_)
#define AFX_QUANXIANDLG_H__6D1A02F6_40F9_40F4_BD41_6465CA57EA95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Quanxiandlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuanxiandlg dialog

class CQuanxiandlg : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;
	BOOL OnInitDialog();
	int radio;
	CQuanxiandlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQuanxiandlg)
	enum { IDD = IDD_quanxian };
	CComboBox	m_IDcombo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuanxiandlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuanxiandlg)
	afx_msg void OnRadioBoss();
	afx_msg void OnRADIOlingban();
	afx_msg void OnRADIOyingyeyuan();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnButtonOk();
	afx_msg void OnButtonCancle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUANXIANDLG_H__6D1A02F6_40F9_40F4_BD41_6465CA57EA95__INCLUDED_)
