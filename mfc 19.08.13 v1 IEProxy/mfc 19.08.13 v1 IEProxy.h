
// mfc 19.08.13 v1 IEProxy.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Cmfc190813v1IEProxyApp:
// 有关此类的实现，请参阅 mfc 19.08.13 v1 IEProxy.cpp
//

class Cmfc190813v1IEProxyApp : public CWinApp
{
public:
	Cmfc190813v1IEProxyApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Cmfc190813v1IEProxyApp theApp;
