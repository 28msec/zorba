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

#include "errors/error_codes.h"

#include <string>

using namespace std;
namespace xqp {


AlertCodes::~AlertCodes()
{  
}


string errors_english::err_decode(enum error_code e)
{
  #define TRIVIAL_ERR( e ) case e: return #e
  switch (e) {
    case XPDY0002:   return "evaluation of an expression relies on some part of the dynamic context that has not been assigned a value.";

    case XPDY0021:  return "(Not currently used.)"; 

    case XPDY0050:  return "The dynamic type of the operand of a treat expression does not match the sequence type specified by the treat expression."; 

    case XPST0001:  return "Analysis of an expression relies on some component of the static context that has not been assigned a value."; 

    case XPST0003:  return "Expression is not a valid instance of the grammar."; 

    case XPST0005:  return "During the analysis phase, it is a static error if the static type assigned to an expression other than the expression () or data(()) is empty-sequence()."; 

    case XPST0008:  return "Expression refers to an element name, attribute name, schema type name, namespace prefix, or variable name that is not defined in the st atic context: /s /s";

    case XPST0010:  return "An implementation must raise a static error if it encounters a reference to an axis that it does not support."; 

    case XPST0017:  return "Expanded QName and number of arguments in function call do not match the name and arity of any function signature in the static context /s / /s";

    case XPST0051:  return "A QName that is used as an AtomicType in a SequenceType is not defined in the in-scope schema types as an atomic type.";
 
    case XPST0080:  return "The target type of a cast or castable expression is xs:NOTATION or xs:anyAtomicType."; 

    case XPST0081:  return "A QName used in a query contains a namespace prefix that cannot be expanded into a namespace URI by using the statically known namespaces."; 

    case XPST0083:  return "(Not currently used.)"; 

    case XPTY0004:  return "During the static analysis phase, an expression is found to have a static type that is not appropriate for the context in which the expression occurs, or during the dynamic evaluation phase, the dynamic type of a value does not match a required type as specified by the matching rules."; 

    case XPTY0006:  return "(Not currently used.)"; 

    case XPTY0007:  return "(Not currently used.)"; 

    case XPTY0018:  return "The result of the last step in a path expression contains both nodes and atomic values."; 

    case XPTY0019:  return "The result of a step (other than the last step) in a path expression contains an atomic value."; 

    case XPTY0020:  return "In an axis step, the context item is not a node."; 

    case XQDY0025:  return "Any attribute of a constructed element does not have a name that is distinct from the names of all other attributes of the constructed element."; 

    case XQDY0026:  return "The result of the content expression of a computed processing instruction constructor contains the string return \"?>\"."; 

    case XQDY0027:  return "In a validate expression, it is a dynamic error if the root element information item in the PSVI resulting from validation does not have the expected validity property: valid if validation mode is strict, or either valid or notKnown if validation mode is lax."; 

    case XQDY0029:  return "(Not currently used.)"; 

    case XQDY0041:  return "The value of the name expression in a computed processing instruction constructor cannot be cast to the type xs:NCName.";
 
    case XQDY0044:  return "The node-name property of the node constructed by a computed attribute constructor is in the namespace http:// www.w3.org/2000/xmlns/ (corresponding to namespace prefix xmlns), or is in no namespace and has local name xmlns.";
 
    case XQDY0052:  return "(Not currently used.)";
 
    case XQDY0061:  return "The operand of a validate expression is a document node whose children do not consist of exactly one element node and zero or more comment and processing instruction nodes, in any order."; 

    case XQDY0062:  return "(Not currently used.)"; 

    case XQDY0064:  return "The value of the name expression in a computed processing instruction constructor is equal to return \"XML\"(in any combination of upper and lower case)."; 

    case XQDY0072:  return "the result of the content expression of a computed comment constructor contains two adjacent hyphens or ends with a hyphen."; 

    case XQDY0074:  return "The value of the name expression in a computed element or attribute constructor cannot be converted to an expanded QName (for example, because it contains a namespace prefix not found in statically known namespaces.) return "; 

    case XQDY0084:  return "The element validated by a validate statement does not have a top-level element declaration in the in-scope element declarations, if validation mode is strict."; 
    case XQDY0091:  return "An implementation MAY raise a dynamic error if an xml:id error, as defined in [XML ID], is encountered during construction of an attribute named xml:id."; 
    case XQDY0092:  return "An implementation MAY raise a dynamic error if a constructed attribute named xml:space has a value other than preserve or default."; 

    case XQST0009:  return "Schema Import Feature not supported.";

    case XQST0012:  return "Error in schema validity."; 

    case XQST0013:  return "Recognized a pragma but determines that its content is invalid."; 

    case XQST0014:  return "(Not currently used.)"; 

    case XQST0015:  return "(Not currently used.)"; 

    case XQST0016:  return "An implementation that does not support the Module Feature raises a static error if it encounters a module declaration or a module import."; 

    case XQST0022:  return "The value of a namespace declaration attribute is not a URILiteral."; 

    case XQST0031:  return "The version number specified in a version declaration is not supported by the implementation.";
 
    case XQST0032:  return "Prolog contains more than one base URI declaration."; 

    case XQST0033:  return "A module contains multiple bindings for the same namespace prefix."; 

    case XQST0034:  return "Duplicate function: /s";

    case XQST0035:  return "Error importing two schema components that both define the same name in the same symbol space and in the same scope."; 

    case XQST0036:  return "Error importing a module if the importing module's in-scope schema types do not include definitions for the schema type names that appear in the declarations of variables and functions (whether in an argument type or return type) that are present in the imported module and are referenced in the importing module."; 

    case XQST0037:  return "(Not currently used.)"; 

    case XQST0038:  return "Prolog contains more than one default collation declaration, or the value specified by a default collation declaration is not present in statically known collations."; 

    case XQST0039:  return "It is a static error for a function declaration to have more than one parameter with the same name."; 

    case XQST0040:  return "The attributes specified by a direct element constructor do not have distinct expanded QNames."; 

    case XQST0042:  return "(Not currently used.)"; 

    case XQST0043:  return "(Not currently used.)"; 

    case XQST0045:  return "Function name '/s' cannot be in one of the following namespaces: http://www.w3.org/XML/1998/namespace, http://www.w3.org/2001/XMLSchema, http://www.w3.org/2001/XMLSchema-instance, http://www.w3.org/2005/xpath-functions";

    case XQST0046:  return "Value of a URILiteral is of nonzero length and is not in the lexical space of xs:anyURI."; 

    case XQST0047:  return "Multiple module imports in the same Prolog specify the same target namespace."; 

    case XQST0048:  return "A function or variable declared in a library module is not in the target namespace of the library module."; 

    case XQST0049:  return "Two or more variables declared or imported by a module have equal expanded QNames (as defined by the eq operator.)"; 

    case XQST0053:  return "(Not currently used.)"; 

    case XQST0054:  return "A variable depends on itself."; 

    case XQST0055:  return "A Prolog contains more than one copy-namespaces declaration."; 
    case XQST0056:  return "(Not currently used.)"; 

    case XQST0057:  return "A schema import binds a namespace prefix but does not specify a target namespace other than a zero-length string."; 

    case XQST0058:  return "Multiple schema imports specify the same target namespace."; 
    case XQST0059:  return "Unable to process a schema or module import by finding a schema or module with the specified target namespace."; 

    case XQST0060:  return "The name of a function in a function declaration is not in a namespace (expanded QName has a null namespace URI).";
 
    case XQST0063:  return "(Not currently used.)"; 

    case XQST0065:  return "Prolog contains more than one ordering mode declaration."; 

    case XQST0066:  return "Prolog contains more than one default element/type namespace declaration, or more than one default function namespace declaration."; 

    case XQST0067:  return "Prolog contains more than one construction declaration."; 

    case XQST0068:  return "Prolog contains more than one boundary-space declaration."; 

    case XQST0069:  return "Prolog contains more than one empty order declaration."; 

    case XQST0070:  return "Namespace URI is bound to a predefined prefix";

    case XQST0071:  return "Namespace declaration attributes of a direct element constructor do not have distinct names."; 

    case XQST0073:  return "The graph of module imports contains a cycle.";

    case XQST0075:  return "An implementation that does not support the Validation Feature must raise a static error if it encounters a validate expression."; 

    case XQST0076:  return "A collation subclause in an order by clause of a FLWOR expression does not identify a collation that is present in statically known collations."; 

    case XQST0077:  return "(Not currently used.)"; 

    case XQST0078:  return "(Not currently used.)"; 

    case XQST0079:  return "An extension expression contains neither a pragma that is recognized by the implementation nor an expression enclosed in curly braces."; 

    case XQST0082:  return "(Not currently used.)"; 

    case XQST0085:  return "The namespace URI in a namespace declaration attribute is a zero-length string, and the implementation does not support [XML Names 1.1]."; 

    case XQST0087:  return "the encoding specified in a Version Declaration does not conform to the definition of EncName specified in [XML 1.0]."; 

    case XQST0088:  return "The literal that specifies the target namespace in a module import or a module declaration is of zero length."; 

    case XQST0089:  return "A variable bound in a for clause of a FLWOR expression, and its associated positional variable, do not have distinct names."; 

    case XQST0090:  return "Xa character reference does not identify a valid character in the version of XML that is in use."; 

    case XQST0093:  return "Static error importing a module.";

    case XQTY0030:  return "The argument of a validate expression does not evaluate to exactly one document or element node."; 

    case XQTY0086:  return "The typed value of a copied element or attribute node is namespace-sensitive when construction mode is preserve and copy-namespaces mode is no-preserve."; 

    case FOER0000: return "Unidentified error."; 

    case FOAR0001: return "Division by zero.";

    case FOAR0002: return "Numeric operation overflow/underflow.";

    case FOCA0001: return "Input value too large for decimal."; 

    case FOCA0002: return "Invalid lexical value."; 

    case FOCA0003: return "Input value too large for integer."; 

    case FOCA0005: return "NaN supplied as float/double value."; 

    case FOCA0006: return "String to be cast to decimal has too many digits of precision."; 

    case FOCH0001: return "Code point not valid."; 

    case FOCH0002: return "Unsupported collation."; 

    case FOCH0003: return "Unsupported normalization form."; 

    case FOCH0004: return "Collation does not support collation units."; 

    case FODC0001: return "No context document."; 

    case FODC0002: return "Error retrieving the resource with uri `/s'.\nReason: `/s'"; 

    case FODC0003: return "Function stability not defined."; 

    case FODC0004: return "Invalid argument to fn:collection."; 

    case FODC0005: return "Invalid argument to fn:doc or fn:doc-available."; 

    case FODT0001: return "Overflow/underflow in date/time operation."; 

    case FODT0002: return "Overflow/underflow in duration operation."; 

    case FODT0003: return "Invalid timezone value."; 

    case FONS0004: return "No namespace found for prefix."; 

    case FONS0005: return "Base-uri not defined in the static context."; 

    case FORG0001: return "Invalid value for cast/constructor."; 

    case FORG0002: return "Invalid argument to fn:resolve-uri()."; 

    case FORG0003: return "fn:zero-or-one called with a sequence containing more than one item."; 

    case FORG0004: return "fn:one-or-more called with a sequence containing no items."; 

    case FORG0005: return "fn:exactly-one called with a sequence containing zero or more than one item."; 

    case FORG0006: return "Invalid argument type."; 

    case FORG0008: return "Both arguments to fn:dateTime have a specified timezone."; 

    case FORG0009: return "Error in resolving a relative URI against a base URI in fn:resolve-uri."; 

    case FORX0001: return "Invalid regular expression. flags"; 

    case FORX0002: return "Invalid regular expression."; 

    case FORX0003: return "Regular expression matches zero-length string."; 

    case FORX0004: return "Invalid replacement string."; 

    case FOTY0012: return "Argument node does not have a typed value."; 

    case XQP0001_DYNAMIC_ITERATOR_OVERRUN: return "XQP0001_DYNAMIC_ITERATOR_OVERRUN";

    case XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD: return "XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD";

    case XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND: return "XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND";

    case XQP0005_SYSTEM_ASSERT_FAILED: return "Assertion `/s' failed in /s";

    TRIVIAL_ERR (XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED);

    case XQP0004_SYSTEM_NOT_SUPPORTED: return "XQP0004_SYSTEM_NOT_SUPPORTED"; 
   
    case XQP0016_LOADER_IO_ERROR: return "XQP0016_LOADER_IO_ERROR";

    case XQP0017_LOADER_NOT_WELL_FORMED_XML: return "XQP0016_LOADER_NOT_WELL_FORMED_XML \n/s";

    case XQP0018_NODEID_OUT_OF_RANGE: return "A nodeid component is too large to be encoded";

    case API0005_COLLECTION_ALREADY_EXISTS: return "A collection with URI `/s' exists already";

    case API0006_COLLECTION_NOT_FOUND: return "A collection with URI `/s' does not exist";

    case API0007_COLLECTION_ITEM_MUST_BE_A_NODE: return "Cannot insert a non-node item to a collection";

    case API0008: return "A document with URI `/s' exists already";

    default: return "<Unknown errcode> /s /s";
  }
} 


std::string errors_english::errtype_decode(enum error_type errtype)
{
  switch(errtype)
  {
  case STATIC_ERROR: return "Static";
  case RUNTIME_ERROR: return "Runtime";
  case TYPE_ERROR: return "Type";
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
string::size_type AlertCodes::ApplyParam(
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


void AlertCodes::ApplyParams(
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

