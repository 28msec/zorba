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

#include "diagnostics/assert.h"

#include "system/globalenv.h"

#include "runtime/core/gflwor/tuplestream_iterator.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/pul.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

using namespace zorba;

namespace zorba 
{
namespace flwor 
{
SERIALIZABLE_CLASS_VERSIONS(TupleStreamIterator)
END_SERIALIZABLE_CLASS_VERSIONS(TupleStreamIterator)

TupleStreamIterator::TupleStreamIterator(
    static_context*   sctx,
    const QueryLoc&   aLoc,
    PlanIter_t        aTupleIter,
    PlanIter_t        aReturnIter,
    bool              aIsUpdating) 
  :
  BinaryBaseIterator<TupleStreamIterator, PlanIteratorState>(sctx,
                                                             aLoc,
                                                             aTupleIter,
                                                             aReturnIter),
  theIsUpdating(aIsUpdating) 
{
}

  
TupleStreamIterator::~TupleStreamIterator() 
{
}


//theChild0 == TupleClause
//theChild1 == ReturnClause
bool TupleStreamIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const 
{
  std::auto_ptr<store::PUL> pul;
  store::Item_t lTuple;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT (PlanIteratorState, lState, aPlanState);

  if (theIsUpdating) 
  {
    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    while (consumeNext (lTuple, theChild0, aPlanState)) 
    {
      while (consumeNext (aResult, theChild1, aPlanState)) 
      {
        ZORBA_FATAL(aResult->isPul(), "");
        pul->mergeUpdates(aResult);
      }
    }

    aResult = pul.release();

    STACK_PUSH(true, lState);
  }
  else 
  {
    while (consumeNext(lTuple, theChild0, aPlanState)) 
    {
      while (consumeNext(aResult, theChild1, aPlanState)) 
      {
        STACK_PUSH(true, lState);
      }
      theChild1->reset(aPlanState);
    }
  }
  STACK_PUSH(false, lState);
  STACK_END(lState);
}


BINARY_ACCEPT(TupleStreamIterator);

  
} //Namespace flwor
}//Namespace zorba
/* vim:set et sw=2 ts=2: */
