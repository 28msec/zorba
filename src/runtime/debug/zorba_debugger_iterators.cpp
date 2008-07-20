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

#include "system/globalenv.h"
#include "zorbautils/thread.h"

using namespace std;

namespace zorba {

FnDebugIterator::FnDebugIterator( const QueryLoc& loc,
               checked_vector<store::Item_t> varnames_,
               checked_vector<std::string> var_keys_,
               checked_vector<xqtref_t> vartypes_,
               std::vector<PlanIter_t>& aChildren ) 
    : NaryBaseIterator<FnDebugIterator, PlanIteratorState>(loc, aChildren),
    theDebugger(0), varnames(varnames_), var_keys(var_keys_), vartypes(vartypes_){}

  FnDebugIterator::~FnDebugIterator(){}

  bool FnDebugIterator::nextImpl( store::Item_t& result, PlanState& planState ) const
  {
    PlanIteratorState * state;

    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    
    theDebugger->theLocation = loc;
    theDebugger->thePlanState = &planState;
    theDebugger->theVarnames = varnames;
    theDebugger->theVarkeys = var_keys;
    theDebugger->theVartypes = vartypes;
    theDebugger->theChildren = theChildren;

    while ( consumeNext( result, theChildren[0], planState ) ) {
      if ( theDebugger->hasToSuspend() )
      {
        theDebugger->theRuntimeThread->suspend();
      }
      STACK_PUSH(true, state);
    }
    STACK_END(state);
  }

  void FnDebugIterator::openImpl(PlanState& planState, uint32_t& offset )
  {
    NaryBaseIterator<FnDebugIterator, PlanIteratorState>::openImpl(planState, offset);
    theDebugger = GlobalEnvironment::getInstance().getDebugger();
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

