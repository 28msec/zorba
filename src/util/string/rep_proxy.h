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

#ifndef ZORBA_RSTRING_REP_PROXY_H
#define ZORBA_RSTRING_REP_PROXY_H

#include <cassert>

namespace zorba {
namespace rstring_classes {

/******************************************************************************
  A proxy for either the default rep or the ptr rep.
********************************************************************************/
template<class Rep>
class rep_proxy 
{
public:
  typedef typename Rep::value_type value_type;

  typedef typename Rep::traits_type traits_type;

  typedef typename Rep::allocator_type allocator_type;

  typedef typename Rep::difference_type difference_type;
  typedef typename Rep::size_type size_type;

  typedef typename Rep::pointer pointer;
  typedef typename Rep::const_pointer const_pointer;
  typedef typename Rep::reference reference;
  typedef typename Rep::const_reference const_reference;

  typedef typename Rep::iterator iterator;
  typedef typename Rep::const_iterator const_iterator;
  typedef typename Rep::reverse_iterator reverse_iterator;
  typedef typename Rep::const_reverse_iterator const_reverse_iterator;

  typedef rep_proxy<typename Rep::result_rep_type> result_rep_type;

public:
  static const bool takes_pointer_ownership = false;

private:
  Rep * theRep;

public:
  /**
   *
   */
  static void assign( pointer to, size_type n, value_type c )
  {
    Rep::assign(to, n, c);
  }

  /**
   *
   */
  static void copy_chars( pointer to, const_pointer from, size_type n ) 
  {
    Rep::copy(to, from, n);
  }

  /**
   *
   */
  static void move_chars( pointer to, const_pointer from, size_type n ) 
  {
    Rep::move(to, from, n);
  }

public:
  /**
   *
   */
  rep_proxy() : theRep(Rep::empty_rep())
  {
  }

  /**
   *
   */
  ~rep_proxy()
  {
    assert(theRep == Rep::empty_rep());
  }

  /**
   *
   */
  bool is_shared() const 
  {
    return theRep->is_shared();
  }

  /**
   *
   */
  pointer data() const
  {
    return theRep->data();
  }

  /**
   *
   */
  size_type capacity() const 
  {
    return theRep->capacity(); 
  }

  /**
   *
   */
  size_type length() const 
  {
    return theRep->length();
  }

  /**
   *
   */
  void set_length( size_type n ) 
  {
    theRep->set_length(n);
  }

  /**
   *
   */
  bool operator==(const rep_proxy& other)
  {
    return theRep == other.theRep;
  }

  /**
   *
   */
  bool operator!=(const rep_proxy& other)
  {
    return theRep != other.theRep;
  }

  /**
   *
   */
  template<class IteratorType>
  void construct(IteratorType begin, IteratorType end, allocator_type const& a) 
  {
    assert(theRep == Rep::empty_rep());

    theRep = Rep::construct(begin, end, a);
  }

  /**
   *
   */
  void construct(size_type size, value_type c,  allocator_type const& a)
  {
    assert(theRep == Rep::empty_rep());

    theRep = Rep::construct(size, c, a);
  }


  /**
   * This method is used only in the mutate method of rstring, when copy-on-write
   * is necessary. It creates a representation with zero length and capacity >= to
   * the given capacity. The actual capacity is computed internally, taking into
   * account the given "old" capacity.
   */
  void realloc(size_type cap, size_type old_cap, allocator_type const& a)
  {
    assert(theRep == Rep::empty_rep());

    theRep = Rep::alloc(a, cap, old_cap);
    theRep->set_length(0);
  }

  /**
   *
   */
  void dispose(allocator_type const& a)
  {
    if (theRep)
      theRep->dispose(a);

    theRep = Rep::empty_rep();
  }

  /**
   *
   */
  void reserve( size_type cap, allocator_type const& a) 
  {
    theRep = theRep->reserve(cap, a);
  }

  /**
   *
   */
  void copy(
        const rep_proxy& other,
        allocator_type const& my_alloc,
        allocator_type const& other_alloc)
  {
    assert(theRep == Rep::empty_rep());

    if (other.theRep->is_sharable() && my_alloc == other_alloc)
    {
      if ( other.theRep != Rep::empty_rep() )
        other.theRep->inc();

      theRep = other.theRep;
    }
    else
    {
      theRep = other.theRep->clone(my_alloc);
    }
  }

  /**
   *
   */
  void take(
        rep_proxy& other,
        allocator_type const& my_alloc,
        allocator_type const& other_alloc)
  {
    assert(theRep == Rep::empty_rep());

    if (my_alloc == other_alloc) 
    {
      theRep = other.theRep;
      other.theRep = Rep::empty_rep();
    }
    else
    {
      theRep = other.theRep->clone(my_alloc);
    }
  }

  /**
   *
   */
  void swap(rep_proxy& other)
  {
    Rep* tmp = theRep;
    theRep = other.theRep;
    other.theRep = tmp;
  }

  /**
   * Makes the representation unsharable if necessary.  If it is currently
   * shared, it must be cloned.
   */
  void make_unsharable_if_necessary(allocator_type const& a) 
  {
    if ( theRep != Rep::empty_rep() ) 
    {
      typename Rep::count_type const count = theRep->count();

      if ( Rep::is_sharable( count ) ) 
      {
        if ( Rep::is_shared( count ) )
        {
          Rep* const new_rep = theRep->clone(a);

          dispose(a);

          theRep = new_rep;
        }

        theRep->set_unsharable();
      }
    }
  }

  /**
   *
   */
  void set_unsharable()
  {
    theRep->set_unsharable();
  }


  /**
   *
   */
  void set_sharable()
  {
    theRep->set_sharable();
  }

  /**
   *
   */
  bool is_sharable()
  {
    return theRep->is_sharable();
  }

private:
  // disabled
  rep_proxy(const rep_proxy&);

  // disabled
  rep_proxy& operator=(const rep_proxy&);
};


} // rstring_classes
} // zorba

#endif /* ZORBA_RSTRING_REP_PROXY_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
