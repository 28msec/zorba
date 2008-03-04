/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: rchandle.h,v 1.1 2006/10/09 07:08:02 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  Apache License.
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_RCHANDLE_H
#define XQP_RCHANDLE_H

#include <sstream>
#include <iostream>

#include <zorba/common/common.h>
//#include <zorba/hashfun.h>

namespace zorba {


#ifndef ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/

#ifdef ZORBA_USE_PTHREAD_LIBRARY

#if defined HAVE_PTHREAD_SPINLOCK

class RCSync
{
protected:
  pthread_spinlock_t  theLock;

public:
  RCSync()
  {
    if (0 != pthread_spin_init(&theLock, PTHREAD_PROCESS_PRIVATE))
    {
      std::cerr << "Failed to initialize spinlock" << std::endl; 
      abort();
    }
  } 

  ~RCSync()
  {
    if (0 != pthread_spin_destroy(&theLock))
    {
      std::cerr << "Failed to destroy spinlock" << std::endl; 
      abort();
    }
  } 

  void lock()
  {
    if (0 != pthread_spin_lock(&theLock))
    {
      std::cerr << "Failed to acquire spinlock" << std::endl; 
      abort();
    }
  }

  void unlock()
  {
    if (0 != pthread_spin_unlock(&theLock))
    {
      std::cerr << "Failed to release spinlock" << std::endl; 
      abort();
    }
  }
};
#elif defined HAVE_PTHREAD_MUTEX

class RCSync
{
protected:
  pthread_mutex_t  theLock;

public:
  RCSync()
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

  ~RCSync()
  {
    if (0 != pthread_mutex_destroy(&theLock))
    {
      std::cerr << "Failed to destroy mutex" << std::endl; 
      abort();
    }
  } 

  void lock()
  {
    if (0 != pthread_mutex_lock(&theLock))
    {
      std::cerr << "Failed to acquire mutex" << std::endl; 
      abort();
    }
  }

  void unlock()
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

#elif WIN32
class RCSync
{
protected:
  HANDLE    mutex;
public:
  RCSync()
  {
    mutex = ::CreateEvent(NULL, FALSE, TRUE, NULL);
  } 

  ~RCSync()
  {
    ::CloseHandle(mutex);
  } 

  void lock()
  {
    ::WaitForSingleObject(mutex, INFINITE);
  }

  void unlock()
  {
    ::SetEvent(mutex);
  }
};
#else
  #error RCSync implemented for PTHREADs and WIN32

#endif // ZORBA_USE_PTHREAD_LIBRARY


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
class RCObject
{

#ifndef ZORBA_FOR_ONE_THREAD_ONLY
#define RCLOCK(sync)    if (sync != 0) sync->lock();
#define RCUNLOCK(sync)  if (sync != 0) sync->unlock();
#else
#define RCLOCK(sync)
#define RCUNLOCK(sync)
#endif

protected:
  mutable long  theRefCount;

public:
  RCObject() : theRefCount(0) { }

  RCObject(const RCObject& /*rhs*/) : theRefCount(0) { }

  virtual ~RCObject() { }

  virtual void free() { delete this; }

  long getRefCount(RCSync* sync) const
  {
    RCLOCK(sync);
    long temp = theRefCount;
    RCUNLOCK(sync);
    return temp;
  }

  void addReference(long& counter, RCSync* sync)
  {
#ifdef WIN32
    if(sync)
      InterlockedIncrement(&counter);
    else
      ++counter;
#else
    RCLOCK(sync);
    ++counter;
    RCUNLOCK(sync);
#endif
  }

  void removeReference(long& counter, RCSync* sync)
  {
#ifdef WIN32
    if(sync)
    {
      if(!InterlockedDecrement(&counter))
      {
        free();
        return;
      }
    }
    else
    {
      if (--counter == 0)
      {
        free();
        return;
      }
    }
#else
    RCLOCK(sync);
    if (--counter == 0)
    {
      RCUNLOCK(sync);
      free();
      return;
    }
    RCUNLOCK(sync);
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

  long& getRefCounter() { return theRefCount; }  
  RCSync* getSync()     { return NULL; }

  SimpleRCObject& operator=(const SimpleRCObject&) { return *this; }
};


/*******************************************************************************

  rchandle = r(ef)c(ount)handle

  Template class for smart pointers-to-T objects. T must support the RCObject
  interface, typically by inheriting from RCObject

********************************************************************************/
template<class T>
class rchandle
{
private:
  T  * p;

  void init()
  {
    if (p == 0) return;
    p->addReference(p->getRefCounter(), p->getSync());
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
      p->removeReference(p->getRefCounter(), p->getSync());
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


  template <class otherT> rchandle<otherT> cast() const
  {
    return rchandle<otherT> (static_cast<otherT *> (p));
  }

  template <class otherT> operator rchandle<otherT> ()
  {
    return cast<otherT> ();
  }

  template <class otherT> operator const rchandle<otherT> () const
  {
    return cast<otherT> ();
  }

  rchandle& operator=(rchandle const& rhs)
  {
    if (p != rhs.p)
    {
      if (p) p->removeReference(p->getRefCounter(), p->getSync());
      p = rhs.p;
      init();
    }
    return *this;
  }

	template <class otherT> rchandle& operator=(rchandle<otherT> const& rhs)
	{
		if (p != rhs.getp()) 
    {
			if (p) p->removeReference(p->getRefCounter(), p->getSync());
			p = static_cast<T*>(rhs.getp());
			init();
		}
		return *this;
	}

//unsigned long hash() const
//{
//  return hashfun::h32((void*)(&p), sizeof(void*), FNV_32_INIT);
//}

public:
	std::string debug() const
  {
    std::ostringstream oss;
    oss << "rchandle[refcount=" << p->getRefCount() << ']';
    return oss.str();
  }
}; 

} /* namespace zorba */

#endif

