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

#include "compiler/parser/ft_types.h"

#define ENUM_STR(E) #E

namespace zorba {

  namespace ft_anyall_mode {
    char const *const string_of[] = {
      ENUM_STR( any ),
      ENUM_STR( any_word ),
      ENUM_STR( all ),
      ENUM_STR( all_words ),
      ENUM_STR( phrase )
    };
  }

  namespace ft_big_unit {
    char const *const string_of[] = {
      ENUM_STR( sentence ),
      ENUM_STR( paragraph )
    };
  }

  namespace ft_case_mode {
    char const *const string_of[] = {
      ENUM_STR( insensitive ),
      ENUM_STR( sensitive ),
      ENUM_STR( lower ),
      ENUM_STR( upper )
    };
  }

  namespace ft_content_mode {
    char const *const string_of[] = {
      ENUM_STR( at_start ),
      ENUM_STR( at_end ),
      ENUM_STR( entire )
    }
  };

  namespace ft_diacritics_mode {
    char const *const string_of[] = {
      ENUM_STR( insensitive ),
      ENUM_STR( senstive )
    };
  }

  namespace ft_range_mode {
    char const *const string_of[] = {
      ENUM_STR( exactly ),
      ENUM_STR( at_least ),
      ENUM_STR( at_most ),
      ENUM_STR( from_to )
    };
  }

  namespace ft_scope {
    char const *const string_of[] = {
      ENUM_STR( same ),
      ENUM_STR( different )
    };
  }

  namespace ft_stem_mode {
    char const *const string_of[] = {
      ENUM_STR( without ),
      ENUM_STR( with )
    };
  }

  namespace ft_stop_words_mode {
    char const *const string_of[] = {
      ENUM_STR( without ),
      ENUM_STR( with ),
      ENUM_STR( with_default )
    };
  }

  namespace ft_stop_words_unex {
    char const *const string_of[] = {
      ENUM_STR( union_ ),
      ENUM_STR( except )
    };
  }

  namespace ft_unit {
    char const *const string_of[] = {
      ENUM_STR( words ),
      ENUM_STR( sentences ),
      ENUM_STR( paragraphs )
    };
  }

  namespace ft_wild_card_mode {
    char const *const string_of[] = {
      ENUM_STR( no_wildcards ),
      ENUM_STR( wildcards ),
    };
  }

} // namespace zorba
/* vim:set et sw=2 ts=2: */
