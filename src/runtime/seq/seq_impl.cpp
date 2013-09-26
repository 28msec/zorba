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

#include <algorithm>
#include <iterator>
#include <set>
#include <sstream>

#include <zorba/config.h>
#include <zorba/internal/cxx_util.h>
#include <zorba/diagnostic_list.h>
#include <zorba/store_consts.h>

#include "runtime/seq/seq.h"
#include "system/globalenv.h"
#include "types/casting.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "util/stl_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

typedef unordered_set<
  store::Item*,
  ztd::hash<store::Item*>,
  ztd::equal_to<store::Item*>
> Item_set_type;

static void remove_references( Item_set_type *set, int n ) {
  while ( n-- )
    MUTATE_EACH( Item_set_type, i, set[n] )
      (*i)->removeReference();
}

///////////////////////////////////////////////////////////////////////////////

SeqSetIntersectIteratorState::~SeqSetIntersectIteratorState() {
  remove_references( set_, 2 );
}

void SeqSetIntersectIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  remove_references( set_, 2 );
  set_[0].clear();
  set_[1].clear();
}

bool SeqSetIntersectIterator::nextImpl( store::Item_t &result,
                                        PlanState &plan_state ) const {
  store::Item_t item;

  SeqSetIntersectIteratorState *state;
  DEFAULT_STACK_INIT( SeqSetIntersectIteratorState, state, plan_state );

  while ( consumeNext( item, theChildren[0], plan_state ) )
    if ( state->set_[0].insert( item.getp() ).second )
      item->addReference();

  while ( consumeNext( item, theChildren[1], plan_state ) )
    if ( ztd::contains( state->set_[0], item.getp() ) &&
         state->set_[1].insert( item.getp() ).second ) {
      item->addReference();
      result = item;
      STACK_PUSH( true, state );
    }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

SeqSetUnionIteratorState::~SeqSetUnionIteratorState() {
  remove_references( &set_, 1 );
}

void SeqSetUnionIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  remove_references( &set_, 1 );
  set_.clear();
}

bool SeqSetUnionIterator::nextImpl( store::Item_t &result,
                                    PlanState &plan_state ) const {
  store::Item_t item;

  SeqSetUnionIteratorState *state;
  DEFAULT_STACK_INIT( SeqSetUnionIteratorState, state, plan_state );

  for ( state->child_ = 0; state->child_ < 2; ++state->child_ )
    while ( consumeNext( item, theChildren[ state->child_ ], plan_state ) )
      if ( state->set_.insert( item.getp() ).second ) {
        item->addReference();
        result = item;
        STACK_PUSH( true, state );
      }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

SeqSetExceptIteratorState::~SeqSetExceptIteratorState() {
  remove_references( &set_, 1 );
}

void SeqSetExceptIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  remove_references( &set_, 1 );
  set_.clear();
}

bool SeqSetExceptIterator::nextImpl( store::Item_t &result,
                                     PlanState &plan_state ) const {
  store::Item_t item;

  SeqSetExceptIteratorState *state;
  DEFAULT_STACK_INIT( SeqSetExceptIteratorState, state, plan_state );

  while ( consumeNext( item, theChildren[1], plan_state ) )
    if ( state->set_.insert( item.getp() ).second )
      item->addReference();

  while ( consumeNext( item, theChildren[0], plan_state ) )
    if ( state->set_.insert( item.getp() ).second ) {
      item->addReference();
      result = item;
      STACK_PUSH( true, state );
    }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/* vim:set et sw=2 ts=2: */
