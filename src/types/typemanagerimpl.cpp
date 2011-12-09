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

#include <assert.h>

#include <zorba/identtypes.h>
#include <zorba/typeident.h>

#include "diagnostics/assert.h"

#include "system/globalenv.h"
#include "zorbamisc/ns_consts.h"

#include "types/node_test.h"
#include "types/typemanagerimpl.h"
#include "types/typeimpl.h"
#include "types/root_typemanager.h"
#include "types/schema/schema.h"

#include "store/api/iterator.h"
#include "store/api/item_factory.h"

#include "runtime/function_item/function_item.h"

#include "compiler/parser/query_loc.h"

#include "functions/signature.h"
#include "util/string_util.h"

#ifdef ZORBA_XBROWSER
#include "DOMQName.h"
#endif


using namespace zorba;
#ifndef ZORBA_NO_XMLSCHEMA
XERCES_CPP_NAMESPACE_USE
#endif

SERIALIZABLE_CLASS_VERSIONS(TypeManager)
END_SERIALIZABLE_CLASS_VERSIONS(TypeManager)

SERIALIZABLE_CLASS_VERSIONS(TypeManagerImpl)
END_SERIALIZABLE_CLASS_VERSIONS(TypeManagerImpl)


/***************************************************************************//**

********************************************************************************/
void TypeManagerImpl::serialize(::zorba::serialization::Archiver &ar)
{
  serialize_baseclass(ar, (TypeManager*)this);
  SERIALIZE_TYPEMANAGER(TypeManager, m_parent);
  ar & m_schema;
}


/***************************************************************************//**

********************************************************************************/
TypeManagerImpl::~TypeManagerImpl()
{
  delete m_schema;
}


/***************************************************************************//**

********************************************************************************/
void TypeManagerImpl::initializeSchema()
{
  if ( m_schema == NULL )
    m_schema = new Schema(this);
}


void TypeManagerImpl::terminateSchema()
{
  if ( m_schema != NULL )
  {
    delete m_schema;
    m_schema = NULL;
  }
}


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

********************************************************************************/
xqtref_t TypeManagerImpl::create_any_function_type(
    TypeConstants::quantifier_t quantifier) const
{
  switch(quantifier)
  {
    case TypeConstants::QUANT_ONE:
      return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE;
    case TypeConstants::QUANT_QUESTION:
      return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_QUESTION;
    case TypeConstants::QUANT_STAR:
      return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_STAR;
    case TypeConstants::QUANT_PLUS:
      return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_PLUS;
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
  Create a sequence type from the given typename and quantifier. The typename
  is assumed to be of an atomic type. If not, or if no type with this name is
  found in the in-scope schemaa, the method will return NULL. 
********************************************************************************/
xqtref_t TypeManagerImpl::create_named_atomic_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier,
    const QueryLoc& loc,
    const Error& error) const
{
  // Try to resolve the type name as a builtin atomic type
  RootTypeManager::qnametype_map_t& myMap = GENV_TYPESYSTEM.m_atomic_qnametype_map;

  TypeConstants::atomic_type_code_t code = TypeConstants::INVALID_TYPE_CODE;

  if (myMap.get(qname, code))
    return create_builtin_atomic_type(code, quantifier);

  // If the type name is an XML Schema builtin type, then it cannot be an atomic
  // type (because, otherwise it would have been found above). So we return NULL.
  if (ZSTREQ(qname->getNamespace(), XML_SCHEMA_NS))
  {
    if (error != zerr::ZXQP0000_NO_ERROR)
    {
			throw XQUERY_EXCEPTION_VAR(error,
			ERROR_PARAMS(qname->getStringValue(), ZED(NotAmongInScopeSchemaTypes)),
			ERROR_LOC(loc));
    }
    else
    {
      return NULL;
    }
  }

#ifndef ZORBA_NO_XMLSCHEMA
  // See if there is a type declaration for this type name in the in-scope
  // schema, if any.
  if (m_schema != NULL)
  {
    xqtref_t namedType = m_schema->createXQTypeFromTypeName(this, qname);

    if (namedType == NULL)
    {
      if (error != zerr::ZXQP0000_NO_ERROR)
      {
				throw XQUERY_EXCEPTION_VAR(error,
				ERROR_PARAMS(qname->getStringValue(), ZED( NotAmongInScopeSchemaTypes)),
				ERROR_LOC(loc));
      }
      else
      {
        return NULL;
      }
    }

    ZORBA_ASSERT(namedType->type_kind() == XQType::USER_DEFINED_KIND);

    const UserDefinedXQType* udt =
    reinterpret_cast<const UserDefinedXQType*>(namedType.getp());

    if (udt->isAtomic())
      return create_type(*namedType, quantifier);
  }
#endif

  if (error != zerr::ZXQP0000_NO_ERROR)
  {
		throw XQUERY_EXCEPTION_VAR(error,
		ERROR_PARAMS(qname->getStringValue(), ZED( NotAmongInScopeSchemaTypes)),
		ERROR_LOC(loc));
  }
  else
  {
    return NULL;
  }

  return NULL;
}


/***************************************************************************//**
  Create a type from the given typename and quantifier.
********************************************************************************/
xqtref_t TypeManagerImpl::create_named_type(
    store::Item* qname,
    TypeConstants::quantifier_t quant,
    const QueryLoc& loc,
    const Error& error) const
{
  RootTypeManager& RTM = GENV_TYPESYSTEM;

  if (qname->equals(RTM.XS_ANY_TYPE_QNAME.getp()))
  {
    return create_any_type();
  }
  else if (qname->equals(RTM.XS_ANY_SIMPLE_TYPE_QNAME.getp()))
  {
    return create_any_simple_type();
  }
  else if (qname->equals(RTM.XS_UNTYPED_QNAME.getp())) 
  {
    return create_untyped_type();
  }
  else
  {
    // Try to resolve the type name as a builtin atomic type
    RootTypeManager::qnametype_map_t& myMap = RTM.m_atomic_qnametype_map;

    TypeConstants::atomic_type_code_t code = TypeConstants::INVALID_TYPE_CODE;

    if (myMap.get(qname, code))
      return create_builtin_atomic_type(code, quant);

#ifndef ZORBA_NO_XMLSCHEMA
    // See if there is a type declaration for this type name in the in-scope
    // schemas, if any.
    if (m_schema != NULL)
    {
      xqtref_t namedType = m_schema->createXQTypeFromTypeName(this, qname);

      if (namedType == NULL)
      {
        if (error != zerr::ZXQP0000_NO_ERROR)
        {
					throw XQUERY_EXCEPTION_VAR(error,
					ERROR_PARAMS(qname->getStringValue(), ZED(NotAmongInScopeSchemaTypes)),
					ERROR_LOC(loc));
        }
        else
        {
          return NULL;
        }
      }

      ZORBA_ASSERT(namedType->type_kind() == XQType::USER_DEFINED_KIND);

      return create_type(*namedType, quant);
    }
#endif

    if (error != zerr::ZXQP0000_NO_ERROR)
    {
			throw XQUERY_EXCEPTION_VAR(error,
			ERROR_PARAMS(qname->getStringValue(), ZED(NotAmongInScopeSchemaTypes)),
			ERROR_LOC(loc));
    }
    else
    {
      return NULL;
    }
  }
}


/******************************************************************************

*******************************************************************************/
xqtref_t TypeManagerImpl::create_function_type(
        const std::vector<xqtref_t>& paramTypes,
        const xqtref_t& returnType,
        TypeConstants::quantifier_t quant) const
{
  return new FunctionXQType(this, paramTypes, returnType, quant);
}


/***************************************************************************//**
  Create a sequence type whose ItemType is a KindTest and has a given quantifier.
********************************************************************************/
xqtref_t TypeManagerImpl::create_node_type(
    store::StoreConsts::NodeKind nodeKind,
    const store::Item_t& nodeName,
    xqtref_t contentType,
    TypeConstants::quantifier_t quantifier,
    bool nillable,
    bool schematest) const
{
  RootTypeManager& RTM = GENV_TYPESYSTEM;

  bool untyped = (contentType == RTM.UNTYPED_TYPE || 
                  (nodeKind == store::StoreConsts::attributeNode &&
                   contentType == RTM.UNTYPED_ATOMIC_TYPE_ONE));

  if (contentType == NULL)
    contentType = RTM.ANY_TYPE;

  switch (nodeKind)
  {
  case store::StoreConsts::anyNode:
    return create_builtin_node_type(nodeKind, quantifier, untyped);

  case store::StoreConsts::documentNode:
  {
    if (contentType == RTM.UNTYPED_TYPE || contentType == RTM.ANY_TYPE)
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
                            false,
                            false);
    }
  }

  case store::StoreConsts::elementNode:
  {
    if (nodeName != NULL || 
        nillable ||
        (contentType != RTM.UNTYPED_TYPE && contentType != RTM.ANY_TYPE))
    {
      return new NodeXQType(this,
                            nodeKind,
                            nodeName,
                            contentType,
                            quantifier,
                            nillable,
                            schematest);
    }
    else
    {
      return create_builtin_node_type(nodeKind, quantifier, untyped);
    }
  }
  case store::StoreConsts::attributeNode:
  {
    if (nodeName != NULL || 
        (contentType != RTM.UNTYPED_ATOMIC_TYPE_ONE &&
         contentType != RTM.ANY_SIMPLE_TYPE))
    {
      return new NodeXQType(this,
                            nodeKind,
                            nodeName,
                            contentType,
                            quantifier,
                            false,
                            schematest);
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
                            RTM.STRING_TYPE_ONE,
                            quantifier,
                            nillable,
                            false);
    }
  }

  default:
    ZORBA_ASSERT(false);
    return RTM.NONE_TYPE;
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


#ifdef ZORBA_WITH_JSON
/***************************************************************************//**
  Create a sequence type based on json item kind and a quantifier
********************************************************************************/
xqtref_t TypeManagerImpl::create_json_type(
    store::StoreConsts::JSONItemKind kind,
    TypeConstants::quantifier_t quantifier) const
{
  return GENV_TYPESYSTEM.JSON_TYPES_MAP[kind][quantifier];
}
#endif


/***************************************************************************//**
  Create a sequence type based on the kind and content of an item.
********************************************************************************/
xqtref_t TypeManagerImpl::create_value_type(
    const store::Item* item,
    const QueryLoc& loc) const 
{
  TypeConstants::quantifier_t quant = TypeConstants::QUANT_ONE;

  if (item->isAtomic())
  {
    return create_named_atomic_type(item->getType(),
                                    quant,
                                    loc,
                                    err::XPTY0004);
  }
  else if (item->isNode())
  {
    store::NodeKind nodeKind = item->getNodeKind();

    switch (nodeKind)
    {
    case store::StoreConsts::elementNode:
    case store::StoreConsts::attributeNode:
    {
      xqtref_t contentType = create_named_type(item->getType(),
                                               quant,
                                               loc,
                                               err::XPTY0004);

      return create_node_type(nodeKind,
                              item->getNodeName(),
                              contentType,
                              quant,
                              false,
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
        return GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE;

      xqtref_t elemType = create_value_type(elemChild);

      return create_node_type(store::StoreConsts::documentNode,
                              NULL,
                              elemType,
                              quant,
                              false,
                              false);
    }
    case store::StoreConsts::textNode:
    {
      return GENV_TYPESYSTEM.TEXT_TYPE_ONE;
    }
    case store::StoreConsts::piNode:
    {
      return create_node_type(store::StoreConsts::piNode,
                              item->getNodeName(),
                              GENV_TYPESYSTEM.STRING_TYPE_ONE,
                              quant,
                              false,
                              false);
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

#ifdef ZORBA_WITH_JSON
  else if (item->isJSONItem())
  {
    return create_json_type(item->getJSONItemKind(), quant);
  }
#endif

  else if (item->isFunction())
  {
    const FunctionItem* lFItem = static_cast<const FunctionItem*>(item);
    const signature& lSig = lFItem->getSignature();
    const xqtref_t& lRetType = lSig.returnType();
    std::vector<xqtref_t> lParamTypes;
    for (uint32_t i = 0; i < lSig.paramCount(); ++i) 
    {
      lParamTypes.push_back(lSig[i]);
    }

    return new FunctionXQType(this, lParamTypes, lRetType, quant);
  }

  else
  {
    ZORBA_ASSERT(false);
    return NULL;
  }
}


#ifndef ZORBA_NO_XMLSCHEMA

/***************************************************************************//**
  Create a sequence type of the form "element(elemName, tname) quant", where
  quant is a given quantifier, elemName is a given element qname, elemName is a
  globaly declared element name, and tname is the name of the type associated
  with elemName in the in-scope schema declarations.
********************************************************************************/
xqtref_t TypeManagerImpl::create_schema_element_type(
    const store::Item_t& elemName,
    TypeConstants::quantifier_t quant,
    const QueryLoc& loc) const
{
  if (m_schema == NULL)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0008,
      ERROR_PARAMS( elemName->getStringValue(), ZED( SchemaElementName ) ),
      ERROR_LOC( loc )
    );
  }

  xqtref_t contentType = 
  m_schema->createXQTypeFromElementName(this, elemName, true, loc);

  return create_node_type(store::StoreConsts::elementNode,
                          elemName,
                          contentType,
                          quant,
                          false, // nillable
                          true); // schematest
}


/***************************************************************************//**
  Get the name of the type associated with a given globally declared element name.
********************************************************************************/
void TypeManagerImpl::get_schema_element_typename(
    const store::Item* elemName,
    store::Item_t& typeName,
    const QueryLoc& loc)
{
  if (m_schema == NULL)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0008,
      ERROR_PARAMS( elemName->getStringValue(), ZED( SchemaElementName ) ),
      ERROR_LOC( loc )
    );
  }

  m_schema->getTypeNameFromElementName(elemName, typeName, loc);
}


/***************************************************************************//**
  Create a sequence type of the form "attribute(attrName, tname) quant", where
  quant is a given quantifier, attrName is a given attribute qname, attrName is
  a globaly declared attribute name, and tname is the name of the type associated
  with attrName in the in-scope schema declarations.
********************************************************************************/
xqtref_t TypeManagerImpl::create_schema_attribute_type(
    const store::Item_t& attrName,
    TypeConstants::quantifier_t quant,
    const QueryLoc& loc) const
{
  if (m_schema == NULL)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0008,
      ERROR_PARAMS( attrName->getStringValue(), ZED( SchemaAttributeName ) ),
      ERROR_LOC( loc )
    );
  }

  xqtref_t contentType = 
  m_schema->createXQTypeFromAttributeName(this, attrName, true, loc);

  return create_node_type(store::StoreConsts::attributeNode,
                          attrName,
                          contentType,
                          quant,
                          false,
                          true);
}


/***************************************************************************//**
  Get the name of the type associated with a given globally declared attribute
  name.
********************************************************************************/
void TypeManagerImpl::get_schema_attribute_typename(
    const store::Item* attrName,
    store::Item_t& typeName,
    const QueryLoc& loc)
{
  if (m_schema == NULL)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0008,
      ERROR_PARAMS( attrName->getStringValue(), ZED( SchemaAttributeName ) ),
      ERROR_LOC( loc )
    );
  }

  m_schema->getTypeNameFromAttributeName(attrName, typeName, loc);
}


#endif // ZORBA_NO_XMLSCHEMA


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

#ifdef ZORBA_WITH_JSON
  case XQType::JSON_TYPE_KIND:
  {
    const JSONXQType& jt = static_cast<const JSONXQType&>(type);
    return create_json_type(jt.get_json_kind(), quantifier);
  }
#endif

  case XQType::FUNCTION_TYPE_KIND:
  {
    const FunctionXQType& ft = static_cast<const FunctionXQType&>(type);
    return new FunctionXQType(
        this,
        ft.get_param_types(),
        ft.get_return_type(),
        quantifier);
  }

  case XQType::ITEM_KIND:
    return create_any_item_type(quantifier);

  case XQType::ANY_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_TYPE;

  case XQType::ANY_SIMPLE_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_SIMPLE_TYPE;

  case XQType::ANY_FUNCTION_TYPE_KIND:
    return create_any_function_type(quantifier);

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
                                          udt.getTypeCategory(),
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
  T, and whose quantifier is the union of T's quantifier and another given 
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
    return create_named_type(i, q, QueryLoc::null, err::XPTY0004);
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
                            false,
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
                            false,
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
                            false,
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

  case IdentTypes::JSON_ITEM_TYPE:
    return create_json_type(store::StoreConsts::jsonItem, q);

  case IdentTypes::JSON_OBJECT_TYPE:
    return create_json_type(store::StoreConsts::jsonObject, q);

  case IdentTypes::JSON_ARRAY_TYPE:
    return create_json_type(store::StoreConsts::jsonArray, q);

  case IdentTypes::JSON_PAIR_TYPE:
    return create_json_type(store::StoreConsts::jsonPair, q);

  case IdentTypes::JSON_OBJECT_PAIR_TYPE:
    return create_json_type(store::StoreConsts::jsonPair, q);

  case IdentTypes::JSON_ARRAY_PAIR_TYPE:
    return create_json_type(store::StoreConsts::jsonArrayPair, q);

  case IdentTypes::ITEM_TYPE:
    return create_any_item_type(q);

  case IdentTypes::EMPTY_TYPE:
    return create_empty_type();

  default:
    break;
  }

  return xqtref_t(0);
}
/* vim:set et sw=2 ts=2: */
