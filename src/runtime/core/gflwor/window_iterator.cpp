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

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  WindowVars                                                                 //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    WindowVars::WindowVars() {
    }

    WindowVars::WindowVars ( std::vector<ForVarIter_t >& aCurVars,
                             std::vector<ForVarIter_t >& aPrevVars,
                             std::vector<ForVarIter_t >& aNextVars,
                             std::vector<ForVarIter_t >& aPosVars,
                             std::vector<ForVarIter_t >& aCurOuterVars,
                             std::vector<ForVarIter_t >& aPrevOuterVars,
                             std::vector<ForVarIter_t >& aNextOuterVars,
                             std::vector<ForVarIter_t >& aPosOuterVars
                           ) :
        theCurVars ( aCurVars ),
        thePrevVars ( aPrevVars ),
        theNextVars ( aNextVars ),
        thePosVars ( aPosVars ),
        theCurOuterVars ( aCurOuterVars ),
        thePrevOuterVars ( aPrevOuterVars ),
        theNextOuterVars ( aNextOuterVars ),
        thePosOuterVars ( aPosOuterVars ) {

    }


    WindowVars::~WindowVars() {
    }

    void WindowVars::accept ( PlanIterVisitor& ) const {
      //TODO More infos
    }

    void WindowVars::bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const {
      store::Item_t lItem;
      if ( !theCurVars.empty() ) {
        lItem = aInputSeq->getItem ( aPosition );
        bindVariables ( lItem, theCurVars, aPlanState );
      }
      if ( !thePrevVars.empty() ) {
        if ( aPosition > 0 ) {
          lItem = aInputSeq->getItem ( aPosition-1 );
        } else {
          lItem = 0;
        }
        bindVariables ( lItem, thePrevVars, aPlanState );
      }
      if ( !theNextVars.empty() ) {
        if ( aInputSeq->containsItem ( aPosition+1 ) ) {
          lItem = aInputSeq->getItem ( aPosition+1 );
        } else {
          lItem = 0;
        }
        bindVariables ( lItem, theNextVars, aPlanState );
      }
      if ( !thePosVars.empty() ) {
        store::Item_t lPosItem;
        GENV_ITEMFACTORY->createInteger ( lPosItem, Integer::parseInt ( aPosition+1 ) );
        bindVariables ( lPosItem, thePosVars, aPlanState );
      }
    }

    void WindowVars::bindExtern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const {
      store::Item_t lItem;
      if ( !theCurOuterVars.empty() ) {
        lItem = aInputSeq->getItem ( aPosition );
        bindVariables ( lItem, theCurOuterVars, aPlanState );
      }
      if ( !thePrevOuterVars.empty() ) {
        if ( aPosition > 0 ) {
          lItem = aInputSeq->getItem ( aPosition-1 );
        } else {
          lItem = 0;
        }
        bindVariables ( lItem, thePrevOuterVars, aPlanState );
      }
      if ( !theNextOuterVars.empty() ) {
        if ( aInputSeq->containsItem ( aPosition+1 ) ) {
          lItem = aInputSeq->getItem ( aPosition+1 );
        } else {
          lItem = 0;
        }
        bindVariables ( lItem, theNextOuterVars, aPlanState );
      }
      if ( !thePosOuterVars.empty() ) {
        GENV_ITEMFACTORY->createInteger ( lItem, Integer::parseInt ( aPosition+1 ) );
        bindVariables ( lItem, thePosOuterVars, aPlanState );
      }
    }


    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  StartClause                                                                //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    StartClause::StartClause ( PlanIter_t& aStartClauseIter,
                               WindowVars& aWindowVars
                             ) :
        theStartClauseIter ( aStartClauseIter ),
        theWindowVars ( aWindowVars ) {

    }


    StartClause::~StartClause() {
    }

    void StartClause::accept ( PlanIterVisitor& v ) const {
      //TODO more output
      theWindowVars.accept ( v );
      theStartClauseIter->accept ( v );
    }

    void StartClause::open ( PlanState& aPlanState, uint32_t& aOffset ) const {
      theStartClauseIter->open ( aPlanState, aOffset );
    }

    void StartClause::reset ( PlanState& aPlanState ) const {
      theStartClauseIter->reset ( aPlanState );
    }

    void StartClause::close ( PlanState& aPlanState ) const {
      theStartClauseIter->close ( aPlanState );
    }

    uint32_t StartClause::getStateSizeOfSubtree() const {
      return theStartClauseIter->getStateSizeOfSubtree();
    }

    bool StartClause::evaluate ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const {
      theWindowVars.bindIntern ( aPlanState, aInputSeq, aPosition );
      return evalToBool ( theStartClauseIter, aPlanState );
    }

    void StartClause::bindExtern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const {
      theWindowVars.bindExtern ( aPlanState, aInputSeq, aPosition );
    }

    void StartClause::bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const {
      theWindowVars.bindIntern ( aPlanState, aInputSeq, aPosition );
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  EndClause                                                                //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    EndClause::EndClause () : theEndClauseIter ( NULL ), theHasEndClause ( false ) {

    }

    EndClause::EndClause ( PlanIter_t& aEndClauseIter,
                           WindowVars& aWindowVars,
                           bool aOnlyEnd
                         ) : theEndClauseIter ( aEndClauseIter ),
        theWindowVars ( aWindowVars ),
        theOnlyEnd ( aOnlyEnd ),
        theHasEndClause ( true ) {

    }

    EndClause::~EndClause() {
    }

    void EndClause::accept ( PlanIterVisitor& v ) const {
      //TODO more output
      if ( theHasEndClause ) {
        theWindowVars.accept ( v );
        theEndClauseIter->accept ( v );
      }
    }

    void EndClause::open ( PlanState& aPlanState, uint32_t& aOffset ) const {
      if ( theHasEndClause )
        theEndClauseIter->open ( aPlanState, aOffset );
    }

    void EndClause::reset ( PlanState& aPlanState ) const {
      if ( theHasEndClause )
        theEndClauseIter->reset ( aPlanState );
    }

    void EndClause::close ( PlanState& aPlanState ) const {
      if ( theHasEndClause )
        theEndClauseIter->close ( aPlanState );
    }

    uint32_t EndClause::getStateSizeOfSubtree() const {
      if ( theHasEndClause )
        return theEndClauseIter->getStateSizeOfSubtree();
      else
        return 0;
    }

    bool EndClause::evaluate ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const {
      theWindowVars.bindIntern ( aPlanState, aInputSeq, aPosition );
      return evalToBool ( theEndClauseIter, aPlanState );
    }

    void EndClause::bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const {
      theWindowVars.bindIntern ( aPlanState, aInputSeq, aPosition );
    }

    void EndClause::bindExtern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const {
      theWindowVars.bindExtern ( aPlanState, aInputSeq, aPosition );
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  WindowState                                                                //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    WindowState::WindowState() : theInputSeq ( NULL ) , theCurInputPos ( 0 ) {
    }


    WindowState::~WindowState() {

    }


    void WindowState::init ( PlanState& aState ) {
      PlanIteratorState::init ( aState );
      theCurInputPos = 0;
      theInputSeq = NULL;
    }

    void WindowState::reset ( PlanState& aPlanState ) {
      PlanIteratorState::reset ( aPlanState );
      theCurInputPos = 0;
      theInputSeq = NULL;
      theOpenWindowsStartPos.clear();
    }


    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  WindowIterator                                                             //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    WindowIterator::WindowIterator ( const QueryLoc& aLoc,
                                     PlanIter_t& aTupleIterator,
                                     PlanIter_t& aInputIterator,
                                     WindowType aWindowType,
                                     std::vector<LetVarIter_t >& aVars,
                                     StartClause& aStartclause,
                                     EndClause& aEndClause,
                                     bool aLazyEval ) :
        Batcher<WindowIterator> ( aLoc ),
        theTupleIter ( aTupleIterator ),
        theInputIter ( aInputIterator ),
        theWindowType ( aWindowType ),
        theVars ( aVars ),
        theStartClause ( aStartclause ),
        theEndClause ( aEndClause ),
        theLazyEval ( aLazyEval ) {

    }

    WindowIterator::~WindowIterator() {

    }

    uint32_t WindowIterator::getStateSize() const {
      return StateTraitsImpl<WindowState>::getStateSize();
    }

    uint32_t WindowIterator::getStateSizeOfSubtree() const {
      int32_t lSize = this->getStateSize();
      lSize += theTupleIter->getStateSizeOfSubtree();
      lSize += theInputIter->getStateSizeOfSubtree();
      lSize += theStartClause.getStateSizeOfSubtree();
      lSize += theEndClause.getStateSizeOfSubtree();
      return lSize;
    }

    void WindowIterator::openImpl ( PlanState& aPlanState, uint32_t& aOffset ) {
      StateTraitsImpl<WindowState>::createState ( aPlanState, this->stateOffset, aOffset );
      theTupleIter->open ( aPlanState, aOffset );
      theInputIter->open ( aPlanState, aOffset );
      theStartClause.open ( aPlanState, aOffset );
      theEndClause.open ( aPlanState, aOffset );
    }


    void WindowIterator::resetImpl ( PlanState& aPlanState ) const {
      WindowState* lState = StateTraitsImpl<WindowState>::getState ( aPlanState, this->stateOffset );
      lState->reset ( aPlanState );

      theTupleIter->reset ( aPlanState );
      theInputIter->reset ( aPlanState );
      theStartClause.reset ( aPlanState );
      theEndClause.reset ( aPlanState );
    }

    void WindowIterator::closeImpl ( PlanState& aPlanState ) {
      theTupleIter->close ( aPlanState );
      theInputIter->close ( aPlanState );
      theStartClause.close ( aPlanState );
      theEndClause.close ( aPlanState );
      StateTraitsImpl<WindowState>::destroyState ( aPlanState, this->stateOffset );
    }


    void WindowIterator::accept ( PlanIterVisitor& v ) const {
      //TODO More infos and more precise
      theTupleIter->accept ( v );
      theInputIter->accept ( v );
      theStartClause.accept ( v );
      theEndClause.accept ( v );
    }

    void WindowIterator::bindVariable ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aStartPos, const uint32_t aEndPos ) const {
      for ( std::vector<LetVarIter_t>::const_iterator lVarIter = theVars.begin();
            lVarIter != theVars.end();
            ++lVarIter ) {
        store::Iterator_t lIter = aInputSeq->getIterator ( aStartPos, aEndPos, true );
        lIter->open(); //FIXME We need to close the iterator! So far this only works because close is a empty function
        ( *lVarIter )->bind ( lIter  , aPlanState );
      }
    }

    bool WindowIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const {
      WindowState* lState;
      DEFAULT_STACK_INIT ( WindowState, lState, aPlanState );
      while ( consumeNext ( aResult, theTupleIter, aPlanState ) ) {
        store::Iterator_t iterWrapper = new PlanIteratorWrapper ( theInputIter, aPlanState );
        lState->theInputSeq = GENV_STORE.createTempSeq ( iterWrapper, false, theLazyEval );

        //Its clever to switch quite early to avoid a lot of if-else statements
        switch ( theWindowType ) {
          case WindowIterator::SLIDING: {
            while ( lState->theInputSeq->containsItem ( lState->theCurInputPos ) ) {
              if ( theStartClause.evaluate ( aPlanState, lState->theInputSeq, lState->theCurInputPos ) ) {
                lState->theOpenWindowsStartPos.push_back ( lState->theCurInputPos );
              }
              lState->theCurWindow =lState->theOpenWindowsStartPos.begin();
              while ( lState->theCurWindow != lState->theOpenWindowsStartPos.end() ) {
                theStartClause.bindIntern ( aPlanState, lState->theInputSeq, *lState->theCurWindow );
                if ( theEndClause.evaluate ( aPlanState, lState->theInputSeq, lState->theCurInputPos ) ) {
                  theStartClause.bindExtern ( aPlanState, lState->theInputSeq, *lState->theCurWindow );
                  theEndClause.bindExtern ( aPlanState, lState->theInputSeq, lState->theCurInputPos );
                  bindVariable ( aPlanState, lState->theInputSeq, *lState->theCurWindow, lState->theCurInputPos );
                  lState->theCurWindow= lState->theOpenWindowsStartPos.erase ( lState->theCurWindow );
                  STACK_PUSH ( true, lState );
                } else {
                  ++ ( lState->theCurWindow );
                }
              }
              ++lState->theCurInputPos;
            }
          }
          break;
          case WindowIterator::TUMBLING: {
            //Doing this switch now also avoids further overhad
            if ( theEndClause.theHasEndClause ) {
              while ( lState->theInputSeq->containsItem ( lState->theCurInputPos ) ) {
                if ( lState->theOpenWindowsStartPos.empty() && theStartClause.evaluate ( aPlanState, lState->theInputSeq, lState->theCurInputPos ) ) {
                  theStartClause.bindExtern ( aPlanState, lState->theInputSeq, lState->theCurInputPos );
                  lState->theOpenWindowsStartPos.push_back ( lState->theCurInputPos );
                }
                if ( !lState->theOpenWindowsStartPos.empty() && theEndClause.evaluate ( aPlanState, lState->theInputSeq, lState->theCurInputPos ) ) {
                  theEndClause.bindExtern ( aPlanState, lState->theInputSeq, lState->theCurInputPos );
                  bindVariable ( aPlanState, lState->theInputSeq, lState->theOpenWindowsStartPos[0], lState->theCurInputPos );
                  lState->theOpenWindowsStartPos.pop_back();
                  assert ( lState->theOpenWindowsStartPos.empty() );
                  STACK_PUSH ( true, lState );
                }
                ++lState->theCurInputPos;
              }
            } else {
              while ( lState->theInputSeq->containsItem ( lState->theCurInputPos ) ) {
                if ( theStartClause.evaluate ( aPlanState, lState->theInputSeq, lState->theCurInputPos ) ) {
                  if ( !lState->theOpenWindowsStartPos.empty() ) {
                    assert ( lState->theOpenWindowsStartPos.size() == 1 ); //In no case there should be more than 1 position inside
                    theStartClause.bindExtern ( aPlanState, lState->theInputSeq, lState->theOpenWindowsStartPos[0] );
                    theEndClause.bindExtern ( aPlanState, lState->theInputSeq, lState->theCurInputPos -1 );
                    lState->theOpenWindowsStartPos.pop_back();
                    STACK_PUSH ( true, lState );
                  }
                  lState->theOpenWindowsStartPos.push_back ( lState->theCurInputPos );
                }
                ++lState->theCurInputPos;
              }
            }
          }
          break;
          default:
            assert ( false ); //shit that should never happen
        }
        theInputIter->reset ( aPlanState );
      }
      STACK_PUSH ( false, lState );
      STACK_END ( lState );
    }
  } //Namespace flwor
}//Namespace zorba
