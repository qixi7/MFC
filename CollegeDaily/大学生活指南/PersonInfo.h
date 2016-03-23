#pragma once
class PersonInfo
{
public:
	PersonInfo()
	{
		per_Name = _T("未知");
		per_Sex = _T("未知");
		per_Tel = _T("未知");
		per_Email = _T("未知");
		per_Group = _T("我的好友");
	}
	~PersonInfo(void);
public:
	CString per_Name;
	CString per_Sex;
	CString per_Tel;
	CString per_Email;
	CString per_Group;
};