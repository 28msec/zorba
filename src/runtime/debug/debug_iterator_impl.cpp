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

#include "runtime/debug/debug_iterator.h"

#include <zorba/singleton_item_sequence.h>

#include "types/typeimpl.h"

#include "compiler/api/compilercb.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "debugger/debugger_runtime.h"
#include "debugger/debugger_commons.h"

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/item_iterator.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "api/serialization/serializer.h"
#include "api/serializerimpl.h"
#include "api/unmarshaller.h"


namespace zorba {


#ifdef ZORBA_WITH_DEBUGGER

// the debug iterator needs to know all variables, their keys
// and types. this is required for the eval command
// this function is called by the plan_visitor

void DebugIterator::setVariables(
    checked_vector<store::Item_t> aVarNames,
    checked_vector<xqtref_t>      aVarTypes)
{
  varnames = aVarNames;
  vartypes = aVarTypes;
}


bool
DebugIterator::nextImpl(
    store::Item_t&  result,
    PlanState&      planState) const
{
  DebugIteratorState* lState = 0;
  DEFAULT_STACK_INIT(DebugIteratorState, lState, planState);

  planState.theDebuggerCommons->setCurrentIterator(this);

  // is there a breakpoint here?
  checkBreak(&planState);

  while (consumeNext(result, theChildren[0], planState)) {
    lState->notEmptySequence = true;
    // this iterator is the identity
    STACK_PUSH(true, lState);
  }

  STACK_END(lState);
}


void
DebugIterator::setChildren( std::vector<PlanIter_t>* args )
{
  theChildren = *args;
}


void
DebugIterator::addChild( DebugIterator* child )
{
  //Preconditions
  ZORBA_ASSERT(child != NULL);

  theDebuggerChildren.push_back(child);

  //Postconditions
  ZORBA_ASSERT(theDebuggerChildren.back() == child);
}


void
DebugIterator::setParent( DebugIterator* parent )
{
  theDebuggerParent = parent;
  
  //Postconditions
  ZORBA_ASSERT(getDebuggerParent() == parent);
}


QueryLoc
DebugIterator::getQueryLocation() const
{
  return loc;
}
  

const DebugIterator*
DebugIterator::getDebuggerParent() const
{
  return theDebuggerParent;
}


std::vector<DebugIterator*>
DebugIterator::getDebuggerChildren() const
{
  return theDebuggerChildren;
}

const DebugIterator*
DebugIterator::getOverIterator() const
{
  if (theDebuggerParent == NULL) {
    return NULL;
  }
  // jump over us
  if (theDebuggerParent->theDebuggerChildren.back() == this) {
    return NULL;
  }
  std::vector<DebugIterator*>::const_iterator lIter;
  const std::vector<DebugIterator*> lSilblings =
    theDebuggerParent->theDebuggerChildren;
  for (lIter = lSilblings.begin(); lIter != lSilblings.end(); lIter++) {
    if (*lIter == this) {
      ++lIter;
      return *lIter;
    }
  }
  
  //Should be never reached.
  ZORBA_ASSERT(false);
  return NULL;
}


std::list<std::pair<zstring, zstring> >
DebugIterator::eval(
    PlanState*                aPlanState,
    Zorba_SerializerOptions*  aSerOptions) const
{
  theChildren[1]->reset(*aPlanState);
  std::list<std::pair<zstring, zstring> > lResult;
  store::Item_t lRes;
  serializer ser(NULL);
  SerializerImpl::setSerializationParameters(ser, *aSerOptions);

  while (consumeNext(lRes, theChildren[1], *aPlanState)) {
    std::stringstream lResStream;

    // Build a singleton item sequence and wrap it in an internal Serializable.
    // The new serializer interface only accepts Serializable objects.
    const Item lItem(lRes);
    SingletonItemSequence lSequence(lItem);
    Iterator_t  seq_iter = lSequence.getIterator();
    seq_iter->open();
    ser.serialize(Unmarshaller::getInternalIterator(seq_iter.get()), lResStream);
    seq_iter->close();

    // build the result pair and append it to the list
    store::Item* lTypeItem = lRes->getType();
    zstring lTypeStr(lTypeItem->getStringValue());
    // TODO: support namespaces
    //zstring lTypeNS = lTypeItem->getNamespace();
    //if (!lTypeNS.empty()) {
    //  lTypeStr = lTypeStr.append(" " + lTypeNS);
    //}    
    std::pair<zstring, zstring> lPair(lResStream.str(), lTypeStr);
    lResult.push_back(lPair);
  }

  return lResult;
}


void
DebugIterator::checkBreak(PlanState* planState) const
{
  DebuggerCommons* lCommons = planState->theDebuggerCommons;
  SuspensionCause lCause = 0;
  
  // check whether we have to suspend 
  // (determined by location, iterator, or some other cause)
  if (lCommons->canBreak() && (lCommons->mustBreak(lCause) ||
      lCommons->hasToBreakAt(loc) || lCommons->hasToBreakAt(this)))
  {
    try
    {
      lCause = lCause == 0 ? CAUSE_BREAKPOINT : lCause;
      
      // tell everybody that we are the iterator who suspended
      //lCommons->setCurrentIterator(this);
      lCommons->setCurrentStaticContext(getStaticContext());
      lCommons->setCurrentDynamicContext(planState->theLocalDynCtx);
      lCommons->setBreak(false);
      lCommons->setPlanState(planState);

      // suspend
      lCommons->getRuntime()->suspendRuntime(loc, lCause);
      lCause = 0;
    }
    catch (...)
    {
      throw;
    }
  }
}
#endif // ZORBA_WITH_DEBUGGER


}/* namespace zorba */
/* vim:set et sw=2 ts=2: */
