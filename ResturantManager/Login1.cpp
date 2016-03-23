// Login1.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Login1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogin1 dialog

extern CMyApp theApp;
CLogin1::CLogin1(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogin1)
	m_Uname = _T("");
	m_Upasswd = _T("");
	//}}AFX_DATA_INIT
}


void CLogin1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin1)
	DDX_Text(pDX, IDC_EDIT_name, m_Uname);
	DDX_Text(pDX, IDC_EDIT_passwd, m_Upasswd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin1, CDialog)
	//{{AFX_MSG_MAP(CLogin1)
	ON_BN_CLICKED(IDC_STATIC_CANCEL, OnStaticCancel)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin1 message handlers

//DEL void CLogin1::OnStaticOk() 
//DEL {
//DEL 	
//DEL 	
//DEL }

void CLogin1::OnStaticCancel() 
{
	CDialog::OnCancel();
	
}
void CLogin1::OnStaticOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(!m_Uname.IsEmpty()&&!m_Upasswd.IsEmpty()||true)
	{
		CString sql="SELECT * FROM Login WHERE Uname='"+m_Uname+"' and Upasswd='"+m_Upasswd+"'";
		try
		{
			m_pRs.CreateInstance("ADODB.Recordset");
			m_pRs->Open((_variant_t)sql,theApp.m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
			if(m_pRs->adoEOF)
			{
				AfxMessageBox("用户名或密码错误!");	
				m_Uname="";
				m_Upasswd="";
				UpdateData(false);
			}
			else
			{
				theApp.name=m_Uname;
				theApp.pwd=m_Upasswd;
				CDialog::OnOK();
				return;
			}
		}
		catch(_com_error e)
		{
			CString temp;
			temp.Format("连接数据库错误信息:%s",e.ErrorMessage());
			AfxMessageBox(temp);
			return;				
		}
	}
	else
	{
		AfxMessageBox("用户名密码不能为空");
	}
}

void CLogin1::OnOK()
{
	OnStaticOk();
}
