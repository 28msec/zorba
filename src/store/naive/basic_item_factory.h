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
#ifndef ZORBA_SIMPLE_STORE_ITEM_FACTORY
#define ZORBA_SIMPLE_STORE_ITEM_FACTORY

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"


#include "common/shared_types.h"

#include "store/api/item_factory.h"


namespace zorba { namespace store {

class CopyMode;
class PUL;

typedef StringPool UriPool;


class BasicItemFactory : public ItemFactory
{
protected:
  UriPool    * theUriPool;
  QNamePool  * theQNamePool;

public:
  BasicItemFactory(UriPool* uriPool, QNamePool* qnPool);

  virtual ~BasicItemFactory();

  bool createQName(
        Item_t&                 result,
        const xqpStringStore_t& ns,
        const xqpStringStore_t& pre,
        const xqpStringStore_t& local);

  bool createQName(
        Item_t&     result,
        const char* ns,
        const char* pre,
        const char* ln);

  bool createNCName(Item_t& result, xqpStringStore_t& value);
        

  bool createAnyURI(Item_t& result, xqpStringStore_t& value);
  bool createAnyURI(Item_t& result, const char* value);

  bool createUntypedAtomic(Item_t& result, xqpStringStore_t& value);

  bool createString(Item_t& result, xqpStringStore_t& value);

  bool createBase64Binary(Item_t& result, xqp_base64Binary value);

  bool createBoolean(Item_t& result, xqp_boolean value);

  bool createDecimal(Item_t& result, xqp_decimal value);

  bool createInteger(Item_t& result, xqp_integer value);

  bool createLong(Item_t& result, xqp_long value);

  bool createInt(Item_t& result, xqp_int value);

  bool createShort(Item_t& result, xqp_short value);

  bool createByte(Item_t& result, xqp_byte value);

  bool createDate(Item_t& result, xqp_date& value);
  
  bool createDate(Item_t& result, short year, short month, short day);

  bool createDate(Item_t& result, const xqp_string& value);

  bool createDateTime(Item_t& result, xqp_dateTime& value);
 
  bool createDateTime(Item_t& result, short year, short month, short day, short hour, short minute, double second);

  bool createDateTime(Item_t& result, short year , short month, short day, short hour, short minute, double second, short timeZone_hours);

  bool createDateTime(Item_t& result, const xqp_string& value);
  
  bool createDateTime(Item_t& result, const Item_t&, const Item_t&);

  bool createDouble(Item_t& result, xqp_double value);

  bool createDuration(Item_t& result, xqp_duration& value);
  
  bool createDuration(Item_t& result, const xqp_string& value);

  bool createDuration(Item_t& result, short years, short months, short days, short hours, short minutes, double seconds);

  bool createENTITIES(Item_t& result, xqpStringStore_t& value);

  bool createENTITY(Item_t& result, xqpStringStore_t& value);

  bool createFloat(Item_t& result, xqp_float value);

  bool createGDay(Item_t& result, xqp_gDay& value);

  bool createGDay(Item_t& result, const xqp_string& value);

  bool createGDay(Item_t& result, short day);

  bool createGMonth(Item_t& result, xqp_gMonth& value);

  bool createGMonth(Item_t& result, const xqp_string& value);

  bool createGMonth(Item_t& result, short month);

  bool createGMonthDay (Item_t& result, xqp_gMonthDay& value);

  bool createGMonthDay (Item_t& result,  const xqp_string& value );

  bool createGMonthDay (Item_t& result,  short month, short day );

  bool createGYear (Item_t& result, xqp_gYear& value);
  
  bool createGYear (Item_t& result,  const xqp_string& value );

  bool createGYear (Item_t& result,  short year );

  bool createGYearMonth (Item_t& result, xqp_gYearMonth& value);

  bool createGYearMonth (Item_t& result,  const xqp_string& value );

  bool createGYearMonth (Item_t& result,  short year, short month );

  bool createHexBinary (Item_t& result,  xqp_hexBinary value );

  bool createID (Item_t& result, xqpStringStore_t& value );

  bool createIDREF (Item_t& result,  xqpStringStore_t& value );

  bool createIDREFS (Item_t& result,  xqpStringStore_t& value );

  bool createLanguage (Item_t& result,  xqpStringStore_t& value );

  bool createNMTOKEN (Item_t& result,  xqpStringStore_t& value );

  bool createNMTOKENS (Item_t& result,  xqpStringStore_t& value );

  bool createNOTATION (Item_t& result,  xqpStringStore_t& value );

  bool createName (Item_t& result,  xqpStringStore_t& value );

  bool createNegativeInteger (Item_t& result,  xqp_integer value );

  bool createNonNegativeInteger(Item_t& result, xqp_uinteger value );

  bool createNonPositiveInteger(Item_t& result, xqp_integer value );

  bool createNormalizedString(Item_t& result, xqpStringStore_t& value );

  bool createPositiveInteger(Item_t& result,  xqp_uinteger value );

  bool createTime(Item_t& result, xqp_time& value);
  
  bool createTime(Item_t& result, const xqp_string& value );

  bool createTime(Item_t& result, short hour, short minute, double second );

  bool createTime(Item_t& result, short hour, short minute, double second, short timeZone_hours);

  bool createToken(Item_t& result, xqpStringStore_t& value);

  bool createUnsignedByte(Item_t& result, xqp_ubyte value);

  bool createUnsignedInt(Item_t& result, xqp_uint value);

  bool createUnsignedLong(Item_t& result, xqp_ulong value);

  bool createUnsignedShort(Item_t& result, xqp_ushort value);



  bool createDocumentNode(
        Item_t&           result,
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri,
        bool              allowSharing = false);

  bool createElementNode(
        Item_t&           result,
        Item*             parent,
        long              pos,
        Item_t&           nodeName,
        Item_t&           typeName,
        const NsBindings& localBindings,
        xqpStringStore_t& baseURI,
        bool              allowSharing = false);

  bool createAttributeNode(
        Item_t&           result,
        Item*             parent,
        long              pos,
        Item_t&           nodeName,
        Item_t&           typeName,
        xqpStringStore_t& stringValue);

  bool createTextNode(
        Item_t&           result,
        Item*             parent,
        long              pos,
        xqpStringStore_t& content);

  bool createPiNode (
        Item_t&           result,
        Item*             parent,
        long              pos,
        xqpStringStore_t& target,
        xqpStringStore_t& content,
        xqpStringStore_t& baseUri);

  bool createCommentNode (
        Item_t&           result,
        Item*             parent,
        long              pos,
        xqpStringStore_t& content);


  PUL* createPendingUpdateList();
};

} // namespace store
} // namespace zorba

#endif
