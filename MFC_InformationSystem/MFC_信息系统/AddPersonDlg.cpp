// AddPersonDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_学生信息管理系统.h"
#include "AddPersonDlg.h"
#include "afxdialogex.h"
#include "MFC_MainDlg.h"
#include "AddGroup.h"
#include "ADO.h"
// CAddPersonDlg 对话框

IMPLEMENT_DYNAMIC(CAddPersonDlg, CDialogEx)

CAddPersonDlg::CAddPersonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddPersonDlg::IDD, pParent)
{

}

CAddPersonDlg::~CAddPersonDlg()
{
}

void CAddPersonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BOY, Boy_ADD);
	DDX_Control(pDX, IDC_GIRL, Girl_ADD);
}


BEGIN_MESSAGE_MAP(CAddPersonDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADD_OK, &CAddPersonDlg::OnClickedAddOk)
END_MESSAGE_MAP()


// CAddPersonDlg 消息处理程序


void CAddPersonDlg::OnClickedAddOk()
{
	// TODO: 在此添加控件通知处理程序代码
	PersonInfo m_person;                                                    //创建一个PersonInfo对象
	CMFC_MainDlg *p = (CMFC_MainDlg*)AfxGetApp()->m_pMainWnd;               //获取主对话框的实例句柄
	GetDlgItemText(IDC_ADD_NAME,p->str_Name);                               //给好友列表控件(TreeControl)指针获取TextBox编辑的姓名Name
	GetDlgItemText(IDC_ADD_NAME,m_person.per_Name);                         //给详细信息控件(ListControl)指针获取TextBox编辑的姓名Name
	GetDlgItemText(IDC_ADD_TEL,m_person.per_Tel);                           //获取TextBox编辑的电话Tel
	GetDlgItemText(IDC_ADD_EMAIL,m_person.per_Email);                       //获取TextBox编辑的邮箱Email
	if (m_person.per_Name.IsEmpty())
	{
		MessageBox(_T("名字不能为空哟~"),_T("添加好友出错啦"),MB_OK|MB_ICONERROR);
		return;
	}
	if (m_person.per_Tel.IsEmpty())
	{
		m_person.per_Tel = _T("未知");
	}
	if (m_person.per_Email.IsEmpty())
	{
		m_person.per_Email = _T("未知");
	}
	if (Boy_ADD.GetCheck() == 1)			//判断是否选中男
	{
		m_person.per_Sex = "男";
	}
	if (Girl_ADD.GetCheck() == 1)			//判断是否选中女
	{
		m_person.per_Sex = "女";
	}
	if (p->m_TreeControl.GetSelectedItem() == NULL)                  //判断选中的哪个分组
	{
		p->m_CurrentFocus = p->m_DefalutFocus;                       //若都没有选择则向"我的好友"列表里插入
		m_person.per_Group = p->m_TreeControl.GetItemText(p->m_CurrentFocus);                     
	}
	else
	{
		m_person.per_Group = p->m_TreeControl.GetItemText(p->m_CurrentFocus);   //获取被选中的分组的组名
	}

	try           //不能重名的检测
	{
		ADO sql;
		sql.OnInitADOConn();
		sql.initRecordset();
		CString sql_DDL_ensure;
		sql_DDL_ensure.Format(_T("select * from PersonInfo where 姓名='%s'"),m_person.per_Name);//验证sql语句,如果修改后有重名情况则终止修改
		sql.m_pReset->Open((_bstr_t)sql_DDL_ensure,sql.m_pConn.GetInterfacePtr(),\
			adOpenStatic,adLockOptimistic,adCmdText);//打开验证sql语句找到的记录集,注意这里是静态打开,
		                                             //见第三个参数如果ado组件在客户端使用的前向只读游标，
		                                             //就无法返回结果集的条数，只能返回－1
		if (sql.m_pReset->GetRecordCount() != 0)	//判断sql语句所得记录集是否有记录
		{
			MessageBox(_T("该姓名已存在,为它加上后缀会是不错的选择哟O(∩_∩)O"),_T("修改好友信息"),
				                                                               MB_OK|MB_ICONERROR);
			sql.CloseConn();
			return;
		}
	}
	catch(...)
	{
		MessageBox(_T("你所添加的人已经存在啦~(＞﹏＜),为TA添加点后缀区分吧~"),_T("添加好友"),
			                                                              MB_OK|MB_ICONERROR);
		return;
	}

	p->m_TreeControl.InsertItem(p->str_Name,p->m_CurrentFocus);      //向好友列表选中的分组里插入好友姓名

	try
	{	
		ADO sql2;
	    sql2.OnInitADOConn();               //初始化数据库连接
		sql2.initRecordset();               //创建记录集实例
		_bstr_t sql_DDL = "select * from PersonInfo";							//sql语句
		sql2.m_pReset->Open(sql_DDL,sql2.m_pConn.GetInterfacePtr(),\
			                adOpenDynamic,adLockOptimistic,adCmdText);     //打开PersonInfo数据集
		sql2.m_pReset->AddNew();                                           //数据库添加行
		sql2.m_pReset->PutCollect("姓名",(_bstr_t)m_person.per_Name);      //向姓名列中插入姓名
		sql2.m_pReset->PutCollect("性别",(_bstr_t)m_person.per_Sex);       //向性别列中插入性别
		sql2.m_pReset->PutCollect("电话",(_bstr_t)m_person.per_Tel);       //向电话列中年插入电话
		sql2.m_pReset->PutCollect("邮箱",(_bstr_t)m_person.per_Email);     //向邮箱列中插入邮箱
		sql2.m_pReset->PutCollect("所在分组",(_bstr_t)m_person.per_Group); //向所在分组列中插入所在分组
		sql2.m_pReset->Update();                                           //更新数据表
		sql2.CloseConn();												  //关闭连接
	}
	catch(...)
	{
		MessageBox(_T("添加出错啦!(＞﹏＜)"));
		return;
	}
	p->m_ListCtrl.DeleteAllItems();                                  //删掉在CListControl加入的所有项再重新更新,为了防止多出一项
	p->ShowAllPerson();                                              //再显示
	CAddPersonDlg::OnCancel();                                       //默认按下取消按钮用以关闭对话框
}