#if !defined(AFX_JIEZHANGDLG_H__FAD63129_2B70_4042_90CC_29752048F214__INCLUDED_)
#define AFX_JIEZHANGDLG_H__FAD63129_2B70_4042_90CC_29752048F214__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Jiezhangdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJiezhangdlg dialog

class CJiezhangdlg : public CDialog
{
// Construction
public:
		_RecordsetPtr m_pRs;
	virtual void OnOK();
	BOOL OnInitDialog();
	CJiezhangdlg(CWnd* pParent = NULL);   // standard constructor
	BOOL res;
// Dialog Data
	//{{AFX_DATA(CJiezhangdlg)
	enum { IDD = IDD_jiezhangdlg };
	CListCtrl	m_MingXi;
	CEdit	m_ZhaoLing;
	CEdit	m_YingShou;
	CEdit	m_ShiShou;
	CComboBox	m_Combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJiezhangdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJiezhangdlg)
	afx_msg void OnButtonOk2();
	afx_msg void OnButtonBye();
	afx_msg void OnChangeEDITshishou();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnEditchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIEZHANGDLG_H__FAD63129_2B70_4042_90CC_29752048F214__INCLUDED_)
