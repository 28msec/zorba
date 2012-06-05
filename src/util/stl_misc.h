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

#ifndef ZORBA_STL_MISC_H
#define ZORBA_STL_MISC_H

#include <zorba/config.h>

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_CXX_NULLPTR


#endif /* ZORBA_CXX_NULLPTR */

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_CXX_STATIC_ASSERT

template<bool> struct zorba_static_assert;  // intentionally undefined
template<>     struct zorba_static_assert<true> { };
template<int>  struct zorba_static_assert_type { };

#define static_assert(expr,msg)                   \
  typedef ::zorba_static_assert_type<             \
    sizeof( ::zorba_static_assert<(expr) != 0> )  \
  > zorba_static_assert_type_##__LINE__

#endif /* ZORBA_CXX_STATIC_ASSERT */

///////////////////////////////////////////////////////////////////////////////

#endif /* ZORBA_STL_MISC_H */
/* vim:set et sw=2 ts=2: */
