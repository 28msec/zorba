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
 * @author Nicolae Brinza (nbrinza@ipdevel.ro)
 * @file serialization/serializer.cpp
 *
 */

#include "api/serialization/serializer.h"
#include "util/zorba.h"
#include "store/naive/basic_item_factory.h"
#include "zorba_api.h"

#include "string.h"

namespace xqp {

  
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Default emitter

serializer::emitter::emitter(serializer& the_serializer, ostream& output_stream)
  : ser(the_serializer), os(output_stream), previous_item(INVALID_ITEM)
{  
}

void serializer::emitter::emit_declaration()
{
  if (ser.byte_order_mark == PARAMETER_VALUE_YES )
  {
    // TODO: output BOM depending on given encoding
    xqpString temp;
    temp = ( uint32_t ) 0xFEFF;
    os << temp;
  }
}

void serializer::emitter::emit_declaration_end()
{
}

// emit_attribute_value is set to true if the string expansion is performed on a value of an attribute
void serializer::emitter::emit_expanded_string(xqp_string str, bool emit_attribute_value = false)
{
	const char* chars = str.c_str();
	int is_quote;
  int skip = 0;
	
	for (unsigned int i=0; i<str.bytes(); i++, chars++ )
	{       
    // TODO: this is for UTF-8 !
    if ((unsigned char)*chars < 0x80)
      skip = 0;      
    else if ((*chars >> 5) == 0x6)
      skip = 2;
    else if ((*chars >> 4) == 0xe)
      skip = 3;
    else if ((*chars >> 3) == 0x1e)
      skip = 4;
       
    if (skip)
    {
      skip--;
      os << *chars;
      continue;
    }
    
		switch (*chars)
		{
		case '<':
      /*
        The HTML output method MUST NOT escape "<" characters occurring in attribute values.
      */
      if (ser.method == PARAMETER_VALUE_HTML && emit_attribute_value)
        os << *chars;
      else
        os << "&lt;";             
			break;
      
		case '>':
			os << "&gt;";
			break;
			
		case '"':
			os << "&quot;";
			break;
			
		case '&':
      /*
        The HTML output method MUST NOT escape a & character occurring in an attribute value 
        immediately followed by a { character (see Section B.7.1 of the HTML Recommendation [HTML]).
      */      
      if (ser.method == PARAMETER_VALUE_HTML && emit_attribute_value)
      {
        if (str.bytes()-i >= 1
            &&
            (*(chars+1) == '{'))
          os << *chars;
        else
          os << "&amp;";
      }
      else
      {      
        is_quote = 0;
        for (unsigned int j=1; j<str.bytes()-i; j++)
        {
				  if ( ! ((*(chars+j) >= 'a' && *(chars+j) <= 'z') 
            ||
            (*(chars+j) >= 'A' && *(chars+j) <= 'Z')
            ||
            (*(chars+j) >= '0' && *(chars+j) <= '9')
            ||
            (*(chars+j) == '#')))
				  {
            break;				
				  }
				
				  if (*(chars+j) == ';' 
            &&
            (j>1))
		  		{
            is_quote = 1;
            break;				
				  }
			 }
			
			 if (is_quote)
			   os << *chars;
			 else
				  os << "&amp;";
      }
      
      break;      
			
		default:
			os << *chars;
			break;
		}
	}	
}

void serializer::emitter::emit_indentation(int depth)
{
	for (int i=0; i<depth; i++)
		os << "  ";
}

int serializer::emitter::emit_node_children(Item_t item, int depth, bool perform_escaping = true)
{
	Iterator_t it;
	Item_t child;	
	int closed_parent_tag = 0;

	// emit namespace declarations
	it = item->getChildren();
	child = it->next();
	while (child != NULL )
	{
		//if (child->getNodeKind() == Item::namespaceNode )		
		//	emit_node(child, depth);
		
		child = it->next();
	}
	
	/* TODO: uncomment when this will be implemented in the Item store 
	it = item->getNamespaceNodes();
	child = it->next();
	while (child != NULL )
	{
		if (child->getNodeKind() == namespaceNode )
		{
			emit_node(child, os, depth);
			children_count++;			
		}		
		
		child = it->next();
	}
  */
		
	// emit attributes 
	it = item->getAttributes();
	child = it->next();
	while (child!= NULL)
	{		
    emit_node(child, depth);		
    child = it->next();
	}
	
	// output all the other nodes
	it = item->getChildren();
	child = it->next();
	while (child!= NULL)
	{
    if (closed_parent_tag == 0)
		{
      os << ">";
      closed_parent_tag = 1;
    }

    emit_node(child, depth, item);			

    child = it->next();
	}

	return closed_parent_tag;
}

void serializer::emitter::emit_node(Item_t item, int depth, Item_t element_parent /* = NULL */)
{
	if( item->getNodeKind() == StoreConsts::documentNode )
	{		
		emit_node_children(item, depth+1);    
	}
	else if (item->getNodeKind() == StoreConsts::elementNode)
	{
    if (ser.indent)
			emit_indentation(depth);
		os << "<" << item->getNodeName()->getStringProperty();

		int closed_parent_tag = emit_node_children(item, depth);

		if (closed_parent_tag)		
			os << "</" << item->getNodeName()->getStringProperty() << ">";
		else
			os << "/>";

    if (ser.indent)
			os << ser.END_OF_LINE;
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else if (item->getNodeKind() == StoreConsts::attributeNode )
	{
		os << " " << item->getNodeName()->getStringProperty() << "=\"";
		emit_expanded_string(item->getStringValue(), true);
		os << "\"";
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
  /*
	else if (item->getNodeKind() == namespaceNode)
	{
		os << " " << item->getNodeName()->getStringProperty() << "=\"";
		emit_expanded_string(item->getStringValue());
		os << "\"";
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
  */
	else if (item->getNodeKind() == StoreConsts::textNode)
	{		
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
      os << " ";    
		emit_expanded_string(item->getStringProperty());
    previous_item = PREVIOUS_ITEM_WAS_TEXT;
	}
	else if (item->getNodeKind() == StoreConsts::commentNode)
	{
    if (ser.indent)
      emit_indentation(depth);
    
    os << "<--" << item->getStringProperty() << "-->";
    
    if (ser.indent)
      os << ser.END_OF_LINE;		
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
  /*
	else if (item->getNodeKind() == piNode )
	{
    state = PREVIOUS_ITEM_WAS_NODE;
	}
	*/
	else 
	{
		os << "node of type: " << item->getNodeKind();		
	}
}

void serializer::emitter::emit_item(Item_t item)
{
  if (item->isAtomic())
  {
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT )
      os << " ";
    emit_expanded_string(item->getStringProperty());
    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else
  {
    if (item->getNodeKind() == StoreConsts::attributeNode)
      //||
      //  item->getNodeKind() == namespaceNode)
    {
      ZORBA_ERROR_ALERT(
                        error_messages::SENR0001_Item_is_attribute_or_namespace_node,
                        error_messages::SYSTEM_ERROR,
                        NULL);
    }
    else        
      emit_node(item, 0);
  }  
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// XML emitter
serializer::xml_emitter::xml_emitter(serializer& the_serializer, ostream& output_stream)
  : emitter(the_serializer, output_stream)
{   
}

void serializer::xml_emitter::emit_declaration()
{
  emitter::emit_declaration();

  if (ser.omit_xml_declaration == PARAMETER_VALUE_NO )
  {
    os << "<?xml version=\"" << ser.version << "\" encoding=\"" << ser.encoding << "\"";
    if ( ser.standalone != PARAMETER_VALUE_OMIT )
    {
      os << "standalone=\"";

      if ( ser.standalone == PARAMETER_VALUE_YES )
        os << "yes";
      else
        os << "no";

      os << "\"";
    }
    os << "?>";

    if ( ser.indent )
      os << END_OF_LINE;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// HTML emitter

serializer::html_emitter::html_emitter(serializer& the_serializer, ostream& output_stream)
  : emitter(the_serializer, output_stream)
{   
}

void serializer::html_emitter::emit_declaration()
{
  emitter::emit_declaration();
     
  os << "<html>";
  if (ser.indent)
    os << END_OF_LINE;
}

void serializer::html_emitter::emit_declaration_end()
{
  os << "</html>";  
}

// returns true if there is a META element, as a child of a HEAD element,
// with an attribute "http-equiv" with value "content-type"
int is_content_type_meta(Item_t item, Item_t element_parent)
{
  Item_t child;
  
  if (element_parent == NULL)
    return 0;
  
  // TODO: should find a function to compare strings ignore case
  if ((element_parent->getNodeName()->getStringProperty() == "HEAD"
      ||
      element_parent->getNodeName()->getStringProperty() == "head")
      &&
      (item->getNodeName()->getStringProperty() == "META"
      ||
      item->getNodeName()->getStringProperty() == "meta"))
  {    
    // iterate through attributes
    Iterator_t it = item->getAttributes();
    Item_t child = it->next();
    while (child!= NULL)
    { 
      if (child->getNodeName()->getStringProperty() == "http-equiv"
          &&
          child->getStringValue() == "content-type")
        return 1;        
      
      child = it->next();
    }    
  }
  
  return 0;
}

int is_html_empty_element(Item_t item)
{
  // TODO: case should be ignored
  if (item->getNodeName()->getStringProperty() == "area"
      ||
      item->getNodeName()->getStringProperty() == "base"
      ||
      item->getNodeName()->getStringProperty() == "basefont"
      ||
      item->getNodeName()->getStringProperty() == "br"
      ||
      item->getNodeName()->getStringProperty() == "col"
      ||
      item->getNodeName()->getStringProperty() == "frame"
      ||
      item->getNodeName()->getStringProperty() == "hr"
      ||
      item->getNodeName()->getStringProperty() == "img"
      ||
      item->getNodeName()->getStringProperty() == "input"
      ||
      item->getNodeName()->getStringProperty() == "isindex"
      ||
      item->getNodeName()->getStringProperty() == "link"
      ||
      item->getNodeName()->getStringProperty() == "meta"
      ||
      item->getNodeName()->getStringProperty() == "param")
    return 1;
  else
    return 0;
}

void serializer::html_emitter::emit_node(Item_t item, int depth, Item_t element_parent)
{
  if (item->getNodeKind() == StoreConsts::elementNode)
  {
    unsigned closed_parent_tag = 0;
    
    /*
      If a meta element has been added to the head element as described above, then any existing 
      meta element child of the head element having an http-equiv attribute with the value "Content-Type" 
      MUST be discarded.
    */
    if (ser.include_content_type == PARAMETER_VALUE_YES 
        &&
        element_parent != NULL
        &&
        is_content_type_meta(item, element_parent))
    {
      // do not emit this element
      return;      
    }        
    
    if (ser.indent)
      emit_indentation(depth);
    os << "<" << item->getNodeName()->getStringProperty();
    
    /*
      If there is a head element, and the include-content-type parameter has the value yes, the 
      HTML output method MUST add a meta element as the first child element of the head element 
      specifying the character encoding actually used.
    */
    // TODO: ignore case
    if (ser.include_content_type == PARAMETER_VALUE_YES
        &&
        (item->getNodeName()->getStringProperty() == "HEAD"
         ||
         item->getNodeName()->getStringProperty() == "head"))
    {
      os << "/>";
      if (ser.indent)
        os << ser.END_OF_LINE;
      if (ser.indent)
        emit_indentation(depth+1);
      os << "<meta http-equiv=\"content-type\" content=\"" << ser.media_type << "; charset=" << ser.encoding << "\">";
      if (ser.indent)
        os << ser.END_OF_LINE;
      closed_parent_tag = 1;
    }

    closed_parent_tag |= emit_node_children(item, depth);
        
    if (closed_parent_tag)   
      os << "</" << item->getNodeName()->getStringProperty() << ">";
    else
    {
      /* 
        The HTML output method MUST NOT output an end-tag for empty elements. For HTML 4.0, the 
        empty elements are area, base, basefont, br, col, frame, hr, img, input, isindex, link, 
        meta and param. For example, an element written as <br/> or <br></br> in an XSLT stylesheet 
        MUST be output as <br>.
      */
      if (is_html_empty_element(item) && ser.version == "4.0")
        os << ">";      
      else
        os << "/>";
    }
    
    if (ser.indent)
      os << serializer::END_OF_LINE;
    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == StoreConsts::textNode)
  {
    /*
      The HTML output method MUST NOT perform escaping for the content of the script and style elements.
    */
    // TODO: ignore case
    if (item->getNodeName()->getStringProperty() == "script"
       ||
        item->getNodeName()->getStringProperty() == "style")
    {
      if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
        os << " ";    
      os << item->getStringProperty();  // no character expansion
      previous_item = PREVIOUS_ITEM_WAS_TEXT;
    }
    else
      emitter::emit_node(item, depth);
  }
  else
    emitter::emit_node(item, depth);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Serializer

const xqp_string serializer::END_OF_LINE = "\n";

void serializer::reset()
{ 
  version = "1.0";  
  indent = PARAMETER_VALUE_NO;
  standalone = PARAMETER_VALUE_OMIT;
  omit_xml_declaration = PARAMETER_VALUE_NO;
  byte_order_mark = PARAMETER_VALUE_NO;
  undeclare_prefixes = PARAMETER_VALUE_NO;
  method = PARAMETER_VALUE_XML;
  include_content_type = PARAMETER_VALUE_NO;
  media_type = "";  
  encoding = "UTF-8";  
}

serializer::serializer()
{  
  reset();  
}

serializer::~serializer()
{
}

void serializer::set_parameter(xqp_string parameter_name, xqp_string value)
{
  // TODO: add handled parameters translation
  if (parameter_name == "standalone")
  {
    if (value == "yes")
      standalone = PARAMETER_VALUE_YES;
    else if (value == "no")
      standalone = PARAMETER_VALUE_NO;
    else if (value == "omit")
      standalone = PARAMETER_VALUE_OMIT;
    else
    {
      ZORBA_ERROR_ALERT(
                        error_messages::SEPM0016_Invalid_parameter_value,
                        error_messages::SYSTEM_ERROR,
                        NULL);
    }
  }
  else if (parameter_name == "omit-xml-declaration")
  {
    if (value == "yes")
      omit_xml_declaration = PARAMETER_VALUE_YES;
    else if (value == "no")
      omit_xml_declaration = PARAMETER_VALUE_NO;    
    else
    {
      ZORBA_ERROR_ALERT(
                        error_messages::SEPM0016_Invalid_parameter_value,
                        error_messages::SYSTEM_ERROR,
                        NULL);
    }
  }
  else if (parameter_name == "byte-order-mark")
  {
    if (value == "yes")
      byte_order_mark = PARAMETER_VALUE_YES;
    else if (value == "no")
      byte_order_mark = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_ALERT(
                        error_messages::SEPM0016_Invalid_parameter_value,
                        error_messages::SYSTEM_ERROR,
                        NULL);
    }
  }
  else if (parameter_name == "undeclare-prefixes")
  {
    if (value == "yes")
      undeclare_prefixes = PARAMETER_VALUE_YES;
    else if (value == "no")
      undeclare_prefixes = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_ALERT(
                        error_messages::SEPM0016_Invalid_parameter_value,
                        error_messages::SYSTEM_ERROR,
                        NULL);
    }
  }
  else if (parameter_name == "method")
  {
    if (value == "xml")
      method = PARAMETER_VALUE_XML;
    else if (value == "html")
      method = PARAMETER_VALUE_HTML;
    else
    {
      ZORBA_ERROR_ALERT(
                        error_messages::SEPM0016_Invalid_parameter_value,
                        error_messages::SYSTEM_ERROR,
                        NULL);
    }
  }
  else if (parameter_name == "include-content-type")
  {
    if (value == "yes")
      include_content_type = PARAMETER_VALUE_YES;
    else if (value == "no")
      include_content_type = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_ALERT(
                        error_messages::SEPM0016_Invalid_parameter_value,
                        error_messages::SYSTEM_ERROR,
                        NULL);
    }
  }
  else if (parameter_name == "media-type")
  {
    media_type = value;    
  }
}

void serializer::validate_parameters(void)
{
  if (omit_xml_declaration == PARAMETER_VALUE_YES)
  {   
    if (standalone != PARAMETER_VALUE_OMIT
      /*||
        (version != "1.0" && doctype_system is specified*/ )
    {
      // throw SEPM0009
    }
  }
}

void serializer::serialize(XQueryResult *result, ostream& os)
{
  emitter* e;
	validate_parameters();  
    
  if (method == PARAMETER_VALUE_XML)
    e = new xml_emitter(*this, os);
  else if (method == PARAMETER_VALUE_HTML)
    e = new html_emitter(*this, os);
  else
  {
    ZORBA_ERROR_ALERT(
                      error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
                      error_messages::SYSTEM_ERROR,
                      NULL);
  }
  
  e->emit_declaration();

	Item_t item = result->next();
	while (item != NULL )
	{
    e->emit_item(item);
		item = result->next();
	}
  
  e->emit_declaration_end();
  delete e;
}

} // namespace xqp
