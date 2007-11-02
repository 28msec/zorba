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

class XQueryResult;
class serializer;

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
	void serialize(XQueryResult *result, ostream& os);

	/**
	 *  Set the serializer's parameters. The list of handled 
	 *  parameters is to be detailed.
	 */
	void set_parameter(xqp_string parameter_name, xqp_string value);


protected:
	// Serialization parameters
	short int byte_order_mark;         // "yes" or "no", implemented
	short int cdata_section_elements;  // TODO: list of expanded QNames
	xqp_string doctype_public;
	xqp_string doctype_system;
	xqp_string encoding;               // TODO: support UTF-16 & other?
	short int escape_uri_attributes;   // TODO: yes/no requires unicode normalization
	short int include_content_type;    // yes/no, implemented
	xqp_string media_type;             // string, implemented
	short int method;                  // an expanded QName: "xml", "html"
	xqp_string normalization_form;     // TODO:   requires unicode normalization
	short int omit_xml_declaration;    // "yes" or "no", implemented
	short int standalone;              // implemented, TODO: add some validity checks
	short int undeclare_prefixes;      // TODO: yes/no, not clear
	void* use_character_maps;          // TODO: list of pairs
	xqp_string version;                // "1.0"
	short int indent;                  // "yes" or "no", implement
	
protected: 	
	static const xqp_string	END_OF_LINE;
	
	typedef enum {
		PARAMETER_VALUE_NO,
    PARAMETER_VALUE_YES,
		PARAMETER_VALUE_OMIT,
		PARAMETER_VALUE_XML,
		PARAMETER_VALUE_HTML
	} PARAMETER_VALUE_TYPE;

	void reset();	
	void list_copy(list_type& dest, list_type& src);
	
	void validate_parameters();

  
  class emitter
  {
  public:
    emitter(serializer& the_serializer, ostream& output_stream);
    
    virtual void emit_declaration();
    virtual void emit_declaration_end();
    
    /**
     *  The root function that performs the serialization
     *  of a normalized sequence.
     */
    virtual void emit_node(Item_t item, int depth, Item_t element_parent = NULL);
    
    /**
     *  Serializes the given string, performing character expansion
     *  if necessary.
     */   
    virtual void emit_expanded_string(xqp_string, bool emit_attribute_value);
    
    /**
     *  Serializes the children of the given node, without
     *  the node itself.
     * 
     *  @return  the number of node's children
     */ 
    virtual unsigned int emit_node_children(Item_t item, int depth, bool perform_escaping);
    
    //virtual unsigned int emit_node_namespaces(Item_t item, int depth);
    //virtual unsigned int emit_node_attributes(Item_t item, int depth, bool perform_escaping);
    //virtual unsigned int emit 
    
    virtual void emit_item(Item_t item);

    virtual void emit_indentation(int depth);
  
  protected:
    serializer& ser;
    ostream& os;
    
    enum {
      INVALID_ITEM,   
      PREVIOUS_ITEM_WAS_TEXT,
      PREVIOUS_ITEM_WAS_NODE
    } previous_item;
  };
  
  class xml_emitter : public emitter
  {
  public:
    xml_emitter(serializer& the_serializer, ostream& output_stream);
    virtual void emit_declaration();    
  };

  class html_emitter : public emitter
  {
  public:
    html_emitter(serializer& the_serializer, ostream& output_stream);
    virtual void emit_declaration();
    virtual void emit_declaration_end();   
    virtual void emit_node(Item_t item, int depth, Item_t element_parent = NULL); 
  };
  
};

} // namespace xqp

#endif // #ifdef XQP_SERIALIZER_H
