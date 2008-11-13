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

#include "zorbamisc/config/platform.h"

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"
#include "zorbatypes/datetime.h"

#include "store/api/collection.h"
#include "store/api/copymode.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/query_context.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/simple_pul.h"
#include "store/naive/qname_pool.h"
#include "store/naive/string_pool.h"
#include "store/naive/tupleimpl.h"


namespace zorba { namespace simplestore {

BasicItemFactory::BasicItemFactory(UriPool* uriPool, QNamePool* qnPool)
  :
  theUriPool(uriPool),
  theQNamePool(qnPool)
{
}


BasicItemFactory::~BasicItemFactory()
{
  theQNamePool = NULL;
  theUriPool = NULL;
}


bool BasicItemFactory::createQName(
    store::Item_t&          result,
    const xqpStringStore_t& ns,
    const xqpStringStore_t& pre,
    const xqpStringStore_t& local)
{
  result = theQNamePool->insert(ns, pre, local);
  return true;
}


bool BasicItemFactory::createQName(
    store::Item_t& result,
    const char*    ns,
    const char*    pre,
    const char*    ln)
{
  result = theQNamePool->insert(ns, pre, ln);
  return true;
}


bool BasicItemFactory::createNCName(store::Item_t& result, xqpStringStore_t& value)
{
  result = new NCNameItemImpl(value);
  return true;
}


bool BasicItemFactory::createAnyURI(store::Item_t& result, xqpStringStore_t& value)
{
  xqpStringStore_t str = value;
  theUriPool->insert(str, str);
  result =  new AnyUriItemImpl(str);
  return true;
}


bool BasicItemFactory::createAnyURI(store::Item_t& result, const char* value)
{
  xqpStringStore_t str;
  theUriPool->insertc(value, str);
  result = new AnyUriItemImpl(str);
  return true;
}


bool BasicItemFactory::createUntypedAtomic(store::Item_t& result, xqpStringStore_t& value)
{
  result = new UntypedAtomicItemImpl(value);
  return true;
}


bool BasicItemFactory::createString(store::Item_t& result, xqpStringStore_t& value)
{
  result = new StringItemNaive(value);
  return true;
}


bool BasicItemFactory::createBase64Binary(store::Item_t& result, xqp_base64Binary value)
{
  result = new Base64BinaryItemNaive ( value );
  return true;
}

bool BasicItemFactory::createBoolean(store::Item_t& result, xqp_boolean value)
{
  result = new BooleanItemNaive(value);
  return true;
}


bool BasicItemFactory::createDecimal(store::Item_t& result, xqp_decimal value)
{
  result = new DecimalItemNaive(value);
  return true;
}


bool BasicItemFactory::createInteger(store::Item_t& result, xqp_integer value)
{
  result = new IntegerItemNaive ( value );
  return true;
}


bool BasicItemFactory::createLong (store::Item_t& result,  xqp_long value )
{
  result = new LongItemNaive ( value );
  return true;
}


bool BasicItemFactory::createInt (store::Item_t& result,  xqp_int value )
{
  result = new IntItemNaive ( value );
  return true;
}


bool BasicItemFactory::createShort (store::Item_t& result,  xqp_short value )
{
  result = new ShortItemNaive ( value );
  return true;
}


bool BasicItemFactory::createByte (store::Item_t& result,  xqp_byte value )
{
  result = new ByteItemNaive ( value );
  return true;
}



bool BasicItemFactory::createDateTime(store::Item_t& result, const xqp_dateTime* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    short   year,
    short   month,
    short   day,
    short   hour,
    short   minute,
    double  second)
{
  DateTime dt;
  TimeZone tz;

  if(DateTime::createDateTime(year, month, day, hour, minute, second, &tz, dt) == 0)
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    short   year ,
    short   month,
    short   day,
    short   hour,
    short   minute,
    double  second,
    short   timeZone_hours)
{
  DateTime dt;
  TimeZone tz(timeZone_hours);

  if (DateTime::createDateTime(year, month, day, hour, minute, second, &tz, dt) == 0)
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else 
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    const xqp_string& value )
{
  DateTime dt;
  
  if (DateTime::parseDateTime(value, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    const store::Item_t& date,
    const store::Item_t& time)
{
  if (date.isNull() || time.isNull()) 
  {
    result = NULL;
    return false;
  } 
  else
  {
    if (2 == DateTimeItemNaive::createFromDateAndTime(&date->getDateValue(),
                                                      &time->getTimeValue(),
                                                      result))
      ZORBA_ERROR(FORG0008);
    
    return true;
  }
}


bool BasicItemFactory::createDate(store::Item_t& result, const xqp_date* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createDate (
    store::Item_t& result,
    short year,
    short month,
    short day )
{
  DateTime dt;
  TimeZone tz;
  
  if(DateTime::createDate(year, month, day, &tz, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDate (store::Item_t& result,  const xqp_string& value )
{
  DateTime dt;
  
  if (DateTime::parseDate(value, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createTime(store::Item_t& result, const xqp_time* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createTime(store::Item_t& result, const xqp_string& value)
{
  DateTime dt;
  
  if( DateTime::parseTime(value, dt) == 0 ) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createTime(
    store::Item_t& result,
    short          hour,
    short          minute,
    double         second)
{
  DateTime dt;
  TimeZone tz;
  
  if( DateTime::createTime(hour, minute, second, &tz, dt) == 0 ) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createTime(
    store::Item_t& result,
    short          hour,
    short          minute,
    double         second,
    short          timeZone_hours)
{
  DateTime dt;
  TimeZone tz(timeZone_hours);
  
  if(DateTime::createTime(hour, minute, second, &tz, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGDay(store::Item_t& result, const xqp_gDay* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createGDay(store::Item_t& result,  const xqp_string& value)
{
  DateTime dt;
  
  if (DateTime::parseGDay(value, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGDay(store::Item_t& result,  short day)
{
  DateTime dt;
  
  if (DateTime::createGDay(day, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGMonth(store::Item_t& result, const xqp_gMonth* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createGMonth(store::Item_t& result, const xqp_string& value)
{
  DateTime dt;
  
  if (DateTime::parseGMonth(value, dt) == 0)
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGMonth(store::Item_t& result, short month)
{
  DateTime dt;

  if(DateTime::createGMonth(month, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else 
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGMonthDay(
    store::Item_t& result,
    const xqp_gMonthDay* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createGMonthDay(
    store::Item_t& result,
    const xqp_string& value )
{
  DateTime dt;
  
  if (DateTime::parseGMonthDay(value, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGMonthDay(store::Item_t& result,  short month, short day)
{
  DateTime dt;

  if(DateTime::createGMonthDay(month, day, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  } else {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYear(store::Item_t& result, const xqp_gYear* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createGYear(store::Item_t& result,  const xqp_string& value)
{
  DateTime dt;
  
  if (DateTime::parseGYear(value, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  } else {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYear(store::Item_t& result,  short year)
{
  DateTime dt;

  if(DateTime::createGYear(year, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYearMonth(
    store::Item_t& result,
    const xqp_gYearMonth* value )
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createGYearMonth(
    store::Item_t& result,
    const xqp_string& value)
{
  DateTime dt;
  
  if (DateTime::parseGYearMonth(value, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else 
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYearMonth(
    store::Item_t& result,
    short year,
    short month)
{
  DateTime dt;

  if(DateTime::createGYearMonth(year, month, dt) == 0) 
  {
    result = new DateTimeItemNaive(&dt);
    return true;
  }
  else 
  {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDouble(
    store::Item_t& result,
    const xqp_double& value )
{
  result = new DoubleItemNaive( value );
  return true;
}


bool BasicItemFactory::createDuration(
    store::Item_t& result,
    xqp_duration* value )
{
  result = new DurationItemNaive(value);
  return true;
}


bool BasicItemFactory::createDuration (store::Item_t& result,  const xqp_string& value )
{
  Duration d;
  if (Duration::parseDuration(value, d))
  {
    result = new DurationItemNaive(&d);
    return true;
  }
  
  result = NULL;
  return false;
}


bool BasicItemFactory::createDuration (
    store::Item_t& result,
    short   years,
    short   months,
    short   days,
    short   hours,
    short   minutes,
    double  seconds)
{
  Duration d(Duration::DURATION_FACET, years, months, days, hours, minutes, seconds);
  result = new DurationItemNaive(&d);
  return true;
}


bool BasicItemFactory::createYearMonthDuration(store::Item_t& result, xqp_yearMonthDuration* value )
{
  result = new DurationItemNaive(value);
  return true;
}


bool BasicItemFactory::createDayTimeDuration(store::Item_t& result, xqp_dayTimeDuration* value )
{
  result = new DurationItemNaive(value);
  return true;
}


bool BasicItemFactory::createENTITIES(store::Item_t& result, xqpStringStore_t& /*value*/)
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createENTITY(store::Item_t& result, xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createFloat (store::Item_t& result,  xqp_float value )
{
  result = new FloatItemNaive( value );
  return true;
}



bool BasicItemFactory::createHexBinary (store::Item_t& result,  xqp_hexBinary value )
{
  result = new HexBinaryItemNaive ( value ); 
  return true;
}


bool BasicItemFactory::createID(store::Item_t& result, xqpStringStore_t& value)
{
  result = new IDItemImpl(value);
  return true;
}


bool BasicItemFactory::createIDREF(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createIDREFS(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createLanguage(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createNMTOKEN(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createNMTOKENS(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createNOTATION(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createName(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createNegativeInteger(
    store::Item_t& result,
    xqp_integer value )
{
  ZORBA_ASSERT(value < xqp_integer::parseInt(0));
  result = new NegativeIntegerItemNaive ( value );
  return true;
}


bool BasicItemFactory::createNonNegativeInteger(
    store::Item_t& result,
    xqp_uinteger value )
{
  result = new NonNegativeIntegerItemNaive ( value );
  return true;
}


bool BasicItemFactory::createNonPositiveInteger(
    store::Item_t& result,
    xqp_integer    value )
{
  ZORBA_ASSERT(value <= Integer::parseInt(0));
  result = new NonPositiveIntegerItemNaive( value );
  return true;
}


bool BasicItemFactory::createNormalizedString(
    store::Item_t&    result,
    xqpStringStore_t& value)
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createPositiveInteger(
    store::Item_t& result,
    xqp_uinteger value)
{
  ZORBA_ASSERT(value > Integer::parseInt(0));
  result = new PositiveIntegerItemNaive( value );
  return true;
}


bool BasicItemFactory::createToken(store::Item_t& result, xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}

bool BasicItemFactory::createUnsignedByte (store::Item_t& result,  xqp_ubyte value )
{
  result = new UnsignedByteItemNaive ( value );
  return true;
}

bool BasicItemFactory::createUnsignedInt (store::Item_t& result,  xqp_uint value )
{
  result = new UnsignedIntItemNaive( value );
  return true;
}

bool BasicItemFactory::createUnsignedLong(store::Item_t& result, xqp_ulong value)
{
  result = new UnsignedLongItemNaive( value );
  return true;
}

bool BasicItemFactory::createUnsignedShort(store::Item_t& result, xqp_ushort value)
{
  result = new UnsignedShortItemNaive( value );
  return true;
}


/*******************************************************************************
  Create a new document node N and make it the root (and single node) of a new
  XML tree.

  baseUri       : The base-uri property of N. It may be NULL.
  docUri        : The document-uri property of N. It may be NULL.
  allowSharing  : A zorba-specific parameter used to optimize node-construction
                  expressions by avoiding node copying whenever possible. If
                  true, then N may have as children nodes that belong to a
                  different XML tree than N (the parent of such a "shared"
                  node C is not N, but a node in the same XmlTree as C). 
********************************************************************************/
bool BasicItemFactory::createDocumentNode(
    store::Item_t&    result,
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri,
    bool              allowSharing)
{
  XmlTree* xmlTree = NULL;
  DocumentNode* n = NULL;

  try
  {
    xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());

   if (allowSharing)
     n = new DocumentDagNode(xmlTree, baseUri, docUri);
   else
     n = new DocumentTreeNode(xmlTree, baseUri, docUri);
  }
  catch (...)
  {
    if (xmlTree) delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new element node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a new XML
  tree. 

  parent        : The parent P of the new element node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos < 0 or pos >= current number of P's children, then
                  N is appended to the list of children.
  nodeName      : The node-name property of N.
  typeName      : The type-name property of N.
  haveTypedValue: Whether the node has a typed value or not (element nodes with
                  complex type and element-only content do not have typed value).
  haveEmptyValue: True if the typed value of the node is the empty sequence.
                  This is the case if the element has a complex type with empty
                  content.
  localBindings : A set of namespace bindings. The namespaces property of N is
                  the union of this set and the namespaces property of P.
  baseUri       : The base-uri property of N. It may be NULL, in which case, 
                  the base-uri property of N is the same as that of P.
  allowSharing  : A zorba-specific parameter used to optimize node-construction
                  expressions by avoiding node copying whenever possible. If
                  true, then N may have as children/attributes nodes that belong
                  to a different XML tree than N (the parent of such a "shared"
                  node C is not N, but a node in the same XmlTree as C). 
********************************************************************************/
bool BasicItemFactory::createElementNode(
    store::Item_t&              result,
    store::Item*                parent,
    long                        pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    bool                        haveTypedValue,
    bool                        haveEmptyValue,
    bool                        isId,
    bool                        isIdRefs,
    const store::NsBindings&    localBindings,
    xqpStringStore_t&           baseUri,
    bool                        allowSharing)
{
  XmlTree* xmlTree = NULL;
  ElementNode* n = NULL;

  XmlNode* pnode = reinterpret_cast<XmlNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());

    if (allowSharing)
      n = new ElementDagNode(xmlTree, pnode, pos, nodeName,
                             typeName, haveTypedValue, haveEmptyValue,
                             isId, isIdRefs,
                             &localBindings, baseUri);
    else
      n = new ElementTreeNode(xmlTree, pnode, pos, nodeName,
                              typeName, haveTypedValue, haveEmptyValue,
                              isId, isIdRefs,
                              &localBindings, baseUri);
  }
  catch (...)
  {
    if (xmlTree) delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new attribute node N and place it as the pos-th attribute of a given
  parent node. If no parent is given, N becomes the root (and single node) of a
  new XML tree. 

  parent        : The parent P of the new attribute node; may be NULL.
  pos           : The position, among the attributes of P, that N will occupy.
                  If pos < 0 or pos >= current number of P's attributes, then
                  N is appended to the list of attributes.
  nodeName      : The node-name property of N.
  typeName      : The type-name property of N.
  typedValue    : The typed-value property of N.
********************************************************************************/
bool BasicItemFactory::createAttributeNode(
    store::Item_t&  result,
    store::Item*    parent,
    long            pos,
    store::Item_t&  nodeName,
    store::Item_t&  typeName,
    store::Item_t&  typedValue,
    bool            isId,
    bool            isIdRefs)
{
  XmlTree* xmlTree = NULL;
  AttributeNode* n = NULL;

  XmlNode* pnode = reinterpret_cast<XmlNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());

    n = new AttributeNode(xmlTree, pnode, pos,
                          nodeName, typeName, typedValue, isId, isIdRefs, false);
  }
  catch (...)
  {
    if (xmlTree) delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


bool BasicItemFactory::createAttributeNode(
    store::Item_t&              result,
    store::Item*                parent,
    long                        pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    std::vector<store::Item_t>& typedValueV,
    bool                        isId,
    bool                        isIdRefs)
{
  XmlTree* xmlTree = NULL;
  AttributeNode* n = NULL;

  XmlNode* pnode = reinterpret_cast<XmlNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());

    store::Item_t typedValue = new ItemVector(typedValueV);
 
    n = new AttributeNode(xmlTree, pnode, pos,
                          nodeName, typeName, typedValue, isId, isIdRefs, true);
  }
  catch (...)
  {
    if (xmlTree) delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new text node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree. 

  parent        : The parent P of the new text node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos < 0 or pos >= current number of P's children, then
                  N is appended to the list of children.
  content       : The content property of N.
********************************************************************************/
bool BasicItemFactory::createTextNode(
    store::Item_t&    result,
    store::Item*      parent,
    long              pos,
    xqpStringStore_t& content)
{
  XmlTree* xmlTree = NULL;
  TextNode* n = NULL;

  XmlNode* pnode = reinterpret_cast<XmlNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());

      n = new TextNode(xmlTree, pnode, pos, content);
    }
    else
    {
      ulong pos2 = (pos >= 0 ? pos : pnode->numChildren());

      XmlNode* lsib = (pos2 > 0 ? pnode->getChild(pos2-1) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == store::StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);

        ZORBA_ASSERT(pnode->getNodeKind() != store::StoreConsts::elementNode ||
                     !reinterpret_cast<ElementNode*>(pnode)->haveTypedValue());

        if (lsib->getParent() == parent)
        {
          xqpStringStore_t content2 = textSibling->getText()->append(content);
          textSibling->setText(content2);
          result = lsib;
        }
        else
        {
          xqpStringStore_t content2 = textSibling->getText()->append(content);
          pnode->removeChild(pos2-1);
          result = new TextNode(NULL, pnode, pos2-1, content2);
        }
        return result != NULL;
      }
 
      n = new TextNode(xmlTree, pnode, pos, content);
    }
  }
  catch (...)
  {
    if (xmlTree) delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new text node N to store the typed value a given element node P (the
  parent of N) that has simple type or complex type with simple content. P is
  not allowed to have any other text or element children. 

  parent        : The parent P of the new text node; must not be NULL.
  content       : The typed value of P.
********************************************************************************/
bool BasicItemFactory::createTextNode(
    store::Item_t&    result,
    store::Item*      parent,
    store::Item_t&    content)
{
  assert(parent != NULL);
  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  // Note: the TextNode constructor asserts that the parent has 0 children
  result = new TextNode(pnode, content, false);
  return true;
}


bool BasicItemFactory::createTextNode(
    store::Item_t&              result,
    store::Item*                parent,
    std::vector<store::Item_t>& content)
{
  assert(parent != NULL);
  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  store::Item_t typedValue = new ItemVector(content);
  result = new TextNode(pnode, typedValue, true);
  return true;
}


/*******************************************************************************
  Create a new pi node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree. 

  parent        : The parent P of the new pi node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos < 0 or pos >= current number of P's children, then
                  N is appended to the list of children.
  target        : The target property of N.
  content       : The content property of N.
  baseUri       : The base-uri property of N.
********************************************************************************/
bool BasicItemFactory::createPiNode(
    store::Item_t&    result,
    store::Item*      parent,
    long              pos,
    xqpStringStore_t& target,
    xqpStringStore_t& content,
    xqpStringStore_t& baseUri)
{
  XmlTree* xmlTree = NULL;
  PiNode* n = NULL;

  XmlNode* pnode = reinterpret_cast<XmlNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());

    n = new PiNode(xmlTree, pnode, pos, target, content);
  }
  catch (...)
  {
    if (xmlTree) delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new comment node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree. 

  parent        : The parent P of the new comment node; may be NULL.
  pos           : The position, among the children of P, that N will occupy.
                  If pos < 0 or pos >= current number of P's children, then
                  N is appended to the list of children.
  content       : The content property of N.
********************************************************************************/
bool BasicItemFactory::createCommentNode(
    store::Item_t&    result,
    store::Item*      parent,
    long              pos,
    xqpStringStore_t& content)
{
  XmlTree* xmlTree = NULL;
  CommentNode* n = NULL;

  XmlNode* pnode = reinterpret_cast<XmlNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());

    n = new CommentNode(xmlTree, pnode, pos, content);
  }
  catch (...)
  {
    if (xmlTree) delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************

********************************************************************************/
store::PUL* BasicItemFactory::createPendingUpdateList()
{
  return new PULImpl();
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createTuple(
        store::Item_t& result,
        std::vector<store::TupleField>& fields)
{
  result = new TupleItem(fields);
  return true;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createTuple(
        store::Item_t& result,
        store::Item *inTuple,
        std::vector<int>& permutation)
{
  ZORBA_ASSERT(inTuple->isTuple());
  std::vector<zorba::store::TupleField> newFields;
  int n = permutation.size();
  for(int i = 0; i <= n; ++i) {
    newFields.push_back(inTuple->getTupleField(permutation[i]));
  }
  result = new TupleItem(newFields);
  return true;
}

} // namespace store
} // namespace zorba

