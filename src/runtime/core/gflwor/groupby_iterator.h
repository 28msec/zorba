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
#ifndef ZORBA_RUNTIME_GFLWOR_GROUPBY
#define ZORBA_RUNTIME_GFLWOR_GROUPBY

#include "zorbautils/checked_vector.h"

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/core/gflwor/common.h"


namespace zorba 
{
namespace flwor 
{

class GroupByIterator;
  

/***************************************************************************//**

********************************************************************************/
class GroupByState : public PlanIteratorState 
{
  friend class GroupByIterator;

protected:
  GroupHashMap           * theGroupMap;
  GroupHashMap::iterator   theGroupMapIter;
       
public:
  GroupByState();

  ~GroupByState();

  void init(
        PlanState& aState,
        const TypeManager* tm,
        const QueryLoc& loc,
        std::vector<GroupingSpec>* gspecs);

  void reset(PlanState& state);
};


/***************************************************************************//**

********************************************************************************/
class GroupByIterator : public Batcher<GroupByIterator> 
{
private:
  PlanIter_t                    theTupleIter;
  std::vector<GroupingSpec>     theGroupingSpecs;
  std::vector<NonGroupingSpec>  theNonGroupingSpecs;

public:
  SERIALIZABLE_CLASS(GroupByIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(GroupByIterator, Batcher<GroupByIterator>)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  GroupByIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t aTupleIterator,
        std::vector<GroupingSpec> aGroupingSpecs,
        std::vector<NonGroupingSpec> aNonGroupingSpecs);

  ~GroupByIterator();

  uint32_t getStateSize() const;

  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor&) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  void resetImpl(PlanState& planState) const;

  void closeImpl(PlanState& planState);

private:
  void matVarsAndGroupBy(
        GroupByState* aGroupByState,
        PlanState& aPlanState) const;

  void bindGroupBy(
        GroupHashMap::iterator aGroupMapIter,
        GroupByState* aGroupByState,
        PlanState& aPlanState) const;
};


}//namespace gflwor
} //namespace zorba


#endif  /* ZORBA_RUNTIME_GFLWOR_GROUPBY */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
