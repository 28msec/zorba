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

#include "diagnostics/assert.h"


namespace std 
{

ostream& operator<<(ostream& o, const zorba::SequenceType::Kind k) 
{
  return o << zorba::SequenceType::kind_string_of[k];
}

ostream& operator<<(ostream& o, const zorba::SequenceType::Quantifier q) 
{
  return o << zorba::SequenceType::quantifier_string_of[q];
}


ostream& operator<<(ostream& o, const zorba::SequenceType& ti) 
{
  return ti.emit(o);
}

ostream& operator<<(ostream& o, const zorba::SequenceType_t ti) 
{
  return ti->emit(o);
}


}


namespace zorba 
{


char const *const SequenceType::kind_string_of[] = 
{
  "empty-sequence",
  "item",
  "AtomicOrUnion",
  "structured-item",
  "node",
  "document-node",
  "element",
  "schema-element",
  "attribute",
  "schema-attribute",
  "processing-instruction",
  "text",
  "comment",
  "namespace-node",
  "json-item",
  "object",
  "array",
  "INVALID",
  0
};


char const *const SequenceType::quantifier_string_of[] = 
{
  "",
  "?",
  "+",
  "*",
  0
};



SequenceType_t SequenceType::createEmptyType()
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = EMPTY_TYPE;
  ti->m_quantifier = QUANT_ONE;

  return ti;
}


SequenceType_t SequenceType::createItemType(Quantifier quantifier)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = ITEM_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


SequenceType_t SequenceType::createNamedType(
    const String& uri,
    const String& localName,
    Quantifier quantifier)
{
    SequenceType_t ti(new SequenceType());
    ti->m_kind = ATOMIC_OR_UNION_TYPE;
    ti->m_quantifier = quantifier;
    ti->m_uri = uri;
    ti->m_localName = localName;

    return ti;
}


SequenceType_t SequenceType::createStructuredItemType(Quantifier q)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = ANY_STRUCTURED_ITEM_TYPE;
  ti->m_quantifier = q;

  return ti;
}


SequenceType_t SequenceType::createAnyNodeType(Quantifier quantifier)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = ANY_NODE_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


SequenceType_t SequenceType::createDocumentType(
    SequenceType_t contentType,
    Quantifier quantifier)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = DOCUMENT_TYPE;
  ti->m_quantifier = quantifier;
  ti->m_contentType = contentType;
  
  return ti;
}


SequenceType_t SequenceType::createElementType(
    const String& uri,
    bool uriWildcard,
    const String& localName,
    bool localNameWildcard,
    SequenceType_t contentType,
    Quantifier quantifier)
{
  // not sure why those were 2 different flags, we maintain 2 flags for
  // compatibility, but they always need to be the same
  ZORBA_ASSERT(uriWildcard == localNameWildcard);
  SequenceType_t ti(new SequenceType());
  ti->m_kind = ELEMENT_TYPE;
  ti->m_quantifier = quantifier;
  ti->m_uri = uri;
  ti->m_uriWildcard = uriWildcard;
  ti->m_localName = localName;
  ti->m_localNameWildcard = localNameWildcard;
  ti->m_contentType = contentType;

  return ti;
}


SequenceType_t SequenceType::createSchemaElementType(
    const String& uri,
    const String& localName,
    Quantifier quantifier)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = SCHEMA_ELEMENT_TYPE;
  ti->m_quantifier = quantifier;
  ti->m_uri = uri;
  ti->m_uriWildcard = false;
  ti->m_localName = localName;
  ti->m_localNameWildcard = false;
  
  return ti;
}


SequenceType_t SequenceType::createAttributeType(
    const String& uri,
    bool uriWildcard,
    const String& localName,
    bool localNameWildcard,
    SequenceType_t contentType,
    Quantifier quantifier)
{
    // not sure why those were 2 different flags, we maintain 2 flags for
    // compatibility, but they always need to be the same
    ZORBA_ASSERT(uriWildcard == localNameWildcard);
    SequenceType_t ti(new SequenceType());
    ti->m_kind = ATTRIBUTE_TYPE;
    ti->m_quantifier = quantifier;
    ti->m_uri = uri;
    ti->m_uriWildcard = uriWildcard;
    ti->m_localName = localName;
    ti->m_localNameWildcard = localNameWildcard;
    ti->m_contentType = contentType;

    return ti;
}


SequenceType_t SequenceType::createSchemaAttributeType(
    const String& uri,
    const String& localName,
    Quantifier quantifier)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = SCHEMA_ATTRIBUTE_TYPE;
  ti->m_quantifier = quantifier;
  ti->m_uri = uri;
  ti->m_uriWildcard = false;
  ti->m_localName = localName;
  ti->m_localNameWildcard = false;
  
  return ti;
}


SequenceType_t SequenceType::createPIType(Quantifier quantifier)
{
    SequenceType_t ti(new SequenceType());
    ti->m_kind = PI_TYPE;
    ti->m_quantifier = quantifier;

    return ti;
}


SequenceType_t SequenceType::createTextType(Quantifier quantifier)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = TEXT_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


SequenceType_t SequenceType::createCommentType(Quantifier quantifier)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = COMMENT_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


SequenceType_t SequenceType::createNamespaceType(Quantifier quantifier)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = NAMESPACE_TYPE;
  ti->m_quantifier = quantifier;

  return ti;
}


SequenceType_t SequenceType::createJSONItemType(Quantifier q)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = JSON_ITEM_TYPE;
  ti->m_quantifier = q;

  return ti;
}


SequenceType_t SequenceType::createJSONObjectType(Quantifier q)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = JSON_OBJECT_TYPE;
  ti->m_quantifier = q;

  return ti;
}


SequenceType_t SequenceType::createJSONArrayType(Quantifier q)
{
  SequenceType_t ti(new SequenceType());
  ti->m_kind = JSON_ARRAY_TYPE;
  ti->m_quantifier = q;

  return ti;
}




SequenceType::SequenceType()
  :
  m_kind(INVALID_TYPE),
  m_quantifier(QUANT_ONE),
  m_uri(""),
  m_uriWildcard(false),
  m_localName(""),
  m_localNameWildcard(false),
  m_contentType()
{
}


SequenceType::~SequenceType()
{
}


SequenceType::Kind SequenceType::getKind() const
{
  return m_kind;
}


SequenceType::Quantifier SequenceType::getQuantifier() const
{
  return m_quantifier;
}


const String& SequenceType::getUri() const
{
  return m_uri;
}


bool SequenceType::isUriWildcard() const
{
  return m_uriWildcard;
}


const String& SequenceType::getLocalName() const
{
  return m_localName;
}


bool SequenceType::isLocalNameWildcard() const
{
  return m_localNameWildcard;
}


SequenceType_t SequenceType::getContentType() const
{
  return m_contentType;
}


std::ostream& SequenceType::emit(std::ostream& os) const 
{
  emitItemType(os);
  return os << m_quantifier;
}


std::ostream& SequenceType::emitItemType(std::ostream& os) const 
{
  if (m_kind == ATOMIC_OR_UNION_TYPE) 
  {
    return emitName(os);
  }

  os << m_kind;

  switch (m_kind) 
  {
    case DOCUMENT_TYPE:
      os << "(";
      if (m_contentType != NULL)
      {
        os << m_contentType;
      }
      return os << ")";

    case ELEMENT_TYPE:
    case ATTRIBUTE_TYPE:
      os << "(";
      if (m_uriWildcard) 
      {
        os << "*";
      }
      else
      {
        emitName(os);
      }
      if (! m_contentType.isNull()) 
      {
        os << "," << m_contentType;
      }
      return os << ")";

    case SCHEMA_ELEMENT_TYPE:
    case SCHEMA_ATTRIBUTE_TYPE:
      os << "(";
      emitName(os);
      return os << ")";

    case ANY_NODE_TYPE:
    case COMMENT_TYPE:
    case EMPTY_TYPE:
    case ITEM_TYPE:
    case PI_TYPE:
    case TEXT_TYPE:
      return os << "()";

    case INVALID_TYPE:
      return os;

    case ATOMIC_OR_UNION_TYPE:
    default:
      ZORBA_ASSERT(false);
  }
}


std::ostream& SequenceType::emitName(std::ostream& os) const 
{
    return os << "{" << m_uri << "}" << m_localName;
}

}


#endif
/* vim:set et sw=2 ts=2: */
