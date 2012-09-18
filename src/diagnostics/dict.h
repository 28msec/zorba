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
#ifndef ZORBA_DIAGNOSTIC_DICT_H
#define ZORBA_DIAGNOSTIC_DICT_H

#include "diagnostics/dict_zed_keys.h"

namespace zorba {
namespace diagnostic {
namespace dict {

///////////////////////////////////////////////////////////////////////////////

/**
 * (Z)orba (E)rror (D)ictionary key prefix.  This string must prefix dictionary
 * keys for non-error-codes, i.e., miscellaneous strings.
 * \hideinitializer
 */
#define ZED_PREFIX "~"

/**
 * (Z)orba (E)rror (D)ictionary entry.  This macro must be used in code to
 * refer to an error string that must be localized, e.g.:
 * \code
 * throw XQUERY_EXCEPTION(
 *   err::FTDY0020, ERROR_PARAMS( ZED( UnbalancedParen ) )
 * );
 * \endcode
 * \hideinitializer
 */
#define ZED(DICT_KEY) ZED_##DICT_KEY

/**
 * Looks up the given key in the language dictionary.
 *
 * @param key The key to look up.
 * @return Returns the value for the given key or \a key if not found.
 */
char const* lookup( char const *key );

/**
 * Looks up the given key in the language dictionary.
 *
 * @tparam StringType The key's string type.
 * @param key The key to look up.
 * @return Returns the value for the given key or \a key if not found.
 */
template<class StringType> inline
char const* lookup( StringType const &key ) {
  return lookup( key.c_str() );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace dict
} // namespace diagnostic
} // namespace zorba
#endif /* ZORBA_DIAGNOSTIC_DICT_H */
/* vim:set et sw=2 ts=2: */
