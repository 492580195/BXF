/********************************************************************
/* Copyright (c) 2013 The BOLT UIEngine. All rights reserved.
/* Use of this source code is governed by a BOLT license that can be
/* found in the LICENSE file.
********************************************************************/ 
#include "stdafx.h"
#include "./LuaBaseFunctor.h"
#include "./LuaJavascriptFunctor.h"
#include "../WebKernel/DBG.h"
#include <sstream>

LuaJavascriptFunctor::LuaJavascriptFunctor(std::wstring functionName, lua_State* luaState, long luaRef )
:BaseLuaListener(luaState, luaRef)
,m_functionName(functionName)
{

}

CefRefPtr<CefDictionaryValue> LuaJavascriptFunctor::operator()(CefRefPtr<CefDictionaryValue> dictionaryValue)
{
	// ����ջ��
	LuaStackKeeper luaState(m_luaState);


	// ��ȡLua����������ջ
	BaseLuaListener::PushLuaFunction();

	// �ֵ������ջ
	WebKernelLuaHelper::PushCefDictionaryValue(luaState,dictionaryValue);

	// ����Lua����
	int nRet = BaseLuaListener::Call(1, 1,m_functionName.c_str());
	
	// ��ȡ����ֵ�ֵ�
	CefRefPtr<CefDictionaryValue> result = CefDictionaryValue::Create();
	if (nRet == 0)
	{
		result = WebKernelLuaHelper::ToCefDictionaryValue(luaState,-1);
	}

	return result;
}


LuaJavascriptCallbackFunctor::LuaJavascriptCallbackFunctor(std::wstring functionName, lua_State* luaState, long luaRef )
:BaseLuaListener(luaState, luaRef)
,m_functionName(functionName)
{

}

bool LuaJavascriptCallbackFunctor::operator()(CefRefPtr<CefDictionaryValue> dictionaryValue)
{
	// ����ջ��
	LuaStackKeeper luaState(m_luaState);


	// ��ȡLua����������ջ
	BaseLuaListener::PushLuaFunction();

	// �ֵ������ջ
	WebKernelLuaHelper::PushCefDictionaryValue(luaState,dictionaryValue);

	// ����Lua����
	int nRet = BaseLuaListener::Call(1, 1,m_functionName.c_str());

	// ��ȡ����ֵ�ֵ�
	if (nRet == 0)
	{
		return true;
	}

	return false;
}
