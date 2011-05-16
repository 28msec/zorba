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

namespace zorba {

#define XQUERY_DEC_ERROR(ERR) extern ZORBA_DLL_PUBLIC XQueryErrorCode ERR

namespace err {

////////// XQuery Errors //////////////////////////////////////////////////////

/**
 * It is a static error if analysis of an expression relies on some component
 * of the static context that has not been assigned a value.
 */
XQUERY_DEC_ERROR( XPST0001 );

/**
 * It is a dynamic error if evaluation of an expression relies on some part of
 * the dynamic context that has not been assigned a value.
 */
XQUERY_DEC_ERROR( XPDY0002 );

/**
 * It is a static error if an expression is not a valid instance of the
 * grammar.
 */
XQUERY_DEC_ERROR( XPST0003 );

/**
 * It is a type error if, during the static analysis phase, an expression is
 * found to have a static type that is not appropriate for the context in which
 * the expression occurs, or during the dynamic evaluation phase, the dynamic
 * type of a value does not match a required type as specified by the matching
 * rules in 2.5.4 SequenceType Matching.
 */
XQUERY_DEC_ERROR( XPTY0004 );

/**
 * During the analysis phase, it is a static error if the static type assigned
 * to an expression other than the expression \c () or \c data(()) is
 * \c empty-sequence().
 */
XQUERY_DEC_ERROR( XPST0005 );

/**
 * It is a static error if an expression refers to an element name, attribute
 * name, schema type name, namespace prefix, or variable name that is not
 * defined in the static context, except for an ElementName in an ElementTest
 * or an AttributeName in an AttributeTest.
 */
XQUERY_DEC_ERROR( XPST0008 );

/**
 * An implementation that does not support the Schema Import Feature must raise
 * a static error if a Prolog contains a schema import.
 */
XQUERY_DEC_ERROR( XQST0009 );

/**
 * It is a static error if the set of definitions contained in all schemas
 * imported by a Prolog do not satisfy the conditions for schema validity
 * specified in Sections 3 and 5 of [XML Schema] Part 1--i.e., each definition
 * must be valid, complete, and unique.
 */
XQUERY_DEC_ERROR( XQST0012 );

/**
 * It is a static error if an implementation recognizes a pragma but determines
 * that its content is invalid.
 */
XQUERY_DEC_ERROR( XQST0013 );

/**
 * It is a static error if the expanded QName and number of arguments in a
 * function call do not match the name and arity of a function signature in the
 * static context.
 */
XQUERY_DEC_ERROR( XPST0017 );

/**
 * It is a type error if the result of the last step in a path expression
 * contains both nodes and non-nodes.
 */
XQUERY_DEC_ERROR( XPTY0018 );

/**
 * It is a type error if the result of a step (other than the last step) in a
 * path expression contains an atomic value.
 */
XQUERY_DEC_ERROR( XPTY0019 );

/**
 * It is a type error if, in an axis step, the context item is not a node.
 */
XQUERY_DEC_ERROR( XPTY0020 );

/**
 * It is a static error if the value of a namespace declaration attribute is
 * not a URILiteral.
 */
XQUERY_DEC_ERROR( XQST0022 );

/**
 * It is a type error if the content sequence in an element constructor
 * contains an attribute node following a node that is not an attribute node.
 */
XQUERY_DEC_ERROR( XQTY0024 );

/**
 * It is a dynamic error if any attribute of a constructed element does not
 * have a name that is distinct from the names of all other attributes of the
 * constructed element.
 */
XQUERY_DEC_ERROR( XQDY0025 );

/**
 * It is a dynamic error if the result of the content expression of a computed
 * processing instruction constructor contains the string "?>".
 */
XQUERY_DEC_ERROR( XQDY0026 );

/**
 * In a validate expression, it is a dynamic error if the root element
 * information item in the PSVI resulting from validation does not have the
 * expected validity property: \c valid if validation mode is \c strict, or
 * either \c valid or \c notKnown if validation mode is \c lax.
 */
XQUERY_DEC_ERROR( XQDY0027 );

/**
 * It is a type error if the argument of a validate expression does not
 * evaluate to exactly one document or element node.
 */
XQUERY_DEC_ERROR( XQTY0030 );

/**
 * It is a static error if the version number specified in a version
 * declaration is not supported by the implementation.
 */
XQUERY_DEC_ERROR( XQST0031 );

/**
 * A static error is raised if a Prolog contains more than one base URI
 * declaration.
 */
XQUERY_DEC_ERROR( XQST0032 );

/**
 * It is a static error if a module contains multiple bindings for the same
 * namespace prefix.
 */
XQUERY_DEC_ERROR( XQST0033 );

/**
 * It is a static error if multiple functions declared or imported by a module
 * have the same number of arguments and their expanded QNames are equal (as
 * defined by the eq operator).
 */
XQUERY_DEC_ERROR( XQST0034 );

/**
 * It is a static error to import two schema components that both define the
 * same name in the same symbol space and in the same scope.
 */
XQUERY_DEC_ERROR( XQST0035 );

/**
 * It is a static error to import a module if the in-scope schema definitions
 * of the importing module do not include all of the following:
 *
 * -# An in-scope schema type for each type-name that appears:
 *    - in the type of a variable that is declared in the imported module and
 *      referenced in the importing module, OR
 *    - in a parameter-type or result-type of a function that is declared in
 *      the imported module and referenced in the importing module.
 * -# An in-scope element declaration for each element-name \c EN such that:
 *    - \c schema-element(EN) appears in the declared type of a variable in the
 *      imported module, and that variable is referenced in the importing
 *      module, OR
 *    - \c schema-element(EN) appears in a parameter-type or result-type of a
 *      function declared in the imported module, and that function is
 *      referenced in the importing module.
 * -# An in-scope attribute declaration for each attribute-name \c AN such that:
 *    - \c schema-attribute(AN) appears in the declared type of a variable in
 *      the imported module, and that variable is referenced in the importing
 *      module, OR
 *    - \c schema-attribute(AN) appears in a parameter-type or result-type of a
 *      function declared in the imported module, and that function is
 *      referenced in the importing module.
 */
XQUERY_DEC_ERROR( XQST0036 );

/**
 * It is a static error if a Prolog contains more than one default collation
 * declaration, or the value specified by a default collation declaration is
 * not present in statically known collations.
 */
XQUERY_DEC_ERROR( XQST0038 );

/**
 * It is a static error for a function declaration to have more than one
 * parameter with the same name.
 */
XQUERY_DEC_ERROR( XQST0039 );

/**
 * It is a static error if the attributes specified by a direct element
 * constructor do not have distinct expanded QNames.
 */
XQUERY_DEC_ERROR( XQST0040 );

/**
 * It is a dynamic error if the value of the name expression in a computed
 * processing instruction constructor cannot be cast to the type \c xs:NCName.
 */
XQUERY_DEC_ERROR( XQDY0041 );

/**
 * It is a static error the node-name of a node constructed by a computed
 * attribute constructor has any of the following properties:
 * - Its namespace prefix is \c xmlns.
 * - It has no namespace prefix and its local name is \c xmlns.
 * - Its namespace URI is <code>http://www.w3.org/2000/xmlns/</code>.
 * - Its namespace prefix is \c xml and its namespace URI is not
 *   <code>http://www.w3.org/XML/1998/namespace</code>.
 * - Its namespace prefix is other than \c xml and its namespace URI is
 *   <code>http://www.w3.org/XML/1998/namespace</code>.
 */
XQUERY_DEC_ERROR( XQDY0044 );

/**
 * It is a static error if the function name in a function declaration is in
 * one of the following namespaces:
 * <code>http://www.w3.org/XML/1998/namespace</code>,
 * <code>http://www.w3.org/2001/XMLSchema</code>,
 * <code>http://www.w3.org/2001/XMLSchema-instance</code>,
 * <code>http://www.w3.org/2005/xpath-functions</code>.
 */
XQUERY_DEC_ERROR( XQST0045 );

/**
 * An implementation MAY raise a static error if the value of a URILiteral is
 * of nonzero length and is not in the lexical space of \c xs:anyURI.
 */
XQUERY_DEC_ERROR( XQST0046 );

/**
 * It is a static error if multiple module imports in the same Prolog specify
 * the same target namespace.
 */
XQUERY_DEC_ERROR( XQST0047 );

/**
 * It is a static error if a function or variable declared in a library module
 * is not in the target namespace of the library module.
 */
XQUERY_DEC_ERROR( XQST0048 );

/**
 * It is a static error if two or more variables declared or imported by a
 * module have equal expanded QNames (as defined by the eq operator.)
 */
XQUERY_DEC_ERROR( XQST0049 );

/**
 * It is a dynamic error if the dynamic type of the operand of a treat
 * expression does not match the sequence type specified by the treat
 * expression. This error might also be raised by a path expression beginning
 * with "<code>/</code>" or "<code>//</code>" if the context node is not in a
 * tree that is rooted at a document node. This is because a leading
 * "<code>/</code>" or "<code>//</code>" in a path expression is an
 * abbreviation for an initial step that includes the clause \c treat as \c
 * document-node().
 */
XQUERY_DEC_ERROR( XPDY0050 );

/**
 * It is a static error if a QName that is used as an AtomicType in a
 * SequenceType is not defined in the in-scope schema types as an atomic type.
 */
XQUERY_DEC_ERROR( XPST0051 );

/**
 * It is a static error if a variable depends on itself.
 */
XQUERY_DEC_ERROR( XQST0054 );

/**
 * It is a static error if a Prolog contains more than one copy-namespaces
 * declaration.
 */
XQUERY_DEC_ERROR( XQST0055 );

/**
 * It is a static error if a schema import binds a namespace prefix but does
 * not specify a target namespace other than a zero-length string.
 */
XQUERY_DEC_ERROR( XQST0057 );

/**
 * It is a static error if multiple schema imports specify the same target
 * namespace.
 */
XQUERY_DEC_ERROR( XQST0058 );

/**
 * It is a static error if an implementation is unable to process a schema or
 * module import by finding a schema or module with the specified target
 * namespace.
 */
XQUERY_DEC_ERROR( XQST0059 );

/**
 * It is a static error if the name of a function in a function declaration is
 * not in a namespace (expanded QName has a null namespace URI).
 */
XQUERY_DEC_ERROR( XQST0060 );

/**
 * It is a dynamic error if the operand of a validate expression is a document
 * node whose children do not consist of exactly one element node and zero or
 * more comment and processing instruction nodes, in any order.
 */
XQUERY_DEC_ERROR( XQDY0061 );

/**
 * It is a dynamic error if the value of the name expression in a computed
 * processing instruction constructor is equal to "XML" (in any combination of
 * upper and lower case).
 */
XQUERY_DEC_ERROR( XQDY0064 );

/**
 * A static error is raised if a Prolog contains more than one ordering mode
 * declaration.
 */
XQUERY_DEC_ERROR( XQST0065 );

/**
 * A static error is raised if a Prolog contains more than one default
 * element/type namespace declaration, or more than one default function
 * namespace declaration.
 */
XQUERY_DEC_ERROR( XQST0066 );

/**
 * A static error is raised if a Prolog contains more than one construction
 * declaration.
 */
XQUERY_DEC_ERROR( XQST0067 );

/**
 * A static error is raised if a Prolog contains more than one boundary-space
 * declaration.
 */
XQUERY_DEC_ERROR( XQST0068 );

/**
 * A static error is raised if a Prolog contains more than one empty order
 * declaration.
 */
XQUERY_DEC_ERROR( XQST0069 );

/**
 * A static error is raised if one of the predefined prefixes \c xml or \c
 * xmlns appears in a namespace declaration, or if any of the following
 * conditions is statically detected in any expression or declaration:
 * - The prefix \c xml is bound to some namespace URI other than
 *   <code>http://www.w3.org/XML/1998/namespace</code>.
 * - A prefix other than \c xml is bound to the namespace URI
 *   <code>http://www.w3.org/XML/1998/namespace</code>.
 * - The prefix \c xmlns is bound to any namespace URI.
 * - A prefix other than \c xmlns is bound to the namespace URI
 *   <code>http://www.w3.org/2000/xmlns/</code>.
 */
XQUERY_DEC_ERROR( XQST0070 );

/**
 * A static error is raised if the namespace declaration attributes of a direct
 * element constructor do not have distinct names.
 */
XQUERY_DEC_ERROR( XQST0071 );

/**
 * It is a dynamic error if the result of the content expression of a computed
 * comment constructor contains two adjacent hyphens or ends with a hyphen.
 */
XQUERY_DEC_ERROR( XQDY0072 );

/**
 * It is a dynamic error if the value of the name expression in a computed
 * element or attribute constructor cannot be converted to an expanded QName
 * (for example, because it contains a namespace prefix not found in statically
 * known namespaces).
 */
XQUERY_DEC_ERROR( XQDY0074 );

/**
 * It is a static error if a \c collation subclause in an order by clause of a
 * FLWOR expression does not identify a collation that is present in statically
 * known collations.
 */
XQUERY_DEC_ERROR( XQST0076 );

/**
 * It is a static error if an extension expression contains neither a pragma
 * that is recognized by the implementation nor an expression enclosed in curly
 * braces.
 */
XQUERY_DEC_ERROR( XQST0079 );

/**
 * It is a static error if the target type of a \c cast or \c castable
 * expression is \c xs:NOTATION or \c xs:anyAtomicType.
 */
XQUERY_DEC_ERROR( XPST0080 );

/**
 * It is a static error if a QName used in a query contains a namespace prefix
 * that cannot be expanded into a namespace URI by using the statically known
 * namespaces.
 */
XQUERY_DEC_ERROR( XPST0081 );

/**
 * It is a static error if the target type of a \c cast expression or
 * constructor function is \c xs:QName or a type derived from \c xs:QName or \c
 * xs:NOTATION, and the argument of the cast expression or constructor function
 * is not a string literal.
 */
XQUERY_DEC_ERROR( XPST0083 );

/**
 * It is a dynamic error if the element validated by a \c validate statement
 * does not have a top-level element declaration in the in-scope element
 * declarations, if validation mode is \c strict.
 */
XQUERY_DEC_ERROR( XQDY0084 );

/**
 * It is a static error if the namespace URI in a namespace declaration
 * attribute is a zero-length string, and the implementation does not support
 * [XML Names 1.1].
 */
XQUERY_DEC_ERROR( XQST0085 );

/**
 * It is a type error if the typed value of a copied element or attribute node
 * is namespace-sensitive when construction mode is \c preserve and
 * copy-namespaces mode is \c no-preserve.
 */
XQUERY_DEC_ERROR( XQTY0086 );

/**
 * It is a static error if the encoding specified in a Version Declaration does
 * not conform to the definition of \c EncName specified in [XML 1.0]
 */
XQUERY_DEC_ERROR( XQST0087 );

/**
 * It is a static error if the literal that specifies the target namespace in a
 * module import or a module declaration is of zero length.
 */
XQUERY_DEC_ERROR( XQST0088 );

/**
 * It is a static error if a variable bound in a \c for or \c window clause of
 * a FLWOR expression, and its associated positional variable, do not have
 * distinct names (expanded QNames).
 */
XQUERY_DEC_ERROR( XQST0089 );

/**
 * It is a static error if a character reference does not identify a valid
 * character in the version of XML that is in use.
 */
XQUERY_DEC_ERROR( XQST0090 );

/**
 * An implementation MAY raise a dynamic error if an \c xml:id error, as
 * defined in [XML ID], is encountered during construction of an attribute
 * named \c xml:id.
 */
XQUERY_DEC_ERROR( XQDY0091 );

/**
 * An implementation MAY raise a dynamic error if a constructed attribute named
 * \c xml:space has a value other than \c preserve or \c default.
 */
XQUERY_DEC_ERROR( XQDY0092 );

/**
 * It is a static error to import a module M1 if there exists a sequence of
 * modules M1 ... Mi ... M1 such that each module directly depends on the next
 * module in the sequence (informally, if M1 depends on itself through some
 * chain of module dependencies.)
 */
XQUERY_DEC_ERROR( XQST0093 );

/**
 * It is a dynamic error the node-name of a node constructed by a computed
 * element constructor has any of the following properties:
 * - Its namespace prefix is \c xmlns.
 * - Its namespace URI is <code>http://www.w3.org/2000/xmlns/</code>.
 * - Its namespace prefix is \c xml and its namespace URI is not
 *   <code>http://www.w3.org/XML/1998/namespace</code>.
 * - Its namespace prefix is other than \c xml and its namespace URI is
 *   <code>http://www.w3.org/XML/1998/namespace</code>.
 */
XQUERY_DEC_ERROR( XQDY0096 );

/**
 * It is a static error if, for any named or unnamed decimal format, the
 * properties representing characters used in a picture string do not each have
 * distinct values. These properties are decimal-separator-sign,
 * grouping-separator, percent-sign, per-mille-sign, zero-digit, digit-sign,
 * and pattern-separator-sign.
 */
XQUERY_DEC_ERROR( XQST0098 );

/**
 * It is a static error if a function's annotations contain more than one
 * annotation named \c private or \c public.  It is a static error if a
 * function's annotations contain more than one annotation named \c
 * deterministic or \c nondeterministic.
 */
XQUERY_DEC_ERROR( XQST0106 );

/**
 * It is a static error for a query prolog to contain two decimal formats with
 * the same name, or to contain two default decimal formats.
 */
XQUERY_DEC_ERROR( XQST0111 );

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
 * \c $value.
 */
XQUERY_DEC_ERROR( XTDE1350 );

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
 * Invalid argument to \c fn:collection().
 */
XQUERY_DEC_ERROR( FODC0004 );

/**
 * Invalid argument to \c fn:doc() or \c fn:doc-available().
 */
XQUERY_DEC_ERROR( FODC0005 );

/**
 * Invalid content passed to \c fn:parse().
 */
XQUERY_DEC_ERROR( FODC0006 );

/**
 * Base URI passed to \c fn:parse() is not a valid absolute URI.
 */
XQUERY_DEC_ERROR( FODC0007 );

/**
 * Invalid decimal format name supplied to \c fn:format-number().
 */
XQUERY_DEC_ERROR( FODF1280 );

/**
 * Invalid \c fn:format-number() picture string.
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
 * format-integer: Cannot cast $language to \c xs:language.
 */
XQUERY_DEC_ERROR( FOFI0001 );

/**
 * format-integer: invalid parameter.
 */
XQUERY_DEC_ERROR( FOFI0002 );

/**
 * No namespace found for prefix.
 */
XQUERY_DEC_ERROR( FONS0004 );

/**
 * Base-URI not defined in static context.
 */
XQUERY_DEC_ERROR( FONS0005 );

/**
 * Invalid value for cast/constructor.
 */
XQUERY_DEC_ERROR( FORG0001 );

/**
 * Invalid argument to \c fn:resolve-uri().
 */
XQUERY_DEC_ERROR( FORG0002 );

/**
 * \c fn:zero-or-one() called with a sequence containing more than one
 * item.
 */
XQUERY_DEC_ERROR( FORG0003 );

/**
 * \c fn:one-or-more() called with a sequence containing no items.
 */
XQUERY_DEC_ERROR( FORG0004 );

/**
 * \c fn:exactly-one() called with a sequence containing zero or more
 * than one item.
 */
XQUERY_DEC_ERROR( FORG0005 );

/**
 * Invalid argument type.
 */
XQUERY_DEC_ERROR( FORG0006 );

/**
 * The two arguments to fn:dateTime() have inconsistent timezones.
 */
XQUERY_DEC_ERROR( FORG0008 );

/**
 * Error in resolving a relative URI against a base URI in \c fn:resolve-uri().
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
 * An argument to \c fn:data() contains a node that does not have a typed
 * value.
 */
XQUERY_DEC_ERROR( FOTY0013 );

/**
 * The argument to \c fn:string() is a function item.
 */
XQUERY_DEC_ERROR( FOTY0014 );

/**
 * An argument to \c fn:deep-equal() contains a function item.
 */
XQUERY_DEC_ERROR( FOTY0015 );

////////// XQuery Scripting ///////////////////////////////////////////////////

XQUERY_DEC_ERROR( XSST0001 );
XQUERY_DEC_ERROR( XSST0002 );
XQUERY_DEC_ERROR( XSST0003 );
XQUERY_DEC_ERROR( XSST0004 );
XQUERY_DEC_ERROR( XSST0005 );
XQUERY_DEC_ERROR( XSST0006 );
XQUERY_DEC_ERROR( XSST0007 );
XQUERY_DEC_ERROR( XSST0008 );

////////// XQuery Update Facility /////////////////////////////////////////////

/**
 * It is a static error if an updating expression is used in any position other
 * than one of the following:
 * - The topmost expression in the body of a query.
 * - The \c modify clause of a transform expression.
 * - The \c return clause of a FLWOR expression.
 * - The \c return clauses of a typeswitch expression in which every \c return
 *   clause contains an updating expression or a vacuous expression.
 * - The \c then and \c else clauses of a conditional statement in which both
 *   the \c then and \c else clauses contain either an updating expression or a
 *   vacuous expression.
 * - An operand of a comma expression in which each operand is either an
 *   updating expression or a vacuous expression.
 * - The content of a parenthesized expression.
 * - The body of a function declaration in which the keyword \c updating is
 *   specified.
 */
XQUERY_DEC_ERROR( XUST0001 );

/**
 * It is a static error if a simple expression that is not a vacuous expression
 * is used in one of the following positions:
 * - The \c modify clause of a transform expression.
 * - The top-level expression in the body of a function declaration in which
 *   the keyword \c updating is specified.
 */
XQUERY_DEC_ERROR( XUST0002 );

/**
 * It is a static error if a Prolog contains more than one revalidation
 * declaration.
 */
XQUERY_DEC_ERROR( XUST0003 );

/**
 * It is a type error if the insertion sequence of an insert expression
 * contains an attribute node following a node that is not an attribute node.
 */
XQUERY_DEC_ERROR( XUTY0004 );

/**
 * In an insert expression where <code>into</code>, <code>as first into</code>,
 * or <code>as last into</code> is specified, it is a type error if the target
 * expression returns a non-empty result that does not consist of a single
 * element or document node.
 */
XQUERY_DEC_ERROR( XUTY0005 );

/**
 * In an insert expression where \c before or \c after is specified, it is a
 * type error if the target expression returns a non-empty result that does not
 * consist of a single element, text, comment, or processing instruction node.
 */
XQUERY_DEC_ERROR( XUTY0006 );

/**
 * It is a type error if the target expression of a delete expression does not
 * return a sequence of zero or more nodes.
 */
XQUERY_DEC_ERROR( XUTY0007 );

/**
 * In a replace expression, it is a type error if the target expression returns
 * a non-empty result that does not consist of a single element, attribute,
 * text, comment, or processing instruction node.
 */
XQUERY_DEC_ERROR( XUTY0008 );

/**
 * In a replace expression where <code>value of</code> is not specified, it is
 * a dynamic error if the node returned by the target expression does not have
 * a parent.
 */
XQUERY_DEC_ERROR( XUDY0009 );

/**
 * In a replace expression where <code>value of</code> is not specified and the
 * target is an element, text, comment, or processing instruction node, it is a
 * type error if the replacement sequence does not consist of zero or more
 * element, text, comment, or processing instruction nodes.
 */
XQUERY_DEC_ERROR( XUTY0010 );

/**
 * In a replace expression where <code>value of</code> is not specified and the
 * target is an attribute node, it is a type error if the replacement sequence
 * does not consist of zero or more attribute nodes.
 */
XQUERY_DEC_ERROR( XUTY0011 );

/**
 * In a rename expression, it is a type error if the target expression returns
 * a non-empty result that does not consist of a single element, attribute, or
 * processing instruction node.
 */
XQUERY_DEC_ERROR( XUTY0012 );

/**
 * In a transform expression, it is a type error if a source expression in the
 * \c copy clause does not return a single node.
 */
XQUERY_DEC_ERROR( XUTY0013 );

/**
 * In a transform expression, it is a dynamic error if the \c modify clause
 * modifies any node that was not created by the \c copy clause.
 */
XQUERY_DEC_ERROR( XUDY0014 );

/**
 * It is a dynamic error if any node is the target of more than one \c rename
 * expression within the same query.
 */
XQUERY_DEC_ERROR( XUDY0015 );

/**
 * It is a dynamic error if any node is the target of more than one \c replace
 * expression (without <code>value of</code> being specified) within the same
 * query.
 */
XQUERY_DEC_ERROR( XUDY0016 );

/**
 * It is a dynamic error if any node is the target of more than one
 * <code>replace value of</code> expression within the same query.
 */
XQUERY_DEC_ERROR( XUDY0017 );

/**
 * It is a dynamic error if a function that was declared to be \c external but
 * not \c updating returns a non-empty pending update list.
 */
XQUERY_DEC_ERROR( XUDY0018 );

/**
 * It is a dynamic error if a function that was declared to be both \c external
 * and \c updating returns a non-empty data model instance.
 */
XQUERY_DEC_ERROR( XUDY0019 );

/**
 * It is a dynamic error if the XDM instance that would result from applying
 * all the updates in a query violates any constraint specified in [XQuery 1.0
 * and XPath 2.0 Data Model]. In this case, none of the updates in the query
 * are made effective.
 */
XQUERY_DEC_ERROR( XUDY0021 );

/**
 * It is a type error if an insert expression specifies the insertion of an
 * attribute node into a document node.
 */
XQUERY_DEC_ERROR( XUTY0022 );

/**
 * It is a dynamic error if an insert, replace, or rename expression affects an
 * element node by introducing a new namespace binding that conflicts with one
 * of its existing namespace bindings.
 */
XQUERY_DEC_ERROR( XUDY0023 );

/**
 * It is a dynamic error if the effect of a set of updating expressions is to
 * introduce conflicting namespace bindings into an element node.
 */
XQUERY_DEC_ERROR( XUDY0024 );

/**
 * It is a dynamic error if the target expression of an insert, replace, or
 * rename expression evaluates to an empty sequence.
 */
XQUERY_DEC_ERROR( XUDY0027 );

/**
 * It is a static error if a function declaration specifies both \c updating
 * and a return type.
 */
XQUERY_DEC_ERROR( XUST0028 );

/**
 * In an insert expression where \c before or \c after is specified, it is a
 * dynamic error if the node returned by the target expression does not have a
 * parent.
 */
XQUERY_DEC_ERROR( XUDY0029 );

/**
 * It is a dynamic error if an insert expression specifies the insertion of an
 * attribute node before or after a child of a document node.
 */
XQUERY_DEC_ERROR( XUDY0030 );

/**
 * It is a dynamic error if multiple calls to \c fn:put() in the same snapshot
 * specify the same URI (after resolution of relative URIs).
 */
XQUERY_DEC_ERROR( XUDY0031 );

/**
 * It is a dynamic error if the first operand of \c fn:put() is not a node of a
 * supported kind.
 */
XQUERY_DEC_ERROR( FOUP0001 );

/**
 * It is a dynamic error if the second operand of \c fn:put() is not a valid
 * lexical representation of the \c xs:anyURI type.
 */
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

///////////////////////////////////////////////////////////////////////////////

} // namespace err

#undef XQUERY_DEC_ERROR
#define ZORBA_DEC_ERROR(ERR) extern ZORBA_DLL_PUBLIC ZorbaErrorCode ERR

namespace zerr {

////////// Zorba XQuery Processor Errors //////////////////////////////////////

/**
 * An "error" constant for "no error."
 */
ZORBA_DEC_ERROR( ZXQP0000_NO_ERROR );

ZORBA_DEC_ERROR( ZXQP0001_DYNAMIC_RUNTIME_ERROR );

/**
 * A Zorba programming assertion failed.  If this error occurs, it is a bug and
 * should be reported.
 */
ZORBA_DEC_ERROR( ZXQP0002_ASSERT_FAILED );

/**
 * Something unexpected occurred in Zorba.  If this error occurs, it is a bug
 * and should be reported.
 */
ZORBA_DEC_ERROR( ZXQP0003_INTERNAL_ERROR );

/**
 * A particular XQuery feature has not been implemented by Zorba.
 */
ZORBA_DEC_ERROR( ZXQP0004_NOT_IMPLEMENTED );

/**
 * A particular XQuery feature has been implemented by Zorba, but the feature
 * has not been enabled in the current build.
 */
ZORBA_DEC_ERROR( ZXQP0005_NOT_ENABLED );

ZORBA_DEC_ERROR( ZXQP0007_FUNCTION_SIGNATURE_NOT_EQUAL );
ZORBA_DEC_ERROR( ZXQP0008_FUNCTION_IMPL_NOT_FOUND );
ZORBA_DEC_ERROR( ZXQP0009_FUNCTION_LOCALNAME_MISMATCH );
ZORBA_DEC_ERROR( ZXQP0013_FXCHARHEAP_EXCEPTION );
ZORBA_DEC_ERROR( ZXQP0016_RESERVED_MODULE_TARGET_NAMESPACE );
ZORBA_DEC_ERROR( ZXQP0017_FILE_ACCESS_DISABLED );
ZORBA_DEC_ERROR( ZXQP0020_INVALID_URI );
ZORBA_DEC_ERROR( ZXQP0021_USER_ERROR );
ZORBA_DEC_ERROR( ZXQP0024_XML_DOES_NOT_MATCH_SCHEMA );
ZORBA_DEC_ERROR( ZXQP0025_ITEM_CREATION_FAILED );
ZORBA_DEC_ERROR( ZXQP0027_MS_DOM_ERROR );
ZORBA_DEC_ERROR( ZXQP0028_TARGET_NAMESPACE_NOT_PROVIDED );
ZORBA_DEC_ERROR( ZXQP0029_MODULE_IMPORT_NOT_ALLOWED );
ZORBA_DEC_ERROR( ZXQP0030_DEADLOCK );
ZORBA_DEC_ERROR( ZXQP0031_MALFORMED_XQUERYX_INPUT );
ZORBA_DEC_ERROR( ZXQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY );
ZORBA_DEC_ERROR( ZXQP0036_BREAKITERATOR_CREATION_FAILED );

#ifndef ZORBA_NO_FULL_TEXT
/**
 * The version of the thesaurus is not the expected version.
 */
ZORBA_DEC_ERROR( ZXQP8401_THESAURUS_VERSION_MISMATCH );

/**
 * The thesaurus data file's endianness does not match that of the CPU.
 */
ZORBA_DEC_ERROR( ZXQP8402_THESAURUS_ENDIANNESS_MISMATCH );

/**
 * The thesaurus data contains an unexpected value.
 */
ZORBA_DEC_ERROR( ZXQP8403_THESAURUS_DATA_ERROR );
#endif /* ZORBA_NO_FULL_TEXT */

ZORBA_DEC_ERROR( ZXQD0001_PREFIX_NOT_DECLARED );
ZORBA_DEC_ERROR( ZXQD0002_DOCUMENT_NOT_VALID );

////////// Zorba API Errors ///////////////////////////////////////////////////

ZORBA_DEC_ERROR( ZAPI0002_XQUERY_COMPILATION_FAILED );
ZORBA_DEC_ERROR( ZAPI0003_XQUERY_NOT_COMPILED );
ZORBA_DEC_ERROR( ZAPI0004_XQUERY_ALREADY_COMPILED );
ZORBA_DEC_ERROR( ZAPI0005_XQUERY_ALREADY_EXECUTING );
ZORBA_DEC_ERROR( ZAPI0006_XQUERY_ALREADY_CLOSED );
ZORBA_DEC_ERROR( ZAPI0007_CANNOT_SERIALIZE_PUL );
ZORBA_DEC_ERROR( ZAPI0008_NOT_AN_UPDATE_XQUERY );
ZORBA_DEC_ERROR( ZAPI0009_XQUERY_NOT_COMPILED_IN_DEBUG_MODE );
ZORBA_DEC_ERROR( ZAPI0014_INVALID_ARGUMENT );
ZORBA_DEC_ERROR( ZAPI0015_CREATEMODULE_NOT_FOUND );
ZORBA_DEC_ERROR( ZAPI0019_MODULE_ALREADY_REGISTERED );
ZORBA_DEC_ERROR( ZAPI0020_DOCUMENT_ALREADY_EXISTS );
ZORBA_DEC_ERROR( ZAPI0021_ITEM_TO_LOAD_IS_NOT_NODE );
ZORBA_DEC_ERROR( ZAPI0027_CANNOT_UPDATE_DCTX_WITH_ITERATORS );
ZORBA_DEC_ERROR( ZAPI0028_INVALID_NODE_URI );
ZORBA_DEC_ERROR( ZAPI0039_XQUERY_HAS_ITERATOR_ALREADY );
ZORBA_DEC_ERROR( ZAPI0040_ITERATOR_NOT_OPEN );
ZORBA_DEC_ERROR( ZAPI0041_ITERATOR_ALREADY_OPEN );
ZORBA_DEC_ERROR( ZAPI0042_ITERATOR_CLOSED );
ZORBA_DEC_ERROR( ZAPI0051_REST_ERROR_PAYLOAD );
ZORBA_DEC_ERROR( ZAPI0070_INVALID_SERIALIZATION_METHOD_FOR_SAX );

////////// Zorba Class Serialization Errors ///////////////////////////////////

ZORBA_DEC_ERROR( ZCSE0001_NONEXISTENT_INPUT_FIELD );
ZORBA_DEC_ERROR( ZCSE0002_INCOMPATIBLE_INPUT_FIELD );
ZORBA_DEC_ERROR( ZCSE0003_UNRECOGNIZED_CLASS_FIELD );
ZORBA_DEC_ERROR( ZCSE0004_UNRESOLVED_FIELD_REFERENCE );
ZORBA_DEC_ERROR( ZCSE0005_CLASS_VERSION_TOO_NEW );
ZORBA_DEC_ERROR( ZCSE0006_CLASS_VERSION_TOO_OLD );
ZORBA_DEC_ERROR( ZCSE0007_INPUT_ARCHIVE_USED_FOR_OUT_SERIALIZATION );
ZORBA_DEC_ERROR( ZCSE0008_OUTPUT_ARCHIVE_USED_FOR_IN_SERIALIZATION );
ZORBA_DEC_ERROR( ZCSE0009_CLASS_NOT_SERIALIZABLE );
ZORBA_DEC_ERROR( ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE );
ZORBA_DEC_ERROR( ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE );
ZORBA_DEC_ERROR( ZCSE0012_INCOMPATIBLE_ARCHIVE_VERSION );
ZORBA_DEC_ERROR( ZCSE0013_UNABLE_TO_LOAD_QUERY );
ZORBA_DEC_ERROR( ZCSE0014_INFINITE_CIRCULAR_DEPENDENCIES );
ZORBA_DEC_ERROR( ZCSE0015_INCOMPATIBLE_BETWEEN_32_AND_64_BITS_OR_LE_AND_BE );
ZORBA_DEC_ERROR( ZCSE0016_CANNOT_LOAD_FROM_RELEASE_TO_DEBUG );
ZORBA_DEC_ERROR( ZCSE0017_CANNOT_LOAD_FROM_DEBUG_TO_RELEASE );

////////// Zorba Data Definition Facility Errors //////////////////////////////

ZORBA_DEC_ERROR( ZDDY0001_COLLECTION_NOT_DECLARED );
ZORBA_DEC_ERROR( ZDDY0002_COLLECTION_ALREADY_EXISTS );
ZORBA_DEC_ERROR( ZDDY0003_COLLECTION_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( ZDDY0004_COLLECTION_CONST_UPDATE );
ZORBA_DEC_ERROR( ZDDY0005_COLLECTION_APPEND_BAD_INSERT );
ZORBA_DEC_ERROR( ZDDY0006_COLLECTION_QUEUE_BAD_INSERT );
ZORBA_DEC_ERROR( ZDDY0007_COLLECTION_APPEND_BAD_DELETE );
ZORBA_DEC_ERROR( ZDDY0008_COLLECTION_QUEUE_BAD_DELETE );
ZORBA_DEC_ERROR( ZDDY0009_COLLECTION_QUEUE_BAD_DELETE );
ZORBA_DEC_ERROR( ZDDY0010_COLLECTION_CONST_NODE_UPDATE );
ZORBA_DEC_ERROR( ZDDY0011_COLLECTION_NODE_NOT_FOUND );
ZORBA_DEC_ERROR( ZDDY0012_COLLECTION_UNORDERED_BAD_INSERT );
ZORBA_DEC_ERROR( ZDDY0013_COLLECTION_BAD_DESTROY_INDEXES );
ZORBA_DEC_ERROR( ZDDY0014_COLLECTION_BAD_DESTROY_ICS );
ZORBA_DEC_ERROR( ZDDY0015_COLLECTION_BAD_DESTROY_NODES );
ZORBA_DEC_ERROR( ZDDY0016_COLLECTION_MULTIPLE_CREATES );
ZORBA_DEC_ERROR( ZDDY0017_NODE_IS_ORPHAN );
ZORBA_DEC_ERROR( ZDDY0018_NODES_NOT_IN_SAME_COLLECTION );
ZORBA_DEC_ERROR( ZDDY0020_INDEX_DOMAIN_NODE_NOT_IN_COLLECTION );
ZORBA_DEC_ERROR( ZDDY0021_INDEX_NOT_DECLARED );
ZORBA_DEC_ERROR( ZDDY0022_INDEX_ALREADY_EXISTS );
ZORBA_DEC_ERROR( ZDDY0023_INDEX_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( ZDDY0024_INDEX_UNIQUE_VIOLATION );
ZORBA_DEC_ERROR( ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS );
ZORBA_DEC_ERROR( ZDDY0026_INDEX_RANGE_PROBE_NOT_ALLOWED );
ZORBA_DEC_ERROR( ZDDY0027_INDEX_MULTIPLE_CREATES );
ZORBA_DEC_ERROR( ZDDY0028_INDEX_DOMAIN_HAS_DUPLICATE_NODES );
ZORBA_DEC_ERROR( ZDDY0029_INDEX_GENERAL_PROBE_NOT_ALLOWED );
ZORBA_DEC_ERROR( ZDDY0031_IC_NOT_DECLARED );
ZORBA_DEC_ERROR( ZDDY0032_IC_NOT_ACTIVATED );
ZORBA_DEC_ERROR( ZDDY0033_IC_NOT_MET );

ZORBA_DEC_ERROR( ZDST0001_COLLECTION_ALREADY_DECLARED );
ZORBA_DEC_ERROR( ZDST0002_COLLECTION_ALREADY_IMPORTED );
ZORBA_DEC_ERROR( ZDST0003_COLLECTION_DECL_IN_MAIN_MODULE );
ZORBA_DEC_ERROR( ZDST0004_COLLECTION_MULTIPLE_PROPERTY_VALUES );
ZORBA_DEC_ERROR( ZDST0005_COLLECTION_PROPERTIES_CONFLICT );
ZORBA_DEC_ERROR( ZDST0006_COLLECTION_INVALID_PROPERTY_VALUE );
ZORBA_DEC_ERROR( ZDST0007_COLLECTION_DECL_IN_FOREIGN_MODULE );
ZORBA_DEC_ERROR( ZDST0021_INDEX_ALREADY_DECLARED );
ZORBA_DEC_ERROR( ZDST0022_INDEX_ALREADY_IMPORTED );
ZORBA_DEC_ERROR( ZDST0023_INDEX_DECL_IN_MAIN_MODULE );
ZORBA_DEC_ERROR( ZDST0024_INDEX_MULTIPLE_PROPERTY_VALUES );
ZORBA_DEC_ERROR( ZDST0026_INDEX_INVALID_PROPERTY_VALUE );
ZORBA_DEC_ERROR( ZDST0027_INDEX_BAD_KEY_TYPE );
ZORBA_DEC_ERROR( ZDST0028_INDEX_NOT_DETERMINISTIC );
ZORBA_DEC_ERROR( ZDST0029_INDEX_INVALID_DATA_SOURCE );
ZORBA_DEC_ERROR( ZDST0030_INDEX_NON_CONST_DATA_SOURCE );
ZORBA_DEC_ERROR( ZDST0031_INDEX_HAS_FREE_VARS );
ZORBA_DEC_ERROR( ZDST0032_INDEX_REFERENCES_CTX_ITEM );
ZORBA_DEC_ERROR( ZDST0033_INDEX_NON_SIMPLE_EXPR );
ZORBA_DEC_ERROR( ZDST0034_INDEX_CANNOT_DO_AUTOMATIC_MAINTENANCE );
ZORBA_DEC_ERROR( ZDST0035_INDEX_GENERAL_MULTIKEY );
ZORBA_DEC_ERROR( ZDST0036_INDEX_DECL_IN_FOREIGN_MODULE );
ZORBA_DEC_ERROR( ZDST0041_IC_ALREADY_DECLARED );
ZORBA_DEC_ERROR( ZDST0044_IC_DECL_IN_MAIN_MODULE );
ZORBA_DEC_ERROR( ZDST0048_IC_DECL_IN_FOREIGN_MODULE );

ZORBA_DEC_ERROR( ZDTY0001_COLLECTION_INVALID_NODE_TYPE );
ZORBA_DEC_ERROR( ZDTY0010_INDEX_DOMAIN_TYPE_ERROR );
ZORBA_DEC_ERROR( ZDTY0011_INDEX_KEY_TYPE_ERROR );
ZORBA_DEC_ERROR( ZDTY0012_INDEX_KEY_TYPE_ERROR );

////////// Zorba Operating System Errors //////////////////////////////////////

ZORBA_DEC_ERROR( ZOSE0001_FILE_NOT_FOUND );
ZORBA_DEC_ERROR( ZOSE0002_NOT_PLAIN_FILE );
ZORBA_DEC_ERROR( ZOSE0003_STREAM_READ_FAILURE );
ZORBA_DEC_ERROR( ZOSE0004_IO_ERROR );

////////// Zorba Store Errors /////////////////////////////////////////////////

ZORBA_DEC_ERROR( ZSTR0001_INDEX_ALREADY_EXISTS );
ZORBA_DEC_ERROR( ZSTR0002_INDEX_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( ZSTR0003_INDEX_PARTIAL_KEY_INSERT );
ZORBA_DEC_ERROR( ZSTR0004_INDEX_PARTIAL_KEY_REMOVE );
ZORBA_DEC_ERROR( ZSTR0005_INDEX_PARTIAL_KEY_PROBE );
ZORBA_DEC_ERROR( ZSTR0006_INDEX_INVALID_BOX_PROBE );
ZORBA_DEC_ERROR( ZSTR0007_INDEX_UNSUPPORTED_PROBE_CONDITION );
ZORBA_DEC_ERROR( ZSTR0008_COLLECTION_ALREADY_EXISTS );
ZORBA_DEC_ERROR( ZSTR0009_COLLECTION_NOT_FOUND );
ZORBA_DEC_ERROR( ZSTR0010_COLLECTION_NODE_ALREADY_IN_COLLECTION );
ZORBA_DEC_ERROR( ZSTR0011_COLLECTION_NON_ROOT_NODE );
ZORBA_DEC_ERROR( ZSTR0012_COLLECTION_ITEM_MUST_BE_A_NODE );
ZORBA_DEC_ERROR( ZSTR0015_IC_ALREADY_EXISTS );
ZORBA_DEC_ERROR( ZSTR0016_IC_DOES_NOT_EXIST );
ZORBA_DEC_ERROR( ZSTR0020_LOADER_IO_ERROR );
ZORBA_DEC_ERROR( ZSTR0021_LOADER_PARSING_ERROR );
ZORBA_DEC_ERROR( ZSTR0030_NODEID_ERROR );
ZORBA_DEC_ERROR( ZSTR0040_TYPE_ERROR );
ZORBA_DEC_ERROR( ZSTR0041_NAN_COMPARISON );
ZORBA_DEC_ERROR( ZSTR0045_DUPLICATE_NODE_ERROR );
ZORBA_DEC_ERROR( ZSTR0050_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE );
ZORBA_DEC_ERROR( ZSTR0055_STREAMABLE_STRING_CONSUMED );

///////////////////////////////////////////////////////////////////////////////

#undef ZORBA_DEC_ERROR

} // namespace zerr
} // namespace zorba
#endif /* ZORBA_ERROR_LIST_API_H */
/* vim:set et sw=2 ts=2: */
