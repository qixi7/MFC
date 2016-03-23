
// CStringCatcherDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "软件工程作业.h"
#include "CStringCatcherDlg.h"
#include "afxdialogex.h"
#include "CString"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CStringCatcherDlg::CStringCatcherDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStringCatcherDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStringCatcherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStringCatcherDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SCAN, &CStringCatcherDlg::OnBnClickedScan)
	ON_BN_CLICKED(IDC_OPEN, &CStringCatcherDlg::OnBnClickedOpen)
END_MESSAGE_MAP()

// CStringCatcherDlg 消息处理程序

BOOL CStringCatcherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SkinH_Attach();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStringCatcherDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CStringCatcherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CStringCatcherDlg::OnBnClickedScan()
{
	//获得复选框的选中状态
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK);   //获取复选框指针
	int state = pBtn->GetCheck();                      //取得选中状态
	//读取文件
	CString path("");
	GetDlgItemText(IDC_PATH,path);                     //获得编辑框文本，即路径
	ifstream getword(path);
	string text("");
	map<string,int> WordCatcher ;
	while(getword >> text)                             //读取文件文本
	{
		if(text != "." && text != "," && text != "\"")
		{
			transform(text.begin(), text.end(), text.begin(), tolower);
			++WordCatcher[text];
		}
	}
	map<string,int>::iterator it = WordCatcher.begin();   //迭代器初始位置靠前
	getword.close();                                   //关闭文件流 
	//排除出现次数最大前10个
	int a[10] = {0};
	int i = 0;
	int temp = 0;
	CString result("");
	CString temp_string("");
	for ( ; i < 10; ++i)
	{
		if (state == 0)
		{
			for (it = WordCatcher.begin() ; it != WordCatcher.end(); ++it)
			{
				temp = it->second;
				if (temp > a[i])
				{
					a[i] = temp;
				}
			}
		}
		if (state ==1)
		{
			for (it = WordCatcher.begin(); it != WordCatcher.end(); ++it)
			{
				temp = it->second;
				if (it->first.compare("am") == 0 ||
					it->first.compare("is") == 0 ||
					it->first.compare("are") == 0 ||
					it->first.compare("i") == 0 ||
					it->first.compare("you") == 0 ||
					it->first.compare("she") == 0 ||
					it->first.compare("he") == 0 ||
					it->first.compare("and") == 0 )
				{
					it->second = 0;
					continue;
				}
				if (temp > a[i])
				{
					a[i] = temp;
				}
			}
		}
		for ( it = WordCatcher.begin(); it != WordCatcher.end(); ++it)
		{
			if (it->second == a[i])
			{
				char *temp_word = const_cast<char*>((it->first).c_str());
				CString temp_first(temp_word);
				temp_string.Format(_T("Top_%d: %s 出现次数: %d \r\n" ), i+1, temp_first, a[i]);
				result = result + temp_string; //因为编辑框不能append,只有保存上次的结果再打印了╮(╯▽╰)╭
				SetDlgItemText(IDC_RESULT,result);   //设置最终结果
				it->second = 0;                   //清零次数，为了下次遍历能取得有效最大值
				break;
			}
		}
	}

}

void CStringCatcherDlg::OnBnClickedOpen()
{
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString FilePath;
	if (IDOK == fileDlg.DoModal())
	{
		FilePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_PATH, FilePath);
	}
}






