// AlterPerson.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_学生信息管理系统.h"
#include "AlterPerson.h"
#include "afxdialogex.h"
#include "ADO.h"
#include "MFC_MainDlg.h"
// CAlterPerson 对话框

IMPLEMENT_DYNAMIC(CAlterPerson, CDialogEx)

CAlterPerson::CAlterPerson(CWnd* pParent/* =NULL */)
	: CDialogEx(CAlterPerson::IDD, pParent)
{
	
}

CAlterPerson::~CAlterPerson()
{
}

void CAlterPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ALTER_BOY, Boy_Selected);
	//  DDX_Control(pDX, IDCANCEL, Girl_Selected);
	DDX_Control(pDX, IDC_ALTER_NAME, CEdit_Name);
	DDX_Control(pDX, IDC_ALTER_TEL, CEdit_Tel);
	DDX_Control(pDX, IDC_ALTER_EMAIL, CEdit_Email);
	DDX_Control(pDX, IDC_ALTER_GIRL, Girl_Selected);
}


BEGIN_MESSAGE_MAP(CAlterPerson, CDialogEx)
	ON_BN_CLICKED(IDC_ENSURE_ALTER, &CAlterPerson::OnClickedEnsureAlter)
END_MESSAGE_MAP()


// CAlterPerson 消息处理程序

BOOL CAlterPerson::OnInitDialog()         //重写初始化对话框虚函数  目的在于初始化时就显示原本的信息
{
	CDialogEx::OnInitDialog();

	CMFC_MainDlg *p = (CMFC_MainDlg*)AfxGetApp()->m_pMainWnd;                                 //获得主窗口应用实例
	CString TargetName = p->m_TreeControl.GetItemText(p->m_TreeControl.GetSelectedItem());    //保存选中好友的文本信息(姓名)
	CString sql_DDL;
	sql_DDL.Format(_T("select * from PersonInfo Where 姓名='%s'"),TargetName);				  //sql语句，查询选中的好友信息
	try
	{
		ADO sql;
		sql.OnInitADOConn();													        //初始化数据库连接
		sql.initRecordset();															//创建记录集实例
		sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),
			                                adOpenDynamic,adLockOptimistic,adCmdText);	//打开所得记录集
		Alter_Name = sql.m_pReset->GetCollect("姓名");									//得到好友姓名
		Alter_Sex = sql.m_pReset->GetCollect("性别");									//得到好友性别
		Alter_Tel = sql.m_pReset->GetCollect("电话");									//得到好友电话
		Alter_Email = sql.m_pReset->GetCollect("邮箱");									//得到好友邮箱
		sql.CloseConn();																//关闭数据库连接
	}
	catch(...)
	{
		MessageBox(_T("初始化修改对话框时出错啦，(＞﹏＜) "),_T("初始化修改对话框"),MB_OK|MB_ICONERROR);
		return FALSE;
	}
	CEdit_Name.SetWindowText(Alter_Name);		//在EditControl上显示姓名
	CEdit_Tel.SetWindowText(Alter_Tel);		//在EditControl上显示电话
	CEdit_Email.SetWindowText(Alter_Email);	//在EditControl上显示邮箱
	if (Alter_Sex == "男")						//性别为男
	{
		Boy_Selected.SetCheck(BST_CHECKED);		//设置RadioButton男为选中
	}
	if (Alter_Sex == "女")						//性别为女
	{
		Girl_Selected.SetCheck(BST_CHECKED);    //设置RadioButton女为选中
	}
	return TRUE;
}

void CAlterPerson::OnClickedEnsureAlter()                 //修改功能实现函数
{
	// TODO: 在此添加控件通知处理程序代码
	CMFC_MainDlg *p = (CMFC_MainDlg*)AfxGetApp()->m_pMainWnd;			//获取主窗口应用实例
	CString TargetName = p->m_TreeControl.GetItemText(p->m_TreeControl.GetSelectedItem());  //用于保存选中的好友名
	GetDlgItemText(IDC_ALTER_NAME,Alter_Name);		  //得到输入的姓名文本
	GetDlgItemText(IDC_ALTER_TEL,Alter_Tel);		  //得到输入的电话文本
	GetDlgItemText(IDC_ALTER_EMAIL,Alter_Email);      //得到输入的邮箱文本
	if (Alter_Name.IsEmpty())                         //处于后续性能考虑,姓名不能为空,若为空则终止修改,
	{
		MessageBox(_T("出于后续性能的考虑,姓名不能为空哟~(╯3╰) "),_T("修改好友信息"),MB_OK|MB_ICONERROR);
		return;
	}
	if (Alter_Tel.IsEmpty())                          //若电话为空则设为"未知"
	{
		Alter_Tel = "未知";
	}
	if (Alter_Email.IsEmpty())                        //若邮箱为空则设为"未知"
	{
		Alter_Email = "未知";
	}
	if (Boy_Selected.GetCheck() == 1)                //若选中"男"
	{
		Alter_Sex = "男";
	}
	if (Girl_Selected.GetCheck() == 1)               //若选中"女"
	{
		Alter_Sex = "女";
	}
	try
	{
		ADO sql;
		sql.OnInitADOConn();		//初始化数据库连接
		sql.initRecordset();		//创建记录集实例
		CString sql_DDL_ensure;
		sql_DDL_ensure.Format(_T("select * from PersonInfo where 姓名='%s'"),Alter_Name);//验证sql语句,如果修改后有重名情况则终止修改
		sql.m_pReset->Open((_bstr_t)sql_DDL_ensure,sql.m_pConn.GetInterfacePtr(),\
			                          adOpenStatic,adLockOptimistic,adCmdText);//打开验证sql语句找到的记录集,注意这里是静态打开,
		                                                                       //见第三个参数如果ado组件在客户端使用的前向只读游标，
		                                                                       //就无法返回结果集的条数，只能返回－1
		if (sql.m_pReset->GetRecordCount() != 0)							   //判断sql语句所得记录集是否有记录
		{
			MessageBox(_T("该姓名已存在,为它加上编号会是不错的选择O(∩_∩)O"),_T("修改好友信息"),MB_OK|MB_ICONERROR);
			sql.CloseConn();
			return;
		}
		else
		{
			sql.CloseRecordset();                                                         //关闭验证记录集 
			CString sql_DDL;
			sql_DDL.Format(_T("update PersonInfo set 姓名='%s',性别='%s',电话='%s',邮箱='%s' where 姓名='%s'"),\
													 Alter_Name,Alter_Sex,Alter_Tel,Alter_Email,TargetName);    //修改信息的 sql语句
			sql.m_pReset->Open((_bstr_t)sql_DDL,sql.m_pConn.GetInterfacePtr(),\
												adOpenDynamic,adLockOptimistic,adCmdText);           //执行sql语句
			sql.CloseConn();       //关闭数据库连接
			p->RefreshData();	   //刷新总数据
		}

	}
	catch(...)
	{
		MessageBox(_T("修改好友信息出错啦~(＞﹏＜) "),_T("修改好友信息"),MB_OK|MB_ICONERROR);
		return;
	}
	CAlterPerson::OnCancel();                                       //默认按下取消按钮用以关闭对话框
}