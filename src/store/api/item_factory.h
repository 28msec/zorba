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
#ifndef ZORBA_STORE_ITEM_FACTORY_H
#define ZORBA_STORE_ITEM_FACTORY_H

#include <istream>
#include <vector>

#include <zorba/config.h>
#include <zorba/zorba_exception.h>
#include <zorba/streams.h>

#include "store/api/shared_types.h"
#include "zorbatypes/schema_types.h"


namespace zorba {

class signature;

namespace store {

class CopyMode;
class PUL;
class TupleField;


class ItemFactory
{
public:
  virtual ~ItemFactory() {}

public:

  /**
   * Create an atomic item with a given user-defined data type.
   */
  virtual bool createUserTypedAtomicItem(
        store::Item_t& result,
        store::Item_t& baseItem,
        store::Item_t& typeName) = 0;

  /**
   * @param value string value of the untyped atomic
   */
  virtual bool createUntypedAtomic(Item_t& result, zstring& value) = 0;

  /**
   * @param namespace namespace of the qname
   * @param prefix prefix of the qname
   * @param localName local name of the qname
   */
  virtual bool createQName(
        Item_t& result,
        const zstring& nameSpace,
        const zstring& prefix,
        const zstring& localName) = 0;

  virtual bool createQName(
        Item_t& result,
        const char* ns,
        const char* pre,
        const char* ln) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#anyURI]
   * @param value parsed value
   * TODO where is the value parsed and checked?
   */
  virtual bool createAnyURI(Item_t& result, zstring& value) = 0;

  virtual bool createAnyURI(Item_t& result, const char* value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#string]
   * @param value string representation of the value
   */
  virtual bool createString(Item_t& result, zstring& value) = 0;

  virtual bool createStreamableString(
      Item_t& result,
      std::istream&,
      StreamReleaser,
      bool seekable = false) = 0;

  /**
   * Create a StreamableStringItem which re-uses the stream from another
   * Streamable*Item. This will maintain a reference to the original
   * item to ensure the stream is not cleaned up before we are done with it.
   *
   * It only makes sense to use this method if either (a) the dependent item's
   * stream is seekable and hence re-usable, or (b) you are sure that the
   * dependent item will not be utilized after this new item is created.
   */
  virtual bool createSharedStreamableString(
      Item_t& result,
      Item_t& streamble_dependent) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#normalizedString]
   * @param value string representation of the value
   */
  virtual bool createNormalizedString(Item_t& result, zstring& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#token]
   * @param value string representation of the value
   */
  virtual bool createToken(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NMTOKEN]
   * @param value string representation of the value
   */
  virtual bool createNMTOKEN(Item_t& result, zstring& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NMTOKENS]
   * @param value string representation of the value
   */
  virtual bool createNMTOKENS(Item_t& result, zstring& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#language]
   * @param value string representation of the value
   */
  virtual bool createLanguage(Item_t& result, zstring& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#Name]
   * @param value string representation of the value
   */
  virtual bool createName(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NCName]
   * @param value string representation of the value
   */
  virtual bool createNCName(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#ID]
   * @param value string representation of the value
   */
  virtual bool createID(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#IDREF]
   * @param value string representation of the value
   */
  virtual bool createIDREF(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#IDREFS]
   * @param value string representation of the value
   */
  virtual bool createIDREFS(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#ENTITY]
   * @param value string representation of the value
   */
  virtual bool createENTITY(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#ENTITIES]
   * @param value string representation of the value
   */
  virtual bool createENTITIES(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NOTATION]
   * @param value string representation of the value (uri:localname)
   */
  virtual bool createNOTATION(Item_t& result, zstring& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NOTATION]
   * @param qname the QName representation of the value
   */
  virtual bool createNOTATION(Item_t& result, Item_t& qname) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NOTATION]
   * @param ns the namespace of the notation
   * @param prefix the prefix of the notation
   * @param local the localname of the notation
   */
  virtual bool createNOTATION(
      store::Item_t& result,
      zstring& ns,
      zstring& prefix,
      zstring& local) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#hexBinary]
   * @param value
   */
  virtual bool createHexBinary(Item_t& result, xs_hexBinary value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#base64Binary]
   * @param value)?
   */
  virtual bool createBase64Binary(Item_t& result, xs_base64Binary value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#base64Binary]
   * creates a base64Binary item with the given content
   * the encoded flag specifies whether the given content is already
   * base64 encoded or not.
   */
  virtual bool createBase64Binary(
      Item_t& result,
      const char* value,
      size_t size,
      bool encoded) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#base64Binary]
   * the encoded flag specifies whether the given content is already
   * base64 encoded or not.
   */
  virtual bool createStreamableBase64Binary(
      Item_t& result,
      std::istream&,
      StreamReleaser,
      bool seekable = false,
      bool encoded = false) = 0;


  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#bool]
   * @param value
   */
  virtual bool createBoolean(Item_t& result, xs_boolean value) = 0;

  /**
   * @param value double value
   */
  virtual bool createDouble(Item_t& result, const xs_double& value ) = 0;

  /**
   * @param value
   */
  virtual bool createFloat(Item_t& result, const xs_float& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#decimal]
   * @param value
   */
  virtual bool createDecimal(Item_t& result, const xs_decimal& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#integer]
   * @param value
   */
  virtual bool createInteger(Item_t& result, const xs_integer& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#nonNegativeInteger]
   * @param value
   */
  virtual bool createNonNegativeInteger(Item_t& result, const xs_nonNegativeInteger& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#positiveInteger]
   * @param value
   */
  virtual bool createPositiveInteger(Item_t& result, const xs_positiveInteger& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#nonPositiveInteger]
   * @param value
   */
  virtual bool createNonPositiveInteger(Item_t& result, const xs_integer& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#negativeInteger]
   * @param value
   */
  virtual bool createNegativeInteger(Item_t& result, const xs_integer& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#long]
   * @param value
   */
  virtual bool createLong(Item_t& result, xs_long value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#int]
   * @param value
   */
  virtual bool createInt(Item_t& result, xs_int value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#short]
   * @param value
   */
  virtual bool createShort(Item_t& result, xs_short value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#byte]
   * @param value
   */
  virtual bool createByte(Item_t& result, xs_byte value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#unsignedLong]
   * @param value
   */
  virtual bool createUnsignedLong(Item_t& result, xs_unsignedLong value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#unsignedInt]
   * @param value
   */
  virtual bool createUnsignedInt(Item_t& result, xs_unsignedInt value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#unsignedShort]
   * @param value
   */
  virtual bool createUnsignedShort(Item_t& result, xs_unsignedShort value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#unsignedByte]
   * @param value
   */
  virtual bool createUnsignedByte(Item_t& result, xs_unsignedByte value) = 0;


  virtual bool createDateTime(
        Item_t& result,
        const xs_dateTime* value) = 0;

  virtual bool createDateTime(
        store::Item_t& result,
        const xs_date* date,
        const xs_time* time) = 0;

  virtual bool createDateTime(
        Item_t& result,
        short year,
        short month,
        short day,
        short hour,
        short minute,
        double second) = 0;

  /**
   * @param year
   * @param month
   * @param day
   * @param hour
   * @param minute
   * @param second
   * @param timeZone_hours Difference in hours to UTC
   */
  virtual bool createDateTime(
        Item_t& result,
        short year,
        short month,
        short day,
        short hour,
        short minute,
        double second,
        short timeZone_hours) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#dateTime]
   * @param value string representation of the value
   */
  virtual bool createDateTime(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xpath-functions/] Section 5.2
   *
   * @param xs:date Item (might be NULL)
   * @param xs:time Item (might be NULL)
   */
  virtual bool createDateTime(Item_t& result, const Item_t&, const Item_t&) = 0;


  virtual bool createDate(Item_t& result, const xs_date* value) = 0;

  /**
   * @param year
   * @param month
   * @param day
   */
  virtual bool createDate(Item_t& result, short year, short month, short day ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#date]
   * @param value string representation of the value
   */
  virtual bool createDate(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   *
   */
  virtual bool createTime(Item_t& result, const xs_time* value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#time]
   * @param value string representation of the value
   */
  virtual bool createTime(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   * @param hour
   * @param minute
   * @param second
   */
  virtual bool createTime(Item_t& result, short hour, short minute, double second) = 0;

  /**
   * @param hour
   * @param minute
   * @param second
   * @param timeZone_hours Difference in hours to UTC
   */
  virtual bool createTime(
        Item_t& result,
        short hour,
        short minute,
        double second,
        short timeZone_hours) = 0;

  virtual bool createGDay(Item_t& result, const xs_gDay* value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gDay]
   * @param value string representation of the value
   */
  virtual bool createGDay(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   * @param day
   */
  virtual bool createGDay(Item_t& result, short day) = 0;

  virtual bool createGMonth(Item_t& result, const xs_gMonth* value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gMonth]
   * @param value string representation of the value
   */
  virtual bool createGMonth(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   * @param month
   */
  virtual bool createGMonth(Item_t& result, short month) = 0;

  virtual bool createGMonthDay(Item_t& result, const xs_gMonthDay* value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gMonthDay]
   * @param value string representation of the value
   */
  virtual bool createGMonthDay(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   * @param month
   * @param day
   */
  virtual bool createGMonthDay(Item_t& result, short month, short day) = 0;

  virtual bool createGYear(Item_t& result, const xs_gYear* value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gYear]
   * @param value string representation of the value
   */
  virtual bool createGYear(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   * @param year
   */
  virtual bool createGYear(Item_t& result, short year) = 0;

  virtual bool createGYearMonth(Item_t& result, const xs_gYearMonth* value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gYearMonth]
   * @param value string representation of the value
   */
  virtual bool createGYearMonth(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   * @param year
   * @param month
   */
  virtual bool createGYearMonth(Item_t& result, short year, short month) = 0;

  virtual bool createDuration(Item_t& result, xs_duration* value ) = 0;

  virtual bool createYearMonthDuration(Item_t& result, xs_yearMonthDuration* value ) = 0;

  virtual bool createYearMonthDuration(Item_t& result, const char* str, ulong strlen ) = 0;

  virtual bool createDayTimeDuration(Item_t& result, xs_dayTimeDuration* value ) = 0;

  virtual bool createDayTimeDuration(Item_t& result, const char* str, ulong strlen ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#duration]
   * @param value string representation of the value
   */
  virtual bool createDuration(Item_t& result, const char* str, ulong strlen) = 0;

  /**
   * @param years
   * @param months
   * @param days
   * @param hours
   * @param minutes
   * @param seconds
   */
  virtual bool createDuration (
			  Item_t& result, short years,
        short months,
        short days,
        short hours,
        short minutes,
        double seconds) = 0;

  /**
   * Create a new document node N and make it the root (and single node) of
   * a new XML tree.
   *
   * @param result        The new node N created by this method.
   * @param baseUri       The base uri of N. It may be NULL.
   * @param docUri        The document uri of N. It may be NULL.
   * @return              Always true (if any errors occur, the method throws
   *                      exceptions)
   */
  virtual bool createDocumentNode(
        store::Item_t& result,
        zstring& baseUri,
        zstring& docUri) = 0;

  /**
   * Create a new element node N and place it as the last child of a given 
   * parent node. If no parent is given, N becomes the root (and single node)
   * of a new XML tree.
   *
   * @param result         The new node N created by this method
   * @param parent         The parent P of the new node; may be NULL.
   * @param nodeName       The fully qualified name of the new node.
   * @param typeName       The fully qualified name of the new node's type.
   *                       Not allowed to be NULL, use xsd:untyped instead.
   * @param haveTypedValue Whether the node has a typed value or not (element
   *                       nodes with complex type and element-only content do
   *                       not have typed value).
   * @param haveEmptyValue True if the typed value of the node is the empty
   *                       sequence. This is the case if the element has a
   *                       complex type with empty content.
   * @param localBindings  A set of namespace bindings. The namespaces property
   *                       of N will be the union of this set and the namespaces
   *                       property of P.
   * @param baseUri        The base uri of N. It may be NULL, in which case, the
   *                       base-uri property of N is the same as that of P.
   * @return               Always true (if any errors occur, the method throws
   *                       exceptions)
   */
  virtual bool createElementNode(
        Item_t&             result,
        Item*               parent,
        Item_t&             nodeName,
        Item_t&             typeName,
        bool                haveTypedValue,
        bool                haveEmptyValue,
        const NsBindings&   localBindings,
        zstring&            baseURI,
        bool                isInSubstitutionGroup = false) = 0;

  /**
   * Create a new attribute node N and place it as the last attribute of a given
   * parent node. If no parent is given, N becomes the root (and single node) of
   * a new XML tree.
   *
   * @param result     The new node N created by this method
   * @param parent     The parent P of the new node; may be NULL.
   * @param nodeName   The fully qualified name of the new node. The nemaspace
   *                   binding implied by this name will be added to the namespaces
   *                   of P. If the name prefix is "xml" and the local name is
   *                   "base", then the base-uri property of P will be set or
   *                   updated accordingly.
   * @param typeName   The fully qualified name of the new node's type.
   * @param typedValue The typed value of the new node.
   * @return           Always true (if any errors occur, the method throws exceptions)
   */
  virtual bool createAttributeNode(
        Item_t&              result,
        Item*                parent,
        Item_t&              nodeName,
        Item_t&              typeName,
        Item_t&              typedValue) = 0;

  virtual bool createAttributeNode(
        Item_t&              result,
        Item*                parent,
        Item_t&              nodeName,
        Item_t&              typeName,
        std::vector<Item_t>& typedValue) = 0;

  /**
   * Create a new text node N and place it as the last child of a given parent
   * node. If no parent is given, N becomes the root (and single node) of a new
   * XML tree.
   *
   * @param result  The new node N created by this method
   * @param parent  The parent P of the new node; may be NULL.
   * @param content The content of the new node.
   * @return        Always true (if any errors occur, the method throws exceptions)
   */
  virtual bool createTextNode(
        Item_t&  result,
        Item*    parent,
        zstring& content) = 0;

  /**
   * Create a new text node N to store the typed value of an element node P, and
   * place N as the last child of P. Notice that in this case, P cannot have any
   * subelements. 
   *
   * @param result  The new node N created by this method
   * @param parent  The parent P of the new node; may NOT be NULL.
   * @param content The content of the new node.
   * @return        Always true (if any errors occur, the method throws exceptions)
   */
  virtual bool createTextNode(
        Item_t&  result,
        Item*    parent,
        Item_t&  content) = 0;

  virtual bool createTextNode(
        Item_t&              result,
        Item*                parent,
        std::vector<Item_t>& content) = 0;

  /**
   * Create a new processing instruction node N and place it as the last child
   * of a given parent node. If no parent is given, N becomes the root (and
   * single node) of a new XML tree.
   *
   * @param result  The new node N created by this method
   * @param parent  The parent P of the new node; may be NULL.
   * @param target  The target of the new node.
   * @param content The content of the new node.
   * @param baseUri The base uri of the new node. May be NULL.
   * @return        Always true (if any errors occur, the method throws exceptions)
   */
  virtual bool createPiNode (
        Item_t&  result,
        Item*    parent,
        zstring& target,
        zstring& content,
        zstring& baseUri) = 0;

  /**
   * Create a new comment node N and place it as the last child of a given
   * parent node. If no parent is given, N becomes the root (and single node)
   * of a new XML tree.
   *
   * @param result  The new node N created by this method
   * @param parent  The parent P of the new node; may be NULL.
   * @param content The content of the new node.
   * @return        Always true (if any errors occur, the method throws exceptions)
   */
  virtual bool createCommentNode(
        Item_t&  result,
        Item*    parent,
        zstring& content) = 0;

  /**
   * Create a pending updates list.
   */
  virtual PUL* createPendingUpdateList() = 0;

  /**
   * Create an ErrorItem encapsulating a pointer to a ZorbaException obj (or to
   * subclasses of ZorbaException). The new ErrorItem assumes ownership of the
   * ZorbaException obj
   */
  virtual bool createError(Item_t& result, ZorbaException* ze) = 0;

#ifdef ZORBA_WITH_JSON
  virtual bool createJSONNull(Item_t& result) = 0;

  virtual bool createJSONNumber(Item_t& result, Item_t& string) = 0;

  virtual bool createJSONNumber(Item_t& result, zstring& string) = 0;

  /**
   *
   */
  virtual bool createJSONArray(
      Item_t& result,
      const std::vector<Iterator_t>& sources,
      const std::vector<CopyMode>& copyModes) = 0;

  /**
   * This method is used when we want to box a sequence of item into an array,
   * but only if the sequence has more than 1 items.
   */
  virtual bool createJSONArray(
      Item_t& result,
      Item_t& item1,
      Item_t& item2,
      const Iterator_t& source,
      const CopyMode& copyMode) = 0;

  /**
   * This method is used by the public API only
   */
  virtual bool createJSONArray(
      Item_t& result,
      const std::vector<Item_t>& items) = 0;

  /**
   *
   */
  virtual bool createJSONObject(
      Item_t& result,
      const std::vector<Iterator_t>& sources,
      const std::vector<CopyMode>& copyModes,
      bool accumulate) = 0;

  /**
   * 
   */
  virtual bool createJSONObject(
      Item_t& result,
      const std::vector<Item_t>& names,
      const std::vector<Item_t>& values) = 0;
#endif
};

} // namespace store
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
