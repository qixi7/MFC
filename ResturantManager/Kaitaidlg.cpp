// Kaitaidlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "Kaitaidlg.h"
#include "Diancaidlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKaitaidlg dialog
extern CMyApp theApp;


CKaitaidlg::CKaitaidlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKaitaidlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKaitaidlg)
	
	//}}AFX_DATA_INIT
}


void CKaitaidlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKaitaidlg)
	DDX_Control(pDX, IDC_LIST1, m_Zhuolist);
	DDX_Text(pDX, IDC_EDIT1, m_ZhuoHao);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKaitaidlg, CDialog)
	//{{AFX_MSG_MAP(CKaitaidlg)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_return, OnBUTTONreturn)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKaitaidlg message handlers





void CKaitaidlg::OnButtonOk() 
{
	UpdateData();

	if(m_ZhuoHao.IsEmpty())
		AfxMessageBox("桌号不能为空");
	else
	{	
		CString Str="select * from TableUSE where TableUSEID=1";
		m_pRs=theApp.m_pCon->Execute((_bstr_t)Str,NULL,adCmdText);
		while(!m_pRs->adoEOF)
		{
			Value=(char*)(_bstr_t)m_pRs->GetCollect("桌号");
			if(m_ZhuoHao==Value)
			{
				AfxMessageBox("有人了");
				m_ZhuoHao="";
				UpdateData(false);
				return;
			}
			m_pRs->MoveNext();
		}
		m_pRs=NULL;
		CString Str1="select * from TableUSE where 桌号="+m_ZhuoHao+"";
		m_pRs=theApp.m_pCon->Execute((_bstr_t)Str1,NULL,adCmdText);
		if(m_pRs->adoEOF)
		{
			
			AfxMessageBox("没有这种桌子");
			m_ZhuoHao="";
			UpdateData(false);
			return;
			
		}
		m_pRs=NULL;
		
		CDiancaidlg dlg;
		dlg.m_ZhuoHao = m_ZhuoHao;
		dlg.DoModal();
		CDialog::OnOK();	
	}

}

void CKaitaidlg::OnBUTTONreturn() 
{
	CDialog::OnCancel();	
}
void CKaitaidlg::OnOK()
{
	OnButtonOk();
}

BOOL CKaitaidlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_kaitai)),TRUE);
	m_Zhuolist.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_Zhuolist.InsertColumn(0,"桌号",LVCFMT_LEFT,140,0);
	m_Zhuolist.InsertColumn(1,"状态",LVCFMT_LEFT,140,1);
	CString sql="select * from tableuse"; 
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql,NULL,adCmdText);
	int i=0;
	while(m_pRs->adoEOF==0)
	{
		CString str=(char*)(_bstr_t)m_pRs->GetCollect("桌号");
		int tableuseid=atoi((char*)(_bstr_t)m_pRs->GetCollect("tableuseid"));
		m_Zhuolist.InsertItem(i,"");
		m_Zhuolist.SetItemText(i,0,str);
		if(tableuseid==0)
			m_Zhuolist.SetItemText(i,1,"空闲");
		if(tableuseid==1)
			m_Zhuolist.SetItemText(i,1,"有人");
		i++;
		m_pRs->MoveNext();
	}



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CKaitaidlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString str;
	str=m_Zhuolist.GetItemText(m_Zhuolist.GetSelectionMark(),0);
	m_ZhuoHao=str;
	UpdateData(false);
	*pResult = 0;
}


