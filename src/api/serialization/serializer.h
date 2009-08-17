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
#ifndef ZORBA_SERIALIZER_H
#define ZORBA_SERIALIZER_H

#include <vector>

#include <zorba/sax2.h>

#include "zorbatypes/representations.h"
#include "zorbatypes/transcoder.h"
#include "common/shared_types.h"

namespace zorba
{

namespace store
{
  class ChildrenIterator;
  class AttributesIterator;
}


typedef std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> > NsBindings;

class serializer : public SimpleRCObject
{
protected:
  class emitter;

public:
  static int get_utf8_length(char ch);

public:
	serializer(error::ErrorManager*);

	virtual ~serializer();

  /**
   * Serializes the given sequence of items to the output stream.
   *
   * @param result The query result to be serialized.
   * @param os The stream to serialize to.
   */
  void serialize(PlanWrapper *result, std::ostream& os);
  
  /**
   * Parse the given sequence with SAX2 interface
   *
   */
   void serializeSAX2( 
        PlanWrapper *result,
        std::ostream & os,
        SAX2_ContentHandler * aSAX2ContentHandler );  

  /**
   * Serializes the given item to the output stream.
   *
   * @param result The item to be serialized.
   * @param os The stream to serialize to.
   */
  void serialize(const store::Item* item, std::ostream& os);

  /**
   * Set the serializer's parameters. The list of handled parameters
   * is to be detailed.
   *
   * @param parameter_name The name of the parameter to be set.
   * @param value The value of the parameter.
   */
  void set_parameter(const char* parameter_name, const char* value);

protected:

  typedef enum 
  {
    PARAMETER_VALUE_NO,
    PARAMETER_VALUE_YES,
    PARAMETER_VALUE_OMIT,
		
    PARAMETER_VALUE_XML,
    PARAMETER_VALUE_HTML,
    PARAMETER_VALUE_XHTML,
    PARAMETER_VALUE_TEXT,
    PARAMETER_VALUE_JSON,
    PARAMETER_VALUE_JSONML,
  
    PARAMETER_VALUE_UTF_8
#ifndef ZORBA_NO_UNICODE
    ,PARAMETER_VALUE_UTF_16
#endif

  } PARAMETER_VALUE_TYPE;


  error::ErrorManager* theErrorManager;

  // Serialization parameters
  short int byte_order_mark;         // "yes" or "no", implemented
  xqpStringStore_t cdata_section_elements; // list of expanded QNames, delimited by
                                     // spaces or semicolons, implemented
  xqpStringStore_t doctype_system;   // string, implemented
  xqpStringStore_t doctype_public;   // string, implemented
  int encoding;                      // UTF-8 and UTF-16 supported, add others?
  short int escape_uri_attributes;   // TODO: yes/no requires unicode normalization
  short int include_content_type;    // yes/no, implemented
  xqpStringStore_t media_type;             // string, implemented
  short int method;                  // an expanded QName: "xml", "html", "xhtml",
                                     // "text", "json" and "jsonml"  are handled
  xqpStringStore_t normalization_form; // TODO:   requires unicode normalization
  short int omit_xml_declaration;    // "yes" or "no", implemented
  short int standalone;              // implemented, TODO: add some validity checks
  short int undeclare_prefixes;      // "yes" or "no", implemented
  void* use_character_maps;          // TODO: list of pairs
  xqpStringStore_t version;          // "1.1"
  short int indent;                  // "yes" or "no", implemented

  bool version_has_default_value;    // Used during validation to set version to
                                     // "4.0" when output method is "html"

  rchandle<emitter>    e;
  rchandle<transcoder> tr;
  
  // Used to hold the QNames of the cdata section elements after they have been tokenized
  std::vector<xqpStringStore_t> cdata_section_elements_tokens;

  static const char	END_OF_LINE;

protected:
  void reset();
  void validate_parameters();
  bool setup(std::ostream& os);
  

  ///////////////////////////////////////////////////////////
  //                                                       //
  //  class emitter                                        //
  //                                                       //
  ///////////////////////////////////////////////////////////

  class emitter : public SimpleRCObject
  {
  public:
    /**
     * Creates a new emitter object.
     *
     * @param the_serializer The parent serializer object.
     * @param output_stream Target output stream.
     */
    emitter(serializer* the_serializer, transcoder& the_transcoder);

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
     * Outputs the doctype declaration. This function is not used by the 
	   * default emitter, it is intended to be defined by the XML, HTML and XHTML 
	   * serializers.
     */
	  virtual void emit_doctype(const xqpStringStore* elementName);
    
    /**
     *  The root function that performs the serialization
     *  of a normalized sequence.
     */
    virtual void emit_node(const store::Item* item,int depth);
    
    /**
     *  Serializes the given string, performing character expansion
     *  if necessary.
     */   
    virtual void emit_expanded_string(const xqpStringStore* str, bool emit_attribute_value);
    
    /**
     *  Serializes a given text node. Also performs the processing of
     *  cdata-section-elements parameter, if set.
     */
    virtual void emit_text_node(const store::Item* item);
    
    /**
     *  Serializes the children of the given node, without the node itself.
     * 
     *  @return  returns 1 if the functions has closed parent's tag with ">"
     */ 
    virtual int emit_node_children(
        const store::Item* item,
        int depth,
        bool perform_escaping);

    /**
     *  Serializes the namespace bindings, if any.
     *
     *  @return  returns true if the function has added a set of bindings to the list,
     *           which should be removed when the elememnt is out of the scope.
     */ 
    virtual bool emit_bindings(const store::Item* item);
        
    /**
     * Serializes the given item, depending on its type, and its children.
     *
     * @param item the item to serialize
     */
    virtual void emit_item(const store::Item* item);

    /**
     * Outputs indentation whitespace, depending on depth. 
     *
     * @param depth the level of indentation
     */
    virtual void emit_indentation(int depth);
    
    virtual ~emitter();
  
  protected:
    bool haveBinding(std::pair<xqpStringStore_t, xqpStringStore_t>& nsBinding) const;
    bool havePrefix(const xqpStringStore* pre) const;

    std::string expand_string(const xqpStringStore* str, bool emit_attribute_value );

    store::ChildrenIterator* getChildIter();
    void releaseChildIter(store::ChildrenIterator* iter);

    store::AttributesIterator* getAttrIter();
    void releaseAttrIter(store::AttributesIterator* iter);

  protected:
    serializer                          * ser;
    transcoder                          & tr;
    std::vector<NsBindings>               theBindings;

    enum ItemState 
    {
      INVALID_ITEM,   
      PREVIOUS_ITEM_WAS_TEXT,      
      PREVIOUS_ITEM_WAS_NODE
    }                                     previous_item;

    std::vector<store::ChildrenIterator*> theChildIters;
    ulong                                 theFirstFreeChildIter;
    store::AttributesIterator           * theAttrIter;

    bool                                  isFirstElementNode;
  };

  
  ///////////////////////////////////////////////////////////
  //                                                       //
  //  class xml_emitter                                    //
  //                                                       //
  ///////////////////////////////////////////////////////////
  
  class xml_emitter : public emitter
  {
  public:
    xml_emitter(serializer* the_serializer, transcoder& the_transcoder);

    virtual void emit_declaration();    
    virtual void emit_doctype(const xqpStringStore* elementName);
  };


  ///////////////////////////////////////////////////////////
  //                                                       //
  //  class html_emitter                                   //
  //                                                       //
  ///////////////////////////////////////////////////////////
  
  class html_emitter : public emitter
  {
  public:
    html_emitter(serializer* the_serializer, transcoder& the_transcoder);
    
    virtual void emit_declaration();
    virtual void emit_declaration_end();
    virtual void emit_doctype(const xqpStringStore* elementName);
    virtual void emit_node(const store::Item* item, int depth);
  };

  ///////////////////////////////////////////////////////////
  //                                                       //
  //  class xhtml_emitter                                  //
  //                                                       //
  ///////////////////////////////////////////////////////////
  
  class xhtml_emitter : public xml_emitter
  {
  public:
    xhtml_emitter(serializer* the_serializer, transcoder& the_transcoder);

    virtual void emit_node(const store::Item* item, int depth);
  };

  
  ///////////////////////////////////////////////////////////
  //                                                       //
  //  class text_emitter                                   //
  //                                                       //
  ///////////////////////////////////////////////////////////
  
  class text_emitter : public emitter
  {
  public:
    text_emitter(serializer* the_serializer, transcoder& the_transcoder);
    
    virtual void emit_declaration();        
    virtual void emit_node(const store::Item* item, int depth);
    virtual int emit_node_children(const store::Item* item, int depth, bool perform_escaping = true);
    virtual void emit_item(const store::Item* item);
  };

  
  ///////////////////////////////////////////////////////////
  //                                                       //
  //  class json_emitter                                   //
  //                                                       //
  ///////////////////////////////////////////////////////////

  class json_emitter : public emitter
  {
    public:
      json_emitter(serializer* the_serializer, transcoder& the_transcoder);

      virtual void emit_declaration();
      virtual void emit_item(const store::Item* item);
  };

  ///////////////////////////////////////////////////////////
  //                                                       //
  //  class jsonml_emitter                                 //
  //                                                       //
  ///////////////////////////////////////////////////////////

  class jsonml_emitter : public emitter
  {
    public:
      jsonml_emitter(serializer* the_serializer, transcoder& the_transcoder);

      virtual void emit_declaration();
      virtual void emit_item(const store::Item* item);
  };


  ///////////////////////////////////////////////////////////
  //                                                       //
  //  class sax2_emitter                                   //
  //                                                       //
  ///////////////////////////////////////////////////////////

  class sax2_emitter : public emitter
  {
  protected:
    SAX2_ContentHandler * theSAX2ContentHandler;
    SAX2_LexicalHandler * theSAX2LexicalHandler;

    std::vector<xqpStringStore_t> theNameSpaces;

  public:
    sax2_emitter(
        serializer* the_serializer,
        transcoder& the_transcoder,
        SAX2_ContentHandler* aSAX2ContentHandler);

    void emit_startPrefixMapping( const store::Item * item, NsBindings & nsBindings );

    void emit_endPrefixMapping( NsBindings & nsBindings );

    virtual void emit_declaration();

    virtual void emit_declaration_end();

    virtual void emit_node(const store::Item* item, int depth);
   
    void emit_node(store::Item* item);

    virtual void emit_expanded_string(
        const xqpStringStore * aStrStore,
        bool aEmitAttributeValue = false );
    
    virtual int emit_node_children(
        const store::Item* item,
        int depth,
        bool perform_escaping);

    void emit_node_children(const store::Item* item);

    virtual bool emit_bindings(const store::Item* item);
        
    virtual void emit_item( const store::Item* item );
  };
};
} // namespace zorba

#endif // #ifdef ZORBA_SERIALIZER_H

/*
 * Local variables:
 * mode: c++
 * End:
 */
