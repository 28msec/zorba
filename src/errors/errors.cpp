/**
 * @file errors.cpp
 * @author Paul Pedersen
 * @copyright 2006-2007 FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "errors/errors.h"
//#include"../errors/xqp_exception.h"

#include <string>

using namespace std;
namespace xqp {
  

string errors_english::err_decode(enum errcode e)
{
#define TRIVIAL_ERR( e ) case e: return #e
  switch (e) {
  case XPST0001_STATIC_CONTEXT_COMPONENT_MISSING:
    return "XPST0001 Static context component missing";
  case XPDY0002_DYNAMIC_CONTEXT_COMPONENT_MISSING:
    return "XPDY0002 Dynamic context component missing";
  case XPST0003_STATIC_GRAMMAR_ERROR:
    return "XPST0003 XQuery grammar error";
  case XPTY0004_STATIC_TYPE_ERROR:
    return "XPTY0004 Static type error: the expression static type is not appropriate in this context, or the dynamic type does not match the required type";
  case XPST0005_STATIC_ILLEGAL_EMPTY_SEQUENCE:
    return "XPST0005 Static type assigned to an expression other than () or data(()) cannot be 'empty_sequence'";
  case XPST0008_STATIC_ILLEGAL_REFERENCE:
    return "XPST0008 Expression refers to an element name, attribute name, schema type name, namespace prefix, or variable name that is not defined in the static context: /s /s";///what elem and the name
  case XQST0009_STATIC_SCHEMA_IMPORT_NOT_SUPPORTED:
    return "XQST0009 Schema import feature not supported";
  case XPST0010_STATIC_AXIS_NOT_SUPPORTED:
    return "XPST0010 Axis not supported";
  case XQST0012_STATIC_SCHEMA_NOT_VALID:
    return "XQST0012 The set of definitions contained in schema imported by Prolog do not satisfy the conditions for schema validity specified in Sections 3 and 5 of [XML Schema] Part 1--i.e., each definition must be valid, complete, and unique";
  case XQST0013_STATIC_PRAGMA_NOT_VALID:
    return "XQST0013 Pragma not valid";
  case XQST0016_STATIC_MODULE_IMPORT_NOT_SUPPORTED:
    return "XQST0016 Module import feature not supported";
  case XPST0017_STATIC_FUNCTION_NOT_FOUND:
    return "XPST0017 Expanded QName and number of arguments in function call do not match the name and arity of any function signature in the static context";
  case XPTY0018_TYPE_MIXED_PATHEXPR:
    return "XPTY0018 The result of the last step in a path expression contains both nodes and atomic values";
  case XPTY0019_TYPE_STEP_IS_ATOMIC:
    return "XPTY0019 The result of a step (other than the last step) in path expression contains an atomic value";
  case XPTY0020_TYPE_CONTEXT_NOT_A_NODE:
    return "XPTY0020 The context item must be a node in an axis step";
  case XQST0022_STATIC_NAMESPACE_DECL_NOT_A_URI:
    return "XQST0022 The value of namespace declaration attribute is not a URILiteral";
  case XQTY0024_TYPE_ATTRIBUTE_NODE_OUT_OF_ORDER:
    return "XQTY0024 The content sequence in the element constructor contains an attribute node following a node that is not an attribute node";
  case XQDY0025_DYNAMIC_DUPLICATE_ATTRIBUTE_NAME:
    return "XQDY0025 Duplicate attribute name in the constructed element";
  case XQDY0026_DYNAMIC_ILLEGAL_CONTENT:
    return "XQDY0026 The result of the content expression of the computed processing instruction constructor cannot contain the string \"?>\"";
  case XQDY0027_DYNAMIC_VALIDATION_FAILED:
    return "XQDY0027 The root element information item in the PSVI resulting from validation does not have the expected validity property: valid if validation mode is strict, or either valid or notKnown if validation mode is lax";
  case XQTY0030_TYPE_VALIDATION_BAD_ARG:
    return "XQTY0030 The argument of a validate expression must evaluate to exactly one document or element node";
  case XQST0031_STATIC_BAD_VERSION:
    return "XQST0031 The version number specified in version declaration is not supported by the implementation";
  case XQST0032_STATIC_DUPLICATE_BASE_URI:
    return "XQST0032 Prolog contains more than one base URI declaration";
  case XQST0033_STATIC_DUPLICATE_NAMESPACE_PREFIX:
    return "XQST0033 Module contains multiple bindings for the same namespace prefix";
  case XQST0034_STATIC_DUPLICATE_FUNCTIONS:
    return "XQST0034 Duplicate function: /s";
  case XQST0035_STATIC_DUPLICATE_SCHEMAS:
    return "XQST0035 Two imported schema components both define the same name in the same symbol space and in the same scope";
  case XQST0036_STATIC_MISSSING_IMPORTED_SCHEMA_TYPES:
    return "XQST0036 The in-scope schema types of the imported module do not include definitions for the schema type names that appear in the declarations of variables and functions (whether in an argument type or return type) that are present in the imported module and are referenced in the importing module";
  case XQST0038_STATIC_DUPLICATE_DEFAULT_COLLATION:
    return "XQST0038 Prolog contain more than one default collation declaration, or the value specified by a default collation declaration is not present in statically known collations";
  case XQST0039_STATIC_DUPLICATE_FUNARG_NAME:
    return "XQST0039 Function declaration cannot have more than one parameter with the same name";
  case XQST0040_STATIC_DUPLICATE_ATTRIBUTE_NAME:
    return "XQST0040 The attributes specified by a direct element constructor must have distinct expanded QNames";
  case XQDY0041_DYNAMIC_PI_NON_NCNAME:
    return "XQDY0041 The value of the name expression in a computed processing instruction constructor cannot be cast to the type xs:NCName";
  case XQDY0044_DYNAMIC_ILLEGAL_ATTRIBUTE_NAME:
    return "XQDY0044 The node-name property of the node constructed by a computed attribute constructor is in the namespace http://www.w3.org/2000/xmlns/ (corresponding to namespace prefix xmlns), or is in no namespace and has local name xmlns";
  case XQST0045_STATIC_ILLEGAL_FUNCTION_NAME:
    return "XQST0045 Function name '/s' cannot be in one of the following namespaces: http://www.w3.org/XML/1998/namespace, http://www.w3.org/2001/XMLSchema, http://www.w3.org/2001/XMLSchema-instance, http://www.w3.org/2005/xpath-functions";
  case XQST0046_STATIC_ILLEGAL_URI_LITERAL:
    return "XQST0046 The URILiteral value is of nonzero length and is not in the lexical space of xs:anyURI";
  case XQST0047_STATIC_DUPLICATE_IMPORTED_TARGET_NS:
    return "XQST0047 Multiple module imports in the same Prolog specify the same target namespace";
  case XQST0048_STATIC_MISSING_TARGET_NAMESPACE:
    return "XQST0048 Functions and variables declared in a library module must be in the target namespace of the library module";
  case XQST0049_STATIC_DUPLICATE_IMPORTED_VARIABLES:
    return "XQST0049 Duplicate expanded qnames of imported variables";
  case XPDY0050_DYNAMIC_TREAT_FAILED:
    return "XPDY0050 The dynamic type of the operand of a treat expression does not match the sequence type specified by the treat expression. This error might also be raised by a path expression beginning with \"/\" or \"//\" if the context node is not in a tree that is rooted at a document node. This is because a leading \"/\" or \"//\" in a path expression is an abbreviation for an initial step that includes the clause treat as document-node()";
  case XPST0051_STATIC_MISSING_SCHEMA_TYPE:
    return "XPST0051_STATIC_MISSING_SCHEMA_TYPE";
  case XQST0054_STATIC_CIRCULAR_INITIALIZATION:
    return "XQST0054_STATIC_CIRCULAR_INITIALIZATION";
  case XQST0055_STATIC_DUPLICATE_COPY_NAMESPACE:
    return "XQST0055_STATIC_DUPLICATE_COPY_NAMESPACE";
  case XQST0057_STATIC_MISSING_TARGET_NAMESPACE:
    return "XQST0057_STATIC_MISSING_TARGET_NAMESPACE";
  case XQST0058_STATIC_DUPLICATE_TARGET_NAMESPACE:
    return "XQST0058_STATIC_DUPLICATE_TARGET_NAMESPACE";
  case XQST0059_STATIC_TARGET_NAMESPACE_NOT_FOUND:
    return "XQST0059_STATIC_TARGET_NAMESPACE_NOT_FOUND";
  case XQST0060_STATIC_FUNCTION_MISSING_NAMESPACE:
    return "XQST0060_STATIC_FUNCTION_MISSING_NAMESPACE";
  case XQDY0061_DYNAMIC_VALIDATE_BAD_DOCUMENT:
    return "XQDY0061_DYNAMIC_VALIDATE_BAD_DOCUMENT";
  case XQDY0064_DYNAMIC_ILLEGAL_PI_NAME:
    return "XQDY0064_DYNAMIC_ILLEGAL_PI_NAME";
  case XQST0065_STATIC_DUPLICATE_ORDERING_MODE_DECL:
    return "XQST0065_STATIC_DUPLICATE_ORDERING_MODE_DECL";
  case XQST0066_STATIC_DUPLICATE_DEFAULT_NAMESPACE_DECL:
    return "XQST0066_STATIC_DUPLICATE_DEFAULT_NAMESPACE_DECL";
  case XQST0067_STATIC_DUPLICATE_CONSTRUCTION_DECL:
    return "XQST0067_STATIC_DUPLICATE_CONSTRUCTION_DECL";
  case XQST0068_STATIC_DUPLICATE_BOUNDARY_SPACE_DECL:
    return "XQST0068_STATIC_DUPLICATE_BOUNDARY_SPACE_DECL";
  case XQST0069_STATIC_DUPLICATE_EMPTY_ORDER_DECL:
    return "XQST0069_STATIC_DUPLICATE_EMPTY_ORDER_DECL";
  case XQST0070_STATIC_RESERVED_PREFIX:
    return "XQST0070_STATIC_RESERVED_PREFIX";
  case XQST0071_STATIC_DUPLICATE_NS_ATTRIBUTES:
    return "XQST0071_STATIC_DUPLICATE_NS_ATTRIBUTES";
  case XQDY0072_DYNAMIC_ILLEGAL_HYPHENS:
    return "XQDY0072_DYNAMIC_ILLEGAL_HYPHENS";
  case XQST0073_STATIC_CYCLIC_MODULE_IMPORT:
    return "XQST0073_STATIC_CYCLIC_MODULE_IMPORT";
  case XQDY0074_DYNAMIC_BAD_ELEM_ATTR_QNAME:
    return "XQDY0074_DYNAMIC_BAD_ELEM_ATTR_QNAME";
  case XQST0075_STATIC_VALIDATION_NOT_SUPPORTED:
    return "XQST0075_STATIC_VALIDATION_NOT_SUPPORTED";
  case XQST0076_STATIC_UNRECOGNIZED_COLLATION:
    return "XQST0076_STATIC_UNRECOGNIZED_COLLATION";
  case XQST0079_STATIC_UNRECOGNIZE_EXTENSION_EXPR:
    return "XQST0079_STATIC_UNRECOGNIZE_EXTENSION_EXPR";
  case XPST0080_STATIC_BAD_CAST_EXPR:
    return "XPST0080_STATIC_BAD_CAST_EXPR";
  case XPST0081_STATIC_BAD_QNAME_PREFIX:
    return "XPST0081_STATIC_BAD_QNAME_PREFIX";
  case XQDY0084_DYNAMIC_UNKNOWN_VALIDATED_ELEMENT:
    return "XQDY0084_DYNAMIC_UNKNOWN_VALIDATED_ELEMENT";
  case XQST0085_STATIC_EMPTY_NAMESPACE_URI:
    return "XQST0085_STATIC_EMPTY_NAMESPACE_URI";
  case XQTY0086_TYPE_NODE_COPY_LOOSES_NAMESPACES:
    return "XQTY0086_TYPE_NODE_COPY_LOOSES_NAMESPACES";
  case XQST0087_STATIC_ILLEGAL_ENCODING:
    return "XQST0087_STATIC_ILLEGAL_ENCODING";
  case XQST0088_STATIC_EMPTY_IMPORT_TARGET_NAMESPACE:
    return "XQST0088_STATIC_EMPTY_IMPORT_TARGET_NAMESPACE";
  case XQST0089_STATIC_POSVAR_SHADOW:
    return "XQST0089_STATIC_POSVAR_SHADOW";
  case XQST0090_STATIC_ILLEGAL_CHARREF:
    return "XQST0090_STATIC_ILLEGAL_CHARREF";
  case XQP0001_DYNAMIC_ITERATOR_OVERRUN:
    return "XQP0001_DYNAMIC_ITERATOR_OVERRUN";
  case XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD:
    return "XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD";
  case XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND:
    return "XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND";
  case XQP0005_SYSTEM_ASSERT_FAILED:
    return "Assertion `/s' failed in /s";
  TRIVIAL_ERR (XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED);
  case XQP0004_SYSTEM_NOT_SUPPORTED:
    return "XQP0004_SYSTEM_NOT_SUPPORTED";    
  case XQP0016_LOADER_IO_ERROR:
    return "XQP0016_LOADER_IO_ERROR";
  case XQP0017_LOADER_NOT_WELL_FORMED_XML:
    return "XQP0016_LOADER_NOT_WELL_FORMED_XML \n/s";
  case XQP0018_NODEID_OUT_OF_RANGE:
    return "A nodeid component is too large to be encoded";
  case API0005_COLLECTION_ALREADY_EXISTS:
    return "A collection with URI `/s' exists already";
  case API0006_COLLECTION_NOT_FOUND:
    return "A collection with URI `/s' does not exist";
  case API0007_COLLECTION_ITEM_MUST_BE_A_NODE:
    return "Cannot insert a non-node item to a collection";
    
  case FODC0002_Error_retrieving_resource:
    return "FODC0002_Error_retrieving_resource: Error retrieving resource";

  case FOCH0001_Code_point_not_valid:
    return "Code point not valid.";
  case FOCH0003_Unsupported_normalization_form:
    return "Unsupported normalization form.";
  
  default: return "<Unknown errcode> /s /s";
  }
} 

std::string errors_english::errtype_decode(enum error_type errtype)
{
  switch(errtype)
  {
  case STATIC_ERROR: return "Static";
  case RUNTIME_ERROR: return "Runtime";
  case SYSTEM_ERROR: return "System";
  case USER_ERROR: return "User";
  }

  return "";
}

std::string errors_english::warning_decode(enum warning_code)
{
  return "?";
}

std::string errors_english::notify_event_decode(enum NotifyEvent_code n)
{
  switch(n)
  {
  case NOTIF_EXECUTION_STEP:
    return "Notify execution step: /s /s";
  }
  return "?";
}

std::string errors_english::ask_user_decode(enum AskUserString_code)
{
  return "?";
}

std::string errors_english::ask_user_options_decode(enum AskUserStringOptions_code)
{
  return "";
}

/* Finds next place for param in err_decoded, and puts the param in that place.
 * A place for param looks like "/s".
 */
string::size_type error_messages::ApplyParam(
    string *err_decoded,
    const string *param1,
    string::size_type start)
{
  std::string::size_type off;
  const static string empty;

  off = err_decoded->find ("/s", start);

  if (off == string::npos)
    return err_decoded->length ();

  if (param1 == NULL) param1 = &empty;

  err_decoded->replace (off, 2, *param1);
  return off + param1->length ();
}

void error_messages::ApplyParams(
    string *err_decoded,
    const string *param1,
    const string *param2)
{
  string::size_type off = ApplyParam (err_decoded, param1, 0);
  ApplyParam (err_decoded, param2, off);
}

errors_string_table::errors_string_table( std::string file_name )
{
}

}///end namespace xqp

