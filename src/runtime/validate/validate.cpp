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
#include "runtime/validate/validate.h"

#include "system/globalenv.h"

#include "types/schema/schema.h"
#include "types/schema/validate.h"

#include "runtime/api/runtimecb.h"

#include "store/api/item.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "zorbaerrors/error_messages.h"
#include "zorbaerrors/errors.h"


namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(ValidateIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ValidateIterator)


ValidateIterator::ValidateIterator(
    short sctx,
    const QueryLoc& loc,
    PlanIter_t& aIter,
    TypeManager *typeMgr,
	store::Item_t typeName,
	ParseConstants::validation_mode_t validationMode)
  :
  UnaryBaseIterator<ValidateIterator, PlanIteratorState>( sctx, loc, aIter ),
  _validationMode(validationMode),
  _typemgr (typeMgr),
  _typeName(typeName)
{
}


bool ValidateIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t item;
  store::Item_t tmp;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);

  if (consumeNext(item, theChild, planState))
  {
    if (consumeNext(tmp, theChild, planState))
    {
      ZORBA_ERROR_LOC_DESC(XQTY0030, loc, 
                           "Argument in validate expression not a single element node.");
      result = NULL;
      STACK_PUSH(false, aState);
    }
    else
    {
      STACK_PUSH(Validator::effectiveValidationValue(result,
                                                     item,
                                                     _typeName,
                                                     _typemgr.getp(),
                                                     _validationMode,
                                                     theSctx,
                                                     this->loc),
                 aState);
    }
  }
  else
  {
    ZORBA_ERROR_LOC_DESC( XQTY0030, loc, "Wrong arguments in validate expression.");
    STACK_PUSH(false, aState);
  }

  STACK_END (aState);
}


}
