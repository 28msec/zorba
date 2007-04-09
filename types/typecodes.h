/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: TypeCodes.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan, Paul Pedersen
 */

// TODO: add emptySequence type?
// TODO: what about anyAtomicType?

#ifndef XQP_TYPECODES_H
#define XQP_TYPECODES_H

#include <stdint.h>

namespace xqp {

// The following defines are really internal to this file.

// Masks and shifts for the bitfields in a type code.
// The representations are at the little end
static const int OBJECT_MASK = 1 << 30 | 1 << 29 | 1 << 28;
static const int OBJECT_SHIFT = 28;
static const int ARITY_MASK = 1 << 27 | 1 << 26;
static const int ARITY_SHIFT = 26;
static const int NODE_MASK = 1 << 25 | 1 << 24 | 1 << 23 | 1 << 22;
static const int NODE_SHIFT = 22;
static const int NONATOMIC_MASK = 1 << 21;
static const int NONATOMIC_SHIFT = 21;
static const int TYPE_MASK = 1 << 20 | 1 << 19 | 1 << 18 | 1 << 17 | 1 << 16;
static const int TYPE_SHIFT = 16;
static const int SUB_MASK = 1 << 15 | 1 << 14;
static const int SUB_SHIFT = 14;
static const int SUB2_MASK = 1 << 13 | 1 << 12;
static const int SUB2_SHIFT = 12;
static const int SUB3_MASK = 1 << 11 | 1 << 10;
static const int SUB3_SHIFT = 10;
static const int SUB4_MASK = 1 << 9;
static const int SUB4_SHIFT = 9;
static const int SUB5_MASK = 1 << 8 | 1 << 7;
static const int SUB5_SHIFT = 7;
static const int SUB6_MASK = 1 << 6;
static const int SUB6_SHIFT = 6;
static const int REP_MASK = 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2 | 1 << 1 | 1 << 0;
static const int REP_SHIFT = 0;
static const int FULLTYPE_MASK = TYPE_MASK|SUB_MASK|SUB2_MASK|SUB3_MASK|SUB4_MASK|SUB5_MASK|SUB6_MASK;

// OBJECT specifies the most basic object type (value or something else)
// A SLACK_OBJECT is one which fills out a block at the end of a file
static const int VALUE_OBJECT = 0 << OBJECT_SHIFT;
static const int REF_OBJECT = 1 << OBJECT_SHIFT;
static const int FT_OBJECT = 2 << OBJECT_SHIFT;
static const int UPDATE_OBJECT = 3 << OBJECT_SHIFT;
static const int EXCEPTION_OBJECT = 4 << OBJECT_SHIFT;
static const int SLACK_OBJECT = 5 << OBJECT_SHIFT;

// ARITY specifies whether this value is an item or a sequence.
// Data items use ITEM_ARITY or SEQUENCE_ARITY.
// The other codes are used only to specify argument and result types of functions.
static const int ITEM_ARITY = 0 << ARITY_SHIFT;
static const int SEQUENCE_ARITY = 1 << ARITY_SHIFT;
static const int NONEMPTY_SEQ_ARITY = 2 << ARITY_SHIFT;
static const int OPT_ITEM_ARITY = 3 << ARITY_SHIFT;

// NODE specifies the node type.
// NOT_NODE is a dummy for values,
// ANY_NODE is a dummy for sequences of any type of node (but not a value).
static const int NOT_NODE = 0 << NODE_SHIFT;
static const int DOCUMENT_NODE = 1 << NODE_SHIFT;
static const int ELEMENT_NODE = 2 << NODE_SHIFT;
static const int ATTRIBUTE_NODE = 3 << NODE_SHIFT;
static const int NAMESPACE_NODE = 4 << NODE_SHIFT;
static const int PI_NODE = 5 << NODE_SHIFT;
static const int COMMENT_NODE = 6 << NODE_SHIFT;
static const int TEXT_NODE = 7 << NODE_SHIFT;
static const int ANY_NODE = 8 << NODE_SHIFT;

// NONATOMIC specifies if the type is atomic or not (complex or sequence)
// TODO: actually set this bit everywhere
// TODO: emptySequence definition
static const int NOT_NONATOMIC = 0 << NONATOMIC_SHIFT;
static const int IS_NONATOMIC = 1 << NONATOMIC_SHIFT;

// TYPE specifies the XML Schema type, plus these extensions:
// UNTYPED_TYPE is used for elements, UNTYPED_ATOMIC_TYPE for other node types.
// COMPLEX_TYPE is reserved for later use with complex types.
// EMPTY_TYPE is a pseudo-type used to construct empty sequences.
// ANY_TYPE is a pseudo-type used to specify "sequences of any type"
// RAW_BINARY_TYPE is not in XML Schema, and represents non-XML entity bodies.
// TYPE_TYPE is a type whose value is one of these typecodes.
static const int UNTYPED_TYPE = 0 << TYPE_SHIFT;
static const int UNTYPED_ATOMIC_TYPE = 1 << TYPE_SHIFT;
static const int STRING_TYPE = 2 << TYPE_SHIFT;
static const int DECIMAL_TYPE = 3 << TYPE_SHIFT;
static const int BOOLEAN_TYPE = 4 << TYPE_SHIFT;
static const int FLOAT_TYPE = 5 << TYPE_SHIFT;
static const int DOUBLE_TYPE = 6 << TYPE_SHIFT;
static const int DURATION_TYPE = 7 << TYPE_SHIFT;
static const int DATE_TIME_TYPE = 8 << TYPE_SHIFT;
static const int TIME_TYPE = 9 << TYPE_SHIFT;
static const int DATE_TYPE = 10 << TYPE_SHIFT;
static const int G_YEAR_MONTH_TYPE = 11 << TYPE_SHIFT;
static const int G_YEAR_TYPE = 12 << TYPE_SHIFT;
static const int G_MONTH_DAY_TYPE = 13 << TYPE_SHIFT;
static const int G_DAY_TYPE = 14 << TYPE_SHIFT;
static const int G_MONTH_TYPE = 15 << TYPE_SHIFT;
static const int HEX_BINARY_TYPE = 16 << TYPE_SHIFT;
static const int BASE_64_BINARY_TYPE = 17 << TYPE_SHIFT;
static const int ANY_URI_TYPE = 18 << TYPE_SHIFT;
static const int QNAME_TYPE = 19 << TYPE_SHIFT;
static const int NOTATION_TYPE = 20 << TYPE_SHIFT;
static const int COMPLEX_TYPE = 21 << TYPE_SHIFT;
static const int EMPTY_TYPE = 22 << TYPE_SHIFT;
static const int ANY_TYPE = 23 << TYPE_SHIFT;
static const int RAW_BINARY_TYPE = 24 << TYPE_SHIFT;
static const int TYPE_TYPE = 25 << TYPE_SHIFT;

// SUB-SUB6 specify derived XML Schema types.
// SUB should be read as "subtype", SUB2 as "sub-subtype", etc.
static const int NORMALIZED_STRING_SUB = STRING_TYPE | 1 << SUB_SHIFT;
static const int TOKEN_SUB2 = NORMALIZED_STRING_SUB | 1 << SUB2_SHIFT;
static const int LANGUAGE_SUB3 = TOKEN_SUB2 | 1 << SUB3_SHIFT;
static const int NMTOKEN_SUB3 = TOKEN_SUB2 | 2 << SUB3_SHIFT;
static const int NAME_SUB3 = TOKEN_SUB2 | 3 << SUB3_SHIFT;
static const int NCNAME_SUB4 = NAME_SUB3 | 1 << SUB4_SHIFT;
static const int ID_SUB5 = NCNAME_SUB4 | 1 << SUB5_SHIFT;
static const int IDREF_SUB5 = NCNAME_SUB4 | 2 << SUB5_SHIFT;
static const int ENTITY_SUB5 = NCNAME_SUB4 | 3 << SUB5_SHIFT;

static const int INTEGER_SUB = DECIMAL_TYPE | 1 << SUB_SHIFT;
static const int NON_POSITIVE_INTEGER_SUB2 = INTEGER_SUB | 1 << SUB2_SHIFT;
static const int NEGATIVE_INTEGER_SUB3 = NON_POSITIVE_INTEGER_SUB2 | 1 << SUB3_SHIFT;
static const int LONG_SUB2 = INTEGER_SUB | 2 << SUB2_SHIFT;
static const int INT_SUB3 = LONG_SUB2 | 1 << SUB3_SHIFT;
static const int SHORT_SUB4 = INT_SUB3 | 1 << SUB4_SHIFT;
static const int BYTE_SUB5 = SHORT_SUB4 | 1 << SUB5_SHIFT;
static const int NON_NEGATIVE_INTEGER_SUB2 = INTEGER_SUB | 3 << SUB2_SHIFT;
static const int UNSIGNED_LONG_SUB3 = NON_NEGATIVE_INTEGER_SUB2 | 1 << SUB3_SHIFT;
static const int UNSIGNED_INT_SUB4 = UNSIGNED_LONG_SUB3 | 1 << SUB4_SHIFT;
static const int UNSIGNED_SHORT_SUB5 = UNSIGNED_INT_SUB4 | 1 << SUB5_SHIFT;
static const int UNSIGNED_BYTE_SUB6 = UNSIGNED_SHORT_SUB5 | 1 << SUB6_SHIFT;
static const int POSITIVE_INTEGER_SUB3 = NON_NEGATIVE_INTEGER_SUB2 | 2 << SUB3_SHIFT;

static const int DAY_TIME_DURATION_SUB = DURATION_TYPE | 1 << SUB_SHIFT;
static const int YEAR_MONTH_DURATION_SUB = DURATION_TYPE | 2 << SUB_SHIFT;

// REP specifies the representation (C++ class)
// More reps may be added in future.
// Initially DECIMAL_REP is not used.
// NO_REP means this type is never instantiated
// BARE_REP means this type does not need a special rep class but is just a type+length.
static const int NO_REP = 0 << REP_SHIFT;
static const int DOCUMENT_REP = 1 << REP_SHIFT;
static const int ELEMENT_REP = 2 << REP_SHIFT;
static const int ATTRIBUTE_REP = 3 << REP_SHIFT;
static const int NAMESPACE_REP = 4 << REP_SHIFT;
static const int PI_REP = 5 << REP_SHIFT;
static const int COMMENT_REP = 6 << REP_SHIFT;
static const int TEXT_REP = 7 << REP_SHIFT;
static const int STRING_REP = 8 << REP_SHIFT;
static const int DECIMAL_REP = 9 << REP_SHIFT;
static const int DOUBLE_REP = 10 << REP_SHIFT;
static const int BOOLEAN_REP = 11 << REP_SHIFT;
static const int TIME_REP = 12 << REP_SHIFT;
static const int BINARY_REP = 13 << REP_SHIFT;
static const int QNAME_REP = 14 << REP_SHIFT;
static const int SEQUENCE_REP = 15 << REP_SHIFT;
static const int BARE_REP = 16 << REP_SHIFT;
static const int COMPLEX_TYPE_REP = 17 << REP_SHIFT;
static const int TYPE_REP = 18 << REP_SHIFT;

// Okay, at last the bit-twiddling is done.  Now we just make an enum of type codes
// that assembles the correct values together.
// Use fix_typecodes to regenerate the Ref, Seq, SeqRef, Plus, and Opt definitions.

enum TypeCode {
	// Node items.
	documentNode = ITEM_ARITY + DOCUMENT_NODE + UNTYPED_TYPE + DOCUMENT_REP,
	documentNodeSeq = SEQUENCE_ARITY + DOCUMENT_NODE + UNTYPED_TYPE + SEQUENCE_REP,
	documentNodePlus = NONEMPTY_SEQ_ARITY + DOCUMENT_NODE + UNTYPED_TYPE + NO_REP,
	documentNodeOpt = OPT_ITEM_ARITY + DOCUMENT_NODE + UNTYPED_TYPE + NO_REP,
	elementNode = ITEM_ARITY + ELEMENT_NODE + UNTYPED_TYPE + ELEMENT_REP,
	elementNodeSeq = SEQUENCE_ARITY + ELEMENT_NODE + UNTYPED_TYPE + SEQUENCE_REP,
	elementNodePlus = NONEMPTY_SEQ_ARITY + ELEMENT_NODE + UNTYPED_TYPE + NO_REP,
	elementNodeOpt = OPT_ITEM_ARITY + ELEMENT_NODE + UNTYPED_TYPE + NO_REP,
	attributeNode = ITEM_ARITY + ATTRIBUTE_NODE + UNTYPED_ATOMIC_TYPE + ATTRIBUTE_REP,
	attributeNodeSeq = SEQUENCE_ARITY + ATTRIBUTE_NODE + UNTYPED_ATOMIC_TYPE + SEQUENCE_REP,
	attributeNodePlus = NONEMPTY_SEQ_ARITY + ATTRIBUTE_NODE + UNTYPED_ATOMIC_TYPE + NO_REP,
	attributeNodeOpt = OPT_ITEM_ARITY + ATTRIBUTE_NODE + UNTYPED_ATOMIC_TYPE + NO_REP,
	namespaceNode = ITEM_ARITY + NAMESPACE_NODE + UNTYPED_TYPE + NAMESPACE_REP,
	namespaceNodeSeq = SEQUENCE_ARITY + NAMESPACE_NODE + UNTYPED_TYPE + SEQUENCE_REP,
	namespaceNodePlus = NONEMPTY_SEQ_ARITY + NAMESPACE_NODE + UNTYPED_TYPE + NO_REP,
	namespaceNodeOpt = OPT_ITEM_ARITY + NAMESPACE_NODE + UNTYPED_TYPE + NO_REP,
	processingInstructionNode = ITEM_ARITY + PI_NODE + UNTYPED_TYPE + PI_REP,
	processingInstructionNodeSeq = SEQUENCE_ARITY + PI_NODE + UNTYPED_TYPE + SEQUENCE_REP,
	processingInstructionNodePlus = NONEMPTY_SEQ_ARITY + PI_NODE + UNTYPED_TYPE + NO_REP,
	processingInstructionNodeOpt = OPT_ITEM_ARITY + PI_NODE + UNTYPED_TYPE + NO_REP,
	commentNode = ITEM_ARITY + COMMENT_NODE + UNTYPED_TYPE + COMMENT_REP,
	commentNodeSeq = SEQUENCE_ARITY + COMMENT_NODE + UNTYPED_TYPE + SEQUENCE_REP,
	commentNodePlus = NONEMPTY_SEQ_ARITY + COMMENT_NODE + UNTYPED_TYPE + NO_REP,
	commentNodeOpt = OPT_ITEM_ARITY + COMMENT_NODE + UNTYPED_TYPE + NO_REP,
	textNode = ITEM_ARITY + TEXT_NODE + UNTYPED_TYPE + TEXT_REP,
	textNodeSeq = SEQUENCE_ARITY + TEXT_NODE + UNTYPED_TYPE + SEQUENCE_REP,
	textNodePlus = NONEMPTY_SEQ_ARITY + TEXT_NODE + UNTYPED_TYPE + NO_REP,
	textNodeOpt = OPT_ITEM_ARITY + TEXT_NODE + UNTYPED_TYPE + NO_REP,
	anyNode = ITEM_ARITY + ANY_NODE + UNTYPED_TYPE + NO_REP,
	anyNodeSeq = SEQUENCE_ARITY + ANY_NODE + UNTYPED_TYPE + SEQUENCE_REP,
	anyNodePlus = NONEMPTY_SEQ_ARITY + ANY_NODE + UNTYPED_TYPE + NO_REP,
	anyNodeOpt = OPT_ITEM_ARITY + ANY_NODE + UNTYPED_TYPE + NO_REP,

	// String values.
	xs_string = ITEM_ARITY + NOT_NODE + STRING_TYPE + STRING_REP,
	xs_stringSeq = SEQUENCE_ARITY + NOT_NODE + STRING_TYPE + SEQUENCE_REP,
	xs_stringPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + STRING_TYPE + NO_REP,
	xs_stringOpt = OPT_ITEM_ARITY + NOT_NODE + STRING_TYPE + NO_REP,
	xs_normalizedString = ITEM_ARITY + NOT_NODE + NORMALIZED_STRING_SUB + STRING_REP,
	xs_normalizedStringSeq = SEQUENCE_ARITY + NOT_NODE + NORMALIZED_STRING_SUB + SEQUENCE_REP,
	xs_normalizedStringPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NORMALIZED_STRING_SUB + NO_REP,
	xs_normalizedStringOpt = OPT_ITEM_ARITY + NOT_NODE + NORMALIZED_STRING_SUB + NO_REP,
	xs_token = ITEM_ARITY + NOT_NODE + TOKEN_SUB2 + STRING_REP,
	xs_tokenSeq = SEQUENCE_ARITY + NOT_NODE + TOKEN_SUB2 + SEQUENCE_REP,
	xs_tokenPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + TOKEN_SUB2 + NO_REP,
	xs_tokenOpt = OPT_ITEM_ARITY + NOT_NODE + TOKEN_SUB2 + NO_REP,
	xs_language = ITEM_ARITY + NOT_NODE + LANGUAGE_SUB3 + STRING_REP,
	xs_languageSeq = SEQUENCE_ARITY + NOT_NODE + LANGUAGE_SUB3 + SEQUENCE_REP,
	xs_languagePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + LANGUAGE_SUB3 + NO_REP,
	xs_languageOpt = OPT_ITEM_ARITY + NOT_NODE + LANGUAGE_SUB3 + NO_REP,
	xs_nmtoken = ITEM_ARITY + NOT_NODE + NMTOKEN_SUB3 + STRING_REP,
	xs_nmtokenSeq = SEQUENCE_ARITY + NOT_NODE + NMTOKEN_SUB3 + SEQUENCE_REP,
	xs_nmtokenPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NMTOKEN_SUB3 + NO_REP,
	xs_nmtokenOpt = OPT_ITEM_ARITY + NOT_NODE + NMTOKEN_SUB3 + NO_REP,
	xs_name = ITEM_ARITY + NOT_NODE + NAME_SUB3 + STRING_REP,
	xs_nameSeq = SEQUENCE_ARITY + NOT_NODE + NAME_SUB3 + SEQUENCE_REP,
	xs_namePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NAME_SUB3 + NO_REP,
	xs_nameOpt = OPT_ITEM_ARITY + NOT_NODE + NAME_SUB3 + NO_REP,
	xs_ncName = ITEM_ARITY + NOT_NODE + NCNAME_SUB4 + STRING_REP,
	xs_ncNameSeq = SEQUENCE_ARITY + NOT_NODE + NCNAME_SUB4 + SEQUENCE_REP,
	xs_ncNamePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NCNAME_SUB4 + NO_REP,
	xs_ncNameOpt = OPT_ITEM_ARITY + NOT_NODE + NCNAME_SUB4 + NO_REP,
	xs_id = ITEM_ARITY + NOT_NODE + ID_SUB5 + STRING_REP,
	xs_idSeq = SEQUENCE_ARITY + NOT_NODE + ID_SUB5 + SEQUENCE_REP,
	xs_idPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + ID_SUB5 + NO_REP,
	xs_idOpt = OPT_ITEM_ARITY + NOT_NODE + ID_SUB5 + NO_REP,
	xs_idref = ITEM_ARITY + NOT_NODE + IDREF_SUB5 + STRING_REP,
	xs_idrefSeq = SEQUENCE_ARITY + NOT_NODE + IDREF_SUB5 + SEQUENCE_REP,
	xs_idrefPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + IDREF_SUB5 + NO_REP,
	xs_idrefOpt = OPT_ITEM_ARITY + NOT_NODE + IDREF_SUB5 + NO_REP,
	xs_entity = ITEM_ARITY + NOT_NODE + ENTITY_SUB5 + STRING_REP,
	xs_entitySeq = SEQUENCE_ARITY + NOT_NODE + ENTITY_SUB5 + SEQUENCE_REP,
	xs_entityPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + ENTITY_SUB5 + NO_REP,
	xs_entityOpt = OPT_ITEM_ARITY + NOT_NODE + ENTITY_SUB5 + NO_REP,

	// Numeric values.
	//xs_decimal = ITEM_ARITY + NOT_NODE + DECIMAL_TYPE + DECIMAL_REP, 
	//xs_decimalSeq = SEQUENCE_ARITY + NOT_NODE + DECIMAL_TYPE + SEQUENCE_REP, 
	//xs_decimalPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + DECIMAL_TYPE + NO_REP, 
	//xs_decimalOpt = OPT_ITEM_ARITY + NOT_NODE + DECIMAL_TYPE + NO_REP, 
	xs_decimal = ITEM_ARITY + NOT_NODE + DECIMAL_TYPE + DOUBLE_REP,  // no decimal rep yet
	xs_decimalSeq = SEQUENCE_ARITY + NOT_NODE + DECIMAL_TYPE + SEQUENCE_REP,  // no decimal rep yet
	xs_decimalPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + DECIMAL_TYPE + NO_REP,  // no decimal rep yet
	xs_decimalOpt = OPT_ITEM_ARITY + NOT_NODE + DECIMAL_TYPE + NO_REP,  // no decimal rep yet
	//xs_integer = ITEM_ARITY + NOT_NODE + INTEGER_SUB + DECIMAL_REP,
	//xs_integerSeq = SEQUENCE_ARITY + NOT_NODE + INTEGER_SUB + SEQUENCE_REP,
	//xs_integerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + INTEGER_SUB + NO_REP,
	//xs_integerOpt = OPT_ITEM_ARITY + NOT_NODE + INTEGER_SUB + NO_REP,
	xs_integer = ITEM_ARITY + NOT_NODE + DOUBLE_REP + INTEGER_SUB,	// no decimal rep yet
	xs_integerSeq = SEQUENCE_ARITY + NOT_NODE + SEQUENCE_REP + INTEGER_SUB,	// no decimal rep yet
	xs_integerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NO_REP + INTEGER_SUB,	// no decimal rep yet
	xs_integerOpt = OPT_ITEM_ARITY + NOT_NODE + NO_REP + INTEGER_SUB,	// no decimal rep yet
	//xs_nonPositiveInteger = ITEM_ARITY + NOT_NODE + NON_POSITIVE_INTEGER_SUB2 + DECIMAL_REP, 
	//xs_nonPositiveIntegerSeq = SEQUENCE_ARITY + NOT_NODE + NON_POSITIVE_INTEGER_SUB2 + SEQUENCE_REP, 
	//xs_nonPositiveIntegerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NON_POSITIVE_INTEGER_SUB2 + NO_REP, 
	//xs_nonPositiveIntegerOpt = OPT_ITEM_ARITY + NOT_NODE + NON_POSITIVE_INTEGER_SUB2 + NO_REP, 
	xs_nonPositiveInteger = ITEM_ARITY + NOT_NODE + NON_POSITIVE_INTEGER_SUB2 + DOUBLE_REP,	// no decimal rep yet
	xs_nonPositiveIntegerSeq = SEQUENCE_ARITY + NOT_NODE + NON_POSITIVE_INTEGER_SUB2 + SEQUENCE_REP,	// no decimal rep yet
	xs_nonPositiveIntegerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NON_POSITIVE_INTEGER_SUB2 + NO_REP,	// no decimal rep yet
	xs_nonPositiveIntegerOpt = OPT_ITEM_ARITY + NOT_NODE + NON_POSITIVE_INTEGER_SUB2 + NO_REP,	// no decimal rep yet
	//xs_negativeInteger = ITEM_ARITY + NOT_NODE + NEGATIVE_INTEGER_SUB3 + DECIMAL_REP,
	//xs_negativeIntegerSeq = SEQUENCE_ARITY + NOT_NODE + NEGATIVE_INTEGER_SUB3 + SEQUENCE_REP,
	//xs_negativeIntegerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NEGATIVE_INTEGER_SUB3 + NO_REP,
	//xs_negativeIntegerOpt = OPT_ITEM_ARITY + NOT_NODE + NEGATIVE_INTEGER_SUB3 + NO_REP,
	xs_negativeInteger = ITEM_ARITY + NOT_NODE + NEGATIVE_INTEGER_SUB3 + DOUBLE_REP,	// no decimal rep yet
	xs_negativeIntegerSeq = SEQUENCE_ARITY + NOT_NODE + NEGATIVE_INTEGER_SUB3 + SEQUENCE_REP,	// no decimal rep yet
	xs_negativeIntegerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NEGATIVE_INTEGER_SUB3 + NO_REP,	// no decimal rep yet
	xs_negativeIntegerOpt = OPT_ITEM_ARITY + NOT_NODE + NEGATIVE_INTEGER_SUB3 + NO_REP,	// no decimal rep yet
	//xs_long = ITEM_ARITY + NOT_NODE + LONG_SUB2 + DECIMAL_REP,
	//xs_longSeq = SEQUENCE_ARITY + NOT_NODE + LONG_SUB2 + SEQUENCE_REP,
	//xs_longPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + LONG_SUB2 + NO_REP,
	//xs_longOpt = OPT_ITEM_ARITY + NOT_NODE + LONG_SUB2 + NO_REP,
	xs_long = ITEM_ARITY + NOT_NODE + LONG_SUB2 + DOUBLE_REP,	// no decimal rep yet
	xs_longSeq = SEQUENCE_ARITY + NOT_NODE + LONG_SUB2 + SEQUENCE_REP,	// no decimal rep yet
	xs_longPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + LONG_SUB2 + NO_REP,	// no decimal rep yet
	xs_longOpt = OPT_ITEM_ARITY + NOT_NODE + LONG_SUB2 + NO_REP,	// no decimal rep yet
	xs_int = ITEM_ARITY + NOT_NODE + INT_SUB3 + DOUBLE_REP,
	xs_intSeq = SEQUENCE_ARITY + NOT_NODE + INT_SUB3 + SEQUENCE_REP,
	xs_intPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + INT_SUB3 + NO_REP,
	xs_intOpt = OPT_ITEM_ARITY + NOT_NODE + INT_SUB3 + NO_REP,
	xs_short = ITEM_ARITY + NOT_NODE + SHORT_SUB4 + DOUBLE_REP,
	xs_shortSeq = SEQUENCE_ARITY + NOT_NODE + SHORT_SUB4 + SEQUENCE_REP,
	xs_shortPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + SHORT_SUB4 + NO_REP,
	xs_shortOpt = OPT_ITEM_ARITY + NOT_NODE + SHORT_SUB4 + NO_REP,
	xs_byte = ITEM_ARITY + NOT_NODE + BYTE_SUB5 + DECIMAL_REP,
	xs_byteSeq = SEQUENCE_ARITY + NOT_NODE + BYTE_SUB5 + SEQUENCE_REP,
	xs_bytePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + BYTE_SUB5 + NO_REP,
	xs_byteOpt = OPT_ITEM_ARITY + NOT_NODE + BYTE_SUB5 + NO_REP,
	//xs_nonNegativeInteger = ITEM_ARITY + NOT_NODE + NON_EGATIVE_INTEGER_SUB2 + DECIMAL_REP,
	//xs_nonNegativeIntegerSeq = SEQUENCE_ARITY + NOT_NODE + NON_EGATIVE_INTEGER_SUB2 + SEQUENCE_REP,
	//xs_nonNegativeIntegerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NON_EGATIVE_INTEGER_SUB2 + NO_REP,
	//xs_nonNegativeIntegerOpt = OPT_ITEM_ARITY + NOT_NODE + NON_EGATIVE_INTEGER_SUB2 + NO_REP,
	xs_nonNegativeInteger = ITEM_ARITY + NOT_NODE + NON_NEGATIVE_INTEGER_SUB2 + DOUBLE_REP,  // no decimal rep yet
	xs_nonNegativeIntegerSeq = SEQUENCE_ARITY + NOT_NODE + NON_NEGATIVE_INTEGER_SUB2 + SEQUENCE_REP,  // no decimal rep yet
	xs_nonNegativeIntegerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NON_NEGATIVE_INTEGER_SUB2 + NO_REP,  // no decimal rep yet
	xs_nonNegativeIntegerOpt = OPT_ITEM_ARITY + NOT_NODE + NON_NEGATIVE_INTEGER_SUB2 + NO_REP,  // no decimal rep yet
	//xs_unsignedLong = ITEM_ARITY + NOT_NODE + UNSIGNED_LONG_SUB3 + DECIMAL_REP,
	//xs_unsignedLongSeq = SEQUENCE_ARITY + NOT_NODE + UNSIGNED_LONG_SUB3 + SEQUENCE_REP,
	//xs_unsignedLongPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + UNSIGNED_LONG_SUB3 + NO_REP,
	//xs_unsignedLongOpt = OPT_ITEM_ARITY + NOT_NODE + UNSIGNED_LONG_SUB3 + NO_REP,
	xs_unsignedLong = ITEM_ARITY + NOT_NODE + UNSIGNED_LONG_SUB3 + DOUBLE_REP,	// no decimal rep yet
	xs_unsignedLongSeq = SEQUENCE_ARITY + NOT_NODE + UNSIGNED_LONG_SUB3 + SEQUENCE_REP,	// no decimal rep yet
	xs_unsignedLongPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + UNSIGNED_LONG_SUB3 + NO_REP,	// no decimal rep yet
	xs_unsignedLongOpt = OPT_ITEM_ARITY + NOT_NODE + UNSIGNED_LONG_SUB3 + NO_REP,	// no decimal rep yet
	xs_unsignedInt = ITEM_ARITY + NOT_NODE + UNSIGNED_INT_SUB4 + DECIMAL_REP,
	xs_unsignedIntSeq = SEQUENCE_ARITY + NOT_NODE + UNSIGNED_INT_SUB4 + SEQUENCE_REP,
	xs_unsignedIntPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + UNSIGNED_INT_SUB4 + NO_REP,
	xs_unsignedIntOpt = OPT_ITEM_ARITY + NOT_NODE + UNSIGNED_INT_SUB4 + NO_REP,
	xs_unsignedShort = ITEM_ARITY + NOT_NODE + UNSIGNED_SHORT_SUB5 + DOUBLE_REP,
	xs_unsignedShortSeq = SEQUENCE_ARITY + NOT_NODE + UNSIGNED_SHORT_SUB5 + SEQUENCE_REP,
	xs_unsignedShortPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + UNSIGNED_SHORT_SUB5 + NO_REP,
	xs_unsignedShortOpt = OPT_ITEM_ARITY + NOT_NODE + UNSIGNED_SHORT_SUB5 + NO_REP,
	xs_unsignedByte = ITEM_ARITY + NOT_NODE + UNSIGNED_BYTE_SUB6 + DECIMAL_REP,
	xs_unsignedByteSeq = SEQUENCE_ARITY + NOT_NODE + UNSIGNED_BYTE_SUB6 + SEQUENCE_REP,
	xs_unsignedBytePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + UNSIGNED_BYTE_SUB6 + NO_REP,
	xs_unsignedByteOpt = OPT_ITEM_ARITY + NOT_NODE + UNSIGNED_BYTE_SUB6 + NO_REP,
//xs_positiveInteger = ITEM_ARITY + NOT_NODE + POSITIVE_INTEGER_SUB3 + DECIMAL_REP,  // no decimal rep yet
//xs_positiveIntegerSeq = SEQUENCE_ARITY + NOT_NODE + POSITIVE_INTEGER_SUB3 + SEQUENCE_REP,  // no decimal rep yet
//xs_positiveIntegerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + POSITIVE_INTEGER_SUB3 + NO_REP,  // no decimal rep yet
//xs_positiveIntegerOpt = OPT_ITEM_ARITY + NOT_NODE + POSITIVE_INTEGER_SUB3 + NO_REP,  // no decimal rep yet
	xs_positiveInteger = ITEM_ARITY + NOT_NODE + POSITIVE_INTEGER_SUB3 + DOUBLE_REP,
	xs_positiveIntegerSeq = SEQUENCE_ARITY + NOT_NODE + POSITIVE_INTEGER_SUB3 + SEQUENCE_REP,
	xs_positiveIntegerPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + POSITIVE_INTEGER_SUB3 + NO_REP,
	xs_positiveIntegerOpt = OPT_ITEM_ARITY + NOT_NODE + POSITIVE_INTEGER_SUB3 + NO_REP,

	// Other atomic values.
	xs_untypedValue = ITEM_ARITY + NOT_NODE + UNTYPED_TYPE + STRING_REP,
	xs_untypedValueSeq = SEQUENCE_ARITY + NOT_NODE + UNTYPED_TYPE + SEQUENCE_REP,
	xs_untypedValuePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + UNTYPED_TYPE + NO_REP,
	xs_untypedValueOpt = OPT_ITEM_ARITY + NOT_NODE + UNTYPED_TYPE + NO_REP,
	xs_untypedAtomicValue = ITEM_ARITY + NOT_NODE+ UNTYPED_ATOMIC_TYPE + STRING_REP ,
	xs_untypedAtomicValueSeq = SEQUENCE_ARITY + NOT_NODE+ UNTYPED_ATOMIC_TYPE + SEQUENCE_REP ,
	xs_untypedAtomicValuePlus = NONEMPTY_SEQ_ARITY + NOT_NODE+ UNTYPED_ATOMIC_TYPE + NO_REP ,
	xs_untypedAtomicValueOpt = OPT_ITEM_ARITY + NOT_NODE+ UNTYPED_ATOMIC_TYPE + NO_REP ,
	xs_boolean = ITEM_ARITY + NOT_NODE + BOOLEAN_TYPE + BOOLEAN_REP,
	xs_booleanSeq = SEQUENCE_ARITY + NOT_NODE + BOOLEAN_TYPE + SEQUENCE_REP,
	xs_booleanPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + BOOLEAN_TYPE + NO_REP,
	xs_booleanOpt = OPT_ITEM_ARITY + NOT_NODE + BOOLEAN_TYPE + NO_REP,
	xs_float = ITEM_ARITY + NOT_NODE + FLOAT_TYPE + DOUBLE_REP,
	xs_floatSeq = SEQUENCE_ARITY + NOT_NODE + FLOAT_TYPE + SEQUENCE_REP,
	xs_floatPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + FLOAT_TYPE + NO_REP,
	xs_floatOpt = OPT_ITEM_ARITY + NOT_NODE + FLOAT_TYPE + NO_REP,
	xs_double = ITEM_ARITY + NOT_NODE + DOUBLE_TYPE + DOUBLE_REP,
	xs_doubleSeq = SEQUENCE_ARITY + NOT_NODE + DOUBLE_TYPE + SEQUENCE_REP,
	xs_doublePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + DOUBLE_TYPE + NO_REP,
	xs_doubleOpt = OPT_ITEM_ARITY + NOT_NODE + DOUBLE_TYPE + NO_REP,
	xs_duration = ITEM_ARITY + NOT_NODE + DURATION_TYPE + TIME_REP,
	xs_durationSeq = SEQUENCE_ARITY + NOT_NODE + DURATION_TYPE + SEQUENCE_REP,
	xs_durationPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + DURATION_TYPE + NO_REP,
	xs_durationOpt = OPT_ITEM_ARITY + NOT_NODE + DURATION_TYPE + NO_REP,
	xs_dayTimeDuration = ITEM_ARITY + NOT_NODE + DAY_TIME_DURATION_SUB + TIME_REP,
	xs_dayTimeDurationSeq = SEQUENCE_ARITY + NOT_NODE + DAY_TIME_DURATION_SUB + SEQUENCE_REP,
	xs_dayTimeDurationPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + DAY_TIME_DURATION_SUB + NO_REP,
	xs_dayTimeDurationOpt = OPT_ITEM_ARITY + NOT_NODE + DAY_TIME_DURATION_SUB + NO_REP,
	xs_yearMonthDuration = ITEM_ARITY + NOT_NODE + YEAR_MONTH_DURATION_SUB + TIME_REP,
	xs_yearMonthDurationSeq = SEQUENCE_ARITY + NOT_NODE + YEAR_MONTH_DURATION_SUB + SEQUENCE_REP,
	xs_yearMonthDurationPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + YEAR_MONTH_DURATION_SUB + NO_REP,
	xs_yearMonthDurationOpt = OPT_ITEM_ARITY + NOT_NODE + YEAR_MONTH_DURATION_SUB + NO_REP,
	xs_dateTime = ITEM_ARITY + NOT_NODE + DATE_TIME_TYPE + TIME_REP,
	xs_dateTimeSeq = SEQUENCE_ARITY + NOT_NODE + DATE_TIME_TYPE + SEQUENCE_REP,
	xs_dateTimePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + DATE_TIME_TYPE + NO_REP,
	xs_dateTimeOpt = OPT_ITEM_ARITY + NOT_NODE + DATE_TIME_TYPE + NO_REP,
	xs_time = ITEM_ARITY + NOT_NODE + TIME_TYPE + TIME_REP,
	xs_timeSeq = SEQUENCE_ARITY + NOT_NODE + TIME_TYPE + SEQUENCE_REP,
	xs_timePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + TIME_TYPE + NO_REP,
	xs_timeOpt = OPT_ITEM_ARITY + NOT_NODE + TIME_TYPE + NO_REP,
	xs_date = ITEM_ARITY + NOT_NODE + DATE_TYPE + TIME_REP,
	xs_dateSeq = SEQUENCE_ARITY + NOT_NODE + DATE_TYPE + SEQUENCE_REP,
	xs_datePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + DATE_TYPE + NO_REP,
	xs_dateOpt = OPT_ITEM_ARITY + NOT_NODE + DATE_TYPE + NO_REP,
	xs_gYearMonth = ITEM_ARITY + NOT_NODE + G_YEAR_MONTH_TYPE + TIME_REP,
	xs_gYearMonthSeq = SEQUENCE_ARITY + NOT_NODE + G_YEAR_MONTH_TYPE + SEQUENCE_REP,
	xs_gYearMonthPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + G_YEAR_MONTH_TYPE + NO_REP,
	xs_gYearMonthOpt = OPT_ITEM_ARITY + NOT_NODE + G_YEAR_MONTH_TYPE + NO_REP,
	xs_gYear = ITEM_ARITY + NOT_NODE+ G_YEAR_TYPE + TIME_REP ,
	xs_gYearSeq = SEQUENCE_ARITY + NOT_NODE+ G_YEAR_TYPE + SEQUENCE_REP ,
	xs_gYearPlus = NONEMPTY_SEQ_ARITY + NOT_NODE+ G_YEAR_TYPE + NO_REP ,
	xs_gYearOpt = OPT_ITEM_ARITY + NOT_NODE+ G_YEAR_TYPE + NO_REP ,
	xs_gMonthDay = ITEM_ARITY + NOT_NODE + G_MONTH_DAY_TYPE + TIME_REP,
	xs_gMonthDaySeq = SEQUENCE_ARITY + NOT_NODE + G_MONTH_DAY_TYPE + SEQUENCE_REP,
	xs_gMonthDayPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + G_MONTH_DAY_TYPE + NO_REP,
	xs_gMonthDayOpt = OPT_ITEM_ARITY + NOT_NODE + G_MONTH_DAY_TYPE + NO_REP,
	xs_gDay = ITEM_ARITY + NOT_NODE + G_DAY_TYPE + TIME_REP,
	xs_gDaySeq = SEQUENCE_ARITY + NOT_NODE + G_DAY_TYPE + SEQUENCE_REP,
	xs_gDayPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + G_DAY_TYPE + NO_REP,
	xs_gDayOpt = OPT_ITEM_ARITY + NOT_NODE + G_DAY_TYPE + NO_REP,
	xs_gMonth = ITEM_ARITY + NOT_NODE + G_MONTH_TYPE + TIME_REP,
	xs_gMonthSeq = SEQUENCE_ARITY + NOT_NODE + G_MONTH_TYPE + SEQUENCE_REP,
	xs_gMonthPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + G_MONTH_TYPE + NO_REP,
	xs_gMonthOpt = OPT_ITEM_ARITY + NOT_NODE + G_MONTH_TYPE + NO_REP,
	xs_hexBinary = ITEM_ARITY + NOT_NODE + HEX_BINARY_TYPE + BINARY_REP,
	xs_hexBinarySeq = SEQUENCE_ARITY + NOT_NODE + HEX_BINARY_TYPE + SEQUENCE_REP,
	xs_hexBinaryPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + HEX_BINARY_TYPE + NO_REP,
	xs_hexBinaryOpt = OPT_ITEM_ARITY + NOT_NODE + HEX_BINARY_TYPE + NO_REP,
	xs_base64Binary = ITEM_ARITY + NOT_NODE + BASE_64_BINARY_TYPE + BINARY_REP,
	xs_base64BinarySeq = SEQUENCE_ARITY + NOT_NODE + BASE_64_BINARY_TYPE + SEQUENCE_REP,
	xs_base64BinaryPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + BASE_64_BINARY_TYPE + NO_REP,
	xs_base64BinaryOpt = OPT_ITEM_ARITY + NOT_NODE + BASE_64_BINARY_TYPE + NO_REP,
	xs_anyURI = ITEM_ARITY + NOT_NODE + ANY_URI_TYPE + STRING_REP,
	xs_anyURISeq = SEQUENCE_ARITY + NOT_NODE + ANY_URI_TYPE + SEQUENCE_REP,
	xs_anyURIPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + ANY_URI_TYPE + NO_REP,
	xs_anyURIOpt = OPT_ITEM_ARITY + NOT_NODE + ANY_URI_TYPE + NO_REP,
	xs_qname = ITEM_ARITY + NOT_NODE + QNAME_TYPE + QNAME_REP,
	xs_qnameSeq = SEQUENCE_ARITY + NOT_NODE + QNAME_TYPE + SEQUENCE_REP,
	xs_qnamePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + QNAME_TYPE + NO_REP,
	xs_qnameOpt = OPT_ITEM_ARITY + NOT_NODE + QNAME_TYPE + NO_REP,
	xs_notation = ITEM_ARITY + NOT_NODE + NOTATION_TYPE + QNAME_REP,
	xs_notationSeq = SEQUENCE_ARITY + NOT_NODE + NOTATION_TYPE + SEQUENCE_REP,
	xs_notationPlus = NONEMPTY_SEQ_ARITY + NOT_NODE + NOTATION_TYPE + NO_REP,
	xs_notationOpt = OPT_ITEM_ARITY + NOT_NODE + NOTATION_TYPE + NO_REP,
	xs_complexType = ITEM_ARITY + NOT_NODE + COMPLEX_TYPE + QNAME_REP,
	xs_complexTypeSeq = SEQUENCE_ARITY + NOT_NODE + COMPLEX_TYPE + SEQUENCE_REP,
	xs_complexTypePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + COMPLEX_TYPE + NO_REP,
	xs_complexTypeOpt = OPT_ITEM_ARITY + NOT_NODE + COMPLEX_TYPE + NO_REP,
	xs_emptyType = ITEM_ARITY + NOT_NODE + EMPTY_TYPE + NO_REP,
	xs_emptyTypeSeq = SEQUENCE_ARITY + NOT_NODE + EMPTY_TYPE + SEQUENCE_REP,
	xs_emptyTypePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + EMPTY_TYPE + NO_REP,
	xs_emptyTypeOpt = OPT_ITEM_ARITY + NOT_NODE + EMPTY_TYPE + NO_REP,
	xs_anyType = ITEM_ARITY + NOT_NODE + ANY_TYPE + NO_REP,
	xs_anyTypeSeq = SEQUENCE_ARITY + NOT_NODE + ANY_TYPE + SEQUENCE_REP,
	xs_anyTypePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + ANY_TYPE + NO_REP,
	xs_anyTypeOpt = OPT_ITEM_ARITY + NOT_NODE + ANY_TYPE + NO_REP,
	xs_rawBinaryType = ITEM_ARITY + NOT_NODE + RAW_BINARY_TYPE + BINARY_REP,
	xs_rawBinaryTypeSeq = SEQUENCE_ARITY + NOT_NODE + RAW_BINARY_TYPE + SEQUENCE_REP,
	xs_rawBinaryTypePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + RAW_BINARY_TYPE + NO_REP,
	xs_rawBinaryTypeOpt = OPT_ITEM_ARITY + NOT_NODE + RAW_BINARY_TYPE + NO_REP,
	xs_typeType = ITEM_ARITY + NOT_NODE + TYPE_TYPE + TYPE_REP,
	xs_typeTypeSeq = SEQUENCE_ARITY + NOT_NODE + TYPE_TYPE + SEQUENCE_REP,
	xs_typeTypePlus = NONEMPTY_SEQ_ARITY + NOT_NODE + TYPE_TYPE + NO_REP,
	xs_typeTypeOpt = OPT_ITEM_ARITY + NOT_NODE + TYPE_TYPE + NO_REP,
};

} /* namespace xqp */
#endif /* XQP_TYPECODES_H */

