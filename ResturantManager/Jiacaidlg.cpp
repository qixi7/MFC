// Jiacaidlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Jiacaidlg.h"
#include "Sldlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJiacaidlg dialog

extern CMyApp theApp;
CJiacaidlg::CJiacaidlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJiacaidlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJiacaidlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CJiacaidlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJiacaidlg)
	DDX_Control(pDX, IDC_COMBO1, m_ZhuohaoCombo);
	DDX_Control(pDX, IDC_LIST3, m_CaidanCheck);
	DDX_Control(pDX, IDC_LIST2, m_CaidanList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJiacaidlg, CDialog)
	//{{AFX_MSG_MAP(CJiacaidlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonadd)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonsub)
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonOK)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJiacaidlg message handlers

BOOL CJiacaidlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_diancai)),TRUE);
	CString Sql="select * from caishiinfo";
	m_CaidanList.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_CaidanList.InsertColumn(0,"菜名",LVCFMT_LEFT,100,0);
	m_CaidanList.InsertColumn(1,"菜价(元)",LVCFMT_LEFT,100,1);
	m_pRs=theApp.m_pCon->Execute((_bstr_t)Sql,NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{
		CString TheValue,TheValue1;
		TheValue=(char*)(_bstr_t)m_pRs->GetCollect("菜名");
		TheValue1=(char*)(_bstr_t)m_pRs->GetCollect("菜价");
		m_CaidanList.InsertItem(0,"");
		m_CaidanList.SetItemText(0,0,TheValue);
		m_CaidanList.SetItemText(0,1,TheValue1);
		m_pRs->MoveNext();
	}
	m_CaidanCheck.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_CaidanCheck.InsertColumn(0,"菜名",LVCFMT_LEFT,100,0);
	m_CaidanCheck.InsertColumn(1,"数量(盘)",LVCFMT_LEFT,100,1);

	Sql="select distinct 桌号 from paybill";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)Sql,NULL,adCmdText);
	while(m_pRs->adoEOF==0)
	{
		CString zhuohao=(char*)(_bstr_t)m_pRs->GetCollect("桌号");
		m_ZhuohaoCombo.AddString(zhuohao);
		m_pRs->MoveNext();
	}
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CJiacaidlg::OnSelchangeCombo1() 
{
	CString str;
	m_ZhuohaoCombo.GetLBText(m_ZhuohaoCombo.GetCurSel(),str);
	CString sql="select * from paybill where 桌号="+str+"";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	m_CaidanCheck.DeleteAllItems();
	while(!m_pRs->adoEOF)
	{
		CString valuename=(char*)(_bstr_t)m_pRs->GetCollect("菜名");
		CString valuenum=(char*)(_bstr_t)m_pRs->GetCollect("数量");
		m_CaidanCheck.InsertItem(0,"");
		m_CaidanCheck.SetItemText(0,0,valuename);
		m_CaidanCheck.SetItemText(0,1,valuenum);
		m_pRs->MoveNext();
	}

}

void CJiacaidlg::OnButtonadd() 
{
	CSLdlg Sldlg;
	if(Sldlg.DoModal()==IDOK)
	{		
		int i = m_CaidanList.GetSelectionMark();
		CString str = m_CaidanList.GetItemText(i,0);
		m_CaidanCheck.InsertItem(0,"");
		m_CaidanCheck.SetItemText(0,0,str);
		m_CaidanCheck.SetItemText(0,1,Sldlg.m_ShuLiang);	
	}	
}

void CJiacaidlg::OnButtonsub() 
{
	m_CaidanCheck.DeleteItem(m_CaidanCheck.GetSelectionMark());	
}

void CJiacaidlg::OnButtonOK() 
{
	UpdateData();
	CString Sql;
	CString zhuohao;
	if(m_ZhuohaoCombo.GetCurSel()==-1)
	{
		AfxMessageBox("请选择要加菜的桌号");
		return;
	}
	m_ZhuohaoCombo.GetLBText(m_ZhuohaoCombo.GetCurSel(),zhuohao);
	int i = m_CaidanCheck.GetItemCount();
	if(i==0)
	{
		AfxMessageBox("请点菜");
		return;
	}
	CString Sql1,Str,Str1,Value,TotleValue;
	Sql1="delete from paybill where 桌号="+zhuohao+"";
	theApp.m_pCon->Execute((_bstr_t)Sql1,NULL,adCmdText);
	double Totle=0;
	for(int n=0;n<i;n++)
	{
	Str=m_CaidanCheck.GetItemText(n,0);
	Str1=m_CaidanCheck.GetItemText(n,1);
	Sql1="select * from caishiinfo where 菜名='"+Str+"'";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)Sql1,NULL,adCmdText);
	Value=(char*)(_bstr_t)m_pRs->GetCollect("菜价");
	Totle=atof(Value)*atof(Str1);
	TotleValue=(char*)(_bstr_t)Totle;
	Sql1="insert into paybill(桌号,菜名,数量,消费) values("+zhuohao+",'"+Str+"',"+Str1+","+TotleValue+")";
	theApp.m_pCon->Execute((_bstr_t)Sql1,NULL,adCmdText);
	}
	AfxMessageBox("操作成功");
	CDialog::OnOK();		
		
}

void CJiacaidlg::OnButton4() 
{
	CDialog::OnCancel();	
}
