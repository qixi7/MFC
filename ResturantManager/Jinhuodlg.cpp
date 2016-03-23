// Jinhuodlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Jinhuodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJinhuodlg dialog

extern CMyApp theApp;
CJinhuodlg::CJinhuodlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJinhuodlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJinhuodlg)
	//}}AFX_DATA_INIT
}


void CJinhuodlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJinhuodlg)
	DDX_Control(pDX, IDC_EDIT_totle, m_Totle);
	DDX_Control(pDX, IDC_LIST_foodbill, m_FoodBill);
	DDX_Control(pDX, IDC_LIST_foodlist, m_FoodList);
	DDX_Control(pDX, IDC_EDIT_time, m_Times);
	DDX_Control(pDX, IDC_EDIT_shuliang, m_ShuLiang);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJinhuodlg, CDialog)
	//{{AFX_MSG_MAP(CJinhuodlg)
	ON_BN_CLICKED(IDC_BUTTON_jinhuo, OnBUTTONjinhuo)
	ON_BN_CLICKED(IDC_BUTTON_tuihuo, OnBUTTONtuihuo)
	ON_BN_CLICKED(IDC_BUTTON_reset, OnBUTTONreset)
	ON_BN_CLICKED(IDC_BUTTON_tuichu, OnBUTTONtuichu)
	ON_BN_CLICKED(IDC_BUTTON_queding, OnBUTTONqueding)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJinhuodlg message handlers

BOOL CJinhuodlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CTime time;
	time=CTime::GetCurrentTime();
	m_Time=time.Format("%Y-%m-%d");
	m_Times.SetWindowText(m_Time);
	m_FoodList.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_FoodList.InsertColumn(0,"商品名",LVCFMT_LEFT,80,0);
	m_FoodList.InsertColumn(1,"单价(元)",LVCFMT_LEFT,100,1);
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from shangpininfo"),NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{
		CString Value1,Value2;
		Value1=(char*)(_bstr_t)m_pRs->GetCollect("商品名");
		Value2=(char*)(_bstr_t)m_pRs->GetCollect("商品单价");
		m_FoodList.InsertItem(0,"");
		m_FoodList.SetItemText(0,0,Value1);
		m_FoodList.SetItemText(0,1,Value2);		
		m_pRs->MoveNext();
	}
	m_FoodBill.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_FoodBill.InsertColumn(0,"商品名",LVCFMT_LEFT,80,0);
	m_FoodBill.InsertColumn(1,"数量(斤)",LVCFMT_LEFT,100,1);
	m_Totle.SetWindowText("0");
	m_ShuLiang.SetWindowText("1");
	return TRUE;
}
double totle=0;

void CJinhuodlg::OnBUTTONjinhuo() 
{
	UpdateData();
	int n=m_FoodList.GetSelectionMark();
	if(n==-1)
	{
		AfxMessageBox("请选择一样商品");
		return;
	}
	CString name=m_FoodList.GetItemText(n,0);
	CString price=m_FoodList.GetItemText(n,1);
	CString shuliang,Mytotle;
	m_ShuLiang.GetWindowText(shuliang);
	if(shuliang.IsEmpty()||shuliang=="0")
	{
		AfxMessageBox("数量至少为1斤");
		return;
	}
	m_FoodBill.InsertItem(0,"");
	m_FoodBill.SetItemText(0,0,name);
	m_FoodBill.SetItemText(0,1,shuliang);	
	totle+=atof(price)*atof(shuliang);
	Mytotle=(char*)(_bstr_t)totle;
	m_Totle.SetWindowText(Mytotle);
	UpdateData(false);

}

void CJinhuodlg::OnBUTTONtuihuo() 
{
	UpdateData();
	CString Mytotle;
	m_Totle.GetWindowText(Mytotle);
	totle=atof(Mytotle);
	int n=m_FoodBill.GetSelectionMark();
	CString str=m_FoodBill.GetItemText(n,0);
	CString shuliang=m_FoodBill.GetItemText(n,1);
	m_FoodBill.DeleteItem(n);
	CString str1;
	int i=m_FoodList.GetItemCount();
	for(int j=0;j<i;j++)
	{
		str1=m_FoodList.GetItemText(j,0);
		if(str==str1)
		{
			CString price=m_FoodList.GetItemText(j,1);
			totle-=atof(price)*atof(shuliang);
			break;
		}
	}
	Mytotle=(char*)(_bstr_t)totle;
	m_Totle.SetWindowText(Mytotle);
	UpdateData(false);

}



void CJinhuodlg::OnBUTTONreset() 
{
	m_FoodBill.DeleteAllItems();
	m_Totle.SetWindowText("0");
	totle=0;
}

void CJinhuodlg::OnBUTTONtuichu() 
{
	CDialog::OnCancel();
}

void CJinhuodlg::OnBUTTONqueding() 
{
	UpdateData();
	m_Times.GetWindowText(m_Time);
	int i=m_FoodBill.GetItemCount();
	int n=m_FoodList.GetItemCount();
	CString sql,name,shuliang,Mtotle,str,price;
	for(int j=0;j<i;j++)
	{
		name=m_FoodBill.GetItemText(j,0);
		shuliang=m_FoodBill.GetItemText(j,1);	
		for(int k=0;k<n;k++)
		{
			str=m_FoodList.GetItemText(k,0);
			if(name==str)
			{
				price=m_FoodList.GetItemText(k,1);
				totle=atof(price)*atof(shuliang);
				break;
			}
		}
		Mtotle=(char*)(_bstr_t)price;
		sql="insert into jinhuoinfo(进货时间,商品名,商品数量,商品价格)values('"+m_Time+"','"+name+"',"+shuliang+","+Mtotle+")";
		theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	CDialog::OnOK();
}


