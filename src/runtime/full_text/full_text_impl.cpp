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

#include <iostream>

#include "common/common.h"

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/utf8.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/full_text/full_text.h"
#include "runtime/api/runtimecb.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

using namespace std;

namespace zorba {

bool FTContainsIterator::nextImpl( store::Item_t &result,
                                   PlanState &planState ) const {
  store::Item_t item0;
  xqpStringStore_t arg2;
  bool ftcontains = false;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, planState );

  while ( consumeNext( item0, theChild0.getp(), planState ) ) {
    xqpStringStore_t lhs = item0->getStringValue();
    if ( lhs->empty() )
      continue;

    // TODO: ftcontains = lhs->positionOf( arg2, NULL ) != -1;
    if ( ftcontains )
      break;
  }

  STACK_PUSH( GENV_ITEMFACTORY->createBoolean( result, ftcontains ), state );
  STACK_END( state );
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
