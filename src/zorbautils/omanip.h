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

#ifndef ZORBA_OMANIP_H
#define ZORBA_OMANIP_H

// standard
#include <iostream>

namespace zorba {

/**
 * An omanip is a class for assisting in the creating of ostream manipulators
 * by storing a pointer to a function and its argument to be called later via
 * operator<<().
 *
 * See also: "Standard C++ IOStreams and Locales," Angelika Langer and Klaus
 * Kreft, Addison-Wesley, pp. 179-191.
 */
template<typename ArgType> class omanip {
public:
  typedef std::ostream& (*func_type)( std::ostream&, ArgType );

  omanip( func_type f, ArgType const &arg ) : f_( f ), arg_( arg ) { }

  friend std::ostream& operator<<( std::ostream &o, omanip const &m ) {
    return (*m.f_)( o, m.arg_ );
  }
private:
  func_type const f_;
  ArgType const arg_;
};

#define DEF_OMANIP(FN_NAME,ARG_TYPE,ARG_NAME)             \
  inline omanip<ARG_TYPE> FN_NAME( ARG_TYPE ARG_NAME ) {  \
    return omanip<ARG_TYPE>( FN_NAME, ARG_NAME );         \
  }

} // namespace zorba

#endif  /* ZORBA_OMANIP_H */
/* vim:set et sw=2 ts=2: */
