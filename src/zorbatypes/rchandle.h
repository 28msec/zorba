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
#ifndef ZORBA_RCHANDLE_H
#define ZORBA_RCHANDLE_H

#include <sstream>
#include <errno.h>

#include <zorba/config.h>

#include "common/common.h"

#include "zorbautils/fatal.h"

#include "util/atomic_int.h"

#include "zorbaserialization/class_serializer.h"


namespace zorba
{

namespace serialization
{
  class archiver;
}


/*******************************************************************************
  
  Base class for reference counted objects

  Any class wishing to take advantage of automatic reference counting
  must inherit from this class.

  rcobject encapsulates the reference count, as well as functions
  for incrementing and decrementing the count. It also contains code
  for destroying a value when it is no longer in use, i.e., when its
  reference count becomes 0.

********************************************************************************/
class SyncedRCObject : public serialization::SerializeBaseClass
{
protected:
#ifdef ZORBA_FOR_ONE_THREAD_ONLY
  mutable long       theRefCount;
#else
  mutable atomic_int theRefCount;
#endif

public:
  SERIALIZABLE_CLASS(SyncedRCObject);

  SyncedRCObject(::zorba::serialization::Archiver& ar)  
    :
    ::zorba::serialization::SerializeBaseClass(),
    theRefCount(0)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar);

public:
  SyncedRCObject()
    :
    ::zorba::serialization::SerializeBaseClass(),
    theRefCount(0)
  {
  }

  SyncedRCObject(const SyncedRCObject&) 
    :
    ::zorba::serialization::SerializeBaseClass(),
    theRefCount(0) 
  {
  }

  virtual ~SyncedRCObject() { }

  SyncedRCObject& operator=(const SyncedRCObject&) { return *this; }

  virtual void free() { delete this; }

#ifdef ZORBA_FOR_ONE_THREAD_ONLY
  long getRefCount() const { return theRefCount; }
#else
  long getRefCount() const { return theRefCount.load(); }
#endif

  void addReference() const { ++theRefCount; }

  void removeReference() 
  {
    assert(getRefCount() > 0);

    if (--theRefCount == 0)
      free();
  }
};


/*******************************************************************************

********************************************************************************/
class ZORBA_DLL_PUBLIC SimpleRCObject : public serialization::SerializeBaseClass
{
protected:
  mutable long  theRefCount;

public:
  SERIALIZABLE_CLASS(SimpleRCObject);

  SimpleRCObject(serialization::Archiver& ar)  
    :
    serialization::SerializeBaseClass(),
    theRefCount(0)
  {
  }

  void serialize(serialization::Archiver& ar);

public:
  SimpleRCObject()
    :
    serialization::SerializeBaseClass(),
    theRefCount(0)
  {
  }

  SimpleRCObject(const SimpleRCObject&) 
    :
    serialization::SerializeBaseClass(),
    theRefCount(0) 
  {
  }

  virtual ~SimpleRCObject() { }

  virtual size_t alloc_size() const;
  virtual size_t dynamic_size() const;

  SimpleRCObject& operator=(const SimpleRCObject&) { return *this; }

  virtual void free() { delete this; }

  long getRefCount() const { return theRefCount; }

  void addReference() const { ++theRefCount; }

  void removeReference() 
  {
    assert(getRefCount() > 0);

    if (--theRefCount == 0)
      free();
  }
};


/*******************************************************************************

  rchandle = r(ef)c(ount)handle

  Template class for smart pointers-to-T objects. T must support the RCObject
  interface, typically by inheriting from RCObject

********************************************************************************/
template<class T> class rchandle
{
public:
  typedef T value_type;
  typedef value_type* pointer;
  typedef value_type const* const_pointer;
  typedef value_type& reference;
  typedef value_type const& const_reference;

protected:
  T  * p;

public:
  union union_T
  {
    T** t;
    void** v;
  };

public:
  rchandle(T* ptr = 0) : p(ptr)
  {
    init(); 
  }

  rchandle(rchandle const& rhs) : p(rhs.getp())
  {
    init();
  }

  ~rchandle()
  {
    if (p)
      p->removeReference();
    p = 0;
  }

  bool isNull () const { return p == NULL; }

  void setNull() { p = NULL;}

  T* getp() const { return p; }
  T* get() const { return p; }          // synonym to match unique_ptr

  union_T getp_ref() { union_T u_t; u_t.t = &p; return u_t;}

  // rchandle const-ness is unclear. The implicit operators are more
  // restrictive than the explicit cast() and getp() methods.
  operator T* ()              { return getp(); }

  operator const T * () const { return getp(); }

  T* operator->() const       { return p; } 

  T& operator*() const        { return *p; } 

  bool operator!() const      { return !p; }

  bool operator==(rchandle const& h) const  { return p == h.p; }
  bool operator!=(rchandle const& h) const  { return p != h.p; }
  bool operator==(T const* pp) const        { return p == pp; } 
  bool operator!=(T const* pp) const        { return p != pp; }
  bool operator<(const rchandle& h) const   { return p < h.p; }


  template <class otherT> rchandle<otherT> cast() const 
  {
    return rchandle<otherT> (static_cast<otherT *> (p));
  }

  template <class otherT> rchandle<otherT> dyn_cast() const 
  {
    return rchandle<otherT> (dynamic_cast<otherT *> (p));
  }  

  template <class otherT> operator rchandle<otherT> () 
  {
    return cast<otherT> ();
  }

  template <class otherT> operator const rchandle<otherT> () const 
  {
    return cast<otherT> ();
  }

  rchandle& operator=(const T* rhs) 
  {
    if (p != rhs)
    {
      if (p)
        p->removeReference();

      p = const_cast<T*>(rhs);

      init();
    }
    return *this;
  }

  template <class otherT> rchandle& operator=(const otherT* rhs)
  {
    if (p != rhs)
    {
      if (p)
        p->removeReference();

      p = static_cast<T*>(const_cast<otherT*>(rhs));

      init();
    }
    return *this;
  }

  rchandle& operator=(rchandle const& rhs) 
  {
    return assign (rhs);
  }

  template <class otherT> rchandle& operator=(rchandle<otherT> const& rhs) 
  {
    return assign (rhs);
  }

  template <class otherT> rchandle& transfer(rchandle<otherT>& rhs)
  {
    if (p != rhs.getp())
    {
      if (p)
        p->removeReference();

      p = static_cast<T*>(rhs.getp());

      rhs.setNull();
    }
    return *this;
  }

  rchandle& transfer(rchandle& rhs)
  {
    if (p != rhs.p)
    {
      if (p)
        p->removeReference();

      p = rhs.p;
      rhs.p = NULL;
    }
    return *this;
  }

  T* release()
  {
    T* tmp = p;
    p = NULL;
    return tmp;
  }

public:
  std::string debug() const
  {
    std::ostringstream oss;
    oss << "rchandle[refcount=" << p->getRefCount() << ']';
    return oss.str();
  }

protected:
  void init()
  {
    if (p)
      p->addReference();
  }


  template <class otherT> rchandle& assign(const rchandle<otherT>& rhs)
  {
    if (p != rhs.getp())
    {
      if (p)
        p->removeReference();

      p = static_cast<T*>(rhs.getp());

      init();
    }
    return *this;
  }

};


namespace ztd 
{

template<typename T> inline
std::string to_string(const rchandle<T>& r)
{
  return !r ? "<null>" : to_string( *r );
}


template<typename T,class OutputStringType> inline
void to_string(const rchandle<T>& r, OutputStringType* out )
{
  if ( !r )
    *out = "<null>";
  else
    to_string( *r, out );
}

} // namespace ztd


/*******************************************************************************

********************************************************************************/
template<class T> class const_rchandle : protected rchandle<T> 
{
public:
  const_rchandle(const T* _p = 0) : rchandle<T>(const_cast<T *>(_p)) {}

  const_rchandle(const const_rchandle& rhs) : rchandle<T>(rhs) {}

  const_rchandle(rchandle<T>& rhs) : rchandle<T>(rhs) {}

  const_rchandle(::zorba::serialization::Archiver& ar) {}

  const_rchandle& operator= (const const_rchandle& rhs)
  {
    this->assign(rhs);
    return *this;
  }

public:
  bool isNull () const { return rchandle<T>::isNull(); }

  void setNull() { rchandle<T>::setNull();}

  const T* getp() const { return rchandle<T>::getp (); }

  typename rchandle<T>::union_T getp_ref() { return rchandle<T>::getp_ref(); }

  operator const T* () const { return rchandle<T>::getp(); }

  const T* operator->() const { return getp(); } 
  const T& operator*() const  { return *getp(); }

  bool operator== (const_rchandle h) const  { return rchandle<T>::operator==(h); }
  bool operator!= (const_rchandle h) const  { return rchandle<T>::operator!=(h); }
  bool operator== (const T* pp) const       { return rchandle<T>::operator==(pp); } 
  bool operator!= (const T* pp) const       { return rchandle<T>::operator!=(pp); } 
  bool operator< (const_rchandle h) const   { return rchandle<T>::operator<(h); }
};



/*******************************************************************************

********************************************************************************/
namespace RCHelper 
{
  template<class T> 
  static void addReference(T *t)
  {
    t->addReference();
  }

  template<class T> 
  static void removeReference(T *t)
  {
    t->removeReference();
  }

  template<class T> 
  static void addReference(rchandle<T> &t)
  {
    addReference(t.getp());
  }
  
  template<class T> 
  static void removeReference(rchandle<T> &t)
  {
    removeReference(t.getp());
  }
};

} // namespace zorba

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
