/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2011              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   SafeWindow
*   Author      :   ������
*   Create      :   2011-10-24
*   LastChange  :   2011-10-24
*   History     :	
*
*   Description :   CWindowImpl��CDialogImpl�İ�ȫ��װ�࣬����ʱ�򲻿�ʹ��delete��ɾ������Ҫ���ö���
*					��SafeDelete������ɾ��
********************************************************************/ 
#ifndef __SAFEWINDOW_H__
#define __SAFEWINDOW_H__

#include <atlbase.h>
#include <atlwin.h>

template<typename BaseWindow>
class SafeWindowWrapper
	: public BaseWindow
{
	typedef BaseWindow base_class;

public:

	BEGIN_MSG_MAP(SafeWindowWrapper)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		// ����Ѿ���ɾ�����ˣ���ô���ٴ�����Ϣ�����࣬�������
		if (m_bFinalDel)
		{
			return TRUE;
		}
		CHAIN_MSG_MAP(base_class)
	END_MSG_MAP()

	SafeWindowWrapper()
		:m_bFinalDel(false),
		m_bOnDestroy(false)
	{}

	void SafeDelete()
	{
		assert(!m_bFinalDel);

		if (base_class::IsWindow()) 
		{
			m_bFinalDel = true;

			if (!m_bOnDestroy)
			{
				End();
			}
		}
		else if (m_dwState & WINSTATE_DESTROYED)
		{
			// �����Ѿ����٣����ǻ�û�е������һ����Ϣ
			m_bFinalDel = true;
		}
		else
		{
			m_bFinalDel = false;
			delete this;
		}
	}

protected:

	// �����ɾ��ֻ����ͨ��DeleteSelf��ɾ����������ֱ�ӵ���delete��ɾ����
	virtual ~SafeWindowWrapper()
	{
		
	}

private:

	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		bHandled = FALSE;

		MarkOnDestroy();

		return 0;
	}

	void End()
	{
		// CDialogImplBaseT
		__if_exists(base_class::StartDialogProc)
		{
			base_class::EndDialog(0);
		}

		// CWindowImplBaseT
		__if_exists(base_class::StartWindowProc)
		{
			base_class::DestroyWindow();
		}
	}

	virtual void OnFinalMessage(HWND)
	{
		m_bOnDestroy = false;

		if (m_bFinalDel)
		{
			m_bFinalDel = false;
			delete this;
		}
	}

	void MarkOnDestroy()
	{
		assert(!m_bOnDestroy);
		m_bOnDestroy = true;
	}

private:

	bool    m_bFinalDel;        // �Ƿ���Ҫ��onfinalmessage����ɾ���Լ�
	bool    m_bOnDestroy;       // �Ƿ��Ѿ����õ�Destroy����EndDialog����ֹ����
};


#endif //__SAFEWINDOW_H__