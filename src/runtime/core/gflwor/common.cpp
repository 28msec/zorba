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

#include "context/dynamic_context.h"

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/gflwor/common.h"

namespace zorba
{

namespace flwor
{

SERIALIZABLE_CLASS_VERSIONS(GroupingSpec)
END_SERIALIZABLE_CLASS_VERSIONS(GroupingSpec)

SERIALIZABLE_CLASS_VERSIONS(NonGroupingSpec)
END_SERIALIZABLE_CLASS_VERSIONS(NonGroupingSpec)


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupingSpec                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

GroupingSpec::GroupingSpec(
    PlanIter_t inputVar,
    const std::vector<PlanIter_t>& varRefs,
    const std::string& collation,
    bool doFastComparison)
  :
  theInput(inputVar),
  theCollation(collation),
  theCollator(NULL),
  theDoFastComparison(doFastComparison)
{
  castIterVector<ForVarIterator>(theVarRefs, varRefs);
}


void GroupingSpec::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theInput;
  ar & theVarRefs;
  ar & theCollation;
  ar & theCollator;
  ar & theDoFastComparison;
}


void GroupingSpec::accept(PlanIterVisitor& v) const
{
  v.beginVisitGroupBySpec();

  theInput->accept(v);

  v.beginVisitGroupVariable(theVarRefs);
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
  theInput->reset(planState);
}


void GroupingSpec::close(PlanState& planState)
{
  theInput->close(planState);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  NonGroupingSpec                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

NonGroupingSpec::NonGroupingSpec(
    PlanIter_t inputVar, 
    const std::vector<PlanIter_t>& varRefs)
  :
  theInput(inputVar)
{
  castIterVector<LetVarIterator>(theVarRefs, varRefs);
}


void NonGroupingSpec::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theInput;
  ar & theVarRefs;
}


void NonGroupingSpec::accept(PlanIterVisitor& v) const
{
  v.beginVisitGroupByOuter();

  theInput->accept(v);

  v.beginVisitNonGroupVariable(theVarRefs);
  v.endVisitNonGroupVariable();

  v.endVisitGroupByOuter();
}


uint32_t NonGroupingSpec::getStateSizeOfSubtree() const 
{
  return theInput->getStateSizeOfSubtree();
}


void NonGroupingSpec::open(PlanState& planState, uint32_t& offset)
{
  theInput->open(planState, offset);
}


void NonGroupingSpec::reset(PlanState& planState) const 
{
  theInput->reset(planState);
}


void NonGroupingSpec::close(PlanState& planState)
{
  theInput->close(planState);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupTupleCmp                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


GroupTupleCmp::GroupTupleCmp(
    const QueryLoc& loc,
    dynamic_context* dctx,
    const TypeManager* tm,
    std::vector<GroupingSpec>* groupingSpecs)
  :
  theLocation(loc),
  theGroupingSpecs(groupingSpecs),
  theTypeManager(tm)
{
  theTimezone = dctx->get_implicit_timezone();
}


uint32_t GroupTupleCmp::hash(GroupTuple* t) const
{
  uint32_t hash = 0;

  std::vector<store::Item_t>::const_iterator ite = t->theTypedValues.begin();
  std::vector<store::Item_t>::const_iterator end = t->theTypedValues.end();
  std::vector<GroupingSpec>::const_iterator ite2 = theGroupingSpecs->begin();

  for (; ite != end; ++ite, ++ite2)
  {
    if (*ite)
    {
      hash += (*ite)->hash(theTimezone, (*ite2).theCollator);
    }
  }

  return hash;
}


bool GroupTupleCmp::equal(const GroupTuple* t1, const GroupTuple* t2) const
{
  assert(theGroupingSpecs->size() == t1->theTypedValues.size());
  assert(t2->theTypedValues.size() == t1->theTypedValues.size());

  std::vector<store::Item_t>::const_iterator end1 = t1->theTypedValues.end();
  std::vector<store::Item_t>::const_iterator iter1 = t1->theTypedValues.begin();
  std::vector<store::Item_t>::const_iterator iter2 = t2->theTypedValues.begin();
  std::vector<GroupingSpec>::const_iterator iter3 = theGroupingSpecs->begin();

  while (iter1 != end1)
  {
    const store::Item* item1 = (*iter1).getp();
    const store::Item* item2 = (*iter2).getp();

    if (item1 == NULL)
    {      
      if (item2 != NULL)
      {
        return false;
      }
    }
    else if (item2 == NULL)
    {
      return false;
    }
    else
    {
      try
      {
        if ((*iter3).theDoFastComparison)
        {
          if (!item1->equals(item2, theTimezone, (*iter3).theCollator))
          {
            return false;
          }
        }
        else
        {
          store::Item_t tmp1 = (*iter1);
          store::Item_t tmp2 = (*iter2);

          if (!CompareIterator::valueEqual(theLocation,
                                           tmp1,
                                           tmp2,
                                           theTypeManager,
                                           theTimezone,
                                           (*iter3).theCollator))
          {
            return false;                                 
          }
        }
      }
      catch (ZorbaException const& e)
      {
        if (e.diagnostic() == err::XPTY0004 ||
            e.diagnostic() == zerr::ZSTR0040_TYPE_ERROR)
          return false;
        else
          throw;
      }
    }
    
    ++iter3;
    ++iter1;
    ++iter2;
  }

  return true;
}


}
}
/* vim:set et sw=2 ts=2: */
