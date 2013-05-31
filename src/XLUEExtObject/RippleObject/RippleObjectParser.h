/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   RippleObjectParser
*   Author      :   ������
*   Create      :   2013-5-28
*   LastChange  :   2013-5-28
*   History     :	
*
*   Description :   RippleObejct��xml������
*
********************************************************************/ 
#ifndef __RIPPLEOBJECTPARSER_H__
#define __RIPPLEOBJECTPARSER_H__

#include "./RippleObject.h"

class RippleObjectParser
	: public ExtObjParserImpl<RippleObject>
{
public:
	RippleObjectParser(void);
	virtual ~RippleObjectParser(void);

private:

	// ExtObjParserImpl
	virtual BOOL ParserAttribute(RippleObject* lpObj, const char* key, const char* value);
};

#endif // __RIPPLEOBJECTPARSER_H__