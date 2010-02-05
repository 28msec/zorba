(:
 : Copyright 2006-2009 The FLWOR Foundation.
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

(:~
 : Intospection Module for the Static Context components.
 :
 : @see http://www.w3.org/TR/xquery/#id-xq-static-context-components
 :
 : @version 1.0
 :)

module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";



(:~
 : The function returns true if a collection with the given QName has been created.
 :
 : @param $name The QName of the collection that is being checked.
 : @return true if the collection has been created and false otherwise.
 :)
declare function sctx:is-declared-collection($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the collections that have
 : been previously created. The sequence will be empty if there are no collections.
 :
 : @return A sequence of QNames, one for each created collection, or an emtpy sequence.
 :)
declare function sctx:declared-collections() as xs:QName* external;

(:~
 : The function returns true if an index with the given QName has been declared.
 :
 : @param $name The QName of the index that is being checked.
 : @return true if the index has been declared and false otherwise.
 :)
declare function sctx:is-declared-index($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the indexes that have
 : been previously created. The sequence will be empty if there are no indexes.
 :
 : @return A sequence of QNames, one for each created index, or an empty
 : sequence if none exist.
 :)
declare function sctx:declared-indexes() as xs:QName* external;

(:~
 : The function returns a sequence of QNames representing the integrity
 : constraints that have been declared, as described by the Zorba Data
 : Definition Language extension. The sequence will be empty if there are no
 : integrity constraints.
 :
 : @return A sequence of QNames, one for each declared integrity constraint,
 : or an empty sequence if none are declared.
 :)
declare function sctx:declared-integrity-constraints() as xs:QName* external;

(:~
 : The function checks if an integrity constraint with the given QName has
 : been declared.
 :
 : @param $name The QName of the constraint that is being checked.
 : @return true if the integrity constraint has been declared and false
 : otherwise.
 :)
declare function sctx:is-declared-integrity-constraint($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a list of known statically known namespaces as prefixes
 : (fn, xml, xs, xsi, etc).
 : @return A sequence of xs:strings, one for each known namespace prefix.
 :
 : @see http://www.w3.org/TR/xquery/#dt-static-namespaces
 :)
declare function sctx:statically-known-namespaces() as xs:string* external;

(:~
 : For any statically know namespace prefix, the bound URI can be retreived
 : with the statically-known-namespace-bindings() function.
 :
 : @param $prefix The prefix of the known namespace, for which the bound URI
 : is being requested.
 : @return The URI bound to the prefix is returned, or an empty sequence if
 : the prefix is not known.
 :
 : @see http://www.w3.org/TR/xquery/#dt-static-namespaces
 :)
declare function sctx:statically-known-namespace-binding($prefix as xs:string) as xs:string? external;

(:~
 : The function returns the URI of the default function namespace.
 :
 : @return The URI of the of the default function namespace.
 :
 : @see http://www.w3.org/TR/xquery/#dt-def-fn-ns
 :)
declare function sctx:default-function-namespace() as xs:string
{
  sctx:statically-known-namespace-binding("fn")
};

(:~
 : The function returns the base URI.
 :
 : @return The base URI.
 :
 : @see http://www.w3.org/TR/xquery/#dt-base-uri
 :)
declare function sctx:base-uri() as xs:string?
{
  fn:static-base-uri()
};

(:~
 : The function returns the statically known default collection type. This
 : is the type of the sequence of nodes that would result from calling the
 : fn:collection function with no arguments.
 :
 : @return The type of the default collection.
 :
 : @see http://www.w3.org/TR/xquery/#dt-known-default-collection
 :)
declare function sctx:default-collection-type() as xs:string external;

(:~
 : The function return a sequence of QNames identifying declared variables
 : from the static context.
 :
 : @return A sequence of QNames, one for each variable.
 :
 : @see http://www.w3.org/TR/xquery/#dt-in-scope-variables
 :)
declare function sctx:in-scope-variables() as xs:QName* external;

(:~
 : The function returns a sequence containing the QNames of all defined
 : functions, which are available to be called from within an expression.
 :
 : @return A sequence for QNames identifying all functions.
 :
 : @see http://www.w3.org/TR/xquery/#dt-function-signature
 :)
declare function sctx:function-names() as xs:QName* external;

(:~
 : The function returns the number of arguments the given XQuery $function
 : takes.
 :
 : @param $function A QName identifying a function.
 : @return A sequence of zero or more integers, one for each overloaded version
 : of the given function. An empty sequence is returned if the function is not
 : defined.
 :
 : @see http://www.w3.org/TR/xquery/#dt-function-signature
 :)
declare function sctx:function-arguments-count($function as xs:QName) as xs:int* external;

(:~
 : The function returns true or false depending on whether rules for
 : compatibility with XPath 1.0 are in effect. XQuery set the value
 : of this component to false.
 :
 : @return The function should return false
 :
 : @see http://www.w3.org/TR/xquery/#dt-xpath-compat-mode
 :)
declare function sctx:xpath10-compatibility-mode() as xs:boolean external;

(:~
 : The function returns one of statically known collations that is used by
 : functions and operators for comparing and ordering values of type xs:string
 : or xs:anyURI when no explicit collation is specified.
 :
 : @return The collations that is used by default.
 :
 : @see http://www.w3.org/TR/xquery/#dt-def-collation
 :)
declare function sctx:default-collation() as xs:string
{
  fn:default-collation()
};

(:~
 : The function returns a sequence that contains the  statically known collations.
 :
 : @return The sequence of collations.
 :
 : @see http://www.w3.org/TR/xquery/#dt-static-collations
 :)
declare function sctx:statically-known-collations() as xs:anyURI* external;

(:~
 : The function returns the static context construction mode of element and
 : document nodes.
 :
 : @return Either "preserve" or "strip", as strings.
 :
 : @see http://www.w3.org/TR/xquery/#dt-construction-mode
 :)
declare function sctx:construction-mode() as xs:string external;

(:~
 : The function returns the static context ordering mode, which affects the
 : ordering of the result sequences returned by certain expressions.
 :
 : @return Either "ordered" or "unordered", as strings.
 :
 : @see http://www.w3.org/TR/xquery/#dt-ordering-mode
 :)
declare function sctx:ordering-mode() as xs:string external;

(:~
 : The function returns the static context component which controls the
 : processing of empty sequences and NaN values as ordering keys in an order
 : by clause in a FLWOR expression.
 :
 : @return Either "greatest" or "least", as strings.
 :
 : @see http://www.w3.org/TR/xquery/#dt-default-empty-order
 :)
declare function sctx:default-order() as xs:string external;

(:~
 : The function returns the static context component which contrls the
 : processing of boundary whitespace by direct element constructors.
 :
 : @return Either "preserve" or "strip", as strings.
 :
 : @see http://www.w3.org/TR/xquery/#dt-boundary-space-policy
 :)
declare function sctx:boundary-space-policy() as xs:string external;

(:~
 : The function returns the static context components which control the
 : the namespace bindings that are assigned when an existing element node
 : is copied by an element constructor
 :
 : @return A sequence containing exactly two strings, of which the first
 : has a value of either "preserve" or "no-preserve" and the second a value
 : of either "inherit" or "no-inherit".
 :
 : @see http://www.w3.org/TR/xquery/#dt-copy-namespaces-mode
 :)
declare function sctx:copy-namespaces-mode() as xs:string+ external;
