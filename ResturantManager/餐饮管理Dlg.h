// ²ÍÒû¹ÜÀíDlg.h : header file
//

#if !defined(AFX_DLG_H__03EB0AFA_3099_46BF_893F_6B4A49E04458__INCLUDED_)
#define AFX_DLG_H__03EB0AFA_3099_46BF_893F_6B4A49E04458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	CImageList m_Imagelist;
	CStatusBar m_Statusbar;
	CToolBar m_Toolbar;
	virtual void OnOK();
	_RecordsetPtr m_pRs;
	CMyDlg(CWnd* pParent = NULL);
// standard constructor


// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMENUlogin();
	afx_msg void OnMENUkaitai();
	afx_msg void OnMENUjiezhang();
	afx_msg void OnBUTTONkaitai();
	afx_msg void OnBUTTONjiezhang();
	afx_msg void OnMENUjiesuan();
	afx_msg void OnBUTTONrishouru();
	afx_msg void OnMENUyuangong();
	afx_msg void OnBUTTONzhuce();
	afx_msg void OnMENUabout();
	afx_msg void OnMENUSPinfo();
	afx_msg void OnMENUjinhuo();
	afx_msg void OnMenuCp();
	afx_msg void OnMENUrishourucx();
	afx_msg void OnMENUyueshouricx();
	afx_msg void OnMENUquanxian();
	afx_msg void OnMENUsqlnew();
	afx_msg void OnMENUsqlcopy();
	afx_msg void OnMENUreturn();
	afx_msg void OnMENUaddcai();
	afx_msg void OnMENUjinhuoselect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
public:
	afx_msg void OnEmployeeWorking();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__03EB0AFA_3099_46BF_893F_6B4A49E04458__INCLUDED_)
