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

#ifndef ZORBA_UNIQUE_PTR_H
#define ZORBA_UNIQUE_PTR_H

#include <zorba/config.h>

#ifdef ZORBA_CXX_UNIQUE_PTR
# include <memory>                      /* for unique_ptr */
# include <utility>                     /* for forward, move */
#else

#include <algorithm>                    /* for swap() */
#include "type_traits.h"

namespace std {

///////////////////////////////////////////////////////////////////////////////

template<typename T> inline
typename enable_if<!zorba::internal::is_movable<T>::value,T&>::type
move( T &t ) {
   return t;
}

template<typename T> inline
typename enable_if<zorba::internal::is_movable<T>::value,
                   zorba::internal::rv<T>&>::type
move( T &t ) {
   return *static_cast<zorba::internal::rv<T>*>( &t );
}

template<typename T> inline
typename enable_if<zorba::internal::is_movable<T>::value,
                   zorba::internal::rv<T>&>::type
move( zorba::internal::rv<T> &t ) {
  return t;
}

///////////////////////////////////////////////////////////////////////////////

/**
 * \internal
 * Storage for unique_ptr's pointer and deleter.
 *
 * @tparam T The pointed-to type.
 * @tparam D The deleter type.
 */
template<typename T,typename D,bool = ZORBA_TR1_NS::is_empty<D>::value>
class unique_ptr_storage {
  typedef typename ZORBA_TR1_NS::add_reference<D>::type deleter_reference;
  typedef zorba::internal::rv<unique_ptr_storage> rvalue_type;
public:
  T *ptr_;

  unique_ptr_storage( T *p ) throw() : ptr_( p ) {
  }

  unique_ptr_storage( T *p, deleter_reference d ) :
    ptr_( p ), deleter_( d )
  {
  }

  operator rvalue_type() throw() {
    return rvalue_type( *this );
  }

  deleter_reference deleter() throw() {
    return deleter_;
  }

private:
  D deleter_;
  // forbid
  unique_ptr_storage( unique_ptr_storage const& );
  unique_ptr_storage& operator=( unique_ptr_storage const& );
};

/**
 * \internal
 * Specialization of %unique_ptr_storage when the \c D is empty.
 *
 * @tparam T The pointed-to type.
 * @tparam D The deleter type.
 */
template<typename T,typename D>
class unique_ptr_storage<T,D,true> : private D {
  typedef zorba::internal::rv<unique_ptr_storage> rvalue_type;
public:
  T *ptr_;

  unique_ptr_storage( T *p ) throw() : ptr_( p ) {
  }

  unique_ptr_storage( T *p, D &d ) : D( d ), ptr_( p ) {
  }

  operator rvalue_type() throw() {
    return rvalue_type( *this );
  }

  D& deleter() throw() {
    return *this;
  }

private:
  // forbid
  unique_ptr_storage( unique_ptr_storage const& );
  unique_ptr_storage& operator=( unique_ptr_storage const& );
};

///////////////////////////////////////////////////////////////////////////////

/**
 * \internal
 * Swaps two unique_ptr objects.
 *
 * @param a The first object to swap.
 * @param b The second object to swap.
 */
template<typename T,typename D,bool IsEmpty> inline
void swap( unique_ptr_storage<T,D,IsEmpty> &a,
           unique_ptr_storage<T,D,IsEmpty> &b ) {
  std::swap( a.ptr_, b.ptr_ );
  std::swap( a.deleter(), b.deleter() );
}

///////////////////////////////////////////////////////////////////////////////

/**
 * \internal
 * The default deleter class used by unique_ptr.  It simply calls \c delete on
 * the pointed-to object.
 */
template<typename T>
struct default_delete {
  default_delete() { }

  /**
   * Copy constructor.
   *
   * @tparam U The type of the deleter to copy-construct from such that \c U*
   * is convertible to \c T*.
   */
  template<typename U>
  default_delete( default_delete<U> const&,
    typename enable_if<ZORBA_TR1_NS::is_convertible<U*,T*>::value>::type* = 0 )
  {
  }

  /**
   * Deletes the pointed-to object using \c delete.
   *
   * @param p A pointer to the object to delete.
   */
  void operator()( T *p ) const {
    delete p;
  }
};

///////////////////////////////////////////////////////////////////////////////

/**
 * \internal
 * Emulation of the C++11 std::unique_ptr.
 *
 * @tparam T The pointed-to type.
 * @tparam D The deleter to use, if any.  It must be either a function pointer
 * or a functor such that if \c d is of type \a D and \c p is of type \a T*,
 * then \c d(p) is valid and deletes the pointed-to object.  The deleter must
 * handle null pointers.  Note that \a D may be a reference type.
 */
template<typename T,class D = default_delete<T> >
class unique_ptr {
  typedef typename ZORBA_TR1_NS::add_reference<D>::type
          deleter_reference;

  typedef typename ZORBA_TR1_NS::add_reference<D const>::type
          deleter_const_reference;

  // see http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2333.html
  struct pointer_conversion { int valid; };
  typedef int pointer_conversion::*explicit_bool;

public:
  typedef T element_type;
  typedef T* pointer;
  typedef D deleter_type;

  /**
   * Default constructor.
   *
   * @param p A pointer to the object to point to, if any.
   */
  explicit unique_ptr( pointer p = 0 ) throw() : storage_( p ) {
  }

  /**
   * Constructs a %unique_ptr using a specific deleter.  This %unique_ptr now
   * has ownership of the pointed-to object.
   *
   * @param p A pointer to the object to own.
   * @param d The deleter to use.
   */
  unique_ptr( pointer p, deleter_reference d ) : storage_( p, d ) {
  }

  /**
   * Constructs a %unique_ptr from an existing %unique_ptr.  Note that:
   * \code
   *  unique_ptr<int> a( new int(1) );
   *  unique_ptr<int> b( a );           // compile-time error
   * \endcode
   * Instead, you must use the \c move() function:
   * \code
   *  unique_ptr<int> a( new int(1) );
   *  unique_ptr<int> b( move(a) );     // ok now
   * \endcode
   *
   * @param p The %unique_ptr to move from.
   */
  unique_ptr( zorba::internal::rv<unique_ptr> &p ) :
    storage_( p.release(), p.get_deleter() )
  {
  }

  /**
   * Constructs a %unique_ptr from an existing %unique_ptr 
   *
   * @tparam U The pointed-to type such that \c U* is convertible to \c T*.
   * @tparam E The deleter such that \c E is convertible to \c D.
   * @param p The %unique_ptr to move from.
   */
  template<typename U,typename E>
  unique_ptr( zorba::internal::rv<unique_ptr<U,E> > &p,
    typename enable_if<
      ZORBA_TR1_NS::is_convertible<typename unique_ptr<U>::pointer,
                                   pointer>::value &&
      ZORBA_TR1_NS::is_convertible<E,D>::value && (
        !ZORBA_TR1_NS::is_reference<D>::value ||
         ZORBA_TR1_NS::is_same<D,E>::value
      )
    >::type* = 0
  ) :
    storage_( p.release(), move<D>( p.get_deleter() ) )
  {
  }

  /**
   * Destroys the pointed-to object by calling the deleter (if the pointer is
   * not null).
   */
  ~unique_ptr() {
    call_deleter();
  }

  /**
   * Destructive assignment: moves ownership of the object pointed-to by \a p
   * to this %unique_ptr.  The object pointed-to by this %unique_ptr, if any,
   * is deleted.
   *
   * @param p The %unique_ptr to move from.
   * @return Returns \c *this.
   */
  unique_ptr& operator=( zorba::internal::rv<unique_ptr> &p ) {
    reset( p.release() );
    storage_.deleter() = move( p.get_deleter() );
    return *this;
  }

  /**
   * Destructive assignment: moves ownership of the object pointed-to by \a p
   * to this %unique_ptr.  The object pointed-to by this %unique_ptr, if any,
   * is deleted.
   *
   * @tparam U The pointed-to type such that \c U* is convertible to \c T*.
   * @tparam E The deleter of \a p.
   * @param p The %unique_ptr to move from.
   * @return Returns \c *this.
   */
  template<typename U,typename E>
  unique_ptr& operator=( zorba::internal::rv<unique_ptr<U,E> > &p ) {
    reset( p.release() );
    storage_.deleter() = move( p.get_deleter() );
    return *this;
  }

  /**
   * Assignment from null: equivalent to \c reset().
   *
   * @return Returns \c *this.
   */
  unique_ptr& operator=( int ) {
    reset();
    return *this;
  }

  /**
   * Dereferences the pointer.
   *
   * @return Returns a reference to the pointed-to object.
   */
  element_type& operator*() const throw() {
    return *get();
  }

  /**
   * Gets the pointer.
   *
   * @return Returns said pointer.
   */
  pointer operator->() const throw() {
    return get();
  }

  /**
   * Gets the pointer.
   *
   * @return Returns said pointer.
   */
  pointer get() const throw() {
    return storage_.ptr_;
  }

  /**
   * Gets the deleter in use.
   *
   * @return Returns said deleter.
   */
  deleter_reference get_deleter() throw() {
    return storage_.deleter();
  }

  /**
   * Gets the deleter in use.
   *
   * @return Returns said deleter.
   */
  deleter_const_reference get_deleter() const throw() {
    return storage_.deleter();
  }

  /**
   * Releases ownership of the pointed-to object.  Said object will now be the
   * responsibility of the caller.
   *
   * @return Returns a pointer to the object.
   */
  pointer release() throw() {
    pointer const temp = get();
    storage_.ptr_ = 0;
    return temp;
  }

  /**
   * Sets the pointer to the given value or null if none.  The previosly
   * pointed-to object, if any, is deleted.  However, if \a p equals the
   * current pointer value, then this function does nothing.
   *
   * @param p The new pointer value, if any.
   */
  void reset( pointer p = 0 ) throw() {
    if ( p != storage_.ptr_ ) {
      call_deleter();
      storage_.ptr_ = p;
    }
  }

  /**
   * Swaps the pointer and deleter with that of another %unique_ptr.
   *
   * @param p The %unique_ptr to swap with.
   */
  void swap( unique_ptr &p ) {
    std::swap( storage_, p.storage_ );
  }

  /**
   * Conversion to \c bool.
   *
   * @return Returns \c true only if the pointer is not null; \c false only if
   * the pointer is null.
   */
  operator explicit_bool() const throw() {
    return get() ? &pointer_conversion::valid : 0;
  }

private:
  unique_ptr_storage<T,D> storage_;

  void call_deleter() {
    if ( storage_.ptr_ )
      get_deleter()( storage_.ptr_ );
  }

  // forbid
  unique_ptr( unique_ptr& );
  unique_ptr& operator=( unique_ptr& );
  template<typename U,typename E> unique_ptr( unique_ptr<U,E>& );
  template<typename U,typename E> unique_ptr& operator=( unique_ptr<U,E>& );

public:
  operator ::zorba::internal::rv<unique_ptr>&() throw() {
    return *static_cast<zorba::internal::rv<unique_ptr>*>( this ); 
  }

  operator ::zorba::internal::rv<unique_ptr> const&() const throw() {
    return *static_cast<zorba::internal::rv<unique_ptr> const*>( this ); 
  }
};

///////////////////////////////////////////////////////////////////////////////

#define ZORBA_UNIQUE_PTR_RELOP(OP) \
  template<typename T1,typename D1,typename T2,typename D2> inline             \
  bool operator OP( unique_ptr<T1,D1> const &a, unique_ptr<T2,D2> const &b ) { \
    return a.get() OP b.get();                                                 \
  }

ZORBA_UNIQUE_PTR_RELOP(==)
ZORBA_UNIQUE_PTR_RELOP(!=)
ZORBA_UNIQUE_PTR_RELOP(< )
ZORBA_UNIQUE_PTR_RELOP(<=)
ZORBA_UNIQUE_PTR_RELOP(> )
ZORBA_UNIQUE_PTR_RELOP(>=)

#undef ZORBA_UNIQUE_PTR_RELOP

///////////////////////////////////////////////////////////////////////////////

/**
 * \internal
 * Swaps the pointed-to object and deleter of one unique_ptr with that of
 * another.
 *
 * @param a The first unique_ptr.
 * @param b The second unique_ptr.
 */
template<typename T,typename D> inline
void swap( unique_ptr<T,D> &a, unique_ptr<T,D> &b ) {
  a.swap( b );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace std

#endif /* ZORBA_CXX_UNIQUE_PTR */
#endif /* ZORBA_UNIQUE_PTR_H */
/* vim:set et sw=2 ts=2: */
