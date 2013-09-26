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

  switch (quantifier)
  {
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


IdentTypes::Kind SequenceType::getKind()
{
  zorba::SequenceType::Kind lKind = theSequenceType.getKind();

  IdentTypes::Kind result = IdentTypes::NODE_TYPE;

  switch (lKind)
  {
  case zorba::SequenceType::EMPTY_TYPE:
    result = IdentTypes::EMPTY_TYPE;
    break;
  case zorba::SequenceType::ITEM_TYPE:
    result = IdentTypes::ITEM_TYPE;
    break;
  case zorba::SequenceType::ATOMIC_OR_UNION_TYPE:
    result = IdentTypes::ATOMIC_OR_UNION_TYPE;
    break;
  case zorba::SequenceType::FUNCTION_TYPE:
    result = IdentTypes::FUNCTION_TYPE;
    break;
  case zorba::SequenceType::STRUCTURED_ITEM_TYPE:
    result = IdentTypes::STRUCTURED_ITEM_TYPE;
    break;
  case zorba::SequenceType::NODE_TYPE:
    result = IdentTypes::NODE_TYPE;
    break;
  case zorba::SequenceType::DOCUMENT_TYPE:
    result = IdentTypes::DOCUMENT_TYPE;
    break;
  case zorba::SequenceType::ELEMENT_TYPE:
    result = IdentTypes::ELEMENT_TYPE;
    break;
  case zorba::SequenceType::SCHEMA_ELEMENT_TYPE:
    result = IdentTypes::SCHEMA_ELEMENT_TYPE;
    break;
  case zorba::SequenceType::ATTRIBUTE_TYPE:
    result = IdentTypes::ATTRIBUTE_TYPE;
    break;
  case zorba::SequenceType::SCHEMA_ATTRIBUTE_TYPE:
    result = IdentTypes::SCHEMA_ATTRIBUTE_TYPE;
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
  case zorba::SequenceType::NAMESPACE_TYPE:
    result = IdentTypes::NAMESPACE_TYPE;
    break;
  case zorba::SequenceType::JSON_ITEM_TYPE:
    result = IdentTypes::JSON_ITEM_TYPE;
    break;
  case zorba::SequenceType::JSON_OBJECT_TYPE:
    result = IdentTypes::JSON_OBJECT_TYPE;
    break;
  case zorba::SequenceType::JSON_ARRAY_TYPE:
    result = IdentTypes::JSON_ARRAY_TYPE;
    break;
  case zorba::SequenceType::INVALID_TYPE:
    result = IdentTypes::INVALID_TYPE;
    break;
  }
  return result;
}
 

IdentTypes::Quantifier SequenceType::getQuantifier()
{
  zorba::SequenceType::Quantifier lQuantifier = theSequenceType.getQuantifier();

  switch (lQuantifier)
  {
  case zorba::SequenceType::QUANT_ONE:
    return IdentTypes::QUANT_ONE;
  case zorba::SequenceType::QUANT_QUESTION:
    return IdentTypes::QUANT_QUESTION;
  case zorba::SequenceType::QUANT_PLUS:
    return IdentTypes::QUANT_PLUS;
  case zorba::SequenceType::QUANT_STAR:
    return IdentTypes::QUANT_STAR;
  default:
    return IdentTypes::QUANT_ONE;
  }
}


const std::string SequenceType::getTypeLocalName()
{
  return std::string(theSequenceType.getTypeLocalName().c_str());
}


const std::string SequenceType::getTypeUri()
{
  return std::string(theSequenceType.getTypeUri().c_str());
}


const std::string SequenceType::getNodeLocalName()
{
  return std::string(theSequenceType.getNodeLocalName().c_str());
}


const std::string SequenceType::getNodeUri()
{
  return std::string(theSequenceType.getNodeUri().c_str());
}
 
 
const std::string SequenceType::getContentTypeLocalName()
{
  return std::string(theSequenceType.getContentTypeLocalName().c_str());
}


const std::string SequenceType::getContentTypeUri()
{
  return std::string(theSequenceType.getContentTypeUri().c_str());
}


bool SequenceType::isWildcard()
{
   return theSequenceType.isWildcard();
}


bool SequenceType::isSchemaTest()
{
  return theSequenceType.isSchemaTest();
}
  

  //  STATIC METHODS

SequenceType
SequenceType::createEmptyType()
{
  return SequenceType(zorba::SequenceType::createEmptyType());
}


SequenceType 
SequenceType::createItemType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createItemType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createAtomicOrUnionType(
    const StaticContext& sctx,
    const std::string& uri,
    const std::string& localName,
    IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createAtomicOrUnionType(sctx.theStaticContext,
                                               uri,
                                               localName,
                                               convertQuantifier(q)));
}


SequenceType 
SequenceType::createStructuredItemType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createStructuredItemType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createAnyNodeType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createAnyNodeType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createDocumentType(
    const SequenceType& contentType,
    IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createDocumentType(contentType.theSequenceType,
                                          convertQuantifier(q)));
}


SequenceType 
SequenceType::createElementType(
    const StaticContext& sctx,
    const std::string& nodeUri,
    const std::string& nodeLocalName,
    const std::string& contentTypeUri,
    const std::string& contentTypeLocalName,
    bool nillable,
    IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createElementType(sctx.theStaticContext,
                                         nodeUri,
                                         nodeLocalName,
                                         contentTypeUri,
                                         contentTypeLocalName,
                                         convertQuantifier(q)));
}


SequenceType 
SequenceType::createSchemaElementType(
    const StaticContext& sctx,
    const std::string& nodeUri,
    const std::string& nodeLocalName,
    IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createSchemaElementType(sctx.theStaticContext,
                                               nodeUri,
                                               nodeLocalName,
                                               convertQuantifier(q)));
}


SequenceType 
SequenceType::createAttributeType(
      const StaticContext& sctx,
      const std::string& nodeUri,
      const std::string& nodeLocalName,
      const std::string& contentTypeUri,
      const std::string& contentTypeLocalName,
      IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createElementType(sctx.theStaticContext,
                                         nodeUri,
                                         nodeLocalName,
                                         contentTypeUri,
                                         contentTypeLocalName,
                                         convertQuantifier(q)));
}


SequenceType 
SequenceType::createSchemaAttributeType(
    const StaticContext& sctx,
    const std::string& nodeUri,
    const std::string& nodeLocalName,
    IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createSchemaAttributeType(sctx.theStaticContext,
                                                 nodeUri,
                                                 nodeLocalName,
                                                 convertQuantifier(q)));
}


SequenceType 
SequenceType::createPIType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createPIType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createTextType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createTextType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createCommentType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createCommentType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createNamespaceType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createNamespaceType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createJSONItemType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createJSONItemType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createJSONObjectType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createJSONArrayType(convertQuantifier(q)));
}


SequenceType 
SequenceType::createJSONArrayType(IdentTypes::Quantifier q)
{
  return SequenceType(
  zorba::SequenceType::createJSONArrayType(convertQuantifier(q)));
}
  
  // END OF STATIC METHODS


%}  // end   Implementation


%include "SequenceType.h"
