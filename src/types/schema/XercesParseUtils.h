/*
 *	Copyright 2006-2008 FLWOR Foundation.
 *  Author: Cezar Andrei (cezar dot andrei at gmail dot com)
 *
 */
#ifndef XERCESPATHUTILS_H_
#define XERCESPATHUTILS_H_

#include "xercesIncludes.h"

#include <zorba/api_shared_types.h>
//#include <zorba/rchandle.h>
#include "util/rchandle.h"
#include <zorba/item.h>
#include "common/shared_types.h"
#include "types/typeconstants.h"


namespace zorba
{

class XercesParseUtils;

class XercesParseUtils
{
public:
	static bool parseXSBoolean(xqpString textValue, store::Item_t &result);

	//numeric types
	static bool parseXSInteger(xqpString textValue, store::Item_t &result);
	static bool parseXSPositiveInteger(xqpString textValue, store::Item_t &result);
	static bool parseXSNonPositiveInteger(xqpString textValue, store::Item_t &result);
	static bool parseXSNegativeInteger(xqpString textValue, store::Item_t &result);
	static bool parseXSNonNegativeInteger(xqpString textValue, store::Item_t &result);
	static bool parseXSUnsignedByte(xqpString textValue, store::Item_t &result);
	static bool parseXSUnsignedShort(xqpString textValue, store::Item_t &result);
	static bool parseXSUnsignedInt(xqpString textValue, store::Item_t &result);
	static bool parseXSUnsignedLong(xqpString textValue, store::Item_t &result);
	static bool parseXSByte(xqpString textValue, store::Item_t &result);
	static bool parseXSShort(xqpString textValue, store::Item_t &result);
	static bool parseXSInt(xqpString textValue, store::Item_t &result);
	static bool parseXSLong(xqpString textValue, store::Item_t &result);
	static bool parseXSFloat(xqpString textValue, store::Item_t &result);
	static bool parseXSDouble(xqpString textValue, store::Item_t &result);
	static bool parseXSDecimal(xqpString textValue, store::Item_t &result);

	// string types
	static bool parseXSString(xqpString textValue, store::Item_t &result);
	static bool parseXSNormalizedString(xqpString textValue, store::Item_t &result);
	static bool parseXSToken(xqpString textValue, store::Item_t &result);
	static bool parseXSNMToken(xqpString textValue, store::Item_t &result);
	static bool parseXSName(xqpString textValue, store::Item_t &result);
	static bool parseXSNCName(xqpString textValue, store::Item_t &result);
	static bool parseXSID(xqpString textValue, store::Item_t &result);
	static bool parseXSIDRef(xqpString textValue, store::Item_t &result);
	static bool parseXSEntity(xqpString textValue, store::Item_t &result);
	static bool parseXSNotation(xqpString textValue, store::Item_t &result);

	// date types
	static bool parseXSDateTime(xqpString textValue, store::Item_t &result);
	static bool parseXSDate(xqpString textValue, store::Item_t &result);
	static bool parseXSTime(xqpString textValue, store::Item_t &result);
	static bool parseXSGYearMonth(xqpString textValue, store::Item_t &result);
	static bool parseXSGYear(xqpString textValue, store::Item_t &result);
	static bool parseXSGMonthDay(xqpString textValue, store::Item_t &result);
	static bool parseXSGDay(xqpString textValue, store::Item_t &result);
	static bool parseXSGMonth(xqpString textValue, store::Item_t &result);
	static bool parseXSDuration(xqpString textValue, store::Item_t &result);
	static bool parseXSYearMonthDuration(xqpString textValue, store::Item_t &result);
	static bool parseXSDayTimeDuration(xqpString textValue, store::Item_t &result);

	// other types
	static bool parseXSAnyAtomicType(xqpString textValue, store::Item_t &result);
	static bool parseXSUntypedAtomic(xqpString textValue, store::Item_t &result);
	static bool parseXSBase64Binary(xqpString textValue, store::Item_t &result);
	static bool parseXSHexBinary(xqpString textValue, store::Item_t &result);
	static bool parseXSAnyUri(xqpString textValue, store::Item_t &result);
	static bool parseXSQName(xqpString textValue, store::Item_t &result);

};
} // namespace zorba
#endif /*XERCESPATHUTILS_H_*/
