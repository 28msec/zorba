/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#ifndef ZORBA_XERCESPATHUTILS_H_
#define ZORBA_XERCESPATHUTILS_H_


#include <zorba/api_shared_types.h>
#include <zorba/item.h>
#include "common/shared_types.h"
#include "types/typeconstants.h"


namespace zorba
{

class XercesParseUtils;

class XercesParseUtils
{
public:
	static bool parseXSBoolean(const zstring& textValue, store::Item_t &result);

	//numeric types
	static bool parseXSInteger(const zstring& textValue, store::Item_t &result);
	static bool parseXSPositiveInteger(const zstring& textValue, store::Item_t &result);
	static bool parseXSNonPositiveInteger(const zstring& textValue, store::Item_t &result);
	static bool parseXSNegativeInteger(const zstring& textValue, store::Item_t &result);
	static bool parseXSNonNegativeInteger(const zstring& textValue, store::Item_t &result);
	static bool parseXSUnsignedByte(const zstring& textValue, store::Item_t &result);
	static bool parseXSUnsignedShort(const zstring& textValue, store::Item_t &result);
	static bool parseXSUnsignedInt(const zstring& textValue, store::Item_t &result);
	static bool parseXSUnsignedLong(const zstring& textValue, store::Item_t &result);
	static bool parseXSByte(const zstring& textValue, store::Item_t &result);
	static bool parseXSShort(const zstring& textValue, store::Item_t &result);
	static bool parseXSInt(const zstring& textValue, store::Item_t &result);
	static bool parseXSLong(const zstring& textValue, store::Item_t &result);
	static bool parseXSFloat(const zstring& textValue, store::Item_t &result);
	static bool parseXSDouble(const zstring& textValue, store::Item_t &result);
	static bool parseXSDecimal(const zstring& textValue, store::Item_t &result);

	// string types
	static bool parseXSString(const zstring& textValue, store::Item_t &result);
	static bool parseXSNormalizedString(const zstring& textValue, store::Item_t &result);
	static bool parseXSToken(const zstring& textValue, store::Item_t &result);
	static bool parseXSNMToken(const zstring& textValue, store::Item_t &result);
	static bool parseXSName(const zstring& textValue, store::Item_t &result);
	static bool parseXSNCName(const zstring& textValue, store::Item_t &result);
	static bool parseXSID(const zstring& textValue, store::Item_t &result);
	static bool parseXSIDRef(const zstring& textValue, store::Item_t &result);
	static bool parseXSEntity(const zstring& textValue, store::Item_t &result);
	static bool parseXSNotation(const zstring& textValue, store::Item_t &result);

	// date types
	static bool parseXSDateTime(const zstring& textValue, store::Item_t &result);
	static bool parseXSDate(const zstring& textValue, store::Item_t &result);
	static bool parseXSTime(const zstring& textValue, store::Item_t &result);
	static bool parseXSGYearMonth(const zstring& textValue, store::Item_t &result);
	static bool parseXSGYear(const zstring& textValue, store::Item_t &result);
	static bool parseXSGMonthDay(const zstring& textValue, store::Item_t &result);
	static bool parseXSGDay(const zstring& textValue, store::Item_t &result);
	static bool parseXSGMonth(const zstring& textValue, store::Item_t &result);
	static bool parseXSDuration(const zstring& textValue, store::Item_t &result);
	static bool parseXSYearMonthDuration(const zstring& textValue, store::Item_t &result);
	static bool parseXSDayTimeDuration(const zstring& textValue, store::Item_t &result);

	// other types
	static bool parseXSAnyAtomicType(const zstring& textValue, store::Item_t &result);
	static bool parseXSUntypedAtomic(const zstring& textValue, store::Item_t &result);
	static bool parseXSBase64Binary(const zstring& textValue, store::Item_t &result);
	static bool parseXSHexBinary(const zstring& textValue, store::Item_t &result);
	static bool parseXSAnyUri(const zstring& textValue, store::Item_t &result);
	static bool parseXSQName(const zstring& textValue, store::Item_t &result);

    // for user defined types see schema.h
};
} // namespace zorba
#endif /*ZORBA_XERCESPATHUTILS_H_*/
/* vim:set et sw=2 ts=2: */
