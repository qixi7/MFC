#if !defined(AFX_KAITAIDLG_H__333E5789_DB0C_4537_BD6E_7D2426A0DA15__INCLUDED_)
#define AFX_KAITAIDLG_H__333E5789_DB0C_4537_BD6E_7D2426A0DA15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Kaitaidlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKaitaidlg dialog

class CKaitaidlg : public CDialog
{
// Construction
public:
	CString Value;
	_RecordsetPtr m_pRs;
	CKaitaidlg(CWnd* pParent = NULL);   // standard constructor
	virtual void OnOK();
// Dialog Data
	//{{AFX_DATA(CKaitaidlg)
	enum { IDD = IDD_kaitaidlg };
	CListCtrl	m_Zhuolist;
	CString	m_ZhuoHao;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKaitaidlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKaitaidlg)
	afx_msg void OnButtonOk();
	afx_msg void OnBUTTONreturn();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KAITAIDLG_H__333E5789_DB0C_4537_BD6E_7D2426A0DA15__INCLUDED_)
