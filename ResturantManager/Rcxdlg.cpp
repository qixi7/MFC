// Rcxdlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Rcxdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CRcxdlg dialog

extern CMyApp theApp;
CRcxdlg::CRcxdlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRcxdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRcxdlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CRcxdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRcxdlg)
	DDX_Control(pDX, IDC_COMBO_day, m_Daycombo);
	DDX_Control(pDX, IDC_COMBO_month, m_Monthcombo);
	DDX_Control(pDX, IDC_COMBO_year, m_Yearcombo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRcxdlg, CDialog)
	//{{AFX_MSG_MAP(CRcxdlg)
	ON_BN_CLICKED(IDC_BUTTON_CHAXUN, OnButtonChaxun)
	ON_BN_CLICKED(IDC_BUTTON_tuichu, OnBUTTONtuichu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRcxdlg message handlers

BOOL CRcxdlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString sql;
	CString str;
	sql="select distinct Year(时间) as 年份 from shouru ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("年份");
		m_Yearcombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Month(时间) as 月份 from shouru ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("月份");
		m_Monthcombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Day(时间) as 日期 from shouru ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("日期");
		m_Daycombo.AddString(str);	
		m_pRs->MoveNext();
	}
	return true;
}

void CRcxdlg::OnButtonChaxun() 
{
	UpdateData();
	CString year,month,day,totle;
	if(m_Yearcombo.GetCurSel()==-1||m_Monthcombo.GetCurSel()==-1||m_Daycombo.GetCurSel()==-1)
	{
		AfxMessageBox("请选择一个时间");
		return;
	}
	m_Yearcombo.GetLBText(m_Yearcombo.GetCurSel(),year);
	m_Monthcombo.GetLBText(m_Monthcombo.GetCurSel(),month);
	m_Daycombo.GetLBText(m_Daycombo.GetCurSel(),day);
	CString sql="select * from shouru where Year(时间)="+year+" and Month(时间)="+month+" and Day(时间)="+day+"";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	int record_count = 0;

	while(m_pRs->adoEOF == 0)  //判断是否为空
	{
		record_count++;
		break;
	}

	if (record_count == 0)
	{
		MessageBox(year+"年"+month+"月"+day+"日的收入为： 0 元","日收入查询");
	}
	else
	{
		totle=(char*)(_bstr_t)m_pRs->GetCollect("日收入");
		MessageBox(year+"年"+month+"月"+day+"日的收入为："+totle+"元","日收入查询");	
	}
}

void CRcxdlg::OnBUTTONtuichu()
{
	CDialog::OnCancel();	
}

void CRcxdlg::OnOK()
{
	OnButtonChaxun(); 

}
