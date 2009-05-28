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
#ifndef ZORBA_TYPEMANAGERIMPL_H
#define ZORBA_TYPEMANAGERIMPL_H

#include "types/typemanager.h"
#include "store/api/item.h"

namespace zorba {

class NodeTest;


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

public:
  TypeManagerImpl(int level, TypeManager* parent)
    :
    TypeManager(level),
    m_parent(parent) 
  {
  }

  virtual ~TypeManagerImpl() { }

  TypeManager* get_parent_type_manager() const { return m_parent; }

  xqtref_t create_any_type() const;

  xqtref_t create_untyped_type() const;

  xqtref_t create_empty_type() const;

  xqtref_t create_none_type() const;

  xqtref_t create_any_simple_type() const;

  xqtref_t create_builtin_atomic_type(
        TypeConstants::atomic_type_code_t type_code,
        TypeConstants::quantifier_t quantifier) const;

  virtual xqtref_t create_named_atomic_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier) const;

  virtual xqtref_t create_named_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const;

  xqtref_t create_any_item_type(TypeConstants::quantifier_t quantifier) const;

  xqtref_t create_node_type(
        store::StoreConsts::NodeKind nodeKind,
        const store::Item* nodeName,
        xqtref_t contentType,
        TypeConstants::quantifier_t quantifier,
        bool nillable) const;

  xqtref_t create_type(
        const XQType& type,
        TypeConstants::quantifier_t quantifier) const;

  xqtref_t create_type_x_quant(
        const XQType& type,
        TypeConstants::quantifier_t quantifier) const;

  xqtref_t create_type(const TypeIdentifier& ident) const;

  xqtref_t create_value_type(const store::Item* item) const;

#ifndef ZORBA_NO_XMLSCHEMA
  xqtref_t create_schema_element_type(
        store::Item *eName,
        TypeConstants::quantifier_t quant) const;

  void get_schema_element_typename(
        store::Item* elemName,
        store::Item_t& typeName);

  xqtref_t create_schema_attribute_type(
        store::Item *aName,
        TypeConstants::quantifier_t quant) const;
#endif

private:
  xqtref_t create_builtin_node_type(
        store::StoreConsts::NodeKind nodeKind,
        TypeConstants::quantifier_t quantifier,
        bool untyped) const;
};

}

#endif /* ZORBA_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */

