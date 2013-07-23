/********************************************************************
/* Copyright (c) 2013 The BOLT UIEngine. All rights reserved.
/* Use of this source code is governed by a BOLT license that can be
/* found in the LICENSE file.
********************************************************************/ 
#include "stdafx.h"
#include "./WebKernelSettings.h"
#include <atltime.h>

const wchar_t WebKernelSettings::s_szUserAgent[] = L"BoltWebBrowser";
const wchar_t WebKernelSettings::s_szDefaultLocale[] = L"zh-CN";
const wchar_t WebKernelSettings::s_szOriginUserAgent[] = L"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.73 Safari/537.36 ";
const wchar_t WebKernelSettings::s_szBoltBrowserUserAgent[] = L"BoltBrowser";

WebKernelSettings::WebKernelSettings()
:m_msgLoopUseTimer(true),
m_msgLoopTimerInterval(30)
{

}

WebKernelSettings::~WebKernelSettings()
{

}

bool WebKernelSettings::Init()
{
	m_setting.size = sizeof(m_setting);

	wchar_t szModuleFolder[MAX_PATH];
	::GetModuleFileName(g_webKernelGlobal.m_hModule, szModuleFolder, MAX_PATH);
	::PathRemoveFileSpec(szModuleFolder);

	// ��ʼ���������̣�ʹ��ͬĿ¼�µ�xlueops
	wchar_t szPath[MAX_PATH];
	::PathCombine(szPath, szModuleFolder, L"XLUEOPS.exe");

	cef_string_set(szPath, ::wcslen(szPath), &m_setting.browser_subprocess_path, true);

	m_setting.multi_threaded_message_loop = false;

	// ��ʼ������Ŀ¼
	// TODO
	m_setting.cache_path;

	// ��ʼ����־���������ļ�
#if defined(_DEBUG)
	m_setting.log_severity = LOGSEVERITY_INFO;
#elif defined(XLUE_LOG)
	m_setting.log_severity = LOGSEVERITY_INFO;
#else
	m_setting.log_severity = LOGSEVERITY_DISABLE;
#endif //DEBUG
	
	// ��־�ļ������C:\XLUE\XLUEWebKernel[pname][pid][date].log
	CTime now(::_time64(NULL));
	wchar_t szTime[512];
	wsprintf(szTime, L"[%d-%d-%d-%d-%d-%d]", now.GetYear(), now.GetMonth(), 
		now.GetDay(), now.GetHour(), now.GetMinute(), now.GetSecond());

	::GetModuleFileName(NULL, szPath, MAX_PATH);
	::PathRemoveExtension(szPath);
	const wchar_t* lpProcessName = ::PathFindFileName(szPath);

	unsigned long pid = ::GetCurrentProcessId();
	wchar_t szFileName[200];
	wsprintf(szFileName, L"C:\\XLUE\\XLUEWebKernel[%s][%d][%s].log", lpProcessName, pid, szTime);

	cef_string_set(szFileName, ::wcslen(szFileName), &m_setting.log_file, true);

	// ����������
	m_setting.command_line_args_disabled = false;

	
	// ��ʼ��resources��localesĿ¼
	::PathCombine(szPath, szModuleFolder, L"resources");
	cef_string_set(szPath, ::wcslen(szPath), &m_setting.resources_dir_path, true);

	::PathCombine(szPath, szModuleFolder, L"locales");
	cef_string_set(szPath, ::wcslen(szPath), &m_setting.locales_dir_path, true);

	// ��ʼ��Ĭ������Ϊ��������
	cef_string_set(s_szDefaultLocale, ::wcslen(s_szDefaultLocale), &m_setting.locale, true);

	// ����usergent
	std::wstring userAgent = s_szOriginUserAgent;
	userAgent += s_szBoltBrowserUserAgent;

	cef_string_set(userAgent.c_str(), userAgent.size(), &m_setting.user_agent, true);

	return true;
}

bool WebKernelSettings::Uninit()
{
	m_setting.Reset();

	return true;
}

const CefSettings& WebKernelSettings::GetCefSettings() const
{
	return m_setting;
}

bool WebKernelSettings::GetMsgLoopUseTimer() const
{
	return m_msgLoopUseTimer;
}

unsigned long WebKernelSettings::GetMsgLoopTimerInterval() const
{
	return m_msgLoopTimerInterval;
}
