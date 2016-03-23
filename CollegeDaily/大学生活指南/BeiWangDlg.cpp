// BeiWangDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "大学生活指南.h"
#include "BeiWangDlg.h"
#include "afxdialogex.h"
#include "ADO.h"

// CBeiWangDlg 对话框

IMPLEMENT_DYNAMIC(CBeiWangDlg, CDialogEx)

CBeiWangDlg::CBeiWangDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBeiWangDlg::IDD, pParent)
{

}

CBeiWangDlg::~CBeiWangDlg()
{
}

void CBeiWangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_BEIWANG, m_beiwangTree);
}


BEGIN_MESSAGE_MAP(CBeiWangDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SAVE, &CBeiWangDlg::OnClickedSave)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_BEIWANG, &CBeiWangDlg::OnDblclkTreeBeiwang)
	ON_BN_CLICKED(IDC_REMOVE, &CBeiWangDlg::OnClickedRemove)
	ON_BN_CLICKED(IDC_CLEAR, &CBeiWangDlg::OnClickedClear)
END_MESSAGE_MAP()


// CBeiWangDlg 消息处理程序


BOOL CBeiWangDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ADO sql;
	_bstr_t sql_DDL_GroupList = "select * from BeiWang order by ID";     //sql语句
	sql.OnInitADOConn();                                                 //初始化数据库连接
	sql.initRecordset();                                                 //创建记录集实例
	sql.m_pReset->Open(sql_DDL_GroupList,sql.m_pConn.GetInterfacePtr(),    \
		adOpenDynamic,adLockOptimistic,adCmdText);
	CString temp;
	while (!sql.m_pReset->adoEOF)                                         //若记录集指针不超出末尾则执行循环
	{   
		temp = (char*)(_bstr_t)sql.m_pReset->GetCollect("备忘录名");
		m_beiwangTree.InsertItem(temp);
		sql.m_pReset->MoveNext();                                     //记录集后移一位
	}
	sql.CloseConn();
	return TRUE;
}

void CBeiWangDlg::OnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码

	GetDlgItemText(IDC_EDIT_TEXT,m_beiwang);
	GetDlgItemText(IDC_EDIT_BEIWANGNAME,title);
	ADO sql;
	sql.OnInitADOConn();												   //初始化数据库连接	
	sql.initRecordset();												   //创建记录集实例
	_bstr_t sql_DDL_GroupList = "select * from BeiWang";				   //sql语句
	sql.m_pReset->Open(sql_DDL_GroupList,sql.m_pConn.GetInterfacePtr(), \
		adOpenDynamic,adLockOptimistic,adCmdText);   
	try
	{
		sql.m_pReset->AddNew();														 //添加新行
		sql.m_pReset->PutCollect("备忘录名",(char*)(_bstr_t)title);           //将获得的文本插入数据库
		sql.m_pReset->PutCollect("备忘录",(char*)(_bstr_t)m_beiwang);
		m_beiwangTree.InsertItem(title);                                 
		sql.m_pReset->Update();														 //更新数据库
		sql.CloseConn();															 //关闭数据库连接
		SetDlgItemText(IDC_EDIT_BEIWANGNAME,_T(""));
		SetDlgItemText(IDC_EDIT_TEXT,_T(""));
	}
	catch(...)
	{
		MessageBox(_T("添加备忘录出错啦！(＞﹏＜) "));
		return;
	}
}

void CBeiWangDlg::OnDblclkTreeBeiwang(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
 	CString temp_title;
	temp_title = m_beiwangTree.GetItemText(m_beiwangTree.GetSelectedItem());
	ADO sql;
	CString sql_DDL;
	sql_DDL.Format(_T("select * from BeiWang where 备忘录名 = '%s'"),temp_title);  //sql语句
	sql.OnInitADOConn();                                                 //初始化数据库连接
	sql.initRecordset();                                                 //创建记录集实例
	sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),    \
		adOpenDynamic,adLockOptimistic,adCmdText);
	SetDlgItemText(IDC_EDIT_BEIWANGNAME,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("备忘录名"));
	SetDlgItemText(IDC_EDIT_TEXT,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("备忘录"));
	sql.CloseConn();
}

void CBeiWangDlg::OnClickedRemove()
{
	// TODO: 在此添加控件通知处理程序代码
	CString Select_name = m_beiwangTree.GetItemText(m_beiwangTree.GetSelectedItem());
	ADO sql;
	sql.OnInitADOConn();                                                             
	sql.initRecordset();
	CString sql_DDL;
	sql_DDL.Format(_T("delete from BeiWang where 备忘录名 = '%s'"),Select_name);
	sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),
		adOpenDynamic,adLockOptimistic,adCmdText);
	sql.CloseConn();
	m_beiwangTree.DeleteAllItems();
	SetDlgItemText(IDC_EDIT_BEIWANGNAME,_T(""));
	SetDlgItemText(IDC_EDIT_TEXT,_T(""));
	this->OnInitDialog();
}

void CBeiWangDlg::OnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_TEXT,_T(""));
	SetDlgItemText(IDC_EDIT_BEIWANGNAME,_T(""));
}
