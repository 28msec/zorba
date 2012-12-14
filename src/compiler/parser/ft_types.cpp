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
#include "stdafx.h"

#include "util/cxx_util.h"

#include "ft_types.h"

namespace zorba {

  namespace ft_anyall_mode {
    char const *const string_of[] = {
      "any",
      "any word",
      "all",
      "all words",
      "phrase",
      nullptr
    };
  }

  namespace ft_big_unit {
    char const *const string_of[] = {
      "sentence",
      "paragraph",
      nullptr
    };
  }

  namespace ft_case_mode {
    char const *const string_of[] = {
      "case insensitive",
      "case sensitive",
      "lower",
      "upper",
      nullptr
    };
  }

  namespace ft_content_mode {
    char const *const string_of[] = {
      "at start",
      "at end",
      "entire",
      nullptr
    };
  };

  namespace ft_diacritics_mode {
    char const *const string_of[] = {
      "diacritics insensitive",
      "diacritics sensitive",
      nullptr
    };
  }

  namespace ft_range_mode {
    char const *const string_of[] = {
      "exactly",
      "at least",
      "at most",
      "from to",
      nullptr
    };
  }

  namespace ft_scope {
    char const *const string_of[] = {
      "same",
      "different",
      nullptr
    };
  }

  namespace ft_stem_mode {
    char const *const string_of[] = {
      "no stemming",
      "stemming",
      nullptr
    };
  }

  namespace ft_stop_words_mode {
    char const *const string_of[] = {
      "without",
      "with",
      "with default",
      nullptr
    };
  }

  namespace ft_stop_words_unex {
    char const *const string_of[] = {
      "union",
      "except",
      nullptr
    };
  }

  namespace ft_unit {
    char const *const string_of[] = {
      "words",
      "sentences",
      "paragraphs",
      nullptr
    };
  }

  namespace ft_wild_card_mode {
    char const *const string_of[] = {
      "no wildcards",
      "wildcards",
      nullptr
    };
  }

} // namespace zorba
/* vim:set et sw=2 ts=2: */
