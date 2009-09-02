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
#ifndef ZORBA_RCHANDLE_H
#define ZORBA_RCHANDLE_H

#include <sstream>
#include <iostream>
#include <cstdlib>

#include <zorba/config.h>
#include "common/common.h"
#include "zorbautils/fatal.h"

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"
#include <errno.h>


namespace zorba 
{


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/

#if defined ZORBA_HAVE_PTHREAD_SPINLOCK

class RCLock 
{
  pthread_spinlock_t theLock;

public:
  RCLock()
  {
    if (0 != pthread_spin_init(&theLock, PTHREAD_PROCESS_PRIVATE))
    {
      std::cerr << "Failed to initialize spinlock" << std::endl; 
    abort();
    }
  } 

  RCLock(const RCLock&)
  {
    if (0 != pthread_spin_init(&theLock, PTHREAD_PROCESS_PRIVATE))
    {
      std::cerr << "Failed to initialize spinlock" << std::endl; 
      abort();
    }
  }

  ~RCLock()
  {
    if (0 != pthread_spin_destroy(&theLock))
    {
      std::cerr << "Failed to destroy spinlock" << std::endl; 
      abort();
    }
  } 

  void acquire()
  {
    if (0 != pthread_spin_lock(&theLock))
    {
      std::cerr << "Failed to acquire spinlock" << std::endl; 
      abort();
    }
  }
  
  void release()
  {
    if (0 != pthread_spin_unlock(&theLock))
    {
      std::cerr << "Failed to release spinlock" << std::endl; 
      abort();
    }
  }
};
  

#elif defined ZORBA_HAVE_PTHREAD_MUTEX

class RCLock 
{
  mutable pthread_mutex_t  theLock;

public:

RCLock::RCLock()
{
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK | PTHREAD_PROCESS_PRIVATE);
  if (0 != pthread_mutex_init(&theLock, &attr))
  {
    std::cerr << "Failed to initialize RCLock" << std::endl; 
    abort();
  }
  pthread_mutexattr_destroy(&attr);
} 


RCLock::RCLock(const RCLock&)
{
  pthread_mutexattr_t attr;
  pthread_mutexattr_init(&attr);
  pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK | PTHREAD_PROCESS_PRIVATE);
  if (0 != pthread_mutex_init(&theLock, &attr))
  {
    std::cerr << "Failed to initialize RCLock" << std::endl; 
    abort();
  }
  pthread_mutexattr_destroy(&attr);
} 


RCLock::~RCLock()
{
  if (0 != pthread_mutex_destroy(&theLock))
  {
    std::cerr << "Failed to destroy RCLock" << std::endl; 
    abort();
  }
} 

void RCLock::acquire()
{
  if (0 != pthread_mutex_lock(&theLock))
  {
    std::cerr << "Failed to acquire RCLock" << std::endl; 
    abort();
  }

}

void RCLock::release()
{
  if (0 != pthread_mutex_unlock(&theLock))
  {
    std::cerr << "Failed to release RCLock" << std::endl; 
    abort();
  }
}
};


#elif defined WIN32 || defined WINCE

class RCLock 
{
public:
  RCLock() { }
  
  RCLock(const RCLock& ) { }

  ~RCLock() { } 

  void acquire() { }

  void release() { }
};

#else

#error must have pthread mutex or phread spinlock, or windows OS

#endif // ZORBA_HAVE_PTHREAD or WIN32

#endif // ZORBA_FOR_ONE_THREAD_ONLY


/*******************************************************************************
  
  Base class for reference counted objects

  Any class wishing to take advantage of automatic reference counting
  must inherit from this class.

  rcobject encapsulates the reference count, as well as functions
  for incrementing and decrementing the count. It also contains code
  for destroying a value when it is no longer in use, i.e., when its
  reference count becomes 0.

********************************************************************************/
class ZORBA_DLL_PUBLIC RCObject : public ::zorba::serialization::SerializeBaseClass
{
protected:
  mutable long  theRefCount;

public:
  SERIALIZABLE_ABSTRACT_CLASS(RCObject);

  RCObject(::zorba::serialization::Archiver& ar)  
    :
    ::zorba::serialization::SerializeBaseClass(),
    theRefCount(0)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar)
  {
    if(!ar.is_serializing_out())
      theRefCount = 0;
  }

public:
  RCObject()
    :
    ::zorba::serialization::SerializeBaseClass(),
    theRefCount(0)
  {
  }

  RCObject(const RCObject&) 
    :
    ::zorba::serialization::SerializeBaseClass(),
    theRefCount(0) 
  {
  }

  virtual ~RCObject() { }

  virtual void free() { delete this; }

  long getRefCount() const { return theRefCount; }

  long* getSharedRefCounter() const { return NULL; } 
 
  SYNC_CODE(RCLock* getRCLock() const { ZORBA_FATAL(0, ""); return NULL; })

  void addReference(long* sharedCounter SYNC_PARAM2(RCLock* lock)) const;

  void removeReference(long* shareCounter SYNC_PARAM2(RCLock* lock));

	RCObject& operator=(const RCObject&) { return *this; }
};


/*******************************************************************************

********************************************************************************/
class ZORBA_DLL_PUBLIC SimpleRCObject : public RCObject
{
public:
  SERIALIZABLE_ABSTRACT_CLASS(SimpleRCObject)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(SimpleRCObject, RCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    if(!ar.is_serializing_out())
      theRefCount = 0;
  }

public:
  SimpleRCObject() : RCObject() { }

  SimpleRCObject(const SimpleRCObject& rhs) : RCObject(rhs) { }

  long* getSharedRefCounter() const  { return NULL; } 

  SYNC_CODE(RCLock* getRCLock() const { return NULL; })

  SimpleRCObject& operator=(const SimpleRCObject&) { return *this; }
};


/*******************************************************************************

  rchandle = r(ef)c(ount)handle

  Template class for smart pointers-to-T objects. T must support the RCObject
  interface, typically by inheriting from RCObject

********************************************************************************/
template<class T> class rchandle
{
protected:
  T  * p;

protected:
  void init()
  {
    if (p == 0) return;
    p->addReference(p->getSharedRefCounter() SYNC_PARAM2(p->getRCLock()));
  }


  template <class otherT> rchandle& assign(const rchandle<otherT>& rhs)
  {
		if (p != rhs.getp())
    {
			if (p) p->removeReference(p->getSharedRefCounter()
                                SYNC_PARAM2(p->getRCLock()));
			p = static_cast<T*>(rhs.getp());
			init();
		}
		return *this;
  }

public:
  rchandle(T* realPtr = 0) : p(realPtr)
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
      p->removeReference(p->getSharedRefCounter() SYNC_PARAM2(p->getRCLock()));
    p = 0;
  }

  bool isNull () const        { return p == NULL; }
  void setNull()              { p = NULL;}

  T* getp() const             { return p; }
  T** getp_ref()              { return &p; }

  // rchandle const-ness is unclear. The implicit operators are more
  // restrictive than the explicit cast() and getp() methods.
  operator T* ()              { return getp(); }
  operator const T * () const { return getp(); }

  T* operator->() const       { return p; } 
  T& operator*() const        { return *p; } 

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
			if (p) p->removeReference(p->getSharedRefCounter()
                                SYNC_PARAM2(p->getRCLock()));
			p = const_cast<T*>(rhs);
			init();
		}
		return *this;
  }

	template <class otherT> rchandle& operator=(const otherT* rhs)
  {
		if (p != rhs)
    {
			if (p) p->removeReference(p->getSharedRefCounter()
                                SYNC_PARAM2(p->getRCLock()));
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
			if (p) p->removeReference(p->getSharedRefCounter()
                                SYNC_PARAM2(p->getRCLock()));
			p = static_cast<T*>(rhs.getp());
			rhs.setNull();
		}
		return *this;
  }

  rchandle& transfer(rchandle& rhs)
  {
		if (p != rhs.p)
    {
			if (p) p->removeReference(p->getSharedRefCounter()
                                SYNC_PARAM2(p->getRCLock()));
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

};


/*******************************************************************************

********************************************************************************/
template<class T> class const_rchandle : protected rchandle<T> 
{
public:
  const_rchandle (const T *_p = 0) : rchandle<T> (const_cast<T *> (_p)) {}

  const_rchandle (const const_rchandle &rhs) : rchandle<T> (rhs) {}

  const_rchandle (rchandle<T> &rhs) : rchandle<T> (rhs) {}

  const_rchandle(::zorba::serialization::Archiver &ar) {}

  const_rchandle& operator= (const const_rchandle &rhs) {
    assign (rhs);
    return *this;
  }

public:
  bool isNull () const        { return rchandle<T>::isNull(); }
  void setNull()              { rchandle<T>::setNull();}

  const T* getp () const { return rchandle<T>::getp (); }
  operator const T * () const { return rchandle<T>::getp (); }

  const T* operator->() const { return getp(); } 
  const T& operator*() const  { return *getp(); }

	bool operator== (const_rchandle h) const  { return rchandle<T>::operator== (h); }
	bool operator!= (const_rchandle h) const  { return rchandle<T>::operator!= (h); }
	bool operator== (const T * pp) const      { return rchandle<T>::operator== (pp); } 
	bool operator!= (const T * pp) const      { return rchandle<T>::operator!= (pp); } 
  bool operator< (const_rchandle h) const   { return rchandle<T>::operator<  (h); }
};


/*******************************************************************************

********************************************************************************/
namespace RCHelper 
{
  template<class T> 
  static void addReference(T *t) throw()
  {
    t->addReference(t->getSharedRefCounter()
                    SYNC_PARAM2(t->getRCLock()));
  }

  template<class T> 
  static void removeReference(T *t) throw()
  {
    t->removeReference(t->getSharedRefCounter()
                       SYNC_PARAM2(t->getRCLock()));
  }

  template<class T> 
  static void addReference(rchandle<T> &t) throw()
  {
    addReference (t.getp ());
  }
  
  template<class T> 
  static void removeReference(rchandle<T> &t) throw()
  {
    removeReference (t.getp ());
  }
};


} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

