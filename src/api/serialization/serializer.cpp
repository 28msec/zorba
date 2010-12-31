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

#include "api/serialization/serializer.h"
#include "api/serialization/serializable.h"
#include "api/sax2impl.h"
#include "api/serializerimpl.h"
#include "api/unmarshaller.h"

#include "util/converters/json_converter.h"
#include "util/ascii_util.h"
#include "util/utf8_util.h"
#include "util/string_util.h"

#include "system/globalenv.h"

#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"
#include "store/api/item.h"


namespace zorba {


/*******************************************************************************

********************************************************************************/
static void toHexString(unsigned char ch, char result[])
{
  static const char hex[] = 
  { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

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


/*******************************************************************************

********************************************************************************/
static void tokenize(
    const char* str,
    zstring::size_type strlen,
    const char* separators,
    ulong seplen,
    std::vector<zstring>& tokens)
{
  ulong start = 0;

  for (ulong i = 0; i < strlen; ++i)
  {
    for (ulong j = 0; j < seplen; ++j)
    {
      if (str[i] == separators[j])
      {
        if (start < i)
        {
          tokens.push_back(zstring(str + start, i-start));
        }
        start = i+1;
        break;
      }
    }
  }

  if (start < strlen)
  {
    tokens.push_back(zstring(str + start, strlen - start));
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Default emitter                                                           //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::emitter::emitter(serializer* the_serializer, transcoder& the_transcoder)
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


/*******************************************************************************

********************************************************************************/
serializer::emitter::~emitter()
{
  ulong numIters = (ulong)theChildIters.size();
  for (ulong i = 0; i < numIters; i++)
    delete theChildIters[i];

  delete theAttrIter;
}


/*******************************************************************************

********************************************************************************/
store::ChildrenIterator* serializer::emitter::getChildIter()
{
  if (theFirstFreeChildIter == theChildIters.size())
  {
    theChildIters.push_back(GENV_ITERATOR_FACTORY->createChildrenIterator());
  }

  theFirstFreeChildIter++;

  return theChildIters[theFirstFreeChildIter-1];
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::releaseChildIter(store::ChildrenIterator* iter)
{
  theFirstFreeChildIter--;
  assert(iter == theChildIters[theFirstFreeChildIter]);
}

/*******************************************************************************
  emit_attribute_value is set to true if the string expansion is performed
  on a value of an attribute
********************************************************************************/
void serializer::emitter::emit_expanded_string(
  const char* str,
  zstring::size_type strlen,
  bool emit_attribute_value = false)
{
  const unsigned char* chars = (const unsigned char*)str;
  const unsigned char* chars_end  = chars + strlen;

#ifndef ZORBA_NO_UNICODE
  int skip = 0;
#endif // ZORBA_NO_UNICODE

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
      unicode::code_point cp = utf8::next_char(temp);

      if (cp >= 0x10000 && cp <= 0x10FFFF)
      {
        temp = chars;
        tr << "&#" << NumConversions::uintToStr(utf8::next_char(temp))
                    << ";";
        chars += (skip-1);
        skip = 0;
      }
      else
      {
        while (skip)
        {
          tr << *chars;
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
        tr << *chars;
      }
      else
      {
        char buf[3];
        toHexString(*chars, buf);
        tr << "&#x" << buf << ";";
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
          tr << *chars;
        else
          tr << "&lt;";
        break;

      case '>':
        tr << "&gt;";
        break;

      case '"':
        if (emit_attribute_value)
          tr << "&quot;";
        else
          tr << *chars;
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
            tr << *chars;
          else
            tr << "&amp;";
        }
        else
        {
          tr << "&amp;";
        }
        break;

      default:
        tr << *chars;
        break;
    }
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_indentation(int depth)
{
  for (int i = 0; i < depth; i++)
    tr << "  ";
}


/*******************************************************************************

********************************************************************************/
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
      tr.verbatim((char)0xFF);
      tr.verbatim((char)0xFE);
    }
#endif
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_declaration_end()
{
  // Do nothing in the default emitter
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_doctype(const zstring& elementName)
{
  // Do nothing in the default emitter
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_item(const store::Item* item)
{
  if (item->isAtomic())
  {
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
      tr << " ";

    zstring strval;
    item->getStringValue2(strval);

    emit_expanded_string(strval.c_str(), strval.size());

    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else
  {
    if (item->getNodeKind() == store::StoreConsts::attributeNode)
    {
      ZORBA_ERROR_DESC_OSS(SENR0001,
                           "Attribute <" << item->getStringValue()
                           << "> can not be serialized.");
    }
    else
    {
      emit_node(item, 0);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_node(const store::Item* item, int depth)
{
  if (item->getNodeKind() == store::StoreConsts::documentNode)
  {
    emit_node_children(item, depth);

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    store::Item* qnameItem = item->getNodeName();
    const zstring& prefix = qnameItem->getPrefix();
    const zstring& local = qnameItem->getLocalName();

    if (isFirstElementNode)
    {
      emit_doctype(local);
      isFirstElementNode = false;
    }
    else if (ser->indent && depth == 0)
    {
      tr << ser->END_OF_LINE;
    }

    if (prefix.empty())
      tr << "<" << local;
    else
      tr << "<" << prefix << ":" << local;

    previous_item = PREVIOUS_ITEM_WAS_NODE;

    bool should_remove_binding = emit_bindings(item);

    int closed_parent_tag = emit_node_children(item, depth+1);

    if (should_remove_binding)
      theBindings.pop_back();

    if (closed_parent_tag)
    {
      if (prefix.empty())
        tr << "</" << local << ">";
      else
        tr << "</" << prefix << ":" << local << ">";
    }
    else
    {
      tr << "/>";
    }

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::attributeNode)
  {
    store::Item* qnameItem = item->getNodeName();
    const zstring& prefix = qnameItem->getPrefix();
    const zstring& local = qnameItem->getLocalName();

    if (prefix.empty())
      tr << " " << local << "=\"";
    else
      tr << " " << prefix << ":" << local << "=\"";

    zstring value;
    item->getStringValue2(value);

    emit_expanded_string(value.c_str(), value.size(), true);

    tr << "\"";

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::textNode)
  {
    zstring text;
    item->getStringValue2(text);

    emit_text_node(item, text);

    if (!ascii::is_whitespace(text.c_str()))
    {
      // ignore whitespace text nodes when doing indentation
      previous_item = PREVIOUS_ITEM_WAS_TEXT;
    }
    else
    {
      previous_item = PREVIOUS_ITEM_WAS_NODE;
    }
  }
  else if (item->getNodeKind() == store::StoreConsts::commentNode)
  {
    tr << "<!--" << item->getStringValue() << "-->";
    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::piNode)
  {
    tr << "<?" << item->getTarget() << " " << item->getStringValue() << "?>";

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else
  {
    tr << "node of type: " << item->getNodeKind();
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_text_node(
    const store::Item* node,
    const zstring& text)
{
  const store::Item* parent = node->getParent();

  if (parent == NULL ||
    parent->getNodeKind() != store::StoreConsts::elementNode)
  {
    emit_expanded_string(text.c_str(), text.size());
    return;
  }

  if (!ser->cdata_section_elements_tokens.empty())
  {
    zstring name;
    parent->getNodeName()->getStringValue2(name);

    for (ulong i = 0; i < ser->cdata_section_elements_tokens.size(); ++i)
    {
      if (ser->cdata_section_elements_tokens[i] == name)
      {
        const char* textp = text.c_str();
        zstring::size_type pos1 = 0;

        while (1)
        {
          zstring::size_type pos2 = text.find("]]>", pos1, 3);
          if ( pos2 != zstring::npos)
          {
            zstring::size_type n = pos2 + 2 - pos1;

            tr << "<![CDATA[";
            tr.write(textp, (std::streamsize)n) << "]]>";
            pos1 += n; 
            textp += n;
          }
          else
          {
            tr << "<![CDATA[" << textp << "]]>";
            return;
          }
        }
      }
    }
  }

  // parent is not in the cdata-section-elements, output as a normal text node
  emit_expanded_string(text.c_str(), text.size());
}


/*******************************************************************************

********************************************************************************/
int serializer::emitter::emit_node_children(
  const store::Item* item,
  int depth,
  bool perform_escaping)
{
  store::Item* child;
  store::Item* attr;
  int closed_parent_tag = 0;

  if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    // emit attributes
    store::AttributesIterator* iter = theAttrIter;

    iter->init(item);
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

  iter->init(item);
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
    if (!ser->indent ||
        child->getNodeKind() != store::StoreConsts::textNode ||
        !ascii::is_whitespace(child->getStringValue().c_str()))
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


/*******************************************************************************

********************************************************************************/
bool serializer::emitter::emit_bindings(const store::Item* item)
{
  // emit namespace bindings
  store::NsBindings nsBindings;
  item->getNamespaceBindings(nsBindings);

  ulong numBindings = (ulong)nsBindings.size();

  for (ulong i = 0; i < numBindings; ++i)
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
              tr << ":" <<  nsBindings[i].first;
            tr << "=\"\"";
          }
        }
      }
      else
      {
        tr << " xmlns";
        if (!nsBindings[i].first.empty())
          tr << ":" <<  nsBindings[i].first;
        tr << "=\"" << nsBindings[i].second << "\"";
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


/*******************************************************************************

********************************************************************************/
bool serializer::emitter::haveBinding(std::pair<zstring, zstring>& nsBinding) const
{
  for (ulong i = 0; i < theBindings.size(); ++i)
  {
    const store::NsBindings& nsBindings = theBindings[i];

    for (ulong j = 0; j < nsBindings.size(); ++j)
    {
      if (nsBindings[j].first == nsBinding.first &&
          nsBindings[j].second == nsBinding.second)
        return true;
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool serializer::emitter::havePrefix(const zstring& pre) const
{
  for (unsigned long i = 0; i < theBindings.size(); ++i)
  {
    const store::NsBindings& nsBindings = theBindings[i];

    for (unsigned long j = 0; j < nsBindings.size(); ++j)
    {
      if (nsBindings[j].first == pre)
        return true;
    }
  }

  return false;
}



////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  XML Emitter                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::xml_emitter::xml_emitter(
  serializer* the_serializer,
  transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{
}


/*******************************************************************************

********************************************************************************/
void serializer::xml_emitter::emit_declaration()
{
  emitter::emit_declaration();

  if (ser->omit_xml_declaration == PARAMETER_VALUE_NO )
  {
    tr << "<?xml version=\"" << ser->version << "\" encoding=\"";
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


/*******************************************************************************

********************************************************************************/
void serializer::xml_emitter::emit_doctype(const zstring& elementName)
{
  // doctype-system has not been specified, do nothing
  if (ser->doctype_system.empty())
    return;

  tr << "<!DOCTYPE " << elementName;

  // The doctype-public parameter MUST be ignored unless the doctype-system
  // parameter is specified.
  if (!ser->doctype_public.empty())
    tr << " PUBLIC \"" << ser->doctype_public << "\"";
  else
    tr << " SYSTEM";

  tr << " \"" << ser->doctype_system << "\">";

  if (ser->indent)
    tr << ser->END_OF_LINE;
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  HTML Emitter                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  returns true if there is a META element, as a child of a HEAD element,
  with an attribute "http-equiv" with value "content-type"
********************************************************************************/ 
static int is_content_type_meta(
    const store::Item* item,
    const store::Item* element_parent)
{
  store::Item_t child;

  if (element_parent == NULL)
    return 0;

  zstring pname;
  zstring iname;

  utf8::to_lower(element_parent->getNodeName()->getStringValue(), &pname);
  utf8::to_lower(item->getNodeName()->getStringValue(), &iname);

  if (equals(pname, "head", 4) && equals(iname, "meta", 4))
  {
    // iterate through attributes
    store::Item_t child;
    store::Iterator_t it = item->getAttributes();

    it->open();

    while (it->next(child))
    {
      zstring cname;
      zstring cvalue;

      utf8::to_lower(child->getNodeName()->getStringValue(), &cname);
      utf8::to_lower(child->getStringValue(), &cvalue);

      if (equals(cname, "http-equiv", 10) && equals(cvalue, "content-type", 12))
        return 1;
    }
  }

  return 0;
}


/*******************************************************************************

********************************************************************************/
static bool is_html_empty_content_model_element(const store::Item* item)
{
  if (item == NULL)
    return false;

  zstring nodename;
  utf8::to_lower(item->getNodeName()->getStringValue(), &nodename);

  if (equals(nodename, "area", 4) ||
      equals(nodename, "base", 4) ||
      equals(nodename, "basefont", 8) ||
      equals(nodename, "br", 2) ||
      equals(nodename, "col", 3) ||
      equals(nodename, "frame", 5) ||
      equals(nodename, "hr", 2) ||
      equals(nodename, "img", 3) ||
      equals(nodename, "input", 5) ||
      equals(nodename, "isindex", 7) ||
      equals(nodename, "link", 4) ||
      equals(nodename, "meta", 4) ||
      equals(nodename, "param", 5))
    return true;
  else
    return false;
}


/*******************************************************************************
  Returns true for those elements which are not allowed under HTML to have
  empty tags (more exactly they are required to have both opening and closing
  tags).
********************************************************************************/ 
static bool is_html_no_empty_tags_element(const store::Item* item)
{
  if (item == NULL)
    return false;

  zstring nodename;
  utf8::to_lower(item->getNodeName()->getStringValue(), &nodename);

  if (equals(nodename, "script", 6) ||
      equals(nodename, "textarea", 8) ||
      equals(nodename, "div", 3))
    return true;
  else
    return false;
}


/*******************************************************************************

********************************************************************************/
static bool is_html_boolean_attribute(const zstring& attribute)
{
  zstring str;
  utf8::to_lower(attribute, &str);

  if (equals(str, "compact", 7) ||
      equals(str, "nowrap", 6) ||
      equals(str, "ismap", 5) ||
      equals(str, "declare", 7) ||
      equals(str, "noshade", 7) ||
      equals(str, "checked", 7) ||
      equals(str, "disabled", 8) ||
      equals(str, "readonly", 8) ||
      equals(str, "multiple", 8) ||
      equals(str, "selected", 8) ||
      equals(str, "noresize", 8) ||
      equals(str, "defer", 5))
    return true;
  else
    return false;
}


/*******************************************************************************

********************************************************************************/
serializer::html_emitter::html_emitter(
  serializer* the_serializer,
  transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{
}


/*******************************************************************************

********************************************************************************/
void serializer::html_emitter::emit_declaration()
{
  emitter::emit_declaration();
}


/*******************************************************************************

********************************************************************************/
void serializer::html_emitter::emit_declaration_end()
{
}


/*******************************************************************************

********************************************************************************/
void
serializer::html_emitter::emit_doctype(const zstring& elementName)
{
  if (ser->doctype_system.empty() && ser->doctype_public.empty()) {
    return;
  }

  // The name following <!DOCTYPE MUST be HTML or html.
  tr << "<!DOCTYPE HTML";

  // If the doctype-public parameter is specified, then the output method
  // MUST output PUBLIC followed by the specified public identifier.
  if (!ser->doctype_public.empty()) {
    tr << " PUBLIC \"" << ser->doctype_public << "\"";
    // If the doctype-system parameter is also specified, it MUST also output
    // the specified system identifier following the public identifier.
    if (!ser->doctype_system.empty()) {
      tr << " \"" << ser->doctype_system << "\"";
    }
  }
  // If the doctype-system parameter is specified but the doctype-public
  // parameter is not specified, then the output method MUST output SYSTEM
  // followed by the specified system identifier.
  else {
    tr << " SYSTEM \"" << ser->doctype_system << "\"";
  }

  tr << ">";

  if (ser->indent) {
    tr << ser->END_OF_LINE;
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::html_emitter::emit_node(
  const store::Item* item,
  int depth)
{
  const store::Item* element_parent = item->getParent();

  if( item->getNodeKind() == store::StoreConsts::documentNode)
  {
    emit_node_children(item, depth);
  }
  else if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    store::Item* qnameItem = item->getNodeName();

    zstring qname;
    qnameItem->getStringValue2(qname);

    unsigned closed_parent_tag = 0;

    if (isFirstElementNode)
    {
      emit_doctype(qname);
      isFirstElementNode = false;
    }

    // If a meta element has been added to the head element as described above,
    // then any existing meta element child of the head element having an
    // http-equiv attribute with the value "Content-Type" MUST be discarded.
    if (ser->include_content_type == PARAMETER_VALUE_YES &&
      element_parent != NULL &&
      is_content_type_meta(item, element_parent))
    {
      // do not emit this element
      return;
    }

    tr << "<" << qname;

    previous_item = PREVIOUS_ITEM_WAS_NODE;

    bool should_remove_binding = emit_bindings(item);

    // If there is a head element, and the include-content-type parameter has
    // the value yes, the HTML output method MUST add a meta element as the
    // first child element of the head element specifying the character encoding
    // actually used.
    if (ser->include_content_type == PARAMETER_VALUE_YES &&
        strcasecmp(qname.c_str(), "head") == 0)
    {
      tr << ">";
      if (ser->indent)
      {
        tr << ser->END_OF_LINE;
        emit_indentation(depth+1);
      }

      tr << "<meta http-equiv=\"content-type\" content=\""
         << ser->media_type << "; charset=";

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
      tr << "</" << qname << ">";
    }
    else
    {
      // The HTML 4.01 spec says that both tags (begin and end tags) are REQUIRED
      // for script, textarea and div tags.
      if (is_html_no_empty_tags_element(item) ||
          (ser->include_content_type == PARAMETER_VALUE_YES &&
           strcasecmp(qname.c_str(), "head") == 0))
      {
        tr << ">";
        tr << "</" << qname << ">";
      }
      else
      {
        // The HTML output method MUST NOT output an end-tag for empty elements.
        // For HTML 4.0, the empty elements are area, base, basefont, br, col,
        // frame, hr, img, input, isindex, link, meta and param. For example,
        // an element written as <br/> or <br></br> in an XSLT stylesheet MUST
        // be output as <br>.
        if (is_html_empty_content_model_element(item) && equals(ser->version, "4.0", 3))
          tr << ">";
        else
          tr << "/>";
      }
    }

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::attributeNode)
  {
    // The HTML output method MUST output boolean attributes (that is attributes
    // with only a single allowed value that is equal to the name of the 
    // attribute) in minimized form.
    zstring qname;
    item->getNodeName()->getStringValue2(qname);

    if (is_html_boolean_attribute(qname))
    {
      tr << " " << qname;
    }
    else
    {
      tr << " " << qname << "=\"";

      zstring strval;
      item->getStringValue2(strval);

      emit_expanded_string(strval.c_str(), strval.size(), true);
      tr << "\"";
    }

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::textNode)
  {
    bool expand = true;

    // The HTML output method MUST NOT perform escaping for the content of
    // the script and style elements.
    if (element_parent != NULL )
    {
      zstring qname;
      element_parent->getNodeName()->getStringValue2(qname);

      if (strcasecmp(qname.c_str(), "script") == 0 ||
          strcasecmp(qname.c_str(), "style") == 0)
        expand = false;
    }

    if (expand)
    {
      zstring strval;
      item->getStringValue2(strval);

      emit_expanded_string(strval.c_str(), strval.size());
    }
    else
    {
      tr << item->getStringValue();  // no character expansion
    }

    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else if (item->getNodeKind() == store::StoreConsts::commentNode)
  {
    tr << "<!--" << item->getStringValue() << "-->";

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
    assert(0);
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  XHTML Emitter                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::xhtml_emitter::xhtml_emitter(
    serializer* the_serializer,
    transcoder& the_transcoder)
  :
  xml_emitter(the_serializer, the_transcoder)
{
}


/*******************************************************************************

********************************************************************************/
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

    // If a meta element has been added to the head element as described above
    //, then any existing meta element child of the head element having an
    // http-equiv attribute with the value "Content-Type" MUST be discarded.

    if (ser->include_content_type == PARAMETER_VALUE_YES &&
      element_parent != NULL &&
      is_content_type_meta(item, element_parent))
    {
      // do not emit this element
      return;
    }

    zstring nodename;
    item->getNodeName()->getStringValue2(nodename);

    tr << "<" << nodename;

    previous_item = PREVIOUS_ITEM_WAS_NODE;

    // If there is a head element, and the include-content-type parameter has
    // the value yes, the HTML output method MUST add a meta element as the
    // first child element of the head element specifying the character encoding
    // actually used.

    if (ser->include_content_type == PARAMETER_VALUE_YES)
    {
      if (strcasecmp(nodename.c_str(), "head") == 0)
      {
        tr << ">";
        if (ser->indent)
        {
          tr << ser->END_OF_LINE;
          emit_indentation(depth+1);
        }

        tr << "<meta http-equiv=\"content-type\" content=\""
           << ser->media_type << "; charset=";
        
        if (ser->encoding == PARAMETER_VALUE_UTF_8)
          tr << "UTF-8";
#ifndef ZORBA_NO_UNICODE
        else if (ser->encoding == PARAMETER_VALUE_UTF_16)
          tr << "UTF-16";
#endif
        tr << "\"/";
        //closed_parent_tag = 1;
      }
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
    {
      tr << "</" << nodename << ">";
    }
    else
    {
      if (is_html_empty_content_model_element(item))
        tr << " />";
      else
        tr << ">" << "</" << nodename << ">";
    }

    previous_item = PREVIOUS_ITEM_WAS_NODE;
  }
  else
  {
    xml_emitter::emit_node(item, depth);
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SAX2 Emitter                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::sax2_emitter::sax2_emitter(
  serializer* the_serializer,
  transcoder& the_transcoder,
  std::stringstream& aSStream,
  SAX2_ContentHandler * aSAX2ContentHandler )
  :
  emitter(the_serializer, the_transcoder),
  theSAX2ContentHandler( aSAX2ContentHandler ),
  theSAX2LexicalHandler( 0 ),
  theSStream(aSStream)
{
  theSAX2LexicalHandler = dynamic_cast< SAX2_LexicalHandler * >( aSAX2ContentHandler );
}


/*******************************************************************************

********************************************************************************/
void serializer::sax2_emitter::emit_declaration()
{
  theSAX2ContentHandler->startDocument();
}


/*******************************************************************************

********************************************************************************/
void serializer::sax2_emitter::emit_declaration_end()
{
  theSAX2ContentHandler->endDocument();
}


/*******************************************************************************

********************************************************************************/
bool serializer::sax2_emitter::emit_bindings(const store::Item * item)
{
  return false;
}


/*******************************************************************************

********************************************************************************/
int serializer::sax2_emitter::emit_node_children(
    const store::Item* item,
    int depth,
    bool perform_escaping)
{
  return emit_node_children( item, 0, false );
}


/*******************************************************************************

********************************************************************************/
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

/*******************************************************************************

********************************************************************************/
void serializer::sax2_emitter::emit_node(const store::Item* item, int depth)
{
  emit_node(item, 0);
}


/*******************************************************************************

********************************************************************************/
void serializer::sax2_emitter::emit_node(const store::Item* item)
{
  if( item->getNodeKind() == store::StoreConsts::documentNode )
  {
    emit_node_children(item);
  }
  else if (item->getNodeKind() == store::StoreConsts::elementNode)
  {
    store::NsBindings local_nsBindings;
    store::Item_t item_qname;
    unsigned long namespaces_emited = 0;
    store::NsBindings::size_type ns_size = 0;

    if (isFirstElementNode)
    {
      // TODO: emit doctype declaration
      // emit_doctype(qname->getLocalName());
      isFirstElementNode = false;
    }

    if (theSAX2ContentHandler)
    {
      item->getNamespaceBindings(local_nsBindings,
                                 store::StoreConsts::ONLY_LOCAL_NAMESPACES);

      SAX2AttributesImpl attrs(const_cast<store::Item*>(item));
      ns_size = local_nsBindings.size();
      std::vector<zstring>::size_type ans_size = theNameSpaces.size();
      for ( unsigned long i = 0; i < ns_size; i++ )
      {
        bool is_declared = false;
        for ( unsigned long j = 0; j < ans_size; j++ )
        {
          if (theNameSpaces[j].second == local_nsBindings[i].second && 
              theNameSpaces[j].first == local_nsBindings[i].first)
          {
            is_declared = true;
            break;
          }
        }

        if ( ! is_declared )
        {
          //aNSList.push_back(local_nsBindings[i].second);
          theNameSpaces.push_back(local_nsBindings[i]);

          String lFirst( Unmarshaller::newString( local_nsBindings[i].first )  );
          String lSecond( Unmarshaller::newString( local_nsBindings[i].second )  );
          theSAX2ContentHandler->startPrefixMapping( lFirst, lSecond );
          namespaces_emited++;
        }
      }

      //emit_startPrefixMapping( item, local_nsBindings );

      item_qname = item->getNodeName();
      String lNS( Unmarshaller::newString( item_qname->getNamespace() ) );
      String lLocalName( Unmarshaller::newString( item_qname->getLocalName() ) );
      String lStringValue( Unmarshaller::newString( item_qname->getStringValue() ) );
      theSAX2ContentHandler->startElement( lNS, lLocalName, lStringValue, attrs );
    }

    emit_node_children(item);

    if(theSAX2ContentHandler)
    {

      String lNS( Unmarshaller::newString( item_qname->getNamespace() ) );
      String lLocalName( Unmarshaller::newString( item_qname->getLocalName() ) );
      String lStringValue( Unmarshaller::newString( item_qname->getStringValue() ) );

      theSAX2ContentHandler->endElement( lNS, lLocalName, lStringValue );

      for ( unsigned long i = 0; i < namespaces_emited; i++ )
      {
        String lFirst( Unmarshaller::newString( theNameSpaces.back().first ) );
        theSAX2ContentHandler->endPrefixMapping( lFirst );
        theNameSpaces.resize(theNameSpaces.size()-1);
      }
      //emit_endPrefixMapping( local_nsBindings );
    }
  }
  else if (item->getNodeKind() == store::StoreConsts::textNode)
  {
    //TODO: if CDATA
    zstring strval;
    item->getStringValue2(strval);

    emit_expanded_string(strval.c_str(), strval.size());
    //TODO: if CDATA
  }
  else if (item->getNodeKind() == store::StoreConsts::commentNode)
  {
    if ( theSAX2LexicalHandler )
    {
      String lComment( Unmarshaller::newString( item->getStringValue() ) );
      theSAX2LexicalHandler->comment( lComment );
    }
  }
  else if (item->getNodeKind() == store::StoreConsts::piNode )
  {
    if(theSAX2ContentHandler)
    {
      String lTarget( item->getTarget().str() );
      String lStringValue( item->getStringValue().str() );
      theSAX2ContentHandler->processingInstruction( lTarget, lStringValue );
    }
  }
//TODO: unimplemented error handling
//      else
  //{
//              tr << "node of type: " << item->getNodeKind();
  //SAX2_ParseException   saxx("Unknown node type", &theLocator);
  //if(error_handler)
  //  error_handler->fatalError(saxx);
  //throw saxx;
  //}
}


/*******************************************************************************

********************************************************************************/
void serializer::sax2_emitter::emit_item(const store::Item* item)
{
  if (item->isAtomic())
  {
    zstring strval;
    item->getStringValue2(strval);

    emit_expanded_string(strval.c_str(), strval.size());
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
    {
      emit_node(item);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::sax2_emitter::emit_expanded_string(
  const char* str,
  zstring::size_type strlen,
  bool aEmitAttributeValue)
{
  if ( theSAX2ContentHandler )
  {
    //use xml_emitter to normalize string
    theSStream.str("");
    emitter::emit_expanded_string(str, strlen, aEmitAttributeValue );
    theSAX2ContentHandler->characters(theSStream.str());
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Text Emitter                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::text_emitter::text_emitter(
    serializer* the_serializer,
    transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{
}


/*******************************************************************************

********************************************************************************/
void serializer::text_emitter::emit_declaration()
{
}


/*******************************************************************************

********************************************************************************/
void serializer::text_emitter::emit_item(const store::Item* item)
{
  if (item->isAtomic())
  {
    if (previous_item == PREVIOUS_ITEM_WAS_TEXT)
      tr << " ";

    tr << item->getStringValue();

    previous_item = PREVIOUS_ITEM_WAS_TEXT;
  }
  else
  {
    if (item->getNodeKind() == store::StoreConsts::attributeNode)
    {
      ZORBA_ERROR_DESC_OSS(SENR0001,
                           "Attribute <" << item->getStringValue()
                           << "> can not be serialized.");
    }
    else
    {
      emit_node(item, 0);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::text_emitter::emit_node(const store::Item* item, int depth)
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
    tr << item->getStringValue();
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


/*******************************************************************************

********************************************************************************/
int serializer::text_emitter::emit_node_children(
  const store::Item* node,
  int depth,
  bool perform_escaping)
{
  store::Item* child;

  // output all the other nodes
  store::ChildrenIterator* iter = getChildIter();

  iter->init(node);
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


/*******************************************************************************

********************************************************************************/
serializer::json_emitter::json_emitter(
    serializer* the_serializer,
    transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{
}


/*******************************************************************************

********************************************************************************/
void serializer::json_emitter::emit_declaration()
{
}


/*******************************************************************************

********************************************************************************/
void serializer::json_emitter::emit_item(const store::Item* item)
{
  zstring result;
  zstring error_log;

  if(!item->isNode() || item->getNodeKind () != store::StoreConsts::elementNode)
  {
    ZORBA_ERROR_PARAM_OSS(API0062_CONV_JSON_PARAM,
                          item->getStringValue(),
                          "");
  }

  if (JSON_serialize(item, result, error_log))
  {
    tr << result;
  }
  else
  {
    ZORBA_ERROR_PARAM_OSS(API0061_CONV_JSON_SERIALIZE,
                          item->getStringValue(),
                          error_log);
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  JsonML Emitter                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::jsonml_emitter::jsonml_emitter(
    serializer* the_serializer,
    transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{
}


/*******************************************************************************

********************************************************************************/
void serializer::jsonml_emitter::emit_declaration()
{
}


/*******************************************************************************

********************************************************************************/
void serializer::jsonml_emitter::emit_item(const store::Item* item)
{
  zstring result;
  zstring error_log;

  if(!item->isNode() || item->getNodeKind () != store::StoreConsts::elementNode)
  {
    ZORBA_ERROR_PARAM_OSS(API0065_CONV_JSON_ML_PARAM,
                          item->getStringValue(),
                          "");
  }

  if (JSON_ML_serialize(item, result, error_log))
  {
    tr << result;
  }
  else
  {
    ZORBA_ERROR_PARAM_OSS(API0064_CONV_JSON_ML_SERIALIZE,
                          item->getStringValue(),
                          error_log);
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  binary emitter                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::binary_emitter::binary_emitter(
    serializer* the_serializer,
    transcoder& the_transcoder)
  :
  emitter(the_serializer, the_transcoder)
{
}


/*******************************************************************************

********************************************************************************/
void serializer::binary_emitter::emit_item(const store::Item* item)
{
  xs_base64Binary lValue;

  // First assume the item is a base64Binary item and try to get its value.
  try 
  {
    lValue = item->getBase64BinaryValue();
  }
  catch (...)
  {
    // If this fails, then just get the string value of the item and convert
    // it to base64
    zstring lStringValue;
    item->getStringValue2(lStringValue);
    Base64::encode(lStringValue, lValue);
  }

  std::vector<char> lDecodedData;
  lValue.decode(lDecodedData);

  for (std::vector<char>::const_iterator lIter = lDecodedData.begin();
       lIter != lDecodedData.end();
       ++lIter) 
  {
    tr << *lIter;
  }
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Serializer                                                                //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

const char serializer::END_OF_LINE = '\n';


/*******************************************************************************

********************************************************************************/
serializer::serializer(error::ErrorManager* aErrorManager)
  :
  theErrorManager(aErrorManager)
{
  reset();
}


/*******************************************************************************

********************************************************************************/
serializer::~serializer()
{
}


/*******************************************************************************

********************************************************************************/
void serializer::reset()
{
  byte_order_mark = PARAMETER_VALUE_NO;

  cdata_section_elements.clear();

  doctype_system.clear();
  doctype_public.clear();

  encoding = PARAMETER_VALUE_UTF_8;

  include_content_type = PARAMETER_VALUE_NO;

  media_type.clear();

  method = PARAMETER_VALUE_XML;

  normalization_form.clear();

  omit_xml_declaration = PARAMETER_VALUE_NO;

  standalone = PARAMETER_VALUE_OMIT;

  undeclare_prefixes = PARAMETER_VALUE_NO;

  version = "1.0";
  version_has_default_value = true;

  indent = PARAMETER_VALUE_NO;
}


/*******************************************************************************

********************************************************************************/
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
      ZORBA_ERROR_DESC_OSS(SEPM0016,
                           "Parameter <" << aName
                           << "> can not be set with value <" << aValue
                           <<">. Accepted values are UTF-8/UTF-16.");
    }
  }
  else if (!strcmp(aName, "media-type"))
  {
    media_type = aValue;
  }
  else if (!strcmp(aName, "version"))
  {
    version = aValue;
    version_has_default_value = false;
  }
  else if (!strcmp(aName, "doctype-system"))
  {
    doctype_system = aValue;
  }
  else if (!strcmp(aName, "doctype-public"))
  {
    doctype_public = aValue;
  }
  else if (!strcmp(aName, "cdata-section-elements"))
  {
    cdata_section_elements = aValue;
  }
  else
  {
    ZORBA_ERROR_DESC_OSS(SEPM0016,
                         "Parameter <" << aName
                         << "> can not be set with value <" << aValue <<">.");
  }
}


/*******************************************************************************

********************************************************************************/
short int serializer::getSerializationMethod() const 
{
  return method;
}


/*******************************************************************************

********************************************************************************/
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
      version = "4.0";
    else if ( !(equals(version, "4.0", 3) || equals(version, "4.01", 4)) )
    {
      // Only HTML versions 4.0 and 4.01 are supported
      ZORBA_ERROR_DESC(SESU0013, 
                       "Unsupported HTML serialization version. Accepted values are 4.0/4.01 .");
    }
  }
}


/*******************************************************************************

********************************************************************************/
bool serializer::setup(std::ostream& os)
{
  if (encoding == PARAMETER_VALUE_UTF_8)
  {
    tr = new transcoder(os, false);
  }
#ifndef ZORBA_NO_UNICODE
  else if (encoding == PARAMETER_VALUE_UTF_16)
  {
    tr = new transcoder(os, true);
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

  if (!cdata_section_elements.empty())
  {
    tokenize(cdata_section_elements.c_str(),
             cdata_section_elements.size(),
             "; ",
             2,
             cdata_section_elements_tokens);
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
void serializer::serialize(
    intern::Serializable* aObject,
    std::ostream& aOStream)
{
  serialize(aObject, aOStream, 0);
}


/*******************************************************************************

********************************************************************************/
void serializer::serialize(
    intern::Serializable* aObject,
    std::ostream&         aOStream,
    SAX2_ContentHandler* aHandler)
{
  std::stringstream temp_sstream; // used to temporarily hold expanded strings

  // used for JSON serialization only
  bool firstItem = true;

  validate_parameters();

  if (!setup(aOStream)) 
  {
    return;
  }

  // in case we use SAX event notifications
  if (aHandler) 
  {
    // only allow XML-based methods for SAX notifications
    if (method != PARAMETER_VALUE_XML &&
      method != PARAMETER_VALUE_XHTML &&
      method != PARAMETER_VALUE_JSONML) 
    {
      ZORBA_ERROR(API0070_INVALID_SERIALIZATION_METHOD_FOR_SAX);
    }
    // it's OK now, build a SAX emmiter  
    tr = new transcoder(temp_sstream, false);
    e = new sax2_emitter(this, *tr, temp_sstream, aHandler);
  }

  e->emit_declaration();

  store::Item_t lItem;
  while (aObject->nextSerializableItem(lItem)) 
  {
    // JSON serialization only alows one single item to be serialized
    // so throw an error if we get to a second item
    if (!firstItem && (
        method == PARAMETER_VALUE_JSON ||
        method == PARAMETER_VALUE_JSONML)) 
    {
      ZORBA_ERROR(API0066_JSON_SEQUENCE_CANNOT_BE_SERIALIZED);
    }

    // PUL's cannot be serialized
    if (lItem->isPul()) 
    {
      ZORBA_ERROR(API0007_CANNOT_SERIALIZE_PUL);
    }

    e->emit_item(&*lItem);

    // used for JSON serialization only
    firstItem = false;
  }

  e->emit_declaration_end();
}


/*******************************************************************************

********************************************************************************/
void serializer::serialize(
    intern::Serializable* object,
    std::ostream& stream,
    itemHandler aHandler,
    void* aHandlerData)
{
  store::Item_t lItem;
  if (object->nextSerializableItem(lItem)) 
  {
    // first, we notify the caller, that everything that we wanted to 
    // (e.g. computed by side-effecting scripting functions is now available).
    //  He can, for example, decide on the serialization method
    Zorba_SerializerOptions_t* lSerParams = aHandler(aHandlerData);
    if (lSerParams) 
    {
      SerializerImpl::setSerializationParameters(*this, *lSerParams);
    }
  }
  else
  {
    return;
  }

  validate_parameters();

  if (!setup(stream)) 
  {
    return;
  }

  e->emit_declaration();

  // used for Json and JsonML serialization only
  bool firstItem = true;

  do 
  {
    if (!firstItem) 
    {
      Zorba_SerializerOptions_t* lSerParams = aHandler(aHandlerData);
      if (lSerParams) 
      {
        SerializerImpl::setSerializationParameters(*this, *lSerParams);
        if (!setup(stream)) 
        {
          return;
        }
      }
        
      // JSON serialization only alows one single item to be serialized
      // so throw an error if we get to a second item
      if (method == PARAMETER_VALUE_JSON ||
          method == PARAMETER_VALUE_JSONML) 
      {
        ZORBA_ERROR(API0066_JSON_SEQUENCE_CANNOT_BE_SERIALIZED);
      }
    }

    // PUL's cannot be serialized
    if (lItem->isPul()) 
    {
      ZORBA_ERROR(API0007_CANNOT_SERIALIZE_PUL);
    }

    e->emit_item(&*lItem);

    // used for Json and JsonML serialization only
    firstItem = false;
  }
  while (object->nextSerializableItem(lItem));

  e->emit_declaration_end();
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
