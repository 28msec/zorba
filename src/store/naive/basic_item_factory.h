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


namespace zorba 
{

namespace store
{
  class CopyMode;
  class PUL;
}


namespace simplestore 
{

typedef StringPool UriPool;


class BasicItemFactory : public store::ItemFactory
{
protected:
  UriPool    * theUriPool;
  QNamePool  * theQNamePool;

public:
  BasicItemFactory(UriPool* uriPool, QNamePool* qnPool);

  virtual ~BasicItemFactory();

  bool createQName(
        store::Item_t&          result,
        const xqpStringStore_t& ns,
        const xqpStringStore_t& pre,
        const xqpStringStore_t& local);

  bool createQName(
        store::Item_t& result,
        const char*    ns,
        const char*    pre,
        const char*    ln);

  bool createNCName(store::Item_t& result, xqpStringStore_t& value);
        

  bool createAnyURI(store::Item_t& result, xqpStringStore_t& value);
  bool createAnyURI(store::Item_t& result, const char* value);

  bool createUntypedAtomic(store::Item_t& result, xqpStringStore_t& value);

  bool createString(store::Item_t& result, xqpStringStore_t& value);

  bool createBase64Binary(store::Item_t& result, xqp_base64Binary value);

  bool createBoolean(store::Item_t& result, xqp_boolean value);

  bool createDecimal(store::Item_t& result, xqp_decimal value);

  bool createInteger(store::Item_t& result, xqp_integer value);

  bool createLong(store::Item_t& result, xqp_long value);

  bool createInt(store::Item_t& result, xqp_int value);

  bool createShort(store::Item_t& result, xqp_short value);

  bool createByte(store::Item_t& result, xqp_byte value);


  bool createDateTime(store::Item_t& result, const xqp_dateTime* value);
 
  bool createDateTime(store::Item_t& result, short year, short month, short day, short hour, short minute, double second);

  bool createDateTime(store::Item_t& result, short year , short month, short day, short hour, short minute, double second, short timeZone_hours);

  bool createDateTime(store::Item_t& result, const xqp_string& value);
  
  bool createDateTime(store::Item_t& result, const store::Item_t&, const store::Item_t&);

  bool createDate(store::Item_t& result, const xqp_date* value);
  
  bool createDate(store::Item_t& result, short year, short month, short day);

  bool createDate(store::Item_t& result, const xqp_string& value);

  bool createTime(store::Item_t& result, const xqp_time* value);
  
  bool createTime(store::Item_t& result, const xqp_string& value );

  bool createTime(store::Item_t& result, short hour, short minute, double second );

  bool createTime(store::Item_t& result, short hour, short minute, double second, short timeZone_hours);

  bool createGDay(store::Item_t& result, const xqp_gDay* value);

  bool createGDay(store::Item_t& result, const xqp_string& value);

  bool createGDay(store::Item_t& result, short day);

  bool createGMonth(store::Item_t& result, const xqp_gMonth* value);

  bool createGMonth(store::Item_t& result, const xqp_string& value);

  bool createGMonth(store::Item_t& result, short month);

  bool createGMonthDay (store::Item_t& result, const xqp_gMonthDay* value);

  bool createGMonthDay (store::Item_t& result,  const xqp_string& value );

  bool createGMonthDay (store::Item_t& result,  short month, short day );

  bool createGYear (store::Item_t& result, const xqp_gYear* value);
  
  bool createGYear (store::Item_t& result,  const xqp_string& value );

  bool createGYear (store::Item_t& result,  short year );

  bool createGYearMonth (store::Item_t& result, const xqp_gYearMonth* value);

  bool createGYearMonth (store::Item_t& result,  const xqp_string& value );

  bool createGYearMonth (store::Item_t& result,  short year, short month );


  bool createDouble(store::Item_t& result, xqp_double value);

  bool createDuration(store::Item_t& result, xqp_duration& value);
  
  bool createDuration(store::Item_t& result, const xqp_string& value);

  bool createDuration(store::Item_t& result, short years, short months, short days, short hours, short minutes, double seconds);

  bool createENTITIES(store::Item_t& result, xqpStringStore_t& value);

  bool createENTITY(store::Item_t& result, xqpStringStore_t& value);

  bool createFloat(store::Item_t& result, xqp_float value);

  bool createHexBinary (store::Item_t& result,  xqp_hexBinary value );

  bool createID (store::Item_t& result, xqpStringStore_t& value );

  bool createIDREF (store::Item_t& result,  xqpStringStore_t& value );

  bool createIDREFS (store::Item_t& result,  xqpStringStore_t& value );

  bool createLanguage (store::Item_t& result,  xqpStringStore_t& value );

  bool createNMTOKEN (store::Item_t& result,  xqpStringStore_t& value );

  bool createNMTOKENS (store::Item_t& result,  xqpStringStore_t& value );

  bool createNOTATION (store::Item_t& result,  xqpStringStore_t& value );

  bool createName (store::Item_t& result,  xqpStringStore_t& value );

  bool createNegativeInteger (store::Item_t& result,  xqp_integer value );

  bool createNonNegativeInteger(store::Item_t& result, xqp_uinteger value );

  bool createNonPositiveInteger(store::Item_t& result, xqp_integer value );

  bool createNormalizedString(store::Item_t& result, xqpStringStore_t& value );

  bool createPositiveInteger(store::Item_t& result,  xqp_uinteger value );

  bool createToken(store::Item_t& result, xqpStringStore_t& value);

  bool createUnsignedByte(store::Item_t& result, xqp_ubyte value);

  bool createUnsignedInt(store::Item_t& result, xqp_uint value);

  bool createUnsignedLong(store::Item_t& result, xqp_ulong value);

  bool createUnsignedShort(store::Item_t& result, xqp_ushort value);



  bool createDocumentNode(
        store::Item_t&    result,
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri,
        bool              allowSharing = false);

  bool createElementNode(
        store::Item_t&           result,
        store::Item*             parent,
        long                     pos,
        store::Item_t&           nodeName,
        store::Item_t&           typeName,
        const store::NsBindings& localBindings,
        xqpStringStore_t&        baseURI,
        bool                     allowSharing = false);

  bool createAttributeNode(
        store::Item_t&    result,
        store::Item*      parent,
        long              pos,
        store::Item_t&    nodeName,
        store::Item_t&    typeName,
        xqpStringStore_t& stringValue);

  bool createTextNode(
        store::Item_t&    result,
        store::Item*      parent,
        long              pos,
        xqpStringStore_t& content);

  bool createPiNode (
        store::Item_t&    result,
        store::Item*      parent,
        long              pos,
        xqpStringStore_t& target,
        xqpStringStore_t& content,
        xqpStringStore_t& baseUri);

  bool createCommentNode (
        store::Item_t&   result,
        store::Item*     parent,
        long              pos,
        xqpStringStore_t& content);


  store::PUL* createPendingUpdateList();
};

} // namespace store
} // namespace zorba

#endif
