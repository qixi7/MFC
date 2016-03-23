// 餐饮管理.h : main header file for the 餐饮管理 application
//

#if !defined(AFX__H__446DF14A_A8C0_4C72_AE09_16339B51D420__INCLUDED_)
#define AFX__H__446DF14A_A8C0_4C72_AE09_16339B51D420__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyApp:
// See 餐饮管理.cpp for the implementation of this class
//

class CMyApp : public CWinApp
{
public:
	CString pwd;
	CString name;


	_ConnectionPtr m_pCon;
	CMyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__H__446DF14A_A8C0_4C72_AE09_16339B51D420__INCLUDED_)
