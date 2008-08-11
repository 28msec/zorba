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
#ifndef ZORBA_RUNTIME_GFLWOR_ORDERBY
#define ZORBA_RUNTIME_GFLWOR_ORDERBY

#include "zorbautils/checked_vector.h"

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"

#include "store/api/temp_seq.h" //FIXME not sure why this is needed here

namespace zorba {
  namespace gflwor {

    class OrderByIterator;

    class OrderValue;
    

    class OrderValue {
        friend class OrderByIterator;

      protected:
        std::vector<store::Item_t > theItems;
        std::vector<store::TempSeq_t > theSequences;

      public:
        OrderValue ( std::vector<store::Item_t >& aItems,std::vector<store::TempSeq_t >& aSequences ) :
            theItems ( aItems ),
            theSequences ( aSequences ) {}
    };

    class OrderKeyCmp;
    typedef std::multimap<std::vector<store::Item_t >, OrderValue, OrderKeyCmp> order_map_t;


    class OrderSpec {
        friend class OrderByIterator;
        friend class OrderKeyCmp;

      protected:
        PlanIter_t             theOrderByIter;
        bool                   theEmptyLeast;
        bool                   theDescending;
        xqpString              theCollation;
        XQPCollator  * theCollator; // TODO hack
        RuntimeCB    * theRuntimeCB; // TODO hack

      public:
        void accept ( PlanIterVisitor& ) const;
        void open (PlanState& aPlanState, uint32_t& offset) const;
        void reset ( PlanState& aPlanState ) const;
        void close (PlanState& aPlanState) const;
        uint32_t getStateSizeOfSubtree() const;
        OrderSpec ( PlanIter_t orderByIter, bool empty_least, bool descending );
        OrderSpec ( PlanIter_t orderByIter, bool empty_least, bool descending, const xqpString& collation );
    };

    /**
     * Class to pass to the MultiMap to do the comparison according to the OrderByClause.
     * Luckily the MultiMap is stable already :-)
     */
    class OrderKeyCmp {
      public:
        OrderKeyCmp() : mOrderSpecs ( 0 ) {}

        OrderKeyCmp ( std::vector<OrderSpec>* aOrderSpecs )
            :
            mOrderSpecs ( aOrderSpecs ) {}

        /**
               * The key comparison function, a Strict Weak Ordering whose argument type is key_type;
               * it returns true if its first argument is less than its second argument, and false otherwise.
               * This is also defined as multimap::key_compare.
         */
        bool operator() ( const std::vector<store::Item_t>& s1, const std::vector<store::Item_t>& s2 ) const;

        /**
               * Does the actual comparision
               * @return    -1, if item0 &lt; item1
               *            0, if item0 == item1
               *            1, if item0 &gt; item1
         */
        inline int8_t compare (
          RuntimeCB* aRuntimeCB,
          const store::Item_t& s1,
          const store::Item_t& s2,
          bool asc,
          bool emptyLeast,
          XQPCollator* collator = 0 ) const;

        /**
             * Helper functions to switch the ordering between ascending and descending
         */
        inline int8_t descAsc ( int8_t result, bool asc ) const;

      private:
        std::vector<OrderSpec>* mOrderSpecs; //Pointer to the OrderSpec to do the comparison accordingly
    };


    class OrderByState : public PlanIteratorState {
        friend class OrderByIterator;
      protected:
        order_map_t theOrderMap;
        order_map_t::const_iterator  theCurOrderPos;

      public:
        ~OrderByState();
        OrderByState();
        void init ( PlanState& aState, std::vector<OrderSpec>* orderSpecs );
        void reset ( PlanState& );
    };

    
    class OrderByIterator : public Batcher<OrderByIterator> {
      private:
        PlanIter_t theTupleIter;
        std::vector<OrderSpec> theOrderSpecs;
        std::vector<ForVarIter_t> theForVariableInput;
        std::vector<LetVarIter_t> theLetVariableInput;
        std::vector< std::vector< ForVarIter_t > > theForVariableOutput;
        std::vector< std::vector< LetVarIter_t > > theLetVariableOutput;

      public:
        OrderByIterator ( const QueryLoc& aLoc,
                          PlanIter_t aTupleIterator,
                          std::vector<OrderSpec>& aOrderSpecs,
                          std::vector<ForVarIter_t>& aForVariableInput,
                          std::vector<LetVarIter_t>& aLetVariableInput,
                          std::vector< std::vector< ForVarIter_t > >& aForVariableOutput,
                          std::vector< std::vector< LetVarIter_t > >& aLetVariableOutput );

        ~OrderByIterator();

        void openImpl ( PlanState& planState, uint32_t& offset );
        bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
        void resetImpl ( PlanState& planState ) const;
        void closeImpl ( PlanState& planState );

        virtual uint32_t getStateSize() const;
        virtual uint32_t getStateSizeOfSubtree() const;

        virtual void accept ( PlanIterVisitor& ) const;

      private:
        void matVarsAndOrderBy ( OrderByState* aOrderByState,
                                 PlanState& aPlanState ) const;

        void bindOrderBy ( order_map_t::const_iterator& aOrderMapIter,
                           PlanState& aPlanState ) const;
        
        
    };
  }//namespace gflwor
} //namespace zorba


#endif  /* ZORBA_RUNTIME_GFLWOR_ORDERBY */

/*
 * Local variables:
 * mode: c++
 * End:
 */
