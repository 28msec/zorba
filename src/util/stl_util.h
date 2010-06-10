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

#ifndef ZORBA_STL_UTIL_H
#define ZORBA_STL_UTIL_H

#include <algorithm>
#include <cassert>
#include <set>
#include <iterator>
#include <stack>

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
 * A less-verbose way to determine whether the given set<T> contains a
 * particular element.
 */
template<typename T> inline
bool contains( std::set<T> const &s, T const &t ) {
  return s.find( t ) != s.end();
}

/**
 * Like std::copy(), but copy at most N elements.
 */
template<typename InputIterator, typename SizeType, typename OutputIterator>
inline OutputIterator copy_n( InputIterator first, SizeType count, 
                              OutputIterator result ) {
  for ( SizeType i = 0; i < count; ++i, *result++ = *first++ )
    ;
  return result;
}

/**
 * A less-verbose way to copy the given sequence.
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

/**
 * A less-verbose way to pop the first element from a sequence.
 */
template<typename SequenceType> inline
typename SequenceType::value_type pop_front( SequenceType &seq ) {
  typename SequenceType::value_type const value( seq.front() );
  seq.pop_front();
  return value;
}

template<typename T> class stack_generator {
  std::stack<T> &stk;
public:
  stack_generator (std::stack<T> &stk_) : stk (stk_) { }
  T operator()() {
    assert( !stk.empty() );
    T const x = stk.top();
    stk.pop();
    return x;
  }
};

template<typename T> inline
stack_generator<T> stack_to_generator(std::stack<T> &stk) {
  return stack_generator<T>( stk );
}

} // namespace zorba
#endif  /* ZORBA_STL_UTIL_H */
/* vim:set et sw=2 ts=2: */
