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

#include "common/common.h"

#include "store/api/iterator.h"
#include "zorbaerrors/error_manager.h"
#include "system/globalenv.h"
#include "zorbaerrors/Assert.h"

#include "store/api/temp_seq.h"
#include "store/api/copymode.h"
#include "store/minimal/min_store_defs.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_item_factory.h"
#include "store/minimal/min_query_context.h"
#include "store/minimal/min_atomic_items.h"
#include "store/minimal/min_node_items.h"
#include "store/minimal/min_temp_seq.h"
#include "store/minimal/min_pul.h"
#include "store/minimal/qname_pool.h"
#include "store/api/collection.h"
#include "store/minimal/string_pool.h"
#include "zorbatypes/datetime.h"


namespace zorba { namespace store {

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
    Item_t& result,
    xqpStringStore* ns,
    xqpStringStore* pre,
    xqpStringStore* local,
    bool*           inserted)
{
  result = theQNamePool->insert(ns, pre, local, inserted);
  return true;
}


bool BasicItemFactory::createQName(
    Item_t& result,
    const char* ns,
    const char* pre,
    const char* ln)
{
  result = theQNamePool->insert(ns, pre, ln);
  return true;
}


bool BasicItemFactory::createNCName(Item_t& result, xqpStringStore_t& value)
{
  result = new NCNameItemImpl(value);
  return true;
}


bool BasicItemFactory::createAnyURI(Item_t& result, xqpStringStore_t& value)
{
  xqpStringStore_t str = value;
  theUriPool->insert(str, str);
  result =  new AnyUriItemImpl(str);
  return true;
}


bool BasicItemFactory::createAnyURI(Item_t& result, const char* value)
{
  xqpStringStore_t str;
  theUriPool->insertc(value, str);
  result = new AnyUriItemImpl(str);
  return true;
}


bool BasicItemFactory::createUntypedAtomic(Item_t& result, xqpStringStore_t& value)
{
  result = new UntypedAtomicItemImpl(value);
  return true;
}


bool BasicItemFactory::createString(Item_t& result, xqpStringStore_t& value)
{
  result = new StringItemNaive(value);
  return true;
}


bool BasicItemFactory::createBase64Binary(Item_t& result, xqp_base64Binary value)
{
  result = new Base64BinaryItemNaive ( value );
  return true;
}

bool BasicItemFactory::createBoolean(Item_t& result, xqp_boolean value)
{
  result = new BooleanItemNaive(value);
  return true;
}


bool BasicItemFactory::createDecimal(Item_t& result, xqp_decimal value)
{
  result = new DecimalItemNaive(value);
  return true;
}


bool BasicItemFactory::createInteger(Item_t& result, xqp_integer value)
{
  result = new IntegerItemNaive ( value );
  return true;
}


bool BasicItemFactory::createLong (Item_t& result,  xqp_long value )
{
  result = new LongItemNaive ( value );
  return true;
}


bool BasicItemFactory::createInt (Item_t& result,  xqp_int value )
{
  result = new IntItemNaive ( value );
  return true;
}


bool BasicItemFactory::createShort (Item_t& result,  xqp_short value )
{
  result = new ShortItemNaive ( value );
  return true;
}


bool BasicItemFactory::createByte (Item_t& result,  xqp_byte value )
{
  result = new ByteItemNaive ( value );
  return true;
}

bool BasicItemFactory::createDate(Item_t& result, xqp_date& value)
{
  result = new DateTimeItemNaive(value);
  return true;
}

bool BasicItemFactory::createDate (
    Item_t& result,
    short year,
    short month,
    short day )
{
  DateTime_t dt_t;
  TimeZone_t tz_t;
  
  if(DateTime::createDate(year, month, day, tz_t, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createDate (Item_t& result,  const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseDate(value, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createDateTime(Item_t& result, xqp_dateTime& value)
{
  result = new DateTimeItemNaive(value);
  return true;
}

bool BasicItemFactory::createDateTime(
    Item_t& result,
    short   year,
    short   month,
    short   day,
    short   hour,
    short   minute,
    double  second)
{
  DateTime_t dt_t;
  TimeZone_t tz_t;
  
  if(DateTime::createDateTime(year, month, day, hour, minute, second, tz_t, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createDateTime(
    Item_t& result,
    short   year ,
    short   month,
    short   day,
    short   hour,
    short   minute,
    double  second,
    short   timeZone_hours)
{
  DateTime_t dt_t;
  TimeZone_t tz_t = new TimeZone( timeZone_hours );

  if (DateTime::createDateTime(year, month, day, hour, minute, second, tz_t, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createDateTime ( Item_t& result, const xqp_string& value )
{
  DateTime_t dt_t;
  
  if ( DateTime::parseDateTime(value, dt_t) == 0 ) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createDateTime (Item_t& result, const Item_t& date, const Item_t& time)
{
  if (date.isNull() || time.isNull()) {
    result = NULL;
    return false;
  } else
  {
    if (2 == DateTimeItemNaive::createFromDateAndTime(date->getDateValue(), time->getTimeValue(), result))
      ZORBA_ERROR(FORG0008);
    
    return true;
  }
}

bool BasicItemFactory::createDouble (Item_t& result,  xqp_double value )
{
  result = new DoubleItemNaive( value );
  return true;
}

bool BasicItemFactory::createDuration (Item_t& result, xqp_duration& value )
{
  result = new DurationItemNaive(value);
  return true;
}

bool BasicItemFactory::createDuration (Item_t& result,  const xqp_string& value )
{
  YearMonthDuration_t ymd_t;
  DayTimeDuration_t   dtd_t;
  
  if( YearMonthDuration::parse_string(value, ymd_t) ){
    xqp_duration d = ymd_t;
    result = new DurationItemNaive(d);
    return true;
  }
  else if( DayTimeDuration::parse_string(value, dtd_t) ){
    xqp_duration d = ymd_t;
    result = new DurationItemNaive(d);
    return true;
  }

  result = NULL;
  return false;
}

bool BasicItemFactory::createDuration (
    Item_t& result,
    short   years,
    short   months,
    short   days,
    short   hours,
    short   minutes,
    double  seconds)
{
  if( years != 0 || months!=0 ){
    YearMonthDuration_t ymd_t = new YearMonthDuration(years*12 + months);
    xqp_duration d = ymd_t;
    result = new DurationItemNaive(d);
    return true;
  }
  else if( days!=0 || hours!=0 || minutes!=0 || seconds!=0 ) {
    DayTimeDuration_t dtd_t = new DayTimeDuration(days, hours, minutes, seconds);
    xqp_duration d = dtd_t;
    result = new DurationItemNaive(d); 
    return false;
  }
  result = NULL;
  return false;
}


bool BasicItemFactory::createENTITIES(Item_t& result, xqpStringStore_t& /*value*/)
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createENTITY(Item_t& result, xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createFloat (Item_t& result,  xqp_float value )
{
  result = new FloatItemNaive( value );
  return true;
}

bool BasicItemFactory::createGDay (Item_t& result, xqp_gDay& value )
{
  result = new DateTimeItemNaive(value);
  return true;
}


bool BasicItemFactory::createGDay (Item_t& result,  const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGDay(value, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createGDay (Item_t& result,  short day )
{
  DateTime_t dt_t;
  
  if (DateTime::createGDay(day, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createGMonth(Item_t& result, xqp_gMonth& value )
{
  result = new DateTimeItemNaive(value);
  return true;
}

bool BasicItemFactory::createGMonth (Item_t& result,  const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGMonth(value, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createGMonth (Item_t& result,  short month )
{
  DateTime_t dt_t;

  if(DateTime::createGMonth(month, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createGMonthDay (Item_t& result, xqp_gMonthDay& value)
{
  result = new DateTimeItemNaive(value);
  return true;
}

bool BasicItemFactory::createGMonthDay (Item_t& result,  const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGMonthDay(value, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createGMonthDay (Item_t& result,  short month, short day )
{
  DateTime_t dt_t;

  if(DateTime::createGMonthDay(month, day, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createGYear (Item_t& result, xqp_gYear& value )
{
  result = new DateTimeItemNaive(value);
  return true;
}

bool BasicItemFactory::createGYear (Item_t& result,  const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGYear(value, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createGYear (Item_t& result,  short year )
{
  DateTime_t dt_t;

  if(DateTime::createGYear(year, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createGYearMonth (Item_t& result, xqp_gYearMonth& value )
{
  result = new DateTimeItemNaive(value);
  return true;
}

bool BasicItemFactory::createGYearMonth (Item_t& result,  const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGYearMonth(value, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createGYearMonth (Item_t& result,  short year, short month )
{
  DateTime_t dt_t;

  if(DateTime::createGYearMonth(year, month, dt_t) == 0) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}


bool BasicItemFactory::createHexBinary (Item_t& result,  xqp_hexBinary value )
{
  result = new HexBinaryItemNaive ( value ); 
  return true;
}


bool BasicItemFactory::createID(Item_t& result, xqpStringStore_t& value)
{
  result = new IDItemImpl(value);
  return true;
}


bool BasicItemFactory::createIDREF(Item_t& result, xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}


bool BasicItemFactory::createIDREFS(Item_t& result, xqpStringStore_t& /*value*/ )
{ result = NULL; return false; }


bool BasicItemFactory::createLanguage(Item_t& result, xqpStringStore_t& /*value*/ )
{ result = NULL; return false; }


bool BasicItemFactory::createNMTOKEN(Item_t& result, xqpStringStore_t& /*value*/ )
{ result = NULL; return false; }


bool BasicItemFactory::createNMTOKENS(Item_t& result, xqpStringStore_t& /*value*/ )
{ result = NULL; return false; }


bool BasicItemFactory::createNOTATION(Item_t& result, xqpStringStore_t& /*value*/ )
{ result = NULL; return false; }


bool BasicItemFactory::createName(Item_t& result, xqpStringStore_t& /*value*/ )
{ result = NULL; return false; }


bool BasicItemFactory::createNegativeInteger (Item_t& result,  xqp_integer value )
{
  ZORBA_ASSERT(value < xqp_integer::parseInt(0));
  result = new NegativeIntegerItemNaive ( value );
  return true;
}


bool BasicItemFactory::createNonNegativeInteger (Item_t& result,  xqp_uinteger value )
{
  result = new NonNegativeIntegerItemNaive ( value );
  return true;
}


bool BasicItemFactory::createNonPositiveInteger (Item_t& result,  xqp_integer value )
{
  ZORBA_ASSERT(value <= Integer::parseInt(0));
  result = new NonPositiveIntegerItemNaive( value );
  return true;
}


bool BasicItemFactory::createNormalizedString(Item_t& result, xqpStringStore_t& value)
{ result = NULL; return false; }


bool BasicItemFactory::createPositiveInteger (Item_t& result,  xqp_uinteger value ) {
  ZORBA_ASSERT(value > Integer::parseInt(0));
  result = new PositiveIntegerItemNaive( value );
  return true;
}

bool BasicItemFactory::createTime(Item_t& result, xqp_time& value)
{
  result = new DateTimeItemNaive(value);
  return true;
}

bool BasicItemFactory::createTime(Item_t& result, const xqp_string& value)
{
  DateTime_t dt_t;
  
  if( DateTime::parseTime(value, dt_t) == 0 ) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createTime(
    Item_t& result,
    short   hour,
    short   minute,
    double  second)
{
  DateTime_t dt_t;
  TimeZone_t tz_t;
  
  if( DateTime::createTime(hour, minute, second, tz_t, dt_t) == 0 ) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createTime(
    Item_t& result,
    short   hour,
    short   minute,
    double  second,
    short   timeZone_hours)
{
  DateTime_t dt_t;
  TimeZone_t tz_t = new TimeZone(timeZone_hours);
  
  if( DateTime::createTime(hour, minute, second, tz_t, dt_t) == 0 ) {
    result = new DateTimeItemNaive(dt_t);
    return true;
  } else {
    result = NULL;
    return false;
  }
}

bool BasicItemFactory::createToken(Item_t& result, xqpStringStore_t& /*value*/ )
{
  result = NULL;
  return false;
}

bool BasicItemFactory::createUnsignedByte (Item_t& result,  xqp_ubyte value )
{
  result = new UnsignedByteItemNaive ( value );
  return true;
}

bool BasicItemFactory::createUnsignedInt (Item_t& result,  xqp_uint value )
{
  result = new UnsignedIntItemNaive( value );
  return true;
}

bool BasicItemFactory::createUnsignedLong(Item_t& result, xqp_ulong value)
{
  result = new UnsignedLongItemNaive( value );
  return true;
}

bool BasicItemFactory::createUnsignedShort(Item_t& result, xqp_ushort value)
{
  result = new UnsignedShortItemNaive( value );
  return true;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createDocumentNode(
    Item_t& result,
    unsigned long     qid,
    xqpStringStore_t& baseUri,
    Iterator*         childrenIter,
    bool              isRoot,
    bool              assignIds,
    bool              copy,
    const CopyMode&   copymode)
{
  XmlTree* xmlTree = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);
  ConstrDocumentNode* n = NULL;
  xqpStringStore_t docUri;

  assert(isRoot);

  bool topRoot = ctx.empty();

  try
  {
    xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
    xmlTree->addReference();

    n = new ConstrDocumentNode(xmlTree, assignIds, baseUri, docUri);

    if (childrenIter != NULL)
    {
      ctx.push(n);
      
      n->constructSubtree(childrenIter, copy, copymode);

      ctx.pop();
    }
  }
  catch (...)
  {
    if (xmlTree)
    {
      xmlTree->removeReference();
      xmlTree->free();
      if (topRoot)
      {
        ctx.clear();
        GET_STORE().deleteQueryContext(qid);
      }
    }

    throw;
  }

  if (xmlTree)
  {
    xmlTree->removeReference();
    if (topRoot)
    {
      ZORBA_FATAL(ctx.empty(), "");
      GET_STORE().deleteQueryContext(qid);
    }
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createElementNode(
    Item_t& result,
    unsigned long     qid,
    Item_t&           name,
    Item_t&           typeName,
    Iterator*         childrenIter,
    Iterator*         attrsIter,
    Iterator*         nsIter,
    const NsBindings& localBindings,
    xqpStringStore_t& baseUri,
    bool              isRoot,
    bool              assignIds,
    bool              copy,
    const CopyMode&   copymode)
{
  XmlTree* xmlTree = NULL;
  XmlNode* parent = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);
  ConstrElementNode* n = NULL;

  ZORBA_FATAL(isRoot || !ctx.empty(), "");

  bool topRoot = ctx.empty();

  try
  {
    // We are at the root of a top-level node-constructor expr, or at the root
    // of a node-constructor expr that is inside an enclosed expr.
    if (isRoot)
    {
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
      xmlTree->addReference();

      n = new ConstrElementNode(xmlTree, assignIds, name, typeName);
    }

    // We are at a node-constructor expr directly nested inside another
    // node-constructor expr.
    else
    {
      parent = ctx.top();

      n = new ConstrElementNode(parent, name, typeName);
    }

    ctx.push(n);

    n->constructSubtree(attrsIter, childrenIter, localBindings,
                        baseUri, isRoot, copy, copymode);

    ctx.pop();
  }
  catch (...)
  {
    if (xmlTree)
    {
      xmlTree->removeReference();
      xmlTree->free();
      if (topRoot)
      {
        ctx.clear();
        GET_STORE().deleteQueryContext(qid);
      }
    }
    throw;
  }

  if (xmlTree)
  {
    xmlTree->removeReference();
    if (topRoot)
    {
      ZORBA_FATAL(ctx.empty(), "");
      GET_STORE().deleteQueryContext(qid);
    }
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createAttributeNode(
    Item_t& result,
    ulong           qid,
    Iterator*       nameIter,
    Item_t&         typeName,
    Iterator*       valueIter,
    bool            isRoot,
    bool            assignIds)
{
  XmlTree* xmlTree = NULL;
  ElementNode* parent = NULL;
  AttributeNode* n = NULL;
  Item_t name;
  Item_t typedValue;
  xqpStringStore_t lexicalValue;
  Item_t valueItem;

  // Compute the attribute name. Note: we don't have to check that itemQName
  // is indeed a valid qname, because the compiler wraps an xs:qname cast
  // around thIteme expression.
  nameIter->open();
  nameIter->next(name);

  if (name->getLocalName()->empty())
  {
    ZORBA_ERROR_DESC(XQDY0074,
                     "Attribute name must not have an empty local part.");
  }
  
  if (name->getNamespace()->byteEqual("http://www.w3.org/2000/xmlns/", 29) ||
      (name->getNamespace()->empty() &&
       name->getLocalName()->byteEqual("xmlns", 5)))
  {
    ZORBA_ERROR(XQDY0044);
  }
  nameIter->close();

  // Compute the attribute value.
  valueIter->open();
  if (valueIter->next(valueItem))
  {
    lexicalValue = valueItem->getStringValue();

    std::string buf;
    while (valueIter->next(valueItem))
    {
      buf += valueItem->getStringValue()->str();
    }
    if (!buf.empty())
      lexicalValue = lexicalValue->append(buf);
  }
  else
  {
    lexicalValue = new xqpStringStore("");
  }
  valueIter->close();
  
  typedValue = new UntypedAtomicItemImpl(lexicalValue);

  QueryContext& ctx = GET_STORE().getQueryContext(qid);

  ZORBA_FATAL(isRoot || !ctx.empty(), "");

  bool topRoot = ctx.empty();

  try
  {
    // We are at the root of a top-level node-constructor expr, or at the root
    // of a node-constructor expr that is inside an enclosed expr.
    if (isRoot)
    {
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
      xmlTree->addReference();

      n = new AttributeNode(xmlTree, assignIds, name, typeName, typedValue, false);
    }

    // We are at a node-constructor expr directly nested inside another
    // node-constructor expr.
    else
    {
      parent = reinterpret_cast<ElementNode*>(ctx.top());

      parent->checkUniqueAttr(name.getp());

      n = new AttributeNode(parent, name, typeName, typedValue, false);
    }
  }
  catch (...)
  {
    if (xmlTree)
    {
      xmlTree->removeReference();
      xmlTree->free();
      if (topRoot)
      {
        ctx.clear();
        GET_STORE().deleteQueryContext(qid);
      }
    }
    throw;
  }

  if (xmlTree)
  {
    xmlTree->removeReference();
    if (topRoot)
    {
      ZORBA_FATAL(ctx.empty(), "");
      GET_STORE().deleteQueryContext(qid);
    }
  }  

  result = n;
  return n != NULL;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createTextNode(
    Item_t& result,
    unsigned long     qid,
    xqpStringStore_t& content,
    bool              isRoot,
    bool              assignIds)
{
  XmlTree* xmlTree = NULL;
  XmlNode* parent = NULL;
  TextNode* n = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);

  // This assertion does not hold in the case of text nodes created by the
  // source expr of an insert expr.
  // ZORBA_FATAL(isRoot || !ctx.empty(), "");

  bool topRoot = ctx.empty();
  if (topRoot)
    isRoot = true;

  try
  {
    // We are at the root of a top-level node-constructor expr, or at the root
    // of a node-constructor expr that is inside an enclosed expr. 
    if (isRoot)
    {
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
      xmlTree->addReference();

      n = new TextNode(xmlTree, assignIds, content);
    }

    // We are at a node-constructor expr directly nested inside another
    // node-constructor expr.
    else
    {
      parent = ctx.top();

      ulong pos = parent->numChildren();
      XmlNode* lsib = (pos > 0 ? parent->getChild(pos-1) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);
        textSibling->theContent = textSibling->theContent->append(content.getp());
        result = lsib;
        return result != NULL;
      }
 
      n = new TextNode(parent, content);
    }
  }
  catch (...)
  {
    if (xmlTree)
    {
      xmlTree->removeReference();
      xmlTree->free();
      if (topRoot)
      {
        ctx.clear();
        GET_STORE().deleteQueryContext(qid);
      }
    }
    throw;
  }

  if (xmlTree)
  {
    xmlTree->removeReference();
    if (topRoot)
    {
      ZORBA_FATAL(ctx.empty(), "");
      GET_STORE().deleteQueryContext(qid);
    }
  }

  result = n;
  return n != NULL;
}


bool BasicItemFactory::createTextNode(
    Item_t& result,
    unsigned long   qid,
    Iterator*       valueIter,
    bool            isRoot,
    bool            assignIds)
{
  // We must compute the value of the node before the node itself because
  // if the value is the empty sequence, no text node should be constructed.

  xqpStringStore_t value;
  Item_t valueItem;

  if (valueIter->next(valueItem))
  {
    value = (valueItem->isAtomic() ?
             valueItem->getStringValue() :
             valueItem->getAtomizationValue()->getStringValue());

    std::string buf;
    while (valueIter->next(valueItem))
    {
      buf += " ";
      buf += (valueItem->isAtomic() ?
              valueItem->getStringValue()->c_str() :
              valueItem->getAtomizationValue()->getStringValue()->str());

    }
    if (!buf.empty())
      value = value->append(buf);
  }
  else
  {
    result = NULL;
    return false;
  }

  return createTextNode(result, qid, value, isRoot, assignIds);
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createPiNode(
    Item_t& result,
    unsigned long     qid,
    xqpStringStore_t& target,
    xqpStringStore_t& content,
    bool              isRoot,
    bool              assignIds)
{
  XmlTree* xmlTree = NULL;
  XmlNode* parent = NULL;
  PiNode* n = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);

  ZORBA_FATAL(isRoot || !ctx.empty(), "");

  bool topRoot = ctx.empty();

  try
  {
    // We are at the root of a top-level node-constructor expr, or at the root
    // of a node-constructor expr that is inside an enclosed expr.
    if (isRoot)
    {
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
      xmlTree->addReference();

      n = new PiNode(xmlTree, assignIds, target, content);
    }

    // We are at a node-constructor expr directly nested inside another
    // node-constructor expr.
    else
    {
      parent = ctx.top();

      n = new PiNode(parent, target, content);
    }
  }
  catch (...)
  {
    if (xmlTree)
    {
      xmlTree->removeReference();
      xmlTree->free();
      if (topRoot)
      {
        ctx.clear();
        GET_STORE().deleteQueryContext(qid);
      }
    }
    throw;
  }

  if (xmlTree)
  {
    xmlTree->removeReference();
    if (topRoot)
    {
      ZORBA_FATAL(ctx.empty(), "");
      GET_STORE().deleteQueryContext(qid);
    }
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************

********************************************************************************/
bool BasicItemFactory::createCommentNode(
    Item_t& result,
    unsigned long     qid,
    xqpStringStore_t& content,
    bool              isRoot,
    bool              assignIds)
{
  XmlTree* xmlTree = NULL;
  XmlNode* parent = NULL;
  CommentNode* n = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);

  ZORBA_FATAL(isRoot || !ctx.empty(), "");

  bool topRoot = ctx.empty();

  try
  {
    // We are at the root of a top-level node-constructor expr, or at the root
    // of a node-constructor expr that is inside an enclosed expr. 
    if (isRoot)
    {
      xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
      xmlTree->addReference();

      n = new CommentNode(xmlTree, assignIds, content);
    }

    // We are at a node-constructor expr directly nested inside another
    // node-constructor expr.
    else
    {
      parent = ctx.top();

      n = new CommentNode(parent, content);
    }
  }
  catch (...)
  {
    if (xmlTree)
    {
      xmlTree->removeReference();
      xmlTree->free();
      if (topRoot)
      {
        ctx.clear();
        GET_STORE().deleteQueryContext(qid);
      }
    }
    throw;
  }

  if (xmlTree)
  {
    xmlTree->removeReference();
    if (topRoot)
    {
      ZORBA_FATAL(ctx.empty(), "");
      GET_STORE().deleteQueryContext(qid);
    }
  }

  result = n;
  return n != NULL;
}


/*******************************************************************************

********************************************************************************/
PUL* BasicItemFactory::createPendingUpdateList()
{
  return new PULImpl();
}


} // namespace store
} // namespace zorba

