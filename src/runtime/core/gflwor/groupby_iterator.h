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
        std::vector<GroupingSpec>* groupingSpecs);

  void reset(PlanState& state);
};


class GroupByIterator : public Batcher<GroupByIterator> 
{
private:
  PlanIter_t                    theTupleIter;
  std::vector<GroupingSpec>     theGroupingSpecs;
  std::vector<GroupingOuterVar> theOuterVars;

public:
  SERIALIZABLE_CLASS(GroupByIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(GroupByIterator, Batcher<GroupByIterator>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (Batcher<GroupByIterator>*)this);
    ar & theTupleIter;
    ar & theGroupingSpecs;
    ar & theOuterVars;
  }
public:
  GroupByIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t aTupleIterator,
        std::vector<GroupingSpec> aGroupingSpecs,
        std::vector<GroupingOuterVar> aOuterVars);

  ~GroupByIterator();

  void openImpl ( PlanState& planState, uint32_t& offset );
  bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
  void resetImpl ( PlanState& planState ) const;
  void closeImpl ( PlanState& planState );

  virtual uint32_t getStateSize() const;
  virtual uint32_t getStateSizeOfSubtree() const;

  virtual void accept(PlanIterVisitor&) const;

private:
  void matVarsAndGroupBy (
        GroupByState* aGroupByState,
        PlanState& aPlanState ) const;

  void bindGroupBy (
        GroupHashMap::iterator aGroupMapIter,
        GroupByState* aGroupByState,
        PlanState& aPlanState ) const;
};


}//namespace gflwor
} //namespace zorba


#endif  /* ZORBA_RUNTIME_GFLWOR_GROUPBY */
/*
 * Local variables:
 * mode: c++
 * End:
 */
