/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_types.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "node_types.h"

using namespace std;
namespace xqp {

/*______________________________________________________________________
|
|	Implementation of the specification in
|		"XQuery 1.0 and XPath 2.0 Data Model (XDM)"
|		[http://www.w3.org/TR/xpath-datamodel/]
|_______________________________________________________________________*/


//////////////////////////////////////////////
//	6.0 Nodes
//////////////////////////////////////////////

rchandle<item_iterator> node::attributes(context *const _p) const
{ return NULL; }
rchandle<item_iterator> node::base_uri(context *const _p) const
{ return NULL; }
rchandle<item_iterator> node::children(context *const _p) const
{ return NULL; }
rchandle<item_iterator> node::document_uri(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::is_id(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::is_idrefs(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::namespace_bindings(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::namespace_nodes(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::nilled(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::node_name(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::parent(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::type_name(context *const _p) const 
{ return NULL; }
rchandle<item_iterator> node::typed_value(context *const _p) const 
{ return NULL; }

rchandle<item_iterator> node::unparsed_entity_public_id(
  context *const context_p,
  string const& entity_name) const
{ 
  return NULL; 
}
  
rchandle<item_iterator> node::unparsed_entity_system_id(
  context *const context_p,
  string const& entity_name) const
{ 
  return NULL; 
}



//////////////////////////////////////////////
//	6.1 Document Nodes
//////////////////////////////////////////////

rchandle<item_iterator> document_node::base_uri(
  context *const context_p) const
{
  return NULL;
}


rchandle<item_iterator> document_node::children(
  context *const context_p) const
{
  return NULL;
}


rchandle<item_iterator> document_node::document_uri(
  context *const context_p) const
{
  return NULL;
}


std::string document_node::string_value(
  context *const context_p) const
{
  return "";
}


rchandle<item_iterator> document_node::typed_value(
  context *const context_p) const
{
  return NULL;
}


rchandle<item_iterator> document_node::unparsed_entity_public_id(
	context *const context_p,
	string const& entityname) const
{
  return NULL;
}


rchandle<item_iterator> document_node::unparsed_entity_system_id(
	context *const context_p,
	string const& entityname) const
{
  return NULL;
}


//document_node::document_node(infoset const& _info)
	/*
	* base-uri
	* The value of the [base URI] property.
	*/

	/*
	* children
	* The sequence of nodes constructed from the information items found
	*	in the [children] property.
	*
	* For each element, processing instruction, and comment found in the 
	*	[children] property, a corresponding Element, Processing Instruction, 
	*	or Comment Node is constructed and that sequence of nodes is used as 
	*	the value of the children property. 
	*
	* If present among the [children], the document type declaration 
	*	information item is ignored. 
	*/

	/*
	* unparsed-entities
	* If the [unparsed entities] property is present and is not the 
	*	empty set, the values of the unparsed entity information items must be 
	*	used to support the dm:unparsed-entity-system-id and 
	*	dm:unparsed-entity-public-id accessors. 
	*
	* The internal structure of the values of the unparsed-entities 
	*	property is implementation defined. 
	*/

	/*
	* string-value
	* The concatenation of the string-values of all its Text Node 
	*	descendants in document order. If the document has no such 
	*	descendants, the zero-length string. 
	*/

	/*
	* typed-value
	* The dm:string-value of the node as an xs:untypedAtomic value.
	*/

	/*
	* document-uri
	* The document-uri property holds the absolute URI for the resource 
	*	from which the document node was constructed, if one is available and 
	*	can be made absolute. For example, if a collection of documents is 
	*	returned by the fn:collection function, the document-uri property may 
	*	serve to distinguish between them even though each has the same 
	*	base-uri property. 
	*
	* If the document-uri is not the empty sequence, then the following 
	*	constraint must hold: the node returned by evaluating fn:doc() with 
	*	the document-uri as its argument must return the document node that 
	*	provided the value of the document-uri property. 
	*
	* In other words, for any Document Node $arg, either 
	*	fn:document-uri($arg) must return the empty sequence or 
	*	fn:doc(fn:document-uri($arg)) must return $arg.
	*/


//document_node::document_node(psvi const& _psvi)
	/*
	* Construction from a PSVI is identical to construction from the Infoset.
	*/


//rchandel<infoset> document_node::infoset_map() const
	/*
	* A Document Node maps to a document information item. The mapping fails 
	* and produces no value if the Document Node contains Text Node children 
	* that do not consist entirely of white space or if the Document Node 
	* contains more than one Element Node child. 
	*/ 

	/*
	* [children]
	* A list of information items obtained by processing each of the 
	* dm:children in order and mapping each to the appropriate information 
	* item(s). 
	*/ 

	/*
	* [document element]
	* The element information item that is among the [children].
	*/ 

	/*
	* [unparsed entities]
	* An unordered set of unparsed entity information items constructed 
	* from the unparsed-entities. 
	*
	* Each unparsed entity maps to an unparsed entity information item. 
	* The following properties are specified by this mapping: 
	*/ 

	/*
	* [name]
	* The name of the entity.
	*/ 

	/*
	* [system identifier]
	* The system identifier of the entity.
	*/ 

	/*
	* [public identifier]
	* The public identifier of the entity.
	*/ 

	/*
	* [declaration base URI]
	* Implementation defined. In the many cases, the document-uri is 
	* the correct answer and implementations must use this value if they 
	* have no better information. Implementations that keep track of the 
	* original [declaration base URI] for entities should use that value. 
	*/ 

	/*
	* The following properties of the unparsed entity information item 
	* have no value: [notation name], [notation]. 
	*
	* The following properties of the document information item have no 
	* value: [notations] [character encoding scheme] [standalone] [version] 
	* [all declarations processed]. 
	*/ 
	




//////////////////////////////////////////////
//	6.2 Element Nodes
//////////////////////////////////////////////

/*
Construction from an Infoset

The following infoset properties are required: 
  [namespace name], 
  [local name], 
  [children], 
  [attributes], 
  [in-scope namespaces], 
  [base URI],
  [parent]. 


base-uri
  The value of the [base URI] property.

node-name
  An xs:QName constructed from the [prefix], [local name], and 
	[namespace name] properties. 

parent
  The node that corresponds to the value of the [parent] property or 
	the empty sequence if there is no parent. 

type-name
  All Element Nodes constructed from an infoset have the type 
	xs:untyped. 

children
  The sequence of nodes constructed from the information items found 
	in the [children] property. 

  For each element, processing instruction, comment, and maximal 
	sequence of adjacent character information items found in the 
	[children] property, a corresponding Element, Processing Instruction, 
	Comment, or Text Node is constructed and that sequence of nodes is 
	used as the value of the children property. 

  Because the data model requires that all general entities be 
	expanded, there will never be unexpanded entity reference information 
	item children. 
	attributes

  A set of Attribute Nodes constructed from the attribute 
	information items appearing in the [attributes] property. This 
	includes all of the "special" attributes (xml:lang, xml:space, 
	xsi:type, etc.) but does not include namespace declarations (because 
	they are not attributes). 

  Default and fixed attributes provided by the DTD are added to the 
	[attributes] and are therefore included in the data model attributes 
	of an element. 
	namespaces

  A set of Namespace Nodes constructed from the namespace 
	information items appearing in the [in-scope namespaces] property. 
	Implementations that do not support Namespace Nodes may simply 
	preserve the relevant bindings in this property. 

  Implementations may ignore namespace information items for 
	namespaces which are not known to be used. A namespace is known to be 
	used if: 
		* It appears in the expanded QName of the node-name of the 
			element. 
    * It appears in the expanded QName of the node-name of any of 
			the element's attributes. 

  Note: applications may rely on namespaces that are not known to be 
	used, for example when QNames are used in content and that content 
	does not have a type of xs:QName Such applications may have difficulty 
	processing data models where some namespaces have been ignored. 
	nilled

  All Element Nodes constructed from an infoset have a nilled 
	property of "false". 

string-value
  The string-value is constructed from the character information 
	item [children] of the element and all its descendants. The precise 
	rules for selecting significant character information items and 
	constructing characters from them is described in 6.7.3 Construction 
	from an Infoset of 6.7 Text Nodes. 

  This process is equivalent to concatenating the dm:string-values 
	of all of the Text Node descendants of the resulting Element Node. 

  If the element has no such descendants, the string-value is the 
	empty string. 

typed-value
  The string-value as an xs:untypedAtomic.

is-id
  All Element Nodes constructed from an infoset have a is-id 
	property of "false". 

is-idrefs
  All Element Nodes constructed from an infoset have a is-idrefs 
	property of "false".
*/



/* 
Construction from a PSVI

The following Element Node properties are affected by PSVI properties.

type-name
  The type-name is determined as described in 3.3.1.1 Element and 
	Attribute Node Type Names. 

children
  The sequence of nodes constructed from the information items found 
	in the [children] property. 

  For each element, processing instruction, comment, and maximal 
	sequence of adjacent character information items found in the 
	[children] property, a corresponding Element, Processing Instruction, 
	Comment, or Text Node is constructed and that sequence of nodes is 
	used as the value of the children property. 

  For elements with schema simple types, or complex types with 
	simple content, if the [schema normalized value] PSVI property exists, 
	the processor may use a sequence of nodes containing the Processing 
	Instruction and Comment Nodes corresponding to the processing 
	instruction and comment information items found in the [children] 
	property, plus an optional single Text Node whose string value is the 
	[schema normalized value] for the children property. If the [schema 
	normalized value] is the empty string, the Text Node must not be 
	present, otherwise it must be present. 

  The relative order of Processing Instruction and Comment Nodes 
	must be preserved, but the position of the Text Node, if it is 
	present, among them is implementation defined. 
	
  The effect of the above rules is that where a fixed or default 
	value for an element is defined in the schema, and the element takes 
	this default value, a text node will be created to contain the value, 
	even though there are no character information items representing the 
	value in the PSVI. The position of this text node relative to any 
	comment or processing instruction children is 
	implementation-dependent. 

  [Schema Part 1] also permits an element with mixed content to take 
	a default or fixed value (which will always be a simple value), but at 
	the time of this writing it is unclear how such a defaulted value is 
	represented in the PSVI. Implementations therefore may represent such 
	a default value by creating a text node, but are not required to do 
	so. 

  Because the data model requires that all general entities be 
	expanded, there will never be unexpanded entity reference information 
	item children. 
	attributes

  A set of Attribute Nodes constructed from the attribute 
	information items appearing in the [attributes] property. This 
	includes all of the "special" attributes (xml:lang, xml:space, 
	xsi:type, etc.) but does not include namespace declarations (because 
	they are not attributes). 

  Default and fixed attributes provided by XML Schema processing are 
	added to the [attributes] and are therefore included in the data model 
	attributes of an element. 
	namespaces

  A set of Namespace Nodes constructed from the namespace 
	information items appearing in the [in-scope namespaces] property. 
	Implementations that do not support Namespace Nodes may simply 
	preserve the relevant bindings in this property. 

  Implementations may ignore namespace information items for 
	namespaces which are not known to be used. A namespace is known to be 
	used if: 

		* It appears in the expanded QName of the node-name of the element. 
		* It appears in the expanded QName of the node-name of any of the 
			element's attributes. 
		* It appears in the expanded QName of any values of type xs:QName 
			that appear among the element's children or the typed values of its 
			attributes. 

  Note: applications may rely on namespaces that are not known to be 
	used, for example when QNames are used in content and that content 
	does not have a type of xs:QName Such applications may have difficulty 
	processing data models where some namespaces have been ignored. 
	nilled

  If the [validity] property exists on an information item and is 
	"valid" then if the [nil] property exists and is true, then the nilled 
	property is "true". In all other cases, including all cases where 
	schema validity assessment was not attempted or did not succeed, the 
	nilled property is "false". 

string-value
  The string-value is calculated as follows:
  
    * If the element is empty: its string value is the zero length string.
    * If the element has a type of xs:untyped, a complex type with 
			element-only content, or a complex type with mixed content: its 
			string-value is the concatenation of the string-values of all its Text 
			Node descendants in document order. 
    * If the element has a simple type or a complex type with 
			simple content: its string-value is the [schema normalized value] of 
			the node. 

  If an implementation stores only the typed value of an element, it 
	may use any valid lexical representation of the typed value for the 
	string-value property. 

typed-value
  The typed-value is calculated as follows:

    * If the element is of type xs:untyped, its typed-value is its 
			dm:string-value as an xs:untypedAtomic. 
    * If the element has a complex type with empty content, its 
			typed-value is the empty sequence. 
    * If the element has a simple type or a complex type with 
			simple content: its typed value is computed as described in 3.3.1.2 
			Typed Value Determination. The result is a sequence of zero or more 
			atomic values. The relationship between the type-name, typed-value, 
			and string-value of an element node is consistent with XML Schema 
			validation. 

      Note that in the case of dates and times, the timezone is 
			preserved as described in 3.3.2 Dates and Times, and in the case of 
			xs:QNames and xs:NOTATIONs, the prefix is preserved as described in 
			3.3.3 QNames and NOTATIONS. 

    * If the element has a complex type with mixed content 
			(including xs:anyType), its typed-value is its dm:string-value as an 
			xs:untypedAtomic. 
    * Otherwise, the element must be a complex type with 
			element-only content. The typed-value of such an element is undefined. 
			Attempting to access this property with the dm:typed-value accessor 
			always raises an error. 

is-id
  If the element has a complex type with element-only content, the 
  is-id property is false. Otherwise, if the typed-value of the element 
  consists of exactly one atomic value that value is of type xs:ID, or a 
  type derived from xs:ID, the is-id property is true, otherwise it is 
  false. 
  
is-idrefs
  If the element has a complex type with element-only content, the 
  is-idrefs property is false. Otherwise, if any of the atomic values in 
  the typed-value of the element is of type xs:IDREF or xs:IDREFS, or a 
  type derived from one of those types, the is-idrefs property is true, 
  otherwise it is false. 

All other properties have values that are consistent with construction 
from an infoset. 
*/


/*
Infoset Mapping

[namespace name]
  The namespace name of the value of dm:node-name.

[local name]
  The local part of the value of dm:node-name.

[prefix]
  The prefix associated with the value of dm:node-name.

[children]
  A list of information items obtained by processing each of the 
  dm:children in order and mapping each to the appropriate information 
  item(s). 

[attributes]
  An unordered set of information items obtained by processing each 
  of the dm:attributes and mapping each to the appropriate information 
  item(s). 

[in-scope namespaces]
  An unordered set of namespace information items constructed from 
  the namespaces. 

  Each in-scope namespace maps to a namespace information item. The 
  following properties are specified by this mapping: 

  [prefix]
    The prefix associated with the namespace.
  [namespace name]
    The URI associated with the namespace.

[base URI]
  The value of dm:base-uri.

[parent]
  * If this node is the root of the infoset mapping operation, 
    unknown. 
  * If this node has a parent, the information item that 
    corresponds to the node returned by dm:parent. 
  * Otherwise no value.

The following property has no value: [namespace attributes].
*/

rchandle<item_iterator> element_node::attributes(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::base_uri(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::children(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::is_id(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::is_idrefs(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::namespace_bindings(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::namespace_nodes(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::nilled(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::node_name(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::parent(
  context *const context_p) const
{
  return NULL;
}

std::string element_node::string_value(
  context *const context_p) const
{
  return "";
}

rchandle<item_iterator> element_node::type_name(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::typed_value(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> element_node::unparsed_entity_public_id(
  context *const context_p,
  std::string const& entityname) const
{
  return NULL;
}

rchandle<item_iterator> element_node::unparsed_entity_system_id(
  context *const context_p,
  std::string const& entityname) const
{
  return NULL;
}



///////////////////////////////
//  6.3 Attribute Nodes
///////////////////////////////

/*
Construction from an Infoset

The following infoset properties are required: 
  [namespace name], 
  [local name], 
  [normalized value], 
  [attribute type],
  [owner element]. 

node-name
  An xs:QName constructed from the [prefix], [local name], and 
  [namespace name] properties. 

parent
  The Element Node that corresponds to the value of the [owner 
  element] property or the empty sequence if there is no owner. 

type-name
  The value xs:untypedAtomic.

string-value
  The [normalized value] of the attribute.

typed-value
  The attribute's typed-value is its dm:string-value as an 
  xs:untypedAtomic. 
    
is-id
  If the attribute is named xml:id and its [attribute type] property 
  does not have the value ID, then [xml:id] processing is performed. 
  This will assure that the value does have the type ID and that it is 
  properly normalized. The is-id is always true for attributes named 
  xml:id. 

  If the [attribute type] property has the value ID, true, otherwise 
  false. 

is-idrefs
  If the [attribute type] property has the value IDREF or IDREFS, 
  true, otherwise false.
*/


/*
Construction from a PSVI

string-value
  * The [schema normalized value] PSVI property if that exists.
  * Otherwise, the [normalized value] property.

  If an implementation stores only the typed value of an attribute, 
  it may use any valid lexical representation of the typed value for the 
  string-value property. 

type-name
  The type-name is determined as described in 3.3.1.1 Element and Attribute Node Type Names.

typed-value
  The typed-value is calculated as follows:
    * If the attribute is of type xs:untypedAtomic: its 
    typed-value is its dm:string-value as an xs:untypedAtomic.
     
    * Otherwise, a sequence of zero or more atomic values as 
    described in 3.3.1.2 Typed Value Determination. The relationship 
    between the type-name, typed-value, and string-value of an attribute 
    node is consistent with XML Schema validation. 

is-id
  If the attribute is named xml:id and its [attribute type] property 
  does not have the value ID, then [xml:id] processing is performed. 
  This will assure that the value does have the type ID and that it is 
  properly normalized. The is-id is always true for attributes named 
  xml:id. 

  If the type-name is xs:ID or a type derived from xs:ID, true, 
  otherwise false. 

is-idrefs
  If any of the atomic values in the typed-value of the attribute is 
  of type xs:IDREF or xs:IDREFS, or a type derived from one of those 
  types, the is-idrefs property is true, otherwise it is false. 

  All other properties have values that are consistent with construction 
  from an infoset. 

Note: attributes from the XML Schema instance namespace, 
"http://www.w3.org/2001/XMLSchema-instance", (xsi:schemaLocation, 
xsi:type, etc.) appear as ordinary attributes in the data model. 
*/


/*
Infoset Mapping

[namespace name]
  The namespace name of the value of dm:node-name.

[local name]
  The local part of the value of dm:node-name.

[prefix]
  The prefix associated with the value of dm:node-name.

[normalized value]
  The value of dm:string-value.

[owner element]
  * If this node has a parent, the information item that 
    corresponds to the node returned by dm:parent. 
        
  * Otherwise no value.

The following properties have no value: [specified] [attribute type] 
[references]. 

*/

rchandle<item_iterator> attribute_node::base_uri(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> attribute_node::is_id(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> attribute_node::is_idrefs(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> attribute_node::node_name(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> attribute_node::parent(
  context *const context_p) const
{
  return NULL;
}

std::string attribute_node::string_value(
  context *const context_p) const
{
  return "";
}

rchandle<item_iterator> attribute_node::type_name(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> attribute_node::typed_value(
  context *const context_p) const
{
  return NULL;
}



///////////////////////////////
//  6.4 Namespace Nodes
///////////////////////////////

/*
Construction from an Infoset

The following infoset properties are required:
  [prefix],
  [namespace name].
Namespace Node properties are derived from the infoset as follows:

prefix
    The [prefix] property.

uri
    The [namespace name] property.

parent
    The element in whose [in-scope namespaces] property the namespace 
    information item appears, if the implementation exposes any mechanism 
    for accessing the dm:parent accessor of Namespace Nodes. 
*/


/*
Construction from a PSVI
Construction from a PSVI is identical to construction from the Infoset.
*/


/*
Infoset Mapping

A Namespace Node maps to a namespace information item.
The following properties are specified by this mapping:

[prefix]
    The prefix associated with the namespace.

[namespace name]
    The value of dm:string-value.
*/


rchandle<item_iterator> ns_node::node_name(
  context *const context_p) const
{
  return NULL;
}

rchandle<item_iterator> ns_node::parent(
  context *const context_p) const
{
  return NULL;
}

std::string ns_node::string_value(
  context *const context_p) const
{
  return "";
}

rchandle<item_iterator> ns_node::typed_value(
  context *const context_p) const
{
  return NULL;
}




///////////////////////////////////////////////
//  6.5 Processing Instruction Nodes
///////////////////////////////////////////////

rchandle<item_iterator> pi_node::base_uri(
  context *const) const
{
  return NULL;
}

rchandle<item_iterator> pi_node::node_name(
  context *const) const
{
  return NULL;
}

rchandle<item_iterator> pi_node::parent(
  context *const) const
{
  return NULL;
}

std::string pi_node::string_value(
  context *const) const
{
  return "";
}

rchandle<item_iterator> pi_node::typed_value(
  context *const) const
{
  return NULL;
}



///////////////////////////////////////////////
//  6.6 Text Nodes
///////////////////////////////////////////////

rchandle<item_iterator> text_node::base_uri(
  context *const) const
{
  return NULL;
}

rchandle<item_iterator> text_node::parent(
  context *const) const
{
  return NULL;
}

std::string text_node::string_value(
  context *const) const
{
  return "";
}

rchandle<item_iterator> text_node::type_name(
  context *const) const
{
  return NULL;
}

rchandle<item_iterator> text_node::typed_value(
  context *const) const
{
  return NULL;
}
		


}	/* namespace xqp */
