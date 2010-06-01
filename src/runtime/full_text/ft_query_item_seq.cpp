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

#include "runtime/full_text/ft_query_item_seq.h"
#include "zorbaerrors/Assert.h"
#include "zorbautils/stl_util.h"

namespace zorba {

FTQueryItemSeqIterator::FTQueryItemSeqIterator( FTQueryItemSeq &qi_seq ) :
  qi_seq_( &qi_seq )
{
  ZORBA_ASSERT( !qi_seq_->empty() );
  reset();
}

FTQueryItemSeqIterator::index_t FTQueryItemSeqIterator::begin() const {
  return qi_seq_->front()->begin();
}

FTToken const& FTQueryItemSeqIterator::current() const {
  return (*qi_)->current();
}

bool FTQueryItemSeqIterator::empty() const {
  FOR_EACH( FTQueryItemSeq, qi, *qi_seq_ ) {
    if ( !(*qi)->empty() )
      return false;
  }
  return true;
}

FTQueryItemSeqIterator::index_t FTQueryItemSeqIterator::end() const {
  return qi_seq_->back()->end();
}

bool FTQueryItemSeqIterator::hasNext() const {
  if ( qi_ == qi_seq_->end() )
    return false;
  if ( (*qi_)->hasNext() )
    return true;
  FTQueryItemSeq::const_iterator qi( qi_ );
  if ( ++qi == qi_seq_->end() )
    return false;
  return (*qi)->hasNext();
}

void FTQueryItemSeqIterator::mark( bool set ) {
  if ( set )
    mark_ = qi_;
  else
    qi_ = mark_;
  (*qi_)->mark( set );
}

bool FTQueryItemSeqIterator::next( FTToken const **ppToken ) {
  bool got_next = false;
  if ( qi_ != qi_seq_->end() ) {
    while ( !got_next ) {
      if ( (*qi_)->next( ppToken ) ) {
        got_next = true;
        if ( (*qi_)->hasNext() )
          break;
        //
        // Unless qi_ is at the end, must always leave it at a position such
        // that (*qi_)->current() is valid.
        //
      }
      if ( ++qi_ == qi_seq_->end() )
        break;
      (*qi_)->reset();
    }
  }
  return got_next;
}

void FTQueryItemSeqIterator::reset() {
  mark_ = qi_ = qi_seq_->begin();
  (*qi_)->reset();
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
