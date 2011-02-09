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
END_SERIALIZABLE_CLASS_VERSIONS(FnBooleanIterator)

SERIALIZABLE_CLASS_VERSIONS(OrIterator)
END_SERIALIZABLE_CLASS_VERSIONS(OrIterator)

SERIALIZABLE_CLASS_VERSIONS(AndIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AndIterator)

SERIALIZABLE_CLASS_VERSIONS(CompareIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CompareIterator)

SERIALIZABLE_TEMPLATE_VERSIONS(TypedValueCompareIterator)
END_SERIALIZABLE_TEMPLATE_VERSIONS(TypedValueCompareIterator)

SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<TypeConstants::XS_DOUBLE>, 1)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<TypeConstants::XS_FLOAT>, 2)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<TypeConstants::XS_DECIMAL>, 3)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<TypeConstants::XS_INTEGER>, 4)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(TypedValueCompareIterator, TypedValueCompareIterator<TypeConstants::XS_STRING>, 5)

SERIALIZABLE_CLASS_VERSIONS(AtomicValuesEquivalenceIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AtomicValuesEquivalenceIterator)


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
  store::Item_t item, temp;
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
    xqtref_t type = tm->create_value_type(item);
    is_sequence = consumeNext(temp, iter, planState);
    if (!is_sequence 
        &&
        (TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)
         || TypeOps::is_subtype(tm, *type, *GENV_TYPESYSTEM.STRING_TYPE_ONE)
         || TypeOps::is_subtype(tm, *type, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)
         || TypeOps::is_subtype(tm, *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
         || TypeOps::is_numeric(tm, *type)))
    {
      // atomic type xs_boolean, xs_string, xs_anyURI, xs_untypedAtomic
      // => effective boolean value is defined in the items
      temp = item->getEBV();
      result = negate ? (negate ^ temp->getBooleanValue()) : temp->getBooleanValue();
    }
    else
    {
      if (is_sequence)
        ZORBA_ERROR_LOC_DESC(FORG0006, loc, "Wrong arguments in fn:boolean function. "
          + zstring("Effective boolean value is not defined for a sequence of two or more items that starts with a ")
          + type->toString()
          + ".");
      else
        ZORBA_ERROR_LOC_DESC(FORG0006, loc, "Wrong arguments in fn:boolean function.");
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
  theTimezone = planState.theDynamicContext->get_implicit_timezone();
}


/*******************************************************************************

********************************************************************************/
bool CompareIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem0, lItem1, tItem0, tItem1;
  bool c0Done = false, c1Done = false, done = false, found = false;
  std::vector<store::Item_t> seq0;
  std::vector<store::Item_t> seq1;
  store::TempSeq_t tSeq0, tSeq1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theIsGeneralComparison)
  {
    if (consumeNext(lItem0, theChild0.getp(), planState))
    {
      if (consumeNext(tItem0, theChild0.getp(), planState))
      {
        seq0.push_back(lItem0);
        seq0.push_back(tItem0);
      }
      else
      {
        c0Done = true;
        if (consumeNext(lItem1, theChild1.getp(), planState))
        {
          if (consumeNext(tItem1, theChild1.getp(), planState))
          {
            seq0.push_back(lItem0);
            seq1.push_back(lItem1);
            seq1.push_back(tItem1);
          }
          else
          {
            c1Done = true;
            found = CompareIterator::generalComparison(loc,
                                                       lItem0,
                                                       lItem1,
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
      store::Iterator_t lIter0;
      store::Iterator_t lIter1;
      tSeq0 = GENV_STORE.createTempSeq(seq0);
      tSeq1 = GENV_STORE.createTempSeq(seq1);

      if (!c0Done)
      {
        lIter0 = new PlanIteratorWrapper(theChild0, planState);
        tSeq0->append(lIter0, false);
      }

      if (!c1Done)
      {
        lIter1 = new PlanIteratorWrapper(theChild1, planState);
        tSeq1->append(lIter1, false);
      }

      ulong i0 = 1;
      while(!found && tSeq0->containsItem(i0))
      {
        ulong i1 = 1;
        while(!found && tSeq1->containsItem(i1))
        {
          store::Item_t item0;
          store::Item_t item1;
          tSeq0->getItem(i0, item0);
          tSeq1->getItem(i1, item1);
          if (CompareIterator::generalComparison(loc,
                                                 item0,
                                                 item1,
                                                 theCompType,
                                                 theTypeManager,
                                                 theTimezone,
                                                 theCollation))
          {
            found = true;
          }
          ++i1;
        }
        ++i0;
      }
    }

    STACK_PUSH ( GENV_ITEMFACTORY->createBoolean ( result, found ), state );

  }
  else
  {
    // value comparison
    if (consumeNext(lItem0, theChild0.getp(), planState) &&
        consumeNext(lItem1, theChild1.getp(), planState))
    {
      STACK_PUSH(GENV_ITEMFACTORY->
                 createBoolean(result,
                               CompareIterator::valueComparison(loc,
                                                                lItem0,
                                                                lItem1,
                                                                theCompType,
                                                                theTypeManager,
                                                                theTimezone,
                                                                theCollation)),
                 state);

      if (consumeNext(lItem0, theChild0.getp(), planState) ||
          consumeNext(lItem1, theChild1.getp(), planState))
      {
        ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                             "Value comparisons must not be made with sequences longer than one item.");
      }
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
  catch (error::ZorbaError& e)
  {
    if (e.theErrorCode == STR0041_NAN_COMPARISON)
      return false;

    throw e;
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
  valueCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
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
  valueCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
  return compare(loc, castItem0, castItem1, typemgr, timezone, aCollation);
}


/*******************************************************************************

********************************************************************************/
void CompareIterator::valueCasting(
    const TypeManager* tm,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    store::Item_t& castItem0,
    store::Item_t& castItem1)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t type0 = tm->create_value_type(aItem0);
  xqtref_t type1 = tm->create_value_type(aItem1);

  // all untyped Atomics to String
  if (TypeOps::is_subtype(tm, *type0, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
  {
    GenericCast::castToAtomic(castItem0, aItem0, &*rtm.STRING_TYPE_ONE, tm);

    if  (TypeOps::is_subtype(tm, *type1, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(castItem1, aItem1, &*rtm.STRING_TYPE_ONE, tm);
    }
    else
    {
      if (!GenericCast::promote(castItem1, aItem1, &*rtm.STRING_TYPE_ONE, tm))
        castItem1.transfer(aItem1);
    }
  }
  else if (TypeOps::is_subtype(tm, *type1, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (!GenericCast::promote(const_cast<store::Item_t&>(castItem0),
                              aItem0,
                              &*rtm.STRING_TYPE_ONE,
                              tm))
      castItem0.transfer(aItem0);

    GenericCast::castToAtomic(castItem1, aItem1, &*rtm.STRING_TYPE_ONE, tm);
  }
  else
  {
    if (!GenericCast::promote(castItem0, aItem0, &*type1, tm))
      castItem0.transfer(aItem0);

    if (!GenericCast::promote(castItem1, aItem1, &*type0, tm))
      castItem1.transfer(aItem1);
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
  @throw  STR0041_NAN_COMPARISON if both the items are of type xs:double or
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
  catch (error::ZorbaError& e)
  {
    if (e.theErrorCode == STR0041_NAN_COMPARISON)
      return false;

    throw e;
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
  generalCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
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
  @throw  STR0041_NAN_COMPARISON if both the items are of type xs:double or
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
  generalCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
  return compare(loc, castItem0, castItem1, typemgr, timezone, aCollation);
}


/*******************************************************************************

********************************************************************************/
void CompareIterator::generalCasting(
    const TypeManager* tm,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    store::Item_t& castItem0,
    store::Item_t& castItem1)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t type0 = tm->create_value_type(aItem0);
  xqtref_t type1 = tm->create_value_type(aItem1);

  if (TypeOps::is_subtype(tm, *type0, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (TypeOps::is_numeric(tm, *type1))
    {
      GenericCast::castToAtomic(castItem0, aItem0, &*rtm.DOUBLE_TYPE_ONE, tm);

      GenericCast::promote(castItem1, aItem1, &*rtm.DOUBLE_TYPE_ONE, tm);
    }
    else if (TypeOps::is_subtype(tm, *type1, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(castItem0, aItem0, &*rtm.STRING_TYPE_ONE, tm);
      GenericCast::castToAtomic(castItem1, aItem1, &*rtm.STRING_TYPE_ONE, tm);
    }
    else if (TypeOps::is_subtype(tm, *type1, *rtm.STRING_TYPE_ONE))
    {
      GenericCast::castToAtomic(castItem0, aItem0, &*rtm.STRING_TYPE_ONE, tm);
      castItem1.transfer(aItem1);
    }
    else
    {
      GenericCast::castToAtomic(castItem0, aItem0, &*type1, tm);
      castItem1.transfer(aItem1);
    }
  }
  else if (TypeOps::is_subtype(tm, *type1, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (TypeOps::is_numeric(tm, *type0))
    {
      GenericCast::castToAtomic(castItem1, aItem1, &*rtm.DOUBLE_TYPE_ONE, tm);
      GenericCast::promote(castItem0, aItem0, &*rtm.DOUBLE_TYPE_ONE, tm);
    }
    else if (TypeOps::is_subtype(tm, *type0, *rtm.STRING_TYPE_ONE))
    {
      GenericCast::castToAtomic(castItem1, aItem1, &*rtm.STRING_TYPE_ONE, tm);
      castItem0.transfer(aItem0);
    }
    else
    {
      GenericCast::castToAtomic(castItem1, aItem1, &*type0, tm);
      castItem0.transfer(aItem0);
    }
  }
  else
  {
    if (!GenericCast::promote(castItem0, aItem0, &*type1, tm))
      castItem0.transfer(aItem0);

    if (!GenericCast::promote(castItem1, aItem1, &*type0, tm))
      castItem1.transfer(aItem1);
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
    const store::Item_t& aItem0,
    const store::Item_t& aItem1,
    const TypeManager* tm,
    long timezone,
    XQPCollator* aCollation)
{
  xqtref_t type0 = tm->create_value_type(aItem0.getp());
  xqtref_t type1 = tm->create_value_type(aItem1.getp());

  if (TypeOps::is_subtype(tm, *type0, *type1))
  {
    return aItem1->equals(aItem0, timezone, aCollation);
  }
  else if (TypeOps::is_subtype(tm, *type1, *type0))
  {
    return aItem0->equals(aItem1, timezone, aCollation);
  }
  else
  {
    // There are 2 cases when two types are comparable without one being a
    // subtype of the other: (a) they belong to different branches under of
    // the type-inheritance subtree rooted at xs:Integer, (b) they belong to
    // different branches under of the type-inheritance subtree rooted at
    // xs::duration (i.e. one is xs:yearMonthDuration and the other is
    // xs:dayTimeDuration).
    // The same case happens when there are two types derived from xs:NOTATION.
    if (TypeOps::is_subtype(tm, *type0, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE) &&
        TypeOps::is_subtype(tm, *type1, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE))
    {
      return (aItem0->getIntegerValue() == aItem1->getIntegerValue());
    }
    else if (TypeOps::is_subtype(tm, *type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE) &&
             TypeOps::is_subtype(tm, *type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
    {
      return (aItem0->getDurationValue() == aItem1->getDurationValue());
    }
    else if (TypeOps::is_subtype(tm, *type0, *GENV_TYPESYSTEM.NOTATION_TYPE_ONE) &&
             TypeOps::is_subtype(tm, *type1, *GENV_TYPESYSTEM.NOTATION_TYPE_ONE))
    {
      return aItem0->equals(aItem1);
    }
    else
    {
      ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, loc,
                               "Cannot compare for equality an item of type "
                               << type0->toString() << " with an item of type "
                               << type1->toString());
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
  @throw  STR0041_NAN_COMPARISON if both the items are of type xs:double or
          xs:float and at leat one of the items is NaN.
********************************************************************************/
long CompareIterator::compare(
    const QueryLoc& loc,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1,
    const TypeManager* tm,
    long timezone,
    XQPCollator* aCollation)
{
  xqtref_t type0 = tm->create_value_type(aItem0.getp());
  xqtref_t type1 = tm->create_value_type(aItem1.getp());

  try
  {
    if (TypeOps::is_subtype(tm, *type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE) &&
        TypeOps::is_subtype(tm, *type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
    {
      if (TypeOps::is_equal(tm, *type0, *type1) &&
          !TypeOps::is_equal(tm, *type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
      {
        return aItem0->compare(aItem1, timezone, aCollation);
      }
      else
      {
        ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, loc,
                                 "Cannot compare an item of type "
                                 << type0->toString() << " with an item of type "
                                 << type1->toString());
      }
    }
    else if (TypeOps::is_subtype(tm, *type1, *type0))
    {
      return aItem0->compare(aItem1, timezone, aCollation);
    }
    else if (TypeOps::is_subtype(tm, *type0, *type1))
    {
      return -aItem1->compare(aItem0, timezone, aCollation);
    }
    else
    {
      // There is 1 case when two types are order-comparable without one being a
      // subtype of the other: they belong to different branches under of the
      // type-inheritance subtree rooted at xs:Integer.
      if (TypeOps::is_subtype(tm, *type0, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE) &&
          TypeOps::is_subtype(tm, *type1, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE))
      {
        return aItem0->getIntegerValue().compare(aItem1->getIntegerValue());
      }
      else
      {
        ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, loc,
                                 "Cannot compare an item of type "
                                 << type0->toString() << " with an item of type "
                                 << type1->toString());
      }
    }
  }
  catch(error::ZorbaError& e)
  {
    // For example, two QName items do not have an order relationship.
    if (e.theErrorCode == STR0040_TYPE_ERROR)
    {
      ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, loc,
                               "Cannot compare an item of type "
                               << type0->toString() << " with an item of type "
                               << type1->toString());
    }
    else
    {
      throw e;
    }
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  TypedValueCompareIterator                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


template <TypeConstants::atomic_type_code_t ATC>
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


template<TypeConstants::atomic_type_code_t ATC>
void TypedValueCompareIterator<ATC>::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<TypedValueCompareIterator, PlanIteratorState>
  ::openImpl(planState, offset);

  theTimezone = planState.theDynamicContext->get_implicit_timezone();
  theCollation = this->theSctx->get_default_collator(this->loc);
}


template<TypeConstants::atomic_type_code_t ATC>
bool TypedValueCompareIterator<ATC>::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem0, lItem1;
  bool bRes;
  bool neq = false;
  bool nonempty = false;
  long cmp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (CONSUME(lItem0, 0) && CONSUME(lItem1, 1))
  {
    nonempty = true;

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
    } // default
    } // switch (theCompType)

    if (nonempty)
      STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, bRes), state);

    if (CONSUME(lItem0, 0) || CONSUME(lItem1, 1))
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, this->loc,
                           "Value comparisons must not be made with sequences longer than one item.");
    }
  }

  STACK_END(state);
}


template class TypedValueCompareIterator<TypeConstants::XS_DOUBLE>;
template class TypedValueCompareIterator<TypeConstants::XS_FLOAT>;
template class TypedValueCompareIterator<TypeConstants::XS_DECIMAL>;
template class TypedValueCompareIterator<TypeConstants::XS_INTEGER>;
template class TypedValueCompareIterator<TypeConstants::XS_STRING>;



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
  BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState> ( sctx, loc, aChild0, aChild1 ),
  theTypeManager(NULL),
  theTimezone(0),
  theCollation(NULL)
{
}


BINARY_ACCEPT(AtomicValuesEquivalenceIterator);


void AtomicValuesEquivalenceIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState>::openImpl(planState, offset);

  theTypeManager = theSctx->get_typemanager();
  theCollation = theSctx->get_default_collator(loc);
  theTimezone = planState.theDynamicContext->get_implicit_timezone();
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
    ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "Cannot test atomic values equivalence for sequences longer than one item.");

  if (consumeNext(lItem1, theChild1.getp(), planState))
    count1 = 1;

  if (count1 && consumeNext(tItem1, theChild1.getp(), planState))
    ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "Cannot test atomic values equivalence for sequences longer than one item.");

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
      catch (error::ZorbaError& e)
      {
        if (e.theErrorCode == XPTY0004)
          are_equivalent = false;
        else
          throw e;
      }

      STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, are_equivalent),
                 state);
    }
  }

  STACK_END(state);
}


} // namespace zorba
