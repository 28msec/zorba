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

#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_item_factory.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/simple_pul.h"
#include "store/naive/qname_pool.h"
#include "store/naive/string_pool.h"
#include "store/naive/node_factory.h"
#include "runtime/function_item/function_item.h"

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


bool BasicItemFactory::createUserTypedAtomicItem(
    store::Item_t& result,
    store::Item_t& baseItem,
    store::Item_t& typeName)
{
  result = new UserTypedAtomicItemImpl(baseItem, typeName);
  return true;
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


bool BasicItemFactory::createString(store::Item_t& result, xqpStringStore_t& value)
{
  result = new StringItemNaive(value);
  return true;
}


bool BasicItemFactory::createNormalizedString(
    store::Item_t&    result,
    xqpStringStore_t& value)
{
  result = new NormalizedStringItemImpl(value);
  return true;
}


bool BasicItemFactory::createToken(store::Item_t& result, xqpStringStore_t& value )
{
  result = new TokenItemImpl(value);
  return true;
}


bool BasicItemFactory::createLanguage(store::Item_t& result, xqpStringStore_t& value )
{
  result = new LanguageItemImpl(value);
  return true;
}


bool BasicItemFactory::createNMTOKEN(store::Item_t& result, xqpStringStore_t& value )
{
  result = new NMTOKENItemImpl(value);
  return true;
}


bool BasicItemFactory::createNMTOKENS(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createName(store::Item_t& result, xqpStringStore_t& value )
{
  result = new NameItemImpl(value);
  return true;
}


bool BasicItemFactory::createNCName(store::Item_t& result, xqpStringStore_t& value )
{
  result = new NCNameItemImpl(value);
  return true;
}


bool BasicItemFactory::createID(store::Item_t& result, xqpStringStore_t& value )
{
  result = new IDItemImpl(value);
  return true;
}


bool BasicItemFactory::createIDREF(store::Item_t& result, xqpStringStore_t& value)
{
  result = new IDREFItemImpl(value);
  return true;
}

bool BasicItemFactory::createIDREFS(store::Item_t& result, xqpStringStore_t& value )
{
  result = NULL;
  return false;
}

bool BasicItemFactory::createENTITY(store::Item_t& result, xqpStringStore_t& value )
{
  result = new ENTITYItemImpl(value);
  return true;
}

bool BasicItemFactory::createENTITIES(store::Item_t& result, xqpStringStore_t& value)
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createUntypedAtomic(store::Item_t& result, xqpStringStore_t& value)
{
  result = new UntypedAtomicItem(value);
  return true;
}


bool BasicItemFactory::createDouble(
    store::Item_t& result,
    const xqp_double& value )
{
  result = new DoubleItemNaive( value );
  return true;
}


bool BasicItemFactory::createFloat(store::Item_t& result,  const xqp_float& value)
{
  result = new FloatItemNaive( value );
  return true;
}


bool BasicItemFactory::createDecimal(store::Item_t& result, const xqp_decimal& value)
{
  result = new DecimalItem(value);
  return true;
}


bool BasicItemFactory::createInteger(store::Item_t& result, const xqp_integer& value)
{
  result = new IntegerItem( value );
  return true;
}


bool BasicItemFactory::createNonPositiveInteger(
    store::Item_t& result,
    const xqp_integer& value)
{
  ZORBA_ASSERT(value <= Integer::parseInt(0));
  result = new NonPositiveIntegerItem( value );
  return true;
}


bool BasicItemFactory::createNegativeInteger(
    store::Item_t& result,
    const xqp_integer& value)
{
  ZORBA_ASSERT(value < xqp_integer::parseInt(0));
  result = new NegativeIntegerItem(value);
  return true;
}


bool BasicItemFactory::createNonNegativeInteger(
    store::Item_t& result,
    const xqp_uinteger& value )
{
  result = new NonNegativeIntegerItem( value );
  return true;
}



bool BasicItemFactory::createPositiveInteger(
    store::Item_t& result,
    const xqp_uinteger& value)
{
  ZORBA_ASSERT(value > Integer::parseInt(0));
  result = new PositiveIntegerItem( value );
  return true;
}


bool BasicItemFactory::createLong(store::Item_t& result,  xqp_long value)
{
  result = new LongItem(value);
  return true;
}


bool BasicItemFactory::createInt(store::Item_t& result,  xqp_int value)
{
  result = new IntItemNaive ( value );
  return true;
}


bool BasicItemFactory::createShort(store::Item_t& result,  xqp_short value)
{
  result = new ShortItemNaive ( value );
  return true;
}


bool BasicItemFactory::createByte(store::Item_t& result,  xqp_byte value)
{
  result = new ByteItemNaive ( value );
  return true;
}


bool BasicItemFactory::createUnsignedLong(store::Item_t& result, xqp_ulong value)
{
  result = new UnsignedLongItem(value);
  return true;
}


bool BasicItemFactory::createUnsignedInt(store::Item_t& result,  xqp_uint value)
{
  result = new UnsignedIntItemNaive( value );
  return true;
}


bool BasicItemFactory::createUnsignedShort(store::Item_t& result, xqp_ushort value)
{
  result = new UnsignedShortItemNaive( value );
  return true;
}


bool BasicItemFactory::createUnsignedByte(store::Item_t& result,  xqp_ubyte value)
{
  result = new UnsignedByteItemNaive ( value );
  return true;
}


bool BasicItemFactory::createBoolean(store::Item_t& result, xqp_boolean value)
{
  result = new BooleanItemNaive(value);
  return true;
}


bool BasicItemFactory::createBase64Binary(store::Item_t& result, xqp_base64Binary value)
{
  result = new Base64BinaryItemNaive ( value );
  return true;
}


bool BasicItemFactory::createDateTime(store::Item_t& result, const xqp_dateTime* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}

bool BasicItemFactory::createDateTime(
    store::Item_t& result,
    const xqp_date* date,
    const xqp_time* time)
{
  std::auto_ptr<DateTimeItemNaive> dtin(new DateTimeItemNaive());
  int err = DateTime::createDateTime(date, time, dtin->theValue);
  if (err == 0) 
  {
    result = dtin.get();
    dtin.release();
  } // destroy object if error occured
  return err == 0;
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
    if (! createDateTime(result, &date->getDateValue(), &time->getTimeValue())) 
      ZORBA_ERROR(FORG0008);
    
    return true;
  }
}


bool BasicItemFactory::createDate(store::Item_t& result, const xqp_date* value)
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createDate(
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


bool BasicItemFactory::createDuration(
    store::Item_t& result,
    xqp_duration* value )
{
  result = new DurationItemNaive(value);
  return true;
}


bool BasicItemFactory::createDuration(
    store::Item_t& result,
    const xqpStringStore_t& value)
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


bool BasicItemFactory::createYearMonthDuration(
    store::Item_t& result,
    xqp_yearMonthDuration* value )
{
  result = new DurationItemNaive(value);
  return true;
}


bool BasicItemFactory::createDayTimeDuration(store::Item_t& result, xqp_dayTimeDuration* value )
{
  result = new DurationItemNaive(value);
  return true;
}



bool BasicItemFactory::createHexBinary (store::Item_t& result,  xqp_hexBinary value )
{
  result = new HexBinaryItemNaive ( value ); 
  return true;
}


bool BasicItemFactory::createNOTATION(
    store::Item_t& result,
    xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}




/*******************************************************************************
  Create a new document node N and make it the root (and single node) of a new
  XML tree.

  baseUri       : The base-uri property of N. It may be NULL.
  docUri        : The document-uri property of N. It may be NULL.
********************************************************************************/
bool BasicItemFactory::createDocumentNode(
    store::Item_t&    result,
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri)
{
  XmlTree* xmlTree = NULL;
  DocumentNode* n = NULL;

  try
  {
    xmlTree = GET_STORE().getNodeFactory().createXmlTree();

    n = GET_STORE().getNodeFactory().createDocumentNode(xmlTree, baseUri, docUri);
  }
  catch (...)
  {
    delete xmlTree;
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
  isId          :
  isIdRefs      :
  localBindings : A set S1 of namespace bindings. The namespaces property of N
                  is set to S1, plus the ns binding implied by N's qname, plus
                  all the ns bindings of P that are not overwritten by S1 or the
                  ns binding implied by N's qname. Note: when called from an
                  element constructor iterator, S1 is the set of ns bindings
                  defined by ns decalration attrs that appear inside the 
                  constructor expr itself.
  baseUri       : The base-uri property of N. It may be NULL, in which case, 
                  the base-uri property of N is the same as that of P. If P
                  is NULL, then baseUri will NOT be null (see 
                  runtime/core/constructors.cpp).

  The haveTypedValue and haveEmptyValue properties are actually a function of
  the node's type. However, since the store stores only the name of the type
  and does not know anything about the definition of that type, the caller
  of this method must provide the value for these two properties, which are
  needed to implement the getTypedValue() method.
********************************************************************************/
bool BasicItemFactory::createElementNode(
    store::Item_t&              result,
    store::Item*                parent,
    long                        pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    bool                        haveTypedValue,
    bool                        haveEmptyValue,
    const store::NsBindings&    localBindings,
    xqpStringStore_t&           baseUri,
    bool                        isInSubstitutionGroup)
{
  XmlTree* xmlTree = NULL;
  ElementNode* n = NULL;

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();

    n = GET_STORE().getNodeFactory().createElementNode(
                        xmlTree,
                        pnode,
                        pos,
                        nodeName,
                        typeName,
                        haveTypedValue,
                        haveEmptyValue,
                        isInSubstitutionGroup,
                        &localBindings,
                        baseUri);
  }
  catch (...)
  {
    delete xmlTree;
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
  typedValue    : The typed-value property of N, for the case where the
                  typed-value is a single atomic value.
  isId          :
  isIdRefs      :
********************************************************************************/
bool BasicItemFactory::createAttributeNode(
    store::Item_t&  result,
    store::Item*    parent,
    long            pos,
    store::Item_t&  nodeName,
    store::Item_t&  typeName,
    store::Item_t&  typedValue)
{
  XmlTree* xmlTree = NULL;
  AttributeNode* n = NULL;

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode);

  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();
    }
    else
    {
      pnode->checkUniqueAttr(nodeName.getp());
    }

    n = GET_STORE().getNodeFactory().createAttributeNode(
                          xmlTree,
                          pnode,
                          pos,
                          nodeName,
                          typeName,
                          typedValue,
                          false,     // isListValue
                          false);    // hidden
  }
  catch (...)
  {
    delete xmlTree;
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
  typedValueV   : The typed-value property of N, for the case where the
                  typed-value is a sequence of atomic values.
  isId          :
  isIdRefs      :
********************************************************************************/
bool BasicItemFactory::createAttributeNode(
    store::Item_t&              result,
    store::Item*                parent,
    long                        pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    std::vector<store::Item_t>& typedValueV)
{
  XmlTree* xmlTree = NULL;
  AttributeNode* node = NULL;

  ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();
    }
    else
    {
      pnode->checkUniqueAttr(nodeName.getp());
    }

    store::Item_t typedValue = new ItemVector(typedValueV);
 
    node = GET_STORE().getNodeFactory().createAttributeNode(xmlTree,
                             pnode,
                             pos,
                             nodeName,
                             typeName,
                             typedValue,
                             true,     // isListValue
                             false);   // hidden
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = node;
  return node != NULL;
}


/*******************************************************************************
  Create a new text node N and place it as the pos-th child of a given parent
  node. If no parent is given, N becomes the root (and single node) of a
  new XML tree. If N is going to be placed next to an existing text node T,
  then no new text node is actually created, but instead the givan content 
  is concatanated with the content of T. 

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

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
    {
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();

      n = GET_STORE().getNodeFactory().createTextNode(xmlTree, pnode, pos, content);
    }
    else
    {
      ulong numChildren = pnode->numChildren();

      ulong pos2 = (pos >= 0 ? pos : numChildren);

      XmlNode* lsib = (pos2 > 0 ? pnode->getChild(pos2-1) : NULL);
      XmlNode* rsib = (pos2 + 1 < numChildren ? pnode->getChild(pos2) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == store::StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);

        ZORBA_ASSERT(!textSibling->isTyped());

        xqpStringStore_t content2 = textSibling->getText()->append(content);
        textSibling->setText(content2);

        result = lsib;
        return result != NULL;
      }
      else if (rsib != NULL && rsib->getNodeKind() == store::StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(rsib);

        ZORBA_ASSERT(!textSibling->isTyped());

        xqpStringStore_t content2 = content->append(textSibling->getText());
        textSibling->setText(content2);

        result = rsib;
        return result != NULL;
      }
      else
      {
        n = GET_STORE().getNodeFactory().createTextNode(xmlTree, pnode, pos, content);
      }
    }
  }
  catch (...)
  {
    delete xmlTree;
    throw;
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************
  Create a new text node N to store the typed value of a given element node P
  (the parent of N) that has simple type or complex type with simple content.
  P is not allowed to have any other text or element children. 

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
  result = GET_STORE().getNodeFactory().createTextNode(pnode, content, false);
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
  result = GET_STORE().getNodeFactory().createTextNode(pnode, typedValue, true);
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

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();

    n = GET_STORE().getNodeFactory().createPiNode(xmlTree, pnode, pos, target, content);
  }
  catch (...)
  {
    delete xmlTree;
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

  assert(parent == NULL ||
         parent->getNodeKind() == store::StoreConsts::elementNode ||
         parent->getNodeKind() == store::StoreConsts::documentNode);

  InternalNode* pnode = reinterpret_cast<InternalNode*>(parent);

  try
  {
    if (parent == NULL)
      xmlTree = GET_STORE().getNodeFactory().createXmlTree();

    n = GET_STORE().getNodeFactory().createCommentNode(xmlTree, pnode, pos, content);
  }
  catch (...)
  {
    delete xmlTree;
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

#if 0
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
#endif

/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createError(
          store::Item_t& result,
          error::ZorbaError* inError)
{
  result = new ErrorItemNaive(inError);
  return true;
}

} // namespace simplestore
} // namespace zorba

