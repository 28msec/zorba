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
#ifndef ZORBA_FULL_TEXT_UTIL_H
#define ZORBA_FULL_TEXT_UTIL_H

#include <zorba/locale.h>

#include "compiler/expression/ftnode.h"
#include "zorbatypes/schema_types.h"
#include "util/cxx_util.h"

#include "ft_match.h"

namespace zorba {

////////// Typedefs ///////////////////////////////////////////////////////////

/**
 * A binary argument apply function.
 */
typedef void (*apply_binary_fn)( ft_all_matches const&, ft_all_matches const&,
                                 ft_all_matches& );

/**
 * The integer type used in full-text, e.g., "at least N", "at most N",
 * "exactly N", "window N", etc.
 */
typedef xs_unsignedInt ft_int;

////////// Functions //////////////////////////////////////////////////////////

/**
 * Gets the language from the given ftmatch_options, if any.
 *
 * @param options The ftmatch_options to get the language from.  This may be \c
 * nullptr.
 * @return Returns said language or unknown if either options is \c nullptr or
 * the options have no language option.
 */
inline locale::iso639_1::type get_lang_from( ftmatch_options const *options ) {
  if ( options )
    if ( ftlanguage_option const *const l = options->get_language_option() )
      return l->get_language();
  return locale::iso639_1::unknown;
}

/**
 * Gets the ftthesaurus_option from the given ftmatch_options, if any.
 *
 * @param options The ftmatch_options to get the ftthesaurus_option from.  This
 * may be \c nullptr.
 * @return Returns said ftthesaurus_option or \c nullptr if none.
 */
inline ftthesaurus_option const*
get_thesaurus_option( ftmatch_options const *options ) {
  if ( options )
    if ( ftthesaurus_option const *const t = options->get_thesaurus_option() )
      if ( !t->no_thesaurus() )
        return t;
  return nullptr;
}

/**
 * Gets whether wildcards are enabled from the given ftmatch_options, if any.
 *
 * @param options The ftmatch_options to check.  This may be \c nullptr.
 * @return Returns \c true only if the options is not \c nullptr and the
 * options contain an enabled wildcard option.
 */
inline bool get_wildcards_from( ftmatch_options const *options ) {
  if ( options )
    if ( ftwild_card_option const *const wc = options->get_wild_card_option() )
      return wc->get_mode() == ft_wild_card_mode::with;
  return false;
}

} // namespace zorba
#endif /* ZORBA_FULL_TEXT_UTIL_H */
/* vim:set et sw=2 ts=2: */
