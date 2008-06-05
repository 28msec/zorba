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
#include <zorba/item.h>
#include "zorbatypes/xqpstring.h"
#include "system/globalenv.h"
#include "types/node_test.h"
#include "types/typeops.h"
#include "store/api/item_factory.h"
//#include "store/api/store.h"
#include "types/typemanagerimpl.h"
#include "types/typeimpl.h"
#include "types/root_typemanager.h"
#include "zorbaerrors/Assert.h"
#include "zorbatypes/representations.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"

#ifdef ZORBA_XBROWSER
#include "DOMQName.h"
#endif


using namespace zorba;

xqtref_t TypeManagerImpl::create_type_x_quant(
    const XQType& type,
    TypeConstants::quantifier_t quantifier) const
{
  return create_type(type, RootTypeManager::QUANT_MULT_MATRIX[type.get_quantifier()][quantifier]);
}


xqtref_t TypeManagerImpl::create_type(
    const XQType& type,
    TypeConstants::quantifier_t quantifier) const
{
  // quantifier multiplication:
  // quantifier = QUANT_MULT_MATRIX [quantifier] [type.get_quantifier ()];
  // most code assumes that the quantifier arg *overrides* the original quantifier!
  switch(type.type_kind())
  {
  case XQType::ATOMIC_TYPE_KIND:
    return create_atomic_type(static_cast <const AtomicXQType *> (& type)->get_type_code(), quantifier);

  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType& nt = static_cast<const NodeXQType&>(type);
    return create_node_type(nt.get_nodetest(), nt.get_content_type(), quantifier);
  }

  case XQType::ANY_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_TYPE;

  case XQType::ITEM_KIND:
    return create_any_item_type(quantifier);

  case XQType::ANY_SIMPLE_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_SIMPLE_TYPE;

  case XQType::UNTYPED_KIND:
    return GENV_TYPESYSTEM.UNTYPED_TYPE;

  case XQType::EMPTY_KIND:
  case XQType::NONE_KIND:
    return GENV_TYPESYSTEM.EMPTY_TYPE;

  case XQType::USER_DEFINED_KIND:
  {
    const UserDefinedXQType& udt = static_cast<const UserDefinedXQType&>(type);
    return xqtref_t(new UserDefinedXQType(this, udt.getQName(), udt.getBaseType(), quantifier));
  }
  }

  assert(false);
  return 0;
}


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
    GENV_ITEMFACTORY->createQName(i, ident.getUri().c_str(), NULL, ident.getLocalName().c_str());
    return create_named_type(i, q);
  }

  case IdentTypes::ELEMENT_TYPE:
  {
    store::Item_t i;
    GENV_ITEMFACTORY->createQName(i, ident.getUri().c_str(), NULL, ident.getLocalName().c_str());
    rchandle<NodeNameTest> nnt(new NodeNameTest(i));
    rchandle<NodeTest> nt(new NodeTest(store::StoreConsts::elementNode, nnt));
    type_ident_ref_t ci = ident.getContentType();
    xqtref_t content_type = (ci != NULL ? create_type(*ci) : xqtref_t(0));
    return create_node_type(nt, content_type, q);
  }

  case IdentTypes::ATTRIBUTE_TYPE:
  {
    store::Item_t i;
    GENV_ITEMFACTORY->createQName(i, ident.getUri().c_str(), NULL, ident.getLocalName().c_str());
    rchandle<NodeNameTest> nnt(new NodeNameTest(i));
    rchandle<NodeTest> nt(new NodeTest(store::StoreConsts::attributeNode, nnt));
    type_ident_ref_t ci = ident.getContentType();
    xqtref_t content_type = (ci != NULL ? create_type(*ci) : xqtref_t(0));
    return create_node_type(nt, content_type, q);
  }

  case IdentTypes::DOCUMENT_TYPE:
  {
    type_ident_ref_t ci = ident.getContentType();
    xqtref_t content_type = ci != NULL ? create_type(*ci) : xqtref_t(0);
    return create_node_type(NodeTest::DOCUMENT_TEST, content_type, q);
  }

  case IdentTypes::PI_TYPE:
    return create_node_type(NodeTest::PI_TEST, GENV_TYPESYSTEM.NONE_TYPE, q);

  case IdentTypes::TEXT_TYPE:
    return create_node_type(NodeTest::TEXT_TEST, GENV_TYPESYSTEM.NONE_TYPE, q);

  case IdentTypes::COMMENT_TYPE:
    return create_node_type(NodeTest::COMMENT_TEST, GENV_TYPESYSTEM.NONE_TYPE, q);

  case IdentTypes::ANY_NODE_TYPE:
    return create_node_type(NodeTest::ANY_NODE_TEST, GENV_TYPESYSTEM.NONE_TYPE, q);

  case IdentTypes::ITEM_TYPE:
    return create_any_item_type(q);

  case IdentTypes::EMPTY_TYPE:
    return create_empty_type();

  default:
    break;
  }

  return xqtref_t(0);
}


xqtref_t TypeManagerImpl::create_value_type(store::Item* item) const 
{
  if (item->isAtomic ())
    return create_named_atomic_type(item->getType(), TypeConstants::QUANT_ONE);

  return create_node_type (new NodeTest (item->getNodeKind ()),
                           xqtref_t (NULL),
                           TypeConstants::QUANT_ONE);
}


xqtref_t TypeManagerImpl::create_named_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const
{
  if (qname == GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME.getp())
  {
    return create_any_type();
  }
  else if (qname == GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME.getp())
  {
    return create_any_simple_type();
  }
  else if (qname == GENV_TYPESYSTEM.XS_UNTYPED_QNAME.getp()) 
  {
    return create_untyped_type();
  }
  else
  {
    return create_named_atomic_type(qname, quantifier);
  }
}


xqtref_t TypeManagerImpl::create_node_type(
    rchandle<NodeTest> nodetest,
    xqtref_t content_type,
    TypeConstants::quantifier_t quantifier) const
{
  return new NodeXQType(this, nodetest, content_type, quantifier);
}


xqtref_t TypeManagerImpl::create_named_atomic_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const
{

  zorba::RootTypeManager::qnametype_map_t& myMap = GENV_TYPESYSTEM.m_atomic_qnametype_map;

  RootTypeManager::qnametype_map_t::const_iterator i =
	  myMap.find(qname);

  bool found = (i != myMap.end());
  if(found)
  {
	  return create_atomic_type(i->second, quantifier);
  } else {
#ifdef ZORBA_XBROWSER
	  RootTypeManager::qnametype_map_t::const_iterator i;
	  for(i = myMap.begin();i!=myMap.end();i++) {
		  xqp::DOMQName *q = static_cast<xqp::DOMQName*>(i->first);
		  if(q->getNamespace()->equals(qname->getNamespace())
			  && q->getLocalName()->equals(qname->getLocalName())
			  && q->getPrefix()->equals(qname->getPrefix())) {
				  return create_atomic_type(i->second, quantifier);
		  }
	  }
#endif
	  return xqtref_t (NULL);
  }
}


xqtref_t TypeManagerImpl::create_atomic_type(
    TypeConstants::atomic_type_code_t type_code,
    TypeConstants::quantifier_t quantifier) const
{
  return *GENV_TYPESYSTEM.m_atomic_typecode_map[type_code][quantifier];
}


xqtref_t TypeManagerImpl::create_any_type() const
{
  return GENV_TYPESYSTEM.ANY_TYPE;
}


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

xqtref_t TypeManagerImpl::create_any_simple_type() const
{
  return GENV_TYPESYSTEM.ANY_SIMPLE_TYPE;
}

xqtref_t TypeManagerImpl::create_untyped_type() const
{
  return GENV_TYPESYSTEM.UNTYPED_TYPE;
}

xqtref_t TypeManagerImpl::create_empty_type() const
{
  return GENV_TYPESYSTEM.EMPTY_TYPE;
}

xqtref_t TypeManagerImpl::create_none_type() const
{
  return GENV_TYPESYSTEM.NONE_TYPE;
}


/* vim:set ts=2 sw=2: */
