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

%{  // start Implementation

  Item Item::createEmptyItem()
  {  return Item();  }

  std::string Item::getStringValue() const 
  {  return std::string(theItem.getStringValue().c_str());  }

  std::string Item::serialize() const 
  {
    std::stringstream lStream;
    Zorba_SerializerOptions_t lOptions;
    lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    zorba::Serializer_t lSerializer = zorba::Serializer::createSerializer(lOptions);
    zorba::SingletonItemSequence lSequence(theItem);
    lSerializer->serialize(&lSequence, lStream);
    return lStream.str();
  }
  std::string Item::serialize(SerializationOptions serOptions) const 
  {
    std::stringstream lStream;
    serOptions.lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    zorba::Serializer_t lSerializer = zorba::Serializer::createSerializer(serOptions.lOptions);
    zorba::SingletonItemSequence lSequence(theItem);
    lSerializer->serialize(&lSequence, lStream);
    return lStream.str();
  }

  Iterator Item::getAtomizationValue () const
  { return Iterator(theItem.getAtomizationValue()); }

  Iterator Item::getAttributes () const
  { return Iterator(theItem.getAttributes()); }

  bool Item::getBooleanValue () const
  { return theItem.getBooleanValue(); }

  Iterator Item::getChildren () const
  { return Iterator(theItem.getChildren()); }

  Item Item::getEBV () const
  { return Item(theItem.getEBV()); }

  int Item::getIntValue () const
  { return theItem.getIntValue(); }

  double 	Item::getDoubleValue () const
  { return theItem.getDoubleValue(); }

  long long Item::getLongValue () const
  { return theItem.getLongValue(); }

  std::string Item::getLocalName () const
  { return std::string(theItem.getLocalName().c_str()); }

  std::string Item::getNamespace () const
  { return std::string(theItem.getNamespace().c_str()); }

  std::vector< std::pair< std::string, std::string > > Item::getNamespaceBindings () {
    std::vector< std::pair< zorba::String, zorba::String > > items;
    std::vector< std::pair< std::string, std::string > > result;
    theItem.getNamespaceBindings(items);
    std::vector< std::pair< zorba::String, zorba::String > >::iterator iter;
    for(iter = items.begin(); iter != items.end(); iter++) {
      std::pair< std::string, std::string > pair;
      pair.first = (*iter).first.c_str();
      pair.second = (*iter).second.c_str();
      result.push_back(pair);
    }
    return result;
  }

  bool Item::getNodeName (Item &aNodeName) const
  { return theItem.getNodeName( aNodeName.theItem ); }

  Item 	Item::getParent () const
  { return theItem.getParent(); }

  std::string Item::getPrefix () const
  { return std::string(theItem.getPrefix().c_str()); }

  Item Item::getType () const
  { return Item( theItem.getType() ); }

  unsigned int Item::getUnsignedIntValue () const
  { return theItem.getUnsignedIntValue(); }

  bool Item::isAtomic () const
  { return theItem.isAtomic(); }

  bool Item::isNaN () const
  { return theItem.isNaN(); }

  bool Item::isNode () const
  { return theItem.isNode(); }

  bool Item::isNull () const
  { return theItem.isNull(); }

  bool Item::isPosOrNegInf () const
  { return theItem.isPosOrNegInf(); }

  int Item::getNodeKind () const
  { return theItem.getNodeKind(); }
  
  void Item::close()
  { theItem.close(); }

  void Item::serializeToStream(ZorbaStream& aStream) const 
  {
    ZorbaBuffer buffer(aStream);
    std::ostream lStream(&buffer);

    Zorba_SerializerOptions_t lOptions;
    lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    zorba::Serializer_t lSerializer = zorba::Serializer::createSerializer(lOptions);
    zorba::SingletonItemSequence lSequence(theItem);
    lSerializer->serialize(&lSequence, lStream);
    return;
  }
  void Item::serializeToStream(ZorbaStream& aStream, SerializationOptions serOptions) const 
  {
    ZorbaBuffer buffer(aStream);
    std::ostream lStream(&buffer);

    Zorba_SerializerOptions_t lOptions;
    serOptions.lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    zorba::Serializer_t lSerializer = zorba::Serializer::createSerializer(serOptions.lOptions);
    zorba::SingletonItemSequence lSequence(theItem);
    lSerializer->serialize(&lSequence, lStream);
    return;
  }

%}  // end   Implementation


%include "Item.h"
