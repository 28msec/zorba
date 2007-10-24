/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author Nicolae Brinza (nicolae.brinza@ipdevel.ro)
 * @file serialization/serializer.h
 *
 */


#ifndef XQP_SERIALIZER_H
#define XQP_SERIALIZER_H

#include <ostream>
#include "util/rchandle.h"
#include "store/api/item.h"
#include "util/list.h"

namespace xqp
{

class serializer : public rcobject
{
public:
	serializer();
	virtual ~serializer();

public:
	typedef list<Item_t> list_type;

	/**
	 *  Serializes the given sequence of items to the
	 *  output stream.
	 */
	void serialize_as_xml2(list_type& items, ostream& os);
	void serialize_as_xml(PlanIter_t iter, ostream& os);

	/**
	 *  Set the serializer's parameters. The list of handled 
	 *  parameters is to be detailed.
	 */
	void set_parameter(xqp_string parameter_name, xqp_string value);


protected:
	// Serialization parameters
	short int byte_order_mark; 			// "yes" or "no", implemented
	short int cdata_section_elements; 	// TODO: list of expanded QNames
	xqp_string doctype_public;
	xqp_string doctype_system;
	xqp_string encoding;				// TODO
	short int escape_uri_attributes;	// TODO: yes/no
	short int include_content_type;		// TODO: yes/no
	xqp_string media_type;
	void* method;						// TODO: an expanded QName
	xqp_string normalization_form;		// TODO:
	short int omit_xml_declaration;		// "yes" or "no", implemented
	short int standalone;				// implemented, TODO: add some validity checks
	short int undeclare_prefixes;		// TODO: yes/no
	void* use_character_maps;			// TODO: list of pairs
	xqp_string version;
	short int indent;					// "yes" or "no", implement
	
protected: 	
	static const xqp_string	END_OF_LINE;
	enum {
		INITIAL_STATE,
  		DOCUMENT_STARTED,
		PREVIOUS_NODE_WAS_TEXT		
	} state;
	
	typedef enum {
		PARAMETER_VALUE_NO,
  		PARAMETER_VALUE_YES,
		PARAMETER_VALUE_OMIT		
	} PARAMETER_VALUE_TYPE;

	void reset();	
	void list_copy(list_type& dest, list_type& src);
	
	void validate_parameters();

	/**
	 *  Normalizes the given sequence of items, as per XSLT 2.0 and 
	 *  XQuery 1.0 Serialization rules, section 2.
	 * 
	 *  @return  result of the normalization
	 */	
	void normalize_sequence(list_type& items, list_type& out);
	
	/**
	 *  The root function that performs the serialization
	 *  of a normalized sequence.
	 */
	void emit_node(Item_t item, ostream& os, int depth);
	
	/**
	 *  Serializes the given string, performing character expansion
	 *  if necessary.
	 */   
	void emit_expanded_string(xqp_string, ostream& os);

	/**
	 *  Serializes the children of the given node, without
	 *  the node itself.
	 * 
	 *  @return  the number of node's children
	 */	
	unsigned int emit_node_children(Item_t item, ostream& os, int depth);

	void emit_indentation(int depth, ostream& os);
};

} // namespace xqp

#endif // #ifdef XQP_SERIALIZER_H
