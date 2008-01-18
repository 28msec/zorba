
#include "errors/error_messages.h"
#include "util/Assert.h"
#include "util/utf8/Unicode_util.h"

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

static const char *canonical_err_names[ZorbaError::MAX_ZORBA_ERROR_CODE + 1];
static const char *err_msg[ZorbaError::MAX_ZORBA_ERROR_CODE + 1];


static struct err_msg_initializer 
{
  err_msg_initializer () 
  {
#define DEF_ERR_CODE( code, name, msg ) canonical_err_names [ ZorbaError::code ] = #name; err_msg [ZorbaError::code] = msg;

    for (int i = 0; i < ZorbaError::MAX_ZORBA_ERROR_CODE; i++) {
      canonical_err_names [i] = NULL;
      err_msg [i] = NULL;
    }

DEF_ERR_CODE (API0005_COLLECTION_ALREADY_EXISTS, API0005, "A collection with URI `/s' exists already")
DEF_ERR_CODE (API0006_COLLECTION_NOT_FOUND, API0006, "A collection with URI `/s' does not exist")
DEF_ERR_CODE (API0007_COLLECTION_ITEM_MUST_BE_A_NODE, API0007, "Cannot insert a non-node item to a collection")
DEF_ERR_CODE (API0008, API0008, "A document with URI `/s' exists already")
DEF_ERR_CODE (FOAR0001, FOAR0001, "Division by zero.")
DEF_ERR_CODE (FOAR0002, FOAR0002, "Numeric operation overflow/underflow.")
DEF_ERR_CODE (FOCA0001, FOCA0001, "Input value too large for decimal.")
DEF_ERR_CODE (FOCA0002, FOCA0002, "Invalid lexical value.")
DEF_ERR_CODE (FOCA0003, FOCA0003, "Input value too large for integer.")
DEF_ERR_CODE (FOCA0005, FOCA0005, "NaN supplied as float/double value.")
DEF_ERR_CODE (FOCA0006, FOCA0006, "String to be cast to decimal has too many digits of precision.")
DEF_ERR_CODE (FOCH0001, FOCH0001, "Code point not valid.")
DEF_ERR_CODE (FOCH0002, FOCH0002, "Unsupported collation.")
DEF_ERR_CODE (FOCH0003, FOCH0003, "Unsupported normalization form.")
DEF_ERR_CODE (FOCH0004, FOCH0004, "Collation does not support collation units.")
DEF_ERR_CODE (FODC0001, FODC0001, "No context document.")
DEF_ERR_CODE (FODC0002, FODC0002, "Error retrieving the resource with uri `/s'.\nReason: `/s'")
DEF_ERR_CODE (FODC0003, FODC0003, "Function stability not defined.")
DEF_ERR_CODE (FODC0004, FODC0004, "Invalid argument to fn:collection.")
DEF_ERR_CODE (FODC0005, FODC0005, "Invalid argument to fn:doc or fn:doc-available.")
DEF_ERR_CODE (FODT0001, FODT0001, "Overflow/underflow in date/time operation.")
DEF_ERR_CODE (FODT0002, FODT0002, "Overflow/underflow in duration operation.")
DEF_ERR_CODE (FODT0003, FODT0003, "Invalid timezone value.")
DEF_ERR_CODE (FOER0000, FOER0000, "Unidentified error.")
DEF_ERR_CODE (FONS0004, FONS0004, "No namespace found for prefix.")
DEF_ERR_CODE (FONS0005, FONS0005, "Base-uri not defined in the static context.")
DEF_ERR_CODE (FORG0001, FORG0001, "Invalid value for cast/constructor.")
DEF_ERR_CODE (FORG0002, FORG0002, "Invalid argument to fn:resolve-uri().")
DEF_ERR_CODE (FORG0003, FORG0003, "fn:zero-or-one called with a sequence containing more than one item.")
DEF_ERR_CODE (FORG0004, FORG0004, "fn:one-or-more called with a sequence containing no items.")
DEF_ERR_CODE (FORG0005, FORG0005, "fn:exactly-one called with a sequence containing zero or more than one item.")
DEF_ERR_CODE (FORG0006, FORG0006, "Invalid argument type.")
DEF_ERR_CODE (FORG0006, FORG0006, "Invalid argument type.")
DEF_ERR_CODE (FORG0008, FORG0008, "Both arguments to fn:dateTime have a specified timezone.")
DEF_ERR_CODE (FORG0009, FORG0009, "Error in resolving a relative URI against a base URI in fn:resolve-uri.")
DEF_ERR_CODE (FORX0001, FORX0001, "Invalid regular expression. flags")
DEF_ERR_CODE (FORX0002, FORX0002, "Invalid regular expression.")
DEF_ERR_CODE (FORX0003, FORX0003, "Regular expression matches zero-length string.")
DEF_ERR_CODE (FORX0004, FORX0004, "Invalid replacement string.")
DEF_ERR_CODE (FOTY0012, FOTY0012, "Argument node does not have a typed value.")
DEF_ERR_CODE (XPDY0002, XPDY0002, "evaluation of an expression relies on some part of the dynamic context that has not been assigned a value: /s.")
DEF_ERR_CODE (XPDY0050, XPDY0050, "The dynamic type of the operand of a treat expression does not match the sequence type specified by the treat expression.")
DEF_ERR_CODE (XPST0001, XPST0001, "Analysis of an expression relies on some component of the static context that has not been assigned a value /s")
DEF_ERR_CODE (XPST0003, XPST0003, "Expression is not a valid instance of the grammar.")
DEF_ERR_CODE (XPST0005, XPST0005, "During the analysis phase, it is a static error if the static type assigned to an expression other than the expression () or data(()) is empty-sequence().")
DEF_ERR_CODE (XPST0008, XPST0008, "Expression refers to an element name, attribute name, schema type name, namespace prefix, or variable name that is not defined in the static context: /s /s")
DEF_ERR_CODE (XPST0010, XPST0010, "An implementation must raise a static error if it encounters a reference to an axis that it does not support.")
DEF_ERR_CODE (XPST0017, XPST0017, "Expanded QName and number of arguments in function call do not match the name and arity of any function signature in the static context /s / /s")
DEF_ERR_CODE (XPST0051, XPST0051, "A QName that is used as an AtomicType in a SequenceType is not defined in the in-scope schema types as an atomic type.")
DEF_ERR_CODE (XPST0080, XPST0080, "The target type of a cast or castable expression is xs:NOTATION or xs:anyAtomicType.")
DEF_ERR_CODE (XPST0081, XPST0081, "A QName used in a query contains a namespace prefix that cannot be expanded into a namespace URI by using the statically known namespaces.")
DEF_ERR_CODE (XPTY0004, XPTY0004, "During the static analysis phase, an expression is found to have a static type that is not appropriate for the context in which the expression occurs, or during the dynamic evaluation phase, the dynamic type of a value does not match a required type as specified by the matching rules: /s")
DEF_ERR_CODE (XPTY0018, XPTY0018, "The result of the last step in a path expression contains both nodes and atomic values.")
DEF_ERR_CODE (XPTY0019, XPTY0019, "The result of a step (other than the last step) in a path expression contains an atomic value.")
DEF_ERR_CODE (XPTY0020, XPTY0020, "In an axis step, the context item is not a node.")
DEF_ERR_CODE (XQDY0025, XQDY0025, "Any attribute of a constructed element does not have a name that is distinct from the names of all other attributes of the constructed element.")
DEF_ERR_CODE (XQDY0026, XQDY0026, "The result of the content expression of a computed processing instruction constructor contains the string return \"?>\".")
DEF_ERR_CODE (XQDY0027, XQDY0027, "In a validate expression, it is a dynamic error if the root element information item in the PSVI resulting from validation does not have the expected validity property: valid if validation mode is strict, or either valid or notKnown if validation mode is lax.")
DEF_ERR_CODE (XQDY0041, XQDY0041, "The value of the name expression in a computed processing instruction constructor cannot be cast to the type xs:NCName.")
DEF_ERR_CODE (XQDY0044, XQDY0044, "The node-name property of the node constructed by a computed attribute constructor is in the namespace http:// www.w3.org/2000/xmlns/ (corresponding to namespace prefix xmlns), or is in no namespace and has local name xmlns.")
DEF_ERR_CODE (XQDY0061, XQDY0061, "The operand of a validate expression is a document node whose children do not consist of exactly one element node and zero or more comment and processing instruction nodes, in any order.")
DEF_ERR_CODE (XQDY0064, XQDY0064, "The value of the name expression in a computed processing instruction constructor is equal to return \"XML\"(in any combination of upper and lower case).")
DEF_ERR_CODE (XQDY0072, XQDY0072, "the result of the content expression of a computed comment constructor contains two adjacent hyphens or ends with a hyphen.")
DEF_ERR_CODE (XQDY0074, XQDY0074, "The value of the name expression in a computed element or attribute constructor cannot be converted to an expanded QName (for example, because it contains a namespace prefix not found in statically known namespaces.) return ")
DEF_ERR_CODE (XQDY0084, XQDY0084, "The element validated by a validate statement does not have a top-level element declaration in the in-scope element declarations, if validation mode is strict.")
DEF_ERR_CODE (XQP0001_DYNAMIC_ITERATOR_OVERRUN, XQP0001, "XQP0001_DYNAMIC_ITERATOR_OVERRUN")
DEF_ERR_CODE (XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD, XQP0002, "XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD")
DEF_ERR_CODE (XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND, XQP0003, "XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND")
DEF_ERR_CODE (XQP0004_SYSTEM_NOT_SUPPORTED, XQP0004, "/s not implemented or not supported")
DEF_ERR_CODE (XQP0005_SYSTEM_ASSERT_FAILED, XQP0005, "Assertion `/s' failed in /s")
DEF_ERR_CODE (XQP0016_LOADER_IO_ERROR, XQP0016, "XQP0016_LOADER_IO_ERROR")
DEF_ERR_CODE (XQP0017_LOADER_NOT_WELL_FORMED_XML, XQP0017, "XQP0016_LOADER_NOT_WELL_FORMED_XML \n/s")
DEF_ERR_CODE (XQP0018_NODEID_OUT_OF_RANGE, XQP0018, "A nodeid component is too large to be encoded")
DEF_ERR_CODE (XQST0009, XQST0009, "Schema Import Feature not supported.")
DEF_ERR_CODE (XQST0012, XQST0012, "Error in schema validity.")
DEF_ERR_CODE (XQST0013, XQST0013, "Recognized a pragma but determines that its content is invalid.")
DEF_ERR_CODE (XQST0016, XQST0016, "An implementation that does not support the Module Feature raises a static error if it encounters a module declaration or a module import.")
DEF_ERR_CODE (XQST0022, XQST0022, "The value of a namespace declaration attribute is not a URILiteral.")
DEF_ERR_CODE (XQST0031, XQST0031, "The version number specified in a version declaration is not supported by the implementation.")
DEF_ERR_CODE (XQST0032, XQST0032, "Prolog contains more than one base URI declaration.")
DEF_ERR_CODE (XQST0033, XQST0033, "A module contains multiple bindings for the same namespace prefix.")
DEF_ERR_CODE (XQST0034, XQST0034, "Duplicate function: /s")
DEF_ERR_CODE (XQST0035, XQST0035, "Error importing two schema components that both define the same name in the same symbol space and in the same scope.")
DEF_ERR_CODE (XQST0036, XQST0036, "Error importing a module if the importing module's in-scope schema types do not include definitions for the schema type names that appear in the declarations of variables and functions (whether in an argument type or return type) that are present in the imported module and are referenced in the importing module.")
DEF_ERR_CODE (XQST0038, XQST0038, "Prolog contains more than one default collation declaration, or the value specified by a default collation declaration is not present in statically known collations.")
DEF_ERR_CODE (XQST0039, XQST0039, "It is a static error for a function declaration to have more than one parameter with the same name.")
DEF_ERR_CODE (XQST0040, XQST0040, "The attributes specified by a direct element constructor do not have distinct expanded QNames.")
DEF_ERR_CODE (XQST0045, XQST0045, "Function name '/s' cannot be in one of the following namespaces: http://www.w3.org/XML/1998/namespace, http://www.w3.org/2001/XMLSchema, http://www.w3.org/2001/XMLSchema-instance, http://www.w3.org/2005/xpath-functions")
DEF_ERR_CODE (XQST0046, XQST0046, "Value of a URILiteral is of nonzero length and is not in the lexical space of xs:anyURI.")
DEF_ERR_CODE (XQST0047, XQST0047, "Multiple module imports in the same Prolog specify the same target namespace.")
DEF_ERR_CODE (XQST0048, XQST0048, "A function or variable declared in a library module is not in the target namespace of the library module.")
DEF_ERR_CODE (XQST0049, XQST0049, "Two or more variables declared or imported by a module have equal expanded QNames (as defined by the eq operator.)")
DEF_ERR_CODE (XQST0054, XQST0054, "A variable depends on itself.")
DEF_ERR_CODE (XQST0055, XQST0055, "A Prolog contains more than one copy-namespaces declaration.")
DEF_ERR_CODE (XQST0057, XQST0057, "A schema import binds a namespace prefix but does not specify a target namespace other than a zero-length string.")
DEF_ERR_CODE (XQST0058, XQST0058, "Multiple schema imports specify the same target namespace.")
DEF_ERR_CODE (XQST0059, XQST0059, "Unable to process a schema or module import by finding a schema or module with the specified target namespace.")
DEF_ERR_CODE (XQST0060, XQST0060, "The name of a function in a function declaration is not in a namespace (expanded QName has a null namespace URI).")
DEF_ERR_CODE (XQST0065, XQST0065, "Prolog contains more than one ordering mode declaration.")
DEF_ERR_CODE (XQST0066, XQST0066, "Prolog contains more than one default element/type namespace declaration, or more than one default function namespace declaration.")
DEF_ERR_CODE (XQST0067, XQST0067, "Prolog contains more than one construction declaration.")
DEF_ERR_CODE (XQST0068, XQST0068, "Prolog contains more than one boundary-space declaration.")
DEF_ERR_CODE (XQST0069, XQST0069, "Prolog contains more than one empty order declaration.")
DEF_ERR_CODE (XQST0070, XQST0070, "Namespace URI is bound to a predefined prefix")
DEF_ERR_CODE (XQST0071, XQST0071, "Namespace declaration attributes of a direct element constructor do not have distinct names.")
DEF_ERR_CODE (XQST0073, XQST0073, "The graph of module imports contains a cycle.")
DEF_ERR_CODE (XQST0075, XQST0075, "An implementation that does not support the Validation Feature must raise a static error if it encounters a validate expression.")
DEF_ERR_CODE (XQST0076, XQST0076, "A collation subclause in an order by clause of a FLWOR expression does not identify a collation that is present in statically known collations.")
DEF_ERR_CODE (XQST0079, XQST0079, "An extension expression contains neither a pragma that is recognized by the implementation nor an expression enclosed in curly braces.")
DEF_ERR_CODE (XQST0085, XQST0085, "The namespace URI in a namespace declaration attribute is a zero-length string, and the implementation does not support [XML Names 1.1].")
DEF_ERR_CODE (XQST0087, XQST0087, "the encoding specified in a Version Declaration does not conform to the definition of EncName specified in [XML 1.0].")
DEF_ERR_CODE (XQST0088, XQST0088, "The literal that specifies the target namespace in a module import or a module declaration is of zero length.")
DEF_ERR_CODE (XQST0089, XQST0089, "A variable bound in a for clause of a FLWOR expression, and its associated positional variable, do not have distinct names.")
DEF_ERR_CODE (XQST0090, XQST0090, "Xa character reference does not identify a valid character in the version of XML that is in use.")
DEF_ERR_CODE (XQTY0030, XQTY0030, "The argument of a validate expression does not evaluate to exactly one document or element node.")
DEF_ERR_CODE (XQTY0086, XQTY0086, "The typed value of a copied element or attribute node is namespace-sensitive when construction mode is preserve and copy-namespaces mode is no-preserve.")
DEF_ERR_CODE (XQTY0024, XQTY0024, "It is a type error if the content sequence in an element constructor contains an attribute node following a node that is not an attribute node.")
DEF_ERR_CODE (XQP0019_INTERNAL_ERROR, XQP0019, "Zorba internal error /s")

#undef DEF_ERR_CODE

  for (int i = 0; i < ZorbaError::MAX_ZORBA_ERROR_CODE; i++) {
    if (canonical_err_names [i] == NULL)
      canonical_err_names [i] = "?";
    if (err_msg [i] == NULL)
      err_msg [i] = strdup (string ("<Unknown errcode " + to_string (i) + "> /s /s").c_str ());
  }


  }
} err_msg_initializer_obj;

std::string ZorbaError::toString(ZorbaError::ErrorCodes code) {
  ZORBA_ASSERT (code < ZorbaError::MAX_ZORBA_ERROR_CODE);
  return canonical_err_names[code];
}

string AlertMessagesEnglish::error_decode(ZorbaError::ErrorCodes e) {
  ZORBA_ASSERT (e < ZorbaError::MAX_ZORBA_ERROR_CODE);
  return err_msg [e];
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

