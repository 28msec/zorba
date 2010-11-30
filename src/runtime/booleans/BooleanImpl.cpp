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

SERIALIZABLE_CLASS_VERSIONS(LogicIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LogicIterator)

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
//  LogicIterator                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


LogicIterator::LogicIterator (
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t theChild0,
    PlanIter_t theChild1,
    LogicType aLogicType)
  :
  BinaryBaseIterator<LogicIterator, PlanIteratorState>(sctx, loc, theChild0, theChild1),
  theLogicType(aLogicType)
{
}


bool
LogicIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool bRes = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  switch(theLogicType) 
  {
  case AND:
    bRes = FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild0)
        && FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild1);
    break;

  case OR:
    bRes = FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild0)
        || FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild1);
    break;
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, bRes), state);
  STACK_END (state);
}


BINARY_ACCEPT(LogicIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  CompareIterator                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


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


void CompareIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  BinaryBaseIterator<CompareIterator, PlanIteratorState>::openImpl(planState, offset);

  theTypeManager = theSctx->get_typemanager();
  theCollation = theSctx->get_default_collator(loc);
  theTimezone = planState.theDynamicContext->get_implicit_timezone();
}


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
  long compValue = -2;

  switch(aCompType)
  {
  case CompareConsts::VALUE_EQUAL:
  {
    compValue = valueEqual(aItem0, aItem1, typemgr, timezone, aCollation);

    if (compValue >= 0)
      return compValue != 0;

    break;
  }
  case CompareConsts::VALUE_NOT_EQUAL:
  {
    compValue = valueEqual(aItem0, aItem1, typemgr, timezone, aCollation);

    if (compValue >= 0)
      return (compValue > 0 ? false : true);

    break;
  }
  case CompareConsts::VALUE_GREATER:
  {
    compValue = valueCompare(aItem0, aItem1, typemgr, timezone, aCollation);
    if ( compValue > -2 )
      return compValue == 1;

    break;
  }
  case CompareConsts::VALUE_GREATER_EQUAL:
  {
    compValue = valueCompare(aItem0, aItem1, typemgr, timezone, aCollation);
    if ( compValue > -2 )
      return (compValue == 0 || compValue == 1);

    break;
  }
  case CompareConsts::VALUE_LESS:
  {
    compValue = valueCompare(aItem0, aItem1, typemgr, timezone, aCollation);
    if ( compValue > -2 )
      return compValue == -1;

    break;
  }
  case CompareConsts::VALUE_LESS_EQUAL:
  {
    compValue = valueCompare(aItem0, aItem1, typemgr, timezone, aCollation);

    if ( compValue > -2 )
      return (compValue == -1 || compValue == 0);

    break;
  }
  default:
  {    ZORBA_ASSERT(false);
  }
  }

  ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                       "Dynamic type of a value does not match a required type.");
}


long CompareIterator::valueEqual(
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  valueCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
  return equal(castItem0, castItem1, typemgr, timezone, aCollation);
}


long CompareIterator::valueCompare(
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  valueCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
  return compare(castItem0, castItem1, typemgr, timezone, aCollation);
}


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
  long compValue = -2;

  switch(aCompType)
  {
  case CompareConsts::GENERAL_EQUAL:
  {
    compValue = generalEqual(aItem0, aItem1, typemgr, timezone, aCollation);

    if (compValue >= 0)
      return compValue != 0;

    break;
  }
  case CompareConsts::GENERAL_NOT_EQUAL:
  {
    compValue = generalEqual(aItem0, aItem1, typemgr, timezone, aCollation);

    if (compValue >= 0)
      return (compValue > 0 ? false : true);

    break;
  }
  case CompareConsts::GENERAL_GREATER:
  {
    compValue = generalCompare(aItem0, aItem1, typemgr, timezone, aCollation);

    if ( compValue != -2 )
      return compValue == 1;

    break;
  }
  case CompareConsts::GENERAL_GREATER_EQUAL:
  {
    compValue = generalCompare(aItem0, aItem1, typemgr, timezone, aCollation);

    if ( compValue != -2 )
      return (compValue == 0 || compValue == 1);

    break;
  }
  case CompareConsts::GENERAL_LESS:
  {
    compValue = generalCompare(aItem0, aItem1, typemgr, timezone, aCollation);

    if ( compValue != -2 )
      return compValue == -1;

    break;
  }
  case CompareConsts::GENERAL_LESS_EQUAL:
  {
    compValue = generalCompare(aItem0, aItem1, typemgr, timezone, aCollation);

    if ( compValue != -2 )
      return compValue == 0 || compValue == -1;

    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }

  ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                       "Dynamic type of a value does not match a required type.");
}


long CompareIterator::generalEqual(
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator*   aCollation)
{
  store::Item_t castItem0, castItem1;
  generalCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
  return equal(castItem0, castItem1, typemgr, timezone, aCollation);
}


long CompareIterator::generalCompare(
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    const TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  generalCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
  return compare(castItem0, castItem1, typemgr, timezone, aCollation);
}


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

********************************************************************************/
long CompareIterator::equal(
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
    if (TypeOps::is_subtype(tm, *type0, *type1))
    {
      return (aItem1->equals(aItem0, timezone, aCollation) ? 1 : 0);
    }
    else if (TypeOps::is_subtype(tm, *type1, *type0))
    {
      return (aItem0->equals(aItem1, timezone, aCollation) ? 1 : 0);
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
      //
      if (TypeOps::is_subtype(tm, *type0, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE) &&
          TypeOps::is_subtype(tm, *type1, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE))
      {
        return (aItem0->getIntegerValue() == aItem1->getIntegerValue() ? 1 : 0);
      }
      else if (TypeOps::is_subtype(tm, *type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE) &&
               TypeOps::is_subtype(tm, *type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
      {
        return (aItem0->getDurationValue() == aItem1->getDurationValue() ? 1 : 0);
      }
      else if (TypeOps::is_subtype(tm, *type0, *GENV_TYPESYSTEM.NOTATION_TYPE_ONE) &&
               TypeOps::is_subtype(tm, *type1, *GENV_TYPESYSTEM.NOTATION_TYPE_ONE))
      {
        return aItem0->equals(aItem1);
      }
      else
      {
        return -2;
      }
    }
  }
  catch(error::ZorbaError& e)
  {
    if (e.theErrorCode == STR0040_TYPE_ERROR)
      return -2;
    else
      throw e;
  }
}


/*******************************************************************************

********************************************************************************/
long CompareIterator::compare(
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
        return aItem0->compare(aItem1, timezone, aCollation);
      else
        return -2;
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
        return -2;
      }
    }
  }
  catch(error::ZorbaError& e)
  {
    if (e.theErrorCode == STR0040_TYPE_ERROR)
      return -2;
    else
      throw e;
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
  bool bRes, neq = false, nonempty = false;
  int cmp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (CONSUME (lItem0, 0) && CONSUME (lItem1, 1))
  {
    switch (theCompType)
    {
    case CompareConsts::VALUE_NOT_EQUAL:
      neq = true;
    case CompareConsts::VALUE_EQUAL:
      nonempty = true;
      bRes = lItem0->equals (lItem1, theTimezone, theCollation);
      if (neq) bRes = ! bRes;
      break;

    default:
      {
        cmp = lItem0->compare (lItem1, theTimezone, theCollation);

        if (cmp > -2)
          nonempty = true;

        switch (theCompType)
        {
        case CompareConsts::VALUE_LESS:
          bRes = (cmp == -1);
          break;
        case CompareConsts::VALUE_GREATER:
          bRes = (cmp == 1);
          break;
        case CompareConsts::VALUE_LESS_EQUAL:
          bRes = (cmp == -1 || cmp == 0);
          break;
        case CompareConsts::VALUE_GREATER_EQUAL:
          bRes = (cmp == 0 || cmp == 1);
          break;
        default:
          ZORBA_ASSERT (false);
        } // switch (theCompType)
      } // default
    } // switch (theCompType)

    if (nonempty)
      STACK_PUSH (GENV_ITEMFACTORY->createBoolean (result, bRes), state);

    if (CONSUME (lItem0, 0) || CONSUME (lItem1, 1))
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, this->loc,
                           "Value comparisons must not be made with sequences longer than one item.");
    }
  }

  STACK_END (state);
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
      are_equivalent = (1 == CompareIterator::valueEqual(lItem0, lItem1, theTypeManager, theTimezone, theCollation));
      STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, are_equivalent), state);
    }
  }

  STACK_END (state);
}


} // namespace zorba
