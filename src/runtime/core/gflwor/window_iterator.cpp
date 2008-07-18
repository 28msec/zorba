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
#include "runtime/core/gflwor/window_iterator.h"
#include "runtime/core/gflwor/common.h"

#include "runtime/core/var_iterators.h"
#include "runtime/visitors/planitervisitor.h"
#include "store/api/store.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"

using namespace zorba;

namespace zorba {
  namespace gflwor {

    StartClause::StartClause ( PlanIter_t& aStartClauseIter,
                               std::vector<ForVarIter_t >& aCurVars,
                               std::vector<ForVarIter_t >& aPrevVars,
                               std::vector<ForVarIter_t >& aNextVars,
                               std::vector<ForVarIter_t >& aPosVars,
                               std::vector<ForVarIter_t >& aCurOuterVars,
                               std::vector<ForVarIter_t >& aPrevOuterVars,
                               std::vector<ForVarIter_t >& aNextOuterVars,
                               std::vector<ForVarIter_t >& aPosOuterVars
                             ) :
        theStartClauseIter ( aStartClauseIter ),
        theCurVars ( aCurVars ),
        thePrevVars ( aPrevVars ),
        theNextVars ( aNextVars ),
        thePosVars ( aPosVars ),
        theCurOuterVars ( aCurOuterVars ),
        thePrevOuterVars ( aPrevOuterVars ),
        theNextOuterVars ( aNextOuterVars ),
        thePosOuterVars ( aPosOuterVars ) {

    }


    StartClause::~StartClause() {
    }

    EndClause::EndClause () : theEndClauseIter ( 0 ) {

    }

    EndClause::EndClause ( PlanIter_t& aEndClauseIter,
                           bool aOnlyEnd,
                           std::vector<ForVarIter_t >& aCurVars,
                           std::vector<ForVarIter_t >& aPrevVars,
                           std::vector<ForVarIter_t >& aNextVars,
                           std::vector<ForVarIter_t >& aPosVars,

                           std::vector<ForVarIter_t >& aCurOuterVars,
                           std::vector<ForVarIter_t >& aPrevOuterVars,
                           std::vector<ForVarIter_t >& aNextOuterVars,
                           std::vector<ForVarIter_t >& aPosOuterVars
                         ) : theEndClauseIter ( aEndClauseIter ),
        theOnlyEnd ( aOnlyEnd ),
        theCurVars ( aCurVars ),
        thePrevVars ( aPrevVars ),
        theNextVars ( aNextVars ),
        thePosVars ( aPosVars ),
        theCurOuterVars ( aCurOuterVars ),
        thePrevOuterVars ( aPrevOuterVars ),
        theNextOuterVars ( aNextOuterVars ),
        thePosOuterVars ( aPosOuterVars ) {

    }

    EndClause::~EndClause() {
    }


    WindowIterator::WindowIterator ( const QueryLoc& aLoc,
                                     PlanIter_t& aTupleIterator,
                                     PlanIter_t& aInputIterator,
                                     WindowType aWindowType,
                                     std::vector<LetVarIter_t >& aWindowVars,
                                     StartClause& aStartclause,
                                     EndClause& aEndClause ) :
        Batcher<WindowIterator> ( aLoc ),
        theTupleIterator ( aTupleIterator ),
        theInputIterator ( aInputIterator ),
        theWindowType ( aWindowType ),
        theWindowVars ( aWindowVars ),
        theStartclause ( aStartclause ),
        theEndClause ( aEndClause ) {

    }

    WindowIterator::~WindowIterator() {

    }

    void WindowIterator::openImpl ( PlanState& planState, uint32_t& offset ) {

    }

    bool WindowIterator::nextImpl ( store::Item_t& result, PlanState& planState ) const {
      return false;
    }

    void WindowIterator::resetImpl ( PlanState& planState ) const {

    }

    void WindowIterator::closeImpl ( PlanState& planState ) {

    }


    uint32_t WindowIterator::getStateSize() const {
      return 0;
    }

    uint32_t WindowIterator::getStateSizeOfSubtree() const {
      return 0;
    }

    void WindowIterator::accept ( PlanIterVisitor& ) const {
    }


  } //Namespace flwor
}//Namespace zorba
