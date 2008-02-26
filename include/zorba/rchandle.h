#ifndef ZORBA_RCHANDLE_H
#define ZORBA_RCHANDLE_H

#include <string>
#include <sstream>
#include <iostream>

// TODO is this really needed here?
#include <zorba/hashfun.h>

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

      virtual void 
      free()                  { delete this; }

      long 
      getRefCount() const             { return theRefCount; }
      
      void 
      addReference(long& counter)     { ++counter; }
      
      void 
      removeReference(long& counter)  { if (--counter == 0) free(); }

      RCObject& 
      operator=(const RCObject&) { return *this; }
  };


  class SimpleRCObject : public RCObject
  {
    public:
      SimpleRCObject() : RCObject() { }

      SimpleRCObject(const SimpleRCObject& rhs) : RCObject(rhs) { }

      long& 
      getRefCounter() { return theRefCount; }  

      SimpleRCObject& 
      operator=(const SimpleRCObject&) { return *this; }
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

      bool 
      isNull () const        { return p == NULL; }

      T* 
      getp() const             { return p; }

      // rchandle const-ness is unclear. The implicit operators are more
      // restrictive than the explicit cast() and getp() methods.
      operator T* 
      ()              { return getp(); }
      
      operator const T*
      () const { return getp(); }

      T* 
      operator->() const       { return p; } 
      
      T& 
      operator*() const        { return *p; } 

      bool 
      operator==(rchandle const& h) const  { return p == h.p; }
      
      bool
      operator!=(rchandle const& h) const  { return p != h.p; }
      
      bool
      operator==(T const* pp) const        { return p == pp; } 
      
      bool
      operator!=(T const* pp) const        { return p != pp; }
      
      bool
      operator<(const rchandle& h) const   { return p < h.p; }

      template <class otherT> rchandle<otherT> 
      cast() const
      {
        return rchandle<otherT> (static_cast<otherT *> (p));
      }

      template <class otherT> 
      operator rchandle<otherT> ()
      {
        return cast<otherT> ();
      }

      template <class otherT>
      operator const rchandle<otherT> () const
      {
        return cast<otherT> ();
      }

      rchandle&
      operator=(rchandle const& rhs)
      {
        if (p != rhs.p)
        {
          if (p) p->removeReference(p->getRefCounter());
          p = rhs.p;
          init();
        }
        return *this;
      }

      template <class otherT> rchandle& 
      operator=(rchandle<otherT> const& rhs)
      {
        if (p != rhs.getp()) 
        {
          if (p) p->removeReference(p->getRefCounter());
          p = static_cast<T*>(rhs.getp());
          init();
        }
        return *this;
      }

      unsigned long
      hash() const
      {
        return hashfun::h32((void*)(&p), sizeof(void*), FNV_32_INIT);
      }

    public:
      std::string 
      debug() const;
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
} /* namespace xqp */
#endif

