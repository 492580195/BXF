/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   MagicObjectParser
*   Author      :   ������
*   Create      :   2013-5-20 0:32
*   LastChange  :   2013-5-20 0:32
*   History     :	
*
*   Description :   MagicObject��xml���������
*
********************************************************************/ 
#ifndef __MAGICOBJECTPARSER_H__
#define __MAGICOBJECTPARSER_H__

#include "./MagicObject.h"

class MagicObjectParser
	: public ExtObjParserImpl<MagicObject>
{
public:
	MagicObjectParser(void);
	virtual ~MagicObjectParser(void);

public:

	// ExtObjParserImpl
	virtual BOOL ParserAttribute(MagicObject* lpObj, const char* key, const char* value);
};

#endif // __MAGICOBJECTPARSER_H__