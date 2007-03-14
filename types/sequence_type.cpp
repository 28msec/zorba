/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: sequence_type.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan, Paul Pedersen
 *
 */

#include "sequence_type.h"
#include "../util/tracer.h"
#include "../util/xqp_exception.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
namespace xqp {

enum sequence_type::occurs_t sequence_type::get_occurs(
	TypeCode t)
{
	switch (t&ARITY_MASK) {
	case ITEM_ARITY: return occurs_once;
	case SEQUENCE_ARITY: return occurs_zero_or_more;
	case NONEMPTY_SEQ_ARITY: return occurs_one_or_more;
	case OPT_ITEM_ARITY: return occurs_zero_or_one;
	default:  {
		cout << TRACE << " : Unexpected arity bits\n";
		return occurs_once;
	}
	}
}

std::string _describe_atomictype(
	TypeCode t)
{
	switch (t&TYPE_MASK) {
	case UNTYPED_TYPE: return "xs:untyped";
	case UNTYPED_ATOMIC_TYPE: return "xs:untypedAtomic";
	case STRING_TYPE: return "xs:string";
	case DECIMAL_TYPE: return "xs:decimal";
	case BOOLEAN_TYPE: return "xs:boolean";
	case FLOAT_TYPE: return "xs:float";
	case DOUBLE_TYPE: return "xs:double";
	case DURATION_TYPE: return "xs:duration";
	case DATE_TIME_TYPE: return "xs:dateTime";
	case TIME_TYPE: return "xs:time";
	case DATE_TYPE: return "xs:date";
	case G_YEAR_MONTH_TYPE: return "xs:gYearMonth";
	case G_YEAR_TYPE: return "xs:gYear";
	case G_MONTH_DAY_TYPE: return "xs:gMonthDay";
	case G_DAY_TYPE: return "xs:gDay";
	case G_MONTH_TYPE: return "xs:gMonth";
	case HEX_BINARY_TYPE: return "xs:hexBinary";
	case BASE_64_BINARY_TYPE: return "xs:base64Binary";
	case ANY_URI_TYPE: return "xs:anyURI";
	case QNAME_TYPE: return "xs:QName";
	case NOTATION_TYPE: return "xs:NOTATION";
	case COMPLEX_TYPE: return "xs:complex_type";
  case EMPTY_TYPE: return "xdm:empty";
  case ANY_TYPE: return "xs:anyType";
  case RAW_BINARY_TYPE: return "xqp:binary";
	case NORMALIZED_STRING_SUB: return "xs:normalizedString";
	case TOKEN_SUB2: return "xs:TOKEN";
	case LANGUAGE_SUB3: return "xs:language";
	case NMTOKEN_SUB3: return "xs:NMTOKEN";
	case NAME_SUB3: return "xs:Name";
	case NCNAME_SUB4: return "xs:NCName";
	case ID_SUB5: return "xs:ID";
	case IDREF_SUB5: return "xs:IDREF";
	case ENTITY_SUB5: return "xs:ENTITY";
	case INTEGER_SUB: return "xs:integer";
	case NON_POSITIVE_INTEGER_SUB2: return "xs:nonPositiveInteger";
	case NEGATIVE_INTEGER_SUB3: return "xs:negativeInteger";
	case LONG_SUB2: return "xs:long";
	case INT_SUB3: return "xs:int";
	case SHORT_SUB4: return "xs:short";
	case BYTE_SUB5: return "xs:byte";
	case NON_NEGATIVE_INTEGER_SUB2: return "xs:nonNegativeInteger";
	case UNSIGNED_LONG_SUB3: return "xs:unsignedLong";
	case UNSIGNED_INT_SUB4: return "xs:unsignedInt";
	case UNSIGNED_SHORT_SUB5: return "xs:unsignedShort";
	case UNSIGNED_BYTE_SUB6: return "xs:unsignedByte";
	case POSITIVE_INTEGER_SUB3: return "xs:positiveInteger";
	case DAY_TIME_DURATION_SUB: return "xs:dayTimeDuration";
	case YEAR_MONTH_DURATION_SUB: return "xs:yearMonthDuration";
	default: {
  	cout << TRACE << " : Unexpected type bits: " << t << "\n";
		return "xs:untyped";
	}
	}
}

std::string _describe_nodetype(
	TypeCode t)
{
	switch (t&NODE_MASK) {
	case DOCUMENT_NODE: return "document()";
	case ELEMENT_NODE: return "element()";
	case ATTRIBUTE_NODE: return "attribute()";
	case NAMESPACE_NODE: return "namespace()";
	case PI_NODE: return "pi()";
	case COMMENT_NODE: return "comment()";
	case TEXT_NODE: return "text()";
	case ANY_NODE: return "node()";
	default: {
  	cout << TRACE << " : Unexpected node bits\n";
		return "node()";
	}
	}
}

std::string _describe_itemtype(
	TypeCode t)
{
	uint32_t node = (t&NODE_MASK);
	return (node ? _describe_nodetype(t) : _describe_atomictype(t));
}

/*
std::string sequence_type::describe0(
	TypeCode t)
{
	ostringstream oss;
	oss << _describe_itemtype(t);
	switch (get_occurs(t)) {
	case occurs_once: break;
	case occurs_zero_or_more: oss << "*"; break;
	case occurs_one_or_more: oss << "+"; break;
	case occurs_zero_or_one: oss << "?"; break;
	default: cout << TRACE << " : Unexpected occurence indicator\n";
	}
	return oss.str();
}
*/

bool sequence_type::derives_from(
	TypeCode ta, TypeCode te)
{
	return false;
}


std::string sequence_type::describe(
	TypeCode t)
{
	switch (t) {
	case documentNode: return "documentNode";
	case documentNodeRef: return "documentNodeRef";
	case documentNodeSeq: return "documentNodeSeq";
	case documentNodeSeqRef: return "documentNodeSeqRef";
	case documentNodePlus: return "documentNodePlus";
	case documentNodeOpt: return "documentNodeOpt";
	case elementNode: return "elementNode";
	case elementNodeRef: return "elementNodeRef";
	case elementNodeSeq: return "elementNodeSeq";
	case elementNodeSeqRef: return "elementNodeSeqRef";
	case elementNodePlus: return "elementNodePlus";
	case elementNodeOpt: return "elementNodeOpt";
	case attributeNode: return "attributeNode";
	case attributeNodeRef: return "attributeNodeRef";
	case attributeNodeSeq: return "attributeNodeSeq";
	case attributeNodeSeqRef: return "attributeNodeSeqRef";
	case attributeNodePlus: return "attributeNodePlus";
	case attributeNodeOpt: return "attributeNodeOpt";
	case namespaceNode: return "namespaceNode";
	case namespaceNodeRef: return "namespaceNodeRef";
	case namespaceNodeSeq: return "namespaceNodeSeq";
	case namespaceNodeSeqRef: return "namespaceNodeSeqRef";
	case namespaceNodePlus: return "namespaceNodePlus";
	case namespaceNodeOpt: return "namespaceNodeOpt";
	case processingInstructionNode: return "processingInstructionNode";
	case processingInstructionNodeRef: return "processingInstructionNodeRef";
	case processingInstructionNodeSeq: return "processingInstructionNodeSeq";
	case processingInstructionNodeSeqRef: return "processingInstructionNodeSeqRef";
	case processingInstructionNodePlus: return "processingInstructionNodePlus";
	case processingInstructionNodeOpt: return "processingInstructionNodeOpt";
	case commentNode: return "commentNode";
	case commentNodeRef: return "commentNodeRef";
	case commentNodeSeq: return "commentNodeSeq";
	case commentNodeSeqRef: return "commentNodeSeqRef";
	case commentNodePlus: return "commentNodePlus";
	case commentNodeOpt: return "commentNodeOpt";
	case textNode: return "textNode";
	case textNodeRef: return "textNodeRef";
	case textNodeSeq: return "textNodeSeq";
	case textNodeSeqRef: return "textNodeSeqRef";
	case textNodePlus: return "textNodePlus";
	case textNodeOpt: return "textNodeOpt";
	case anyNode: return "anyNode";
	case anyNodeRef: return "anyNodeRef";
	case anyNodeSeq: return "anyNodeSeq";
	case anyNodeSeqRef: return "anyNodeSeqRef";
	case anyNodePlus: return "anyNodePlus";
	case anyNodeOpt: return "anyNodeOpt";
	case xs_string: return "xs_string";
	case xs_stringRef: return "xs_stringRef";
	case xs_stringSeq: return "xs_stringSeq";
	case xs_stringSeqRef: return "xs_stringSeqRef";
	case xs_stringPlus: return "xs_stringPlus";
	case xs_stringOpt: return "xs_stringOpt";
	case xs_normalizedString: return "xs_normalizedString";
	case xs_normalizedStringRef: return "xs_normalizedStringRef";
	case xs_normalizedStringSeq: return "xs_normalizedStringSeq";
	case xs_normalizedStringSeqRef: return "xs_normalizedStringSeqRef";
	case xs_normalizedStringPlus: return "xs_normalizedStringPlus";
	case xs_normalizedStringOpt: return "xs_normalizedStringOpt";
	case xs_token: return "xs_token";
	case xs_tokenRef: return "xs_tokenRef";
	case xs_tokenSeq: return "xs_tokenSeq";
	case xs_tokenSeqRef: return "xs_tokenSeqRef";
	case xs_tokenPlus: return "xs_tokenPlus";
	case xs_tokenOpt: return "xs_tokenOpt";
	case xs_language: return "xs_language";
	case xs_languageRef: return "xs_languageRef";
	case xs_languageSeq: return "xs_languageSeq";
	case xs_languageSeqRef: return "xs_languageSeqRef";
	case xs_languagePlus: return "xs_languagePlus";
	case xs_languageOpt: return "xs_languageOpt";
	case xs_nmtoken: return "xs_nmtoken";
	case xs_nmtokenRef: return "xs_nmtokenRef";
	case xs_nmtokenSeq: return "xs_nmtokenSeq";
	case xs_nmtokenSeqRef: return "xs_nmtokenSeqRef";
	case xs_nmtokenPlus: return "xs_nmtokenPlus";
	case xs_nmtokenOpt: return "xs_nmtokenOpt";
	case xs_name: return "xs_name";
	case xs_nameRef: return "xs_nameRef";
	case xs_nameSeq: return "xs_nameSeq";
	case xs_nameSeqRef: return "xs_nameSeqRef";
	case xs_namePlus: return "xs_namePlus";
	case xs_nameOpt: return "xs_nameOpt";
	case xs_ncName: return "xs_ncName";
	case xs_ncNameRef: return "xs_ncNameRef";
	case xs_ncNameSeq: return "xs_ncNameSeq";
	case xs_ncNameSeqRef: return "xs_ncNameSeqRef";
	case xs_ncNamePlus: return "xs_ncNamePlus";
	case xs_ncNameOpt: return "xs_ncNameOpt";
	case xs_id: return "xs_id";
	case xs_idRef: return "xs_idRef";
	case xs_idSeq: return "xs_idSeq";
	case xs_idSeqRef: return "xs_idSeqRef";
	case xs_idPlus: return "xs_idPlus";
	case xs_idOpt: return "xs_idOpt";
	case xs_idref: return "xs_idref";
	case xs_idrefRef: return "xs_idrefRef";
	case xs_idrefSeq: return "xs_idrefSeq";
	case xs_idrefSeqRef: return "xs_idrefSeqRef";
	case xs_idrefPlus: return "xs_idrefPlus";
	case xs_idrefOpt: return "xs_idrefOpt";
	case xs_entity: return "xs_entity";
	case xs_entityRef: return "xs_entityRef";
	case xs_entitySeq: return "xs_entitySeq";
	case xs_entitySeqRef: return "xs_entitySeqRef";
	case xs_entityPlus: return "xs_entityPlus";
	case xs_entityOpt: return "xs_entityOpt";
	case xs_decimal: return "xs_decimal";
	case xs_decimalRef: return "xs_decimalRef";
	case xs_decimalSeq: return "xs_decimalSeq";
	case xs_decimalSeqRef: return "xs_decimalSeqRef";
	case xs_decimalPlus: return "xs_decimalPlus";
	case xs_decimalOpt: return "xs_decimalOpt";
	case xs_integer: return "xs_integer";
	case xs_integerRef: return "xs_integerRef";
	case xs_integerSeq: return "xs_integerSeq";
	case xs_integerSeqRef: return "xs_integerSeqRef";
	case xs_integerPlus: return "xs_integerPlus";
	case xs_integerOpt: return "xs_integerOpt";
	case xs_nonPositiveInteger: return "xs_nonPositiveInteger";
	case xs_nonPositiveIntegerRef: return "xs_nonPositiveIntegerRef";
	case xs_nonPositiveIntegerSeq: return "xs_nonPositiveIntegerSeq";
	case xs_nonPositiveIntegerSeqRef: return "xs_nonPositiveIntegerSeqRef";
	case xs_nonPositiveIntegerPlus: return "xs_nonPositiveIntegerPlus";
	case xs_nonPositiveIntegerOpt: return "xs_nonPositiveIntegerOpt";
	case xs_negativeInteger: return "xs_negativeInteger";
	case xs_negativeIntegerRef: return "xs_negativeIntegerRef";
	case xs_negativeIntegerSeq: return "xs_negativeIntegerSeq";
	case xs_negativeIntegerSeqRef: return "xs_negativeIntegerSeqRef";
	case xs_negativeIntegerPlus: return "xs_negativeIntegerPlus";
	case xs_negativeIntegerOpt: return "xs_negativeIntegerOpt";
	case xs_long: return "xs_long";
	case xs_longRef: return "xs_longRef";
	case xs_longSeq: return "xs_longSeq";
	case xs_longSeqRef: return "xs_longSeqRef";
	case xs_longPlus: return "xs_longPlus";
	case xs_longOpt: return "xs_longOpt";
	case xs_int: return "xs_int";
	case xs_intRef: return "xs_intRef";
	case xs_intSeq: return "xs_intSeq";
	case xs_intSeqRef: return "xs_intSeqRef";
	case xs_intPlus: return "xs_intPlus";
	case xs_intOpt: return "xs_intOpt";
	case xs_short: return "xs_short";
	case xs_shortRef: return "xs_shortRef";
	case xs_shortSeq: return "xs_shortSeq";
	case xs_shortSeqRef: return "xs_shortSeqRef";
	case xs_shortPlus: return "xs_shortPlus";
	case xs_shortOpt: return "xs_shortOpt";
	case xs_byte: return "xs_byte";
	case xs_byteRef: return "xs_byteRef";
	case xs_byteSeq: return "xs_byteSeq";
	case xs_byteSeqRef: return "xs_byteSeqRef";
	case xs_bytePlus: return "xs_bytePlus";
	case xs_byteOpt: return "xs_byteOpt";
	case xs_nonNegativeInteger: return "xs_nonNegativeInteger";
	case xs_nonNegativeIntegerRef: return "xs_nonNegativeIntegerRef";
	case xs_nonNegativeIntegerSeq: return "xs_nonNegativeIntegerSeq";
	case xs_nonNegativeIntegerSeqRef: return "xs_nonNegativeIntegerSeqRef";
	case xs_nonNegativeIntegerPlus: return "xs_nonNegativeIntegerPlus";
	case xs_nonNegativeIntegerOpt: return "xs_nonNegativeIntegerOpt";
	case xs_unsignedLong: return "xs_unsignedLong";
	case xs_unsignedLongRef: return "xs_unsignedLongRef";
	case xs_unsignedLongSeq: return "xs_unsignedLongSeq";
	case xs_unsignedLongSeqRef: return "xs_unsignedLongSeqRef";
	case xs_unsignedLongPlus: return "xs_unsignedLongPlus";
	case xs_unsignedLongOpt: return "xs_unsignedLongOpt";
	case xs_unsignedInt: return "xs_unsignedInt";
	case xs_unsignedIntRef: return "xs_unsignedIntRef";
	case xs_unsignedIntSeq: return "xs_unsignedIntSeq";
	case xs_unsignedIntSeqRef: return "xs_unsignedIntSeqRef";
	case xs_unsignedIntPlus: return "xs_unsignedIntPlus";
	case xs_unsignedIntOpt: return "xs_unsignedIntOpt";
	case xs_unsignedShort: return "xs_unsignedShort";
	case xs_unsignedShortRef: return "xs_unsignedShortRef";
	case xs_unsignedShortSeq: return "xs_unsignedShortSeq";
	case xs_unsignedShortSeqRef: return "xs_unsignedShortSeqRef";
	case xs_unsignedShortPlus: return "xs_unsignedShortPlus";
	case xs_unsignedShortOpt: return "xs_unsignedShortOpt";
	case xs_unsignedByte: return "xs_unsignedByte";
	case xs_unsignedByteRef: return "xs_unsignedByteRef";
	case xs_unsignedByteSeq: return "xs_unsignedByteSeq";
	case xs_unsignedByteSeqRef: return "xs_unsignedByteSeqRef";
	case xs_unsignedBytePlus: return "xs_unsignedBytePlus";
	case xs_unsignedByteOpt: return "xs_unsignedByteOpt";
	case xs_positiveInteger: return "xs_positiveInteger";
	case xs_positiveIntegerRef: return "xs_positiveIntegerRef";
	case xs_positiveIntegerSeq: return "xs_positiveIntegerSeq";
	case xs_positiveIntegerSeqRef: return "xs_positiveIntegerSeqRef";
	case xs_positiveIntegerPlus: return "xs_positiveIntegerPlus";
	case xs_positiveIntegerOpt: return "xs_positiveIntegerOpt";
	case xs_untypedValue: return "xs_untypedValue";
	case xs_untypedValueRef: return "xs_untypedValueRef";
	case xs_untypedValueSeq: return "xs_untypedValueSeq";
	case xs_untypedValueSeqRef: return "xs_untypedValueSeqRef";
	case xs_untypedValuePlus: return "xs_untypedValuePlus";
	case xs_untypedValueOpt: return "xs_untypedValueOpt";
	case xs_untypedAtomicValue: return "xs_untypedAtomicValue";
	case xs_untypedAtomicValueRef: return "xs_untypedAtomicValueRef";
	case xs_untypedAtomicValueSeq: return "xs_untypedAtomicValueSeq";
	case xs_untypedAtomicValueSeqRef: return "xs_untypedAtomicValueSeqRef";
	case xs_untypedAtomicValuePlus: return "xs_untypedAtomicValuePlus";
	case xs_untypedAtomicValueOpt: return "xs_untypedAtomicValueOpt";
	case xs_boolean: return "xs_boolean";
	case xs_booleanRef: return "xs_booleanRef";
	case xs_booleanSeq: return "xs_booleanSeq";
	case xs_booleanSeqRef: return "xs_booleanSeqRef";
	case xs_booleanPlus: return "xs_booleanPlus";
	case xs_booleanOpt: return "xs_booleanOpt";
	case xs_float: return "xs_float";
	case xs_floatRef: return "xs_floatRef";
	case xs_floatSeq: return "xs_floatSeq";
	case xs_floatSeqRef: return "xs_floatSeqRef";
	case xs_floatPlus: return "xs_floatPlus";
	case xs_floatOpt: return "xs_floatOpt";
	case xs_double: return "xs_double";
	case xs_doubleRef: return "xs_doubleRef";
	case xs_doubleSeq: return "xs_doubleSeq";
	case xs_doubleSeqRef: return "xs_doubleSeqRef";
	case xs_doublePlus: return "xs_doublePlus";
	case xs_doubleOpt: return "xs_doubleOpt";
	case xs_duration: return "xs_duration";
	case xs_durationRef: return "xs_durationRef";
	case xs_durationSeq: return "xs_durationSeq";
	case xs_durationSeqRef: return "xs_durationSeqRef";
	case xs_durationPlus: return "xs_durationPlus";
	case xs_durationOpt: return "xs_durationOpt";
	case xs_dayTimeDuration: return "xs_dayTimeDuration";
	case xs_dayTimeDurationRef: return "xs_dayTimeDurationRef";
	case xs_dayTimeDurationSeq: return "xs_dayTimeDurationSeq";
	case xs_dayTimeDurationSeqRef: return "xs_dayTimeDurationSeqRef";
	case xs_dayTimeDurationPlus: return "xs_dayTimeDurationPlus";
	case xs_dayTimeDurationOpt: return "xs_dayTimeDurationOpt";
	case xs_yearMonthDuration: return "xs_yearMonthDuration";
	case xs_yearMonthDurationRef: return "xs_yearMonthDurationRef";
	case xs_yearMonthDurationSeq: return "xs_yearMonthDurationSeq";
	case xs_yearMonthDurationSeqRef: return "xs_yearMonthDurationSeqRef";
	case xs_yearMonthDurationPlus: return "xs_yearMonthDurationPlus";
	case xs_yearMonthDurationOpt: return "xs_yearMonthDurationOpt";
	case xs_dateTime: return "xs_dateTime";
	case xs_dateTimeRef: return "xs_dateTimeRef";
	case xs_dateTimeSeq: return "xs_dateTimeSeq";
	case xs_dateTimeSeqRef: return "xs_dateTimeSeqRef";
	case xs_dateTimePlus: return "xs_dateTimePlus";
	case xs_dateTimeOpt: return "xs_dateTimeOpt";
	case xs_time: return "xs_time";
	case xs_timeRef: return "xs_timeRef";
	case xs_timeSeq: return "xs_timeSeq";
	case xs_timeSeqRef: return "xs_timeSeqRef";
	case xs_timePlus: return "xs_timePlus";
	case xs_timeOpt: return "xs_timeOpt";
	case xs_date: return "xs_date";
	case xs_dateRef: return "xs_dateRef";
	case xs_dateSeq: return "xs_dateSeq";
	case xs_dateSeqRef: return "xs_dateSeqRef";
	case xs_datePlus: return "xs_datePlus";
	case xs_dateOpt: return "xs_dateOpt";
	case xs_gYearMonth: return "xs_gYearMonth";
	case xs_gYearMonthRef: return "xs_gYearMonthRef";
	case xs_gYearMonthSeq: return "xs_gYearMonthSeq";
	case xs_gYearMonthSeqRef: return "xs_gYearMonthSeqRef";
	case xs_gYearMonthPlus: return "xs_gYearMonthPlus";
	case xs_gYearMonthOpt: return "xs_gYearMonthOpt";
	case xs_gYear: return "xs_gYear";
	case xs_gYearRef: return "xs_gYearRef";
	case xs_gYearSeq: return "xs_gYearSeq";
	case xs_gYearSeqRef: return "xs_gYearSeqRef";
	case xs_gYearPlus: return "xs_gYearPlus";
	case xs_gYearOpt: return "xs_gYearOpt";
	case xs_gMonthDay: return "xs_gMonthDay";
	case xs_gMonthDayRef: return "xs_gMonthDayRef";
	case xs_gMonthDaySeq: return "xs_gMonthDaySeq";
	case xs_gMonthDaySeqRef: return "xs_gMonthDaySeqRef";
	case xs_gMonthDayPlus: return "xs_gMonthDayPlus";
	case xs_gMonthDayOpt: return "xs_gMonthDayOpt";
	case xs_gDay: return "xs_gDay";
	case xs_gDayRef: return "xs_gDayRef";
	case xs_gDaySeq: return "xs_gDaySeq";
	case xs_gDaySeqRef: return "xs_gDaySeqRef";
	case xs_gDayPlus: return "xs_gDayPlus";
	case xs_gDayOpt: return "xs_gDayOpt";
	case xs_gMonth: return "xs_gMonth";
	case xs_gMonthRef: return "xs_gMonthRef";
	case xs_gMonthSeq: return "xs_gMonthSeq";
	case xs_gMonthSeqRef: return "xs_gMonthSeqRef";
	case xs_gMonthPlus: return "xs_gMonthPlus";
	case xs_gMonthOpt: return "xs_gMonthOpt";
	case xs_hexBinary: return "xs_hexBinary";
	case xs_hexBinaryRef: return "xs_hexBinaryRef";
	case xs_hexBinarySeq: return "xs_hexBinarySeq";
	case xs_hexBinarySeqRef: return "xs_hexBinarySeqRef";
	case xs_hexBinaryPlus: return "xs_hexBinaryPlus";
	case xs_hexBinaryOpt: return "xs_hexBinaryOpt";
	case xs_base64Binary: return "xs_base64Binary";
	case xs_base64BinaryRef: return "xs_base64BinaryRef";
	case xs_base64BinarySeq: return "xs_base64BinarySeq";
	case xs_base64BinarySeqRef: return "xs_base64BinarySeqRef";
	case xs_base64BinaryPlus: return "xs_base64BinaryPlus";
	case xs_base64BinaryOpt: return "xs_base64BinaryOpt";
	case xs_anyURI: return "xs_anyURI";
	case xs_anyURIRef: return "xs_anyURIRef";
	case xs_anyURISeq: return "xs_anyURISeq";
	case xs_anyURISeqRef: return "xs_anyURISeqRef";
	case xs_anyURIPlus: return "xs_anyURIPlus";
	case xs_anyURIOpt: return "xs_anyURIOpt";
	case xs_qname: return "xs_qname";
	case xs_qnameRef: return "xs_qnameRef";
	case xs_qnameSeq: return "xs_qnameSeq";
	case xs_qnameSeqRef: return "xs_qnameSeqRef";
	case xs_qnamePlus: return "xs_qnamePlus";
	case xs_qnameOpt: return "xs_qnameOpt";
	case xs_notation: return "xs_notation";
	case xs_notationRef: return "xs_notationRef";
	case xs_notationSeq: return "xs_notationSeq";
	case xs_notationSeqRef: return "xs_notationSeqRef";
	case xs_notationPlus: return "xs_notationPlus";
	case xs_notationOpt: return "xs_notationOpt";
	case xs_complexType: return "xs_complexType";
	case xs_complexTypeRef: return "xs_complexTypeRef";
	case xs_complexTypeSeq: return "xs_complexTypeSeq";
	case xs_complexTypeSeqRef: return "xs_complexTypeSeqRef";
	case xs_complexTypePlus: return "xs_complexTypePlus";
	case xs_complexTypeOpt: return "xs_complexTypeOpt";
	case xs_emptyType: return "xs_emptyType";
	case xs_emptyTypeRef: return "xs_emptyTypeRef";
	case xs_emptyTypeSeq: return "xs_emptyTypeSeq";
	case xs_emptyTypeSeqRef: return "xs_emptyTypeSeqRef";
	case xs_emptyTypePlus: return "xs_emptyTypePlus";
	case xs_emptyTypeOpt: return "xs_emptyTypeOpt";
	case xs_anyType: return "xs_anyType";
	case xs_anyTypeRef: return "xs_anyTypeRef";
	case xs_anyTypeSeq: return "xs_anyTypeSeq";
	case xs_anyTypeSeqRef: return "xs_anyTypeSeqRef";
	case xs_anyTypePlus: return "xs_anyTypePlus";
	case xs_anyTypeOpt: return "xs_anyTypeOpt";
	case xs_rawBinaryType: return "xs_rawBinaryType";
	case xs_rawBinaryTypeRef: return "xs_rawBinaryTypeRef";
	case xs_rawBinaryTypeSeq: return "xs_rawBinaryTypeSeq";
	case xs_rawBinaryTypeSeqRef: return "xs_rawBinaryTypeSeqRef";
	case xs_rawBinaryTypePlus: return "xs_rawBinaryTypePlus";
	case xs_rawBinaryTypeOpt: return "xs_rawBinaryTypeOpt";
	default: {
  	ostringstream oss;
  	oss <<"??? [" << (uint32_t)t << "]";
  	return oss.str();
	}}
}


}	/* namespace xqp */

