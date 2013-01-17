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

#include <zorba/identtypes.h>
#include <zorba/typeident.h>

#include "api/unmarshaller.h"

#include "system/globalenv.h"

#include "store/api/item.h"

#include "types/typeops.h"
#include "types/typeimpl.h"
#include "types/node_test.h"
#include "types/root_typemanager.h"
#include "types/schema/schema.h"

#include "diagnostics/assert.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"


namespace zorba {



#define CHECK_IN_SCOPE(tm, type, loc)                                         \
{                                                                             \
  const TypeManager* ttm = type.get_manager();                                \
  if (ttm != tm && ttm != &GENV_TYPESYSTEM && !TypeOps::is_in_scope(tm,type)) \
    RAISE_ERROR(err::XPTY0004, loc,                                           \
    ERROR_PARAMS(ZED(BadType_23o), type, ZED(NotAmongInScopeSchemaTypes)));   \
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_sub_quant(
    TypeConstants::quantifier_t q1,
    TypeConstants::quantifier_t q2)
{
  return RootTypeManager::QUANT_SUBTYPE_MATRIX[q1][q2];
}


/*******************************************************************************

********************************************************************************/
TypeConstants::quantifier_t TypeOps::intersect_quant(
    TypeConstants::quantifier_t q1,
    TypeConstants::quantifier_t q2)
{
  return RootTypeManager::QUANT_INTERS_MATRIX [q1] [q2];
}


/*******************************************************************************

********************************************************************************/
TypeConstants::quantifier_t TypeOps::union_quant(
    TypeConstants::quantifier_t q1,
    TypeConstants::quantifier_t q2)
{
  return RootTypeManager::QUANT_UNION_MATRIX [q1] [q2];
}


/*******************************************************************************

********************************************************************************/
store::SchemaTypeCode TypeOps::get_atomic_type_code(const XQType& type)
{
  assert(type.type_kind() == XQType::ATOMIC_TYPE_KIND);
  return (static_cast<const AtomicXQType&>(type)).get_type_code();
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_in_scope(const TypeManager* tm, const XQType& type) 
{
  if (type.type_kind() == XQType::USER_DEFINED_KIND)
  {
    return (tm->create_named_type(type.get_qname(), 
                                  TypeConstants::QUANT_ONE,
                                  QueryLoc::null) != NULL);
  }
  else if (type.type_kind() == XQType::NODE_TYPE_KIND)
  {
    const NodeXQType& ntype = static_cast<const NodeXQType&>(type);
    xqtref_t ctype = ntype.get_content_type();

    if (ctype != NULL)
    {
      if (ntype.get_node_kind() == store::StoreConsts::documentNode)
      {
        assert(!ntype.is_schema_test());
        return is_in_scope(tm, *ctype);
      }
      else if (tm->create_named_type(ctype->get_qname(),
                                     TypeConstants::QUANT_ONE,
                                     QueryLoc::null) == NULL)
      {
        return false;
      }
    }

    if (ntype.is_schema_test())
    {
      Schema* schema = tm->getSchema();

      if (schema == NULL)
        return false;

#ifndef ZORBA_NO_XMLSCHEMA
      if (ntype.get_node_kind() == store::StoreConsts::elementNode)
      {
        return (schema->createXQTypeFromElementName(tm,
                                                    ntype.get_node_name(),
                                                    false,
                                                    QueryLoc::null) != NULL);
      }
      else
      {
        return (schema->createXQTypeFromAttributeName(tm,
                                                      ntype.get_node_name(),
                                                      false,
                                                      QueryLoc::null) != NULL);
      }
#else
      throw ZORBA_EXCEPTION(err::XQST0009);
#endif
    }

    return true;
  }
  else if (type.type_kind() == XQType::FUNCTION_TYPE_KIND)
  {
    throw ZORBA_EXCEPTION(zerr::ZXQP0004_NOT_IMPLEMENTED,
    ERROR_PARAMS(ZED(ZXQP0004_TypeOps_is_in_scope_ForFunctionItemTypes)));
  }
  else
  {
    return true;
  }
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_numeric(store::SchemaTypeCode type)
{
  return store::XS_FLOAT <= type && type <= store::XS_POSITIVE_INTEGER;
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_numeric(const TypeManager* tm, const XQType& type)
{
  CHECK_IN_SCOPE(tm, type, QueryLoc::null);

  RootTypeManager& rtm = GENV_TYPESYSTEM;

  return (is_subtype(tm, type, *rtm.DOUBLE_TYPE_QUESTION) ||
          is_subtype(tm, type, *rtm.FLOAT_TYPE_QUESTION) ||
          is_subtype(tm, type, *rtm.DECIMAL_TYPE_QUESTION));
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_numeric_or_untyped(const TypeManager* tm, const XQType& type)
{
  CHECK_IN_SCOPE(tm, type, QueryLoc::null);

  RootTypeManager& rtm = GENV_TYPESYSTEM;

  return (is_subtype(tm, type, *rtm.DOUBLE_TYPE_QUESTION) ||
          is_subtype(tm, type, *rtm.FLOAT_TYPE_QUESTION) ||
          is_subtype(tm, type, *rtm.DECIMAL_TYPE_QUESTION) ||
          is_subtype(tm, type, *rtm.UNTYPED_ATOMIC_TYPE_QUESTION));
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::maybe_date_time(const TypeManager* tm, const XQType& type) 
{
  CHECK_IN_SCOPE(tm, type, QueryLoc::null);

  switch (type.type_kind()) 
  {
  case XQType::ATOMIC_TYPE_KIND:
    switch (static_cast<const AtomicXQType &>(type).get_type_code()) 
    {
    case store::XS_ANY_ATOMIC:
    case store::XS_DATE:
    case store::XS_TIME:
    case store::XS_DATETIME:
    case store::XS_GYEAR_MONTH:
    case store::XS_GYEAR:
    case store::XS_GMONTH_DAY:
    case store::XS_GDAY:
    case store::XS_GMONTH:
      return true;
    default:
      return false;
    }
    break;

  case XQType::ANY_TYPE_KIND:
  case XQType::ANY_SIMPLE_TYPE_KIND:
  case XQType::ITEM_KIND:
    return true;

  case XQType::USER_DEFINED_KIND:
    return true;  // TODO: finer analysis

  default:
    // NODE, EMPTY, NONE, JSON, STRUCTURED_ITEM
    return false;
  }
}


/*******************************************************************************
  For atomic, node, json, function and item types --> just set the quant to ONE

  none --> none

  empty -->  none

  xs:any --> item

  xs:untyped --> item

  xs:anySimple --> xs:anyAtomic
********************************************************************************/
xqtref_t TypeOps::prime_type(const TypeManager* tm, const XQType& type) 
{
  CHECK_IN_SCOPE(tm, type, QueryLoc::null);

  switch (type.type_kind()) 
  {
  case XQType::EMPTY_KIND:
    return GENV_TYPESYSTEM.NONE_TYPE;

  case XQType::ATOMIC_TYPE_KIND: 
  {
    if (type.get_quantifier() == TypeConstants::QUANT_ONE)
      return &type;

    const AtomicXQType& atype = static_cast<const AtomicXQType&>(type);
    return tm->create_builtin_atomic_type(atype.get_type_code(),
                                          TypeConstants::QUANT_ONE);
  }

  case XQType::NONE_KIND:
    return &type;

  case XQType::ITEM_KIND:
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;

  case XQType::ANY_TYPE_KIND:
  case XQType::UNTYPED_KIND:
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;

  case XQType::ANY_SIMPLE_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;

  case XQType::ANY_FUNCTION_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE;

  case XQType::FUNCTION_TYPE_KIND:
  {
    if (type.get_quantifier() == TypeConstants::QUANT_ONE)
      return &type;

    const FunctionXQType& lType = static_cast<const FunctionXQType&>(type);
    return tm->create_function_type(lType.get_param_types(),
                                    lType.get_return_type(),
                                    TypeConstants::QUANT_ONE);
  }

  case XQType::STRUCTURED_ITEM_KIND:
    return GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_ONE;

#ifdef ZORBA_WITH_JSON
  case XQType::JSON_TYPE_KIND: 
#endif 
  case XQType::NODE_TYPE_KIND:

  {
    if (type.get_quantifier() == TypeConstants::QUANT_ONE)
      return &type;

    return tm->create_type(type, TypeConstants::QUANT_ONE);
  }

  case XQType::USER_DEFINED_KIND:
  {
    if (type.get_quantifier() == TypeConstants::QUANT_ONE)
      return &type;

    const UserDefinedXQType& udt = static_cast<const UserDefinedXQType&>(type);

    if (udt.isAtomic())
    {
      return tm->create_type(type, TypeConstants::QUANT_ONE);
    }
    else
    {
      return &type;
    }
  }

  default:
    ZORBA_ASSERT(false);
    return NULL;
  }
}


/*******************************************************************************
  Returns true iff type1 is equal to type2 including the quantifier.
********************************************************************************/
bool TypeOps::is_equal(
    const TypeManager* tm,
    const XQType& type1,
    const XQType& type2,
    const QueryLoc& loc)
{
  CHECK_IN_SCOPE(tm, type1, loc);
  CHECK_IN_SCOPE(tm, type2, loc);

  if (&type1 == &type2)
    return true;

  if (type1.get_quantifier() != type2.get_quantifier()) 
  {
    return false;
  }

  if (type1.type_kind() != type2.type_kind()) 
  {
    return false;
  }

  switch(type1.type_kind()) 
  {
    case XQType::ATOMIC_TYPE_KIND:
    {
      const AtomicXQType& a1 = static_cast<const AtomicXQType&>(type1);
      const AtomicXQType& a2 = static_cast<const AtomicXQType&>(type2);

      return a1.get_type_code() == a2.get_type_code();
    }
    case XQType::NODE_TYPE_KIND:
    {
      const NodeXQType& n1 = static_cast<const NodeXQType&>(type1);
      const NodeXQType& n2 = static_cast<const NodeXQType&>(type2);

      return n1.is_equal(tm, n2);
    }
#ifdef ZORBA_WITH_JSON
    case XQType::JSON_TYPE_KIND:
    {
      const JSONXQType& j1 = static_cast<const JSONXQType&>(type1);
      const JSONXQType& j2 = static_cast<const JSONXQType&>(type2);

      return j1.get_json_kind() == j2.get_json_kind();
    }
#endif
    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udt1 = static_cast<const UserDefinedXQType&>(type1);
      const UserDefinedXQType& udt2 = static_cast<const UserDefinedXQType&>(type2);

      return (udt1.getTypeCategory() == udt2.getTypeCategory() &&
              udt1.get_qname()->equals(udt2.get_qname()));
    }
    default:
      break;
  }

  return true;
}


/*******************************************************************************
  Returns true iff "subtype" is a subtype of "supertype".
********************************************************************************/
bool TypeOps::is_subtype(
    store::SchemaTypeCode subtype,
    store::SchemaTypeCode supertype)
{
  return RootTypeManager::ATOMIC_SUBTYPE_MATRIX[subtype][supertype];
}


/*******************************************************************************
  Returns true iff "subtype" is a subtype of "supertype".
********************************************************************************/
bool TypeOps::is_subtype(
    const TypeManager* tm,
    const XQType& subtype,
    const XQType& supertype,
    const QueryLoc& loc)
{
  CHECK_IN_SCOPE(tm, subtype, loc);
  CHECK_IN_SCOPE(tm, supertype, loc);

  if (&subtype == &supertype)
    return true;

  if (subtype.type_kind() == XQType::NONE_KIND)
    return true;

  if (!RootTypeManager::QUANT_SUBTYPE_MATRIX[subtype.get_quantifier()]
                                            [supertype.get_quantifier()])
    return false;

  switch(supertype.type_kind()) 
  {
  case XQType::EMPTY_KIND:
  {
    switch(subtype.type_kind()) 
    {
    case XQType::EMPTY_KIND:
      return true;

    default:
      return false;
    }
    break;
  }

  case XQType::NONE_KIND:
  {
    return false;
  }

  case XQType::ITEM_KIND:
  {
    switch(subtype.type_kind())
    {
    case XQType::ATOMIC_TYPE_KIND:
    case XQType::NODE_TYPE_KIND:
    case XQType::ITEM_KIND:
    case XQType::FUNCTION_TYPE_KIND:
    case XQType::ANY_FUNCTION_TYPE_KIND:
    case XQType::EMPTY_KIND:
    case XQType::STRUCTURED_ITEM_KIND:
#ifdef ZORBA_WITH_JSON
    case XQType::JSON_TYPE_KIND:
#endif
      return true;
      
    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udSubType = 
      static_cast<const UserDefinedXQType&>(subtype);
      
      // What about union of atomic types ????
      return udSubType.isAtomic();
    }
    
    default:
      // ANY, ANY_SIMPLE, UNTYPED
      return false;
    }
    break;
  }

  case XQType::FUNCTION_TYPE_KIND:
  {
    switch (subtype.type_kind())
    {
    case XQType::ANY_FUNCTION_TYPE_KIND:
    {
      return false;
    }

    case XQType::FUNCTION_TYPE_KIND:
    {
      const FunctionXQType& f1 = static_cast<const FunctionXQType&>(subtype);
      const FunctionXQType& f2 = static_cast<const FunctionXQType&>(supertype);
      return f1.is_subtype(tm, f2);
    }
    default:
      return false;
    }
  }

  case XQType::ANY_FUNCTION_TYPE_KIND:
  {
    switch (subtype.type_kind())
    {
    case XQType::FUNCTION_TYPE_KIND:
    case XQType::ANY_FUNCTION_TYPE_KIND:
      return true;
    default:
      // any, untyped, node, atomic
      return false;
    }
  }
  
  case XQType::ATOMIC_TYPE_KIND:
  {
    switch(subtype.type_kind()) 
    {
    case XQType::ATOMIC_TYPE_KIND:
    {
      const AtomicXQType& a1 = static_cast<const AtomicXQType&>(subtype);
      const AtomicXQType& a2 = static_cast<const AtomicXQType&>(supertype);

      return RootTypeManager::ATOMIC_SUBTYPE_MATRIX[a1.get_type_code()][a2.get_type_code()];
    }
    case XQType::EMPTY_KIND:
    {
      return true;
    }
    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udSubtype = 
      static_cast<const UserDefinedXQType&>(subtype);

      return udSubtype.isSubTypeOf(tm, supertype);
    }
    default:
    {
      // NODE, ITEM, STRUCTURED_ITEM, ANY, ANY_SIMPLE, FUNCTION, UNTYPED, JSON
      return false;
    }
    }
    break;
  }

  case XQType::STRUCTURED_ITEM_KIND:
  {
    switch(subtype.type_kind())
    {
    case XQType::NODE_TYPE_KIND:
    case XQType::EMPTY_KIND:
    case XQType::STRUCTURED_ITEM_KIND:
#ifdef ZORBA_WITH_JSON
    case XQType::JSON_TYPE_KIND:
#endif
      return true;

    default:
      // ITEM, ANY_FUNCTION, FUNCTION, ATOMIC, USER_DEFINED, ANY, ANY_SIMPLE, UNTYPED
      return false;
    }
    
    break;
  }

#ifdef ZORBA_WITH_JSON
  case XQType::JSON_TYPE_KIND:
  {
    if (subtype.type_kind() != XQType::JSON_TYPE_KIND)
      return false;

    const JSONXQType& sub = static_cast<const JSONXQType&>(subtype);
    const JSONXQType& sup = static_cast<const JSONXQType&>(supertype);

    store::StoreConsts::JSONItemKind subKind = sub.get_json_kind();
    store::StoreConsts::JSONItemKind supKind = sup.get_json_kind();

    switch (supKind)
    {
    case store::StoreConsts::jsonItem:
      return true;

    case store::StoreConsts::jsonObject:
    case store::StoreConsts::jsonArray:
      return (subKind == supKind);
      
    default:
      ZORBA_ASSERT(false);
    }
  }
#endif

  case XQType::NODE_TYPE_KIND:
  {
    switch(subtype.type_kind())
    {
    case XQType::NODE_TYPE_KIND:
    {
      const NodeXQType& n1 = static_cast<const NodeXQType&>(subtype);
      const NodeXQType& n2 = static_cast<const NodeXQType&>(supertype);
      
      return n1.is_subtype(tm, n2, loc);
    }
    case XQType::EMPTY_KIND:
    {
      return true;
    }
    default:
    {
      // ATOMIC, ITEM, STRUCTURED_ITEM, ANY, ANY_SIMPLE, UNTYPED, FUNCTION,
      // JSON, USER_DEFINED (???)
      return false;
    }
    }
    break;
  }
  
  case XQType::ANY_TYPE_KIND:
  {
    switch(subtype.type_kind()) 
    {
    case XQType::ATOMIC_TYPE_KIND:
    case XQType::ANY_TYPE_KIND:
    case XQType::ANY_SIMPLE_TYPE_KIND:
    case XQType::UNTYPED_KIND:
    case XQType::EMPTY_KIND:
    case XQType::USER_DEFINED_KIND:
      return true;

    case XQType::NODE_TYPE_KIND:
    case XQType::ITEM_KIND:
#ifdef ZORBA_WITH_JSON
    case XQType::JSON_TYPE_KIND:
#endif
    case XQType::STRUCTURED_ITEM_KIND:
      return false;

    default:
      ZORBA_ASSERT(false);
    }
    break;
  }

  case XQType::ANY_SIMPLE_TYPE_KIND:
  {
    switch(subtype.type_kind())
    {
    case XQType::ATOMIC_TYPE_KIND:
    case XQType::ANY_SIMPLE_TYPE_KIND:
    case XQType::EMPTY_KIND:
      return true;

    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udSubType = 
      static_cast<const UserDefinedXQType&>(subtype);

      return (udSubType.isAtomic() || udSubType.isList() || udSubType.isUnion());
    }

    default:
      // ANY, UNTYPED, ITEM, NODE, JSON
      return false;
    }
    break;
  }
  
  case XQType::UNTYPED_KIND:
  {
    switch(subtype.type_kind()) 
    {
    case XQType::UNTYPED_KIND:
      return true;

    default:
      return false;
    }
    break;
  }

  case XQType::USER_DEFINED_KIND:
  {
    const UserDefinedXQType& udSuperType = 
    static_cast<const UserDefinedXQType&>(supertype);

    return udSuperType.isSuperTypeOf(tm, subtype);
  }
  
  default:
    ZORBA_ASSERT(false);
  }

  return false;
}


/*******************************************************************************
  Returns true iff the type of "subitem" is a subtype of "supertype".
********************************************************************************/
bool TypeOps::is_subtype(
    const TypeManager* tm,
    const store::Item* subitem,
    const XQType& supertype,
    const QueryLoc& loc)
{
  CHECK_IN_SCOPE(tm, supertype, loc);

  switch(supertype.type_kind()) 
  {
  case XQType::EMPTY_KIND:
  case XQType::NONE_KIND:
  {
    return false;
  }

  case XQType::ITEM_KIND:
  {
    return true;
    break;
  }

  case XQType::FUNCTION_TYPE_KIND:
  {
    if (!subitem->isFunction())
      return false;

    xqtref_t subtype = tm->create_value_type(subitem, loc);

    switch (subtype->type_kind())
    {
    case XQType::ANY_FUNCTION_TYPE_KIND:
    case XQType::FUNCTION_TYPE_KIND:
    {
      const FunctionXQType& f1 = static_cast<const FunctionXQType&>(*subtype);
      const FunctionXQType& f2 = static_cast<const FunctionXQType&>(supertype);
      return f1.is_subtype(tm, f2);
    }
    default:
      return false;
    }
  }

  case XQType::ANY_FUNCTION_TYPE_KIND:
  {
    if (subitem->isFunction())
      return true;
    
    return false;
  }

  case XQType::ATOMIC_TYPE_KIND:
  {
    if (!subitem->isAtomic())
      return false;

    const AtomicXQType& a2 = static_cast<const AtomicXQType&>(supertype);

    if (a2.get_type_code() == store::XS_ANY_ATOMIC)
      return true;

    xqtref_t subtype = tm->create_named_atomic_type(subitem->getType(),
                                                    TypeConstants::QUANT_ONE,
                                                    loc,
                                                    true);
    switch(subtype->type_kind()) 
    {
    case XQType::ATOMIC_TYPE_KIND:
    {
      const AtomicXQType& a1 = static_cast<const AtomicXQType&>(*subtype);

      return RootTypeManager::ATOMIC_SUBTYPE_MATRIX[a1.get_type_code()]
                                                   [a2.get_type_code()];
    }
    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udSubtype = 
      static_cast<const UserDefinedXQType&>(*subtype);

      return udSubtype.isSubTypeOf(tm, supertype);
    }
    case XQType::EMPTY_KIND:
    {
      assert(false);
      return true;
    }
    default:
    {
      // NODE, ITEM, ANY, ANY_SIMPLE, FUNCTION, UNTYPED, JSON
      return false;
    }
    }
    break;
  }

  case XQType::STRUCTURED_ITEM_KIND:
  {
#ifdef ZORBA_WITH_JSON
    if (subitem->isJSONItem() || subitem->isNode())
#else
    if (subitem->isNode())
#endif
      return true;

    return false;
  }

#ifdef ZORBA_WITH_JSON
  case XQType::JSON_TYPE_KIND:
  {
    if (!subitem->isJSONItem())
      return false;

    const JSONXQType& sup = static_cast<const JSONXQType&>(supertype);

    store::StoreConsts::JSONItemKind subKind = subitem->getJSONItemKind();
    store::StoreConsts::JSONItemKind supKind = sup.get_json_kind();

    switch (supKind)
    {
    case store::StoreConsts::jsonItem:
      return true;

    case store::StoreConsts::jsonObject:
    case store::StoreConsts::jsonArray:
      return (subKind == supKind);
      
    default:
      ZORBA_ASSERT(false);
    }
  }
#endif

  case XQType::NODE_TYPE_KIND:
  {
    if (!subitem->isNode())
      return false;

    const NodeXQType& n2 = static_cast<const NodeXQType&>(supertype);

    return n2.is_supertype(tm, subitem, loc);
    
    break;
  }

  case XQType::ANY_SIMPLE_TYPE_KIND:
  {
    if (!subitem->isAtomic())
      return false;

    xqtref_t subtype = tm->create_named_atomic_type(subitem->getType(),
                                                    TypeConstants::QUANT_ONE,
                                                    loc,
                                                    true);
    switch (subtype->type_kind())
    {
    case XQType::ATOMIC_TYPE_KIND:
    case XQType::ANY_SIMPLE_TYPE_KIND:
    case XQType::EMPTY_KIND:
      return true;

    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udSubType = 
      static_cast<const UserDefinedXQType&>(*subtype);

      return (udSubType.isAtomic() || udSubType.isList() || udSubType.isUnion());
    }

    default:
      // ANY, UNTYPED, ITEM, NODE
      return false;
    }
    break;
  }

  case XQType::UNTYPED_KIND:
  case XQType::ANY_TYPE_KIND:
  {
    // We shouldn't be here because these are not a sequence types
    ZORBA_ASSERT(false);

    if (!subitem->getType()->equals(GENV_TYPESYSTEM.XS_UNTYPED_QNAME))
      return false;

    return true;
  }

  case XQType::USER_DEFINED_KIND:
  {
    // The supertype must be a sequence type, and the only way that a user-
    // defined type may be a sequence type, is if it is an atomic type.
    if (!subitem->isAtomic())
      return false;

    xqtref_t subtype = tm->create_named_atomic_type(subitem->getType(),
                                                    TypeConstants::QUANT_ONE,
                                                    loc,
                                                    true);
    const UserDefinedXQType& udSuperType = 
    static_cast<const UserDefinedXQType&>(supertype);

    return udSuperType.isSuperTypeOf(tm, *subtype);
  }

  default:
    ZORBA_ASSERT(false);
  }

  return false;
}


/*******************************************************************************
  
********************************************************************************/
bool TypeOps::is_treatable(
    const TypeManager* tm,
    const store::Item_t& item,
    const XQType& targetType,
    const QueryLoc& loc)
{
  return is_subtype(tm, item.getp(), targetType, loc);
}


/*******************************************************************************
  Returns the castability fron the source ItemType to the target ItemType. It
  works only if both source and target types are builtin atomic types.
  Otherwise, it returns NOT_CASTABLE.
********************************************************************************/
TypeConstants::castable_t TypeOps::castability(const XQType& src, const XQType& target)
{
  if (src.type_kind() == XQType::ATOMIC_TYPE_KIND &&
      target.type_kind() == XQType::ATOMIC_TYPE_KIND) 
  {
    const AtomicXQType& aSrc = static_cast<const AtomicXQType&>(src);
    const AtomicXQType& aTarget = static_cast<const AtomicXQType&>(target);

    return RootTypeManager::ATOMIC_CAST_MATRIX[aSrc.get_type_code()]
                                              [aTarget.get_type_code()];
  }

  // incorect should work for other than built-in types or at least rename it.
  return TypeConstants::MAYBE_CASTABLE;
}


/*******************************************************************************

********************************************************************************/
xqtref_t TypeOps::union_type(
    const XQType& type1,
    const XQType& type2,
    const TypeManager* tm)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  XQType::TypeKind kind1 = type1.type_kind();
  XQType::TypeKind kind2 = type2.type_kind();

  ZORBA_ASSERT(kind1 != XQType::ANY_TYPE_KIND &&
               kind1 != XQType::ANY_SIMPLE_TYPE_KIND &&
               kind1 != XQType::UNTYPED_KIND);
  
  ZORBA_ASSERT(kind2 != XQType::ANY_TYPE_KIND &&
               kind2 != XQType::ANY_SIMPLE_TYPE_KIND &&
               kind2 != XQType::UNTYPED_KIND);

  if (is_subtype(tm, type1, type2))
    return &type2;

  else if (is_subtype(tm, type2, type1))
    return &type1;

  else if (type1.is_empty())
    return tm->create_type_x_quant(type2, TypeConstants::QUANT_QUESTION);

  else if (type2.is_empty())
    return tm->create_type_x_quant(type1, TypeConstants::QUANT_QUESTION);

  else if (type1.get_quantifier() == TypeConstants::QUANT_ONE &&
           type2.get_quantifier() == TypeConstants::QUANT_ONE) 
  {
    if (kind1 == kind2)
    {
      switch (kind1) 
      {
      case XQType::ATOMIC_TYPE_KIND:
        return rtm.ANY_ATOMIC_TYPE_ONE;

      case XQType::NODE_TYPE_KIND:
          return rtm.ANY_NODE_TYPE_ONE;

      case XQType::STRUCTURED_ITEM_KIND:
        return rtm.STRUCTURED_ITEM_TYPE_ONE;

#ifdef ZORBA_WITH_JSON
      case XQType::JSON_TYPE_KIND:
        return rtm.JSON_ITEM_TYPE_ONE;
#endif
      default:
        break;
      }
    }
    else if ((kind1 == XQType::NODE_TYPE_KIND || 
#ifdef ZORBA_WITH_JSON
              kind1 == XQType::JSON_TYPE_KIND ||
#endif
              kind1 == XQType::STRUCTURED_ITEM_KIND) &&
             (kind2 == XQType::NODE_TYPE_KIND ||
#ifdef ZORBA_WITH_JSON
              kind2 == XQType::JSON_TYPE_KIND ||
#endif
              kind2 == XQType::STRUCTURED_ITEM_KIND))
    {
      return rtm.STRUCTURED_ITEM_TYPE_ONE;
    }

    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  }
  else
  {
    xqtref_t pt1 = prime_type(tm, type1);
    xqtref_t pt2 = prime_type(tm, type2);

    if (! is_equal(tm, type1, *pt1) || ! is_equal(tm, type2, *pt2))
    {
      TypeConstants::quantifier_t q1 = type1.get_quantifier();
      TypeConstants::quantifier_t q2 = type2.get_quantifier();

      TypeConstants::quantifier_t q12 = RootTypeManager::QUANT_UNION_MATRIX[q1][q2];

      // to be on the safe side
      q12 = RootTypeManager::QUANT_UNION_MATRIX[TypeConstants::QUANT_QUESTION][q12];

      return tm->create_type_x_quant(*union_type(*pt1, *pt2, tm), q12); 
    }
    else
    {
      ZORBA_ASSERT(false);
      return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
    }
  }
}


/*******************************************************************************

********************************************************************************/
xqtref_t TypeOps::intersect_type(
    const XQType& type1,
    const XQType& type2,
    const TypeManager* tm)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  XQType::TypeKind tk1 = type1.type_kind();
  XQType::TypeKind tk2 = type2.type_kind();

  ZORBA_ASSERT(tk1 != XQType::ANY_TYPE_KIND &&
               tk1 != XQType::ANY_SIMPLE_TYPE_KIND &&
               tk1 != XQType::UNTYPED_KIND);

  ZORBA_ASSERT(tk2 != XQType::ANY_TYPE_KIND &&
               tk2 != XQType::ANY_SIMPLE_TYPE_KIND &&
               tk2 != XQType::UNTYPED_KIND);

  if (is_subtype(tm, type1, type2))
    return &type1;

  if (is_subtype(tm, type2, type1))
    return &type2;

  TypeConstants::quantifier_t q1 = type1.get_quantifier();
  TypeConstants::quantifier_t q2 = type2.get_quantifier();

  if (tk1 == XQType::EMPTY_KIND)
    return (q2 == TypeConstants::QUANT_QUESTION || q2 == TypeConstants::QUANT_STAR ?
            rtm.EMPTY_TYPE :
            rtm.NONE_TYPE);

  if (tk2 == XQType::EMPTY_KIND)
    return (q1 == TypeConstants::QUANT_QUESTION || q1 == TypeConstants::QUANT_STAR ?
            rtm.EMPTY_TYPE :
            rtm.NONE_TYPE);

  if (q1 == TypeConstants::QUANT_ONE && q2 == TypeConstants::QUANT_ONE) 
  {
    assert(tk1 != XQType::EMPTY_KIND &&
           tk1 != XQType::NONE_KIND &&
           tk1 != XQType::ITEM_KIND);

    assert(tk2 != XQType::EMPTY_KIND &&
           tk2 != XQType::NONE_KIND &&
           tk2 != XQType::ITEM_KIND);

    switch (tk1) 
    {
    case XQType::ANY_FUNCTION_TYPE_KIND:
    {
      return rtm.NONE_TYPE;
    }

    case XQType::FUNCTION_TYPE_KIND:
    {
      return rtm.ANY_FUNCTION_TYPE_ONE;
    }

    case XQType::ATOMIC_TYPE_KIND:
    {
      return rtm.NONE_TYPE;
    }

    case XQType::NODE_TYPE_KIND:
    {
      return (tk2 != XQType::NODE_TYPE_KIND ?
              rtm.NONE_TYPE :
              rtm.ANY_NODE_TYPE_ONE); // ????
    }

    case XQType::STRUCTURED_ITEM_KIND:
    {
      return rtm.NONE_TYPE;
    }

#ifdef ZORBA_WITH_JSON
    case XQType::JSON_TYPE_KIND:
    {
      return rtm.NONE_TYPE;
    }
#endif

    default:
      break;
    }

    return rtm.ITEM_TYPE_ONE;
  }
  else 
  {
    xqtref_t pt1 = prime_type(tm, type1);
    xqtref_t pt2 = prime_type(tm, type2);

    if (! is_equal(tm, type1, *pt1) || ! is_equal(tm, type2, *pt2)) 
    {
      xqtref_t pti = intersect_type(*pt1, *pt2, tm);
      return tm->create_type_x_quant(*pti,
                                     RootTypeManager::QUANT_INTERS_MATRIX[q1][q2]);
    }
    else
    {
      ZORBA_ASSERT(false);
      return rtm.ITEM_TYPE_STAR;
    }
  }
}


/*******************************************************************************

********************************************************************************/
xqtref_t TypeOps::arithmetic_type(
    const TypeManager* tm,
    const XQType& type1,
    const XQType& type2,
    bool division)
{
  if (type1.is_empty())
    return &type1;

  if (type2.is_empty())
    return &type2;

  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t resultType;
  TypeConstants::quantifier_t resultQuant = TypeConstants::QUANT_ONE;

  TypeConstants::quantifier_t quant1 = type1.get_quantifier();
  TypeConstants::quantifier_t quant2 = type2.get_quantifier();

  if (quant1 == TypeConstants::QUANT_QUESTION ||
      quant1 == TypeConstants::QUANT_STAR ||
      quant2 == TypeConstants::QUANT_QUESTION ||
      quant2 == TypeConstants::QUANT_STAR)
  {
    resultQuant = TypeConstants::QUANT_QUESTION;
  }

  if (division &&
      TypeOps::is_subtype(tm, type1, *rtm.INTEGER_TYPE_STAR) &&
      TypeOps::is_subtype(tm, type2, *rtm.INTEGER_TYPE_STAR))
  {
    return (resultQuant == TypeConstants::QUANT_ONE ?
            rtm.DECIMAL_TYPE_ONE : rtm.DECIMAL_TYPE_QUESTION); 
  }

  if (TypeOps::is_subtype(tm, type1, *rtm.UNTYPED_ATOMIC_TYPE_STAR) ||
      TypeOps::is_subtype(tm, type2, *rtm.UNTYPED_ATOMIC_TYPE_STAR)) 
  {
    return (resultQuant == TypeConstants::QUANT_ONE ?
            rtm.DOUBLE_TYPE_ONE : rtm.DOUBLE_TYPE_QUESTION);
  }
 
  if (TypeOps::is_subtype(tm, type1, *rtm.DOUBLE_TYPE_STAR) ||
      TypeOps::is_subtype(tm, type2, *rtm.DOUBLE_TYPE_STAR)) 
  {
    return (resultQuant == TypeConstants::QUANT_ONE ?
            rtm.DOUBLE_TYPE_ONE : rtm.DOUBLE_TYPE_QUESTION);
  }
 
  if (TypeOps::is_subtype(tm, type1, *rtm.FLOAT_TYPE_STAR) ||
      TypeOps::is_subtype(tm, type2, *rtm.FLOAT_TYPE_STAR)) 
  {
    return (resultQuant == TypeConstants::QUANT_ONE ?
            rtm.FLOAT_TYPE_ONE : rtm.FLOAT_TYPE_QUESTION);
  }

  if (TypeOps::is_subtype(tm, type1, *rtm.INTEGER_TYPE_STAR) &&
      TypeOps::is_subtype(tm, type2, *rtm.INTEGER_TYPE_STAR)) 
  {
    return (resultQuant == TypeConstants::QUANT_ONE ?
            rtm.INTEGER_TYPE_ONE : rtm.INTEGER_TYPE_QUESTION);
  }

  if (TypeOps::is_subtype(tm, type1, *rtm.DECIMAL_TYPE_STAR) &&
      TypeOps::is_subtype(tm, type2, *rtm.DECIMAL_TYPE_STAR)) 
  {
    return (resultQuant == TypeConstants::QUANT_ONE ?
            rtm.DECIMAL_TYPE_ONE : rtm.DECIMAL_TYPE_QUESTION); 
  }

  return rtm.ANY_ATOMIC_TYPE_QUESTION;
}


/*******************************************************************************

********************************************************************************/
static inline IdentTypes::quantifier_t get_typeident_quant(
    TypeConstants::quantifier_t quant)
{
  switch(quant) 
  {
  case TypeConstants::QUANT_ONE:
    return IdentTypes::QUANT_ONE;

  case TypeConstants::QUANT_QUESTION:
    return IdentTypes::QUANT_QUESTION;

  case TypeConstants::QUANT_STAR:
    return IdentTypes::QUANT_STAR;

  case TypeConstants::QUANT_PLUS:
    return IdentTypes::QUANT_PLUS;

  default:
    break;
  }

  return IdentTypes::QUANT_ONE;
}


/*******************************************************************************

********************************************************************************/
TypeIdentifier_t TypeOps::get_type_identifier(
    const TypeManager* tm,
    const XQType& type,
    bool nested)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  IdentTypes::quantifier_t q = get_typeident_quant(type.get_quantifier());

  switch(type.type_kind()) 
  {
  case XQType::EMPTY_KIND:
    return TypeIdentifier::createEmptyType();

  case XQType::ITEM_KIND:
    return TypeIdentifier::createItemType(q);

  case XQType::ATOMIC_TYPE_KIND:
  {
    const AtomicXQType& at = static_cast<const AtomicXQType&>(type);
    store::Item* qname = rtm.m_atomic_typecode_qname_map[at.get_type_code()];

    return TypeIdentifier::createNamedType(
        Unmarshaller::newString(qname->getNamespace()),
        Unmarshaller::newString(qname->getLocalName()),
        q);
  }

  case XQType::STRUCTURED_ITEM_KIND:
  {
    return TypeIdentifier::createStructuredItemType(q);
  }

#ifdef ZORBA_WITH_JSON
  case XQType::JSON_TYPE_KIND:
  {
    const JSONXQType& t = static_cast<const JSONXQType&>(type);

    switch (t.get_json_kind())
    {
    case store::StoreConsts::jsonItem:
      return TypeIdentifier::createJSONItemType(q);

    case store::StoreConsts::jsonObject:
      return TypeIdentifier::createJSONObjectType(q);

    case store::StoreConsts::jsonArray:
      return TypeIdentifier::createJSONArrayType(q);

    default:
      ZORBA_ASSERT(false);
    }
  }
#endif

  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType& nt = static_cast<const NodeXQType&>(type);

    const store::Item* nodeName = nt.get_node_name();

    TypeIdentifier_t content_type;
 
    if (nt.get_content_type() != NULL && !nt.is_schema_test())
      content_type = get_type_identifier(tm, *nt.get_content_type(), true);

    switch(nt.get_node_kind()) 
    {
    case store::StoreConsts::anyNode:
      return TypeIdentifier::createAnyNodeType(q);

    case store::StoreConsts::textNode:
      return TypeIdentifier::createTextType(q);

    case store::StoreConsts::piNode:
      return TypeIdentifier::createPIType(q);

    case store::StoreConsts::commentNode:
      return TypeIdentifier::createCommentType(q);

    case store::StoreConsts::documentNode:
      return TypeIdentifier::createDocumentType(content_type, q);

    case store::StoreConsts::elementNode:
    {
      if (nt.is_schema_test()) 
      {
        ZORBA_ASSERT(nodeName);
        String uri( Unmarshaller::newString( nodeName->getNamespace() ) );
        String local( Unmarshaller::newString( nodeName->getLocalName() ) );

        return TypeIdentifier::createSchemaElementType(uri, local, q);
      }
      else
      {
        String uri;
        String local;
        if (nodeName)
        {
          uri   = nodeName->getNamespace().c_str();
          local = nodeName->getLocalName().c_str();
        }

        return TypeIdentifier::createElementType(uri,
                                                 nodeName == NULL,
                                                 local,
                                                 nodeName == NULL,
                                                 content_type,
                                                 q); 
      }
    }  
    case store::StoreConsts::attributeNode:
    {
      if (nt.is_schema_test()) 
      {
        ZORBA_ASSERT(nodeName);
        String uri( Unmarshaller::newString( nodeName->getNamespace() ) );
        String local( Unmarshaller::newString( nodeName->getLocalName() ) );

        return TypeIdentifier::createSchemaAttributeType(uri, local, q);
      }
      else
      {
        String uri;
        String local;
        if (nodeName)
        {
          uri   = nodeName->getNamespace().c_str();
          local = nodeName->getLocalName().c_str();
        }

        return TypeIdentifier::createAttributeType(uri,
                                                   nodeName == NULL,
                                                   local,
                                                   nodeName == NULL,
                                                   content_type,
                                                   q);
      }
    }
    default:
      // cannot happen
      ZORBA_ASSERT(false);
      return NULL;
    }
  }

  case XQType::ANY_TYPE_KIND:
  {
    return TypeIdentifier::createNamedType(
      Unmarshaller::newString(rtm.XS_ANY_TYPE_QNAME->getNamespace()),
      Unmarshaller::newString(rtm.XS_ANY_TYPE_QNAME->getLocalName()),
      q);
  }

  case XQType::ANY_SIMPLE_TYPE_KIND:
    return TypeIdentifier::createNamedType(
      Unmarshaller::newString(rtm.XS_ANY_SIMPLE_TYPE_QNAME->getNamespace()),
      Unmarshaller::newString(rtm.XS_ANY_SIMPLE_TYPE_QNAME->getLocalName()),
      q);

  case XQType::UNTYPED_KIND:
    return TypeIdentifier::createNamedType(
      Unmarshaller::newString(rtm.XS_UNTYPED_QNAME->getNamespace()),
      Unmarshaller::newString(rtm.XS_UNTYPED_QNAME->getLocalName()),
      q);

  case XQType::USER_DEFINED_KIND:
  {
    ZORBA_ASSERT(nested || type.isAtomicOne());

    store::Item* lQname = type.get_qname().getp();

    return TypeIdentifier::createNamedType(
      Unmarshaller::newString(lQname->getNamespace()), 
      Unmarshaller::newString(lQname->getLocalName()),
      q);
  }
  default:
    break;
  }

  ZORBA_ASSERT(false);
  return NULL;
}


/*******************************************************************************

********************************************************************************/
std::ostream& TypeOps::serialize(std::ostream& os, const XQType& type)
{
  return type.serialize_ostream(os);
}


/*******************************************************************************

********************************************************************************/
const char* TypeOps::decode_quantifier(TypeConstants::quantifier_t quant) 
{
  switch (quant) 
  {
  case TypeConstants::QUANT_ONE:
    return "";
  case TypeConstants::QUANT_QUESTION:
    return "?";
  case TypeConstants::QUANT_STAR:
    return "*";
  case TypeConstants::QUANT_PLUS:
      return "+";
  default:
    return "<unknown-quant>";
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
