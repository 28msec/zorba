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

#include "zorbaerrors/error_manager.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "runtime/core/sequencetypes.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"


using namespace std;

namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(InstanceOfIterator)
END_SERIALIZABLE_CLASS_VERSIONS(InstanceOfIterator)

SERIALIZABLE_CLASS_VERSIONS(CastIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CastIterator)

SERIALIZABLE_CLASS_VERSIONS(CastableIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CastableIterator)

SERIALIZABLE_CLASS_VERSIONS(PromoteIterator)
END_SERIALIZABLE_CLASS_VERSIONS(PromoteIterator)

SERIALIZABLE_CLASS_VERSIONS(TreatIterator)
END_SERIALIZABLE_CLASS_VERSIONS(TreatIterator)

SERIALIZABLE_CLASS_VERSIONS(EitherNodesOrAtomicsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(EitherNodesOrAtomicsIterator)

/*******************************************************************************

********************************************************************************/

InstanceOfIterator::InstanceOfIterator(
   static_context* sctx,
   const QueryLoc& loc,
   PlanIter_t& aTreatExpr,
   xqtref_t aSequenceType)
  :
  UnaryBaseIterator<InstanceOfIterator, PlanIteratorState>(sctx, loc, aTreatExpr),
  theSequenceType (aSequenceType)
{
}


InstanceOfIterator::~InstanceOfIterator()
{
}


bool InstanceOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lTreatItem;
  xqtref_t lTreatType;
  TypeConstants::quantifier_t lQuantifier;
  bool lResult;

  RootTypeManager& ts = GENV_TYPESYSTEM;
  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lQuantifier = TypeOps::quantifier(*theSequenceType);

  if (consumeNext(lTreatItem, theChild.getp(), planState))
  {
    if (TypeOps::is_treatable(tm, lTreatItem, *theSequenceType, loc))
    {
      if (consumeNext(lTreatItem, theChild.getp(), planState))
      {
        if (lQuantifier == TypeConstants::QUANT_ONE ||
            lQuantifier == TypeConstants::QUANT_QUESTION)
        {
          lResult = false;
        }
        else
        {
          lResult = true;
          do
          {
            if (!TypeOps::is_treatable(tm, lTreatItem, *theSequenceType, loc))
            {
              lResult = false;
            }
          } while (consumeNext(lTreatItem, theChild.getp(), planState));
        }
      }
      else
      {
        lResult = true;
      }
    }
    else
    {
      lResult = false;
    }
  }
  else
  {
    if ((lQuantifier == TypeConstants::QUANT_ONE ||
         lQuantifier == TypeConstants::QUANT_PLUS) &&
        !TypeOps::is_equal(tm, *ts.EMPTY_TYPE, *theSequenceType))
    {
      lResult = false;
    }
    else
    {
      lResult = true;
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, lResult), state);
  STACK_END (state);
}


UNARY_ACCEPT(InstanceOfIterator);


/*******************************************************************************

********************************************************************************/

CastIterator::CastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& aChild,
    const xqtref_t& aCastType)
  : UnaryBaseIterator<CastIterator, PlanIteratorState>(sctx, loc, aChild)
{
  theCastType = TypeOps::prime_type(sctx->get_typemanager(), *aCastType);
  theQuantifier = TypeOps::quantifier(*aCastType);
}


CastIterator::~CastIterator()
{
}


bool CastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  bool valid = false;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  ZORBA_ASSERT(theQuantifier == TypeConstants::QUANT_ONE ||
               theQuantifier == TypeConstants::QUANT_QUESTION);

  if (!consumeNext(lItem, theChild.getp(), planState))
  {
    if (theQuantifier == TypeConstants::QUANT_ONE)
    {
      throw XQUERY_EXCEPTION(
        XPTY0004,
        ERROR_PARAMS( ZED( EmptySeqNoCastToTypeWithQuantOne ) ),
        ERROR_LOC( loc )
      );
    }
  }
  else
  {
    if (theCastType->type_kind() == XQType::USER_DEFINED_KIND)
    {
      try
      {
        zstring strval;
        lItem->getStringValue2(strval);

        namespace_context tmp_ctx(theSctx);
        valid = GenericCast::castToAtomic(result, strval, theCastType, tm, &tmp_ctx);
      }
      catch (XQueryException &e)
      {
  set_source( e, loc );
  throw;
      }
    }
    else
    {
      try
      {
        valid = GenericCast::castToAtomic(result, lItem, theCastType, tm);
      }
      catch (XQueryException &e)
      {
        set_source( e, loc );
        throw;
      }
    }

    if (consumeNext(lItem, theChild.getp(), planState))
    {
      throw XQUERY_EXCEPTION(
        XPTY0004,
        ERROR_PARAMS( ZED( NoSeqCastToTypeWithQuantOneOrQuestion ) ),
        ERROR_LOC( loc )
      );
    }

    STACK_PUSH(valid, state);
  }

  STACK_END (state);
}


UNARY_ACCEPT(CastIterator);


/*******************************************************************************

********************************************************************************/

CastableIterator::CastableIterator(
  static_context* sctx,
  const QueryLoc& aLoc,
  PlanIter_t& aChild,
  const xqtref_t& aCastType)
:
  UnaryBaseIterator<CastableIterator, PlanIteratorState>(sctx, aLoc, aChild)
{
  theCastType = TypeOps::prime_type(sctx->get_typemanager(), *aCastType);
  theQuantifier = TypeOps::quantifier(*aCastType);
}


CastableIterator::~CastableIterator()
{
}


bool CastableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool lBool;
  store::Item_t lItem;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(lItem, theChild.getp(), planState))
  {
    if (theQuantifier == TypeConstants::QUANT_PLUS ||
        theQuantifier == TypeConstants::QUANT_ONE)
    {
      lBool = false;
    }
    else
    {
      lBool = true;
    }
  }
  else
  {
    lBool = GenericCast::isCastable(lItem, theCastType, tm);
    if (lBool)
    {
      if (consumeNext(lItem, theChild.getp(), planState))
      {
        if (theQuantifier == TypeConstants::QUANT_ONE ||
            theQuantifier == TypeConstants::QUANT_QUESTION)
        {
          lBool = false;
        }
        else
        {
          do
          {
            lBool = GenericCast::isCastable(lItem, theCastType, tm);
          } while (lBool && consumeNext(lItem, theChild.getp(), planState));
        }
      }
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, lBool), state);
  STACK_END(state);
}


UNARY_ACCEPT(CastableIterator);


/*******************************************************************************

********************************************************************************/

PromoteIterator::PromoteIterator(
    static_context* sctx,
    const QueryLoc& aLoc,
    PlanIter_t& aChild,
    const xqtref_t& aPromoteType,
    store::Item_t fnQName)
  :
  UnaryBaseIterator<PromoteIterator, PlanIteratorState>(sctx, aLoc, aChild),
  theFnQName(fnQName)
{
  thePromoteType = TypeOps::prime_type(sctx->get_typemanager(), *aPromoteType);
  theQuantifier = TypeOps::quantifier(*aPromoteType); 
}


PromoteIterator::~PromoteIterator()
{
}


bool PromoteIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  store::Item_t temp;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(lItem, theChild.getp(), planState))
  {
    if (theQuantifier == TypeConstants::QUANT_PLUS ||
        theQuantifier == TypeConstants::QUANT_ONE)
    {
      zstring const type = thePromoteType->toSchemaString() + (theQuantifier == TypeConstants::QUANT_PLUS? "+" : "");
      if ( theFnQName.getp() )
        throw XQUERY_EXCEPTION(
          XPTY0004,
          ERROR_PARAMS(
            ZED( EmptySeqNotAsFunctionResult_23 ),
            theFnQName->getStringValue(),
            type
          ),
          ERROR_LOC( loc )
        );
      else
        throw XQUERY_EXCEPTION(
          XPTY0004,
          ERROR_PARAMS( ZED( EmptySeqNoPromoteTo ), type ),
          ERROR_LOC( loc )
        );
    }
  }
  else if (theQuantifier == TypeConstants::QUANT_QUESTION ||
           theQuantifier == TypeConstants::QUANT_ONE)
  {
    if(consumeNext(temp, theChild.getp(), planState))
    {
      if ( theFnQName.getp() )
        throw XQUERY_EXCEPTION(
          XPTY0004,
          ERROR_PARAMS(
            ZED( NoSeqTypePromotion_23 ),
            BUILD_STRING(
              thePromoteType->toSchemaString(),
              (theQuantifier == TypeConstants::QUANT_QUESTION ? "?" : "")
            ),
            theFnQName->getStringValue()
          ),
          ERROR_LOC( loc )
        );
      else
        throw XQUERY_EXCEPTION(
          XPTY0004,
          ERROR_PARAMS( ZED( NoSeqTypePromotion ) ),
          ERROR_LOC( loc )
        );
    }

    // catch exceptions to add/change the error location
    try
    {
      if (! GenericCast::promote(result, lItem, thePromoteType, tm))
      {
        if ( theFnQName.getp() )
          throw XQUERY_EXCEPTION(
            XPTY0004,
            ERROR_PARAMS(
              ZED( NoTypePromotion_234 ),
              tm->create_value_type(lItem)->toSchemaString(),
              thePromoteType->toSchemaString(),
              theFnQName->getStringValue()
            ),
            ERROR_LOC( loc )
          );
        else
          throw XQUERY_EXCEPTION(
            XPTY0004,
            ERROR_PARAMS(
              ZED( NoTypePromotion_23 ),
              tm->create_value_type(lItem)->toSchemaString(),
              thePromoteType->toSchemaString()
            ),
            ERROR_LOC( loc )
          );
      }
    }
    catch(XQueryException &e)
    {
      set_source( e, loc );
      throw;
    }

    STACK_PUSH(true, state);
  }
  else
  {
    do
    {
      if (! GenericCast::promote(result, lItem, thePromoteType, tm))
      {
        if ( theFnQName.getp() )
          throw XQUERY_EXCEPTION(
            XPTY0004,
            ERROR_PARAMS(
              ZED( NoTypePromotion_234 ),
              tm->create_value_type(lItem)->toSchemaString(),
              thePromoteType->toSchemaString(),
              theFnQName->getStringValue()
            ),
            ERROR_LOC( loc )
          );
        else
          throw XQUERY_EXCEPTION(
            XPTY0004,
            ERROR_PARAMS(
              ZED( NoTypePromotion_23 ),
              tm->create_value_type(lItem)->toSchemaString(),
              thePromoteType->toSchemaString()
            ),
            ERROR_LOC( loc )
          );
      }
      else
      {
        STACK_PUSH(true, state);
      }
    }
    while (consumeNext(lItem, theChild.getp(), planState));
  }

  STACK_END(state);
}


UNARY_ACCEPT(PromoteIterator);


/*******************************************************************************

********************************************************************************/

TreatIterator::TreatIterator(
    static_context* sctx,
    const QueryLoc& aLoc,
    PlanIter_t& aChild,
    const xqtref_t& aTreatType,
    bool check_prime_,
    Error const &aErrorCode,
    store::Item_t fnQName)
  :
  UnaryBaseIterator<TreatIterator, PlanIteratorState>(sctx, aLoc, aChild),
  check_prime(check_prime_),
  theErrorCode((Error*)&aErrorCode),
  theFnQName(fnQName)
{
  theTreatType = TypeOps::prime_type(sctx->get_typemanager(), *aTreatType);
  theQuantifier = TypeOps::quantifier(*aTreatType);
}


bool TreatIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t temp;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(result, theChild.getp(), planState))
  {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE)
    {
      zstring type = theTreatType->toSchemaString() + (theQuantifier == TypeConstants::QUANT_PLUS? "+" : "");
      ZORBA_ERROR_VAR_LOC_DESC(*theErrorCode, loc, 
        (theFnQName.getp() != NULL)?
                  "An empty sequence is not allowed as the result of the function " 
                  + theFnQName->getStringValue() + "() which returns " + type + "."
              :   
                  "Cannot treat empty sequence as " + type + ".");
    }
  }
  else if (theQuantifier == TypeConstants::QUANT_QUESTION ||
           theQuantifier == TypeConstants::QUANT_ONE)
  {
    if (consumeNext(temp, theChild.getp(), planState))
    {
      zstring type = theTreatType->toSchemaString() + (theQuantifier == TypeConstants::QUANT_PLUS? "?" : "");
      ZORBA_ERROR_VAR_LOC_DESC(*theErrorCode, loc, 
          (theFnQName.getp() != NULL)?
                "A sequence with more than one item cannot be the result of the function " 
                + theFnQName->getStringValue() + "() which returns " + type + "."
            :   
                "Cannot treat sequence with more than one item as " + type + ".");
    }

    if (check_prime && !TypeOps::is_treatable(tm, result, *theTreatType))
    {
      zstring msg = (theFnQName.getp() != NULL)?
              "Cannot treat " + tm->create_value_type(result)->toSchemaString() 
              + " as " + theTreatType->toSchemaString() + " when returning the result of the function "
              + theFnQName->getStringValue() + "()."
          :
              "Cannot treat " + tm->create_value_type(result)->toSchemaString() 
              + " as " + theTreatType->toSchemaString() + ".";

      xqtref_t subtype = tm->create_value_type(result);
      if (subtype->type_kind() == XQType::ATOMIC_TYPE_KIND &&
        theTreatType->type_kind() == XQType::ATOMIC_TYPE_KIND && 
        static_cast<const AtomicXQType*>(subtype.getp())->get_type_code() == TypeConstants::XS_STRING &&
        static_cast<const AtomicXQType*>(theTreatType.getp())->get_type_code() == TypeConstants::XS_QNAME)
      {
        msg += " Treating as xs:QName is permitted only if the xs:string is written as a string literal.";
      }

      ZORBA_ERROR_VAR_LOC_DESC(*theErrorCode, loc, msg);
    }
    else
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    do
    {
      if (check_prime && !TypeOps::is_treatable(tm, result, *theTreatType))
      {
        ZORBA_ERROR_VAR_LOC_DESC(*theErrorCode, loc,
          (theFnQName.getp() != NULL)?
              "Cannot treat " + tm->create_value_type(result)->toSchemaString() 
              + " as " + theTreatType->toSchemaString() + " when returning the result of the function "
              + theFnQName->getStringValue() + "()."
          :
              "Cannot treat " + tm->create_value_type(result)->toSchemaString() 
              + " as " + theTreatType->toSchemaString());
      }
      else
      {
        STACK_PUSH(true, state);
      }
    } while (consumeNext(result, theChild.getp(), planState));
  }

  STACK_END(state);
}


UNARY_ACCEPT(TreatIterator);


/*******************************************************************************

********************************************************************************/
bool EitherNodesOrAtomicsIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  EitherNodesOrAtomicsIteratorState* lState;
  DEFAULT_STACK_INIT(EitherNodesOrAtomicsIteratorState, lState, planState);

  if (CONSUME (result, 0))
  {
    lState->atomics = result->isAtomic ();
    STACK_PUSH (true, lState);

    while (CONSUME (result, 0))
    {
      if (lState->atomics != result->isAtomic ())
        throw XQUERY_EXCEPTION (XPTY0018, ERROR_LOC(loc));
      STACK_PUSH (true, lState);
    }
  }

  STACK_END (lState);
}


NARY_ACCEPT(EitherNodesOrAtomicsIterator);


} // namespace zorba
/* vim:set et sw=2 ts=2: */
