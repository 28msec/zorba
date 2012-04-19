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
#ifndef ZORBA_STORE_ITEM_HANDLE_H
#define ZORBA_STORE_ITEM_HANDLE_H


namespace zorba 
{

namespace store
{


/*******************************************************************************
  Template class for smart pointers-to-T objects. T must be Item or a subclass
  of Item.
********************************************************************************/
template<class T> class ItemHandle
{
protected:
  T  * p;

public:
  union union_T
  {
    T** t;
    void** v;
  };

public:
  ItemHandle() : p(0)
  {
  }

  ItemHandle(T* ptr) : p(ptr)
  {
    if (p)
      p->addReference();
  }

  ItemHandle(const ItemHandle& rhs) : p(rhs.getp())
  {
    if (p)
      p->addReference();
  }

  ~ItemHandle()
  {
    if (p)
      p->removeReference();

    p = NULL; // do not remove
  }

  bool isNull () const { return p == NULL; }

  void setNull() { p = NULL; }

  T* getp() const { return p; }

  union_T getp_ref() { union_T u_t; u_t.t = &p; return u_t;}

  operator T* () { return getp(); }

  operator const T* () const { return getp(); }

  T* operator->() const { return p; } 

  T& operator*() const { return *p; } 

	bool operator==(const ItemHandle& h) const  { return p == h.p; }

	bool operator==(const T* pp) const { return p == pp; } 

	bool operator!=(const ItemHandle& h) const  { return p != h.p; }

	bool operator!=(const T* pp) const { return p != pp; }

  bool operator<(const ItemHandle& h) const { return p < h.p; }


  template <class otherT> ItemHandle<otherT> cast() const 
  {
    return ItemHandle<otherT> (static_cast<otherT *>(p));
  }

  template <class otherT> operator ItemHandle<otherT> () 
  {
    return cast<otherT>();
  }

  template <class otherT> operator const ItemHandle<otherT> () const 
  {
    return cast<otherT>();
  }

  ItemHandle& operator=(const T* rhs) 
  {
		if (p != rhs)
    {
			if (p) 
        p->removeReference();

			p = const_cast<T*>(rhs);

      if (p)
        p->addReference();      
		}

		return *this;
  }

  template <class otherT> ItemHandle& operator=(const otherT* rhs)
  {
		if (p != rhs)
    {
			if (p)
        p->removeReference();

			p = static_cast<T*>(const_cast<otherT*>(rhs));

      if (p)
        p->addReference();
		}
		return *this;
  }

  ItemHandle& operator=(const ItemHandle& rhs) 
  {
    return assign(rhs);
  }

	template <class otherT> ItemHandle& operator=(const ItemHandle<otherT>& rhs) 
  {
    return assign(rhs);
	}

  template <class otherT> ItemHandle& transfer(ItemHandle<otherT>& rhs)
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

  ItemHandle& transfer(ItemHandle& rhs)
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
    oss << "ItemHandle[refcount=" << p->getRefCount() << ']';
    return oss.str();
  }

protected:
  template <class otherT> ItemHandle& assign(const ItemHandle<otherT>& rhs)
  {
		if (p != rhs.getp())
    {
			if (p)
        p->removeReference();

			p = static_cast<T*>(rhs.getp());

      if (p)
        p->addReference();
		}

		return *this;
  }
};


} // namespace store
} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
