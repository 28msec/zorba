#include <string>

#include "zorbatypes/Unicode_util.h"
#include "util/Assert.h"

#include <zorba/error.h>
#include "errors/error_messages.h"

using namespace std;

namespace zorba { namespace error {


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
  string::size_type off;
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

static const char *canonical_err_names[::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE + 1];
static const char *err_msg[::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE + 1];


static struct err_msg_initializer 
{
  err_msg_initializer () 
  {
#define DEF_ERR_CODE( code, name, msg ) canonical_err_names [ ::zorba::ZorbaError::code ] = strdup(#name); err_msg [::zorba::ZorbaError::code] = strdup(msg);

    for (int i = 0; i < ::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE; i++) {
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
DEF_ERR_CODE (FOCH0001, FOCH0001, "Code point not valid: /s.")
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
DEF_ERR_CODE (FORG0001, FORG0001, "Invalid value for cast/constructor. Reason: /s")
DEF_ERR_CODE (FORG0002, FORG0002, "Invalid argument to fn:resolve-uri().")
DEF_ERR_CODE (FORG0003, FORG0003, "fn:zero-or-one called with a sequence containing more than one item.")
DEF_ERR_CODE (FORG0004, FORG0004, "fn:one-or-more called with a sequence containing no items.")
DEF_ERR_CODE (FORG0005, FORG0005, "fn:exactly-one called with a sequence containing zero or more than one item.")
DEF_ERR_CODE (FORG0006, FORG0006, "Invalid argument type.")
DEF_ERR_CODE (FORG0008, FORG0008, "Both arguments to fn:dateTime have a specified timezone.")
DEF_ERR_CODE (FORG0009, FORG0009, "Error in resolving a relative URI against a base URI in fn:resolve-uri.")
DEF_ERR_CODE (FORX0001, FORX0001, "Invalid regular expression. flags")
DEF_ERR_CODE (FORX0002, FORX0002, "Invalid regular expression.")
DEF_ERR_CODE (FORX0003, FORX0003, "Regular expression matches zero-length string.")
DEF_ERR_CODE (FORX0004, FORX0004, "Invalid replacement string.")
DEF_ERR_CODE (FOTY0012, FOTY0012, "Argument node does not have a typed value.")

DEF_ERR_CODE(FOUP0001, FOUP0001, "It is a dynamic error if the first operand of fn:put is not a node of a supported kind.")

DEF_ERR_CODE(FOUP0002, FOUP0002, "It is a dynamic error if the second operand of fn:put is not a valid lexical representation of the xs:anyURI type.")

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



//
// ZORBA Errors
//

DEF_ERR_CODE (API0001_XQUERY_STRING_IS_EMPTY, API0001, "Empty query")
DEF_ERR_CODE (API0002_COMPILE_FAILED, API0002, "Query compilation failed")
DEF_ERR_CODE (API0003_XQUERY_NOT_COMPILED, API0003, "Query not compiled")
DEF_ERR_CODE (API0004_XQUERY_ALREADY_COMPILED, API0004, "Query already compiled")

DEF_ERR_CODE (API0005_COLLECTION_ALREADY_EXISTS, API0005, "A collection with URI /s exists already.")

DEF_ERR_CODE (API0006_COLLECTION_NOT_FOUND, API0006, "A collection with URI `/s' does not exist.")

DEF_ERR_CODE (API0007_COLLECTION_ITEM_MUST_BE_A_NODE, API0007, "Cannot insert to a collectionan item that is not a node.")

DEF_ERR_CODE (API0020_DOCUMENT_ALREADY_EXISTS, API0020, "Another document with uri `/s' exists in the store already.")

DEF_ERR_CODE (API0021_ITEM_TO_LOAD_IS_NOT_NODE, API0021, "The uri `/s' does not identify an XML node")

DEF_ERR_CODE(API0023_CANNOT_SERIALIZE_UPDATE_QUERY, API0023, "Cannot serialize an updating query")

DEF_ERR_CODE(API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY, API0024, "Cannot iterate over an updating query")


DEF_ERR_CODE (XQP0001_DYNAMIC_ITERATOR_OVERRUN, XQP0001, "XQP0001_DYNAMIC_ITERATOR_OVERRUN")

DEF_ERR_CODE (XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD, XQP0002, "XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD")

DEF_ERR_CODE (XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND, XQP0003, "XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND")

DEF_ERR_CODE (XQP0004_SYSTEM_NOT_SUPPORTED, XQP0004, "/s not implemented or not supported")

DEF_ERR_CODE (XQP0005_SYSTEM_ASSERT_FAILED, XQP0005, "Assertion `/s' failed in /s")

DEF_ERR_CODE (XQP0016_LOADER_IO_ERROR, XQP0016, "Loader I/O error: /s")

DEF_ERR_CODE (XQP0017_LOADER_PARSING_ERROR, XQP0017, "Loader parsing error: /s")

DEF_ERR_CODE (XQP0018_NODEID_ERROR, XQP0018, "Nodeid error: /s")

DEF_ERR_CODE (XQP0019_INTERNAL_ERROR, XQP0019, "Zorba internal error /s")

DEF_ERR_CODE (XQP0020_INVALID_URI, XQP0020, "Invalid URI /s")

DEF_ERR_CODE (XQP0021_USER_ERROR, XQP0021, "User error")

DEF_ERR_CODE (XQP0022_GET_RESULTS_AS_DOM_FAILED, XQP0022, "Couldn't get result as DOM")

DEF_ERR_CODE (XQP0023_GET_RESULTS_AS_SAX_FAILED, XQP0023, "Couldn't get result as SAX")

DEF_ERR_CODE (XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE, XQP0024, "The function called (/s) is not available for the given item type (/s).")


//
// XPDY
//

DEF_ERR_CODE (XPDY0002, XPDY0002, "evaluation of an expression relies on some part of the dynamic context that has not been assigned a value: /s.")

DEF_ERR_CODE (XPDY0050, XPDY0050, "The dynamic type of the operand of a treat expression does not match the sequence type specified by the treat expression.")


//
// XPST
//

DEF_ERR_CODE (XPST0001, XPST0001, "Analysis of an expression relies on some component of the static context that has not been assigned a value /s")

DEF_ERR_CODE (XPST0003, XPST0003, "Expression is not a valid instance of the grammar.")

DEF_ERR_CODE (XPST0005, XPST0005, "During the analysis phase, it is a static error if the static type assigned to an expression other than the expression () or data(()) is empty-sequence().")

DEF_ERR_CODE (XPST0008, XPST0008, "Expression refers to an element name, attribute name, schema type name, namespace prefix, or variable name that is not defined in the static context: /s /s")

DEF_ERR_CODE (XPST0010, XPST0010, "An implementation must raise a static error if it encounters a reference to an axis that it does not support.")

DEF_ERR_CODE (XPST0017, XPST0017, "Expanded QName and number of arguments in function call do not match the name and arity of any function signature in the static context /s / /s")

DEF_ERR_CODE (XPST0051, XPST0051, "A QName that is used as an AtomicType in a SequenceType is not defined in the in-scope schema types as an atomic type.")

DEF_ERR_CODE (XPST0080, XPST0080, "The target type of a cast or castable expression is xs:NOTATION or xs:anyAtomicType.")

DEF_ERR_CODE (XPST0081, XPST0081, "A QName used in a query contains a namespace prefix that cannot be expanded into a namespace URI by using the statically known namespaces.")


//
// XPTY
//

DEF_ERR_CODE (XPTY0004, XPTY0004, "During the static analysis phase, an expression is found to have a static type that is not appropriate for the context in which the expression occurs, or during the dynamic evaluation phase, the dynamic type of a value does not match a required type as specified by the matching rules: /s")

DEF_ERR_CODE (XPTY0018, XPTY0018, "The result of the last step in a path expression contains both nodes and atomic values.")

DEF_ERR_CODE (XPTY0019, XPTY0019, "The result of a step (other than the last step) in a path expression contains an atomic value.")

DEF_ERR_CODE (XPTY0020, XPTY0020, "In an axis step, the context item is not a node.")



//
// XQDY
//

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

DEF_ERR_CODE (XQST0090, XQST0090, "A character reference does not identify a valid character in the version of XML that is in use.")


//
// XQTY
//

DEF_ERR_CODE (XQTY0030, XQTY0030, "The argument of a validate expression does not evaluate to exactly one document or element node.")

DEF_ERR_CODE (XQTY0086, XQTY0086, "The typed value of a copied element or attribute node is namespace-sensitive when construction mode is preserve and copy-namespaces mode is no-preserve.")

DEF_ERR_CODE (XQTY0024, XQTY0024, "It is a type error if the content sequence in an element constructor contains an attribute node following a node that is not an attribute node.")


//
// UPDATE FACILITY
//

DEF_ERR_CODE(XUST0001, XUST0001, "It is a static error if an updating expression is used in any position other than one of the following: \
 1. The topmost expression in the body of a query. \
 2. The modify clause of a transform expression. \
 3. The return clause of a FLWOR expression. \
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


#undef DEF_ERR_CODE

  for (int i = 0; i < ::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE; ++i) {
    if (canonical_err_names [i] == NULL)
      canonical_err_names [i] = strdup("?");
    if (err_msg [i] == NULL)
      err_msg [i] = strdup (string ("<Unknown errcode " + to_string (i) + "> /s /s").c_str ());
  }


  }

  ~err_msg_initializer()
  {
    for (int i = 0; i < ::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE; ++i) {
      if (canonical_err_names [i] != NULL) {
        free(const_cast<char *>(canonical_err_names [i]));
      }
      if (err_msg [i] != NULL) {
        free(const_cast<char *>(err_msg [i]));
      }
    }
  }
} err_msg_initializer_obj;

::zorba::ZorbaError::ErrorCode 
ZorbaError::err_name_to_code (string name) {
  // TODO: use a map or hashmap
  for (int i = 0; i < ::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE; i++)
    if (name == canonical_err_names [i])
      return (enum ::zorba::ZorbaError::ErrorCode) i;
  return ::zorba::ZorbaError::XQP0019_INTERNAL_ERROR;
}

string ZorbaError::toString(::zorba::ZorbaError::ErrorCode& code) {
  ZORBA_ASSERT (code < ::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE);
  return canonical_err_names [code];
}


string AlertMessagesEnglish::error_decode(::zorba::ZorbaError::ErrorCode& e) {
  ZORBA_ASSERT (e < ::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE);
  return err_msg [e];
} 


string AlertMessagesEnglish::warning_decode(ZorbaWarning::WarningCode& code)
{
  return "?";
}

::zorba::ZorbaError::ErrorCode DecodeZorbatypesError(::zorba::ZorbatypesError::ErrorCode code)
{
  switch( code )
  {
    case  ::zorba::ZorbatypesError::FOER0000:
      return ::zorba::ZorbaError::FOER0000;
      break;
    case  ::zorba::ZorbatypesError::FOAR0001:
      return ::zorba::ZorbaError::FOAR0001;
      break;
    case  ::zorba::ZorbatypesError::FOAR0002:
      return ::zorba::ZorbaError::FOAR0002;
      break;
    case ::zorba::ZorbatypesError::FOCA0001:
      return ::zorba::ZorbaError::FOCA0001;
      break;
    case ::zorba::ZorbatypesError::FOCA0002:
      return ::zorba::ZorbaError::FOCA0002;
      break;
    case ::zorba::ZorbatypesError::FOCA0003:
      return ::zorba::ZorbaError::FOCA0003;
      break;
    case ::zorba::ZorbatypesError::FOCA0005:
      return ::zorba::ZorbaError::FOCA0005;
      break;
    case ::zorba::ZorbatypesError::FOCA0006:
      return ::zorba::ZorbaError::FOCA0006;
      break;
    case ::zorba::ZorbatypesError::FOCH0001:
      return ::zorba::ZorbaError::FOCH0001;
      break;
    case ::zorba::ZorbatypesError::FOCH0002:
      return ::zorba::ZorbaError::FOCH0002;
      break;
      
      
    case ::zorba::ZorbatypesError::FOCH0003:
      return ::zorba::ZorbaError::FOCH0003;
      break;
    case ::zorba::ZorbatypesError::FOCH0004:
      return ::zorba::ZorbaError::FOCH0004;
      break;
    case ::zorba::ZorbatypesError::FODC0001:
      return ::zorba::ZorbaError::FODC0001;
      break;
    case ::zorba::ZorbatypesError::FODC0002:
      return ::zorba::ZorbaError::FODC0002;
      break;
    case ::zorba::ZorbatypesError::FODC0003:
      return ::zorba::ZorbaError::FODC0003;
      break;
    case ::zorba::ZorbatypesError::FODC0004:
      return ::zorba::ZorbaError::FODC0004;
      break;
    case ::zorba::ZorbatypesError::FODC0005:
      return ::zorba::ZorbaError::FODC0005;
      break;
    case ::zorba::ZorbatypesError::FODT0001:
      return ::zorba::ZorbaError::FODT0001;
      break;
    case ::zorba::ZorbatypesError::FODT0002:
      return ::zorba::ZorbaError::FODT0002;
      break;
    case ::zorba::ZorbatypesError::FODT0003:
      return ::zorba::ZorbaError::FODT0003;
      break;

      
    case ::zorba::ZorbatypesError::FONS0004:
      return ::zorba::ZorbaError::FONS0004;
      break;
    case ::zorba::ZorbatypesError::FONS0005:
      return ::zorba::ZorbaError::FONS0005;
      break;
    case ::zorba::ZorbatypesError::FORG0001:
      return ::zorba::ZorbaError::FORG0001;
      break;
    case ::zorba::ZorbatypesError::FORG0002:
      return ::zorba::ZorbaError::FORG0002;
      break;
    case ::zorba::ZorbatypesError::FORG0003:
      return ::zorba::ZorbaError::FORG0003;
      break;
    case ::zorba::ZorbatypesError::FORG0004:
      return ::zorba::ZorbaError::FORG0004;
      break;
    case ::zorba::ZorbatypesError::FORG0005:
      return ::zorba::ZorbaError::FORG0005;
      break;
    case ::zorba::ZorbatypesError::FORG0006:
      return ::zorba::ZorbaError::FORG0006;
      break;
    case ::zorba::ZorbatypesError::FORG0008:
      return ::zorba::ZorbaError::FORG0008;
      break;
    case ::zorba::ZorbatypesError::FORG0009:
      return ::zorba::ZorbaError::FORG0009;
      break;

      
    case ::zorba::ZorbatypesError::FORX0001:
      return ::zorba::ZorbaError::FORX0001;
      break;
    case ::zorba::ZorbatypesError::FORX0002:
      return ::zorba::ZorbaError::FORX0002;
      break;
    case ::zorba::ZorbatypesError::FORX0003:
      return ::zorba::ZorbaError::FORX0003;
      break;
    case ::zorba::ZorbatypesError::FORX0004:
      return ::zorba::ZorbaError::FORX0004;
      break;
    case ::zorba::ZorbatypesError::FOTY0012:
      return ::zorba::ZorbaError::FOTY0012;
      break;
    case ::zorba::ZorbatypesError::FOUP0001:
      return ::zorba::ZorbaError::FOUP0001;
      break;
    case ::zorba::ZorbatypesError::FOUP0002:
      return ::zorba::ZorbaError::FOUP0002;
      break;

    default:
      return ::zorba::ZorbaError::MAX_ZORBA_ERROR_CODE;
      break;
  }
  return ::zorba::ZorbaError::FORX0001;
}

} /* namespace error */
} /* namespace zorba */
