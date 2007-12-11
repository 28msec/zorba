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
#include "util/Assert.h"
#include "store/naive/basic_item_factory.h"
#include "zorba_api.h"
#include "string.h"

namespace xqp {

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Default transcoder (transparent)

serializer::transcoder::transcoder(ostream& output_stream)
  : os(output_stream)
{
}

serializer::transcoder& serializer::transcoder::operator<<(const xqpString& s)
{
  os << s;
  return *this;
}
 
serializer::transcoder& serializer::transcoder::operator<<(const char ch)
{
  os << ch;
  return *this;
}

void serializer::transcoder::verbatim(const char ch)
{
  os << ch;
}
  
///////////////////////////////////////////////////////////////////////////////////////////////////////
// UTF-8 to UTF-16 transcoder

serializer::utf8_to_utf16_transcoder::utf8_to_utf16_transcoder(ostream& output_stream)
  : transcoder(output_stream)
{
  UErrorCode status = U_ZERO_ERROR;
  conv = ucnv_open("utf-8", &status);
  Assert(U_SUCCESS(status));
  chars_in_buffer = 0;
  chars_expected = 1;
}

serializer::utf8_to_utf16_transcoder::~utf8_to_utf16_transcoder()
{
  ucnv_close(conv);
}

serializer::utf8_to_utf16_transcoder& serializer::utf8_to_utf16_transcoder::operator<<(const xqpString& s)
{
  UChar temp;
  UErrorCode status = U_ZERO_ERROR;
  int target_size = ucnv_toUChars(conv, &temp, 1, s.c_str(), s.bytes(), &status);

  status = U_ZERO_ERROR;
  UChar* target = new UChar[target_size+1];
  char* target2 = (char*)target;
  target_size = ucnv_toUChars(conv, target, target_size, s.c_str(), s.bytes(), &status);

  if (U_FAILURE(status))
  {
    ZORBA_ERROR_ALERT(
                      error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
                      error_messages::SYSTEM_ERROR,
                      NULL
                     );
  }
  
  
  for (unsigned int i=0; i<target_size*sizeof(UChar); i++)
    os << target2[i];

  return *this;
}
 
serializer::utf8_to_utf16_transcoder& serializer::utf8_to_utf16_transcoder::operator<<(const char ch)
{
  int done = 0;
  buffer[chars_in_buffer++] = ch;

  if (chars_expected == 1)
  {
    if (serializer::get_utf8_length(ch) > 1)
      chars_expected = serializer::get_utf8_length(ch);
    else
      done = 1;

  }
  else if (chars_expected == chars_in_buffer)
    done = 1;

  if (done)
  {
    UErrorCode status = U_ZERO_ERROR;
    UChar target[20];
    char* target2 = (char*)target;
    
    int target_size = ucnv_toUChars(conv, target, 20, buffer, chars_in_buffer, &status);
    
    if (U_FAILURE(status))
    {
      ZORBA_ERROR_ALERT(
                        error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
                        error_messages::SYSTEM_ERROR,
                        NULL
                       );
    }
  
    for (unsigned int i=0; i<target_size*sizeof(UChar); i++)
      os << target2[i];

    chars_in_buffer = 0;
    chars_expected = 1;
  }
  
  return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Default emitter

serializer::emitter::emitter(serializer& the_serializer, transcoder& the_transcoder)
  : ser(the_serializer), tr(the_transcoder), previous_item(INVALID_ITEM)
{  
}

void serializer::emitter::emit_declaration()
{
  if (ser.byte_order_mark == PARAMETER_VALUE_YES )
  {
    if (ser.encoding == PARAMETER_VALUE_UTF_8 )
    {
      tr << (char)0xEF << (char)0xBB << (char)0xBF;
    }
    else if (ser.encoding == PARAMETER_VALUE_UTF_16)
    {
      // Little-endian
      tr.verbatim(0xFF);
      tr.verbatim(0xFE);
    }
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
    // the input string is UTF-8
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
      tr << *chars;
      continue;
    }
    
		switch (*chars)
		{
		case '<':
      /*
        The HTML output method MUST NOT escape "<" characters occurring in attribute values.
      */
      if (ser.method == PARAMETER_VALUE_HTML && emit_attribute_value)
        tr << *chars;
      else
        tr << "&lt;";             
			break;
      
		case '>':
			tr << "&gt;";
			break;
			
		case '"':
			tr << "&quot;";
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
          tr << *chars;
        else
          tr << "&amp;";
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
			   tr << *chars;
			 else
				  tr << "&amp;";
      }
      
      break;      
			
		default:
			tr << *chars;
			break;
		}
	}	
}

void serializer::emitter::emit_indentation(int depth)
{
	for (int i=0; i<depth; i++)
		tr << "  ";
}

int serializer::emitter::emit_node_children(Item* item, int depth, bool perform_escaping = true)
{
  Iterator_t it;
  Item_t child;	
  int closed_parent_tag = 0;

  // emit namespace declarations
  it = item->getChildren();
  child = it->next();
  while (child != NULL )
  {
    if (child->getNodeKind() == StoreConsts::attributeNode)
      emit_node(&*child, depth);
			
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
			emit_node(child, tr, depth);
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
    emit_node(&*child, depth);
    child = it->next();
	}
	
	// output all the other nodes
	it = item->getChildren();
	child = it->next();
	while (child!= NULL)
	{
    if (child->getNodeKind() != StoreConsts::attributeNode)
    {
      if (closed_parent_tag == 0)
		  {
        tr << ">";
        closed_parent_tag = 1;
      }
      emit_node(&*child, depth, item);
    }
    child = it->next();
  }

  return closed_parent_tag;
}

void serializer::emitter::emit_node(Item* item, int depth, Item* element_parent /* = NULL */)
{
	if( item->getNodeKind() == StoreConsts::documentNode )
	{		
		emit_node_children(item, depth+1);    
	}
	else if (item->getNodeKind() == StoreConsts::elementNode)
	{
    if (ser.indent)
			emit_indentation(depth);
		tr << "<" << item->getNodeName()->getStringProperty();
    previous_item = PREVIOUS_ITEM_WAS_NODE;

		int closed_parent_tag = emit_node_children(item, depth);

		if (closed_parent_tag)		
			tr << "</" << item->getNodeName()->getStringProperty() << ">";
		else
			tr << "/>";

    if (ser.indent)
			tr << ser.END_OF_LINE;
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else if (item->getNodeKind() == StoreConsts::attributeNode )
	{
		tr << " " << item->getNodeName()->getStringProperty() << "=\"";
		emit_expanded_string(item->getStringValue(), true);
		tr << "\"";
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
  /*
	else if (item->getNodeKind() == namespaceNode)
	{
		tr << " " << item->getNodeName()->getStringProperty() << "=\"";
		emit_expanded_string(item->getStringValue());
		tr << "\"";
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
  */
	else if (item->getNodeKind() == StoreConsts::textNode)
	{		
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
      tr << " ";    
		emit_expanded_string(item->getStringProperty());
    previous_item = PREVIOUS_ITEM_WAS_TEXT;
	}
	else if (item->getNodeKind() == StoreConsts::commentNode)
	{
    if (ser.indent)
      emit_indentation(depth);
    tr << "<!--" << item->getStringProperty() << "-->";
    if (ser.indent)
      tr << ser.END_OF_LINE;		
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
		tr << "node of type: " << item->getNodeKind();		
	}
}

void serializer::emitter::emit_item(Item* item)
{
  if (item->isAtomic())
  {
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT )
      tr << " ";
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
serializer::xml_emitter::xml_emitter(serializer& the_serializer, transcoder& the_transcoder)
  : emitter(the_serializer, the_transcoder)
{   
}

void serializer::xml_emitter::emit_declaration()
{
  emitter::emit_declaration();

  if (ser.omit_xml_declaration == PARAMETER_VALUE_NO )
  {
    tr << "<?xml version=\"" << ser.version << "\" encoding=\"";
    if (ser.encoding == PARAMETER_VALUE_UTF_8)
      tr << "UTF-8";
    else if (ser.encoding == PARAMETER_VALUE_UTF_16)
      tr << "UTF-16";
    tr << "\"";
      
    if ( ser.standalone != PARAMETER_VALUE_OMIT )
    {
      tr << "standalone=\"";

      if ( ser.standalone == PARAMETER_VALUE_YES )
        tr << "yes";
      else
        tr << "no";

      tr << "\"";
    }
    tr << "?>";

    tr << END_OF_LINE; // Always output a newline
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// HTML emitter

serializer::html_emitter::html_emitter(serializer& the_serializer, transcoder& the_transcoder)
  : emitter(the_serializer, the_transcoder)
{   
}

void serializer::html_emitter::emit_declaration()
{
  emitter::emit_declaration();
     
  tr << "<html>";
  if (ser.indent)
    tr << END_OF_LINE;
}

void serializer::html_emitter::emit_declaration_end()
{
  tr << "</html>";  
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

void serializer::html_emitter::emit_node(Item* item, int depth, Item* element_parent)
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
    tr << "<" << item->getNodeName()->getStringProperty();
    
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
      tr << "/>";
      if (ser.indent)
        tr << ser.END_OF_LINE;
      if (ser.indent)
        emit_indentation(depth+1);

      tr << "<meta http-equiv=\"content-type\" content=\"" << ser.media_type << "; charset=";
      if (ser.encoding == PARAMETER_VALUE_UTF_8)
        tr << "UTF-8";
      else if (ser.encoding == PARAMETER_VALUE_UTF_16)
        tr << "UTF-16";
      tr << "\">";
      
      if (ser.indent)
        tr << ser.END_OF_LINE;
      closed_parent_tag = 1;
    }

    closed_parent_tag |= emit_node_children(item, depth);
        
    if (closed_parent_tag)   
      tr << "</" << item->getNodeName()->getStringProperty() << ">";
    else
    {
      /* 
        The HTML output method MUST NOT output an end-tag for empty elements. For HTML 4.0, the 
        empty elements are area, base, basefont, br, col, frame, hr, img, input, isindex, link, 
        meta and param. For example, an element written as <br/> or <br></br> in an XSLT stylesheet 
        MUST be output as <br>.
      */
      if (is_html_empty_element(item) && ser.version == "4.0")
        tr << ">";      
      else
        tr << "/>";
    }
    
    if (ser.indent)
      tr << serializer::END_OF_LINE;
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
        tr << " ";    
      tr << item->getStringProperty();  // no character expansion
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
  encoding = PARAMETER_VALUE_UTF_8;
}

serializer::serializer()
{
  reset();
}

serializer::~serializer()
{
}

int serializer::get_utf8_length(char ch)
{
  unsigned char lead = (unsigned char)ch;
  
  if (lead < 0x80)
    return 1;
  else if ((lead >> 5) == 0x6)
    return 2;
  else if ((lead >> 4) == 0xe)
    return 3;
  else if ((lead >> 3) == 0x1e)
    return 4;
  else
    return 0;
}

void serializer::set_parameter(xqp_string parameter_name, xqp_string value)
{
  // TODO: add handled parameters translation
  if (parameter_name == "indent")
  {
    if (value == "yes")
      indent = PARAMETER_VALUE_YES;
    else if (value == "no")
      indent = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_ALERT(
                        error_messages::SEPM0016_Invalid_parameter_value,
                        error_messages::SYSTEM_ERROR,
                        NULL);
    }
  }
  else if (parameter_name == "standalone")
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
  else if (parameter_name == "encoding")
  {
    if (value == "UTF-8")
      encoding = PARAMETER_VALUE_UTF_8;
    else if (value == "UTF-16")
      encoding = PARAMETER_VALUE_UTF_16;
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
  else
  {
    ZORBA_ERROR_ALERT(
                      error_messages::SEPM0016_Invalid_parameter_value,
                      error_messages::SYSTEM_ERROR,
                      NULL);
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

void serializer::setup(ostream& os)
{
  if (encoding == PARAMETER_VALUE_UTF_8)
    tr = new transcoder(os); // the strings are UTF_8, so we use the ``transparent'' transcoder
  else if (encoding == PARAMETER_VALUE_UTF_16)
    tr = new utf8_to_utf16_transcoder(os);
  else
  {
    ZORBA_ERROR_ALERT(
                      error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
                      error_messages::SYSTEM_ERROR,
                      NULL);
    return;
  }
    
  if (method == PARAMETER_VALUE_XML)
    e = new xml_emitter(*this, *tr);
  else if (method == PARAMETER_VALUE_HTML)
    e = new html_emitter(*this, *tr);
  else
  {
    ZORBA_ERROR_ALERT(
                      error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
                      error_messages::SYSTEM_ERROR,
                      NULL);
    return;
  }
}

void serializer::serialize(XQueryExecution *result, ostream& os)
{
  validate_parameters();
  setup(os);
  
  e->emit_declaration();

  Item_t item = result->next();
  while (item != NULL )
  {
    e->emit_item(&*item);
    item = result->next();
  }
  
  e->emit_declaration_end();
}

void serializer::serialize(Item* item, ostream& os)
{
  validate_parameters();
  setup(os);
  
  e->emit_declaration();
  e->emit_item(item);
  e->emit_declaration_end();
}

} // namespace xqp
