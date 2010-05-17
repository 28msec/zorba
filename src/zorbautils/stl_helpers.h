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

#ifndef ZORBA_STL_HELPERS_H
#define ZORBA_STL_HELPERS_H

#include <algorithm>
#include <set>
#include <iterator>

namespace zorba {

/**
 * A less-verbose way to iterate over a constant sequence.
 */
#define FOR_EACH(TYPE,IT,SEQ) \
  for ( TYPE::const_iterator IT = (SEQ).begin(); IT != (SEQ).end(); ++IT )

/**
 * A less-verbose way to iterate over a mutable sequence.
 */
#define MUTATE_EACH(TYPE,IT,SEQ) \
  for ( TYPE::iterator IT = (SEQ).begin(); IT != (SEQ).end(); ++IT )

/**
 * A less-verbose way to pop the first element from a sequence.  This is done
 * as a macro rather than an inline template function because the former is
 * more efficient: the latter requires an extra construction/destruction.
 */
#define POP_FRONT(SEQ) \
  (SEQ).front(); (SEQ).pop_front()

/**
 * Determines whether the given set<T> contains a particular element in a
 * less-verbose way.
 */
template<typename T> inline
bool contains( std::set<T> const &s, T const &t ) {
  return s.find( t ) != s.end();
}

/**
 * Copies the given sequence in a less-verbose way.
 */
template<typename SequenceType> inline
void copy_seq( SequenceType const &from, SequenceType &to ) {
  std::copy( from.begin(), from.end(), std::back_inserter( to ) );
}

/**
 * Given a seq<T*>, deletes all the elements.
 */
template<typename SequenceType> inline
void delete_ptr_seq( SequenceType &seq ) {
  MUTATE_EACH( typename SequenceType, i, seq )
    delete *i;
}

/**
 * Moves the first element of the first sequence to the back of the second.
 */
template<typename SequenceType> inline
void move_front_to_back( SequenceType &from, SequenceType &to ) {
  to.push_back( from.front() );
  from.pop_front();
}

} // namespace zorba
#endif  /* ZORBA_STL_HELPERS_H */
/* vim:set et sw=2 ts=2: */
