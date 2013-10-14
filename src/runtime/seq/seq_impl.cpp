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

#include <zorba/config.h>
#include <zorba/internal/cxx_util.h>

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "runtime/seq/seq.h"
#include "runtime/seq/seq_util.h"
#include "types/typemanager.h"
#include "util/stl_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

inline Item_set_type* new_Item_set( TypeManager const *tm, long tz,
                                    XQPCollator *coll, QueryLoc const &loc ) {
  int lBucketCount =
#ifdef WIN32
        11
#else
        ztd::prime_rehash_policy::default_bucket_count
#endif /* WIN32 */
  ;

  return new Item_set_type(
    lBucketCount,
    Item_set_type::hasher(),
    Item_value_equal( tm, tz, coll, loc )
  );
}

static void delete_Item_set( Item_set_type *set ) {
  MUTATE_EACH( Item_set_type, i, *set )
    (*i)->removeReference();
  delete set;
}

///////////////////////////////////////////////////////////////////////////////

bool SeqValueIntersectIterator::nextImpl( store::Item_t &result,
                                          PlanState &plan_state ) const {
  XQPCollator *const coll = theSctx->get_default_collator( loc );
  store::Item_t item;
  TypeManager *const tm = getTypeManager();
  long tz;

  SeqValueIntersectIteratorState *state;
  DEFAULT_STACK_INIT( SeqValueIntersectIteratorState, state, plan_state );

  tz = plan_state.theLocalDynCtx->get_implicit_timezone();

  state->set_[0] = new_Item_set( tm, tz, coll, loc );
  state->set_[1] = new_Item_set( tm, tz, coll, loc );

  while ( consumeNext( item, theChildren[0], plan_state ) )
    if ( state->set_[0]->insert( item.getp() ).second )
      item->addReference();

  while ( consumeNext( item, theChildren[1], plan_state ) )
    if ( ztd::contains( *state->set_[0], item.getp() ) &&
         state->set_[1]->insert( item.getp() ).second ) {
      item->addReference();
      result = item;
      STACK_PUSH( true, state );
    }

  delete_Item_set( state->set_[0] );
  delete_Item_set( state->set_[1] );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SeqValueUnionIterator::nextImpl( store::Item_t &result,
                                      PlanState &plan_state ) const {
  XQPCollator *const coll = theSctx->get_default_collator( loc );
  store::Item_t item;
  TypeManager *const tm = getTypeManager();
  long tz;

  SeqValueUnionIteratorState *state;
  DEFAULT_STACK_INIT( SeqValueUnionIteratorState, state, plan_state );

  tz = plan_state.theLocalDynCtx->get_implicit_timezone();
  state->set_ = new_Item_set( tm, tz, coll, loc );

  for ( state->child_ = 0; state->child_ < 2; ++state->child_ )
    while ( consumeNext( item, theChildren[ state->child_ ], plan_state ) )
      if ( state->set_->insert( item.getp() ).second ) {
        item->addReference();
        result = item;
        STACK_PUSH( true, state );
      }

  delete_Item_set( state->set_ );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SeqValueExceptIterator::nextImpl( store::Item_t &result,
                                       PlanState &plan_state ) const {
  XQPCollator *const coll = theSctx->get_default_collator( loc );
  store::Item_t item;
  TypeManager *const tm = getTypeManager();
  long tz;

  SeqValueExceptIteratorState *state;
  DEFAULT_STACK_INIT( SeqValueExceptIteratorState, state, plan_state );

  tz = plan_state.theLocalDynCtx->get_implicit_timezone();
  state->set_ = new_Item_set( tm, tz, coll, loc );

  while ( consumeNext( item, theChildren[1], plan_state ) )
    if ( state->set_->insert( item.getp() ).second )
      item->addReference();

  while ( consumeNext( item, theChildren[0], plan_state ) )
    if ( state->set_->insert( item.getp() ).second ) {
      item->addReference();
      result = item;
      STACK_PUSH( true, state );
    }

  delete_Item_set( state->set_ );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
