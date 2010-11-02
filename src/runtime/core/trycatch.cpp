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
#include "zorbaerrors/errors.h"
#include "zorbaerrors/Assert.h"
#include "errors/user_error.h"

#include "compiler/api/compilercb.h"

#include "context/static_context.h"

#include "runtime/core/trycatch.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/var_iterators.h"
#include "runtime/util/item_iterator.h"

#include "store/api/store.h"
#include "store/api/temp_seq.h"

#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/node_test.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(TryCatchIterator::CatchClause)
END_SERIALIZABLE_CLASS_VERSIONS(TryCatchIterator::CatchClause)

SERIALIZABLE_CLASS_VERSIONS(TryCatchIterator)
END_SERIALIZABLE_CLASS_VERSIONS(TryCatchIterator)


TryCatchIteratorState::TryCatchIteratorState()
  : theTempIterator(NULL),
  theCatchIterator(NULL)
{}

TryCatchIteratorState::~TryCatchIteratorState()
{
  if (theTempIterator != NULL) {
    theTempIterator->close();
    theTempIterator = NULL;
  }

  std::vector<store::Iterator_t>::iterator lIters = theErrorIters.begin();
  std::vector<store::Iterator_t>::iterator lItersEnd = theErrorIters.end();
  for (; lIters != lItersEnd; ++lIters) {
    (*lIters)->close();
  }

}

void
TryCatchIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void
TryCatchIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  if ( theTargetSequence )
    theTargetSequence->purge(); // release the target sequence
  if (theTempIterator != NULL) {
    theTempIterator->close();
    theTempIterator = NULL;
  }
  theCatchIterator = NULL;

  std::vector<store::Iterator_t>::iterator lIters = theErrorIters.begin();
  std::vector<store::Iterator_t>::iterator lItersEnd = theErrorIters.end();
  for (; lIters != lItersEnd; ++lIters) {
    (*lIters)->close();
  }

}


TryCatchIterator::CatchClause::~CatchClause() 
{
}


TryCatchIterator::TryCatchIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& aBlock,
    std::vector<CatchClause>& aCatchClauses)
  : 
  UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState> (sctx, loc, aBlock),
  theCatchClauses(aCatchClauses)
{ 
}


TryCatchIterator::~TryCatchIterator() 
{
}


void TryCatchIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<TryCatchIteratorState>::createState(planState,
                                                      theStateOffset,
                                                      offset);

  StateTraitsImpl<TryCatchIteratorState>::initState(planState, theStateOffset);
  
  theChild->open(planState, offset);

  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->open(planState, offset);
  } 

}

uint32_t
TryCatchIterator::getStateSizeOfSubtree() const
{
	uint32_t size = theChild->getStateSizeOfSubtree() + getStateSize();

  std::vector<CatchClause>::const_iterator lIter = theCatchClauses.begin(); 
  std::vector<CatchClause>::const_iterator lEnd = theCatchClauses.end();
  for (; lIter!= lEnd; ++lIter )
  {
		size += ( *lIter ).catch_expr->getStateSizeOfSubtree();
	}

  return size; 
}


// check if/which catch matches and bind the state's catch iterator to the matching catch clause
bool
TryCatchIterator::matchedCatch(
    error::ZorbaError& e,
    TryCatchIteratorState* state,
    PlanState& planState) const
{
  std::vector<CatchClause>::const_iterator lIter = theCatchClauses.begin(); 
  std::vector<CatchClause>::const_iterator lEnd = theCatchClauses.end();
  for (; lIter!= lEnd; ++lIter )
  {
    const CatchClause& cc = *lIter;
    const std::vector<NodeNameTest_t>& nts = cc.node_names;
    std::vector<NodeNameTest_t>::const_iterator i;
    for(i = nts.begin(); i != nts.end(); ++i) 
    {
      const NodeNameTest& nt = **i;
      if (nt.matches(e.theLocalName.c_str(), e.theNamespace.c_str()))
      {
        state->theCatchIterator = cc.catch_expr;
        bindErrorVars(e, &cc, planState);
        return true;
      }
    }
  }
  return false;
}


void
TryCatchIterator::bindErrorVars(
    error::ZorbaError& e,
    const CatchClause* clause,
    PlanState& planState) const
{
  TryCatchIteratorState* state =
    StateTraitsImpl<TryCatchIteratorState>::getState(planState, theStateOffset);

  // bind the error code (always)
  store::Item_t lErrorCodeItem;
  GENV_ITEMFACTORY->createQName(lErrorCodeItem, e.ns().c_str(), e.prefix().c_str(), e.localName().c_str());

  std::vector<LetVarIter_t>::const_iterator lErrorCodeVarIter = clause->errorcode_var.begin();
  std::vector<LetVarIter_t>::const_iterator lErrorCodeVarIterEnd = clause->errorcode_var.end();
  for ( ; lErrorCodeVarIter != lErrorCodeVarIterEnd; lErrorCodeVarIter++ ) 
  {
    store::Iterator_t lErrorCodeIter = new ItemIterator(lErrorCodeItem);
    lErrorCodeIter->open();
    state->theErrorIters.push_back(lErrorCodeIter);
    (*lErrorCodeVarIter)->bind(lErrorCodeIter, planState);
  }
  
  std::vector<LetVarIter_t>::const_iterator lErrorDescVarIter = clause->errordesc_var.begin();
  std::vector<LetVarIter_t>::const_iterator lErrorDescVarIterEnd = clause->errordesc_var.end();
  for ( ; lErrorDescVarIter != lErrorDescVarIterEnd; lErrorDescVarIter++ ) 
  {
    // bind the description or the empty sequence
    store::Iterator_t lErrorDescIter;
    if (!e.theDescription.empty()) 
    {
      zstring errDescr = e.theDescription;
      store::Item_t errDescItem;
      GENV_ITEMFACTORY->createString(errDescItem, errDescr);
      lErrorDescIter = new ItemIterator(errDescItem);
    } 
    else
    {
      lErrorDescIter = new ItemIterator();
    }
    lErrorDescIter->open();
    state->theErrorIters.push_back(lErrorDescIter);
    (*lErrorDescVarIter)->bind(lErrorDescIter, planState);
  }

  // TODO bind the error objects
  std::vector<LetVarIter_t>::const_iterator lErrorObjVarIter = clause->errorobj_var.begin();
  std::vector<LetVarIter_t>::const_iterator lErrorObjVarIterEnd = clause->errorobj_var.end();
  error::ZorbaUserError *ue = dynamic_cast<error::ZorbaUserError *>(&e);
  std::vector<store::Item_t> *eObjs = NULL;
  if (ue != NULL && !ue->theErrorObject.empty()) {
    eObjs = &ue->theErrorObject;
  }
  for ( ; lErrorObjVarIter != lErrorObjVarIterEnd; lErrorObjVarIter++ ) {
    store::Iterator_t lErrorObjIter = eObjs == NULL ? new ItemIterator() : new ItemIterator(*eObjs);
    lErrorObjIter->open();
    state->theErrorIters.push_back(lErrorObjIter);
    (*lErrorObjVarIter)->bind(lErrorObjIter, planState);
  }

}

bool
TryCatchIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{

  store::Item_t item; // each item that will be returned 
  
  store::Iterator_t lIterator;
  
  TryCatchIteratorState* state;
  DEFAULT_STACK_INIT(TryCatchIteratorState, state, planState);
  
  try 
  { 
    lIterator = new PlanIteratorWrapper(theChild, planState);
    state->theTargetSequence = GENV_STORE.createTempSeq(lIterator, false, false);
    state->theTempIterator = state->theTargetSequence->getIterator();
    state->theTempIterator->open();
  }
  catch (error::ZorbaError& e) 
  {
    if (!matchedCatch(e, state, planState)) 
    {
      throw e;
    }
  }

  if (state->theTempIterator != NULL) 
  {
    ZORBA_ASSERT(state->theCatchIterator == NULL);
    while (state->theTempIterator->next(result)) 
    {
      STACK_PUSH( true, state );
    } 
  }
  else if (state->theCatchIterator != NULL) 
  {
    ZORBA_ASSERT(state->theTempIterator == NULL);
    while(consumeNext(result, state->theCatchIterator.getp(), planState)) 
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    ZORBA_ASSERT(false);
  }
 
  STACK_END (state);
}


void 
TryCatchIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<TryCatchIteratorState>::reset(planState, theStateOffset);

  theChild->reset(planState);
  
  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->reset(planState);
  } 

}

void 
TryCatchIterator::closeImpl(PlanState& planState)
{
  theChild->close(planState);
  
  std::vector<TryCatchIterator::CatchClause>::iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->close(planState);
  } 

  StateTraitsImpl<TryCatchIteratorState>::destroyState(planState, theStateOffset);
}

void TryCatchIterator::accept(PlanIterVisitor &v) const {
  v.beginVisit(*this);
  theChild->accept ( v );
  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();
  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->accept ( v );
  } 
  v.endVisit(*this);
}

} /* namespace zorba */
/* vim:set ts=2 sw=2: */
