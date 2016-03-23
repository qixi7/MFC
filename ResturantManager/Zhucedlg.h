#if !defined(AFX_ZHUCEDLG_H__6D12C887_9386_4C1D_9700_305668FEBD00__INCLUDED_)
#define AFX_ZHUCEDLG_H__6D12C887_9386_4C1D_9700_305668FEBD00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Zhucedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZhucedlg dialog

class CZhucedlg : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;
	CZhucedlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CZhucedlg)
	enum { IDD = IDD_zhuce };
	CString	m_Name;
	CString	m_Pwd;
	CString	m_Pwd1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhucedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZhucedlg)
	afx_msg void OnButtonOk();
	afx_msg void OnBUTTONreset();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUCEDLG_H__6D12C887_9386_4C1D_9700_305668FEBD00__INCLUDED_)
