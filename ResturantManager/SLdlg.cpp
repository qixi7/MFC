// SLdlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "SLdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSLdlg dialog


CSLdlg::CSLdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSLdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSLdlg)
	m_ShuLiang = _T("");
	//}}AFX_DATA_INIT
}


void CSLdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSLdlg)
	DDX_Text(pDX, IDC_EDIT1, m_ShuLiang);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSLdlg, CDialog)
	//{{AFX_MSG_MAP(CSLdlg)
	ON_BN_CLICKED(IDC_BUTTON, OnButtonok)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSLdlg message handlers

void CSLdlg::OnButtonok() 
{
	UpdateData();
	if(m_ShuLiang.IsEmpty()||m_ShuLiang=="0")
	{
		AfxMessageBox("数量至少为1");
		return;
	}

	CDialog::OnOK();
	
}




void CSLdlg::OnButton2() 
{
	CDialog::OnCancel();	
}



BOOL CSLdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_sl)),TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
