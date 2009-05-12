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

namespace zorba
{
namespace flwor
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  WindowVars                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

WindowDef::~WindowDef()
{
}

WindowDef::WindowDef(uint32_t aStartPos) : theStartPos(aStartPos), theEndPos(0)
{
}



WindowVars::WindowVars()
{
}


WindowVars::WindowVars (
    const std::vector<PlanIter_t >& aCurVars,
    const std::vector<PlanIter_t >& aPrevVars,
    const std::vector<PlanIter_t >& aNextVars,
    const std::vector<PlanIter_t >& aPosVars,
    const std::vector<PlanIter_t >& aCurOutVars,
    const std::vector<PlanIter_t >& aPrevOutVars,
    const std::vector<PlanIter_t >& aNextOutVars,
    const std::vector<PlanIter_t >& aPosOutVars)
{
  castIterVector<ForVarIterator>(theCurVars, aCurVars);
  castIterVector<ForVarIterator>(thePrevVars, aPrevVars);
  castIterVector<ForVarIterator>(theNextVars, aNextVars);
  castIterVector<ForVarIterator>(thePosVars, aPosVars);

  castIterVector<ForVarIterator>(theCurOuterVars, aCurOutVars);
  castIterVector<ForVarIterator>(thePrevOuterVars, aPrevOutVars);
  castIterVector<ForVarIterator>(theNextOuterVars, aNextOutVars);
  castIterVector<ForVarIterator>(thePosOuterVars, aPosOutVars);
}


WindowVars::~WindowVars()
{
}


void WindowVars::accept(PlanIterVisitor& v) const
{
  if (!theCurVars.empty())
  {
    v.beginVisitWinCondVariable("CurrentIn", theCurVars);
    v.endVisitWinCondVariable();
  }
  if (!thePrevVars.empty())
  {
    v.beginVisitWinCondVariable("PrevIn", thePrevVars);
    v.endVisitWinCondVariable();
  }
  if (!theNextVars.empty())
  {
    v.beginVisitWinCondVariable("NextIn", theNextVars);
    v.endVisitWinCondVariable();
  }
  if (!thePosVars.empty())
  {
    v.beginVisitWinCondVariable("PosIn", thePosVars);
    v.endVisitWinCondVariable();
  }
}


void WindowVars::bindIntern (
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const uint32_t aPosition ) const
{
  store::Item_t lItem;

  if ( !theCurVars.empty() ) {
    aInputSeq->getItem ( aPosition, lItem );
    bindVariables ( lItem, theCurVars, aPlanState );
  }

  if ( !thePrevVars.empty() ) {
    if ( aPosition > 1 ) {
      aInputSeq->getItem ( aPosition - 1, lItem );
    } else {
      lItem = 0;
    }
    bindVariables ( lItem, thePrevVars, aPlanState );
  }

  if ( !theNextVars.empty() ) {
    if ( aInputSeq->containsItem ( aPosition + 1 ) ) {
      aInputSeq->getItem ( aPosition + 1, lItem );
    } else {
      lItem = 0;
    }
    bindVariables ( lItem, theNextVars, aPlanState );
  }

  if ( !thePosVars.empty() ) {
    store::Item_t lPosItem;
    GENV_ITEMFACTORY->createInteger ( lPosItem, Integer::parseInt ( aPosition ) );
    bindVariables ( lPosItem, thePosVars, aPlanState );
  }
}


void WindowVars::bindExtern (
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const uint32_t aPosition ) const
{
  store::Item_t lItem;
  if ( !theCurOuterVars.empty() ) {
    aInputSeq->getItem ( aPosition, lItem );
    bindVariables ( lItem, theCurOuterVars, aPlanState );
  }

  if ( !thePrevOuterVars.empty() ) {
    if ( aPosition > 1 ) {
      aInputSeq->getItem ( aPosition - 1, lItem );
    } else {
      lItem = 0;
    }
    bindVariables ( lItem, thePrevOuterVars, aPlanState );
  }

  if ( !theNextOuterVars.empty() ) {
    if ( aInputSeq->containsItem ( aPosition + 1 ) ) {
      aInputSeq->getItem ( aPosition + 1, lItem );
    } else {
      lItem = 0;
    }
    bindVariables ( lItem, theNextOuterVars, aPlanState );
  }
  if ( !thePosOuterVars.empty() ) {
    GENV_ITEMFACTORY->createInteger ( lItem, Integer::parseInt ( aPosition ) );
    bindVariables ( lItem, thePosOuterVars, aPlanState );
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  StartClause                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

StartClause::StartClause(
    PlanIter_t aStartClauseIter,
    WindowVars& aWindowVars)
  :
  theStartClauseIter ( aStartClauseIter ),
  theWindowVars ( aWindowVars )
{
}


StartClause::~StartClause()
{
}


void StartClause::accept ( PlanIterVisitor& v ) const
{
  theWindowVars.accept ( v );
  theStartClauseIter->accept ( v );
}


void StartClause::open ( PlanState& aPlanState, uint32_t& aOffset ) const
{
  theStartClauseIter->open ( aPlanState, aOffset );
}


void StartClause::reset ( PlanState& aPlanState ) const
{
  theStartClauseIter->reset ( aPlanState );
}


void StartClause::close ( PlanState& aPlanState ) const
{
  theStartClauseIter->close ( aPlanState );
}


uint32_t StartClause::getStateSizeOfSubtree() const
{
  return theStartClauseIter->getStateSizeOfSubtree();
}


bool StartClause::evaluate(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const uint32_t aPosition) const
{
  theWindowVars.bindIntern ( aPlanState, aInputSeq, aPosition );
  return evalToBool ( theStartClauseIter, aPlanState );
}


void StartClause::bindExtern(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const uint32_t aPosition ) const
{
  theWindowVars.bindExtern ( aPlanState, aInputSeq, aPosition );
}


void StartClause::bindIntern(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const uint32_t aPosition ) const
{
  theWindowVars.bindIntern ( aPlanState, aInputSeq, aPosition );
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  EndClause                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


EndClause::EndClause()
  :
  theEndClauseIter ( NULL ),
  theOnlyEnd(false),
  theHasEndClause ( false )
{
}


EndClause::EndClause (
    PlanIter_t aEndClauseIter,
    WindowVars& aWindowVars,
    bool aOnlyEnd)
  :
  theEndClauseIter ( aEndClauseIter ),
  theWindowVars ( aWindowVars ),
  theOnlyEnd ( aOnlyEnd ),
  theHasEndClause ( true )
{
}


EndClause::~EndClause()
{
}


void EndClause::accept ( PlanIterVisitor& v ) const
{
  //TODO more output
  if ( theHasEndClause ) {
    theWindowVars.accept ( v );
    theEndClauseIter->accept ( v );
  }
}


void EndClause::open ( PlanState& aPlanState, uint32_t& aOffset ) const
{
  if ( theHasEndClause )
    theEndClauseIter->open ( aPlanState, aOffset );
}


void EndClause::reset ( PlanState& aPlanState ) const
{
  if ( theHasEndClause )
    theEndClauseIter->reset ( aPlanState );
}


void EndClause::close ( PlanState& aPlanState ) const
{
  if ( theHasEndClause )
    theEndClauseIter->close ( aPlanState );
}


uint32_t EndClause::getStateSizeOfSubtree() const
{
  if ( theHasEndClause )
    return theEndClauseIter->getStateSizeOfSubtree();
  else
    return 0;
}


bool EndClause::evaluate ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const
{
  theWindowVars.bindIntern ( aPlanState, aInputSeq, aPosition );
  return evalToBool ( theEndClauseIter, aPlanState );
}


void EndClause::bindIntern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const
{
  theWindowVars.bindIntern ( aPlanState, aInputSeq, aPosition );
}


void EndClause::bindExtern ( PlanState& aPlanState, const store::TempSeq_t& aInputSeq, const uint32_t aPosition ) const
{
  theWindowVars.bindExtern ( aPlanState, aInputSeq, aPosition );
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  WindowState                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

WindowState::WindowState() : theInputSeq ( NULL ) , theCurInputPos ( 1 )
{
}


WindowState::~WindowState()
{
}


void WindowState::init ( PlanState& aState )
{
  PlanIteratorState::init ( aState );
  theCurInputPos = 1;
  theInputSeq = NULL;
}


void WindowState::reset ( PlanState& aPlanState )
{
  PlanIteratorState::reset ( aPlanState );
  tupleReset();
}


void WindowState::tupleReset ( )
{
  theCurInputPos = 1;
  theInputSeq = NULL;
  theOpenWindows.clear();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  WindowIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

const uint32_t WindowIterator::MAX_HISTORY = 2147483647; //TODO should be set platform dependent, but somebody hat comment out everything in platform.h!

WindowIterator::WindowIterator (
    const QueryLoc& loc,
    WindowType windowType,
    PlanIter_t tupleIter,
    PlanIter_t domainIterator,
    const store::Item_t& varName,
    const std::vector<PlanIter_t >& varRefs,
    StartClause& startClause,
    EndClause& endClause,
    bool lazyEval,
    uint32_t maxNeededHistory)
  :
  Batcher<WindowIterator>(loc),
  theWindowType(windowType),
  theTupleIter(tupleIter),
  theInputIter(domainIterator),
  theVarName(varName),
  theStartClause(startClause),
  theEndClause(endClause),
  theLazyEval(lazyEval),
  theMaxNeededHistory(maxNeededHistory)
{
  castIterVector<LetVarIterator>(theVarRefs, varRefs);
}


WindowIterator::~WindowIterator()
{
}


uint32_t WindowIterator::getStateSize() const
{
  return StateTraitsImpl<WindowState>::getStateSize();
}


uint32_t WindowIterator::getStateSizeOfSubtree() const
{
  int32_t lSize = this->getStateSize();
  lSize += theTupleIter->getStateSizeOfSubtree();
  lSize += theInputIter->getStateSizeOfSubtree();
  lSize += theStartClause.getStateSizeOfSubtree();
  lSize += theEndClause.getStateSizeOfSubtree();
  return lSize;
}


void WindowIterator::openImpl ( PlanState& aPlanState, uint32_t& aOffset )
{
  StateTraitsImpl<WindowState>::createState ( aPlanState, this->stateOffset, aOffset );
  theTupleIter->open ( aPlanState, aOffset );
  theInputIter->open ( aPlanState, aOffset );
  theStartClause.open ( aPlanState, aOffset );
  theEndClause.open ( aPlanState, aOffset );
}


void WindowIterator::resetImpl ( PlanState& aPlanState ) const
{
  WindowState* lState = StateTraitsImpl<WindowState>::getState ( aPlanState, this->stateOffset );
  lState->reset ( aPlanState );

  theTupleIter->reset ( aPlanState );
  theInputIter->reset ( aPlanState );
  theStartClause.reset ( aPlanState );
  theEndClause.reset ( aPlanState );
}


void WindowIterator::closeImpl ( PlanState& aPlanState )
{
  theTupleIter->close ( aPlanState );
  theInputIter->close ( aPlanState );
  theStartClause.close ( aPlanState );
  theEndClause.close ( aPlanState );
  StateTraitsImpl<WindowState>::destroyState ( aPlanState, this->stateOffset );
}


void WindowIterator::accept ( PlanIterVisitor& v ) const
{
  v.beginVisit(*this);

  v.beginVisitWindowVariable(theVarName->getStringValue()->str(), theVarRefs);

  theInputIter->accept(v);

  v.endVisitWindowVariable();

  theStartClause.accept(v);
  theEndClause.accept(v);

  theTupleIter->accept(v);

  v.endVisit(*this);
}


void WindowIterator::bindVariable(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const uint32_t aStartPos,
    const uint32_t aEndPos ) const
{
  for ( std::vector<LetVarIter_t>::const_iterator lVarIter = theVarRefs.begin();
        lVarIter != theVarRefs.end();
        ++lVarIter)
  {
    store::Iterator_t lIter = aInputSeq->getIterator ( aStartPos, aEndPos, true );
    lIter->open(); //FIXME We need to close the iterator! So far this only works because close is a empty function
    ( *lVarIter )->bind ( lIter  , aPlanState );
  }
}

/**
 * The theMaxNeededHistory has to be determined by the compiler e.g. for $seq[$startPos - 4] cases
 */
void WindowIterator::doGarbageCollection(WindowState* lState) const
{
  if (theMaxNeededHistory != MAX_HISTORY)
  {
    if ( lState->theOpenWindows.empty() ) {
      if ( lState->theCurInputPos > theMaxNeededHistory )
        lState->theInputSeq->purgeUpTo ( lState->theCurInputPos - theMaxNeededHistory );
    } else {
      int32_t lPurgeTo = lState->theOpenWindows.front().theStartPos - theMaxNeededHistory;
      if ( lPurgeTo > 0 )
        lState->theInputSeq->purgeUpTo ( lPurgeTo );
    }
  }
}


bool WindowIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const
{
  WindowState* lState;
  DEFAULT_STACK_INIT ( WindowState, lState, aPlanState );

  while ( consumeNext ( aResult, theTupleIter, aPlanState ) )
  {
    lState->theInputSeq = GENV_STORE.createTempSeq(new PlanIteratorWrapper(theInputIter, aPlanState), false, theLazyEval);

    //Its clever to switch quite early to avoid a lot of if-else statements
    if ( theWindowType == WindowIterator::SLIDING )
    {
      while ( lState->theInputSeq->containsItem ( lState->theCurInputPos ) )
      {
        if (theStartClause.evaluate(aPlanState,
                                    lState->theInputSeq,
                                    lState->theCurInputPos))
        {
          lState->theOpenWindows.push_back ( WindowDef(lState->theCurInputPos));
        }

        lState->theCurWindow = lState->theOpenWindows.begin();

        while ( lState->theCurWindow != lState->theOpenWindows.end() )
        {
          theStartClause.bindIntern(aPlanState,
                                    lState->theInputSeq,
                                    lState->theCurWindow->theStartPos);

          uint32_t lCurPos = lState->theCurInputPos;
          if ( theEndClause.evaluate(aPlanState,
                                     lState->theInputSeq,
                                     lCurPos))
          {

        	lState->theCurWindow->theEndPos = lCurPos;

          }
          ++ ( lState->theCurWindow );

        }

        lState->theCurWindow = lState->theOpenWindows.begin();

        while ( lState->theCurWindow != lState->theOpenWindows.end() && lState->theCurWindow->theEndPos != 0)
        {

            theStartClause.bindExtern(aPlanState,
                                      lState->theInputSeq,
                                      lState->theCurWindow->theStartPos);

            theEndClause.bindExtern(aPlanState,
                                    lState->theInputSeq,
                                    lState->theCurWindow->theEndPos);

            bindVariable(aPlanState,
                         lState->theInputSeq,
                         lState->theCurWindow->theStartPos,
                         lState->theCurWindow->theEndPos);

            lState->theCurWindow = lState->theOpenWindows.erase(lState->theCurWindow);
            doGarbageCollection ( lState );

            STACK_PUSH ( true, lState );
            ++ ( lState->theCurWindow );
          }
			++lState->theCurInputPos;
        }
    }
    else //Tumpling window
    {
      if ( theEndClause.theHasEndClause )
      {
        //Doing this switch now also avoids further overhad
        while (lState->theInputSeq->containsItem(lState->theCurInputPos))
        {
          if (lState->theOpenWindows.empty() &&
              theStartClause.evaluate(aPlanState,
                                      lState->theInputSeq,
                                      lState->theCurInputPos))
          {
            theStartClause.bindExtern(aPlanState,
                                      lState->theInputSeq,
                                      lState->theCurInputPos );

            lState->theOpenWindows.push_back(lState->theCurInputPos);
          }

          if ( !lState->theOpenWindows.empty() &&
               theEndClause.evaluate(aPlanState,
                                     lState->theInputSeq,
                                     lState->theCurInputPos))
          {
            theEndClause.bindExtern(aPlanState,
                                    lState->theInputSeq,
                                    lState->theCurInputPos);

            bindVariable(aPlanState,
                         lState->theInputSeq,
                         lState->theOpenWindows[0].theStartPos,
                         lState->theCurInputPos);

            lState->theOpenWindows.pop_back();

            assert ( lState->theOpenWindows.empty() );

            doGarbageCollection ( lState );

            STACK_PUSH ( true, lState );
          }
          ++lState->theCurInputPos;
        }
      }
      else
      {
        while ( lState->theInputSeq->containsItem ( lState->theCurInputPos ) )
        {
          if ( theStartClause.evaluate(aPlanState,
                                       lState->theInputSeq,
                                       lState->theCurInputPos))
          {
            if ( !lState->theOpenWindows.empty() )
            {
              assert ( lState->theOpenWindows.size() == 1 ); //In no case there should be more than 1 position inside
              theStartClause.bindExtern(aPlanState,
                                        lState->theInputSeq,
                                        lState->theOpenWindows[0].theStartPos);

              bindVariable(aPlanState,
                           lState->theInputSeq,
                           lState->theOpenWindows[0].theStartPos,
                           lState->theCurInputPos  -1);

              lState->theOpenWindows.pop_back();

              doGarbageCollection ( lState );

              STACK_PUSH ( true, lState );
            }

            lState->theOpenWindows.push_back ( lState->theCurInputPos );
          }

          ++lState->theCurInputPos;
        }
      }
    }

    //Check if we have open windows
    while(!lState->theOpenWindows.empty() && (!theEndClause.theOnlyEnd))
    {
      bindVariable(aPlanState,
                   lState->theInputSeq,
                   lState->theOpenWindows[0].theStartPos,
                   lState->theCurInputPos - 1);

      theEndClause.bindExtern(aPlanState,
                              lState->theInputSeq,
                              lState->theCurInputPos-1);

      lState->theCurWindow = lState->theOpenWindows.erase(lState->theOpenWindows.begin());

      STACK_PUSH(true, lState);
    }

    theInputIter->reset(aPlanState);
    lState->tupleReset();
  }
  STACK_PUSH ( false, lState );
  STACK_END ( lState );
  std::cout << "END" << std::endl;
}

  } //Namespace flwor
}//Namespace zorba
