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

#include "context/dynamic_context.h"

#include "runtime/visitors/planitervisitor.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/gflwor/common.h"
#include "runtime/api/runtimecb.h"

namespace zorba
{

namespace flwor
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderSpec                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

OrderSpec::OrderSpec (
    PlanIter_t aOrderByIter,
    bool aEmpty_least,
    bool aDescending )
  :
  theInput( aOrderByIter ),
  theEmptyLeast( aEmpty_least ),
  theDescending( aDescending ),
  theCollator(0)
{
}


OrderSpec::OrderSpec (
    PlanIter_t aOrderByIter,
    bool aEmpty_least,
    bool aDescending,
    const std::string& aCollation)
  :
  theInput( aOrderByIter ),
  theEmptyLeast( aEmpty_least ),
  theDescending( aDescending ),
  theCollation(aCollation),
  theCollator(0)
{
}


void OrderSpec::accept(PlanIterVisitor& v) const
{
  v.beginVisitFlworOrderBy(*theInput);
  v.endVisitFlworOrderBy(*theInput);
}


uint32_t OrderSpec::getStateSizeOfSubtree() const 
{
  return theInput->getStateSizeOfSubtree();
}


void OrderSpec::open(PlanState& aPlanState, uint32_t& offset) const 
{
  theInput->open(aPlanState, offset);
}


void OrderSpec::reset(PlanState& aPlanState) const 
{
  theInput->reset ( aPlanState );
}


void OrderSpec::close(PlanState& aPlanState) const 
{
  theInput->close(aPlanState);
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderTupleCmp                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


OrderTupleCmp::OrderTupleCmp(RuntimeCB* rcb, std::vector<OrderSpec>* aOrderSpecs) 
  :
  theOrderSpecs ( aOrderSpecs ) 
{
  theTypeManager = rcb->theStaticContext->get_typemanager();
  theTimezone = rcb->theDynamicContext->get_implicit_timezone();
}


/*******************************************************************************
  The key comparison function, a Strict Weak Ordering whose argument type is
  key_type. It returns true if its first argument is less than its second argument,
  and false otherwise. This is also defined as multimap::key_compare.
********************************************************************************/
bool OrderTupleCmp::operator() (
    const std::vector<store::Item_t>& s1,
    const std::vector<store::Item_t>& s2 ) const
{
  ZORBA_ASSERT ( s1.size() == s2.size() );
  ZORBA_ASSERT ( s1.size() == theOrderSpecs->size() );

  std::vector<store::Item_t>::const_iterator s1iter = s1.begin();
  std::vector<store::Item_t>::const_iterator s2iter = s2.begin();
  std::vector<OrderSpec>::const_iterator orderSpecIter = theOrderSpecs->begin();

  while ( s1iter != s1.end() )
  {
    long cmp = compare(*s1iter,
                       *s2iter,
                       orderSpecIter->theDescending,
                       orderSpecIter->theEmptyLeast,
                       orderSpecIter->theCollator);
    if ( cmp == 1 )
    {
      return false;
    }
    else if ( cmp == -1 )
    {
      return true;
    }
    ++s1iter;
    ++s2iter;
    ++orderSpecIter;
  }
  return false;
}


/*******************************************************************************
  Does the actual comparision. Returns:
   -1, if s1 < s2
    0, if s1 == s2
    1, if s1 > s2
********************************************************************************/
long OrderTupleCmp::compare(
    const store::Item_t& s1,
    const store::Item_t& s2,
    bool desc,
    bool emptyLeast,
    XQPCollator* collator) const
{
  if (empty_item(s1))
  {
    if (empty_item(s2))
      return descAsc(0, desc);
    else
      return descAsc(emptyLeast ? -1 : 1, desc);
  }
  else if (empty_item (s2))
  {
    return descAsc(emptyLeast ? 1 : -1, desc);
  }
  else
  {
    // danm: both valueCompare (x, NaN) and valueCompare (NaN, x) return 2.
    // That's why empty_item is needed.
    store::Item_t ls1(s1);
    store::Item_t ls2(s2);
    long result = CompareIterator::valueCompare(ls1 , ls2,
                                                theTypeManager,
                                                theTimezone,
                                                collator);
    if (result > 1 || result < -1) 
    {
      ZORBA_ERROR_DESC( XPTY0004, "Non-comparable types found while sorting" );
    }
    return descAsc (result , desc );
  }
}


/*******************************************************************************
  Helper functions to switch the ordering between ascending and descending.
********************************************************************************/
long OrderTupleCmp::descAsc(long result, bool desc) const
{
  ZORBA_ASSERT (result <= 1 && result >= -1);
  return desc ? -result : result;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupingSpec                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

GroupingSpec::GroupingSpec(
    PlanIter_t aInput,
    std::vector<ForVarIter_t> aInnerVars,
    const std::string& aCollation )
  :
  theInput(aInput),
  theInnerVars(aInnerVars),
  theCollation(aCollation)
{
}


void GroupingSpec::accept ( PlanIterVisitor& v ) const
{
  theInput->accept(v);
}


uint32_t GroupingSpec::getStateSizeOfSubtree() const
{
  return theInput->getStateSizeOfSubtree();
}

void GroupingSpec::open ( PlanState& planState, uint32_t& offset )
{
  theInput->open(planState, offset);
}


void GroupingSpec::reset ( PlanState& planState ) const 
{
  theInput->reset ( planState );
}


void GroupingSpec::close ( PlanState& planState )
{
  theInput->close(planState);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupingOuterVar                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

GroupingOuterVar::GroupingOuterVar(
    PlanIter_t aInput, 
    std::vector<LetVarIter_t> aOuterVars)
  : 
  theInput(aInput),
  theOuterVars(aOuterVars)
{
}


void GroupingOuterVar::accept ( PlanIterVisitor& v ) const
{
  theInput->accept(v);
}


uint32_t GroupingOuterVar::getStateSizeOfSubtree() const 
{
  return theInput->getStateSizeOfSubtree();
}


void GroupingOuterVar::open ( PlanState& planState, uint32_t& offset )
{
  theInput->open(planState, offset);
}


void GroupingOuterVar::reset ( PlanState& planState ) const 
{
  theInput->reset ( planState );
}


void GroupingOuterVar::close ( PlanState& planState )
{
  theInput->close(planState);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupTupleCmp                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


GroupTupleCmp::GroupTupleCmp(RuntimeCB* rcb, std::vector<GroupingSpec>* groupingSpecs) 
  :
  theGroupingSpecs(groupingSpecs) 
{
  theTypeManager = rcb->theStaticContext->get_typemanager();
  theTimezone = rcb->theDynamicContext->get_implicit_timezone();
}


uint32_t GroupTupleCmp::hash(GroupTuple* t) const
{
  uint32_t hash = 0;

  long numCols = theGroupingSpecs->size();

  for (long i = 0; i < numCols; i++)
  {
    if (t->theTypedValues[i] != NULL)
    {
      hash += t->theTypedValues[i]->hash(theTimezone,
                                         (*theGroupingSpecs)[i].theCollator);
    }
  }

  return hash;
}


bool GroupTupleCmp::equal(const GroupTuple* t1, const GroupTuple* t2) const
{
  assert(theGroupingSpecs->size() == t1->theTypedValues.size());
  assert(t2->theTypedValues.size() == t1->theTypedValues.size());

  std::vector<store::Item_t>::const_iterator iter1 = t1->theTypedValues.begin();
  std::vector<store::Item_t>::const_iterator iter2 = t2->theTypedValues.begin();
  std::vector<store::Item_t>::const_iterator end = t1->theTypedValues.end();
  long i = 0;

  while(iter1 != end)
  {
    if(*iter1 == NULL)
    {      
      if(*iter2 != NULL)
      {
        return false;
      }
    }
    else if(*iter2 == NULL)
    {
      return false;
    }
    else
    {
      store::Item_t item1 = *iter1;
      store::Item_t item2 = *iter2;
      if (CompareIterator::valueEqual(item1,
                                      item2,
                                      theTypeManager,
                                      theTimezone,
                                      (*theGroupingSpecs)[i].theCollator) != 1)
      {
        return false;                                 
      }
    }
    
    ++i;
    ++iter1;
    ++iter2;
  }
  return true;
}


}
}
