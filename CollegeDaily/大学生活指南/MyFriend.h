#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMyFriend 对话框
#define MaxGroupNumber 50 //好友分组最大数量,为了减少TreeControl与数据库交互时遍历插入时带来的开销
class CMyFriend : public CDialogEx
{
	DECLARE_DYNAMIC(CMyFriend)

public:
	CMyFriend(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyFriend();

// 对话框数据
	enum { IDD = IDD_MYFRIEND_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedAddperson();
	CTreeCtrl m_Tree;
//	CListBox m_List;

public:
	HTREEITEM m_DefalutFocus;
	HTREEITEM m_CurrentFocus;

	CString str_Name;                               //获取的姓名,用与插入好友列表
	CString str_TargetGroup;                        //选中的目标分组       
	HTREEITEM m_Group[50];                          //分组数组,用于存储HTREEITEM节点类型变量
	int GroupNumber;                                //当前分组数量

	void ShowAllPerson();
	void ShowAllPeronTree();
	void RemovePerson_CListControl(long pos);
	void RemovePerson_CTreeControl(HTREEITEM Remove_CTreeControl);
	void RemoveGroup(CString str_RemoveGroup);
	void RefreshData();
	CListCtrl m_List;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedMoreinfo();
	afx_msg void OnClickedRemove();
	afx_msg void OnClickedRewrite();
	afx_msg void OnClickedSelect();
	afx_msg void OnClickedAddgroup();
	afx_msg void OnClickedRefresh();
	afx_msg void OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);
};
