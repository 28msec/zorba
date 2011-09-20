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
#ifndef NONATOMIC_INT_H
#define NONATOMIC_INT_H

namespace zorba {

/**
 * A %nonatomic_int has the same API as atomic_int except that it doesn't use
 * atomic operations.  This class can be used when it's certain that atomic
 * operations are not needed.
 */
class nonatomic_int {
public:
  typedef int value_type;

  explicit nonatomic_int( value_type n = 0 ) : value_( n ) {
  }

  nonatomic_int volatile& operator=( value_type n ) volatile {
    value_ = n;
    return *this;
  }

  value_type load() const volatile {
    return value_;
  }

  void store( value_type n ) volatile {
    value_ = n;
  }

  value_type operator++() volatile {
    return ++value_;
  }

  value_type operator++(int) volatile {
    return value_++;
  }

  value_type operator--() volatile {
    return --value_;
  }

  value_type operator--(int) volatile {
    return value_--;
  }

  value_type operator+=( value_type n ) volatile {
    return value_ += n;
  }

  value_type operator-=( value_type n ) volatile {
    return value_ -= n;
  }

private:
  value_type volatile value_;

  // forbid for compatibility with atomic_int
  nonatomic_int( nonatomic_int const& );
  nonatomic_int& operator=( nonatomic_int& );
};

} // namespace zorba

#endif /* NONATOMIC_INT_H */
/* vim:set et sw=2 ts=2: */
