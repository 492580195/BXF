/********************************************************************
/* Copyright (c) 2013 The BOLT UIEngine. All rights reserved.
/* Use of this source code is governed by a BOLT license that can be
/* found in the LICENSE file.
********************************************************************/ 
#include "stdafx.h"
#include "./XLUEWebKernel.h"
#include "./BrowserObject/BoltBrowserObjectRegister.h"

WebKernelGlobal g_webKernelGlobal;

// ��չģ���ʼ�ص���ÿ����չģ�鱻����ʱ�����øýӿ�
BOOL XLUE_STDCALL XLUE_InitExtModule()
{
	if (!WebKernelGlobalMethods::Init())
	{
		return FALSE;
	}

	return TRUE;
}

BOOL XLUE_STDCALL XLUE_UninitExtModule()
{
	WebKernelGlobalMethods::Uninit();

	//TODO
	return TRUE;
}

BOOL XLUE_STDCALL XLUE_RegisterObj( const char* lpCategory, const char* lpObjClass )
{
	assert(lpCategory);
	assert(lpObjClass);

	BOOL ret = TRUE;

	if (::strcmp(lpObjClass, EXTCLASSNAME_BOLTBROWSEROBJECT) == 0)
	{
		ret = BoltBrowserObjectRegister::RegisterBoltBrowserObject();
	}
	else if (::strcmp(lpObjClass, EXTCLASSNAME_WINDOWLESSBOLTBROWSEROBJECT) == 0)
	{
		ret = WindowlessBoltBrowserObjectRegister::RegisterWindowlessBoltBrowserObject();
	}
	else
	{
		ret = FALSE;
		assert(false);
	}

	return ret;
}

long XLUE_STDCALL XLUE_RunWebServer(const wchar_t* id)
{
	return WebKernelGlobalMethods::RunWebServer();
}

long XLUE_STDCALL XLUE_IsWebServerIdle()
{
	// return 0��ʾidle����0��ʾ����ʹ��
	return 1;
}