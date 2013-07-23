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
*   FileName    :   WebKernelMessageLoop
*   Author      :   ������
*   Create      :   2013-6-28 
*   LastChange  :   2013-6-28
*   History     :	
*
*   Description :   ���������Ϣѭ��������Ŀǰ����timer
*
********************************************************************/ 
#ifndef __WEBKERNELMESSAGELOOP_H__
#define __WEBKERNELMESSAGELOOP_H__

class WebKernelMessageLoop
{
public:
	WebKernelMessageLoop(void);
	~WebKernelMessageLoop(void);

	void IncreaseBrowserUser();
	void DecreaseBrowserUser();

private:

	bool Start();
	bool End();

	long OnMessageLoopWork();
	static long XLUE_STDCALL MessageLoopWorkCallBack(void* userData);

private:

	// Timer
	void OnTimer(unsigned int timerID);

private:

	// ��ǰ������Ϣѭ�������������
	int m_browserUserCount;

	// XLUE��Ϣѭ�����Ƶ�cookie
	long m_messageLoopWorkCookie;

	// ��Ϣѭ��timerid
	unsigned long m_msgLoopTimerID;

	typedef Xunlei::Bolt::MemberTimerManagerWrapperT<WebKernelMessageLoop> TimerManager;
	TimerManager m_timerManager;
};

#endif // __WEBKERNELMESSAGELOOP_H__