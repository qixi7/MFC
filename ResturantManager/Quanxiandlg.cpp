// Quanxiandlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Quanxiandlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuanxiandlg dialog

extern CMyApp theApp;
CQuanxiandlg::CQuanxiandlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQuanxiandlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuanxiandlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CQuanxiandlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuanxiandlg)
	DDX_Control(pDX, IDC_COMBO1, m_IDcombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuanxiandlg, CDialog)
	//{{AFX_MSG_MAP(CQuanxiandlg)
	ON_BN_CLICKED(IDC_RADIO_BOSS, OnRadioBoss)
	ON_BN_CLICKED(IDC_RADIO_lingban, OnRADIOlingban)
	ON_BN_CLICKED(IDC_RADIO_yingyeyuan, OnRADIOyingyeyuan)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, OnButtonCancle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuanxiandlg message handlers

void CQuanxiandlg::OnRadioBoss() 
{
	radio=0;
}

void CQuanxiandlg::OnRADIOlingban() 
{
	radio=1;
}

void CQuanxiandlg::OnRADIOyingyeyuan() 
{
	radio=2;	
}

BOOL CQuanxiandlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString sql="select * from login where Uname<>'"+theApp.name+"'";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{	
		CString str=(char*)(_bstr_t)m_pRs->GetCollect("Uname");
		m_IDcombo.AddString(str);
		m_pRs->MoveNext();
	}

	return true;

}

void CQuanxiandlg::OnSelchangeCombo1() 
{
	UpdateData();
	CString str;
    CButton* boss = (CButton*)GetDlgItem(IDC_RADIO_BOSS);
	CButton* lingban = (CButton*)GetDlgItem(IDC_RADIO_lingban);
	CButton* yingyeyuan = (CButton*)GetDlgItem(IDC_RADIO_yingyeyuan);
	m_IDcombo.GetLBText(m_IDcombo.GetCurSel(),str);
	CString sql="select * from login where Uname='"+str+"'";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	CString pow;
	pow=(char*)(_bstr_t)m_pRs->GetCollect("power");
	radio=atoi(pow);
	if(radio==0)
	{
		boss->SetCheck(1);
		lingban->SetCheck(0);
		yingyeyuan->SetCheck(0);
	}
	if(radio==1)
	{
		boss->SetCheck(0);
		lingban->SetCheck(1);
		yingyeyuan->SetCheck(0);
	}
	if(radio==2)
	{
		boss->SetCheck(0);
		lingban->SetCheck(0);
		yingyeyuan->SetCheck(1);
	}
	UpdateData(false);
	
}

void CQuanxiandlg::OnButtonOk() 
{
	UpdateData();
	CString str,str1;
	if(m_IDcombo.GetCurSel()==-1)
	{
		AfxMessageBox("请选择一个用户");
		return;
	}
	m_IDcombo.GetLBText(m_IDcombo.GetCurSel(),str);
	str1.Format("%d",radio);
	CString sql="update login set power="+str1+" where Uname='"+str+"'";
	theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	AfxMessageBox("修改权限成功");	
}



void CQuanxiandlg::OnButtonCancle() 
{
	CDialog::OnCancel();	
}
