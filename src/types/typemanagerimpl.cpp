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

#include <zorba/typeident.h>

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "system/globalenv.h"
#include "zorbamisc/ns_consts.h"

#include "types/node_test.h"
#include "types/typemanagerimpl.h"
#include "types/typeimpl.h"
#include "types/root_typemanager.h"
#include "types/schema/schema.h"

#include "store/api/iterator.h"
#include "store/api/item_factory.h"

#include "runtime/hof/function_item.h"

#include "compiler/parser/query_loc.h"

#include "functions/signature.h"

#include "util/string_util.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

#include "context/static_context.h"

#ifdef ZORBA_XBROWSER
#include "DOMQName.h"
#endif


using namespace zorba;
#ifndef ZORBA_NO_XMLSCHEMA
XERCES_CPP_NAMESPACE_USE
#endif


SERIALIZE_INTERNAL_METHOD(TypeManager)

SERIALIZABLE_CLASS_VERSIONS(TypeManagerImpl)


/***************************************************************************//**

********************************************************************************/
TypeManagerImpl::TypeManagerImpl(TypeManager* parent)
  :
  TypeManager(parent ? parent->level() + 1 : 0),
  m_parent(parent),
  m_schema(NULL)
{
  // This is too expensive. Do it only if relly necessary
  //initializeSchema();
}


/***************************************************************************//**

********************************************************************************/
void TypeManager::serialize(::zorba::serialization::Archiver& ar)
{
  ar & m_level;
}


/***************************************************************************//**

********************************************************************************/
void TypeManagerImpl::serialize(::zorba::serialization::Archiver& ar)
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
  ZORBA_ASSERT(this != &GENV_TYPESYSTEM);

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
xqtref_t TypeManagerImpl::create_any_simple_type() const
{
  return GENV_TYPESYSTEM.ANY_SIMPLE_TYPE;
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
xqtref_t TypeManagerImpl::create_any_item_type(SequenceType::Quantifier q) const
{
  switch(q)
  {
    case SequenceType::QUANT_ONE:
      return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
    case SequenceType::QUANT_QUESTION:
      return GENV_TYPESYSTEM.ITEM_TYPE_QUESTION;
    case SequenceType::QUANT_STAR:
      return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
    case SequenceType::QUANT_PLUS:
      return GENV_TYPESYSTEM.ITEM_TYPE_PLUS;
    default:
      return xqtref_t(0);
  }
}


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_any_function_type(
    SequenceType::Quantifier quantifier) const
{
  switch(quantifier)
  {
    case SequenceType::QUANT_ONE:
      return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE;
    case SequenceType::QUANT_QUESTION:
      return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_QUESTION;
    case SequenceType::QUANT_STAR:
      return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_STAR;
    case SequenceType::QUANT_PLUS:
      return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_PLUS;
    default:
      return xqtref_t(0);
  }
}


/******************************************************************************

*******************************************************************************/
xqtref_t TypeManagerImpl::create_function_type(
    const std::vector<xqtref_t>& paramTypes,
    const xqtref_t& returnType,
    SequenceType::Quantifier quant) const
{
  return new FunctionXQType(this, paramTypes, returnType, quant, false);
}


/***************************************************************************//**
  Return the builtin sequence type corresponding to the given typecode and
  quantifier. The typecode identifies a builtin atomic type.
********************************************************************************/
xqtref_t TypeManagerImpl::create_builtin_atomic_type(
    store::SchemaTypeCode type_code,
    SequenceType::Quantifier quantifier) const
{
  return *GENV_TYPESYSTEM.m_atomic_typecode_map[type_code][quantifier];
}


/***************************************************************************//**
  Create a sequence type from the given typename and quantifier. The typename
  is assumed to be of an atomic type. If not, or if no type with this name is
  found in the in-scope schema, the method will return NULL or raise an error,
  depending on the value of the "error" param.
********************************************************************************/
xqtref_t TypeManagerImpl::create_named_atomic_type(
    store::Item* qname,
    SequenceType::Quantifier quantifier,
    const QueryLoc& loc,
    bool raiseError) const
{
  // Try to resolve the type name as a builtin atomic type
  RootTypeManager::qnametype_map_t& myMap = GENV_TYPESYSTEM.m_atomic_qnametype_map;

  store::SchemaTypeCode code = store::XS_LAST;

  if (myMap.get(qname, code))
    return create_builtin_atomic_type(code, quantifier);

  // If the type name is an XML Schema builtin type, then it cannot be an atomic
  // type (because, otherwise it would have been found above). So we return NULL.
  if (qname->getNamespace() == static_context::W3C_XML_SCHEMA_NS)
  {
    if (raiseError)
    {
			RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(qname->getStringValue(), ZED(NotAmongInScopeSchemaTypes)));
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
      if (raiseError)
      {
				RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(qname->getStringValue(), ZED(NotAmongInScopeSchemaTypes)));
      }
      else
      {
        return NULL;
      }
    }

    ZORBA_ASSERT(namedType->type_kind() == XQType::USER_DEFINED_KIND);

    const UserDefinedXQType* udt =
    reinterpret_cast<const UserDefinedXQType*>(namedType.getp());

    if (udt->isAtomicAny())
      return create_type(*namedType, quantifier);
  }
#endif

  if (raiseError)
  {
		RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(qname->getStringValue(), ZED(NotAmongInScopeSchemaTypes)));
  }
  else
  {
    return NULL;
  }

  return NULL;
}


/***************************************************************************//**
  Create an XML Schema type from the given typename. The typename is assumed to
  be of a simple type. If not, or if no type with this name is found in the
  in-scope schema, the method will return NULL.
********************************************************************************/
xqtref_t TypeManagerImpl::create_named_simple_type(store::Item* qname) const
{
  // Try to resolve the type name as a builtin atomic type
  RootTypeManager::qnametype_map_t& myMap = GENV_TYPESYSTEM.m_atomic_qnametype_map;

  store::SchemaTypeCode code = store::XS_LAST;

  if (myMap.get(qname, code))
    return create_builtin_atomic_type(code, SequenceType::QUANT_ONE);

  // If the type name is an XML Schema builtin type, then it can only be one of
  // xs:NMTOKES, xs:IDREFS, or xs:ENTITIES.
  if (qname->getNamespace() == static_context::W3C_XML_SCHEMA_NS)
  {
    RootTypeManager& rtm = GENV_TYPESYSTEM;

    if (qname->equals(rtm.XS_NMTOKENS_QNAME))
      return rtm.XS_NMTOKENS_TYPE;

    if (qname->equals(rtm.XS_IDREFS_QNAME))
      return rtm.XS_IDREFS_TYPE;

    if (qname->equals(rtm.XS_ENTITIES_QNAME))
      return rtm.XS_ENTITIES_TYPE;
 
    if (qname->equals(rtm.XS_ANY_SIMPLE_TYPE_QNAME))
      return rtm.ANY_SIMPLE_TYPE;

    return NULL;
  }

#ifndef ZORBA_NO_XMLSCHEMA
  // See if there is a type declaration for this type name in the in-scope
  // schema, if any.
  if (m_schema != NULL)
  {
    xqtref_t namedType = m_schema->createXQTypeFromTypeName(this, qname);

    if (namedType == NULL)
    {
      return NULL;
    }

    ZORBA_ASSERT(namedType->type_kind() == XQType::USER_DEFINED_KIND);

    const UserDefinedXQType* udt =
    reinterpret_cast<const UserDefinedXQType*>(namedType.getp());

    if (udt->isAtomicAny() || udt->isList() || udt->isUnion())
      return create_type_x_quant(*namedType, SequenceType::QUANT_ONE);
  }
#endif

  return NULL;
}


/***************************************************************************//**
  Create an XMLSchema type from the given typename and quantifier.
********************************************************************************/
xqtref_t TypeManagerImpl::create_named_type(
    store::Item* qname,
    SequenceType::Quantifier quant,
    const QueryLoc& loc,
    bool raiseError) const
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
  else if (qname->equals(RTM.XS_IDREFS_QNAME.getp()))
  {
    return RTM.XS_IDREFS_TYPE;
  }
  else if (qname->equals(RTM.XS_NMTOKENS_QNAME.getp()))
  {
    return RTM.XS_NMTOKENS_TYPE;
  }
  else if (qname->equals(RTM.XS_ENTITIES_QNAME.getp()))
  {
    return RTM.XS_ENTITIES_TYPE;
  }
  else
  {
    // Try to resolve the type name as a builtin atomic type
    RootTypeManager::qnametype_map_t& myMap = RTM.m_atomic_qnametype_map;

    store::SchemaTypeCode code = store::XS_LAST;

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
        if (raiseError)
        {
					RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(qname->getStringValue(), ZED(NotAmongInScopeSchemaTypes)));
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

    if (raiseError)
    {
			RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(qname->getStringValue(), ZED(NotAmongInScopeSchemaTypes)));
    }
    else
    {
      return NULL;
    }
  }
}


/***************************************************************************//**

********************************************************************************/
xqtref_t TypeManagerImpl::create_structured_item_type(
    SequenceType::Quantifier q) const
{
  switch(q)
  {
    case SequenceType::QUANT_ONE:
      return GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_ONE;
    case SequenceType::QUANT_QUESTION:
      return GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_QUESTION;
    case SequenceType::QUANT_STAR:
      return GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_STAR;
    case SequenceType::QUANT_PLUS:
      return GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_PLUS;
    default:
      return xqtref_t(0);
  }
}


/***************************************************************************//**
  Create a sequence type based on json item kind and a quantifier
********************************************************************************/
xqtref_t TypeManagerImpl::create_json_type(
    store::StoreConsts::JSONItemKind kind,
    SequenceType::Quantifier quantifier) const
{
  return GENV_TYPESYSTEM.JSON_TYPES_MAP[kind][quantifier];
}


/***************************************************************************//**
  Create a sequence type whose ItemType is a KindTest and has a given quantifier.
********************************************************************************/
xqtref_t TypeManagerImpl::create_node_type(
    store::StoreConsts::NodeKind nodeKind,
    const store::Item_t& nodeName,
    const xqtref_t& contType,
    SequenceType::Quantifier quant,
    bool nillable,
    bool schematest) const
{
  RootTypeManager& RTM = GENV_TYPESYSTEM;

  bool untyped = (contType == RTM.UNTYPED_TYPE ||
                  (nodeKind == store::StoreConsts::attributeNode &&
                   contType == RTM.UNTYPED_ATOMIC_TYPE_ONE));

  xqtref_t contentType = contType;

  if (contentType == NULL)
    contentType = RTM.ANY_TYPE;

  switch (nodeKind)
  {
  case store::StoreConsts::anyNode:
    return create_builtin_node_type(nodeKind, quant, untyped);

  case store::StoreConsts::documentNode:
  {
    if (contentType == RTM.UNTYPED_TYPE || contentType == RTM.ANY_TYPE)
    {
      return create_builtin_node_type(nodeKind, quant, untyped);
    }
    else
    {
      return new NodeXQType(this,
                            nodeKind,
                            NULL,
                            contentType,
                            quant,
                            false,
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
                            quant,
                            nillable,
                            schematest,
                            false);
    }
    else
    {
      return create_builtin_node_type(nodeKind, quant, untyped);
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
                            quant,
                            false,
                            schematest,
                            false);
    }
    else
    {
      return create_builtin_node_type(nodeKind, quant, untyped);
    }
  }

  case store::StoreConsts::textNode:
  case store::StoreConsts::commentNode:
  case store::StoreConsts::namespaceNode:
    return create_builtin_node_type(nodeKind, quant, true);

  case store::StoreConsts::piNode:
  {
    if (nodeName == NULL)
    {
      return create_builtin_node_type(nodeKind, quant, true);
    }
    else
    {
      return new NodeXQType(this,
                            nodeKind,
                            nodeName,
                            RTM.STRING_TYPE_ONE,
                            quant,
                            nillable,
                            false,
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
    case SequenceType::QUANT_ONE:                          \
      return GENV_TYPESYSTEM.kind##_UNTYPED_TYPE_ONE;       \
    case SequenceType::QUANT_QUESTION:                     \
      return GENV_TYPESYSTEM.kind##_UNTYPED_TYPE_QUESTION;  \
    case SequenceType::QUANT_STAR:                         \
      return GENV_TYPESYSTEM.kind##_UNTYPED_TYPE_STAR;      \
    case SequenceType::QUANT_PLUS:                         \
      return GENV_TYPESYSTEM.kind##_UNTYPED_TYPE_PLUS;      \
    default:                                                \
      ZORBA_ASSERT(false);                                  \
    }                                                       \
  }                                                         \
  else                                                      \
  {                                                         \
    switch(quantifier)                                      \
    {                                                       \
    case SequenceType::QUANT_ONE:                          \
      return GENV_TYPESYSTEM.kind##_TYPE_ONE;               \
    case SequenceType::QUANT_QUESTION:                     \
      return GENV_TYPESYSTEM.kind##_TYPE_QUESTION;          \
    case SequenceType::QUANT_STAR:                         \
      return GENV_TYPESYSTEM.kind##_TYPE_STAR;              \
    case SequenceType::QUANT_PLUS:                         \
      return GENV_TYPESYSTEM.kind##_TYPE_PLUS;              \
    default:                                                \
      ZORBA_ASSERT(false);                                  \
    }                                                       \
  }


xqtref_t TypeManagerImpl::create_builtin_node_type(
    store::StoreConsts::NodeKind nodeKind,
    SequenceType::Quantifier quantifier,
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
    case SequenceType::QUANT_ONE:
      return GENV_TYPESYSTEM.TEXT_TYPE_ONE;
    case SequenceType::QUANT_QUESTION:
      return GENV_TYPESYSTEM.TEXT_TYPE_QUESTION;
    case SequenceType::QUANT_STAR:
      return GENV_TYPESYSTEM.TEXT_TYPE_STAR;
    case SequenceType::QUANT_PLUS:
      return GENV_TYPESYSTEM.TEXT_TYPE_PLUS;
    default:
      ZORBA_ASSERT(false);
    }
  }

  case store::StoreConsts::piNode:
  {
    switch(quantifier)
    {
    case SequenceType::QUANT_ONE:
      return GENV_TYPESYSTEM.PI_TYPE_ONE;
    case SequenceType::QUANT_QUESTION:
      return GENV_TYPESYSTEM.PI_TYPE_QUESTION;
    case SequenceType::QUANT_STAR:
      return GENV_TYPESYSTEM.PI_TYPE_STAR;
    case SequenceType::QUANT_PLUS:
      return GENV_TYPESYSTEM.PI_TYPE_PLUS;
    default:
      ZORBA_ASSERT(false);
    }
  }

  case store::StoreConsts::commentNode:
  {
    switch(quantifier)
    {
    case SequenceType::QUANT_ONE:
    return GENV_TYPESYSTEM.COMMENT_TYPE_ONE;
    case SequenceType::QUANT_QUESTION:
      return GENV_TYPESYSTEM.COMMENT_TYPE_QUESTION;
    case SequenceType::QUANT_STAR:
      return GENV_TYPESYSTEM.COMMENT_TYPE_STAR;
    case SequenceType::QUANT_PLUS:
      return GENV_TYPESYSTEM.COMMENT_TYPE_PLUS;
    default:
      ZORBA_ASSERT(false);
    }
  }

  case store::StoreConsts::namespaceNode:
  {
    switch(quantifier)
    {
    case SequenceType::QUANT_ONE:
    return GENV_TYPESYSTEM.NAMESPACE_TYPE_ONE;
    case SequenceType::QUANT_QUESTION:
      return GENV_TYPESYSTEM.NAMESPACE_TYPE_QUESTION;
    case SequenceType::QUANT_STAR:
      return GENV_TYPESYSTEM.NAMESPACE_TYPE_STAR;
    case SequenceType::QUANT_PLUS:
      return GENV_TYPESYSTEM.NAMESPACE_TYPE_PLUS;
    default:
      ZORBA_ASSERT(false);
    }
  }

  default:
    ZORBA_ASSERT(false);
    return GENV_TYPESYSTEM.NONE_TYPE;
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
    SequenceType::Quantifier quant,
    const QueryLoc& loc) const
{
  if (m_schema == NULL)
  {
    RAISE_ERROR(err::XPST0008, loc,
    ERROR_PARAMS(ZED(XPST0008_SchemaElementName_2), elemName->getStringValue()));
  }

  bool nillable;

  xqtref_t contentType =
  m_schema->createXQTypeFromGlobalElementDecl(this, elemName, true, nillable, loc);

  return create_node_type(store::StoreConsts::elementNode,
                          elemName,
                          contentType,
                          quant,
                          nillable,
                          true); // schematest
}


/***************************************************************************//**
  Get the name of the type associated with a given globally declared element name.
********************************************************************************/
void TypeManagerImpl::get_schema_element_typeinfo(
    const store::Item* elemName,
    store::Item_t& typeName,
    bool& nillable,
    const QueryLoc& loc) const
{
  if (m_schema == NULL)
  {
    RAISE_ERROR(err::XPST0008, loc,
    ERROR_PARAMS(ZED(XPST0008_SchemaElementName_2), elemName->getStringValue()));
  }

  m_schema->getInfoFromGlobalElementDecl(elemName, typeName, nillable, loc);
}


/***************************************************************************//**
  Create a sequence type of the form "attribute(attrName, tname) quant", where
  quant is a given quantifier, attrName is a given attribute qname, attrName is
  a globaly declared attribute name, and tname is the name of the type associated
  with attrName in the in-scope schema declarations.
********************************************************************************/
xqtref_t TypeManagerImpl::create_schema_attribute_type(
    const store::Item_t& attrName,
    SequenceType::Quantifier quant,
    const QueryLoc& loc) const
{
  if (m_schema == NULL)
  {
    RAISE_ERROR(err::XPST0008, loc,
    ERROR_PARAMS(ZED(XPST0008_SchemaAttributeName_2), attrName->getStringValue()));
  }

  xqtref_t contentType =
  m_schema->createXQTypeFromGlobalAttributeDecl(this, attrName, true, loc);

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
void TypeManagerImpl::get_schema_attribute_typeinfo(
    const store::Item* attrName,
    store::Item_t& typeName,
    const QueryLoc& loc)
{
  if (m_schema == NULL)
  {
    RAISE_ERROR(err::XPST0008, loc,
    ERROR_PARAMS(ZED(XPST0008_SchemaAttributeName_2), attrName->getStringValue()));
  }

  m_schema->getInfoFromGlobalAttributeDecl(attrName, typeName, loc);
}


#endif // ZORBA_NO_XMLSCHEMA


/***************************************************************************//**
  Create a sequence type based on the kind and content of an item.
********************************************************************************/
xqtref_t TypeManagerImpl::create_value_type(
    const store::Item* item,
    const QueryLoc& loc) const
{
  SequenceType::Quantifier quant = SequenceType::QUANT_ONE;

  if (item->isAtomic())
  {
    return create_named_atomic_type(item->getType(),
                                    quant,
                                    loc,
                                    true);
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
                                               true);

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
    case store::StoreConsts::namespaceNode:
    {
      return GENV_TYPESYSTEM.NAMESPACE_TYPE_ONE;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }

  else if (item->isJSONItem())
  {
    return create_json_type(item->getJSONItemKind(), quant);
  }

  else if (item->isFunction())
  {
    const FunctionItem* fitem = static_cast<const FunctionItem*>(item);
    const signature& sig = fitem->getSignature();
    const xqtref_t& retType = sig.returnType();
    const xqtref_t& nonOptimizedRetType = sig.getNonOptimizedReturnType();
    std::vector<xqtref_t> paramTypes;
    
    assert(fitem->getStartArity() <= sig.paramCount());
    
    for (csize i = 0; i < fitem->getStartArity(); ++i)
    {
      // In case some of the parameters of the function have been partially applied,
      // the type of the function needs to be adjusted accordingly -- by skipping
      // the corresponding signature parameter types.
      if ( ! fitem->isArgumentApplied(i))
        paramTypes.push_back(sig[i]);
    }

    return new FunctionXQType(this,
                              paramTypes,
                              nonOptimizedRetType.getp() ? nonOptimizedRetType : retType,
                              quant,
                              false);
  }

  else
  {
    ZORBA_ASSERT(false);
    return NULL;
  }
}


/***************************************************************************//**
  Create a sequence type with a given quantifier and the same ItemType as the
  one of a given type.
********************************************************************************/
xqtref_t TypeManagerImpl::create_type(
    const XQType& type,
    SequenceType::Quantifier quantifier) const
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
      return new NodeXQType(nt, quantifier, false);
    }
  }

  case XQType::STRUCTURED_ITEM_KIND:
  {
    return create_structured_item_type(quantifier);
  }

  case XQType::JSON_TYPE_KIND:
  {
    const JSONXQType& jt = static_cast<const JSONXQType&>(type);
    return create_json_type(jt.get_json_kind(), quantifier);
  }

  case XQType::FUNCTION_TYPE_KIND:
  {
    const FunctionXQType& ft = static_cast<const FunctionXQType&>(type);
    return new FunctionXQType(this,
                              ft.get_param_types(),
                              ft.get_return_type(),
                              quantifier,
                              false);
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
    return (quantifier == SequenceType::QUANT_ONE ||
            quantifier == SequenceType::QUANT_PLUS ?
            GENV_TYPESYSTEM.NONE_TYPE :
            GENV_TYPESYSTEM.EMPTY_TYPE);

  case XQType::USER_DEFINED_KIND:
  {
    const UserDefinedXQType& udt = static_cast<const UserDefinedXQType&>(type);

    if (udt.isList())
    {
      return new UserDefinedXQType(this,
                                   udt.isAnonymous(),
                                   udt.getQName(),
                                   udt.getBaseType(),
                                   udt.getListItemType(),
                                   false);
    }
    else if (udt.isUnion())
    {
      return new UserDefinedXQType(this,
                                   udt.isAnonymous(),
                                   udt.getQName(),
                                   udt.getBaseType(),
                                   quantifier,
                                   udt.getUnionItemTypes(),
                                   false);
    }
    else
    {
      return new UserDefinedXQType(this,
                                   udt.isAnonymous(),
                                   udt.getQName(),
                                   udt.getBaseType(),
                                   quantifier,
                                   udt.getUDTKind(),
                                   udt.contentKind(),
                                   false);
    }
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
    SequenceType::Quantifier quantifier) const
{
  return create_type(type,
                     RootTypeManager::QUANT_UNION_MATRIX[type.get_quantifier()]
                                                        [quantifier]);
}

/* vim:set et sw=2 ts=2: */
