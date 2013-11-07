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

#include "jsound_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool JSoundValidateIterator::nextImpl( store::Item_t &result,
                                       PlanState &plan_state ) const {
  store::Item_t item, json_item;
  zstring type_name;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  // $type-name as string
  consumeNext( item, theChildren[1], plan_state );
  type_name = item->getStringValue();

  // $item as json-item
  consumeNext( json_item, theChildren[2], plan_state );

  // $jsd as object
  consumeNext( item, theChildren[0], plan_state );

  { // local scope
    jsound::validator const validator( item );
    validator.validate( json_item, type_name, &result );
  }

  result = json_item;

  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
