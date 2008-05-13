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
#ifndef ZORBA_XERCESPATHUTILS_H_
#define ZORBA_XERCESPATHUTILS_H_

#include "xercesIncludes.h"

#include <zorba/api_shared_types.h>
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
	static bool parseXSBoolean(const xqpStringStore_t& textValue, store::Item_t &result);

	//numeric types
	static bool parseXSInteger(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSPositiveInteger(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSNonPositiveInteger(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSNegativeInteger(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSNonNegativeInteger(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSUnsignedByte(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSUnsignedShort(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSUnsignedInt(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSUnsignedLong(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSByte(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSShort(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSInt(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSLong(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSFloat(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSDouble(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSDecimal(const xqpStringStore_t& textValue, store::Item_t &result);

	// string types
	static bool parseXSString(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSNormalizedString(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSToken(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSNMToken(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSName(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSNCName(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSID(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSIDRef(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSEntity(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSNotation(const xqpStringStore_t& textValue, store::Item_t &result);

	// date types
	static bool parseXSDateTime(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSDate(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSTime(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSGYearMonth(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSGYear(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSGMonthDay(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSGDay(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSGMonth(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSDuration(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSYearMonthDuration(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSDayTimeDuration(const xqpStringStore_t& textValue, store::Item_t &result);

	// other types
	static bool parseXSAnyAtomicType(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSUntypedAtomic(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSBase64Binary(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSHexBinary(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSAnyUri(const xqpStringStore_t& textValue, store::Item_t &result);
	static bool parseXSQName(const xqpStringStore_t& textValue, store::Item_t &result);

    // for user defined types see schema.h
};
} // namespace zorba
#endif /*ZORBA_XERCESPATHUTILS_H_*/
