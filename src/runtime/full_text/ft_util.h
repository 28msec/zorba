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

#ifndef ZORBA_FULL_TEXT_UTIL_H
#define ZORBA_FULL_TEXT_UTIL_H

#include "compiler/expression/ftnode.h"
#include "zorbautils/locale.h"

namespace zorba {

/**
 * Gets the language from the given ftmatch_options, if any.
 *
 * @param options The ftmatch_options to get the language from.  This may be
 * <code>null</code>.
 * @return Returns said language or unknown if either options is
 * <code>NULL</code> or the options have no language option.
 */
inline locale::iso639_1::type get_lang_from( ftmatch_options const *options ) {
  if ( options )
    if ( ftlanguage_option const *const l = options->get_language_option() )
      return l->get_language();
  return locale::iso639_1::unknown;
}

} // namespace zorba
#endif /* ZORBA_FULL_TEXT_UTIL_H */
/* vim:set et sw=2 ts=2: */
