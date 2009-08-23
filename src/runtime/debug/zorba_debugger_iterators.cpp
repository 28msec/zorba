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

//SERIALIZABLE_CLASS_VERSIONS(FnDebugIterator)
//END_SERIALIZABLE_CLASS_VERSIONS(FnDebugIterator)
	FnDebugIterator::FnDebugIterator(
		ZorbaDebugger* debugger,
    short sctx,
		const QueryLoc& loc,
               checked_vector<store::Item_t> varnames_,
               checked_vector<std::string> var_keys_,
               checked_vector<xqtref_t> vartypes_,
               checked_vector<global_binding> globals_,
               std::vector<PlanIter_t>& aChildren,
               bool for_expr_) 
		: NaryBaseIterator<FnDebugIterator, PlanIteratorState>(sctx, loc, aChildren),
		theDebugger(debugger), varnames(varnames_), var_keys(var_keys_), vartypes(vartypes_),
		globals(globals_), for_expr(for_expr_), m_break(false)
	{
		debugger->registerIterator(loc, this);
	}

  FnDebugIterator::~FnDebugIterator(){}

  bool FnDebugIterator::nextImpl( store::Item_t& result, PlanState& planState ) const
  {
    PlanIteratorState * state;
    updateInfos(loc, planState, varnames, var_keys, vartypes, globals);

    try{
      DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

			if ( m_break )
      {
        //updateInfos(loc, planState, varnames, var_keys, vartypes, globals);
        assert(theDebugger->theRuntimeThread);
				theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_BREAKPOINT);
        theDebugger->theRuntimeThread->suspend();
      } else if ( theDebugger->hasToStepOver() ) {
        //updateInfos(loc, planState, varnames, var_keys, vartypes, globals);
        theDebugger->stepOver();
        theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_STEP);
        assert(theDebugger->theRuntimeThread);
        theDebugger->theRuntimeThread->suspend();
      } else if ( theDebugger->hasToStepOut() ) {
        //updateInfos(loc, planState, varnames, var_keys, vartypes, globals);
        theDebugger->stepOut();
        theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_STEP);
        assert(theDebugger->theRuntimeThread);
        theDebugger->theRuntimeThread->suspend();
      } else if ( theDebugger->hasToStepInto() ) {
        //updateInfos(loc, planState, varnames, var_keys, vartypes, globals);
        theDebugger->stepInto();
        theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_STEP);
        assert(theDebugger->theRuntimeThread);
        theDebugger->theRuntimeThread->suspend();
      }


      while ( consumeNext( result, theChildren[0], planState )) {
        STACK_PUSH(true, state);
        assert(theDebugger != 0);
        if ( for_expr ) {
					if ( m_break )
          {
            updateInfos(loc, planState, varnames, var_keys, vartypes, globals);
            assert(theDebugger->theRuntimeThread);
						theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_BREAKPOINT);
            theDebugger->theRuntimeThread->suspend();
          } else if ( theDebugger->hasToStepOver() ) {
            updateInfos(loc, planState, varnames, var_keys, vartypes, globals);
            theDebugger->stepOver();
            theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_STEP);
            assert(theDebugger->theRuntimeThread);
            theDebugger->theRuntimeThread->suspend();
          } else if ( theDebugger->hasToStepOut() ) {
            updateInfos(loc, planState, varnames, var_keys, vartypes, globals);
            theDebugger->stepOut();
            theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_STEP);
            assert(theDebugger->theRuntimeThread);
            theDebugger->theRuntimeThread->suspend();
          } else if ( theDebugger->hasToStepInto() ) {
            updateInfos(loc, planState, varnames, var_keys, vartypes, globals);
            theDebugger->stepInto();
            theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_STEP);
            assert(theDebugger->theRuntimeThread);
            theDebugger->theRuntimeThread->suspend();
          }
        }
      }
      STACK_END(state);
    }catch(error::ZorbaError &e) {
      if(e.theDebug == true)
      {
        throw e;
      }
      cerr << e.toString() << endl;
      theDebugger->setStatus(QUERY_SUSPENDED, CAUSE_ERROR); 
      assert(theDebugger->theRuntimeThread);
      theDebugger->theRuntimeThread->suspend();
      e.theDebug = true;
      throw e;
    }
		return false;
  }

  void FnDebugIterator::openImpl(PlanState& planState, uint32_t& offset )
  {
    NaryBaseIterator<FnDebugIterator, PlanIteratorState>::openImpl(planState, offset);
    //theDebugger = planState.theCompilerCB->m_debugger;
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

  bool FnDebugIterator::isUpdating() const { return theChildren[0]->isUpdating(); }

	void FnDebugIterator::updateInfos(const QueryLoc& loc, PlanState& planState, checked_vector<store::Item_t> varnames,
                                  checked_vector<std::string> var_keys, checked_vector<xqtref_t> vartypes,
                                  checked_vector<global_binding> globals) const
	{
  assert(theDebugger);
  theDebugger->theLocation = loc;
  theDebugger->thePlanState = &planState;
  theDebugger->theVarnames = varnames;
  theDebugger->theVarkeys = var_keys;
  theDebugger->theVartypes = vartypes;
  theDebugger->theGlobals  = globals;
  theDebugger->theChildren = theChildren;
  theDebugger->theLocation = loc;
	}  
} /* namespace zorba */

