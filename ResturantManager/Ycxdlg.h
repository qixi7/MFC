#if !defined(AFX_YCXDLG_H__F5D9B57E_AF0B_4775_BA9D_33FC295CEB6F__INCLUDED_)
#define AFX_YCXDLG_H__F5D9B57E_AF0B_4775_BA9D_33FC295CEB6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ycxdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CYcxdlg dialog

class CYcxdlg : public CDialog
{
// Construction
public:
	virtual void OnOK();
	_RecordsetPtr m_pRs;
	BOOL OnInitDialog();
	CYcxdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CYcxdlg)
	enum { IDD = IDD_YSRCX };
	CComboBox	m_MonthCombo;
	CComboBox	m_YearCombo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYcxdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CYcxdlg)
	afx_msg void OnButtonChaxun();
	afx_msg void OnBUTTONtuichu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YCXDLG_H__F5D9B57E_AF0B_4775_BA9D_33FC295CEB6F__INCLUDED_)
