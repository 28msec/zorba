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
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>                      /* for pair */
#include <vector>

#include <zorba/internal/ztd.h>
#include <zorba/internal/unique_ptr.h>

#include "store/api/item_handle.h"
#include "util/stl_util.h"
#include "util/unordered_map.h"
#include "util/unordered_set.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "zorbautils/hashmap.h"

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace ztd {

/**
 * \file
 * This file provides the \c mem_sizeof() function that returns the total
 * amount of memory an object is using including any dynamically allocated
 * memory it has pointers to.  Hence \c mem_sizeof() takes a reference to an
 * actual object at run-time rather than only a type at compile-time like the
 * built-in C++ \c sizeof operator does.
 *
 * For all built-in types as well as arrays, structs, classes, and unions
 * composed of only built-in types, <code>mem_sizeof(t) == sizeof(t)</code>.
 * However, for a \c std::string \c s (for example),
 * <code>mem_sizeof(s) == sizeof(s) + s.capacity() + 1</code>.
 *
 * To implement this, there have to be distinctions among
 * <em>memory size</em> (<code>mem_sizeof()</code>),
 * <em>allocation size</em> (<code>alloc_sizeof()</code>),
 * and <em>dynamic size</em> (<code>dynamic_sizeof()</code>).
 * <em>Memory size</em> has already been explained.
 *
 * The <em>allocation size</em> is how much \e additional memory has been
 * dynamically allocated by an object (if any).
 *
 * For all objects of built-in types as well as arrays, structs, classes, and
 * unions composed of only built-in types, <code>alloc_sizeof(t) == 0</code>
 * because those objects don't have any additional dynamically allocated
 * memory.
 *
 * For structs and classes that \e do have additional dynamically allocated
 * memory, there has to be a way for \c alloc_sizeof() to be able to know how
 * much memory.
 * This can be accomplished by two different methods:
 *  <ol>
 *    <li>
 *      Template partial specialization of \c alloc_size_traits.
 *    </li>
 *    <li>
 *      Adding an \c alloc_size() member function to a class.
 *    </li>
 *  </ol>
 * Template partial specialization must be used
 * when you can not (or do not want to) modify a class.
 * However, this method may not always be able to report
 * all the dynamically allocated memory an object may be using.
 * It also has the code for a class and its template specialization
 * in different places in the code.
 *
 * Adding an \c alloc_size() member function allows you to report the precise
 * amount of memory an object is using and also has the code directly in the
 * class.
 * However, it is intrusive and adds a (possibly virtual) function.
 *
 * An example of template partial specialization is for \c std::string.
 * Since the source code for \c std::string can not be (easily) modified,
 * you must use template partial specialization for it.
 * \code
 *  template<>
 *  struct alloc_size_traits<std::string> {
 *    static size_t alloc_sizeof( std::string const &s ) {
 *      return s.capacity() + 1;
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
 *      return alloc_sizeof( s ) + alloc_sizeof( p );
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
 *      Calling \c alloc_sizeof(p) for a pointer automatically dereferences it
 *      (if it's non-null) and adds in the \c mem_sizeof(*p).
 *    </li>
 *  </ul>
 *
 * If a class has one or more derived classes
 * (and at least one derived class allocates additional memory
 * or contains a data member that does)
 * and you refer to objects of derived classes via base class references
 * or pointers,
 * then:
 *  <ol>
 *    <li>
 *      \c alloc_size() must be \c virtual.
 *      (It need not be otherwise.)
 *    </li>
 *    <li>
 *      A derived class must also implement of \c alloc_size()
 *      (but only if it allocates additional memory
 *      or contains a data member that does)
 *      and it must call its base class's implementation.
 *    </li>
 *  </ol>
 * For example:
 * \code
 *  class my_derived_class : public my_class {
 *  public:
 *    // ...
 *    size_t alloc_size() const {
 *      return my_class::alloc_size() + alloc_sizeof( u );
 *    }
 *  private:
 *    std::string u;
 *  };
 * \endcode
 *
 * The <em>dynamic size</em> is the size of an object's run-time type (similar
 * to \c dynamic_cast casting to an object's run-time type).
 * Dynamic size is only necessary for objects in a class hierarchy
 * and you refer to objects of derived classes via base class references
 * or pointers.
 *
 * Implementing dynamic size is always done by adding a virtual
 * \c dynamic_size() member function:
 * \code
 *  class my_class {
 *  public:
 *    // ...
 *    virtual size_t dynamic_size() const {
 *      return sizeof( *this );
 *    }
 *  };
 *
 *  class my_derived_class : public my_class {
 *  public:
 *    // ...
 *    size_t dynamic_size() const {
 *      return sizeof( *this );
 *    }
 *  };
 * \endcode
 * The body of the function is \e always as shown.
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
class has_alloc_size : ::zorba::internal::ztd::sfinae_base {
  template<typename SignatureType,SignatureType> struct type_check;

  template<typename U>
  static yes& test( type_check<size_t (U::*)() const,&U::alloc_size>* );

  template<typename U>
  static no& test( ... );

  //
  // The struct and friend declaration below suppress the "all member functions
  // are private" warning.
  //
  struct suppress_warning;
  friend struct suppress_warning;
public:
  static bool const value = sizeof( test<T>(0) ) == sizeof( yes );
};

/**
 * Tests the given type to see if it's a class that has a member function
 * named \c dynamic_size having the signature:
 * \code
 *  size_t (T::*)() const
 * \endcode
 * @tparam T The type to test.
 */
template<typename T>
class has_dynamic_size : ::zorba::internal::ztd::sfinae_base {
  template<typename SignatureType,SignatureType> struct type_check;

  template<typename U>
  static yes& test( type_check<size_t (U::*)() const,&U::dynamic_size>* );

  template<typename U>
  static no& test( ... );

  //
  // The struct and friend declaration below suppress the "all member functions
  // are private" warning.
  //
  struct suppress_warning;
  friend struct suppress_warning;
public:
  static bool const value = sizeof( test<T>(0) ) == sizeof( yes );
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Allocation size for classes that have an \c alloc_size() member function
 * having the signature:
 * \code
 *  size_t (T::*)() const
 * \endcode
 *
 * @tparam T The type to use.
 */
template<typename T,bool = has_alloc_size<T>::value>
struct alloc_size_traits {
  static size_t alloc_sizeof( T const &t ) {
    return t.alloc_size();
  }
};

/**
 * Allocation size specialization for all types that do \e not have an
 * \c alloc_size() member function having the signature:
 * \code
 *  size_t (T::*)() const
 * \endcode
 *
 * @tparam T The type to use.
 */
template<typename T>
struct alloc_size_traits<T,false> {
  static size_t alloc_sizeof( T const& ) {
    return 0;
  }
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Dynamic size for classes that have a \c dynamic_size() member function
 * having the signature:
 * \code
 *  size_t (T::*)() const
 * \endcode
 *
 * @tparam T The type to use.
 */
template<typename T,bool = has_dynamic_size<T>::value>
struct dynamic_size_traits {
  static size_t dynamic_sizeof( T const &t ) {
    return t.dynamic_size();
  }
};

/**
 * Dynamic size specialization for all types that do \e not have a
 * \c dynamic_size() member function having the signature:
 * \code
 *  size_t (T::*)() const
 * \endcode
 *
 * @tparam T The type to use.
 */
template<typename T>
struct dynamic_size_traits<T,false> {
  static size_t dynamic_sizeof( T const& ) {
    return sizeof( T );
  }
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Combined size traits.
 *
 * @tparam T The type to use.
 */
template<typename T>
struct size_traits : alloc_size_traits<T>, dynamic_size_traits<T> {
};

/**
 * Gets the size of an object's dynamically allocated data.
 * It does \e not include the size of the object itself.
 *
 * @tparam T The type to get the data size of.
 * @param t An instance of \a T to get the dynamically allocated size of.
 */
template<typename T>
inline size_t alloc_sizeof( T const &t ) {
  return size_traits<T>::alloc_sizeof( t );
}

/**
 * Gets the size of the object itself.
 * It does \e not include the size of an object's dynamically allocated data.
 *
 * @tparam T The type to get the size of.
 * @param t An instance of \a T to get the size of.
 */
template<typename T>
inline size_t dynamic_sizeof( T const &t ) {
  return size_traits<T>::dynamic_sizeof( t );
}

/**
 * Gets the total memory size of an object.
 *
 * @tparam T The type to get the memory size of.
 * @param t An instance of \a T to get the memory size of.
 */
template<typename T>
inline size_t mem_sizeof( T const &t ) {
  return dynamic_sizeof( t ) + alloc_sizeof( t );
}

///////////////////////////////////////////////////////////////////////////////

/**
 * Allocation size specialization for pointer types.
 * @tparam T A pointer type.
 */
template<typename T>
struct alloc_size_traits<T*,false> {
  static size_t alloc_sizeof( T *p ) {
    return p ? mem_sizeof( *p ) : 0;
  }
};

/**
 * Allocation size specialization for <code>char const*</code>.
 */
template<>
struct alloc_size_traits<char const*> {
  static size_t alloc_sizeof( char const *s ) {
    return s ? std::strlen( s ) + 1 /* terminating null */ : 0;
  }
};

////////// C++ Standard Library Specializations ///////////////////////////////

/**
 * Specialization for std::string.
 */
template<>
struct alloc_size_traits<std::string> {
  static size_t alloc_sizeof( std::string const &s ) {
    return s.capacity() + 1;
  }
};

/**
 * Allocation size traits for a MapType.
 * (This is a base class used by other specializations.)
 */
template<class MapType>
struct map_size_traits {
  static size_t alloc_sizeof( MapType const &m ) {
    size_t total_size = m.size() * value_type_padding;
    FOR_EACH( typename MapType, i, m )
      total_size += mem_sizeof( i->first ) + mem_sizeof( i->second );
    return total_size;
  }
private:
  static size_t const value_type_padding =
      sizeof( typename MapType::value_type )
    - sizeof( typename MapType::key_type )
    - sizeof( typename MapType::mapped_type );
};

/**
 * Allocation size traits for a SequenceType.
 * (This is a base class used by other specializations.)
 */
template<class SequenceType>
struct sequence_size_traits {
  static size_t alloc_sizeof( SequenceType const &s ) {
    size_t total_size = 0;
    FOR_EACH( typename SequenceType, i, s )
      total_size += mem_sizeof( *i );
    return total_size;
  }
};

/**
 * Specialization for std::deque.
 */
template<typename T,class Alloc>
struct alloc_size_traits<std::deque<T,Alloc>,false> :
  sequence_size_traits< std::deque<T,Alloc> >
{
};

/**
 * Specialization for std::list.
 */
template<typename T,class Alloc>
struct alloc_size_traits<std::list<T,Alloc>,false> :
  sequence_size_traits< std::list<T,Alloc> >
{
};

/**
 * Specialization for std::map.
 */
template<typename K,typename V,class Comp,class Alloc>
struct alloc_size_traits<std::map<K,V,Comp,Alloc>,false> :
  map_size_traits< std::map<K,V,Comp,Alloc> >
{
  typedef std::map<K,V,Comp,Alloc> sized_type;

  static size_t alloc_sizeof( sized_type const &m ) {
    return map_size_traits<sized_type>::alloc_sizeof( m )
      // assume two pointers per node, e.g, red-black tree
      + m.size() * sizeof( void* ) * 2;
  }
};

/**
 * Specialization for std::pair.
 */
template<typename T,typename U>
struct alloc_size_traits<std::pair<T,U>,false> {
  static size_t alloc_sizeof( std::pair<T,U> const &p ) {
    // yes, alloc_sizeof() is correct here
    return ztd::alloc_sizeof( p.first ) + ztd::alloc_sizeof( p.second );
  }
};

/**
 * Specialization for std::set.
 */
template<typename T,class Comp,class Alloc>
struct alloc_size_traits<std::set<T,Comp,Alloc>,false> :
  sequence_size_traits< std::set<T,Comp,Alloc> >
{
  typedef std::set<T,Comp,Alloc> sized_type;

  static size_t alloc_sizeof( sized_type const &s ) {
    return map_size_traits<sized_type>::alloc_sizeof( s )
      // assume two pointers per node, e.g, red-black tree
      + s.size() * sizeof( void* ) * 2;
  }
};

/**
 * Specialization for std::stack.
 */
template<typename T,class Container>
struct alloc_size_traits<std::stack<T,Container>,false> :
  sequence_size_traits< std::stack<T,Container> >
{
};

/**
 * Specialization for std::unique_ptr.
 */
template<typename T,class D>
struct alloc_size_traits<std::unique_ptr<T,D>,false> {
  static size_t alloc_sizeof( std::unique_ptr<T,D> const &p ) {
    return p ? mem_sizeof( *p ) : 0;
  }
};

/**
 * Specialization for std::unordered_map.
 */
template<typename K,typename V,class Hash,class Equal,class Alloc>
struct alloc_size_traits<std::unordered_map<K,V,Hash,Equal,Alloc>,false> :
  map_size_traits< std::unordered_map<K,V,Hash,Equal,Alloc> >
{
  typedef std::unordered_map<K,V,Hash,Equal,Alloc> sized_type;

  static size_t alloc_sizeof( sized_type const &m ) {
    return map_size_traits<sized_type>::alloc_sizeof( m )
      // assume 1 pointer per node and per bucket
      + (m.size() + m.bucket_count()) * sizeof( void* );
  }
};

/**
 * Specialization for std::unordered_set.
 */
template<typename K,class Hash,class Equal,class Alloc>
struct alloc_size_traits<std::unordered_set<K,Hash,Equal,Alloc>,false> :
  sequence_size_traits< std::unordered_set<K,Hash,Equal,Alloc> >
{
  typedef std::unordered_set<K,Hash,Equal,Alloc> sized_type;

  static size_t alloc_sizeof( sized_type const &m ) {
    return map_size_traits<sized_type>::alloc_sizeof( m )
      // assume 1 pointer per node and per bucket
      + (m.size() + m.bucket_count()) * sizeof( void* );
  }
};

/**
 * Specialization for std::vector.
 */
template<typename T,class Alloc>
struct alloc_size_traits<std::vector<T,Alloc>,false> :
  sequence_size_traits< std::vector<T,Alloc> >
{
  typedef std::vector<T,Alloc> sized_type;

  static size_t alloc_sizeof( sized_type const &v ) {
    return sequence_size_traits<sized_type>::alloc_sizeof( v )
      + (v.capacity() - v.size()) * sizeof( T );
  }
};

////////// Zorba specializations //////////////////////////////////////////////

/**
 * Specialization for ItemHandle.
 */
template<class T>
struct alloc_size_traits<store::ItemHandle<T>,false> {
  static size_t alloc_sizeof( store::ItemHandle<T> const &h ) {
    return h.isNull() ? 0 : mem_sizeof( *h );
  }
};

/**
 * Specialization for rstring.
 */
template<class RepType>
struct alloc_size_traits<rstring<RepType>,false> {
  static size_t alloc_sizeof( rstring<RepType> const &s ) {
    return s.capacity() + 1 + (s.is_shared() ? 0 : sizeof( RepType ));
  }
};

/**
 * Specialization for rchandle.
 */
template<class T>
struct alloc_size_traits<rchandle<T>,false> {
  static size_t alloc_sizeof( rchandle<T> const &h ) {
    return h.isNull() ? 0 : mem_sizeof( *h );
  }
};

/**
 * Specialization for HashMap.
 */
template<typename T,typename V,class C>
struct alloc_size_traits<HashMap<T,V,C>,false> {
  static size_t alloc_sizeof( HashMap<T,V,C> const &m ) {
    size_t total_size = 0;
    for ( typename HashMap<T,V,C>::const_iterator
        i = m.cbegin(); i != m.cend(); ++i ) {
      total_size += mem_sizeof( i.getKey() ) + mem_sizeof( i.getValue() );
    }
    return total_size;
  }
};

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
#endif /* ZORBA_MEM_SIZEOF */
/* vim:set et sw=2 ts=2: */
