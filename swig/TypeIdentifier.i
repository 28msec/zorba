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

  zorba::IdentTypes::quantifier_t 
  TypeIdentifier::convertQuantifier(IdentTypes::Quantifier quantifier)
  {
    zorba::IdentTypes::quantifier_t result;
    switch (quantifier) {
      case IdentTypes::QUANT_ONE:
        result = zorba::IdentTypes::QUANT_ONE;
        break;
      case IdentTypes::QUANT_QUESTION:
        result = zorba::IdentTypes::QUANT_QUESTION;
        break;
      case IdentTypes::QUANT_PLUS:
        result = zorba::IdentTypes::QUANT_PLUS;
        break;
      case IdentTypes::QUANT_STAR:
        result = zorba::IdentTypes::QUANT_STAR;
        break;
    }
    return result;
  }

  TypeIdentifier TypeIdentifier::getContentType()
  {
    return TypeIdentifier(theTypeIdentifier->getContentType());
  }
  IdentTypes::Kind TypeIdentifier::getKind()
  {
    zorba::IdentTypes::kind_t lKind = theTypeIdentifier->getKind();
    IdentTypes::Kind result;
    switch (lKind) {
      case zorba::IdentTypes::NAMED_TYPE:
        result = IdentTypes::NAMED_TYPE;
        break;
      case zorba::IdentTypes::ELEMENT_TYPE:
        result = IdentTypes::ELEMENT_TYPE;
        break;
      case zorba::IdentTypes::ATTRIBUTE_TYPE:
        result = IdentTypes::ATTRIBUTE_TYPE;
        break;
      case zorba::IdentTypes::DOCUMENT_TYPE:
        result = IdentTypes::DOCUMENT_TYPE;
        break;
      case zorba::IdentTypes::PI_TYPE:
        result = IdentTypes::PI_TYPE;
        break;
      case zorba::IdentTypes::TEXT_TYPE:
        result = IdentTypes::TEXT_TYPE;
        break;
      case zorba::IdentTypes::COMMENT_TYPE:
        result = IdentTypes::COMMENT_TYPE;
        break;
      case zorba::IdentTypes::ANY_NODE_TYPE:
        result = IdentTypes::ANY_NODE_TYPE;
        break;
      case zorba::IdentTypes::ITEM_TYPE:
        result = IdentTypes::ITEM_TYPE;
        break;
      case zorba::IdentTypes::EMPTY_TYPE:
        result = IdentTypes::EMPTY_TYPE;
        break;
      case zorba::IdentTypes::INVALID_TYPE:
        result = IdentTypes::INVALID_TYPE;
        break;
      default:
        result = IdentTypes::ANY_NODE_TYPE;
        break;
    }
    return result;
  }
  const std::string TypeIdentifier::getLocalName()
  {
    return std::string(theTypeIdentifier->getLocalName().c_str());
  }
  IdentTypes::Quantifier TypeIdentifier::getQuantifier()
  {
    zorba::IdentTypes::quantifier_t lQuantifier = theTypeIdentifier->getQuantifier();
    IdentTypes::Quantifier result;
    switch (lQuantifier) {
      case zorba::IdentTypes::QUANT_ONE:
        result = IdentTypes::QUANT_ONE;
        break;
      case zorba::IdentTypes::QUANT_QUESTION:
        result = IdentTypes::QUANT_QUESTION;
        break;
      case zorba::IdentTypes::QUANT_PLUS:
        result = IdentTypes::QUANT_PLUS;
        break;
      case zorba::IdentTypes::QUANT_STAR:
        result = IdentTypes::QUANT_STAR;
        break;
    }
    return result;
  }
  long TypeIdentifier::getRefCount()
  {
    return theTypeIdentifier->getRefCount();
  }
  const std::string TypeIdentifier::getUri()
  {
    return std::string(theTypeIdentifier->getUri().c_str());
  }
  bool TypeIdentifier::isLocalNameWildcard()
  {
    return theTypeIdentifier->isLocalNameWildcard();
  }
  bool TypeIdentifier::isUriWildcard()
  {
    return theTypeIdentifier->isUriWildcard();
  }
  

  //  STATIC METHODS
  TypeIdentifier 
  TypeIdentifier::createAnyNodeType (IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createAnyNodeType ( convertQuantifier(quantifier) ) );
  }

  TypeIdentifier 
  TypeIdentifier::createAttributeType (const std::string &uri, bool uriWildcard, const std::string &localNameName, bool localNameWildcard, TypeIdentifier contentType, IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createAttributeType( uri, uriWildcard, localNameName, localNameWildcard, contentType.theTypeIdentifier,  convertQuantifier(quantifier) ) );
  }

  TypeIdentifier 
  TypeIdentifier::createCommentType (IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createCommentType ( convertQuantifier(quantifier) ) );
  }

  TypeIdentifier 
  TypeIdentifier::createDocumentType (TypeIdentifier contentType, IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createDocumentType(contentType.theTypeIdentifier, convertQuantifier(quantifier) ) );
  }

  TypeIdentifier 
  TypeIdentifier::createElementType (const std::string &uri, bool uriWildcard, const std::string &localName, bool localNameWildcard, TypeIdentifier contentType, IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createElementType(uri, uriWildcard, localName, localNameWildcard, contentType.theTypeIdentifier, convertQuantifier(quantifier) ) );
  }

  TypeIdentifier
  TypeIdentifier::createEmptyType()
  {
    return TypeIdentifier( zorba::TypeIdentifier::createEmptyType() );
  }

  TypeIdentifier 
  TypeIdentifier::createItemType (IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createItemType( convertQuantifier(quantifier) ) );
  }

  TypeIdentifier 
  TypeIdentifier::createNamedType (const std::string &uri, const std::string &localName, IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createNamedType( uri, localName, convertQuantifier(quantifier) ) );
  }

  TypeIdentifier 
  TypeIdentifier::createPIType (IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createPIType( convertQuantifier(quantifier) ) );
  }

  TypeIdentifier 
  TypeIdentifier::createTextType (IdentTypes::Quantifier quantifier)
  {
    return TypeIdentifier( zorba::TypeIdentifier::createTextType( convertQuantifier(quantifier) ) );
  }
  
  // END OF STATIC METHODS


%}  // end   Implementation


%include "TypeIdentifier.h"
