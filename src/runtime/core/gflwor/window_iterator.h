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

namespace zorba 
{
namespace flwor 
{
    class WindowIterator;

    class WindowVars {
        friend class WindowIterator;
        friend class StartClause;
        friend class EndClause;
      protected:
        std::vector<ForVarIter_t > theCurVars;
        std::vector<ForVarIter_t > thePrevVars;
        std::vector<ForVarIter_t > theNextVars;
        std::vector<ForVarIter_t > thePosVars;

        std::vector<ForVarIter_t > theCurOuterVars;
        std::vector<ForVarIter_t > thePrevOuterVars;
        std::vector<ForVarIter_t > theNextOuterVars;
        std::vector<ForVarIter_t > thePosOuterVars;

      public:
        WindowVars();
        /**
          * Method to construct the WindowVars.
          *
          * @param aCurVars Variables which refer the current item. The scope is only the WindowClause.
          * @param aPrevVars Previous item variables. The scope is only the WindowClause.
          * @param aNextVars Next item variables. The scope is only the WindowClause.
          * @param aPosVars  Position variables. The scope is only the WindowClause.
          * @param aCurOuterVars Variables which refer the current item. The scope is everything after the WindowClause.
          * @param aPrevOuterVars Previous item variables. The scope is everything after the WindowClause.
          * @param aNextOuterVars Next item variables. The scope is everything after the WindowClause.
          * @param aPosOuterVars  Position variables. The scope is everything after the WindowClause.
         */
        WindowVars ( std::vector<ForVarIter_t >& aCurVars,
                     std::vector<ForVarIter_t >& aPrevVars,
                     std::vector<ForVarIter_t >& aNextVars,
                     std::vector<ForVarIter_t >& aPosVars,

                     std::vector<ForVarIter_t >& aCurOuterVars,
                     std::vector<ForVarIter_t >& aPrevOuterVars,
                     std::vector<ForVarIter_t >& aNextOuterVars,
                     std::vector<ForVarIter_t >& aPosOuterVars
                   );

        ~WindowVars();

        void accept ( PlanIterVisitor& ) const;

        /**
         * Binds the variables inside the window clause.
         *
         * @param aPlanState The PlanState
         * @param aInputSeq The underlying input sequence
         * @param aPosition The relative position for all variables. Starts counting with 0 (although the XQuery counting starts with 1).
         */
        void bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const;

        /**
        * Binds the variables outside the window clause.
        *
        * @param aPlanState The PlanState
        * @param aInputSeq The underlying input sequence
        * @param aPosition The relative position for all variables. Starts counting with 0 (although the XQuery counting starts with 1).
        */
        void bindExtern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const;
    };

    class StartClause {
        friend class WindowIterator;
      protected:
        PlanIter_t theStartClauseIter;
        WindowVars theWindowVars;

      public:
        StartClause ( PlanIter_t aStartClauseIter,
                      WindowVars& aWindowVars
                    );
        ~StartClause();
        
      protected:

        void accept ( PlanIterVisitor& ) const;
        void open ( PlanState& aPlanState, uint32_t& offset ) const;
        void reset ( PlanState& aPlanState ) const;
        void close ( PlanState& aPlanState ) const;
        uint32_t getStateSizeOfSubtree() const;
        bool evaluate(PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition) const;
        void bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const;
        void bindExtern(PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition) const;
    };

    class EndClause {
        friend class WindowIterator;
      protected:
        PlanIter_t theEndClauseIter;
        WindowVars theWindowVars;
        bool theOnlyEnd;
        bool theHasEndClause;

      public:
        /**
         * If the EndClause is missing in the case of a tumbling window, this constructor should be used
         */
        EndClause ();
        EndClause ( PlanIter_t aEndClauseIter,
                    WindowVars& theWindowVars,
                    bool aOnlyEnd
                  );
        ~EndClause();

      protected:
        void accept ( PlanIterVisitor& ) const;
        void open ( PlanState& aPlanState, uint32_t& offset ) const;
        void reset ( PlanState& aPlanState ) const;
        void close ( PlanState& aPlanState ) const;
        uint32_t getStateSizeOfSubtree() const;
        bool evaluate(PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition) const;
        void bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const;
        void bindExtern(PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition) const;
    };


    class WindowState : public PlanIteratorState {
        friend class WindowIterator;
      protected:
        store::TempSeq_t theInputSeq;
        uint32_t theCurInputPos;
        std::vector<uint32_t> theOpenWindowsStartPos;
        std::vector<uint32_t>::iterator theCurWindow;
        
      public:
        ~WindowState();
        WindowState();
        void init ( PlanState& aState );
        void reset ( PlanState& aState );
        void tupleReset();
    };


    class WindowIterator :public Batcher<WindowIterator> {
      public:
        static const uint32_t MAX_HISTORY; //TODO should be set platform dependent, but somebody hat comment out everything in platform.h!
        
        enum WindowType   {
          TUMBLING,
          SLIDING
        };
      
      private:
        PlanIter_t theTupleIter;
        PlanIter_t theInputIter;
        WindowType theWindowType;
        std::vector<LetVarIter_t > theVars;
        StartClause theStartClause;
        EndClause theEndClause;
        bool theLazyEval;
        uint32_t theMaxNeededHistory;

      public:

        /**
         * Method to construct a WindowIterator.
         *
         * @param aTupleIterator The tuple triggering the window
         * @param aInputIterator The window input
         * @param aWindowType The window Type
         * @param aStartclause The start clause. The iterator has to return a Boolean Value or Null.
         * @param aEndClause The end clause. The iterator has to return a Boolean Value or Null.
         * @param aLazyEval For Windowing the input sequence needs to be materialized. Is it allowed to do this lazy?
         * @param aMaxNeededHistory To allow Continous Queries we need to garbage collect a possible infinite input sequence. 
         *                          But the Start, End and other Clauses might require to look back from the start position of a window.
         *                          The MaxNeededHistory specifies how much it is required to look back. 
         *                          If the value is MAX_HISTORY no Garbage Colleciton is performed.
         * 
         */
        WindowIterator ( const QueryLoc& aLoc,
                         PlanIter_t aTupleIterator,
                         PlanIter_t aInputIterator,
                         WindowType aWindowType,
                         std::vector<LetVarIter_t >& aVars,
                         StartClause& aStartclause,
                         EndClause& aEndClause,
                         bool aLazyEval = true,
                         uint32_t aMaxNeededHistory = MAX_HISTORY);
        ~WindowIterator();

        void openImpl ( PlanState& aPlanState, uint32_t& aOffset );
        bool nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const;
        void resetImpl ( PlanState& aPlanState ) const;
        void closeImpl ( PlanState& aPlanState );

        virtual uint32_t getStateSize() const;
        virtual uint32_t getStateSizeOfSubtree() const;

        virtual void accept ( PlanIterVisitor& ) const;
        
      private:
        void bindVariable ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aStartPos, const uint32_t aEndPos ) const;
        void doGarbageCollection(WindowState* lState) const;
    };

  }//namespace gflwor
} //namespace zorba
#endif  /* ZORBA_RUNTIME_GFLWOR_WINDOW */
/*
 * Local variables:
 * mode: c++
 * End:
 */
