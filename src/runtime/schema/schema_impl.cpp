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

#include <set>

#include "runtime/schema/schema.h"

#include "types/schema/revalidateUtils.h"
#include "types/schema/schema.h"
#include "types/schema/validate.h"
#include "types/typemanager.h"

#include "system/globalenv.h"
#include "diagnostics/xquery_diagnostics.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/pul.h"

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
      throw XQUERY_EXCEPTION( err::XQTY0030, ERROR_LOC( loc ) );
      // STACK_PUSH(false, aState); -- THIS IS NEVER REACHED
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
    throw XQUERY_EXCEPTION( err::XQTY0030, ERROR_LOC( loc ) );
    // STACK_PUSH(false, aState); -- THIS IS NEVER REACHED
  }

  STACK_END (aState);
}
#endif // ZORBA_NO_XMLSCHEMA


bool
ZorbaValidateInPlaceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t node;

  PlanIteratorState* state;
  store::PUL_t pul;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(node, theChild.getp(), planState))
  {
    // verify that if the element being revalidated is an element it is the root
    if (node->getNodeKind()==store::StoreConsts::elementNode &&
        node->getParent() &&
        node->getParent()->getNodeKind()!=store::StoreConsts::documentNode)
      throw XQUERY_EXCEPTION( zerr::ZAPI0090_CANNOT_VALIDATE_NON_ROOT, ERROR_LOC( loc ) );

    pul = GENV_ITEMFACTORY->createPendingUpdateList();

    pul->addRevalidate(&loc,node);

    result.transfer(pul);
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


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

} // namespace zorba
/* vim:set et sw=2 ts=2: */
