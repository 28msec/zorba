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
#include "capi/error.h"

using namespace zorba;

namespace zorbac {

  XQC_Error
  Error::convert_xquery_error(XQUERY_ERROR error) {
    switch (error) {
      case XQ_NO_ERROR:
        return XQC_NO_ERROR;

        //
        // XPath dynamic errors
        //
      case XPDY0002:
        // evaluation of an expression relies on some part of the
        // dynamic context that has not been assigned a value.
      case XPDY0021:
        // (Not currently used.)
      case XPDY0050:
        // the dynamic type of the operand of a treat expression does
        // not match the sequence type specified by the treat
        // expression. This error might also be raised by a path
        // expression beginning with "/" or "// " if the context node
        // is not in a tree that is rooted at a document node. This is
        // because a leading "/" or "// " in a path expression is an
        // abbreviation for an initial step that includes the clause
        // treat as document-node().

        return XQC_DYNAMIC_ERROR;


        //
        // XPath static errors
        //
      case XPST0001:
        // analysis of an expression relies on some component of the
        // static context that has not been assigned a value.
      case XPST0003:
        // an expression is not a valid instance of the grammar.
      case XPST0005:
        // During the analysis phase, it is a static error if the
        // static type assigned to an expression other than the
        // expression () or data(()) is empty-sequence().
      case XPST0008:
        // an expression refers to an element name, attribute name,
        // schema type name, namespace prefix, or variable name that
        // is not defined in the static context, except for an
        // ElementName in an ElementTest or an AttributeName in an
        // AttributeTest.
      case XPST0010:
        // An implementation must raise a static error if it
        // encounters a reference to an axis that it does not support.
      case XPST0017:
        // the expanded QName and number of arguments in a function
        // call do not match the name and arity of a function
        // signature in the static context.
      case XPST0051: // = 10,
        // a QName that is used as an AtomicType in a SequenceType is
        // not defined in the in-scope schema types as an atomic type.
      case XPST0080:
        // the target type of a cast or castable expression is
        // xs:NOTATION or xs:anyAtomicType.
      case XPST0081:
        // a QName used in a query contains a namespace prefix that
        // cannot be expanded into a namespace URI by using the
        // statically known namespaces.
      case XPST0083:
        // (Not currently used.)

        return XQC_STATIC_ERROR;


        //
        // XPath type errors
        //
      case XPTY0004:
        // during the static analysis phase, an expression is found to
        // have a static type that is not appropriate for the context
        // in which the expression occurs, or during the dynamic
        // evaluation phase, the dynamic type of a value does not
        // match a required type as specified by the matching rules in
        // 2.5.4, SequenceType Matching.
      case XPTY0006:
        // (Not currently used.)
      case XPTY0007:
        // (Not currently used.)
      case XPTY0018:
        // the result of the last step in a path expression contains
        // both nodes and atomic values.
      case XPTY0019:
        // the result of a step (other than the last step) in a path
        // expression contains an atomic value.
      case XPTY0020:
        // in an axis step, the context item is not a node.

        return XQC_TYPE_ERROR;


        //
        // XQuery dynamic errors
        //
      case XQDY0025: // = 20,
        // any attribute of a constructed element does not have a name
        // that is distinct from the names of all other attributes of
        // the constructed element.
      case XQDY0026:
        // a constructor or replace expression results in a processing
        // instruction node whose content includes the string "?>".
      case XQDY0027:
        // In a validate expression, it is a dynamic error if the root
        // element information item in the PSVI resulting from
        // validation does not have the expected validity property:
        // valid if validation mode is strict, or either valid or
        // notKnown if validation mode is lax.
      case XQDY0029:
        // (Not currently used.)
      case XQDY0041:
        // the value of the name expression in a computed processing
        // instruction constructor cannot be cast to the type
        // xs:NCName.
      case XQDY0044:
        // the node-name property of the node constructed by a
        // computed attribute constructor is in the namespace http://
        // www.w3.org/2000/xmlns/ (corresponding to namespace prefix
        // xmlns), or is in no namespace and has local name xmlns.
      case XQDY0052:
        // (Not currently used.)
      case XQDY0061:
        // the operand of a validate expression is a document node
        // whose children do not consist of exactly one element node
        // and zero or more comment and processing instruction nodes,
        // in any order.
      case XQDY0062:
        // (Not currently used.)
      case XQDY0064:
        // the value of the name expression in a computed processing
        // instruction constructor is equal to "XML" (in any
        // combination of upper and lower case).
      case XQDY0072: // = 30,
        // a constructor or replace expression results in a comment
        // node whose content ends with a hyphen or contains two
        // adjacent hyphens.
      case XQDY0074:
        // the value of the name expression in a computed element or
        // attribute constructor or rename expression cannot be
        // converted to an expanded QName (for example, because it
        // contains a namespace prefix not found in statically known
        // namespaces.)
      case XQDY0084:
        // the element validated by a validate statement does not have
        // a top-level element declaration in the in-scope element
        // declarations, if validation mode is strict.
      case XQDY0091:
        // An implementation MAY raise a dynamic error if an xml:id
        // error, as defined in [XML ID], is encountered during
        // construction of an attribute named xml:id.
      case XQDY0092:
        // An implementation MAY raise a dynamic error if a
        // constructed attribute named xml:space has a value other
        // than preserve or default.

        return XQC_DYNAMIC_ERROR;


        //
        // XQuery static errors
        //
      case XQST0009:
        // An implementation that does not support the Schema Import
        // Feature must raise a static error if a Prolog contains a
        // schema import.
      case XQST0012:
        // the set of definitions contained in all schemas imported by
        // a Prolog do not satisfy the conditions for schema validity
        // specified in Sections 3 and 5 of [XML Schema] Part 1--i.e.,
        // each definition must be valid, complete, and unique.
      case XQST0013:
        // an implementation recognizes a pragma but determines that
        // its content is invalid.
      case XQST0014:
        // (Not currently used.)
      case XQST0015:
        // (Not currently used.)
      case XQST0016: // = 40,
        // An implementation that does not support the Module Feature
        // raises a static error if it encounters a module declaration
        // or a module import.
      case XQST0022:
        // the value of a namespace declaration attribute is not a URILiteral.
      case XQST0031:
        // the version number specified in a version declaration is
        // not supported by the implementation.
      case XQST0032:
        // A static error is raised if a Prolog contains more than one
        // base URI declaration.
      case XQST0033:
        // a module contains multiple bindings for the same namespace
        // prefix.
      case XQST0034:
        // multiple functions declared or imported by a module have
        // the number of arguments and their expanded QNames are equal
        // (as defined by the eq operator).
      case XQST0035:
        // It is a static error to import two schema components that
        // both define the same name in the same symbol space and in
        // the same scope.
      case XQST0036:
        // It is a static error to import a module if the importing
        // module's in-scope schema types do not include definitions
        // for the schema type names that appear in the declarations
        // of variables and functions (whether in an argument type or
        // return type) that are present in the imported module and
        // are referenced in the importing module.
      case XQST0037:
        // (Not currently used.)
      case XQST0038:
        // a Prolog contains more than one default collation
        //declaration, or the value specified by a default collation
        //declaration is not present in statically known collations.
      case XQST0039: // = 50,
        // It is a static error for a function declaration to have
        // more than one parameter with the same name.
      case XQST0040:
        // the attributes specified by a direct element constructor do
        // not have distinct expanded QNames.
      case XQST0042:
        // (Not currently used.)
      case XQST0043:
        // (Not currently used.)
      case XQST0045:
        // the function name in a function declaration is in one of
        // the following namespaces:
        // http://www.w3.org/XML/1998/namespace,
        // http://www.w3.org/2001/XMLSchema,
        // http://www.w3.org/2001/XMLSchema-instance,
        // http://www.w3.org/2005/xpath-functions.
      case XQST0046:
        // An implementation MAY raise a static error if the value of
        // a URILiteral is of nonzero length and is not in the lexical
        // space of xs:anyURI.
      case XQST0047:
        // multiple module imports in the same Prolog specify the same
        // target namespace.
      case XQST0048:
        // a function or variable declared in a library module is not
        // in the target namespace of the library module.
      case XQST0049:
        // two or more variables declared or imported by a module have
        // equal expanded QNames (as defined by the eq operator.)
      case XQST0053:
        // (Not currently used.)
      case XQST0054: // = 60,
        // a variable depends on itself.
      case XQST0055:
        // a Prolog contains more than one copy-namespaces declaration.
      case XQST0056:
        // (Not currently used.)
      case XQST0057:
        // a schema import binds a namespace prefix but does not
        // specify a target namespace other than a zero-length string.
      case XQST0058:
        // multiple schema imports specify the same target namespace.
      case XQST0059:
        // an implementation is unable to process a schema or module
        // import by finding a schema or module with the specified
        // target namespace.
      case XQST0060:
        // the name of a function in a function declaration is not in
        // a namespace (expanded QName has a null namespace URI).
      case XQST0063:
        // (Not currently used.)
      case XQST0065:
        // A static error is raised if a Prolog contains more than one
        // ordering mode declaration.
      case XQST0066:
        // A static error is raised if a Prolog contains more than one
        // default element/type namespace declaration, or more than
        // one default function namespace declaration.
      case XQST0067: // = 70,
        // A static error is raised if a Prolog contains more than one
        // construction declaration.
      case XQST0068:
        // A static error is raised if a Prolog contains more than one
        // boundary-space declaration.
      case XQST0069:
        // A static error is raised if a Prolog contains more than one
        // empty order declaration.
      case XQST0070:
        // A static error is raised if a namespace URI is bound to the
        // predefined prefix xmlns, or if a namespace URI other than
        // http://www.w3.org/XML/1998/namespace is bound to the prefix
        // xml, or if the prefix xml is bound to a namespace URI other
        // than http://www.w3.org/XML/1998/namespace.
      case XQST0071:
        // A static error is raised if the namespace declaration
        // attributes of a direct element constructor do not have
        // distinct names.
      case XQST0073:
        // the graph of module imports contains a cycle (that is, if
        // there exists a sequence of modules case M1: ... Mn such
        // that each Mi imports Mi+1, and Mn imports M1), unless all
        // the modules in the cycle share a common namespace.
      case XQST0075:
        // An implementation that does not support the Validation
        // Feature must raise a static error if it encounters a
        // validate expression.
      case XQST0076:
        // a collation subclause in an order by clause of a FLWOR
        // expression does not identify a collation that is present in
        // statically known collations.
      case XQST0077:
        // (Not currently used.)
      case XQST0078:
        // (Not currently used.)
      case XQST0079: // = 80,
        // an extension expression contains neither a pragma that is
        // recognized by the implementation nor an expression enclosed
        // in curly braces.
      case XQST0082:
        // (Not currently used.)
      case XQST0085:
        // the namespace URI in a namespace declaration attribute is a
        // zero-length string, and the implementation does not support
        // [XML Names 1.1].
      case XQST0087:
        // the encoding specified in a Version Declaration does not
        // conform to the definition of EncName specified in [XML
        // 1.0].
      case XQST0088:
        // the literal that specifies the target namespace in a module
        // import or a module declaration is of zero length.
      case XQST0089:
        // a variable bound in a for clause of a FLWOR expression, and
        // its associated positional variable, do not have distinct
        // names (expanded QNames).
      case XQST0090:
        // a character reference does not identify a valid character
        // in the version of XML that is in use.
      case XQST0093:
        // It is a static error to import a module case M1: // if
        // there exists a sequence of modules case M1: ... Mi ... case
        // M1: such that each module directly depends on the next
        // module in the sequence (informally, if case M1: depends on
        // itself through some chain of module dependencies.)

        return XQC_STATIC_ERROR;


        //
        // XQuery Type erros
        //
      case XQTY0023:
        // (Not currently used.)
      case XQTY0024:
        // the content sequence in an element constructor contains an
        // attribute node following a node that is not an attribute
        // node.
      case XQTY0028: // = 90,
        // (Not currently used.)
      case XQTY0030:
        // the argument of a validate expression does not evaluate to
        // exactly one document or element node.
      case XQTY0086:
        // the typed value of a copied element or attribute node is
        // namespace- sensitive when construction mode is preserve and
        // copy-namespaces mode is no-preserve.

        return XQC_TYPE_ERROR;


        //
        // XQuery Update Facility
        //
      case XUST0001:
        // It is a static error if an updating expression is used in
        // any position other than one of the following:
        // 1. The topmost expression in the body of a query.
        // 2. The modify clause of a transform expression.
        // 3. The return clause of a FLWOR expression.
        // 4. The return clauses of a typeswitch expression in which
        //    every return clause contains an updating expression, an
        //    empty expression ( ), or a call to the fn:error
        //    function.
        // 5. The then and else clauses of a conditional statement in
        //    which both the then and else clauses contain either an
        //    updating expression, an empty expression ( ), or a call
        //    to the fn:error function.  6. An operand of a comma
        //    expression in which each operand is either an updating
        //    expression, an empty expression ( ), or a call to the
        //    fn:error function.  7. The content of a parenthesized
        //    expression.  8. The body of a function declaration in
        //    which the keyword updating is specified.
      case XUST0002:
        // It is a static error if an non-updating expression other than an
        // empty expression ( ) or a call to the fn:error function is used in
        // one of the following positions:
        // 1. The modify clause of a transform expression.
        // 2. The top-level expression in the body of a function declaration in
        //     which the keyword updating is specified.
      case XUST0003:
        // It is a static error if a Prolog contains more than one
        // revalidation declaration.

        return XQC_STATIC_ERROR;


      case XUTY0004:
        // It is a type error if the insertion sequence of an insert
        // expression contains an attribute node following a node that
        // is not an attribute node.
      case XUTY0005:
        // In an insert expression where into, as first into, or as
        // last into is specified, it is a type error if the target
        // expression returns a non-empty result that does not consist
        // of a single element or document node.
      case XUTY0006:
        // In an insert expression where before or after is specified,
        // it is a type error if the target expression returns a
        // non-empty result that does not consist of a single element,
        // text, comment, or processing instruction node.
      case XUTY0007:
        // It is a type error if the target expression of a delete
        // expression does not return a sequence of zero or more
        // nodes.
      case XUTY0008: // = 100,
        // In a replace expression, it is a type error if the target
        // expression returns a non-empty result that does not consist
        // of a single element, attribute, text, comment, or
        // processing instruction node.

        return XQC_TYPE_ERROR;


      case XUDY0009:
        // In a replace expression where value of is not specified, it
        // is a dynamic error if the node returned by the target
        // expression does not have a parent.

        return XQC_DYNAMIC_ERROR;


      case XUTY0010:
        // In a replace expression where value of is not specified and
        // the target is an element, text, comment, or processing
        // instruction node, it is a type error if the replacement
        // sequence does not consist of zero or more element, text,
        // comment, or processing instruction nodes.
      case XUTY0011:
        // In a replace expression where value of is not specified and
        // the target is an attribute node, it is a type error if the
        // replacement sequence does not consist of zero or more
        // attribute nodes.
      case XUTY0012:
        // In a rename expression, it is a type error if the target
        // expression returns a non-empty result that does not consist
        // of a single element, attribute, or processing instruction
        // node.
      case XUTY0013:
        // In a transform expression, it is a type error if a source
        // expression in the copy clause does not return a single
        // node.

        return XQC_TYPE_ERROR;


      case XUDY0014:
        // In a transform expression, it is a dynamic error if the
        // modify clause modifies any node that was not created by the
        // copy clause.
      case XUDY0015:
        // It is a dynamic error if any node is the target of more
        // than one rename expression within the same query.
      case XUDY0016:
        // It is a dynamic error if any node is the target of more
        // than one replace expression (without value of being
        // specified) within the same query.
      case XUDY0017:
        // It is a dynamic error if any node is the target of more
        // than one replace value of expression within the same query.
      case XUDY0018: // = 110,
        // It is a dynamic error if a function that was declared to be
        // external but not updating returns a non-empty pending
        // update list.
      case XUDY0019:
        // It is a dynamic error if a function that was declared to be
        // both external and updating returns a non-empty data model
        // instance.
      case XUDY0020:
        // An implementation may (but is not required to) raise a
        // dynamic error if a node is deleted that had no parent
        // before execution of the query began.
      case XUDY0021:
        // It is a dynamic error if the XDM instance that would result
        // from applying all the updates in a query violates any
        // constraint specified in [XQuery/XPath Data Model (XDM)]. In
        // this case, none of the updates in the query are made
        // effective.

        return XQC_DYNAMIC_ERROR;


      case XUTY0022:
        // It is a type error if an insert expression specifies the
        // insertion of an attribute node into a document node.
      case XUDY0023:
        // It is a dynamic error if an insert, replace, or rename
        // expression affects an element node by introducing a new
        // namespace binding that conflicts with one of its existing
        // namespace bindings.
      case XUDY0024:
        // It is a dynamic error if the effect of a set of updating
        // expressions is to introduce conflicting namespace bindings
        // into an element node.
      case XUDY0025:
        // It is a dynamic error if the target of a rename expression
        // is a processing instruction node, and the new name
        // expression returns a QName with a non-empty namespace
        // prefix.
      case XUST0026:
        // It is a static error if a revalidation declaration in a
        // Prolog specifies a revalidation mode that is not supported
        // by the current implementation.
      case XUDY0027:
        // It is a dynamic error if the target expression of an
        // insert, replace, or rename expression evaluates to an empty
        // sequence.

        return XQC_DYNAMIC_ERROR;


      case XUST0028: // = 120,
        // It is a static error if a function declaration specifies
        // both updating and a return type.

        return XQC_STATIC_ERROR;


      case XUDY0029:
        // In an insert expression where before or after is specified,
        // it is a dynamic error if node returned by the target
        // expression does not have a parent.
      case XUDY0030:
        // It is a dynamic error if an insert expression specifies the
        // insertion of an attribute node before or after a child of a
        // document node.
      case XUDY0031:
        // It is a dynamic error if multiple calls to fn:put in the
        // same snapshot specify the same URI (after resolution of
        // relative URIs).

        return XQC_DYNAMIC_ERROR;


        //
        // XQuery 1.0 and XPath 2.0 Functions and Operators
        //
      case FOER0000:
        // Unidentified error.
      case FOAR0001:
        // Division by zero.  This error is raised whenever an attempt
        // is made to divide by zero.
      case FOAR0002:
        // Numeric operation overflow/underflow.  This error is raised
        // whenever numeric operations result in an overflow or
        // underflow.

        // These are runtime, data-driven errors, so "dynamic error"
        // seems like best fit:
        return XQC_DYNAMIC_ERROR;


      case FOCA0001:
        // Input value too large for decimal.
      case FOCA0002:
        // Invalid lexical value.
      case FOCA0003: 
        // Input value too large for integer.
      case FOCA0005: 
        // NaN supplied as float/double value.
      case FOCA0006: 
        // String to be cast to decimal has too many digits of precision.
      case FOCH0001: 
        // Code point not valid.
      case FOCH0002: 
        // Unsupported collation.
      case FOCH0003: 
        // Unsupported normalization form.
      case FOCH0004: 
        // Collation does not support collation units.

        return XQC_INVALID_ARGUMENT;


      case FODC0001: 
        // No context document.

        return XQC_NO_CURRENT_ITEM;


      case FODC0002: 
        // Error retrieving resource.

        return XQC_DYNAMIC_ERROR;


      case FODC0003: 
        // Function stability not defined.

        // ???
        return XQC_INTERNAL_ERROR;


      case FODC0004: 
        // Invalid argument to fn:collection.
      case FODC0005: 
        // Invalid argument to fn:doc or fn:doc-available.

        return XQC_INVALID_ARGUMENT;


      case FODT0001: 
        //  = 140, //Overflow/underflow in date/time operation.
      case FODT0002: 
        // Overflow/underflow in duration operation.

        return XQC_DYNAMIC_ERROR;


      case FODT0003: 
        // Invalid timezone value.
      case FONS0004: 
        // No namespace found for prefix.
      case FONS0005: 
        // Base-uri not defined in the static context.
      case FORG0001: 
        // Invalid value for cast/constructor.
      case FORG0002: 
        // Invalid argument to fn:resolve-uri().
      case FORG0003: 
        // fn:zero-or-one called with a sequence containing more than one item.
      case FORG0004: 
        // fn:one-or-more called with a sequence containing no items.
      case FORG0005: 
        // fn:exactly-one called with a sequence containing zero or
        // more than one item.
      case FORG0006: 
        // Invalid argument type.
      case FORG0008: 
        // Both arguments to fn:dateTime have a specified timezone.
      case FORG0009: 
        // Error in resolving a relative URI against a base URI in
        // fn:resolve-uri.

        return XQC_INVALID_ARGUMENT;


      case FORX0001: 
        // Invalid regular expression flags
      case FORX0002: 
        // Invalid regular expression.
      case FORX0003: 
        // Regular expression matches zero-length string.
      case FORX0004: 
        // Invalid replacement string.
      case FOTY0012: 
        // Argument node does not have a typed value.

        return XQC_INVALID_ARGUMENT;


      case FOUP0001:
        // It is a dynamic error if the first operand of fn:put is not
        // a node of a supported kind.
      case FOUP0002:
        // It is a dynamic error if the second operand of fn:put is
        // not a valid lexical representation of the xs:anyURI type.

        return XQC_DYNAMIC_ERROR;


        //
        // Serialization errors
        //
      case SENR0001: // = 160,
        //  It is an error if an item in S6 in sequence normalization
        //  is an attribute node or a namespace node.
      case SERE0003:
        //  It is an error if the serializer is unable to satisfy the
        //  rules for either a well-formed XML document entity or a
        //  well-formed XML external general parsed entity, or both,
        //  except for content modified by the character expansion
        //  phase of serialization.
      case SEPM0004:
        //  It is an error to specify the doctype-system parameter, or
        //  to specify the standalone parameter with a value other
        //  than omit, if the instance of the data model contains text
        //  nodes or multiple element nodes as children of the root
        //  node.
      case SERE0005:
        //  It is an error if the serialized result would contain an
        //  NCName Names that contains a character that is not
        //  permitted by the version of Namespaces in XML specified by
        //  the version parameter.
      case SERE0006:
        //  It is an error if the serialized result would contain a
        //  character that is not permitted by the version of XML
        //  specified by the version parameter.
      case SESU0007:
        //  It is an error if an output encoding other than UTF-8 or
        //  UTF-16 is requested and the serializer does not support
        //  that encoding.
      case SERE0008:
        //  It is an error if a character that cannot be represented
        //  in the encoding that the serializer is using for output
        //  appears in a context where character references are not
        //  allowed (for example if the character occurs in the name
        //  of an element).
      case SEPM0009:
        //  It is an error if the omit-xml-declaration parameter has
        //  the value yes, and the standalone attribute has a value
        //  other than omit; or the version parameter has a value
        //  other than 1.0 and the doctype-system parameter is
        //  specified.
      case SEPM0010:
        //  It is an error if the output method is xml, the value of
        //  the undeclare-prefixes parameter is yes, and the value of
        //  the version parameter is 1.0.
      case SESU0011:
        //  It is an error if the value of the normalization-form
        //  parameter specifies a normalization form that is not
        //  supported by the serializer.
      case SERE0012: // = 170,
        //  It is an error if the value of the normalization-form
        //  parameter is fully-normalized and any relevant construct
        //  of the result begins with a combining character.
      case SESU0013:
        //  It is an error if the serializer does not support the
        //  version of XML or HTML specified by the version parameter.
      case SERE0014:
        //  It is an error to use the HTML output method when
        //  characters which are legal in XML but not in HTML,
        //  specifically the control characters #x7F-#x9F, appear in
        //  the instance of the data model.
      case SERE0015:
        //  It is an error to use the HTML output method when >
        //  appears within a processing instruction in the data model
        //  instance being serialized.
      case SEPM0016:
        // It is a an error if a parameter value is invalid for the
        // defined domain.

        return XQC_SERIALIZATION_ERROR;


      case XTDE1310:
        // It is a non-recoverable dynamic error if the picture string
        // does not satisfy the format-number function rules.
      case XTDE1340:
        // It is a non-recoverable dynamic error if the syntax of the
        // picture is incorrect.
      case XTDE1350:
        // It is a non-recoverable dynamic error if a component
        // specifier within the picture refers to components that are
        // not available in the given type of $value.

        return XQC_DYNAMIC_ERROR;


        //
        // ZORBA errors
        //
      case XQP0000_DYNAMIC_RUNTIME_ERROR:
      case XQP0001_DYNAMIC_ITERATOR_OVERRUN:
      case XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD: // = 180,
      case XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND:
      case XQP0004_SYSTEM_NOT_SUPPORTED:
      case XQP0005_SYSTEM_ASSERT_FAILED:
      case XQP0006_SYSTEM_HASH_ERROR_KEYLEN_EXCEEDS_MAXKEYLEN:
      case XQP0007_SYSTEM_VECTOR_OUT_OF_RANGE:
      case XQP0008_SYSTEM_READ_LOCK_FAILED:
      case XQP0009_SYSTEM_WRITE_LOCK_FAILED:
      case XQP0010_SYSTEM_POP_FROM_EMPTY_LIST:
      case XQP0011_SYSTEM_FILE_ERROR_IN_FUNCTION:
      case XQP0012_SYSTEM_FXCHARHEAP_IOEXCEPTION: // = 190,
      case XQP0013_SYSTEM_MMFILE_IOEXCEPTION:
      case XQP0015_SYSTEM_NOT_YET_IMPLEMENTED:
      case XQP0019_INTERNAL_ERROR:
      case XQP0020_INVALID_URI:
      case XQP0021_USER_ERROR:
      case XQP0022_GET_RESULTS_AS_DOM_FAILED:
      case XQP0023_GET_RESULTS_AS_SAX_FAILED:
      case XQP0025_COULD_NOT_CREATE_ITEM:
      case XQP0026_COULD_NOT_CREATE_THREAD:
      case XQP0026_CANNOT_INIT_STORE: // = 200,
      case XQP0027_MS_DOM_ERROR:
      case XQP0028_FUNCTION_IMPL_NOT_FOUND:
      case XQP0030_DEADLOCK:

        return XQC_INTERNAL_ERROR;


      case XQP0031_MALFORMED_XQUERYX_INPUT:
      case XQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY:

        return XQC_INVALID_ARGUMENT;


      case XQP0033_INDEX_DOES_NOT_EXIST:
      case XQP0034_INDEX_ALREADY_EXISTS:
      case XQP0035_MULTI_VALUED_INDEX_KEY:
      case XQP0036_NON_ATOMIC_INDEX_KEY:
      case XQP0037_INDEX_IS_NOT_DECLARED:
      case XQP0038_INDEX_IS_ALREADY_DECLARED:
      case XQP0040_INDEX_HAS_FREE_VARS:
      case XQP0041_INDEX_HAS_INVALID_DATA_SOURCE:
      case XQP0042_INDEX_NOT_DETERMINISTIC:
      case XQP0043_IC_DOES_NOT_EXIST:
      case XQP0044_IC_ALREADY_EXISTS:
      case XQP0045_MULTI_VALUED_IC_KEY:
      case XQP0046_NON_ATOMIC_IC_KEY:
      case XQP0047_IC_IS_NOT_DECLARED:
      case XQP0048_IC_IS_ALREADY_DECLARED:
      case XQP0049_IC_IN_NON_DATA_MODULE:
      case XQP0050_IC_HAS_FREE_VARS:
      case XQP0051_IC_HAS_INVALID_DATA_SOURCE:
      case XQP0052_IC_NOT_DETERMINISTIC:

        return XQC_INVALID_ARGUMENT;


        //
        // Zorba API errors
        //
      case API0001_XQUERY_STRING_IS_EMPTY:

        return XQC_INVALID_ARGUMENT;


      case API0002_COMPILE_FAILED:

        return XQC_STATIC_ERROR;


      case API0003_XQUERY_NOT_COMPILED: // = 210,
      case API0004_XQUERY_ALREADY_COMPILED:
      case API0007_COLLECTION_ITEM_MUST_BE_A_NODE:
      case API0009_THREAD_NOT_INITIALIZED:
      case API0010_XQUERY_EXECUTION_NOT_STARTED:
      case API0011_INVALID_VARIABLE_QNAME:
      case API0012_INVALID_INDEX:
      case API0013_INAPPROPRIATE_VARIABLE_VALUE:
      case API0014_INVALID_ARGUMENT: // = 220,
      case API0015_CANNOT_OPEN_FILE:
      case API0016_CANNOT_CREATE_COLLECTION:
      case API0017_CANNOT_LOAD_DOCUMENT:
      case API0018_CANNOT_ACCESS_FILE:
      case API0019_FUNCTION_ALREADY_REGISTERED:
      case API0020_DOCUMENT_ALREADY_EXISTS:
      case API0021_ITEM_TO_LOAD_IS_NOT_NODE:
      case API0022_QUERY_ALREADY_CLOSED:
      case API0023_CANNOT_SERIALIZE_UPDATE_QUERY:
      case API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY: // = 230,

        return XQC_INVALID_ARGUMENT;


      case API0025_END_OF_SEQUENCE:

        return XQC_END_OF_SEQUENCE;


      case API0026_CANNOT_CLOSE_QUERY_WITH_ITERATORS:
      case API0027_CANNOT_UPDATE_DCTX_WITH_ITERATORS:
      case API0028_INVALID_NODE_URI:
      case API0030_NO_NODE_AT_GIVEN_POSITION:
      case API0031_NODE_ALREADY_IN_COLLECTION:
      case API0032_NON_ROOT_NODE_IN_COLLECTION:
      case API0032_QUERY_NOT_COMPILED_IN_DEBUG_MODE:
      case API0033_FILE_OR_FOLDER_DOES_NOT_EXIST:
      case API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED:
      case API0035_COLLECTION_CANNOT_BE_SERIALIZED:
      case API0036_TIDY_ERROR:
      case API0037_TIDY_ERROR_SET_OPTION:
      case API0050_REST_ERROR_HEADER:
      case API0051_REST_ERROR_PAYLOAD:
      case API0060_CONV_JSON_PARSE:
      case API0061_CONV_JSON_SERIALIZE:
      case API0062_CONV_JSON_PARAM:
      case API0063_CONV_JSON_ML_PARSE:
      case API0064_CONV_JSON_ML_SERIALIZE:
      case API0065_CONV_JSON_ML_PARAM:
      case API0066_JSON_SEQUENCE_CANNOT_BE_SERIALIZED:
      case API0070_INVALID_SERIALIZATION_METHOD_FOR_SAX:

        return XQC_INVALID_ARGUMENT;


        //
        // Store Errors
        //
      case STR0001_INDEX_ALREADY_EXISTS:
      case STR0002_INDEX_DOES_NOT_EXIST:
      case STR0003_INDEX_PARTIAL_KEY_INSERT:
      case STR0004_INDEX_PARTIAL_KEY_REMOVE: // = 250,
      case STR0005_INDEX_PARTIAL_KEY_PROBE:
      case STR0006_INDEX_INVALID_BOX_PROBE:
      case STR0007_INDEX_UNSUPPORTED_PROBE_CONDITION:
      case STR0008_COLLECTION_ALREADY_EXISTS:
      case STR0009_COLLECTION_NOT_FOUND:
      case STR0020_LOADER_IO_ERROR:
      case STR0021_LOADER_PARSING_ERROR:
      case STR0030_NODEID_ERROR:
      case STR0040_TYPE_ERROR: // = 257,
      case STR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE:

        return XQC_INVALID_ARGUMENT;


        // Class Serialization errors
      case SRL0001_INEXISTENT_INPUT_FIELD:
      case SRL0002_INCOMPATIBLE_INPUT_FIELD:
      case SRL0003_UNRECOGNIZED_CLASS_FIELD:
      case SRL0004_UNRESOLVED_FIELD_REFERENCE:
      case SRL0005_CLASS_VERSION_IS_TOO_NEW:
      case SRL0006_CLASS_VERSION_IS_TOO_OLD:
      case SRL0007_INPUT_ARCHIVE_USED_FOR_OUT_SERIALIZATION:
      case SRL0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION:
      case SRL0009_CLASS_NOT_SERIALIZABLE:
      case SRL0010_ITEM_TYPE_NOT_SERIALIZABLE:
      case SRL0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE:
      case SRL0012_INCOMPATIBLE_ARCHIVE_VERSION:
      case SRL0013_UNABLE_TO_LOAD_QUERY:

        return XQC_INTERNAL_ERROR;


        //
        // XQuery Data Definition Facility
        //
      case XDST0001_COLLECTION_ALREADY_DECLARED:
      case XDST0002_COLLECTION_ALREADY_IMPORTED:
      case XDST0003_COLLECTION_DECL_IN_MAIN_MODULE:
      case XDST0004_COLLECTION_MULTIPLE_PROPERTY_VALUES:
      case XDST0005_COLLECTION_PROPERTIES_CONFLICT:
      case XDST0006_COLLECTION_INVALID_PROPERTY_VALUE:

      case XDST0021_INDEX_ALREADY_DECLARED:
      case XDST0022_INDEX_ALREADY_IMPORTED:
      case XDST0023_INDEX_DECL_IN_MAIN_MODULE:
      case XDST0024_INDEX_MULTIPLE_PROPERTY_VALUES:
      case XDST0025_INDEX_PROPERTIES_CONFLICT:
      case XDST0026_INDEX_INVALID_PROPERTY_VALUE:

      case XDDY0001_COLLECTION_NOT_DECLARED:
      case XDDY0002_COLLECTION_EXISTS_ALREADY:
      case XDDY0003_COLLECTION_DOES_NOT_EXIST:
      case XDDY0004_COLLECTION_CONST_UPDATE:
      case XDDY0005_COLLECTION_APPEND_BAD_INSERT:
      case XDDY0006_COLLECTION_QUEUE_BAD_INSERT:
      case XDDY0007_COLLECTION_APPEND_BAD_DELETE:
      case XDDY0008_COLLECTION_QUEUE_BAD_DELETE:
      case XDDY0009_COLLECTION_QUEUE_BAD_DELETE:
      case XDDY0010_COLLECTION_CONST_NODE_UPDATE:
      case XDDY0011_COLLECTION_NODE_NOT_FOUND:

        return XQC_INVALID_ARGUMENT;


      default:

        return (XQC_Error) -1;
    }

  } /* Error::convert_xquery_error() */

} /* namespace zorbac */
