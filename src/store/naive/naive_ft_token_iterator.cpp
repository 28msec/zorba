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

#include "store/naive/naive_ft_token_iterator.h"
#include "zorbaerrors/Assert.h"

using namespace std;

namespace zorba {

NaiveFTTokenIterator::NaiveFTTokenIterator( FTTokens const &tokens,
                                            index_t begin, index_t end ) :
  tokens_( tokens ), begin_( begin ), end_( end )
{
  ZORBA_ASSERT( end_ <= tokens_.size() );
  ZORBA_ASSERT( begin_ <= end_ );
  pos_ = begin_;
}

FTTokenIterator::index_t NaiveFTTokenIterator::begin() const {
  return begin_;
}

FTTokenIterator_t NaiveFTTokenIterator::clone() const {
  FTTokenIterator *const copy =
    new NaiveFTTokenIterator( tokens_, begin_, end_ );
  return FTTokenIterator_t( copy );
}

FTTokenIterator::index_t NaiveFTTokenIterator::end() const {
  return end_;
}

bool NaiveFTTokenIterator::hasNext() const {
  return pos_ < end_;
}

bool NaiveFTTokenIterator::next( FTToken const **ppToken ) {
  if ( pos_ < end_ ) {
    if ( ppToken )
      *ppToken = &tokens_[ pos_ ];
    ++pos_;
    return true;
  }
  return false;
}

FTTokenIterator::Mark_t NaiveFTTokenIterator::pos() const {
  return Mark_t( new LocalMark( pos_ ) );
}

void NaiveFTTokenIterator::pos( Mark_t const &mark ) {
  pos_ = dynamic_cast<LocalMark const&>( *mark ).pos_;
}

void NaiveFTTokenIterator::reset() {
  pos_ = begin_;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
