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
#ifndef ZORBA_OSEPARATOR_H
#define ZORBA_OSEPARATOR_H

#include <iostream>
#include <string>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %oseparator is useful for emitting lists of strings that are separated by
 * some other string, e.g.: "A, B, C" where ", " is the separator.
 */
class oseparator {
public:

  /**
   * Constructs an %oseparator.
   *
   * @param sep The separator string.
   */
  explicit oseparator( char const *sep = ", " ) : sep_( sep ), print_( false ) {
  }

  /**
   * Constructs an %oseparator.
   *
   * @param sep The separator character.
   */
  explicit oseparator( char sep ) : sep_( 1, sep ), print_( false ) {
  }

  /**
   * Gets the printing state of this %oseparator.
   *
   * @return Returns \c true only if this %oseparator is currently printing.
   */
  bool printing() const {
    return print_;
  }

  /**
   * Manually set the printing state.
   *
   * @state If \c true, the separator will always print; if \c false, the
   * separator will not print only the next time it is emitted.
   */
  void printing( bool state ) {
    print_ = state;
  }

  /**
   * Gets the current separator.
   *
   * @return Returns said separator.
   */
  char const* sep() const {
    return sep_.c_str();
  }

  /**
   * Sets the separator.
   *
   * @param s The new separator string.
   */
  void sep( char const *s ) {
    sep_ = s;
  }

  /**
   * Sets the separator.
   *
   * @tparam StringType The string type.
   * @param s The new separator string.
   */
  template<class StringType>
  void sep( StringType const &s ) {
    sep_ = s.c_str();
  }

  /**
   * Emits the %separator to the given ostream.  The first time this is called,
   * nothing is emitted; the second and subsequent times this is called, the
   * separator is emitted.
   *
   * @param o The ostream to emit to.
   * @param sep The separator to emit.
   * @return Returns \a o.
   */
  friend std::ostream& operator<<( std::ostream &o, oseparator &sep ) {
    if ( sep.print_ )
      o << sep.sep_;
    else
      sep.printing( true );
    return o;
  }

private:
  std::string sep_;
  bool print_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_OSEPARATOR_H */
/* vim:set et sw=2 ts=2: */
