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
#include "stdafx.h"

#include "system/globalenv.h"

#include "runtime/core/gflwor/window_iterator.h"
#include "runtime/core/gflwor/common.h"
#include "runtime/core/var_iterators.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"


namespace zorba
{
namespace flwor
{

SERIALIZABLE_CLASS_VERSIONS(StartClause)

SERIALIZABLE_CLASS_VERSIONS(EndClause)

SERIALIZABLE_CLASS_VERSIONS(WindowIterator)

SERIALIZABLE_CLASS_VERSIONS(WindowVars)


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  WindowVars                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
WindowVars::WindowVars()
{
}


/***************************************************************************//**
  Constructor
********************************************************************************/
WindowVars::WindowVars (
    const std::vector<PlanIter_t >& aCurVars,
    const std::vector<PlanIter_t >& aPrevVars,
    const std::vector<PlanIter_t >& aNextVars,
    const std::vector<PlanIter_t >& aPosVars,
    const std::vector<PlanIter_t >& aCurOutVars,
    const std::vector<PlanIter_t >& aPrevOutVars,
    const std::vector<PlanIter_t >& aNextOutVars,
    const std::vector<PlanIter_t >& aPosOutVars)
:
  theCurVars(aCurVars),
  thePrevVars(aPrevVars),
  theNextVars(aNextVars),
  thePosVars(aPosVars),
  theCurOuterVars(aCurOutVars),
  thePrevOuterVars(aPrevOutVars),
  theNextOuterVars(aNextOutVars),
  thePosOuterVars(aPosOutVars)
{
}


/***************************************************************************//**
  Destructor
********************************************************************************/
WindowVars::~WindowVars()
{
}


/***************************************************************************//**

********************************************************************************/
void WindowVars::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theCurVars;
  ar & thePrevVars;
  ar & theNextVars;
  ar & thePosVars;

  ar & theCurOuterVars;
  ar & thePrevOuterVars;
  ar & theNextOuterVars;
  ar & thePosOuterVars;
}


/***************************************************************************//**

********************************************************************************/
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


/*******************************************************************************
  Binds the variables inside the window clause.

  @param aPlanState The PlanState
  @param aInputSeq The underlying input sequence
  @param aPosition The position of the current item within the input sequence
                   (counting starts with 1).
********************************************************************************/
void WindowVars::bindIntern(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const ulong aPosition) const
{
  store::Item_t lItem;

  if (!theCurVars.empty())
  {
    aInputSeq->getItem(xs_integer(aPosition), lItem);
    bindVariables(lItem, theCurVars, aPlanState);
  }

  if (!thePrevVars.empty())
  {
    if (aPosition > 1)
    {
      aInputSeq->getItem(xs_integer(aPosition - 1), lItem);
    }
    else
    {
      lItem = 0;
    }

    bindVariables(lItem, thePrevVars, aPlanState);
  }

  if (!theNextVars.empty())
  {
    if (aInputSeq->containsItem(xs_integer(aPosition + 1)))
    {
      aInputSeq->getItem(xs_integer(aPosition + 1), lItem);
    }
    else
    {
      lItem = 0;
    }

    bindVariables(lItem, theNextVars, aPlanState);
  }

  if (!thePosVars.empty())
  {
    store::Item_t lPosItem;
    GENV_ITEMFACTORY->createInteger(lPosItem, xs_integer(aPosition));
    bindVariables(lPosItem, thePosVars, aPlanState);
  }
}


/*******************************************************************************
  Binds the variables outside the window clause.

  @param aPlanState The PlanState
  @param aInputSeq The underlying input sequence
  @param aPosition The position of the current item within the input sequence
                   (counting starts with 1).
********************************************************************************/
void WindowVars::bindExtern(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const ulong aPosition) const
{
  store::Item_t lItem;

  if (!theCurOuterVars.empty())
  {
    aInputSeq->getItem(xs_integer(aPosition), lItem);
    bindVariables(lItem, theCurOuterVars, aPlanState);
  }

  if (!thePrevOuterVars.empty())
  {
    if (aPosition > 1)
    {
      aInputSeq->getItem(xs_integer(aPosition - 1), lItem);
    }
    else
    {
      lItem = 0;
    }

    bindVariables(lItem, thePrevOuterVars, aPlanState);
  }

  if (!theNextOuterVars.empty())
  {
    if (aInputSeq->containsItem(xs_integer(aPosition + 1)))
    {
      aInputSeq->getItem(xs_integer(aPosition + 1), lItem);
    }
    else
    {
      lItem = 0;
    }

    bindVariables(lItem, theNextOuterVars, aPlanState);
  }

  if (!thePosOuterVars.empty())
  {
    GENV_ITEMFACTORY->createInteger(lItem, Integer(aPosition));
    bindVariables(lItem, thePosOuterVars, aPlanState);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  StartClause                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
StartClause::StartClause(
    PlanIter_t aStartClauseIter,
    WindowVars& aWindowVars)
  :
  theStartClauseIter(aStartClauseIter),
  theWindowVars(aWindowVars)
{
}


/***************************************************************************//**

********************************************************************************/
StartClause::~StartClause()
{
}


/***************************************************************************//**

********************************************************************************/
uint32_t StartClause::getStateSizeOfSubtree() const
{
  return theStartClauseIter->getStateSizeOfSubtree();
}


/***************************************************************************//**

********************************************************************************/
void StartClause::accept(PlanIterVisitor& v) const
{
  theWindowVars.accept(v);
  theStartClauseIter->accept(v);
}


/***************************************************************************//**

********************************************************************************/
void StartClause::open(PlanState& aPlanState, uint32_t& aOffset) const
{
  theStartClauseIter->open(aPlanState, aOffset);
}


/***************************************************************************//**

********************************************************************************/
void StartClause::reset(PlanState& aPlanState) const
{
  theStartClauseIter->reset(aPlanState);
}


/***************************************************************************//**

********************************************************************************/
void StartClause::close(PlanState& aPlanState) const
{
  theStartClauseIter->close(aPlanState);
}


/***************************************************************************//**
  Evaluate the start condition expr on the item that is pointed to by the given
  position within the temp sequence that materializes the result of the domain
  expr.
********************************************************************************/
bool StartClause::evaluate(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const ulong aPosition) const
{
  theWindowVars.bindIntern(aPlanState, aInputSeq, aPosition);

  return evalToBool(theStartClauseIter, aPlanState);
}


/***************************************************************************//**
  Bind the references to the external start-condition variables to the values
  corresponding to the item that is pointed to by the given position within
  the temp sequence that materializes the result of the domain expr.
********************************************************************************/
void StartClause::bindExtern(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const ulong aPosition) const
{
  theWindowVars.bindExtern(aPlanState, aInputSeq, aPosition);
}


/***************************************************************************//**

********************************************************************************/
void StartClause::bindIntern(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const ulong aPosition) const
{
  theWindowVars.bindIntern(aPlanState, aInputSeq, aPosition);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  EndClause                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  If the EndClause is missing in the case of a tumbling window, this constructor
  should be used.
********************************************************************************/
EndClause::EndClause()
  :
  theEndClauseIter(NULL),
  theOnlyEnd(false),
  theHasEndClause(false)
{
}


/***************************************************************************//**

********************************************************************************/
EndClause::EndClause(
    PlanIter_t aEndClauseIter,
    WindowVars& aWindowVars,
    bool aOnlyEnd)
  :
  theEndClauseIter(aEndClauseIter),
  theWindowVars(aWindowVars),
  theOnlyEnd(aOnlyEnd),
  theHasEndClause(true)
{
}


/***************************************************************************//**

********************************************************************************/
EndClause::~EndClause()
{
}


/***************************************************************************//**

********************************************************************************/
uint32_t EndClause::getStateSizeOfSubtree() const
{
  if (theHasEndClause)
    return theEndClauseIter->getStateSizeOfSubtree();
  else
    return 0;
}


/***************************************************************************//**

********************************************************************************/
void EndClause::accept(PlanIterVisitor& v) const
{
  //TODO more output
  if (theHasEndClause)
  {
    theWindowVars.accept(v);
    theEndClauseIter->accept(v);
  }
}


/***************************************************************************//**

********************************************************************************/
void EndClause::open(PlanState& aPlanState, uint32_t& aOffset) const
{
  if (theHasEndClause)
    theEndClauseIter->open(aPlanState, aOffset);
}


/***************************************************************************//**

********************************************************************************/
void EndClause::reset(PlanState& aPlanState) const
{
  if (theHasEndClause)
    theEndClauseIter->reset(aPlanState);
}


/***************************************************************************//**

********************************************************************************/
void EndClause::close(PlanState& aPlanState) const
{
  if (theHasEndClause)
    theEndClauseIter->close(aPlanState);
}


/***************************************************************************//**

********************************************************************************/
bool EndClause::evaluate(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const ulong aPosition) const
{
  theWindowVars.bindIntern(aPlanState, aInputSeq, aPosition);

  return evalToBool(theEndClauseIter, aPlanState);
}


/***************************************************************************//**

********************************************************************************/
void EndClause::bindIntern(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const ulong aPosition) const
{
  theWindowVars.bindIntern(aPlanState, aInputSeq, aPosition);
}


/***************************************************************************//**

********************************************************************************/
void EndClause::bindExtern(
    PlanState& aPlanState,
    const store::TempSeq_t& aInputSeq,
    const ulong aPosition) const
{
  theWindowVars.bindExtern(aPlanState, aInputSeq, aPosition);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  WindowDef                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


WindowDef::~WindowDef()
{
}

WindowDef::WindowDef(ulong aStartPos) : theStartPos(aStartPos), theEndPos(0)
{
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  WindowState                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

WindowState::WindowState() : theDomainSeq (NULL) , theCurInputPos(1)
{
}


WindowState::~WindowState()
{
}


void WindowState::init(PlanState& aState)
{
  PlanIteratorState::init(aState);
  theCurInputPos = 1;
  theDomainSeq = NULL;
}


void WindowState::reset(PlanState& aPlanState)
{
  PlanIteratorState::reset(aPlanState);
  theCurInputPos = 1;
  theDomainSeq = NULL;
  theOpenWindows.clear();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  WindowIterator                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

const ulong WindowIterator::MAX_HISTORY = 2147483647; //TODO should be set platform dependent, but somebody hat comment out everything in platform.h!


/***************************************************************************//**

********************************************************************************/
WindowIterator::WindowIterator(
    static_context* sctx,
    const QueryLoc& loc,
    WindowType windowType,
    PlanIter_t tupleIter,
    PlanIter_t domainIterator,
    store::Item* varName,
    const std::vector<PlanIter_t>& varRefs,
    StartClause& startClause,
    EndClause& endClause,
    bool lazyEval,
    ulong maxNeededHistory)
  :
  Batcher<WindowIterator>(sctx, loc),
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


/***************************************************************************//**

********************************************************************************/
WindowIterator::~WindowIterator()
{
}


/***************************************************************************//**

********************************************************************************/
void WindowIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (Batcher<WindowIterator>*)this);
  SERIALIZE_ENUM(WindowType, theWindowType);
  ar & theTupleIter;
  ar & theInputIter;
  ar & theVarName;
  ar & theVarRefs;
  ar & theStartClause;
  ar & theEndClause;
  ar & theLazyEval;

  SERIALIZE_ULONG(theMaxNeededHistory);
}


/***************************************************************************//**

********************************************************************************/
uint32_t WindowIterator::getStateSize() const
{
  return StateTraitsImpl<WindowState>::getStateSize();
}


/***************************************************************************//**

********************************************************************************/
uint32_t WindowIterator::getStateSizeOfSubtree() const
{
  int32_t lSize = this->getStateSize();
  lSize += theTupleIter->getStateSizeOfSubtree();
  lSize += theInputIter->getStateSizeOfSubtree();
  lSize += theStartClause.getStateSizeOfSubtree();
  lSize += theEndClause.getStateSizeOfSubtree();
  return lSize;
}


/***************************************************************************//**

********************************************************************************/
void WindowIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  v.beginVisitWindowVariable(theVarName->getStringValue().str(), theVarRefs);

  theInputIter->accept(v);

  v.endVisitWindowVariable();

  theStartClause.accept(v);
  theEndClause.accept(v);

  theTupleIter->accept(v);

  v.endVisit(*this);
}


/***************************************************************************//**

********************************************************************************/
void WindowIterator::openImpl(PlanState& aPlanState, uint32_t& aOffset)
{
  StateTraitsImpl<WindowState>::createState(aPlanState, theStateOffset, aOffset);

  theTupleIter->open(aPlanState, aOffset);
  theInputIter->open(aPlanState, aOffset);

  theStartClause.open(aPlanState, aOffset);
  theEndClause.open(aPlanState, aOffset);
}


/***************************************************************************//**

********************************************************************************/
void WindowIterator::resetImpl(PlanState& aPlanState) const
{
  WindowState* lState = StateTraitsImpl<WindowState>::getState(aPlanState,
                                                               theStateOffset);
  lState->reset(aPlanState);

  theTupleIter->reset(aPlanState);
  theInputIter->reset(aPlanState);
  theStartClause.reset(aPlanState);
  theEndClause.reset(aPlanState);
}


/***************************************************************************//**

********************************************************************************/
void WindowIterator::closeImpl(PlanState& aPlanState)
{
  theTupleIter->close(aPlanState);
  theInputIter->close(aPlanState);
  theStartClause.close(aPlanState);
  theEndClause.close(aPlanState);
  StateTraitsImpl<WindowState>::destroyState(aPlanState, theStateOffset);
}


/***************************************************************************//**
  Bind the window var to the items between the given starting and ending items
  of the domain sequence.
********************************************************************************/
void WindowIterator::bindVariable(
    PlanState& aPlanState,
    store::TempSeq_t& aInputSeq,
    ulong aStartPos,
    ulong aEndPos) const
{
  xs_integer const lStartPos( aStartPos );
  xs_integer const lEndPos( aEndPos );

  for (std::vector<LetVarIter_t>::const_iterator lVarIter = theVarRefs.begin();
       lVarIter != theVarRefs.end();
       ++lVarIter)
  {
    (*lVarIter)->bind(aInputSeq, aPlanState, lStartPos, lEndPos);
  }
}


/***************************************************************************//**
  The theMaxNeededHistory has to be determined by the compiler e.g. for
  $seq[$startPos - 4] cases
********************************************************************************/
void WindowIterator::doGarbageCollection(WindowState* lState) const
{
  if (theMaxNeededHistory != MAX_HISTORY)
  {
    if (lState->theOpenWindows.empty())
    {
      if (lState->theCurInputPos > theMaxNeededHistory)
        lState->theDomainSeq->purgeUpTo(xs_integer(lState->theCurInputPos - theMaxNeededHistory));
    }
    else
    {
      int32_t lPurgeTo = lState->theOpenWindows.front().theStartPos - theMaxNeededHistory;
      if (lPurgeTo > 0)
        lState->theDomainSeq->purgeUpTo(xs_integer(lPurgeTo));
    }
  }
}


/***************************************************************************//**

********************************************************************************/
bool WindowIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  store::Iterator_t iterator;
  WindowState* lState;
  DEFAULT_STACK_INIT(WindowState, lState, aPlanState);

  // Pull the next tuple from the input stream
  while (consumeNext(aResult, theTupleIter, aPlanState))
  {
    // Create the temp sequence where to materialize the result of the domain
    // expr (lazily if theLazyEval flag is true).
    iterator = new PlanIteratorWrapper(theInputIter, aPlanState);
    lState->theDomainSeq = GENV_STORE.createTempSeq(iterator, theLazyEval);

    // Its clever to switch quite early to avoid a lot of if-else statements
    if (theWindowType == WindowIterator::SLIDING)
    {
      // Get the next item from the domain sequence
      // TODO: can the xs_integer be hoisted?
      while (lState->theDomainSeq->containsItem(xs_integer(lState->theCurInputPos)))
      {
        // If the current item satisfies the start condition, create a candidate
        // window starting at the current domain item.
        if (theStartClause.evaluate(aPlanState,
                                    lState->theDomainSeq,
                                    lState->theCurInputPos))
        {
          lState->theOpenWindows.push_back(WindowDef(lState->theCurInputPos));
        }

        // For each candidate window, check if the current domain item satisfies
        // the end condition. Notice that before evaluating the end condition
        // expr, we must rebind the internal vars of the start condition, because
        // those varaibles may be refrenced in the end cond expr.
        lState->theCurWindow = lState->theOpenWindows.begin();

        while ( lState->theCurWindow != lState->theOpenWindows.end() )
        {
          if (lState->theCurWindow->theEndPos == 0)
          {
            theStartClause.bindIntern(aPlanState,
                                      lState->theDomainSeq,
                                      lState->theCurWindow->theStartPos);

            ulong lCurPos = lState->theCurInputPos;
            if ( theEndClause.evaluate(aPlanState,
                                       lState->theDomainSeq,
                                       lCurPos))
            {
              lState->theCurWindow->theEndPos = lCurPos;
            }
          }

          ++lState->theCurWindow;
        }

        // Try to return closed windows to the consumer iterator. Notice that
        // windows must be sorted according to the position of their starting
        // items in the domain sequence. So, we can return a closed window only
        // if it appears as the first window in lState->theOpenWindows.
        lState->theCurWindow = lState->theOpenWindows.begin();

        while (!lState->theOpenWindows.empty())
        {
          if (lState->theCurWindow->theEndPos != 0)
          {
            // The current window is closed and its starting item is before the
            // stating items of all other windows (open or closed) in the domain
            // sequence. So, (a) bind the window var and the external vars of 
            // the start and end conditions, (b) remove the window from the set
            // of candidate windows, (c) purge from the domain temp seq any item
            // that we know for sure they will not be needed in subsequent 
            // evaluations of the start and/or end conditions, and (d) return to
            // the caller a new tuple that consists of the current input tuple
            // augmented with one column per variable that was bound in this step.
            theStartClause.bindExtern(aPlanState,
                                      lState->theDomainSeq,
                                      lState->theCurWindow->theStartPos);

            theEndClause.bindExtern(aPlanState,
                                    lState->theDomainSeq,
                                    lState->theCurWindow->theEndPos);

            bindVariable(aPlanState,
                         lState->theDomainSeq,
                         lState->theCurWindow->theStartPos,
                         lState->theCurWindow->theEndPos);

            lState->theCurWindow = lState->theOpenWindows.erase(lState->theCurWindow);
            doGarbageCollection(lState);

            STACK_PUSH(true, lState);
          }
          else
          {
            break;
          }
        }

        ++lState->theCurInputPos;
      }
    }
    else //Tumpling window
    {
      // Doing this switch now also avoids further overhad
      if (theEndClause.theHasEndClause)
      {
        // TODO: can the xs_integer be hoisted?
        while (lState->theDomainSeq->containsItem(xs_integer(lState->theCurInputPos)))
        {
          if (lState->theOpenWindows.empty() &&
              theStartClause.evaluate(aPlanState,
                                      lState->theDomainSeq,
                                      lState->theCurInputPos))
          {
            theStartClause.bindExtern(aPlanState,
                                      lState->theDomainSeq,
                                      lState->theCurInputPos);

            lState->theOpenWindows.push_back(lState->theCurInputPos);
          }

          if ( !lState->theOpenWindows.empty() &&
               theEndClause.evaluate(aPlanState,
                                     lState->theDomainSeq,
                                     lState->theCurInputPos))
          {
            theEndClause.bindExtern(aPlanState,
                                    lState->theDomainSeq,
                                    lState->theCurInputPos);

            bindVariable(aPlanState,
                         lState->theDomainSeq,
                         lState->theOpenWindows[0].theStartPos,
                         lState->theCurInputPos);

            lState->theOpenWindows.pop_back();

            assert(lState->theOpenWindows.empty());

            doGarbageCollection(lState);

            STACK_PUSH(true, lState);
          }
          ++lState->theCurInputPos;
        }
      }
      else
      {
        // TODO: can the xs_integer be hoisted?
        while (lState->theDomainSeq->containsItem(xs_integer(lState->theCurInputPos)))
        {
          if (theStartClause.evaluate(aPlanState,
                                      lState->theDomainSeq,
                                      lState->theCurInputPos))
          {
            if (!lState->theOpenWindows.empty())
            {
              //In no case there should be more than 1 position inside
              assert(lState->theOpenWindows.size() == 1);

              theStartClause.bindExtern(aPlanState,
                                        lState->theDomainSeq,
                                        lState->theOpenWindows[0].theStartPos);

              bindVariable(aPlanState,
                           lState->theDomainSeq,
                           lState->theOpenWindows[0].theStartPos,
                           lState->theCurInputPos  -1);

              lState->theOpenWindows.pop_back();

              doGarbageCollection(lState);

              STACK_PUSH(true, lState);
            }

            lState->theOpenWindows.push_back(lState->theCurInputPos);
          }

          ++lState->theCurInputPos;
        }
      }
    }

    // Check if we have open and/or closed windows
    lState->theCurWindow = lState->theOpenWindows.begin();

    while (lState->theCurWindow != lState->theOpenWindows.end())
    {
      if (!theEndClause.theOnlyEnd || lState->theCurWindow->theEndPos != 0)
      {
        if (lState->theCurWindow->theEndPos == 0)
          lState->theCurWindow->theEndPos = lState->theCurInputPos - 1;

        bindVariable(aPlanState,
                     lState->theDomainSeq,
                     lState->theOpenWindows[0].theStartPos,
                     lState->theCurWindow->theEndPos);

        theStartClause.bindExtern(aPlanState,
                                  lState->theDomainSeq,
                                  lState->theOpenWindows[0].theStartPos);

        theEndClause.bindExtern(aPlanState,
                                lState->theDomainSeq,
                                lState->theCurWindow->theEndPos);

        lState->theCurWindow = lState->theOpenWindows.erase(lState->theCurWindow);

        STACK_PUSH(true, lState);
      }
      else
      {
        ++lState->theCurWindow;
      }
    }

    theInputIter->reset(aPlanState);
    lState->reset(aPlanState);
  }

  STACK_PUSH(false, lState);
  STACK_END(lState);
}

  } //Namespace flwor
}//Namespace zorba
/* vim:set et sw=2 ts=2: */
