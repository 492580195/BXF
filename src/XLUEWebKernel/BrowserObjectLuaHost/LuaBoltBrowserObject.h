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
*   FileName    :   LuaBoltBrowserObject
*   Author      :   ������
*   Create      :   2013-7-4 
*   LastChange  :   2013-7-4
*   History     :	
*
*   Description :   BoltBrowserObject��lua��װ
*
********************************************************************/ 
#ifndef __LUABOLTBROWSEROBJECT_H__
#define __LUABOLTBROWSEROBJECT_H__

#include "../BrowserObject/BoltBrowserObject.h"
#include "./LuaBaseBoltBrowserObject.h"

class LuaBoltBrowserObject
	: public LuaBaseBoltBrowserObject
{
public:
	LuaBoltBrowserObject(void);
	virtual ~LuaBoltBrowserObject(void);

private:

	// LuaBaseBoltBrowserObject
	virtual const XLLRTGlobalAPI* GetChildLuaAPIs();

private:

	static const XLLRTGlobalAPI s_szLuaMemberFuncs[];
};

#endif // __LUABOLTBROWSEROBJECT_H__