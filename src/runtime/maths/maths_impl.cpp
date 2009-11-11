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
#include "runtime/maths/maths.h"

#include "types/casting.h"
#include "types/typeconstants.h"
#include "types/typeops.h"

#include "system/globalenv.h"
#include "store/api/item_factory.h"
#include "store/api/item.h"

namespace zorba {

/*******************************************************************************

********************************************************************************/
bool FnSQRTIterator::nextImpl (store::Item_t& result, PlanState& planState) const 
{
  store::Item_t item;
  xqtref_t type;
    
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState ))
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().sqrt());

    if ( consumeNext(item, theChild.getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "fn:sqrt has a sequence longer than one as an operator.");
    }
    
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnAtan2Iterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  store::Item_t n0;
  store::Item_t n1;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(n0, this->theChild0.getp(), planState))
  {
    if (consumeNext(n1, this->theChild1.getp(), planState))
    {
      {
        xqp_double doub1 = n0->getDoubleValue();
        xqp_double doub2 = n1->getDoubleValue();

        GENV_ITEMFACTORY->createDouble(result, doub1.atan2(doub2));
      }

      if (consumeNext(n0, this->theChild0.getp(), planState) ||
          consumeNext(n1, this->theChild1.getp(), planState))
        ZORBA_ERROR_DESC(XPTY0004,
                         "Atan2 function has a sequence longer than one as an operand.");
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


} /* namespace zorba */
