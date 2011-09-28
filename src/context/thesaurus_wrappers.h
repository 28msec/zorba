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
#ifndef ZORBA_THESAURUS_WRAPPERS_H
#define ZORBA_THESAURUS_WRAPPERS_H

#include <zorba/config.h>

#ifndef ZORBA_NO_FULL_TEXT

#include <zorba/thesaurus.h>
#include "runtime/full_text/thesaurus.h"

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

class ThesaurusWrapper : public Thesaurus {
public:
  ThesaurusWrapper( zorba::Thesaurus::ptr );
  ~ThesaurusWrapper();

  // inherited
  void destroy() const;
  iterator::ptr lookup( zstring const&, zstring const&, ft_int, ft_int ) const;

private:
  typedef zorba::Thesaurus::iterator::ptr api_iterator_ptr;

  struct iterator_wrapper : Thesaurus::iterator {
    void destroy() const;
    bool next( zstring *synonym );

    iterator_wrapper( api_iterator_ptr );
    ~iterator_wrapper();

    api_iterator_ptr api_ptr_;
  };

  zorba::Thesaurus::ptr api_thesaurus_;
};

class ThesaurusProviderWrapper : public ThesaurusProvider {
public:
  ThesaurusProviderWrapper( zorba::ThesaurusProvider const *p );

  Thesaurus::ptr get_thesaurus( zstring const &uri,
                                locale::iso639_1::type lang ) const;
private:
  zorba::ThesaurusProvider const *const api_thesaurus_provider_;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba

#endif /* ZORBA_NO_FULL_TEXT */
#endif /* ZORBA_THESAURUS_WRAPPERS_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
