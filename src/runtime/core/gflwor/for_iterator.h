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
#ifndef ZORBA_RUNTIME_GFLWOR_FOR_ITERATOR
#define ZORBA_RUNTIME_GFLWOR_FOR_ITERATOR

#include "zorbautils/checked_vector.h"
#include "runtime/base/binarybase.h"


namespace zorba {
 
  namespace gflwor {   
    
    class ForState : public PlanIteratorState {
      private:
        int thePosition;

      public:
        void init ( PlanState& );
        void reset ( PlanState& );
        inline int incReturnPosition() {return ++thePosition;}

    };

    class ForIterator : public BinaryBaseIterator<ForIterator, ForState> {
      private:
        store::Item_t theVarName;
        bool theHasPosVars;
        std::vector<ForVarIter_t> theForVars;
        std::vector<ForVarIter_t> thePosVars;
      public:
        ForIterator ( const QueryLoc& aLoc,
                      const store::Item_t& aVarName,
                      PlanIter_t aTupleIterator,
                      PlanIter_t aInput,
                      std::vector<ForVarIter_t> aForVars );
        
        ForIterator ( const QueryLoc& loc,
                      const store::Item_t& aVarName,
                      PlanIter_t aTupleIterator,
                      PlanIter_t aInput,
                      std::vector<ForVarIter_t> aForVars,
                      std::vector<ForVarIter_t> aPosVars );
        ~ForIterator();

      public:
        bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
        virtual void accept ( PlanIterVisitor& ) const;
    };
  }
}


#endif  /* ZORBA_RUNTIME_GFLWOR_TUPLESTREAM_ITERATOR */
