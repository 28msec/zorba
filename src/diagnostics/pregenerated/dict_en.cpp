/**
 * Copyright 2006-2011 The FLWOR Foundation.
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
 
 /*
  * THIS FILE IS GENERATED.
  * PLEASE DO NOT EDIT.
  */
 
#include "stdafx.h"
#include "zorba/config.h"
#include "diagnostics/dict_impl.h"

namespace zorba {
namespace diagnostic {
namespace dict {

extern entry const dict_en[] = {
  { "FOAR0001", "division by zero" },
  { "FOAR0002", "numeric operation overflow/underflow${: 1}" },
  { "FOCA0001", "\"$1\": value too large for decimal" },
  { "FOCA0002", "\"$1\": invalid lexical value${: 2}" },
  { "FOCA0003", "\"$1\": value too large for integer" },
  { "FOCA0005", "NaN supplied as float/double value" },
  { "FOCA0006", "\"$1\": string to be cast to decimal has too many digits of precision" },
  { "FOCH0001", "\"$1\": invalid code point" },
  { "FOCH0002", "\"$1\": unsuported collation${: 2}" },
  { "FOCH0003", "\"$1\": unsupported normalization form" },
  { "FOCH0004", "\"$1\": collation does not support collation units" },
  { "FODC0001", "no context document for $1() function" },
  { "FODC0002", "\"$1\": error retrieving resource${: 2}" },
  { "FODC0003", "function stability not defined" },
  { "FODC0004", "\"$1\": invalid argument to fn:collection()${: 2}" },
  { "FODC0005", "\"$1\": invalid argument to fn:doc() or fn:doc-available()" },
  { "FODC0006", "invalid content passed to $1: $2" },
  { "FODC0007", "\"$1\": base URI passed to fn:parse() is not a valid absolute URI" },
  { "FODF1280", "\"$1\": invalid decimal format name for fn:format-number()" },
  { "FODF1310", "\"$1\": invalid fn:format-number() picture string$2" },
  { "FODT0001", "overflow/underflow in date/time operation" },
  { "FODT0002", "overflow/underflow in duration operation" },
  { "FODT0003", "\"$1\": invalid timezone value" },
  { "FOER0000", "unidentifier error" },
  { "FOFI0001", "\"$1\": not castable to xs:language" },
  { "FOFI0002", "invalid argument in format-integer: $1" },
  { "FONS0004", "\"$1\": no namespace found for prefix" },
  { "FONS0005", "base-URI not defined in the static context" },
  { "FORG0001", "${\"1\": }invalid value for cast/constructor${: 2}" },
  { "FORG0002", "\"$1\": invalid argument to fn:resolve-uri()${: 2}" },
  { "FORG0003", "fn:zero-or-one() called with a sequnce containing more than one item" },
  { "FORG0004", "fn:one-or-more() called with a sequence containing no items" },
  { "FORG0005", "fn:exactly-one() called with a sequence containing zero or more than one item" },
  { "FORG0006", "$1" },
  { "FORG0008", "\"$1\" and \"$2\": two arguments to fn:dateTime() have inconsistent timezones" },
  { "FORG0009", "error resolving a relative URI against a base URI in fn:resolve-uri()${: 1}" },
  { "FORX0001", "'$1': invalid regular expression flag" },
  { "FORX0002", "\"$1\": invalid regular expression${: 2}" },
  { "FORX0003", "\"$1\": regular expression matches zero-length string" },
  { "FORX0004", "\"$1\": invalid replacement string${: 2}" },
  { "FOTY0012", "\"$1\": element node of type $2 does not have a typed value" },
  { "FOTY0013", "\"$1\": argument to fn:data() is function item" },
  { "FOTY0014", "\"$1\": argument to fn:string() is a function item" },
  { "FOTY0015", "\"$1\": argument to fn:deep-equal() contains a function item" },
  { "FOUP0001", "first operand of fn:put() is not a node of a supported kind" },
  { "FOUP0002", "second operand of fn:put() is not a valid lexical representation of the xs:anyURI type" },
  { "FOUT1170", "\"$1\": error retrieving resource containing text" },
  { "FOUT1190", "\"$1\": can not decode resource retrieved" },
#if !defined(ZORBA_NO_FULL_TEXT)
  { "FTDY0016", "\"$1\": invalid weight: absolute value must be in [0,1000]" },
#endif
#if !defined(ZORBA_NO_FULL_TEXT)
  { "FTDY0017", "mild-not contains StringExclude" },
#endif
#if !defined(ZORBA_NO_FULL_TEXT)
  { "FTDY0020", "${\"1\": }invalid wildcard syntax${: 2}" },
#endif
#if !defined(ZORBA_NO_FULL_TEXT)
  { "FTST0008", "\"$1\": unknown stop-word list" },
#endif
#if !defined(ZORBA_NO_FULL_TEXT)
  { "FTST0009", "\"$1\": unsupported language${ 2}" },
#endif
#if !defined(ZORBA_NO_FULL_TEXT)
  { "FTST0018", "\"$1\": unknown thesaurus" },
#endif
#if !defined(ZORBA_NO_FULL_TEXT)
  { "FTST0019", "\"$1\": match option specified more than once" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNDY0003", "\"$1\": pair with the same name already exists in object." },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNSE0012", "Cannot serialize multiple top-level items as JSON" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNSE0013", "Cannot serialize value as JSON: $1" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNSE0014", "Cannot serialize a function item as JSON" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNSE0022", "$1: invalid serialization method for item type ($2)" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNTY0001", "Cannot atomize and/or cast value of type $1 to a string." },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNTY0002", "Pair value returns no, or more than one, item." },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNTY0003", "$1 items do not have string value" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNTY0004", "$1 items do not have typed value" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNTY0011", "JSON item cannot appear in content sequence of node constructor or updating expression" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNTY0018", "Object or array selection needs exactly one parameter." },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNUP0005", "\"$1\": duplicate pair to insert" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNUP0006", "\"$1\": pair to insert already exists in object." },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNUP0007", "$1 - wrong type for object/array selector in update expression." },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNUP0008", "$1" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNUP0009", "\"$1\": duplicate pair to replace" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNUP0010", "\"$1\": duplicate pair to rename" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNUP0016", "$1" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JNUP0017", "Cannot replace with less or more than an item." },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JSDY0020", "$1: invalid option type for option $2 (expected $3)" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JSDY0021", "$1" },
#endif
#if defined(ZORBA_WITH_JSON)
  { "JSDY0040", "$1" },
#endif
  { "SENR0001", "\"$1\": can not serialize $2" },
  { "SEPM0004", "doctype-system parameter, or standalone parameter with a value other than \"omit\", specified" },
  { "SEPM0009", "omit-xml-declaration parameter is \"yes\" and $1" },
  { "SEPM0010", "the output method is \"xml\", the value of the undeclare-prefixes parameter is \"yes\", and the value of the version parameter is \"1.0\"" },
  { "SEPM0016", "\"$1\": value for parameter \"$2\" invalid${; $3}" },
  { "SERE0003", "serializer can't satisfy the rules for either a well-formed XML document entity or a well-formed XML external general parsed entity" },
  { "SERE0005", "invalid NCName character" },
  { "SERE0006", "\"$1\": invalid character for XML version $2" },
  { "SERE0008", "\"$1\": can not encode character as character reference here" },
  { "SERE0012", "normalization-form parameter value is fully-normalized and any relevant construct of the result begins with a combining character" },
  { "SERE0014", "\"#$1\": character not allowed for HTML output method" },
  { "SERE0015", "can not use '>' within processing instruction for HTML output method" },
  { "SESU0007", "\"$1\": unsupported encoding" },
  { "SESU0011", "\"$1\": unsupported normalization form" },
  { "SESU0013", "\"$1\": unsupported $2 version; supported versions are: $3" },
  { "XPDY0002", "\"$1\": $2" },
  { "XPDY0050", "\"$1\" cannot be treated as type $2" },
  { "XPST0001", "${\"1\": }undefined value${: 2}" },
  { "XPST0003", "invalid expression${: 1}" },
  { "XPST0005", "static type must not be empty-sequence()" },
  { "XPST0008", "\"$1\": undefined $2" },
  { "XPST0017", "\"$1\": $2" },
  { "XPST0051", "\"$1\": not defined as atomic type${: 2}" },
  { "XPST0080", "\"$1\": invalid type for \"cast\" or \"castable\" exression" },
  { "XPST0081", "\"$1\": can not expand namespace prefix to URI" },
  { "XPST0083", "\"$1\": not a string literal" },
  { "XPTY0004", "$1" },
  { "XPTY0018", "path expression last step must not have nodes and atomic values" },
  { "XPTY0019", "a non-last axis step produces non-node items" },
  { "XPTY0020", "context item in axis step is not a node" },
  { "XQDY0025", "\"$1\": duplicate attribute name" },
  { "XQDY0026", "computed processing instrucion must not contain \"?>\"" },
  { "XQDY0027", "\"$1\": unexpected validity property${: 2}" },
  { "XQDY0041", "can not cast to xs:NCName" },
  { "XQDY0044", "\"$1\": invalid attibute node-name" },
  { "XQDY0061", "invalid validate expression operand${: 1}" },
  { "XQDY0064", "\"XML\": invalid name expression" },
  { "XQDY0072", "comment must not contain \"--\" or end with \"-\"" },
  { "XQDY0074", "${\"1\": }can not convert to expanded QName${: 2}" },
  { "XQDY0084", "validated element does not have a top-level element declaration in the in-scope element declarations${: 1}" },
  { "XQDY0091", "\"xml:id\" encountered" },
  { "XQDY0092", "\"$1\": must be either \"preserve\" or \"default\"" },
  { "XQDY0096", "\"$1\": invalid node-name" },
  { "XQST0009", "schema import not supported" },
  { "XQST0012", "invalid schema definitions" },
  { "XQST0013", "invalid pragma content" },
  { "XQST0022", "namespace declaration attribute is not a URI literal" },
  { "XQST0031", "\"$1\": $2" },
  { "XQST0032", "multiple base URI declarations" },
  { "XQST0033", "\"$1\": namespace prefix already bound to \"$2\"" },
  { "XQST0034", "\"$1\": duplicate function declaration" },
  { "XQST0035", "\"$1\": name previosly imported" },
  { "XQST0036", "$1" },
  { "XQST0038", "multiple default collation declarations" },
  { "XQST0039", "\"$1\": duplicate parameter name" },
  { "XQST0040", "\"$1\": non-distinct expanded attribute QName" },
  { "XQST0045", "\"$1\": invalid function or annotation namespace" },
  { "XQST0046", "${\"1\": }invalid URI literal${: 2}" },
  { "XQST0047", "\"$1\": duplicate target namespace" },
  { "XQST0048", "\"$1\": not in library namespace" },
  { "XQST0049", "\"$1\": duplicate variable declaration" },
  { "XQST0054", "${\"1\": }variable must not depend on itself" },
  { "XQST0055", "multiple copy-namespaces declarations" },
  { "XQST0057", "empty target namespace" },
  { "XQST0058", "\"$1\": duplicate target namespace" },
  { "XQST0059", "\"$1\": target namespace not found for schema/module${ 2}" },
  { "XQST0060", "\"$1\": function name has a null namespace URI" },
  { "XQST0065", "multiple ordering mode declaraions" },
  { "XQST0066", "multiple element/type/function namespace declarations" },
  { "XQST0067", "multiple construction declarations" },
  { "XQST0068", "multiple boundary-space declarations" },
  { "XQST0069", "multiple empty order declarations" },
  { "XQST0070", "\"$1\": $2" },
  { "XQST0071", "\"$1\": duplicate namespace declaration attribute" },
  { "XQST0076", "\"$1\": unknown collation" },
  { "XQST0079", "unknown pragma or empty expression" },
  { "XQST0085", "namespace URI is empty" },
  { "XQST0087", "\"$1\": invalid encoding" },
  { "XQST0088", "empty target namespace literal" },
  { "XQST0089", "\"$1\": duplicate variable name" },
  { "XQST0090", "\"$1\": invalid character reference in XML $2" },
  { "XQST0093", "\"$1\": module must not depend on itself" },
  { "XQST0098", "properties \"$1\" and \"$2\", representing characters used in picture string, do not have distinct values" },
  { "XQST0099", "module contains more than one context item declaration" },
  { "XQST0103", "$1: non-distinct variable in window clause" },
  { "XQST0106", "$1: multiple annotations with $2 names" },
  { "XQST0111", "$1" },
  { "XQTY0024", "element constructor content sequence must not have an attribute node following a non-attribute node" },
  { "XQTY0030", "validate argument must be exactly one document or element node" },
  { "XQTY0086", "typed value of copied element or attribute node is namespace-sensitive when construction mode is preserve and copy-namespaces mode is no-preserve" },
  { "XSST0001", "\"$1\": function cannot be declared as both updating and sequential" },
  { "XSST0002", "\"$1\": function declared sequential but has updating body" },
  { "XSST0003", "\"$1\": function declared updating but has sequential body" },
  { "XSST0004", "\"$1\": function declared nonsequential but has sequential body" },
  { "XSST0005", "expression cannot be both updating and sequential" },
  { "XSST0006", "sequential expression not allowed here" },
  { "XSST0007", "\"$1\": variable not assignable" },
  { "XSST0008", "\"while\" statement with non-sequential body" },
  { "XSST0009", "\"break loop\" statement not inside while statement" },
  { "XSST0010", "\"continue loop\" statement not inside while statement" },
  { "XTDE1310", "\"$1\": picture string does not satisfy format-number() function rules" },
  { "XTDE1340", "\"$1\": invalid picture string for date/time" },
  { "XTDE1350", "component specifier not available" },
  { "XUDY0009", "node has no parent in \"replace\" expression (without \"value of\")" },
  { "XUDY0014", "\"modify\" can not modify node not created by \"copy\"" },
  { "XUDY0015", "node is target of multiple \"rename\" expressions in same query" },
  { "XUDY0016", "node is target of multiple \"replace\" expressions (without \"value of\") in same query" },
  { "XUDY0017", "node is target of multiple \"replace value of\" expressions in same query" },
  { "XUDY0018", "\"$1\": function declared external, non-updating returns non-empty pending update list" },
  { "XUDY0019", "\"$1\": function declated external, updating returns non-empty data model instance" },
  { "XUDY0021", "updates violate constraint${ 1}" },
  { "XUDY0023", "\"$1\": namespace binding conflicts with $2=$3" },
  { "XUDY0024", "\"$1\": namespace binding conflicts with $2=$3" },
  { "XUDY0027", "target expression is empty sequence" },
  { "XUDY0029", "node has no parent in \"insert\" expression (with \"before\" or \"after\")" },
  { "XUDY0030", "insertion of attrhbute node before or after document node child" },
  { "XUDY0031", "\"$1\": same URI used in multiple calls to fn:put() in same snapshot" },
  { "XUST0001", "$1" },
  { "XUST0002", "simple expression not allowed here" },
  { "XUST0003", "multiple revalidation declarations" },
  { "XUST0028", "\"$1\": function can not be updating with a return type" },
  { "XUTY0004", "attribute node follows non-attribute node" },
  { "XUTY0005", "target expression not a single element or document node" },
  { "XUTY0006", "target expression not a single element, text, comment, or processing instruction node" },
  { "XUTY0007", "target expression does not return a sequence of zero or more nodes" },
  { "XUTY0008", "target expression not a single element, attribute, text, comment, or processing instruction node" },
  { "XUTY0010", "replacement sequence does not consist of zero or more element, text, comment, or processing instruction nodes" },
  { "XUTY0011", "replacement sequence does not consist of zero or more attribute nodes" },
  { "XUTY0012", "multiple elements, attributes, or processing-instruction nodes returned" },
  { "XUTY0013", "source expression of \"copy\" clause must return a single node or json-item" },
  { "XUTY0022", "insertion of attribute node into document node" },
  { "ZAPI0002", "XQuery compilation failed${: 1}" },
  { "ZAPI0003", "XQuery not compiled" },
  { "ZAPI0004", "XQuery already compiled" },
  { "ZAPI0005", "XQuery already executing" },
  { "ZAPI0006", "XQuery already closed" },
  { "ZAPI0007", "cannot serialize pul" },
  { "ZAPI0008", "can not execute a non-updating XQuery" },
  { "ZAPI0009", "XQuery not compiled in debug mode" },
  { "ZAPI0011", "\"$1\": undefined $2" },
  { "ZAPI0014", "\"$1\": invalid argument${: 2}" },
  { "ZAPI0015", "\"$1\": createModule() function not found${: 2}" },
  { "ZAPI0019", "\"$1\": external module already registered" },
  { "ZAPI0020", "\"$1\": document already exists in store" },
  { "ZAPI0021", "\"$1\": item to load is not a node" },
  { "ZAPI0027", "cannot update dynamic context with iterators" },
  { "ZAPI0028", "\"$1\": invalid node URI" },
  { "ZAPI0029", "\"$1\": reference already present in the store" },
  { "ZAPI0030", "node has no current reference" },
  { "ZAPI0039", "XQuery has iterator already" },
  { "ZAPI0040", "iterator is not open" },
  { "ZAPI0041", "iterator is already open" },
  { "ZAPI0042", "iterator is closed" },
  { "ZAPI0043", "cannot serialize JSON item using current output method" },
  { "ZAPI0045", "cannot serialize sequence containing both JSON and XML items" },
  { "ZAPI0070", "\"$1\": invalid serialization method for SAX" },
  { "ZAPI0080", "can not retrieve node-reference for a node that is not in a collection." },
  { "ZAPI0090", "a non root element cannot be validated in place." },
  { "ZCSE0001", "\"$1\": nonexistent input field" },
  { "ZCSE0002", "\"$1\": incompatible input field${: type=2}${, class=3}" },
  { "ZCSE0003", "\"$1\": unrecognized class field" },
  { "ZCSE0004", "\"$1\": unresolved field reference" },
  { "ZCSE0005", "class version for \"$1\" ($2) is too new; supported version is $3" },
  { "ZCSE0006", "class version for \"$1\" ($2) is too old; minimum supported version is $3; use Zorba 0x$4 instead" },
  { "ZCSE0007", "input archive used for out serialization" },
  { "ZCSE0008", "output archive used for in serialization" },
  { "ZCSE0009", "\"$1\": class not serializable" },
  { "ZCSE0010", "\"$1\": item type not serializable; only atomic, node, function, and error items are supported" },
  { "ZCSE0011", "input archive not Zorba archive" },
  { "ZCSE0012", "\"$1\": incompatible archive version; expected \"$2\"" },
  { "ZCSE0013", "failed to load pre-compiled query${: 1}" },
  { "ZCSE0014", "cannot save execution plan: infinite circular dependencies" },
  { "ZCSE0015", "cannot load execution plan: incompatible between 32/64 bits or little/big-endian" },
  { "ZCSE0016", "cannot load execution plan saved from release mode Zorba into debug mode Zorba" },
  { "ZCSE0017", "cannot load execution plan saved from debug mode Zorba into release mode Zorba" },
  { "ZDDY0001", "\"$1\": collection not declared" },
  { "ZDDY0002", "\"$1\": collection already exists" },
  { "ZDDY0003", "\"$1\": collection does not exist" },
  { "ZDDY0004", "\"$1\": can not update constant collection" },
  { "ZDDY0005", "\"$1\": illegal insert into append-only collection" },
  { "ZDDY0006", "\"$1\": illegal insert into queue collection" },
  { "ZDDY0007", "\"$1\": illegal delete from append-only collection" },
  { "ZDDY0008", "\"$1\": illegal delete from queue collection" },
  { "ZDDY0009", "\"$1\": not all nodes to delete are at the beginning of this queue collection" },
  { "ZDDY0010", "\"$1\": illegal update of read-only nodes" },
  { "ZDDY0011", "\"$1\": collection does not contain node" },
  { "ZDDY0012", "\"$1\": illegal $2 into unordered collection" },
  { "ZDDY0013", "\"$1\": can not delete collection because indexes reference it" },
  { "ZDDY0014", "\"$1\": can not delete collection because integrity constraints reference it" },
  { "ZDDY0015", "\"$1\": can not delete collection because there are references to its nodes" },
  { "ZDDY0016", "\"$1\": multiple attemps to create a collection in the same snapshot" },
  { "ZDDY0017", "node does not belong to any collection" },
  { "ZDDY0018", "all nodes must be in same collection" },
  { "ZDDY0020", "\"$1\": index domain expression yields nodes that are not in collection" },
  { "ZDDY0021", "\"$1\": undeclared index" },
  { "ZDDY0022", "\"$1\": index already exists" },
  { "ZDDY0023", "\"$1\": index does not exist" },
  { "ZDDY0024", "\"$1\": index uniqueness violation" },
  { "ZDDY0025", "\"$1\": invalid number of arguments to $2 operation; given $3 expected $4" },
  { "ZDDY0026", "\"$1\": index range probe not allowed" },
  { "ZDDY0027", "\"$1\": index multiple creates" },
  { "ZDDY0028", "\"$1\": index domain has duplicate nodes" },
  { "ZDDY0029", "\"$1\": index point-general probe not allowed" },
  { "ZDDY0030", "\"$1\": index range-general probe not allowed" },
  { "ZDDY0031", "\"$1\": integrity constraint is not declared" },
  { "ZDDY0032", "\"$1\": integrity constraint is not activated" },
  { "ZDDY0033", "\"$1\": integrity constraint not met for collection \"$2\"" },
  { "ZDDY0034", "\"$1\": index range-value probe has search keys with incompatible types" },
  { "ZDDY0035", "\"$1\": index inserting more than one key not allowed for general index" },
  { "ZDDY0036", "attempt to delete non-root node from collection \"$1\"" },
  { "ZDST0001", "\"$1\": collection already declared" },
  { "ZDST0002", "\"$1\": collection already imported into module \"$2\"" },
  { "ZDST0003", "\"$1\": collection declaration not allowed in main module" },
  { "ZDST0004", "collection multiple property values" },
  { "ZDST0006", "\"$1\": invalid annotation for collection \"$2\"" },
  { "ZDST0007", "\"$1\": collection declaration in foreign module" },
  { "ZDST0021", "\"$1\": index already declared" },
  { "ZDST0022", "\"$1\": index already imported into module \"$2\"" },
  { "ZDST0023", "\"$1\": index declaration not allowed in main module" },
  { "ZDST0024", "index multiple property values" },
  { "ZDST0025", "\"$1\": index cannot be declared as unique" },
  { "ZDST0026", "index invalid property value" },
  { "ZDST0027", "\"$1\": index bad key type" },
  { "ZDST0028", "\"$1\": index not deterministic" },
  { "ZDST0029", "\"$1\": index invalid data source" },
  { "ZDST0030", "\"$1\": index non-constant data source" },
  { "ZDST0031", "\"$1\": index has free vars" },
  { "ZDST0032", "\"$1\": index references context item" },
  { "ZDST0033", "\"$1\": index non-simple expression" },
  { "ZDST0034", "\"$1\": index can not do automatic maintenance" },
  { "ZDST0035", "\"$1\": number of key expressions for general indexes is restricted to one expression" },
  { "ZDST0036", "\"$1\": index declaration in foreign module" },
  { "ZDST0041", "\"$1\": integrity constraint already declared" },
  { "ZDST0044", "\"$1\": integrity constraint declaration not allowed in main module" },
  { "ZDST0048", "\"$1\": integrity constraint declaration in foreign module" },
  { "ZDST0060", "\"$1\": feature not supported; $2" },
  { "ZDTY0001", "\"$1\": invalid item type in collection \"$2\"" },
  { "ZDTY0010", "non-node item in domain expression of index $1" },
  { "ZDTY0011", "item type \"$1\" does not match declared type \"$2\" for key expression of index $3" },
  { "ZDTY0012", "\"$1\": general range index key item has type for which no ordering relationship exists" },
#if defined(ZORBA_WITH_DEBUGGER)
  { "ZGDB0001", "" },
#endif
  { "ZJPE0001", "'$1': illegal JSON character" },
  { "ZJPE0002", "\"$1\": illegal Unicode code-point" },
  { "ZJPE0003", "'\\$1': illegal JSON character escape" },
  { "ZJPE0004", "illegal JSON literal" },
  { "ZJPE0005", "illegal JSON number" },
  { "ZJPE0006", "\"$1\": unexpected JSON token" },
  { "ZJPE0007", "unterminated JSON string" },
  { "ZJPE0008", "\"$1\": illegal QName" },
  { "ZJPE0009", "illegal empty string" },
  { "ZJPE0010", "JsonML (array form) must start with '['" },
  { "ZJSE0001", "JSON serialization requires document or element node" },
  { "ZJSE0002", "\"$1\" element missing required \"$2\" attribute" },
  { "ZJSE0003", "\"$1\": illegal value for attribute \"$2\"" },
  { "ZJSE0004", "\"$1\": illegal element${; must be \"2\"}${ or \"3\"}" },
  { "ZJSE0005", "\"$1\": illegal child element of \"$2\" type; must be \"$3\"" },
  { "ZJSE0006", "JSON type \"$1\" can not have a child element node" },
  { "ZJSE0007", "JSON type \"$1\" can not have a child text node" },
  { "ZJSE0008", "\"$1\": illegal value for JSON type \"$2\"" },
  { "ZOSE0001", "\"$1\": file not found" },
  { "ZOSE0002", "\"$1\": not plain file" },
  { "ZOSE0003", "stream read failure" },
  { "ZOSE0004", "${\"1\": }I/O error${: 2}" },
  { "ZOSE0005", "\"$1\": error loading dynamic library${: 2}" },
  { "ZOSE0006", "stream transcoding error ($1)" },
  { "ZSTR0001", "\"$1\": index already exists" },
  { "ZSTR0002", "\"$1\": index does not exist" },
  { "ZSTR0003", "\"$1\": partial key insertion into index \"$2\"" },
  { "ZSTR0004", "\"$1\": partial key deletion from index \"$2\"" },
  { "ZSTR0007", "\"$1\": unsupported probe condition for index \"$2\"" },
  { "ZSTR0008", "\"$1\": collection already exists" },
  { "ZSTR0009", "\"$1\": collection not found" },
  { "ZSTR0010", "can not insert node into colletion \"$1\" because it already belongs to collection \"$2\"" },
  { "ZSTR0011", "non-root node can not be inserted into collection \"$1\"" },
  { "ZSTR0012", "non-node item used with collection \"$1\"" },
  { "ZSTR0013", "an item that is not a node, object, or array is used with collection \"$1\"" },
  { "ZSTR0015", "\"$1\": integrity constraint already exists" },
  { "ZSTR0016", "\"$1\": integrity constraint does not exist" },
  { "ZSTR0020", "loader I/O error${: 1}" },
  { "ZSTR0021", "loader parsing error${: 1}" },
  { "ZSTR0030", "NodeID error${: 1}" },
  { "ZSTR0040", "type error${: 1}" },
  { "ZSTR0041", "NaN comparison" },
  { "ZSTR0045", "duplicate node found in sequence" },
  { "ZSTR0050", "\"$1\" not implemented for item type \"$2\"" },
  { "ZSTR0055", "streamable string has already been consumed" },
  { "ZSTR0060", "out of range: $1" },
  { "ZSTR0065", "Zorba did not close properly, objects may still in memory.\n$1 referenced URI(s) remain in the string pool.\nFor help avoiding this message please refer to http://www.zorba-xquery.com/html/documentation in section General Architecture -> Memory Leaks." },
  { "ZSTR0066", "$1: does not reference a node in collection $2." },
  { "ZWST0002", "\"$1\": unknown or unsupported annotation" },
  { "ZWST0003", "\"$1\": function declared sequential, but has non-sequential body" },
  { "ZWST0004", "Sequential FLWOR expr may not have the semantics you expect" },
  { "ZWST0005", "\"$1\": function caching not possible; $2" },
  { "ZWST0006", "\"$1\": function caching might not give the intended result because the function is declared as $2" },
  { "ZXQD0001", "\"$1\": prefix not declared when calling function \"$2\" from $3" },
  { "ZXQD0002", "\"$1\": $2" },
  { "ZXQD0003", "inconsistent options to the parse-xml() function: $1" },
  { "ZXQD0004", "invalid parameter: $1" },
  { "ZXQD0005", "key with type $1 not subtype or castable to target type $2 of map ($3)" },
  { "ZXQD0006", "\"$1\": invalid UTF-8 byte sequence" },
  { "ZXQP0000", "no error" },
  { "ZXQP0001", "dynamic runtime error${: 1}" },
  { "ZXQP0002", "\"$1\": assertion failed.${ The following information might help: 2}" },
  { "ZXQP0003", "internal error${: 1}" },
  { "ZXQP0004", "not yet implemented: $1" },
  { "ZXQP0005", "\"$1\": feature not enabled" },
  { "ZXQP0006", "\"$1\": unknown character encoding" },
  { "ZXQP0007", "\"$1\": function signature does not match declaration" },
  { "ZXQP0008", "\"$1\": function implementation not found" },
  { "ZXQP0009", "\"$1\": function referred to by this local-name has the local-name \"$2\" instead" },
  { "ZXQP0010", "\"$1\": builtin sequential function not implemented as sequential" },
  { "ZXQP0013", "FxCharHeap error: $1 ($2)" },
  { "ZXQP0016", "\"$1\": reserved module target namespace" },
  { "ZXQP0017", "file access disabled" },
  { "ZXQP0020", "\"$1\": invalid URI${: 2}" },
  { "ZXQP0021", "user error" },
  { "ZXQP0024", "XML does not match schema${: \"1\"}${ 2}" },
  { "ZXQP0025", "\"$1\": could not fetch resource${; reason: 2}" },
  { "ZXQP0026", "\"$1\": invalid enumerated value for $2" },
  { "ZXQP0028", "\"$1\": target namespace not provided by module from $2" },
  { "ZXQP0029", "\"$1\": URI access not allowed" },
  { "ZXQP0030", "deadlock" },
  { "ZXQP0031", "malformed XQueryX XML input${: 1}" },
  { "ZXQP0032", "error transforming XQueryX to XQuery${: 1}" },
  { "ZXQP0036", "BreakIterator creation failed" },
  { "ZXQP0037", "\"$1\": loaded module version \"$2\" does not match import version specification" },
  { "ZXQP0038", "Query requires Zorba version \"$1\"; you are running Zorba \"$2\"" },
  { "ZXQP0039", "\"$1\": invalid version specification" },
  { "ZXQP0040", "\"$1\": function invokes a nondeterministic function but is missing the nondeterministic annotation" },
  { "ZXQP0050", "\"$1\": feature not available" },
  { "ZXQP0060", "\"$1\": unkown option" },
#if !defined(ZORBA_NO_FULL_TEXT)
  { "ZXQP8401", "\"$1\": wrong WordNet file version; should be \"$2\"" },
#endif
#if !defined(ZORBA_NO_FULL_TEXT)
  { "ZXQP8402", "thesaurus data endianness does not match CPU" },
#endif
#if !defined(ZORBA_NO_FULL_TEXT)
  { "ZXQP8403", "thesaurus data error${: 1}" },
#endif
  { "~AllMatchesHasExcludes", "AllMatches contains StringExclude" },
  { "~AlreadySpecified", "already specified" },
  { "~ArithOpNotDefinedBetween_23", "arithmetic operation not defined between types \"$2\" and \"$3\"" },
  { "~AtomizationHasMoreThanOneValue", "atomization has more than one value" },
  { "~AtomizationOfGroupByMakesMoreThanOneItem", "atomization of groupby variable produces more than one item" },
  { "~AttributeName", "attribute name" },
  { "~AttributeNode", "attribute node" },
#if !defined(ZORBA_NO_ICU)
  { "~BackRef0Illegal", "\"0\": illegal backreference" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~BackRefIllegalInCharClass", "backreference illegal in character class" },
#endif
  { "~BadAnyURI", "invalid xs:anyURI" },
  { "~BadArgTypeForFn_2o34o", "${\"2\": }invalid argument type for function $3()${: 4}" },
  { "~BadCharAfter_34", "'$3': illegal character after '$4'" },
  { "~BadCharInBraces_3", "'$3': illegal character within { }" },
  { "~BadDecDigit_3", "'$3': invalid decimal digit" },
  { "~BadFileURIAuthority_2", "\"$2\": invalid authority for \"file\" scheme" },
  { "~BadHexDigit_3", "'$3': invalid hexedecimal digit" },
  { "~BadHexSequence", "invalid hexedecimal sequence" },
  { "~BadItem", "invalid item" },
  { "~BadIterator", "invalid iterator" },
  { "~BadLibraryModule", "invalid library module" },
  { "~BadPath", "invalid path" },
#if !defined(ZORBA_NO_ICU)
  { "~BadRegexEscape_3", "\"$3\": illegal escape character" },
#endif
  { "~BadStreamState", "bad I/O stream state" },
  { "~BadTokenInBraces_3", "\"$3\": illegal token within { }" },
  { "~BadTraceStream", "trace stream not retrievable using SerializationCallback" },
  { "~BadTypeFor_23", "\"$2\": invalid type for $3" },
  { "~BadType_23o", "\"$2\": invalid type${: 3}" },
  { "~BadURIScheme_3", "\"$3\": unknown URI scheme" },
  { "~BadURISyntaxForScheme_3", "invalid URI syntax for \"$3\" scheme" },
  { "~BadUnicodeChar_3", "\"$3\": invalid character code-point" },
  { "~BadWordNetPartOfSpeech_2", "\"$2\": invalid part-of-speech" },
  { "~BadWordNetPtr_2", "\"$2\": invalid pointer type" },
  { "~BadXMLDocument_2o", "malformed XML document${ at \"2\"}" },
  { "~BadXMLForXQDoc_3", "can not parse as XML for xqdoc: $3" },
  { "~BadXMLNoOpeningTag", "closing tag without matching opening tag" },
  { "~BadXQueryVersion", "unsupported XQuery version" },
  { "~Base64BadChar", "invalid Base64 character" },
  { "~Base64Multiple4", "Base64 data must be a multiple of 4 characters" },
  { "~BaseURI", "base URI" },
  { "~BoxCondTooManyColumns", "box condition has more columns than index" },
  { "~CastFromToFailed_34", "$3 to $4 cast failed" },
  { "~CharExpected_3", "'$3' expected" },
  { "~CloneNotImplemented", "clone() not implemented for expression" },
  { "~ClosingBraceWithoutOpen", "'}' encountered without '{' first" },
  { "~CollectionIteratorNotOpen", "collection iterator not open" },
  { "~DefaultCollation", "default collation" },
  { "~DivisionNoINF", "division can not have +-INF dividend" },
  { "~DivisionNoNaN", "division can not involve NaN" },
  { "~DocNodeMultipleElements", "document node has more than one element" },
  { "~EBVNotDefSeq_5", "effective boolean value not defined for sequence of more than one item that starts with \"$5\"" },
  { "~EffectiveBooleanValue", "effective boolean value" },
  { "~ElementName", "element name" },
  { "~EmptyPath", "empty path" },
  { "~EmptySeqNoCastToQName", "empty sequence can not be cast to QName" },
  { "~EmptySeqNoCastToTypeWithQuantOne", "empty sequence can not be cast to type with quantifier '1'" },
  { "~EmptySeqNoFnRemoveArg", "empty sequence not allowed as 2nd argument of fn:remove()" },
  { "~EmptySeqNoSearchItem", "empty sequence not allowed as search item of fn:index-of()" },
  { "~EmptySequence", "empty sequence" },
  { "~ErrorCodeMessage_12", "error $2: $3" },
  { "~ExpectedNumericOrDurationType", "expected numeric or duration type" },
  { "~ExpectedNumericType", "expected numeric type" },
  { "~ExpectedType_5", "expected type \"$5\"" },
  { "~ExprNoReturnUpdateList", "expression does not return a pending update list" },
  { "~ExprReturnsTooManyUpdateLists", "expression does not return a pending update list" },
  { "~ExternFnDeterministic", "only external functions may be declared deterministic" },
  { "~ExternFnNondeterministic", "only external functions may be declared nondeterministic" },
  { "~FTST0009_BadStemmerLang", "for current stemmer" },
  { "~FTST0009_BadStopWordsLang", "for current stop words" },
  { "~FTST0009_BadThesaurusLang", "for given thesaurus" },
  { "~FTST0009_BadTokenizerLang", "for current tokenizer" },
  { "~FileNotFoundOrReadable", "file not found or readable" },
  { "~FnNilledArgNotNode", "fn:nilled() argument not a node" },
  { "~FnOnlyInXQueryVersion_3", "function only available in XQuery $3" },
  { "~FormatNumberAtLeastOneOptionalOrDecimal", ": a sub-picture must contain at least one character that is an optional-digit-sign or a member of the decimal-digit-family" },
  { "~FormatNumberDuplicates", ": a sub-picture must not contain more than one of the \"$3\" sign" },
  { "~FormatNumberFractionalPart", ": the fractional part of a sub-picture must not contain an optional-digit-sign that is followed by a member of the decimal-digit-family" },
  { "~FormatNumberGroupingAdjacentToDecimal", ": a sub-picture must not contain a grouping-separator-sign adjacent to a decimal-separator-sign" },
  { "~FormatNumberIntegerPart", ": the integer part of a sub-picture must not contain a member of the decimal-digit-family that is followed by an optional-digit-sign" },
  { "~FormatNumberPercentPermille", ": a sub-picture must not contain more than one percent-sign or per-mille-sign, and it must not contain one of each" },
  { "~FullTextNotEnabled", "full-text was not enabled in this build" },
  { "~FunctionFailedErrorCodeMessage_123", "$2 failed (error $3): $4" },
  { "~FunctionFailed_12o", "$2 failed${: 3}" },
  { "~FunctionUndeclared_3", "function with arity $3 not declared" },
  { "~GoodValuesAreUTF8", "valid values are: UTF-8, UTF-16" },
  { "~GoodValuesAreXMLEtc", "valid values are: xml, html, xhtml, text, binary, json, jsoniq" },
  { "~GoodValuesAreYesNo", "valid values are: yes, no" },
  { "~GoodValuesAreYesNoOmit", "valid values are: yes, no, omit" },
  { "~GroupByVarHasMoreThanOneItem_2", "\"$2\": value of groupby variable has more than one item" },
  { "~HexBinaryMustBeEven", "HexBinary value must contain an even number of characters" },
  { "~IncompleteKeyInIndexBuild", "incomplete key during index build" },
  { "~IncompleteKeyInIndexRefresh", "incomplete key during index refresh" },
  { "~JNUP0007_Array", "\"$2\": can not be promoted to type xs:integer" },
  { "~JNUP0007_Object", "\"$2\": can not be promoted to type xs:string" },
  { "~JNUP0007_ObjectArray", "\"$2\": can not be promoted to type xs:anyAtomicType" },
  { "~JNUP0008_Array", "\"$2\": target of an appending expression or of a position-inserting expression is not an array" },
  { "~JNUP0008_Object", "\"$2\": target of a renaming expression or of a non-position-inserting expression is not an object." },
  { "~JNUP0008_ObjectArray", "\"$2\": target of a deleting or replacing expression is not a JSON item." },
  { "~JNUP0016_Array", "\"$2\": selector cannot be resolved against supplied array." },
  { "~JNUP0016_Object", "\"$2\": selector cannot be resolved against supplied object." },
  { "~JSON parser error", "JSON parser error" },
  { "~JSON serialization error", "JSON serialization error" },
  { "~JSON_ILLEGAL_CHARACTER", "'$2': illegal JSON character${ at 3}" },
  { "~JSON_ILLEGAL_CODEPOINT", "\"$2\": illegal Unicode code-point${ at 3}" },
  { "~JSON_ILLEGAL_ESCAPE", "'\\$2': illegal JSON character escape${ at 3}" },
  { "~JSON_ILLEGAL_LITERAL", "illegal JSON literal${ at 2}" },
  { "~JSON_ILLEGAL_NUMBER", "illegal JSON number${ at 2}" },
  { "~JSON_UNEXPECTED_EXTRA_CONTENT", "unexpected extra content at the end of the document (consider using the jsoniq-multiple-top-level-items option)" },
  { "~JSON_UNEXPECTED_TOKEN", "\"$2\": unexpected JSON token${ at 3}" },
  { "~JSON_UNTERMINATED_STRING", "unterminated JSON string${ at 2}" },
  { "~JSONiq dynamic error", "JSONIQ dynamic error" },
  { "~JSONiq dynamic warning", "JSONIQ dynamic warning" },
  { "~JSONiq error", "JSONIQ error" },
  { "~JSONiq serialization error", "JSONIQ serialization error" },
  { "~JSONiq serialization warning", "JSONIQ serialization warning" },
  { "~JSONiq static error", "JSONIQ static error" },
  { "~JSONiq static warning", "JSONIQ static warning" },
  { "~JSONiq type error", "JSONIQ type error" },
  { "~JSONiq type warning", "JSONIQ type warning" },
  { "~JSONiq warning", "JSONIQ warning" },
  { "~LibModVersionMismatch_3", "XQuery library version can not be imported by a $3 version module" },
  { "~ModuleNotFound", "module not found" },
  { "~MustBeAbsoluteURI", "must be absolute" },
  { "~MustBeNCName", "must be an xs:NCName" },
  { "~NoAttrNodesInDocument", "document node must not contain attribute nodes" },
  { "~NoBindURI", "namespace URI can not be bound to prefix" },
  { "~NoCastToCInt_2", "\"$2\": 2nd operand can not be cast from \"xs:integer\" to C++ \"int\"" },
  { "~NoCastTo_34o", "can not cast to \"$3\"${: 4}" },
  { "~NoCastTo_45o", "can not cast to \"$4\"${: 5}" },
  { "~NoCompareTypes_23", "can not compare item of type $2 with item of type $3" },
  { "~NoCompareWithType_4", "can not compare for equality to type \"$4\"" },
  { "~NoDriveSpecification", "missing drive specification" },
  { "~NoEmptyLocalname", "local-name can not be empty" },
  { "~NoEmptySeqAsBaseURI", "can't treat empty sequence as base URI" },
  { "~NoEmptySeqAsCollationParam", "empty-sequence not allowed as collation parameter" },
  { "~NoHashItemOfType_2", "can not hash item of type \"$2\"" },
  { "~NoInputData", "no input data" },
  { "~NoModuleURIResolver", "no module URI resolver could be retrieved using SerializationCallback" },
  { "~NoMultiKeyNodeValues_2", "node with more than one key value found during probe on index \"$2\"" },
  { "~NoParseFnArity", "could not parse function arity (maybe it's too large)" },
  { "~NoRebindPrefix", "can not rebind predefined prefix" },
  { "~NoRegisteredSerializationCallback_2", "external module \"$2\" not available using registered SerializationCallback" },
  { "~NoResolveRelativeURI", "could not resolve relative URI" },
  { "~NoSeqAsArithOp", "sequence of more than one item can not be operand for arithmetic operation" },
  { "~NoSeqAsCollationParam", "sequence of more than one item not allowed as collation parameter" },
  { "~NoSeqCastToTypeWithQuantOneOrQuestion", "sequence of more than one item can not be cast to type with quantifier '1' or '?'" },
  { "~NoSeqForConcat", "multi-item sequence can not be operand for concatenation" },
  { "~NoSeqForFnOp_2", "sequence of more than one item can not be operand for function \"$2()\"" },
  { "~NoSeqInValueComp", "sequnce of more than one item can not be in value comparisons" },
  { "~NoSeqTestedForAtomicEquiv", "sequence of more than one item can not be tested for atomic value equivalence" },
  { "~NoSerializationCallbackForDocColMod", "document, collection, or module resolver required but no SerializationCallback given" },
  { "~NoSerializationCallbackForModule", "no SerializationCallback for required external module \"$2\"" },
  { "~NoSerializationCallbackForTraceStream", "no SerializationCallback for required trace stream" },
  { "~NoSourceURI", "no URI" },
  { "~NoTreatAs_4", "can not treat as \"$4\"" },
  { "~NoTypeInCtx", "undefined type in current context" },
  { "~NoTypeInMainModule_4", "type of variable \"$4\" is not among the in-scope types of the main module" },
  { "~NoTypeInModule_45", "type of variable \"$4\" is not among the in-scope types module \"$5\"" },
  { "~NoURIAuthority", "no authority" },
  { "~NoURIInStore", "URI for document not found in store" },
  { "~NoURIScheme", "no URI scheme" },
  { "~NoUntypedKeyNodeValue_2", "node with untyped key value found during probe on index \"$2\"" },
  { "~NodeIDNeedsBytes_2", "nodeid requires more than $2 bytes" },
  { "~NodeIDTooBig", "nodeid component too big for encoding" },
#if !defined(ZORBA_NO_ICU)
  { "~NonClosedBackRef_3", "'$$3': non-closed backreference" },
#endif
  { "~NonFileThesaurusURI", "non-file thesaurus URI" },
  { "~NonLocalhostAuthority", "non-localhost authority" },
#if !defined(ZORBA_NO_ICU)
  { "~NonexistentBackRef_3", "'$$3': non-existent backreference" },
#endif
  { "~NotAllowedForTypeName", "not allowed for typeName (use xsd:untyped instead)" },
  { "~NotAmongInScopeSchemaTypes", "not among in-scope schema types" },
  { "~NotDefInDynamicCtx", "not defined in dynamic context" },
  { "~NotDocOrElementNode", "not a document or element node" },
  { "~NotInStaticCtx", "not found in static context" },
  { "~NotPlainFile", "not plain file" },
  { "~NotSpecified", "not specified" },
  { "~OpIsSameNodeMustHaveNodes", "op:is-same-node() must have nodes as parameters" },
  { "~OpNodeAfterMustHaveNodes", "op:node-after() must have nodes as parameters" },
  { "~OpNodeBeforeMustHaveNodes", "op:node-before() must have nodes as parameters" },
  { "~OperationNotDef_23", "$2 not defined for type \"$3\"" },
  { "~OperationNotPossibleWithTypes_234", "\"$2\": operation not possible with parameters of type \"$3\" and \"$4\"" },
  { "~ParseFragmentDoctypeNotAllowed", "a DOCTYPE declaration is not allowed" },
  { "~ParseFragmentDoctypeNotAllowedHere", "a DOCTYPE declaration must appear before any element or text node, and at most once" },
  { "~ParseFragmentInvalidOptions", "invalid options passed to the parse-xml:parse() function, the element must be in the schema target namespace" },
  { "~ParseFragmentOptionCombinationNotAllowed", "only one of the <schema-validate/>, <DTD-validate/> or <parse-external-parsed-entity/> options can be specified" },
  { "~ParserInitFailed", "parser initialization failed" },
  { "~ParserNoCreateTree", "XML tree creation failed" },
  { "~PromotionImpossible", "promotion not possible" },
  { "~QuotedColon_23", "\"$2\": $3" },
#if defined(ZORBA_NO_ICU)
  { "~REGEX_BROKEN_PIs_CONSTRUCT", "broken \\p{Is} construct; valid characters are [a-zA-Z0-9-]" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_BROKEN_P_CONSTRUCT", "broken \\p construct" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_INVALID_ATOM_CHAR", "'$3': invalid character for an atom; forbidden characters are: [{}?*+|^]" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_INVALID_BACK_REF", "\\$3 backreference to a non-existent capture group ($4 groups so far)" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_INVALID_SUBCLASS", "malformed class subtraction" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_INVALID_UNICODE_CODEPOINT_u", "invalid unicode hex, should be in form \\uXXXX or \\UXXXXXXXX" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_INVALID_USE_OF_SUBCLASS", "improper use of class subtraction: it must be the last construct in a class group [xxx-[yyy]]" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_MAX_LT_MIN", "in {min,max}, max is less than min" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_MISMATCHED_PAREN", "incorrectly nested parentheses" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_MISSING_CLOSE_BRACKET", "missing ']' in character group" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_MULTICHAR_IN_CHAR_RANGE", "multichars or char categories cannot be part of a char range" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNIMPLEMENTED", "use of regular expression feature that is not yet implemented" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_ESC_CHAR", "unknown \\? escape char; supported escapes are: \\[nrt\\|.?*+(){}[]-^$] for char escapes, \\[pP] for categories and \\[sSiIcCdDwW] for multichar groups" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_PC_CONSTRUCT", "unknown \\p{C?} category; supported categories: C, Cc, Cf, Co, Cn(for not assigned)" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_PIs_CONSTRUCT", "unknown \\p{Is} category block; see supported block escapes here: http://www.w3.org/TR/xmlschema-2/#charcter-classes" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_PL_CONSTRUCT", "unknown \\p{L?} category; supported categories: L, Lu, Ll, Lt, Lm, Lo" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_PM_CONSTRUCT", "unknown \\p{M?} category; supported categories: M, Mn, Mc, Me" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_PN_CONSTRUCT", "unknown \\p{N?} category; supported categories: N, Nd, Nl, No" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_PP_CONSTRUCT", "unknown \\p{P?} category; supported categories: P, Pc, Pd, Ps, Pe, Pi, Pf, Po" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_PS_CONSTRUCT", "unknown \\p{S?} category; supported categories: S, Sm, Sc, Sk, So" },
#endif
#if defined(ZORBA_NO_ICU)
  { "~REGEX_UNKNOWN_PZ_CONSTRUCT", "unknown \\p{Z?} category; supported categories: Z, Zs, Zl, Zp" },
#endif
  { "~SEPM0009_Not10", "the version parameter has a value other than \"1.0\" and the doctype-system parameter is specified" },
  { "~SEPM0009_NotOmit", "the standalone attribute has a value other than \"omit\"" },
  { "~SchemaAttributeName", "schema-attribute name" },
  { "~SchemaElementName", "schema-element name" },
  { "~SchemaOutOfMemory", "OutOfMemoryException during parsing" },
  { "~SchemaParseError", "error during parsing" },
  { "~SchemaUnexpected", "unexpected exception during parsing" },
  { "~SearchKeyTypeMismatch_234", "\"$2\": search key type for index \"$3\" does not match expected type \"$4\"" },
  { "~SearchKeyTypeNoProbeIndex_23", "\"$2\": search key type can not probe index \"$3\"" },
  { "~SeqFnBody", "only a function declared sequential can have a body that is a sequential expression" },
  { "~SeqNoCastToQName", "sequence of more than one item can not be cast to QName" },
  { "~SingletonExpected_2o", "singleton expected${ (2)}" },
  { "~StackOverflow", "stack overflow" },
  { "~StingLiteral", "string literal" },
  { "~StringValue", "string value" },
  { "~SumImpossibleWithTypes_23", "sum not possible with parameters of type \"$2\" and \"$3\"" },
  { "~TrailingChar_3", "trailing '$3'" },
  { "~TwoDecimalFormatsSameName_2", "\"$2\": two decimal formats with this name" },
  { "~TwoDefaultDecimalFormats", "two default decimal formats" },
  { "~TypeIsNotSubtype", "item type is not a subtype of \"$3\"" },
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_BAD_ESCAPE_SEQUENCE", "unrecognized backslash escape sequence" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_BAD_INTERVAL", "error in {min,max} interval" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_INTERNAL_ERROR", "an internal ICU error (bug) was detected" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_INVALID_BACK_REF", "backreference to a non-existent capture group" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_INVALID_FLAG", "invalid value for match mode flags" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_INVALID_RANGE", "in character range [x-y], x is greater than y" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_INVALID_STATE", "RegexMatcher in invalid state for requested operation" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_LOOK_BEHIND_LIMIT", "look-behind pattern matches must have a bounded maximum length" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_MAX_LT_MIN", "in {min,max}, max is less than min" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_MISMATCHED_PAREN", "incorrectly nested parentheses" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_MISSING_CLOSE_BRACKET", "missing ']'" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_NUMBER_TOO_BIG", "decimal number is too large" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_OCTAL_TOO_BIG", "octal character constants must be <= 0377" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_PROPERTY_SYNTAX", "incorrect Unicode property" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_RULE_SYNTAX", "syntax error" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_SET_CONTAINS_STRING", "can not have UnicodeSets containing strings" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_STACK_OVERFLOW", "backtrack stack overflow" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_STOPPED_BY_CALLER", "matching operation aborted by user callback fn" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_TIME_OUT", "maximum allowed match time exceeded" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~U_REGEX_UNIMPLEMENTED", "use of regular expression feature that is not yet implemented" },
#endif
  { "~UnaryArithOp", "unary arithmetic operator" },
#if !defined(ZORBA_NO_ICU)
  { "~UnbalancedChar_3", "unbalanced '$3'" },
#endif
#if !defined(ZORBA_NO_ICU)
  { "~UnescapedChar_3", "character '$3' must be escaped here" },
#endif
  { "~UnexpectedElement", "unexpected element" },
  { "~VarValMustBeSingleItem_2", "\"$2\": variable value must be single item" },
  { "~Variable", "variable" },
  { "~VariabledHasNoValue", "variable has no value" },
  { "~VariabledUndeclared", "undeclared variable" },
  { "~XMLSchema", "XML schema" },
  { "~XPST0003_Anotations", "function and variable annotations only available in XQuery 3.0 or later" },
  { "~XPST0003_CountClause11", "\"count\" clause only available in XQuery 3.0 or later" },
  { "~XPST0003_ModuleDeclNotInMain", "module declaration must not be in main module" },
  { "~XPST0003_OuterForClause11", "\"outer-for\" clause only available in XQuery 3.0 or later" },
  { "~XPST0003_PiTarget", "\"XML\" not allowed as target of a direct processing-instruction constructor" },
  { "~XPST0003_Scripting", "scripting feature not available" },
  { "~XPST0003_StartEndTagMismatch_23", "start tag \"$2\" does not match end tag \"$3\"" },
  { "~XPST0003_SwitchExpr11", "\"switch\" expressions only available in XQuery 3.0 or later" },
  { "~XPST0003_TryCatchExpr11", "\"try/catch\" expressions only available in XQuery 3.0 or later" },
  { "~XPST0003_WindowClause11", "\"window\" clause only available in XQuery 3.0 or later" },
  { "~XPST0003_XQueryVersionAtLeast30_2", "\"$2\": XQuery version must be at least 3.0" },
  { "~XPTY0004_FormatNumber_2", "the first parameter to the format-number() function is of type $2, which is not allowed" },
  { "~XPTY0004_FuncParam", "$2 can not be promoted to parameter type $3 of function $4()" },
  { "~XPTY0004_FuncReturn", "$2 can not be promoted to return type $3 of function $4()" },
  { "~XPTY0004_NoMultiSeqTypePromotion", "sequence of more than one item can not be promoted to type $2" },
  { "~XPTY0004_TypeMatch", "$2 can not be treated as type $3" },
  { "~XPTY0004_TypePromotion", "$2 can not be promoted to type $3" },
  { "~XQST0106_CONFLICTING", "conflicting" },
  { "~XQST0106_THE_SAME", "the same" },
  { "~XUDY0021_AppliedAt", "applied at $2" },
  { "~XUST0001_CONCAT", "comma expression with updating and non-updating branches" },
  { "~XUST0001_Generic", "updating expression illegal here" },
  { "~XUST0001_IF", "conditional expression with updating and non-updating branch" },
  { "~XUST0001_TRYCATCH", "try-catch expression with updating and non-updating clauses" },
  { "~XUST0001_UDF_2", "\"$2\": function declared simple but body is updating" },
  { "~XUST0002_Transform", "transform expression witn non-updating or vacuous modify clause" },
  { "~XUST0002_UDF_2", "\"$2\": function declared updating but body is not updating or vacuous" },
  { "~ZDST0060_unknown_localname", "unknown localname ($3)" },
  { "~ZDST0060_unknown_namespace", "unknown namespace ($3)" },
  { "~ZWST0005_PARAM_TYPE", "type of parameter $3 is $4 which is not a subtype of xs:anyAtomicType" },
  { "~ZWST0005_RETURN_TYPE", "return type ($3) is not subtype of xs:anyAtomicType" },
  { "~ZWST0005_UPDATING", "function is updating" },
  { "~ZWST0005_VARIADIC", "function is variadic" },
  { "~ZXQD0004_NON_NEGATIVE", "given value must be non-negative ($2)" },
  { "~ZXQD0004_NOT_WITHIN_RANGE", "not within allowed range ($2)" },
  { "~ZXQP0004_TypeOps_is_in_scope_ForFunctionItemTypes", "TypeOps::is_in_scope() for function-item types" },
  { "~ZXQP0025_RESOURCE_NOT_FOUND", "resource not found" },
  { "~ZeroLenURI", "zero-length URI (and no base URI given)" },
  { "~Zorba API error", "Zorba API error" },
  { "~Zorba data-definition error", "Zorba data-definition error" },
  { "~Zorba dynamic error", "Zorba dynamic error" },
  { "~Zorba dynamic warning", "Zorba dynamic warning" },
  { "~Zorba error", "Zorba error" },
  { "~Zorba serialization error", "Zorba serialization error" },
  { "~Zorba serialization warning", "Zorba serialization warning" },
  { "~Zorba static error", "Zorba static error" },
  { "~Zorba static warning", "Zorba static warning" },
  { "~Zorba store error", "Zorba store error" },
  { "~Zorba type error", "Zorba type error" },
  { "~Zorba type warning", "Zorba type warning" },
  { "~Zorba warning", "Zorba warning" },
  { "~dynamic error", "dynamic error" },
  { "~dynamic warning", "dynamic warning" },
  { "~error", "error" },
  { "~format_integer_bad_picture_format", "bad $picture format: $2" },
  { "~format_integer_duplicated_optional_format_modifier", "duplicated optional format modifier '$2'" },
  { "~format_integer_optional_format_modifier_not_closed", "bad optional format modifier ($2), cannot find closing ')' " },
  { "~format_integer_picture_empty", "$picture parameter should not be empty" },
  { "~format_integer_unknown_optional_format_modifier_character", "unknown optional format modifier character '$2'" },
  { "~format_integer_value_1_10", "$value ($2) should be between 1 and 10 for this formatting picture" },
  { "~format_integer_value_1_20", "$value ($2) should be between 1 and 20 for this formatting picture" },
  { "~format_integer_value_gt_3000", "$value ($2) should be less than 3000 for Roman representation" },
  { "~full-text dynamic error", "full-text dynamic error" },
  { "~full-text dynamic warning", "full-text dynamic warning" },
  { "~full-text static error", "full-text static error" },
  { "~full-text static warning", "full-text static warning" },
  { "~full-text type error", "full-text type error" },
  { "~full-text type warning", "full-text type warning" },
  { "~operating system error", "operating system error" },
  { "~scripting static error", "scripting static error" },
  { "~scripting static warning", "scripting static warning" },
  { "~serialization error", "serialization error" },
  { "~serialization warning", "serialization warning" },
  { "~static error", "static error" },
  { "~static warning", "static warning" },
  { "~type error", "type error" },
  { "~type warning", "type warning" },
  { "~update dynamic error", "update dynamic error" },
  { "~update dynamic warning", "update dynamic warning" },
  { "~update static error", "update static error" },
  { "~update static warning", "update static warning" },
  { "~update type error", "update type error" },
  { "~update type warning", "update type warning" },
  { "~user-defined error", "user-defined error" },
  { "~user-defined warning", "user-defined warning" },
  { "~warning", "warning" },
  { "~xqueryx_empty_content", "xqueryx content is empty" },
};
DEF_DICT_END(en);

} // namespace dict
} // namespace diagnostic
} // namespace zorba
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
