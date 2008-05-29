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
#ifndef ZORBA_CHECKED_VECTOR_H
#define ZORBA_CHECKED_VECTOR_H

#include <vector>

namespace zorba { 
  
template<typename T>
class checked_vector : public std::vector<T> 
{
public:
  checked_vector () {}
  checked_vector (int n) : std::vector<T> (n) {}
  checked_vector (const std::vector<T> &other)
    : std::vector<T> (other)
  {}
  checked_vector (const checked_vector<T> &other)
    : std::vector<T> (other)
  {}

  checked_vector<T> &operator= (const std::vector<T> &other) {
    std::vector<T>::operator= (other);
    return *this;
  }

  checked_vector<T> &operator= (const checked_vector<T> &other) {
    std::vector<T>::operator= (other);
    return *this;
  }

#ifndef NDEBUG
  T &operator[] (typename std::vector<T>::size_type i) { return std::vector<T>::at (i); }

  const T &operator[] (typename std::vector<T>::size_type i) const { return std::vector<T>::at (i); }
#endif
  };


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
