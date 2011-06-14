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

#include "runtime/booleans/booleans.h"
#include "runtime/util/iterator_impl.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "diagnostics/xquery_diagnostics.h"

namespace zorba {

//14.6 op:is-same-node
bool
IsSameNodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{ 
  bool lBool;
  store::Item_t lItem0, lItem1;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);
  
  if (CONSUME (lItem0, 0)) {
    if (CONSUME (lItem1, 1)) {
      if (!lItem0->isNode() || !lItem0->isNode()) {
        throw XQUERY_EXCEPTION(
          err::XPTY0004,
          ERROR_PARAMS( ZED( OpIsSameNodeMustHaveNodes ) ),
          ERROR_LOC( loc )
        );
      }
      lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == 0); 
      STACK_PUSH (GENV_ITEMFACTORY->createBoolean(result, lBool),
                  aState);
    }
  }
  STACK_END (aState);
}


//14.7 op:node-before
bool
NodeBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{ 
  bool lBool;
  store::Item_t lItem0, lItem1;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);

  if (CONSUME (lItem0, 0)) {
    if (CONSUME (lItem1, 1)) {
      if (!lItem0->isNode() || !lItem0->isNode()) {
        throw XQUERY_EXCEPTION(
          err::XPTY0004,
          ERROR_PARAMS( ZED( OpNodeBeforeMustHaveNodes ) ),
          ERROR_LOC( loc )
        );
      }
      lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == -1); 
      STACK_PUSH (GENV_ITEMFACTORY->createBoolean(result, lBool), aState);
    }
  }
  STACK_END (aState);
}

//14.8 op:node-after
bool
NodeAfterIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{ 
  bool lBool;
  store::Item_t lItem0, lItem1;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);

  if (CONSUME (lItem0, 0)) {
    if (CONSUME (lItem1, 1)) {
      if (!lItem0->isNode() || !lItem0->isNode()) {
        throw XQUERY_EXCEPTION(
          err::XPTY0004,
          ERROR_PARAMS( ZED( OpNodeAfterMustHaveNodes ) ),
          ERROR_LOC( loc )
        );
      }
      lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == 1); 
      STACK_PUSH (GENV_ITEMFACTORY->createBoolean(result, lBool), aState);
    }
  }
  STACK_END (aState);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
