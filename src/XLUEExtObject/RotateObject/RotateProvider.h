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
*   FileName    :   RotateProvider
*   Author      :   ������
*   Create      :   2013-8-1 
*   LastChange  :   2013-8-1
*   History     :	
*
*   Description :   ��ת�㷨��ʵ�֣��ɷ�ΪĬ�ϵ�ͼ�ο���ת�㷨��GDI+���㷨
*
********************************************************************/ 
#ifndef __ROTATEPROVIDER_H__
#define __ROTATEPROVIDER_H__

#include <XLGraphic.h>

enum RotateMode
{
	RotateMode_normal = 0,
	RotateMode_antialias = 1,
};

class IRotateProvider
{
public:
	virtual ~IRotateProvider()
	{}

	virtual bool Rotate(XL_BITMAP_HANDLE hBitmap, SIZE bmpSize, POINT ptCenter, double angel
		, RotateMode mode, unsigned char alpha, XLGraphicHint* lpHint) = 0;
};

class DefaultRotateProvider
	: public IRotateProvider
{
public:
	DefaultRotateProvider()
	{

	}

	virtual ~DefaultRotateProvider()
	{

	}

	virtual bool Rotate(XL_BITMAP_HANDLE hBitmap, SIZE bmpSize, POINT ptCenter, double angel
		, RotateMode mode, unsigned char alpha, XLGraphicHint* lpHint);
};

#endif // __ROTATEPROVIDER_H__