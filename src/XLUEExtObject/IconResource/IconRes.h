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
*   FileName    :   IconRes
*   Author      :   ������
*   Create      :   2013-7-29 
*   LastChange  :   2013-7-29
*   History     :	
*
*   Description :   ICON��չ��Դ����
*
********************************************************************/ 
#ifndef __ICONRES_H__
#define __ICONRES_H__

#include <bxf/ExtResourceImpl.h>
#include <XLGraphicPlus.h>

#define XLUE_EXTRES_ICON "icon"

class IconRes
	: public ExtResourceMethodsImpl
{
public:

	enum IconSourceType
	{
		IconSourceType_unknown = 0,
		IconSourceType_file = 1,
		IconSourceType_module = 2,
		IconSourceType_ext = 3,
	};

	typedef ExtResourceMethodsImpl base_class;

public:
	IconRes(XLUE_RESOURCE_HANDLE hResHandle);
	~IconRes(void);

	void SetModule(const char* lpModule);
	void SetFile(const char* lpFile);
	void SetExt(const char* lpExt);
	void SetWidth(int cx);
	void SetHeight(int cy);
	void SetIconIndex(int index);

	// ����ֵ�����������ü���
	XLGP_ICON_HANDLE GetIconHandle();

private:

	// ExtResourceMethodsImpl
	virtual bool LoadRes(const wchar_t* lpResFolder);
	virtual bool FreeRes();

	// ����ֵ�����������ü�������
	virtual void* GetRealHandle();

	// ������Դ������������ڻ������ü�������
	virtual long AddRefRealHandle(void* /*lpRealHandle*/);
	virtual long ReleaseRealHandle(void* /*lpRealHandle*/);

private:

	bool LoadImpl(const wchar_t* lpResFolder);
	void FreeImpl();

private:

	bool m_resLoaded;
	XLGP_ICON_HANDLE m_iconHandle;

	IconSourceType m_sourceType;
	std::string m_iconFile;
	int m_iconIndex;
	int m_cx, m_cy;

	std::wstring m_resFolder;
};

#endif // __ICONRES_H__