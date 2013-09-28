/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   DirtyRectObjectParser
*   Author      :   ������
*   Create      :   2013-9-27 
*   LastChange  :   2013-9-27
*   History     :	
*
*   Description :   DirtyRectObject��xml���ý�����
*
********************************************************************/ 
#ifndef __DIRTYRECTOBJECTPARSER_H__
#define __DIRTYRECTOBJECTPARSER_H__

#include "./DirtyRectObject.h"

class DirtyRectObjectParser
	: public ExtObjParserImpl<DirtyRectObject>
{
public:
	DirtyRectObjectParser(void);
	virtual ~DirtyRectObjectParser(void);

private:

	// ExtObjParserImpl
	virtual bool ParserAttribute(DirtyRectObject* lpObj, const char* key, const char* value);
};

#endif // __DIRTYRECTOBJECTPARSER_H__