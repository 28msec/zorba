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

#ifndef ZORBA_MEM_SIZEOF
#define ZORBA_MEM_SIZEOF

#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <zorba/internal/ztd.h>

#include "util/stl_util.h"
#include "util/unordered_map.h"
#include "util/unordered_set.h"
#include "zorbatypes/zstring.h"

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace ztd {

/**
 * \file
 * This file provides the \c mem_sizeof() function that returns the total
 * amount of memory an object is using including any dynamically allocated
 * memory it has pointers to.  Hence \c mem_sizeof() takes a reference to an
 * actual object at run-time rather than only a type at compile-time like the
 * build-in C++ \c sizeof operator does.
 *
 * For all built-in types as well as arrays, structs, classes, and unions
 * composed of only built-in types, <code>mem_sizeof(t) == sizeof(t)</code>.
 * However, for a \c std::string \s,
 * <code>mem_sizeof(s) == sizeof(s) + s.size()</code>.
 *
 * To implement this, there has to be a distinction between
 * <em>memory size</em> (<code>mem_sizeof()</code)
 * and <em>allocation size</em> (<code>alloc_sizeof()</code).
 * The latter is how much \e additional memory has been dynamically allocated
 * by an object (if any).
 *
 * For all objects of built-in types as well as arrays, structs, classes, and
 * unions composed of only built-in types, <code>alloc_sizeof(t) == 0</code>
 * because those objects don't have any additional dynamically allocated memory.
 *
 * For structs and classes that \e do have additional dynamically allocated
 * memory, there has to be a way for \c alloc_sizeof() to be able to know how
 * much memory.
 * This can be accomplished by two different methods:
 *  <ol>
 *    <li>
 *      Template partial specialization of \c size_traits.
 *    </li>
 *    <li>
 *      Adding an \c alloc_size() member function to your class.
 *    </li>
 *  </ol>
 * Template partial specialization must be used
 * when you can not (or do not want to) modify a class.
 * However, this method may not always be able to report
 * all the dynamically allocated memory an object may be using.
 * It also has the code for a class and its template specialization
 * in different places in the code.
 *
 * Adding an \c alloc_size() member function
 * allows you to report the precise amount of memory an object is using
 * and also has the code directly in the class.
 * However, it is intrusive and adds a (possibly virtual) function.
 *
 * An example of template partial specialization is for \c std::string.
 * Since the source code for \c std::string can not be (easily) modified,
 * you must use template partial specialization for it.
 * \code
 *  template<>
 *  struct size_traits<std::string> {
 *    static size_t alloc_sizeof( std::string const &s ) {
 *      return s.size();
 *    }
 *  };
 * \endcode
 * This specialization, however, does not report all the memory
 * dynamically allocated by some implementations of \c std::string.
 * Some implementations use an additional "rep" object.
 * There's no way to determine whether a given implemenation uses one
 * much less how much memory it uses programatically,
 * but it's the best that can be done.
 *
 * An example of adding an \c alloc_size() member function is:
 * \code
 *  class my_class {
 *  public:
 *    // ...
 *    size_t alloc_size() const {
 *      return alloc_sizeof( s ) + mem_sizeof( *p );
 *    }
 *  private:
 *    int i;
 *    std::string s;
 *    some_other_class *p;
 *  };
 * \endcode
 * Notes:
 *  <ul>
 *    <li>
 *      Doing \c alloc_sizeof(i) isn't necessary since it returns 0.
 *      (You could do it if you wanted to for the sake of completeness
 *      without incurring any run-time penalty
 *      since the implementation of \c alloc_sizeof() for built-in C++ types
 *      is an \c inline function that always returns 0.
 *      The function will be optimized away by the compiler.)
 *    </li>
 *    <li>
 *      The reason it's \c mem_sizeof(*p) rather than \c alloc_sizeof(*p)
 *      is because the former adds in \c sizeof(*p)
 *      (which is what we want).
 *      For any pointer \c p, always use \c mem_sizeof(*p).
 *    </li>
 *  </ul>
 *
 * If your class has derived classes, then:
 *  <ol>
 *    <li>
 *      \c alloc_size() must be virtual.
 *    </li>
 *    <li>
 *      Derived classes must also implement of \c alloc_size()
 *      and they must call their base class's implementations.
 *    </li>
 *  </ol>
 * For example:
 * \code
 *  class my_derived_class : public my_class {
 *  public:
 *    // ...
 *    size_t alloc_size() const {
 *      return my_class::alloc_size() + alloc_size( u );
 *    }
 *  private:
 *    std::string u;
 *  };
 * \endcode
 */

///////////////////////////////////////////////////////////////////////////////

/**
 * Tests the given type to see if it's a class that has a member function
 * named \c alloc_size having the signature:
 * \code
 *  size_t (T::*)() const
 * \endcode
 * @tparam T The type to test.
 */
template<typename T>
class has_alloc_size : zorba::internal::ztd::sfinae_base {
  template<typename SignatureType,SignatureType> struct type_check;

  template<typename U>
  static yes& test( type_check<size_t (U::*)() const,&U::alloc_size>* );

  template<typename U>
  static no& test( ... );

public:
  static bool const value = sizeof( test<T>(0) ) == sizeof( yes );
};

/**
 * Size traits for classes that have an \c alloc_size() member function having
 * the signature:
 * \code
 *  size_t (T::*)() const
 * \endcode
 *
 * @tparam T The type to use.
 */
template<typename T,bool = has_alloc_size<T>::value>
struct size_traits {
  static size_t alloc_sizeof( T const &t ) {
    return t.alloc_size();
  }
};

/**
 * Specialization for any type.
 * @tparam T The type to use.
 */
template<typename T>
struct size_traits<T,false> {
  static size_t alloc_sizeof( T const& ) {
    return 0;
  }
};

/**
 * Gets the size of all the object's additional data.
 * It does \e not include the size of the object itself.
 *
 * @tparam T The type to get the data size of.
 * @param t An instance of \a T to get the data size of.
 */
template<typename T>
inline size_t alloc_sizeof( T const &t ) {
  return size_traits<T>::alloc_sizeof( t );
}

/**
 * Gets the total memory size of an object.
 *
 * @tparam T The type to get the data size of.
 * @param t An instance of \a T to get the memory size of.
 */
template<typename T>
inline size_t mem_sizeof( T const &t ) {
  return sizeof( T ) + alloc_sizeof( t );
}

////////// C++ Specializations ////////////////////////////////////////////////

/**
 * Specialization for std::string.
 */
template<>
struct size_traits<std::string> {
  static size_t alloc_sizeof( std::string const &s ) {
    return s.size();
  }
};

/**
 * Specialization for <code>char const*</code>.
 */
template<>
struct size_traits<char const*> {
  static size_t alloc_sizeof( char const *s ) {
    return s ? std::strlen( s ) : 0;
  }
};

/**
 * Size traits for a MapType&lt;T&gt;.
 * (This is a base class used by other specializations.)
 */
template<class MapType>
class map_size_traits {
protected:
  static size_t map_sizeof( MapType const &m ) {
    size_t total_size = 0;
    FOR_EACH( typename MapType, i, m )
      total_size += mem_sizeof( i->first ) + mem_sizeof( i->second );
    return total_size;
  }
};

/**
 * Specialization for std::map.
 */
template<typename K,typename V,typename Comp,class Alloc>
class size_traits<std::map<K,V,Comp,Alloc>,false> :
  map_size_traits< std::map<K,V,Comp,Alloc> >
{
  typedef std::map<K,V,Comp,Alloc> map_type;
  typedef map_size_traits<map_type> base_type;
public:
  static size_t alloc_sizeof( map_type const &m ) {
    return base_type::map_sizeof( m );
  }
};

/**
 * Specialization for std::unordered_map.
 */
template<typename K,typename V,class Hash,class Equal,class Alloc>
class size_traits<std::unordered_map<K,V,Hash,Equal,Alloc>,false> :
  map_size_traits< std::unordered_map<K,V,Hash,Equal,Alloc> >
{
  typedef std::unordered_map<K,V,Hash,Equal,Alloc> map_type;
  typedef map_size_traits<map_type> base_type;
public:
  static size_t alloc_sizeof( map_type const &m ) {
    return base_type::map_sizeof( m );
  }
};

/**
 * Size traits for a SequenceType&lt;T&gt;.
 * (This is a base class used by other specializations.)
 */
template<class SequenceType>
class sequence_size_traits {
protected:
  static size_t sequence_sizeof( SequenceType const &s ) {
    size_t total_size = 0;
    FOR_EACH( typename SequenceType, i, s )
      total_size += mem_sizeof( *i );
    return total_size;
  }
};

/**
 * Specialization for std::set.
 */
template<typename T,class Comp,class Alloc>
class size_traits<std::set<T,Comp,Alloc>,false> :
  sequence_size_traits< std::set<T,Comp,Alloc> >
{
  typedef std::set<T,Comp,Alloc> set_type;
  typedef sequence_size_traits<set_type> base_type;
public:
  static size_t alloc_sizeof( set_type const &s ) {
    return base_type::sequence_sizeof( s );
  }
};

/**
 * Specialization for std::stack.
 */
template<typename T,class Container>
class size_traits<std::stack<T,Container>,false> :
  sequence_size_traits< std::stack<T,Container> >
{
  typedef std::stack<T,Container> stack_type;
  typedef sequence_size_traits<stack_type> base_type;
public:
  static size_t alloc_sizeof( stack_type const &s ) {
    return base_type::sequence_sizeof( s );
  }
};

/**
 * Specialization for std::unordered_set.
 */
template<typename K,class Hash,class Equal,class Alloc>
class size_traits<std::unordered_set<K,Hash,Equal,Alloc>,false> :
  sequence_size_traits< std::unordered_set<K,Hash,Equal,Alloc> >
{
  typedef std::unordered_set<K,Hash,Equal,Alloc> set_type;
  typedef sequence_size_traits<set_type> base_type;
public:
  static size_t alloc_sizeof( set_type const &s ) {
    return base_type::sequence_sizeof( s );
  }
};

/**
 * Specialization for std::vector.
 */
template<typename T,class Alloc>
class size_traits<std::vector<T,Alloc>,false> :
  sequence_size_traits< std::vector<T,Alloc> >
{
  typedef std::vector<T,Alloc> vector_type;
  typedef sequence_size_traits<vector_type> base_type;
public:
  static size_t alloc_sizeof( vector_type const &v ) {
    return base_type::sequence_sizeof( v );
  }
};

////////// Zorba specializations //////////////////////////////////////////////

/**
 * Specialization for rstring.
 */
template<class RepType>
struct size_traits<rstring<RepType>,false> {
  static size_t alloc_sizeof( rstring<RepType> const &s ) {
    return s.size();
  }
};

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
#endif /* ZORBA_MEM_SIZEOF */
/* vim:set et sw=2 ts=2: */
