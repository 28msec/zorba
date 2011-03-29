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

#ifndef ZORBA_ERROR_LIST_API_H
#define ZORBA_ERROR_LIST_API_H

#include <zorba/config.h>
#include <zorba/error.h>

#define XQUERY_DEC_ERROR(ERR) extern ZORBA_DLL_PUBLIC XQueryError ERR

namespace zorba {
namespace err {

////////// XQuery Errors //////////////////////////////////////////////////////

XQUERY_DEC_ERROR( XPST0001 );
XQUERY_DEC_ERROR( XPDY0002 );
XQUERY_DEC_ERROR( XPST0003 );
XQUERY_DEC_ERROR( XPTY0004 );
XQUERY_DEC_ERROR( XPST0005 );
XQUERY_DEC_ERROR( XPST0008 );
XQUERY_DEC_ERROR( XQST0009 );
XQUERY_DEC_ERROR( XPST0010 );
XQUERY_DEC_ERROR( XQST0012 );
XQUERY_DEC_ERROR( XQST0013 );
XQUERY_DEC_ERROR( XQST0016 );
XQUERY_DEC_ERROR( XPST0017 );
XQUERY_DEC_ERROR( XPTY0018 );
XQUERY_DEC_ERROR( XPTY0019 );
XQUERY_DEC_ERROR( XPTY0020 );
XQUERY_DEC_ERROR( XQST0022 );
XQUERY_DEC_ERROR( XQTY0024 );
XQUERY_DEC_ERROR( XQDY0025 );
XQUERY_DEC_ERROR( XQDY0026 );
XQUERY_DEC_ERROR( XQDY0027 );
XQUERY_DEC_ERROR( XQTY0030 );
XQUERY_DEC_ERROR( XQST0031 );
XQUERY_DEC_ERROR( XQST0032 );
XQUERY_DEC_ERROR( XQST0033 );
XQUERY_DEC_ERROR( XQST0034 );
XQUERY_DEC_ERROR( XQST0035 );
XQUERY_DEC_ERROR( XQST0036 );
XQUERY_DEC_ERROR( XQST0038 );
XQUERY_DEC_ERROR( XQST0039 );
XQUERY_DEC_ERROR( XQST0040 );
XQUERY_DEC_ERROR( XQDY0041 );
XQUERY_DEC_ERROR( XQDY0044 );
XQUERY_DEC_ERROR( XQST0045 );
XQUERY_DEC_ERROR( XQST0046 );
XQUERY_DEC_ERROR( XQST0047 );
XQUERY_DEC_ERROR( XQST0048 );
XQUERY_DEC_ERROR( XQST0049 );
XQUERY_DEC_ERROR( XPDY0050 );
XQUERY_DEC_ERROR( XPST0051 );
XQUERY_DEC_ERROR( XQST0054 );
XQUERY_DEC_ERROR( XQST0055 );
XQUERY_DEC_ERROR( XQST0057 );
XQUERY_DEC_ERROR( XQST0058 );
XQUERY_DEC_ERROR( XQST0059 );
XQUERY_DEC_ERROR( XQST0060 );
XQUERY_DEC_ERROR( XQDY0061 );
XQUERY_DEC_ERROR( XQDY0064 );
XQUERY_DEC_ERROR( XQST0065 );
XQUERY_DEC_ERROR( XQST0066 );
XQUERY_DEC_ERROR( XQST0067 );
XQUERY_DEC_ERROR( XQST0068 );
XQUERY_DEC_ERROR( XQST0069 );
XQUERY_DEC_ERROR( XQST0070 );
XQUERY_DEC_ERROR( XQST0071 );
XQUERY_DEC_ERROR( XQDY0072 );
XQUERY_DEC_ERROR( XQDY0074 );
XQUERY_DEC_ERROR( XQST0075 );
XQUERY_DEC_ERROR( XQST0076 );
XQUERY_DEC_ERROR( XQST0079 );
XQUERY_DEC_ERROR( XPST0080 );
XQUERY_DEC_ERROR( XPST0081 );
XQUERY_DEC_ERROR( XPST0083 );
XQUERY_DEC_ERROR( XQDY0084 );
XQUERY_DEC_ERROR( XQST0085 );
XQUERY_DEC_ERROR( XQTY0086 );
XQUERY_DEC_ERROR( XQST0087 );
XQUERY_DEC_ERROR( XQST0088 );
XQUERY_DEC_ERROR( XQST0089 );
XQUERY_DEC_ERROR( XQST0090 );
XQUERY_DEC_ERROR( XQDY0091 );
XQUERY_DEC_ERROR( XQDY0092 );
XQUERY_DEC_ERROR( XQST0093 );
XQUERY_DEC_ERROR( XQDY0096 );

/**
 * It is a static error if a function's annotations contain more than one
 * annotation named \c %private or \c %public.  It is a static error if a
 * function's annotations contain more than one annotation named \c
 * %deterministic or \c %nondeterministic.
 */
XQUERY_DEC_ERROR( XQST0106 );

////////// XQuery Full-Text Errors ////////////////////////////////////////////

#ifndef XQUERY_NO_FULL_TEXT

/**
 * It is a static error if, during the static analysis phase, the query is
 * found to contain a stop word option that refers to a stop word list that is
 * not found in the statically known stop word lists.
 */
XQUERY_DEC_ERROR( FTST0008 );

/**
 * It may be a static error if, during the static analysis phase, the query is
 * found to contain a language identifier in a language option that the
 * implementation does not support. The implementation may choose not to raise
 * this error and instead provide some other implementation-defined behavior.
 */
XQUERY_DEC_ERROR( FTST0009 );

/**
 * It is a dynamic error if a weight value is not within the required range of
 * values; it is also a dynamic error if an implementation that does not
 * support negative weights encounters a negative weight value.
 */
XQUERY_DEC_ERROR( FTDY0016 );

/**
 * It is a dynamic error if an implementation encounters a mild not selection,
 * one of whose operands evaluates to an AllMatches that contains a
 * StringExclude.
 */
XQUERY_DEC_ERROR( FTDY0017 );

/**
 * It is a static error if, during the static analysis phase, the query is
 * found to contain a thesaurus option that refers to a thesaurus that is not
 * found in the statically known thesauri.
 */
XQUERY_DEC_ERROR( FTST0018 );

/**
 * It is a static error if, within a single FTMatchOptions, there is more than
 * one match option of any given match option group.
 */
XQUERY_DEC_ERROR( FTST0019 );

/**
 * It is a dynamic error if, when "wildcards" is in effect, a query string
 * violates wildcard syntax.
 */
XQUERY_DEC_ERROR( FTDY0020 );

#endif /* XQUERY_NO_FULL_TEXT */

////////// XQuery Functions & Operators Errors ////////////////////////////////

/**
 * Unidentified error.
 */
XQUERY_DEC_ERROR( FOER0000 );

/**
 * Division by zero.
 */
XQUERY_DEC_ERROR( FOAR0001 );

/**
 * Numeric operation overflow/underflow.
 */
XQUERY_DEC_ERROR( FOAR0002 );

/**
 * Input value too large for decimal.
 */
XQUERY_DEC_ERROR( FOCA0001 );

/**
 * Invalid lexical value.
 */
XQUERY_DEC_ERROR( FOCA0002 );

/**
 * Input value too large for integer.
 */
XQUERY_DEC_ERROR( FOCA0003 );

/**
 * NaN supplied as float/double value.
 */
XQUERY_DEC_ERROR( FOCA0005 );

/**
 * String to be cast to decimal has too many digits of precision.
 */
XQUERY_DEC_ERROR( FOCA0006 );

/**
 * Code point not valid.
 */
XQUERY_DEC_ERROR( FOCH0001 );

/**
 * Unsupported collation.
 */
XQUERY_DEC_ERROR( FOCH0002 );

/**
 * Unsupported normalization form.
 */
XQUERY_DEC_ERROR( FOCH0003 );

/**
 * Collation does not support collation units.
 */
XQUERY_DEC_ERROR( FOCH0004 );

/**
 * No context document.
 */
XQUERY_DEC_ERROR( FODC0001 );

/**
 * Error retrieving resource.
 */
XQUERY_DEC_ERROR( FODC0002 );

/**
 * Function stability not defined.
 */
XQUERY_DEC_ERROR( FODC0003 );

/**
 * Invalid argument to <code>fn:collection</code>.
 */
XQUERY_DEC_ERROR( FODC0004 );

/**
 * Invalid argument to <code>fn:doc</code> or <code>fn:doc-available</code>.
 */
XQUERY_DEC_ERROR( FODC0005 );

/**
 * Invalid content passed to <code>fn:parse()</code>.
 */
XQUERY_DEC_ERROR( FODC0006 );

/**
 * Base URI passed to <code>fn:parse()</code> is not a valid absolute URI.
 */
XQUERY_DEC_ERROR( FODC0007 );

/**
 * Invalid decimal format name supplied to <code>fn:format-number()</code>.
 */
XQUERY_DEC_ERROR( FODF1280 );

/**
 * Invalid <code>fn:format-number()</code> picture string.
 */
XQUERY_DEC_ERROR( FODF1310 );

/**
 * Overflow/underflow in date/time operation.
 */
XQUERY_DEC_ERROR( FODT0001 );

/**
 * Overflow/underflow in duration operation.
 */
XQUERY_DEC_ERROR( FODT0002 );

/**
 * Invalid timezone value.
 */
XQUERY_DEC_ERROR( FODT0003 );

/**
 * No namespace found for prefix.
 */
XQUERY_DEC_ERROR( FONS0004 );

/**
 * Base-URI not defined in the static context.
 */
XQUERY_DEC_ERROR( FONS0005 );

/**
 * Invalid value for cast/constructor.
 */
XQUERY_DEC_ERROR( FORG0001 );

/**
 * Invalid argument to <code>fn:resolve-uri()</code>.
 */
XQUERY_DEC_ERROR( FORG0002 );

/**
 * <code>fn:zero-or-one</code> called with a sequence containing more than one
 * item.
 */
XQUERY_DEC_ERROR( FORG0003 );

/**
 * <code>fn:one-or-more</code> called with a sequence containing no items.
 */
XQUERY_DEC_ERROR( FORG0004 );

/**
 * <code>fn:exactly-one</code> called with a sequence containing zero or more
 * than one item.
 */
XQUERY_DEC_ERROR( FORG0005 );

/**
 * Invalid argument type.
 */
XQUERY_DEC_ERROR( FORG0006 );

/**
 * The two arguments to fn:dateTime have inconsistent timezones.
 */
XQUERY_DEC_ERROR( FORG0008 );

/**
 * Error in resolving a relative URI against a base URI in
 * <code>fn:resolve-uri</code>.
 */
XQUERY_DEC_ERROR( FORG0009 );

/**
 * Invalid regular expression flags.
 */
XQUERY_DEC_ERROR( FORX0001 );

/**
 * Invalid regular expression.
 */
XQUERY_DEC_ERROR( FORX0002 );

/**
 * Regular expression matches zero-length string.
 */
XQUERY_DEC_ERROR( FORX0003 );

/**
 * Invalid replacement string.
 */
XQUERY_DEC_ERROR( FORX0004 );

/**
 * Argument node does not have a typed value.
 */
XQUERY_DEC_ERROR( FOTY0012 );

/**
 * An argument to <code>fn:data()</code> contains a node that does not have a
 * typed value.
 */
XQUERY_DEC_ERROR( FOTY0013 );

/**
 * The argument to <code>fn:string()</code> is a function item.
 */
XQUERY_DEC_ERROR( FOTY0014 );

/**
 * An argument to <code>fn:deep-equal()</code> contains a function item.
 */
XQUERY_DEC_ERROR( FOTY0015 );

////////// XQuery Update Facility /////////////////////////////////////////////

XQUERY_DEC_ERROR( XUST0001 );
XQUERY_DEC_ERROR( XUST0002 );
XQUERY_DEC_ERROR( XUST0003 );
XQUERY_DEC_ERROR( XUTY0004 );
XQUERY_DEC_ERROR( XUTY0005 );
XQUERY_DEC_ERROR( XUTY0006 );
XQUERY_DEC_ERROR( XUTY0007 );
XQUERY_DEC_ERROR( XUTY0008 );
XQUERY_DEC_ERROR( XUDY0009 );
XQUERY_DEC_ERROR( XUTY0010 );
XQUERY_DEC_ERROR( XUTY0011 );
XQUERY_DEC_ERROR( XUTY0012 );
XQUERY_DEC_ERROR( XUTY0013 );
XQUERY_DEC_ERROR( XUDY0014 );
XQUERY_DEC_ERROR( XUDY0015 );
XQUERY_DEC_ERROR( XUDY0016 );
XQUERY_DEC_ERROR( XUDY0017 );
XQUERY_DEC_ERROR( XUDY0018 );
XQUERY_DEC_ERROR( XUDY0019 );
XQUERY_DEC_ERROR( XUDY0020 );
XQUERY_DEC_ERROR( XUDY0021 );
XQUERY_DEC_ERROR( XUTY0022 );
XQUERY_DEC_ERROR( XUDY0023 );
XQUERY_DEC_ERROR( XUDY0024 );
XQUERY_DEC_ERROR( XUDY0025 );
XQUERY_DEC_ERROR( XUST0026 );
XQUERY_DEC_ERROR( XUDY0027 );
XQUERY_DEC_ERROR( XUST0028 );
XQUERY_DEC_ERROR( XUDY0029 );
XQUERY_DEC_ERROR( XUDY0030 );
XQUERY_DEC_ERROR( XUDY0031 );
XQUERY_DEC_ERROR( FOUP0001 );
XQUERY_DEC_ERROR( FOUP0002 );

////////// Serialization //////////////////////////////////////////////////////

/**
 * It is an error if an item in S6 in sequence normalization is an attribute
 * node or a namespace node.
 */
XQUERY_DEC_ERROR( SENR0001 );

/**
 * It is an error if the serializer is unable to satisfy the rules for either a
 * well-formed XML document entity or a well-formed XML external general parsed
 * entity, or both, except for content modified by the character expansion
 * phase of serialization.
 */
XQUERY_DEC_ERROR( SERE0003 );

/**
 * It is an error to specify the doctype-system parameter, or to specify the
 * standalone parameter with a value other than omit, if the instance of the
 * data model contains text nodes or multiple element nodes as children of the
 * root node.
 */
XQUERY_DEC_ERROR( SEPM0004 );

/**
 * It is an error if the serialized result would contain an NCName Names that
 * contains a character that is not permitted by the version of Namespaces in
 * XML specified by the version parameter.
 */
XQUERY_DEC_ERROR( SERE0005 );

/**
 * It is an error if the serialized result would contain a character that is
 * not permitted by the version of XML specified by the version parameter.
 */
XQUERY_DEC_ERROR( SERE0006 );

/**
 * It is an error if an output encoding other than UTF-8 or UTF-16 is requested
 * and the serializer does not support that encoding.
 */
XQUERY_DEC_ERROR( SESU0007 );

/**
 * It is an error if a character that cannot be represented in the encoding
 * that the serializer is using for output appears in a context where character
 * references are not allowed (for example if the character occurs in the name
 * of an element).
 */
XQUERY_DEC_ERROR( SERE0008 );

/**
 * It is an error if the omit-xml-declaration parameter has the value yes, and
 * the standalone attribute has a value other than omit; or the version
 * parameter has a value other than 1.0 and the doctype-system parameter is
 * specified.
 */
XQUERY_DEC_ERROR( SEPM0009 );

/**
 * It is an error if the output method is xml, the value of the
 * undeclare-prefixes parameter is yes, and the value of the version parameter
 * is 1.0.
 */
XQUERY_DEC_ERROR( SEPM0010 );

/**
 * It is an error if the value of the normalization-form parameter specifies a
 * normalization form that is not supported by the serializer.
 */
XQUERY_DEC_ERROR( SESU0011 );

/**
 * It is an error if the value of the normalization-form parameter is
 * fully-normalized and any relevant construct of the result begins with a
 * combining character.
 */
XQUERY_DEC_ERROR( SERE0012 );

/**
 * It is an error if the serializer does not support the version of XML or HTML
 * specified by the version parameter.
 */
XQUERY_DEC_ERROR( SESU0013 );

/**
 * It is an error to use the HTML output method when characters which are legal
 * in XML but not in HTML, specifically the control characters #x7F-#x9F,
 * appear in the instance of the data model.
 */
XQUERY_DEC_ERROR( SERE0014 );

/**
 * It is an error to use the HTML output method when \c > appears within a
 * processing instruction in the data model instance being serialized.
 */
XQUERY_DEC_ERROR( SERE0015 );

/**
 * It is a an error if a parameter value is invalid for the defined domain.
 */
XQUERY_DEC_ERROR( SEPM0016 );

/**
 * It is a non-recoverable dynamic error if the picture string does not satisfy
 * the format-number function rules.
 */
XQUERY_DEC_ERROR( XTDE1310 );

/**
 * It is a non-recoverable dynamic error if the syntax of the picture is
 * incorrect.
 */
XQUERY_DEC_ERROR( XTDE1340 );

/**
 * It is a non-recoverable dynamic error if a component specifier within the
 * picture refers to components that are not available in the given type of
 * <code>$value</code>.
 */
XQUERY_DEC_ERROR( XTDE1350 );

////////// Zorba Errors ///////////////////////////////////////////////////////

#define ZORBA_DEC_ERROR(ERR)  extern ZORBA_DLL_PUBLIC ZorbaError ERR

ZORBA_DEC_ERROR( XQP0000_NO_ERROR );
ZORBA_DEC_ERROR( XQP0001_DYNAMIC_RUNTIME_ERROR );
ZORBA_DEC_ERROR( XQP0002_DYNAMIC_ITERATOR_OVERRUN );
ZORBA_DEC_ERROR( XQP0003_DYNAMIC_ILLEGAL_NODE_CHILD );
ZORBA_DEC_ERROR( XQP0004_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND );
ZORBA_DEC_ERROR( XQP0005_SYSTEM_NOT_SUPPORTED );
ZORBA_DEC_ERROR( XQP0006_SYSTEM_ASSERT_FAILED );
ZORBA_DEC_ERROR( XQP0007_SYSTEM_HASH_ERROR_KEYLEN_EXCEEDS_MAXKEYLEN );
ZORBA_DEC_ERROR( XQP0008_SYSTEM_VECTOR_OUT_OF_RANGE );
ZORBA_DEC_ERROR( XQP0009_SYSTEM_READ_LOCK_FAILED );
ZORBA_DEC_ERROR( XQP0010_SYSTEM_WRITE_LOCK_FAILED );
ZORBA_DEC_ERROR( XQP0011_SYSTEM_POP_FROM_EMPTY_LIST );
ZORBA_DEC_ERROR( XQP0012_SYSTEM_FILE_ERROR_IN_FUNCTION );
ZORBA_DEC_ERROR( XQP0013_SYSTEM_FXCHARHEAP_IOEXCEPTION );
ZORBA_DEC_ERROR( XQP0014_SYSTEM_MMFILE_IOEXCEPTION );
ZORBA_DEC_ERROR( XQP0015_SYSTEM_NOT_YET_IMPLEMENTED );
ZORBA_DEC_ERROR( XQP0016_RESERVED_MODULE_TARGET_NAMESPACE );
ZORBA_DEC_ERROR( XQP0017_FILE_ACCESS_DISABLED );
ZORBA_DEC_ERROR( XQP0019_INTERNAL_ERROR );
ZORBA_DEC_ERROR( XQP0020_INVALID_URI );
ZORBA_DEC_ERROR( XQP0021_USER_ERROR );
ZORBA_DEC_ERROR( XQP0022_GET_RESULTS_AS_DOM_FAILED );
ZORBA_DEC_ERROR( XQP0023_GET_RESULTS_AS_SAX_FAILED );
ZORBA_DEC_ERROR( XQP0024_XML_DOES_NOT_MATCH_SCHEMA );
ZORBA_DEC_ERROR( XQP0025_COULD_NOT_CREATE_ITEM );
ZORBA_DEC_ERROR( XQP0026_COULD_NOT_CREATE_THREAD );
ZORBA_DEC_ERROR( XQP0026_CANNOT_INIT_STORE );
ZORBA_DEC_ERROR( XQP0027_MS_DOM_ERROR );
ZORBA_DEC_ERROR( XQP0028_FUNCTION_IMPL_NOT_FOUND );
ZORBA_DEC_ERROR( XQP0029_MODULE_IMPORT_NOT_ALLOWED );
ZORBA_DEC_ERROR( XQP0030_DEADLOCK );
ZORBA_DEC_ERROR( XQP0031_MALFORMED_XQUERYX_INPUT );
ZORBA_DEC_ERROR( XQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY );
ZORBA_DEC_ERROR( XQP0034_ILLEGAL_UTF8_BYTE );
ZORBA_DEC_ERROR( XQP0035_ILLEGAL_UTF16_BYTE );
ZORBA_DEC_ERROR( XQP0036_BREAKITERATOR_CREATION_FAILED );

#ifndef ZORBA_NO_FULL_TEXT
ZORBA_DEC_ERROR( XQP8401_THESAURUS_VERSION_MISMATCH );
ZORBA_DEC_ERROR( XQP8402_THESAURUS_DATA_ERROR );
#endif /* ZORBA_NO_FULL_TEXT */

ZORBA_DEC_ERROR( XQD0000_PREFIX_NOT_DECLARED );
ZORBA_DEC_ERROR( XQD0001_DOCUMENT_NOT_VALID );

////////// Zorba API Errors ///////////////////////////////////////////////////

ZORBA_DEC_ERROR( API0001_XQUERY_STRING_IS_EMPTY );
ZORBA_DEC_ERROR( API0002_XQUERY_COMPILATION_FAILED );
ZORBA_DEC_ERROR( API0003_XQUERY_NOT_COMPILED );
ZORBA_DEC_ERROR( API0004_XQUERY_ALREADY_COMPILED );
ZORBA_DEC_ERROR( API0005_XQUERY_ALREADY_EXECUTING );
ZORBA_DEC_ERROR( API0006_XQUERY_ALREADY_CLOSED );
ZORBA_DEC_ERROR( API0007_CANNOT_SERIALIZE_PUL );
ZORBA_DEC_ERROR( API0008_NOT_AN_UPDATE_XQUERY );
ZORBA_DEC_ERROR( API0009_XQUERY_NOT_COMPILED_IN_DEBUG_MODE );
ZORBA_DEC_ERROR( API0010_THREAD_NOT_INITIALIZED );
ZORBA_DEC_ERROR( API0010_XQUERY_HAS_ITERATOR_ALREADY );
ZORBA_DEC_ERROR( API0011_INVALID_VARIABLE_QNAME );
ZORBA_DEC_ERROR( API0012_INVALID_INDEX );
ZORBA_DEC_ERROR( API0013_INAPPROPRIATE_VARIABLE_VALUE );
ZORBA_DEC_ERROR( API0014_INVALID_ARGUMENT );
ZORBA_DEC_ERROR( API0015_CANNOT_OPEN_FILE );
ZORBA_DEC_ERROR( API0016_CANNOT_CREATE_COLLECTION );
ZORBA_DEC_ERROR( API0017_CANNOT_LOAD_DOCUMENT );
ZORBA_DEC_ERROR( API0018_CANNOT_ACCESS_FILE );
ZORBA_DEC_ERROR( API0019_FUNCTION_ALREADY_REGISTERED );
ZORBA_DEC_ERROR( API0020_DOCUMENT_ALREADY_EXISTS );
ZORBA_DEC_ERROR( API0021_ITEM_TO_LOAD_IS_NOT_NODE );
ZORBA_DEC_ERROR( API0022_NOT_PLAIN_FILE );
ZORBA_DEC_ERROR( API0025_END_OF_SEQUENCE );
ZORBA_DEC_ERROR( API0027_CANNOT_UPDATE_DCTX_WITH_ITERATORS );
ZORBA_DEC_ERROR( API0028_INVALID_NODE_URI );
ZORBA_DEC_ERROR( API0030_NO_NODE_AT_GIVEN_POSITION );
ZORBA_DEC_ERROR( API0033_FILE_OR_FOLDER_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED );
ZORBA_DEC_ERROR( API0035_COLLECTION_CANNOT_BE_SERIALIZED );
ZORBA_DEC_ERROR( API0040_ITERATOR_IS_NOT_OPEN );
ZORBA_DEC_ERROR( API0041_ITERATOR_IS_OPEN_ALREADY );
ZORBA_DEC_ERROR( API0042_ITERATOR_QUERY_IS_CLOSED );
ZORBA_DEC_ERROR( API0050_REST_ERROR_HEADER );
ZORBA_DEC_ERROR( API0051_REST_ERROR_PAYLOAD );
ZORBA_DEC_ERROR( API0060_CONV_JSON_PARSE );
ZORBA_DEC_ERROR( API0061_CONV_JSON_SERIALIZE );
ZORBA_DEC_ERROR( API0062_CONV_JSON_PARAM );
ZORBA_DEC_ERROR( API0063_CONV_JSON_ML_PARSE );
ZORBA_DEC_ERROR( API0064_CONV_JSON_ML_SERIALIZE );
ZORBA_DEC_ERROR( API0065_CONV_JSON_ML_PARAM );
ZORBA_DEC_ERROR( API0066_JSON_SEQUENCE_CANNOT_BE_SERIALIZED );
ZORBA_DEC_ERROR( API0070_INVALID_SERIALIZATION_METHOD_FOR_SAX );

////////// Zorba Class Serialization Errors ///////////////////////////////////

ZORBA_DEC_ERROR( SRL0001_INEXISTENT_INPUT_FIELD );
ZORBA_DEC_ERROR( SRL0002_INCOMPATIBLE_INPUT_FIELD );
ZORBA_DEC_ERROR( SRL0003_UNRECOGNIZED_CLASS_FIELD );
ZORBA_DEC_ERROR( SRL0004_UNRESOLVED_FIELD_REFERENCE );
ZORBA_DEC_ERROR( SRL0005_CLASS_VERSION_IS_TOO_NEW );
ZORBA_DEC_ERROR( SRL0006_CLASS_VERSION_IS_TOO_OLD );
ZORBA_DEC_ERROR( SRL0007_INPUT_ARCHIVE_USED_FOR_OUT_SERIALIZATION );
ZORBA_DEC_ERROR( SRL0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION );
ZORBA_DEC_ERROR( SRL0009_CLASS_NOT_SERIALIZABLE );
ZORBA_DEC_ERROR( SRL0010_ITEM_TYPE_NOT_SERIALIZABLE );
ZORBA_DEC_ERROR( SRL0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE );
ZORBA_DEC_ERROR( SRL0012_INCOMPATIBLE_ARCHIVE_VERSION );
ZORBA_DEC_ERROR( SRL0013_UNABLE_TO_LOAD_QUERY );
ZORBA_DEC_ERROR( SRL0014_INFINITE_CIRCULAR_DEPENDENCIES );
ZORBA_DEC_ERROR( SRL0015_INCOMPATIBLE_BETWEEN_32_AND_64_BITS_OR_LE_AND_BE );

////////// Store Errors ///////////////////////////////////////////////////////

ZORBA_DEC_ERROR( STR0001_INDEX_ALREADY_EXISTS );
ZORBA_DEC_ERROR( STR0002_INDEX_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( STR0003_INDEX_PARTIAL_KEY_INSERT );
ZORBA_DEC_ERROR( STR0004_INDEX_PARTIAL_KEY_REMOVE );
ZORBA_DEC_ERROR( STR0005_INDEX_PARTIAL_KEY_PROBE );
ZORBA_DEC_ERROR( STR0006_INDEX_INVALID_BOX_PROBE );
ZORBA_DEC_ERROR( STR0007_INDEX_UNSUPPORTED_PROBE_CONDITION );
ZORBA_DEC_ERROR( STR0008_COLLECTION_ALREADY_EXISTS );
ZORBA_DEC_ERROR( STR0009_COLLECTION_NOT_FOUND );
ZORBA_DEC_ERROR( STR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION );
ZORBA_DEC_ERROR( STR0011_COLLECTION_NON_ROOT_NODE );
ZORBA_DEC_ERROR( STR0012_COLLECTION_ITEM_MUST_BE_A_NODE );
ZORBA_DEC_ERROR( STR0015_IC_ALREADY_EXISTS );
ZORBA_DEC_ERROR( STR0016_IC_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( STR0020_LOADER_IO_ERROR );
ZORBA_DEC_ERROR( STR0021_LOADER_PARSING_ERROR );
ZORBA_DEC_ERROR( STR0030_NODEID_ERROR );
ZORBA_DEC_ERROR( STR0040_TYPE_ERROR );
ZORBA_DEC_ERROR( STR0041_NAN_COMPARISON );
ZORBA_DEC_ERROR( STR0045_DUPLICATE_NODE_ERROR );
ZORBA_DEC_ERROR( STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE );

////////// Data Definition Facility Errors ////////////////////////////////////

ZORBA_DEC_ERROR( XDST0001_COLLECTION_ALREADY_DECLARED );
ZORBA_DEC_ERROR( XDST0002_COLLECTION_ALREADY_IMPORTED );
ZORBA_DEC_ERROR( XDST0003_COLLECTION_DECL_IN_MAIN_MODULE );
ZORBA_DEC_ERROR( XDST0004_COLLECTION_MULTIPLE_PROPERTY_VALUES );
ZORBA_DEC_ERROR( XDST0005_COLLECTION_PROPERTIES_CONFLICT );
ZORBA_DEC_ERROR( XDST0006_COLLECTION_INVALID_PROPERTY_VALUE );
ZORBA_DEC_ERROR( XDST0007_COLLECTION_DECL_IN_FOREIGN_MODULE );
ZORBA_DEC_ERROR( XDST0021_INDEX_ALREADY_DECLARED );
ZORBA_DEC_ERROR( XDST0022_INDEX_ALREADY_IMPORTED );
ZORBA_DEC_ERROR( XDST0023_INDEX_DECL_IN_MAIN_MODULE );
ZORBA_DEC_ERROR( XDST0024_INDEX_MULTIPLE_PROPERTY_VALUES );
ZORBA_DEC_ERROR( XDST0025_INDEX_PROPERTIES_CONFLICT );
ZORBA_DEC_ERROR( XDST0026_INDEX_INVALID_PROPERTY_VALUE );
ZORBA_DEC_ERROR( XDST0027_INDEX_BAD_KEY_TYPE );
ZORBA_DEC_ERROR( XDST0028_INDEX_NOT_DETERMINISTIC );
ZORBA_DEC_ERROR( XDST0029_INDEX_INVALID_DATA_SOURCE );
ZORBA_DEC_ERROR( XDST0030_INDEX_NON_CONST_DATA_SOURCE );
ZORBA_DEC_ERROR( XDST0031_INDEX_HAS_FREE_VARS );
ZORBA_DEC_ERROR( XDST0032_INDEX_REFERENCES_CTX_ITEM );
ZORBA_DEC_ERROR( XDST0033_INDEX_NON_SIMPLE_EXPR );
ZORBA_DEC_ERROR( XDST0034_INDEX_CANNOT_DO_AUTOMATIC_MAINTENANCE );
ZORBA_DEC_ERROR( XDST0035_INDEX_GENERAL_MULTIKEY );
ZORBA_DEC_ERROR( XDST0036_INDEX_DECL_IN_FOREIGN_MODULE );
ZORBA_DEC_ERROR( XDST0041_IC_IS_ALREADY_DECLARED );
ZORBA_DEC_ERROR( XDST0042_MULTI_VALUED_IC_KEY );
ZORBA_DEC_ERROR( XDST0043_NON_ATOMIC_IC_KEY );
ZORBA_DEC_ERROR( XDST0044_IC_DECL_IN_MAIN_MODULE );
ZORBA_DEC_ERROR( XDST0045_IC_HAS_FREE_VARS );
ZORBA_DEC_ERROR( XDST0046_IC_HAS_INVALID_DATA_SOURCE );
ZORBA_DEC_ERROR( XDST0047_IC_NOT_DETERMINISTIC );
ZORBA_DEC_ERROR( XDST0048_IC_DECL_IN_FOREIGN_MODULE );

ZORBA_DEC_ERROR( XDTY0001_COLLECTION_INVALID_NODE_TYPE );
ZORBA_DEC_ERROR( XDTY0010_INDEX_DOMAIN_TYPE_ERROR );
ZORBA_DEC_ERROR( XDTY0011_INDEX_KEY_TYPE_ERROR );
ZORBA_DEC_ERROR( XDTY0012_INDEX_KEY_TYPE_ERROR );

ZORBA_DEC_ERROR( XDDY0001_COLLECTION_NOT_DECLARED );
ZORBA_DEC_ERROR( XDDY0002_COLLECTION_EXISTS_ALREADY );
ZORBA_DEC_ERROR( XDDY0003_COLLECTION_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( XDDY0004_COLLECTION_CONST_UPDATE );
ZORBA_DEC_ERROR( XDDY0005_COLLECTION_APPEND_BAD_INSERT );
ZORBA_DEC_ERROR( XDDY0006_COLLECTION_QUEUE_BAD_INSERT );
ZORBA_DEC_ERROR( XDDY0007_COLLECTION_APPEND_BAD_DELETE );
ZORBA_DEC_ERROR( XDDY0008_COLLECTION_QUEUE_BAD_DELETE );
ZORBA_DEC_ERROR( XDDY0009_COLLECTION_QUEUE_BAD_DELETE );
ZORBA_DEC_ERROR( XDDY0010_COLLECTION_CONST_NODE_UPDATE );
ZORBA_DEC_ERROR( XDDY0011_COLLECTION_NODE_NOT_FOUND );
ZORBA_DEC_ERROR( XDDY0012_COLLECTION_UNORDERED_BAD_INSERT );
ZORBA_DEC_ERROR( XDDY0013_COLLECTION_BAD_DESTROY_INDEXES );
ZORBA_DEC_ERROR( XDDY0014_COLLECTION_BAD_DESTROY_ICS );
ZORBA_DEC_ERROR( XDDY0015_COLLECTION_BAD_DESTROY_NODES );
ZORBA_DEC_ERROR( XDDY0016_COLLECTION_MULTIPLE_CREATES );
ZORBA_DEC_ERROR( XDDY0020_INDEX_DOMAIN_NODE_NOT_IN_COLLECTION );
ZORBA_DEC_ERROR( XDDY0021_INDEX_IS_NOT_DECLARED );
ZORBA_DEC_ERROR( XDDY0022_INDEX_EXISTS_ALREADY );
ZORBA_DEC_ERROR( XDDY0023_INDEX_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( XDDY0024_INDEX_UNIQUE_VIOLATION );
ZORBA_DEC_ERROR( XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS );
ZORBA_DEC_ERROR( XDDY0026_INDEX_RANGE_PROBE_NOT_ALLOWED );
ZORBA_DEC_ERROR( XDDY0027_INDEX_MULTIPLE_CREATES );
ZORBA_DEC_ERROR( XDDY0028_INDEX_DOMAIN_HAS_DUPLICATE_NODES );
ZORBA_DEC_ERROR( XDDY0029_INDEX_GENERAL_PROBE_NOT_ALLOWED );
ZORBA_DEC_ERROR( XDDY0031_IC_IS_NOT_DECLARED );
ZORBA_DEC_ERROR( XDDY0032_IC_IS_NOT_ACTIVATED );
ZORBA_DEC_ERROR( XDDY0033_IC_NOT_MET );

///////////////////////////////////////////////////////////////////////////////

#undef XQUERY_DEC_ERROR
#undef ZORBA_DEC_ERROR

} // namespace err
} // namespace zorba
#endif /* ZORBA_ERROR_LIST_API_H */
/* vim:set et sw=2 ts=2: */
