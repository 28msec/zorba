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

#ifndef ZORBA_INTERNAL_TYPE_TRAITS_H
#define ZORBA_INTERNAL_TYPE_TRAITS_H

#include <zorba/config.h>

#ifdef ZORBA_TR1_IN_TR1_SUBDIRECTORY
# include <tr1/type_traits>
#else
# include <type_traits>
#endif

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_CXX_ENABLE_IF
namespace std {

/**
 * \internal
 * Define our own version of \c enable_if since g++ 4.2.1 (the version that
 * comes with Xcode 3.x) doesn't have \c enable_if.
 */
template<bool,typename T = void>
struct enable_if {
};

/**
 * \internal
 * Specialization of \c enable_if for the \c true case.
 */
template<typename T>
struct enable_if<true,T> {
  typedef T type;
};

} // namespace std
#endif /* ZORBA_CXX_ENABLE_IF */

///////////////////////////////////////////////////////////////////////////////

#endif /* ZORBA_INTERNAL_TYPE_TRAITS_H */
/* vim:set et sw=2 ts=2: */
