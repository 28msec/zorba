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

#include "util/stl_util.h"
#include "zorbaerrors/Assert.h"

#include "ft_query_item.h"

namespace zorba {

////////// Constructors, destructor, initialization, cloning //////////////////

FTQueryItemSeqIterator::FTQueryItemSeqIterator( FTQueryItemSeq &qi_seq ) :
  qi_seq_( &qi_seq ), delete_seq_( false )
{
  init();
}

FTQueryItemSeqIterator::FTQueryItemSeqIterator( FTQueryItemSeq *qi_seq ) :
  qi_seq_( qi_seq ), delete_seq_( true )
{
  init();
}

FTQueryItemSeqIterator::~FTQueryItemSeqIterator() {
  if ( delete_seq_ )
    delete qi_seq_;
}

void FTQueryItemSeqIterator::init() {
  ZORBA_ASSERT( !qi_seq_->empty() );
  reset();
}

///////////////////////////////////////////////////////////////////////////////

FTQueryItemSeqIterator::index_t FTQueryItemSeqIterator::begin() const {
  return qi_seq_->front()->begin();
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

FTTokenIterator::Mark_t FTQueryItemSeqIterator::pos() const {
  LocalMark *const lmark = new LocalMark;
  lmark->qi_ = qi_;
  FOR_EACH( FTQueryItemSeq, qi, *qi_seq_ ) {
    lmark->marks_.push_back( (*qi)->pos() );
  }
  return Mark_t( lmark );
}

void FTQueryItemSeqIterator::pos( Mark_t const &mark ) {
  LocalMark const &lm = dynamic_cast<LocalMark const&>( *mark );
  ZORBA_ASSERT( qi_seq_->size() == lm.marks_.size() );
  qi_ = lm.qi_;
  MarkSeq::const_iterator m = lm.marks_.begin();
  MUTATE_EACH( FTQueryItemSeq, qi, *qi_seq_ ) {
    (*qi)->pos( *m++ );
  }
}

FTToken const* FTQueryItemSeqIterator::next() {
  FTToken const *result = 0;
  if ( qi_ != qi_seq_->end() ) {
    while ( !result ) {
      if ( (result = (*qi_)->next()) ) {
        if ( (*qi_)->hasNext() )
          break;
      }
      if ( ++qi_ == qi_seq_->end() )
        break;
      (*qi_)->reset();
    }
  }
  return result;
}

void FTQueryItemSeqIterator::reset() {
  qi_ = qi_seq_->begin();
  (*qi_)->reset();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
