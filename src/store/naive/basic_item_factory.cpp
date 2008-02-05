/* -*- mode: c++ { return Item_t(NULL); } indent-tabs-mode: nil { return Item_t(NULL); } tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com), Donald Kossmann, Tim Kraska
 *`
 */

#include "store/api/temp_seq.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/query_context.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/simple_temp_seq.h"
#include "store/naive/qname_pool.h"
#include "store/util/string_pool.h"

namespace xqp
{

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


Item_t BasicItemFactory::createQName(
    const xqpStringStore_t& ns,
    const xqpStringStore_t& pre,
    const xqpStringStore_t& local)
{
  return theQNamePool->insert(ns, pre, local);
}


Item_t BasicItemFactory::createQName(
    const xqp_string& ns,
    const xqp_string& pre,
    const xqp_string& local)
{
  xqpStringStore_t ns_t(ns.getStore());
  xqpStringStore_t pre_t(pre.getStore());
  xqpStringStore_t local_t(local.getStore());

  return theQNamePool->insert(ns_t, pre_t, local_t);
}


Item_t BasicItemFactory::createQName(
    const char* ns,
    const char* pre,
    const char* ln)
{
  return theQNamePool->insert(ns, pre, ln);
}


Item_t BasicItemFactory::createNCName(xqpStringStore* value)
{
  return new NCNameItemImpl(value);
}


Item_t BasicItemFactory::createNCName(const xqp_string& value)
{
  return new NCNameItemImpl(value.getStore());
}


Item_t BasicItemFactory::createAnyURI(const xqpStringStore_t& value)
{
  theUriPool->insert(value.getp());
  return new AnyUriItemImpl(value);
}


Item_t BasicItemFactory::createAnyURI(const xqp_string& value)
{
  theUriPool->insert(value.getStore());
  return new AnyUriItemImpl(xqpStringStore_t(value.getStore()));
}


Item_t BasicItemFactory::createAnyURI(const char* value)
{
  xqpStringStore_t str;
  theUriPool->insert(value, str);
  return new AnyUriItemImpl(str);
}


Item_t BasicItemFactory::createUntypedAtomic(const xqpStringStore_t& value)
{
  return new UntypedAtomicItemImpl(value.getp());
}

Item_t BasicItemFactory::createUntypedAtomic(const xqp_string& value)
{
  return new UntypedAtomicItemImpl(value.getStore());
}


Item_t BasicItemFactory::createString(xqpStringStore* value)
{
  return new StringItemNaive(value);
}


Item_t BasicItemFactory::createString(const xqp_string& value)
{
  return new StringItemNaive(xqpStringStore_t(value.getStore()));
}


Item_t BasicItemFactory::createBase64Binary(xqp_base64Binary value)
{
  return Item_t ( NULL );
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
  return new DateItemNaive(value);
}

Item_t BasicItemFactory::createDate ( short year, short month, short day )
{
  return Item_t ( NULL );
}

Item_t BasicItemFactory::createDate ( const xqp_string& value )
{
  return Item_t ( NULL );
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
    short second)
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createDateTime(
    short year ,
    short month,
    short day,
    short hour,
    short minute,
    short second,
    short timeZone)
{
  return Item_t ( NULL );
}

Item_t BasicItemFactory::createDateTime ( const xqp_string& value )
{
  return Item_t(NULL);
}

Item_t BasicItemFactory::createDateTime (const Item_t& date, const Item_t& time)
{
  if (date == NULL || time == NULL)
    return Item_t(NULL);
  else
    return new DateTimeItemNaive(date->getDateValue(), time->getTimeValue());
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
  return Item_t(NULL);
}

Item_t BasicItemFactory::createDuration (
	    short years, short months, short days, short hours, short minutes, short seconds
	)
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createENTITIES ( const xqp_string& value )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createENTITY ( const xqp_string& value )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createFloat ( xqp_float value ) 
{ 
  return new FloatItemNaive( value ); 
}

Item_t BasicItemFactory::createGDay (xqp_gDay& value )
{
  return new GDayItemNaive(value);
}

Item_t BasicItemFactory::createGDay ( const xqp_string& value )
{
  return Item_t(NULL);
}


Item_t BasicItemFactory::createGDay ( short day )
{ return Item_t ( NULL ); }

Item_t BasicItemFactory::createGMonth(xqp_gMonth& value )
{
  return new GMonthItemNaive(value);
}

Item_t BasicItemFactory::createGMonth ( const xqp_string& value )
{
  return Item_t(NULL);
}

Item_t BasicItemFactory::createGMonth ( short month )
{ return Item_t ( NULL ); }

Item_t BasicItemFactory::createGMonthDay (xqp_gMonthDay& value)
{
  return new GMonthDayItemNaive(value);
}

Item_t BasicItemFactory::createGMonthDay ( const xqp_string& value )
{
  return Item_t(NULL);
}


Item_t BasicItemFactory::createGMonthDay ( short month, short day )
{ return Item_t ( NULL ); }

Item_t BasicItemFactory::createGYear (xqp_gYear& value )
{
  return new GYearItemNaive(value);
}

Item_t BasicItemFactory::createGYear ( const xqp_string& value )
{
  return Item_t(NULL);
}


Item_t BasicItemFactory::createGYear ( short year )
{ return Item_t ( NULL ); }

Item_t BasicItemFactory::createGYearMonth (xqp_gYearMonth& value )
{
  return new GYearMonthItemNaive(value);
}

Item_t BasicItemFactory::createGYearMonth ( const xqp_string& value )
{
  return Item_t(NULL);
}

Item_t BasicItemFactory::createGYearMonth ( short year, short month )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createHexBinary ( xqp_hexBinary value )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createID ( const xqp_string& value )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createIDREF ( const xqp_string& value )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createIDREFS ( const xqp_string& value )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createLanguage ( const xqp_string& value )
{ return Item_t ( NULL ); }


Item_t BasicItemFactory::createNMTOKEN ( const xqp_string& value )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createNMTOKENS ( const xqp_string& value )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createNOTATION ( const xqp_string& value )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createName ( const xqp_string& value )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createNegativeInteger ( xqp_integer value )
{ 
  Assert(value < 0);
  return new NegativeIntegerItemNaive ( value ); 
}


Item_t BasicItemFactory::createNonNegativeInteger ( xqp_uinteger value )
{ 
  return new NonNegativeIntegerItemNaive ( value ); 
}


Item_t BasicItemFactory::createNonPositiveInteger ( xqp_integer value )
{ 
  Assert(value <= 0);
  return new NonPositiveIntegerItemNaive( value );
}


Item_t BasicItemFactory::createNormalizedString ( const xqp_string& value )
{
  return Item_t ( NULL );
}


Item_t BasicItemFactory::createPositiveInteger ( xqp_uinteger value ) { 
  Assert(value > 0);
  return new PositiveIntegerItemNaive( value ); 
}

Item_t BasicItemFactory::createTime(xqp_time& value)
{
  return new TimeItemNaive(value);
}

Item_t BasicItemFactory::createTime(const xqp_string& value)
{
  return Item_t(NULL);
}

Item_t BasicItemFactory::createTime(short hour, short minute, short second)
{
  return Item_t ( NULL );
}

Item_t BasicItemFactory::createTime(short hour, short minute, short second, short timeZone)
{
  return Item_t ( NULL );
}

Item_t BasicItemFactory::createToken ( const xqp_string& value )
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
    unsigned long   qid,
    xqpStringStore* baseUri,
    xqpStringStore* docUri,
    Iterator*       childrenIter,
    bool            isRoot,
    bool            copy,
    bool            typePreserve,
    bool            nsPreserve,
    bool            nsInherit)
{
  rchandle<XmlTree> xmlTree;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);

  if (isRoot)
  {
    xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
  }

  ConstrDocumentNode* n = new ConstrDocumentNode(xmlTree,
                                                 baseUri,
                                                 docUri,
                                                 typePreserve,
                                                 nsPreserve,
                                                 nsInherit);
  if (childrenIter != NULL)
  {
    ctx.push(n);

    try
    {
      n->constructSubtree(childrenIter, copy);
    }
    catch (...)
    {
      ctx.clear();
      throw;
    }

    ctx.pop();
  }

  return n;
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createElementNode(
    unsigned long     qid,
    Item*             name,
    Item*             type,
    Iterator*         childrenIter,
    Iterator*         attrsIter,
    Iterator*         nsIter,
    const NsBindings& contextBindings,
    const NsBindings& localBindings,
    bool              isRoot,
    bool              copy,
    bool              typePreserve,
    bool              nsPreserve,
    bool              nsInherit) 
{
  rchandle<XmlTree> xmlTree;
  XmlNode* parent = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);
  ulong pos = 0;

  if (isRoot)
  {
    xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
  }
  else
  {
    parent = ctx.top();
    pos = parent->numChildren();
  }

  ConstrElementNode* n = new ConstrElementNode(xmlTree, parent, pos,
                                               name,
                                               type,
                                               typePreserve,
                                               nsPreserve,
                                               nsInherit);

  ctx.push(n);

  try
  {
    n->constructSubtree(attrsIter, childrenIter, localBindings, copy);
  }
  catch (...)
  {
    ctx.clear();
    throw;
  }

  ctx.pop();

  return n;
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createAttributeNode(
    ulong      qid,
    Iterator*  nameIter,
    Item*      typeName,
    Iterator*  valueIter,
    bool       isRoot)
{
  rchandle<XmlTree> xmlTree;
  XmlNode* parent = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);
  ulong pos = 0;

  if (isRoot)
  {
    xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
  }
  else
  {
    ZORBA_ASSERT(!ctx.empty());

    parent = ctx.top();
    pos = parent->numAttributes();
  }

  // Compute the attribute name. Note: we don't have to check that itemQName 
  // is indeed a valid qname, because the compiler wraps an xs:qname cast
  // around thIteme expression.
  Item_t attrName = nameIter->next();

  if (attrName->getLocalName().size() == 0)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0074, false, false,
                      "Attribute name must not have an empty local part.");
  }

  if (attrName->getNamespace() == "http://www.w3.org/2000/xmlns/" ||
      (attrName->getNamespace() == "" && attrName->getLocalName() == "xmlns"))
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0044);
  }

  if (parent != NULL)
  {
    parent->checkUniqueAttr(attrName.getp());
  }

  AttributeNode* n = new AttributeNode(xmlTree, parent, pos,
                                       attrName, typeName,
                                       false, false);

  if (valueIter != NULL)
  {
    try
    {
      n->constructValue(valueIter);
    }
    catch (...)
    {
      ctx.clear();
      throw;
    }
  }

  return n;
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createTextNode(
    unsigned long   qid,
    xqpStringStore* value,
    bool            isRoot)
{
  rchandle<XmlTree> xmlTree;
  XmlNode* parent = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);
  ulong pos = 0;

  if (isRoot)
  {
    xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
  }
  else
  {
    parent = ctx.top();
    pos = parent->numChildren();

    XmlNode* lsib = (pos > 0 ? parent->getChild(pos-1) : NULL);

    if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
    {
      *(lsib->getStringValueP()) = *(lsib->getStringValueP()) + *value;
      return lsib;
    }
  }

  XmlNode* n = new TextNode(xmlTree, parent, pos, value);

  return n;
}


Item_t BasicItemFactory::createTextNode(
    unsigned long   qid,
    Iterator*       valueIter,
    bool            isRoot)
{
  // We must compute the value of the node before the node itself because
  // if the value is the empty sequence, no text node should be constructed.
  xqpString value;
  Item_t valueItem = valueIter->next();
  if (valueItem != 0)
  {
    value = valueItem->getAtomizationValue()->getStringValue();

    valueItem = valueIter->next();
    while (valueItem != NULL)
    {
      value += " ";
      value += valueItem->getAtomizationValue()->getStringValue();
      valueItem = valueIter->next();
    }
  }
  else
  {
    return NULL;
  }

  return createTextNode(qid, value.getStore(), isRoot);
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createPiNode(
    unsigned long   qid,
    xqpStringStore* target,
    xqpStringStore* data,
    bool            isRoot)
{
  rchandle<XmlTree> xmlTree;
  XmlNode* parent = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);
  ulong pos = 0;

  if (isRoot)
  {
    xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
  }
  else
  {
    parent = ctx.top();
    pos = parent->numChildren();
  }

  XmlNode* n = new PiNode(xmlTree, parent, pos, target, data);

  return n;
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createCommentNode(
    unsigned long   qid,
    xqpStringStore* comment,
    bool            isRoot)
{
  rchandle<XmlTree> xmlTree;
  XmlNode* parent = NULL;
  QueryContext& ctx = GET_STORE().getQueryContext(qid);
  ulong pos = 0;

  if (isRoot)
  {
    xmlTree = new XmlTree(NULL, GET_STORE().getTreeId());
  }
  else
  {
    parent = ctx.top();
    pos = parent->numChildren();
  }

  XmlNode* n = new CommentNode(xmlTree, parent, pos, comment);

  return n;
}


} /* namespace xqp */
