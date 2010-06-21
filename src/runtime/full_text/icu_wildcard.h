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

#ifndef ZORBA_FULL_TEXT_ICU_WILDCARD_MATCHER_H
#define ZORBA_FULL_TEXT_ICU_WILDCARD_MATCHER_H

#include <memory>
#include <unicode/regex.h>

#include "runtime/full_text/ft_wildcard.h"

namespace zorba {

class icu_wildcard : public ft_wildcard {
public:
  icu_wildcard() { }

  void compile( std::string const &xquery_pattern );
  bool matches( std::string const &string ) const;

private:
  typedef std::auto_ptr<U_NAMESPACE_QUALIFIER RegexMatcher> RegexMatcher_ptr;
  RegexMatcher_ptr matcher_;

  // forbid these
  icu_wildcard( icu_wildcard const& );
  icu_wildcard& operator=( icu_wildcard const& );
};

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_ICU_WILDCARD_MATCHER_H */
/* vim:set et sw=2 ts=2: */
