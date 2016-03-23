// Jiacaidlg1.cpp : implementation file
//

#include "stdafx.h"
#include "≤Õ“˚π‹¿Ì.h"
#include "Jiacaidlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJiacaidlg dialog


CJiacaidlg1::CJiacaidlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CJiacaidlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJiacaidlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CJiacaidlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJiacaidlg)
	DDX_Control(pDX, IDC_LIST3, m_CaidanCheck);
	DDX_Control(pDX, IDC_LIST2, m_CaidanList);
	DDX_Control(pDX, IDC_COMBO1, m_ZhuohaoCombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJiacaidlg1, CDialog)
	//{{AFX_MSG_MAP(CJiacaidlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJiacaidlg message handlers
