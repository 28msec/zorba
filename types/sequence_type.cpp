/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: sequence_type.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf
 *
 */

#include "sequence_type.h"
#include "../util/tracer.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;
namespace xqp
{

	enum sequence_type::occurs_t sequence_type::get_occurs (
	    TypeCode t )
	{
		switch ( t&ARITY_MASK )
		{
			case ITEM_ARITY: return occurs_once;
			case SEQUENCE_ARITY: return occurs_zero_or_more;
			case NONEMPTY_SEQ_ARITY: return occurs_one_or_more;
			case OPT_ITEM_ARITY: return occurs_zero_or_one;
			default:
			{
				cout << TRACE << " : Unexpected arity bits\n";
				return occurs_once;
			}
		}
	}

	bool sequence_type::derives_from (
	    TypeCode subtype, TypeCode type )
	{
		int startType = type >> TYPE_SHIFT;
		int startSubtype = subtype >> TYPE_SHIFT;
		int mask = SUB_MASK | SUB2_MASK | SUB3_MASK | SUB4_MASK | SUB5_MASK | SUB6_MASK;
		int effType = type & mask;
		int effSubtype = subtype & mask;
		return (startType == startSubtype) && !(effType && ~effSubtype);
	}

	bool sequence_type::isNumeric ( TypeCode type )
	{
		return (type & ISNUMERIC_MASK > 0);
	}

	TypeCode sequence_type::getNumericalOpResultType ( TypeCode type0, TypeCode type1 )
	{
		if ( type0 == xs_untypedAtomicValue /*|| type0 == xs_anySimpleType*/ || type1 == xs_untypedAtomicValue /*|| type1 == xs_anySimpleType*/ )
			return xs_double;

		if ( type0 == xs_double || type1 == xs_double )
			return xs_double;

		if ( type0 == xs_float || type1 == xs_float )
			return xs_float;

		if ( type0 == xs_decimal || type1 == xs_decimal )
			return xs_decimal;

		return xs_integer;
	}

	TypeCode sequence_type::getTypeSubstituted ( TypeCode type )
	{
		if ( sequence_type::derives_from ( type, xs_decimal ) )
			return xs_decimal;
		else if ( sequence_type::derives_from ( type,xs_string ) )
			return xs_string;
		else
			return type;
	}

	bool sequence_type::comparable(TypeCode type0, TypeCode type1)
	{
		if (type0 == type1) 
			return true;
		
		if ((type0 == xs_string /*|| type0 == xs_anySimpleType*/ || type0 == xs_untypedAtomicValue || type0 == xs_anyURI 
				|| type0 == xs_untypedValue)
			&& (type1 == xs_string /*|| type1 == xs_anySimpleType*/ || type1 == xs_untypedAtomicValue || type1 == xs_anyURI 
				|| type1 == xs_untypedValue)) {
			return true;
		}
		
		/*
		Duration types can be partially compared:
		xs:duration + other types => depending on values in xs:duration
		xs:dayTime + xs:yearMonth => if both are 0
		=> in any case, the comparison could work
		*/
		if ((type0 == xs_duration || type0 == xs_dayTimeDuration || type0 == xs_yearMonthDuration)
				&& (type1 == xs_duration || type1 == xs_dayTimeDuration || type1 == xs_yearMonthDuration)) {
			return true;
		}
		
		if (sequence_type::isNumeric(type0) && sequence_type::isNumeric(type1))
			return true;
			
			
		return false;
	}

	std::string sequence_type::describe (
	    TypeCode t )
	{
		switch ( t )
		{
			case documentNode: return "documentNode";
			case documentNodeSeq: return "documentNodeSeq";
			case documentNodePlus: return "documentNodePlus";
			case documentNodeOpt: return "documentNodeOpt";
			case elementNode: return "elementNode";
			case elementNodeSeq: return "elementNodeSeq";
			case elementNodePlus: return "elementNodePlus";
			case elementNodeOpt: return "elementNodeOpt";
			case attributeNode: return "attributeNode";
			case attributeNodeSeq: return "attributeNodeSeq";
			case attributeNodePlus: return "attributeNodePlus";
			case attributeNodeOpt: return "attributeNodeOpt";
			case namespaceNode: return "namespaceNode";
			case namespaceNodeSeq: return "namespaceNodeSeq";
			case namespaceNodePlus: return "namespaceNodePlus";
			case namespaceNodeOpt: return "namespaceNodeOpt";
			case processingInstructionNode: return "processingInstructionNode";
			case processingInstructionNodeSeq: return "processingInstructionNodeSeq";
			case processingInstructionNodePlus: return "processingInstructionNodePlus";
			case processingInstructionNodeOpt: return "processingInstructionNodeOpt";
			case commentNode: return "commentNode";
			case commentNodeSeq: return "commentNodeSeq";
			case commentNodePlus: return "commentNodePlus";
			case commentNodeOpt: return "commentNodeOpt";
			case textNode: return "textNode";
			case textNodeSeq: return "textNodeSeq";
			case textNodePlus: return "textNodePlus";
			case textNodeOpt: return "textNodeOpt";
			case anyNode: return "anyNode";
			case anyNodeSeq: return "anyNodeSeq";
			case anyNodePlus: return "anyNodePlus";
			case anyNodeOpt: return "anyNodeOpt";
			case xs_string: return "xs_string";
			case xs_stringSeq: return "xs_stringSeq";
			case xs_stringPlus: return "xs_stringPlus";
			case xs_stringOpt: return "xs_stringOpt";
			case xs_normalizedString: return "xs_normalizedString";
			case xs_normalizedStringSeq: return "xs_normalizedStringSeq";
			case xs_normalizedStringPlus: return "xs_normalizedStringPlus";
			case xs_normalizedStringOpt: return "xs_normalizedStringOpt";
			case xs_token: return "xs_token";
			case xs_tokenSeq: return "xs_tokenSeq";
			case xs_tokenPlus: return "xs_tokenPlus";
			case xs_tokenOpt: return "xs_tokenOpt";
			case xs_language: return "xs_language";
			case xs_languageSeq: return "xs_languageSeq";
			case xs_languagePlus: return "xs_languagePlus";
			case xs_languageOpt: return "xs_languageOpt";
			case xs_nmtoken: return "xs_nmtoken";
			case xs_nmtokenSeq: return "xs_nmtokenSeq";
			case xs_nmtokenPlus: return "xs_nmtokenPlus";
			case xs_nmtokenOpt: return "xs_nmtokenOpt";
			case xs_name: return "xs_name";
			case xs_nameSeq: return "xs_nameSeq";
			case xs_namePlus: return "xs_namePlus";
			case xs_nameOpt: return "xs_nameOpt";
			case xs_ncName: return "xs_ncName";
			case xs_ncNameSeq: return "xs_ncNameSeq";
			case xs_ncNamePlus: return "xs_ncNamePlus";
			case xs_ncNameOpt: return "xs_ncNameOpt";
			case xs_id: return "xs_id";
			case xs_idSeq: return "xs_idSeq";
			case xs_idPlus: return "xs_idPlus";
			case xs_idOpt: return "xs_idOpt";
			case xs_idref: return "xs_idref";
			case xs_idrefSeq: return "xs_idrefSeq";
			case xs_idrefPlus: return "xs_idrefPlus";
			case xs_idrefOpt: return "xs_idrefOpt";
			case xs_entity: return "xs_entity";
			case xs_entitySeq: return "xs_entitySeq";
			case xs_entityPlus: return "xs_entityPlus";
			case xs_entityOpt: return "xs_entityOpt";
			case xs_decimal: return "xs_decimal";
			case xs_decimalSeq: return "xs_decimalSeq";
			case xs_decimalPlus: return "xs_decimalPlus";
			case xs_decimalOpt: return "xs_decimalOpt";
			case xs_integer: return "xs_integer";
			case xs_integerSeq: return "xs_integerSeq";
			case xs_integerPlus: return "xs_integerPlus";
			case xs_integerOpt: return "xs_integerOpt";
			case xs_nonPositiveInteger: return "xs_nonPositiveInteger";
			case xs_nonPositiveIntegerSeq: return "xs_nonPositiveIntegerSeq";
			case xs_nonPositiveIntegerPlus: return "xs_nonPositiveIntegerPlus";
			case xs_nonPositiveIntegerOpt: return "xs_nonPositiveIntegerOpt";
			case xs_negativeInteger: return "xs_negativeInteger";
			case xs_negativeIntegerSeq: return "xs_negativeIntegerSeq";
			case xs_negativeIntegerPlus: return "xs_negativeIntegerPlus";
			case xs_negativeIntegerOpt: return "xs_negativeIntegerOpt";
			case xs_long: return "xs_long";
			case xs_longSeq: return "xs_longSeq";
			case xs_longPlus: return "xs_longPlus";
			case xs_longOpt: return "xs_longOpt";
			case xs_int: return "xs_int";
			case xs_intSeq: return "xs_intSeq";
			case xs_intPlus: return "xs_intPlus";
			case xs_intOpt: return "xs_intOpt";
			case xs_short: return "xs_short";
			case xs_shortSeq: return "xs_shortSeq";
			case xs_shortPlus: return "xs_shortPlus";
			case xs_shortOpt: return "xs_shortOpt";
			case xs_byte: return "xs_byte";
			case xs_byteSeq: return "xs_byteSeq";
			case xs_bytePlus: return "xs_bytePlus";
			case xs_byteOpt: return "xs_byteOpt";
			case xs_nonNegativeInteger: return "xs_nonNegativeInteger";
			case xs_nonNegativeIntegerSeq: return "xs_nonNegativeIntegerSeq";
			case xs_nonNegativeIntegerPlus: return "xs_nonNegativeIntegerPlus";
			case xs_nonNegativeIntegerOpt: return "xs_nonNegativeIntegerOpt";
			case xs_unsignedLong: return "xs_unsignedLong";
			case xs_unsignedLongSeq: return "xs_unsignedLongSeq";
			case xs_unsignedLongPlus: return "xs_unsignedLongPlus";
			case xs_unsignedLongOpt: return "xs_unsignedLongOpt";
			case xs_unsignedInt: return "xs_unsignedInt";
			case xs_unsignedIntSeq: return "xs_unsignedIntSeq";
			case xs_unsignedIntPlus: return "xs_unsignedIntPlus";
			case xs_unsignedIntOpt: return "xs_unsignedIntOpt";
			case xs_unsignedShort: return "xs_unsignedShort";
			case xs_unsignedShortSeq: return "xs_unsignedShortSeq";
			case xs_unsignedShortPlus: return "xs_unsignedShortPlus";
			case xs_unsignedShortOpt: return "xs_unsignedShortOpt";
			case xs_unsignedByte: return "xs_unsignedByte";
			case xs_unsignedByteSeq: return "xs_unsignedByteSeq";
			case xs_unsignedBytePlus: return "xs_unsignedBytePlus";
			case xs_unsignedByteOpt: return "xs_unsignedByteOpt";
			case xs_positiveInteger: return "xs_positiveInteger";
			case xs_positiveIntegerSeq: return "xs_positiveIntegerSeq";
			case xs_positiveIntegerPlus: return "xs_positiveIntegerPlus";
			case xs_positiveIntegerOpt: return "xs_positiveIntegerOpt";
			case xs_untypedValue: return "xs_untypedValue";
			case xs_untypedValueSeq: return "xs_untypedValueSeq";
			case xs_untypedValuePlus: return "xs_untypedValuePlus";
			case xs_untypedValueOpt: return "xs_untypedValueOpt";
			case xs_untypedAtomicValue: return "xs_untypedAtomicValue";
			case xs_untypedAtomicValueSeq: return "xs_untypedAtomicValueSeq";
			case xs_untypedAtomicValuePlus: return "xs_untypedAtomicValuePlus";
			case xs_untypedAtomicValueOpt: return "xs_untypedAtomicValueOpt";
			case xs_boolean: return "xs_boolean";
			case xs_booleanSeq: return "xs_booleanSeq";
			case xs_booleanPlus: return "xs_booleanPlus";
			case xs_booleanOpt: return "xs_booleanOpt";
			case xs_float: return "xs_float";
			case xs_floatSeq: return "xs_floatSeq";
			case xs_floatPlus: return "xs_floatPlus";
			case xs_floatOpt: return "xs_floatOpt";
			case xs_double: return "xs_double";
			case xs_doubleSeq: return "xs_doubleSeq";
			case xs_doublePlus: return "xs_doublePlus";
			case xs_doubleOpt: return "xs_doubleOpt";
			case xs_duration: return "xs_duration";
			case xs_durationSeq: return "xs_durationSeq";
			case xs_durationPlus: return "xs_durationPlus";
			case xs_durationOpt: return "xs_durationOpt";
			case xs_dayTimeDuration: return "xs_dayTimeDuration";
			case xs_dayTimeDurationSeq: return "xs_dayTimeDurationSeq";
			case xs_dayTimeDurationPlus: return "xs_dayTimeDurationPlus";
			case xs_dayTimeDurationOpt: return "xs_dayTimeDurationOpt";
			case xs_yearMonthDuration: return "xs_yearMonthDuration";
			case xs_yearMonthDurationSeq: return "xs_yearMonthDurationSeq";
			case xs_yearMonthDurationPlus: return "xs_yearMonthDurationPlus";
			case xs_yearMonthDurationOpt: return "xs_yearMonthDurationOpt";
			case xs_dateTime: return "xs_dateTime";
			case xs_dateTimeSeq: return "xs_dateTimeSeq";
			case xs_dateTimePlus: return "xs_dateTimePlus";
			case xs_dateTimeOpt: return "xs_dateTimeOpt";
			case xs_time: return "xs_time";
			case xs_timeSeq: return "xs_timeSeq";
			case xs_timePlus: return "xs_timePlus";
			case xs_timeOpt: return "xs_timeOpt";
			case xs_date: return "xs_date";
			case xs_dateSeq: return "xs_dateSeq";
			case xs_datePlus: return "xs_datePlus";
			case xs_dateOpt: return "xs_dateOpt";
			case xs_gYearMonth: return "xs_gYearMonth";
			case xs_gYearMonthSeq: return "xs_gYearMonthSeq";
			case xs_gYearMonthPlus: return "xs_gYearMonthPlus";
			case xs_gYearMonthOpt: return "xs_gYearMonthOpt";
			case xs_gYear: return "xs_gYear";
			case xs_gYearSeq: return "xs_gYearSeq";
			case xs_gYearPlus: return "xs_gYearPlus";
			case xs_gYearOpt: return "xs_gYearOpt";
			case xs_gMonthDay: return "xs_gMonthDay";
			case xs_gMonthDaySeq: return "xs_gMonthDaySeq";
			case xs_gMonthDayPlus: return "xs_gMonthDayPlus";
			case xs_gMonthDayOpt: return "xs_gMonthDayOpt";
			case xs_gDay: return "xs_gDay";
			case xs_gDaySeq: return "xs_gDaySeq";
			case xs_gDayPlus: return "xs_gDayPlus";
			case xs_gDayOpt: return "xs_gDayOpt";
			case xs_gMonth: return "xs_gMonth";
			case xs_gMonthSeq: return "xs_gMonthSeq";
			case xs_gMonthPlus: return "xs_gMonthPlus";
			case xs_gMonthOpt: return "xs_gMonthOpt";
			case xs_hexBinary: return "xs_hexBinary";
			case xs_hexBinarySeq: return "xs_hexBinarySeq";
			case xs_hexBinaryPlus: return "xs_hexBinaryPlus";
			case xs_hexBinaryOpt: return "xs_hexBinaryOpt";
			case xs_base64Binary: return "xs_base64Binary";
			case xs_base64BinarySeq: return "xs_base64BinarySeq";
			case xs_base64BinaryPlus: return "xs_base64BinaryPlus";
			case xs_base64BinaryOpt: return "xs_base64BinaryOpt";
			case xs_anyURI: return "xs_anyURI";
			case xs_anyURISeq: return "xs_anyURISeq";
			case xs_anyURIPlus: return "xs_anyURIPlus";
			case xs_anyURIOpt: return "xs_anyURIOpt";
			case xs_qname: return "xs_qname";
			case xs_qnameSeq: return "xs_qnameSeq";
			case xs_qnamePlus: return "xs_qnamePlus";
			case xs_qnameOpt: return "xs_qnameOpt";
			case xs_notation: return "xs_notation";
			case xs_notationSeq: return "xs_notationSeq";
			case xs_notationPlus: return "xs_notationPlus";
			case xs_notationOpt: return "xs_notationOpt";
			case xs_complexType: return "xs_complexType";
			case xs_complexTypeSeq: return "xs_complexTypeSeq";
			case xs_complexTypePlus: return "xs_complexTypePlus";
			case xs_complexTypeOpt: return "xs_complexTypeOpt";
			case xs_emptyType: return "xs_emptyType";
			case xs_emptyTypeSeq: return "xs_emptyTypeSeq";
			case xs_emptyTypePlus: return "xs_emptyTypePlus";
			case xs_emptyTypeOpt: return "xs_emptyTypeOpt";
			case xs_anyType: return "xs_anyType";
			case xs_anyTypeSeq: return "xs_anyTypeSeq";
			case xs_anyTypePlus: return "xs_anyTypePlus";
			case xs_anyTypeOpt: return "xs_anyTypeOpt";
			case xs_rawBinaryType: return "xs_rawBinaryType";
			case xs_rawBinaryTypeSeq: return "xs_rawBinaryTypeSeq";
			case xs_rawBinaryTypePlus: return "xs_rawBinaryTypePlus";
			case xs_rawBinaryTypeOpt: return "xs_rawBinaryTypeOpt";
			default:
			{
				ostringstream oss;
				oss <<"??? [" << ( uint32_t ) t << "]";
				return oss.str();
			}
		}
	}


}	/* namespace xqp */

