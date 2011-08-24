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
#pragma once
#ifndef ZORBA_STL_UTIL_H
#define ZORBA_STL_UTIL_H

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iterator>
#include <set>
#include <stack>

#include <zorba/config.h>
#include <zorba/internal/ztd.h>

#include "cxx_util.h"

namespace zorba {
namespace ztd {

using internal::ztd::destroy_delete;
using internal::ztd::has_insertion_operator;
using internal::ztd::less;

///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

/**
 * An %auto_vec<T> is like the standard auto_ptr<T> but works where \c T is a
 * pointer to a \c T[] and so \c delete[] must be used.
 */
template<typename T> class auto_vec {
public:
  typedef T element_type;

  explicit auto_vec( element_type *p = nullptr ) throw() : p_( p ) {
  }

  auto_vec( auto_vec &a ) throw() : p_( a.release() ) {
  }

  template<typename U>
  auto_vec( auto_vec<U> &a ) throw() : p_( a.release() ) {
  }

  ~auto_vec() {
    delete[] p_;
  }

  auto_vec& operator=( auto_vec &a ) throw() {
    reset( a.release() );
    return *this;
  }

  template<typename U>
  auto_vec& operator=( auto_vec<U> &a ) throw() {
    reset( a.release() );
    return *this;
  }

  element_type* get() const throw() {
    return p_;
  }

  element_type* release() throw() {
    element_type *const tmp = p_;
    p_ = nullptr;
    return tmp;
  }

  void reset( element_type *p = nullptr ) throw() {
    if ( p != p_ ) {
      delete[] p_;
      p_ = p;
    }
  }

  element_type& operator*() const throw() {
    return *p_;
  }

  element_type& operator[]( int i ) const throw() {
    return p_[i];
  }

  operator bool() const throw() {
    return !!p_;
  }

  bool operator!() const throw() {
    return !p_;
  }

private:
  element_type *p_;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A version of std::back_insert_iterator that's suitable as a base-class (the
 * standard one is not).
 *
 * @tparam ContainerType The type of the container to insert into.
 * @tparam DerivedType The type of the class deriving from this.
 */
template<class ContainerType,class DerivedType>
class back_insert_iterator_base :
  public std::iterator<std::output_iterator_tag,void,void,void,void> {
public:
  typedef ContainerType container_type;

  DerivedType& operator*() {
    return *static_cast<DerivedType*>( this );
  }

  DerivedType& operator++() {
    return *static_cast<DerivedType*>( this );
  }

  DerivedType& operator++(int) {
    return *static_cast<DerivedType*>( this );
  }

protected:
  back_insert_iterator_base( ContainerType &c ) : container( &c ) {
  }

  /**
   * A pointer is used (rather than a reference) so this class can be copy
   * constructed.
   */
  ContainerType *container;
};

///////////////////////////////////////////////////////////////////////////////

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
template<class FromSequenceType,class ToSequenceType> inline
void copy_seq( FromSequenceType const &from, ToSequenceType &to ) {
  std::copy( from.begin(), from.end(), std::back_inserter( to ) );
}

/**
 * A less-verbose way to copy the given set.
 */
template<class FromSequenceType,class ToSequenceType> inline
void copy_set( FromSequenceType const &from, ToSequenceType &to ) {
  std::copy( from.begin(), from.end(), std::inserter( to, to.begin() ) );
}

/**
 * Given a seq<T*>, deletes all the elements.
 */
template<class SequenceType> inline
void delete_ptr_seq( SequenceType &seq ) {
  MUTATE_EACH( typename SequenceType, i, seq )
    delete *i;
}

/**
 * Erases the first element in the given sequence for which the given predicate
 * is \c true.
 *
 * @tparam SequenceType The sequence type.
 * @tparam PredicateType The predicate type.
 * @param seq The sequence to modify.
 * @param pred The predicate to use.
 * @return Returns \c true only if an element was erased; \c false otherwise.
 */
template<class SequenceType,class PredicateType> inline
bool erase_1st_if( SequenceType &seq, PredicateType pred ) {
  MUTATE_EACH( typename SequenceType, i, seq ) {
    if ( pred( *i ) ) {
      seq.erase( i );
      return true;
    }
  }
  return false;
}

/**
 * Moves the first element of the first sequence to the back of the second.
 */
template<class FromSequenceType,class ToSequenceType> inline
void move_front_to_back( FromSequenceType &from, ToSequenceType &to ) {
  to.push_back( from.front() );
  from.pop_front();
}

/**
 * Same as std::strdup(3) except it uses C++'s \c new[] rather than malloc(3).
 *
 * @param s The C string to duplicate.
 * @return Returns a copy of \a s.  Deallocation via \c delete[] is the
 * responsibility of the caller.
 */
inline char* new_strdup( char const *s ) {
  return std::strcpy( new char[ std::strlen( s ) + 1 ], s );
}

/**
 * A less-verbose way to pop the first element from a sequence.
 */
template<class SequenceType> inline
typename SequenceType::value_type pop_front( SequenceType &seq ) {
  typename SequenceType::value_type const value( seq.front() );
  seq.pop_front();
  return value;
}

/**
 * A less-verbose way to pop an element from a stack.
 */
template<class StackType> inline
typename StackType::value_type pop_stack( StackType &s ) {
  typename StackType::value_type const value( s.top() );
  s.pop();
  return value;
}

///////////////////////////////////////////////////////////////////////////////

template<typename T>
struct is_double {
  static bool const value = false;
};

template<>
struct is_double<double> {
  static bool const value = true;
};

template<typename T>
struct is_float {
  static bool const value = false;
};

template<>
struct is_float<float> {
  static bool const value = true;
};

template<typename NumericType> inline
typename std::enable_if<ZORBA_TR1_NS::is_signed<NumericType>::value,bool>::type
ge0( NumericType n ) {
  return n >= 0;
}

template<typename IntType> inline
typename std::enable_if<ZORBA_TR1_NS::is_unsigned<IntType>::value,bool>::type
ge0( IntType ) {
  return true;
}

///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
#endif  /* ZORBA_STL_UTIL_H */
/* vim:set et sw=2 ts=2: */
