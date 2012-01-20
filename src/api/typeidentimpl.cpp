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

#ifndef ZORBA_TYPEIDENT_IMPL_H
#define ZORBA_TYPEIDENT_IMPL_H

#include <zorba/typeident.h>

namespace zorba {

TypeIdentifier::TypeIdentifier()
  :
  m_kind(IdentTypes::INVALID_TYPE),
  m_quantifier(IdentTypes::QUANT_ONE),
  m_uri(""),
  m_uriWildcard(false),
  m_localName(""),
  m_localNameWildcard(false),
  m_contentType()
{
}

TypeIdentifier::~TypeIdentifier()
{
}

IdentTypes::kind_t TypeIdentifier::getKind() const
{
    return m_kind;
}

IdentTypes::quantifier_t TypeIdentifier::getQuantifier() const
{
  return m_quantifier;
}


const String& TypeIdentifier::getUri() const
{
  return m_uri;
}


bool TypeIdentifier::isUriWildcard() const
{
  return m_uriWildcard;
}


const String& TypeIdentifier::getLocalName() const
{
  return m_localName;
}


bool TypeIdentifier::isLocalNameWildcard() const
{
  return m_localNameWildcard;
}


TypeIdentifier_t TypeIdentifier::getContentType() const
{
  return m_contentType;
}


TypeIdentifier_t TypeIdentifier::createNamedType(
    const String& uri,
    const String& localName,
    IdentTypes::quantifier_t quantifier)
{
    TypeIdentifier_t ti(new TypeIdentifier());
    ti->m_kind = IdentTypes::NAMED_TYPE;
    ti->m_quantifier = quantifier;
    ti->m_uri = uri;
    ti->m_localName = localName;

    return ti;
}


TypeIdentifier_t TypeIdentifier::createElementType(
    const String& uri,
    bool uriWildcard,
    const String& localName,
    bool localNameWildcard,
    TypeIdentifier_t contentType,
    IdentTypes::quantifier_t quantifier)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::ELEMENT_TYPE;
  ti->m_quantifier = quantifier;
  ti->m_uri = uri;
  ti->m_uriWildcard = uriWildcard;
  ti->m_localName = localName;
  ti->m_localNameWildcard = localNameWildcard;
  ti->m_contentType = contentType;

  return ti;
}


TypeIdentifier_t TypeIdentifier::createAttributeType(
    const String& uri,
    bool uriWildcard,
    const String& localName,
    bool localNameWildcard,
    TypeIdentifier_t contentType,
    IdentTypes::quantifier_t quantifier)
{
    TypeIdentifier_t ti(new TypeIdentifier());
    ti->m_kind = IdentTypes::ATTRIBUTE_TYPE;
    ti->m_quantifier = quantifier;
    ti->m_uri = uri;
    ti->m_uriWildcard = uriWildcard;
    ti->m_localName = localName;
    ti->m_localNameWildcard = localNameWildcard;
    ti->m_contentType = contentType;

    return ti;
}


TypeIdentifier_t TypeIdentifier::createDocumentType(
    TypeIdentifier_t contentType,
    IdentTypes::quantifier_t quantifier)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::DOCUMENT_TYPE;
  ti->m_quantifier = quantifier;
  ti->m_contentType = contentType;
  
  return ti;
}


TypeIdentifier_t TypeIdentifier::createPIType(IdentTypes::quantifier_t quantifier)
{
    TypeIdentifier_t ti(new TypeIdentifier());
    ti->m_kind = IdentTypes::PI_TYPE;
    ti->m_quantifier = quantifier;

    return ti;
}


TypeIdentifier_t TypeIdentifier::createTextType(IdentTypes::quantifier_t quantifier)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::TEXT_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


TypeIdentifier_t TypeIdentifier::createCommentType(IdentTypes::quantifier_t quantifier)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::COMMENT_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


TypeIdentifier_t TypeIdentifier::createAnyNodeType(IdentTypes::quantifier_t quantifier)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::ANY_NODE_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


#ifdef ZORBA_WITH_JSON

TypeIdentifier_t TypeIdentifier::createStructuredItemType(IdentTypes::quantifier_t q)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::STRUCTURED_ITEM_TYPE;
  ti->m_quantifier = q;

  return ti;
}


TypeIdentifier_t TypeIdentifier::createJSONItemType(IdentTypes::quantifier_t q)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::JSON_ITEM_TYPE;
  ti->m_quantifier = q;

  return ti;
}


TypeIdentifier_t TypeIdentifier::createJSONObjectType(IdentTypes::quantifier_t q)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::JSON_OBJECT_TYPE;
  ti->m_quantifier = q;

  return ti;
}


TypeIdentifier_t TypeIdentifier::createJSONArrayType(IdentTypes::quantifier_t q)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::JSON_ARRAY_TYPE;
  ti->m_quantifier = q;

  return ti;
}


TypeIdentifier_t TypeIdentifier::createJSONPairType(IdentTypes::quantifier_t q)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::JSON_PAIR_TYPE;
  ti->m_quantifier = q;

  return ti;
}
#endif


TypeIdentifier_t TypeIdentifier::createItemType(IdentTypes::quantifier_t quantifier)
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::ITEM_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


TypeIdentifier_t TypeIdentifier::createEmptyType()
{
  TypeIdentifier_t ti(new TypeIdentifier());
  ti->m_kind = IdentTypes::EMPTY_TYPE;

  return ti;
}

}

#endif
/* vim:set et sw=2 ts=2: */
