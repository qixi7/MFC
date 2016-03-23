#include "stdafx.h"
#include "ADO.h"


ADO::ADO(void)
{
	m_pConn = NULL;
	m_pReset = NULL;
}

ADO::~ADO(void)
{
}

BOOL ADO::OnInitADOConn()
{
	::CoInitialize(NULL);   //  初始化COM 环境
	try 
	{
		m_pConn.CreateInstance(_T("ADODB.Connection"));    //创建连接对象实例
		_bstr_t strConn=_T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=stu_mdb.mdb;Jet OLEDB:DataBase Password=admin");//连接字符串
		m_pConn->Open(strConn,"","",adModeUnknown);      //连接数据库
		return TRUE;
	}
	catch(_com_error e)      //暂时不报诡异的错，先不用e....想报错了在下面加上e.Description()和e.ErrorMessage();
	{
		CString err = _T("");
		err.Format(_T("数据库连接出错!"));
		return false;
	}
}

void ADO::initRecordset()   //打开数据集
{
	try
	{
		m_pReset.CreateInstance(_T("ADODB.Recordset"));  //创建记录集实例
	}
	catch(_com_error e)
	{
		AfxMessageBox(_T("打开记录集失败!"));
		return;
	}
}

void ADO::CloseRecordset()
{
	try
	{
		if (m_pReset->GetState() == adStateOpen)     //判断记录集的状态是否为打开
		{
			m_pReset->Close();                       //关闭记录集
		}
	}
	catch(_com_error e)
	{
		AfxMessageBox(_T("关闭记录集出错!"));
	}
}
 
void ADO::CloseConn()
{
	if (m_pConn->GetState() == adStateOpen)        //判断数据库连接是否为打开
	{
		m_pConn->Close();						   //断开数据库连接 
	}
	::CoUninitialize();          //释放COM环境
}

