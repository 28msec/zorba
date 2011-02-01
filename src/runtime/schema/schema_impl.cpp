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
#include "runtime/schema/schema.h"

#include "types/schema/schema.h"
#include "types/schema/validate.h"
#include "types/typemanager.h"

#include "system/globalenv.h"
#include "zorbaerrors/errors.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"

namespace zorba {

#ifndef ZORBA_NO_XMLSCHEMA
void
ValidateIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (UnaryBaseIterator<ValidateIterator, PlanIteratorState>*)this);
  SERIALIZE_ENUM(enum ParseConstants::validation_mode_t, validationMode);
  SERIALIZE_TYPEMANAGER_RCHANDLE(TypeManager, typemgr);
  ar & typeName;
}

bool
ValidateIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
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
                                                     typeName,
                                                     typemgr.getp(),
                                                     validationMode,
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
#endif

bool
ZorbaSchemaTypeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    result = item->getType();
    if ( result )
      STACK_PUSH(true, state );
  }

  STACK_END (state);
}

bool
ZorbaIsValidatedIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::ItemFactory* factory = GENV_ITEMFACTORY;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    factory->createBoolean(result, item->isValidated());

    STACK_PUSH(true, state);
  }

  STACK_END (state);
}

} /* namespace zorba */
