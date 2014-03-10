xquery version '1.0';

(:
 : Copyright 2006-2013 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)
 
 (:
  : THIS FILE IS GENERATED.
  : PLEASE DO NOT EDIT.
  :)

(:~
 : This module contains one variable declaration for each diagnostic of the
 : http://www.w3.org/2005/xqt-errors namespace.
 : The variables serves as documentation for the errors but can also
 : be used in the code. For example, one useful scenario is to compare
 : an error caught in the catch clause of a try-catch expression with one of
 : the variables.
 :
 : @author Carlos Lopez
 : @project W3C/XPath Error Codes
 :
 :)

module namespace err = 'http://www.w3.org/2005/xqt-errors';

declare variable $err:NS := 'http://www.w3.org/2005/xqt-errors';

(:~
 :
 : It is a static error if analysis of an expression relies on some
 : component of the static context that has not been assigned a value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0001 as xs:QName := fn:QName($err:NS, "err:XPST0001");

(:~
 :
 : It is a static error if an expression is not a valid instance of the
 : grammar.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0003 as xs:QName := fn:QName($err:NS, "err:XPST0003");

(:~
 :
 : During the analysis phase, it is a static error if the static type
 : assigned to an expression other than the expression \c () or \c data(())
 : is \c empty-sequence().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0005 as xs:QName := fn:QName($err:NS, "err:XPST0005");

(:~
 :
 : It is a static error if an expression refers to an element name,
 : attribute name, schema type name, namespace prefix, or variable name
 : that is not defined in the static context, except for an ElementName in
 : an ElementTest or an AttributeName in an AttributeTest.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0008 as xs:QName := fn:QName($err:NS, "err:XPST0008");

(:~
 :
 : It is a static error if the expanded QName and number of arguments in a
 : function call do not match the name and arity of a function signature in
 : the static context.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0017 as xs:QName := fn:QName($err:NS, "err:XPST0017");

(:~
 :
 : It is a static error if a QName that is used as an AtomicType in a
 : SequenceType is not defined in the in-scope schema types as an atomic
 : type.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0051 as xs:QName := fn:QName($err:NS, "err:XPST0051");

(:~
 :
 : It is a static error if the target type of a \c cast or \c castable
 : expression is \c xs:NOTATION or \c xs:anyAtomicType.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0080 as xs:QName := fn:QName($err:NS, "err:XPST0080");

(:~
 :
 : It is a static error if a QName used in a query contains a namespace
 : prefix that cannot be expanded into a namespace URI by using the
 : statically known namespaces.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0081 as xs:QName := fn:QName($err:NS, "err:XPST0081");

(:~
 :
 : It is a static error if the target type of a \c cast expression or
 : constructor function is \c xs:QName or a type derived from \c xs:QName
 : or \c xs:NOTATION, and the argument of the cast expression or
 : constructor function is not a string literal.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPST0083 as xs:QName := fn:QName($err:NS, "err:XPST0083");

(:~
 :
 : It is a type error if, during the static analysis phase, an expression
 : is found to have a static type that is not appropriate for the context
 : in which the expression occurs, or during the dynamic evaluation phase,
 : the dynamic type of a value does not match a required type as specified
 : by the matching rules in 2.5.4 SequenceType Matching.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPTY0004 as xs:QName := fn:QName($err:NS, "err:XPTY0004");

(:~
 :
 : It is a type error if the result of the last step in a path expression
 : contains both nodes and non-nodes.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPTY0018 as xs:QName := fn:QName($err:NS, "err:XPTY0018");

(:~
 :
 : It is a type error if the result of a step (other than the last step) in a
 : path expression contains an atomic value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPTY0019 as xs:QName := fn:QName($err:NS, "err:XPTY0019");

(:~
 :
 : It is a type error if, in an axis step, the context item is not a node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPTY0020 as xs:QName := fn:QName($err:NS, "err:XPTY0020");

(:~
 :
 : Attempt to cast to a namespace-sensitive type failed because the namespace
 : bindings for the result can not be determined.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPTY0117 as xs:QName := fn:QName($err:NS, "err:XPTY0117");

(:~
 :
 : It is a type error if the content sequence in an element constructor
 : contains an attribute node following a node that is not an attribute node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQTY0024 as xs:QName := fn:QName($err:NS, "err:XQTY0024");

(:~
 :
 : It is a type error if the argument of a validate expression does not
 : evaluate to exactly one document or element node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQTY0030 as xs:QName := fn:QName($err:NS, "err:XQTY0030");

(:~
 :
 : It is a type error if the typed value of a copied element or attribute
 : node is namespace-sensitive when construction mode is \c preserve and
 : copy-namespaces mode is \c no-preserve.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQTY0086 as xs:QName := fn:QName($err:NS, "err:XQTY0086");

(:~
 :
 : It is a type error if the content sequence in an element constructor contains a function item.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQTY0105 as xs:QName := fn:QName($err:NS, "err:XQTY0105");

(:~
 :
 : An implementation that does not support the Schema Import Feature must
 : raise a static error if a Prolog contains a schema import.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0009 as xs:QName := fn:QName($err:NS, "err:XQST0009");

(:~
 :
 : It is a static error if the set of definitions contained in all schemas
 : imported by a Prolog do not satisfy the conditions for schema validity
 : specified in Sections 3 and 5 of [XML Schema] Part 1--i.e., each
 : definition must be valid, complete, and unique.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0012 as xs:QName := fn:QName($err:NS, "err:XQST0012");

(:~
 :
 : It is a static error if an implementation recognizes a pragma but
 : determines that its content is invalid.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0013 as xs:QName := fn:QName($err:NS, "err:XQST0013");

(:~
 :
 : It is a static error if the value of a namespace declaration attribute is
 : not a URILiteral.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0022 as xs:QName := fn:QName($err:NS, "err:XQST0022");

(:~
 :
 : It is a static error if the version number specified in a version
 : declaration is not supported by the implementation.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0031 as xs:QName := fn:QName($err:NS, "err:XQST0031");

(:~
 :
 : A static error is raised if a Prolog contains more than one base URI
 : declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0032 as xs:QName := fn:QName($err:NS, "err:XQST0032");

(:~
 :
 : It is a static error if a module contains multiple bindings for the same
 : namespace prefix.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0033 as xs:QName := fn:QName($err:NS, "err:XQST0033");

(:~
 :
 : It is a static error if multiple functions declared or imported by a
 : module have the same number of arguments and their expanded QNames are
 : equal (as defined by the eq operator).
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0034 as xs:QName := fn:QName($err:NS, "err:XQST0034");

(:~
 :
 : It is a static error to import two schema components that both define the
 : same name in the same symbol space and in the same scope.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0035 as xs:QName := fn:QName($err:NS, "err:XQST0035");

(:~
 :
 : It is a static error to import a module if the in-scope schema
 : definitions of the importing module do not include all of the following:
 : 
 : -# An in-scope schema type for each type-name that appears:
 : - in the type of a variable that is declared in the imported module
 : and referenced in the importing module, OR
 : - in a parameter-type or result-type of a function that is declared in
 : the imported module and referenced in the importing module.
 : -# An in-scope element declaration for each element-name \c EN such that:
 : - \c schema-element(EN) appears in the declared type of a variable in
 : the imported module, and that variable is referenced in the
 : importing module, OR
 : - \c schema-element(EN) appears in a parameter-type or result-type
 : of a function declared in the imported module, and that function is
 : referenced in the importing module.
 : -# An in-scope attribute declaration for each attribute-name \c AN such
 : that:
 : - \c schema-attribute(AN) appears in the declared type of a variable
 : in the imported module, and that variable is referenced in the
 : importing module, OR
 : - \c schema-attribute(AN) appears in a parameter-type or result-type
 : of a function declared in the imported module, and that function is
 : referenced in the importing module.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0036 as xs:QName := fn:QName($err:NS, "err:XQST0036");

(:~
 :
 : It is a static error if a Prolog contains more than one default collation
 : declaration, or the value specified by a default collation declaration is
 : not present in statically known collations.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0038 as xs:QName := fn:QName($err:NS, "err:XQST0038");

(:~
 :
 : It is a static error for a function declaration to have more than one
 : parameter with the same name.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0039 as xs:QName := fn:QName($err:NS, "err:XQST0039");

(:~
 :
 : It is a static error if the attributes specified by a direct element
 : constructor do not have distinct expanded QNames.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0040 as xs:QName := fn:QName($err:NS, "err:XQST0040");

(:~
 :
 : It is a static error if the function name in a function declaration is in
 : one of the following namespaces:
 : http://www.w3.org/XML/1998/namespace,
 : http://www.w3.org/2001/XMLSchema,
 : http://www.w3.org/2001/XMLSchema-instance,
 : http://www.w3.org/2005/xpath-functions.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0045 as xs:QName := fn:QName($err:NS, "err:XQST0045");

(:~
 :
 : An implementation MAY raise a static error if the value of a URILiteral
 : is of nonzero length and is not in the lexical space of \c xs:anyURI.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0046 as xs:QName := fn:QName($err:NS, "err:XQST0046");

(:~
 :
 : It is a static error if multiple module imports in the same Prolog
 : specify the same target namespace.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0047 as xs:QName := fn:QName($err:NS, "err:XQST0047");

(:~
 :
 : It is a static error if a function or variable declared in a library
 : module is not in the target namespace of the library module.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0048 as xs:QName := fn:QName($err:NS, "err:XQST0048");

(:~
 :
 : It is a static error if two or more variables declared or imported by a
 : module have equal expanded QNames (as defined by the eq operator.)
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0049 as xs:QName := fn:QName($err:NS, "err:XQST0049");

(:~
 :
 : The type must be the name of a type defined in the in-scope schema types,
 : and the {variety} of the type must be simple.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0052 as xs:QName := fn:QName($err:NS, "err:XQST0052");

(:~
 :
 : It is a static error if a variable depends on itself.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0054 as xs:QName := fn:QName($err:NS, "err:XQST0054");

(:~
 :
 : It is a static error if a Prolog contains more than one copy-namespaces
 : declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0055 as xs:QName := fn:QName($err:NS, "err:XQST0055");

(:~
 :
 : It is a static error if a schema import binds a namespace prefix but
 : does not specify a target namespace other than a zero-length string.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0057 as xs:QName := fn:QName($err:NS, "err:XQST0057");

(:~
 :
 : It is a static error if multiple schema imports specify the same target
 : namespace.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0058 as xs:QName := fn:QName($err:NS, "err:XQST0058");

(:~
 :
 : It is a static error if an implementation is unable to process a schema
 : or module import by finding a schema or module with the specified
 : target namespace.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0059 as xs:QName := fn:QName($err:NS, "err:XQST0059");

(:~
 :
 : It is a static error if the name of a function in a function declaration
 : is not in a namespace (expanded QName has a null namespace URI).
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0060 as xs:QName := fn:QName($err:NS, "err:XQST0060");

(:~
 :
 : A static error is raised if a Prolog contains more than one ordering mode
 : declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0065 as xs:QName := fn:QName($err:NS, "err:XQST0065");

(:~
 :
 : A static error is raised if a Prolog contains more than one default
 : element/type namespace declaration, or more than one default function
 : namespace declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0066 as xs:QName := fn:QName($err:NS, "err:XQST0066");

(:~
 :
 : A static error is raised if a Prolog contains more than one construction
 : declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0067 as xs:QName := fn:QName($err:NS, "err:XQST0067");

(:~
 :
 : A static error is raised if a Prolog contains more than one
 : boundary-space declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0068 as xs:QName := fn:QName($err:NS, "err:XQST0068");

(:~
 :
 : A static error is raised if a Prolog contains more than one empty order
 : declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0069 as xs:QName := fn:QName($err:NS, "err:XQST0069");

(:~
 :
 : A static error is raised if one of the predefined prefixes \c xml or \c
 : xmlns appears in a namespace declaration, or if any of the following
 : conditions is statically detected in any expression or declaration:
 : - The prefix \c xml is bound to some namespace URI other than
 : http://www.w3.org/XML/1998/namespace.
 : - A prefix other than \c xml is bound to the namespace URI
 : http://www.w3.org/XML/1998/namespace.
 : - The prefix \c xmlns is bound to any namespace URI.
 : - A prefix other than \c xmlns is bound to the namespace URI
 : http://www.w3.org/2000/xmlns/.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0070 as xs:QName := fn:QName($err:NS, "err:XQST0070");

(:~
 :
 : A static error is raised if the namespace declaration attributes of a
 : direct element constructor do not have distinct names.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0071 as xs:QName := fn:QName($err:NS, "err:XQST0071");

(:~
 :
 : It is a static error if a \c collation subclause in an order by clause
 : of a FLWOR expression does not identify a collation that is present in
 : statically known collations.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0076 as xs:QName := fn:QName($err:NS, "err:XQST0076");

(:~
 :
 : It is a static error if an extension expression contains neither a
 : pragma that is recognized by the implementation nor an expression
 : enclosed in curly braces.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0079 as xs:QName := fn:QName($err:NS, "err:XQST0079");

(:~
 :
 : It is a static error if the namespace URI in a namespace declaration
 : attribute is a zero-length string, and the implementation does not
 : support [XML Names 1.1].
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0085 as xs:QName := fn:QName($err:NS, "err:XQST0085");

(:~
 :
 : It is a static error if the encoding specified in a Version Declaration
 : does not conform to the definition of \c EncName specified in [XML 1.0]
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0087 as xs:QName := fn:QName($err:NS, "err:XQST0087");

(:~
 :
 : It is a static error if the literal that specifies the target namespace
 : in a module import or a module declaration is of zero length.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0088 as xs:QName := fn:QName($err:NS, "err:XQST0088");

(:~
 :
 : It is a static error if a variable bound in a \c for or \c window clause
 : of a FLWOR expression, and its associated positional variable, do not
 : have distinct names (expanded QNames).
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0089 as xs:QName := fn:QName($err:NS, "err:XQST0089");

(:~
 :
 : It is a static error if a character reference does not identify a valid
 : character in the version of XML that is in use.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0090 as xs:QName := fn:QName($err:NS, "err:XQST0090");

(:~
 :
 : It is a static error to import a module M1 if there exists a sequence of
 : modules M1 ... Mi ... M1 such that each module directly depends on the
 : next module in the sequence (informally, if M1 depends on itself through
 : some chain of module dependencies.)
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0093 as xs:QName := fn:QName($err:NS, "err:XQST0093");

(:~
 :
 : In the group by clause of a FLWOR expression, it is a static error if the
 : name of a grouping variable is not equal (by the eq operator on expanded
 : QNames) to the name of a variable that is bound by a for or let clause
 : that precedes the group by clause.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0094 as xs:QName := fn:QName($err:NS, "err:XQST0094");

(:~
 :
 : It is a static error for a decimal-format to specify a value that is
 : not valid for a given property.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0097 as xs:QName := fn:QName($err:NS, "err:XQST0097");

(:~
 :
 : It is a static error if, for any named or unnamed decimal format, the
 : properties representing characters used in a picture string do not each
 : have distinct values. These properties are decimal-separator-sign,
 : grouping-separator, percent-sign, per-mille-sign, zero-digit,
 : digit-sign, and pattern-separator-sign.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0098 as xs:QName := fn:QName($err:NS, "err:XQST0098");

(:~
 :
 : If a module contains more than one context item declaration, a static error is raised [err:XQST0099].
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0099 as xs:QName := fn:QName($err:NS, "err:XQST0099");

(:~
 :
 : All variables in a window clause must have distinct names.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0103 as xs:QName := fn:QName($err:NS, "err:XQST0103");

(:~
 :
 : It is a static error if a function's annotations contain more than one
 : annotation named \c private or \c public.  It is a static error if a
 : function's annotations contain more than one annotation named \c
 : deterministic or \c nondeterministic.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0106 as xs:QName := fn:QName($err:NS, "err:XQST0106");

(:~
 :
 : It is a static error for a query prolog to contain two decimal formats
 : with the same name, or to contain two default decimal formats.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0111 as xs:QName := fn:QName($err:NS, "err:XQST0111");

(:~
 :
 : Specifying a VarValue or VarDefaultValue for a context item declaration
 : in a library module is a static error.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0113 as xs:QName := fn:QName($err:NS, "err:XQST0113");

(:~
 :
 : It is a static error for a decimal format declaration to define the
 : same property more than once.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0114 as xs:QName := fn:QName($err:NS, "err:XQST0114");

(:~
 :
 : It is a static error if a variable declaration contains both a %private
 : and a %public annotation, more than one %private annotation, or more
 : than one %public annotation.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0116 as xs:QName := fn:QName($err:NS, "err:XQST0116");

(:~
 :
 : It is a static error if a feature required by require-feature is not
 : supported by the implementation.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0120 as xs:QName := fn:QName($err:NS, "err:XQST0120");

(:~
 :
 : It is a static error if the name of a feature in require-feature or
 : prohibit-feature is not in the lexical space of QName.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0122 as xs:QName := fn:QName($err:NS, "err:XQST0122");

(:~
 :
 : It is a static error if the name of a feature in require-feature is not
 : recognized by the implementation.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0123 as xs:QName := fn:QName($err:NS, "err:XQST0123");

(:~
 :
 : It is a static error if all-extensions appears in a require-feature option declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0126 as xs:QName := fn:QName($err:NS, "err:XQST0126");

(:~
 :
 : It is a static error if a given feature is both required and prohibited, directly or indirectly, in a module.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0127 as xs:QName := fn:QName($err:NS, "err:XQST0127");

(:~
 :
 : It is a static error if a feature name that an implementation supports appears
 : in a prohibit-feature option declaration, and the implementation is unable to
 : disable the feature.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQST0128 as xs:QName := fn:QName($err:NS, "err:XQST0128");

(:~
 :
 : It is a dynamic error if evaluation of an expression relies on some part
 : of the dynamic context that has not been assigned a value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPDY0002 as xs:QName := fn:QName($err:NS, "err:XPDY0002");

(:~
 :
 : It is a dynamic error if the dynamic type of the operand of a treat
 : expression does not match the sequence type specified by the treat
 : expression. This error might also be raised by a path expression
 : beginning with "/" or "//" if the context node
 : is not in a tree that is rooted at a document node. This is because a
 : leading "/" or "//" in a path expression is an
 : abbreviation for an initial step that includes the clause \c treat as \c
 : document-node().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XPDY0050 as xs:QName := fn:QName($err:NS, "err:XPDY0050");

(:~
 :
 : It is a dynamic error if any attribute of a constructed element does not
 : have a name that is distinct from the names of all other attributes of
 : the constructed element.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0025 as xs:QName := fn:QName($err:NS, "err:XQDY0025");

(:~
 :
 : It is a dynamic error if the result of the content expression of a
 : computed processing instruction constructor contains the string "?>".
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0026 as xs:QName := fn:QName($err:NS, "err:XQDY0026");

(:~
 :
 : In a validate expression, it is a dynamic error if the root element
 : information item in the PSVI resulting from validation does not have the
 : expected validity property: \c valid if validation mode is \c strict, or
 : either \c valid or \c notKnown if validation mode is \c lax.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0027 as xs:QName := fn:QName($err:NS, "err:XQDY0027");

(:~
 :
 : It is a dynamic error if the value of the name expression in a computed
 : processing instruction constructor cannot be cast to the type
 : \c xs:NCName.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0041 as xs:QName := fn:QName($err:NS, "err:XQDY0041");

(:~
 :
 : It is a static error the node-name of a node constructed by a computed
 : attribute constructor has any of the following properties:
 : - Its namespace prefix is \c xmlns.
 : - It has no namespace prefix and its local name is \c xmlns.
 : - Its namespace URI is http://www.w3.org/2000/xmlns/.
 : - Its namespace prefix is \c xml and its namespace URI is not
 : http://www.w3.org/XML/1998/namespace.
 : - Its namespace prefix is other than \c xml and its namespace URI is
 : http://www.w3.org/XML/1998/namespace.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0044 as xs:QName := fn:QName($err:NS, "err:XQDY0044");

(:~
 :
 : It is a dynamic error if a cycle is encountered in the definition of a
 : module's dynamic context components, for example because of a cycle in
 : variable declarations.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0054 as xs:QName := fn:QName($err:NS, "err:XQDY0054");

(:~
 :
 : It is a dynamic error if the operand of a validate expression is a
 : document node whose children do not consist of exactly one element node
 : and zero or more comment and processing instruction nodes, in any order.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0061 as xs:QName := fn:QName($err:NS, "err:XQDY0061");

(:~
 :
 : It is a dynamic error if the value of the name expression in a computed
 : processing instruction constructor is equal to "XML" (in any combination
 : of upper and lower case).
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0064 as xs:QName := fn:QName($err:NS, "err:XQDY0064");

(:~
 :
 : It is a dynamic error if the result of the content expression of a
 : computed comment constructor contains two adjacent hyphens or ends with
 : a hyphen.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0072 as xs:QName := fn:QName($err:NS, "err:XQDY0072");

(:~
 :
 : It is a dynamic error if the value of the name expression in a computed
 : element or attribute constructor cannot be converted to an expanded
 : QName (for example, because it contains a namespace prefix not found in
 : statically known namespaces).
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0074 as xs:QName := fn:QName($err:NS, "err:XQDY0074");

(:~
 :
 : It is a dynamic error if the element validated by a \c validate statement
 : does not have a top-level element declaration in the in-scope element
 : declarations, if validation mode is \c strict.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0084 as xs:QName := fn:QName($err:NS, "err:XQDY0084");

(:~
 :
 : An implementation MAY raise a dynamic error if an \c xml:id error, as
 : defined in [XML ID], is encountered during construction of an attribute
 : named \c xml:id.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0091 as xs:QName := fn:QName($err:NS, "err:XQDY0091");

(:~
 :
 : An implementation MAY raise a dynamic error if a constructed attribute
 : named \c xml:space has a value other than \c preserve or \c default.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0092 as xs:QName := fn:QName($err:NS, "err:XQDY0092");

(:~
 :
 : It is a dynamic error the node-name of a node constructed by a computed
 : element constructor has any of the following properties:
 : - Its namespace prefix is \c xmlns.
 : - Its namespace URI is http://www.w3.org/2000/xmlns/.
 : - Its namespace prefix is \c xml and its namespace URI is not
 : http://www.w3.org/XML/1998/namespace.
 : - Its namespace prefix is other than \c xml and its namespace URI is
 : http://www.w3.org/XML/1998/namespace.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0096 as xs:QName := fn:QName($err:NS, "err:XQDY0096");

(:~
 :
 : Invalid prefix and/or uri in computed namespace constructor
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0101 as xs:QName := fn:QName($err:NS, "err:XQDY0101");

(:~
 :
 : In an element constructor, if two or more namespace bindings in the in-scope bindings would have the same prefix, then an error is raised if they have different URIs; if they would have the same prefix and URI, duplicate bindings are ignored.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XQDY0102 as xs:QName := fn:QName($err:NS, "err:XQDY0102");

(:~
 :
 : It is a non-recoverable dynamic error if the picture string does not
 : satisfy the format-number function rules.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XTDE1310 as xs:QName := fn:QName($err:NS, "err:XTDE1310");

(:~
 :
 : It is a non-recoverable dynamic error if the $picture, $language,
 : $calendar, or $place argument for fn:format-date, fn:format-time, or
 : fn:format-dateTime is invalid.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOFD1340 as xs:QName := fn:QName($err:NS, "err:FOFD1340");

(:~
 :
 : It is a non-recoverable dynamic error if a component specifier within
 : the picture refers to components that are not available in the given
 : type of $value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOFD1350 as xs:QName := fn:QName($err:NS, "err:FOFD1350");

(:~
 :
 : It is a static error if, during the static analysis phase, the query is
 : found to contain a stop word option that refers to a stop word list that
 : is not found in the statically known stop word lists.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FTST0008 as xs:QName := fn:QName($err:NS, "err:FTST0008");

(:~
 :
 : It may be a static error if, during the static analysis phase, the query
 : is found to contain a language identifier in a language option that the
 : implementation does not support. The implementation may choose not to
 : raise this error and instead provide some other implementation-defined
 : behavior.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FTST0009 as xs:QName := fn:QName($err:NS, "err:FTST0009");

(:~
 :
 : It is a dynamic error if a weight value is not within the required range
 : of values; it is also a dynamic error if an implementation that does not
 : support negative weights encounters a negative weight value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FTDY0016 as xs:QName := fn:QName($err:NS, "err:FTDY0016");

(:~
 :
 : It is a dynamic error if an implementation encounters a mild not
 : selection, one of whose operands evaluates to an AllMatches that
 : contains a StringExclude.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FTDY0017 as xs:QName := fn:QName($err:NS, "err:FTDY0017");

(:~
 :
 : It is a static error if, during the static analysis phase, the query is
 : found to contain a thesaurus option that refers to a thesaurus that is
 : not found in the statically known thesauri.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FTST0018 as xs:QName := fn:QName($err:NS, "err:FTST0018");

(:~
 :
 : It is a static error if, within a single FTMatchOptions, there is more
 : than one match option of any given match option group.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FTST0019 as xs:QName := fn:QName($err:NS, "err:FTST0019");

(:~
 :
 : It is a dynamic error if, when "wildcards" is in effect, a query string
 : violates wildcard syntax.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FTDY0020 as xs:QName := fn:QName($err:NS, "err:FTDY0020");

(:~
 :
 : Unidentified error.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOER0000 as xs:QName := fn:QName($err:NS, "err:FOER0000");

(:~
 :
 : Division by zero.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOAR0001 as xs:QName := fn:QName($err:NS, "err:FOAR0001");

(:~
 :
 : Numeric operation overflow/underflow.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOAR0002 as xs:QName := fn:QName($err:NS, "err:FOAR0002");

(:~
 :
 : Input value too large for decimal.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCA0001 as xs:QName := fn:QName($err:NS, "err:FOCA0001");

(:~
 :
 : Invalid lexical value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCA0002 as xs:QName := fn:QName($err:NS, "err:FOCA0002");

(:~
 :
 : Input value too large for integer.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCA0003 as xs:QName := fn:QName($err:NS, "err:FOCA0003");

(:~
 :
 : NaN supplied as float/double value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCA0005 as xs:QName := fn:QName($err:NS, "err:FOCA0005");

(:~
 :
 : Raised when casting a string to xs:decimal if the string has more
 : digits of precision than the implementation can represent (the
 : implementation also has the option of rounding).
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCA0006 as xs:QName := fn:QName($err:NS, "err:FOCA0006");

(:~
 :
 : Code point not valid.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCH0001 as xs:QName := fn:QName($err:NS, "err:FOCH0001");

(:~
 :
 : Unsupported collation.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCH0002 as xs:QName := fn:QName($err:NS, "err:FOCH0002");

(:~
 :
 : Unsupported normalization form.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCH0003 as xs:QName := fn:QName($err:NS, "err:FOCH0003");

(:~
 :
 : Collation does not support collation units.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCH0004 as xs:QName := fn:QName($err:NS, "err:FOCH0004");

(:~
 :
 : No context document.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODC0001 as xs:QName := fn:QName($err:NS, "err:FODC0001");

(:~
 :
 : Error retrieving resource.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODC0002 as xs:QName := fn:QName($err:NS, "err:FODC0002");

(:~
 :
 : Raised by fn:doc, fn:collection to indicate that it is not possible to
 : return a result that is guaranteed deterministic.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODC0003 as xs:QName := fn:QName($err:NS, "err:FODC0003");

(:~
 :
 : Invalid argument to \c fn:collection().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODC0004 as xs:QName := fn:QName($err:NS, "err:FODC0004");

(:~
 :
 : Invalid argument to \c fn:doc() or \c fn:doc-available().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODC0005 as xs:QName := fn:QName($err:NS, "err:FODC0005");

(:~
 :
 : Invalid content passed to \c fn:parse().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODC0006 as xs:QName := fn:QName($err:NS, "err:FODC0006");

(:~
 :
 : Base URI passed to \c fn:parse() is not a valid absolute URI.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODC0007 as xs:QName := fn:QName($err:NS, "err:FODC0007");

(:~
 :
 : Invalid decimal format name supplied to \c fn:format-number().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODF1280 as xs:QName := fn:QName($err:NS, "err:FODF1280");

(:~
 :
 : Invalid decimal/integer format picture string.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODF1310 as xs:QName := fn:QName($err:NS, "err:FODF1310");

(:~
 :
 : Overflow/underflow in date/time operation.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODT0001 as xs:QName := fn:QName($err:NS, "err:FODT0001");

(:~
 :
 : Overflow/underflow in duration operation.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODT0002 as xs:QName := fn:QName($err:NS, "err:FODT0002");

(:~
 :
 : Invalid timezone value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FODT0003 as xs:QName := fn:QName($err:NS, "err:FODT0003");

(:~
 :
 : No namespace found for prefix.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FONS0004 as xs:QName := fn:QName($err:NS, "err:FONS0004");

(:~
 :
 : Base-URI not defined in static context.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FONS0005 as xs:QName := fn:QName($err:NS, "err:FONS0005");

(:~
 :
 : Invalid value for cast/constructor.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORG0001 as xs:QName := fn:QName($err:NS, "err:FORG0001");

(:~
 :
 : Invalid argument to \c fn:resolve-uri().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORG0002 as xs:QName := fn:QName($err:NS, "err:FORG0002");

(:~
 :
 : \c fn:zero-or-one() called with a sequence containing more than one
 : item.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORG0003 as xs:QName := fn:QName($err:NS, "err:FORG0003");

(:~
 :
 : \c fn:one-or-more() called with a sequence containing no items.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORG0004 as xs:QName := fn:QName($err:NS, "err:FORG0004");

(:~
 :
 : \c fn:exactly-one() called with a sequence containing zero or more
 : than one item.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORG0005 as xs:QName := fn:QName($err:NS, "err:FORG0005");

(:~
 :
 : Invalid argument type.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORG0006 as xs:QName := fn:QName($err:NS, "err:FORG0006");

(:~
 :
 : The two arguments to fn:dateTime() have inconsistent timezones.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORG0008 as xs:QName := fn:QName($err:NS, "err:FORG0008");

(:~
 :
 : Error in resolving a relative URI against a base URI in
 : \c fn:resolve-uri().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORG0009 as xs:QName := fn:QName($err:NS, "err:FORG0009");

(:~
 :
 : Invalid regular expression flags.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORX0001 as xs:QName := fn:QName($err:NS, "err:FORX0001");

(:~
 :
 : Invalid regular expression.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORX0002 as xs:QName := fn:QName($err:NS, "err:FORX0002");

(:~
 :
 : Regular expression matches zero-length string.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORX0003 as xs:QName := fn:QName($err:NS, "err:FORX0003");

(:~
 :
 : Invalid replacement string.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FORX0004 as xs:QName := fn:QName($err:NS, "err:FORX0004");

(:~
 :
 : Argument node does not have a typed value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOTY0012 as xs:QName := fn:QName($err:NS, "err:FOTY0012");

(:~
 :
 : An argument to \c fn:data() contains a node that does not have a typed
 : value.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOTY0013 as xs:QName := fn:QName($err:NS, "err:FOTY0013");

(:~
 :
 : The argument to \c fn:string() is a function item.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOTY0014 as xs:QName := fn:QName($err:NS, "err:FOTY0014");

(:~
 :
 : An argument to \c fn:deep-equal() contains a function item.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOTY0015 as xs:QName := fn:QName($err:NS, "err:FOTY0015");

(:~
 :
 : Identifier cannot be used to retrive a resource containing text
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOUT1170 as xs:QName := fn:QName($err:NS, "err:FOUT1170");

(:~
 :
 : Retrieved resource contains octets that cannot be decoded into Unicode
 : using the specified encoding, the resulting characters are not
 : permitted XML characters or requested encoding not supported
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOUT1190 as xs:QName := fn:QName($err:NS, "err:FOUT1190");

(:~
 :
 : This error is raised if the fn:function-lookup returns a context-dependent function and the context-dependent function is then called.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOFL0001 as xs:QName := fn:QName($err:NS, "err:FOFL0001");

(:~
 :
 : Invalid content passed to \c x:canonicalize().
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOCZ0001 as xs:QName := fn:QName($err:NS, "err:FOCZ0001");

(:~
 :
 : It is a static error if an updating expression is used in any position
 : other than one of the following:
 : - The topmost expression in the body of a query.
 : - The \c modify clause of a transform expression.
 : - The \c return clause of a FLWOR expression.
 : - The \c return clauses of a typeswitch expression in which every \c
 : return clause contains an updating expression or a vacuous expression.
 : - The \c then and \c else clauses of a conditional statement in which
 : both the \c then and \c else clauses contain either an updating
 : expression or a vacuous expression.
 : - An operand of a comma expression in which each operand is either an
 : updating expression or a vacuous expression.
 : - The content of a parenthesized expression.
 : - The body of a function declaration in which the keyword \c updating is
 : specified.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUST0001 as xs:QName := fn:QName($err:NS, "err:XUST0001");

(:~
 :
 : It is a static error if a simple expression that is not a vacuous
 : expression is used in one of the following positions:
 : - The \c modify clause of a transform expression.
 : - The top-level expression in the body of a function declaration in
 : which the keyword \c updating is specified.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUST0002 as xs:QName := fn:QName($err:NS, "err:XUST0002");

(:~
 :
 : It is a static error if a Prolog contains more than one revalidation
 : declaration.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUST0003 as xs:QName := fn:QName($err:NS, "err:XUST0003");

(:~
 :
 : It is a type error if the insertion sequence of an insert expression
 : contains an attribute node following a node that is not an attribute
 : node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0004 as xs:QName := fn:QName($err:NS, "err:XUTY0004");

(:~
 :
 : In an insert expression where into, as first
 : into, or as last into is specified, it is a type
 : error if the target expression returns a non-empty result that does not
 : consist of a single element or document node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0005 as xs:QName := fn:QName($err:NS, "err:XUTY0005");

(:~
 :
 : In an insert expression where \c before or \c after is specified, it is
 : a type error if the target expression returns a non-empty result that
 : does not consist of a single element, text, comment, or processing
 : instruction node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0006 as xs:QName := fn:QName($err:NS, "err:XUTY0006");

(:~
 :
 : It is a type error if the target expression of a delete expression does
 : not return a sequence of zero or more nodes.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0007 as xs:QName := fn:QName($err:NS, "err:XUTY0007");

(:~
 :
 : In a replace expression, it is a type error if the target expression
 : returns a non-empty result that does not consist of a single element,
 : attribute, text, comment, or processing instruction node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0008 as xs:QName := fn:QName($err:NS, "err:XUTY0008");

(:~
 :
 : In a replace expression where value of is not specified, it
 : is a dynamic error if the node returned by the target expression does
 : not have a parent.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0009 as xs:QName := fn:QName($err:NS, "err:XUDY0009");

(:~
 :
 : In a replace expression where value of is not specified and
 : the target is an element, text, comment, or processing instruction node,
 : it is a type error if the replacement sequence does not consist of zero
 : or more element, text, comment, or processing instruction nodes.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0010 as xs:QName := fn:QName($err:NS, "err:XUTY0010");

(:~
 :
 : In a replace expression where value of is not specified and
 : the target is an attribute node, it is a type error if the replacement
 : sequence does not consist of zero or more attribute nodes.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0011 as xs:QName := fn:QName($err:NS, "err:XUTY0011");

(:~
 :
 : In a rename expression, it is a type error if the target expression
 : returns a non-empty result that does not consist of a single element,
 : attribute, or processing instruction node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0012 as xs:QName := fn:QName($err:NS, "err:XUTY0012");

(:~
 :
 : In a transform expression, it is a type error if a source expression in
 : the \c copy clause does not return a single node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0013 as xs:QName := fn:QName($err:NS, "err:XUTY0013");

(:~
 :
 : In a transform expression, it is a dynamic error if the \c modify clause
 : modifies any node that was not created by the \c copy clause.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0014 as xs:QName := fn:QName($err:NS, "err:XUDY0014");

(:~
 :
 : It is a dynamic error if any node is the target of more than one \c
 : rename expression within the same query.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0015 as xs:QName := fn:QName($err:NS, "err:XUDY0015");

(:~
 :
 : It is a dynamic error if any node is the target of more than one \c
 : replace expression (without value of being specified)
 : within the same query.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0016 as xs:QName := fn:QName($err:NS, "err:XUDY0016");

(:~
 :
 : It is a dynamic error if any node is the target of more than one
 : replace value of expression within the same query.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0017 as xs:QName := fn:QName($err:NS, "err:XUDY0017");

(:~
 :
 : It is a dynamic error if a function that was declared to be \c external
 : but not \c updating returns a non-empty pending update list.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0018 as xs:QName := fn:QName($err:NS, "err:XUDY0018");

(:~
 :
 : It is a dynamic error if a function that was declared to be both \c
 : external and \c updating returns a non-empty data model instance.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0019 as xs:QName := fn:QName($err:NS, "err:XUDY0019");

(:~
 :
 : It is a dynamic error if the XDM instance that would result from
 : applying all the updates in a query violates any constraint specified in
 : [XQuery 1.0 and XPath 2.0 Data Model]. In this case, none of the updates
 : in the query are made effective.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0021 as xs:QName := fn:QName($err:NS, "err:XUDY0021");

(:~
 :
 : It is a type error if an insert expression specifies the insertion of an
 : attribute node into a document node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUTY0022 as xs:QName := fn:QName($err:NS, "err:XUTY0022");

(:~
 :
 : It is a dynamic error if an insert, replace, or rename expression
 : affects an element node by introducing a new namespace binding that
 : conflicts with one of its existing namespace bindings.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0023 as xs:QName := fn:QName($err:NS, "err:XUDY0023");

(:~
 :
 : It is a dynamic error if the effect of a set of updating expressions is
 : to introduce conflicting namespace bindings into an element node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0024 as xs:QName := fn:QName($err:NS, "err:XUDY0024");

(:~
 :
 : It is a dynamic error if the target expression of an insert, replace, or
 : rename expression evaluates to an empty sequence.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0027 as xs:QName := fn:QName($err:NS, "err:XUDY0027");

(:~
 :
 : It is a static error if a function declaration specifies both \c updating
 : and a return type.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUST0028 as xs:QName := fn:QName($err:NS, "err:XUST0028");

(:~
 :
 : In an insert expression where \c before or \c after is specified, it is
 : a dynamic error if the node returned by the target expression does not
 : have a parent.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0029 as xs:QName := fn:QName($err:NS, "err:XUDY0029");

(:~
 :
 : It is a dynamic error if an insert expression specifies the insertion of
 : an attribute node before or after a child of a document node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0030 as xs:QName := fn:QName($err:NS, "err:XUDY0030");

(:~
 :
 : It is a dynamic error if multiple calls to \c fn:put() in the same
 : snapshot specify the same URI (after resolution of relative URIs).
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:XUDY0031 as xs:QName := fn:QName($err:NS, "err:XUDY0031");

(:~
 :
 : It is a dynamic error if the first operand of \c fn:put() is not a node
 : of a supported kind.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOUP0001 as xs:QName := fn:QName($err:NS, "err:FOUP0001");

(:~
 :
 : It is a dynamic error if the second operand of \c fn:put() is not a valid
 : lexical representation of the \c xs:anyURI type.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:FOUP0002 as xs:QName := fn:QName($err:NS, "err:FOUP0002");

(:~
 :
 : It is an error if an item in S6 in sequence normalization is an attribute
 : node or a namespace node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SENR0001 as xs:QName := fn:QName($err:NS, "err:SENR0001");

(:~
 :
 : It is an error if the serializer is unable to satisfy the rules for
 : either a well-formed XML document entity or a well-formed XML external
 : general parsed entity, or both, except for content modified by the
 : character expansion phase of serialization.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SERE0003 as xs:QName := fn:QName($err:NS, "err:SERE0003");

(:~
 :
 : It is an error to specify the doctype-system parameter, or to specify
 : the standalone parameter with a value other than omit, if the instance
 : of the data model contains text nodes or multiple element nodes as
 : children of the root node.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SEPM0004 as xs:QName := fn:QName($err:NS, "err:SEPM0004");

(:~
 :
 : It is an error if the serialized result would contain an NCName Names
 : that contains a character that is not permitted by the version of
 : Namespaces in XML specified by the version parameter.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SERE0005 as xs:QName := fn:QName($err:NS, "err:SERE0005");

(:~
 :
 : It is an error if the serialized result would contain a character that is
 : not permitted by the version of XML specified by the version parameter.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SERE0006 as xs:QName := fn:QName($err:NS, "err:SERE0006");

(:~
 :
 : It is an error if an output encoding other than UTF-8 or UTF-16 is
 : requested and the serializer does not support that encoding.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SESU0007 as xs:QName := fn:QName($err:NS, "err:SESU0007");

(:~
 :
 : It is an error if a character that cannot be represented in the encoding
 : that the serializer is using for output appears in a context where
 : character references are not allowed (for example if the character
 : occurs in the name of an element).
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SERE0008 as xs:QName := fn:QName($err:NS, "err:SERE0008");

(:~
 :
 : It is an error if the omit-xml-declaration parameter has the value yes,
 : and the standalone attribute has a value other than omit; or the version
 : parameter has a value other than 1.0 and the doctype-system parameter is
 : specified.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SEPM0009 as xs:QName := fn:QName($err:NS, "err:SEPM0009");

(:~
 :
 : It is an error if the output method is xml, the value of the
 : undeclare-prefixes parameter is yes, and the value of the version
 : parameter is 1.0.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SEPM0010 as xs:QName := fn:QName($err:NS, "err:SEPM0010");

(:~
 :
 : It is an error if the value of the normalization-form parameter
 : specifies a normalization form that is not supported by the serializer.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SESU0011 as xs:QName := fn:QName($err:NS, "err:SESU0011");

(:~
 :
 : It is an error if the value of the normalization-form parameter is
 : fully-normalized and any relevant construct of the result begins with a
 : combining character.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SERE0012 as xs:QName := fn:QName($err:NS, "err:SERE0012");

(:~
 :
 : It is an error if the serializer does not support the version of XML or
 : HTML specified by the version parameter.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SESU0013 as xs:QName := fn:QName($err:NS, "err:SESU0013");

(:~
 :
 : It is an error to use the HTML output method when characters which are
 : legal in XML but not in HTML, specifically the control characters
 : #x7F-#x9F, appear in the instance of the data model.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SERE0014 as xs:QName := fn:QName($err:NS, "err:SERE0014");

(:~
 :
 : It is an error to use the HTML output method when \c > appears within a
 : processing instruction in the data model instance being serialized.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SERE0015 as xs:QName := fn:QName($err:NS, "err:SERE0015");

(:~
 :
 : It is a an error if a parameter value is invalid for the defined domain.
 : 
 : @see http://www.w3.org/2005/xqt-errors
:)
declare variable $err:SEPM0016 as xs:QName := fn:QName($err:NS, "err:SEPM0016");