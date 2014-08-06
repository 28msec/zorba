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

#ifndef ZORBA_INTERNAL_CXX_UTIL_H
#define ZORBA_INTERNAL_CXX_UTIL_H

#include <zorba/config.h>

///////////////////////////////////////////////////////////////////////////////

#if !defined( ZORBA_CXX_NULLPTR ) && !defined( nullptr )

namespace zorba {
namespace internal {

/**
 * \internal
 * A \c nullptr type for C++ compilers that don't yet implement C++11's
 * \c nullptr keyword.
 *
 * See http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2431.pdf
 * section 1.1: "Alternative #1: A Library Implementation of nullptr," p. 3.
 */
class nullptr_type {
public:
  template<typename T>                  // convertible to any type
  operator T*() const {                 // of null non-member
    return 0;                           // pointer...
  }
  template<class C,class T>             // or any type of null
  operator T C::*() const {             // member pointer...
    return 0;
  }
private:
  void operator&() const;               // whose address can't be taken
};

} // namespace internal
} // namespace zorba

/**
 * \internal
 * We use "zorba_nullptr" in combination with a macro to elimimate an
 * "identifier 'nullptr' will become a keyword in C++0x" warning.
 *
 * We also use a singleton object since using multiple instances as shown in
 * Bjarne's paper has a slight performance penalty (surprisingly).
 */
ZORBA_DLL_PUBLIC
extern zorba::internal::nullptr_type const zorba_nullptr;

#define nullptr ::zorba_nullptr

#endif /* ZORBA_CXX_NULLPTR */

///////////////////////////////////////////////////////////////////////////////

#if !defined( ZORBA_CXX_STATIC_ASSERT ) && !defined( static_assert )

template<bool> struct zorba_static_assert;  // intentionally undefined
template<>     struct zorba_static_assert<true> { };
template<int>  struct zorba_static_assert_type { };

#define static_assert_helper_2(EXPR,MSG,LINE)                             \
  typedef ::zorba_static_assert_type<                                     \
    sizeof( ::zorba_static_assert<(EXPR) != 0> )                          \
  > zorba_static_assert_type_##LINE;                                      \
  zorba_static_assert_type_##LINE zorba_static_assert_no_warning_##LINE;  \
  (void)zorba_static_assert_no_warning_##LINE

// See: http://stackoverflow.com/a/1597129/99089
#define static_assert_helper_1(EXPR,MSG,LINE) \
  static_assert_helper_2(EXPR,MSG,LINE)

/** 
 * \internal
 * A \c static_assert macro for C++ compilers that don't yet implement C++11's
 * \c static_assert keyword.
 * \hideinitializer
 */
#define static_assert(EXPR,MSG) \
  static_assert_helper_1(EXPR,MSG,__LINE__)

#endif /* ZORBA_CXX_STATIC_ASSERT */

///////////////////////////////////////////////////////////////////////////////

#endif /* ZORBA_INTERNAL_CXX_UTIL_H */
/* vim:set et sw=2 ts=2: */
