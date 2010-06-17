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

#ifndef ZORBA_FULL_TEXT_FT_WILDCARD_MATCHER_H
#define ZORBA_FULL_TEXT_FT_WILDCARD_MATCHER_H

#include <string>

namespace zorba {

class ft_wildcard_matcher {
public:
  virtual ~ft_wildcard_matcher() { }

  static ft_wildcard_matcher* create();

  virtual void compile( std::string const &xquery_pattern ) = 0;
  virtual bool matches( std::string const &string ) const = 0;
};

inline bool operator==( ft_wildcard_matcher const &m, std::string const &s ) {
  return m.matches( s );
}

inline bool operator==( std::string const &s, ft_wildcard_matcher const &m ) {
  return m == s;
}

inline bool operator!=( ft_wildcard_matcher const &m, std::string const &s ) {
  return !( m == s );
}

inline bool operator!=( std::string const &s, ft_wildcard_matcher const &m ) {
  return !( s == m );
}

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_WILDCARD_MATCHER_H */
/* vim:set et sw=2 ts=2: */
