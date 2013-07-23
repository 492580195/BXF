/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2011              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   XLUETranscode
*   Author      :   ������
*   Create      :   2011-11-11 23:25
*   LastChange  :   2011-11-11 23:25
*   History     :	
*
*   Description :   ƽ̨�޹ص�ת��֧��
*
********************************************************************/ 
#ifndef __XLUETRANSCODE_H__
#define __XLUETRANSCODE_H__

#if defined(XLUE_WIN32)

#include "./Win32Transcode.h"
typedef Win32Transcode XLUETranscode;

#elif defined(XLUE_MAC)

#include "./PosixTranscode.h"
typedef PosixTranscode XLUETranscode;

#else
#error "platform macro not specified!!!"
#endif

#endif //__XLUETRANSCODE_H__