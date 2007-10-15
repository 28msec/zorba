/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: basic_item_factory.h,v 1.1 2007/08/28 09:54:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com), Donald Kossmann, Tim Kraska
 *
 */

#ifndef XQP_BASIC_ITEM_FACTORY_H
#define XQP_BASIC_ITEM_FACTORY_H

#include "store/api/item_factory.h"

namespace xqp
{
	class BasicItemFactory : public ItemFactory
	{
		public:
			virtual ~BasicItemFactory();
			virtual Item_t createUntypedAtomic( const xqp_string& value);
			virtual Item_t createQName ( xqp_string namespace_p, xqp_string prefix, xqp_string localName );
			virtual Item_t createAnyURI ( const xqp_string& value );
			virtual Item_t createBase64Binary ( xqp_base64Binary value );
			virtual Item_t createBoolean ( bool value );
			virtual Item_t createDecimal ( long double value );
			virtual Item_t createInteger ( long long value );
			virtual Item_t createLong ( long value );
			virtual Item_t createInt ( int32_t value );
			virtual Item_t createShort ( short value );
			virtual Item_t createByte ( char value );
			virtual Item_t createDate ( short year, short month, short day );
			virtual Item_t createDate ( const xqp_string& value );
			virtual Item_t createDateTime (
			    short year, short month, short day, short hour, short minute, short second
			);
			virtual Item_t createDateTime (
			    short year , short month, short day, short hour, short minute, short second, short timeZone
			);
			virtual Item_t createDateTime ( const xqp_string& value );
			virtual Item_t createDateTime ( const Item_t&, const Item_t& );
			virtual Item_t createDouble ( double value );
			virtual Item_t createDuration ( const xqp_string& value );
			virtual Item_t createDuration (
			    short years, short months, short days, short hours, short minutes, short seconds
			);
			virtual Item_t createENTITIES ( const xqp_string& value );
			virtual Item_t createENTITY ( const xqp_string& value );
			virtual Item_t createFloat ( float value );
			virtual Item_t createGDay ( const xqp_string& value );
			virtual Item_t createGDay ( short day );
			virtual Item_t createGMonth ( const xqp_string& value );
			virtual Item_t createGMonth ( short month );
			virtual Item_t createGMonthDay ( const xqp_string& value );
			virtual Item_t createGMonthDay ( short month, short day );
			virtual Item_t createGYear ( const xqp_string& value );
			virtual Item_t createGYear ( short year );
			virtual Item_t createGYearMonth ( const xqp_string& value );
			virtual Item_t createGYearMonth ( short year, short month );
			virtual Item_t createHexBinary ( xqp_hexBinary value );
			virtual Item_t createID ( const xqp_string& value );
			virtual Item_t createIDREF ( const xqp_string& value );
			virtual Item_t createIDREFS ( const xqp_string& value );
			virtual Item_t createLanguage ( const xqp_string& value );
			virtual Item_t createNCName ( const xqp_string& value );
			virtual Item_t createNMTOKEN ( const xqp_string& value );
			virtual Item_t createNMTOKENS ( const xqp_string& value );
			virtual Item_t createNOTATION ( const xqp_string& value );
			virtual Item_t createName ( const xqp_string& value );
			virtual Item_t createNegativeInteger ( xqp_negativeInteger value );
			virtual Item_t createNonNegativeInteger ( xqp_nonNegativeInteger value );
			virtual Item_t createNonPositiveInteger ( xqp_nonPositiveInteger value );
			virtual Item_t createNormalizedString ( const xqp_string& value );
			virtual Item_t createPositiveInteger ( xqp_positiveInteger value );
			virtual Item_t createString ( const xqp_string& value );
			virtual Item_t createTime ( const xqp_string& value );
			virtual Item_t createTime ( short hour, short minute, short second );
			virtual Item_t createTime ( short hour, short minute, short second, short timeZone );
			virtual Item_t createToken ( const xqp_string& value );
			virtual Item_t createUnsignedByte ( xqp_unsignedByte value );
			virtual Item_t createUnsignedInt ( xqp_unsignedInt value );
			virtual Item_t createUnsignedLong ( xqp_unsignedLong value );
			virtual Item_t createUnsignedShort ( xqp_unsignedShort value );
			virtual Item_t createDocumentNode (
			    xqp_string baseURI,
			    xqp_string docURI,
			    Iterator_t& children,
			    bool createId = false
			);
			virtual Item_t createElementNode (
			    const Item_t& name,
			    TypeCode type,
			    TempSeq_t& children,
			    TempSeq_t& attributes,
			    TempSeq_t& namespaces,
			    bool copy,
			    bool newTypes,
			    bool createId = false
			);
			virtual Item_t createAttributeNode (
			    const Item_t& name,
			    TypeCode type,
			    const Item_t& lexicalValue,
			    const Item_t& typedValue,
			    bool createId = false
			);
			virtual Item_t createTextNode (
			    const xqp_string& value,
			    bool createId = false
			);
			virtual Item_t createNamespaceNode (
			    const xqp_string& prefix,
			    const xqp_string& name,
			    bool createId = false
			);
			virtual Item_t createCommentNode (
			    const xqp_string& comment,
			    bool createId = false
			);
			virtual Item_t createPiNode (
			    const Item_t& name,
			    const xqp_string& content,
			    const xqp_string& baseUri,
			    bool createId = false
			);
	}; /* class BasicItemFactory */

}/* namespace xqp */

#endif
