#if !defined(AFX_JINHUODLG_H__3C261E09_DC23_4A79_97BF_89619BA67DB1__INCLUDED_)
#define AFX_JINHUODLG_H__3C261E09_DC23_4A79_97BF_89619BA67DB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Jinhuodlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJinhuodlg dialog

class CJinhuodlg : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;	
	BOOL OnInitDialog();
	CJinhuodlg(CWnd* pParent = NULL);


// Dialog Data
	//{{AFX_DATA(CJinhuodlg)
	enum { IDD = IDD_jinhuodlg };
	CEdit	m_Totle;
	CListCtrl	m_FoodBill;
	CListCtrl	m_FoodList;
	CEdit	m_Times;
	CEdit	m_ShuLiang;
	CString	m_Time;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJinhuodlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJinhuodlg)
	afx_msg void OnBUTTONjinhuo();
	afx_msg void OnBUTTONtuihuo();
	afx_msg void OnBUTTONreset();
	afx_msg void OnBUTTONtuichu();
	afx_msg void OnBUTTONqueding();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JINHUODLG_H__3C261E09_DC23_4A79_97BF_89619BA67DB1__INCLUDED_)
