// ShowInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "大学生活指南.h"
#include "ShowInfo.h"
#include "afxdialogex.h"
#include "ADO.h"
#include "MyFriend.h"

// CShowInfo 对话框

IMPLEMENT_DYNAMIC(CShowInfo, CDialogEx)

CShowInfo::CShowInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowInfo::IDD, pParent)
{

}

CShowInfo::~CShowInfo()
{
}

void CShowInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShowInfo, CDialogEx)
	ON_BN_CLICKED(IDC_OK, &CShowInfo::OnClickedOk)
END_MESSAGE_MAP()


// CShowInfo 消息处理程序


BOOL CShowInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CMyFriend *p = (CMyFriend*)this->GetParent();
	CString Target_Person = p->m_Tree.GetItemText(p->m_Tree.GetSelectedItem()); //获取选中好友的文本(姓名)
	try
	{
		ADO sql;
		sql.OnInitADOConn();         //初始化数据库连接
		sql.initRecordset();		 //创建数据集实例
		CString sql_DDL;
		sql_DDL.Format(_T("select * from PersonInfo where 姓名='%s'"),Target_Person);  //查询选中的好友信息
		sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),\
			              adOpenDynamic,adLockOptimistic,adCmdText); //打开所得记录集
		Show_Name = (char*)(_bstr_t)sql.m_pReset->GetCollect("姓名");       //得到姓名信息
		Show_Sex = (char*)(_bstr_t)sql.m_pReset->GetCollect("性别");		//得到性别信息
		Show_Tel = (char*)(_bstr_t)sql.m_pReset->GetCollect("电话");		//得到电话信息
		Show_Email = (char*)(_bstr_t)sql.m_pReset->GetCollect("邮箱");		//得到邮箱信息
		SetDlgItemText(IDC_SHOW_NAME,Show_Name);        //设置显示姓名
		SetDlgItemText(IDC_SHOW_SEX,Show_Sex);			//设置显示性别
		SetDlgItemText(IDC_SHOW_TEL,Show_Tel);			//设置显示电话
		SetDlgItemText(IDC_SHOW_EMAIL,Show_Email);		//设置显示邮箱
		sql.CloseConn();		    //关闭数据库连接
	}
	catch(...)
	{
		MessageBox(_T("双击显示好友信息时出错啦.⊙﹏⊙ "),_T("显示好友信息"),MB_OK|MB_ICONERROR);
		return FALSE;
	}


	return TRUE;
}


void CShowInfo::OnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CShowInfo::OnCancel();
}
