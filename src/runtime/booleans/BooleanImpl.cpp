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
#include "system/globalenv.h"
#include "runtime/booleans/BooleanImpl.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "runtime/api/runtimecb.h"
#include "zorbaerrors/error_manager.h"
#include "runtime/accessors//AccessorsImpl.h"
#include "store/api/temp_seq.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/collation_cache.h"
#include "zorbatypes/collation_manager.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/datetime.h"


namespace zorba
{

/*______________________________________________________________________

 15.1.1 fn:boolean
 fn:boolean($arg as item()*) as xs:boolean

 Computes the effective boolean value of the sequence $arg.
_______________________________________________________________________*/
FnBooleanIterator::FnBooleanIterator(
    const QueryLoc& loc,
    PlanIter_t& aIter,
    bool aNegate)
  :
  UnaryBaseIterator<FnBooleanIterator, PlanIteratorState>(loc, aIter),
  theNegate(aNegate)
{
}

    
FnBooleanIterator::~FnBooleanIterator() 
{
}


bool FnBooleanIterator::effectiveBooleanValue(
    const QueryLoc& loc,
    PlanState& planState,
    const PlanIterator* iter,
    bool negate)
{
  store::Item_t item;
  xqtref_t type;
  store::Item_t temp;
  bool result;

  if (!consumeNext(item, iter, planState))
  {
    // empty sequence => false
    result = negate ^ false;
  }
  else if ( item->isNode() )
  {
    // node => true
    result = negate ^ true;
  }
  else
  {
    type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type(item);
    if (( !consumeNext(temp, iter, planState))
        && (TypeOps::is_equal(*type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)
            || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.STRING_TYPE_ONE )
            || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE )
            || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE )
            || TypeOps::is_numeric ( *type )))
    {
      // atomic type xs_boolean, xs_string, xs_anyURI, xs_untypedAtomic
      // => effective boolean value is defined in the items
      temp = item->getEBV();
      result = negate ? (negate ^ temp->getBooleanValue()) : temp->getBooleanValue();
    }
    else
    {
      ZORBA_ERROR_LOC_DESC( FORG0006, loc,  
                            "Wrong arguments in fn:boolean function.");
    }
  }

  return result;
}


bool FnBooleanIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{ 
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);

  GENV_ITEMFACTORY->createBoolean(result,
                                  FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild, theNegate));
  STACK_PUSH (true, aState);
  STACK_END (aState);
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  LogicIterator                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


LogicIterator::LogicIterator (
    const QueryLoc& loc,
    PlanIter_t theChild0,
    PlanIter_t theChild1,
    LogicType aLogicType)
  :
  BinaryBaseIterator<LogicIterator, PlanIteratorState>(loc, theChild0, theChild1),
  theLogicType(aLogicType) 
{
}
  

LogicIterator::~LogicIterator()
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



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  CompareIterator                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


CompareIterator::CompareIterator(
     const QueryLoc& loc,
     PlanIter_t aChild0,
     PlanIter_t aChild1,
     CompareConsts::CompareType aCompType)
  :
  BinaryBaseIterator<CompareIterator, PlanIteratorState> ( loc, aChild0, aChild1 ), 
  theCompType(aCompType) 
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

  
CompareIterator::~CompareIterator()
{
}
  

void CompareIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  BinaryBaseIterator<CompareIterator, PlanIteratorState>::openImpl(planState, offset);

  theTypeManager = planState.theRuntimeCB->theStaticContext->get_typemanager();
  theTimezone = planState.theRuntimeCB->theDynamicContext->get_implicit_timezone();
  theCollation = planState.theRuntimeCB->theCollationCache->getDefaultCollator();
}


bool CompareIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem0;
  store::Item_t lItem1;
  store::Item_t tItem0;
  store::Item_t tItem1;
  bool c0Done = false;
  bool c1Done = false;
  bool done = false;
  bool found = false;
  std::vector<store::Item_t> seq0;
  std::vector<store::Item_t> seq1;
  store::TempSeq_t tSeq0;
  store::TempSeq_t tSeq1;
    
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  
  // If general comparison ...
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
        lIter0 = new PlanIteratorWrapper ( theChild0, planState );
        tSeq0->append(lIter0, false);
      }
      if (!c1Done) 
      {
        lIter1 = new PlanIteratorWrapper ( theChild1, planState );
        tSeq1->append(lIter1, false);
      }

      int i0 = 1;
      while(!found && tSeq0->containsItem(i0)) 
      {
        int i1 = 1;
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
 
  // else it is a value comparison ...
  else 
  {
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
                             "Value comparisons must not be made with sequences with length greater 1.");
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
    TypeManager* typemgr,
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
      return compValue;

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
  {
    ZORBA_ASSERT(false);
  }
  }

  ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                       "Dynamic type of a value does not match a required type.");
}
  

long CompareIterator::valueEqual(
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    TypeManager* typemgr,
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
    TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  valueCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
  return compare(castItem0, castItem1, typemgr, timezone, aCollation);
}


void CompareIterator::valueCasting(
    TypeManager* typemgr,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    store::Item_t& castItem0,
    store::Item_t& castItem1)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t type0 = typemgr->create_value_type(aItem0);
  xqtref_t type1 = typemgr->create_value_type(aItem1);

  // all untyped Atomics to String
  if (TypeOps::is_subtype(*type0, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
  {
    GenericCast::instance()->castToAtomic(castItem0, aItem0, &*rtm.STRING_TYPE_ONE);

    if  (TypeOps::is_subtype(*type1, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::instance()->castToAtomic(castItem1, aItem1, &*rtm.STRING_TYPE_ONE);
    }
    else
    {
      if (!GenericCast::instance()->promote(castItem1, aItem1, &*rtm.STRING_TYPE_ONE))
        castItem1.transfer(aItem1);
    }  
  }
  else if (TypeOps::is_subtype(*type1, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (!GenericCast::instance()->promote(const_cast<store::Item_t&>(castItem0),
                                          aItem0,
                                          &*rtm.STRING_TYPE_ONE))
      castItem0.transfer(aItem0);

    GenericCast::instance()->castToAtomic(castItem1, aItem1, &*rtm.STRING_TYPE_ONE);
  }
  else
  {
    if (!GenericCast::instance()->promote(castItem0, aItem0, &*type1))
      castItem0.transfer(aItem0);

    if (!GenericCast::instance()->promote(castItem1, aItem1, &*type0))
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
    TypeManager* typemgr,
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
      return compValue;

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
    TypeManager* typemgr,
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
    TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  generalCasting(typemgr, aItem0, aItem1, castItem0, castItem1);
  return compare(castItem0, castItem1, typemgr, timezone, aCollation);
}


void CompareIterator::generalCasting(
    TypeManager* typemgr,
    store::Item_t& aItem0,
    store::Item_t& aItem1,
    store::Item_t& castItem0,
    store::Item_t& castItem1)
{
  xqtref_t type0 = typemgr->create_value_type(aItem0);
  xqtref_t type1 = typemgr->create_value_type(aItem1);

  if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (TypeOps::is_numeric(*type1))
    {
      GenericCast::instance()->castToAtomic(castItem0, aItem0,
                                            &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);

      GenericCast::instance()->promote(castItem1, aItem1,
                                       &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
    }
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::instance()->castToAtomic(castItem0, aItem0,
                                            &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
      GenericCast::instance()->castToAtomic(castItem1, aItem1,
                                            &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
    {
      GenericCast::instance()->castToAtomic(castItem0, aItem0,
                                            &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
      castItem1.transfer(aItem1);
    }
    else
    {
      GenericCast::instance()->castToAtomic(castItem0, aItem0, &*type1);
      castItem1.transfer(aItem1);
    }
  }
  else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (TypeOps::is_numeric(*type0))
    {
      GenericCast::instance()->castToAtomic(castItem1, aItem1,
                                            &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      GenericCast::instance()->promote(castItem0, aItem0,
                                       &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
    {
      GenericCast::instance()->castToAtomic(castItem1, aItem1,
                                            &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
      castItem0.transfer(aItem0);
    }
    else
    {
      GenericCast::instance()->castToAtomic(castItem1, aItem1, &*type0);
      castItem0.transfer(aItem0);
    }
  }
  else
  {
    if (!GenericCast::instance()->promote(castItem0, aItem0, &*type1))
      castItem0.transfer(aItem0);

    if (!GenericCast::instance()->promote(castItem1, aItem1, &*type0))
      castItem1.transfer(aItem1);
  }  
}


/*******************************************************************************

********************************************************************************/
long CompareIterator::equal(
    const store::Item_t& aItem0,
    const store::Item_t& aItem1,
    TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  xqtref_t type0 = typemgr->create_value_type(aItem0.getp());
  xqtref_t type1 = typemgr->create_value_type(aItem1.getp());

  try
  {
    if (TypeOps::is_subtype(*type0, *type1))
    {
      return (aItem1->equals(aItem0, timezone, aCollation) ? 1 : 0);
    } 
    else if (TypeOps::is_subtype(*type1, *type0))
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
      if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE) &&
          TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE)) 
      {
        return (aItem0->getIntegerValue() == aItem1->getIntegerValue() ? 1 : 0);
      }
      else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE) &&
               TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE)) 
      {
        return (aItem0->getDurationValue() == aItem1->getDurationValue() ? 1 : 0);
      }
      else
      {
        return -2;
      }
    }
  }
  catch(error::ZorbaError& e)
  {
    if (e.theErrorCode == XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE)
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
    TypeManager* typemgr,
    long timezone,
    XQPCollator* aCollation)
{
  xqtref_t type0 = typemgr->create_value_type(aItem0.getp());
  xqtref_t type1 = typemgr->create_value_type(aItem1.getp());

  try
  {
    if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE) &&
        TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE)) 
    {
      if (TypeOps::is_equal(*type0, *type1) && 
          !TypeOps::is_equal(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
        return aItem0->compare(aItem1, timezone, aCollation);
      else
        return -2;
    }
    else if (TypeOps::is_subtype(*type1, *type0))
    {
      return aItem0->compare(aItem1, timezone, aCollation);
    } 
    else if (TypeOps::is_subtype(*type0, *type1))
    {
      return -aItem1->compare(aItem0, timezone, aCollation);
    }
    else
    {
      // There is 1 case when two types are order-comparable without one being a
      // subtype of the other: they belong to different branches under of the
      // type-inheritance subtree rooted at xs:Integer.
      if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE) &&
          TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE)) 
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
    if (e.theErrorCode == XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE)
      return -2;
    else
      throw e;
  }
}

  
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IsSameNodeIterator                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


bool
OpIsSameNodeIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{ 
  bool lBool;
  store::Item_t lItem0, lItem1;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
    
  if (consumeNext(lItem0, theChildren[0].getp(), aPlanState)) {
    if (consumeNext(lItem1, theChildren[1].getp(), aPlanState)) {
      if (!lItem0->isNode() || !lItem0->isNode()) {
        ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
      }
      lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == 0); 
      STACK_PUSH ( 
                  GENV_ITEMFACTORY->createBoolean(result, lBool),
                  aState
                   );
    }
  }
  STACK_END (aState);
}


bool
OpNodeBeforeIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{ 
  bool lBool;
  store::Item_t lItem0, lItem1;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

  if (consumeNext(lItem0, theChildren[0].getp(), aPlanState)) {
    if (consumeNext(lItem1, theChildren[1].getp(), aPlanState)) {
      if (!lItem0->isNode() || !lItem0->isNode()) {
        ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
      }
      lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == -1); 
      STACK_PUSH ( 
                  GENV_ITEMFACTORY->createBoolean(result, lBool),
                  aState
                   );
    }
  }
  STACK_END (aState);
}


bool
OpNodeAfterIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{ 
  bool lBool;
  store::Item_t lItem0, lItem1;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

  if (consumeNext(lItem0, theChildren[0].getp(), aPlanState)) {
    if (consumeNext(lItem1, theChildren[1].getp(), aPlanState)) {
      if (!lItem0->isNode() || !lItem0->isNode()) {
        ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
      }
      lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == 1); 
      STACK_PUSH ( 
                  GENV_ITEMFACTORY->createBoolean(result, lBool),
                  aState
                   );
      }
  }
  STACK_END (aState);
}


}
