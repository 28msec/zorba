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

#include "diagnostics/xquery_exception.h"
#include "runtime/jsound/jsound.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/typeops.h"
#include "zorbautils/store_util.h"

#include "jsound_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

#define IS_ATOMIC_TYPE(ITEM,TYPE) \
  ( (ITEM)->isAtomic() && IS_SUBTYPE( (ITEM)->getTypeCode(), TYPE ) )

#define IS_SUBTYPE(T,U) \
  TypeOps::is_subtype( (T), store::U )

static bool const cast_default = false;

///////////////////////////////////////////////////////////////////////////////

static bool get_bool_opt( store::Item_t const &object,
                          char const *opt_name, bool *result ) {
  store::Item_t opt_item;
  if ( get_json_option( object, opt_name, &opt_item ) ) {
    if ( !IS_ATOMIC_TYPE( opt_item, XS_BOOLEAN ) )
      throw XQUERY_EXCEPTION(
        jse::INVALID_OPTION,
        ERROR_PARAMS(
          opt_item->getStringValue(),
          opt_name,
          ZED( INVALID_OPTION_jse_MustBeBoolean )
        )
      );
    *result = opt_item->getBooleanValue();
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

bool JSoundAnnotateIterator::nextImpl( store::Item_t &result,
                                       PlanState &plan_state ) const {
  bool cast = cast_default;
  store::Item_t jsd_item, type_item, json_item, options_item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( jsd_item, theChildren[0], plan_state );
  consumeNext( type_item, theChildren[1], plan_state );
  consumeNext( json_item, theChildren[2], plan_state );
  //consumeNext( options_item, theChildren[3], plan_state );

  try {
    //get_bool_opt( options_item, "cast-atomic-values", &cast );
    jsound::schema const schema( jsd_item, theSctx );
    schema.validate( json_item, type_item->getStringValue(), cast, &result );
  }
  catch ( ZorbaException &e ) {
    set_source( e, loc, false );
    throw;
  }

  STACK_PUSH( true, state );
  STACK_END( state );
}

bool JSoundValidateIterator::nextImpl( store::Item_t &result,
                                       PlanState &plan_state ) const {
  bool cast = cast_default;
  store::Item_t jsd_item, type_item, json_item, options_item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( jsd_item, theChildren[0], plan_state );
  consumeNext( type_item, theChildren[1], plan_state );
  consumeNext( json_item, theChildren[2], plan_state );
  //consumeNext( options_item, theChildren[3], plan_state );

  try {
    //get_bool_opt( options_item, "cast-atomic-values", &cast );
    jsound::schema const schema( jsd_item, theSctx );
    GENV_ITEMFACTORY->createBoolean(
      result, schema.validate( json_item, type_item->getStringValue(), cast )
    );
  }
  catch ( ZorbaException &e ) {
    set_source( e, loc, false );
    throw;
  }

  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
