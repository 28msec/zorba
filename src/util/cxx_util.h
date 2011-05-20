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

#ifndef ZORBA_CXX_UTIL_H
#define ZORBA_CXX_UTIL_H

#include <zorba/config.h>

#ifndef ZORBA_CXX_NULLPTR
/**
 * See: http://www2.research.att.com/~bs/C++0xFAQ.html#nullptr
 */
class nullptr_t {
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
} const nullptr = {};                   // and whose name is nullptr
#endif /* ZORBA_CXX_NULLPTR */

#endif /* ZORBA_CXX_UTIL_H */
/* vim:set et sw=2 ts=2: */
