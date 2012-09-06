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
    const std::vector<PlanIter_t >& curVars,
    const std::vector<PlanIter_t >& prevVars,
    const std::vector<PlanIter_t >& nextVars,
    const std::vector<PlanIter_t >& posVars,
    const std::vector<PlanIter_t >& curOutVars,
    const std::vector<PlanIter_t >& prevOutVars,
    const std::vector<PlanIter_t >& nextOutVars,
    const std::vector<PlanIter_t >& posOutVars)
:
  theCurVars(curVars),
  thePrevVars(prevVars),
  theNextVars(nextVars),
  thePosVars(posVars),
  theCurOuterVars(curOutVars),
  thePrevOuterVars(prevOutVars),
  theNextOuterVars(nextOutVars),
  thePosOuterVars(posOutVars)
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
void WindowVars::accept(PlanIterVisitor& v, bool startClause) const
{
  zstring varName;

  if (startClause)
    varName = "start-";
  else
    varName = "end-";

  if (!theCurVars.empty())
  {
    varName += "CurrentIn";
    v.beginVisitWinCondVariable(varName, theCurVars);
    v.endVisitWinCondVariable();
  }

  if (!thePrevVars.empty())
  {
    varName += "PrevIn";
    v.beginVisitWinCondVariable(varName, thePrevVars);
    v.endVisitWinCondVariable();
  }

  if (!theNextVars.empty())
  {
    varName += "NextIn";
    v.beginVisitWinCondVariable(varName, theNextVars);
    v.endVisitWinCondVariable();
  }

  if (!thePosVars.empty())
  {
    varName += "PosIn";
    v.beginVisitWinCondVariable(varName, thePosVars);
    v.endVisitWinCondVariable();
  }

  if (!theCurOuterVars.empty())
  {
    varName += "CurrentOut";
    v.beginVisitWinCondVariable(varName, theCurOuterVars);
    v.endVisitWinCondVariable();
  }

  if (!thePrevOuterVars.empty())
  {
    varName += "PrevOut";
    v.beginVisitWinCondVariable(varName, thePrevOuterVars);
    v.endVisitWinCondVariable();
  }

  if (!theNextOuterVars.empty())
  {
    varName += "NextOut";
    v.beginVisitWinCondVariable(varName, theNextOuterVars);
    v.endVisitWinCondVariable();
  }

  if (!thePosOuterVars.empty())
  {
    varName += "PosOut";
    v.beginVisitWinCondVariable(varName, thePosOuterVars);
    v.endVisitWinCondVariable();
  }
}


/*******************************************************************************
  Binds the variables inside the window clause.

  @param planState The PlanState
  @param aInputSeq The underlying input sequence
  @param aPosition The position of the current item within the input sequence
                   (counting starts with 1).
********************************************************************************/
void WindowVars::bindIntern(
    PlanState& planState,
    const store::TempSeq_t& inputSeq,
    const ulong pos) const
{
  store::Item_t item;

  if (!theCurVars.empty())
  {
    inputSeq->getItem(xs_integer(pos), item);

    bindVariables(item, theCurVars, planState);
  }

  if (!thePrevVars.empty())
  {
    if (pos > 1)
      inputSeq->getItem(xs_integer(pos - 1), item);
    else
      item = NULL;

    bindVariables(item, thePrevVars, planState);
  }

  if (!theNextVars.empty())
  {
    inputSeq->getItem(xs_integer(pos + 1), item);

    bindVariables(item, theNextVars, planState);
  }

  if (!thePosVars.empty())
  {
    GENV_ITEMFACTORY->createInteger(item, xs_integer(pos));

    bindVariables(item, thePosVars, planState);
  }
}


/*******************************************************************************
  Binds the variables outside the window clause.

  @param planState The PlanState
  @param inputSeq The underlying input sequence
  @param pos The position of the current item within the input sequence
                   (counting starts with 1).
********************************************************************************/
void WindowVars::bindExtern(
    PlanState& planState,
    const store::TempSeq_t& inputSeq,
    const ulong pos) const
{
  store::Item_t item;

  if (!theCurOuterVars.empty())
  {
    inputSeq->getItem(xs_integer(pos), item);

    bindVariables(item, theCurOuterVars, planState);
  }

  if (!thePrevOuterVars.empty())
  {
    if (pos > 1)
      inputSeq->getItem(xs_integer(pos - 1), item);
    else
      item = NULL;

    bindVariables(item, thePrevOuterVars, planState);
  }

  if (!theNextOuterVars.empty())
  {
    inputSeq->getItem(xs_integer(pos + 1), item);

    bindVariables(item, theNextOuterVars, planState);
  }

  if (!thePosOuterVars.empty())
  {
    GENV_ITEMFACTORY->createInteger(item, Integer(pos));

    bindVariables(item, thePosOuterVars, planState);
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


void StartClause::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theStartClauseIter;
  ar & theWindowVars;
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
  theWindowVars.accept(v, true);
  theStartClauseIter->accept(v);
}


/***************************************************************************//**

********************************************************************************/
void StartClause::open(PlanState& planState, uint32_t& aOffset) const
{
  theStartClauseIter->open(planState, aOffset);
}


/***************************************************************************//**

********************************************************************************/
void StartClause::reset(PlanState& planState) const
{
  theStartClauseIter->reset(planState);
}


/***************************************************************************//**

********************************************************************************/
void StartClause::close(PlanState& planState) const
{
  theStartClauseIter->close(planState);
}


/***************************************************************************//**
  Evaluate the start condition expr on the item that is pointed to by the given
  position within the temp sequence that materializes the result of the domain
  expr.
********************************************************************************/
bool StartClause::evaluate(
    PlanState& planState,
    const store::TempSeq_t& inputSeq,
    const ulong pos) const
{
  theWindowVars.bindIntern(planState, inputSeq, pos);

  return evalToBool(theStartClauseIter, planState);
}


/***************************************************************************//**
  Bind the references to the external start-condition variables to the values
  corresponding to the item that is pointed to by the given position within
  the temp sequence that materializes the result of the domain expr.
********************************************************************************/
void StartClause::bindExtern(
    PlanState& planState,
    const store::TempSeq_t& inputSeq,
    const ulong pos) const
{
  theWindowVars.bindExtern(planState, inputSeq, pos);
}


/***************************************************************************//**

********************************************************************************/
void StartClause::bindIntern(
    PlanState& planState,
    const store::TempSeq_t& inputSeq,
    const ulong pos) const
{
  theWindowVars.bindIntern(planState, inputSeq, pos);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  EndClause                                                                  //
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
void EndClause::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theEndClauseIter;
  ar & theWindowVars;
  ar & theOnlyEnd;
  ar & theHasEndClause;
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
    theWindowVars.accept(v, false);
    theEndClauseIter->accept(v);
  }
}


/***************************************************************************//**

********************************************************************************/
void EndClause::open(PlanState& planState, uint32_t& aOffset) const
{
  if (theHasEndClause)
    theEndClauseIter->open(planState, aOffset);
}


/***************************************************************************//**

********************************************************************************/
void EndClause::reset(PlanState& planState) const
{
  if (theHasEndClause)
    theEndClauseIter->reset(planState);
}


/***************************************************************************//**

********************************************************************************/
void EndClause::close(PlanState& planState) const
{
  if (theHasEndClause)
    theEndClauseIter->close(planState);
}


/***************************************************************************//**

********************************************************************************/
bool EndClause::evaluate(
    PlanState& planState,
    const store::TempSeq_t& inputSeq,
    const ulong pos) const
{
  theWindowVars.bindIntern(planState, inputSeq, pos);

  return evalToBool(theEndClauseIter, planState);
}


/***************************************************************************//**

********************************************************************************/
void EndClause::bindIntern(
    PlanState& planState,
    const store::TempSeq_t& inputSeq,
    const ulong pos) const
{
  theWindowVars.bindIntern(planState, inputSeq, pos);
}


/***************************************************************************//**

********************************************************************************/
void EndClause::bindExtern(
    PlanState& planState,
    const store::TempSeq_t& inputSeq,
    const ulong pos) const
{
  theWindowVars.bindExtern(planState, inputSeq, pos);
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


void WindowState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
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

  if (theWindowType == TUMBLING)
    theMaxNeededHistory = 1;
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

  ar & theMaxNeededHistory;
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
void WindowIterator::openImpl(PlanState& planState, uint32_t& aOffset)
{
  StateTraitsImpl<WindowState>::createState(planState, theStateOffset, aOffset);

  theTupleIter->open(planState, aOffset);
  theInputIter->open(planState, aOffset);

  theStartClause.open(planState, aOffset);
  theEndClause.open(planState, aOffset);
}


/***************************************************************************//**

********************************************************************************/
void WindowIterator::resetImpl(PlanState& planState) const
{
  WindowState* lState = StateTraitsImpl<WindowState>::getState(planState,
                                                               theStateOffset);
  lState->reset(planState);

  theTupleIter->reset(planState);
  theInputIter->reset(planState);
  theStartClause.reset(planState);
  theEndClause.reset(planState);
}


/***************************************************************************//**

********************************************************************************/
void WindowIterator::closeImpl(PlanState& planState)
{
  theTupleIter->close(planState);
  theInputIter->close(planState);
  theStartClause.close(planState);
  theEndClause.close(planState);
  StateTraitsImpl<WindowState>::destroyState(planState, theStateOffset);
}


/***************************************************************************//**
  Bind the window var to the items between the given starting and ending items
  of the domain sequence.
********************************************************************************/
void WindowIterator::bindVariable(
    PlanState& planState,
    store::TempSeq_t& inputSeq,
    ulong aStartPos,
    ulong aEndPos) const
{
  xs_integer const lStartPos( aStartPos );
  xs_integer const lEndPos( aEndPos );

  for (std::vector<LetVarIter_t>::const_iterator lVarIter = theVarRefs.begin();
       lVarIter != theVarRefs.end();
       ++lVarIter)
  {
    (*lVarIter)->bind(inputSeq, planState, lStartPos, lEndPos);
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
        lState->theDomainSeq->
        purgeUpTo(xs_integer(lState->theCurInputPos - theMaxNeededHistory));
    }
    else
    {
      int64_t lPurgeTo =
      lState->theOpenWindows.front().theStartPos - theMaxNeededHistory;

      if (lPurgeTo > 0)
        lState->theDomainSeq->purgeUpTo(xs_integer(lPurgeTo));
    }
  }
}


/***************************************************************************//**

********************************************************************************/
bool WindowIterator::nextImpl(store::Item_t& aResult, PlanState& planState) const
{
  store::Iterator_t iterator;

  WindowState* state;
  DEFAULT_STACK_INIT(WindowState, state, planState);

  // Pull the next tuple from the input stream
  while (consumeNext(aResult, theTupleIter, planState))
  {
    // Create the temp sequence where to materialize the result of the domain
    // expr (lazily if theLazyEval flag is true).
    iterator = new PlanIteratorWrapper(theInputIter, planState);
    state->theDomainSeq = GENV_STORE.createTempSeq(iterator, theLazyEval);

    // Its clever to switch quite early to avoid a lot of if-else statements
    if (theWindowType == WindowIterator::SLIDING)
    {
      // Get the next item from the domain sequence
      // TODO: can the xs_integer be hoisted?
      while (state->theDomainSeq->containsItem(xs_integer(state->theCurInputPos)))
      {
        // If the current item satisfies the start condition, create a candidate
        // window starting at the current domain item.
        if (theStartClause.evaluate(planState,
                                    state->theDomainSeq,
                                    state->theCurInputPos))
        {
          state->theOpenWindows.push_back(WindowDef(state->theCurInputPos));
        }

        // For each candidate window, check if the current domain item satisfies
        // the end condition. Notice that before evaluating the end condition
        // expr, we must rebind the internal vars of the start condition, because
        // those varaibles may be refrenced in the end cond expr.
        state->theCurWindow = state->theOpenWindows.begin();

        while ( state->theCurWindow != state->theOpenWindows.end() )
        {
          if (state->theCurWindow->theEndPos == 0)
          {
            theStartClause.bindIntern(planState,
                                      state->theDomainSeq,
                                      state->theCurWindow->theStartPos);

            ulong lCurPos = state->theCurInputPos;
            if ( theEndClause.evaluate(planState,
                                       state->theDomainSeq,
                                       lCurPos))
            {
              state->theCurWindow->theEndPos = lCurPos;
            }
          }

          ++state->theCurWindow;
        }

        // Try to return closed windows to the consumer iterator. Notice that
        // windows must be sorted according to the position of their starting
        // items in the domain sequence. So, we can return a closed window only
        // if it appears as the first window in state->theOpenWindows.
        state->theCurWindow = state->theOpenWindows.begin();

        while (!state->theOpenWindows.empty())
        {
          if (state->theCurWindow->theEndPos != 0)
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
            theStartClause.bindExtern(planState,
                                      state->theDomainSeq,
                                      state->theCurWindow->theStartPos);

            theEndClause.bindExtern(planState,
                                    state->theDomainSeq,
                                    state->theCurWindow->theEndPos);

            bindVariable(planState,
                         state->theDomainSeq,
                         state->theCurWindow->theStartPos,
                         state->theCurWindow->theEndPos);

            state->theCurWindow = state->theOpenWindows.erase(state->theCurWindow);

            //doGarbageCollection(state);

            STACK_PUSH(true, state);
          }
          else
          {
            break;
          }
        }

        ++state->theCurInputPos;
      }
    }
    else //Tumpling window
    {
      // Doing this switch now also avoids further overhad
      if (theEndClause.theHasEndClause)
      {
        while (state->theDomainSeq->containsItem(xs_integer(state->theCurInputPos)))
        {
          if (state->theOpenWindows.empty() &&
              theStartClause.evaluate(planState,
                                      state->theDomainSeq,
                                      state->theCurInputPos))
          {
            theStartClause.bindExtern(planState,
                                      state->theDomainSeq,
                                      state->theCurInputPos);

            state->theOpenWindows.push_back(state->theCurInputPos);
          }

          if ( !state->theOpenWindows.empty() &&
               theEndClause.evaluate(planState,
                                     state->theDomainSeq,
                                     state->theCurInputPos))
          {
            theEndClause.bindExtern(planState,
                                    state->theDomainSeq,
                                    state->theCurInputPos);

            bindVariable(planState,
                         state->theDomainSeq,
                         state->theOpenWindows[0].theStartPos,
                         state->theCurInputPos);

            state->theOpenWindows.pop_back();

            assert(state->theOpenWindows.empty());

            STACK_PUSH(true, state);

            doGarbageCollection(state);
          }

          ++state->theCurInputPos;
        }
      }
      else
      {
        while (state->theDomainSeq->containsItem(xs_integer(state->theCurInputPos)))
        {
          if (theStartClause.evaluate(planState,
                                      state->theDomainSeq,
                                      state->theCurInputPos))
          {
            if (!state->theOpenWindows.empty())
            {
              //In no case there should be more than 1 position inside
              assert(state->theOpenWindows.size() == 1);

              theStartClause.bindExtern(planState,
                                        state->theDomainSeq,
                                        state->theOpenWindows[0].theStartPos);

              bindVariable(planState,
                           state->theDomainSeq,
                           state->theOpenWindows[0].theStartPos,
                           state->theCurInputPos  - 1);

              state->theOpenWindows.pop_back();

              assert(state->theOpenWindows.empty());

              STACK_PUSH(true, state);

              --state->theCurInputPos;
              doGarbageCollection(state);
              ++state->theCurInputPos;
            }

            state->theOpenWindows.push_back(state->theCurInputPos);
          }

          ++state->theCurInputPos;
        }
      }
    }

    // Check if we have open and/or closed windows
    state->theCurWindow = state->theOpenWindows.begin();

    while (state->theCurWindow != state->theOpenWindows.end())
    {
      if (!theEndClause.theOnlyEnd || state->theCurWindow->theEndPos != 0)
      {
        if (state->theCurWindow->theEndPos == 0)
          state->theCurWindow->theEndPos = state->theCurInputPos - 1;

        bindVariable(planState,
                     state->theDomainSeq,
                     state->theOpenWindows[0].theStartPos,
                     state->theCurWindow->theEndPos);

        theStartClause.bindExtern(planState,
                                  state->theDomainSeq,
                                  state->theOpenWindows[0].theStartPos);

        theEndClause.bindExtern(planState,
                                state->theDomainSeq,
                                state->theCurWindow->theEndPos);

        state->theCurWindow = state->theOpenWindows.erase(state->theCurWindow);

        STACK_PUSH(true, state);
      }
      else
      {
        ++state->theCurWindow;
      }
    }

    theInputIter->reset(planState);
    state->reset(planState);
  }

  STACK_PUSH(false, state);
  STACK_END(state);
}

  } //Namespace flwor
}//Namespace zorba
/* vim:set et sw=2 ts=2: */
