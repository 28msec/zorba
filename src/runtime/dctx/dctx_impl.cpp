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

#include "runtime/dctx/dctx.h"

#include "system/globalenv.h"

#include "runtime/visitors/planiter_visitor.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "store/api/item_factory.h"
#include "zorbatypes/integer.h"


namespace zorba
{
bool
DctxSnapshotIdIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );
  GENV_ITEMFACTORY->createUnsignedLong( result, xs_unsignedLong(planState.theGlobalDynCtx->getSnapshotID()) );
  STACK_PUSH( true, state );
  STACK_END( state );
}

}/* namespace zorba */
/* vim:set et sw=2 ts=2: */
