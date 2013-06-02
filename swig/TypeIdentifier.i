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

  zorba::SequenceType::Quantifier 
  SequenceType::convertQuantifier(IdentTypes::Quantifier quantifier)
  {
    zorba::SequenceType::Quantifier result = zorba::SequenceType::QUANT_ONE;

    switch (quantifier) {
      case IdentTypes::QUANT_ONE:
        result = zorba::SequenceType::QUANT_ONE;
        break;
      case IdentTypes::QUANT_QUESTION:
        result = zorba::SequenceType::QUANT_QUESTION;
        break;
      case IdentTypes::QUANT_PLUS:
        result = zorba::SequenceType::QUANT_PLUS;
        break;
      case IdentTypes::QUANT_STAR:
        result = zorba::SequenceType::QUANT_STAR;
        break;
    }
    return result;
  }


  SequenceType SequenceType::getContentType()
  {
    return SequenceType(theSequenceType->getContentType());
  }


  IdentTypes::Kind SequenceType::getKind()
  {
    zorba::SequenceType::Kind lKind = theSequenceType->getKind();

    IdentTypes::Kind result = IdentTypes::ANY_NODE_TYPE;

    switch (lKind)
    {
      case zorba::SequenceType::ATOMIC_OR_UNION_TYPE:
        result = IdentTypes::ATOMIC_OR_UNION_TYPE;
        break;
      case zorba::SequenceType::ELEMENT_TYPE:
        result = IdentTypes::ELEMENT_TYPE;
        break;
      case zorba::SequenceType::ATTRIBUTE_TYPE:
        result = IdentTypes::ATTRIBUTE_TYPE;
        break;
      case zorba::SequenceType::DOCUMENT_TYPE:
        result = IdentTypes::DOCUMENT_TYPE;
        break;
      case zorba::SequenceType::PI_TYPE:
        result = IdentTypes::PI_TYPE;
        break;
      case zorba::SequenceType::TEXT_TYPE:
        result = IdentTypes::TEXT_TYPE;
        break;
      case zorba::SequenceType::COMMENT_TYPE:
        result = IdentTypes::COMMENT_TYPE;
        break;
      case zorba::SequenceType::ANY_NODE_TYPE:
        result = IdentTypes::ANY_NODE_TYPE;
        break;
      case zorba::SequenceType::ITEM_TYPE:
        result = IdentTypes::ITEM_TYPE;
        break;
      case zorba::SequenceType::EMPTY_TYPE:
        result = IdentTypes::EMPTY_TYPE;
        break;
      case zorba::SequenceType::INVALID_TYPE:
        result = IdentTypes::INVALID_TYPE;
        break;
      default:
        result = IdentTypes::ANY_NODE_TYPE;
        break;
    }
    return result;
  }


  const std::string SequenceType::getLocalName()
  {
    return std::string(theSequenceType->getLocalName().c_str());
  }


  IdentTypes::Quantifier SequenceType::getQuantifier()
  {
    zorba::SequenceType::Quantifier lQuantifier = theSequenceType->getQuantifier();

    IdentTypes::Quantifier result = IdentTypes::QUANT_ONE;

    switch (lQuantifier)
    {
      case zorba::SequenceType::QUANT_ONE:
        result = IdentTypes::QUANT_ONE;
        break;
      case zorba::SequenceType::QUANT_QUESTION:
        result = IdentTypes::QUANT_QUESTION;
        break;
      case zorba::SequenceType::QUANT_PLUS:
        result = IdentTypes::QUANT_PLUS;
        break;
      case zorba::SequenceType::QUANT_STAR:
        result = IdentTypes::QUANT_STAR;
        break;
    }
    return result;
  }


  long SequenceType::getRefCount()
  {
    return theSequenceType->getRefCount();
  }


  const std::string SequenceType::getUri()
  {
    return std::string(theSequenceType->getUri().c_str());
  }


  bool SequenceType::isLocalNameWildcard()
  {
    return theSequenceType->isLocalNameWildcard();
  }


  bool SequenceType::isUriWildcard()
  {
    return theSequenceType->isUriWildcard();
  }
  

  //  STATIC METHODS
  SequenceType 
  SequenceType::createAnyNodeType(IdentTypes::Quantifier quantifier)
  {
    return SequenceType(zorba::SequenceType::createAnyNodeType(convertQuantifier(quantifier)));
  }


  SequenceType 
  SequenceType::createAttributeType(
    const std::string &uri,
    bool uriWildcard,
    const std::string &localNameName,
    bool localNameWildcard,
    SequenceType contentType,
    IdentTypes::Quantifier quantifier)
  {
    return SequenceType(zorba::SequenceType::createAttributeType(uri, uriWildcard, localNameName, localNameWildcard, contentType.theSequenceType,  convertQuantifier(quantifier)));
  }


  SequenceType 
  SequenceType::createCommentType(IdentTypes::Quantifier quantifier)
  {
    return SequenceType(zorba::SequenceType::createCommentType(convertQuantifier(quantifier)));
  }


  SequenceType 
  SequenceType::createDocumentType()
  {
    return SequenceType(zorba::SequenceType::createDocumentType(NULL));
  }


  SequenceType 
  SequenceType::createElementType(
    const std::string &uri,
    bool uriWildcard,
    const std::string &localName,
    bool localNameWildcard,
    SequenceType contentType,
    IdentTypes::Quantifier quantifier)
  {
    return SequenceType(zorba::SequenceType::createElementType(uri, uriWildcard, localName, localNameWildcard, contentType.theSequenceType, convertQuantifier(quantifier)));
  }


  SequenceType
  SequenceType::createEmptyType()
  {
    return SequenceType(zorba::SequenceType::createEmptyType());
  }


  SequenceType 
  SequenceType::createItemType(IdentTypes::Quantifier quantifier)
  {
    return SequenceType(zorba::SequenceType::createItemType(convertQuantifier(quantifier)));
  }


  SequenceType 
  SequenceType::createNamedType(
    const std::string &uri,
    const std::string &localName,
    IdentTypes::Quantifier quantifier)
  {
    return SequenceType(zorba::SequenceType::createNamedType( uri, localName, convertQuantifier(quantifier)));
  }


  SequenceType 
  SequenceType::createPIType(IdentTypes::Quantifier quantifier)
  {
    return SequenceType(zorba::SequenceType::createPIType(convertQuantifier(quantifier)));
  }


  SequenceType 
  SequenceType::createTextType(IdentTypes::Quantifier quantifier)
  {
    return SequenceType(zorba::SequenceType::createTextType(convertQuantifier(quantifier)));
  }
  
  // END OF STATIC METHODS


%}  // end   Implementation


%include "TypeIdentifier.h"
