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

#ifndef ZORBA_FULL_TEXT_FT_THESAURUS_H
#define ZORBA_FULL_TEXT_FT_THESAURUS_H

#include <limits>

#include "zorbatypes/zstring.h"
#include "zorbautils/locale.h"

#include "ft_query_item.h"
#include "ft_util.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class ft_thesaurus {
public:
  virtual ~ft_thesaurus();

  virtual void lookup( zstring const &query_phrase, int pos_no, int sent_no,
                       locale::iso639_1::type lang, zstring const &relationship,
                       ft_int at_least, ft_int at_most,
                       FTQueryItemSeq &result ) const = 0;

  static ft_thesaurus const* get( zstring const &uri, locale::iso639_1::type );

protected:
  ft_thesaurus( locale::iso639_1::type lang ) : lang_( lang ) { }

  locale::iso639_1::type const lang_;

private:
  // forbid these
  ft_thesaurus( ft_thesaurus const& );
  ft_thesaurus& operator=( ft_thesaurus const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_THESAURUS_H */
/* vim:set et sw=2 ts=2: */
