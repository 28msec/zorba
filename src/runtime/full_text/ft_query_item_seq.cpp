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
  mark_ = qi_ = qi_seq_->begin();
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
  if ( qi_ != qi_seq_->end() ) {
    while ( true ) {
      if ( (*qi_)->hasNext() )
        return (*qi_)->next( ppToken );
      if ( ++qi_ == qi_seq_->end() )
        break;
      (*qi_)->reset();
    }
  }
  return false;
}

void FTQueryItemSeqIterator::reset() {
  MUTATE_EACH( FTQueryItemSeq, qi, *qi_seq_ ) {
    (*qi)->reset();
  }
  mark_ = qi_ = qi_seq_->begin();
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
