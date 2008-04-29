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
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "util/Assert.h"

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
//#include "store/naive/qname_pool.h"
#include "store/api/collection.h"
//#include "store/naive/string_pool.h"
#include "zorbatypes/datetime.h"


namespace zorba { namespace store {

BasicItemFactory::BasicItemFactory()//UriPool* uriPool, QNamePool* qnPool)
//  :
//  theUriPool(uriPool),
//  theQNamePool(qnPool)
{
}


BasicItemFactory::~BasicItemFactory()
{
//  theQNamePool = NULL;
//  theUriPool = NULL;
}


Item_t BasicItemFactory::createQName(
    xqpStringStore* ns,
    xqpStringStore* pre,
    xqpStringStore* local,
    bool*           inserted
    )
{
//  return theQNamePool->insert(ns, pre, local, inserted);
  if(inserted)
    *inserted = true;
  return new QNameItemImpl(ns, pre, local);
}


Item_t BasicItemFactory::createQName(
    const char* ns,
    const char* pre,
    const char* ln)
{
//  return theQNamePool->insert(ns, pre, ln);
  return new QNameItemImpl(ns, pre, ln);
}


Item_t BasicItemFactory::createNCName(xqpStringStore* value)
{
  return new NCNameItemImpl(value);
}


Item_t BasicItemFactory::createAnyURI(xqpStringStore* value)
{
//  xqpStringStore_t str = value;
//  theUriPool->insert(str, str);
  return new AnyUriItemImpl(value);
}


Item_t BasicItemFactory::createAnyURI(const char* value)
{
//  xqpStringStore_t str;
//  theUriPool->insertc(value, str);
  return new AnyUriItemImpl(new xqpStringStore(value));
}


Item_t BasicItemFactory::createUntypedAtomic(xqpStringStore* value)
{
  return new UntypedAtomicItemImpl(value);
}


Item_t BasicItemFactory::createString(xqpStringStore* value)
{
  return new StringItemNaive(value);
}


Item_t BasicItemFactory::createBase64Binary(xqp_base64Binary value)
{
  return new Base64BinaryItemNaive ( value );
}



Item_t BasicItemFactory::createBoolean(xqp_boolean value)
{
  return new BooleanItemNaive(value);
}


Item_t BasicItemFactory::createDecimal(xqp_decimal value)
{
  return new DecimalItemNaive(value);
}


Item_t BasicItemFactory::createInteger(xqp_integer value)
{
  return new IntegerItemNaive ( value );
}


Item_t BasicItemFactory::createLong ( xqp_long value )
{
  return new LongItemNaive ( value );
}


Item_t BasicItemFactory::createInt ( xqp_int value )
{
  return new IntItemNaive ( value );
}


Item_t BasicItemFactory::createShort ( xqp_short value )
{
  return new ShortItemNaive ( value );
}


Item_t BasicItemFactory::createByte ( xqp_byte value )
{
  return new ByteItemNaive ( value );
}

Item_t BasicItemFactory::createDate(xqp_date& value)
{
  return new DateTimeItemNaive(value);
}

Item_t BasicItemFactory::createDate ( 
                                     short year, 
                                     short month, 
                                     short day )
{
  DateTime_t dt_t;
  TimeZone_t tz_t;
  
  if(DateTime::createDate(year, month, day, tz_t, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t ( NULL );
}

Item_t BasicItemFactory::createDate ( const xqp_string& value )
{
  DateTime_t dt_t;
  if (DateTime::parseDate(value, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createDateTime(xqp_dateTime& value)
{
  return new DateTimeItemNaive(value);
}

Item_t BasicItemFactory::createDateTime(
    short year,
    short month,
    short day,
    short hour,
    short minute,
    double second)
{
  DateTime_t dt_t;
  TimeZone_t tz_t;
  
  if(DateTime::createDateTime(year, month, day, hour, minute, second, tz_t, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t ( NULL );
}


Item_t BasicItemFactory::createDateTime(
    short year ,
    short month,
    short day,
    short hour,
    short minute,
    double  second,
    short   timeZone_hours)
{
  DateTime_t dt_t;
  TimeZone_t tz_t = new TimeZone( timeZone_hours );

  if (DateTime::createDateTime(year, month, day, hour, minute, second, tz_t, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createDateTime ( const xqp_string& value )
{
  DateTime_t dt_t;
  if (DateTime::parseDateTime(value, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createDateTime (const Item_t& date, const Item_t& time)
{
  if (date.isNull() || time.isNull())
    return Item_t(NULL);
  else
  {
    Item_t item;
    
    if (2 == DateTimeItemNaive::createFromDateAndTime(date->getDateValue(), time->getTimeValue(), item))
      ZORBA_ERROR(ZorbaError::FORG0008);
    
    return item;
  }
}

Item_t BasicItemFactory::createDouble ( xqp_double value )
{
  return new DoubleItemNaive( value );
}

Item_t BasicItemFactory::createDuration (xqp_duration& value )
{
  return new DurationItemNaive(value);
}

Item_t BasicItemFactory::createDuration ( const xqp_string& value )
{
  YearMonthDuration_t ymd_t;
  DayTimeDuration_t   dtd_t;
  
  if (YearMonthDuration::parse_string(value, ymd_t)){
    xqp_duration d = ymd_t;
    return new DurationItemNaive(d);
  }
  else if(DayTimeDuration::parse_string(value, dtd_t)){
    xqp_duration d = ymd_t;
    return new DurationItemNaive(d);
  }

  return Item_t(NULL);
}

Item_t BasicItemFactory::createDuration (
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
    return new DurationItemNaive(d);
  }
  else if( days!=0 || hours!=0 || minutes!=0 || seconds!=0 ) {
    DayTimeDuration_t dtd_t = new DayTimeDuration(days, hours, minutes, seconds);
    xqp_duration d = dtd_t;
    return new DurationItemNaive(d); 
  }
  else
    return Item_t ( NULL );
}

Item_t BasicItemFactory::createENTITIES ( const xqp_string& /*value*/ )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createENTITY ( const xqp_string& /*value*/ )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createFloat ( xqp_float value )
{
  return new FloatItemNaive( value );
}

Item_t BasicItemFactory::createGDay (xqp_gDay& value )
{
  return new DateTimeItemNaive(value);
}

Item_t BasicItemFactory::createGDay ( const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGDay(value, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createGDay ( short day )
{
  DateTime_t dt_t;
  
  if (DateTime::createGDay(day, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createGMonth(xqp_gMonth& value )
{
  return new DateTimeItemNaive(value);
}

Item_t BasicItemFactory::createGMonth ( const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGMonth(value, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createGMonth ( short month )
{
  DateTime_t dt_t;

  if(DateTime::createGMonth(month, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t ( NULL );
}

Item_t BasicItemFactory::createGMonthDay (xqp_gMonthDay& value)
{
  return new DateTimeItemNaive(value);
}

Item_t BasicItemFactory::createGMonthDay ( const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGMonthDay(value, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createGMonthDay ( short month, short day )
{
  DateTime_t dt_t;

  if(DateTime::createGMonthDay(month, day, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t ( NULL );
}

Item_t BasicItemFactory::createGYear (xqp_gYear& value )
{
  return new DateTimeItemNaive(value);
}

Item_t BasicItemFactory::createGYear ( const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGYear(value, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}


Item_t BasicItemFactory::createGYear ( short year )
{
  DateTime_t dt_t;

  if(DateTime::createGYear(year, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t ( NULL );
}

Item_t BasicItemFactory::createGYearMonth (xqp_gYearMonth& value )
{
  return new DateTimeItemNaive(value);
}

Item_t BasicItemFactory::createGYearMonth ( const xqp_string& value )
{
  DateTime_t dt_t;
  
  if (DateTime::parseGYearMonth(value, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createGYearMonth ( short year, short month )
{
  DateTime_t dt_t;

  if(DateTime::createGYearMonth(year, month, dt_t) == 0)
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t ( NULL );
}


Item_t BasicItemFactory::createHexBinary ( xqp_hexBinary value )
{ return new HexBinaryItemNaive ( value ); }


Item_t BasicItemFactory::createID ( const xqp_string& /*value*/ )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createIDREF ( const xqp_string& /*value*/ )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createIDREFS ( const xqp_string& /*value*/ )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createLanguage ( const xqp_string& /*value*/ )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createNMTOKEN ( const xqp_string& /*value*/ )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createNMTOKENS ( const xqp_string& /*value*/ )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createNOTATION ( const xqp_string& /*value*/ )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createName ( const xqp_string& /*value*/ )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createNegativeInteger ( xqp_integer value )
{
  ZORBA_ASSERT(value < xqp_integer::parseInt(0));
  return new NegativeIntegerItemNaive ( value );
}


Item_t BasicItemFactory::createNonNegativeInteger ( xqp_uinteger value )
{
  return new NonNegativeIntegerItemNaive ( value );
}


Item_t BasicItemFactory::createNonPositiveInteger ( xqp_integer value )
{
  ZORBA_ASSERT(value <= Integer::parseInt(0));
  return new NonPositiveIntegerItemNaive( value );
}


Item_t BasicItemFactory::createNormalizedString ( const xqp_string& value )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createPositiveInteger ( xqp_uinteger value ) {
  ZORBA_ASSERT(value > Integer::parseInt(0));
  return new PositiveIntegerItemNaive( value );
}

Item_t BasicItemFactory::createTime(xqp_time& value)
{
  return new DateTimeItemNaive(value);
}

Item_t BasicItemFactory::createTime(const xqp_string& value)
{
  DateTime_t dt_t;
  
  if( DateTime::parseTime(value, dt_t) == 0 )
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t(NULL);
}

Item_t BasicItemFactory::createTime(
    short   hour,
    short   minute,
    double  second)
{
  DateTime_t dt_t;
  TimeZone_t tz_t;
  
  if( DateTime::createTime(hour, minute, second, tz_t, dt_t) == 0 )
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t ( NULL );
}

Item_t BasicItemFactory::createTime(
    short   hour,
    short   minute,
    double  second,
    short   timeZone_hours)
{
  DateTime_t dt_t;
  TimeZone_t tz_t = new TimeZone(timeZone_hours);
  
  if( DateTime::createTime(hour, minute, second, tz_t, dt_t) == 0 )
    return new DateTimeItemNaive(dt_t);
  else
    return Item_t ( NULL );
}

Item_t BasicItemFactory::createToken ( const xqp_string& /*value*/ )
{
  return Item_t ( NULL );
}

Item_t BasicItemFactory::createUnsignedByte ( xqp_ubyte value )
{
  return new UnsignedByteItemNaive ( value );
}

Item_t BasicItemFactory::createUnsignedInt ( xqp_uint value )
{
  return new UnsignedIntItemNaive( value );
}

Item_t BasicItemFactory::createUnsignedLong(xqp_ulong value)
{
  return new UnsignedLongItemNaive( value );
}

Item_t BasicItemFactory::createUnsignedShort(xqp_ushort value)
{
  return new UnsignedShortItemNaive( value );
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createDocumentNode(
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
      ctx.clear();
      GET_STORE().deleteQueryContext(qid);
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

  return n;
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createElementNode(
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
      ctx.clear();
      GET_STORE().deleteQueryContext(qid);
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

  return n;
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createAttributeNode(
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

  // Compute the attribute name. Note: we don't have to check that itemQName
  // is indeed a valid qname, because the compiler wraps an xs:qname cast
  // around thIteme expression.
  name = nameIter->next();

  if (name->getLocalName()->empty())
  {
    ZORBA_ERROR_DESC(ZorbaError::XQDY0074,
                     "Attribute name must not have an empty local part.");
  }
  
  if (name->getNamespace()->byteEqual("http://www.w3.org/2000/xmlns/", 29) ||
      (name->getNamespace()->empty() &&
       name->getLocalName()->byteEqual("xmlns", 5)))
  {
    ZORBA_ERROR(ZorbaError::XQDY0044);
  }

  // Compute the attribute value.
  Item_t valueItem = valueIter->next();
  if (valueItem != 0)
  {
    lexicalValue = valueItem->getStringValue();

    std::string buf;
    valueItem = valueIter->next();
    while (valueItem != NULL)
    {
      buf += valueItem->getStringValue()->str();
      valueItem = valueIter->next();
    }
    if (!buf.empty())
      lexicalValue = lexicalValue->append(buf);
  }
  else
  {
    lexicalValue = new xqpStringStore("");
  }
  
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
      ctx.clear();
      GET_STORE().deleteQueryContext(qid);
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

  return n;
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createTextNode(
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
        return lsib;
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
      ctx.clear();
      GET_STORE().deleteQueryContext(qid);
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

  return n;
}


Item_t BasicItemFactory::createTextNode(
    unsigned long   qid,
    Iterator*       valueIter,
    bool            isRoot,
    bool            assignIds)
{
  // We must compute the value of the node before the node itself because
  // if the value is the empty sequence, no text node should be constructed.
  xqpStringStore_t value;
  Item_t valueItem = valueIter->next();
  if (valueItem != 0)
  {
    value = valueItem->getAtomizationValue()->getStringValue();

    std::string buf;
    valueItem = valueIter->next();
    while (valueItem != NULL)
    {
      buf += " ";
      buf += valueItem->getAtomizationValue()->getStringValue()->str();

      valueItem = valueIter->next();
    }
    if (!buf.empty())
      value = value->append(buf);
  }
  else
  {
    return NULL;
  }

  return createTextNode(qid, value, isRoot, assignIds);
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createPiNode(
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
      ctx.clear();
      GET_STORE().deleteQueryContext(qid);
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

  return n;
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createCommentNode(
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
      ctx.clear();
      GET_STORE().deleteQueryContext(qid);
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

  return n;
}


/*******************************************************************************

********************************************************************************/
PUL* BasicItemFactory::createPendingUpdateList()
{
  return new PULImpl();
}


} // namespace store
} // namespace zorba

