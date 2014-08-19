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
#include "stdafx.h"

#include <sstream>
#include <iomanip>

#include <zorba/zorba_string.h>
#include <zorba/util/transcode_stream.h>

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"

#include "api/serialization/serializer.h"
#include "api/serialization/serializable.h"
#include "api/sax2impl.h"
#include "api/serializerimpl.h"
#include "api/unmarshaller.h"

#include "util/ascii_util.h"
#include "util/json_util.h"
#include "util/string_util.h"
#include "util/unicode_util.h"
#include "util/utf8_util.h"
#include "util/xml_util.h"

#include "system/globalenv.h"

#include "zorbamisc/ns_consts.h"

#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"

#include "context/static_context.h"

#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/copymode.h"

namespace zorba {

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
serializer::emitter::emitter(
    serializer* the_serializer, 
    std::ostream& the_stream,
    bool aEmitAttributes)
  :
  ser(the_serializer),
  tr(the_stream),
  thePreviousItemKind(INVALID_ITEM),
  theChildIters(8),
  theFirstFreeChildIter(0),
  theIsFirstElementNode(true),
  theEmitAttributes(aEmitAttributes)
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
int serializer::emitter::emit_expanded_string(
  const char* str,
  zstring::size_type strlen,
  bool emit_attribute_value = false)
{
  const unsigned char* chars = (const unsigned char*)str;
  const unsigned char* chars_end  = chars + strlen;

  for (; chars < chars_end; chars++ )
  {

    // the input string is UTF-8
    int char_length;
    try
    {
      char_length = utf8::char_length(*chars);
    }
    catch ( utf8::invalid_byte const& )
    {
      char_length = 1;
    }

    if (char_length > chars_end - chars)
      return chars_end - chars;

    if (char_length > 1)
    {
      const unsigned char* temp = chars;
      unicode::code_point cp = utf8::next_char(temp);

      // raise an error iff (1) the serialization format is XML 1.0 and 
      // (2) the given character is an invalid XML 1.0 character
      if (ser &&
          ser->method == PARAMETER_VALUE_XML &&
          ser->version == PARAMETER_VALUE_VERSION_1_0 &&
          !xml::is_valid(cp))
      {
        throw XQUERY_EXCEPTION( err::FOCH0001, ERROR_PARAMS( cp ) );
      }

      if (cp >= 0x10000 && cp <= 0x10FFFF)
      {
        ascii::itoa_buf_type cp_buf;
        tr << "&#" << ascii::itoa(cp, cp_buf) << ';';
        chars += (char_length-1);
      }
      else
      {
        while (char_length)
        {
          tr << *chars;
          if (char_length > 1)
            chars++;
          char_length--;
        }
      }

      continue;
    }

    // raise an error iff (1) the serialization format is XML 1.0 and (2) the given character is an invalid XML 1.0 character
    if (ser && ser->method == PARAMETER_VALUE_XML &&
        ser->version == PARAMETER_VALUE_VERSION_1_0 && !xml::is_valid(static_cast<unsigned>(*chars)))
      throw XQUERY_EXCEPTION(
        err::XQST0090,
        ERROR_PARAMS( static_cast<unsigned>( *chars ), xml::v1_0 )
      );

    /*
      Certain characters, specifically the control characters #x7F-#x9F, are
      legal in XML but not in HTML. It is a serialization error
      [err:SERE0014] to use the HTML output method when such characters appear
      in the instance of the data model.
    */
    if (ser && ser->method == PARAMETER_VALUE_HTML && *chars >= 0x7F && *chars <= 0x9f)
      throw ZORBA_EXCEPTION( err::SERE0014, ERROR_PARAMS( *chars ) );

    /*
      In addition, the non-whitespace control characters #x1 through #x1F and
      #x7F through #x9F in text nodes and attribute nodes MUST be output as
      character references.
    */
    if ((*chars >= 0x01 && *chars <= 0x1F)
          ||
        (*chars >= 0x7F && *chars <= 0x9F))
    {
      if ((!emit_attribute_value) && (*chars == 0xA || *chars == 0x9))
      {
        tr << *chars;
      }
      else
      {
        char buf[3];
        zorba::xml::toHexString(*chars, buf);
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
    } // switch
  } // for

  return 0;
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
  if ( ser->byte_order_mark == PARAMETER_VALUE_YES )
  {
    std::streambuf *const orig_buf = transcode::orig_streambuf( tr );
    if ( ser->encoding == "UTF-8" )
      orig_buf->sputn( utf8::BOM, sizeof utf8::BOM );
    else if ( ser->encoding == "UTF-16" )
      orig_buf->sputn( (char const*)&unicode::BOM, sizeof unicode::BOM );
    else if ( ser->encoding == "UTF-16LE" )
      orig_buf->sputn( (char const*)&unicode::BOM_LE, sizeof unicode::BOM_LE );
    else if ( ser->encoding == "UTF-16BE" )
      orig_buf->sputn( (char const*)&unicode::BOM_BE, sizeof unicode::BOM_BE );
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_end()
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
void serializer::emitter::emit_streamable_item(store::Item* item)
{
  // Streamable item
  store::SchemaTypeCode lTypeCode = item->getTypeCode();

  switch (lTypeCode)
  {
  case store::XS_STRING:
  {
    char buffer[1024];
    int rollover = 0;
    std::streambuf *  pbuf;
    std::streamsize   read_bytes;
    std::istream& is = item->getStream();

    // read bytes and do string expansion
    do
    {
      // std::istream::read uses a try/catch internally so the Zorba_Exception
      // is lost: that is why we are using std::streambuf::sgetn
      pbuf = is.rdbuf();

      read_bytes = pbuf->sgetn(buffer + rollover, 1024 - rollover);

      rollover = emit_expanded_string(buffer, static_cast<zstring::size_type>(read_bytes + rollover));
      memmove(buffer, buffer + 1024 - rollover, rollover);
    } while (read_bytes > 0);
    break;
  }
  case store::XS_BASE64BINARY:
  {
    if (item->isEncoded())
    {
      std::istream& is = item->getStream();
      char buf[1024];
      while (is.good())
      {
        is.read(buf, 1024);
        tr.write(buf, is.gcount());
      }
    }
    else
    {
      tr << item->getStringValue();
    }
    break;
  }
  default: assert(false);
  }

}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_item(store::Item* item)
{
  if (item->isAtomic())
  {
    if (thePreviousItemKind == PREVIOUS_ITEM_WAS_TEXT)
      tr << (ser->item_separator_is_set ? ser->item_separator : " ");
    else if (thePreviousItemKind)
      tr << ser->item_separator;

    if (item->isStreamable())
    {
      emit_streamable_item(item);
    }
    else
    {
      zstring strval;
      item->getStringValue2(strval);
      emit_expanded_string(strval.c_str(), strval.size());
    }

    thePreviousItemKind = PREVIOUS_ITEM_WAS_TEXT;
  }
  else if (item->isNode())
  {
    if (!theEmitAttributes &&
        item->getNodeKind() == store::StoreConsts::attributeNode)
    {
      throw ZORBA_EXCEPTION(err::SENR0001,
      ERROR_PARAMS(item->getStringValue(), ZED(SENR0001_AttributeNode)));
    }
    emit_node(item, 0);
  }
  else if (item->isObject() || item->isArray())
  {
    zstring lMethod;
    ser->getSerializationMethod(lMethod);

    throw ZORBA_EXCEPTION(jerr::JNSE0022,
    ERROR_PARAMS(lMethod, item->getType()->getStringValue()));
  }
  else if (item->isFunction())
  {
    throw ZORBA_EXCEPTION(err::SENR0001,
    ERROR_PARAMS(item->show(), "function item node"));
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::emitter::emit_node(const store::Item* item, int depth)
{
  if (thePreviousItemKind)
    tr << ser->item_separator;
  switch (item->getNodeKind())
  {
  case store::StoreConsts::documentNode:
  {
    emit_node_children(item, depth);

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    break;
  }
  case store::StoreConsts::elementNode:
  {
    store::Item* qnameItem = item->getNodeName();
    const zstring& prefix = qnameItem->getPrefix();
    const zstring& local = qnameItem->getLocalName();

    if (theIsFirstElementNode)
    {
      emit_doctype(local);
      theIsFirstElementNode = false;
    }
    else if (ser->indent && depth == 0)
    {
      tr << ser->END_OF_LINE;
    }

    if (prefix.empty())
      tr << "<" << local;
    else
      tr << "<" << prefix << ":" << local;

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    bool should_remove_binding = emit_bindings(item, depth);

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

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    break;
  }
  case store::StoreConsts::attributeNode:
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

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    break;
  }
  case store::StoreConsts::textNode:
  {
    zstring text;
    item->getStringValue2(text);

    emit_text_node(item, text);

    // Put a space between consecutive text nodes (or a text node and an
    // atomic item), unless the text node contains whitespace only.
    if (!ascii::is_space(text.c_str()))
    {
      thePreviousItemKind = PREVIOUS_ITEM_WAS_TEXT;
    }
    else
    {
      thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
    }

    break;
  }
  case store::StoreConsts::commentNode:
  {
    tr << "<!--" << item->getStringValue() << "-->";
    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    break;
  }
  case store::StoreConsts::piNode:
  {
    tr << "<?" << item->getTarget() << " " << item->getStringValue() << "?>";

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    break;
  }
  case store::StoreConsts::namespaceNode:
  {
    throw ZORBA_EXCEPTION(err::SENR0001,
    ERROR_PARAMS(item->getStringValue(), ZED(SENR0001_NamespaceNode)));
    break;
  }
  default:
  {
    int k = static_cast<int>(item->getNodeKind());
    ZORBA_ASSERT_WITH_MSG(false, BUILD_STRING("node of type: ", k));
  }
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

    if (ser->indent
        &&
        (prev_node_kind != store::StoreConsts::textNode)
        &&
        (child->getNodeKind() == store::StoreConsts::elementNode
          ||
          child->getNodeKind() == store::StoreConsts::commentNode))
    {
      if (depth > 0)
        tr << ser->END_OF_LINE;

      emit_indentation(depth);
    }

    // Ignore whitespace text nodes when doing indentation
    if (!ser->indent ||
        child->getNodeKind() != store::StoreConsts::textNode ||
        !ascii::is_space(child->getStringValue().c_str()))
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
bool serializer::emitter::emit_bindings(const store::Item* item, int depth)
{
  store::NsBindings nsBindings;

  if (depth == 0)
  {
    item->getNamespaceBindings(nsBindings);
  }
  else
  {
    item->getNamespaceBindings(nsBindings);

    store::Item* nodeName = item->getNodeName();
    const zstring& prefix = nodeName->getPrefix();
    const zstring& nsuri = nodeName->getNamespace();
    if (prefix.empty() && nsuri.empty())
    {
      store::NsBindings::const_iterator ite = nsBindings.begin();
      store::NsBindings::const_iterator end = nsBindings.end();

      for (; ite != end; ++ite)
      {
        if (ite->second.empty() && ite->first.empty())
          break;
      }

      if (ite == end)
        nsBindings.push_back(std::pair<zstring, zstring>(prefix, nsuri));
    }
  }

  csize numBindings = nsBindings.size();

  for (csize i = 0; i < numBindings; ++i)
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
            tr << " xmlns:" <<  nsBindings[i].first << "=\"\"";
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
  for (csize i = 0; i < theBindings.size(); ++i)
  {
    const store::NsBindings& nsBindings = theBindings[i];

    for (csize j = 0; j < nsBindings.size(); ++j)
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
  for (csize i = 0; i < theBindings.size(); ++i)
  {
    const store::NsBindings& nsBindings = theBindings[i];

    for (csize j = 0; j < nsBindings.size(); ++j)
    {
      if (nsBindings[j].first == pre)
        return true;
    }
  }

  return false;
}



////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  XML emitter                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::xml_emitter::xml_emitter(
  serializer* the_serializer,
  std::ostream& the_stream,
  bool aEmitAttributes)
  :
  emitter(the_serializer, the_stream, aEmitAttributes)
{
  ser->attach_transcoder( the_stream );
}


/*******************************************************************************

********************************************************************************/
void serializer::xml_emitter::emit_declaration()
{
  emitter::emit_declaration();

  if (ser->omit_xml_declaration == PARAMETER_VALUE_NO)
  {
    tr << "<?xml version=\"" << ser->version_string << '"';
    if ( !ser->encoding.empty() )
      tr << " encoding=\"" << ser->encoding << '"';

    if (ser->standalone != PARAMETER_VALUE_OMIT) {
      tr << " standalone=\"";

      if (ser->standalone == PARAMETER_VALUE_YES) {
        tr << "yes";
      } else {
        tr << "no";
      }

      tr << "\"";
    }
    tr << "?>";

    // Always output a newline after the XML declaration, although it's not a very good idea
    tr << END_OF_LINE;
  }
  // the err:SEPM0009 error is handled in the serializer::validate_parameters() method
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
//  JSON emitter - as defined by JSONiq spec                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

serializer::json_emitter::json_emitter(
  serializer* the_serializer,
  std::ostream& the_stream)
  : emitter(the_serializer, the_stream),
    theMultipleItems(false)
{
}

serializer::json_emitter::~json_emitter()
{
}

void serializer::json_emitter::emit_item(store::Item *item)
{
  // This is called by serializer for each top-level item. Therefore it's the
  // right place to check for multiple items in the sequence.
  if (theMultipleItems && ser->jsoniq_multiple_items == PARAMETER_VALUE_NO)
  {
    throw ZORBA_EXCEPTION(jerr::JNSE0012);
  }
  emit_json_item(item, 0);
  theMultipleItems = true;
}

void serializer::json_emitter::emit_declaration()
{
}

void serializer::json_emitter::emit_end()
{
}

void serializer::json_emitter::emit_json_item(store::Item* item, int depth)
{
  // This is called for any item within a JSON array or object, or for a
  // top-level item. JSON rules for simple types apply here.
  if (item->isObject())
  {
    emit_json_object(item, depth);

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->isArray())
  {
    emit_json_array(item, depth);

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->isAtomic())
  {
    store::SchemaTypeCode type = item->getTypeCode();
    switch (type)
    {
    case store::XS_STRING:
      emit_json_string(item->getStringValue());
      break;

    case store::XS_DOUBLE:
    case store::XS_FLOAT:
      if (item->isNaN())
      {
        emit_json_string("NaN");
        break;
      }
      else if (item->isPosOrNegInf())
      {
        // QQQ with Cloudscript, this is supposed to be INF or -INF - how can
        // I tell which I have?
        emit_json_string("INF");
        break;
      }
      // else fall through
    case store::XS_INTEGER:
    case store::XS_DECIMAL:
    case store::XS_NON_POSITIVE_INTEGER:
    case store::XS_NEGATIVE_INTEGER:
    case store::XS_LONG:
    case store::XS_INT:
    case store::XS_SHORT:
    case store::XS_BYTE:
    case store::XS_NON_NEGATIVE_INTEGER:
    case store::XS_UNSIGNED_LONG:
    case store::XS_UNSIGNED_INT:
    case store::XS_UNSIGNED_SHORT:
    case store::XS_UNSIGNED_BYTE:
    case store::XS_POSITIVE_INTEGER:
      // All numerics get serialized the same way
      tr << item->getStringValue();
      break;

    case store::XS_BOOLEAN:
      tr << (item->getBooleanValue() ? "true" : "false");
      break;

    case store::JS_NULL:
      tr << "null";
      break;

    default:
    {
      emit_json_string(item->getStringValue());
      break;
    }
    }
  }
  else
  {
    emit_jsoniq_xdm_node(item, depth);
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::json_emitter::emit_json_object(store::Item* obj, int depth)
{
  store::Item_t key;
  store::Iterator_t it = obj->getObjectKeys();
  it->open();
  bool first = true;

  if (ser->indent)
  {
    tr << "{" << ser->END_OF_LINE;
  }
  else
  {
    tr << "{ ";
  }

  depth++;

  while (it->next(key))
  {
    if (first)
    {
      first = false;
    }
    else
    {
      tr << ", ";
      if (ser->indent)
      {
        tr << ser->END_OF_LINE;
      }
    }

    if (ser->indent)
    {
      emit_indentation(depth);
    }

    emit_json_item(key, depth);
    tr << " : ";
    emit_json_item(obj->getObjectValue(key).getp(), depth);
  }

  if (ser->indent)
  {
    tr << ser->END_OF_LINE;
    emit_indentation(depth-1);
    tr << "}";
  }
  else
  {
    tr << " }";
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::json_emitter::emit_json_array(store::Item* array, int depth)
{
  xs_integer size = array->getArraySize();
  tr << "[ ";
  for (xs_integer i = xs_integer(1); i <= size; ++i)
  {
    if (i != 1) {
      tr << ", ";
    }
    store::Item_t position;
    GENV_ITEMFACTORY->createInteger(position, i);
    emit_json_item(array->getArrayValue(position->getIntegerValue()).getp(), depth);
  }
  tr << " ]";
}

/*******************************************************************************

********************************************************************************/
void serializer::json_emitter::emit_jsoniq_xdm_node(store::Item*, int)
{
  throw ZORBA_EXCEPTION(jerr::JNSE0014);
}


/*******************************************************************************

********************************************************************************/
void serializer::json_emitter::emit_json_string(zstring const &string)
{
  tr << '"' << json::serialize( string ) << '"';
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  hybrid emitter (auto-detects JSON or XML)                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

serializer::hybrid_emitter::hybrid_emitter(
  serializer* the_serializer,
  std::ostream& the_stream,
  bool aEmitAttributes)
  : json_emitter(the_serializer, the_stream),
    theEmitterState(JESTATE_UNDETERMINED),
    theXMLEmitter(new xml_emitter(the_serializer, the_stream, aEmitAttributes)),
    theNestedXMLStringStream(nullptr)
{
}

serializer::hybrid_emitter::~hybrid_emitter()
{
  delete theNestedXMLStringStream;
  delete theXMLEmitter;
}

void serializer::hybrid_emitter::emit_declaration()
{
}

void serializer::hybrid_emitter::emit_item(store::Item *item)
{
  if (item->isJSONItem())
  {
    theEmitterState = JESTATE_JDM;
    json_emitter::emit_item(item);
    theXMLEmitter->setPreviousItemKind(thePreviousItemKind);
  }
  else
  {
    if (theEmitterState == JESTATE_UNDETERMINED)
    {
      theXMLEmitter->emit_declaration();
    }
    theEmitterState = JESTATE_XDM;
    theXMLEmitter->emit_item(item);
    thePreviousItemKind = theXMLEmitter->getPreviousItemKind();
  }
}

void serializer::hybrid_emitter::emit_end()
{
  switch(theEmitterState)
  {
    case JESTATE_JDM:
      json_emitter::emit_end();
      return;
    case JESTATE_XDM:
    default:
      theXMLEmitter->emit_end();
  }
}

void serializer::hybrid_emitter::emit_jsoniq_xdm_node(
    store::Item* item,
    int)
{
  if (! theNestedXMLEmitter)
  {
    theNestedXMLStringStream = new std::stringstream();
    ser->attach_transcoder(*theNestedXMLStringStream);
    theNestedXMLEmitter
        = new serializer::xml_emitter(ser, *theNestedXMLStringStream);
  }
  theNestedXMLEmitter->emit_item(item);
  zstring xml(theNestedXMLStringStream->str());
  theNestedXMLStringStream->str("");

  emit_json_string(xml);
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

  if (ztd::equals(pname, "head", 4) && ztd::equals(iname, "meta", 4))
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

      if (ztd::equals(cname, "http-equiv", 10) &&
          ztd::equals(cvalue, "content-type", 12))
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

  if (ztd::equals(nodename, "area", 4) ||
      ztd::equals(nodename, "base", 4) ||
      ztd::equals(nodename, "basefont", 8) ||
      ztd::equals(nodename, "br", 2) ||
      ztd::equals(nodename, "col", 3) ||
      ztd::equals(nodename, "frame", 5) ||
      ztd::equals(nodename, "hr", 2) ||
      ztd::equals(nodename, "img", 3) ||
      ztd::equals(nodename, "input", 5) ||
      ztd::equals(nodename, "isindex", 7) ||
      ztd::equals(nodename, "link", 4) ||
      ztd::equals(nodename, "meta", 4) ||
      ztd::equals(nodename, "param", 5))
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

  if (ztd::equals(str, "compact", 7) ||
      ztd::equals(str, "nowrap", 6) ||
      ztd::equals(str, "ismap", 5) ||
      ztd::equals(str, "declare", 7) ||
      ztd::equals(str, "noshade", 7) ||
      ztd::equals(str, "checked", 7) ||
      ztd::equals(str, "disabled", 8) ||
      ztd::equals(str, "readonly", 8) ||
      ztd::equals(str, "multiple", 8) ||
      ztd::equals(str, "selected", 8) ||
      ztd::equals(str, "noresize", 8) ||
      ztd::equals(str, "defer", 5))
    return true;
  else
    return false;
}


/*******************************************************************************

********************************************************************************/
serializer::html_emitter::html_emitter(
  serializer* the_serializer,
  std::ostream& the_stream)
  :
  emitter(the_serializer, the_stream)
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
void serializer::html_emitter::emit_end()
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

  store::NodeKind kind = item->getNodeKind();

  switch (kind)
  {
  case store::StoreConsts::documentNode:
  {
    emit_node_children(item, depth);
    break;
  }
  case store::StoreConsts::elementNode:
  {
    store::Item* qnameItem = item->getNodeName();

    zstring qname;
    qnameItem->getStringValue2(qname);

    unsigned closed_parent_tag = 0;

    if (theIsFirstElementNode)
    {
      emit_doctype(qname);
      theIsFirstElementNode = false;
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

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    bool should_remove_binding = emit_bindings(item, depth);

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
         << ser->media_type << '"';
      if ( !ser->encoding.empty() )
        tr << "\" charset=\"" << ser->encoding << '"';
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
      // The HTML 4.01 and XQuery Serialization specs strongly imply that
      // ALL empty elements must be serialized as either a matched open-
      // close tag, or (only for elements with an empty content model) as
      // an unclosed open tag.
      if (is_html_empty_content_model_element(item))
      {
        tr << ">";
      }
      else
      {
        tr << "></" << qname << ">";
      }
    }

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    break;
  }
  case store::StoreConsts::attributeNode:
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

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    break;
  }
  case store::StoreConsts::textNode:
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

    thePreviousItemKind = PREVIOUS_ITEM_WAS_TEXT;
    break;
  }
  case store::StoreConsts::commentNode:
  {
    tr << "<!--" << item->getStringValue() << "-->";

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
    break;
  }
  case store::StoreConsts::piNode:
  {
    tr << "<?" << item->getTarget() << " " << item->getStringValue() << "?>";

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
    break;
  }
  default:
  {
    int k = static_cast<int>(kind);
    ZORBA_ASSERT_WITH_MSG(false, BUILD_STRING("node of type: ", k));
  }
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
    std::ostream& the_stream)
  :
  xml_emitter(the_serializer, the_stream)
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

    if (theIsFirstElementNode)
    {
      emit_doctype(item->getNodeName()->getStringValue());
      theIsFirstElementNode = false;
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

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

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
           << ser->media_type << '"';
        if ( !ser->encoding.empty() )
          tr << "\" charset=\"" << ser->encoding << '"';
        //closed_parent_tag = 1;
      }
    }

    bool should_remove_binding = emit_bindings(item, depth);

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

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
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
  std::ostream& the_stream,
  std::stringstream& aSStream,
  SAX2_ContentHandler * aSAX2ContentHandler )
  :
  emitter(the_serializer, the_stream),
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
void serializer::sax2_emitter::emit_end()
{
  theSAX2ContentHandler->endDocument();
}


/*******************************************************************************

********************************************************************************/
bool serializer::sax2_emitter::emit_bindings(const store::Item * item, int)
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

    if (theIsFirstElementNode)
    {
      // TODO: emit doctype declaration
      // emit_doctype(qname->getLocalName());
      theIsFirstElementNode = false;
    }

    if (theSAX2ContentHandler)
    {
      item->getNamespaceBindings(local_nsBindings,
                                 store::StoreConsts::ONLY_LOCAL_BINDINGS);

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
void serializer::sax2_emitter::emit_item(store::Item* item)
{
  if (item->isAtomic())
  {
    zstring strval;
    item->getStringValue2(strval);

    emit_expanded_string(strval.c_str(), strval.size());
  }
  else if (item->getNodeKind() == store::StoreConsts::attributeNode)
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


/*******************************************************************************

********************************************************************************/
int serializer::sax2_emitter::emit_expanded_string(
  const char* str,
  zstring::size_type strlen,
  bool aEmitAttributeValue)
{
  int result = 0;

  if ( theSAX2ContentHandler )
  {
    // use xml_emitter to normalize string
    theSStream.str("");
    result = emitter::emit_expanded_string(str, strlen, aEmitAttributeValue );
    theSAX2ContentHandler->characters(theSStream.str());
  }

  return result;
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
    std::ostream& the_stream)
  :
  emitter(the_serializer, the_stream)
{
  ser->attach_transcoder( the_stream );
}


/*******************************************************************************

********************************************************************************/
void serializer::text_emitter::emit_declaration()
{
}


/*******************************************************************************

********************************************************************************/
void serializer::text_emitter::emit_streamable_item(store::Item* item)
{
  // Streamable item
  char buffer[1024];
  std::streambuf *  pbuf;
  std::streamsize   read_bytes;
  std::istream& is = item->getStream();
  std::streampos pos;
  std::ios::iostate const old_exceptions = is.exceptions();

  if (item->isSeekable())
  {
    // prepare the stream
    is.exceptions( std::ios::badbit | std::ios::failbit );
    pos = is.tellg();
    if (pos)
      is.seekg(0, std::ios::beg);
    is.exceptions(is.exceptions() & ~std::ios::failbit);
  }

  // read bytes and do string expansion
  do
  {
    //std::istream::read uses a try/catch internally so the Zorba_Exception is lost: that is why we are using std::streambuf::sgetn
    pbuf = is.rdbuf();
    read_bytes = pbuf->sgetn(buffer, 1024);
    tr.write(buffer, read_bytes);
  }
  while (read_bytes > 0);

  // restore stream's state
  is.clear();                   // clear eofbit
  if (item->isSeekable())
  {
    if (pos)
    {
      is.exceptions(is.exceptions() | std::ios::failbit);
      is.seekg(pos, std::ios::beg);
    }
    is.exceptions(old_exceptions);
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::text_emitter::emit_item(store::Item* item)
{
  if (item->isJSONItem())
  {
    throw ZORBA_EXCEPTION(jerr::JNSE0022,
    ERROR_PARAMS("text", item->getType()->getStringValue()));
  }

  if (item->isAtomic())
  {
    if (thePreviousItemKind == PREVIOUS_ITEM_WAS_TEXT)
      tr << (ser->item_separator_is_set ? ser->item_separator : " ");
    else if (thePreviousItemKind)
      tr << ser->item_separator;

    if (item->isStreamable())
      emit_streamable_item(item);
    else
      tr << item->getStringValue();

    thePreviousItemKind = PREVIOUS_ITEM_WAS_TEXT;
  }
  else if (item->getNodeKind() == store::StoreConsts::attributeNode)
  {
    throw ZORBA_EXCEPTION(err::SENR0001,
    ERROR_PARAMS(item->getStringValue(), ZED(SENR0001_AttributeNode)));
  }
  else
  {
    emit_node(item, 0);
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
    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;

    emit_node_children(item, depth);

    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::attributeNode )
  {
    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::textNode)
  {
    tr << item->getStringValue();
    thePreviousItemKind = PREVIOUS_ITEM_WAS_TEXT;
  }
  else if (item->getNodeKind() == store::StoreConsts::commentNode)
  {
    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
  }
  else if (item->getNodeKind() == store::StoreConsts::piNode )
  {
    thePreviousItemKind = PREVIOUS_ITEM_WAS_NODE;
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
//  binary emitter                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
serializer::binary_emitter::binary_emitter(
    serializer* the_serializer,
    std::ostream& the_stream)
  :
  emitter(the_serializer, the_stream)
{
}


/*******************************************************************************

********************************************************************************/
void serializer::binary_emitter::emit_item(store::Item* item)
{
  if (item->isJSONItem())
  {
    throw ZORBA_EXCEPTION(
        jerr::JNSE0022,
        ERROR_PARAMS("binary", item->getType()->getStringValue())
      );
  }

  if (item->isStreamable())
  {
    std::istream& stream = item->getStream();
    if (item->isEncoded())
    {
      zstring decoded;
      Base64::decode(stream, &decoded);
      tr << decoded;
    }
    else
    {
      char buf[1024];
      while (!stream.eof())
      {
        stream.read(buf, 1024);
        tr.write(buf, stream.gcount());
      }
    }
  }
  else
  {
    if (!item->isNode() && 
        item->getTypeCode() == store::XS_BASE64BINARY)
    {
      size_t len;
      const char* value = item->getBase64BinaryValue(len);

      if (item->isEncoded())
      {
        zstring decoded;
        Base64::decode(value, len, &decoded);
        tr << decoded;
      }
      else
      {
        tr.write(value, len);
      }
    }
    else
    {
      zstring lStringValue;
      item->getStringValue2(lStringValue);
      tr << lStringValue;
    }
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
serializer::serializer(XQueryDiagnostics* aXQueryDiagnostics)
  :
  theXQueryDiagnostics(aXQueryDiagnostics)
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

  encoding = "UTF-8";

  include_content_type = PARAMETER_VALUE_NO;

  item_separator.clear();
  item_separator_is_set = false;

  media_type.clear();

  // This default should match the default for ser_method in Zorba_SerializerOptions
  method = PARAMETER_VALUE_JSON_XML_HYBRID;
  jsoniq_multiple_items = PARAMETER_VALUE_YES;
  jsoniq_xdm_method = PARAMETER_VALUE_XML;

  normalization_form.clear();

  omit_xml_declaration = PARAMETER_VALUE_NO;

  standalone = PARAMETER_VALUE_OMIT;

  undeclare_prefixes = PARAMETER_VALUE_NO;

  version = PARAMETER_VALUE_VERSION_1_0;
  version_string = "1.0";
  version_has_default_value = true;

  indent = PARAMETER_VALUE_NO;
}

static short int
convertMethodString(const char* aValue, const char* aName) {
  if (!strcmp(aValue, "xml"))
    return serializer::PARAMETER_VALUE_XML;
  else if (!strcmp(aValue, "html"))
    return serializer::PARAMETER_VALUE_HTML;
  else if (!strcmp(aValue, "xhtml"))
    return serializer::PARAMETER_VALUE_XHTML;
  else if (!strcmp(aValue, "text"))
    return serializer::PARAMETER_VALUE_TEXT;
  else if (!strcmp(aValue, "binary"))
    return serializer::PARAMETER_VALUE_BINARY;
  else if (!strcmp(aValue, "json"))
    return serializer::PARAMETER_VALUE_JSON;
  else if (!strcmp(aValue, "json-xml-hybrid"))
    return serializer::PARAMETER_VALUE_JSON_XML_HYBRID;
  else
    throw ZORBA_EXCEPTION(
      err::SEPM0016, ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreXMLEtc ) )
    );
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
      throw ZORBA_EXCEPTION(
        err::SEPM0016, ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreYesNo ) )
      );
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
      throw ZORBA_EXCEPTION(
        err::SEPM0016,
        ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreYesNoOmit ) )
      );
  }
  else if (!strcmp(aName, "omit-xml-declaration"))
  {
    if (!strcmp(aValue, "yes"))
      omit_xml_declaration = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      omit_xml_declaration = PARAMETER_VALUE_NO;
    else
      throw ZORBA_EXCEPTION(
        err::SEPM0016, ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreYesNo ) )
      );
  }
  else if (!strcmp(aName, "byte-order-mark"))
  {
    if (!strcmp(aValue, "yes"))
      byte_order_mark = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      byte_order_mark = PARAMETER_VALUE_NO;
    else
      throw ZORBA_EXCEPTION(
        err::SEPM0016, ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreYesNo ) )
      );
  }
  else if (!strcmp(aName, "undeclare-prefixes"))
  {
    if (!strcmp(aValue, "yes"))
      undeclare_prefixes = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      undeclare_prefixes = PARAMETER_VALUE_NO;
    else
      throw ZORBA_EXCEPTION(
        err::SEPM0016, ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreYesNo ) )
      );
  }
  else if (!strcmp(aName, "method"))
  {
    method = convertMethodString(aValue, aName);
  }
  else if (!strcmp(aName, "include-content-type"))
  {
    if (!strcmp(aValue, "yes"))
      include_content_type = PARAMETER_VALUE_YES;
    else if (!strcmp(aValue, "no"))
      include_content_type = PARAMETER_VALUE_NO;
    else
      throw ZORBA_EXCEPTION(
        err::SEPM0016, ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreYesNo ) )
      );
  }
  else if (!strcmp(aName, "encoding"))
  {
    if ( !transcode::is_supported( aValue ) )
      throw ZORBA_EXCEPTION(
        err::SEPM0016,
        ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreUTF8Etc ) )
      );
    zstring temp( aValue );
    ascii::to_upper( temp );
    encoding = aValue;
  }
  else if (!strcmp(aName, "media-type"))
  {
    media_type = aValue;
  }
  else if (!strcmp(aName, "version"))
  {
    version_string = aValue;
    version_has_default_value = false;
    if (version_string == "1.0")
      version = PARAMETER_VALUE_VERSION_1_0;
    else if (version_string == "1.1")
      version = PARAMETER_VALUE_VERSION_1_1;
    else if (version_string == "4.0")
      version = PARAMETER_VALUE_VERSION_4_0;
    else if (version_string == "4.01")
      version = PARAMETER_VALUE_VERSION_4_01;
    else
      version = PARAMETER_VALUE_VERSION_OTHER;
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
  else if (!strcmp(aName, "item-separator"))
  {
    item_separator = aValue;
    item_separator_is_set = true;
  }
  else if (!strcmp(aName, "jsoniq-multiple-items"))
  {
    if (!strcmp(aValue, "no"))
      jsoniq_multiple_items = PARAMETER_VALUE_NO;
    else if (!strcmp(aValue, "yes"))
      jsoniq_multiple_items = PARAMETER_VALUE_YES;
    else
      throw ZORBA_EXCEPTION(
        err::SEPM0016, ERROR_PARAMS( aValue, aName, ZED( GoodValuesAreYesNo ) )
      );
  }
  else if (!strcmp(aName, "jsoniq-xdm-node-output-method"))
  {
    jsoniq_xdm_method = convertMethodString(aValue, aName);
  }
  else
  {
    throw ZORBA_EXCEPTION( err::SEPM0016, ERROR_PARAMS( aValue, aName ) );
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::getSerializationMethod(zstring& m) const
{
  switch (getSerializationMethod())
  {
    case PARAMETER_VALUE_XML: m = "xml"; break;
    case PARAMETER_VALUE_HTML: m = "html"; break;
    case PARAMETER_VALUE_XHTML: m = "xhtml"; break;
    case PARAMETER_VALUE_TEXT: m = "text"; break;
    case PARAMETER_VALUE_BINARY: m = "binary"; break;
    case PARAMETER_VALUE_JSON: m = "json"; break;
    case PARAMETER_VALUE_JSON_XML_HYBRID: m = "json-xml-hybrid"; break;
    default: ZORBA_ASSERT(false);
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
void
serializer::validate_parameters(void)
{
  if (method == PARAMETER_VALUE_XML || method == PARAMETER_VALUE_XHTML)
  {
    // XML-only validation
    if (method == PARAMETER_VALUE_XML)
    {
      if (version != PARAMETER_VALUE_VERSION_1_0 && version != PARAMETER_VALUE_VERSION_1_1)
        throw ZORBA_EXCEPTION(
          err::SESU0013, ERROR_PARAMS( version_string, "XML", "\"1.0\", \"1.1\"" )
        );
    }

    // XHTML-only validation
    if (method == PARAMETER_VALUE_XHTML)
    {
    }

    // XML and XHTML validation

    if (omit_xml_declaration == PARAMETER_VALUE_YES)
    {
      if (standalone != PARAMETER_VALUE_OMIT)
        throw ZORBA_EXCEPTION(
          err::SEPM0009, ERROR_PARAMS( ZED( SEPM0009_NotOmit ) )
        );
      if (version != PARAMETER_VALUE_VERSION_1_0 && !doctype_system.empty())
        throw ZORBA_EXCEPTION(
          err::SEPM0009, ERROR_PARAMS( ZED( SEPM0009_Not10 ) )
        );
    }

    if (undeclare_prefixes == PARAMETER_VALUE_YES && version == PARAMETER_VALUE_VERSION_1_0)
      throw ZORBA_EXCEPTION( err::SEPM0010 );
  }

  if (method == PARAMETER_VALUE_HTML)
  {
    // Default value for "version" when method is HTML is "4.0"
    if (version_has_default_value)
    {
      version = PARAMETER_VALUE_VERSION_4_0;
      version_string = "4.0";
    }
    else if (version != PARAMETER_VALUE_VERSION_4_0 && version != PARAMETER_VALUE_VERSION_4_01)
    {
      throw ZORBA_EXCEPTION(
        err::SESU0013, ERROR_PARAMS( version_string, "HTML", "\"4.0\", \"4.01\"" )
      );
    }
  }
}


/*******************************************************************************

********************************************************************************/
bool serializer::setup(std::ostream& os, bool aEmitAttributes)
{
  tr = &os;
  if (method == PARAMETER_VALUE_XML)
    e = new xml_emitter(this, *tr, aEmitAttributes);
  else if (method == PARAMETER_VALUE_HTML)
    e = new html_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_XHTML)
    e = new xhtml_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_TEXT)
    e = new text_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_BINARY)
    e = new binary_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_JSON)
    e = new json_emitter(this, *tr);
  else if (method == PARAMETER_VALUE_JSON_XML_HYBRID)
    e = new hybrid_emitter(this, *tr, aEmitAttributes);
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

void serializer::attach_transcoder(std::ostream &os)
{
#ifndef ZORBA_NO_UNICODE
  if ( transcode::is_necessary( encoding.c_str() ) )
    transcode::attach( os, encoding.c_str() );
#endif /* ZORBA_NO_UNICODE */
}

/*******************************************************************************

********************************************************************************/
void serializer::serialize(
    store::Iterator_t    aObject,
    std::ostream& aOStream,
    bool aEmitAttributes)
{
  serialize(aObject, aOStream, 0, aEmitAttributes);
}


/*******************************************************************************

********************************************************************************/
void
serializer::serialize(
  store::Iterator_t     aObject,
  std::ostream&         aOStream,
  SAX2_ContentHandler*  aHandler,
  bool                  aEmitAttributes)
{
  std::stringstream temp_sstream; // used to temporarily hold expanded strings for the SAX serializer

  validate_parameters();

  if (!setup(aOStream, aEmitAttributes))
  {
    return;
  }

  try {

    // in case we use SAX event notifications
    if (aHandler)
    {
      // Only allow XML-based methods for SAX notifications. For now at least,
      // the "JSON-XML-hybrid" method is considerd "XML-based", although you
      // will certainly get errors if you attempt to serialize JDM this way.
      if (method != PARAMETER_VALUE_XML &&
          method != PARAMETER_VALUE_XHTML
          && method != PARAMETER_VALUE_JSON_XML_HYBRID
        ) {
        throw ZORBA_EXCEPTION(
          zerr::ZAPI0070_INVALID_SERIALIZATION_METHOD_FOR_SAX,
          ERROR_PARAMS( method )
        );
      }
      // it's OK now, build a SAX emmiter
      tr = &temp_sstream;
      e = new sax2_emitter(this, *tr, temp_sstream, aHandler);
    }

    e->emit_declaration();

    store::Item_t lItem;
    //+  aObject->open();
    while (aObject->next(lItem))
    {
      // PUL's cannot be serialized
      if (lItem->isPul())
      {
        throw ZORBA_EXCEPTION(zerr::ZAPI0007_CANNOT_SERIALIZE_PUL);
      }

      e->emit_item(&*lItem);
    }
  //+  aObject->close();
    e->emit_end();
    transcode::detach( aOStream );
  }
  catch ( ... ) {
    transcode::detach( aOStream );
    throw;
  }
}


/*******************************************************************************

********************************************************************************/
void serializer::serialize(
    store::Iterator_t object,
    std::ostream& stream,
    itemHandler aHandler,
    void* aHandlerData)
{
  validate_parameters();

  if (!setup(stream))
  {
    return;
  }

  try {
    e->emit_declaration();

    store::Item_t lItem;
    //object->open();
    while (object->next(lItem))
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

      // PUL's cannot be serialized
      if (lItem->isPul())
      {
        throw ZORBA_EXCEPTION(zerr::ZAPI0007_CANNOT_SERIALIZE_PUL);
      }

      e->emit_item(&*lItem);
    }

    //object->close();
    e->emit_end();
    transcode::detach( stream );
  }
  catch ( ... ) {
    transcode::detach( stream );
    throw;
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
