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
#include <zorba/serializable.h>
#include <zorba/default_error_handler.h>

#include "api/zorbaimpl.h"
#include "api/serialization/serializable_wrapper.h"
#include "api/serialization/serializable.h"
#include "api/unmarshaller.h"

#include "serializerimpl.h"

namespace zorba { 

Serializer_t
Serializer::createSerializer(const Zorba_SerializerOptions_t& aOptions)
{
  return new SerializerImpl(aOptions);
}

Serializer_t
Serializer::createSerializer(ItemSequence* aOptions)
{
  return new SerializerImpl(aOptions);
}

SerializerImpl::SerializerImpl(const Zorba_SerializerOptions_t& aOptions, ErrorHandler* aErrorHandler)
  : theErrorHandler(aErrorHandler),
    theInternalSerializer(&theErrorManager)
{
  setSerializationParameters(theInternalSerializer, aOptions);
  if (!theErrorHandler) {
    theErrorHandler = new DefaultErrorHandler();
  }
}

SerializerImpl::SerializerImpl(ItemSequence* aOptions, ErrorHandler* aErrorHandler)
  : theErrorHandler(aErrorHandler),
    theInternalSerializer(&theErrorManager)
{
  setSerializationParameters(theInternalSerializer, aOptions);
  if (!theErrorHandler) {
    theErrorHandler = new DefaultErrorHandler();
  }
}

void
SerializerImpl::serialize(Serializable* aObject, std::ostream& aOs) const
{
  try {
    intern::SerializableWrapper lWrapper(aObject);
    theInternalSerializer.serialize((intern::Serializable*)&lWrapper, aOs);
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}

int
SerializerImpl::getSerializationMethod() const
{
  switch (theInternalSerializer.getSerializationMethod())
  {
  case serializer::PARAMETER_VALUE_HTML:
    return ZORBA_SERIALIZATION_METHOD_HTML;
  case serializer::PARAMETER_VALUE_XHTML:
    return ZORBA_SERIALIZATION_METHOD_XHTML;
  case serializer::PARAMETER_VALUE_TEXT:
    return ZORBA_SERIALIZATION_METHOD_TEXT;
  case serializer::PARAMETER_VALUE_JSON:
    return ZORBA_SERIALIZATION_METHOD_JSON;
  case serializer::PARAMETER_VALUE_JSONML:
    return ZORBA_SERIALIZATION_METHOD_JSONML;
  case serializer::PARAMETER_VALUE_BINARY:
    return ZORBA_SERIALIZATION_METHOD_BINARY;
  default:
    return ZORBA_SERIALIZATION_METHOD_XML;
  }
}


void
SerializerImpl::setSerializationParameters(
  serializer&                       aInternalSerializer,
  const Zorba_SerializerOptions_t&  aSerializerOptions)
{
  switch (aSerializerOptions.ser_method) 
  {
  case ZORBA_SERIALIZATION_METHOD_XML:
    aInternalSerializer.setParameter("method", "xml"); break;
  case ZORBA_SERIALIZATION_METHOD_HTML:
    aInternalSerializer.setParameter("method", "html"); break;
  case ZORBA_SERIALIZATION_METHOD_XHTML:
    aInternalSerializer.setParameter("method", "xhtml"); break;
  case ZORBA_SERIALIZATION_METHOD_TEXT:
    aInternalSerializer.setParameter("method", "text"); break;
  case ZORBA_SERIALIZATION_METHOD_JSON:
    aInternalSerializer.setParameter("method", "json"); break;
  case ZORBA_SERIALIZATION_METHOD_JSONML:
    aInternalSerializer.setParameter("method", "jsonml"); break;
  case ZORBA_SERIALIZATION_METHOD_BINARY:
    aInternalSerializer.setParameter("method", "binary"); break;
  }

  switch (aSerializerOptions.byte_order_mark) 
  {
  case ZORBA_BYTE_ORDER_MARK_YES:
    aInternalSerializer.setParameter("byte-order-mark", "yes"); break;
  case ZORBA_BYTE_ORDER_MARK_NO:
    aInternalSerializer.setParameter("byte-order-mark", "no"); break;
  }

  switch (aSerializerOptions.include_content_type)
  {
  case ZORBA_INCLUDE_CONTENT_TYPE_YES:
    aInternalSerializer.setParameter("include-content-type", "yes"); break;
  case ZORBA_INCLUDE_CONTENT_TYPE_NO:
    aInternalSerializer.setParameter("include-content-type", "no"); break;
  }

  switch (aSerializerOptions.indent) 
  {
  case ZORBA_INDENT_YES:
    aInternalSerializer.setParameter("indent", "yes"); break;
  case ZORBA_INDENT_NO:
    aInternalSerializer.setParameter("indent", "no"); break;
  }

  switch (aSerializerOptions.omit_xml_declaration)
  {
  case ZORBA_OMIT_XML_DECLARATION_YES:
    aInternalSerializer.setParameter("omit-xml-declaration", "yes"); break;
  case ZORBA_OMIT_XML_DECLARATION_NO:
    aInternalSerializer.setParameter("omit-xml-declaration", "no"); break;
  }

  switch (aSerializerOptions.standalone)
  {
  case ZORBA_STANDALONE_YES:
    aInternalSerializer.setParameter("standalone", "yes"); break;
  case ZORBA_STANDALONE_NO:
    aInternalSerializer.setParameter("standalone", "no"); break;
  case ZORBA_STANDALONE_OMIT:
    aInternalSerializer.setParameter("standalone", "omit"); break;
  }

  switch (aSerializerOptions.undeclare_prefixes)
  {
  case ZORBA_UNDECLARE_PREFIXES_YES:
    aInternalSerializer.setParameter("undeclare-prefixes", "yes"); break;
  case ZORBA_UNDECLARE_PREFIXES_NO:
    aInternalSerializer.setParameter("undeclare-prefixes", "no"); break;
  }

  if (aSerializerOptions.media_type != "")
    aInternalSerializer.setParameter("media-type", aSerializerOptions.media_type.c_str());

  if (aSerializerOptions.doctype_system != "")
    aInternalSerializer.setParameter("doctype-system", aSerializerOptions.doctype_system.c_str());

  if (aSerializerOptions.doctype_public != "")
    aInternalSerializer.setParameter("doctype-public", aSerializerOptions.doctype_public.c_str());
  
  if (aSerializerOptions.cdata_section_elements != "")
    aInternalSerializer.setParameter("cdata-section-elements", aSerializerOptions.cdata_section_elements.c_str());

  if (aSerializerOptions.version != "")
    aInternalSerializer.setParameter("version", aSerializerOptions.version.c_str());
}

void
SerializerImpl::setSerializationParameters(
  serializer&   aInternalSerializer,
  ItemSequence* aSerializerOptions)
{
  Item lItem;
  while (aSerializerOptions->next(lItem)) {
    Item lNodeName;
    lItem.getNodeName(lNodeName);
    aInternalSerializer.setParameter(lNodeName.getLocalName().c_str(), lItem.getStringValue().c_str());
  }
}

} // namespace zorba
