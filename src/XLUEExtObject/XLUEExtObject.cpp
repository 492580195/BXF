// XLUEExtObject.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "./XLUEExtObject.h"
#include <XLUE.h>
#include "./MagicObject/MagicObjectRegister.h"
#include <assert.h>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

// ��չģ���ʼ�ص���ÿ����չģ�鱻����ʱ�����øýӿ�
BOOL XLUE_STDCALL XLUE_InitExtModule()
{
	//TODO
	return TRUE;
}

BOOL XLUE_STDCALL XLUE_UninitExtModule()
{
	//TODO
	return TRUE;
}

BOOL XLUE_STDCALL XLUE_RegisterObj( const char* lpObjClass )
{
	assert(lpObjClass);

	BOOL ret = FALSE;

	if (strcmp(lpObjClass, "MagicObject") == 0)
	{
		ret = MagicObjectRegister::RegisterMagicObject();
	}
	else
	{
		assert(false);
	}

	return ret;
}