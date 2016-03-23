// 餐饮管理Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理.h"
#include "餐饮管理Dlg.h"
#include "Logindlg.h"
#include "Kaitaidlg.h"
#include "Jiezhangdlg.h"
#include "Diancaidlg.h"
#include "Zhucedlg.h"
#include "Spinfo.h"
#include "Jinhuodlg.h"
#include "CPdlg.h"
#include "Rcxdlg.h"
#include "Ycxdlg.h"
#include "Quanxiandlg.h"
#include "Copydlg.h"
#include "Returndlg.h"
#include "Jiacaidlg.h"
#include "Jinhuoselect.h"
#include "EmployeeWork.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern CMyApp theApp;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)

	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_login, OnMENUlogin)
	ON_COMMAND(ID_MENU_kaitai, OnMENUkaitai)
	ON_COMMAND(ID_MENU_jiezhang, OnMENUjiezhang)
	ON_COMMAND(IDB_kaitai, OnBUTTONkaitai)
	ON_COMMAND(IDB_pay, OnBUTTONjiezhang)
	ON_COMMAND(ID_MENU_jiesuan, OnMENUjiesuan)
	ON_COMMAND(IDB_rishouru, OnBUTTONrishouru)
	ON_COMMAND(ID_MENU_yuangong, OnMENUyuangong)
	ON_COMMAND(IDB_reg, OnBUTTONzhuce)
	ON_COMMAND(ID_MENU_about, OnMENUabout)
	ON_COMMAND(ID_MENU_SPinfo, OnMENUSPinfo)
	ON_COMMAND(ID_MENU_jinhuo, OnMENUjinhuo)
	ON_COMMAND(ID_MENU_CP, OnMenuCp)
	ON_COMMAND(ID_MENU_rishourucx, OnMENUrishourucx)
	ON_COMMAND(ID_MENU_yueshouricx, OnMENUyueshouricx)
	ON_COMMAND(ID_MENU_quanxian, OnMENUquanxian)
	ON_COMMAND(ID_MENU_sqlnew, OnMENUsqlnew)
	ON_COMMAND(ID_MENU_sqlcopy, OnMENUsqlcopy)
	ON_COMMAND(ID_MENU_return, OnMENUreturn)
	ON_COMMAND(ID_MENU_addcai, OnMENUaddcai)
	ON_COMMAND(IDB_login, OnMENUlogin)
	ON_COMMAND(IDB_cancel, OnCancel)
	ON_COMMAND(IDB_add, OnMENUaddcai)
	ON_COMMAND(ID_MENU_jinhuoselect, OnMENUjinhuoselect)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_32798, &CMyDlg::OnEmployeeWorking)
END_MESSAGE_MAP()


BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SkinH_Attach();
	// Add "About..." menu item to system menu.
	 
	// IDM_ABOUTBOX must be in the system command range.

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME)),TRUE);

	CTime Time;
	Time = CTime::GetCurrentTime();
	CString Str = Time.Format("%Y-%m-%d");
	m_Imagelist.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_login));
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_open));
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_add));
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_pay));	
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_rishouru));
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_reg));
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON_cancel));
	UINT Array[7];
	for(int i=0;i<7;i++)
	{
		Array[i]=9000+i;
	}
	m_Toolbar.Create(this);
	m_Toolbar.SetButtons(Array,7);
	m_Toolbar.SetButtonText(0,"系统登录");
	m_Toolbar.SetButtonText(1,"开台");
	m_Toolbar.SetButtonText(2,"加减菜");
	m_Toolbar.SetButtonText(3,"顾客买单");
	m_Toolbar.SetButtonText(4,"本日收入");
	m_Toolbar.SetButtonText(5,"员工注册");
	m_Toolbar.SetButtonText(6,"退出系统");
	m_Toolbar.GetToolBarCtrl().SetButtonWidth(60,120);
	m_Toolbar.GetToolBarCtrl().SetImageList(&m_Imagelist);
	m_Toolbar.SetSizes(CSize(70,60),CSize(28,40));
	
	for(int i=0;i<4;i++)
	{
		Array[i]=10000+1;
	}
	m_Statusbar.Create(this);
	m_Statusbar.SetIndicators(Array,4);
	for(int n=0;n<3;n++)
	{
		m_Statusbar.SetPaneInfo(n,Array[n],0,80);
	}
	m_Statusbar.SetPaneInfo(1,Array[1],0,200);
	m_Statusbar.SetPaneInfo(2,Array[2],0,800);
	m_Statusbar.SetPaneText(2,"当前时间"+Str);
	m_Statusbar.SetPaneText(0,"餐饮管理系统");
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

	m_Toolbar.GetToolBarCtrl().EnableButton(IDB_kaitai,false);
	m_Toolbar.GetToolBarCtrl().EnableButton(IDB_pay,false);
	m_Toolbar.GetToolBarCtrl().EnableButton(IDB_rishouru,false);
	m_Toolbar.GetToolBarCtrl().EnableButton(IDB_reg,false);
	m_Toolbar.GetToolBarCtrl().EnableButton(IDB_add,false);

	CMenu* pMenu=GetMenu();
	pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(3)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED);

	CString Sql;
	Sql="select * from shouru where 时间='"+Str+"'";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)Sql,NULL,adCmdText);
	if(m_pRs->adoEOF)
	{
		theApp.m_pCon->Execute((_bstr_t)("insert into shouru(时间)values('"+Str+"')"),NULL,adCmdText);
	}	

	CString sql_TableUse_MAX = "select * from TableUSE";
	int Table_Number = 0;
	int Table_Using_int = 0;
	int Table_Unusing_int = 0;
	CString Table_Using_string = _T("");
	CString Table_Unusing_string = _T("");

	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql_TableUse_MAX,NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{
		Table_Number++;
		m_pRs->MoveNext();
	}

	CString sql_TableUse_count = "select * from TableUSE where TableUSEID = 1";
	m_pRs=theApp.m_pCon->Execute((_bstr_t)sql_TableUse_count,NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{
		Table_Using_int++;
		m_pRs->MoveNext();
	}
	Table_Unusing_int = Table_Number - Table_Using_int;

	Table_Using_string.Format("%d",Table_Using_int);
	Table_Unusing_string.Format("%d",Table_Unusing_int);
	SetDlgItemText(IDC_TABLE_USE,Table_Using_string);
	SetDlgItemText(IDC_TABLE_UNUSE,Table_Unusing_string);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.

HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnMENUlogin() 
{
	
	CLogindlg Logindlg;	
	if(Logindlg.DoModal()==IDOK)
	{		
		CString Sql="select * from login where Uname='"+theApp.name+"'";
		m_pRs=theApp.m_pCon->Execute((_bstr_t)Sql,NULL,adCmdText);
		CString Str=(char*)(_bstr_t)m_pRs->GetCollect("power");
		int radio=atoi(Str);
		if(radio==0)
		{
			CMenu* pMenu=GetMenu();
			pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(3)->EnableMenuItem(2,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(2,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(3,MF_BYPOSITION | MF_ENABLED );
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_kaitai,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_pay,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_rishouru,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_reg,true);	
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_add,true);
		}
		if(radio==1)
		{
			CMenu* pMenu=GetMenu();
			pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(3,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED );
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_kaitai,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_pay,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_rishouru,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_reg,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_add,true);
		}
		if(radio==2)
		{
			CMenu* pMenu=GetMenu();
			pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED );
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_kaitai,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_pay,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_rishouru,true);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_reg,false);
			m_Toolbar.GetToolBarCtrl().EnableButton(IDB_add,true);
		}
		m_Statusbar.SetPaneText(1,"当前用户:"+theApp.name);
		SetWindowText("餐饮管理系统      当前登录用户:"+theApp.name);
	}	
	if(Logindlg.i==3)
		CDialog::OnCancel();
}

void CMyDlg::OnMENUkaitai() 
{
	CKaitaidlg kaitaidlg;
	kaitaidlg.DoModal();
}

void CMyDlg::OnMENUjiezhang() 
{
	CJiezhangdlg jiezhangdlg;
	jiezhangdlg.DoModal();
}

void CMyDlg::OnBUTTONkaitai() 
{
	CKaitaidlg kaitaidlg;
	kaitaidlg.DoModal();
}

void CMyDlg::OnBUTTONjiezhang() 
{
	CJiezhangdlg jiezhangdlg;
	jiezhangdlg.DoModal();
}

void CMyDlg::OnMENUjiesuan() 
{
	CTime Time;
	Time=CTime::GetCurrentTime();
	CString Str=Time.Format("%Y-%m-%d");
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from shouru where 时间='"+Str+"'"),NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{
		CString Value=(char*)(_bstr_t)m_pRs->GetCollect("日收入");		
		MessageBox("本日营业额为："+Value+"元","日收入");
		return;
	}
}

void CMyDlg::OnBUTTONrishouru() 
{
	CTime Time;
	Time=CTime::GetCurrentTime();
	CString Str=Time.Format("%Y-%m-%d");
	m_pRs=theApp.m_pCon->Execute((_bstr_t)("select * from shouru where 时间='"+Str+"'"),NULL,adCmdText);
	while(!m_pRs->adoEOF)
	{
		CString Value=(char*)(_bstr_t)m_pRs->GetCollect("日收入");		
		MessageBox("本日营业额为："+Value+"元","日收入");
		return;
	}
}

void CMyDlg::OnMENUyuangong() 
{
	CZhucedlg zhucedlg;
	zhucedlg.DoModal();
}

void CMyDlg::OnBUTTONzhuce() 
{
	CZhucedlg zhucedlg;
	zhucedlg.DoModal();
}

void CMyDlg::OnMENUabout() 
{
	CAboutDlg aboudlg;
	aboudlg.DoModal();
}

void CMyDlg::OnOK()
{
}

void CMyDlg::OnMENUSPinfo() 
{
	CSpInfo spinfodlg;
	spinfodlg.DoModal();
}

void CMyDlg::OnMENUjinhuo() 
{
	CJinhuodlg jinhuodlg;
	jinhuodlg.DoModal();
}

void CMyDlg::OnMenuCp() 
{
	CCPdlg cp;
	cp.DoModal();
}

void CMyDlg::OnMENUrishourucx() 
{
	CRcxdlg dlg;
	dlg.DoModal();
}

void CMyDlg::OnMENUyueshouricx() 
{
	CYcxdlg dlg;
	dlg.DoModal();
}

void CMyDlg::OnMENUquanxian() 
{
	CQuanxiandlg dlg;
	dlg.DoModal();
}

void CMyDlg::OnMENUsqlnew() 
{
	if(MessageBox("确定要初始化数据库吗?","提示",MB_YESNO)==IDYES)
	{
		CString Sql1="delete from caishiinfo";
		CString Sql2="delete from jinhuoinfo";
		CString Sql3="delete from shangpininfo";
		CString Sql4="delete from shouru";
		CString Sql5="delete from paybill";
		theApp.m_pCon->Execute((_bstr_t)Sql1,NULL,adCmdText);
		theApp.m_pCon->Execute((_bstr_t)Sql2,NULL,adCmdText);
		theApp.m_pCon->Execute((_bstr_t)Sql3,NULL,adCmdText);
		theApp.m_pCon->Execute((_bstr_t)Sql4,NULL,adCmdText);
		theApp.m_pCon->Execute((_bstr_t)Sql5,NULL,adCmdText);
		AfxMessageBox("初始化成功");
		return;
	}
	else
		return;
		
}

void CMyDlg::OnMENUsqlcopy() 
{
	CCopydlg dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUreturn() 
{
	CReturndlg dlg;
	dlg.DoModal();	
}

void CMyDlg::OnCancel()
{
	CDialog::OnCancel();
}

void CMyDlg::OnMENUaddcai() 
{
	CJiacaidlg dlg;
	dlg.DoModal();
}

void CMyDlg::OnMENUjinhuoselect() 
{
	CJinhuoselect dlg;
	dlg.DoModal();
}

void CMyDlg::OnEmployeeWorking()
{
	// TODO: 在此添加命令处理程序代码
	CEmployeeWork dlg;
	dlg.DoModal();
}
