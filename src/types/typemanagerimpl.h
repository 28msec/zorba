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
#pragma once
#ifndef ZORBA_TYPEMANAGERIMPL_H
#define ZORBA_TYPEMANAGERIMPL_H

#include "types/typemanager.h"
//#include "types/schema/schema.h"
#include "store/api/item.h"

#include "system/globalenv.h"

namespace zorba {

class NodeTest;
class Schema;


class qname_hash_equals 
{
 public:
  static uint32_t hash(const store::Item *qn)
  {
    return qn->hash();
  }

  static bool equal(const store::Item *qn1, const store::Item *qn2)
  {
    return qn1->equals(qn2);
  }
};


/***************************************************************************//**
  A type manager acts as a factory and manager of XQType instances. 

  Multiple type managers may participate in an xquery program, each corresponding
  to a different xml schema. These type managers are arranged in a tree hierarchy.
  There is always a root type manager (see root_typemanager.h) that is created
  during system initialization and manages the built-in types of XQDM. Other
  type managers are allocated dynamically during the processing of schema import
  statements inside an xquery program. 

  Each XQType instance has a pointer back to the type manager that created that
  XQType.
********************************************************************************/
class TypeManagerImpl : public TypeManager 
{
protected:
  TypeManager * m_parent;
  Schema      * m_schema;

public:
  SERIALIZABLE_CLASS(TypeManagerImpl)
  SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM1(TypeManagerImpl, TypeManager,m_schema)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  TypeManagerImpl(TypeManager* parent)
    :
    TypeManager(parent ? parent->level() + 1 : 0),
    m_parent(parent),
    m_schema(NULL)
  {
  }

  virtual ~TypeManagerImpl();

  TypeManager* get_parent_type_manager() const { return m_parent; }

  Schema* getSchema() const { return m_schema; }

  void initializeSchema();

  void terminateSchema();

  xqtref_t create_any_type() const;

  xqtref_t create_untyped_type() const;

  xqtref_t create_empty_type() const;

  xqtref_t create_none_type() const;

  xqtref_t create_any_simple_type() const;

  xqtref_t create_builtin_atomic_type(
        store::SchemaTypeCode type_code,
        TypeConstants::quantifier_t quant) const;

  xqtref_t create_named_atomic_type(
        store::Item* qname,
        TypeConstants::quantifier_t quant,
        const QueryLoc& loc = QueryLoc::null,
        const Error& error = zerr::ZXQP0000_NO_ERROR) const;

  xqtref_t create_named_type(
        store::Item* qname,
        TypeConstants::quantifier_t quant = TypeConstants::QUANT_ONE,
        const QueryLoc& loc = QueryLoc::null,
        const Error& error = zerr::ZXQP0000_NO_ERROR) const;

  xqtref_t create_any_item_type(TypeConstants::quantifier_t quant) const;

  xqtref_t create_any_function_type(TypeConstants::quantifier_t quant) const;

  xqtref_t create_node_type(
        store::StoreConsts::NodeKind nodeKind,
        const store::Item_t& nodeName,
        xqtref_t contentType,
        TypeConstants::quantifier_t quant,
        bool nillable,
        bool schematest) const;

  xqtref_t create_function_type(
        const std::vector<xqtref_t>& aArgs,
        const xqtref_t& aReturn,
        TypeConstants::quantifier_t aQuant) const;

  xqtref_t create_type(
        const XQType& type,
        TypeConstants::quantifier_t quant) const;

  xqtref_t create_type_x_quant(
        const XQType& type,
        TypeConstants::quantifier_t quant) const;

  xqtref_t create_type(const TypeIdentifier& ident) const;

  xqtref_t create_value_type(
        const store::Item* item,
        const QueryLoc& loc = QueryLoc::null) const;

#ifndef ZORBA_NO_XMLSCHEMA

  xqtref_t create_schema_element_type(
        const store::Item_t& elemName,
        TypeConstants::quantifier_t quant,
        const QueryLoc& loc) const;

  void get_schema_element_typename(
        const store::Item* elemName,
        store::Item_t& typeName,
        const QueryLoc& loc);

  xqtref_t create_schema_attribute_type(
        const store::Item_t& attrName,
        TypeConstants::quantifier_t quant,
        const QueryLoc& loc) const;
  
  void get_schema_attribute_typename(
        const store::Item* attrName,
        store::Item_t& typeName,
        const QueryLoc& loc);
#endif

private:
  xqtref_t create_builtin_node_type(
        store::StoreConsts::NodeKind nodeKind,
        TypeConstants::quantifier_t quantifier,
        bool untyped) const;
};

}

#endif /* ZORBA_TYPEMANAGER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
