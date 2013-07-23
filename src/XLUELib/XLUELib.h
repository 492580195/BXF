/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   XLUELib
*   Author      :   ������
*   Create      :   2013-6-28 
*   LastChange  :   2013-6-28
*   History     :	
*
*   Description :   XLUELib��ȫ��ͷ�ļ��������˳��õ�XLUELibͷ�ļ�
*
********************************************************************/ 
#ifndef __XLUELIB_H__
#define __XLUELIB_H__

#if defined(WIN32)
	#define XLUE_WIN32
#elif defined(__APPLE__)
	#include <TargetConditionals.h>
	#if defined(TARGET_OS_MAC)
		#define XLUE_MAC
	#else
		#error "unknown apple platform!"
	#endif
#else
	#error "unknown platform!"
#endif

#include "./lua/LuaEvent.h"
#include "./lua/LuaHelper.h"
#include "./Transcode/XLUETranscode.h"

using namespace Xunlei::XAF;

#endif // __XLUELIB_H__