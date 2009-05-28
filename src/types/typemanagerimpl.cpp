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
#include <assert.h>

#include <zorba/identtypes.h>
#include <zorba/typeident.h>

#include "zorbaerrors/Assert.h"
#include <zorbatypes/xerces_xmlcharray.h>

#include "system/globalenv.h"

#include "types/node_test.h"
#include "types/typemanagerimpl.h"
#include "types/typeimpl.h"
#include "types/root_typemanager.h"
#include "types/delegating_typemanager.h"
#include "types/schema/schema.h"

#include "store/api/item_factory.h"


#ifdef ZORBA_XBROWSER
#include "DOMQName.h"
#endif


using namespace zorba;
#ifndef ZORBA_NO_XMLSCHEMA
XERCES_CPP_NAMESPACE_USE
#endif


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_any_type() const
{
  return GENV_TYPESYSTEM.ANY_TYPE;
}


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_untyped_type() const
{
  return GENV_TYPESYSTEM.UNTYPED_TYPE;
}


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_empty_type() const
{
  return GENV_TYPESYSTEM.EMPTY_TYPE;
}


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_none_type() const
{
  return GENV_TYPESYSTEM.NONE_TYPE;
}


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_any_simple_type() const
{
  return GENV_TYPESYSTEM.ANY_SIMPLE_TYPE;
}


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_any_item_type(
    TypeConstants::quantifier_t quantifier) const
{
  switch(quantifier)
  {
    case TypeConstants::QUANT_ONE:
      return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
    case TypeConstants::QUANT_QUESTION:
      return GENV_TYPESYSTEM.ITEM_TYPE_QUESTION;
    case TypeConstants::QUANT_STAR:
      return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
    case TypeConstants::QUANT_PLUS:
      return GENV_TYPESYSTEM.ITEM_TYPE_PLUS;
    default:
      return xqtref_t(0);
  }
}


/***************************************************************************//**
  Return the builtin sequence type corresponding to the given typecode and
  quantifier. The typecode identifies a builtin atomic type.
********************************************************************************/
xqtref_t TypeManagerImpl::create_builtin_atomic_type(
    TypeConstants::atomic_type_code_t type_code,
    TypeConstants::quantifier_t quantifier) const
{
  return *GENV_TYPESYSTEM.m_atomic_typecode_map[type_code][quantifier];
}


/***************************************************************************//**
  Create a sequence type from the given typename and quantifier.

  Here, the typename is assumed to be of a builtin atomic type. If not, the
  method will return NULL. Class DelegatingTypeManager redefines this method
  to handle user-defined atomic types. 
********************************************************************************/
xqtref_t TypeManagerImpl::create_named_atomic_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const
{
  RootTypeManager::qnametype_map_t& myMap = GENV_TYPESYSTEM.m_atomic_qnametype_map;

  TypeConstants::atomic_type_code_t code = TypeConstants::INVALID_TYPE_CODE;

  return (myMap.get(qname, code) ?
          create_builtin_atomic_type(code, quantifier) :
          xqtref_t(NULL));
}


/***************************************************************************//**
  Create a sequence type from the given typename and quantifier.

  Here, the typename is assumed to be of a builtin type. If not, the method will
  return NULL. Class DelegatingTypeManager redefines this method to handle user-
  defined types. 
********************************************************************************/
xqtref_t TypeManagerImpl::create_named_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const
{
  if (qname->equals(GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME.getp()))
  {
    return create_any_type();
  }
  else if (qname->equals(GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME.getp()))
  {
    return create_any_simple_type();
  }
  else if (qname->equals(GENV_TYPESYSTEM.XS_UNTYPED_QNAME.getp())) 
  {
    return create_untyped_type();
  }
  else if (qname->equals(GENV_TYPESYSTEM.ZXSE_TUPLE_QNAME.getp()))
  {
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  }
  else
  {
    return create_named_atomic_type(qname, quantifier);
  }
}


/***************************************************************************//**
  Create a sequence type whose ItemType is a KindTest and has a given quantifier.
********************************************************************************/
xqtref_t TypeManagerImpl::create_node_type(
    store::StoreConsts::NodeKind nodeKind,
    const store::Item* nodeName,
    xqtref_t contentType,
    TypeConstants::quantifier_t quantifier,
    bool nillable) const
{
  bool untyped = (contentType == GENV_TYPESYSTEM.UNTYPED_TYPE);

  if (contentType == NULL)
    contentType = GENV_TYPESYSTEM.ANY_TYPE;

  switch (nodeKind)
  {
  case store::StoreConsts::anyNode:
    return create_builtin_node_type(nodeKind, quantifier, untyped);

  case store::StoreConsts::documentNode:
  {
    if (contentType == GENV_TYPESYSTEM.UNTYPED_TYPE ||
        contentType == GENV_TYPESYSTEM.ANY_TYPE)
    {
      return create_builtin_node_type(nodeKind, quantifier, untyped);
    }
    else
    {
      return new NodeXQType(this,
                            nodeKind,
                            NULL,
                            contentType,
                            quantifier,
                            false);
    }
  }

  case store::StoreConsts::elementNode:
  case store::StoreConsts::attributeNode:
  {
    if (nodeName != NULL || 
        nillable ||
        (contentType != GENV_TYPESYSTEM.UNTYPED_TYPE &&
         contentType != GENV_TYPESYSTEM.ANY_TYPE))
    {
      return new NodeXQType(this,
                            nodeKind,
                            nodeName,
                            contentType,
                            quantifier,
                            nillable);

    }
    else if (nodeKind == store::StoreConsts::elementNode)
    {
      return create_builtin_node_type(nodeKind, quantifier, untyped);
    }
    else
    {
      return create_builtin_node_type(nodeKind, quantifier, untyped);
    }
  }

  case store::StoreConsts::textNode:
  case store::StoreConsts::commentNode:
    return create_builtin_node_type(nodeKind, quantifier, true);

  case store::StoreConsts::piNode:
  {
    if (nodeName == NULL)
    {
      return create_builtin_node_type(nodeKind, quantifier, true);
    }
    else
    {
      return new NodeXQType(this,
                            nodeKind,
                            nodeName,
                            contentType,
                            quantifier,
                            nillable);
    }
  }

  default:
    ZORBA_ASSERT(false);
    return GENV_TYPESYSTEM.NONE_TYPE;
  }
}


/***************************************************************************//**

********************************************************************************/

#define createBuiltinNodeType(quantifier, untyped, kind)    \
  if (untyped)                                              \
  {                                                         \
    switch(quantifier)                                      \
    {                                                       \
    case TypeConstants::QUANT_ONE:                          \
      return GENV_TYPESYSTEM.kind##_UNTYPED_TYPE_ONE;       \
    case TypeConstants::QUANT_QUESTION:                     \
      return GENV_TYPESYSTEM.kind##_UNTYPED_TYPE_QUESTION;  \
    case TypeConstants::QUANT_STAR:                         \
      return GENV_TYPESYSTEM.kind##_UNTYPED_TYPE_STAR;      \
    case TypeConstants::QUANT_PLUS:                         \
      return GENV_TYPESYSTEM.kind##_UNTYPED_TYPE_PLUS;      \
    default:                                                \
      ZORBA_ASSERT(false);                                  \
    }                                                       \
  }                                                         \
  else                                                      \
  {                                                         \
    switch(quantifier)                                      \
    {                                                       \
    case TypeConstants::QUANT_ONE:                          \
      return GENV_TYPESYSTEM.kind##_TYPE_ONE;               \
    case TypeConstants::QUANT_QUESTION:                     \
      return GENV_TYPESYSTEM.kind##_TYPE_QUESTION;          \
    case TypeConstants::QUANT_STAR:                         \
      return GENV_TYPESYSTEM.kind##_TYPE_STAR;              \
    case TypeConstants::QUANT_PLUS:                         \
      return GENV_TYPESYSTEM.kind##_TYPE_PLUS;              \
    default:                                                \
      ZORBA_ASSERT(false);                                  \
    }                                                       \
  }


xqtref_t TypeManagerImpl::create_builtin_node_type(
    store::StoreConsts::NodeKind nodeKind,
    TypeConstants::quantifier_t quantifier, 
    bool untyped) const
{
  switch (nodeKind)
  {
  case store::StoreConsts::anyNode:
    createBuiltinNodeType(quantifier, untyped, ANY_NODE);

  case store::StoreConsts::documentNode:
    createBuiltinNodeType(quantifier, untyped, DOCUMENT);

  case store::StoreConsts::elementNode:
    createBuiltinNodeType(quantifier, untyped, ELEMENT);

  case store::StoreConsts::attributeNode:
    createBuiltinNodeType(quantifier, untyped, ATTRIBUTE);

  case store::StoreConsts::textNode:
  {
    switch(quantifier)
    {
    case TypeConstants::QUANT_ONE:
      return GENV_TYPESYSTEM.TEXT_TYPE_ONE;
    case TypeConstants::QUANT_QUESTION:
      return GENV_TYPESYSTEM.TEXT_TYPE_QUESTION;
    case TypeConstants::QUANT_STAR:
      return GENV_TYPESYSTEM.TEXT_TYPE_STAR;
    case TypeConstants::QUANT_PLUS:
      return GENV_TYPESYSTEM.TEXT_TYPE_PLUS;
    default:
      ZORBA_ASSERT(false);
    }
  }

  case store::StoreConsts::piNode:
  {
    switch(quantifier)
    {
    case TypeConstants::QUANT_ONE:
      return GENV_TYPESYSTEM.PI_TYPE_ONE;
    case TypeConstants::QUANT_QUESTION:
      return GENV_TYPESYSTEM.PI_TYPE_QUESTION;
    case TypeConstants::QUANT_STAR:
      return GENV_TYPESYSTEM.PI_TYPE_STAR;
    case TypeConstants::QUANT_PLUS:
      return GENV_TYPESYSTEM.PI_TYPE_PLUS;
    default:
      ZORBA_ASSERT(false);
    }            
  }

  case store::StoreConsts::commentNode:
  {
    switch(quantifier)
    {
    case TypeConstants::QUANT_ONE:
    return GENV_TYPESYSTEM.COMMENT_TYPE_ONE;
    case TypeConstants::QUANT_QUESTION:
      return GENV_TYPESYSTEM.COMMENT_TYPE_QUESTION;
    case TypeConstants::QUANT_STAR:
      return GENV_TYPESYSTEM.COMMENT_TYPE_STAR;
    case TypeConstants::QUANT_PLUS:
      return GENV_TYPESYSTEM.COMMENT_TYPE_PLUS;
    default:
      ZORBA_ASSERT(false);
    }   
  }

  default:
    ZORBA_ASSERT(false);
    return GENV_TYPESYSTEM.NONE_TYPE;
  }
}


/***************************************************************************//**
  Create a sequence type with a given quantifier and the same ItemType as the
  one of a given type.
********************************************************************************/
xqtref_t TypeManagerImpl::create_type(
    const XQType& type,
    TypeConstants::quantifier_t quantifier) const
{
  if (type.get_quantifier() == quantifier)
    return &type;

  switch(type.type_kind())
  {
  case XQType::ATOMIC_TYPE_KIND:
  {
    return create_builtin_atomic_type(
                  static_cast<const AtomicXQType*>(&type)->get_type_code(),
                  quantifier);
  }

  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType& nt = static_cast<const NodeXQType&>(type);
    if (type.is_builtin())
    {
      return create_builtin_node_type(nt.get_node_kind(),
                                      quantifier,
                                      nt.is_untyped());
    }
    else
    {
      return new NodeXQType(nt, quantifier);
    }
  }

  case XQType::ITEM_KIND:
    return create_any_item_type(quantifier);

  case XQType::ANY_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_TYPE;

  case XQType::ANY_SIMPLE_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_SIMPLE_TYPE;

  case XQType::UNTYPED_KIND:
    return GENV_TYPESYSTEM.UNTYPED_TYPE;

  case XQType::EMPTY_KIND:
    return GENV_TYPESYSTEM.EMPTY_TYPE;

  case XQType::NONE_KIND:
    return (quantifier == TypeConstants::QUANT_ONE ||
            quantifier == TypeConstants::QUANT_PLUS ?
            GENV_TYPESYSTEM.NONE_TYPE :
            GENV_TYPESYSTEM.EMPTY_TYPE);

  case XQType::USER_DEFINED_KIND:
  {
    const UserDefinedXQType& udt = static_cast<const UserDefinedXQType&>(type);
    return xqtref_t(new UserDefinedXQType(this,
                                          udt.get_qname(),
                                          udt.getBaseType(),
                                          quantifier,
                                          udt.content_kind()));
  }
  default:
    ZORBA_ASSERT(false);
  }

  ZORBA_ASSERT (false);
  return 0;
}


/***************************************************************************//**
  Create a sequence type whose ItemType is the same as the one of a given type
  T, and whose quntifier is the union of T's quantifier and another given 
  quantifier.
********************************************************************************/
xqtref_t TypeManagerImpl::create_type_x_quant(
    const XQType& type,
    TypeConstants::quantifier_t quantifier) const
{
  return create_type(type,
                     RootTypeManager::QUANT_UNION_MATRIX[type.get_quantifier()]
                                                        [quantifier]);
}


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_type(const TypeIdentifier& ident) const
{
  TypeConstants::quantifier_t q = TypeConstants::QUANT_ONE;

  switch(ident.getQuantifier()) 
  {
    case IdentTypes::QUANT_ONE:
      q = TypeConstants::QUANT_ONE;
      break;

    case IdentTypes::QUANT_QUESTION:
      q = TypeConstants::QUANT_QUESTION;
      break;

    case IdentTypes::QUANT_PLUS:
      q = TypeConstants::QUANT_PLUS;
      break;

    case IdentTypes::QUANT_STAR:
      q = TypeConstants::QUANT_STAR;
      break;
  }

  switch(ident.getKind()) 
  {
  case IdentTypes::NAMED_TYPE:
  {
    store::Item_t i;
    GENV_ITEMFACTORY->createQName(i,
                                  ident.getUri().c_str(),
                                  NULL,
                                  ident.getLocalName().c_str());
    return create_named_type(i, q);
  }

  case IdentTypes::ELEMENT_TYPE:
  {
    store::Item_t ename;
    GENV_ITEMFACTORY->createQName(ename,
                                  ident.getUri().c_str(),
                                  NULL,
                                  ident.getLocalName().c_str());

    TypeIdentifier_t ci = ident.getContentType();
    xqtref_t content_type = (ci != NULL ? create_type(*ci) : xqtref_t(0));

    return create_node_type(store::StoreConsts::elementNode,
                            ename.getp(),
                            content_type,
                            q,
                            false);
  }

  case IdentTypes::ATTRIBUTE_TYPE:
  {
    store::Item_t aname;
    GENV_ITEMFACTORY->createQName(aname,
                                  ident.getUri().c_str(),
                                  NULL,
                                  ident.getLocalName().c_str());

    TypeIdentifier_t ci = ident.getContentType();
    xqtref_t content_type = (ci != NULL ? create_type(*ci) : xqtref_t(0));

    return create_node_type(store::StoreConsts::attributeNode,
                            aname.getp(),
                            content_type,
                            q,
                            false);
  }

  case IdentTypes::DOCUMENT_TYPE:
  {
    TypeIdentifier_t ci = ident.getContentType();
    xqtref_t content_type = (ci != NULL ? create_type(*ci) : xqtref_t(0));

    return create_node_type(store::StoreConsts::documentNode,
                            NULL,
                            content_type,
                            q,
                            false);
  }

  case IdentTypes::PI_TYPE:
    return create_builtin_node_type(store::StoreConsts::piNode, q, false);

  case IdentTypes::TEXT_TYPE:
    return create_builtin_node_type(store::StoreConsts::textNode, q, false);

  case IdentTypes::COMMENT_TYPE:
    return create_builtin_node_type(store::StoreConsts::commentNode, q, false);

  case IdentTypes::ANY_NODE_TYPE:
    return create_builtin_node_type(store::StoreConsts::anyNode, q, false);

  case IdentTypes::ITEM_TYPE:
    return create_any_item_type(q);

  case IdentTypes::EMPTY_TYPE:
    return create_empty_type();

  default:
    break;
  }

  return xqtref_t(0);
}


/***************************************************************************//**
  Create a sequence type based on the kind and content of an item.
********************************************************************************/
xqtref_t TypeManagerImpl::create_value_type(const store::Item* item) const 
{
  if (item->isAtomic())
  {
    return create_named_atomic_type(item->getType(), TypeConstants::QUANT_ONE);
  }
  else if (item->isNode())
  {
    store::NodeKind nodeKind = item->getNodeKind();

    switch (nodeKind)
    {
    case store::StoreConsts::elementNode:
    case store::StoreConsts::attributeNode:
    {
      return new NodeXQType(this,
                            nodeKind,
                            item->getNodeName(),
                            create_named_type(item->getType(),
                                              TypeConstants::QUANT_ONE),
                            TypeConstants::QUANT_ONE,
                            false);
    }
    case store::StoreConsts::documentNode:
    {
      store::Iterator_t childrenIte = item->getChildren();
      store::Item_t child;
      store::Item_t elemChild;
      bool foundElemChild = false;
      childrenIte->open();
      while (childrenIte->next(child))
      {
        if (child->getNodeKind() == store::StoreConsts::elementNode)
        {
          if (!foundElemChild)
            elemChild.transfer(child);
          else
            elemChild = NULL;
        }
      }
      childrenIte->close();

      if (elemChild == NULL)
        return GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE;;

      xqtref_t elemType = new NodeXQType(this,
                                         store::StoreConsts::elementNode,
                                         elemChild->getNodeName(),
                                         create_named_type(elemChild->getType(),
                                                           TypeConstants::QUANT_ONE),
                                         TypeConstants::QUANT_ONE,
                                         false);

      return new NodeXQType(this,
                            store::StoreConsts::documentNode,
                            NULL,
                            elemType,
                            TypeConstants::QUANT_ONE,
                            false);
    }
    case store::StoreConsts::textNode:
    {
      return GENV_TYPESYSTEM.TEXT_TYPE_ONE;
    }
    case store::StoreConsts::piNode:
    {
      return GENV_TYPESYSTEM.PI_TYPE_ONE;
    }
    case store::StoreConsts::commentNode:
    {
      return GENV_TYPESYSTEM.COMMENT_TYPE_ONE;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }
  else
  {
    ZORBA_ASSERT(false);
    return NULL;
  }
}


#ifndef ZORBA_NO_XMLSCHEMA

/***************************************************************************//**
  Create a sequence type of the form "element(ename, tname) quant", where
  quant is a given quantifier, ename is a given element qname, ename is a
  globaly declared element name, and tname is the name of the type associated
  with ename in the in-scope declarations.
********************************************************************************/
xqtref_t TypeManagerImpl::create_schema_element_type(
    store::Item* qname,
    TypeConstants::quantifier_t quant) const
{
  Schema* schema = static_cast<const DelegatingTypeManager *>(this)->getSchema();
  XMLGrammarPool* pool = schema->getGrammarPool();

#if _XERCES_VERSION >= 30000
  bool xsModelWasChanged;
  XSModel *model = pool->getXSModel(xsModelWasChanged);
#else
  XSModel *model = pool->getXSModel();
#endif

  XMLChArray local (qname->getLocalName()->c_str());
  XMLChArray uri (qname->getNamespace()->c_str());

  XSElementDeclaration* eDecl = model->getElementDeclaration(local, uri);
  if (!eDecl) 
  {
    ZORBA_ERROR_PARAM(XPST0008, "schema-element", qname->getStringValue()->c_str());
  }

  XSTypeDefinition* ct = eDecl->getTypeDefinition();
  const XMLCh *typeName = ct->getName();
  const XMLCh *typeUri = ct->getNamespace();
  store::Item_t tName;
  GENV_ITEMFACTORY->createQName(tName,
                                StrX(typeUri).localForm(),
                                "",
                                StrX(typeName).localForm());

  xqtref_t cType = schema->createIfExists(this, tName, TypeConstants::QUANT_ONE);

  rchandle<NodeNameTest> nnTest = new NodeNameTest(qname);
  rchandle<NodeTest> nTest = new NodeTest(store::StoreConsts::elementNode, nnTest);
  return new NodeXQType(this, nTest, cType, quant, false);
}


/***************************************************************************//**
  Get the name of the type associated with a given globally declared element name.
********************************************************************************/
void TypeManagerImpl::get_schema_element_typename(
    store::Item* elemName,
    store::Item_t& typeName)
{
  Schema* schema = static_cast<const DelegatingTypeManager *>(this)->getSchema();
  XMLGrammarPool* pool = schema->getGrammarPool();

#if _XERCES_VERSION >= 30000
  bool xsModelWasChanged;
  XSModel* model = pool->getXSModel(xsModelWasChanged);
#else
  XSModel* model = pool->getXSModel();
#endif

  XMLChArray local(elemName->getLocalName()->c_str());
  XMLChArray uri(elemName->getNamespace()->c_str());

  XSElementDeclaration *eDecl = model->getElementDeclaration(local, uri);
  if (!eDecl) 
  {
    ZORBA_ERROR_PARAM(XPST0008, "schema-element", elemName->getStringValueP()->c_str());
  }

  XSTypeDefinition* ct = eDecl->getTypeDefinition();
  const XMLCh* typeNameStr = ct->getName();
  const XMLCh* typeUri = ct->getNamespace();

  GENV_ITEMFACTORY->createQName(typeName,
                                StrX(typeUri).localForm(),
                                "",
                                StrX(typeNameStr).localForm());
}


/***************************************************************************//**
  Create a sequence type of the form "attribute(aname, tname) quant", where
  quant is a given quantifier, aname is a given attribute qname, aname is a
  globaly declared attribute name, and tname is the name of the type associated
  with aname in the in-scope declarations.
********************************************************************************/
xqtref_t TypeManagerImpl::create_schema_attribute_type(
    store::Item* qname,
    TypeConstants::quantifier_t quant) const
{
  Schema *schema = static_cast<const DelegatingTypeManager *>(this)->getSchema();
  XMLGrammarPool *pool = schema->getGrammarPool();

  bool xsModelWasChanged;
  XSModel *model = pool->getXSModel(xsModelWasChanged);
  XMLChArray local (qname->getLocalName()->c_str());
  XMLChArray uri (qname->getNamespace()->c_str());
  XSAttributeDeclaration *aDecl = model->getAttributeDeclaration(local, uri);
  if (!aDecl) {
    ZORBA_ERROR_PARAM(XPST0008, "schema-attribute", qname->getStringValueP()->c_str());
  }

  XSTypeDefinition *ct = aDecl->getTypeDefinition();
  const XMLCh *typeName = ct->getName();
  const XMLCh *typeUri = ct->getNamespace();
  store::Item_t tName;
  GENV_ITEMFACTORY->createQName(tName,
                                StrX(typeUri).localForm(),
                                "",
                                StrX(typeName).localForm());

  xqtref_t cType = schema->createIfExists(this, tName, TypeConstants::QUANT_ONE);

  rchandle<NodeNameTest> nnTest = new NodeNameTest(qname);
  rchandle<NodeTest> nTest = new NodeTest(store::StoreConsts::attributeNode, nnTest);
  return new NodeXQType(this, nTest, cType, quant, false);
}
#endif

/* vim:set ts=2 sw=2: */
