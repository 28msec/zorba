jsoniq version "1.0";

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

(:===========================================================================:)

(:~
 : This module provides functions that gets components of the static context.
 :
 : @see http://www.w3.org/TR/xquery/#id-xq-static-context-components
 : @author Nicolae Brinza
 : @project Zorba/Introspection/Static Context/Static Context
 :)
module namespace sctx = "http://zorba.io/modules/sctx";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Gets the base URI.
 :
 : @return The base URI.
 : @see http://www.w3.org/TR/xquery/#dt-base-uri
 :)
declare function sctx:base-uri()
  as xs:string? external;

(:~
 : Gets the boundary whitespace policy used by direct element constructors.
 :
 : @return Either <code>preserve</code> or <code>strip</code>.
 : @see http://www.w3.org/TR/xquery/#dt-boundary-space-policy
 :)
declare function sctx:boundary-space-policy()
  as xs:string external;

(:~
 : Gets the static context construction mode of element and document nodes.
 :
 : @return Either <code>preserve</code> or <code>strip</code>.
 : @see http://www.w3.org/TR/xquery/#dt-construction-mode
 :)
declare function sctx:construction-mode()
  as xs:string external;

(:~
 : Gets the static context components that control the the namespace bindings
 : that are assigned when an existing element node is copied
 : by an element constructor.
 :
 : @return A sequence of two strings:
 : the first is either <code>preserve</code> or <code>no-preserve</code>
 : and the second is either <code>inherit</code> or <code>no-inherit</code>.
 : @see http://www.w3.org/TR/xquery/#dt-copy-namespaces-mode
 :)
declare function sctx:copy-namespaces-mode()
  as xs:string+ external;

(:~
 : Gets one of statically known collations used by functions and operators
 : for comparing and ordering values of type <code>xs:string</code>
 : or <code>xs:anyURI</code> when no explicit collation is specified.
 :
 : @return The collations that is used by default.
 : @see http://www.w3.org/TR/xquery/#dt-def-collation
 :)
declare function sctx:default-collation()
  as xs:string external;

(:~
 : Gets the statically known default collection type.
 : This is the type of the sequence of nodes that would result from calling the
 : <code>fn:collection</code> function with no arguments.
 :
 : @return The type of the default collection.
 : @see http://www.w3.org/TR/xquery/#dt-known-default-collection
 :)
declare function sctx:default-collection-type()
  as xs:string external;

(:~
 : Gets the URI of the default function namespace.
 :
 : @return The URI of the of the default function namespace.
 : @see http://www.w3.org/TR/xquery/#dt-def-fn-ns
 :)
declare function sctx:default-function-namespace()
  as xs:string external;

(:~
 : Gets the component that controls the processing of empty sequences and NaN
 : values as ordering keys in an <code>order by</code> clause
 : in a FLWOR expression.
 :
 : @return Either <code>greatest</code> or <code>least</code>.
 : @see http://www.w3.org/TR/xquery/#dt-default-empty-order
 :)
declare function sctx:default-order()
  as xs:string external;

(:~
 : Gets the list of annotations declared for the given function.
 :
 : @param $name The name of the function.
 : @param $arity The number of arguments the function takes.
 : @return the list of annotations
 :)
declare function sctx:function-annotations( $name as xs:QName,
                                            $arity as xs:integer )
  as xs:QName* external;

(:~
 : Gets the number of arguments the given XQuery function takes.
 :
 : @param $function A QName identifying a function.
 : @return Either a sequence of zero or more integers
 : (one for each overloaded version of the given function)
 : or an empty sequence if the function is not defined.
 :
 : @see http://www.w3.org/TR/xquery/#dt-function-signature
 :)
declare function sctx:function-arguments-count( $function as xs:QName )
  as xs:int* external;

(:~
 : Gets a sequence containing the QNames of all defined functions
 : that are available to be called from within an expression.
 :
 : @return A sequence for QNames identifying all functions.
 : @see http://www.w3.org/TR/xquery/#dt-function-signature
 :)
declare function sctx:function-names()
  as xs:QName* external;

(:~
 : Gets a sequence of JSON objects containing the name, arity, and annotations
 : of all defined functions that are available to be called form within an
 : expression.
 :
 : @return A sequence of objects.
 :)
declare function sctx:functions()
  as object()* external;

(:~
 : Gets a sequence of QNames identifying declared attributes
 : in the imported schemas.
 :
 : @return A sequence of QNames, one for each attribute.
 : @see http://www.w3.org/TR/xquery/#dt-is-attrs
 :)
declare function sctx:in-scope-attribute-declarations()
  as xs:QName* external;

(:~
 : Gets a sequence of QNames identifying declared in-scope
 : schema attribute groups.
 :
 : @return A sequence of QNames, one for each attribute group.
 :)
declare function sctx:in-scope-attribute-groups()
  as xs:QName* external;

(:~
 : Gets a sequence of QNames identifying declared elements
 : in the imported schemas.
 :
 : @return A sequence of QNames, one for each declared element.
 : @see http://www.w3.org/TR/xquery/#dt-is-elems
 :)
declare function sctx:in-scope-element-declarations()
  as xs:QName* external;

(:~
 : Gets a sequence of QNames identifying declared in-scope
 : schema element groups.
 :
 : @return A sequence of QNames, one for each element group.
 :)
declare function sctx:in-scope-element-groups()
  as xs:QName* external;

(:~
 : Gets a sequence of QNames identifying in-scope schema types
 : including all the predefined schema types and all definitions
 : found in imported schemas.
 :
 : @return A sequence of QNames, one for each defined type.
 : @see http://www.w3.org/TR/xquery/#dt-is-types
 :)
declare function sctx:in-scope-schema-types()
  as xs:QName* external;

(:~
 : Gets a sequence of QNames identifying declared variables
 : from the static context.
 :
 : @return A sequence of QNames, one for each variable.
 : @see http://www.w3.org/TR/xquery/#dt-in-scope-variables
 :)
declare function sctx:in-scope-variables()
  as xs:QName* external;

(:~
 : Gets the value of an option that is declared in the prolog of the module.
 :
 : @param $name the name of the option value to retrieve
 : @return the value of the option if contained in the static context
 : or the empty sequence otherwise.
 :)
declare function sctx:option( $name as xs:QName )
  as xs:string? external;

(:~
 : Gets the ordering mode that affects the ordering of the result sequences
 : returned by certain expressions.
 :
 : @return Either <code>ordered</code> or <code>unordered</code>.
 : @see http://www.w3.org/TR/xquery/#dt-ordering-mode
 :)
declare function sctx:ordering-mode() as xs:string external;

(:~
 : Gets a sequence that contains the statically known collations.
 :
 : @return The sequence of collations.
 : @see http://www.w3.org/TR/xquery/#dt-static-collations
 :)
declare function sctx:statically-known-collations()
  as xs:anyURI* external;

(:~
 : Gets a sequence that contains the URIs of all statically known documents.
 :
 : @return The sequence of document URIs.
 : @see http://www.w3.org/TR/xquery/#dt-known-docs
 :)
declare function sctx:statically-known-documents()
  as xs:anyURI* external;

(:~
 : For the given document, returns the static type of its root node.
 :
 : @param $document A URI of a document.
 : @return The static type of the given document.
 : @see http://www.w3.org/TR/xquery/#dt-known-docs
 :)
declare function sctx:statically-known-document-type( $document as xs:string )
  as xs:QName external;

(:~
 : Gets the bound URI for the given prefix.
 :
 : @param $prefix The prefix of the known namespace for which the bound URI
 : is being requested.
 : @return The URI bound to the prefix is returned, or an empty sequence if
 : the prefix is not known.
 : @see http://www.w3.org/TR/xquery/#dt-static-namespaces
 :)
declare function sctx:statically-known-namespace-binding( $prefix as xs:string )
  as xs:string? external;

(:~
 : Gets a list of known statically known namespaces as prefixes
 : (fn, xml, xs, xsi, etc).
 :
 : @return A sequence of xs:strings, one for each known namespace prefix.
 : @see http://www.w3.org/TR/xquery/#dt-static-namespaces
 :)
declare function sctx:statically-known-namespaces()
  as xs:string* external;

(:~
 : Gets true or false depending on whether rules for compatibility
 : with XPath 1.0 are in effect.
 : XQuery set the value of this component to false.
 :
 : @return The function should return <code>false</code>.
 : @see http://www.w3.org/TR/xquery/#dt-xpath-compat-mode
 :)
declare function sctx:xpath10-compatibility-mode()
  as xs:boolean external;

(:===========================================================================:)

(: vim:set syntax=xquery et sw=2 ts=2: :)
