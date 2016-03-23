// MyFriend.cpp : 实现文件
//

#include "stdafx.h"
#include "大学生活指南.h"
#include "MyFriend.h"
#include "afxdialogex.h"
#include "AddPerson.h"
#include "ADO.h"
#include "ReWrite.h"
#include "SelectPerson.h"
#include "AddGroup.h"
#include "ShowInfo.h"
// CMyFriend 对话框

IMPLEMENT_DYNAMIC(CMyFriend, CDialogEx)

CMyFriend::CMyFriend(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyFriend::IDD, pParent)
{

}

CMyFriend::~CMyFriend()
{
}

void CMyFriend::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_Tree);
	//  DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_LIST, m_List);
}


BEGIN_MESSAGE_MAP(CMyFriend, CDialogEx)
	ON_BN_CLICKED(IDC_ADDPERSON, &CMyFriend::OnClickedAddperson)
	ON_BN_CLICKED(IDC_MOREINFO, &CMyFriend::OnClickedMoreinfo)
	ON_BN_CLICKED(IDC_REMOVE, &CMyFriend::OnClickedRemove)
	ON_BN_CLICKED(IDC_REWRITE, &CMyFriend::OnClickedRewrite)
	ON_BN_CLICKED(IDC_SELECT, &CMyFriend::OnClickedSelect)
	ON_BN_CLICKED(IDC_ADDGROUP, &CMyFriend::OnClickedAddgroup)
	ON_BN_CLICKED(IDC_REFRESH, &CMyFriend::OnClickedRefresh)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, &CMyFriend::OnDblclkTree)
END_MESSAGE_MAP()


// CMyFriend 消息处理程序


void CMyFriend::ShowAllPerson()                //显示所有好友的详细信息函数
{  
	ADO sql;  
	sql.OnInitADOConn();                             //初始化数据库链接
	sql.initRecordset();                             //创建记录集对象指针实例  
	_bstr_t sql_DDL = "select * from PersonInfo order by ID desc";           //sql语句
	sql.m_pReset->Open(sql_DDL,sql.m_pConn.GetInterfacePtr(),\
		adOpenDynamic,adLockOptimistic,adCmdText);   //打开记录集
	while (!sql.m_pReset->adoEOF)                                           //记录集不超出末尾时执行循环
	{
		m_List.InsertItem(0,_T(""));                                                      //插入一行
		m_List.SetItemText(0,0,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("姓名"));     //给该行第1列赋值
		m_List.SetItemText(0,1,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("性别"));     //给该行第2列赋值
		m_List.SetItemText(0,2,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("电话"));     //给该行第3列赋值
		m_List.SetItemText(0,3,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("邮箱"));     //给该行第4列赋值
		m_List.SetItemText(0,4,(LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("所在分组")); //给该行第5列赋值
		sql.m_pReset->MoveNext();                                                         //记录集指针后移一位
	}
	sql.CloseConn();                                                                      //关闭数据库连接
}

void CMyFriend::ShowAllPeronTree()                         //显示好友列表函数
{
	GroupNumber = 0;                                          //初始时默认没有组
	ADO sql;
	_bstr_t sql_DDL_GroupList = "select * from GroupList order by ID";   //sql语句
	sql.OnInitADOConn();                                                 //初始化数据库连接
	sql.initRecordset();                                                 //创建记录集实例
	sql.m_pReset->Open(sql_DDL_GroupList,sql.m_pConn.GetInterfacePtr(),    \
		adOpenDynamic,adLockOptimistic,adCmdText);//打开GroupList记录集
	while (!sql.m_pReset->adoEOF)                                         //若记录集指针不超出末尾则执行循环
	{                                                                     //此主要先插入所有分组
		if ((int)sql.m_pReset->GetCollect("ID") <= (MaxGroupNumber + 1))  //判断分组的ID号是否超过了最大容量(50个)AccessID是从1开始的
		{                                                                 //故MaxGroupNumber要加1
			m_Group[GroupNumber] = m_Tree.InsertItem((LPCTSTR)(_bstr_t)sql.m_pReset->GetCollect("分组名")); //向好友列表插入该分组名
			GroupNumber++;                                                //分组数加1
			sql.m_pReset->MoveNext();                                     //记录集后移一位
		}
	}
	m_DefalutFocus = m_Group[0];                                          //第一个分组作为默认选中焦点,
																		  //为了没有选中任何组而添加好友提供默认行为
	sql.CloseRecordset();                                                 //关闭记录集                   

	_bstr_t sql_DDL_PersonInfo = "select * from PersonInfo order by ID";  //SQL语句
	sql.m_pReset->Open(sql_DDL_PersonInfo,sql.m_pConn.GetInterfacePtr(),   \
		adOpenDynamic,adLockOptimistic,adCmdText);//打开GroupList记录集
	while (!sql.m_pReset->adoEOF)                                         //记录集指针不超出末尾时执行循环
	{                                                                     //此循环向所有分组中插入好友姓名
		str_Name = (char*)(_bstr_t)sql.m_pReset->GetCollect("姓名");      //保存此行的姓名
		str_TargetGroup = (char*)(_bstr_t)sql.m_pReset->GetCollect("所在分组"); //保存此好友的所在分组名
		for (int i = 0; i <= GroupNumber; ++i)                                  //循环分组个数次
		{
			if (m_Tree.GetItemText(m_Group[i]) == (CString)str_TargetGroup) //如果好友所在分组名等于循环所得分组名
			{
				m_Tree.InsertItem(str_Name,m_Group[i]);                     //向该组中插入好友姓名
				break;                                                             //出于性能考虑一定要break一下，不然还会继续循环
			}
		}
		sql.m_pReset->MoveNext();                                       //记录后移
	}
	sql.CloseConn();   //断开数据库连接
}

void CMyFriend::RefreshData()                      //刷新总数据实现函数
{
	m_List.DeleteAllItems();                  //删除目前CListControl(详细信息)所有项
	m_Tree.DeleteAllItems();               //删除目前CTreeControl(好友列表)所有项
	ShowAllPerson();                              //重新插入所有好友详细信息
	ShowAllPeronTree();                           //重新插入所有好友列表
} 

void CMyFriend::RemoveGroup(CString str_RemoveGroup)        //删除分组事件响应函数
{
	CString Target;                      //要删除的目标分组名
	ADO sql;     
	sql.OnInitADOConn();                 //初始化数据库连接
	sql.initRecordset();                 //创建数据集实例
	_bstr_t sql_DDL_GroupList = "select * from GroupList";     //sql语句
	sql.m_pReset->Open(sql_DDL_GroupList,sql.m_pConn.GetInterfacePtr(),\
		adOpenDynamic,adLockOptimistic,adCmdText);            //打开GroupList记录集
	try
	{
		while (!sql.m_pReset->adoEOF)     //若不记录集指针不超过末尾则执行循环
		{
			Target = (char*)(_bstr_t)sql.m_pReset->GetCollect("分组名");    //保存该次循环所得的分组名
			if (str_RemoveGroup == (CString)Target)                         //若要删除的分组名等于该循环所得的分组名
			{
				sql.m_pReset->Delete(adAffectCurrent);                      //删除数据库中的该分组名
				sql.m_pReset->Update();                                     //更新数据库
			}   
			sql.m_pReset->MoveNext();                                       //数据集指针后移
		}  
		sql.CloseConn();                                                    //断开数据库连接
	}
	catch(...)
	{
		MessageBox(_T("删除好友分组失败啦！(＞﹏＜)"),_T("删除好友分组"),MB_OK);
		return;
	}
}

void CMyFriend::RemovePerson_CTreeControl(HTREEITEM Remove_CTreeControl)                    //为CTreeControl定制删除函数
{
	ADO sql;
	sql.OnInitADOConn();                      //初始化数据库连接
	sql.initRecordset();                      //创建数据集实例
	_bstr_t sql_DDL_DELETE = "select * from PersonInfo";    //要执行的sql语句
	sql.m_pReset->Open(sql_DDL_DELETE,sql.m_pConn.GetInterfacePtr(), \
		adOpenDynamic,adLockOptimistic,adCmdText);             //打开PersonInfo记录集
	CString Target_Name;                        //存放循环所得好友名
	CString Delete_Name = m_Tree.GetItemText(Remove_CTreeControl);                    //存放选中的将要删除的好友名
	try  
	{
		while (!sql.m_pReset->adoEOF)                                   //若不记录集指针不超出末尾则执行循环
		{  
			Target_Name = (CString)sql.m_pReset->GetCollect("姓名");    //保存循环所得的好友名
			if (Delete_Name == Target_Name)                             //判断循环所得好友名是否和将要删除的好友名相等
			{
				sql.m_pReset->Delete(adAffectCurrent);                  //删除当前项
				sql.m_pReset->Update();                                 //更新数据库
				sql.CloseConn();                                        //关闭连接
				break;                                                  //为了性能,记得break;防止继续循环
			}
			sql.m_pReset->MoveNext();                                   //记录集指针后移一位
		}
		sql.CloseConn();                                                //关闭数据库连接
	}
	catch(...)
	{
		MessageBox(_T("删除单个人出错啦（CTreeControl）！(＞﹏＜)"),_T("删除好友"),MB_OK);
		return;
	}
}

void CMyFriend::OnClickedAddperson()
{
	// TODO: 在此添加控件通知处理程序代码              
	m_CurrentFocus = m_Tree.GetSelectedItem();     //设置当前选中的焦点
	if (!m_Tree.GetItemText(m_Tree.GetParentItem(m_CurrentFocus)).IsEmpty())    //检查是否在分组中添加分组
	{
		MessageBox(_T("添加好友只能选择分组名哟，乖~~╮(╯▽╰)╭ "),_T("添加好友"),MB_OK);
		return;
	}
	else
	{
		CAddPerson addpersonDlg;
		addpersonDlg.DoModal();           //运行模态对话框
	}
}

BOOL CMyFriend::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	OnClickedMoreinfo();                                      //初始化时自动按下详细信息按钮,为了美观嘛,初始界面还是小巧点好
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT);            //设置CListControl风格,能被整行选中
	m_List.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,80);       //插入姓名行
	m_List.InsertColumn(1,_T("性别"),LVCFMT_CENTER,50);       //插入性别行
	m_List.InsertColumn(2,_T("电话"),LVCFMT_CENTER,105);      //插入电话号码行
	m_List.InsertColumn(3,_T("邮箱"),LVCFMT_CENTER,140);      //插入邮箱行
	m_List.InsertColumn(4,_T("所在分组"),LVCFMT_CENTER,110);  //插入所在分组行	
	ShowAllPerson();                                          //显示好友详细信息
	ShowAllPeronTree();
	return TRUE;
}

void CMyFriend::OnClickedMoreinfo()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	if (GetDlgItemText(IDC_MOREINFO,str),str == "详细信息 >>")
	{
		SetDlgItemText(IDC_MOREINFO,_T("详细信息<<"));  //改变按钮文本
	}
	else
	{
		SetDlgItemText(IDC_MOREINFO,_T("详细信息 >>")); //这里的 >>前有一个空格。。。不然我也不知道怎么格式显示有问题0-0
	}
	static CRect rectNormal;              //保存正常大小信息
	static CRect rectSmaller;             //保存缩小后的大小信息

	if (rectNormal.IsRectNull())          //如果正常大小矩阵范围不为NULL的情况下
	{
		CRect rectSeparator;              //再创建一个存放将要剪切下的矩阵范围数据
		GetWindowRect(&rectNormal);       //初始化正常大小的矩阵信息
		GetDlgItem(IDC_SEPARATOR)->GetWindowRect(&rectSeparator); //获得拆分对话框矩阵的Image的坐标
		rectSmaller.left = rectNormal.left;                       //缩小后的矩阵的左不变
		rectSmaller.top = rectNormal.top;                         //顶也不变
		rectSmaller.right = rectSeparator.right;                  //右边坐标等于分割线Image的坐标y
		rectSmaller.bottom = rectNormal.bottom;                   //底部坐标也不变
	}
	if (str == "详细信息<<")
	{
		SetWindowPos(NULL,0,0,rectSmaller.Width(),rectSmaller.Height(),SWP_NOMOVE | SWP_NOZORDER);    //若伸展，则缩小
	}
	if (str == "详细信息 >>")
	{
		SetWindowPos(NULL,0,0,rectNormal.Width(),rectNormal.Height(),SWP_NOMOVE | SWP_NOZORDER);      //若缩小，则伸展
	}
}

void CMyFriend::OnClickedRemove()
{
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM m_Remove = m_Tree.GetSelectedItem();
	CString TargetRemove = m_Tree.GetItemText(m_Remove);                           //选中的目标项文本
	if (m_Remove == NULL && m_List.GetSelectionMark() == -1)                          //(1).若未选中任何
	{
		MessageBox(_T("尚未选中任何人或组哟~"),_T("删除好友"),MB_OK);
		return;
	}
	if (m_Remove == m_DefalutFocus)                                                       //(2).若选中"我的好友"分组
	{
		MessageBox(_T("这是霸王组，不能删除哟╮(╯▽╰)╭ "),_T("删除好友"),MB_OK);
		return;
	}
	else                                                                                  //选中其他可删除的情况
	{
		if (!m_Tree.GetItemText(m_Tree.GetParentItem(m_Remove)).IsEmpty())               //(3).若选中删除的项不是分组
		{
			RemovePerson_CTreeControl(m_Remove);                                                     //删除选中的好友
			RefreshData();                                                                           //刷新总数据
			return;
		}
		if (!m_Tree.ItemHasChildren(m_Remove) && \
			m_Tree.GetItemText(m_Tree.GetParentItem(m_Remove)).IsEmpty())                //(4).选中没有人的分组时
		{
			RemoveGroup(TargetRemove);                                                                  //删除分组
			RefreshData();                                                                              //刷新总数据
			return;
		}
		if (m_Tree.GetItemText(m_Tree.GetParentItem(m_Remove)).IsEmpty() && \
			m_Tree.ItemHasChildren(m_Remove))                                                  //(5).选中有好友的分组时
		{
			int temp = MessageBox(_T("你选中的一个分组，确定要删除这个分组及里面所有成员吗？"),\
				_T("删除分组及成员"),MB_OKCANCEL);                                  //判断是否选中确定按钮
			if (temp == IDCANCEL)
			{
				return;
			}
			else
			{
				CString Dele_GroupName = m_Tree.GetItemText(m_Remove);                        //获得选中分组的文本
				CString Target_GroupName;                                                            //保存循环所得分组名
				ADO sql;
				sql.OnInitADOConn();                                                                 //初始化数据库连接
				sql.initRecordset();																 //创建记录集实例
				_bstr_t sql_DDL_DELETE_Person = "select * from PersonInfo";							 //sql语句
				sql.m_pReset->Open(sql_DDL_DELETE_Person,sql.m_pConn.GetInterfacePtr(),
					adOpenDynamic,adLockOptimistic,adCmdText);  //打开PersonInfo记录集
				try
				{
					while (!sql.m_pReset->adoEOF)												     //记录集指针不超出末尾记录时执行循环
					{
						Target_GroupName = (char*)(_bstr_t)sql.m_pReset->GetCollect("所在分组");     //保存循环所得分组名
						if (Dele_GroupName == (CString)Target_GroupName)				//判断要删除的人所在分组是否等于选中的分组
						{
							sql.m_pReset->Delete(adAffectCurrent);									//删除该行
						}												    
						sql.m_pReset->MoveNext();													//记录集指针后移一位
					}
					sql.CloseConn();										//断开数据库连接
					RemoveGroup(Dele_GroupName);							//删除所选分组在数据库中的记录
					RefreshData();											//刷新总数据
					return;
				}
				catch(...)
				{
					MessageBox(_T("批量删除好友出错啦(＞﹏＜)"),_T("批量删除好友"),MB_OK);
					return;
				}
			}
		}
	}
}

void CMyFriend::OnClickedRewrite()
{
	// TODO: 在此添加控件通知处理程序代码
	CReWrite m_AlterPerson;
	HTREEITEM Selected_TreeItem = m_Tree.GetSelectedItem();		//保存选中的节点信息
	if (Selected_TreeItem == NULL)										//判断是否有选中任何节点
	{
		MessageBox(_T("你还没有选择修改谁呢~O(∩_∩)O~"),_T("修改好友信息"),MB_OK);
		return;
	}
	if (!m_Tree.ItemHasChildren(Selected_TreeItem) && \
		!m_Tree.GetItemText(m_Tree.GetParentItem(Selected_TreeItem)).IsEmpty())  //判断是否选则的是好友，不能是分组
	{																							
		m_AlterPerson.DoModal();	//运行模态对话框
	}
	else
	{
		MessageBox(_T("操作有问题诶,╮(╯▽╰)╭,不能选择分组，只能选择好友"),_T("修改好友信息"),MB_OK);
		return;
	}
}

void CMyFriend::OnClickedSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	CSelectPerson m_SelectDlg;
	m_SelectDlg.DoModal();
}

void CMyFriend::OnClickedAddgroup()
{
	// TODO: 在此添加控件通知处理程序代码
	CAddGroup m_AddGroupDlg;
	m_AddGroupDlg.DoModal();
}

void CMyFriend::OnClickedRefresh()
{
	// TODO: 在此添加控件通知处理程序代码
	RefreshData();
}

void CMyFriend::OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CShowInfo m_ShowDlg;
	m_ShowDlg.DoModal();
}
