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

#include <iostream>

#include "debugger/debugger_serverimpl.hpp"

#include "runtime/debug/debug_iterators.h"

#include "runtime/debug/zorba_debugger_iterators.hpp"


using namespace std;

namespace zorba {

  FnDebugIterator::FnDebugIterator(const QueryLoc& loc, std::vector<PlanIter_t>& args) 
    : NaryBaseIterator<FnDebugIterator, PlanIteratorState>(loc, args),
    theDebugger(0)
  {}

  FnDebugIterator::~FnDebugIterator()
  {
  }

  store::Item_t FnDebugIterator::nextImpl(PlanState& planState) const
  {

    store::Item_t lSequenceItem;
  
    PlanIteratorState * state;
    
    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    
    theDebugger->theLocation = loc;
    
    while ( ( lSequenceItem = consumeNext(theChildren[0], planState ) ) != NULL ) {
      
      if ( theDebugger->hasToSuspend() )
      {
        boost::mutex::scoped_lock lock( theDebugger->theRuntimeMutex );
        theDebugger->theRuntimeSuspendedCV.wait( lock );
      }

      STACK_PUSH(lSequenceItem, state);
    }
    STACK_END(state);
  }

  void FnDebugIterator::openImpl(PlanState& planState, uint32_t& offset )
  {
    NaryBaseIterator<FnDebugIterator, PlanIteratorState>::openImpl(planState, offset);
    theDebugger = dynamic_cast<ZorbaDebuggerImpl *>( ZorbaDebugger::getInstance() );
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

