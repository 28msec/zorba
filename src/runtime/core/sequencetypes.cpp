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

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "runtime/core/sequencetypes.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(InstanceOfIterator)

SERIALIZABLE_CLASS_VERSIONS(CastIterator)

SERIALIZABLE_CLASS_VERSIONS(CastableIterator)

SERIALIZABLE_CLASS_VERSIONS(PromoteIterator)

SERIALIZABLE_CLASS_VERSIONS(TreatIterator)

SERIALIZABLE_CLASS_VERSIONS(EitherNodesOrAtomicsIterator)


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


void InstanceOfIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<InstanceOfIterator, PlanIteratorState>*)this);

  ar & theSequenceType;
}


bool InstanceOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  TypeConstants::quantifier_t quant;
  bool res = false;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  quant = TypeOps::quantifier(*theSequenceType);

  if (consumeNext(item, theChild.getp(), planState))
  {
    if (theSequenceType->type_kind() == XQType::ATOMIC_TYPE_KIND &&
        item->isAtomic())
    {
      store::SchemaTypeCode targetType = 
      static_cast<const AtomicXQType*>(theSequenceType.getp())->get_type_code();

      store::SchemaTypeCode itemType = item->getTypeCode();

      if (TypeOps::is_subtype(itemType, targetType))
      {
        if (consumeNext(item, theChild.getp(), planState))
        {
          if (quant == TypeConstants::QUANT_PLUS || quant == TypeConstants::QUANT_STAR)
          {
            res = true;
            do
            {
              if (item->isAtomic())
              {
                itemType = item->getTypeCode();
                res = TypeOps::is_subtype(itemType, targetType);
              }
              else 
              {
                res = false;
              }

              if (res == false)
              {
                theChild->reset(planState);
                break;
              }
            }
            while (consumeNext(item, theChild.getp(), planState));
          }
        }
        else
        {
          res = true;
        }
      }
    }
    else if (TypeOps::is_treatable(tm, item, *theSequenceType, loc))
    {
      if (consumeNext(item, theChild.getp(), planState))
      {
        if (quant == TypeConstants::QUANT_PLUS || quant == TypeConstants::QUANT_STAR)
        {
          res = true;
          do
          {
            if (!TypeOps::is_treatable(tm, item, *theSequenceType, loc))
            {
              res = false;
              theChild->reset(planState);
              break;
            }
          }
          while (consumeNext(item, theChild.getp(), planState));
        }
      }
      else
      {
        res = true;
      }
    }
  }
  else
  {
    res = !(quant == TypeConstants::QUANT_ONE || quant == TypeConstants::QUANT_PLUS);
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, res), state);
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


void CastIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (UnaryBaseIterator<CastIterator, PlanIteratorState>*)this);
  ar & theCastType;
  SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
}


bool CastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  bool valid = false;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  assert(theQuantifier == TypeConstants::QUANT_ONE ||
         theQuantifier == TypeConstants::QUANT_QUESTION);

  if (!consumeNext(item, theChild.getp(), planState))
  {
    if (theQuantifier == TypeConstants::QUANT_ONE)
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(EmptySeqNoCastToTypeWithQuantOne)));
    }
  }
  else
  {
    if (theCastType->type_kind() == XQType::ATOMIC_TYPE_KIND)
    {
      store::SchemaTypeCode targetType = 
      static_cast<const AtomicXQType*>(theCastType.getp())->get_type_code();

      valid = GenericCast::castToAtomic(result, item, targetType, tm, NULL, loc);
    }
    else
    {
      assert(theCastType->type_kind() == XQType::USER_DEFINED_KIND);

      zstring strval;
      item->getStringValue2(strval);
      
      namespace_context tmp_ctx(theSctx);
      valid = GenericCast::castToAtomic(result, strval, theCastType, tm, &tmp_ctx, loc);
    }

    if (consumeNext(item, theChild.getp(), planState))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqCastToTypeWithQuantOneOrQuestion)));
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


void CastableIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<CastableIterator, PlanIteratorState>*)this);

  ar & theCastType;
  SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
}


bool CastableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool res;
  store::Item_t item;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item, theChild.getp(), planState))
  {
    res = !(theQuantifier == TypeConstants::QUANT_PLUS ||
            theQuantifier == TypeConstants::QUANT_ONE);
  }
  else
  {
    res = GenericCast::isCastable(item, theCastType, tm);
    if (res)
    {
      if (consumeNext(item, theChild.getp(), planState))
      {
        if (theQuantifier == TypeConstants::QUANT_ONE ||
            theQuantifier == TypeConstants::QUANT_QUESTION)
        {
          res = false;
        }
        else
        {
          res = true;
          do
          {
            if (!GenericCast::isCastable(item, theCastType, tm))
            {
              res = false;
              theChild->reset(planState);
              break;
            }
          } 
          while (consumeNext(item, theChild.getp(), planState));
        }
      }
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, res), state);
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


void PromoteIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<PromoteIterator, PlanIteratorState>*)this);

  ar & thePromoteType;
  SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
  ar & theFnQName;
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
      zstring type = thePromoteType->toSchemaString() + 
                     (theQuantifier == TypeConstants::QUANT_PLUS? "+" : "");

      if (theFnQName.getp())
      {
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(EmptySeqNotAsFunctionResult_23),
                     theFnQName->getStringValue(),
                     type));
      }
      else
      {
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(EmptySeqNoPromoteTo), type));
      }
    }
  }
  else if (theQuantifier == TypeConstants::QUANT_QUESTION ||
           theQuantifier == TypeConstants::QUANT_ONE)
  {
    if (consumeNext(temp, theChild.getp(), planState))
    {
      if (theFnQName.getp())
      {
        std::string tmp = BUILD_STRING(thePromoteType->toSchemaString(),
                                       (theQuantifier == TypeConstants::QUANT_QUESTION ?
                                        "?" : ""));

        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(NoSeqTypePromotion_23),
                     tmp,
                     theFnQName->getStringValue()));
      }
      else
      {
        RAISE_ERROR(err::XPTY0004, loc, ERROR_PARAMS(ZED(NoSeqTypePromotion)));
      }
    }

    // catch exceptions to add/change the error location
    if (! GenericCast::promote(result, lItem, thePromoteType, tm, loc))
    {
      xqtref_t valueType = tm->create_value_type(lItem);

      if ( theFnQName.getp() )
      {
        throw XQUERY_EXCEPTION(err::XPTY0004,
                               ERROR_PARAMS(ZED(NoTypePromotion_234),
                                            valueType->toSchemaString(),
                                            thePromoteType->toSchemaString(),
                                            theFnQName->getStringValue()),
                               ERROR_LOC(loc));
      }
      else
      {
        throw XQUERY_EXCEPTION(err::XPTY0004,
                               ERROR_PARAMS(ZED(NoTypePromotion_23),
                                            valueType->toSchemaString(),
                                            thePromoteType->toSchemaString()),
                               ERROR_LOC(loc));
      }
    }

    STACK_PUSH(true, state);
  }
  else
  {
    do
    {
      if (! GenericCast::promote(result, lItem, thePromoteType, tm, loc))
      {
        if (theFnQName.getp())
        {
          RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(ZED(NoTypePromotion_234),
                       tm->create_value_type(lItem)->toSchemaString(),
                       thePromoteType->toSchemaString(),
                       theFnQName->getStringValue()));
        }
        else
        {
          RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(ZED(NoTypePromotion_23),
                       tm->create_value_type(lItem)->toSchemaString(),
                       thePromoteType->toSchemaString()));
        }
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
    const QueryLoc& loc,
    PlanIter_t& aChild,
    const xqtref_t& aTreatType,
    bool checkPrime,
    const Error& aErrorCode,
    store::Item_t fnQName)
  :
  UnaryBaseIterator<TreatIterator, PlanIteratorState>(sctx, loc, aChild),
  theCheckPrime(checkPrime),
  theErrorCode(&aErrorCode),
  theFnQName(fnQName)
{
  theTreatType = TypeOps::prime_type(sctx->get_typemanager(), *aTreatType);
  theQuantifier = TypeOps::quantifier(*aTreatType);
}


void TreatIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<TreatIterator, PlanIteratorState>*)this);

  ar & theTreatType;
  SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
  ar & theCheckPrime;
  ar & theErrorCode;
  ar & theFnQName;
}


bool TreatIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t temp;
  bool res;
  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(result, theChild.getp(), planState))
  {
    if (theQuantifier == TypeConstants::QUANT_PLUS || 
        theQuantifier == TypeConstants::QUANT_ONE)
    {
      zstring type = theTreatType->toSchemaString() + 
                     (theQuantifier == TypeConstants::QUANT_PLUS? "+" : "");

      if (theFnQName.getp() != NULL)
      {
        ZORBA_ERROR_VAR_LOC_OSS(*theErrorCode, loc, 
                                "An empty sequence is not allowed as the result "
                                << "of the function " 
                                << theFnQName->getStringValue() 
                                << "() which returns " << type << ".");
      }
      else
      {
        ZORBA_ERROR_VAR_LOC_OSS(*theErrorCode, loc, 
                                "Cannot treat empty sequence as " << type << ".");
      }
    }
  }
  else if (theQuantifier == TypeConstants::QUANT_QUESTION ||
           theQuantifier == TypeConstants::QUANT_ONE)
  {
    if (consumeNext(temp, theChild.getp(), planState))
    {
      zstring type = theTreatType->toSchemaString() + 
                     (theQuantifier == TypeConstants::QUANT_PLUS? "?" : "");

      if (theFnQName.getp() != NULL)
      {
        ZORBA_ERROR_VAR_LOC_OSS(*theErrorCode, loc, 
                                "A sequence with more than one item cannot be "
                                << "the result of the function " 
                                << theFnQName->getStringValue() 
                                << "() which returns " << type << ".");
      }
      else
      {
        ZORBA_ERROR_VAR_LOC_OSS(*theErrorCode, loc, 
                                "Cannot treat sequence with more than one item as "
                                << type << ".");
      }
    }

    if (theCheckPrime)
    {
      if (theTreatType->type_kind() == XQType::ATOMIC_TYPE_KIND &&
          result->isAtomic())
      {
        store::SchemaTypeCode targetType = 
        static_cast<const AtomicXQType*>(theTreatType.getp())->get_type_code();

        store::SchemaTypeCode itemType = result->getTypeCode();

        res = TypeOps::is_subtype(itemType, targetType);
      }
      else
      {
        res = TypeOps::is_subtype(tm, result, *theTreatType, loc);
      }
      
      if (!res)
      {
        xqtref_t valueType = tm->create_value_type(result);

        if (theFnQName.getp() != NULL)
        {
          ZORBA_ERROR_VAR_LOC_OSS(*theErrorCode, loc,
                                  "Cannot treat " << valueType->toSchemaString() 
                                  << " as " << theTreatType->toSchemaString()
                                  << " when returning the result of the function "
                                  << theFnQName->getStringValue() << "().");
        }
        else
        {
          ZORBA_ERROR_VAR_LOC_OSS(*theErrorCode, loc, 
                                  "Cannot treat " << valueType->toSchemaString() 
                                  << " as " << theTreatType->toSchemaString()
                                  << ".");
        }
      }
    }

    STACK_PUSH(true, state);
  }
  else
  {
    do
    {
      if (theCheckPrime) 
      {
        if (theTreatType->type_kind() == XQType::ATOMIC_TYPE_KIND &&
            result->isAtomic())
        {
          store::SchemaTypeCode targetType = 
          static_cast<const AtomicXQType*>(theTreatType.getp())->get_type_code();

          store::SchemaTypeCode itemType = result->getTypeCode();

          res = TypeOps::is_subtype(itemType, targetType);
        }
        else
        {
          res = TypeOps::is_subtype(tm, result, *theTreatType, loc);
        } 
        
        if (!res)
        {
          xqtref_t valueType = tm->create_value_type(result);

          if (theFnQName.getp() != NULL)
          {
            ZORBA_ERROR_VAR_LOC_OSS(*theErrorCode, loc,
                                    "Cannot treat " + valueType->toSchemaString() 
                                    << " as " << theTreatType->toSchemaString()
                                    << " when returning the result of the function "
                                    << theFnQName->getStringValue() << "().");
          }
          else
          {
            ZORBA_ERROR_VAR_LOC_OSS(*theErrorCode, loc,
                                    "Cannot treat " << valueType->toSchemaString() 
                                    << " as " << theTreatType->toSchemaString());
          }
        }
      }

      STACK_PUSH(true, state);
    } 
    while (consumeNext(result, theChild.getp(), planState));
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
  EitherNodesOrAtomicsIteratorState* state;
  DEFAULT_STACK_INIT(EitherNodesOrAtomicsIteratorState, state, planState);

  if (CONSUME(result, 0))
  {
    state->atomics = result->isAtomic();

    STACK_PUSH(true, state);

    while (CONSUME(result, 0))
    {
      if (state->atomics != result->isAtomic())
        throw XQUERY_EXCEPTION(err::XPTY0018, ERROR_LOC(loc));

      STACK_PUSH (true, state);
    }
  }

  STACK_END(state);
}


NARY_ACCEPT(EitherNodesOrAtomicsIterator);


} // namespace zorba
/* vim:set et sw=2 ts=2: */
