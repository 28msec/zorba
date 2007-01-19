/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: node_types.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "node.h"
#include "values.h"

using namespace std;
namespace xqp {

/*______________________________________________________________________
|
|	Implementation of the specification in
|		"XQuery 1.0 and XPath 2.0 Data Model (XDM)"
|		[http://www.w3.org/TR/xpath-datamodel/]
|_______________________________________________________________________*/

#define EMPTY_SEQUENCE(X) item_iterator((X))

//////////////////////////////////////////////
//	Nodes
//////////////////////////////////////////////

item_iterator node::attributes(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::base_uri(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::children(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::document_uri(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::namespace_bindings(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::namespace_nodes(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::node_name(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::parent(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::type_name(context const& p) const { return EMPTY_SEQUENCE(p); }
item_iterator node::typed_value(context const& p) const { return EMPTY_SEQUENCE(p); }

bool node::is_id(context const& p) const { return false; }
bool node::is_idrefs(context const& p) const { return false; }
bool node::nilled(context const& p) const { return false; }

item_iterator node::unparsed_entity_public_id(
  context const& p,
  string const& entity) const
{ 
  return EMPTY_SEQUENCE(p); 
}
  
item_iterator node::unparsed_entity_system_id(
  context const& p,
  string const& entity) const
{ 
  return EMPTY_SEQUENCE(p); 
}

enum node::node_kind_t node::node_kind() const
{
	return uninitialized_kind;
}



//////////////////////////////////////////////
//	Document Nodes
//////////////////////////////////////////////

item_iterator document_node::base_uri(
  context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator document_node::children(
  context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator document_node::document_uri(
  context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

std::string document_node::string_value(
  context const& p) const
{
  return "";
}

item_iterator document_node::typed_value(
  context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator document_node::unparsed_entity_public_id(
	context const& p,
	string const& entityname) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator document_node::unparsed_entity_system_id(
	context const& p,
	string const& entityname) const
{
  return EMPTY_SEQUENCE(p);
}



//////////////////////////////////////////////
//	Collection Nodes
//////////////////////////////////////////////

item_iterator collection_node::base_uri(
  context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator collection_node::children(
  context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator collection_node::collection_uri(
  context const& p) const
{
  return EMPTY_SEQUENCE(p);
}



//////////////////////////////////////////////
//	Element Nodes
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


std::string element_node::string_value(
	context const& p) const
{
  return "";
}

item_iterator element_node::attributes(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator element_node::base_uri(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator element_node::children(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

bool element_node::is_id(
	context const& p) const
{
  return false;
}

bool element_node::is_idrefs(
	context const& p) const
{
  return false;
}

item_iterator element_node::namespace_bindings(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator element_node::namespace_nodes(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

bool element_node::nilled(
	context const& p) const
{
  return false;
}

item_iterator element_node::node_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator element_node::parent(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator element_node::type_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator element_node::typed_value(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator element_node::unparsed_entity_public_id(
  context const& p,
  std::string const& entity) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator element_node::unparsed_entity_system_id(
  context const& p,
  std::string const& entity) const
{
  return EMPTY_SEQUENCE(p);
}



///////////////////////////////
//  Attribute Nodes
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
  The type-name is determined as described in 3.3.1.1 Element and
	Attribute Node Type Names.

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


std::string attribute_node::string_value(
	context const& p) const
{
  return "";
}

item_iterator attribute_node::base_uri(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

bool attribute_node::is_id(
	context const& p) const
{
  return false;
}

bool attribute_node::is_idrefs(
	context const& p) const
{
  return false;
}

item_iterator attribute_node::node_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator attribute_node::parent(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator attribute_node::type_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator attribute_node::typed_value(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}



///////////////////////////////
//  Namespace Nodes
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
Construction from a PSVI is identical to construction from the Infoset.
*/



std::string ns_node::string_value(
	context const& p) const
{
  return "";
}

item_iterator ns_node::node_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator ns_node::parent(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator ns_node::typed_value(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}




///////////////////////////////////////////////
//  Processing Instruction Nodes
///////////////////////////////////////////////

std::string pi_node::string_value(
	context const& p) const
{
  return "";
}

item_iterator pi_node::base_uri(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator pi_node::node_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator pi_node::parent(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator pi_node::typed_value(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}



///////////////////////////////////////////////
//  Comment Nodes
///////////////////////////////////////////////

std::string comment_node::string_value(
	context const& p) const
{
  return "";
}

item_iterator comment_node::base_uri(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator comment_node::parent(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator comment_node::type_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator comment_node::typed_value(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}



///////////////////////////////////////////////
//  Text Nodes
///////////////////////////////////////////////

std::string text_node::string_value(
	context const& p) const
{
  return "";
}

item_iterator text_node::base_uri(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator text_node::parent(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator text_node::type_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator text_node::typed_value(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}



///////////////////////////////////////////////
//  Binary Nodes
///////////////////////////////////////////////

std::string binary_node::string_value(
	context const& p) const
{
  return "";
}

item_iterator binary_node::base_uri(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator binary_node::parent(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator binary_node::type_name(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}

item_iterator binary_node::typed_value(
	context const& p) const
{
  return EMPTY_SEQUENCE(p);
}
		


}	/* namespace xqp */
