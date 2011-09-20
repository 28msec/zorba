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
#pragma once
#ifndef VOID_INT_H
#define VOID_INT_H

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %void_int has the same API as atomic_int except that it does no reference
 * counting.
 *
 * It can also take no space when derived from via the empty base class
 * optimization: http://www.cantrip.org/emptyopt.html
 */
class void_int {
public:
  typedef int value_type;

  explicit void_int( value_type = 0 ) {
  }

  void_int& operator=( value_type ) {
    return *this;
  }

  value_type load() const {
    return 0;
  }

  void store( value_type ) {
  }

  value_type operator++() {
    return 0;
  }

  value_type operator++(int) {
    return 0;
  }

  value_type operator--() {
    return 0;
  }

  value_type operator--(int) {
    return 0;
  }

  void_int& operator+=( value_type ) {
    return *this;
  }

  void_int& operator-=( value_type ) {
    return *this;
  }

private:
  // forbid for compatibility with atomic_int
  void_int( void_int const& );
  void_int& operator=( void_int& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* VOID_INT_H */
/* vim:set et sw=2 ts=2: */
