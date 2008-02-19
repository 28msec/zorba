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
class rcobject
{
protected:
  long theRefCount;

public:
  rcobject() : theRefCount(0) { }

  rcobject(const rcobject& /*rhs*/) : theRefCount(0) { }

  virtual ~rcobject() { }

  virtual void free()              { delete this; }

	long getRefCount() const         { return theRefCount; }

  virtual void addReference()      { ++(theRefCount); }

  virtual void removeReference()   { if (--theRefCount == 0) this->free(); }

	rcobject& operator=(const rcobject&) { return *this; }
};


/*__________________________________________________________________________  
|                                                                           |
|  rchandle = r(ef)c(ount)handle                                            |
|                                                                           |
|  Template class for smart pointers-to-T objects. T must support the       |
|  rcobject interface, typically by inheriting from rcobject								| 
|___________________________________________________________________________|*/

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
      p->removeReference(); 
    p = 0;
  }

public:
  T* getp() const { return p; }
  bool isNull () const { return p==NULL; }

  template <class otherT> rchandle<otherT> cast () const
  {
    return rchandle<otherT> (static_cast<otherT *> (p));
  }

public:
  rchandle& operator=(rchandle const& rhs);

	template <class otherT> rchandle& operator=(rchandle<otherT> const& rhs)
	{
		if (p != rhs.getp()) {
			if (p) p->removeReference();
			p = static_cast<T*>(rhs.getp());
			init();
		}
		return *this;
	}

  T* operator->() const; 
  T& operator*() const;

  // rchandle const-ness is unclear.
  // The implicit operators are more restrictive than the explicit
  // cast() and getp() methods.
  operator T* () { return getp(); }
  operator const T * () const { return getp(); }
  template <class otherT> operator rchandle<otherT> () { return cast<otherT> (); }
  template <class otherT> operator const rchandle<otherT> () const { return cast<otherT> (); }

	bool operator==(rchandle const& h) const;
	bool operator!=(rchandle const& h) const;
	bool operator==(T const* pp) const;
	bool operator!=(T const* pp) const;
  bool operator<(const rchandle& h) const;
  unsigned long hash() const;

public:
	std::string debug() const;
}; 


template<class T>
inline T* rchandle<T>::operator->() const { return p; } 

template<class T>
inline T& rchandle<T>::operator*() const { return *p; } 

template<class T>
inline bool rchandle<T>::operator==(rchandle const& h) const { return p==h.p; }

template<class T>
inline bool rchandle<T>::operator!=(rchandle const& h) const { return p!=h.p; }

template<class T>
inline bool rchandle<T>::operator==(T const* pp) const { return p==pp; } 

template<class T>
inline bool rchandle<T>::operator!=(T const* pp) const { return p!=pp; }

template<class T>
bool rchandle<T>::operator<(const rchandle& h) const { return p < h.p; }

template<class T>
unsigned long rchandle<T>::hash() const
{
  return hashfun::h32((void*)(&p), sizeof(void*), FNV_32_INIT);
}


template<class T>
inline void rchandle<T>::init()
{
  if (p == 0) return;
  p->addReference();
}

template<class T>
inline rchandle<T>& rchandle<T>::operator=(rchandle const& rhs)
{
  if (p != rhs.p) {
    if (p) p->removeReference();
    p = rhs.p;
    init();
  }
  return *this;
}

template<class T>
inline std::string rchandle<T>::debug() const
{
	std::ostringstream oss;
	oss << "rchandle[refcount="<<p->get_refCount()<<']';
	return oss.str();
}


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
  struct CountHolder: public rcobject
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


}	/* namespace xqp */
#endif	/* XQP_RCHANDLE_H */

