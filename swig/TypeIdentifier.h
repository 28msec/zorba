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

class IdentTypes
{
public:
  typedef enum
  {
    EMPTY_TYPE,
    ITEM_TYPE,
    ATOMIC_OR_UNION_TYPE,
    FUNCTION_TYPE,
    STRUCTURED_ITEM_TYPE,
    NODE_TYPE,
    DOCUMENT_TYPE,
    ELEMENT_TYPE,
    SCHEMA_ELEMENT_TYPE,
    ATTRIBUTE_TYPE,
    SCHEMA_ATTRIBUTE_TYPE,
    PI_TYPE,
    TEXT_TYPE,
    COMMENT_TYPE,
    NAMESPACE_TYPE,
    JSON_ITEM_TYPE,
    JSON_OBJECT_TYPE,
    JSON_ARRAY_TYPE,
    INVALID_TYPE,
  } Kind;

  typedef enum
  {
    QUANT_ONE,
    QUANT_QUESTION,
    QUANT_PLUS,
    QUANT_STAR,
  } Quantifier;
};


class StaticContext;


/** \brief Type identifiers
 *
 * The type identifiers provides a way to identify the type of an Item.
 *
 */
class SequenceType 
{
  friend class StaticContext;
private:
  zorba::SequenceType theSequenceType;

  static zorba::SequenceType::Quantifier convertQuantifier(
      IdentTypes::Quantifier quantifier);

public: 
  SequenceType(const SequenceType& aSequenceType)
    :
    theSequenceType(aSequenceType.theSequenceType)
  {
  }

  SequenceType(const zorba::SequenceType& aZSequenceType)
    :
    theSequenceType(aZSequenceType)
  {
  }

  IdentTypes::Kind getKind();

  IdentTypes::Quantifier getQuantifier();

  const std::string getTypeLocalName();

  const std::string getTypeUri();

  const std::string getNodeLocalName();

  const std::string getNodeUri();

  const std::string getContentTypeLocalName();

  const std::string getContentTypeUri();

  bool isWildcard();

  bool isSchemaTest();

  static SequenceType createEmptyType();
  
  static SequenceType createItemType(IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType createAtomicOrUnionType(
      const StaticContext& sctx,
      const std::string& uri,
      const std::string& localName,
      IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType createStructuredItemType(
      IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType createAnyNodeType(
      IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createDocumentType(
    const SequenceType& contentType,
    IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createElementType(
      const StaticContext& sctx,
      const std::string& nodeUri,
      const std::string& nodeLocalName,
      const std::string& contentTypeUri,
      const std::string& contentTypeLocalName,
      bool nillable,
      IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createSchemaElementType(
      const StaticContext& sctx,
      const std::string& nodeUri,
      const std::string& nodeLocalName,
      IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createAttributeType(
      const StaticContext& sctx,
      const std::string& nodeUri,
      const std::string& nodeLocalName,
      const std::string& contentTypeUri,
      const std::string& contentTypeLocalName,
      IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);
  
  static SequenceType 
  createSchemaAttributeType(
      const StaticContext& sctx,
      const std::string& nodeUri,
      const std::string& nodeLocalName,
      IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createPIType(IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);
  
  static SequenceType 
  createTextType(IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);
  
  static SequenceType 
  createCommentType(IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createNamespaceType(IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createJSONItemType(IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createJSONObjectType(IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);

  static SequenceType 
  createJSONArrayType(IdentTypes::Quantifier q = IdentTypes::QUANT_ONE);
}; // class SequenceType


#endif
