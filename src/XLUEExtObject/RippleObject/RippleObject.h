/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   RippleObject
*   Author      :   ������
*   Create      :   2013-5-28
*   LastChange  :   2013-5-28
*   History     :	
*
*   Description :   ˮ������������������Ⱦ���󣬼������У�����ö����������LayerObject
*					ʹ�ã����ܻ���ĳЩ�����ˮ���г�������Ч��
*					Ŀǰʹ�õ��㷨�ǻ���ÿ��ˮ��һ��RippleItem�ķ������ڶ������н���ˮ��ʱ��Ч�ʽϸߣ�
*					����������ϴ��ڽ϶�ˮ�Σ�����ˮ�ܶȽ�С����ôЧ�ʻ�ܵͣ��Ժ����������ˮ���������
********************************************************************/ 
#ifndef __RIPPLEOBJECT_H__
#define __RIPPLEOBJECT_H__

#include "./RippleItem.h"
#include <vector>

class RippleObject
	: public ExtLayoutObjMethodsImpl
{
private:

	struct RippleHolder
	{
		RippleItem* lpRippleItem;
		RECT pos;
	};

public:
	RippleObject(XLUE_LAYOUTOBJ_HANDLE hObj);
	virtual ~RippleObject(void);

	void SetMouseDrop(bool enable);
	bool GetMouseDrop();

	void SetRandomDrop(bool enable);
	bool GetRandomDrop();

	void SetDropDensity(unsigned long density);
	unsigned long GetDropDensity();

	void SetUpdateInterval(unsigned long interval);
	unsigned long GetUpdateInterval();

	void SetWaterDensity(unsigned long density);
	unsigned long GetWaterDensity();

	void ClearAllDrops();

private:

	// LayoutObject virtual funcs
	virtual void OnInitControl();
	virtual void OnDestroy();

	virtual void OnPaint(XL_BITMAP_HANDLE /*hBitmapDest*/, const RECT* /*lpDestClipRect*/, const RECT* /*lpSrcClipRect*/, unsigned char /*alpha*/);

	virtual bool CanHandleInput();
	virtual long PostInputFilter(unsigned long actionType, unsigned long /*wParam*/, unsigned long /*lParam*/, BOOL* lpHandled);

private:

	// Timer
	void OnTimer(unsigned int timerID);

private:

	void StartUpdateTimer();
	void KillUpdateTimer();

	void StartRandomDropTimer();
	void KillRandomDropTimer();

	void GenerateRandomDrops();
	void UpdateAllRipple();

	bool GenerateRipple(RippleHolder& holder, short radius, short height, long x = LONG_MAX, long y = LONG_MAX);

private:

	// �Ƿ���������Ϣ������ˮ��
	bool m_mouseDrop;

	// �Ƿ��������ˮ��
	bool m_randomdrop;

	// ���ˮ��ʱ������Ĭ��Ϊ1s
	unsigned long m_randomDropInterval;

	// ˮ��֡�����Ĭ��Ϊ50ms����СΪ30ms
	unsigned long m_updateInterval;

	// ���ˮ������timer
	unsigned long m_randomDropTimerID;

	// ˮ��֡�������timer
	unsigned long m_updateTimerID;

	// ���ˮ���ܶȣ�Ϊÿ5sʱ�����ڣ����������ˮ�θ���
	unsigned long m_dropDensity;

	// ˮ�����ģʽ
	bool m_fineMode;

	// ˥�����ӣ�Ϊ������ⶨ��Ϊˮ�ܶ�
	char m_waterDensity;

	typedef MemberTimerManagerWrapperT<RippleObject> RippleMemberTimerManager;
	RippleMemberTimerManager m_timerManager;

	// ��ǰ�����С�ˮ�Ρ�
	typedef std::vector<RippleHolder> vtRippleItems;
	vtRippleItems m_rippleItems;
};

#endif // __RIPPLEOBJECT_H__