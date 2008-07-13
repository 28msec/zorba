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
#include <pthread.h>

#include "compiler/expression/var_expr.h"
#include "debugger/debugger_serverimpl.h"

using namespace std;

namespace zorba {
FnDebugIterator::FnDebugIterator( const QueryLoc& loc, checked_vector<PlanIter_t>& args,
                                  const static_context * aStaticContext,
                                  checked_vector<var_expr_t> &aVariables ) 
    : NaryBaseIterator<FnDebugIterator, PlanIteratorState>(loc, args),
    theDebugger(0), theStaticContext( aStaticContext ), theVariables( aVariables ){}

  FnDebugIterator::~FnDebugIterator(){}

  bool FnDebugIterator::nextImpl( store::Item_t& result, PlanState& planState ) const
  {
    PlanIteratorState * state;

    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    
    theDebugger->theLocation = loc;
    theDebugger->thePlanState = &planState;

    while ( consumeNext( result, theChildren[0], planState ) ) {
      //std::cerr << "Number of variables in scope:" << theVariables.size() << std::endl;
      for( unsigned int i=0; i<theVariables.size(); i++)
      {
        std::cerr << "name: " << theVariables.at(i)->toString() << std::endl;  
      }
      if ( theDebugger->hasToSuspend() )
      {
        pthread_mutex_lock( &theDebugger->theRuntimeMutex );
        pthread_cond_wait( &theDebugger->theRuntimeSuspendedCV, &theDebugger->theRuntimeMutex ); 
        pthread_mutex_unlock( &theDebugger->theRuntimeMutex ); 
      }
      STACK_PUSH(true, state);
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

