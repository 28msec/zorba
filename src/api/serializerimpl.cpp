/*
 * Copyright 2006-2009 The FLWOR Foundation.
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

#include <zorba/item.h>
#include <zorba/options.h>
#include <zorba/singleton_item_sequence.h>

#include "api/unmarshaller.h"
#include "api/serializer_item_sequence.h"

#include "serializerimpl.h"

namespace zorba { 

Serializer_t
Serializer::createSerializer(const Zorba_SerializerOptions_t& aOptions)
{
  return new SerializerImpl(aOptions);
}

SerializerImpl::SerializerImpl(const Zorba_SerializerOptions_t& aOptions)
  : theInternalSerializer(&theErrorManager)
{
  setSerializationParameters(theInternalSerializer, aOptions);
}

void
SerializerImpl::serialize(const Item& aItem, std::ostream& aOs) const
{
  SingletonItemSequence lItemSequence(aItem);
  SerializerItemSequence lSerItemSequence(&lItemSequence);
  theInternalSerializer.serialize(lSerItemSequence, aOs);
}

void
SerializerImpl::serialize(ItemSequence* aSequence, std::ostream& aOs) const
{
  SerializerItemSequence lSerItemSequence(aSequence);
  theInternalSerializer.serialize(lSerItemSequence, aOs);
}

void
SerializerImpl::setSerializationParameters(
  serializer& aInternalSerializer,
  const Zorba_SerializerOptions_t& aSerializerOptions)
{
  switch (aSerializerOptions.ser_method) 
  {
  case ZORBA_SERIALIZATION_METHOD_XML:
    aInternalSerializer.set_parameter("method", "xml"); break;
  case ZORBA_SERIALIZATION_METHOD_HTML:
    aInternalSerializer.set_parameter("method", "html"); break;
  case ZORBA_SERIALIZATION_METHOD_XHTML:
    aInternalSerializer.set_parameter("method", "xhtml"); break;
  case ZORBA_SERIALIZATION_METHOD_TEXT:
    aInternalSerializer.set_parameter("method", "text"); break;
  case ZORBA_SERIALIZATION_METHOD_JSON:
    aInternalSerializer.set_parameter("method", "json"); break;
  case ZORBA_SERIALIZATION_METHOD_JSONML:
    aInternalSerializer.set_parameter("method", "jsonml"); break;
  }

  switch (aSerializerOptions.byte_order_mark) 
  {
  case ZORBA_BYTE_ORDER_MARK_YES:
    aInternalSerializer.set_parameter("byte-order-mark", "yes"); break;
  case ZORBA_BYTE_ORDER_MARK_NO:
    aInternalSerializer.set_parameter("byte-order-mark", "no"); break;
  }

  switch (aSerializerOptions.include_content_type)
  {
  case ZORBA_INCLUDE_CONTENT_TYPE_YES:
    aInternalSerializer.set_parameter("include-content-type", "yes"); break;
  case ZORBA_INCLUDE_CONTENT_TYPE_NO:
    aInternalSerializer.set_parameter("include-content-type", "no"); break;
  }

  switch (aSerializerOptions.indent) 
  {
  case ZORBA_INDENT_YES:
    aInternalSerializer.set_parameter("indent", "yes"); break;
  case ZORBA_INDENT_NO:
    aInternalSerializer.set_parameter("indent", "no"); break;
  }

  switch (aSerializerOptions.omit_xml_declaration)
  {
  case ZORBA_OMIT_XML_DECLARATION_YES:
    aInternalSerializer.set_parameter("omit-xml-declaration", "yes"); break;
  case ZORBA_OMIT_XML_DECLARATION_NO:
    aInternalSerializer.set_parameter("omit-xml-declaration", "no"); break;
  }

  switch (aSerializerOptions.standalone)
  {
  case ZORBA_STANDALONE_YES:
    aInternalSerializer.set_parameter("standalone", "yes"); break;
  case ZORBA_STANDALONE_NO:
    aInternalSerializer.set_parameter("standalone", "no"); break;
  case ZORBA_STANDALONE_OMIT:
    aInternalSerializer.set_parameter("standalone", "omit"); break;
  }

  switch (aSerializerOptions.undeclare_prefixes)
  {
  case ZORBA_UNDECLARE_PREFIXES_YES:
    aInternalSerializer.set_parameter("undeclare-prefixes", "yes"); break;
  case ZORBA_UNDECLARE_PREFIXES_NO:
    aInternalSerializer.set_parameter("undeclare-prefixes", "no"); break;
  }

  if (aSerializerOptions.media_type != "")
    aInternalSerializer.set_parameter("media-type", aSerializerOptions.media_type.c_str());

  if (aSerializerOptions.doctype_system != "")
    aInternalSerializer.set_parameter("doctype-system", aSerializerOptions.doctype_system.c_str());

  if (aSerializerOptions.doctype_public != "")
    aInternalSerializer.set_parameter("doctype-public", aSerializerOptions.doctype_public.c_str());
  
  if (aSerializerOptions.cdata_section_elements != "")
    aInternalSerializer.set_parameter("cdata-section-elements", aSerializerOptions.cdata_section_elements.c_str());
}



} // namespace zorba
