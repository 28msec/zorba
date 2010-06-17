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

#include <zorba/zorbastring.h>
#include <zorba/error.h>

#include "zorbatypes/numconversions.h"
#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"
#include "zorbatypes/utf8.h"

#include "api/serialization/serializer.h"
#include "api/serialization/serializable.h"
#include "api/sax2impl.h"
#include "api/serializerimpl.h"

#include "util/converters/json_converter.h"

#include "system/globalenv.h"

#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"
#include "store/api/item.h"


namespace zorba {


static void toHexString(unsigned char ch, char result[])
{
  static const char hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

  if ((ch >> 4) > 0)
  {
    result[0] = hex[ch >> 4];
    result[1]= hex[ch & 0xF];
    result[2] = '\0';
  }
  else
  {
    result[0]= hex[ch & 0xF];
    result[1] = '\0';
  }
}


static void tokenize(
  const xqpStringStore& str,
  const xqpStringStore& separators,
  std::vector<xqpStringStore_t>& tokens)
{
  unsigned int start = 0;

  for (unsigned int i = 0; i < str.bytes(); i++)
  {
    for (unsigned int j = 0; j < separators.bytes(); j++)
    {
      if (str.byteAt(i) == separators.byteAt(j))
      {
        if (start < i)
        {
          tokens.push_back(str.byteSubstr(start, i-start));
        }
        start = i+1;
      }
    }
  }

  if (start < str.bytes())
  {
    tokens.push_back(str.byteSubstr(start, str.bytes()-start));
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Default emitter                                                           //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

serializer::emitter::emitter(serializer *the_serializer, transcoder& the_transcoder)
  :
  ser(the_serializer),
  tr(the_transcoder),
  previous_item(INVALID_ITEM),
  theChildIters(8),
  theFirstFreeChildIter(0),
  isFirstElementNode(true)
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
        lTranscoder << "&#" << NumConversions::uintToStr(UTF8Decode(temp))->c_str()
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
      if ((!emit_attribute_value) && (*chars == 0xA || *chars == 0x9))
      {
        lTranscoder << *chars;
      }
      else
      {
        char buf[3];
        toHexString(*chars, buf);
        lTranscoder << "&#x" << buf << ";";
      }
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


void serializer::emitter::emit_text_node(const store::Item* node)
{
  xqpStringStore_t text;
  node->getStringValue(text);

  const store::Item* parent = node->getParent();

  if (parent == NULL ||
    parent->getNodeKind() != store::StoreConsts::elementNode)
  {
    emit_expanded_string(text.getp());
    return;
  }

  if (!ser->cdata_section_elements_tokens.empty())
  {
    xqpStringStore_t name;
    parent->getNodeName()->getStringValue(name);

    for (unsigned int i = 0; i < ser->cdata_section_elements_tokens.size(); i++)
    {
      if (ser->cdata_section_elements_tokens[i]->byteEqual(name.getp()))
      {
        while (1)
        {
          int pos = text->bytePositionOf("]]>", 3, 0);
          if ( pos > -1)
          {
            tr << "<![CDATA[" << text->byteSubstr(0, pos+2)->c_str() << "]]>";
            text = text->substr(pos+2);
          }
          else
          {
            tr << "<![CDATA[" << text->c_str() << "]]>";
            return;
          }
        }
      }
    }
  }

  // parent is not in the cdata-section-elements, output as a normal text node
  emit_expanded_string(text.getp());
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
    store::Item_t tmp = const_cast<store::Item*>(item);
    iter->init(tmp);
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
  store::StoreConsts::NodeKind prev_node_kind = store::StoreConsts::anyNode;
  store::ChildrenIterator* iter = getChildIter();
  store::Item_t tmp = const_cast<store::Item*>(item);
  iter->init(tmp);
  iter->open();

  while ((child = iter->next()) != NULL)
  {
    if (closed_parent_tag == 0)
    {
      tr << ">";
      closed_parent_tag = 1;
    }

    if (ser->indent &&
      (child->getNodeKind() == store::StoreConsts::elementNode ||
        child->getNodeKind() == store::StoreConsts::commentNode) &&
      (prev_node_kind != store::StoreConsts::textNode))
    {
      if (depth > 0)
        tr << ser->END_OF_LINE;
      emit_indentation(depth);
    }

    // Ignore whitespace text nodes when doing indentation
    if (!ser->indent || child->getNodeKind() != store::StoreConsts::textNode || !child->getStringValue()->is_whitespace())
    {
      emit_node(child, depth);
      prev_node_kind = child->getNodeKind();
    }
  }

  if (ser->indent &&
    (prev_node_kind == store::StoreConsts::elementNode ||
      prev_node_kind == store::StoreConsts::commentNode))
  {
    tr << ser->END_OF_LINE;
    emit_indentation(depth-1);
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

  ulong numBindings = nsBindings.size();

  for (ulong i = 0; i < numBindings; ++i)
  {
    if (!haveBinding(nsBindings[i]))
    {
      if (nsBindings[i].second->empty())
      {
        bool havePrefix = this->havePrefix(nsBindings[i].first);
        if (havePrefix)
        {
          if (nsBindings[i].first->empty())
          {
            tr << " xmlns=\"\"";
          }
          else if (ser->undeclare_prefixes == PARAMETER_VALUE_YES)
          {
            tr << " xmlns";
            if (nsBindings[i].first->size() > 0)
              tr << ":" <<  nsBindings[i].first->c_str();
            tr << "=\"\"";
          }
        }
      }
      else
      {
        tr << " xmlns";
        if (!nsBindings[i].first->empty())
          tr << ":" <<  nsBindings[i].first->c_str();
        tr << "=\"" << nsBindings[i].second->c_str() << "\"";
      }
    }
  }

  if (!nsBindings.empty())
  {
    theBindings.push_back(nsBindings);
    return true;
  }

  return false;
}


bool serializer::emitter::haveBinding(
  std::pair<xqpStringStore_t, xqpStringStore_t>& nsBinding) const
{
  for (ulong i = 0; i < theBindings.size(); ++i)
  {
    const NsBindings& nsBindings = theBindings[i];

    for (ulong j = 0; j < nsBindings.size(); ++j)
    {
      if (nsBindings[j].first->byteEqual(nsBinding.first.getp()) &&
          nsBindings[j].second->byteEqual(nsBinding.second.getp()))
        return true;
    }
  }

  return false;
}


bool serializer::emitter::havePrefix(const xqpStringStore* pre) const
{
  for (unsigned long i = 0; i < theBindings.size(); ++i)
  {
    NsBindings nsBindings = theBindings[i];

    for (unsigned long j = 0; j < nsBindings.size(); ++j)
    {
      if (nsBindings[j].first->byteEqual(pre))
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
    emit_node_children(item, depth);
  }
  else if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    store::Item* qname = item->getNodeName();
    xqpStringStore* prefix = qname->getPrefix();

    if (isFirstElementNode)
    {
      emit_doctype(qname->getLocalName());
      isFirstElementNode = false;
    }
    else if (ser->indent && depth == 0)
      tr << ser->END_OF_LINE;

    if (prefix->empty())
      tr << "<" << qname->getLocalName()->c_str();
    else
      tr << "<" << prefix->c_str() << ":" << qname->getLocalName()->c_str();

    previous_item = PREVIOUS_ITEM_WAS_NODE;

    bool should_remove_binding = emit_bindings(item);

    int closed_parent_tag = emit_node_children(item, depth+1);

    if (should_remove_binding)
      theBindings.pop_back();

    if (closed_parent_tag)
    {
      if (prefix->empty())
        tr << "</" << qname->getLocalName()->c_str() << ">";
      else
        tr << "</" << prefix->c_str() << ":" << qname->getLocalName()->c_str() << ">";
    }
    else
    {
      tr << "/>";
    }

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
    emit_text_node(item);
    if (!item->getStringValue()->is_whitespace()) // ignore whitespace text nodes when doing indentation
      previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else if (item->getNodeKind() == store::StoreConsts::commentNode)
  {
    tr << "<!--" << item->getStringValueP()->c_str() << "-->";
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
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
      tr << " ";

    emit_expanded_string(item->getStringValue());

    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else
  {
    if (item->getNodeKind() == store::StoreConsts::attributeNode)
      ZORBA_ERROR_DESC_OSS(SENR0001,"Attribute <" << item->getStringValue()->c_str() << "> can not be serialized.");
    else
      emit_node(item, 0);
  }
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
  // Do nothing in the default emitter
}


void serializer::emitter::emit_doctype(const xqpStringStore* elementName)
{
  // Do nothing in the default emitter
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  XML Emitter                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

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
    tr << "<?xml version=\"" << ser->version->c_str() << "\" encoding=\"";
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

    tr << END_OF_LINE; // Always output a newline after the XML declaration, although it's not a very good idea
  }
}

void serializer::xml_emitter::emit_doctype(const xqpStringStore* elementName)
{
  // doctype-system has not been specified, do nothing
  if (ser->doctype_system->empty())
    return;

  tr << "<!DOCTYPE " << elementName->c_str();

  /*
   * The doctype-public parameter MUST be ignored unless the doctype-system parameter is specified.
   */
  if (!ser->doctype_public->empty())
    tr << " PUBLIC \"" << ser->doctype_public->c_str() << "\"";
  else
    tr << " SYSTEM";

  tr << " \"" << ser->doctype_system->c_str() << "\">";

  if (ser->indent)
    tr << ser->END_OF_LINE;
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  HTML Emitter                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

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
}

void serializer::html_emitter::emit_declaration_end()
{
}

void serializer::html_emitter::emit_doctype(const xqpStringStore* elementName)
{
  if (ser->doctype_system->empty() && ser->doctype_public->empty())
    return;

  /*
   * The name following <!DOCTYPE MUST be HTML or html.
   */
  tr << "<!DOCTYPE html";

  if (!ser->doctype_public->empty())
  {
    tr << " PUBLIC \"" << ser->doctype_public->c_str() << "\"";
    if (!ser->doctype_system->empty())
      tr << " \"" << ser->doctype_system->c_str() << "\">";
  }
  else
    tr << " SYSTEM" << " \"" << ser->doctype_system->c_str() << "\">";

  if (ser->indent)
    tr << ser->END_OF_LINE;
}

// returns true if there is a META element, as a child of a HEAD element,
// with an attribute "http-equiv" with value "content-type"
int is_content_type_meta(const store::Item* item, const store::Item* element_parent)
{
  store::Item_t child;

  if (element_parent == NULL)
    return 0;

  xqpStringStore_t pname = element_parent->getNodeName()->getStringValue();
  xqpStringStore_t iname = item->getNodeName()->getStringValue();

  if (pname->lowercase()->byteEqual("head", 4) &&
      iname->lowercase()->byteEqual("meta", 4))
  {
    // iterate through attributes
    store::Iterator_t it = item->getAttributes();
    it->open();
    store::Item_t child;
    while (it->next(child))
    {
      xqpStringStore_t cname = child->getNodeName()->getStringValue();
      xqpStringStore_t cvalue = child->getStringValue();
      if (cname->lowercase()->byteEqual("http-equiv", 10) &&
          cvalue->lowercase()->byteEqual("content-type", 12))
        return 1;
    }
  }

  return 0;
}


static bool is_html_empty_content_model_element(const store::Item* item)
{
  if (item == NULL)
    return false;

  xqpStringStore_t str = item->getNodeName()->getStringValue()->lowercase();

  if (str->byteEqual("area", 4) ||
      str->byteEqual("base", 4) ||
      str->byteEqual("basefont", 8) ||
      str->byteEqual("br", 2) ||
      str->byteEqual("col", 3) ||
      str->byteEqual("frame", 5) ||
      str->byteEqual("hr", 2) ||
      str->byteEqual("img", 3) ||
      str->byteEqual("input", 5) ||
      str->byteEqual("isindex", 7) ||
      str->byteEqual("link", 4) ||
      str->byteEqual("meta", 4) ||
      str->byteEqual("param", 5))
    return true;
  else
    return false;
}


// Returns true for those elements which are not allowed under HTML to have
// empty tags (more exactly they are required to have both opening and closing
// tags).
static bool is_html_no_empty_tags_element(const store::Item* item)
{
  if (item == NULL)
    return false;

  xqpStringStore_t str = item->getNodeName()->getStringValue()->lowercase();

  if (str->byteEqual("script", 6) ||
      str->byteEqual("textarea", 8) ||
      str->byteEqual("div", 3))
    return true;
  else
    return false;
}


static bool is_html_boolean_attribute(const xqpStringStore_t& attribute)
{
  xqpStringStore_t str = attribute->lowercase();

  if (str->byteEqual("compact", 7) ||
      str->byteEqual("nowrap", 6) ||
      str->byteEqual("ismap", 5) ||
      str->byteEqual("declare", 7) ||
      str->byteEqual("noshade", 7) ||
      str->byteEqual("checked", 7) ||
      str->byteEqual("disabled", 8) ||
      str->byteEqual("readonly", 8) ||
      str->byteEqual("multiple", 8) ||
      str->byteEqual("selected", 8) ||
      str->byteEqual("noresize", 8) ||
      str->byteEqual("defer", 5))
    return true;
  else
    return false;
}


void serializer::html_emitter::emit_node(
  const store::Item* item,
  int depth)
{
  const store::Item* element_parent = item->getParent();

  if( item->getNodeKind() == store::StoreConsts::documentNode )
  {
    emit_node_children(item, depth);
  }
  else if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    store::Item* qname = item->getNodeName();
    xqpStringStore* prefix = qname->getPrefix();
    unsigned closed_parent_tag = 0;

    if (isFirstElementNode)
    {
      emit_doctype(item->getNodeName()->getStringValue());
      isFirstElementNode = false;
    }

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

    if (prefix->empty())
      tr << "<" << qname->getLocalName()->c_str();
    else
      tr << "<" << prefix->c_str() << ":" << qname->getLocalName()->c_str();

    previous_item = PREVIOUS_ITEM_WAS_NODE;

    bool should_remove_binding = emit_bindings(item);

    /*
      If there is a head element, and the include-content-type parameter has the value yes, the
      HTML output method MUST add a meta element as the first child element of the head element
      specifying the character encoding actually used.
    */
    if (ser->include_content_type == PARAMETER_VALUE_YES
      &&
      item->getNodeName()->getStringValue()->lowercase()->str() == "head")
    {
      tr << ">";
      if (ser->indent)
      {
        tr << ser->END_OF_LINE;
        emit_indentation(depth+1);
      }

      tr << "<meta http-equiv=\"content-type\" content=\""
         << ser->media_type->c_str() << "; charset=";
      if (ser->encoding == PARAMETER_VALUE_UTF_8)
        tr << "UTF-8";
#ifndef ZORBA_NO_UNICODE
      else if (ser->encoding == PARAMETER_VALUE_UTF_16)
        tr << "UTF-16";
#endif
      tr << "\"";
      // closed_parent_tag = 1;
    }

    closed_parent_tag |= emit_node_children(item, depth+1);

    if (should_remove_binding)
      theBindings.pop_back();

    if (closed_parent_tag)
    {
      if (prefix->empty())
        tr << "</" << qname->getLocalName()->c_str() << ">";
      else
        tr << "</" << prefix->c_str() << ":" << qname->getLocalName()->c_str() << ">";
    }
    else
    {
      /*
        The HTML 4.01 spec says that both tags (begin and end tags) are REQUIRED
        for script, textarea and div tags.
      */
      if (is_html_no_empty_tags_element(item)
        ||
        (ser->include_content_type == PARAMETER_VALUE_YES
          &&
          item->getNodeName()->getStringValue()->lowercase()->str() == "head"))
      {
        tr << ">";
        if (prefix->empty())
          tr << "</" << qname->getLocalName()->c_str() << ">";
        else
          tr << "</" << prefix->c_str() << ":" << qname->getLocalName()->c_str() << ">";
      }
      else
      {
        /*
          The HTML output method MUST NOT output an end-tag for empty elements. For HTML 4.0, the
          empty elements are area, base, basefont, br, col, frame, hr, img, input, isindex, link,
          meta and param. For example, an element written as <br/> or <br></br> in an XSLT stylesheet
          MUST be output as <br>.
        */
        if (is_html_empty_content_model_element(item) &&
            ser->version->byteEqual("4.0", 3))
          tr << ">";
        else
          tr << "/>";
      }
    }

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::attributeNode)
  {
    /*
      The HTML output method MUST output boolean attributes (that is attributes with only a single
      allowed value that is equal to the name of the attribute) in minimized form.
    */
    if (is_html_boolean_attribute(item->getNodeName()->getStringValue()))
    {
      tr << " " << item->getNodeName()->getStringValue()->c_str();
    }
    else
    {
      tr << " " << item->getNodeName()->getStringValue()->c_str() << "=\"";
      emit_expanded_string(item->getStringValue(), true);
      tr << "\"";
    }

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
      xqpStringStore_t iname = element_parent->getNodeName()->getStringValue();
      iname = iname->lowercase();

      if (iname->byteEqual("script", 6) || iname->byteEqual("style", 5))
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
    tr << "<!--" << item->getStringValue()->c_str() << "-->";
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

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  XHTML Emitter                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

serializer::xhtml_emitter::xhtml_emitter(
  serializer* the_serializer,
  transcoder& the_transcoder)
  :
  xml_emitter(the_serializer, the_transcoder)
{
}

void serializer::xhtml_emitter::emit_node(
  const store::Item* item,
  int depth)
{
  if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    const store::Item* element_parent = item->getParent();
    unsigned closed_parent_tag = 0;

    if (isFirstElementNode)
    {
      emit_doctype(item->getNodeName()->getStringValue());
      isFirstElementNode = false;
    }

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
      tr << ">";
      if (ser->indent)
      {
        tr << ser->END_OF_LINE;
        emit_indentation(depth+1);
      }

      tr << "<meta http-equiv=\"content-type\" content=\""
         << ser->media_type->c_str() << "; charset=";
      if (ser->encoding == PARAMETER_VALUE_UTF_8)
        tr << "UTF-8";
#ifndef ZORBA_NO_UNICODE
      else if (ser->encoding == PARAMETER_VALUE_UTF_16)
        tr << "UTF-16";
#endif
      tr << "\"/";
      //closed_parent_tag = 1;
    }

    bool should_remove_binding = emit_bindings(item);

    closed_parent_tag |= emit_node_children(item, depth+1);

    if (should_remove_binding)
      theBindings.pop_back();

    /*
     * [Definition: The following XHTML elements have an EMPTY content model:
     * area, base, br, col, hr, img, input, link, meta, basefont, frame, isindex
     *, and param.]
     *
     * Given an empty instance of an XHTML element whose content model is not
     * EMPTY (for example, an empty title or paragraph) the serializer MUST NOT
     * use the minimized form. That is, it MUST output <p></p> and not <p />.
     */

    /*
     * Given an XHTML element whose content model is EMPTY, the serializer MUST
     * use the minimized tag syntax, for example <br />, as the alternative
     * syntax <br></br> allowed by XML gives uncertain results in many existing
     * user agents. The serializer MUST include a space before the trailing />,
     * e.g. <br />, <hr /> and <img src="karen.jpg"  alt="Karen" />.
     */

    if (closed_parent_tag)
      tr << "</" << item->getNodeName()->getStringValue()->c_str() << ">";
    else
    {
      if (is_html_empty_content_model_element(item))
        tr << " />";
      else
        tr << ">" << "</" << item->getNodeName()->getStringValue()->c_str() << ">";
    }

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else
    xml_emitter::emit_node(item, depth);
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SAX2 Emitter                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

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
    emit_node_children(item);
  }
  else if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    NsBindings local_nsBindings;
    store::Item_t item_qname;
    //std::vector<xqpStringStore_t> aNSList;
    unsigned long namespaces_emited = 0;
    NsBindings::size_type ns_size = 0;

    if (isFirstElementNode)
    {
      // TODO: emit doctype declaration
      // emit_doctype(qname->getLocalName());
      isFirstElementNode = false;
    }

    if(theSAX2ContentHandler)
    {
      item->getNamespaceBindings(local_nsBindings,
        store::StoreConsts::ONLY_LOCAL_NAMESPACES);//only local namespaces

      SAX2AttributesImpl attrs(item);
      ns_size = local_nsBindings.size();
      std::vector<xqpStringStore_t>::size_type ans_size = theNameSpaces.size();
      for ( unsigned long i = 0; i < ns_size; i++ )
      {
        bool is_declared = false;
        for ( unsigned long j = 0; j < ans_size; j++ )
        {
          if ( theNameSpaces.at(j).second->byteEqual(local_nsBindings[i].second.getp()) && 
              theNameSpaces.at(j).first->byteEqual(local_nsBindings[i].first.getp()))
          {
            is_declared = true;
            break;
          }
        }

        if ( ! is_declared )
        {
          //aNSList.push_back(local_nsBindings[i].second);
          theNameSpaces.push_back(local_nsBindings[i]);

          String lFirst( local_nsBindings[i].first );
          String lSecond( local_nsBindings[i].second );
          theSAX2ContentHandler->startPrefixMapping( lFirst, lSecond );
          namespaces_emited++;
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

      for ( unsigned long i = 0; i < namespaces_emited; i++ )
      {
        String lFirst( theNameSpaces.back().first );
        theSAX2ContentHandler->endPrefixMapping( lFirst );
        theNameSpaces.resize(theNameSpaces.size()-1);
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


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Text Emitter                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

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
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
      tr << " ";

    tr << item->getStringValue()->c_str();

    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else
  {
    if (item->getNodeKind() == store::StoreConsts::attributeNode)
      ZORBA_ERROR_DESC_OSS(SENR0001,"Attribute <" << item->getStringValue()->c_str() << "> can not be serialized.");
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


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Json Emitter                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

serializer::json_emitter::json_emitter(serializer* the_serializer, transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{
}

void serializer::json_emitter::emit_declaration()
{
}

void serializer::json_emitter::emit_item(const store::Item* item)
{
  xqpStringStore_t result, error_log;

  if(!item->isNode() || item->getNodeKind () != store::StoreConsts::elementNode)
    ZORBA_ERROR_PARAM_OSS(API0062_CONV_JSON_PARAM,
      item->getStringValue(),
      NULL);

  if (JSON_serialize(item, result, error_log))
    tr << result->c_str();
  else
    ZORBA_ERROR_PARAM_OSS(API0061_CONV_JSON_SERIALIZE,
      item->getStringValue(),
      error_log);
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  JsonML Emitter                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

serializer::jsonml_emitter::jsonml_emitter(serializer* the_serializer, transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{
}

void serializer::jsonml_emitter::emit_declaration()
{
}

void serializer::jsonml_emitter::emit_item(const store::Item* item)
{
  xqpStringStore_t result, error_log;

  if(!item->isNode() || item->getNodeKind () != store::StoreConsts::elementNode)
    ZORBA_ERROR_PARAM_OSS(API0065_CONV_JSON_ML_PARAM,
      item->getStringValue(),
      NULL);

  if (JSON_ML_serialize(item, result, error_log))
    tr << result->c_str();
  else
    ZORBA_ERROR_PARAM_OSS(API0064_CONV_JSON_ML_SERIALIZE,
      item->getStringValue(),
      error_log);
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Serializer                                                                //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

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
  byte_order_mark = PARAMETER_VALUE_NO;

  cdata_section_elements = new xqpStringStore("");

  doctype_system = new xqpStringStore("");
  doctype_public = new xqpStringStore("");

  encoding = PARAMETER_VALUE_UTF_8;

  include_content_type = PARAMETER_VALUE_NO;

  media_type = new xqpStringStore("");

  method = PARAMETER_VALUE_XML;

  normalization_form = new xqpStringStore("");

  omit_xml_declaration = PARAMETER_VALUE_NO;

  standalone = PARAMETER_VALUE_OMIT;

  undeclare_prefixes = PARAMETER_VALUE_NO;

  version = new xqpStringStore("1.0");
  version_has_default_value = true;

  indent = PARAMETER_VALUE_NO;
}


void serializer::setParameter(const char* aName, const char* aValue)
{
  if (!strcmp(aName, "indent"))
  {
    if (!strcmp(aValue, "yes"))
      indent = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      indent = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
        << "> can not be set with value <" << aValue
        << ">. Accepted values are yes/no.");
    }
  }
  else if (!strcmp(aName, "standalone"))
  {
    if (!strcmp(aValue, "yes"))
      standalone = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      standalone = PARAMETER_VALUE_NO;
    else if (!strcmp(aValue, "omit"))
      standalone = PARAMETER_VALUE_OMIT;
    else
    {
      ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
        << "> can not be set with value <" << aValue
        << ">. Accepted values are yes/no/omit.");
    }
  }
  else if (!strcmp(aName, "omit-xml-declaration"))
  {
    if (!strcmp(aValue, "yes"))
      omit_xml_declaration = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      omit_xml_declaration = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
        << "> can not be set with value <" << aValue
        <<">. Accepted values are yes/no.");
    }
  }
  else if (!strcmp(aName, "byte-order-mark"))
  {
    if (!strcmp(aValue, "yes"))
      byte_order_mark = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      byte_order_mark = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
        << "> can not be set with value <" << aValue
        <<">. Accepted values are yes/no.");
    }
  }
  else if (!strcmp(aName, "undeclare-prefixes"))
  {
    if (!strcmp(aValue, "yes"))
      undeclare_prefixes = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      undeclare_prefixes = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
        << "> can not be set with value <" << aValue
        <<">. Accepted values are yes/no.");
    }
  }
  else if (!strcmp(aName, "method"))
  {
    if (!strcmp(aValue, "xml"))
      method = PARAMETER_VALUE_XML;
    else if (!strcmp(aValue, "html"))
      method = PARAMETER_VALUE_HTML;
    else if (!strcmp(aValue, "xhtml"))
      method = PARAMETER_VALUE_XHTML;
    else if (!strcmp(aValue, "text"))
      method = PARAMETER_VALUE_TEXT;
    else if (!strcmp(aValue, "json"))
      method = PARAMETER_VALUE_JSON;
    else if (!strcmp(aValue, "jsonml"))
      method = PARAMETER_VALUE_JSONML;
    else if (!strcmp(aValue, "binary"))
      method = PARAMETER_VALUE_BINARY;
    else
    {
      ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
        << "> can not be set with value <" << aValue
        <<">. Accepted values are xml/html/xhtml/text/json/jsonml/binary.");
    }
  }
  else if (!strcmp(aName, "include-content-type"))
  {
    if (!strcmp(aValue, "yes"))
      include_content_type = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      include_content_type = PARAMETER_VALUE_NO;
    else
    {
      ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
        << "> can not be set with value <" << aValue
        <<">. Accepted values are yes/no.");
    }
  }
  else if (!strcmp(aName, "encoding"))
  {
    if (!strcmp(aValue, "UTF-8"))
      encoding = PARAMETER_VALUE_UTF_8;
#ifndef ZORBA_NO_UNICODE
    else if (!strcmp(aValue, "UTF-16"))
      encoding = PARAMETER_VALUE_UTF_16;
#endif
    else
    {
      ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
        << "> can not be set with value <" << aValue
        <<">. Accepted values are UTF-8/UTF-16.");
    }
  }
  else if (!strcmp(aName, "media-type"))
  {
    media_type = new xqpStringStore(aValue);
  }
  else if (!strcmp(aName, "version"))
  {
    version = new xqpStringStore(aValue);
    version_has_default_value = false;
  }
  else if (!strcmp(aName, "doctype-system"))
  {
    doctype_system = new xqpStringStore(aValue);
  }
  else if (!strcmp(aName, "doctype-public"))
  {
    doctype_public = new xqpStringStore(aValue);
  }
  else if (!strcmp(aName, "cdata-section-elements"))
  {
    cdata_section_elements = new xqpStringStore(aValue);
  }
  else
  {
    ZORBA_ERROR_DESC_OSS(SEPM0016,"Parameter <" << aName
      << "> can not be set with value <" << aValue <<">.");
  }
}


void serializer::validate_parameters(void)
{
  if (omit_xml_declaration == PARAMETER_VALUE_YES)
  {
    if (standalone != PARAMETER_VALUE_OMIT)
    {
      // TODO: throw SEPM0009
    }
  }

  if (method == PARAMETER_VALUE_HTML)
  {
    // Default value for "version" when method is HTML is "4.0"
    if (version_has_default_value)
      version = new xqpStringStore("4.0");
    else if ( !(version->byteEqual("4.0", 3) || version->byteEqual("4.01", 4)) )
    {
      // Only HTML versions 4.0 and 4.01 are supported
      ZORBA_ERROR_DESC(SESU0013, "Unsupported HTML serialization version. Accepted values are 4.0/4.01 .");
    }
  }
}


bool serializer::setup(std::ostream& os)
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
  else if (method == PARAMETER_VALUE_XHTML)
    e = new xhtml_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_TEXT)
    e = new text_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_JSON)
    e = new json_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_JSONML)
    e = new jsonml_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_BINARY)
    e = new binary_emitter(this, *tr);
  else
  {
    ZORBA_ASSERT(0);
    return false;
  }

  if (!cdata_section_elements->empty())
  {
    tokenize(*cdata_section_elements.getp(),
      xqpStringStore("; "),
      cdata_section_elements_tokens);
  }

  return true;
}

void
serializer::serialize(
  intern::Serializable* aObject,
  std::ostream&      aOStream)
{
  serialize(aObject, aOStream, 0);
}

void
serializer::serialize(
  intern::Serializable* aObject,
  std::ostream&              aOStream,
  SAX2_ContentHandler*  aHandler)
{
  // used for JSON serialization only
  bool firstItem = true;

  validate_parameters();
  if (!setup(aOStream)) {
    return;
  }

  // in case we use SAX event notifications
  if (aHandler) {
    // only allow XML-based methods for SAX notifications
    if (method != PARAMETER_VALUE_XML &&
      method != PARAMETER_VALUE_XHTML &&
      method != PARAMETER_VALUE_JSONML) {
      ZORBA_ERROR(API0070_INVALID_SERIALIZATION_METHOD_FOR_SAX);
    }
    // it's OK now, build a SAX emmiter
    e = new sax2_emitter(this, *tr, aHandler);
  }

  e->emit_declaration();

  store::Item_t lItem;
  while (aObject->nextSerializableItem(lItem)) {
    // JSON serialization only alows one single item to be serialized
    // so throw an error if we get to a second item
    if (!firstItem && (
        method == PARAMETER_VALUE_JSON ||
        method == PARAMETER_VALUE_JSONML)) {
      ZORBA_ERROR(API0066_JSON_SEQUENCE_CANNOT_BE_SERIALIZED);
    }

    // PUL's cannot be serialized
    if (lItem->isPul()) {
      ZORBA_ERROR(API0023_CANNOT_SERIALIZE_UPDATE_QUERY);
    }

    e->emit_item(&*lItem);

    // used for JSON serialization only
    firstItem = false;
  }

  e->emit_declaration_end();
}

void serializer::serialize(intern::Serializable* object,
  std::ostream& stream,
  itemHandler aHandler,
  void* aHandlerData)
{
  store::Item_t lItem;
  if (object->nextSerializableItem(lItem)) {
    // first, we notify the caller, that everything that we wanted to 
    // (e.g. computed by side-effecting scripting functions is now available).
    //  He can, for example, decide on the serialization method
      Zorba_SerializerOptions_t* lSerParams = aHandler(aHandlerData);
      if (lSerParams) {
        SerializerImpl::setSerializationParameters(*this, *lSerParams);
      }
  } else {
    return;
  }

  validate_parameters();

  if (!setup(stream)) {
    return;
  }

  e->emit_declaration();

  // used for Json and JsonML serialization only
  bool firstItem = true;

  do {
    if (!firstItem) {
      Zorba_SerializerOptions_t* lSerParams = aHandler(aHandlerData);
      if (lSerParams) {
        SerializerImpl::setSerializationParameters(*this, *lSerParams);
        if (!setup(stream)) {
          return;
        }
      }
        
      // JSON serialization only alows one single item to be serialized
      // so throw an error if we get to a second item
      if (method == PARAMETER_VALUE_JSON ||
          method == PARAMETER_VALUE_JSONML) {
        ZORBA_ERROR(API0066_JSON_SEQUENCE_CANNOT_BE_SERIALIZED);
      }
    }

    // PUL's cannot be serialized
    if (lItem->isPul()) {
      ZORBA_ERROR(API0023_CANNOT_SERIALIZE_UPDATE_QUERY);
    }

    e->emit_item(&*lItem);

    // used for Json and JsonML serialization only
    firstItem = false;
  } while (object->nextSerializableItem(lItem));

  e->emit_declaration_end();
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  binary emitter                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

serializer::binary_emitter::binary_emitter(
  serializer* the_serializer,
  transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{}

void serializer::binary_emitter::emit_item(const store::Item* item)
{
  xqp_base64Binary lValue;
  // First try to just get the base64 value from the String
  try {
    lValue = item->getBase64BinaryValue();
  } catch (...) {
    //If this fails, then just get the string value of the item
    // and convert it to base64
    std::string lStringValue;
    item->getStringValue(lStringValue);
    std::stringstream lStream(lStringValue);
    Base64::encode(lStream, lValue);
  }

  std::vector<char> lDecodedData;
  lValue.decode(lDecodedData);

  for (std::vector<char>::const_iterator lIter = lDecodedData.begin();
       lIter != lDecodedData.end();
       ++lIter) {
    tr << *lIter;
  }
}


} // namespace zorba

