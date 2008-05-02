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
#ifndef ZORBA_MINIMAL_STORE_ITEM_FACTORY
#define ZORBA_MINIMAL_STORE_ITEM_FACTORY

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"


#include "common/shared_types.h"

#include "store/api/item_factory.h"


namespace zorba { 
  namespace store {

class CopyMode;
  class PUL;

//typedef StringPool UriPool;


class BasicItemFactory : public ItemFactory
{
protected:
//  UriPool    * theUriPool;
//  QNamePool  * theQNamePool;

public:
//  BasicItemFactory(UriPool* uriPool, QNamePool* qnPool);
  BasicItemFactory();

  virtual ~BasicItemFactory();

  Item_t createQName(
        xqpStringStore* ns,
        xqpStringStore* pre,
        xqpStringStore* local,
        bool*           inserted = 0 );

  Item_t createQName(
        const char* ns,
        const char* pre,
        const char* ln);

  Item_t createNCName(xqpStringStore_t& value);

  Item_t createAnyURI(xqpStringStore_t& value);
  Item_t createAnyURI(const char* value);

  Item_t createUntypedAtomic(xqpStringStore_t& value);

  Item_t createString(xqpStringStore_t& value);

  Item_t createBase64Binary(xqp_base64Binary value);

  Item_t createBoolean(xqp_boolean value);

  Item_t createDecimal(xqp_decimal value);

  Item_t createInteger(xqp_integer value);

  Item_t createLong(xqp_long value);

  Item_t createInt(xqp_int value);

  Item_t createShort(xqp_short value);

  Item_t createByte(xqp_byte value);

  Item_t createDate(xqp_date& value);
  
  Item_t createDate(short year, short month, short day);

  Item_t createDate(const xqp_string& value);

  Item_t createDateTime(xqp_dateTime& value);
 
  Item_t createDateTime(short year, short month, short day, short hour, short minute, double second);

  Item_t createDateTime(short year , short month, short day, short hour, short minute, double second, short timeZone_hours);

  Item_t createDateTime(const xqp_string& value);
  
  Item_t createDateTime(const Item_t&, const Item_t&);

  Item_t createDouble(xqp_double value);

  Item_t createDuration(xqp_duration& value);
  
  Item_t createDuration(const xqp_string& value);

  Item_t createDuration(short years, short months, short days, short hours, short minutes, double seconds);

  Item_t createENTITIES (xqpStringStore_t& value );

  Item_t createENTITY (xqpStringStore_t& value );

  Item_t createFloat ( xqp_float value );

  Item_t createGDay (xqp_gDay& value );

  Item_t createGDay ( const xqp_string& value );

  Item_t createGDay ( short day );

  Item_t createGMonth (xqp_gMonth& value);

  Item_t createGMonth ( const xqp_string& value );

  Item_t createGMonth ( short month );

  Item_t createGMonthDay (xqp_gMonthDay& value);

  Item_t createGMonthDay ( const xqp_string& value );

  Item_t createGMonthDay ( short month, short day );

  Item_t createGYear (xqp_gYear& value);
  
  Item_t createGYear ( const xqp_string& value );

  Item_t createGYear ( short year );

  Item_t createGYearMonth (xqp_gYearMonth& value);

  Item_t createGYearMonth ( const xqp_string& value );

  Item_t createGYearMonth ( short year, short month );

  Item_t createHexBinary ( xqp_hexBinary value );

  Item_t createID (xqpStringStore_t& value );

  Item_t createIDREF ( xqpStringStore_t& value );

  Item_t createIDREFS ( xqpStringStore_t& value );

  Item_t createLanguage ( xqpStringStore_t& value );

  Item_t createNMTOKEN ( xqpStringStore_t& value );

  Item_t createNMTOKENS ( xqpStringStore_t& value );

  Item_t createNOTATION ( xqpStringStore_t& value );

  Item_t createName ( xqpStringStore_t& value );

  Item_t createNegativeInteger ( xqp_integer value );

  Item_t createNonNegativeInteger(xqp_uinteger value );

  Item_t createNonPositiveInteger(xqp_integer value );

  Item_t createNormalizedString(xqpStringStore_t& value );

  Item_t createPositiveInteger( xqp_uinteger value );

  Item_t createTime(xqp_time& value);
  
  Item_t createTime(const xqp_string& value );

  Item_t createTime(short hour, short minute, double second );

  Item_t createTime(short hour, short minute, double second, short timeZone_hours);

  Item_t createToken(xqpStringStore_t& value);

  Item_t createUnsignedByte(xqp_ubyte value);

  Item_t createUnsignedInt(xqp_uint value);

  Item_t createUnsignedLong(xqp_ulong value);

  Item_t createUnsignedShort(xqp_ushort value);



  Item_t createDocumentNode(
        ulong             qid,
        xqpStringStore_t& baseURI,
        Iterator*         children,
        bool              isRoot,
        bool              assignIds,
        bool              copy,
        const CopyMode&   copymode);

  Item_t createElementNode(
        ulong             qid,
        Item_t&           name,
        Item_t&           type,
        Iterator*         childrenIte,
        Iterator*         attributesIte,
        Iterator*         namespacesIte,
        const NsBindings& localBindings,
        xqpStringStore_t& baseURI,
        bool              isRoot,
        bool              assignIds,
        bool              copy,
        const CopyMode&   copymode);

  Item_t createAttributeNode(
        ulong     qid,
        Iterator* nameIter,
        Item_t&   typeName,
        Iterator* valueIter,
        bool      isRoot,
        bool      assignIds);

  Item_t createTextNode(
        ulong           qid,
        Iterator*       valueIter,
        bool            isRoot,
        bool            assignIds);

  Item_t createTextNode(
        ulong             qid,
        xqpStringStore_t& content,
        bool              isRoot,
        bool              assignIds);

  Item_t createPiNode (
        ulong             qid,
        xqpStringStore_t& target,
        xqpStringStore_t& content,
        bool              isRoot,
        bool              assignIds);

  Item_t createCommentNode (
        ulong             qid,
        xqpStringStore_t& content,
        bool              isRoot,
        bool              assignIds);

  PUL* createPendingUpdateList();
};

} // namespace store
} // namespace zorba

#endif
