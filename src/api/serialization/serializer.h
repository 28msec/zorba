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
  /**
   * Serializes the given sequence of items to the output stream.
   *
   * @param result The query result to be serialized.
   * @param os The stream to serialize to.
   */
  void serialize(XQueryResult *result, std::ostream& os);
  
  /**
   * Serializes the given item to the output stream.
   *
   * @param result The item to be serialized.
   * @param os The stream to serialize to.
   */
  void serialize(Item* item, std::ostream& os);

  /**
   * Set the serializer's parameters. The list of handled parameters
   * is to be detailed.
   *
   * @param parameter_name The name of the parameter to be set.
   * @param value The value of the parameter.
   */
  void set_parameter(xqp_string parameter_name, xqp_string value);


protected:
  // Serialization parameters
  short int byte_order_mark;         // "yes" or "no", implemented
  short int cdata_section_elements;  // TODO: list of expanded QNames
  xqp_string doctype_public;         // TODO:
  xqp_string doctype_system;         // TODO:
  int encoding;                      // UTF-8 and UTF-16 supported, add others?
  short int escape_uri_attributes;   // TODO: yes/no requires unicode normalization
  short int include_content_type;    // yes/no, implemented
  xqp_string media_type;             // string, implemented
  short int method;                  // an expanded QName: "xml", "html" are handled
  xqp_string normalization_form;     // TODO:   requires unicode normalization
  short int omit_xml_declaration;    // "yes" or "no", implemented
  short int standalone;              // implemented, TODO: add some validity checks
  short int undeclare_prefixes;      // TODO: yes/no, not clear
  void* use_character_maps;          // TODO: list of pairs
  xqp_string version;                // "1.0"
  short int indent;                  // "yes" or "no", implemented
	
protected:
  void reset();
  void validate_parameters();
  static int get_utf8_length(char ch);
  void setup(std::ostream& os);
  
protected:
  class emitter;
  class transcoder;
  
  rchandle<emitter> e;
  rchandle<transcoder> tr;
  static const xqp_string	END_OF_LINE;

  typedef enum {
    PARAMETER_VALUE_NO,
    PARAMETER_VALUE_YES,
    PARAMETER_VALUE_OMIT,
		
    PARAMETER_VALUE_XML,
	PARAMETER_VALUE_HTML,
  
    PARAMETER_VALUE_UTF_8,
    PARAMETER_VALUE_UTF_16
        
  } PARAMETER_VALUE_TYPE;

  
  class transcoder : public rcobject
  {
  public:
    transcoder(std::ostream& output_stream);
    virtual ~transcoder() { } ;

    /**
     * Output a byte to the stream without transcoding it.
     *
     * @param ch the byte to be output
     */
    void verbatim(const char ch);
    
    virtual transcoder& operator<<(const xqpString& s);
    virtual transcoder& operator<<(const char ch);
    
  protected:
    std::ostream& os;
  };
  
  class utf8_to_utf16_transcoder : public transcoder
  {
    public:
      utf8_to_utf16_transcoder(std::ostream& output_stream);
      virtual ~utf8_to_utf16_transcoder();
      
      virtual utf8_to_utf16_transcoder& operator<<(const xqpString& s);
      virtual utf8_to_utf16_transcoder& operator<<(const char ch);
      
    protected:
      UConverter *conv;
      char buffer[10];
      int chars_in_buffer;
      int chars_expected;
  };
  
  
  class emitter : public rcobject
  {
  public:
    /**
     * Creates a new emitter object.
     *
     * @param the_serializer The parent serializer object.
     * @param output_stream Target output stream.
     */
    emitter(serializer& the_serializer, transcoder& the_transcoder);

    /**
     * Outputs the start of the serialized document, which, depending on the serialization
     * method, can be the XML declaration, the HTML declaration, etc.
     */
    virtual void emit_declaration();
    
    /**
     * Outputs the end of the serialized document.
     */
    virtual void emit_declaration_end();
    
    /**
     *  The root function that performs the serialization
     *  of a normalized sequence.
     */
    virtual void emit_node(Item* item, int depth, Item* element_parent = NULL);
    
    /**
     *  Serializes the given string, performing character expansion
     *  if necessary.
     */   
    virtual void emit_expanded_string(xqp_string, bool emit_attribute_value);
    
    /**
     *  Serializes the children of the given node, without
     *  the node itself.
     * 
     *  @return  returns 1 if the functions has closed parent's tag with ">"
     */ 
    virtual int emit_node_children(Item* item, int depth, bool perform_escaping);
        
    /**
     * Serializes the given item, depending on its type, and its children.
     *
     * @param item the item to serialize
     */
    virtual void emit_item(Item* item);

    /**
     * Outputs indentation whitespace, depending of depth. 
     *
     * @param depth the level of indentation
     */
    virtual void emit_indentation(int depth);
    
    virtual ~emitter() { };
  
  protected:
    serializer& ser;
    transcoder& tr;
    
    enum {
      INVALID_ITEM,   
      PREVIOUS_ITEM_WAS_TEXT,
      PREVIOUS_ITEM_WAS_NODE
    } previous_item;
  };
  
  class xml_emitter : public emitter
  {
  public:
    xml_emitter(serializer& the_serializer, transcoder& the_transcoder);
    virtual void emit_declaration();    
  };

  class html_emitter : public emitter
  {
  public:
    html_emitter(serializer& the_serializer, transcoder& the_transcoder);
    virtual void emit_declaration();
    virtual void emit_declaration_end();   
    virtual void emit_node(Item* item, int depth, Item* element_parent = NULL);
  };  
};

} // namespace xqp

#endif // #ifdef XQP_SERIALIZER_H
