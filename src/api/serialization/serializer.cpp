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

#include <zorba/result_iterator.h>
#include <zorba/iterator.h>

#include "api/serialization/serializer.h"
#include "errors/error_factory.h"
#include "system/zorba.h"
#include "util/Assert.h"

using namespace std;

namespace zorba {

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
  ZORBA_ASSERT(U_SUCCESS(status));
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
    ZORBA_ASSERT(0);
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
      ZORBA_ASSERT(0);
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
      tr.verbatim((char)0xFF); // TODO isn't the value truncated?
      tr.verbatim((char)0xFE);
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
	
	for (unsigned int i = 0; i < str.bytes(); i++, chars++ )
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
    case '\r':
      tr << "&#xD;";
      break;

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
        The HTML output method MUST NOT escape a & character occurring in an
        attribute value immediately followed by a { character (see Section
        B.7.1 of the HTML Recommendation [HTML]).
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
      /*
      {      
        is_quote = 0;
        unsigned int j;
        for (j = 1; j < str.bytes() - i; j++)
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
        }

        if (j < str.bytes() - i && *(chars+j) == ';' && j > 1)
          is_quote = 1;

        if (is_quote)
        {
          tr << std::string(chars, j+1);
          chars += j;
          i += j;
        }
        else
        {
				  tr << "&amp;";
        }
      }
      */
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

bool serializer::emitter::haveBinding(std::pair<xqpString,xqpString>& nsBinding) const
{
  for (unsigned long i = 0; i < bindings.size(); i++)
  {
    NsBindings nsBindings = bindings[i];
    
    for (unsigned long j = 0; j < nsBindings.size(); j++)
      if (nsBindings[j].first == nsBinding.first
         &&
         nsBindings[j].second == nsBinding.second)
        return true;
  }

  return false;
}

int serializer::emitter::emit_node_children(store::Item* item, int depth, bool perform_escaping = true)
{
  Iterator_t it;
  store::Item_t child;	
  int closed_parent_tag = 0;
  
  if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    // emit attributes 
    it = item->getAttributes();
    it->open();
    child = it->next();
    while (child!= NULL)
    {		
      emit_node(&*child, depth);
      child = it->next();
    }
  }
  else if (item->getNodeKind() == store::StoreConsts::documentNode)
  {
    closed_parent_tag = 1;
  }
	
	// output all the other nodes
	it = item->getChildren();
  it->open();
	child = it->next();
	while (child!= NULL)
	{
    if (child->getNodeKind() != store::StoreConsts::attributeNode)
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

bool serializer::emitter::emit_bindings(store::Item* item)
{
  // emit namespace bindings
  NsBindings nsBindings;
  item->getNamespaceBindings(nsBindings);
    
  for (unsigned long i = 0; i < nsBindings.size(); i++)
    if (!haveBinding(nsBindings[i]))
    {
      tr << " xmlns";
      if (nsBindings[i].first.size() > 0)
        tr << ":" <<  nsBindings[i].first;
      tr << "=\"" << nsBindings[i].second << "\"";
    }

  if (nsBindings.size() > 0)
  {
    bindings.push_back(nsBindings);
    return true;
  }
  else
    return false;
}

void serializer::emitter::emit_node(store::Item* item, int depth, store::Item* element_parent /* = NULL */)
{
	if( item->getNodeKind() == store::StoreConsts::documentNode )
	{		
		emit_node_children(item, depth+1);    
	}
	else if (item->getNodeKind() == store::StoreConsts::elementNode)
	{
    if (ser.indent)
			emit_indentation(depth);
		tr << "<" << item->getNodeName()->getStringValue();
    previous_item = PREVIOUS_ITEM_WAS_NODE;

    bool should_remove_binding = emit_bindings(item);
		int closed_parent_tag = emit_node_children(item, depth);

    if (should_remove_binding)
      bindings.pop_back();

		if (closed_parent_tag)		
			tr << "</" << item->getNodeName()->getStringValue() << ">";
		else
			tr << " />";

    if (ser.indent)
			tr << ser.END_OF_LINE;
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else if (item->getNodeKind() == store::StoreConsts::attributeNode )
	{
		tr << " " << item->getNodeName()->getStringValue() << "=\"";
		emit_expanded_string(item->getStringValue(), true);
		tr << "\"";
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else if (item->getNodeKind() == store::StoreConsts::textNode)
	{		
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
      tr << " ";    
		emit_expanded_string(item->getStringValue());
    previous_item = PREVIOUS_ITEM_WAS_TEXT;
	}
	else if (item->getNodeKind() == store::StoreConsts::commentNode)
	{
    if (ser.indent)
      emit_indentation(depth);
    tr << "<!--" << item->getStringValue() << "-->";
    if (ser.indent)
      tr << ser.END_OF_LINE;		
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else if (item->getNodeKind() == store::StoreConsts::piNode )
	{
    tr << "<?" << item->getTarget() << " " << item->getStringValue() << "?>";
    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else 
	{
		tr << "node of type: " << item->getNodeKind();		
	}
}

void serializer::emitter::emit_item(store::Item* item)
{
  if (item->isAtomic())
  {
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT )
      tr << " ";
    emit_expanded_string(item->getStringValue());
    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else
  {
    if (item->getNodeKind() == store::StoreConsts::attributeNode)
      //||
      //  item->getNodeKind() == namespaceNode)
    {
      ZORBA_ERROR_ALERT(ZorbaError::SENR0001_Item_is_attribute_or_namespace_node);
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
int is_content_type_meta(store::Item_t item, store::Item_t element_parent)
{
  store::Item_t child;
  
  if (element_parent == NULL)
    return 0;
  
  if (element_parent->getNodeName()->getStringValue().lowercase() == "head"
      &&
      item->getNodeName()->getStringValue().lowercase() == "meta")
  {    
    // iterate through attributes
    Iterator_t it = item->getAttributes();
    it->open();
    store::Item_t child = it->next();
    while (child!= NULL)
    { 
      if (child->getNodeName()->getStringValue().lowercase() == "http-equiv"
          &&
          child->getStringValue().lowercase() == "content-type")
        return 1;        
      
      child = it->next();
    }    
  }
  
  return 0;
}

int is_html_empty_element(store::Item_t item)
{
  if (item->getNodeName()->getStringValue().lowercase() == "area"
      ||
      item->getNodeName()->getStringValue().lowercase() == "base"
      ||
      item->getNodeName()->getStringValue().lowercase() == "basefont"
      ||
      item->getNodeName()->getStringValue().lowercase() == "br"
      ||
      item->getNodeName()->getStringValue().lowercase() == "col"
      ||
      item->getNodeName()->getStringValue().lowercase() == "frame"
      ||
      item->getNodeName()->getStringValue().lowercase() == "hr"
      ||
      item->getNodeName()->getStringValue().lowercase() == "img"
      ||
      item->getNodeName()->getStringValue().lowercase() == "input"
      ||
      item->getNodeName()->getStringValue().lowercase() == "isindex"
      ||
      item->getNodeName()->getStringValue().lowercase() == "link"
      ||
      item->getNodeName()->getStringValue().lowercase() == "meta"
      ||
      item->getNodeName()->getStringValue().lowercase() == "param")
    return 1;
  else
    return 0;
}

void serializer::html_emitter::emit_node(store::Item* item, int depth, store::Item* element_parent)
{
  if (item->getNodeKind() == store::StoreConsts::elementNode)
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
    tr << "<" << item->getNodeName()->getStringValue();
    
    /*
      If there is a head element, and the include-content-type parameter has the value yes, the 
      HTML output method MUST add a meta element as the first child element of the head element 
      specifying the character encoding actually used.
    */
    if (ser.include_content_type == PARAMETER_VALUE_YES
        &&
        item->getNodeName()->getStringValue().lowercase() == "head")
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
      tr << "</" << item->getNodeName()->getStringValue() << ">";
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
  else if (item->getNodeKind() == store::StoreConsts::textNode)
  {
    /*
      The HTML output method MUST NOT perform escaping for the content of the script and style elements.
    */
    if (item->getNodeName()->getStringValue().lowercase() == "script"
        ||
        item->getNodeName()->getStringValue().lowercase() == "style")
    {
      if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
        tr << " ";    
      tr << item->getStringValue();  // no character expansion
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
      ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
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
      ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
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
      ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
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
      ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
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
      ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
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
      ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
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
      ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
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
      ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
    }
  }
  else if (parameter_name == "media-type")
  {
    media_type = value;    
  }
  else
  {
    ZORBA_ERROR_ALERT(ZorbaError::SEPM0016_Invalid_parameter_value);
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

bool serializer::setup(ostream& os)
{
  if (encoding == PARAMETER_VALUE_UTF_8)
    tr = new transcoder(os); // the strings are UTF_8, so we use the ``transparent'' transcoder
  else if (encoding == PARAMETER_VALUE_UTF_16)
    tr = new utf8_to_utf16_transcoder(os);
  else
  {
    ZORBA_ASSERT(0);
    return false;
  }
    
  if (method == PARAMETER_VALUE_XML)
    e = new xml_emitter(*this, *tr);
  else if (method == PARAMETER_VALUE_HTML)
    e = new html_emitter(*this, *tr);
  else
  {
    ZORBA_ASSERT(0);
    return false;
  }

  return true;
}

void serializer::serialize(ResultIterator *result, ostream& os)
{
  validate_parameters();
  if (!setup(os))
    return;
  
  e->emit_declaration();

  store::Item_t item = result->nextItem();
  while (item != NULL )
  {
    e->emit_item(&*item);
    item = result->nextItem();
  }
  
  e->emit_declaration_end();
}

void serializer::serialize(store::Item* item, ostream& os)
{
  validate_parameters();
  setup(os);
  
  e->emit_declaration();
  e->emit_item(item);
  e->emit_declaration_end();
}

} // namespace zorba
