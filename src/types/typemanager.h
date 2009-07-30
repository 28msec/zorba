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
#ifndef ZORBA_TYPEMANAGER_H
#define ZORBA_TYPEMANAGER_H

#include <ostream>
#include <zorba/typeident.h>
#include <zorba/store_consts.h>

#include "zorbatypes/rchandle.h"
#include "common/shared_types.h"
#include "types/typeconstants.h"

#include "zorbaserialization/serialization_engine.h"

namespace zorba {

class NodeTest;
class Schema;


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
class TypeManager : public SimpleRCObject 
{
    
protected:
  int m_level;

public:
  SERIALIZABLE_ABSTRACT_CLASS(TypeManager)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(TypeManager, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    //serialize_baseclass(ar, (SimpleRCObject*)this);
    ar & m_level;
  }
public:
  TypeManager(int level) : m_level(level) { }
  
  virtual ~TypeManager() { }

  virtual TypeManager *get_parent_type_manager() const = 0;

  virtual int level() const { return m_level; }

  virtual void initializeSchema() = 0;

  virtual void terminateSchema() = 0;

  virtual Schema* getSchema() const = 0;

  /* Factory Methods */

  virtual xqtref_t create_any_type() const = 0;

  virtual xqtref_t create_untyped_type() const = 0;

  virtual xqtref_t create_empty_type() const = 0;

  virtual xqtref_t create_none_type() const = 0;

  virtual xqtref_t create_any_simple_type() const = 0;

  virtual xqtref_t create_builtin_atomic_type(
        TypeConstants::atomic_type_code_t type_code,
        TypeConstants::quantifier_t quantifier) const = 0;

  virtual xqtref_t create_named_atomic_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier) const = 0;

  virtual xqtref_t create_named_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const = 0;

  virtual xqtref_t create_any_item_type(
        TypeConstants::quantifier_t quantifier) const = 0;

  virtual xqtref_t create_node_type(
        store::StoreConsts::NodeKind nodeKind,
        const store::Item_t& nodeName,
        xqtref_t contentType,
        TypeConstants::quantifier_t quantifier,
        bool nillable,
        bool schematype) const = 0;

  virtual xqtref_t create_type(
        const XQType& type,
        TypeConstants::quantifier_t quantifier) const = 0;

  virtual xqtref_t create_type_x_quant(
        const XQType& type,
        TypeConstants::quantifier_t quantifier) const = 0;

  virtual xqtref_t create_value_type(const store::Item* item) const = 0;

  virtual xqtref_t create_type(const TypeIdentifier& ident) const = 0;

#ifndef ZORBA_NO_XMLSCHEMA

  virtual xqtref_t create_schema_element_type(
        const store::Item_t& eName,
        TypeConstants::quantifier_t quant) const = 0;

  virtual void get_schema_element_typename(
        const store::Item* elemName,
        store::Item_t& typeName) = 0;

  virtual xqtref_t create_schema_attribute_type(
        const store::Item_t& aName,
        TypeConstants::quantifier_t quant) const = 0;

  virtual void get_schema_attribute_typename(
        const store::Item* attrName,
        store::Item_t& typeName) = 0;

#endif
};

}

#endif /* ZORBA_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
