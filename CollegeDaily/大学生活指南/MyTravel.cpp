// MyTravel.cpp : 实现文件
//

#include "stdafx.h"
#include "大学生活指南.h"
#include "MyTravel.h"
#include "afxdialogex.h"
#include "ADO.h"

// CMyTravel 对话框

IMPLEMENT_DYNAMIC(CMyTravel, CDialogEx)

CMyTravel::CMyTravel(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyTravel::IDD, pParent)
{

}

CMyTravel::~CMyTravel()
{
}

void CMyTravel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_travelTree);
}


BEGIN_MESSAGE_MAP(CMyTravel, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, &CMyTravel::OnDblclkTree)
END_MESSAGE_MAP()


// CMyTravel 消息处理程序


BOOL CMyTravel::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString quxian_name;
	CString scenic_name;
	int count = 0;

	ADO sql;
	_bstr_t sql_DDL_GroupList = "select * from 所在区县 order by ID";        //sql语句
	sql.OnInitADOConn();                                                 //初始化数据库连接
	sql.initRecordset();                                                 //创建记录集实例
	sql.m_pReset->Open(sql_DDL_GroupList,sql.m_pConn.GetInterfacePtr(),    \
		adOpenDynamic,adLockOptimistic,adCmdText);
	while (!sql.m_pReset->adoEOF)                                         //若记录集指针不超出末尾则执行循环
	{                                                                     //此主要先插入所有分组	
	    quxian_name = (LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("区县名");
		temp_quxian[count] = m_travelTree.InsertItem(quxian_name); 
		count++;
		sql.m_pReset->MoveNext();                                         //记录集后移一位
	}
	sql.CloseRecordset();                                                 //关闭记录集                   
	_bstr_t sql_DDL_PersonInfo = "select * from 景点 order by ID";  //SQL语句
	sql.m_pReset->Open(sql_DDL_PersonInfo,sql.m_pConn.GetInterfacePtr(),   \
		adOpenDynamic,adLockOptimistic,adCmdText);
	while (!sql.m_pReset->adoEOF)                                         //记录集指针不超出末尾时执行循环
	{
		quxian_name = (char*)(_bstr_t)sql.m_pReset->GetCollect("区县名");
	    scenic_name = (char*)(_bstr_t)sql.m_pReset->GetCollect("景点名"); 
		for (int i = 0; i < count; ++i)                                  //循环分组个数次
		{
			if (m_travelTree.GetItemText(temp_quxian[i]) == quxian_name) 
			{
				m_travelTree.InsertItem(scenic_name,temp_quxian[i]);                     
				break;                                //出于性能考虑一定要break一下，不然还会继续循环
			}
		}
		sql.m_pReset->MoveNext();                                       //记录后移
	}
	sql.CloseConn();   //断开数据库连接
	return TRUE;
}

void CMyTravel::OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM CurrentFocus = m_travelTree.GetSelectedItem();
	if (!m_travelTree.ItemHasChildren(CurrentFocus) && \
		!m_travelTree.GetItemText(m_travelTree.GetParentItem(CurrentFocus)).IsEmpty())  
	{
		CString senic_name = m_travelTree.GetItemText(CurrentFocus);
		CString ticket;
		CString transport;
		CString info;
		ADO sql;
		sql.OnInitADOConn();
		sql.initRecordset();
		CString sql_DDL;
		sql_DDL.Format(_T("select * from 景点 where 景点名 = '%s'"),senic_name);
		sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),\
			                    adOpenDynamic,adLockOptimistic,adCmdText); 
		ticket = (char*)(_bstr_t)sql.m_pReset->GetCollect("门票信息");
		transport = (char*)(_bstr_t)sql.m_pReset->GetCollect("交通路线");
		info = (char*)(_bstr_t)sql.m_pReset->GetCollect("景点介绍");
		sql.CloseConn();
		SetDlgItemText(IDC_READ_TICKET,ticket);
		SetDlgItemText(IDC_READ_TRANS,transport);
		SetDlgItemText(IDC_READ_INFO,info);
	}
}
