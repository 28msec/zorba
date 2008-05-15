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
#ifndef WIN32_COMPATIBLE_DEFS_WITH_GNU_25_JULY_2007
#define WIN32_COMPATIBLE_DEFS_WITH_GNU_25_JULY_2007

#include <iostream>
//#include <io.h>

#include "common/config/stdint.h"

#ifdef WINCE
#include "strport.h"
#include "sys/timeb.h"
#endif

typedef unsigned long ulong;
// typedef __int64		int64_t;
// typedef unsigned __int64	uint64_t;
typedef unsigned short		uint16_t;
typedef unsigned char			uint8_t;
// typedef short int					int16_t;

//typedef uint32_t  __int32;

#ifdef _WIN32_WCE
typedef long	off_t;
#endif


#define  strcasecmp		_stricmp

#define		isatty			_isatty
#define		fileno			_fileno


namespace __gnu_cxx{
 
   // This iterator adapter is 'normal' in the sense that it does not
   // change the semantics of any of the operators of its iterator
   // parameter.  Its primary purpose is to convert an iterator that is
   // not a class, e.g. a pointer, into an iterator that is a class.
   // The _Container parameter exists solely so that different containers
   // using this template can instantiate different types, even if the
   // _Iterator parameter is the same.
   using std::iterator_traits;
   using std::iterator;
   template<typename _Iterator, typename _Container>
     class __normal_iterator
     {
     protected:
       _Iterator _M_current;
 
     public:
       typedef typename iterator_traits<_Iterator>::iterator_category
                                                              iterator_category;
       typedef typename iterator_traits<_Iterator>::value_type  value_type;
       typedef typename iterator_traits<_Iterator>::difference_type
                                                              difference_type;
       typedef typename iterator_traits<_Iterator>::reference reference;
       typedef typename iterator_traits<_Iterator>::pointer   pointer;
 
       typedef _Iterator _PlanIter_type;
 
       __normal_iterator() : _M_current(_Iterator()) { }
 
       explicit
       __normal_iterator(const _Iterator& __i) : _M_current(__i) { }
 
       // Allow iterator to const_iterator conversion
 /*daniel      template<typename _Iter>
         __normal_iterator(const __normal_iterator<_Iter,
               typename __enable_if<
                (std::__are_same<_Iter, typename _Container::pointer>::__value),
               _Container>::__type>& __i)
         : _M_current(__i.base()) { }
 */

       // Forward iterator requirements
       reference
       operator*() const
       { return *_M_current; }
 
       pointer
       operator->() const
       { return _M_current; }
 
       __normal_iterator&
       operator++()
       {
     ++_M_current;
     return *this;
       }
 
       __normal_iterator
       operator++(int)
       { return __normal_iterator(_M_current++); }
 
       // Bidirectional iterator requirements
       __normal_iterator&
       operator--()
       {
     --_M_current;
     return *this;
       }
 
       __normal_iterator
       operator--(int)
       { return __normal_iterator(_M_current--); }
 
       // Random access iterator requirements
       reference
       operator[](const difference_type& __n) const
       { return _M_current[__n]; }
 
       __normal_iterator&
       operator+=(const difference_type& __n)
       { _M_current += __n; return *this; }
 
       __normal_iterator
       operator+(const difference_type& __n) const
       { return __normal_iterator(_M_current + __n); }
 
       __normal_iterator&
       operator-=(const difference_type& __n)
       { _M_current -= __n; return *this; }
 
       __normal_iterator
       operator-(const difference_type& __n) const
       { return __normal_iterator(_M_current - __n); }
 
       const _Iterator&
       base() const
       { return _M_current; }
     };
 
   // Note: In what follows, the left- and right-hand-side iterators are
   // allowed to vary in types (conceptually in cv-qualification) so that
   // comparaison between cv-qualified and non-cv-qualified iterators be
   // valid.  However, the greedy and unfriendly operators in std::rel_ops
   // will make overload resolution ambiguous (when in scope) if we don't
   // provide overloads whose operands are of the same type.  Can someone
   // remind me what generic programming is about? -- Gaby
 
   // Forward iterator requirements
   template<typename _IteratorL, typename _IteratorR, typename _Container>
     inline bool
     operator==(const __normal_iterator<_IteratorL, _Container>& __lhs,
            const __normal_iterator<_IteratorR, _Container>& __rhs)
     { return __lhs.base() == __rhs.base(); }
 
   template<typename _Iterator, typename _Container>
     inline bool
     operator==(const __normal_iterator<_Iterator, _Container>& __lhs,
            const __normal_iterator<_Iterator, _Container>& __rhs)
     { return __lhs.base() == __rhs.base(); }
 
   template<typename _IteratorL, typename _IteratorR, typename _Container>
     inline bool
     operator!=(const __normal_iterator<_IteratorL, _Container>& __lhs,
            const __normal_iterator<_IteratorR, _Container>& __rhs)
     { return __lhs.base() != __rhs.base(); }
 
   template<typename _Iterator, typename _Container>
     inline bool
     operator!=(const __normal_iterator<_Iterator, _Container>& __lhs,
            const __normal_iterator<_Iterator, _Container>& __rhs)
     { return __lhs.base() != __rhs.base(); }
 
   // Random access iterator requirements
   template<typename _IteratorL, typename _IteratorR, typename _Container>
     inline bool
     operator<(const __normal_iterator<_IteratorL, _Container>& __lhs,
           const __normal_iterator<_IteratorR, _Container>& __rhs)
     { return __lhs.base() < __rhs.base(); }
 
   template<typename _Iterator, typename _Container>
     inline bool
     operator<(const __normal_iterator<_Iterator, _Container>& __lhs,
           const __normal_iterator<_Iterator, _Container>& __rhs)
     { return __lhs.base() < __rhs.base(); }
 
   template<typename _IteratorL, typename _IteratorR, typename _Container>
     inline bool
     operator>(const __normal_iterator<_IteratorL, _Container>& __lhs,
           const __normal_iterator<_IteratorR, _Container>& __rhs)
     { return __lhs.base() > __rhs.base(); }
 
   template<typename _Iterator, typename _Container>
     inline bool
     operator>(const __normal_iterator<_Iterator, _Container>& __lhs,
           const __normal_iterator<_Iterator, _Container>& __rhs)
     { return __lhs.base() > __rhs.base(); }
 
   template<typename _IteratorL, typename _IteratorR, typename _Container>
     inline bool
     operator<=(const __normal_iterator<_IteratorL, _Container>& __lhs,
            const __normal_iterator<_IteratorR, _Container>& __rhs)
     { return __lhs.base() <= __rhs.base(); }
 
   template<typename _Iterator, typename _Container>
     inline bool
     operator<=(const __normal_iterator<_Iterator, _Container>& __lhs,
            const __normal_iterator<_Iterator, _Container>& __rhs)
     { return __lhs.base() <= __rhs.base(); }
 
   template<typename _IteratorL, typename _IteratorR, typename _Container>
     inline bool
     operator>=(const __normal_iterator<_IteratorL, _Container>& __lhs,
            const __normal_iterator<_IteratorR, _Container>& __rhs)
     { return __lhs.base() >= __rhs.base(); }
 
   template<typename _Iterator, typename _Container>
     inline bool
     operator>=(const __normal_iterator<_Iterator, _Container>& __lhs,
            const __normal_iterator<_Iterator, _Container>& __rhs)
     { return __lhs.base() >= __rhs.base(); }
 
   // _GLIBCXX_RESOLVE_LIB_DEFECTS
   // According to the resolution of DR179 not only the various comparison
   // operators but also operator- must accept mixed iterator/const_iterator
   // parameters.
   template<typename _IteratorL, typename _IteratorR, typename _Container>
     inline typename __normal_iterator<_IteratorL, _Container>::difference_type
     operator-(const __normal_iterator<_IteratorL, _Container>& __lhs,
           const __normal_iterator<_IteratorR, _Container>& __rhs)
     { return __lhs.base() - __rhs.base(); }
 
   template<typename _Iterator, typename _Container>
     inline typename __normal_iterator<_Iterator, _Container>::difference_type
     operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
           const __normal_iterator<_Iterator, _Container>& __rhs)
     { return __lhs.base() - __rhs.base(); }
 
   template<typename _Iterator, typename _Container>
     inline __normal_iterator<_Iterator, _Container>
     operator+(typename __normal_iterator<_Iterator, _Container>::difference_type
           __n, const __normal_iterator<_Iterator, _Container>& __i)
     { return __normal_iterator<_Iterator, _Container>(__i.base() + __n); }
 
}//end namespace __gnu_cxx


#endif

