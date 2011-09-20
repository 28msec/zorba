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
#include "diagnostics/assert.h"

#include "ft_token_seq_iterator.h"

using namespace std;

namespace zorba {

FTTokenSeqIterator::FTTokenSeqIterator( FTTokens &tokens ) {
  tokens_.swap( tokens );
  pos_ = 0;
}

FTTokenSeqIterator::~FTTokenSeqIterator() {
  // do nothing
}

FTTokenIterator::index_t FTTokenSeqIterator::begin() const {
  return 0;
}

FTTokenIterator::index_t FTTokenSeqIterator::end() const {
  return (FTTokenIterator::index_t)tokens_.size();;
}

bool FTTokenSeqIterator::hasNext() const {
  return pos_ < tokens_.size();
}

FTToken const* FTTokenSeqIterator::next() {
  return pos_ < tokens_.size() ? &tokens_[ pos_++ ] : nullptr;
}

FTTokenIterator::Mark_t FTTokenSeqIterator::pos() const {
  return Mark_t( new LocalMark( pos_ ) );
}

void FTTokenSeqIterator::pos( Mark_t const &mark ) {
  pos_ = dynamic_cast<LocalMark const&>( *mark ).pos_;
}

void FTTokenSeqIterator::reset() {
  pos_ = 0;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
