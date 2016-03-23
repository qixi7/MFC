// Jinhuoselect.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Jinhuoselect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJinhuoselect dialog

extern CMyApp theApp;
CJinhuoselect::CJinhuoselect(CWnd* pParent /*=NULL*/)
	: CDialog(CJinhuoselect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJinhuoselect)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CJinhuoselect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJinhuoselect)
	DDX_Control(pDX, IDC_LIST1, m_Jinhuoinfo);
	DDX_Control(pDX, IDC_COMBO_year, m_Yearcombo);
	DDX_Control(pDX, IDC_COMBO_month, m_Monthcombo);
	DDX_Control(pDX, IDC_COMBO_day, m_Daycombo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJinhuoselect, CDialog)
	//{{AFX_MSG_MAP(CJinhuoselect)
	ON_BN_CLICKED(IDC_CHAXUN_BUTTON, OnChaxunButton)
	ON_BN_CLICKED(IDC_TUICHU_BUTTON, OnTuichuButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJinhuoselect message handlers

BOOL CJinhuoselect::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	CString sql;
	CString str;
	sql="select distinct Year(进货时间) as 年份 from jinhuoinfo ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("年份");
		m_Yearcombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Month(进货时间) as 月份 from jinhuoinfo ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("月份");
		m_Monthcombo.AddString(str);	
		m_pRs->MoveNext();
	}
	
	sql="select distinct Day(进货时间) as 日期 from jinhuoinfo ";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		str=(char*)(_bstr_t)m_pRs->GetCollect("日期");
		m_Daycombo.AddString(str);	
		m_pRs->MoveNext();
	}
	m_Jinhuoinfo.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_Jinhuoinfo.InsertColumn(0,"商品名",LVCFMT_LEFT,60,0);
	m_Jinhuoinfo.InsertColumn(1,"数量(斤)",LVCFMT_LEFT,80,1);
	m_Jinhuoinfo.InsertColumn(2,"价格(元)",LVCFMT_LEFT,80,2);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CJinhuoselect::OnChaxunButton() 
{	
	m_Jinhuoinfo.DeleteAllItems();
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
	CString sql="select * from jinhuoinfo where Year(进货时间)="+year+" and Month(进货时间)="+month+" and Day(进货时间)="+day+"";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		CString name,sum,price;
		name=(char*)(_bstr_t)m_pRs->GetCollect("商品名");
		sum=(char*)(_bstr_t)m_pRs->GetCollect("商品数量");
		price=(char*)(_bstr_t)m_pRs->GetCollect("商品价格");
		m_Jinhuoinfo.InsertItem(0,"");
		m_Jinhuoinfo.SetItemText(0,0,name);
		m_Jinhuoinfo.SetItemText(0,1,sum);
		m_Jinhuoinfo.SetItemText(0,2,price);
		m_pRs->MoveNext();
	}
}

void CJinhuoselect::OnTuichuButton() 
{
	CDialog::OnCancel();	
}

void CJinhuoselect::OnOK()
{
	OnChaxunButton();
}
