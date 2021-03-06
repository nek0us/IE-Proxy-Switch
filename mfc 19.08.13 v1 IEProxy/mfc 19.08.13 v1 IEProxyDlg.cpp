
// mfc 19.08.13 v1 IEProxyDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc 19.08.13 v1 IEProxy.h"
#include "mfc 19.08.13 v1 IEProxyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cmfc190813v1IEProxyDlg 对话框



Cmfc190813v1IEProxyDlg::Cmfc190813v1IEProxyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC190813V1IEPROXY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc190813v1IEProxyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cmfc190813v1IEProxyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cmfc190813v1IEProxyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmfc190813v1IEProxyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmfc190813v1IEProxyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cmfc190813v1IEProxyDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Cmfc190813v1IEProxyDlg 消息处理程序

BOOL Cmfc190813v1IEProxyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cmfc190813v1IEProxyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cmfc190813v1IEProxyDlg::OnPaint()
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

	CString str = (L"D:\\ipindex\\proxy\\");
	if (!PathIsDirectory(str))
	{
		::CreateDirectory(str, NULL);//创建目录,已有的话不影响
	}



	CFile file1;

	TCHAR* pFileName = _T("D:\\ipindex\\proxy\\index.txt");

	if (!file1.Open(pFileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead))
	{
		MessageBox(_T("欢迎使用!"));

		return;
	}
	DWORD len = file1.GetLength();
	len = len / 2;
	TCHAR *pContent = new TCHAR[len + 1];

	//file.Seek(0,CFile::begin);
	file1.Read(pContent, len * 2);
	pContent[len] = '\0';    // 如果文件后方还有其他字符，需要添加结束字符'\0'
	// CString str=pContent;
	//MessageBox(pContent);
	CString _name;
	_name.Format(_T("%s"), pContent);
	if (_name.IsEmpty())
	{
		MessageBox(L"欢迎使用~");
	}
	else
	{
		while (!(_name.IsEmpty()))
		{
			CString _top = _name.Left(_name.Find('\n'));
			_name = _name.Mid(_name.Find('\n') + 1);
			((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(_top);
		}
	}
	file1.Close();

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cmfc190813v1IEProxyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cmfc190813v1IEProxyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取
	CString ipproxy = NULL;
	CString port = NULL;
	CString gate = NULL;
	CString dns = NULL;
	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(ipproxy);
	GetDlgItem(IDC_EDIT1)->GetWindowText(port);
	ipproxy.Append(L"\n");
	port.Append(L"\n");

	//方案文件名
	CString name1(_T("D:\\ipindex\\proxy\\"));
	CString name2;
	GetDlgItem(IDC_COMBO1)->GetWindowText(name2);
	name1.Append(name2);
	name1.Append(_T(".txt"));
	CString _n(L"\n");


	CFile life;
	CString strline;
	BOOL flag = life.Open(L"D:\\ipindex\\proxy\\index.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);   //判断索引文件是否存在
	if (flag == FALSE)
	{



		CFile setlife;
		setlife.Open(L"D:\\ipindex\\proxy\\index.txt", CFile::modeCreate | CFile::modeWrite);    //创建索引文件
		setlife.Write(name2.GetBuffer(), name2.GetLength() * sizeof(TCHAR));    //保存方案名至索引文件
		setlife.Write(_n.GetBuffer(), _n.GetLength() * sizeof(TCHAR));
		setlife.Flush();
		setlife.Close();

		CFile file;
		file.Open(name1, CFile::modeCreate | CFile::modeWrite);               //创建方案文件
		//file.Write(str.GetBuffer(), str.GetLength() * sizeof(TCHAR));//str为CString类型   
		file.Write(ipproxy.GetBuffer(), ipproxy.GetLength() * sizeof(TCHAR));    //保存方案信息
		file.Write(port.GetBuffer(), port.GetLength() * sizeof(TCHAR));
		file.Flush();
		file.Close();

		MessageBox(L"方案创建保存成功！");

	}
	else
	{


		//life.Open(L"D:\\ipindex\\index.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
		life.SeekToEnd();
		life.Write(name2.GetBuffer(), name2.GetLength() * sizeof(TCHAR));    //保存方案名至索引文件
		life.Write(_n.GetBuffer(), _n.GetLength() * sizeof(TCHAR));
		life.Flush();
		life.Close();

		CFile file;
		file.Open(name1, CFile::modeCreate | CFile::modeWrite);               //创建方案文件
		//file.Write(str.GetBuffer(), str.GetLength() * sizeof(TCHAR));//str为CString类型   
		file.Write(ipproxy.GetBuffer(), ipproxy.GetLength() * sizeof(TCHAR));    //保存方案信息
		file.Write(port.GetBuffer(), port.GetLength() * sizeof(TCHAR));
		file.Flush();
		file.Close();

		MessageBox(L"保存方案成功！重新开启后生效！");
	}
	UpdateData(TRUE);
}


void Cmfc190813v1IEProxyDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//载入

	CString ipproxy = NULL;
	CString port = NULL;
	CString text = NULL;
	GetDlgItem(IDC_COMBO1)->GetWindowText(text);
	//if (text.Find('\n'))
	//{
	//	text = text.Left(text.Find('\n'));
	//}

	CString path(_T("D:\\ipindex\\proxy\\"));
	path.Append(text);
	path.Append(_T(".txt"));

	CIPAddressCtrl m_ip;

	DWORD m_dwPos = 0;
	CString strline;//定义一个变量用于接收读取的一行内容 
	CStdioFile file;//定义一个CStdioFile类的对象 file 


	CFile file1;




	if (!file1.Open(path, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead))
	{
		MessageBox(_T("打开方案失败!"));
	}
	DWORD len = file1.GetLength();
	len = len / 2;
	TCHAR *pContent = new TCHAR[len + 1];

	//file.Seek(0,CFile::begin);
	file1.Read(pContent, len * 2);
	pContent[len] = '\0';    // 如果文件后方还有其他字符，需要添加结束字符'\0'
	// CString str=pContent;
	//MessageBox(pContent);

	CString allip;
	allip.Format(_T("%s"), pContent);

	CString m_ipproxy = allip.Left(allip.Find('\n'));
	CString m_port = allip.Mid(allip.Find('\n') + 1);



	SetDlgItemText(IDC_IPADDRESS1, m_ipproxy);
	SetDlgItemText(IDC_EDIT1, m_port);


	//m_ip.SetWindowText(pContent);

	file1.Close();

}


void Cmfc190813v1IEProxyDlg::OnBnClickedButton3()    //设置 代理ip
{
	// TODO: 在此添加控件通知处理程序代码


	CString ipproxy = NULL;
	CString port = NULL;
	CString _cmdon = NULL;
	CString _cmdset = NULL;
	CString set_before("/c reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyServer /d \"");
	CString mao(":");
	CString set_after("\" /f");
	CString onproxy("/c reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyEnable /t REG_DWORD /d 1 /f");


	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(ipproxy);
	GetDlgItem(IDC_EDIT1)->GetWindowText(port);

	

	CString m_port = port.Left(port.Find('\n'));

	//if (dns == "0.0.0.0")  //check dns
	//{
	//	dns = gate;
	//}

	//set ip
	_cmdset.Append(set_before);
	_cmdset.Append(ipproxy);
	_cmdset.Append(mao);
	_cmdset.Append(m_port);
	_cmdset.Append(set_after);

	SHELLEXECUTEINFO shellon;
	memset(&shellon, 0, sizeof(shellon));
	shellon.cbSize = sizeof(shellon);
	shellon.hwnd = NULL;
	shellon.lpVerb = _T("runas");
	shellon.lpFile = _T("C:\\\\Windows\\\\System32\\\\cmd.exe"); // 打开代理
	shellon.lpParameters = (onproxy);
	shellon.nShow = SW_HIDE;
	shellon.fMask = SEE_MASK_NOCLOSEPROCESS;
	BOOL seton = ShellExecuteEx(&shellon);


	SHELLEXECUTEINFO shellproxy;
	memset(&shellproxy, 0, sizeof(shellproxy));
	shellproxy.cbSize = sizeof(shellproxy);
	shellproxy.hwnd = NULL;
	shellproxy.lpVerb = _T("runas");
	shellproxy.lpFile = _T("C:\\\\Windows\\\\System32\\\\cmd.exe"); // 修改代理
	shellproxy.lpParameters = (_cmdset);
	shellproxy.nShow = SW_HIDE;
	shellproxy.fMask = SEE_MASK_NOCLOSEPROCESS;
	BOOL setproxy = ShellExecuteEx(&shellproxy);





}

 
void Cmfc190813v1IEProxyDlg::OnBnClickedButton4()   //取消代理
{
	// TODO: 在此添加控件通知处理程序代码

	CString ipproxy = NULL;
	CString port = NULL;
	CString _cmdzero("/c reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyServer /d \"\" /f");
	CString _cmdoff("/c reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyEnable /t REG_DWORD /d 0 /f");



	SHELLEXECUTEINFO shelloff;
	memset(&shelloff, 0, sizeof(shelloff));
	shelloff.cbSize = sizeof(shelloff);
	shelloff.hwnd = NULL;
	shelloff.lpVerb = _T("runas");
	shelloff.lpFile = _T("C:\\\\Windows\\\\System32\\\\cmd.exe"); // 关闭代理
	shelloff.lpParameters = (_cmdoff);
	shelloff.nShow = SW_HIDE;
	shelloff.fMask = SEE_MASK_NOCLOSEPROCESS;
	BOOL setoff = ShellExecuteEx(&shelloff);


	SHELLEXECUTEINFO shellzero;
	memset(&shellzero, 0, sizeof(shellzero));
	shellzero.cbSize = sizeof(shellzero);
	shellzero.hwnd = NULL;
	shellzero.lpVerb = _T("runas");
	shellzero.lpFile = _T("C:\\\\Windows\\\\System32\\\\cmd.exe"); // 清空代理
	shellzero.lpParameters = (_cmdzero);
	shellzero.nShow = SW_HIDE;
	shellzero.fMask = SEE_MASK_NOCLOSEPROCESS;
	BOOL setzero = ShellExecuteEx(&shellzero);




}
