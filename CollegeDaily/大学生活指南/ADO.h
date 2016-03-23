#pragma once
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") 
class ADO
{
public:
	ADO(void);
	~ADO(void);
	_RecordsetPtr m_pReset;     //创建记录集指针
	_ConnectionPtr m_pConn;         //创建连接指针

	BOOL OnInitADOConn();       //声明初始化连接函数
	void initRecordset();       //声明创建记录集实例函数
	void CloseRecordset();      //声明关闭记录集实例函数
	void CloseConn();           //声明关闭连接函数
};