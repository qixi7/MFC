// Returndlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Returndlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturndlg dialog


CReturndlg::CReturndlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReturndlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturndlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReturndlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturndlg)
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReturndlg, CDialog)
	//{{AFX_MSG_MAP(CReturndlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonliulan)
	ON_BN_CLICKED(IDC_BUTTON_return, OnBUTTONreturn)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturndlg message handlers

void CReturndlg::OnButtonliulan() 
{
	CFileDialog dlg(TRUE,"mdb",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "(*.mdb)|*.mdb",NULL);
	if(dlg.DoModal()==IDOK)
	{
		CString str;
		str = dlg.GetPathName();
		m_Edit.SetWindowText(str);
	}
		
}

void CReturndlg::OnBUTTONreturn() 
{
	UpdateData();
	CString str;
	m_Edit.GetWindowText(str);	
	CopyFile(str,buf,false);//复制文件
	MessageBox("还原完成！","系统提示",MB_OK|MB_ICONEXCLAMATION);
	CDialog::OnOK();


	
}

BOOL CReturndlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	::GetCurrentDirectory(256,buf);
	strcat(buf,"\\canyin.mdb");
	return TRUE;              
}

void CReturndlg::OnButtonCancel() 
{
	CDialog::OnCancel();	
}
