/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: basic_item_factory.h,v 1.1 2007/08/28 09:54:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#ifndef XQP_BASIC_ITEM_FACTORY_H
#define XQP_BASIC_ITEM_FACTORY_H

#include "../values/item_factory.h"

namespace xqp
{
	class BasicItemFactory : public ItemFactory
	{
		public:
			Item_t createQName ( xqp_string namespace_p, xqp_string prefix, xqp_string localName );
			Item_t createAnyURI ( const xqp_string& value );
			Item_t createBase64Binary ( xqp_base64Binary value );
			Item_t createBoolean ( bool value );
			Item_t createDecimal ( long double value );
			Item_t createInteger ( int value );
			Item_t createLong ( long value );
			Item_t createInt ( int value );
			Item_t createShort ( short value );
			Item_t createByte ( char value );
			Item_t createDate ( short year, short month, short day );
			Item_t createDate ( const xqp_string& value );
			Item_t createDateTime (
			    short year, short month, short day, short hour, short minute, short second
			);
			Item_t createDateTime (
			    short year , short month, short day, short hour, short minute, short second, short timeZone
			);
			Item_t createDateTime ( const xqp_string& value );
			Item_t createDateTime ( const Item_t&, const Item_t& );
			Item_t createDouble ( double value );
			Item_t createDuration ( const xqp_string& value );
			Item_t createDuration (
			    short years, short months, short days, short hours, short minutes, short seconds
			);
			Item_t createENTITIES ( const xqp_string& value );
			Item_t createENTITY ( const xqp_string& value );
			Item_t createFloat ( float value );
			Item_t createGDay ( const xqp_string& value );
			Item_t createGDay ( short day );
			Item_t createGMonth ( const xqp_string& value );
			Item_t createGMonth ( short month );
			Item_t createGMonthDay ( const xqp_string& value );
			Item_t createGMonthDay ( short month, short day );
			Item_t createGYear ( const xqp_string& value );
			Item_t createGYear ( short year );
			Item_t createGYearMonth ( const xqp_string& value );
			Item_t createGYearMonth ( short year, short month );
			Item_t createHexBinary ( xqp_hexBinary value );
			Item_t createID ( const xqp_string& value );
			Item_t createIDREF ( const xqp_string& value );
			Item_t createIDREFS ( const xqp_string& value );
			Item_t createLanguage ( const xqp_string& value );
			Item_t createNCName ( const xqp_string& value );
			Item_t createNMTOKEN ( const xqp_string& value );
			Item_t createNMTOKENS ( const xqp_string& value );
			Item_t createNOTATION ( const xqp_string& value );
			Item_t createName ( const xqp_string& value );
			Item_t createNegativeInteger ( int value );
			Item_t createNonNegativeInteger ( int value );
			Item_t createNonPositiveInteger ( int value );
			Item_t createNormalizedString ( const xqp_string& value );
			Item_t createPositiveInteger ( unsigned int value );
			Item_t createString ( xqp_string value );
			Item_t createTime ( const xqp_string& value );
			Item_t createTime ( short hour, short minute, short second );
			Item_t createTime ( short hour, short minute, short second, short timeZone );
			Item_t createToken ( const xqp_string& value );
			Item_t createUnsignedByte ( unsigned char value );
			Item_t createUnsignedInt ( unsigned int value );
			Item_t createUnsignedLong ( unsigned long value );
			Item_t createUnsignedShort ( uint16_t value );
			Item_t createDocumentNode (
			    xqp_string baseURI,
			    xqp_string docURI,
			    const Item_t& rootItem,
			    bool createId = false
			);
			Item_t createElementNode (
			    const Item_t& name,
			    const Item_t& type,
			    Iterator_t children,
			    Iterator_t attributes,
			    bool copy,
			    bool newTypes,
			    bool createId = false
			);
			Item_t createDocumentNode (
			    xqp_string baseURI,
			    xqp_string docURI,
			    Iterator_t children,
			    bool createId = false
			);
			Item_t createAttributeNode (
			    const Item_t& name,
			    const Item_t& type,
			    const Item_t& lexicalValue,
			    const Item_t& typedValue,
			    bool createId = false
			);
			Item_t createTextNode (
			    const xqp_string& value,
			    bool createId = false
			);
			Item_t createNamespaceNode (
			    const xqp_string& prefix,
			    const xqp_string& name,
			    bool createId = false
			);
			Item_t createCommentNode (
			    const xqp_string& comment,
			    bool createId = false
			);
			Item_t createPiNode (
			    const Item_t& name,
			    const xqp_string& content,
			    const xqp_string& baseUri,
			    bool createId = false
			);
	}; /* class BasicItemFactory */

}/* namespace xqp */

#endif
