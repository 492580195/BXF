/********************************************************************
/* Copyright (c) 2013 The BOLT UIEngine. All rights reserved.
/* Use of this source code is governed by a BOLT license that can be
/* found in the LICENSE file.
********************************************************************/ 
/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   WebKernelSyncProxy
*   Author      :   ������
*   Create      :   2013-7-6 
*   LastChange  :   2013-7-6
*   History     :	
*
*   Description :   ����������/�߳�ͬ��ͨ�ŵĴ���
*
********************************************************************/ 
#ifndef __WEBKERNELSYNCPROXY_H__
#define __WEBKERNELSYNCPROXY_H__

// �����/�߳�ͬ��ͨ�ŵ�Ӧ�����
// Ŀǰ������render��browser�������̵����̵߳���
class WebKernelSyncReplyManager
{
public:
	WebKernelSyncReplyManager();
	~WebKernelSyncReplyManager();

	int GetReplyNo();
	bool Add(int no, CefRefPtr<CefListValue> spResult);
	CefRefPtr<CefListValue> Fetch(int no);

	void Clear();

private:

	int m_no;

	typedef stdext::hash_map<int, CefRefPtr<CefListValue> > mapReply;
	mapReply m_replys;
};


class WebKernelSyncProxy
{
public:
	WebKernelSyncProxy(void);
	~WebKernelSyncProxy(void);

	bool Init();
	bool Uninit();

	// ���̼���Ϣ
	bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefProcessMessage> message);

	// �̼߳���Ϣ
	bool OnThreadMessagerRecevied(CefRefPtr<CefBrowser> browser, CefRefPtr<CefProcessMessage> message);

public:

	// RenderProcess functions
	bool OnBeforeNavigation( CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, 
		CefRefPtr<CefRequest> request, cef_navigation_type_t navigation_type, bool is_redirect );

	void OnFocusedNodeChanged( CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, 
		CefRefPtr<CefDOMNode> node );

	// BrowserProcess UI Thread
	void OnBeforePopup(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
		const CefString& target_url, const CefString& target_frame_name,
		const CefPopupFeatures& popupFeatures);

private:

	bool OnBeforeNavigationMessage(CefRefPtr<CefBrowser> browser, CefRefPtr<CefProcessMessage> message);
	bool OnBeforeNavigationRetMessage(CefRefPtr<CefBrowser> browser, CefRefPtr<CefProcessMessage> message);

	bool OnFocusedNodeChangedMessage(CefRefPtr<CefBrowser> browser, CefRefPtr<CefProcessMessage> message);

	bool OnBeforePopupMessage(CefRefPtr<CefBrowser> browser, CefRefPtr<CefProcessMessage> message);

private:

	static void SerializeFrame(CefListValue* lpListValue, CefFrame* lpFrame, int index);
	static CefRefPtr<CefFrame> UnSerializeFrame(CefListValue* lpListValue, CefBrowser* lpBrowser, int index);

private:

	// �¼������б�
	static const wchar_t s_szOnBeforeNavigation[];
	static const wchar_t s_szOnBeforeNavigationRet[];
	static const wchar_t s_szOnFocusedNodeChanged[];

	static const wchar_t s_szOnBeforePopup[];
	
	// �¼��ص������б�
	typedef bool (WebKernelSyncProxy::*LPFNONPROCESSMESSAGE)(CefRefPtr<CefBrowser>, CefRefPtr<CefProcessMessage>);
	typedef stdext::hash_map<std::wstring, LPFNONPROCESSMESSAGE> messageMap;
	messageMap m_messageMap;

	// �ص�Ӧ�������
	WebKernelSyncReplyManager m_replyManager;
};

#endif // __WEBKERNELSYNCPROXY_H__