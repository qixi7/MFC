// SelectPerson.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_学生信息管理系统.h"
#include "SelectPerson.h"
#include "afxdialogex.h"
#include "ADO.h"
#include "MFC_MainDlg.h"

// CSelectPerson 对话框

IMPLEMENT_DYNAMIC(CSelectPerson, CDialogEx)

CSelectPerson::CSelectPerson(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectPerson::IDD, pParent)
{                                                         
	
}

CSelectPerson::~CSelectPerson()
{
}

void CSelectPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BOY, Boy_Select);
	DDX_Control(pDX, IDC_GIRL, Girl_Select);
}


BEGIN_MESSAGE_MAP(CSelectPerson, CDialogEx)
	ON_BN_CLICKED(IDC_SELECT_OK, &CSelectPerson::OnClickedSelectOk)
END_MESSAGE_MAP()


// CSelectPerson 消息处理程序


void CSelectPerson::OnClickedSelectOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CMFC_MainDlg *p = (CMFC_MainDlg*)AfxGetApp()->m_pMainWnd;    //获取主窗口应用实例
	CString sql_DDL;  
	GetDlgItemText(IDC_SELECT_NAME,Select_Name);                 //获得输入的名字文本
	GetDlgItemText(IDC_SELECT_TEL,Select_Tel);					 //获得输入的电话文本
	GetDlgItemText(IDC_SELECT_EMAIL,Select_Email);				 //获得输入的邮箱文本
	if (Boy_Select.GetCheck() == 1)								 //若选中性别为男
	{
		Select_Sex = "男";
	}
	if (Girl_Select.GetCheck() == 1)							 //若选中性别为女
	{
		Select_Sex = "女";
	}
	if (Select_Name.IsEmpty() && Select_Sex.IsEmpty() && Select_Tel.IsEmpty() && Select_Email.IsEmpty()) //判断是否什么都没有输入
	{
		MessageBox(_T("什么都没输入诶."),_T("查询好友"),MB_OK|MB_ICONERROR);
		return;
	}
	ADO sql;
	sql.OnInitADOConn();		//初始化数据库连接
	sql.initRecordset();		//创建记录集实例
	sql_DDL.Format(_T("select * from PersonInfo where 姓名 like '%%%s%%' and 性别 like'%%%s%%'\
					                              and 电话 like'%%%s%%' and 邮箱 like'%%%s%%'"),\
		                                          Select_Name,Select_Sex,Select_Tel,Select_Email);   //模糊查询sql语句
	try
	{
		sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),\
			                                adOpenDynamic,adLockOptimistic,adCmdText); //打开查找结果记录集
		p->m_ListCtrl.DeleteAllItems();                                                //清空详细信息列表(ListControl)
		while (!sql.m_pReset->adoEOF)											//若记录集指针不超出末尾则执行循环
		{
			p->m_ListCtrl.InsertItem(0,_T(""));                                                      //插入行
			p->m_ListCtrl.SetItemText(0,0,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("ID"));       //设置ID列信息
			p->m_ListCtrl.SetItemText(0,1,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("姓名"));	 //设置姓名列信息
			p->m_ListCtrl.SetItemText(0,2,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("性别"));	 //设置性别列信息
			p->m_ListCtrl.SetItemText(0,3,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("电话"));	 //设置电话列信息
			p->m_ListCtrl.SetItemText(0,4,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("邮箱"));	 //设置邮箱列信息
			p->m_ListCtrl.SetItemText(0,5,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("所在分组")); //设置所在分组列信息
			sql.m_pReset->MoveNext();															 //记录集后移
		}
		sql.CloseConn();		       //关闭数据库连接
		CSelectPerson::OnCancel();     //默认按下取消按钮，用以关闭对话框
		CString tempstr;
		p->GetDlgItemText(IDC_MOREINFO,tempstr);  //获取当前相信信息按钮文本用以判断是否被点击过
		if (tempstr == "详细信息 >>")             //判断是否有点击详细信息按钮
		{ 
			p->OnClickedMoreinfo();               //若没有按下详细信息按钮,默认按下.没有这个怎么看结果啊朋友0-0..
		}
	}
	catch(...)
	{
		MessageBox(_T("查找好友出错啦!(＞﹏＜) "),_T("查找好友"),MB_OK|MB_ICONERROR);
		return;
	}


}
