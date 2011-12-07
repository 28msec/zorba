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
TypeConstants::atomic_type_code_t TypeOps::get_atomic_type_code(const XQType& type)
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
bool TypeOps::is_atomic(const TypeManager* tm, const XQType& type)
{
  CHECK_IN_SCOPE(tm, type, QueryLoc::null);

  if (type.get_quantifier() == TypeConstants::QUANT_ONE)
  {
    if (type.type_kind() == XQType::ATOMIC_TYPE_KIND)
    {
      return true;
    }
    else if (type.type_kind() == XQType::USER_DEFINED_KIND)
    {
      return reinterpret_cast<const UserDefinedXQType&>(type).isAtomic();
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_builtin_atomic(const TypeManager* tm, const XQType& type)
{
  CHECK_IN_SCOPE(tm, type, QueryLoc::null);

  return type.get_quantifier() == TypeConstants::QUANT_ONE &&
         type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_builtin_simple(const TypeManager* tm, const XQType& type)
{
  CHECK_IN_SCOPE(tm, type, QueryLoc::null);

  return type.type_kind() == XQType::ATOMIC_TYPE_KIND;
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
    case TypeConstants::XS_ANY_ATOMIC:
    case TypeConstants::XS_DATE:
    case TypeConstants::XS_TIME:
    case TypeConstants::XS_DATETIME:
    case TypeConstants::XS_GYEAR_MONTH:
    case TypeConstants::XS_GYEAR:
    case TypeConstants::XS_GMONTH_DAY:
    case TypeConstants::XS_GDAY:
    case TypeConstants::XS_GMONTH:
      return true;
    default: return false;
    }
    break;

  case XQType::ANY_TYPE_KIND:
  case XQType::ANY_SIMPLE_TYPE_KIND:
  case XQType::ITEM_KIND:
    return true;

  case XQType::USER_DEFINED_KIND:
    return true;  // TODO: finer analysis

  default:
    // NODE, EMPTY, NONE
    return false;
  }
}


/*******************************************************************************

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

  case XQType::UNTYPED_KIND:
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;

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

    const UserDefinedXQType& udType = static_cast<const UserDefinedXQType&>(type);

    return tm->create_named_type(udType.get_qname(),
                                 TypeConstants::QUANT_ONE,
                                 QueryLoc::null,
                                 err::XPTY0004);
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
    const TypeManager* tm,
    const XQType& subtype,
    const XQType& supertype,
    const QueryLoc& loc)
{
  CHECK_IN_SCOPE(tm, subtype, loc);
  CHECK_IN_SCOPE(tm, supertype, loc);

  if (subtype.type_kind() == XQType::NONE_KIND)
    return true;

  if (!RootTypeManager::QUANT_SUBTYPE_MATRIX[subtype.get_quantifier()]
                                            [supertype.get_quantifier()])
    return false;

  switch(supertype.type_kind()) 
  {
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
        const UserDefinedXQType& udSubtype = static_cast<const UserDefinedXQType&>(subtype);
        return udSubtype.isSubTypeOf(tm, supertype);
      }
      default:
      {
        // NODE, ITEM, ANY, ANY_SIMPLE, FUNCTION, UNTYPED
        return false;
      }
      }
      break;
    }

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
        // ATOMIC, ITEM, ANY, ANY_SIMPLE, UNTYPED, FUNCTION, USER_DEFINED (???)
        return false;
      }
      }
      break;
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
        return true;

      case XQType::USER_DEFINED_KIND:
      {
        const UserDefinedXQType& udSubType = static_cast<const UserDefinedXQType&>(subtype);

        // What about union of atomic types ????
        return udSubType.isAtomic();
      }

      default:
        // ANY, ANY_SIMPLE, UNTYPED
        return false;
      }
      break;
    }

    case XQType::ANY_TYPE_KIND:
    {
      switch(subtype.type_kind()) 
      {
      case XQType::ATOMIC_TYPE_KIND:
      case XQType::NODE_TYPE_KIND:
      case XQType::ITEM_KIND:
      case XQType::ANY_TYPE_KIND:
      case XQType::ANY_SIMPLE_TYPE_KIND:
      case XQType::UNTYPED_KIND:
      case XQType::EMPTY_KIND:
      case XQType::USER_DEFINED_KIND:
        return true;

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
        // ANY, UNTYPED, ITEM, NODE
        return false;
      }
      break;
    }

    case XQType::FUNCTION_TYPE_KIND:
    {
      switch (subtype.type_kind())
      {
      case XQType::ANY_FUNCTION_TYPE_KIND:
      case XQType::FUNCTION_TYPE_KIND:
      {
        const FunctionXQType& f1 = static_cast<const FunctionXQType&>(subtype);
        const FunctionXQType& f2 = static_cast<const FunctionXQType&>(supertype);
        return f1.is_subtype(tm, f2);
      }
      default:
        return false;
      }
    } // XQType::FUNCTION_TYPE_KIND

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
    } // XQTYPE::ANY_FUNCTION_TYPE_KIND

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

    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udSuperType = static_cast<const UserDefinedXQType&>(supertype);

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
    case XQType::ATOMIC_TYPE_KIND:
    {
      if (!subitem->isAtomic())
        return false;

      const AtomicXQType& a2 = static_cast<const AtomicXQType&>(supertype);

      if (a2.get_type_code() == TypeConstants::XS_ANY_ATOMIC)
        return true;

      xqtref_t subtype = tm->create_named_atomic_type(subitem->getType(),
                                                      TypeConstants::QUANT_ONE,
                                                      loc,
                                                      err::XPTY0004);
      switch(subtype->type_kind()) 
      {
      case XQType::ATOMIC_TYPE_KIND:
      {
        const AtomicXQType& a1 = static_cast<const AtomicXQType&>(*subtype);

        return RootTypeManager::ATOMIC_SUBTYPE_MATRIX[a1.get_type_code()][a2.get_type_code()];
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
        // NODE, ITEM, ANY, ANY_SIMPLE, FUNCTION, UNTYPED
        return false;
      }
      }
      break;
    }

    case XQType::NODE_TYPE_KIND:
    {
      if (!subitem->isNode())
        return false;

      const NodeXQType& n2 = static_cast<const NodeXQType&>(supertype);

      return n2.is_supertype(tm, subitem, loc);

      break;
    }

    case XQType::ITEM_KIND:
    case XQType::ANY_TYPE_KIND:
    {
      return true;
      break;
    }

    case XQType::ANY_SIMPLE_TYPE_KIND:
    {
      if (!subitem->isAtomic())
        return false;

      xqtref_t subtype = tm->create_named_atomic_type(subitem->getType(),
                                                      TypeConstants::QUANT_ONE,
                                                      loc,
                                                      err::XPTY0004);
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

    case XQType::UNTYPED_KIND:
    {
      // We shouldn't be here because xs:untyped is not a sequence type
      ZORBA_ASSERT(false);

      if (!subitem->getType()->equals(GENV_TYPESYSTEM.XS_UNTYPED_QNAME))
        return false;

      return true;
    }

    case XQType::EMPTY_KIND:
    case XQType::NONE_KIND:
    {
      return false;
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
                                                      err::XPTY0004);
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
  // return is_subtype(tm, *tm->create_value_type(item.getp(), loc), targetType, loc);
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
    return RootTypeManager::ATOMIC_CAST_MATRIX[aSrc.get_type_code()][aTarget.get_type_code()];
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
    if (type1.type_kind() == type2.type_kind())
    {
      switch (type1.type_kind()) 
      {
      case XQType::ATOMIC_TYPE_KIND:
        return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;
      case XQType::NODE_TYPE_KIND:
          return GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE;
      default:
        break;
      }
    }
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  }
  else
  {
    xqtref_t pt1 = prime_type(tm, type1);
    xqtref_t pt2 = prime_type(tm, type2);

    if (! is_equal(tm, type1, *pt1) || ! is_equal(tm, type2, *pt2))
    {
      return tm->create_type_x_quant(
                 *union_type(*pt1, *pt2, tm),
                 RootTypeManager::QUANT_UNION_MATRIX[TypeConstants::QUANT_QUESTION] /* to be on the safe side */
                 [RootTypeManager::QUANT_UNION_MATRIX[type1.get_quantifier()] [type2.get_quantifier()]]);
    }
    else
    {
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
  XQType::type_kind_t tk1 = type1.type_kind(), tk2 = type2.type_kind();

  if (tk1 < tk2)
    return intersect_type(type2, type1, tm);

  TypeConstants::quantifier_t q1 = type1.get_quantifier();
  TypeConstants::quantifier_t q2 = type2.get_quantifier();

  if (is_subtype(tm, type1, type2))
    return &type1;

  else if (is_subtype(tm, type2, type1))
    return &type2;

  else if (tk1 == XQType::EMPTY_KIND)
    return (q2 == TypeConstants::QUANT_QUESTION || q2 == TypeConstants::QUANT_STAR ?
            GENV_TYPESYSTEM.EMPTY_TYPE :
            GENV_TYPESYSTEM.NONE_TYPE);

  else if (tk2 == XQType::EMPTY_KIND)
    return (q1 == TypeConstants::QUANT_QUESTION || q1 == TypeConstants::QUANT_STAR ?
            GENV_TYPESYSTEM.EMPTY_TYPE :
            GENV_TYPESYSTEM.NONE_TYPE);

  else if (q1 == TypeConstants::QUANT_ONE && q2 == TypeConstants::QUANT_ONE) 
  {
    switch (tk1) 
    {
    case XQType::ATOMIC_TYPE_KIND:
      if (tk2 == XQType::NODE_TYPE_KIND || tk2 == XQType::ATOMIC_TYPE_KIND)
        return GENV_TYPESYSTEM.NONE_TYPE;
      else
        return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;
      break;

    case XQType::NODE_TYPE_KIND:
      return (tk2 != XQType::NODE_TYPE_KIND ?
              GENV_TYPESYSTEM.NONE_TYPE :
              GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE); // ????

    default:
      break;
    }

    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
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
      return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
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
type_ident_ref_t TypeOps::get_type_identifier(
    const TypeManager* tm,
    const XQType& type)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  IdentTypes::quantifier_t q = get_typeident_quant(type.get_quantifier());

  switch(type.type_kind()) 
  {
  case XQType::ATOMIC_TYPE_KIND:
  {
    const AtomicXQType& at = static_cast<const AtomicXQType&>(type);
    store::Item* qname = rtm.m_atomic_typecode_qname_map[at.get_type_code()];
    return TypeIdentifier::createNamedType(
      Unmarshaller::newString(qname->getNamespace()),
      Unmarshaller::newString(qname->getLocalName()),
      q
    );
  }
  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType& nt = static_cast<const NodeXQType&>(type);

    type_ident_ref_t content_type = (nt.get_content_type() != NULL ?
                                     get_type_identifier(tm, *nt.get_content_type()) :
                                     type_ident_ref_t());

    const store::Item* nodeName = nt.get_node_name();

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
      String uri( Unmarshaller::newString( nodeName->getNamespace() ) );
      String local( Unmarshaller::newString( nodeName->getLocalName() ) );

      return TypeIdentifier::createElementType(uri,
                                               nodeName == NULL,
                                               local,
                                               nodeName == NULL,
                                               content_type,
                                               q);
    }  
    case store::StoreConsts::attributeNode:
    {
      String uri( Unmarshaller::newString( nodeName->getNamespace() ) );
      String local( Unmarshaller::newString( nodeName->getLocalName() ) );

      return TypeIdentifier::createAttributeType(uri,
                                                 nodeName == NULL,
                                                 local,
                                                 nodeName == NULL,
                                                 content_type,
                                                 q);
    }
    default:
      // cannot happen
      ZORBA_ASSERT(false);
      return type_ident_ref_t();
    }
  }
  case XQType::ANY_TYPE_KIND:
    return TypeIdentifier::createNamedType(
      Unmarshaller::newString( rtm.XS_ANY_TYPE_QNAME->getNamespace() ),
      Unmarshaller::newString( rtm.XS_ANY_TYPE_QNAME->getLocalName() ),
      q
    );

  case XQType::ITEM_KIND:
    return TypeIdentifier::createItemType(q);

  case XQType::ANY_SIMPLE_TYPE_KIND:
    return TypeIdentifier::createNamedType(
      Unmarshaller::newString( rtm.XS_ANY_SIMPLE_TYPE_QNAME->getNamespace() ),
      Unmarshaller::newString( rtm.XS_ANY_SIMPLE_TYPE_QNAME->getLocalName() ),
      q
    );

  case XQType::UNTYPED_KIND:
    return TypeIdentifier::createNamedType(
      Unmarshaller::newString( rtm.XS_UNTYPED_QNAME->getNamespace() ),
      Unmarshaller::newString( rtm.XS_UNTYPED_QNAME->getLocalName() ),
      q
    );
    
  case XQType::EMPTY_KIND:
    return TypeIdentifier::createEmptyType();

  case XQType::USER_DEFINED_KIND:
    //TODO for Vinayak return type identifier
  default:
    break;
  }

  ZORBA_ASSERT(false);
  return type_ident_ref_t();
}


/*******************************************************************************

********************************************************************************/
std::ostream& TypeOps::serialize(std::ostream& os, const XQType& type)
{
  return type.serialize_ostream(os);
}


/*******************************************************************************

********************************************************************************/
std::string TypeOps::toString(const XQType& type)
{
  std::ostringstream os;
  serialize(os, type);
  return os.str ();
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
