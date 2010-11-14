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

#ifndef ZORBA_FULL_TEXT_WORDNET_H
#define ZORBA_FULL_TEXT_WORDNET_H

#include <list>

#include "../ft_thesaurus.h"

namespace zorba {
namespace wordnet {

///////////////////////////////////////////////////////////////////////////////

class thesaurus : public ft_thesaurus {
public:
  thesaurus( zstring const &phrase, zstring const &relationship,
             ft_int at_least, ft_int at_most );
  ~thesaurus();

  bool next( zstring *synonym );

private:
  typedef std::list<char const*> synonym_list_t;

  synonym_list_t synonyms_;
  synonym_list_t::const_iterator i_;

  // forbid these
  thesaurus( thesaurus const& );
  thesaurus& operator=( thesaurus const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba

#endif  /* ZORBA_FULL_TEXT_WORDNET_H */
/* vim:set et sw=2 ts=2: */
