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

#include "zorbatypes/collation_manager.h"
#include "zorbatypes/datetime.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"

#include "store/api/temp_seq.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"


namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(FnBooleanIterator)

SERIALIZABLE_CLASS_VERSIONS(OrIterator)

SERIALIZABLE_CLASS_VERSIONS(AndIterator)

SERIALIZABLE_CLASS_VERSIONS(CompareIterator)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<store::XS_DOUBLE>, 1)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<store::XS_FLOAT>, 2)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<store::XS_DECIMAL>, 3)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<store::XS_INTEGER>, 4)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<store::XS_STRING>, 5)

SERIALIZABLE_CLASS_VERSIONS(AtomicValuesEquivalenceIterator)


/*******************************************************************************
  15.1.1 fn:boolean
********************************************************************************/
FnBooleanIterator::FnBooleanIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& aIter,
    bool aNegate)
  :
  UnaryBaseIterator<FnBooleanIterator, PlanIteratorState>(sctx, loc, aIter),
  theNegate(aNegate)
{
}


bool FnBooleanIterator::effectiveBooleanValue(
    const QueryLoc& loc,
    PlanState& planState,
    const PlanIterator* iter,
    bool negate)
{
  store::Item_t item;
  bool result;
  bool is_sequence;

  TypeManager* tm = iter->getStaticContext()->get_typemanager();

  if (!consumeNext(item, iter, planState))
  {
    // empty sequence => false
    result = negate ^ false;
  }
  else if (item->isNode())
  {
    // node => true
    result = negate ^ true;
  }
  else
  {
    store::SchemaTypeCode type = item->getTypeCode();

    store::Item_t item2;
    is_sequence = consumeNext(item2, iter, planState);

    if (!is_sequence 
        &&
        (type == store::XS_BOOLEAN ||
         TypeOps::is_subtype(type, store::XS_STRING) ||
         TypeOps::is_subtype(type, store::XS_ANY_URI) ||
         type == store::XS_UNTYPED_ATOMIC ||
         TypeOps::is_numeric(type)))
    {
      // atomic type xs_boolean, xs_string, xs_anyURI, xs_untypedAtomic
      // => effective boolean value is defined in the items
      bool temp = item->getEBV();
      result = negate ? (negate ^ temp) : temp;
    }
    else
    {
      if (is_sequence)
      {
        xqtref_t type = tm->create_value_type(item);

        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     "", "fn:boolean",
                     ZED(EBVNotDefSeq_5),
                     *type));
      }
      else
      {
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o), "", "fn:boolean" ));
      }
    }
  }

  return result;
}


bool FnBooleanIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);

  GENV_ITEMFACTORY->
  createBoolean(result,
                FnBooleanIterator::effectiveBooleanValue(this->loc,
                                                         planState,
                                                         theChild,
                                                         theNegate));
  STACK_PUSH(true, aState);
  STACK_END(aState);
}


UNARY_ACCEPT(FnBooleanIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrIterator                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


OrIterator::OrIterator (
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& inChildren)
  :
  NaryBaseIterator<OrIterator, PlanIteratorState>(sctx, loc, inChildren)
{
}


void 
OrIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NaryBaseIterator<OrIterator, PlanIteratorState>*)this);
}


bool
OrIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool res = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  {
    std::vector<PlanIter_t>::const_iterator ite = theChildren.begin();
    std::vector<PlanIter_t>::const_iterator end = theChildren.end();
    for (; res == false && ite != end; ++ite)
    {
      res = res ||
            FnBooleanIterator::effectiveBooleanValue(loc, planState, (*ite));
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, res), state);
  STACK_END(state);
}


NARY_ACCEPT(OrIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  AndIterator                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

AndIterator::AndIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& inChildren)
  :
  NaryBaseIterator<AndIterator, PlanIteratorState>(sctx, loc, inChildren)
{
}


void 
AndIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NaryBaseIterator<AndIterator, PlanIteratorState>*)this);
}


bool
AndIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool res = true;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  {
    std::vector<PlanIter_t>::const_iterator ite = theChildren.begin();
    std::vector<PlanIter_t>::const_iterator end = theChildren.end();
    for (; res && ite != end; ++ite)
    {
      res = res &&
            FnBooleanIterator::effectiveBooleanValue(loc, planState, (*ite));
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, res), state);
  STACK_END(state);
}


NARY_ACCEPT(AndIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  CompareIterator                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
CompareIterator::CompareIterator(
     static_context* sctx,
     const QueryLoc& loc,
     PlanIter_t aChild0,
     PlanIter_t aChild1,
     CompareConsts::CompareType aCompType)
  :
  BinaryBaseIterator<CompareIterator, PlanIteratorState> ( sctx, loc, aChild0, aChild1 ),
  theCompType(aCompType),
  theTypeManager(NULL),
  theTimezone(0),
  theCollation(NULL)
{
  switch(theCompType)
  {
  case CompareConsts::GENERAL_EQUAL:
  case CompareConsts::GENERAL_NOT_EQUAL:
  case CompareConsts::GENERAL_LESS:
  case CompareConsts::GENERAL_LESS_EQUAL:
  case CompareConsts::GENERAL_GREATER:
  case CompareConsts::GENERAL_GREATER_EQUAL:
    theIsGeneralComparison = true;
    break;
  default:
    theIsGeneralComparison = false;
    break;
  }
}


BINARY_ACCEPT(CompareIterator);


/*******************************************************************************

********************************************************************************/
void CompareIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  BinaryBaseIterator<CompareIterator, PlanIteratorState>::openImpl(planState, offset);

  theTypeManager = theSctx->get_typemanager();
  theCollation = theSctx->get_default_collator(loc);
  theTimezone = planState.theLocalDynCtx->get_implicit_timezone();
}


/*******************************************************************************

********************************************************************************/
bool CompareIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item0, item1, tItem0, tItem1;
  bool c0Done = false, c1Done = false, done = false, found = false;
  std::vector<store::Item_t> seq0;
  std::vector<store::Item_t> seq1;
  store::TempSeq_t tSeq0, tSeq1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theIsGeneralComparison)
  {
    if (consumeNext(item0, theChild0.getp(), planState))
    {
      if (consumeNext(tItem0, theChild0.getp(), planState))
      {
        seq0.push_back(item0);
        seq0.push_back(tItem0);
      }
      else
      {
        c0Done = true;
        if (consumeNext(item1, theChild1.getp(), planState))
        {
          if (consumeNext(tItem1, theChild1.getp(), planState))
          {
            seq0.push_back(item0);
            seq1.push_back(item1);
            seq1.push_back(tItem1);
          }
          else
          {
            c1Done = true;
            found = generalComparison(loc,
                                      item0,
                                      item1,
                                      theCompType,
                                      theTypeManager,
                                      theTimezone,
                                      theCollation);
            done = true;
          }
        }
        else
        {
          c1Done = true;
          found = false;
          done = true;
        }
      }
    }
    else
    {
      c0Done = true;
      found = false;
      done = true;
    }

    if (!done)
    {
      store::Iterator_t ite0;
      store::Iterator_t ite1;
      tSeq0 = GENV_STORE.createTempSeq(seq0);
      tSeq1 = GENV_STORE.createTempSeq(seq1);

      if (!c0Done)
      {
        ite0 = new PlanIteratorWrapper(theChild0, planState);
        tSeq0->append(ite0);
      }

      if (!c1Done)
      {
        ite1 = new PlanIteratorWrapper(theChild1, planState);
        tSeq1->append(ite1);
      }

      ite0 = tSeq0->getIterator();
      ite1 = tSeq1->getIterator();
      ite0->open();
      ite1->open();

      while (!found && ite0->next(item0))
      {
        while (!found && ite1->next(item1))
        {
          store::Item_t tmp = item0;

          if (generalComparison(loc,
                                tmp,
                                item1,
                                theCompType,
                                theTypeManager,
                                theTimezone,
                                theCollation))
          {
            found = true;
            break;
          }
        }

        ite1->reset();
      }
    }

    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, found), state);
  }
  else
  {
    // value comparison
    if (consumeNext(item0, theChild0.getp(), planState) &&
        consumeNext(item1, theChild1.getp(), planState))
    {
      STACK_PUSH(GENV_ITEMFACTORY->
                 createBoolean(result,
                               CompareIterator::valueComparison(loc,
                                                                item0,
                                                                item1,
                                                                theCompType,
                                                                theTypeManager,
                                                                theTimezone,
                                                                theCollation)),
                 state);

      assert(!consumeNext(item0, theChild0.getp(), planState) &&
             !consumeNext(item1, theChild1.getp(), planState));
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool CompareIterator::valueComparison(
    const QueryLoc& loc,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    CompareConsts::CompareType aCompType,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  try
  {
    switch(aCompType)
    {
    case CompareConsts::VALUE_EQUAL:
    {
      return valueEqual(loc, aItem0, aItem1, typemgr, timezone, aCollation);
    }
    case CompareConsts::VALUE_NOT_EQUAL:
    {
      return ! valueEqual(loc, aItem0, aItem1, typemgr, timezone, aCollation);
    }
    case CompareConsts::VALUE_GREATER:
    {
      return valueCompare(loc, aItem0, aItem1, typemgr, timezone, aCollation) > 0;
    }
    case CompareConsts::VALUE_GREATER_EQUAL:
    {
      return valueCompare(loc, aItem0, aItem1, typemgr, timezone, aCollation) >= 0;
    }
    case CompareConsts::VALUE_LESS:
    {
      return valueCompare(loc, aItem0, aItem1, typemgr, timezone, aCollation) < 0;
    }
    case CompareConsts::VALUE_LESS_EQUAL:
    {
      return valueCompare(loc, aItem0, aItem1, typemgr, timezone, aCollation) <= 0;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }
  catch (const ZorbaException& e)
  {
    if (e.diagnostic() == zerr::ZSTR0041_NAN_COMPARISON)
      return false;

    throw;
  }
}


/*******************************************************************************
  Compares two items for equality according to the rules of value comparison

  @param  item0
  @param  item1
  @param  tm The type manager to use to extract the type of the 2 items and
          perform any necessary type checks and castings/promotions
  @param  timezone Optional timezone parameter used when comparing datetimes
  @param  aCollation optional collation parameter (passed as pointer to make
          it possible to be set to 0)
  @return True if the two item are equal; false otherwise.
  @throw  appropriate exception if any necesary casting/promotion fails.
  @throw  XPTY0004 if the two items are not equality comparable according to
          the table in http://www.w3.org/TR/xquery/#mapping. 
********************************************************************************/
bool CompareIterator::valueEqual(
    const QueryLoc& loc,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  valueCasting(loc, typemgr, aItem0, aItem1, castItem0, castItem1);
  return equal(loc, castItem0, castItem1, typemgr, timezone, aCollation);
}


/*******************************************************************************

********************************************************************************/
long CompareIterator::valueCompare(
    const QueryLoc& loc,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  valueCasting(loc, typemgr, aItem0, aItem1, castItem0, castItem1);
  return compare(loc, castItem0, castItem1, typemgr, timezone, aCollation);
}


/*******************************************************************************

********************************************************************************/
void CompareIterator::valueCasting(
    const QueryLoc& loc,
    const TypeManager* tm,
    store::Item_t& item0,
    store::Item_t& item1,
    store::Item_t& castItem0,
    store::Item_t& castItem1)
{
  store::SchemaTypeCode type0 = item0->getTypeCode();
  store::SchemaTypeCode type1 = item1->getTypeCode();

  // all untyped Atomics to String
  if (TypeOps::is_subtype(type0, store::XS_UNTYPED_ATOMIC))
  {
    GenericCast::castToAtomic(castItem0, item0, store::XS_STRING, tm, NULL, loc);

    if  (TypeOps::is_subtype(type1, store::XS_UNTYPED_ATOMIC))
    {
      GenericCast::castToAtomic(castItem1, item1, store::XS_STRING, tm, NULL, loc);
    }
    else
    {
      if (!GenericCast::promote(castItem1, item1, store::XS_STRING, tm, loc))
        castItem1.transfer(item1);
    }
  }
  else if (TypeOps::is_subtype(type1, store::XS_UNTYPED_ATOMIC))
  {
    if (!GenericCast::promote(castItem0, item0, store::XS_STRING, tm, loc))
      castItem0.transfer(item0);

    GenericCast::castToAtomic(castItem1, item1, store::XS_STRING, tm, NULL, loc);
  }
  else
  {
    if (!GenericCast::promote(castItem0, item0, type1, tm, loc))
      castItem0.transfer(item0);

    if (!GenericCast::promote(castItem1, item1, type0, tm, loc))
      castItem1.transfer(item1);
  }
}


/*******************************************************************************
  Compares two items for their relative order with respect to a general 
  comparison operator.

  @param  item0
  @param  item1
  $param  aCompType
  @param  tm The type manager to use to extract the type of the 2 items and
          perform any necessary type checks and castings/promotions
  @param  timezone Optional timezone parameter used when comparing datetimes
  @param  aCollation optional collation parameter (passed as pointer to make
          it possible to be set to 0)
  @return True if the ordering between item0 and item1 satisfies the given
          general comparison operator; false otherwise.
  @throw  appropriate exception if any necesary casting/promotion fails.
  @throw  XPTY0004 if the two items are not order comparable.
  @throw  ZSTR0041_NAN_COMPARISON if both the items are of type xs:double or
          xs:float and at leat one of the items is NaN.
********************************************************************************/
bool CompareIterator::generalComparison(
    const QueryLoc& loc,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    CompareConsts::CompareType aCompType,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  try
  {
    switch(aCompType)
    {
    case CompareConsts::GENERAL_EQUAL:
    {
      return generalEqual(loc, aItem0, aItem1, typemgr, timezone, aCollation);
    }
    case CompareConsts::GENERAL_NOT_EQUAL:
    {
      return !generalEqual(loc, aItem0, aItem1, typemgr, timezone, aCollation);
    }
    case CompareConsts::GENERAL_GREATER:
    {
      return generalCompare(loc, aItem0, aItem1, typemgr, timezone, aCollation) > 0;
    }
    case CompareConsts::GENERAL_GREATER_EQUAL:
    {
      return generalCompare(loc, aItem0, aItem1, typemgr, timezone, aCollation) >= 0;
    }
    case CompareConsts::GENERAL_LESS:
    {
      return generalCompare(loc, aItem0, aItem1, typemgr, timezone, aCollation) < 0;
    }
    case CompareConsts::GENERAL_LESS_EQUAL:
    {
      return generalCompare(loc, aItem0, aItem1, typemgr, timezone, aCollation) <= 0;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }
  catch (const ZorbaException& e)
  {
    if (e.diagnostic() == zerr::ZSTR0041_NAN_COMPARISON)
      return false;
    throw;
  }
}


/*******************************************************************************
  Compares two items for equality according to the rules of general comparison

  @param  item0
  @param  item1
  @param  tm The type manager to use to extract the type of the 2 items and
          perform any necessary type checks and castings/promotions
  @param  timezone Optional timezone parameter used when comparing datetimes
  @param  aCollation optional collation parameter (passed as pointer to make
          it possible to be set to 0)
  @return True if the two item are equal; false otherwise.
  @throw  appropriate exception if any necesary casting/promotion fails.
  @throw  XPTY0004 if the two items are not equality comparable.
********************************************************************************/
bool CompareIterator::generalEqual(
    const QueryLoc& loc,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  generalCasting(loc, typemgr, aItem0, aItem1, castItem0, castItem1);
  return equal(loc, castItem0, castItem1, typemgr, timezone, aCollation);
}


/*******************************************************************************
  Compares two items for ordering according to the rules of general comparison

  @param  item0
  @param  item1
  @param  tm The type manager to use to extract the type of the 2 items and
          perform any necessary type checks and castings/promotions
  @param  timezone Optional timezone parameter used when comparing datetimes
  @param  aCollation optional collation parameter (passed as pointer to make
          it possible to be set to 0)
  @return < 0 if item0 is less than item1, 0 if the two items are equal, or
          > 0 if item0 is greater than item1.
  @throw  appropriate exception if any necesary casting/promotion fails.
  @throw  XPTY0004 if the two items are not order comparable.
  @throw  ZSTR0041_NAN_COMPARISON if both the items are of type xs:double or
          xs:float and at leat one of the items is NaN.
********************************************************************************/
long CompareIterator::generalCompare(
    const QueryLoc& loc,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  generalCasting(loc, typemgr, aItem0, aItem1, castItem0, castItem1);
  return compare(loc, castItem0, castItem1, typemgr, timezone, aCollation);
}


/*******************************************************************************

********************************************************************************/
void CompareIterator::generalCasting(
    const QueryLoc& loc,
    const TypeManager* tm,
    store::Item_t& item0,
    store::Item_t& item1,
    store::Item_t& castItem0,
    store::Item_t& castItem1)
{
  store::SchemaTypeCode type0 = item0->getTypeCode();
  store::SchemaTypeCode type1 = item1->getTypeCode();

  if (TypeOps::is_subtype(type0, store::XS_UNTYPED_ATOMIC))
  {
    if (TypeOps::is_numeric(type1))
    {
      GenericCast::castToAtomic(castItem0, item0, store::XS_DOUBLE, tm, NULL, loc);

      GenericCast::promote(castItem1, item1, store::XS_DOUBLE, tm, loc);
    }
    else if (TypeOps::is_subtype(type1, store::XS_UNTYPED_ATOMIC))
    {
      GenericCast::castToAtomic(castItem0, item0, store::XS_STRING, tm, NULL, loc);
      GenericCast::castToAtomic(castItem1, item1, store::XS_STRING, tm, NULL, loc);
    }
    else if (TypeOps::is_subtype(type1, store::XS_STRING))
    {
      GenericCast::castToAtomic(castItem0, item0, store::XS_STRING, tm, NULL, loc);
      castItem1.transfer(item1);
    }
    else
    {
      GenericCast::castToAtomic(castItem0, item0, type1, tm, NULL, loc);
      castItem1.transfer(item1);
    }
  }
  else if (TypeOps::is_subtype(type1, store::XS_UNTYPED_ATOMIC))
  {
    if (TypeOps::is_numeric(type0))
    {
      GenericCast::castToAtomic(castItem1, item1, store::XS_DOUBLE, tm, NULL, loc);
      GenericCast::promote(castItem0, item0, store::XS_DOUBLE, tm, loc);
    }
    else if (TypeOps::is_subtype(type0, store::XS_STRING))
    {
      GenericCast::castToAtomic(castItem1, item1, store::XS_STRING, tm, NULL, loc);
      castItem0.transfer(item0);
    }
    else
    {
      GenericCast::castToAtomic(castItem1, item1, type0, tm, NULL, loc);
      castItem0.transfer(item0);
    }
  }
  else
  {
    if (!GenericCast::promote(castItem0, item0, type1, tm, loc))
      castItem0.transfer(item0);

    if (!GenericCast::promote(castItem1, item1, type0, tm, loc))
      castItem1.transfer(item1);
  }
}


/*******************************************************************************
  Checks if the two passed items contain the same value (without performing any
  castings or promotions on the two items). 

  @param  item0
  @param  item1
  @param  tm The type manager to use to extract the type of the 2 items
  @param  timezone Optional timezone parameter used when comparing datetimes
  @param  aCollation optional collation parameter (passed as pointer to make
          it possible to be set to 0)
  @return True if the two item are equal; false otherwise.
  @throw  XPTY0004 if the two items are not equality comparable according to
          the table in http://www.w3.org/TR/xquery/#mapping. 
********************************************************************************/
bool CompareIterator::equal(
    const QueryLoc& loc,
    const store::Item_t& item0,
    const store::Item_t& item1,
    const TypeManager* tm,
    long timezone,
    XQPCollator* collation)
{
  store::SchemaTypeCode type0 = item0->getTypeCode();
  store::SchemaTypeCode type1 = item1->getTypeCode();

  if (TypeOps::is_subtype(type0, type1))
  {
    return item1->equals(item0, timezone, collation);
  }
  else if (TypeOps::is_subtype(type1, type0))
  {
    return item0->equals(item1, timezone, collation);
  }
  else
  {
    // There are 2 cases when two types are comparable without one being a
    // subtype of the other: (a) they belong to different branches under of
    // the type-inheritance subtree rooted at xs:integer, (b) they belong to
    // different branches under of the type-inheritance subtree rooted at
    // xs::duration (i.e. one is xs:yearMonthDuration and the other is
    // xs:dayTimeDuration).
    // The same case happens when there are two types derived from xs:NOTATION.
    if (TypeOps::is_subtype(type0, store::XS_INTEGER) &&
        TypeOps::is_subtype(type1, store::XS_INTEGER))
    {
      return (item0->getIntegerValue() == item1->getIntegerValue());
    }
    else if (TypeOps::is_subtype(type0, store::XS_DURATION) &&
             TypeOps::is_subtype(type1, store::XS_DURATION))
    {
      return (item0->getDurationValue() == item1->getDurationValue());
    }
    else if (TypeOps::is_subtype(type0, store::XS_NOTATION) &&
             TypeOps::is_subtype(type1, store::XS_NOTATION))
    {
      return item0->equals(item1);
    }
    else
    {
      xqtref_t type0 = tm->create_value_type(item0.getp());
      xqtref_t type1 = tm->create_value_type(item1.getp());

      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadType_23o), *type0, ZED(NoCompareWithType_4), *type1));
    }
  }
}


/*******************************************************************************
  Performs an order-comparison between two given items (without performing any
  castings or promotions on the two items). 

  @param  item0
  @param  item1
  @param  tm The type manager to use to extract the type of the 2 items
  @param  timezone Optional timezone parameter used when comparing datetimes
  @param  aCollation optional collation parameter (passed as pointer to make
          it possible to be set to 0)
  @return < 0 if item0 is less than item1, 0 if the two items are equal, or
          > 0 if item0 is greater than item1.
  @throw  XPTY0004 if the two items are not order comparable according to
          the table in http://www.w3.org/TR/xquery/#mapping. 
  @throw  ZSTR0041_NAN_COMPARISON if both the items are of type xs:double or
          xs:float and at leat one of the items is NaN.
********************************************************************************/
long CompareIterator::compare(
    const QueryLoc& loc,
    const store::Item_t& item0,
    const store::Item_t& item1,
    const TypeManager* tm,
    long timezone,
    XQPCollator* collation)
{
  store::SchemaTypeCode type0 = item0->getTypeCode();
  store::SchemaTypeCode type1 = item1->getTypeCode();

  try
  {
    if (TypeOps::is_subtype(type0, store::XS_DURATION) &&
        TypeOps::is_subtype(type1, store::XS_DURATION))
    {
      if (type0 == type1 && type0 != store::XS_DURATION)
      {
        return item0->compare(item1, timezone, collation);
      }
      else
      {
        xqtref_t type0 = tm->create_value_type(item0.getp());
        xqtref_t type1 = tm->create_value_type(item1.getp());

        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(BadType_23o), *type0, ZED(NoCompareWithType_4), *type1));
      }
    }
    else if (TypeOps::is_subtype(type1, type0))
    {
      return item0->compare(item1, timezone, collation);
    }
    else if (TypeOps::is_subtype(type0, type1))
    {
      return -item1->compare(item0, timezone, collation);
    }
    else
    {
      // There is 1 case when two types are order-comparable without one being a
      // subtype of the other: they belong to different branches under of the
      // type-inheritance subtree rooted at xs:integer.
      if (TypeOps::is_subtype(type0, store::XS_INTEGER) &&
          TypeOps::is_subtype(type1, store::XS_INTEGER))
      {
        return item0->getIntegerValue().compare(item1->getIntegerValue());
      }
      else
      {
        xqtref_t type0 = tm->create_value_type(item0.getp());
        xqtref_t type1 = tm->create_value_type(item1.getp());

        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(BadType_23o), *type0, ZED(NoCompareWithType_4), *type1));
      }
    }
  }
  catch(const ZorbaException& e)
  {
    // For example, two QName items do not have an order relationship.
    if (e.diagnostic() == zerr::ZSTR0040_TYPE_ERROR)
    {
      xqtref_t type0 = tm->create_value_type(item0.getp());
      xqtref_t type1 = tm->create_value_type(item1.getp());

      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadType_23o), *type0, ZED(NoCompareWithType_4), *type1));
    }

    throw;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  TypedValueCompareIterator                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


template <store::SchemaTypeCode ATC>
void TypedValueCompareIterator<ATC>::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator iter =  this->theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd =  this->theChildren.end();
  for ( ; iter != lEnd; ++iter )
  {
    (*iter)->accept(v);
  }

  v.endVisit(*this);
}


template<store::SchemaTypeCode ATC>
void TypedValueCompareIterator<ATC>::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<TypedValueCompareIterator, PlanIteratorState>
  ::openImpl(planState, offset);

  theTimezone = planState.theLocalDynCtx->get_implicit_timezone();
  theCollation = this->theSctx->get_default_collator(this->loc);
}


template<store::SchemaTypeCode ATC>
bool TypedValueCompareIterator<ATC>::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lItem0, lItem1;
  bool bRes;
  bool neq = false;
  long cmp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (CONSUME(lItem0, 0) && CONSUME(lItem1, 1))
  {
    switch (theCompType)
    {
    case CompareConsts::VALUE_NOT_EQUAL:
      neq = true;

    case CompareConsts::VALUE_EQUAL:
    {
      bRes = lItem0->equals(lItem1, theTimezone, theCollation);
      if (neq)
        bRes = ! bRes;

      break;
    }

    default:
    {
      try
      {
        cmp = lItem0->compare(lItem1, theTimezone, theCollation);

        switch (theCompType)
        {
        case CompareConsts::VALUE_LESS:
          bRes = (cmp < 0);
          break;
        case CompareConsts::VALUE_GREATER:
          bRes = (cmp > 0);
          break;
        case CompareConsts::VALUE_LESS_EQUAL:
          bRes = (cmp <= 0);
          break;
        case CompareConsts::VALUE_GREATER_EQUAL:
          bRes = (cmp >= 0);
          break;
        default:
          ZORBA_ASSERT(false);
        } // switch (theCompType)
      }
      catch (const ZorbaException& e)
      {
        if (e.diagnostic() == zerr::ZSTR0041_NAN_COMPARISON)
          bRes = false;
        else
          throw;
      }
    } // default
    } // switch (theCompType)

    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, bRes), state);

    assert(!CONSUME(lItem0, 0) && !CONSUME(lItem1, 1));
  }

  STACK_END(state);
}


template class TypedValueCompareIterator<store::XS_DOUBLE>;
template class TypedValueCompareIterator<store::XS_FLOAT>;
template class TypedValueCompareIterator<store::XS_DECIMAL>;
template class TypedValueCompareIterator<store::XS_INTEGER>;
template class TypedValueCompareIterator<store::XS_STRING>;



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  AtomicValuesEquivalenceIterator                                            //
//                                                                             //
//  http://www.w3.org/TR/xquery-11/#dt-equivalence-two-atomic-values           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

AtomicValuesEquivalenceIterator::AtomicValuesEquivalenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t aChild0,
    PlanIter_t aChild1)
  :
  BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState>(sctx, loc, aChild0, aChild1),
  theTypeManager(NULL),
  theTimezone(0),
  theCollation(NULL)
{
}


BINARY_ACCEPT(AtomicValuesEquivalenceIterator);


void AtomicValuesEquivalenceIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState>::
  openImpl(planState, offset);

  theTypeManager = theSctx->get_typemanager();
  theCollation = theSctx->get_default_collator(loc);
  theTimezone = planState.theLocalDynCtx->get_implicit_timezone();
}


bool AtomicValuesEquivalenceIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lItem0, lItem1, tItem0, tItem1;
  int count0, count1;
  xqtref_t type0, type1;
  bool are_equivalent;

  RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  count0 = 0;
  count1 = 0;

  if (consumeNext(lItem0, theChild0.getp(), planState))
    count0 = 1;

  if (count0 && consumeNext(tItem0, theChild0.getp(), planState))
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS( ZED( NoSeqTestedForAtomicEquiv ) ),
      ERROR_LOC( loc )
    );

  if (consumeNext(lItem1, theChild1.getp(), planState))
    count1 = 1;

  if (count1 && consumeNext(tItem1, theChild1.getp(), planState))
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS( ZED( NoSeqTestedForAtomicEquiv ) ),
      ERROR_LOC( loc )
    );

  if (count0 == 0 && count1 == 0)
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, true), state);
  }
  else if ((count0 == 0 && count1 == 1) || (count0 == 1 && count1 == 0))
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, false), state);
  }
  else
  {
    type0 = theTypeManager->create_value_type(lItem0.getp());
    type1 = theTypeManager->create_value_type(lItem1.getp());

    if ((TypeOps::is_subtype(tm, *type0, *rtm.FLOAT_TYPE_ONE) ||
         TypeOps::is_subtype(tm, *type0, *rtm.DOUBLE_TYPE_ONE))
        &&
        (TypeOps::is_subtype(tm, *type1, *rtm.FLOAT_TYPE_ONE) ||
         TypeOps::is_subtype(tm, *type1, *rtm.DOUBLE_TYPE_ONE))
        &&
        lItem0->isNaN() && lItem1->isNaN())
    {
      STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, true), state);
    }
    else
    {
      try
      {
        are_equivalent = CompareIterator::valueEqual(loc,
                                                     lItem0,
                                                     lItem1,
                                                     theTypeManager,
                                                     theTimezone,
                                                     theCollation);
      }
      catch (ZorbaException const& e)
      {
        if (e.diagnostic() == err::XPTY0004)
          are_equivalent = false;
        else
          throw;
      }

      STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, are_equivalent),
                 state);
    }
  }

  STACK_END(state);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
