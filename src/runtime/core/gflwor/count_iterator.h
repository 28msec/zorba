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
#ifndef ZORBA_RUNTIME_GFLWOR_COUNT_ITERATOR
#define ZORBA_RUNTIME_GFLWOR_COUNT_ITERATOR

#include "zorbautils/checked_vector.h"
#include "runtime/base/unarybase.h"


namespace zorba {

  namespace gflwor {

    class CountState : public PlanIteratorState {
      private:
        int theCount;

      public:
        void init ( PlanState& );
        void reset ( PlanState& );
        inline int incCount() {return ++theCount;}

    };

    class CountIterator : public UnaryBaseIterator<CountIterator, CountState> {
      private:
        store::Item_t theVarName;
        std::vector<ForVarIter_t> theCountVars;
      public:
        CountIterator ( const QueryLoc& aLoc,
                      const store::Item_t& aVarName,
                      PlanIter_t aTupleIterator,
                      std::vector<ForVarIter_t> aCountVars );

        ~CountIterator();

      public:
        bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
        virtual void accept ( PlanIterVisitor& ) const;
    };
  }
}


#endif  /* ZORBA_RUNTIME_GFLWOR_COUNT_ITERATOR */
/*
 * Local variables:
 * mode: c++
 * End:
 */
