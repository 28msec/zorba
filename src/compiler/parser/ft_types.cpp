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

#include "ft_types.h"

namespace zorba {

  namespace ft_anyall_mode {
    char const *const string_of[] = {
      "any",
      "any_word",
      "all",
      "all words",
      "phrase"
    };
  }

  namespace ft_big_unit {
    char const *const string_of[] = {
      "sentence",
      "paragraph"
    };
  }

  namespace ft_case_mode {
    char const *const string_of[] = {
      "insensitive",
      "sensitive",
      "lower",
      "upper"
    };
  }

  namespace ft_content_mode {
    char const *const string_of[] = {
      "at start",
      "at end",
      "entire"
    };
  };

  namespace ft_diacritics_mode {
    char const *const string_of[] = {
      "insensitive",
      "sensitive"
    };
  }

  namespace ft_range_mode {
    char const *const string_of[] = {
      "exactly",
      "at least",
      "at most",
      "from to"
    };
  }

  namespace ft_scope {
    char const *const string_of[] = {
      "same",
      "different"
    };
  }

  namespace ft_stem_mode {
    char const *const string_of[] = {
      "without",
      "with"
    };
  }

  namespace ft_stop_words_mode {
    char const *const string_of[] = {
      "without",
      "with",
      "with default"
    };
  }

  namespace ft_stop_words_unex {
    char const *const string_of[] = {
      "union",
      "except"
    };
  }

  namespace ft_thesaurus_rel {
    char const *const string_of[] = {
      "USE",
      "UF",
      "BT",
      "NT",
      "BTG",
      "NTG",
      "BTP",
      "NTP",
      "TT",
      "RT"
    };
  };

  namespace ft_unit {
    char const *const string_of[] = {
      "words",
      "sentences",
      "paragraphs"
    };
  }

  namespace ft_wild_card_mode {
    char const *const string_of[] = {
      "no wildcards",
      "wildcards"
    };
  }

} // namespace zorba
/* vim:set et sw=2 ts=2: */
