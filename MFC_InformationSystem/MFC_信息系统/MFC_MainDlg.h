
// MFC_MainDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

#define MaxGroupNumber 50                      //好友分组最大数量,为了减少TreeControl与数据库交互时遍历插入时带来的开销
// CMFC_MainDlg 对话框
class CMFC_MainDlg : public CDialogEx
{
// 构造
public:
	CMFC_MainDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC__DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedMoreinfo();
	afx_msg void OnClickedAdd();

	HTREEITEM m_DefalutFocus;
	HTREEITEM m_CurrentFocus;

    CString str_Name;                               //获取的姓名,用与插入好友列表
	CString str_TargetGroup;                        //选中的目标分组
	CTreeCtrl m_TreeControl;
	CListCtrl m_ListCtrl;                          
	HTREEITEM m_Group[50];                               //分组数组,用于存储HTREEITEM节点类型变量
 	int GroupNumber;                                      //当前分组数量

	afx_msg void OnClickedRemove();
	afx_msg void OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);

	void ShowAllPerson();
	void ShowAllPeronTree();
	void RemovePerson_CListControl(long pos);
	void RemovePerson_CTreeControl(HTREEITEM Remove_CTreeControl);
	void RemoveGroup(CString str_RemoveGroup);
	void RefreshData();       

	afx_msg void OnClickedAddgroup();
	afx_msg void OnClickedAlter();
	afx_msg void OnClickedSelect();
	afx_msg void OnClickedRefresh();
};