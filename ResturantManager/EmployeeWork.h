#pragma once


// CEmployeeWork 对话框

class CEmployeeWork : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployeeWork)

public:
	CEmployeeWork(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEmployeeWork();

// 对话框数据
	enum { IDD = IDD_EMPLOY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	_RecordsetPtr m_ptr;

	virtual BOOL OnInitDialog();
};
