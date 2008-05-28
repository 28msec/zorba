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

#include "common/common.h"

namespace zorba {


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/

#ifdef HAVE_PTHREAD_H

#if defined HAVE_PTHREAD_SPINLOCK

class RCLock
{
protected:
  pthread_spinlock_t  theLock;

public:
  RCLock()
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

#elif defined HAVE_PTHREAD_MUTEX

class RCLock
{
protected:
  mutable pthread_mutex_t  theLock;

public:
  RCLock()
  {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK | PTHREAD_PROCESS_PRIVATE);
    if (0 != pthread_mutex_init(&theLock, &attr))
    {
      std::cerr << "Failed to initialize mutex" << std::endl; 
      abort();
    }
    pthread_mutexattr_destroy(&attr);
  } 

  ~RCLock()
  {
    if (0 != pthread_mutex_destroy(&theLock))
    {
      std::cerr << "Failed to destroy mutex" << std::endl; 
      abort();
    }
  } 

  void acquire()
  {
    if (0 != pthread_mutex_lock(&theLock))
    {
      std::cerr << "Failed to acquire mutex" << std::endl; 
      abort();
    }
  }

  void release()
  {
    if (0 != pthread_mutex_unlock(&theLock))
    {
      std::cerr << "Failed to release mutex" << std::endl; 
      abort();
    }
  }
};


#else
  #error must have pthread mutex or phread spinlock

#endif // HAVE_PTHREAD_SPINLOCK or HAVE_PTHREAD_MUTEX

#elif defined WIN32 || defined WINCE

class RCLock
{
protected:
  HANDLE    mutex;
public:
  RCLock()
  {
    mutex = ::CreateEvent(NULL, FALSE, TRUE, NULL);
  } 

  ~RCLock()
  {
    ::CloseHandle(mutex);
  } 

  void acquire()
  {
    ::WaitForSingleObject(mutex, INFINITE);
  }

  void release()
  {
    ::SetEvent(mutex);
  }
};
#endif // HAVE_PTHREAD_H or WIN32

//use this macro to activate or deactivate use of sync code
#define SYNC_CODE(x)    x
#define SYNC_PARAM2(x)  , x

#else // ZORBA_FOR_ONE_THREAD_ONLY

#define SYNC_CODE(x)    
#define SYNC_PARAM2(x)

#endif


/*******************************************************************************
  
  Base class for reference counted objects

  Any class wishing to take advantage of automatic reference counting
  must inherit from this class.

  rcobject encapsulates the reference count, as well as functions
  for incrementing and decrementing the count. It also contains code
  for destroying a value when it is no longer in use, i.e., when its
  reference count becomes 0.

********************************************************************************/
class RCObject
{
protected:
  mutable long  theRefCount;

public:
  RCObject() : theRefCount(0) { }

  RCObject(const RCObject&) : theRefCount(0) { }

  virtual ~RCObject() { }

  virtual void free() { delete this; }

  long getRefCount() const
  {
    return theRefCount;
  }

  void addReference(long* counter
                    SYNC_PARAM2(RCLock* lock)) const
  {
#if defined WIN32 && !defined CYGWIN &&!defined ZORBA_FOR_ONE_THREAD_ONLY
    if(lock)
    {
      if (counter) InterlockedIncrement(counter);
      InterlockedIncrement(&theRefCount);
    }
    else
    {
      if (counter) ++(*counter);
      ++theRefCount;
    }
#else
    SYNC_CODE(if (lock) lock->acquire());
    if (counter) ++(*counter);
    ++theRefCount;
    SYNC_CODE(if (lock) lock->release());
#endif
  }

  void removeReference (long* counter 
                        SYNC_PARAM2(RCLock* lock))
  {
#if defined WIN32 && !defined CYGWIN &&!defined ZORBA_FOR_ONE_THREAD_ONLY
    if(lock)
    {
      if (counter)
      {
        InterlockedDecrement(&theRefCount);
        if (!InterlockedDecrement(counter))
        {
          free();
          return;
        }
      }
      else if (!InterlockedDecrement(&theRefCount))
      {
        free();
        return;
      }
    }
    else
    {
      if (counter)
      {
        --theRefCount;
        if (--(*counter) == 0)
        {
          free();
          return;
        }
      }
      else if (--theRefCount == 0)
      {
        free();
        return; 
      }
    }
#else
    SYNC_CODE(if (lock) lock->acquire());
    if (counter)
    {
      --theRefCount;
      if (--(*counter) == 0)
      {
        SYNC_CODE(if (lock) lock->release());
        free();
        return;
      }
    }
    else if (--theRefCount == 0)
    {
      SYNC_CODE(if (lock) lock->release());
      free();
      return; 
    }
    SYNC_CODE(if (lock) lock->release());
#endif
  }

	RCObject& operator=(const RCObject&) { return *this; }
};


/*******************************************************************************

********************************************************************************/
class SimpleRCObject : public RCObject
{
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
  T  *p;

  void init()
  {
    if (p == 0) return;
    p->addReference(p->getSharedRefCounter()
                    SYNC_PARAM2(p->getRCLock()));
  }

  template <class otherT> rchandle& assign (const rchandle<otherT>& rhs)
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
      p->removeReference(p->getSharedRefCounter()
                          SYNC_PARAM2(p->getRCLock()));
    p = 0;
  }

  bool isNull () const        { return p == NULL; }

  T* getp() const             { return p; }

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


  template <class otherT> rchandle<otherT> cast() const {
    return rchandle<otherT> (static_cast<otherT *> (p));
  }

  template <class otherT> rchandle<otherT> dyn_cast() const {
    return rchandle<otherT> (dynamic_cast<otherT *> (p));
  }  

  template <class otherT> operator rchandle<otherT> () {
    return cast<otherT> ();
  }

  template <class otherT> operator const rchandle<otherT> () const {
    return cast<otherT> ();
  }

  rchandle& operator=(rchandle const& rhs) {
    return assign (rhs);
  }

	template <class otherT> rchandle& operator=(rchandle<otherT> const& rhs) {
    return assign (rhs);
	}

  template <class otherT> rchandle& transfer(rchandle<otherT>& rhs)
  {
		if (p != rhs.p)
    {
			if (p) p->removeReference(p->getSharedRefCounter()
                                SYNC_PARAM2(p->getRCLock()));
			p = static_cast<T*>(rhs.p);
			rhs.p = NULL;
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

  T* transfer()
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


template<class T> class const_rchandle : protected rchandle<T> {
public:
  const_rchandle (const T *_p = 0) : rchandle<T> (const_cast<T *> (_p)) {}
  const_rchandle (const const_rchandle &rhs) : rchandle<T> (rhs) {}
  const_rchandle (rchandle<T> &rhs) : rchandle<T> (rhs) {}
  const_rchandle& operator= (const const_rchandle &rhs) {
    assign (rhs);
    return *this;
  }

public:
  const T *getp () const { return rchandle<T>::getp (); }
  operator const T * () const { return rchandle<T>::getp (); }

  const T* operator->() const { return getp(); } 
  const T& operator*() const  { return *getp(); }

	bool operator== (const_rchandle h) const  { return rchandle<T>::operator== (h); }
	bool operator!= (const_rchandle h) const  { return rchandle<T>::operator!= (h); }
	bool operator== (const T * pp) const      { return rchandle<T>::operator== (pp); } 
	bool operator!= (const T * pp) const      { return rchandle<T>::operator!= (pp); } 
  bool operator< (const_rchandle h) const   { return rchandle<T>::operator<  (h); }
};


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
