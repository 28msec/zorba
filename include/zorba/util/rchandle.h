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

#include <string>
#include <sstream>
#include <iostream>

#include "util/hashfun.h"

namespace xqp {

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
  long theRefCount;

public:
  RCObject() : theRefCount(0) { }


  RCObject(const RCObject& /*rhs*/) : theRefCount(0) { }

  virtual ~RCObject() { }

  virtual void free()                  { delete this; }

  long getRefCount() const             { return theRefCount; }
  void addReference(long& counter)     { ++counter; }
  void removeReference(long& counter)  { if (--counter == 0) free(); }

	RCObject& operator=(const RCObject&) { return *this; }
};


class SimpleRCObject : public RCObject
{
public:
  SimpleRCObject() : RCObject() { }

  SimpleRCObject(const SimpleRCObject& rhs) : RCObject(rhs) { }

  long& getRefCounter() { return theRefCount; }  

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
  T  * p;      // dumb pointer this object emulates

  void init(); // common initialization

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
      p->removeReference(p->getRefCounter());
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
      if (p) p->removeReference(p->getRefCounter());
      p = rhs.p;
      init();
    }
    return *this;
  }

	template <class otherT> rchandle& operator=(rchandle<otherT> const& rhs)
	{
		if (p != rhs.getp()) 
    {
			if (p) p->removeReference(p->getRefCounter());
			p = static_cast<T*>(rhs.getp());
			init();
		}
		return *this;
	}

  unsigned long hash() const
  {
    return hashfun::h32((void*)(&p), sizeof(void*), FNV_32_INIT);
  }

public:
	std::string debug() const;
}; 


template<class T>
inline void rchandle<T>::init()
{
  if (p == 0) return;
  p->addReference(p->getRefCounter());
}

template<class T>
inline std::string rchandle<T>::debug() const
{
	std::ostringstream oss;
	oss << "rchandle[refcount=" << p->getRefCount() << ']';
	return oss.str();
}


#if 0
/*__________________________________________________________________________  
|                                                                           |           
|  rcihandle = r(ef)c(ount)i(ndirect)handle                                 |
|                                                                           |
|  rcihandle differs from rchandle in 2 ways:                               |
|                                                                           |
|    (1) rchandle objects point to values directly, while rcihandle objects |
|        point to values through intervening 'countholder' objects.         |
|                                                                           |
|    (2) rcihandle overloads operator-> and operator* so that a             |
|        copy-on-write is automatically performed whenever a non-const      |
|        access is made to a pointed-to object.                             |
|___________________________________________________________________________|*/

template<class T>
class rcihandle
{
private:
  struct CountHolder: public RCObject
	{
    ~CountHolder() { delete p; }
    T *p;
  };

  CountHolder *counter;
  void init();
  void makeCopy(); 

public:	// ctor, dtor
  rcihandle(T* realPtr = 0);
  rcihandle(const rcihandle& rhs);
  ~rcihandle();

public:	// operator overloading
  rcihandle& operator=(const rcihandle& rhs);
  const T* operator->() const; 
  T* operator->();            
  const T& operator*() const;
  T& operator*();           

	bool operator==(const rcihandle& h) const { return counter->p==h.counter->p; }
	bool operator!=(const rcihandle& h) const { return counter->p!=h.counter->p; }
	bool operator==(const T* pp) const { return counter->p==pp; }
	bool operator!=(const T* pp) const { return counter->p!=pp; }

};


template<class T>
inline void rcihandle<T>::init()
{
	if (counter->isShareable() == false) {
		T *oldValue = counter->p;
		counter = new CountHolder;
		counter->p = new T(*oldValue);
	}
  counter->addReference();
}


template<class T>
inline rcihandle<T>::rcihandle(T* realPtr)
: counter(new CountHolder)
{
  counter->p = realPtr;
  init();
}


template<class T>
inline rcihandle<T>::rcihandle(const rcihandle& rhs)
: counter(rhs.counter)
{
	init();
}


template<class T>
inline rcihandle<T>::~rcihandle()
{
	counter->removeReference();
}


template<class T>
inline rcihandle<T>& rcihandle<T>::operator=(const rcihandle& rhs)
{
  if (counter != rhs.counter) {
    counter->removeReference();
    counter = rhs.counter;
    init();
  }
  return *this;
}


template<class T>																	// implement the copy part
inline void rcihandle<T>::makeCopy()							// of copy-on-write (conw)
{ 
  if (counter->isShared()) {
    T *oldValue = counter->p;
    counter->removeReference();
    counter = new CountHolder;
    counter->p = new T(*oldValue);
    counter->addReference();
  }
}


template<class T>																	// const access,
inline const T* rcihandle<T>::operator->() const	// no conw needed
{
	return counter->p;
}


template<class T>																	// non-const access,
inline T* rcihandle<T>::operator->()							// conw needed
{
	makeCopy(); return counter->p;
} 


template<class T>																	// const access,
inline const T& rcihandle<T>::operator*() const		// no conw needed
{
	return *(counter->p);
}


template<class T>																	// non-const access,
inline T& rcihandle<T>::operator*()								// conw needed
{
	makeCopy(); return *(counter->p);
} 
#endif

}	/* namespace xqp */
#endif	/* XQP_RCHANDLE_H */

