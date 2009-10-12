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

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/gflwor/common.h"
#include "runtime/api/runtimecb.h"

namespace zorba
{

namespace flwor
{

SERIALIZABLE_CLASS_VERSIONS(GroupingSpec)
END_SERIALIZABLE_CLASS_VERSIONS(GroupingSpec)

SERIALIZABLE_CLASS_VERSIONS(GroupingOuterVar)
END_SERIALIZABLE_CLASS_VERSIONS(GroupingOuterVar)


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupingSpec                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

GroupingSpec::GroupingSpec(
    PlanIter_t inputVar,
    const std::vector<PlanIter_t>& outputVarRefs,
    const std::string& collation)
  :
  theInput(inputVar),
  theCollation(collation),
  theCollator(NULL)
{
  castIterVector<ForVarIterator>(theInnerVars, outputVarRefs);
}


void GroupingSpec::accept(PlanIterVisitor& v) const
{
  v.beginVisitGroupBySpec();

  theInput->accept(v);

  v.beginVisitGroupVariable(theInnerVars);
  v.endVisitGroupVariable();

  v.endVisitGroupBySpec();
}


uint32_t GroupingSpec::getStateSizeOfSubtree() const
{
  return theInput->getStateSizeOfSubtree();
}

void GroupingSpec::open(PlanState& planState, uint32_t& offset)
{
  theInput->open(planState, offset);
}


void GroupingSpec::reset(PlanState& planState) const 
{
  theInput->reset ( planState );
}


void GroupingSpec::close(PlanState& planState)
{
  theInput->close(planState);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupingOuterVar                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

GroupingOuterVar::GroupingOuterVar(
    PlanIter_t inputVar, 
    const std::vector<PlanIter_t>& outputVarRefs)
  : 
  theInput(inputVar)
{
  castIterVector<LetVarIterator>(theOuterVars, outputVarRefs);
}


void GroupingOuterVar::accept(PlanIterVisitor& v) const
{
  v.beginVisitGroupByOuter();

  theInput->accept(v);

  v.beginVisitNonGroupVariable(theOuterVars);
  v.endVisitNonGroupVariable();

  v.endVisitGroupByOuter();
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


GroupTupleCmp::GroupTupleCmp(
    RuntimeCB* rcb,
    const TypeManager* tm,
    std::vector<GroupingSpec>* groupingSpecs) 
  :
  theGroupingSpecs(groupingSpecs),
  theTypeManager(tm)
{
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
