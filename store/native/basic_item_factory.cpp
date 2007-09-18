/* -*- mode: c++ { return Item_t(NULL); } indent-tabs-mode: nil { return Item_t(NULL); } tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com), Donald Kossmann, Tim Kraska
 *`
 */

#include "basic_item_factory.h"
#include "atomic_items.h"
#include "node_items.h"
#include "../../runtime/zorba.h"
#include "../api/temp_seq.h"

namespace xqp
{
	BasicItemFactory::~BasicItemFactory(){}

	Item_t BasicItemFactory::createUntypedAtomic( const xqp_string& value)
	{
		return new UntypedAtomicItem(value);
	}
	
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
	Item_t BasicItemFactory::createNegativeInteger ( xqp_negativeInteger value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNonNegativeInteger ( xqp_nonNegativeInteger value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNonPositiveInteger ( xqp_nonPositiveInteger value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createNormalizedString ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createPositiveInteger ( xqp_positiveInteger value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createString ( const xqp_string& value )
	{
		return new StringItem ( value );
	}
	Item_t BasicItemFactory::createTime ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createTime ( short hour, short minute, short second ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createTime ( short hour, short minute, short second, short timeZone ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createToken ( const xqp_string& value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createUnsignedByte ( xqp_unsignedByte value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createUnsignedInt ( xqp_unsignedInt value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createUnsignedLong ( xqp_unsignedLong value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createUnsignedShort ( xqp_unsignedShort value ) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createDocumentNode (
	    xqp_string baseURI,
	    xqp_string docURI,
	    Iterator_t& children,
	    bool createId
	) { return Item_t ( NULL ); }
	Item_t BasicItemFactory::createElementNode (
	    const Item_t& name,
	    TypeCode type,
	    Iterator_t& children,
	    Iterator_t& attributes,
	    Iterator_t& namespaces,
	    bool copy,
	    bool newTypes,
	    bool createId
	) 
	{ 
		Store* store = zorba::getZorbaForCurrentThread()->getStore();
		TempSeq_t seqChildren = NULL;
		TempSeq_t seqAttributes = NULL;
		TempSeq_t seqNamespaces = NULL;
		
		if (children != NULL)
			seqChildren = store->createTempSeq ( children );
		if (attributes != NULL)
			seqAttributes = store->createTempSeq ( attributes );
		Item_t item = new ElementNode(
			name,
			type,
			seqChildren,
			seqAttributes,
			seqNamespaces,
			copy,
			newTypes
		); 
		return item;
	}
	Item_t BasicItemFactory::createAttributeNode (
	    const Item_t& name,
	    TypeCode type,
	    const Item_t& lexicalValue,
	    const Item_t& typedValue,
	    bool createId
	) 
	{ 
		Item_t item = new AttributeNode(
				name,
				type,
				lexicalValue,
				typedValue,
				false,
				false
			);
		return item;
	}
	Item_t BasicItemFactory::createTextNode (
	    const xqp_string& value,
	    bool createId
	) 
	{
		Item_t item = new TextNode(value);
		return item;
	}
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
