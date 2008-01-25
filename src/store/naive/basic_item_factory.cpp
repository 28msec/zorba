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


Item_t BasicItemFactory::createAnyURI(const xqpStringStore_t& value)
{
  theUriPool->insert(value.get_ptr());
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
  return new UntypedAtomicItemImpl(value.get_ptr());
}

Item_t BasicItemFactory::createUntypedAtomic(const xqp_string& value)
{
  return new UntypedAtomicItemImpl(value.getStore());
}


Item_t BasicItemFactory::createString(const xqpStringStore_t& value)
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

Item_t BasicItemFactory::createDouble ( double value ) 
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


Item_t BasicItemFactory::createFloat ( float value ) 
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


Item_t BasicItemFactory::createNCName ( const xqp_string& value )
{
  return Item_t ( NULL );
}


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
    xqpStringStore* baseUri,
    xqpStringStore* docUri,
    Iterator*       children,
    bool            isRoot,
    bool            copy,
    bool            typePreserve,
    bool            nsPreserve,
    bool            nsInherit)
{
  if (isRoot)
  {
    rchandle<XmlTree> xmlTree(new XmlTree(NULL, GET_STORE().getTreeId()));

    XmlNode* n = new ConstrDocumentNode(baseUri, docUri, children,
                                        true, copy,
                                        typePreserve, nsPreserve, nsInherit);
    xmlTree->setRoot(n);

    n->constructTree(xmlTree.get_ptr(), 0);

    return n;
  }
  else
  {
    return new ConstrDocumentNode(baseUri, docUri, children,
                                  false, copy,
                                  typePreserve, nsPreserve, nsInherit);
  }
}


/*******************************************************************************
  This method is used by the zorba runtime (during node construction).
********************************************************************************/
Item_t BasicItemFactory::createElementNode(
    Item*             name,
    Item*             type,
    Iterator*         childrenIte,
    Iterator*         attrsIte,
    Iterator*         nsIte,
    const NsBindings& nsBindings,
    bool              isRoot,
    bool              copy,
    bool              typePreserve,
    bool              nsPreserve,
    bool              nsInherit) 
{
  if (isRoot)
  {
    rchandle<XmlTree> xmlTree(new XmlTree(NULL, GET_STORE().getTreeId()));

    XmlNode* n = new ConstrElementNode(name, type,
                                       childrenIte, attrsIte, nsIte, nsBindings,
                                       true, copy,
                                       typePreserve, nsPreserve, nsInherit);

    xmlTree->setRoot(n);

    n->constructTree(xmlTree.get_ptr(), 0);

    return n;
  }
  else
  {
    return new ConstrElementNode(name, type,
                                 childrenIte, attrsIte, nsIte, nsBindings,
                                 false, copy,
                                 typePreserve, nsPreserve, nsInherit); 
  }
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createAttributeNode(
    Item* name,
    Item* type,
    Item* typedValue,
    bool  isRoot)
{
  if (isRoot)
  {
    rchandle<XmlTree> xmlTree(new XmlTree(NULL, GET_STORE().getTreeId()));

    XmlNode* n = new AttributeNode(name, type, typedValue, false, false, true);

    xmlTree->setRoot(n);

    n->constructTree(xmlTree.get_ptr(), 0);

    return n;
  }
  else
  {
    return new AttributeNode(name, type, typedValue, false, false, false);
  }
}



/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createTextNode(
    xqpStringStore* value,
    bool            isRoot)
{
  if (isRoot)
  {
    rchandle<XmlTree> xmlTree(new XmlTree(NULL, GET_STORE().getTreeId()));

    XmlNode* n = new TextNode(value, true);

    xmlTree->setRoot(n);

    n->constructTree(xmlTree.get_ptr(), 0);

    return n;
  }
  else
  {
    return new TextNode(value, false);
  }
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createCommentNode(
    xqpStringStore* comment,
    bool            isRoot)
{
  if (isRoot)
  {
    rchandle<XmlTree> xmlTree(new XmlTree(NULL, GET_STORE().getTreeId()));

    XmlNode* n = new CommentNode(comment, true);

    xmlTree->setRoot(n);

    n->constructTree(xmlTree.get_ptr(), 0);

    return n;
  }
  else
  {
    return new CommentNode(comment, false);
  }
}


/*******************************************************************************

********************************************************************************/
Item_t BasicItemFactory::createPiNode(
    xqpStringStore* target,
    xqpStringStore* data,
    bool            isRoot)
{
  if (isRoot)
  {
    rchandle<XmlTree> xmlTree(new XmlTree(NULL, GET_STORE().getTreeId()));

    XmlNode* n = new PiNode(target, data, true);

    xmlTree->setRoot(n);

    n->constructTree(xmlTree.get_ptr(), 0);

    return n;
  }
  else
  {
    return new PiNode(target, data, isRoot);
  }
}


} /* namespace xqp */
