/* -*- mode: c++ { return Item_t(NULL); } indent-tabs-mode: nil { return Item_t(NULL); } tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *`
 */

#include "basic_item_factory.h"
#include "atomic_items.h"

namespace xqp
{
	Item_t BasicItemFactory::createQName ( xqp_string namespace_p, xqp_string prefix, xqp_string localName )
	{
		return new QNameItem ( namespace_p, prefix, localName );
	}
	Item_t BasicItemFactory::createAnyURI ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createBase64Binary ( xqp_base64Binary value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createBoolean ( bool value )
	{
		return new BooleanItem ( value );
	}
	Item_t BasicItemFactory::createDecimal ( long double value )
	{
		return new DecimalItem ( value );
	}
	Item_t BasicItemFactory::createInteger ( long long value )
	{
		return new IntegerItem ( value );
	}
	Item_t BasicItemFactory::createLong ( long value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createInt ( int32_t value )
	{
		return new IntItem ( value );
	}
	Item_t BasicItemFactory::createShort ( short value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createByte ( char value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDate ( short year, short month, short day ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDate ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDateTime (
	    short year, short month, short day, short hour, short minute, short second
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDateTime (
	    short year , short month, short day, short hour, short minute, short second, short timeZone
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDateTime ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDateTime ( const Item_t&, const Item_t& ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDouble ( double value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDuration ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDuration (
	    short years, short months, short days, short hours, short minutes, short seconds
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createENTITIES ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createENTITY ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createFloat ( float value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGDay ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGDay ( short day ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGMonth ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGMonth ( short month ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGMonthDay ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGMonthDay ( short month, short day ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGYear ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGYear ( short year ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGYearMonth ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createGYearMonth ( short year, short month ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createHexBinary ( xqp_hexBinary value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createID ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createIDREF ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createIDREFS ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createLanguage ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNCName ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNMTOKEN ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNMTOKENS ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNOTATION ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createName ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNegativeInteger ( int32_t value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNonNegativeInteger ( int32_t value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNonPositiveInteger ( int32_t value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNormalizedString ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createPositiveInteger ( uint32_t value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createString ( xqp_string value ) { 
		return new StringItem ( value ); 
	}
	Item_t BasicItemFactory::createTime ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createTime ( short hour, short minute, short second ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createTime ( short hour, short minute, short second, short timeZone ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createToken ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createUnsignedByte ( unsigned char value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createUnsignedInt ( unsigned int value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createUnsignedLong ( unsigned long value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createUnsignedShort ( uint16_t value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDocumentNode (
	    xqp_string baseURI,
	    xqp_string docURI,
	    Iterator_t children,
	    bool createId
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createElementNode (
	    const Item_t& name,
	    const Item_t& type,
	    Iterator_t children,
	    Iterator_t attributes,
	    bool copy,
	    bool newTypes,
	    bool createId
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createAttributeNode (
	    const Item_t& name,
	    const Item_t& type,
	    const Item_t& lexicalValue,
	    const Item_t& typedValue,
	    bool createId
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createTextNode (
	    const xqp_string& value,
	    bool createId
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNamespaceNode (
	    const xqp_string& prefix,
	    const xqp_string& name,
	    bool createId
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createCommentNode (
	    const xqp_string& comment,
	    bool createId
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createPiNode (
	    const Item_t& name,
	    const xqp_string& content,
	    const xqp_string& baseUri,
	    bool createId
	) { return Item_t ( NULL ); }
} /* namespace xqp */
