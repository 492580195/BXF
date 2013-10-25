/********************************************************************
/* Copyright (c) 2013 The BOLT UIEngine. All rights reserved.
/* Use of this source code is governed by a BOLT license that can be
/* found in the LICENSE file.
********************************************************************/ 
#include "stdafx.h"
#include "./WebKernelClient.h"
#include "./DBG.h"
#include "./BaseBoltBrowser.h"

WebKernelClient::WebKernelClient(void)
{
}

WebKernelClient::~WebKernelClient(void)
{
}

CefRefPtr<CefContextMenuHandler> WebKernelClient::GetContextMenuHandler()
{
	return NULL;
}

CefRefPtr<CefDisplayHandler> WebKernelClient::GetDisplayHandler()
{
	return m_displayHandler.get();
}

CefRefPtr<CefDownloadHandler> WebKernelClient::GetDownloadHandler()
{
	return NULL;
}

CefRefPtr<CefFocusHandler> WebKernelClient::GetFocusHandler()
{
	return NULL;
}

CefRefPtr<CefGeolocationHandler> WebKernelClient::GetGeolocationHandler()
{
	return NULL;
}

CefRefPtr<CefKeyboardHandler> WebKernelClient::GetKeyboardHandler()
{
	return NULL;
}

CefRefPtr<CefLifeSpanHandler> WebKernelClient::GetLifeSpanHandler()
{
	return m_lifeSpanHandler.get();
}

CefRefPtr<CefLoadHandler> WebKernelClient::GetLoadHandler()
{
	return NULL;
}

CefRefPtr<CefRenderHandler> WebKernelClient::GetRenderHandler()
{
	return m_renderHandler.get();
}

CefRefPtr<CefRequestHandler> WebKernelClient::GetRequestHandler()
{
	return NULL;
}

bool WebKernelClient::OnProcessMessageReceived( CefRefPtr<CefBrowser> browser, CefProcessId source_process, 
											   CefRefPtr<CefProcessMessage> message )
{
	//
	//�ж��Ƿ�Ϊxlue.js.message.xxx���͵���Ϣ��
	//����������Lua����Ϣ��Ӧ����
	//�����ؽ����Render����
	//
	CefString name=message->GetName();
	const wchar_t xlueJsMessageHeader[] = L"xlue.js.message.";
	int headLength = sizeof(xlueJsMessageHeader)/sizeof(wchar_t)-1;
	DBG(name);
	int equal = std::wcsncmp(name.c_str(),xlueJsMessageHeader,headLength-1);
	if(equal==0)
	{
		CefString jsMessageName = name.ToString().substr(headLength);
		CefRefPtr<CefListValue> argList = message->GetArgumentList();
		DBG(jsMessageName);

		//���Lua�����Ƿ�����Ӧ�˸���Ϣ�����ڷ��ظ�render���̵�js����
		bool handled = false;

		//TODO:����Luaע�����Ӧ����
		BaseBoltBrowser* lpBoltBrowser = g_webKernelGlobal.m_browserManager.GetBoltBrowserFromID(browser->GetIdentifier());
		lpBoltBrowser->OnJavaScriptMessageReceived(jsMessageName,argList,handled);

		CefRefPtr<CefProcessMessage> resultMessage = CefProcessMessage::Create(name);
		CefRefPtr<CefListValue> resultArgList = resultMessage->GetArgumentList();
		resultArgList->SetBool(0,handled);
		browser->SendProcessMessage(PID_RENDERER,resultMessage);
		return true;
	}

	return g_webKernelGlobal.m_syncProxy.OnProcessMessageReceived(browser, message);
}

bool WebKernelClient::SetLifeSpanHandler( CefLifeSpanHandler* lpHandler )
{
	m_lifeSpanHandler = lpHandler;

	return true;
}

bool WebKernelClient::SetDisplayHandler( CefDisplayHandler* lpHandler )
{
	m_displayHandler = lpHandler;

	return true;
}

bool WebKernelClient::SetRenderHandler( CefRenderHandler* lpHandler )
{
	m_renderHandler = lpHandler;

	return true;
}