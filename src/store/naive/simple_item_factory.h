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

#include <iostream>

#include "shared_types.h"

#include "store/api/item_factory.h"
//#include "store/api/tuples.h"

#include "zorbatypes/schema_types.h"

#include "tree_id.h"

namespace zorba
{

namespace store
{
  class PUL;
}


namespace simplestore
{

class StringPool;
typedef StringPool UriPool;
class QNamePool;
class OrdPath;


class BasicItemFactory : public store::ItemFactory
{
protected:
  UriPool    * theUriPool;
  QNamePool  * theQNamePool;

  // boolean items
  // we don't need to create more than two, hence
  // they are cached here. createBoolean always
  // returns one of them
  store::Item_t theTrueItem;
  store::Item_t theFalseItem;
#ifdef ZORBA_WITH_JSON
  store::Item_t theNullItem;
#endif

public:
  BasicItemFactory(UriPool* uriPool, QNamePool* qnPool);

  virtual ~BasicItemFactory();

  bool createUserTypedAtomicItem(
        store::Item_t& result,
        store::Item_t& baseItem,
        store::Item_t& typeName);

  bool createQName(
        store::Item_t& result,
        const zstring& ns,
        const zstring& pre,
        const zstring& local);

  bool createQName(
        store::Item_t& result,
        const char*  ns,
        const char*  pre,
        const char*  ln);

  bool createNCName(store::Item_t& result, zstring& value);


  bool createAnyURI(store::Item_t& result, zstring& value);

  bool createAnyURI(store::Item_t& result, const char* value);

  bool createStructuralAnyURI(store::Item_t& result, zstring& value);

  bool createStructuralAnyURI(
      store::Item_t& result,
      ulong collectionId,
      const TreeId& treeId,
      store::StoreConsts::NodeKind nodeKind,
      const OrdPath& ordPath);

  bool createUntypedAtomic(store::Item_t& result, zstring& value);

  bool createString(store::Item_t& result, zstring& value);

  bool createStreamableString(
      store::Item_t& result,
      std::istream&,
      StreamReleaser,
      bool seekable = false);

  bool createSharedStreamableString(
      store::Item_t& result,
      store::Item_t& streamable_dependent);

  bool createBase64Binary(store::Item_t& result, xs_base64Binary value);

  bool createBase64Binary(
      store::Item_t& result,
      const char* value,
      size_t size,
      bool encoded);

  bool createStreamableBase64Binary(
      store::Item_t& result,
      std::istream&,
      StreamReleaser,
      bool seekable = false,
      bool encoded = false);

  bool createBoolean(store::Item_t& result, xs_boolean value);


  bool createDouble(store::Item_t& result, const xs_double& value);

  bool createFloat(store::Item_t& result, const xs_float& value);

  bool createDecimal(store::Item_t& result, const xs_decimal& value);

  bool createInteger(store::Item_t& result, const xs_integer& value);

  bool createNonNegativeInteger(store::Item_t& result, const xs_nonNegativeInteger& value);

  bool createPositiveInteger(store::Item_t& result,  const xs_positiveInteger& value );

  bool createNonPositiveInteger(store::Item_t& result, const xs_integer& value);

  bool createNegativeInteger(store::Item_t& result,  const xs_integer& value);

  bool createLong(store::Item_t& result, xs_long value);

  bool createInt(store::Item_t& result, xs_int value);

  bool createShort(store::Item_t& result, xs_short value);

  bool createByte(store::Item_t& result, xs_byte value);

  bool createUnsignedLong(store::Item_t& result, xs_unsignedLong value);

  bool createUnsignedInt(store::Item_t& result, xs_unsignedInt value);

  bool createUnsignedShort(store::Item_t& result, xs_unsignedShort value);

  bool createUnsignedByte(store::Item_t& result, xs_unsignedByte value);

  bool createDateTime(store::Item_t& result, const xs_date* date, const xs_time* time);

  bool createDateTime(store::Item_t& result, const xs_dateTime* value);

  bool createDateTime(store::Item_t& result, short year, short month, short day, short hour, short minute, double second);

  bool createDateTime(store::Item_t& result, short year , short month, short day, short hour, short minute, double second, short timeZone_hours);

  bool createDateTime(store::Item_t& result, const char* str, ulong strlen);

  bool createDateTime(store::Item_t& result, const store::Item_t&, const store::Item_t&);

  bool createDate(store::Item_t& result, const xs_date* value);

  bool createDate(store::Item_t& result, short year, short month, short day);

  bool createDate(store::Item_t& result, const char* str, ulong strlen);

  bool createTime(store::Item_t& result, const xs_time* value);

  bool createTime(store::Item_t& result, const char* str, ulong strlen);

  bool createTime(store::Item_t& result, short hour, short minute, double second );

  bool createTime(store::Item_t& result, short hour, short minute, double second, short timeZone_hours);

  bool createGDay(store::Item_t& result, const xs_gDay* value);

  bool createGDay(store::Item_t& result, const char* str, ulong strlen);

  bool createGDay(store::Item_t& result, short day);

  bool createGMonth(store::Item_t& result, const xs_gMonth* value);

  bool createGMonth(store::Item_t& result, const char* str, ulong strlen);

  bool createGMonth(store::Item_t& result, short month);

  bool createGMonthDay (store::Item_t& result, const xs_gMonthDay* value);

  bool createGMonthDay (store::Item_t& result,  const char* str, ulong strlen);

  bool createGMonthDay (store::Item_t& result,  short month, short day);

  bool createGYear (store::Item_t& result, const xs_gYear* value);

  bool createGYear (store::Item_t& result,  const char* str, ulong strlen);

  bool createGYear (store::Item_t& result,  short year);

  bool createGYearMonth (store::Item_t& result, const xs_gYearMonth* value);

  bool createGYearMonth (store::Item_t& result,  const char* str, ulong strlen);

  bool createGYearMonth (store::Item_t& result,  short year, short month);

  bool createDuration(store::Item_t& result, xs_duration* value);

  bool createDuration(store::Item_t& result, const char* str, ulong strlen);

  bool createDuration(store::Item_t& result, short years, short months, short days, short hours, short minutes, double seconds);

  bool createYearMonthDuration(store::Item_t& result, const char* str, ulong strlen );

  bool createYearMonthDuration(store::Item_t& result, xs_yearMonthDuration* value );

  bool createDayTimeDuration(store::Item_t& result, xs_dayTimeDuration* value );

  bool createDayTimeDuration(store::Item_t& result, const char* str, ulong strlen );

  bool createENTITIES(store::Item_t& result, zstring& value);

  bool createENTITY(store::Item_t& result, zstring& value);


  bool createHexBinary (store::Item_t& result,  xs_hexBinary value );

  bool createID (store::Item_t& result, zstring& value );

  bool createIDREF (store::Item_t& result,  zstring& value );

  bool createIDREFS (store::Item_t& result,  zstring& value );

  bool createLanguage (store::Item_t& result,  zstring& value );

  bool createNMTOKEN (store::Item_t& result,  zstring& value );

  bool createNMTOKENS (store::Item_t& result,  zstring& value );

  bool createNOTATION (store::Item_t& result,  zstring& value );

  bool createNOTATION(
      store::Item_t& result,
      zstring& ns,
      zstring& prefix,
      zstring& local);

  bool createNOTATION (store::Item_t& result,  store::Item_t& qname );

  bool createName (store::Item_t& result,  zstring& value );

  bool createNormalizedString(store::Item_t& result, zstring& value );

  bool createToken(store::Item_t& result, zstring& value);



  bool createDocumentNode(
        store::Item_t& result,
        zstring& baseUri,
        zstring& docUri);

  bool createElementNode(
        store::Item_t&              result,
        store::Item*                parent,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        bool                        haveTypedValue,
        bool                        haveEmptyValue,
        const store::NsBindings&    localBindings,
        zstring&                    baseURI,
        bool                        isInSubstitutionGroup = false);

  bool createElementNode(
        store::Item_t&              result,
        store::Item*                parent,
        ulong                       pos,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        bool                        haveTypedValue,
        bool                        haveEmptyValue,
        const store::NsBindings&    localBindings,
        zstring&                    baseURI,
        bool                        isInSubstitutionGroup = false);

  bool createAttributeNode(
        store::Item_t&              result,
        store::Item*                parent,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        store::Item_t&              typedValue);

  bool createAttributeNode(
        store::Item_t&              result,
        store::Item*                parent,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        std::vector<store::Item_t>& typedValueV);


  bool createAttributeNode(
        store::Item_t&              result,
        store::Item*                parent,
        ulong                       pos,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        store::Item_t&              typedValue);

  bool createAttributeNode(
        store::Item_t&              result,
        store::Item*                parent,
        ulong                       pos,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        std::vector<store::Item_t>& typedValueV);

  bool createTextNode(
        store::Item_t&    result,
        store::Item*      parent,
        zstring&          content);

  bool createTextNode(
        store::Item_t&    result,
        store::Item*      parent,
        ulong             pos,
        zstring&          content);

  bool createTextNode(
        store::Item_t&    result,
        store::Item*      parent,
        store::Item_t&    content);

  bool createTextNode(
        store::Item_t&              result,
        store::Item*                parent,
        std::vector<store::Item_t>& content);

  bool createPiNode (
        store::Item_t& result,
        store::Item*   parent,
        zstring&       target,
        zstring&       content,
        zstring&       baseUri);

  bool createPiNode (
        store::Item_t& result,
        store::Item*   parent,
        ulong          pos,
        zstring&       target,
        zstring&       content,
        zstring&       baseUri);

  bool createCommentNode (
        store::Item_t& result,
        store::Item*   parent,
        zstring&       content);

  bool createCommentNode (
        store::Item_t& result,
        store::Item*   parent,
        ulong          pos,
        zstring&       content);


  store::PUL* createPendingUpdateList();

  bool createError(
          store::Item_t& result,
          ZorbaException* ze);

  bool createFunction(
          store::Item_t&,
          const store::Item_t&,
          const signature&,
          const store::Iterator_t&);

  bool createFunction(
          store::Item_t&,
          const std::vector<store::Iterator_t>&,
          const signature&,
          const store::Iterator_t&);

#ifdef ZORBA_WITH_JSON
  bool createJSONNull(store::Item_t& result);

  bool createJSONNumber(
      store::Item_t& result,
      store::Item_t& string);

  bool createJSONNumber(
      store::Item_t& result,
      zstring& string);

  bool createJSONArray(
      store::Item_t& result,
      const std::vector<store::Iterator_t>& sources,
      const std::vector<store::CopyMode>& copyModes);

  bool createJSONArray(
      store::Item_t& result,
      store::Item_t& item1,
      store::Item_t& item2,
      const store::Iterator_t& source,
      const store::CopyMode& copyMode);

  bool createJSONArray(
      store::Item_t& result,
      const std::vector<store::Item_t>& items);

  bool createJSONObject(
      store::Item_t& result,
      const std::vector<store::Iterator_t>& sources,
      const std::vector<store::CopyMode>& copyModes,
      bool accumulate);

  bool createJSONObject(
      store::Item_t& result,
      const std::vector<store::Item_t>& names,
      const std::vector<store::Item_t>& values);
#endif

private:
  void splitToAtomicTextValues(
          zstring& textValue,
          std::vector<zstring>& atomicTextValues);
};

} // namespace simplestore
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
