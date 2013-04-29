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
  xqtref_t type;

  const TypeManager* tm = theSctx->get_typemanager();

  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    if (TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type(result);
    }

    if (TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
    {
      if (result->getDoubleValue().isPos() || result->getDoubleValue().isPosZero())
      {
        if ( !TypeOps::is_equal(tm, *type, *rtm.DOUBLE_TYPE_ONE))
          GENV_ITEMFACTORY->createDouble (result, result->getDoubleValue());
      }
      else
      {
        GENV_ITEMFACTORY->createDouble(result, -result->getDoubleValue());
      }
    }
    else if (TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
    {
      if ( result->getFloatValue().isPos() || result->getFloatValue().isPosZero())
      {
        if ( !TypeOps::is_equal(tm, *type, *rtm.FLOAT_TYPE_ONE))
          GENV_ITEMFACTORY->createFloat (result, result->getFloatValue());
      }
      else
      {
        GENV_ITEMFACTORY->createFloat(result, -result->getFloatValue());
      }
    }
    else if (TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    {
      if (result->getIntegerValue().sign() >= 0)
      {
        if ( !TypeOps::is_equal(tm, *type, *rtm.INTEGER_TYPE_ONE))
          GENV_ITEMFACTORY->createInteger(result, result->getIntegerValue());
      }
      else
      {
        GENV_ITEMFACTORY->createInteger(result, -result->getIntegerValue());
      }
    }
    else if (TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE))
    {
      if ( result->getDecimalValue().sign() >= 0)
      {
        if ( !TypeOps::is_equal(tm, *type, *rtm.DECIMAL_TYPE_ONE))
          GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue());
      }
      else
      {
        GENV_ITEMFACTORY->createDecimal (result, -result->getDecimalValue());
      }
    }
    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:abs" ));
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:abs"));
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
  xqtref_t type;

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().ceil());

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().ceil());

    //item type is subtype of INTEGER
    else if(TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    { /* do nothing */ }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().ceil());

    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:ceiling" ));
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:ceiling"));
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
  xqtref_t type;

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if (TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if (TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().floor());

    //item type is subtype of FLOAT
    else if (TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().floor());

    //item type is subtype of INTEGER
    else if(TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    { /* do nothing */ }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().floor());

    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:floor"));
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ) )
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:floor" ));
    }
    STACK_PUSH (true, state );
  }
  STACK_END (state);
}

bool
RoundIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;
  store::Item_t precision;
  Integer precision_integer(0);

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

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

    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm->create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = tm->create_value_type(result);
    }

    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().round(precision_integer));

    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE))
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().round(precision_integer));

    //item type is subtype of INTEGER
    else if(TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE))
    {
      if(precision_integer < numeric_consts<xs_integer>::zero())
        GENV_ITEMFACTORY->createInteger(result, result->getIntegerValue().round(precision_integer));
    }

    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().round(precision_integer));

    else
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type, "fn:round"));
    }

    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqForFnOp_2), "fn:round" ));
    }
    STACK_PUSH (true, state );
  }
  STACK_END (state);
}

//6.4.5 fn:round-half-to-even
bool RoundHalfToEvenIterator::nextImpl( store::Item_t &result,
                                        PlanState& planState ) const {
  store::Item_t item;
  xs_integer precision;
  RootTypeManager const &rtm = GENV_TYPESYSTEM;
  TypeManager const *const tm = theSctx->get_typemanager();
  xqtref_t type;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  if ( consumeNext( result, theChildren [0].getp(), planState ) ) {
    assert( result->isAtomic() );
    type = tm->create_value_type( result );

    if ( theChildren.size() == 2 ) {
      consumeNext( item, theChildren[1].getp(), planState );
      assert( item->isAtomic() );
      precision = item->getIntegerValue();
    }

    if ( TypeOps::is_subtype( tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) ) {
      //
      // XQuery 3.0 3.1.5.2: Each item in the atomic sequence that is of type
      // xs:untypedAtomic is cast to the expected generalized atomic type. For
      // built-in functions where the expected type is specified as numeric,
      // arguments of type xs:untypedAtomic are cast to xs:double.
      //
      GenericCast::castToAtomic(
        result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc
      );
      type = tm->create_value_type( result );
    }

    if ( TypeOps::is_subtype( tm, *type, *rtm.DOUBLE_TYPE_ONE ) )
      GENV_ITEMFACTORY->createDouble(
        result, result->getDoubleValue().roundHalfToEven( precision )
      );

    else if ( TypeOps::is_subtype( tm, *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(
        result, result->getFloatValue().roundHalfToEven( precision )
      );

    else if ( TypeOps::is_subtype( tm, *type, *rtm.INTEGER_TYPE_ONE ) )
      GENV_ITEMFACTORY->createInteger(
        result, result->getIntegerValue().roundHalfToEven( precision )
      );

    else if ( TypeOps::is_subtype( tm, *type, *rtm.DECIMAL_TYPE_ONE ) )
      GENV_ITEMFACTORY->createDecimal(
        result, result->getDecimalValue().roundHalfToEven( precision )
      );

    else
      throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS( ZED( BadTypeFor_23 ), type, "fn:round-half-to-even" ),
        ERROR_LOC( loc )
      );

    if ( consumeNext( item, theChildren [0].getp(), planState ) ) {
      throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS( ZED( NoSeqForFnOp_2 ), "fn:round-half-to-even" ),
        ERROR_LOC( loc )
      );
    }
    STACK_PUSH( true, state );
  }
  STACK_END( state );
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
