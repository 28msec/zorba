/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#include "runtime/jsound/jsound.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"

#include "jsound_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool JSoundAnnotateIterator::nextImpl( store::Item_t &result,
                                       PlanState &plan_state ) const {
  store::Item_t jsd_item, type_item, json_item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( jsd_item, theChildren[0], plan_state );
  consumeNext( type_item, theChildren[1], plan_state );
  consumeNext( json_item, theChildren[2], plan_state );

  { // local scope
    jsound::schema const schema( jsd_item );
    schema.validate( json_item, type_item->getStringValue(), &result );
  }

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool JSoundValidateIterator::nextImpl( store::Item_t &result,
                                       PlanState &plan_state ) const {
  store::Item_t jsd_item, type_item, json_item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( jsd_item, theChildren[0], plan_state );
  consumeNext( type_item, theChildren[1], plan_state );
  consumeNext( json_item, theChildren[2], plan_state );

  { // local scope
    jsound::schema const schema( jsd_item );
    GENV_ITEMFACTORY->createBoolean(
      result, schema.validate( json_item, type_item->getStringValue() )
    );
  }

  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
