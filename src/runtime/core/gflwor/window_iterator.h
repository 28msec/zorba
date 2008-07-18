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
#ifndef ZORBA_RUNTIME_GFLWOR_WINDOW
#define ZORBA_RUNTIME_GFLWOR_WINDOW

#include "zorbautils/checked_vector.h"

#include "common/shared_types.h"

#include "runtime/base/plan_iterator.h"

namespace zorba {
  namespace gflwor {
    class WindowIterator;

    enum WindowType   {
      TUMBLING,
      SLIDING
    };

    class StartClause {
        friend class WindowIterator;
      protected:
        PlanIter_t theStartClauseIter;
        std::vector<ForVarIter_t > theCurVars;
        std::vector<ForVarIter_t > thePrevVars;
        std::vector<ForVarIter_t > theNextVars;
        std::vector<ForVarIter_t > thePosVars;

        std::vector<ForVarIter_t > theCurOuterVars;
        std::vector<ForVarIter_t > thePrevOuterVars;
        std::vector<ForVarIter_t > theNextOuterVars;
        std::vector<ForVarIter_t > thePosOuterVars;

      public:

        
        /**
       * Method to construct the StartClause.
       *
       * @param aStartClauseIter The Expr-Single from the StartClause
       * @param aCurVars Variables which refer the current item. The scope is only the EndClauseIter.
       * @param aPrevVars Previous item variables. The scope is only the EndClauseIter.
       * @param aNextVars Next item variables. The scope is only the EndClauseIter.
       * @param aPosVars  Position variables. The scope is only the EndClauseIter.
       * @param aCurOuterVars Variables which refer the current item. The scope is everything after the WindowClause.
       * @param aPrevOuterVars Previous item variables. The scope is everything after the WindowClause.
       * @param aNextOuterVars Next item variables. The scope is everything after the WindowClause.
       * @param aPosOuterVars  Position variables. The scope is everything after the WindowClause.
         */
        StartClause ( PlanIter_t& aStartClauseIter,
                      std::vector<ForVarIter_t >& aCurVars,
                      std::vector<ForVarIter_t >& aPrevVars,
                      std::vector<ForVarIter_t >& aNextVars,
                      std::vector<ForVarIter_t >& aPosVars,

                      std::vector<ForVarIter_t >& aCurOuterVars,
                      std::vector<ForVarIter_t >& aPrevOuterVars,
                      std::vector<ForVarIter_t >& aNextOuterVars,
                      std::vector<ForVarIter_t >& aPosOuterVars
                    );
        
        ~StartClause();
    };

    class EndClause {
        friend class WindowIterator;
      protected:
        PlanIter_t theEndClauseIter;
        bool theOnlyEnd;
        std::vector<ForVarIter_t > theCurVars;
        std::vector<ForVarIter_t > thePrevVars;
        std::vector<ForVarIter_t > theNextVars;
        std::vector<ForVarIter_t > thePosVars;

        std::vector<ForVarIter_t > theCurOuterVars;
        std::vector<ForVarIter_t > thePrevOuterVars;
        std::vector<ForVarIter_t > theNextOuterVars;
        std::vector<ForVarIter_t > thePosOuterVars;

      public:
        
        /**
         * If the EndClause is missing in the case of a tumbling window, this constructor should be used
         */
        EndClause ();
        
        
        /**
         * Method to construct the EndClause.
         *
         * @param aEndClauseIter The Expr-Single from the EndClause
         * @param aOnlyEnd Indicates if the only flag was used
         * @param aCurVars Variables which refer the current item. The scope is only the EndClauseIter.
         * @param aPrevVars Previous item variables. The scope is only the EndClauseIter.
         * @param aNextVars Next item variables. The scope is only the EndClauseIter.
         * @param aPosVars  Position variables. The scope is only the EndClauseIter.
         * @param aCurOuterVars Variables which refer the current item. The scope is everything after the WindowClause.
         * @param aPrevOuterVars Previous item variables. The scope is everything after the WindowClause.
         * @param aNextOuterVars Next item variables. The scope is everything after the WindowClause.
         * @param aPosOuterVars  Position variables. The scope is everything after the WindowClause.
         */
        EndClause ( PlanIter_t& aEndClauseIter,
                    bool aOnlyEnd,
                    std::vector<ForVarIter_t >& aCurVars,
                    std::vector<ForVarIter_t >& aPrevVars,
                    std::vector<ForVarIter_t >& aNextVars,
                    std::vector<ForVarIter_t >& aPosVars,

                    std::vector<ForVarIter_t >& aCurOuterVars,
                    std::vector<ForVarIter_t >& aPrevOuterVars,
                    std::vector<ForVarIter_t >& aNextOuterVars,
                    std::vector<ForVarIter_t >& aPosOuterVars
                  );
        
        ~EndClause();
    };


    class WindowIterator :public Batcher<WindowIterator> {
      private:
        PlanIter_t theTupleIterator;
        PlanIter_t theInputIterator;
        WindowType theWindowType;
        std::vector<LetVarIter_t > theWindowVars;
        StartClause theStartclause;
        EndClause theEndClause;

      public:

        /**
         * Method to construct a WindowIterator.
         *
         * @param aTupleIterator The tuple triggering the window
         * @param aInputIterator The window input
         * @param aWindowType The window Type
         * @param aStartclause The start clause
         * @param aEndClause The end clause. If there is no EndClause theEndClauseIter should be 0
         */
        WindowIterator ( const QueryLoc& aLoc,
                         PlanIter_t& aTupleIterator,
                         PlanIter_t& aInputIterator,
                         WindowType aWindowType,
                         std::vector<LetVarIter_t >& aWindowVars,
                         StartClause& aStartclause,
                         EndClause& aEndClause );
        ~WindowIterator();

        void openImpl ( PlanState& planState, uint32_t& offset );
        bool nextImpl ( store::Item_t& result, PlanState& planState ) const;
        void resetImpl ( PlanState& planState ) const;
        void closeImpl ( PlanState& planState );

        virtual uint32_t getStateSize() const;
        virtual uint32_t getStateSizeOfSubtree() const;

        virtual void accept ( PlanIterVisitor& ) const;

    };

  }//namespace gflwor
} //namespace zorba
#endif  /* ZORBA_RUNTIME_GFLWOR_WINDOW */
