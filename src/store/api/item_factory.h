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

#include <vector>

#include "zorbatypes/representations.h"

#include "common/common.h"

#include "common/shared_types.h"


namespace zorba { namespace store {

class CopyMode;
class PUL;

typedef std::vector<std::pair<xqpString, xqpString> > NsBindings;

class ItemFactory
{
public:
  virtual ~ItemFactory() {}
  
public:
			
  /**
   * @param namespace namespace of the qname
   * @param prefix prefix of the qname
   * @param localName local name of the qname
   */
  virtual bool createQName(
        Item_t& result,
        xqpStringStore* nameSpace,
        xqpStringStore* prefix,
        xqpStringStore* localName,
        bool*           inserted = 0) = 0;

  virtual bool createQName(
        Item_t& result,
        const char* ns,
        const char* pre,
        const char* ln) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NCName]
   * @param value string representation of the value
   */
  virtual bool createNCName(Item_t& result, xqpStringStore_t& value) = 0;
    
  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#anyURI]
   * @param value parsed value
   * TODO where is the value parsed and checked?
   */
  virtual bool createAnyURI(Item_t& result, xqpStringStore_t& value) = 0;
  virtual bool createAnyURI(Item_t& result, const char* value) = 0;

  /**
   * @param value string value of the untyped atomic
   */
  virtual bool createUntypedAtomic(Item_t& result, xqpStringStore_t& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#string]
   * @param value string representation of the value
   */
  virtual bool createString(Item_t& result, xqpStringStore_t& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#base64Binary]
   * @param value)?
   */
  virtual bool createBase64Binary(Item_t& result, xqp_base64Binary value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#bool]
   * @param value
   */
  virtual bool createBoolean(Item_t& result, xqp_boolean value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#decimal]
   * @param value
   */
  virtual bool createDecimal ( Item_t& result, xqp_decimal value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#integer]
   * @param value
   */
  virtual bool createInteger ( Item_t& result, xqp_integer value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#long]
   * @param value
   */
  virtual bool createLong ( Item_t& result, xqp_long value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#int]
   * @param value
   */
  virtual bool createInt ( Item_t& result, xqp_int value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#short]
   * @param value
   */
  virtual bool createShort ( Item_t& result, xqp_short value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#byte]
   * @param value
   */
  virtual bool createByte ( Item_t& result, xqp_byte value ) = 0;


  virtual bool createDate ( Item_t& result, xqp_date& value ) = 0;
  
  /**
   * @param year
   * @param month
   * @param day
   */
  virtual bool createDate ( Item_t& result, short year, short month, short day ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#date]
   * @param value string representation of the value
   */
  virtual bool createDate ( Item_t& result, const xqp_string& value ) = 0;

  virtual bool createDateTime(Item_t& result, xqp_dateTime& value) = 0;
            
  /**
   * @param year
   * @param month
   * @param day
   * @param hour
   * @param minute
   * @param second
   */
  virtual bool createDateTime (Item_t& result,  
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
  virtual bool createDateTime (Item_t& result,  
      short year , short month, short day,
      short hour, short minute, double second, short timeZone_hours) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#dateTime]
   * @param value string representation of the value
   */
  virtual bool createDateTime ( Item_t& result, const xqp_string& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xpath-functions/] Section 5.2
   *
   * @param xs:date Item (might be NULL)
   * @param xs:time Item (might be NULL)
   */
  virtual bool createDateTime ( Item_t& result, const Item_t&, const Item_t& ) = 0;

  /**
   * @param value double value
   */
  virtual bool createDouble ( Item_t& result, xqp_double value ) = 0;

  virtual bool createDuration(Item_t& result, xqp_duration& value ) = 0;
  
  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#duration]
   * @param value string representation of the value
   */
  virtual bool createDuration ( Item_t& result, const xqp_string& value ) = 0;

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
   * Specification: [http://www.w3.org/TR/xmlschema-2/#ENTITIES]
   * @param value string representation of the value
   */
  virtual bool createENTITIES(Item_t& result, xqpStringStore_t& value) = 0;
  
  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#ENTITY]
   * @param value string representation of the value
   */
  virtual bool createENTITY(Item_t& result, xqpStringStore_t& value) = 0;

  /**
   * @param value
   */
  virtual bool createFloat ( Item_t& result, xqp_float value ) = 0;

  virtual bool createGDay ( Item_t& result, xqp_gDay& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gDay]
   * @param value string representation of the value
   */
  virtual bool createGDay ( Item_t& result, const xqp_string& value ) = 0;

  /**
   * @param day
   */
  virtual bool createGDay ( Item_t& result, short day ) = 0;

  virtual bool createGMonth ( Item_t& result, xqp_gMonth& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gMonth]
   * @param value string representation of the value
   */
  virtual bool createGMonth ( Item_t& result, const xqp_string& value ) = 0;

  /**
   * @param month
   */
  virtual bool createGMonth ( Item_t& result, short month ) = 0;

  virtual bool createGMonthDay ( Item_t& result, xqp_gMonthDay& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gMonthDay]
   * @param value string representation of the value
   */
  virtual bool createGMonthDay ( Item_t& result, const xqp_string& value ) = 0;

  /**
   * @param month
   * @param day
   */
  virtual bool createGMonthDay ( Item_t& result, short month, short day ) = 0;

  virtual bool createGYear ( Item_t& result, xqp_gYear& value ) = 0;
  
  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gYear]
   * @param value string representation of the value
   */
  virtual bool createGYear ( Item_t& result, const xqp_string& value ) = 0;

  /**
   * @param year
   */
  virtual bool createGYear ( Item_t& result, short year ) = 0;

  virtual bool createGYearMonth ( Item_t& result, xqp_gYearMonth& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#gYearMonth]
   * @param value string representation of the value
   */
  virtual bool createGYearMonth ( Item_t& result, const xqp_string& value ) = 0;

  /**
   * @param year
   * @param month
   */
  virtual bool createGYearMonth ( Item_t& result, short year, short month ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#hexBinary]
   * @param value
   */
  virtual bool createHexBinary ( Item_t& result, xqp_hexBinary value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#ID]
   * @param value string representation of the value
   */
  virtual bool createID(Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#IDREF]
   * @param value string representation of the value
   */
  virtual bool createIDREF(Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#IDREFS]
   * @param value string representation of the value
   */
  virtual bool createIDREFS(Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#language]
   * @param value string representation of the value
   */
  virtual bool createLanguage(Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NMTOKEN]
   * @param value string representation of the value
   */
  virtual bool createNMTOKEN(Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NMTOKENS]
   * @param value string representation of the value
   */
  virtual bool createNMTOKENS(Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#NOTATION]
   * @param value string representation of the value
   */
  virtual bool createNOTATION (Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#Name]
   * @param value string representation of the value
   */
  virtual bool createName (Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#negativeInteger]
   * @param value
   */
  virtual bool createNegativeInteger ( Item_t& result, xqp_integer value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#nonNegativeInteger]
   * @param value
   */
  virtual bool createNonNegativeInteger ( Item_t& result, xqp_uinteger value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#nonPositiveInteger]
   * @param value
   */
  virtual bool createNonPositiveInteger ( Item_t& result, xqp_integer value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#normalizedString]
   * @param value string representation of the value
   */
  virtual bool createNormalizedString (Item_t& result, xqpStringStore_t& value ) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#positiveInteger]
   * @param value
   */
  virtual bool createPositiveInteger(Item_t& result, xqp_uinteger value) = 0;

  virtual bool createTime(Item_t& result, xqp_time& value) = 0;
  
  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#time]
   * @param value string representation of the value
   */
  virtual bool createTime(Item_t& result, const xqp_string& value) = 0;

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
  virtual bool createTime(Item_t& result, short hour, short minute, double second, short timeZone_hours) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#token]
   * @param value string representation of the value
   */
  virtual bool createToken(Item_t& result, xqpStringStore_t& value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#unsignedByte]
   * @param value
   */
  virtual bool createUnsignedByte(Item_t& result, xqp_ubyte value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#unsignedInt]
   * @param value
   */
  virtual bool createUnsignedInt(Item_t& result, xqp_uint value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#unsignedLong]
   * @param value
   */
  virtual bool createUnsignedLong(Item_t& result, xqp_ulong value) = 0;

  /**
   * Specification: [http://www.w3.org/TR/xmlschema-2/#unsignedShort]
   * @param value
   */
  virtual bool createUnsignedShort(Item_t& result, xqp_ushort value) = 0;

  /**
   * @param baseUri The base URI of the document.
   * @param docUri The document URI of the document.
   * @param children Content of the Document(root element + comment nodes + PI nodes). 
   * 								The item factory does not check if the parameter contains exactly one root element!
   * @param createId Does the created item need an ID?
   */
  virtual bool createDocumentNode(
        Item_t& result, unsigned long     qid,
        xqpStringStore_t& baseURI,
        Iterator*         children,
        bool              isRoot,
        bool              assignIds,
        bool              copy,
        const CopyMode&   copymode) = 0;

  /**
   * @param name QName which contains the name of the element
   * @param type QName which contains the type of the element
   * @param children Content of the element
   * @param attributes Attributes of the element
   * @param namespaces Namespace definitions of this element
   * @param copy Should the children of the element be copied? (for element construction)
   * @param newTypes Have the children to be checked agains the type of the parent?
   * @param createId Does the created item need an ID?
   */
  virtual bool createElementNode (
        Item_t& result, unsigned long     qid,
        Item_t&           qname,
        Item_t&           typeName,
        Iterator*         childrenIte,
        Iterator*         attributesIte,
        Iterator*         namespacesIte,
        const NsBindings& localBindings,
        xqpStringStore_t& baseURI,
        bool              isRoot,
        bool              assignIds,
        bool              copy,
        const CopyMode&   copymode) = 0;

  /**
   * @param name QName which contains the name of the element
   * @param type QName which contains the type of the element
   * @param lexicalValue lexical value (atomic) of the attribute element
   * @param typedValue typed value (atomic) of the attribute element
   * @param createId Does the created item need an ID?
   *
   * Implementations might only store the typed value.
   */
  virtual bool createAttributeNode(
        Item_t& result, unsigned long qid,
        Iterator*     nameIter,
        Item_t&       typeName,
        Iterator*     valueIter,
        bool          isRoot,
        bool          assignIds) = 0;

  /**
   * @param value text
   * @param createId Does the created item need an ID (default == false)?
   */
  virtual bool createTextNode(
        Item_t& result, unsigned long   qid,
        Iterator*       valueIter,
        bool            isRoot,
        bool            assignIds) = 0;

  virtual bool createTextNode(
        Item_t& result, unsigned long     qid,
        xqpStringStore_t& value,
        bool              isRoot,
        bool              assignIds) = 0;

  /**
   * @param target The QName for the processing instruction.
   * @param data The content of the processing instruction.
   * @param createId Does the created item need an ID?
   */
  virtual bool createPiNode(
        Item_t& result, unsigned long     qid,
        xqpStringStore_t& target,
        xqpStringStore_t& content,
        bool              isRoot,
        bool              assignIds) = 0;

  /**
   * @param comment
   * @param createId Does the created item need an ID (default == false)?
   */
  virtual bool createCommentNode(
        Item_t& result, unsigned long     qid,
        xqpStringStore_t& content,
        bool              isRoot,
        bool              assignIds) = 0;

  virtual PUL* createPendingUpdateList() = 0;
};

} // namespace store
} // namespace zorba

#endif
