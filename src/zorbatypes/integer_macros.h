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

// DO NOT PUT #pragma once HERE!
// DO NOT PUT #include GUARDS HERE!

#ifndef ZORBA_UNDEFINE_INTEGER_MACROS

#ifdef ZORBA_WITH_BIG_INTEGER
# define TEMPLATE_DECL(I)   /* nothing */
# define INTEGER_IMPL(I)    IntegerImpl
# define TEMPLATE_TYPENAME  /* nothing */
#else
# define TEMPLATE_DECL(I)   template<typename I> /* spacer */
# define INTEGER_IMPL(I)    IntegerImpl<I> /* spacer */
# define TEMPLATE_TYPENAME  typename
#endif /* ZORBA_WITH_BIG_INTEGER */

typedef long long z_int_type;
typedef unsigned long long z_uint_type;
#define INTEGER_IMPL_LL   INTEGER_IMPL(z_int_type)
#define INTEGER_IMPL_ULL  INTEGER_IMPL(z_uint_type)

#else /* ZORBA_UNDEFINE_INTEGER_MACROS */

#undef TEMPLATE_DECL
#undef TEMPLATE_TYPENAME
#undef INTEGER_IMPL
#undef INTEGER_IMPL_LL
#undef INTEGER_IMPL_ULL
#undef ZORBA_UNDEFINE_INTEGER_MACROS

#endif /* ZORBA_UNDEFINE_INTEGER_MACROS */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
