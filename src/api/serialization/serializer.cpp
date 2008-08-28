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
#include <sstream>

#include "runtime/api/plan_wrapper.h"
#include "api/serialization/serializer.h"
#include "zorbatypes/numconversions.h"
#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"
#include "zorbatypes/utf8.h"
#include <zorba/zorbastring.h>

#include "system/globalenv.h"
#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"
#include "store/api/item.h"


using namespace std;

namespace zorba {

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Default emitter                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

serializer::emitter::emitter(serializer *the_serializer, transcoder& the_transcoder)
  :
  ser(the_serializer),
  tr(the_transcoder),
  previous_item(INVALID_ITEM),
  theChildIters(8),
  theFirstFreeChildIter(0)
{
  for (ulong i = 0; i < 8; i++)
    theChildIters[i] = GENV_ITERATOR_FACTORY->createChildrenIterator();

  theAttrIter = GENV_ITERATOR_FACTORY->createAttributesIterator();
}


serializer::emitter::~emitter()
{
  ulong numIters = theChildIters.size();
  for (ulong i = 0; i < numIters; i++)
    delete theChildIters[i];

  delete theAttrIter;
}
 

store::ChildrenIterator* serializer::emitter::getChildIter()
{
  if (theFirstFreeChildIter == theChildIters.size())
  {
    theChildIters.push_back(GENV_ITERATOR_FACTORY->createChildrenIterator());
  }

  theFirstFreeChildIter++;

  return theChildIters[theFirstFreeChildIter-1];
}


void serializer::emitter::releaseChildIter(store::ChildrenIterator* iter)
{
  theFirstFreeChildIter--;
  assert(iter == theChildIters[theFirstFreeChildIter]);
}


void serializer::emitter::emit_declaration()
{
  if (ser->byte_order_mark == PARAMETER_VALUE_YES )
  {
    if (ser->encoding == PARAMETER_VALUE_UTF_8 )
    {
      tr << (char)0xEF << (char)0xBB << (char)0xBF;
    }
#ifndef ZORBA_NO_UNICODE
    else if (ser->encoding == PARAMETER_VALUE_UTF_16)
    {
      // Little-endian
      tr.verbatim((char)0xFF); // TODO isn't the value truncated?
      tr.verbatim((char)0xFE);
    }
#endif
  }
}


void serializer::emitter::emit_declaration_end()
{
}


xqpString toHexString(unsigned char ch)
{
  static const char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

  xqpString result;

  if ((ch >> 4) > 0)
    result += hex[ch >> 4];

  result += hex[ch & 0xF];

  return result;
}


void serializer::emitter::emit_expanded_string(
    const xqpStringStore * str,
    bool emit_attribute_value = false )
{
  tr << expand_string(str, emit_attribute_value).c_str();
}


// emit_attribute_value is set to true if the string expansion is performed
// on a value of an attribute
std::string serializer::emitter::expand_string(
    const xqpStringStore* str,
    bool emit_attribute_value = false)
{
  std::stringstream lStringStream;
  transcoder lTranscoder( lStringStream ); 
	const unsigned char* chars = (const unsigned char*)str->c_str();
  const unsigned char* chars_end  = chars + str->bytes();

	int skip = 0;
  
	for (; chars < chars_end; chars++ )
	{       
    // the input string is UTF-8
#ifndef ZORBA_NO_UNICODE    
    if (*chars < 0x80)
      skip = 0;
    else if ((*chars >> 5) == 0x6)
      skip = 2;
    else if ((*chars >> 4) == 0xe)
      skip = 3;
    else if ((*chars >> 3) == 0x1e)
      skip = 4;

    if (skip)
    {
      const unsigned char* temp = chars;
      unsigned int cp = UTF8Decode(temp);
      
      if (cp >= 0x10000 && cp <= 0x10FFFF)
      {
        temp = chars;
        lTranscoder << "&#" << NumConversions::longToStr(UTF8Decode(temp)).c_str()
                    << ";";
        chars += (skip-1);
        skip = 0;
      }
      else
      {
        while (skip)
        {
          lTranscoder<< *chars;
          if (skip > 1)
            chars++;
          skip--;
        }
      }
      continue;
    }
#endif//ZORBA_NO_UNICODE

    /*
      In addition, the non-whitespace control characters #x1 through #x1F and
      #x7F through #x9F in text nodes and attribute nodes MUST be output as
      character references.
    */
    if ((*chars >= 0x1 && *chars <= 0x1F) ||
        (*chars >= 0x7F && *chars <= 0x9F))
    {
      if ((!emit_attribute_value) &&
          (*chars == 0xA || *chars == 0x9))
        lTranscoder << *chars;
      else
        lTranscoder << "&#x" << toHexString(*chars).c_str() << ";";
    }
    else switch (*chars)
		{
		case '<':
      /*
        The HTML output method MUST NOT escape "<" characters occurring in
        attribute values.
      */
      if (ser && ser->method == PARAMETER_VALUE_HTML && emit_attribute_value)
        lTranscoder << *chars;
      else
        lTranscoder << "&lt;";             
			break;
      
		case '>':
			lTranscoder << "&gt;";
			break;
			
    case '"':
      if (emit_attribute_value)
        lTranscoder << "&quot;";
      else
        lTranscoder << *chars;
			break;
			
		case '&':
      /*
        The HTML output method MUST NOT escape a & character occurring in an
        attribute value immediately followed by a { character (see Section
        B.7.1 of the HTML Recommendation [HTML]).
      */      
      if (ser && ser->method == PARAMETER_VALUE_HTML && emit_attribute_value)
      {
        if (chars_end - chars > 1
            &&
            (*(chars+1) == '{'))
          lTranscoder << *chars;
        else
          lTranscoder << "&amp;";
      }
      else
      { 
        int is_quote = 0;
        for (int j = 1; j < chars_end - chars; j++)
        {
          if (j == 1 && *(chars+j) != '#')
            break;
          
				  if ( ! ((*(chars+j) >= 'a' && *(chars+j) <= 'f')
            ||
            (*(chars+j) >= 'A' && *(chars+j) <= 'F')
            ||
            (*(chars+j) >= '0' && *(chars+j) <= '9')
            ||
            *(chars+j) == '#'
            ||
            *(chars+j) == ';'))
				  {
            break;				
				  }
				
				  if (*(chars+j) == ';')
		  		{
            if (j>1)
              is_quote = 1;
            break;				
				  }
			 }
			
			 if (is_quote)
			   lTranscoder << *chars;
          //{
          //  tr << std::string(chars, j+1);
          //  chars += j;
          //}
			 else
				 lTranscoder << "&amp;";
      }
      break;      
			
		default:
			lTranscoder << *chars;
			break;
		}
	}

  return lStringStream.str();
}


void serializer::emitter::emit_indentation(int depth)
{
	for (int i = 0; i < depth; i++)
		tr << "  ";
}


int serializer::emitter::emit_node_children(
    const store::Item* item,
    int depth,
    bool perform_escaping = true)
{
  store::Item* child;
  store::Item* attr;
  int closed_parent_tag = 0;
  
  
  if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    // emit attributes
    store::AttributesIterator* iter = theAttrIter;
    store::Item_t parent = const_cast<store::Item*>(item);
    iter->init(parent);
    iter->open(); 
    while ((attr = iter->next()) != NULL)
    {		
      emit_node(attr, depth);
    }
    iter->close();
  }
  else if (item->getNodeKind() == store::StoreConsts::documentNode)
  {
    closed_parent_tag = 1;
  }
	
	// output all the other nodes
  store::ChildrenIterator* iter = getChildIter();
  store::Item_t parent = const_cast<store::Item*>(item);
  iter->init(parent);
  iter->open();
	while ((child = iter->next()) != NULL)
	{
    if (closed_parent_tag == 0)
		{
      tr << ">";
      closed_parent_tag = 1;
    }

    emit_node(child, depth);
  }
  iter->close();
  releaseChildIter(iter);

  return closed_parent_tag;
}


bool serializer::emitter::emit_bindings(const store::Item* item)
{
  // emit namespace bindings
  NsBindings nsBindings;
  item->getNamespaceBindings(nsBindings);
    
  for (unsigned long i = 0; i < nsBindings.size(); i++)
  {
    if (!haveBinding(nsBindings[i]))
    {
      if (nsBindings[i].second.empty())
      {
        bool havePrefix = this->havePrefix(nsBindings[i].first);
        if (havePrefix)
        {
          if (nsBindings[i].first.empty())
          {
            tr << " xmlns=\"\"";
          }
          else if (ser->undeclare_prefixes == PARAMETER_VALUE_YES)
          {
            tr << " xmlns";
            if (nsBindings[i].first.size() > 0)
              tr << ":" <<  nsBindings[i].first.c_str();
            tr << "=\"\"";
          }
        }
      }
      else
      {
        tr << " xmlns";
        if (nsBindings[i].first.size() > 0)
          tr << ":" <<  nsBindings[i].first.c_str();
        tr << "=\"" << nsBindings[i].second.c_str() << "\"";
      }
    }
  }

  if (nsBindings.size() > 0)
  {
    bindings.push_back(nsBindings);
    return true;
  }
  else
    return false;
}


bool serializer::emitter::haveBinding(std::pair<xqpString,xqpString>& nsBinding) const
{
  for (unsigned long i = 0; i < bindings.size(); i++)
  {
    NsBindings nsBindings = bindings[i];
    
    for (unsigned long j = 0; j < nsBindings.size(); j++)
    {
      if (nsBindings[j].first == nsBinding.first
         &&
         nsBindings[j].second == nsBinding.second)
        return true;
    }
  }

  return false;
}


bool serializer::emitter::havePrefix(const xqpString& pre) const
{
  for (unsigned long i = 0; i < bindings.size(); i++)
  {
    NsBindings nsBindings = bindings[i];
    
    for (unsigned long j = 0; j < nsBindings.size(); j++)
    {
      if (nsBindings[j].first == pre)
        return true;
    }
  }

  return false;
}


void serializer::emitter::emit_node(
    const store::Item* item,
    int depth)
{
	if( item->getNodeKind() == store::StoreConsts::documentNode )
	{		
		emit_node_children(item, depth+1);    
	}
	else if (item->getNodeKind() == store::StoreConsts::elementNode)
	{
    if (ser->indent)
      emit_indentation(depth);

    store::Item* qname = item->getNodeName();
    xqpStringStore* prefix = qname->getPrefix();

    if (prefix->empty())
      tr << "<" << qname->getLocalName()->c_str();
    else
      tr << "<" << prefix->c_str() << ":" << qname->getLocalName()->c_str();

    previous_item = PREVIOUS_ITEM_WAS_NODE;

    bool should_remove_binding = emit_bindings(item);

    int closed_parent_tag = emit_node_children(item, depth);

    if (should_remove_binding)
      bindings.pop_back();

    if (closed_parent_tag)
    {		
      if (prefix->empty())
        tr << "</" << qname->getLocalName()->c_str() << ">";
      else
        tr << "</" << prefix->c_str() << ":" << qname->getLocalName()->c_str() << ">";
    }
    else
    {
      tr << " />";
    }

    if (ser->indent)
      tr << ser->END_OF_LINE;

    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else if (item->getNodeKind() == store::StoreConsts::attributeNode )
	{
    store::Item* qname = item->getNodeName();
    xqpStringStore* prefix = qname->getPrefix();

    if (prefix->empty())
      tr << " " << qname->getLocalName()->c_str() << "=\"";
    else
      tr << " " << prefix->c_str() << ":" << qname->getLocalName()->c_str() << "=\"";

	  emit_expanded_string(item->getStringValue(), true);

	  tr << "\"";

	  previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else if (item->getNodeKind() == store::StoreConsts::textNode)
	{		
    emit_expanded_string(item->getStringValue());

    previous_item = PREVIOUS_ITEM_WAS_TEXT;
	}
	else if (item->getNodeKind() == store::StoreConsts::commentNode)
	{
    if (ser->indent)
      emit_indentation(depth);

    tr << "<!--" << item->getStringValueP()->c_str() << "-->";

    if (ser->indent)
      tr << ser->END_OF_LINE;		

    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else if (item->getNodeKind() == store::StoreConsts::piNode )
	{
    tr << "<?" << item->getTarget()->c_str() << " "
       << item->getStringValueP()->c_str() << "?>";

    previous_item = PREVIOUS_ITEM_WAS_NODE;
	}
	else 
	{
		tr << "node of type: " << item->getNodeKind();		
	}
}


void serializer::emitter::emit_item(const store::Item* item)
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
      ZORBA_ERROR(SENR0001);
    else        
      emit_node(item, 0);
  }  
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XML Emitter                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

serializer::xml_emitter::xml_emitter(
    serializer* the_serializer,
    transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{   
}

void serializer::xml_emitter::emit_declaration()
{
  emitter::emit_declaration();

  if (ser->omit_xml_declaration == PARAMETER_VALUE_NO )
  {
    tr << "<?xml version=\"" << ser->version.c_str() << "\" encoding=\"";
    if (ser->encoding == PARAMETER_VALUE_UTF_8)
      tr << "UTF-8";
#ifndef ZORBA_NO_UNICODE
    else if (ser->encoding == PARAMETER_VALUE_UTF_16)
      tr << "UTF-16";
#endif
    tr << "\"";
      
    if ( ser->standalone != PARAMETER_VALUE_OMIT )
    {
      tr << "standalone=\"";

      if ( ser->standalone == PARAMETER_VALUE_YES )
        tr << "yes";
      else
        tr << "no";

      tr << "\"";
    }
    tr << "?>";

    tr << END_OF_LINE; // Always output a newline
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  HTML Emitter                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

serializer::html_emitter::html_emitter(
    serializer* the_serializer,
    transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{   
}

void serializer::html_emitter::emit_declaration()
{
  emitter::emit_declaration();
     
  tr << "<html>";
  if (ser->indent)
    tr << END_OF_LINE;
}

void serializer::html_emitter::emit_declaration_end()
{
  tr << "</html>";  
}

// returns true if there is a META element, as a child of a HEAD element,
// with an attribute "http-equiv" with value "content-type"
int is_content_type_meta(const store::Item* item, const store::Item* element_parent)
{
  store::Item_t child;
  
  if (element_parent == NULL)
    return 0;

  xqpString pname(element_parent->getNodeName()->getStringValue());
  xqpString iname(item->getNodeName()->getStringValue());
  if (pname.lowercase() == "head"
      &&
      iname.lowercase() == "meta")
  {    
    // iterate through attributes
    store::Iterator_t it = item->getAttributes();
    it->open();
    store::Item_t child;
    while (it->next(child))
    { 
      xqpString cname(child->getNodeName()->getStringValue());
      xqpString cvalue(child->getStringValue());
      if (cname.lowercase() == "http-equiv"
          &&
          cvalue.lowercase() == "content-type")
        return 1;        
    }    
  }
  
  return 0;
}

int is_html_empty_element(const store::Item* item)
{
  xqpString str(item->getNodeName()->getStringValue());
  str = str.lowercase();

  if (str == "area" ||
      str == "base" ||
      str == "basefont" ||
      str == "br" ||
      str == "col" ||
      str == "frame" ||
      str == "hr" ||
      str == "img" ||
      str == "input" ||
      str == "isindex" ||
      str == "link" ||
      str == "meta" ||
      str == "param")
    return 1;
  else
    return 0;
}

void serializer::html_emitter::emit_node(
    const store::Item* item,
    int depth)
{
  const store::Item* element_parent = item->getParent();
      
  if( item->getNodeKind() == store::StoreConsts::documentNode )
  {
    emit_node_children(item, depth+1);
  }
  else if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    unsigned closed_parent_tag = 0;
    
    /*
      If a meta element has been added to the head element as described above, then any existing 
      meta element child of the head element having an http-equiv attribute with the value "Content-Type" 
      MUST be discarded.
    */
    if (ser->include_content_type == PARAMETER_VALUE_YES 
        &&
        element_parent != NULL
        &&
        is_content_type_meta(item, element_parent))
    {
      // do not emit this element
      return;      
    }        
    
    if (ser->indent)
      emit_indentation(depth);
    tr << "<" << item->getNodeName()->getStringValue()->c_str();
    previous_item = PREVIOUS_ITEM_WAS_NODE;
    
    /*
      If there is a head element, and the include-content-type parameter has the value yes, the 
      HTML output method MUST add a meta element as the first child element of the head element 
      specifying the character encoding actually used.
    */
    if (ser->include_content_type == PARAMETER_VALUE_YES
        &&
        item->getNodeName()->getStringValue()->lowercase()->str() == "head")
    {
      tr << "/>";
      if (ser->indent)
        tr << ser->END_OF_LINE;
      if (ser->indent)
        emit_indentation(depth+1);

      tr << "<meta http-equiv=\"content-type\" content=\"" << ser->media_type.c_str() << "; charset=";
      if (ser->encoding == PARAMETER_VALUE_UTF_8)
        tr << "UTF-8";
#ifndef ZORBA_NO_UNICODE
      else if (ser->encoding == PARAMETER_VALUE_UTF_16)
        tr << "UTF-16";
#endif      
      tr << "\">";
      
      if (ser->indent)
        tr << ser->END_OF_LINE;
      closed_parent_tag = 1;
    }

    closed_parent_tag |= emit_node_children(item, depth);
        
    if (closed_parent_tag)   
      tr << "</" << item->getNodeName()->getStringValue()->c_str() << ">";
    else
    {
      /* 
        The HTML output method MUST NOT output an end-tag for empty elements. For HTML 4.0, the 
        empty elements are area, base, basefont, br, col, frame, hr, img, input, isindex, link, 
        meta and param. For example, an element written as <br/> or <br></br> in an XSLT stylesheet 
        MUST be output as <br>.
      */
      if (is_html_empty_element(item) && ser->version == "4.0")
        tr << ">";      
      else
        tr << "/>";
    }
    
    if (ser->indent)
      tr << serializer::END_OF_LINE;

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::attributeNode)
  {
    tr << " " << item->getNodeName()->getStringValue()->c_str() << "=\"";

    emit_expanded_string(item->getStringValue(), true);

    tr << "\"";

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::textNode)
  {
    bool expand = true;
    
    /*
      The HTML output method MUST NOT perform escaping for the content of the script and style elements.
    */
    if (element_parent != NULL )
    {
      xqpString iname(element_parent->getNodeName()->getStringValue());
      iname = iname.lowercase();

      if (iname == "script" || iname == "style")
        expand = false;
    }
    
    /* commented out
      if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
        tr << " ";
    */
    if (expand)
      emit_expanded_string(item->getStringValue());
    else
      tr << item->getStringValue()->c_str();  // no character expansion
    
    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else if (item->getNodeKind() == store::StoreConsts::commentNode)
  {
    if (ser->indent)
      emit_indentation(depth);

    tr << "<!--" << item->getStringValue()->c_str() << "-->";

    if (ser->indent)
      tr << ser->END_OF_LINE;

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::piNode )
  {
    tr << "<?" << item->getTarget()->c_str() << " "
       << item->getStringValue()->c_str() << "?>";

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else
  {
    tr << "node of type: " << item->getNodeKind();
    assert(0);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  SAX2 Emitter                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

serializer::sax2_emitter::sax2_emitter(
    serializer * the_serializer,
    transcoder & the_transcoder,
    SAX2_ContentHandler * aSAX2ContentHandler )
  : 
  emitter(the_serializer, the_transcoder),
  theSAX2ContentHandler( aSAX2ContentHandler ),
  theSAX2LexicalHandler( 0 )
{
  theSAX2LexicalHandler = dynamic_cast< SAX2_LexicalHandler * >( aSAX2ContentHandler );
}


void serializer::sax2_emitter::emit_node_children( const store::Item* item )
{
  store::Iterator_t it;
  store::Item_t child;	
	// output all the other nodes
	it = item->getChildren();
  it->open();
	while (it->next(child))
	{
    if (child->getNodeKind() != store::StoreConsts::attributeNode)
    {
      emit_node(&*child);
    }
  }
}


void serializer::sax2_emitter::emit_declaration()
{
  theSAX2ContentHandler->startDocument();
}


void serializer::sax2_emitter::emit_declaration_end()
{
  theSAX2ContentHandler->endDocument();
}


bool serializer::sax2_emitter::emit_bindings( const store::Item * item )
{
  return false;
}


void serializer::sax2_emitter::emit_node(
    const store::Item * item,
    int depth)
{
  emit_node( item, 0);
}


int serializer::sax2_emitter::emit_node_children( const store::Item* item, int depth, bool perform_escaping )
{
  return emit_node_children( item, 0, false );
}


void serializer::sax2_emitter::emit_node( store::Item* item )
{
	if( item->getNodeKind() == store::StoreConsts::documentNode )
	{
    String lPublicID( item->getUnparsedEntityPublicId() );
    String lSystemID( item->getUnparsedEntitySystemId() );
		emit_node_children(item);    
	}
	else if (item->getNodeKind() == store::StoreConsts::elementNode)
	{
    NsBindings local_nsBindings;
    store::Item_t      item_qname;
    std::vector< xqpString > aNSList; 
    NsBindings::size_type ns_size = 0;
    

    if(theSAX2ContentHandler)
    {
      item->getNamespaceBindings(local_nsBindings,
                                 store::StoreConsts::ONLY_LOCAL_NAMESPACES);//only local namespaces

      SAX2AttributesImpl attrs(item);
      ns_size = local_nsBindings.size(); 
      std::vector< xqpString >::size_type ans_size = theNameSpaces.size();
      for ( unsigned long i = 0; i < ns_size; i++ )
      {
        bool is_declared = false;
        for ( unsigned long j = 0; j < ans_size; j++ )
        {
          if ( theNameSpaces.at( j ) == local_nsBindings[i].second )
          {
            is_declared = true;
            break;
          }
        }
    
        if ( ! is_declared )
        {
          aNSList.push_back( local_nsBindings[i].second );
          theNameSpaces.push_back( local_nsBindings[i].second );
          String lFirst( local_nsBindings[i].first );
          String lSecond( local_nsBindings[i].second );
          theSAX2ContentHandler->startPrefixMapping( lFirst, lSecond );
        }
      }       
      
      //emit_startPrefixMapping( item, local_nsBindings );

      item_qname = item->getNodeName();
      String lNS( item_qname->getNamespace() );
      String lLocalName( item_qname->getLocalName() );
      String lStringValue( item_qname->getStringValue().getp() );
      theSAX2ContentHandler->startElement( lNS, lLocalName, lStringValue, attrs );
    }
      
		emit_node_children(item);

    if(theSAX2ContentHandler)
    {

      String lNS( item_qname->getNamespace() );
      String lLocalName( item_qname->getLocalName() );
      String lStringValue( item_qname->getStringValue().getp() );
      theSAX2ContentHandler->endElement( lNS, lLocalName, lStringValue );

      for ( unsigned long i = 0; i < ns_size; i++ )
      {
        for ( unsigned long j = 0; j < aNSList.size(); j++ )
        {
          if ( aNSList.at( j ) == local_nsBindings[ i ].second )
          {
            String lFirst( local_nsBindings[i].first );
            theSAX2ContentHandler->endPrefixMapping( lFirst );
          }
        }
      }
      //emit_endPrefixMapping( local_nsBindings );
    }
	}
	else if (item->getNodeKind() == store::StoreConsts::textNode)
	{		
		//TODO: if CDATA
    emit_expanded_string(item->getStringValue().getp());
	  //TODO: if CDATA
  }
	else if (item->getNodeKind() == store::StoreConsts::commentNode)
	{
    if ( theSAX2LexicalHandler )
    { 
      String lComment ( item->getStringValue().getp() );
      theSAX2LexicalHandler->comment( lComment ); 
    }
	}
	else if (item->getNodeKind() == store::StoreConsts::piNode )
	{
    if(theSAX2ContentHandler){
      String lTarget( item->getTarget() );
      String lStringValue( item->getStringValue().getp() );
      theSAX2ContentHandler->processingInstruction( lTarget, lStringValue );
    }
	}
//TODO: unimplemented error handling
//	else 
	//{
//		tr << "node of type: " << item->getNodeKind();		
    //SAX2_ParseException   saxx("Unknown node type", &theLocator);
    //if(error_handler)
    //  error_handler->fatalError(saxx);
    //throw saxx;
	//}
}


void serializer::sax2_emitter::emit_item(const store::Item* item)
{
  if (item->isAtomic())
  {
    emit_expanded_string(item->getStringValue().getp());
  }
  else
  {
    if (item->getNodeKind() == store::StoreConsts::attributeNode)
    {
      //TODO: unimplemented error handling
      //SAX2_ParseException   saxx("Node is attribute or namespace", &theLocator);
      //if(error_handler)
      //  error_handler->fatalError(saxx);
      //throw saxx;
    }
    else        
      emit_node( const_cast< store::Item * >( item ) );
  }  
}


void serializer::sax2_emitter::emit_expanded_string(
    const xqpStringStore * aStrStore,
    bool aEmitAttributeValue )
{
  if ( theSAX2ContentHandler )
  {
    //use xml_emitter to normalize string
    std::string lStr = expand_string( aStrStore, aEmitAttributeValue );
    const String lString( lStr );
    theSAX2ContentHandler->characters( lString );
  }
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Text Emitter                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

serializer::text_emitter::text_emitter(
    serializer* the_serializer,
    transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{   
}

void serializer::text_emitter::emit_declaration()
{  
}

void serializer::text_emitter::emit_item(const store::Item* item)
{
  if (item->isAtomic())
  {
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT )
      tr << " ";
    
    tr << item->getStringValue()->c_str();
    
    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else
  {
    if (item->getNodeKind() == store::StoreConsts::attributeNode)
      ZORBA_ERROR(SENR0001);
    else
      emit_node(item, 0);
  }
}

void serializer::text_emitter::emit_node(
    const store::Item* item,
    int depth)
{
  if( item->getNodeKind() == store::StoreConsts::documentNode )
  {		
    emit_node_children(item, depth+1);    
  }
  else if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    previous_item = PREVIOUS_ITEM_WAS_NODE;

    emit_node_children(item, depth);
    
    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::attributeNode )
  {
    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::textNode)
  {
    tr << item->getStringValue()->c_str();
    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else if (item->getNodeKind() == store::StoreConsts::commentNode)
  {
    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::piNode )
  {
    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else 
  {
    assert(0);
  }
}

int serializer::text_emitter::emit_node_children(
                                            const store::Item* item,
                                            int depth,
                                            bool perform_escaping)
{
  store::Item* child;
  
  // output all the other nodes
  store::ChildrenIterator* iter = getChildIter();
  store::Item_t parent = const_cast<store::Item*>(item);
  iter->init(parent);
  iter->open();
  while ((child = iter->next()) != NULL)
  {
    emit_node(child, depth);
  }
  iter->close();
  releaseChildIter(iter);

  return 0;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Serializer                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

const char serializer::END_OF_LINE = '\n';


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


serializer::serializer(error::ErrorManager* aErrorManager)
  :
  theErrorManager(aErrorManager)
{
  reset();
}


serializer::~serializer()
{
}


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
      ZORBA_ERROR( SEPM0016);
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
      ZORBA_ERROR( SEPM0016);
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
      ZORBA_ERROR( SEPM0016);
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
      ZORBA_ERROR( SEPM0016);
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
      ZORBA_ERROR( SEPM0016);
    }
  }
  else if (parameter_name == "method")
  {
    if (value == "xml")
      method = PARAMETER_VALUE_XML;
    else if (value == "html")
      method = PARAMETER_VALUE_HTML;
	else if (value == "text")
      method = PARAMETER_VALUE_TEXT;
    else
    {
      ZORBA_ERROR( SEPM0016);
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
      ZORBA_ERROR( SEPM0016);
    }
  }
  else if (parameter_name == "encoding")
  {
    if (value == "UTF-8")
      encoding = PARAMETER_VALUE_UTF_8;
#ifndef ZORBA_NO_UNICODE
    else if (value == "UTF-16")
      encoding = PARAMETER_VALUE_UTF_16;
#endif
    else
    {
      ZORBA_ERROR( SEPM0016);
    }
  }
  else if (parameter_name == "media-type")
  {
    media_type = value;    
  }
  else
  {
    ZORBA_ERROR( SEPM0016);
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
  {
    tr = new transcoder(os); // the strings are UTF_8, so we use the ``transparent'' transcoder
  }
#ifndef ZORBA_NO_UNICODE
  else if (encoding == PARAMETER_VALUE_UTF_16)
  {
    tr = new utf8_to_utf16_transcoder(os);
  }
#endif
  else
  {
    ZORBA_ASSERT(0);
    return false;
  }
    
  if (method == PARAMETER_VALUE_XML)
    e = new xml_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_HTML)
    e = new html_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_TEXT)
    e = new text_emitter(this, *tr);
  else
  {
    ZORBA_ASSERT(0);
    return false;
  }

  return true;
}


void serializer::serialize(PlanWrapper *result, ostream& os)
{
  validate_parameters();
  if (!setup(os))
    return;
  
  e->emit_declaration();

  store::Item_t item;
  while (result->next(item))
  {
    if (item->isPul())
      ZORBA_ERROR(API0023_CANNOT_SERIALIZE_UPDATE_QUERY);

    e->emit_item(&*item);
  }
  
  e->emit_declaration_end();
}


void serializer::serializeSAX2(
    PlanWrapper * result,
    ostream & os,
    SAX2_ContentHandler * aSAX2ContentHandler )
{
  validate_parameters();
  if (!setup(os))
    return;
  
  e = new sax2_emitter( this, *tr, aSAX2ContentHandler ); 
  e->emit_declaration();

  store::Item_t item;
  while (result->next(item))
  {
    if (item->isPul())
      ZORBA_ERROR(API0023_CANNOT_SERIALIZE_UPDATE_QUERY);

    e->emit_item(&*item);
  }
  e->emit_declaration_end();
}


void serializer::serialize(const store::Item* item, ostream& os)
{
  validate_parameters();
  setup(os);
  
  e->emit_declaration();
  e->emit_item(item);
  e->emit_declaration_end();
}

} // namespace zorba
