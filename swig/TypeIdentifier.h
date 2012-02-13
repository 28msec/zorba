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

#ifndef API_TYPE_IDENTIFIER_H
#define API_TYPE_IDENTIFIER_H

class IdentTypes {
public:
  typedef enum {
    NAMED_TYPE,
    ELEMENT_TYPE,
    ATTRIBUTE_TYPE,
    DOCUMENT_TYPE,
    PI_TYPE,
    TEXT_TYPE,
    COMMENT_TYPE,
    ANY_NODE_TYPE,
    ITEM_TYPE,
    EMPTY_TYPE,
    INVALID_TYPE,
  } Kind;

  typedef enum {
    QUANT_ONE,
    QUANT_QUESTION,
    QUANT_PLUS,
    QUANT_STAR,
  } Quantifier;
};

class TypeIdentifier 
{
  friend class StaticContext;
private:
  zorba::TypeIdentifier_t theTypeIdentifier;
  static zorba::IdentTypes::quantifier_t convertQuantifier(IdentTypes::Quantifier quantifier);

public: 
  TypeIdentifier() {}
  TypeIdentifier (const TypeIdentifier& aTypeIdentifier) : theTypeIdentifier(aTypeIdentifier.theTypeIdentifier) {}
  TypeIdentifier (const zorba::TypeIdentifier_t& aZTypeIdentifier) : theTypeIdentifier(aZTypeIdentifier) {}

  TypeIdentifier getContentType();
  IdentTypes::Kind getKind();
  const std::string getLocalName();
  IdentTypes::Quantifier getQuantifier();
  long getRefCount();
  const std::string getUri();
  bool isLocalNameWildcard();
  bool isUriWildcard();

  static TypeIdentifier 
  createAnyNodeType (IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
  static TypeIdentifier 
  createAttributeType (const std::string &uri, bool uriWildcard, const std::string &localNameName, bool localNameWildcard, TypeIdentifier contentType, IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
  static TypeIdentifier 
  createCommentType (IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
  static TypeIdentifier 
  createDocumentType (TypeIdentifier contentType, IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
  static TypeIdentifier 
  createElementType (const std::string &uri, bool uriWildcard, const std::string &localName, bool localNameWildcard, TypeIdentifier contentType, IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
  static TypeIdentifier 
  createEmptyType();
  
  static TypeIdentifier 
  createItemType (IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
  static TypeIdentifier 
  createNamedType (const std::string &uri, const std::string &localName, IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
  static TypeIdentifier 
  createPIType (IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
  static TypeIdentifier 
  createTextType (IdentTypes::Quantifier quantifier=IdentTypes::QUANT_ONE);
  
}; // class TypeIdentifier


#endif