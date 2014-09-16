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

#ifndef ZORBA_API_SEQUENCE_TYPE
#define ZORBA_API_SEQUENCE_TYPE

#include <zorba/typeident.h>

#include "types/typeimpl.h"
#include "types/root_typemanager.h"

#include "diagnostics/assert.h"

#include "api/unmarshaller.h"

#include "context/static_context.h"

#include "store/api/item_factory.h"


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

}


namespace zorba 
{


char const *const SequenceType::kind_string_of[] = 
{
  "empty-sequence",
  "item",
  "AtomicOrUnion",
  "function",
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
  "*",
  "+",
  "INVALID",
  0
};



/*******************************************************************************

********************************************************************************/
SequenceType SequenceType::createEmptyType()
{
  return Unmarshaller::createSequenceType(GENV_TYPESYSTEM.EMPTY_TYPE.getp());
}


SequenceType SequenceType::createItemType(Quantifier quant)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  switch (quant)
  {
  case QUANT_ONE:
    return Unmarshaller::createSequenceType(rtm.ITEM_TYPE_ONE.getp());
  case QUANT_QUESTION:
    return Unmarshaller::createSequenceType(rtm.ITEM_TYPE_QUESTION.getp());
  case QUANT_PLUS:
    return Unmarshaller::createSequenceType(rtm.ITEM_TYPE_PLUS.getp());
  case QUANT_STAR:
    return Unmarshaller::createSequenceType(rtm.ITEM_TYPE_STAR.getp());
  default:
    ZORBA_ASSERT(false);
  }
}


SequenceType SequenceType::createAtomicOrUnionType(
    const StaticContext_t& sctx,
    const String& uri,
    const String& localName,
    Quantifier quant)
{
  TypeManager* tm;

  if (sctx == NULL)
  {
    tm = &GENV_TYPESYSTEM;
  }
  else
  {
    static_context* sctx2 = Unmarshaller::getInternalStaticContext(sctx);
    tm = sctx2->get_typemanager();
  }

  zstring& ns = Unmarshaller::getInternalString(uri);
  zstring& local = Unmarshaller::getInternalString(localName);

  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, ns, "", local);

  xqtref_t type = tm->create_named_type(qname, quant, QueryLoc::null, false);

  if (type->isGenAtomicAny())
    return Unmarshaller::createSequenceType(type.getp());

  return Unmarshaller::createSequenceType(NULL);
}


SequenceType SequenceType::createStructuredItemType(Quantifier quant)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  switch (quant)
  {
  case QUANT_ONE:
    return Unmarshaller::createSequenceType(rtm.STRUCTURED_ITEM_TYPE_ONE.getp());
  case QUANT_QUESTION:
    return Unmarshaller::createSequenceType(rtm.STRUCTURED_ITEM_TYPE_QUESTION.getp());
  case QUANT_PLUS:
    return Unmarshaller::createSequenceType(rtm.STRUCTURED_ITEM_TYPE_PLUS.getp());
  case QUANT_STAR:
    return Unmarshaller::createSequenceType(rtm.STRUCTURED_ITEM_TYPE_STAR.getp());
  default:
    ZORBA_ASSERT(false);
  }
}


SequenceType SequenceType::createAnyNodeType(Quantifier quant)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  switch (quant)
  {
  case QUANT_ONE:
    return Unmarshaller::createSequenceType(rtm.ANY_NODE_TYPE_ONE.getp());
  case QUANT_QUESTION:
    return Unmarshaller::createSequenceType(rtm.ANY_NODE_TYPE_QUESTION.getp());
  case QUANT_PLUS:
    return Unmarshaller::createSequenceType(rtm.ANY_NODE_TYPE_PLUS.getp());
  case QUANT_STAR:
    return Unmarshaller::createSequenceType(rtm.ANY_NODE_TYPE_STAR.getp());
  default:
    ZORBA_ASSERT(false);
  }
}


SequenceType SequenceType::createDocumentType(
    const SequenceType& contentType,
    Quantifier quant)
{
  const XQType* contentType2 = Unmarshaller::getInternalType(contentType);

  TypeManager* tm = (contentType2 == NULL ?
                     &GENV_TYPESYSTEM :
                     contentType2->get_manager());

  store::Item_t qname;

  xqtref_t res = tm->create_node_type(store::StoreConsts::documentNode,
                                      qname,
                                      contentType2,
                                      quant,
                                      false,
                                      false);

  return Unmarshaller::createSequenceType(res.getp());
}


SequenceType SequenceType::createElementType(
    const StaticContext_t& sctx,
    const String& nodeUri,
    const String& nodeLocalName,
    const String& typeUri,
    const String& typeLocalName,
    bool nillable,
    Quantifier quant)
{
  TypeManager* tm;

  if (sctx == NULL)
  {
    tm = &GENV_TYPESYSTEM;
  }
  else
  {
    static_context* sctx2 = Unmarshaller::getInternalStaticContext(sctx);
    tm = sctx2->get_typemanager();
  }

  zstring& nodeNS = Unmarshaller::getInternalString(nodeUri);
  zstring& nodeLocal = Unmarshaller::getInternalString(nodeLocalName);
  store::Item_t nodeQName;

  if (!nodeLocal.empty())
    GENV_ITEMFACTORY->createQName(nodeQName, nodeNS, "", nodeLocal);

  zstring& typeNS = Unmarshaller::getInternalString(typeUri);
  zstring& typeLocal = Unmarshaller::getInternalString(typeLocalName);
  store::Item_t typeQName;
  xqtref_t contentType;

  if (!typeLocal.empty())
  {
    GENV_ITEMFACTORY->createQName(typeQName, typeNS, "", typeLocal);

    contentType = tm->create_named_type(typeQName, QUANT_ONE, QueryLoc::null, false);

    if (contentType == NULL)
      return Unmarshaller::createSequenceType(NULL);
  }

  xqtref_t res = tm->create_node_type(store::StoreConsts::elementNode,
                                      nodeQName,
                                      contentType,
                                      quant,
                                      nillable,
                                      false);

  return Unmarshaller::createSequenceType(res.getp());
}

#ifndef ZORBA_NO_FULL_TEXT
SequenceType SequenceType::createSchemaElementType(
    const StaticContext_t& sctx,
    const String& uri,
    const String& localName,
    Quantifier quant)
{
  ZORBA_ASSERT(sctx != NULL);

  static_context* sctx2 = Unmarshaller::getInternalStaticContext(sctx);

  TypeManager* tm = sctx2->get_typemanager();

  zstring& ns = Unmarshaller::getInternalString(uri);
  zstring& local = Unmarshaller::getInternalString(localName);
  store::Item_t qname;

  ZORBA_ASSERT(!local.empty());

  GENV_ITEMFACTORY->createQName(qname, ns, "", local);

  try
  {
    xqtref_t res = tm->create_schema_element_type(qname, quant, QueryLoc::null);

    return Unmarshaller::createSequenceType(res.getp());
  }
  catch (...)
  {
    return Unmarshaller::createSequenceType(NULL);
  }
}
#endif

SequenceType SequenceType::createAttributeType(
    const StaticContext_t& sctx,
    const String& nodeUri,
    const String& nodeLocalName,
    const String& typeUri,
    const String& typeLocalName,
    Quantifier quant)
{
  TypeManager* tm;

  if (sctx == NULL)
  {
    tm = &GENV_TYPESYSTEM;
  }
  else
  {
    static_context* sctx2 = Unmarshaller::getInternalStaticContext(sctx);
    tm = sctx2->get_typemanager();
  }

  zstring& nodeNS = Unmarshaller::getInternalString(nodeUri);
  zstring& nodeLocal = Unmarshaller::getInternalString(nodeLocalName);
  store::Item_t nodeQName;

  if (!nodeLocal.empty())
    GENV_ITEMFACTORY->createQName(nodeQName, nodeNS, "", nodeLocal);

  zstring& typeNS = Unmarshaller::getInternalString(typeUri);
  zstring& typeLocal = Unmarshaller::getInternalString(typeLocalName);
  store::Item_t typeQName;
  xqtref_t contentType;

  if (!typeLocal.empty())
  {
    GENV_ITEMFACTORY->createQName(typeQName, typeNS, "", typeLocal);

    contentType = tm->create_named_type(typeQName, QUANT_ONE, QueryLoc::null, false);

    if (contentType == NULL)
      return Unmarshaller::createSequenceType(NULL);
  }

  xqtref_t res = tm->create_node_type(store::StoreConsts::attributeNode,
                                      nodeQName,
                                      contentType,
                                      quant,
                                      false,
                                      false);

  return Unmarshaller::createSequenceType(res.getp());
}

#ifndef ZORBA_NO_FULL_TEXT
SequenceType SequenceType::createSchemaAttributeType(
    const StaticContext_t& sctx,
    const String& uri,
    const String& localName,
    Quantifier quant)
{
  ZORBA_ASSERT(sctx != NULL);

  static_context* sctx2 = Unmarshaller::getInternalStaticContext(sctx);

  TypeManager* tm = sctx2->get_typemanager();

  zstring& ns = Unmarshaller::getInternalString(uri);
  zstring& local = Unmarshaller::getInternalString(localName);
  store::Item_t qname;

  ZORBA_ASSERT(!local.empty());

  GENV_ITEMFACTORY->createQName(qname, ns, "", local);

  try
  {
    xqtref_t res = tm->create_schema_attribute_type(qname, quant, QueryLoc::null);

    return Unmarshaller::createSequenceType(res.getp());
  }
  catch (...)
  {
    return Unmarshaller::createSequenceType(NULL);
  }
}
#endif

SequenceType SequenceType::createPIType(Quantifier quant)
{
  TypeManager* tm = &GENV_TYPESYSTEM;

  xqtref_t res = tm->create_node_type(store::StoreConsts::piNode,
                                      NULL,
                                      NULL,
                                      quant,
                                      false,
                                      false);

  return Unmarshaller::createSequenceType(res.getp());
}


SequenceType SequenceType::createTextType(Quantifier quant)
{
  TypeManager* tm = &GENV_TYPESYSTEM;

  xqtref_t res = tm->create_node_type(store::StoreConsts::textNode,
                                      NULL,
                                      NULL,
                                      quant,
                                      false,
                                      false);

  return Unmarshaller::createSequenceType(res.getp());
}


SequenceType SequenceType::createCommentType(Quantifier quant)
{
  TypeManager* tm = &GENV_TYPESYSTEM;

  xqtref_t res = tm->create_node_type(store::StoreConsts::commentNode,
                                      NULL,
                                      NULL,
                                      quant,
                                      false,
                                      false);

  return Unmarshaller::createSequenceType(res.getp());
}


SequenceType SequenceType::createNamespaceType(Quantifier quant)
{
  TypeManager* tm = &GENV_TYPESYSTEM;

  xqtref_t res = tm->create_node_type(store::StoreConsts::namespaceNode,
                                      NULL,
                                      NULL,
                                      quant,
                                      false,
                                      false);

  return Unmarshaller::createSequenceType(res.getp());
}


SequenceType SequenceType::createJSONItemType(Quantifier q)
{
  TypeManager* tm = &GENV_TYPESYSTEM;

  xqtref_t res = tm->create_json_type(store::StoreConsts::jsonItem, q);

  return Unmarshaller::createSequenceType(res.getp());
}


SequenceType SequenceType::createJSONObjectType(Quantifier q)
{
  TypeManager* tm = &GENV_TYPESYSTEM;

  xqtref_t res = tm->create_json_type(store::StoreConsts::jsonObject, q);

  return Unmarshaller::createSequenceType(res.getp());
}


SequenceType SequenceType::createJSONArrayType(Quantifier q)
{
  TypeManager* tm = &GENV_TYPESYSTEM;

  xqtref_t res = tm->create_json_type(store::StoreConsts::jsonArray, q);

  return Unmarshaller::createSequenceType(res.getp());
}



/*******************************************************************************

********************************************************************************/
SequenceType::SequenceType()
  :
  theType(NULL)
{
}


SequenceType::SequenceType(const XQType* type)
  :
  theType(type)
{
  if (theType)
    RCHelper::addReference(theType);
}


SequenceType::SequenceType(const SequenceType& other)
  :
  theType(other.theType)
{
  if (theType)
    RCHelper::addReference(theType);
}


SequenceType::~SequenceType()
{
  if (theType)
  {
    RCHelper::removeReference(const_cast<XQType*>(theType));
    theType = NULL;
  }
}


bool SequenceType::isValid() const
{
  return theType != NULL;
}


SequenceType::Quantifier SequenceType::getQuantifier() const
{
  if (theType == NULL)
    return QUANT_INVALID;

  return (theType->get_quantifier());
}


SequenceType::Kind SequenceType::getKind() const
{
  if (theType == NULL)
    return INVALID_TYPE;

  switch (theType->type_kind()) 
  {
  case XQType::EMPTY_KIND:
  {
    return EMPTY_TYPE;
  }
  case XQType::ITEM_KIND:
  {
    return ITEM_TYPE;
  }
  case XQType::ATOMIC_TYPE_KIND:
  {
    return ATOMIC_OR_UNION_TYPE;
  }
  case XQType::USER_DEFINED_KIND:
  {
    if (theType->isGenAtomicAny())
      return ATOMIC_OR_UNION_TYPE;
    else
      return INVALID_TYPE;
  }
  case XQType::STRUCTURED_ITEM_KIND:
  {
    return STRUCTURED_ITEM_TYPE;
  }
  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType* nt = static_cast<const NodeXQType*>(theType);

    switch (nt->get_node_kind()) 
    {
    case store::StoreConsts::anyNode:
    {
      return NODE_TYPE;
    }
    case store::StoreConsts::documentNode:
    {
      return DOCUMENT_TYPE;
    }
    case store::StoreConsts::elementNode:
    {
      if (nt->is_schema_test())
        return SCHEMA_ELEMENT_TYPE;
      else
        return ELEMENT_TYPE;
    }
    case store::StoreConsts::attributeNode:
    {
      if (nt->is_schema_test())
        return SCHEMA_ATTRIBUTE_TYPE;
      else
        return ATTRIBUTE_TYPE;
    }
    case store::StoreConsts::textNode:
    {
      return TEXT_TYPE;
    }
    case store::StoreConsts::commentNode:
    {
      return COMMENT_TYPE;
    }
    case store::StoreConsts::piNode:
    {
      return PI_TYPE;
    }
    case store::StoreConsts::namespaceNode:
    {
      return NAMESPACE_TYPE;
    }
    default:
    {
      ZORBA_ASSERT(false);
      return INVALID_TYPE;
    }
    }
  }
  case XQType::JSON_TYPE_KIND:
  {
    const JSONXQType* t = static_cast<const JSONXQType*>(theType);

    switch (t->get_json_kind())
    {
    case store::StoreConsts::jsonItem:
      return JSON_ITEM_TYPE;

    case store::StoreConsts::jsonObject:
      return JSON_OBJECT_TYPE;

    case store::StoreConsts::jsonArray:
      return JSON_ARRAY_TYPE;

    default:
      ZORBA_ASSERT(false);
    }
  }
  case XQType::UNTYPED_KIND:
  case XQType::ANY_TYPE_KIND:
  case XQType::ANY_SIMPLE_TYPE_KIND:
  default:
  {
    return INVALID_TYPE;
  }
  }
}


String SequenceType::getTypeUri() const
{
  switch (theType->type_kind())
  {
  case XQType::ATOMIC_TYPE_KIND:
  case XQType::USER_DEFINED_KIND:
  {
    store::Item_t qname = theType->getQName();

    return Unmarshaller::newString(qname->getNamespace());
  }
  default:
  {
    return String("");
  }
  }
}


String SequenceType::getTypeLocalName() const
{
  switch (theType->type_kind())
  {
  case XQType::ATOMIC_TYPE_KIND:
  case XQType::USER_DEFINED_KIND:
  {
    store::Item_t qname = theType->getQName();

    return Unmarshaller::newString(qname->getLocalName());
  }
  default:
  {
    return String("");
  }
  }
}


String SequenceType::getNodeUri() const
{
  if (theType->type_kind() == XQType::NODE_TYPE_KIND)
  {
    const NodeXQType* nt = static_cast<const NodeXQType*>(theType);

    if (nt->get_node_name() != NULL)
      return Unmarshaller::newString(nt->get_node_name()->getNamespace());
  }

  return String("");
}


String SequenceType::getNodeLocalName() const
{
  if (theType->type_kind() == XQType::NODE_TYPE_KIND)
  {
    const NodeXQType* nt = static_cast<const NodeXQType*>(theType);

    if (nt->get_node_name() != NULL)
      return Unmarshaller::newString(nt->get_node_name()->getLocalName());
  }

  return String("");
}


bool SequenceType::isWildcard() const
{
  if (theType->type_kind() == XQType::NODE_TYPE_KIND)
  {
    const NodeXQType* nt = static_cast<const NodeXQType*>(theType);

    store::StoreConsts::NodeKind nodeKind = nt->get_node_kind();

    if (nt->get_node_name() == NULL &&
        (nodeKind == store::StoreConsts::elementNode ||
         nodeKind == store::StoreConsts::attributeNode))
      return true;
  }

  return false;
}


SequenceType SequenceType::getContentType() const
{
  switch (theType->type_kind())
  {
  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType* nt = static_cast<const NodeXQType*>(theType);

    store::StoreConsts::NodeKind nodeKind = nt->get_node_kind();

    if (nodeKind == store::StoreConsts::documentNode)
    {
      const XQType* contentType = nt->get_content_type();

      return Unmarshaller::createSequenceType(contentType);
    }
  }
  default:
  {
    return Unmarshaller::createSequenceType(NULL);
  }
  }
}


String SequenceType::getContentTypeUri() const
{
  switch (theType->type_kind())
  {
  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType* nt = static_cast<const NodeXQType*>(theType);

    store::StoreConsts::NodeKind nodeKind = nt->get_node_kind();

    if (nodeKind == store::StoreConsts::elementNode ||
        nodeKind == store::StoreConsts::attributeNode)
    {
      const XQType* contentType = nt->get_content_type();

      if (contentType != NULL)
        return Unmarshaller::newString(contentType->getQName()->getNamespace());
    }
  }
  default:
  {
    return String("");
  }
  }
}


String SequenceType::getContentTypeLocalName() const
{
  switch (theType->type_kind())
  {
  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType* nt = static_cast<const NodeXQType*>(theType);

    store::StoreConsts::NodeKind nodeKind = nt->get_node_kind();

    if (nodeKind == store::StoreConsts::elementNode ||
        nodeKind == store::StoreConsts::attributeNode)
    {
      const XQType* contentType = nt->get_content_type();

      if (contentType != NULL)
        return Unmarshaller::newString(contentType->getQName()->getLocalName());
    }
  }
  default:
  {
    return String("");
  }
  }
}


bool SequenceType::isSchemaTest() const
{
  if (theType->type_kind() == XQType::NODE_TYPE_KIND)
  {
    const NodeXQType* nt = static_cast<const NodeXQType*>(theType);

    return nt->is_schema_test();
  }

  return false;
}


std::ostream& SequenceType::emit(std::ostream& os) const 
{
  return os << theType->toSchemaString();
}


}


#endif
/* vim:set et sw=2 ts=2: */
