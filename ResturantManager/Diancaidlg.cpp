// Diancaidlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Diancaidlg.h"
#include "kaitaidlg.h"
#include "SLdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiancaidlg dialog
extern CMyApp theApp;


CDiancaidlg::CDiancaidlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiancaidlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiancaidlg)
	m_ZhuoHao = _T("");
	//}}AFX_DATA_INIT
}


void CDiancaidlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiancaidlg)
	DDX_Control(pDX, IDC_LIST3, m_CaidanCheck);
	DDX_Control(pDX, IDC_LIST2, m_CaidanList);
	DDX_Text(pDX, IDC_EDIT_zhuohao, m_ZhuoHao);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDiancaidlg, CDialog)
	//{{AFX_MSG_MAP(CDiancaidlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonadd)
	ON_BN_CLICKED(IDC_BUTTON_sub, OnBUTTONsub)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiancaidlg message handlers




BOOL CDiancaidlg::OnInitDialog()
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
	return TRUE;
}

void CDiancaidlg::OnButtonadd() 
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

void CDiancaidlg::OnBUTTONsub() 
{
	m_CaidanCheck.DeleteItem(m_CaidanCheck.GetSelectionMark());
}

void CDiancaidlg::OnButtonOk() 
{
	UpdateData();
	CString Sql;
	int i = m_CaidanCheck.GetItemCount();
	if(i==0)
	{
		AfxMessageBox("请点菜");
		return;
	}
	Sql="update TableUSE set TableUSEID=1 where 桌号="+m_ZhuoHao+" ";
	theApp.m_pCon->Execute((_bstr_t)Sql,NULL,adCmdText);
	CString Sql1,Str,Str1,Value,TotleValue;
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
		Sql1="insert into paybill(桌号,菜名,数量,消费) values("+m_ZhuoHao+",'"+Str+"',"+Str1+","+TotleValue+")";
		theApp.m_pCon->Execute((_bstr_t)Sql1,NULL,adCmdText);
	}
	AfxMessageBox("点菜成功");
	CDialog::OnOK();	
}



void CDiancaidlg::OnButtonCancel() 
{
	CDialog::OnCancel();
	
}


void CDiancaidlg::OnOK()
{
	OnButtonOk();
}
