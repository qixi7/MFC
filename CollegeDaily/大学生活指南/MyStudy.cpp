// MyStudy.cpp : 实现文件
//

#include "stdafx.h"
#include "大学生活指南.h"
#include "MyStudy.h"
#include "afxdialogex.h"
#include "ADO.h"


// CMyStudy 对话框

IMPLEMENT_DYNAMIC(CMyStudy, CDialogEx)

CMyStudy::CMyStudy(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyStudy::IDD, pParent)
{

}

CMyStudy::~CMyStudy()
{
}

void CMyStudy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_studyTree);
}


BEGIN_MESSAGE_MAP(CMyStudy, CDialogEx)
//	ON_BN_CLICKED(IDC_BUTTON1, &CMyStudy::OnBnClickedButton1)
//	ON_EN_CHANGE(IDC_EDIT2, &CMyStudy::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_ADD_STUDY, &CMyStudy::OnClickedAddStudy)
	ON_BN_CLICKED(IDC_REMOVE, &CMyStudy::OnClickedRemove)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, &CMyStudy::OnDblclkTree)
END_MESSAGE_MAP()


// CMyStudy 消息处理程序

void CMyStudy::OnClickedAddStudy()
{
	// TODO: 在此添加控件通知处理程序代码
	CString course_name;
	CString xueyuan_name;
	CString myStudy;
	GetDlgItemText(IDC_EDIT_COURSE,course_name);
	GetDlgItemText(IDC_EDIT_STUDY,myStudy);
	xueyuan_name = m_studyTree.GetItemText(m_studyTree.GetParentItem(m_studyTree.GetSelectedItem()));
	if (myStudy.IsEmpty())
	{
		myStudy = _T("暂无");
	}
	ADO sql;
	sql.OnInitADOConn();
	sql.initRecordset();
	CString sql_DDL;
	sql_DDL.Format(_T("update 重点课程 set 学习计划 = '%s' where 课程名='%s' and 学院名 = '%s'"),\
		                                                       myStudy,course_name,xueyuan_name);
	sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),    \
		                adOpenDynamic,adLockOptimistic,adCmdText);
	sql.CloseConn();
}

void CMyStudy::OnClickedRemove()
{
	// TODO: 在此添加控件通知处理程序代码
	SetDlgItemText(IDC_EDIT_STUDY,_T(""));
}

void CMyStudy::OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	xueyuan = m_studyTree.GetSelectedItem();
	if (!m_studyTree.ItemHasChildren(xueyuan) && \
		!m_studyTree.GetItemText(m_studyTree.GetParentItem(xueyuan)).IsEmpty()) 
	{	
		CString xueyuan_name;
		CString course_name;
		CString myStudy;
		xueyuan_name = m_studyTree.GetItemText(m_studyTree.GetParentItem(xueyuan));
		course_name = m_studyTree.GetItemText(xueyuan);
		SetDlgItemText(IDC_EDIT_COURSE,course_name);
		ADO sql;
		sql.OnInitADOConn();
		sql.initRecordset();
		CString sql_DDL;
		sql_DDL.Format(_T("select 学习计划 from 重点课程 where 课程名 = '%s' and 学院名 = '%s'"),course_name,xueyuan_name);
		sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),   \
			adOpenDynamic,adLockOptimistic,adCmdText);
		myStudy = (char*)(_bstr_t)sql.m_pReset->GetCollect("学习计划");
		sql.CloseConn();
		SetDlgItemText(IDC_EDIT_STUDY,myStudy);
	}
}

BOOL CMyStudy::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString temp_course;
	CString temp_name;
	int count = 0;

	ADO sql;
	_bstr_t sql_DDL_GroupList = "select * from 学院 order by ID";        //sql语句
	sql.OnInitADOConn();                                                 //初始化数据库连接
	sql.initRecordset();                                                 //创建记录集实例
	sql.m_pReset->Open(sql_DDL_GroupList,sql.m_pConn.GetInterfacePtr(),    \
		adOpenDynamic,adLockOptimistic,adCmdText);
	while (!sql.m_pReset->adoEOF)                                         //若记录集指针不超出末尾则执行循环
	{                                                                     //此主要先插入所有分组	
		temp_name = (LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("学院名");
		temp_xuyuan[count] = m_studyTree.InsertItem(temp_name); 
		count++;
		sql.m_pReset->MoveNext();                                         //记录集后移一位
	}
	sql.CloseRecordset();                                                 //关闭记录集                   
	_bstr_t sql_DDL_PersonInfo = "select * from 重点课程 order by ID";  //SQL语句
	sql.m_pReset->Open(sql_DDL_PersonInfo,sql.m_pConn.GetInterfacePtr(),   \
		adOpenDynamic,adLockOptimistic,adCmdText);
	while (!sql.m_pReset->adoEOF)                                         //记录集指针不超出末尾时执行循环
	{                                                                     //此循环向所有分组中插入好友姓名
		temp_course = (char*)(_bstr_t)sql.m_pReset->GetCollect("课程名");      //保存此行的姓名
	    temp_name = (char*)(_bstr_t)sql.m_pReset->GetCollect("学院名"); //保存此好友的所在分组名
		for (int i = 0; i < count; ++i)                                  //循环分组个数次
		{
			if (m_studyTree.GetItemText(temp_xuyuan[i]) == temp_name) //如果好友所在分组名等于循环所得分组名
			{
				m_studyTree.InsertItem(temp_course,temp_xuyuan[i]);                     
				break;                                //出于性能考虑一定要break一下，不然还会继续循环
			}
		}
		sql.m_pReset->MoveNext();                                       //记录后移
	}
	sql.CloseConn();   //断开数据库连接
	return TRUE;
}
