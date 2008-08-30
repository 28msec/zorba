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

#include "runtime/debug/zorba_debugger_iterators.h"

#include <iostream>
#include <sstream>
#include <cassert>

#include <zorbautils/thread.h>

#include "system/globalenv.h"

#include "debugger/debugger_server.h"

using namespace std;

namespace zorba {

FnDebugIterator::FnDebugIterator(DebuggerBreak aKind, const QueryLoc& loc,
               checked_vector<store::Item_t> varnames_,
               checked_vector<std::string> var_keys_,
               checked_vector<xqtref_t> vartypes_,
               checked_vector<global_binding> globals_,
               std::vector<PlanIter_t>& aChildren ) 
    : NaryBaseIterator<FnDebugIterator, PlanIteratorState>(loc, aChildren),
    theKind(aKind), theDebugger(0), varnames(varnames_), var_keys(var_keys_), vartypes(vartypes_),
    globals(globals_){}

  FnDebugIterator::~FnDebugIterator(){}

  bool FnDebugIterator::nextImpl( store::Item_t& result, PlanState& planState ) const
  {
    PlanIteratorState * state;

    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    
    if ( (theKind == BEFORE || theKind == BOTH) && theDebugger->hasToSuspend() )
    {
      assert(theDebugger->theRuntimeThread);
      theDebugger->theRuntimeThread->suspend();
    }
    while ( consumeNext( result, theChildren[0], planState ) ) {
      assert(theDebugger);
      theDebugger->thePlanState = &planState;
      theDebugger->theVarnames = varnames;
      theDebugger->theVarkeys = var_keys;
      theDebugger->theVartypes = vartypes;
      theDebugger->theGlobals  = globals;
      theDebugger->theChildren = theChildren;
      theDebugger->theLocation = loc;
      if ( (theKind == AFTER || theKind == BOTH) && theDebugger->hasToSuspend() )
      {
        assert(theDebugger->theRuntimeThread);
        theDebugger->theRuntimeThread->suspend();
      }
      STACK_PUSH(true, state);
    }
    STACK_END(state);
  }

  void FnDebugIterator::openImpl(PlanState& planState, uint32_t& offset )
  {
    NaryBaseIterator<FnDebugIterator, PlanIteratorState>::openImpl(planState, offset);
    theDebugger = planState.theCompilerCB->m_debugger;
  }
  
  void FnDebugIterator::accept( PlanIterVisitor& v ) const
  {
    v.beginVisit(*this);
    std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin();
    std::vector<PlanIter_t>::const_iterator lEnd =  theChildren.end();
    for ( ; iter != lEnd; ++iter ) {
      ( *iter )->accept ( v );
    }
    v.endVisit(*this);
  }
} /* namespace zorba */

