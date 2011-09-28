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

#ifndef ZORBA_STRING_TRAITS_H
#define ZORBA_STRING_TRAITS_H

#include <string>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

template<class StringType>
struct string_traits {
  typedef typename StringType::rep_type rep_type;

  /**
   * Indicates whether construction or assignment from a non-const char* makes
   * the string take ownership of the char*.
   */
  enum { takes_pointer_ownership = rep_type::takes_pointer_ownership };
};

/**
 * Partial specialization of %string_traits for std::string.
 */
template<class CharType,class TraitsType,class Allocator>
struct string_traits< std::basic_string<CharType,TraitsType,Allocator> > {
  enum { takes_pointer_ownership = false };
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_STRING_TRAITS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
