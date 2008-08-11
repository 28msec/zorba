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
#include "runtime/util/handle_hashmap_item_value.h"

namespace zorba {
  namespace gflwor {

    class GroupByIterator;

    typedef ItemValuesCollHandleHashMap<std::vector<store::TempSeq_t>* > group_map_t;

    class GroupingSpec {
        friend class PrinterVisitor;
        friend class GroupByIterator;
      protected:
        PlanIter_t              theInput;
        std::vector<ForVarIter_t> theInnerVars;
        xqpString               theCollation;
      public:
        GroupingSpec ( PlanIter_t aInput, std::vector<ForVarIter_t> aInnerVars, xqpString aCollation );
        void accept ( PlanIterVisitor& ) const;
        void open ( PlanState& planState, uint32_t& offset ) const;
        void close ( PlanState& planState ) const ;
        void reset ( PlanState& planState ) const;
        uint32_t getStateSizeOfSubtree() const;
    };

    class GroupingOuterVar {
        friend class PrinterVisitor;
        friend class GroupByIterator;
      protected:
        PlanIter_t              theInput;
        std::vector<LetVarIter_t> theOuterVars;
      public:
        GroupingOuterVar ( PlanIter_t aInput, std::vector<LetVarIter_t> aOuterVars );
        void accept ( PlanIterVisitor& ) const;
        void open ( PlanState& planState, uint32_t& offset ) const;
        void close ( PlanState& planState ) const;
        void reset ( PlanState& planState ) const;
        uint32_t getStateSizeOfSubtree() const;
    };

    class GroupByState : public PlanIteratorState {
        friend class GroupByIterator;
      protected:
        group_map_t* theGroupMap; //Needs to be a pointer because of the Collators
        GroupCompareParam* theValueCompareParam;
        group_map_t::iterator theCurGroupPos;
       

      public:
        ~GroupByState();
        GroupByState();
        void init ( PlanState& aState, std::vector<XQPCollator*> * aGroupingCollators );
        void reset ( PlanState& );
    };

    class GroupByIterator : public Batcher<GroupByIterator> {
      private:
        PlanIter_t theTupleIter;
        std::vector<GroupingSpec> theGroupingSpecs;
        std::vector<GroupingOuterVar> theOuterVars;

      public:
        GroupByIterator ( const QueryLoc& loc,
                          PlanIter_t aTupleIterator,
                          std::vector<GroupingSpec> aGroupingSpecs,
                          std::vector<GroupingOuterVar> aOuterVars );

        ~GroupByIterator();

        void openImpl ( PlanState& planState, uint32_t& offset );
        bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
        void resetImpl ( PlanState& planState ) const;
        void closeImpl ( PlanState& planState );

        virtual uint32_t getStateSize() const;
        virtual uint32_t getStateSizeOfSubtree() const;

        virtual void accept ( PlanIterVisitor& ) const;

      private:
        void matVarsAndGroupBy ( GroupByState* aGroupByState,
                                 PlanState& aPlanState ) const;

        void bindGroupBy ( group_map_t::iterator aGroupMapIter,
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
