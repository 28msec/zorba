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
#include <string>

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

using namespace std;

namespace zorba { namespace error {


/*******************************************************************************

********************************************************************************/


struct err_msg_wrapper
{
  private:
    const char *canonical_err_names[MAX_ZORBA_ERROR_CODE + 1];

    const char *err_msg[MAX_ZORBA_ERROR_CODE + 1];

  public:
  err_msg_wrapper () 
  {
#ifdef WIN32  
#define DEF_ERR_CODE( code, name, msg )          \
  canonical_err_names [ code ] = _strdup(#name); \
  err_msg [code] = _strdup(msg);
#else
#define DEF_ERR_CODE( code, name, msg )          \
  canonical_err_names [ code ] = strdup(#name);  \
  err_msg [code] = strdup(msg);
#endif

    for (int i = 0; i < MAX_ZORBA_ERROR_CODE; i++) 
    {
      canonical_err_names [i] = NULL;
      err_msg [i] = NULL;
    }


DEF_ERR_CODE (FOAR0001, FOAR0001, "Division by zero.")
DEF_ERR_CODE (FOAR0002, FOAR0002, "Numeric operation overflow/underflow.")
DEF_ERR_CODE (FOCA0001, FOCA0001, "Input value too large for decimal.")
DEF_ERR_CODE (FOCA0002, FOCA0002, "Invalid lexical value.")
DEF_ERR_CODE (FOCA0003, FOCA0003, "Input value too large for integer.")
DEF_ERR_CODE (FOCA0005, FOCA0005, "NaN supplied as float/double value.")
DEF_ERR_CODE (FOCA0006, FOCA0006, "String to be cast to decimal has too many digits of precision.")
DEF_ERR_CODE (FOCH0001, FOCH0001, "Code point not valid: {/s}.")
DEF_ERR_CODE (FOCH0002, FOCH0002, "Unsupported collation.")
DEF_ERR_CODE (FOCH0003, FOCH0003, "Unsupported normalization form.")
DEF_ERR_CODE (FOCH0004, FOCH0004, "Collation does not support collation units.")
DEF_ERR_CODE (FODC0001, FODC0001, "No context document.")
DEF_ERR_CODE (FODC0002, FODC0002, "Error retrieving the resource with uri {/s}.\nReason {/s}")
DEF_ERR_CODE (FODC0003, FODC0003, "Function stability not defined.")
DEF_ERR_CODE (FODC0004, FODC0004, "Invalid argument to fn:collection {/s}.")
DEF_ERR_CODE (FODC0005, FODC0005, "Invalid argument to fn:doc or fn:doc-available {/s}")
DEF_ERR_CODE (FODC0006, FODC0006, "Argument to fn:parse is not well-formed.")
DEF_ERR_CODE (FODC0007, FODC0007, "Base URI passed as second argument to fn:parse is not a valid absolute URI")
DEF_ERR_CODE (FODT0001, FODT0001, "Overflow/underflow in date/time operation.")
DEF_ERR_CODE (FODT0002, FODT0002, "Overflow/underflow in duration operation.")
DEF_ERR_CODE (FODT0003, FODT0003, "Invalid timezone value.")
DEF_ERR_CODE (FOER0000, FOER0000, "Unidentified error.")
DEF_ERR_CODE (FONS0004, FONS0004, "No namespace found for prefix.")
DEF_ERR_CODE (FONS0005, FONS0005, "Base-uri not defined in the static context.")
DEF_ERR_CODE (FORG0001, FORG0001, "Invalid value for cast/constructor. Reason {/s}")
DEF_ERR_CODE (FORG0002, FORG0002, "Invalid argument to fn:resolve-uri().")
DEF_ERR_CODE (FORG0003, FORG0003, "fn:zero-or-one called with a sequence containing more than one item.")
DEF_ERR_CODE (FORG0004, FORG0004, "fn:one-or-more called with a sequence containing no items.")
DEF_ERR_CODE (FORG0005, FORG0005, "fn:exactly-one called with a sequence containing zero or more than one item.")
DEF_ERR_CODE (FORG0006, FORG0006, "Invalid argument type.")
DEF_ERR_CODE (FORG0008, FORG0008, "Both arguments to fn:dateTime have a specified timezone.")
DEF_ERR_CODE (FORG0009, FORG0009, "Error in resolving a relative URI against a base URI in fn:resolve-uri.")
DEF_ERR_CODE (FORX0001, FORX0001, "Invalid regular expression flags {/s}")
DEF_ERR_CODE (FORX0002, FORX0002, "Invalid regular expression {/s} ")
DEF_ERR_CODE (FORX0003, FORX0003, "Regular expression matches zero-length string.")
DEF_ERR_CODE (FORX0004, FORX0004, "Invalid replacement string.")
DEF_ERR_CODE (FOTY0012, FOTY0012, "Argument node does not have a typed value.")
DEF_ERR_CODE (FOTY0013, FOTY0013, "Argument to fn:data() contains a node that does not have a typed value.")
DEF_ERR_CODE (FOTY0014, FOTY0014, "The argument to fn:string() cannot be a function item")
DEF_ERR_CODE (FOTY0015, FOTY0015, "An argument to fn:deep-equal() contains a function item.")

DEF_ERR_CODE(FOUP0001, FOUP0001, "It is a dynamic error if the first operand of fn:put is not a node of a supported kind.")

DEF_ERR_CODE(FOUP0002, FOUP0002, "It is a dynamic error if the second operand of fn:put is not a valid lexical representation of the xs:anyURI type.")

#ifndef ZORBA_NO_FULL_TEXT
DEF_ERR_CODE(FTDY0016, FTDY0016, "Invalid weight value.")
DEF_ERR_CODE(FTDY0017, FTDY0017, "Invalid expression for not-in.")
DEF_ERR_CODE(FTDY0020, FTDY0020, "Wildcard syntax error in query string.")
DEF_ERR_CODE(FTST0008, FTST0008, "Unknown stop-word list: {/s}")
DEF_ERR_CODE(FTST0009, FTST0009, "Unsupported language: {/s}")
DEF_ERR_CODE(FTST0018, FTST0018, "Unknown thesaurus: {/s}")
DEF_ERR_CODE(FTST0019, FTST0019, "Multiply-specified match option: {/s}")
#endif /* ZORBA_NO_FULL_TEXT */

//
// Serialization Errors
//

DEF_ERR_CODE(SENR0001, SENR0001, "Item is attribute or namespace node")

DEF_ERR_CODE(SERE0003, SERE0003, "SERE003")

DEF_ERR_CODE(SEPM0004, SEPM0004, "SEPM0004")

DEF_ERR_CODE(SERE0005, SERE0005, "SERE0005")

DEF_ERR_CODE(SERE0006, SERE0006, "SERE0006")

DEF_ERR_CODE(SESU0007, SESU0007, "SESU0007")

DEF_ERR_CODE(SERE0008, SERE0008, "SERE0008")

DEF_ERR_CODE(SEPM0009, SEPM0009, "SEPM0009")

DEF_ERR_CODE(SEPM0010, SEPM0010, "SEPM0010")

DEF_ERR_CODE(SESU0011, SESU0011, "SESU0011")

DEF_ERR_CODE(SERE0012, SERE0012, "SERE0012")

DEF_ERR_CODE(SESU0013, SESU0013, "SESU0013")

DEF_ERR_CODE(SERE0014, SERE0014, "SERE0014")

DEF_ERR_CODE(SERE0015, SERE0015, "SERE0015")

DEF_ERR_CODE(SEPM0016, SEPM0016, "Invalid parameter value")

DEF_ERR_CODE(XTDE1310, XTDE1310, "It is a non-recoverable dynamic error if the picture string does not satisfy the format-number function rules.")

DEF_ERR_CODE(XTDE1340, XTDE1340, "It is a non-recoverable dynamic error if the syntax of the picture is incorrect.")

DEF_ERR_CODE(XTDE1350, XTDE1350, "It is a non-recoverable dynamic error if a component specifier within the picture refers to components that are not available in the given type of $value.")

//
// ZORBA API Errors
//

DEF_ERR_CODE(API0001_XQUERY_STRING_IS_EMPTY, API0001, "Empty query")
DEF_ERR_CODE(API0002_COMPILE_FAILED, API0002, "Query compilation failed")
DEF_ERR_CODE(API0003_XQUERY_NOT_COMPILED, API0003, "Query not compiled")
DEF_ERR_CODE(API0004_XQUERY_ALREADY_COMPILED, API0004, "Query already compiled")

DEF_ERR_CODE(API0020_DOCUMENT_ALREADY_EXISTS, API0020, "Another document with uri {/s} exists in the store already.")

DEF_ERR_CODE(API0021_ITEM_TO_LOAD_IS_NOT_NODE, API0021, "The uri {/s} does not identify an XML node")

DEF_ERR_CODE(API0023_CANNOT_SERIALIZE_UPDATE_QUERY, API0023, "Cannot serialize an updating query")

DEF_ERR_CODE(API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY, API0024, "Cannot iterate over an updating query")

DEF_ERR_CODE(API0025_END_OF_SEQUENCE, API0025_END_OF_SEQUENCE, "Reached the end of the sequence")

DEF_ERR_CODE(API0026_CANNOT_CLOSE_QUERY_WITH_ITERATORS, API0026, "Query cannot be closed because there are result iterators on it")

DEF_ERR_CODE(API0027_CANNOT_UPDATE_DCTX_WITH_ITERATORS, API0027, "The query dynamic context cannot be updated because there are result iterators on the query")

DEF_ERR_CODE(API0028_INVALID_NODE_URI, API0028, "The uri {/s} is not a valid node reference")

DEF_ERR_CODE(API0030_NO_NODE_AT_GIVEN_POSITION, API0030, "There is no node at the given position {/s}, the collection has fewer nodes.");

DEF_ERR_CODE(API0033_FILE_OR_FOLDER_DOES_NOT_EXIST, API0033, "File or folder {/s} does not exist.");

DEF_ERR_CODE(API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED, API0034, "File or folder {/s} could not be opened.");

DEF_ERR_CODE(API0035_COLLECTION_CANNOT_BE_SERIALIZED, API0035, "Collection {/s} can not be serialized.");

DEF_ERR_CODE(API0036_TIDY_ERROR, API0036, "Error in Tidy library: {/s}.");

DEF_ERR_CODE(API0037_TIDY_ERROR_SET_OPTION, API0037, "Could not set option {/s} with value {/s} in Tidy.");

DEF_ERR_CODE(API0050_REST_ERROR_HEADER, API0050, "Invalid value passed for header parameter.");
DEF_ERR_CODE(API0051_REST_ERROR_PAYLOAD, API0051, "Invalid value passed for payload parameter.");

DEF_ERR_CODE(API0060_CONV_JSON_PARSE, API0060, 
"Could not parse the Json string {/s}. Reason: {/s}.");

DEF_ERR_CODE(API0061_CONV_JSON_SERIALIZE, API0061,
"Could not serialize the element with string representation {/s}. Error: {/s}");

DEF_ERR_CODE(API0062_CONV_JSON_PARAM, API0062, 
"Parameter with string representation {/s} is not an element node.");

DEF_ERR_CODE(API0063_CONV_JSON_ML_PARSE, API0063, 
"Could not parse the JsonML string {/s} reason: {/s}.");

DEF_ERR_CODE(API0064_CONV_JSON_ML_SERIALIZE, API0064, 
"Could not serialize the element with string representation {/s}. Error: {/s}");

DEF_ERR_CODE(API0065_CONV_JSON_ML_PARAM, API0065, 
"Parameter with string representation {/s} is not an element node.");

DEF_ERR_CODE(API0066_JSON_SEQUENCE_CANNOT_BE_SERIALIZED, API0066, 
"Cannot serialize a sequence with more than one element if the 'json' or 'jsonml' method was selected.")

DEF_ERR_CODE(API0070_INVALID_SERIALIZATION_METHOD_FOR_SAX, API0070,
"Invalid serialization method. Only XML output can issue SAX event notifications. Therefore, only the following serialization methods are allowed: xml, xhtml, jsonml")

DEF_ERR_CODE(API0071_CONV_CSV2XML_PARAM, API0071, 
"Invalid parameter in csv import: /s /s")

DEF_ERR_CODE(API0072_CONV_CSV2XML_TOO_MANY_FIELDS, API0072, 
"CSV import error: first row is header but one of the subsequent rows contains more fields than the header")

DEF_ERR_CODE(API0073_CONV_XML2CSV_PARAM, API0073, 
"CSV export error: /s /s")

//
// Store Errors
//
DEF_ERR_CODE(STR0001_INDEX_ALREADY_EXISTS, STR0001,
"An index with qname /s exists already.")

DEF_ERR_CODE(STR0002_INDEX_DOES_NOT_EXIST, STR0002,
"An index with qame /s does not exist.")

DEF_ERR_CODE(STR0003_INDEX_PARTIAL_KEY_INSERT, STR0003,
"Partial key insertion in index \"/s\". Key = /s")

DEF_ERR_CODE(STR0004_INDEX_PARTIAL_KEY_REMOVE, STR0004,
"Partial key deletion from index \"/s\"")

DEF_ERR_CODE(STR0005_INDEX_PARTIAL_KEY_PROBE, STR0005,
"Partial key probe into index \"/s\"")

DEF_ERR_CODE(STR0006_INDEX_INVALID_BOX_PROBE, STR0006,
"Invalid box probe condition for index \"/s\" : /s")

DEF_ERR_CODE(STR0007_INDEX_UNSUPPORTED_PROBE_CONDITION, STR0007,
"Index \"/s\" does not support probe conditions of kind /s")


DEF_ERR_CODE(STR0008_COLLECTION_ALREADY_EXISTS, STR0008,
"A collection with URI {/s} exists already.")

DEF_ERR_CODE(STR0009_COLLECTION_NOT_FOUND, STR0009,
"A collection with URI {/s} does not exist.")

DEF_ERR_CODE(STR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION, STR0010,
"Node cannot be inserted in collection /s because it belongs already to collection /s.");

DEF_ERR_CODE(STR0011_COLLECTION_NON_ROOT_NODE, STR0011,
"Node cannot be inserted in collection /s because it is a non-root node.");

DEF_ERR_CODE(STR0012_COLLECTION_ITEM_MUST_BE_A_NODE, STR0012,
"A non-node item is involved in an operation on collection /s.");

DEF_ERR_CODE(STR0020_LOADER_IO_ERROR, STR0020, 
"Loader I/O error: /s")

DEF_ERR_CODE(STR0021_LOADER_PARSING_ERROR, STR0021,
"Loader parsing error: /s")

DEF_ERR_CODE(STR0030_NODEID_ERROR, STR0030,
"Nodeid error: /s")

DEF_ERR_CODE(STR0040_TYPE_ERROR,  STR0040,
"Type error: /s")

DEF_ERR_CODE(STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE, STR0050,
"The function called {/s} is not available for the given item type {/s}.")


//
// ZORBA-specific errors
//
DEF_ERR_CODE (XQP0000_DYNAMIC_RUNTIME_ERROR, XQP0000, "XQP0000_DYNAMIC_RUNTIME_ERROR")

DEF_ERR_CODE (XQP0001_DYNAMIC_ITERATOR_OVERRUN, XQP0001, "XQP0001_DYNAMIC_ITERATOR_OVERRUN")

DEF_ERR_CODE (XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD, XQP0002, "XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD")

DEF_ERR_CODE (XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND, XQP0003, "XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND")

DEF_ERR_CODE (XQP0004_SYSTEM_NOT_SUPPORTED, XQP0004, "/s not implemented or not supported")

DEF_ERR_CODE (XQP0005_SYSTEM_ASSERT_FAILED, XQP0005, "Assertion /s failed in /s")

DEF_ERR_CODE (XQP0019_INTERNAL_ERROR, XQP0019, "Zorba internal error /s")

DEF_ERR_CODE (XQP0020_INVALID_URI, XQP0020, "Invalid URI /s")

DEF_ERR_CODE (XQP0021_USER_ERROR, XQP0021, "User error")

DEF_ERR_CODE (XQP0022_GET_RESULTS_AS_DOM_FAILED, XQP0022, "Couldn't get result as DOM")

DEF_ERR_CODE (XQP0023_GET_RESULTS_AS_SAX_FAILED, XQP0023, "Couldn't get result as SAX")

DEF_ERR_CODE (XQP0025_COULD_NOT_CREATE_ITEM, XQP0025, "The item could not be created.")

DEF_ERR_CODE (XQP0026_CANNOT_INIT_STORE, XQP0026, "Failed to initialize store.")

DEF_ERR_CODE (XQP0027_MS_DOM_ERROR, XQP0027, "Error from MS DOM engine.")

DEF_ERR_CODE(XQP0028_FUNCTION_IMPL_NOT_FOUND, XQP0028,
             "The external function called ({/s}/s) is not bound in the static context")

DEF_ERR_CODE(XQP0030_DEADLOCK, XQP0029,
             "Lock upgrade request will result in deadlock")

DEF_ERR_CODE(XQP0031_MALFORMED_XQUERYX_INPUT, XQP0031,
             "XQueryX Xml input is malformed.")

DEF_ERR_CODE(XQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY, XQP0032,
             "Error transforming XQueryX to XQuery using XSLT engine.")

DEF_ERR_CODE(XQP0034_ILLEGAL_UTF8_BYTE, XQP0034,
             "Illegal byte foud in UTF-8 character sequence.")

DEF_ERR_CODE(XQP0035_ILLEGAL_UTF16_BYTE, XQP0035,
             "Illegal byte foud in UTF-16 character sequence.")

DEF_ERR_CODE(XQP0036_BREAKITERATOR_CREATION_FAILED, XQP0036,
             "ICU::BreakIterator creation failed.")

//
// XPDY
//

DEF_ERR_CODE (XPDY0002, XPDY0002, "evaluation of an expression relies on some part of the dynamic context that has not been assigned a value: {/s}.")

DEF_ERR_CODE (XPDY0050, XPDY0050, "The dynamic type of the operand of a treat expression does not match the sequence type specified by the treat expression.")


//
// XPST
//

DEF_ERR_CODE (XPST0001, XPST0001, "Analysis of an expression relies on some component of the static context that has not been assigned a value {/s}")

DEF_ERR_CODE (XPST0003, XPST0003, "Expression is not a valid instance of the grammar.")

DEF_ERR_CODE (XPST0005, XPST0005, "During the analysis phase, it is a static error if the static type assigned to an expression other than the expression () or data(()) is empty-sequence().")

DEF_ERR_CODE (XPST0008, XPST0008, "Expression refers to an element name, attribute name, schema type name, namespace prefix, or variable name that is not defined in the static context: {/s} {/s}")

DEF_ERR_CODE (XPST0010, XPST0010, "An implementation must raise a static error if it encounters a reference to an axis that it does not support.")

DEF_ERR_CODE (XPST0017, XPST0017, "Expanded QName and number of arguments in function call do not match the name and arity of any function signature in the static context {/s} / {/s}")

DEF_ERR_CODE (XPST0051, XPST0051, "A QName {/s} that is used as an AtomicType in a SequenceType is not defined in the in-scope schema types as an atomic type.")

DEF_ERR_CODE (XPST0080, XPST0080, "The target type of a cast or castable expression is xs:NOTATION or xs:anyAtomicType.")

DEF_ERR_CODE (XPST0081, XPST0081, "A QName used in a query contains namespace prefix {/s} that cannot be expanded into a namespace URI by using the statically known namespaces")


//
// XPTY
//

DEF_ERR_CODE (XPTY0004, XPTY0004, "During the static analysis phase, an expression is found to have a static type that is not appropriate for the context in which the expression occurs, or during the dynamic evaluation phase, the dynamic type of a value does not match a required type as specified by the matching rules: {/s}")

DEF_ERR_CODE (XPTY0018, XPTY0018, "The result of the last step in a path expression contains both nodes and atomic values.")

DEF_ERR_CODE (XPTY0019, XPTY0019, "The result of a step (other than the last step) in a path expression contains an atomic value.")

DEF_ERR_CODE (XPTY0020, XPTY0020, "In an axis step, the context item is not a node.")



//
// XQDY
//

DEF_ERR_CODE (XQDY0025, XQDY0025, "An attribute of a constructed element has name \"/s\", which is not distinct from the names of all other attributes of the constructed element.")

DEF_ERR_CODE (XQDY0026, XQDY0026, "The result of the content expression of a computed processing instruction constructor contains the string return \"?>\".")

DEF_ERR_CODE (XQDY0027, XQDY0027, "In a validate expression, it is a dynamic error if the root element information item in the PSVI resulting from validation does not have the expected validity property: valid if validation mode is strict, or either valid or notKnown if validation mode is lax.")

DEF_ERR_CODE (XQDY0041, XQDY0041, "The value of the name expression in a computed processing instruction constructor cannot be cast to the type xs:NCName.")

DEF_ERR_CODE (XQDY0044, XQDY0044, "The node-name property of the node constructed by a computed attribute constructor is in the namespace http:// www.w3.org/2000/xmlns/ (corresponding to namespace prefix xmlns), or is in no namespace and has local name xmlns.")

DEF_ERR_CODE (XQDY0061, XQDY0061, "The operand of a validate expression is a document node whose children do not consist of exactly one element node and zero or more comment and processing instruction nodes, in any order.")

DEF_ERR_CODE (XQDY0064, XQDY0064, "The value of the name expression in a computed processing instruction constructor is equal to return \"XML\"(in any combination of upper and lower case).")

DEF_ERR_CODE (XQDY0072, XQDY0072, "the result of the content expression of a computed comment constructor contains two adjacent hyphens or ends with a hyphen.")

DEF_ERR_CODE (XQDY0074, XQDY0074, "The value of the name expression in a computed element or attribute constructor cannot be converted to an expanded QName (for example, because it contains a namespace prefix not found in statically known namespaces.) return ")

DEF_ERR_CODE (XQDY0084, XQDY0084, "The element validated by a validate statement does not have a top-level element declaration in the in-scope element declarations, if validation mode is strict.")

//
// XQST
//

DEF_ERR_CODE (XQST0009, XQST0009, "Schema Import Feature not supported.")

DEF_ERR_CODE (XQST0012, XQST0012, "Error in schema validity.")

DEF_ERR_CODE (XQST0013, XQST0013, "Recognized a pragma but determines that its content is invalid.")

DEF_ERR_CODE (XQST0016, XQST0016, "An implementation that does not support the Module Feature raises a static error if it encounters a module declaration or a module import.")

DEF_ERR_CODE (XQST0022, XQST0022, "The value of a namespace declaration attribute is not a URILiteral.")

DEF_ERR_CODE (XQST0031, XQST0031, "The version number specified in a version declaration is not supported by the implementation.")

DEF_ERR_CODE (XQST0032, XQST0032, "Prolog contains more than one base URI declaration.")

DEF_ERR_CODE (XQST0033, XQST0033, "A module contains multiple bindings for the same namespace prefix.")

DEF_ERR_CODE (XQST0034, XQST0034, "Duplicate function: {/s}")

DEF_ERR_CODE (XQST0035, XQST0035, "Error importing two schema components that both define the same name in the same symbol space and in the same scope.")

DEF_ERR_CODE (XQST0036, XQST0036, "Error importing a module if the importing module's in-scope schema types do not include definitions for the schema type names that appear in the declarations of variables and functions (whether in an argument type or return type) that are present in the imported module and are referenced in the importing module.")

DEF_ERR_CODE (XQST0038, XQST0038, "Prolog contains more than one default collation declaration, or the value specified by a default collation declaration is not present in statically known collations.")

DEF_ERR_CODE (XQST0039, XQST0039, "It is a static error for a function declaration to have more than one parameter with the same name: /s")

DEF_ERR_CODE (XQST0040, XQST0040, "The attributes specified by a direct element constructor do not have distinct expanded QNames.")

DEF_ERR_CODE (XQST0045, XQST0045, "Function name {/s} cannot be in one of the following namespaces: http://www.w3.org/XML/1998/namespace, http://www.w3.org/2001/XMLSchema, http://www.w3.org/2001/XMLSchema-instance, http://www.w3.org/2005/xpath-functions")

DEF_ERR_CODE (XQST0046, XQST0046, "Value of a URILiteral is of nonzero length and is not in the lexical space of xs:anyURI.")

DEF_ERR_CODE (XQST0047, XQST0047, "Multiple module imports in the same Prolog specify the same target namespace.")

DEF_ERR_CODE (XQST0048, XQST0048, "A function or variable declared in a library module is not in the target namespace of the library module.")

DEF_ERR_CODE (XQST0049, XQST0049, "Two or more variables declared or imported by a module have equal expanded QNames {/s} (as defined by the eq operator.)")

DEF_ERR_CODE (XQST0054, XQST0054, "A variable depends on itself.")

DEF_ERR_CODE (XQST0055, XQST0055, "A Prolog contains more than one copy-namespaces declaration.")

DEF_ERR_CODE (XQST0057, XQST0057, "A schema import binds a namespace prefix but does not specify a target namespace other than a zero-length string.")

DEF_ERR_CODE (XQST0058, XQST0058, "Multiple schema imports specify the same target namespace.")

DEF_ERR_CODE (XQST0059, XQST0059, "Unable to process a schema or module import by finding a schema or module {/s} with the specified target namespace {/s}")

DEF_ERR_CODE (XQST0060, XQST0060, "The name of a function in a function declaration is not in a namespace (expanded QName has a null namespace URI).")

DEF_ERR_CODE (XQST0065, XQST0065, "Prolog contains more than one ordering mode declaration.")

DEF_ERR_CODE (XQST0066, XQST0066, "Prolog contains more than one default element/type namespace declaration, or more than one default function namespace declaration.")

DEF_ERR_CODE (XQST0067, XQST0067, "Prolog contains more than one construction declaration.")

DEF_ERR_CODE (XQST0068, XQST0068, "Prolog contains more than one boundary-space declaration.")

DEF_ERR_CODE (XQST0069, XQST0069, 
"Prolog contains more than one empty order declaration.")

DEF_ERR_CODE (XQST0070, XQST0070, 
"Namespace URI is bound to a predefined prefix")

DEF_ERR_CODE (XQST0071, XQST0071, 
"Namespace declaration attributes of a direct element constructor do not have distinct names.")

DEF_ERR_CODE (XQST0073, XQST0073, 
"The graph of module imports contains a cycle.")

DEF_ERR_CODE (XQST0075, XQST0075, 
"An implementation that does not support the Validation Feature must raise a static error if it encounters a validate expression.")

DEF_ERR_CODE (XQST0076, XQST0076, 
"A collation subclause in an order by clause of a FLWOR expression does not identify a collation that is present in statically known collations.")

DEF_ERR_CODE (XQST0079, XQST0079, 
"An extension expression contains neither a pragma that is recognized by the implementation nor an expression enclosed in curly braces.")

DEF_ERR_CODE (XQST0085, XQST0085, 
"The namespace URI in a namespace declaration attribute is a zero-length string, and the implementation does not support [XML Names 1.1].")

DEF_ERR_CODE (XQST0087, XQST0087, 
"the encoding specified in a Version Declaration does not conform to the definition of EncName specified in [XML 1.0].")

DEF_ERR_CODE (XQST0088, XQST0088, 
"The literal that specifies the target namespace in a module import or a module declaration is of zero length.")

DEF_ERR_CODE (XQST0089, XQST0089,
"A variable bound in a for clause of a FLWOR expression, and its associated positional variable, do not have distinct names.")

DEF_ERR_CODE (XQST0090, XQST0090,
"A character reference does not identify a valid character in the version of XML that is in use.")

DEF_ERR_CODE(XQST0096, XQST0096,
"It is a static error for a query prolog to contain two decimal formats with the same name, or to contain two default decimal formats.")


//
// XQTY
//

DEF_ERR_CODE (XQTY0030, XQTY0030, 
"The argument of a validate expression does not evaluate to exactly one document or element node.")

DEF_ERR_CODE (XQTY0086, XQTY0086, 
"The typed value of a copied element or attribute node is namespace-sensitive when construction mode is preserve and copy-namespaces mode is no-preserve.")

DEF_ERR_CODE (XQTY0024, XQTY0024, 
"It is a type error if the content sequence in an element constructor contains an attribute node following a node that is not an attribute node.")


//
// UPDATE FACILITY
//

DEF_ERR_CODE(XUST0001, XUST0001, "It is a static error if an updating expression is used in any position other than one of the following: \n \
 1. The topmost expression in the body of a query. \n \
 2. The modify clause of a transform expression. \n \
 3. The return clause of a FLWOR expression. \n \
 4. The return clauses of a typeswitch expression in which every return \
    clause contains an updating expression, an empty expression ( ), or \
    a call to the fn:error function. \
 5. The then and else clauses of a conditional statement in which both \
    the then and else clauses contain either an updating expression, an \
    empty expression ( ), or a call to the fn:error function. \
 6. An operand of a comma expression in which each operand is either an \
    updating expression, an empty expression ( ), or a call to the \
    fn:error function. \
 7. The content of a parenthesized expression. \
 8. The body of a function declaration in which the keyword updating \
    is specified.")

DEF_ERR_CODE(XUST0002, XUST0002, "It is a static error if an non-updating expression other than an empty expression ( ) or a call to the fn:error function is used in one of the following positions: \
 1. The modify clause of a transform expression. \
 2. The top-level expression in the body of a function declaration in \
    which the keyword updating is specified.")

DEF_ERR_CODE(XUST0003, XUST0003, "It is a static error if a Prolog contains more than one revalidation declaration.")

DEF_ERR_CODE(XUTY0004, XUTY0004, "It is a type error if the insertion sequence of an insert expression contains an attribute node following a node that is not an attribute node.")

DEF_ERR_CODE(XUTY0005, XUTY0005, "In an insert expression where into, as first into, or as last into is specified, it is a type error if the target expression returns a non-empty result that does not consist of a single element or document node.")

DEF_ERR_CODE(XUTY0006, XUTY0006, "In an insert expression where before or after is specified, it is a type error if the target expression returns a non-empty result that does not consist of a single element, text, comment, or processing instruction node.")

DEF_ERR_CODE(XUTY0007, XUTY0007, "It is a type error if the target expression of a delete expression does not return a sequence of zero or more nodes.")

DEF_ERR_CODE(XUTY0008, XUTY0008, "In a replace expression, it is a type error if the target expression returns a non-empty result that does not consist of a single element, attribute, text, comment, or processing instruction node.")

DEF_ERR_CODE(XUDY0009, XUDY0009, "In a replace expression where value of is not specified, it is a dynamic error if the node returned by the target expression does not have a parent.")

DEF_ERR_CODE(XUTY0010, XUTY0010, "In a replace expression where value of is not specified and the target is an element, text, comment, or processing instruction node, it is a type error if the replacement sequence does not consist of zero or more element, text, comment, or processing instruction nodes.")

DEF_ERR_CODE(XUTY0011, XUTY0011, "In a replace expression where value of is not specified and the target is an attribute node, it is a type error if the replacement sequence does not consist of zero or more attribute nodes.")

DEF_ERR_CODE(XUTY0012, XUTY0012, "In a rename expression, it is a type error if the target expression returns a non-empty result that does not consist of a single element, attribute, or processing instruction node.")

DEF_ERR_CODE(XUTY0013, XUTY0013, "In a transform expression, it is a type error if a source expression in the copy clause does not return a single node.")

DEF_ERR_CODE(XUDY0014, XUDY0014,  "In a transform expression, it is a dynamic error if the modify clause modifies any node that was not created by the copy clause.")

DEF_ERR_CODE(XUDY0015, XUDY0015, "It is a dynamic error if any node is the target of more than one rename expression within the same query.")

DEF_ERR_CODE(XUDY0016, XUDY0016, "It is a dynamic error if any node is the target of more than one replace expression (without value of being specified) within the same query.")

DEF_ERR_CODE(XUDY0017, XUDY0017, "It is a dynamic error if any node is the target of more than one replace value of expression within the same query.")

DEF_ERR_CODE(XUDY0018, XUDY0018, "It is a dynamic error if a function that was declared to be external but not updating returns a non-empty pending update list.")

DEF_ERR_CODE(XUDY0019, XUDY0019, "It is a dynamic error if a function that was declared to be both external and updating returns a non-empty data model instance.")

DEF_ERR_CODE(XUDY0020, XUDY0020, "An implementation may (but is not required to) raise a dynamic error if a node is deleted that had no parent before execution of the query began.")

DEF_ERR_CODE(XUDY0021, XUDY0021, "It is a dynamic error if the XDM instance that would result from applying all the updates in a query violates any constraint specified in [XQuery/XPath Data Model (XDM)]. In this case, none of the updates in the query are made effective.")

DEF_ERR_CODE(XUTY0022, XUTY0022, "It is a type error if an insert expression specifies the insertion of an attribute node into a document node.")

DEF_ERR_CODE(XUDY0023, XUDY0023, "It is a dynamic error if an insert, replace, or rename expression affects an element node by introducing a new namespace binding that conflicts with one of its existing namespace bindings.")

DEF_ERR_CODE(XUDY0024, XUDY0024, "It is a dynamic error if the effect of a set of updating expressions is to introduce conflicting namespace bindings into an element node.")

DEF_ERR_CODE(XUDY0025, XUDY0025, "It is a dynamic error if the target of a rename expression is a processing instruction node, and the new name expression returns a QName with a non-empty namespace prefix.")

DEF_ERR_CODE(XUST0026, XUST0026, "It is a static error if a revalidation declaration in a Prolog specifies a revalidation mode that is not supported by the current implementation.")

DEF_ERR_CODE(XUDY0027, XUDY0027, "It is a dynamic error if the target expression of an insert, replace, or rename expression evaluates to an empty sequence.")

DEF_ERR_CODE(XUST0028, XUST0028, "It is a static error if a function declaration specifies both updating and a return type.")

DEF_ERR_CODE(XUDY0029, XUDY0029, "In an insert expression where before or after is specified, it is a dynamic error if node returned by the target expression does not have a parent.")

DEF_ERR_CODE(XUDY0030, XUDY0030, "It is a dynamic error if an insert expression specifies the insertion of an attribute node before or after a child of a document node.")

DEF_ERR_CODE(XUDY0031, XUDY0031, "It is a dynamic error if multiple calls to fn:put in the same snapshot specify the same URI (after resolution of relative URIs).")


DEF_ERR_CODE(SRL0001_INEXISTENT_INPUT_FIELD, SRL0001, "Plan serialization error: Cannot read expected input field.")

DEF_ERR_CODE(SRL0002_INCOMPATIBLE_INPUT_FIELD, SRL0002, "Plan serialization error: Input field is not the expected one for id: /s.")

DEF_ERR_CODE(SRL0003_UNRECOGNIZED_CLASS_FIELD, SRL0003, "Plan serialization error: Cannot find class factory for class: /s.")

DEF_ERR_CODE(SRL0004_UNRESOLVED_FIELD_REFERENCE, SRL0004, "Plan serialization error: Unresolved forward field reference. Referencing id: /s.")

DEF_ERR_CODE(SRL0005_CLASS_VERSION_IS_TOO_NEW, SRL0005, "Plan serialization error: Class version is too new: /s.")

DEF_ERR_CODE(SRL0006_CLASS_VERSION_IS_TOO_OLD, SRL0006, "Plan serialization error: Class version is too old: /s.")

DEF_ERR_CODE(SRL0007_INPUT_ARCHIVE_USED_FOR_OUT_SERIALIZATION, SRL0007, "Plan serialization error: Input archive used for out serialization.")

DEF_ERR_CODE(SRL0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION, SRL0008, "Plan serialization error: Output archive used for in serialization.")

DEF_ERR_CODE(SRL0009_CLASS_NOT_SERIALIZABLE, SRL0009, "Plan serialization error: Class not serializable: /s")

DEF_ERR_CODE(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, SRL0010, "Plan serialization error: Store item type not serializable: /s")

DEF_ERR_CODE(SRL0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE, SRL0011, "Plan serialization error: Unrecognized input archive.")

DEF_ERR_CODE(SRL0012_INCOMPATIBLE_ARCHIVE_VERSION, SRL0012, "Plan serialization error: Incompatible archive version: /s")

DEF_ERR_CODE(SRL0013_UNABLE_TO_LOAD_QUERY, SRL0013, "Plan serialization error: Unable to load query plan: /s")

DEF_ERR_CODE(SRL0014_INFINITE_CIRCULAR_DEPENDENCIES, SRL0014, "Plan serialization error: Unable to solve delayed serialization of object references")


//
// XQuery Data Definition Facility - Static Errors
//

DEF_ERR_CODE(XDST0001_COLLECTION_ALREADY_DECLARED, XDST0001,
"A collection with name /s is already declared in the same module")

DEF_ERR_CODE(XDST0002_COLLECTION_ALREADY_IMPORTED, XDST0002, 
"A collection with name /s that is imported from module /s is already declared in the importing module.")

DEF_ERR_CODE(XDST0003_COLLECTION_DECL_IN_MAIN_MODULE, XDST0003, 
"A collection declaration cannot appear in a main module.")

DEF_ERR_CODE(XDST0004_COLLECTION_MULTIPLE_PROPERTY_VALUES, XDST0004,
"The declaration for collection /s specifies multiple values for the same property.")

DEF_ERR_CODE(XDST0005_COLLECTION_PROPERTIES_CONFLICT, XDST0005,
"The declaration for collection /s specifies conflicting property values.")

DEF_ERR_CODE(XDST0006_COLLECTION_INVALID_PROPERTY_VALUE, XDST0006,
"The declaratrion for collection /s contains an invalid property value: /s")

DEF_ERR_CODE(XDST0021_INDEX_ALREADY_DECLARED, XDST0021,
"An index with name /s is already declared in the same module")

DEF_ERR_CODE(XDST0022_INDEX_ALREADY_IMPORTED, XDST0022, 
"An index with name /s that is imported from module /s is already declared in the importing module.")

DEF_ERR_CODE(XDST0023_INDEX_DECL_IN_MAIN_MODULE, XDST0023, 
"An index declaration cannot appear in a main module.")

DEF_ERR_CODE(XDST0024_INDEX_MULTIPLE_PROPERTY_VALUES, XDST0024,
"The declaration for index /s specifies multiple values for the same property.")

DEF_ERR_CODE(XDST0025_INDEX_PROPERTIES_CONFLICT, XDST0025,
"The declaration for index /s specifies conflicting property values.")

DEF_ERR_CODE(XDST0026_INDEX_INVALID_PROPERTY_VALUE, XDST0026,
"The declaration for index /s contains an invalid property value: /s")

DEF_ERR_CODE(XDST0027_INDEX_BAD_KEY_TYPE, XDST0027,
"The index /s has an invalid index key type")

DEF_ERR_CODE(XDST0028_INDEX_NOT_DETERMINISTIC, XDST0028,
"The index /s has a non deterministic definition.")

DEF_ERR_CODE(XDST0029_INDEX_INVALID_DATA_SOURCE, XDST0029,
"The index /s references a data source that is not a XQDDF collection.")

DEF_ERR_CODE(XDST0030_INDEX_NON_CONST_DATA_SOURCE, XDST0030,
"The index /s references a collection with a non-const QName")

DEF_ERR_CODE(XDST0031_INDEX_HAS_FREE_VARS, XDST0031,
"The index /s has free variables in its definition.")

DEF_ERR_CODE(XDST0032_INDEX_REFERENCES_CTX_ITEM, XDST0032,
"The domain expression of index /s references the context item.")

DEF_ERR_CODE(XDST0033_INDEX_NON_SIMPLE_EXPR, XDST0033,
"The declaration of index /s contains a non-simple expression.")

DEF_ERR_CODE(XDST0034_INDEX_CANNOT_DO_AUTOMATIC_MAINTENANCE, XDST0034,
"Index /s cannot be automatically maintained.")

DEF_ERR_CODE(XDST0035_INDEX_GENERAL_MULTIKEY, XDST0035,
"Index /s cannot be both a general index and have more than one key expressions")

DEF_ERR_CODE(XDST0041_IC_IS_ALREADY_DECLARED, XDST0041,
             "An integrity constraint with URI /s is declared already.")

DEF_ERR_CODE(XDST0042_MULTI_VALUED_IC_KEY, XDST0042,
             "An integrity constraint key has multiple values.")

DEF_ERR_CODE(XDST0043_NON_ATOMIC_IC_KEY, XDST0043,
             "An integrity constraint key has a non-atomic value.")

DEF_ERR_CODE(XDST0044_IC_DECL_IN_MAIN_MODULE, XDST0044,
             "The integrity constraint /s cannot be declared in a main module.")

DEF_ERR_CODE(XDST0045_IC_HAS_FREE_VARS, XDST0045,
             "The integrity constraint with URI /s has free variables in its definition.")

DEF_ERR_CODE(XDST0046_IC_HAS_INVALID_DATA_SOURCE, XDST0046,
             "The integrity constraint with URI /s references a data source that is not a collection among the statically known collections.")

DEF_ERR_CODE(XDST0047_IC_NOT_DETERMINISTIC, XDST0047,
             "The integrity constraint with URI /s has a non deterministic definition.")



//
// XQuery Data Definition Facility - Type Errors
//

DEF_ERR_CODE(XDTY0001_COLLECTION_INVALID_NODE_TYPE, XDTY0001,
"Collection /s cannot contain a node of type: /s")

DEF_ERR_CODE(XDTY0010_INDEX_DOMAIN_TYPE_ERROR, XDTY0010,
"The domain expression of index /s produces an item that is not a node.")

DEF_ERR_CODE(XDTY0011_INDEX_KEY_TYPE_ERROR, XDTY0011,
"The result of some key expression of index /s does not match its declared type.")

//
// XQuery Data Definition Facility - Dynamic Errors
//

DEF_ERR_CODE(XDDY0001_COLLECTION_NOT_DECLARED, XDDY0001, 
"Collection /s is not declared in the static context.")

DEF_ERR_CODE(XDDY0002_COLLECTION_EXISTS_ALREADY, XDDY0002, 
"Collection /s exists already.")

DEF_ERR_CODE(XDDY0003_COLLECTION_DOES_NOT_EXIST, XDDY0003, 
"Collection /s does not exist.")

DEF_ERR_CODE(XDDY0004_COLLECTION_CONST_UPDATE, XDDY0004, 
"Cannot update const collection /s.")

DEF_ERR_CODE(XDDY0005_COLLECTION_APPEND_BAD_INSERT, XDDY0005, 
"Illegal insert in append-only collection /s.")

DEF_ERR_CODE(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, XDDY0006, 
"Illegal insert in queue collection /s.")

DEF_ERR_CODE(XDDY0007_COLLECTION_APPEND_BAD_DELETE, XDDY0007, 
"Illegal delete from append-only collection /s.")

DEF_ERR_CODE(XDDY0008_COLLECTION_QUEUE_BAD_DELETE, XDDY0008, 
"Illegal delete from queue collection /s.")

DEF_ERR_CODE(XDDY0009_COLLECTION_QUEUE_BAD_DELETE, XDDY0009, 
"Not all the nodes to delete are at the beginning of queue collection /s.")

DEF_ERR_CODE(XDDY0010_COLLECTION_CONST_NODE_UPDATE, XDDY0010,
"Illegal update of node in collection /s, whose nodes are read-only.")

DEF_ERR_CODE(XDDY0011_COLLECTION_NODE_NOT_FOUND, XDDY0011, 
"Node is not contained in collection /s.")

DEF_ERR_CODE(XDDY0012_COLLECTION_UNORDERED_BAD_INSERT, XDDY0012, 
"Illegal insert in unordered collection /s.")

DEF_ERR_CODE(XDDY0013_COLLECTION_BAD_DESTROY_INDEXES, XDDY0013,
"Cannot delete collection /s because there are indexes that reference it.")

DEF_ERR_CODE(XDDY0014_COLLECTION_BAD_DESTROY_ICS, XDDY0014,
"Cannot delete collection /s because there are integrity constraints that reference it.")

DEF_ERR_CODE(XDDY0015_COLLECTION_BAD_DESTROY_NODES, XDDY0015,
"Cannot delete collection /s because there are references on its nodes.")

DEF_ERR_CODE(XDDY0016_COLLECTION_MULTIPLE_CREATES, XDDY0016, 
"Multiple calls to create-collection function in the same snapshot for collection /s.")


DEF_ERR_CODE(XDDY0020_INDEX_DOMAIN_NODE_NOT_IN_COLLECTION, XDDY0020,
"The domain expression of index /s produces nodes that are not in collection.")

DEF_ERR_CODE(XDDY0021_INDEX_IS_NOT_DECLARED, XDDY0021,
"Index /s is not declared in the static context.")

DEF_ERR_CODE(XDDY0022_INDEX_EXISTS_ALREADY, XDDY0022, 
"Index /s exists already.")

DEF_ERR_CODE(XDDY0023_INDEX_DOES_NOT_EXIST, XDDY0023, 
"Index /s does not exist.")

DEF_ERR_CODE(XDDY0024_INDEX_UNIQUE_VIOLATION, XDDY0024, 
"The uniqueness property of index /s is violated.")

DEF_ERR_CODE(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, XDDY0025,
"Invalid number of arguments in probe of index /s.")

DEF_ERR_CODE(XDDY0026_INDEX_RANGE_PROBE_NOT_ALLOWED, XDDY0026,
"Index /s does not support range probes.")

DEF_ERR_CODE(XDDY0027_INDEX_MULTIPLE_CREATES, XDDY0027, 
"Multiple calls to create-index function in the same snapshot for index /s.")


DEF_ERR_CODE(XDDY0031_IC_IS_NOT_DECLARED, XDDY0031,
             "An integrity constraint with URI /s is not declared.")

DEF_ERR_CODE(XDDY0032_IC_IS_NOT_ACTIVATED, XDDY0032,
             "An integrity constraint with URI /s is not declared.")

DEF_ERR_CODE(XDDY0033_IC_NOT_MET, XDDY0033,
             "Conditions for integrity constraint /s were not met on collection /s.")


#undef DEF_ERR_CODE

    for (int i = 0; i < MAX_ZORBA_ERROR_CODE; ++i) 
    {
      if (canonical_err_names [i] == NULL)
#ifdef WIN32
          canonical_err_names [i] = _strdup("?");
#else
          canonical_err_names [i] = strdup("?");
#endif
      if (err_msg [i] == NULL)
      {
        std::ostringstream stream;
        stream << "<Unknown errcode " << i << ">";
#ifdef WIN32
        err_msg[i] = _strdup(stream.str().c_str());
#else
        err_msg[i] = strdup(stream.str().c_str());
#endif
      }
    }
  }

  ~err_msg_wrapper()
  {
    for (int i = 0; i < MAX_ZORBA_ERROR_CODE; ++i) 
    {
      if (canonical_err_names[i] != NULL)
      {
        free(const_cast<char *>(canonical_err_names[i]));
      }

      if (err_msg [i] != NULL)
      {
        free(const_cast<char *>(err_msg [i]));
      }
    }
  }

  const char* get_canonical_err_name(const XQUERY_ERROR& code) const
  {
    return canonical_err_names[code];
  }

  const char *get_err_msg(const XQUERY_ERROR& code) const
  {
    return err_msg[code];
  }
};

static const struct err_msg_wrapper& get_err_msg_wrapper()
{
  static struct err_msg_wrapper wrapper;

  return wrapper;
}


std::string
ErrorMessages::getMessageForErrorCode(const XQUERY_ERROR& e) 
{
  ZORBA_ASSERT (e < MAX_ZORBA_ERROR_CODE);
  return get_err_msg_wrapper().get_err_msg(e);
} 


std::string
ErrorMessages::getMessageForWarningCode(ZorbaWarning::WarningCode& code)
{
  return "?";
}


std::string
ErrorMessages::getNameForErrorCode(const XQUERY_ERROR& code)
{
  ZORBA_ASSERT (code < MAX_ZORBA_ERROR_CODE);
  return get_err_msg_wrapper().get_canonical_err_name(code);
}


XQUERY_ERROR
ErrorMessages::getErrorCodeForName(const std::string& name) 
{
  const err_msg_wrapper& err_wrapper = get_err_msg_wrapper();
  // TODO: use a map or hashmap
  for (int i = 0; i < MAX_ZORBA_ERROR_CODE; i++)
  {
    if (name == err_wrapper.get_canonical_err_name((XQUERY_ERROR)i))
      return (XQUERY_ERROR) i;
  }
  return XQP0019_INTERNAL_ERROR;
}



XQUERY_ERROR
DecodeZorbatypesError(::zorba::ZorbatypesError::ErrorCode code)
{
  switch( code )
  {
    case  ::zorba::ZorbatypesError::FOER0000:
      return FOER0000;
      break;
    case  ::zorba::ZorbatypesError::FOAR0001:
      return FOAR0001;
      break;
    case  ::zorba::ZorbatypesError::FOAR0002:
      return FOAR0002;
      break;
    case ::zorba::ZorbatypesError::FOCA0001:
      return FOCA0001;
      break;
    case ::zorba::ZorbatypesError::FOCA0002:
      return FOCA0002;
      break;
    case ::zorba::ZorbatypesError::FOCA0003:
      return FOCA0003;
      break;
    case ::zorba::ZorbatypesError::FOCA0005:
      return FOCA0005;
      break;
    case ::zorba::ZorbatypesError::FOCA0006:
      return FOCA0006;
      break;
    case ::zorba::ZorbatypesError::FOCH0001:
      return FOCH0001;
      break;
    case ::zorba::ZorbatypesError::FOCH0002:
      return FOCH0002;
      break;
      
      
    case ::zorba::ZorbatypesError::FOCH0003:
      return FOCH0003;
      break;
    case ::zorba::ZorbatypesError::FOCH0004:
      return FOCH0004;
      break;
    case ::zorba::ZorbatypesError::FODC0001:
      return FODC0001;
      break;
    case ::zorba::ZorbatypesError::FODC0002:
      return FODC0002;
      break;
    case ::zorba::ZorbatypesError::FODC0003:
      return FODC0003;
      break;
    case ::zorba::ZorbatypesError::FODC0004:
      return FODC0004;
      break;
    case ::zorba::ZorbatypesError::FODC0005:
      return FODC0005;
      break;
    case ::zorba::ZorbatypesError::FODT0001:
      return FODT0001;
      break;
    case ::zorba::ZorbatypesError::FODT0002:
      return FODT0002;
      break;
    case ::zorba::ZorbatypesError::FODT0003:
      return FODT0003;
      break;

      
    case ::zorba::ZorbatypesError::FONS0004:
      return FONS0004;
      break;
    case ::zorba::ZorbatypesError::FONS0005:
      return FONS0005;
      break;
    case ::zorba::ZorbatypesError::FORG0001:
      return FORG0001;
      break;
    case ::zorba::ZorbatypesError::FORG0002:
      return FORG0002;
      break;
    case ::zorba::ZorbatypesError::FORG0003:
      return FORG0003;
      break;
    case ::zorba::ZorbatypesError::FORG0004:
      return FORG0004;
      break;
    case ::zorba::ZorbatypesError::FORG0005:
      return FORG0005;
      break;
    case ::zorba::ZorbatypesError::FORG0006:
      return FORG0006;
      break;
    case ::zorba::ZorbatypesError::FORG0008:
      return FORG0008;
      break;
    case ::zorba::ZorbatypesError::FORG0009:
      return FORG0009;
      break;

      
    case ::zorba::ZorbatypesError::FORX0001:
      return FORX0001;
      break;
    case ::zorba::ZorbatypesError::FORX0002:
      return FORX0002;
      break;
    case ::zorba::ZorbatypesError::FORX0003:
      return FORX0003;
      break;
    case ::zorba::ZorbatypesError::FORX0004:
      return FORX0004;
      break;
    case ::zorba::ZorbatypesError::FOTY0012:
      return FOTY0012;
      break;
    case ::zorba::ZorbatypesError::FOTY0013:
      return FOTY0013;
      break;
    case ::zorba::ZorbatypesError::FOTY0014:
      return FOTY0014;
      break;
    case ::zorba::ZorbatypesError::FOTY0015:
      return FOTY0015;
      break;
    case ::zorba::ZorbatypesError::FOUP0001:
      return FOUP0001;
      break;
    case ::zorba::ZorbatypesError::FOUP0002:
      return FOUP0002;
      break;

    default:
      return MAX_ZORBA_ERROR_CODE;
      break;
  }
  return FORX0001;
}

} /* namespace error */
} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
