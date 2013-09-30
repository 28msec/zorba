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

#include <vector>

#include "common/shared_types.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/zorbatypes_decl.h"

#include "system/globalenv.h"

#include "util/tracer.h"

#include "types/casting.h"
#include "types/typeconstants.h"
#include "types/typeops.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/numerics/numerics.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/arithmetic_impl.h"

#include "store/api/item_factory.h"
#include "store/api/item.h"

namespace zorba
{
//6.4.1 fn:abs
bool
AbsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::SchemaTypeCode type;
  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    assert(result->isAtomic());

    type = result->getTypeCode();

    if (type == store::XS_UNTYPED_ATOMIC)
    {
      GenericCast::castToBuiltinAtomic(result, result, store::XS_DOUBLE, NULL, loc);
      type = store::XS_DOUBLE;
    }

    if (TypeOps::is_subtype(type, store::XS_DOUBLE))
    {
      if (result->getDoubleValue() > 0 || result->getDoubleValue().isPosZero())
      {
        if (type != store::XS_DOUBLE)
          GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue());
      }
      else
      {
        GENV_ITEMFACTORY->createDouble(result, -result->getDoubleValue());
      }
    }
    else if (TypeOps::is_subtype(type, store::XS_FLOAT))
    {
      if ( result->getFloatValue() > 0 || result->getFloatValue().isPosZero())
      {
        if (type != store::XS_FLOAT)
          GENV_ITEMFACTORY->createFloat (result, result->getFloatValue());
      }
      else
      {
        GENV_ITEMFACTORY->createFloat(result, -result->getFloatValue());
      }
    }
    else if (TypeOps::is_subtype(type, store::XS_INTEGER))
    {
      if (result->getIntegerValue().sign() >= 0)
      {
        if (type != store::XS_INTEGER)
          GENV_ITEMFACTORY->createInteger(result, result->getIntegerValue());
      }
      else
      {
        GENV_ITEMFACTORY->createInteger(result, -result->getIntegerValue());
      }
    }
    else if (TypeOps::is_subtype(type, store::XS_DECIMAL))
    {
      if ( result->getDecimalValue().sign() >= 0)
      {
        if (type != store::XS_DECIMAL)
          GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue());
      }
      else
      {
        GENV_ITEMFACTORY->createDecimal(result, -result->getDecimalValue());
      }
    }
    else
    {
      xqtref_t type = tm->create_value_type(result);
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type->toSchemaString(), "fn:abs" ));
    }

    STACK_PUSH(true, state);
  }
  STACK_END(state);
}


//6.4.2 fn:ceiling
bool
CeilingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::SchemaTypeCode type;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = result->getTypeCode();

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if (TypeOps::is_subtype(type, store::XS_UNTYPED_ATOMIC))
    {
      GenericCast::castToBuiltinAtomic(result, result, store::XS_DOUBLE, NULL, loc);
      type = store::XS_DOUBLE;
    }

    if (TypeOps::is_subtype(type, store::XS_DOUBLE))
    {
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().ceil());
    }
    else if (TypeOps::is_subtype(type, store::XS_FLOAT))
    {
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().ceil());
    }
    else if (TypeOps::is_subtype(type, store::XS_INTEGER))
    {
      /* do nothing */
    }
    else if (TypeOps::is_subtype(type, store::XS_DECIMAL))
    {
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().ceil());
    }
    else
    {
      xqtref_t type = tm->create_value_type(result);
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:ceiling" ));
    }

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


//6.4.3 fn:floor
bool
FloorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::SchemaTypeCode type;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    assert(result->isAtomic());

    type = result->getTypeCode();

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if (TypeOps::is_subtype(type, store::XS_UNTYPED_ATOMIC))
    {
      GenericCast::castToBuiltinAtomic(result, result, store::XS_DOUBLE, NULL, loc);
      type = store::XS_DOUBLE;
    }

    if (TypeOps::is_subtype(type, store::XS_DOUBLE))
    {
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().floor());
    }
    else if (TypeOps::is_subtype(type, store::XS_FLOAT))
    {
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().floor());
    }
    else if(TypeOps::is_subtype(type, store::XS_INTEGER))
    {
      /* do nothing */
    }
    else if (TypeOps::is_subtype(type, store::XS_DECIMAL))
    {
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().floor());
    }
    else
    {
      xqtref_t type = tm->create_value_type(result);
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:floor"));
    }

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


bool
RoundIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::SchemaTypeCode type;
  store::Item_t precision;
  Integer precision_integer(0);

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    if (theChildren.size() == 2)
    {
      consumeNext(precision, theChildren[1].getp(), planState);
      assert(precision->isAtomic());

      precision_integer = precision->getIntegerValue();
    }

    assert(result->isAtomic());

    type = result->getTypeCode();

    if (TypeOps::is_subtype(type, store::XS_UNTYPED_ATOMIC))
    {
      GenericCast::castToBuiltinAtomic(result, result, store::XS_DOUBLE, NULL, loc);
      type = store::XS_DOUBLE;
    }

    if (TypeOps::is_subtype(type, store::XS_DOUBLE))
    {
      GENV_ITEMFACTORY->
      createDouble(result, result->getDoubleValue().round(precision_integer));
    }
    else if (TypeOps::is_subtype(type, store::XS_FLOAT))
    {
      GENV_ITEMFACTORY->
      createFloat(result, result->getFloatValue().round(precision_integer));
    }
    else if (TypeOps::is_subtype(type, store::XS_INTEGER))
    {
      if (precision_integer.sign() < 0)
        GENV_ITEMFACTORY->
        createInteger(result, result->getIntegerValue().round(precision_integer));
    }

    else if (TypeOps::is_subtype(type, store::XS_DECIMAL))
    {
      GENV_ITEMFACTORY->
      createDecimal(result, result->getDecimalValue().round(precision_integer));
    }
    else
    {
      xqtref_t type = tm->create_value_type(result);
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:round"));
    }

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


//6.4.5 fn:round-half-to-even
bool RoundHalfToEvenIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState ) const
{
  store::Item_t item;
  xs_integer precision;
  TypeManager const *const tm = theSctx->get_typemanager();
  store::SchemaTypeCode type;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren [0].getp(), planState))
  {
    assert(result->isAtomic());
    type = result->getTypeCode();

    if (theChildren.size() == 2)
    {
      consumeNext(item, theChildren[1].getp(), planState);
      assert(item->isAtomic());
      precision = item->getIntegerValue();
    }

    if (TypeOps::is_subtype(type, store::XS_UNTYPED_ATOMIC))
    {
      //
      // XQuery 3.0 3.1.5.2: Each item in the atomic sequence that is of type
      // xs:untypedAtomic is cast to the expected generalized atomic type. For
      // built-in functions where the expected type is specified as numeric,
      // arguments of type xs:untypedAtomic are cast to xs:double.
      //
      GenericCast::castToBuiltinAtomic(result, result, store::XS_DOUBLE, NULL, loc);
      type = store::XS_DOUBLE;
    }

    if (TypeOps::is_subtype(type, store::XS_DOUBLE))
    {
      GENV_ITEMFACTORY->
      createDouble(result, result->getDoubleValue().roundHalfToEven(precision));
    }
    else if (TypeOps::is_subtype(type, store::XS_FLOAT))
    {
      GENV_ITEMFACTORY->
      createFloat(result, result->getFloatValue().roundHalfToEven(precision));
    }
    else if (TypeOps::is_subtype(type, store::XS_INTEGER))
    {
      GENV_ITEMFACTORY->
      createInteger(result, result->getIntegerValue().roundHalfToEven(precision));
    }
    else if (TypeOps::is_subtype(type, store::XS_DECIMAL))
    {
      GENV_ITEMFACTORY->
      createDecimal(result, result->getDecimalValue().roundHalfToEven(precision));
    }
    else
    {
      xqtref_t type = tm->create_value_type(result);
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:round-half-to-even"));
    }

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
