
#include "errors/error_messages.h"

#include <string>

using namespace std;

namespace xqp
{


/*******************************************************************************

********************************************************************************/
void AlertMessages::applyParams(
    string*       errorMsg,
    const string* param1,
    const string* param2)
{
  string::size_type off = applyParam(errorMsg, param1, 0);
  applyParam(errorMsg, param2, off);
}


/*******************************************************************************
  Finds next place for param in err_decoded, and puts the param in that place.
  A place for param looks like "/s".
********************************************************************************/
string::size_type AlertMessages::applyParam(
    string*           errorMsg,
    const string*     param1,
    string::size_type start)
{
  std::string::size_type off;
  const static string empty;

  off = errorMsg->find ("/s", start);

  if (off == string::npos)
    return errorMsg->length ();

  if (param1 == NULL) param1 = &empty;

  errorMsg->replace (off, 2, *param1);
  return off + param1->length ();
}


/*******************************************************************************

********************************************************************************/
string AlertMessagesEnglish::error_decode(ZorbaError::ErrorCodes e)
{
  switch (e)
  {
  case ZorbaError::XPDY0002:  return "evaluation of an expression relies on some part of the dynamic context that has not been assigned a value: /s.";

  case ZorbaError::XPDY0021:  return "(Not currently used.)"; 

  case ZorbaError::XPDY0050:  return "The dynamic type of the operand of a treat expression does not match the sequence type specified by the treat expression."; 

  case ZorbaError::XPST0001:  return "Analysis of an expression relies on some component of the static context that has not been assigned a value."; 

  case ZorbaError::XPST0003:  return "Expression is not a valid instance of the grammar."; 

  case ZorbaError::XPST0005:  return "During the analysis phase, it is a static error if the static type assigned to an expression other than the expression () or data(()) is empty-sequence()."; 

  case ZorbaError::XPST0008:  return "Expression refers to an element name, attribute name, schema type name, namespace prefix, or variable name that is not defined in the static context: /s /s";

  case ZorbaError::XPST0010:  return "An implementation must raise a static error if it encounters a reference to an axis that it does not support."; 

  case ZorbaError::XPST0017:  return "Expanded QName and number of arguments in function call do not match the name and arity of any function signature in the static context /s / /s";

  case ZorbaError::XPST0051:  return "A QName that is used as an AtomicType in a SequenceType is not defined in the in-scope schema types as an atomic type.";
 
  case ZorbaError::XPST0080:  return "The target type of a cast or castable expression is xs:NOTATION or xs:anyAtomicType."; 

  case ZorbaError::XPST0081:  return "A QName used in a query contains a namespace prefix that cannot be expanded into a namespace URI by using the statically known namespaces."; 

  case ZorbaError::XPST0083:  return "(Not currently used.)"; 

  case ZorbaError::XPTY0004:  return "During the static analysis phase, an expression is found to have a static type that is not appropriate for the context in which the expression occurs, or during the dynamic evaluation phase, the dynamic type of a value does not match a required type as specified by the matching rules: /s"; 

  case ZorbaError::XPTY0006:  return "(Not currently used.)"; 

  case ZorbaError::XPTY0007:  return "(Not currently used.)"; 

  case ZorbaError::XPTY0018:  return "The result of the last step in a path expression contains both nodes and atomic values."; 

  case ZorbaError::XPTY0019:  return "The result of a step (other than the last step) in a path expression contains an atomic value."; 

  case ZorbaError::XPTY0020:  return "In an axis step, the context item is not a node."; 

  case ZorbaError::XQDY0025:  return "Any attribute of a constructed element does not have a name that is distinct from the names of all other attributes of the constructed element."; 

  case ZorbaError::XQDY0026:  return "The result of the content expression of a computed processing instruction constructor contains the string return \"?>\"."; 

  case ZorbaError::XQDY0027:  return "In a validate expression, it is a dynamic error if the root element information item in the PSVI resulting from validation does not have the expected validity property: valid if validation mode is strict, or either valid or notKnown if validation mode is lax."; 

  case ZorbaError::XQDY0029:  return "(Not currently used.)"; 

  case ZorbaError::XQDY0041:  return "The value of the name expression in a computed processing instruction constructor cannot be cast to the type xs:NCName.";
 
  case ZorbaError::XQDY0044:  return "The node-name property of the node constructed by a computed attribute constructor is in the namespace http:// www.w3.org/2000/xmlns/ (corresponding to namespace prefix xmlns), or is in no namespace and has local name xmlns.";
 
  case ZorbaError::XQDY0052:  return "(Not currently used.)";
 
  case ZorbaError::XQDY0061:  return "The operand of a validate expression is a document node whose children do not consist of exactly one element node and zero or more comment and processing instruction nodes, in any order."; 

  case ZorbaError::XQDY0062:  return "(Not currently used.)"; 

  case ZorbaError::XQDY0064:  return "The value of the name expression in a computed processing instruction constructor is equal to return \"XML\"(in any combination of upper and lower case)."; 

  case ZorbaError::XQDY0072:  return "the result of the content expression of a computed comment constructor contains two adjacent hyphens or ends with a hyphen."; 

  case ZorbaError::XQDY0074:  return "The value of the name expression in a computed element or attribute constructor cannot be converted to an expanded QName (for example, because it contains a namespace prefix not found in statically known namespaces.) return "; 

  case ZorbaError::XQDY0084:  return "The element validated by a validate statement does not have a top-level element declaration in the in-scope element declarations, if validation mode is strict."; 
  case ZorbaError::XQDY0091:  return "An implementation MAY raise a dynamic error if an xml:id error, as defined in [XML ID], is encountered during construction of an attribute named xml:id."; 
  case ZorbaError::XQDY0092:  return "An implementation MAY raise a dynamic error if a constructed attribute named xml:space has a value other than preserve or default."; 

  case ZorbaError::XQST0009:  return "Schema Import Feature not supported.";

  case ZorbaError::XQST0012:  return "Error in schema validity."; 

  case ZorbaError::XQST0013:  return "Recognized a pragma but determines that its content is invalid."; 

  case ZorbaError::XQST0014:  return "(Not currently used.)"; 

  case ZorbaError::XQST0015:  return "(Not currently used.)"; 

  case ZorbaError::XQST0016:  return "An implementation that does not support the Module Feature raises a static error if it encounters a module declaration or a module import."; 

  case ZorbaError::XQST0022:  return "The value of a namespace declaration attribute is not a URILiteral."; 

  case ZorbaError::XQST0031:  return "The version number specified in a version declaration is not supported by the implementation.";
 
  case ZorbaError::XQST0032:  return "Prolog contains more than one base URI declaration."; 

  case ZorbaError::XQST0033:  return "A module contains multiple bindings for the same namespace prefix."; 

  case ZorbaError::XQST0034:  return "Duplicate function: /s";

  case ZorbaError::XQST0035:  return "Error importing two schema components that both define the same name in the same symbol space and in the same scope."; 

  case ZorbaError::XQST0036:  return "Error importing a module if the importing module's in-scope schema types do not include definitions for the schema type names that appear in the declarations of variables and functions (whether in an argument type or return type) that are present in the imported module and are referenced in the importing module."; 

  case ZorbaError::XQST0037:  return "(Not currently used.)"; 

  case ZorbaError::XQST0038:  return "Prolog contains more than one default collation declaration, or the value specified by a default collation declaration is not present in statically known collations."; 

  case ZorbaError::XQST0039:  return "It is a static error for a function declaration to have more than one parameter with the same name."; 

  case ZorbaError::XQST0040:  return "The attributes specified by a direct element constructor do not have distinct expanded QNames."; 

  case ZorbaError::XQST0042:  return "(Not currently used.)"; 

  case ZorbaError::XQST0043:  return "(Not currently used.)"; 

  case ZorbaError::XQST0045:  return "Function name '/s' cannot be in one of the following namespaces: http://www.w3.org/XML/1998/namespace, http://www.w3.org/2001/XMLSchema, http://www.w3.org/2001/XMLSchema-instance, http://www.w3.org/2005/xpath-functions";

  case ZorbaError::XQST0046:  return "Value of a URILiteral is of nonzero length and is not in the lexical space of xs:anyURI."; 

  case ZorbaError::XQST0047:  return "Multiple module imports in the same Prolog specify the same target namespace."; 

  case ZorbaError::XQST0048:  return "A function or variable declared in a library module is not in the target namespace of the library module."; 

  case ZorbaError::XQST0049:  return "Two or more variables declared or imported by a module have equal expanded QNames (as defined by the eq operator.)"; 

  case ZorbaError::XQST0053:  return "(Not currently used.)"; 

  case ZorbaError::XQST0054:  return "A variable depends on itself."; 

  case ZorbaError::XQST0055:  return "A Prolog contains more than one copy-namespaces declaration."; 

  case ZorbaError::XQST0056:  return "(Not currently used.)"; 

  case ZorbaError::XQST0057:  return "A schema import binds a namespace prefix but does not specify a target namespace other than a zero-length string."; 

  case ZorbaError::XQST0058:  return "Multiple schema imports specify the same target namespace."; 

  case ZorbaError::XQST0059:  return "Unable to process a schema or module import by finding a schema or module with the specified target namespace."; 

  case ZorbaError::XQST0060:  return "The name of a function in a function declaration is not in a namespace (expanded QName has a null namespace URI).";
 
  case ZorbaError::XQST0063:  return "(Not currently used.)"; 

  case ZorbaError::XQST0065:  return "Prolog contains more than one ordering mode declaration."; 

  case ZorbaError::XQST0066:  return "Prolog contains more than one default element/type namespace declaration, or more than one default function namespace declaration."; 

  case ZorbaError::XQST0067:  return "Prolog contains more than one construction declaration."; 

  case ZorbaError::XQST0068:  return "Prolog contains more than one boundary-space declaration."; 

  case ZorbaError::XQST0069:  return "Prolog contains more than one empty order declaration."; 

  case ZorbaError::XQST0070:  return "Namespace URI is bound to a predefined prefix";

  case ZorbaError::XQST0071:  return "Namespace declaration attributes of a direct element constructor do not have distinct names."; 

  case ZorbaError::XQST0073:  return "The graph of module imports contains a cycle.";

  case ZorbaError::XQST0075:  return "An implementation that does not support the Validation Feature must raise a static error if it encounters a validate expression."; 

  case ZorbaError::XQST0076:  return "A collation subclause in an order by clause of a FLWOR expression does not identify a collation that is present in statically known collations."; 

  case ZorbaError::XQST0077:  return "(Not currently used.)"; 

  case ZorbaError::XQST0078:  return "(Not currently used.)"; 

  case ZorbaError::XQST0079:  return "An extension expression contains neither a pragma that is recognized by the implementation nor an expression enclosed in curly braces."; 

  case ZorbaError::XQST0082:  return "(Not currently used.)"; 

  case ZorbaError::XQST0085:  return "The namespace URI in a namespace declaration attribute is a zero-length string, and the implementation does not support [XML Names 1.1]."; 

  case ZorbaError::XQST0087:  return "the encoding specified in a Version Declaration does not conform to the definition of EncName specified in [XML 1.0]."; 

  case ZorbaError::XQST0088:  return "The literal that specifies the target namespace in a module import or a module declaration is of zero length."; 

  case ZorbaError::XQST0089:  return "A variable bound in a for clause of a FLWOR expression, and its associated positional variable, do not have distinct names."; 

  case ZorbaError::XQST0090:  return "Xa character reference does not identify a valid character in the version of XML that is in use."; 

  case ZorbaError::XQST0093:  return "Static error importing a module.";

  case ZorbaError::XQTY0030:  return "The argument of a validate expression does not evaluate to exactly one document or element node."; 

  case ZorbaError::XQTY0086:  return "The typed value of a copied element or attribute node is namespace-sensitive when construction mode is preserve and copy-namespaces mode is no-preserve."; 

  case ZorbaError::FOER0000: return "Unidentified error."; 

  case ZorbaError::FOAR0001: return "Division by zero.";

  case ZorbaError::FOAR0002: return "Numeric operation overflow/underflow.";

  case ZorbaError::FOCA0001: return "Input value too large for decimal."; 

  case ZorbaError::FOCA0002: return "Invalid lexical value."; 

  case ZorbaError::FOCA0003: return "Input value too large for integer."; 

  case ZorbaError::FOCA0005: return "NaN supplied as float/double value."; 

  case ZorbaError::FOCA0006: return "String to be cast to decimal has too many digits of precision."; 

  case ZorbaError::FOCH0001: return "Code point not valid."; 

  case ZorbaError::FOCH0002: return "Unsupported collation."; 

  case ZorbaError::FOCH0003: return "Unsupported normalization form."; 

  case ZorbaError::FOCH0004: return "Collation does not support collation units."; 

  case ZorbaError::FODC0001: return "No context document."; 

  case ZorbaError::FODC0002: return "Error retrieving the resource with uri `/s'.\nReason: `/s'"; 

  case ZorbaError::FODC0003: return "Function stability not defined."; 

  case ZorbaError::FODC0004: return "Invalid argument to fn:collection."; 

  case ZorbaError::FODC0005: return "Invalid argument to fn:doc or fn:doc-available."; 

  case ZorbaError::FODT0001: return "Overflow/underflow in date/time operation."; 

  case ZorbaError::FODT0002: return "Overflow/underflow in duration operation."; 

  case ZorbaError::FODT0003: return "Invalid timezone value."; 
      
  case ZorbaError::FONS0004: return "No namespace found for prefix."; 

  case ZorbaError::FONS0005: return "Base-uri not defined in the static context."; 

  case ZorbaError::FORG0001: return "Invalid value for cast/constructor."; 

  case ZorbaError::FORG0002: return "Invalid argument to fn:resolve-uri()."; 

  case ZorbaError::FORG0003: return "fn:zero-or-one called with a sequence containing more than one item."; 

  case ZorbaError::FORG0004: return "fn:one-or-more called with a sequence containing no items."; 

  case ZorbaError::FORG0005: return "fn:exactly-one called with a sequence containing zero or more than one item."; 

  case ZorbaError::FORG0006: return "Invalid argument type."; 

  case ZorbaError::FORG0008: return "Both arguments to fn:dateTime have a specified timezone."; 

  case ZorbaError::FORG0009: return "Error in resolving a relative URI against a base URI in fn:resolve-uri."; 

  case ZorbaError::FORX0001: return "Invalid regular expression. flags"; 

  case ZorbaError::FORX0002: return "Invalid regular expression."; 

  case ZorbaError::FORX0003: return "Regular expression matches zero-length string."; 

  case ZorbaError::FORX0004: return "Invalid replacement string."; 

  case ZorbaError::FOTY0012: return "Argument node does not have a typed value."; 

  case ZorbaError::XQP0001_DYNAMIC_ITERATOR_OVERRUN: return "XQP0001_DYNAMIC_ITERATOR_OVERRUN";

  case ZorbaError::XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD: return "XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD";

  case ZorbaError::XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND: return "XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND";

  case ZorbaError::XQP0005_SYSTEM_ASSERT_FAILED: return "Assertion `/s' failed in /s";

  case ZorbaError::XQP0004_SYSTEM_NOT_SUPPORTED: return "/s not implemented or not supported";
   
  case ZorbaError::XQP0016_LOADER_IO_ERROR: return "XQP0016_LOADER_IO_ERROR";

  case ZorbaError::XQP0017_LOADER_NOT_WELL_FORMED_XML: return "XQP0016_LOADER_NOT_WELL_FORMED_XML \n/s";

  case ZorbaError::XQP0018_NODEID_OUT_OF_RANGE: return "A nodeid component is too large to be encoded";

  case ZorbaError::API0005_COLLECTION_ALREADY_EXISTS: return "A collection with URI `/s' exists already";

  case ZorbaError::API0006_COLLECTION_NOT_FOUND: return "A collection with URI `/s' does not exist";

  case ZorbaError::API0007_COLLECTION_ITEM_MUST_BE_A_NODE: return "Cannot insert a non-node item to a collection";

  case ZorbaError::API0008: return "A document with URI `/s' exists already";

  default: return "<Unknown errcode> /s /s";
  }
} 


std::string AlertMessagesEnglish::warning_decode(ZorbaWarning::WarningCodes code)
{
  return "?";
}


std::string AlertMessagesEnglish::notify_event_decode(ZorbaNotify::NotifyCodes code)
{
  switch(code)
  {
  case ZorbaNotify::NOTIF_EXECUTION_STEP:
    return "Notify execution step: /s /s";
  }
  return "?";
}


std::string AlertMessagesEnglish::ask_user_decode(ZorbaAskUser::UserQuestionCodes)
{
  return "?";
}


std::string AlertMessagesEnglish::ask_user_options_decode(ZorbaAskUser::UserReplyOptionsCodes)
{
  return "";
}



AlertMessagesTable::AlertMessagesTable(std::string file_name)
{
}

}///end namespace xqp

