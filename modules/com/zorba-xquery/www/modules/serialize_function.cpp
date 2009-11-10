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

#include <zorba/zorba.h>

#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/store_consts.h>
#include "serialize_function.h"
#include "serialize_module.h"

namespace zorba { namespace serializemodule {

SerializeFunction::SerializeFunction(const SerializeModule* aModule)
  : theModule(aModule)
{
}

SerializeFunction::~SerializeFunction()
{
}

String
SerializeFunction::getURI() const
{
  return theModule->getURI();
}


ItemSequence_t
SerializeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& args) const
{
  Zorba_SerializerOptions_t lOptions;
  lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  if (args.size() == 2) {
    Item lItem;
    if (!args[1]->next(lItem)) {
      std::stringstream lErrorMessage;
      lErrorMessage << "The serialization options parameter cannot be empty-sequence";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    lOptions = createSerializerOptions(lItem);
  }
  Serializer_t s = Serializer::createSerializer(lOptions);

  std::ostringstream lResult;
  s->serialize( static_cast<Serializable*>(args[0]), lResult );
  return ItemSequence_t(new SingletonItemSequence(
    theModule->getItemFactory()->createString(lResult.str())));
}

void
SerializeFunction::throwError(
    const std::string aErrorMessage,
    const XQUERY_ERROR& aErrorType)
{
  throw zorba::ExternalFunctionData::createZorbaException(aErrorType,
      aErrorMessage.c_str(), __FILE__, __LINE__);
}

const Zorba_SerializerOptions_t
SerializeFunction::createSerializerOptions(const Item& aItem) const
{
  Zorba_SerializerOptions_t lOptions;
  
  // in case the parameter is a string
  if (aItem.isAtomic()) {
    zorba::String lMethod = aItem.getStringValue();
    if (lMethod == "xml") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
    } else if (lMethod == "html") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
    } else if (lMethod == "xhtml") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XHTML;
    } else if (lMethod == "text") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
    } else if (lMethod == "json") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_JSON;
    } else if (lMethod == "jsonml") {
      lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_JSONML;
    } else {
      throwInvalidSerializationOptionValue();
    }
  // if we have an element node
  } else if (aItem.isNode() && aItem.getNodeKind() == store::StoreConsts::elementNode) {
    // and must have "output" as local name
    Item lQName;
    aItem.getNodeName(lQName);
    zorba::String lLocalName = lQName.getLocalName();
    if(lLocalName != "output") {
      throwInvalidSerializationOptionValue();
    }
    // iterate all the atributes and set the serialization options accordingly
    // NOTE: Extra attributes and invalid values for attributes are ignored.
    Iterator_t lIter = aItem.getAttributes();
    lIter->open();
    Item lAttribute;
    while (lIter->next(lAttribute)) {
      Item lAttributeQName;
      lAttribute.getNodeName(lAttributeQName);
      lOptions.SetSerializerOption(lAttributeQName.getLocalName().c_str(), lAttribute.getStringValue().c_str());
    }
    lIter->close();
  } else {
    throwInvalidSerializationOptionValue();
  }

  return lOptions;
}

void
SerializeFunction::throwInvalidSerializationOptionValue() const
{
  std::stringstream lErrorMessage;
  lErrorMessage << "Invalid serialization options parameter. "
      << "Please see the documentation for valid values.";
  throwError(lErrorMessage.str(), XPTY0004);
}

} /* namespace serializemodule */ } /* namespace zorba */

