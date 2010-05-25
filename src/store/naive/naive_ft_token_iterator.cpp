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
  tokens_( &tokens ), begin_( begin ), end_( end )
{
  ZORBA_ASSERT( end_ <= tokens_->size() );
  ZORBA_ASSERT( begin_ <= end_ );
  mark_ = pos_ = begin_;
}

FTTokenIterator::index_t NaiveFTTokenIterator::begin() const {
  return begin_;
}

FTToken const& NaiveFTTokenIterator::current() const {
  ZORBA_ASSERT( hasNext() );
  return (*tokens_)[ pos_ ];
}

bool NaiveFTTokenIterator::empty() const {
  return begin_ == end_;
}

FTTokenIterator::index_t NaiveFTTokenIterator::end() const {
  return end_;
}

bool NaiveFTTokenIterator::hasNext() const {
  return pos_ < end_;
}

void NaiveFTTokenIterator::mark( bool set ) {
  if ( set )
    mark_ = pos_;
  else
    pos_ = mark_;
}

bool NaiveFTTokenIterator::next( FTToken const **ppToken ) {
  if ( hasNext() ) {
    if ( ppToken )
      *ppToken = &(*tokens_)[ pos_ ];
    ++pos_;
    return true;
  }
  return false;
}

void NaiveFTTokenIterator::reset() {
  mark_ = pos_ = begin_;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
