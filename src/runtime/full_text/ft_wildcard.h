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

#ifndef ZORBA_FULL_TEXT_FT_WILDCARD_H
#define ZORBA_FULL_TEXT_FT_WILDCARD_H

#include "util/regex.h"
#include "zorbatypes/zstring.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class ft_wildcard {
public:
  ft_wildcard( zstring const &xquery_pattern );

  bool matches( zstring const &string ) const {
    return regex_.match_whole( string );
  }

private:
  mutable unicode::regex regex_;

  // forbid these
  ft_wildcard( ft_wildcard const& );
  ft_wildcard& operator=( ft_wildcard const& );
};

///////////////////////////////////////////////////////////////////////////////

inline bool operator==( ft_wildcard const &m, zstring const &s ) {
  return m.matches( s );
}

inline bool operator==( zstring const &s, ft_wildcard const &m ) {
  return m == s;
}

inline bool operator!=( ft_wildcard const &m, zstring const &s ) {
  return !( m == s );
}

inline bool operator!=( zstring const &s, ft_wildcard const &m ) {
  return !( s == m );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_WILDCARD_H */
/* vim:set et sw=2 ts=2: */
