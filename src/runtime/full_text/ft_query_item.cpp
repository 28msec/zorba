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

#include "util/cxx_util.h"
#include "util/stl_util.h"
#include "diagnostics/assert.h"

#include "ft_query_item.h"

namespace zorba {

////////// Constructors, destructor, initialization, cloning //////////////////

query_item_star_iterator::query_item_star_iterator( query_item_star_t &qis ) :
  qi_star_( &qis ), delete_( false )
{
  init();
}

query_item_star_iterator::query_item_star_iterator( query_item_star_t *qis ) :
  qi_star_( qis ), delete_( true )
{
  init();
}

query_item_star_iterator::~query_item_star_iterator() {
  if ( delete_ )
    delete qi_star_;
}

void query_item_star_iterator::init() {
  ZORBA_ASSERT( !qi_star_->empty() );
  reset();
}

///////////////////////////////////////////////////////////////////////////////

query_item_star_iterator::index_t query_item_star_iterator::begin() const {
  return qi_star_->front()->begin();
}

query_item_star_iterator::index_t query_item_star_iterator::end() const {
  return qi_star_->back()->end();
}

bool query_item_star_iterator::hasNext() const {
  if ( qi_ == qi_star_->end() )
    return false;
  if ( (*qi_)->hasNext() )
    return true;
  query_item_star_t::const_iterator qi( qi_ );
  if ( ++qi == qi_star_->end() )
    return false;
  return (*qi)->hasNext();
}

FTTokenIterator::Mark_t query_item_star_iterator::pos() const {
  LocalMark *const lmark = new LocalMark;
  lmark->qi_ = qi_;
  FOR_EACH( query_item_star_t, qi, *qi_star_ ) {
    lmark->marks_.push_back( (*qi)->pos() );
  }
  return Mark_t( lmark );
}

void query_item_star_iterator::pos( Mark_t const &mark ) {
  LocalMark const &lm = dynamic_cast<LocalMark const&>( *mark );
  ZORBA_ASSERT( qi_star_->size() == lm.marks_.size() );
  qi_ = lm.qi_;
  MarkSeq::const_iterator m = lm.marks_.begin();
  MUTATE_EACH( query_item_star_t, qi, *qi_star_ ) {
    (*qi)->pos( *m++ );
  }
}

FTToken const* query_item_star_iterator::next() {
  FTToken const *result = nullptr;
  if ( qi_ != qi_star_->end() ) {
    while ( !result ) {
      if ( (result = (*qi_)->next()) ) {
        if ( (*qi_)->hasNext() )
          break;
      }
      if ( ++qi_ == qi_star_->end() )
        break;
      (*qi_)->reset();
    }
  }
  return result;
}

void query_item_star_iterator::reset() {
  qi_ = qi_star_->begin();
  (*qi_)->reset();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
