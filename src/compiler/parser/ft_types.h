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
#ifndef ZORBA_FT_TYPES_H
#define ZORBA_FT_TYPES_H

#include <iostream>

#define DEF_OSTREAM_INSERT_OPERATOR                             \
  inline std::ostream& operator<<( std::ostream &o, type t ) {  \
    return o << string_of[ t ];                                 \
  }

///////////////////////////////////////////////////////////////////////////////

namespace zorba {

  namespace ft_anyall_mode {
    enum type {
      any,
      any_word,
      all,
      all_words,
      phrase
    };
    type const DEFAULT = any;
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_big_unit {
    enum type {
      sentence,
      paragraph
    };
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_case_mode {
    enum type {
      insensitive,
      sensitive,
      lower,
      upper
    };
    type const DEFAULT = insensitive;
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_content_mode {
    enum type {
      at_start,
      at_end,
      entire
    };
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  };

  namespace ft_diacritics_mode {
    enum type {
      insensitive,
      sensitive
    };
    type const DEFAULT = insensitive;
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_range_mode {
    enum type {
      exactly,
      at_least,
      at_most,
      from_to
    };
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_scope {
    enum type {
      same,
      different
    };
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_stem_mode {
    enum type {
      without,
      with
    };
    type const DEFAULT = without;
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_stop_words_mode {
    enum type {
      without,
      with,
      with_default
    };
    type const DEFAULT = without;
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_stop_words_unex {
    enum type {
      union_,
      except
    };
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_unit {
    enum type {
      words,
      sentences,
      paragraphs
    };
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

  namespace ft_wild_card_mode {
    enum type {
      without,
      with
    };
    type const DEFAULT = without;
    extern char const *const string_of[];
    DEF_OSTREAM_INSERT_OPERATOR
  }

} // namespace zorba

///////////////////////////////////////////////////////////////////////////////

#undef DEF_OSTREAM_INSERT_OPERATOR

#endif /* ZORBA_FT_TYPES_H */
/* vim:set et sw=2 ts=2: */
