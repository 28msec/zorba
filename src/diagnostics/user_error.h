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
#ifndef ZORBA_ERROR_H
#define ZORBA_ERROR_H

#include <zorba/error.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * Makes a UserError.
 *
 * @param ns The namespace.
 * @param prefix The prefix.
 * @param localname The local-name.
 * @return Returns a new UserError.
 */
inline UserError make_user_error( char const *ns, char const *prefix,
                                  char const *localname ) {
  return UserError( ns, prefix, localname );
}

/**
 * Makes a UserError.
 *
 * @tparam NamespaceStringType The namespace's string type.
 * @tparam PrefixStringType The prefix's string type.
 * @tparam LocalnameStringType The local-name's string type.
 * @param ns The namespace.
 * @param prefix The prefix.
 * @param localname The local-name.
 * @return Returns a new UserError.
 */
template<
  class NamespaceStringType,
  class PrefixStringType,
  class LocalnameStringType
>
inline UserError make_user_error( NamespaceStringType const &ns,
                                  PrefixStringType const &prefix,
                                  LocalnameStringType const &localname ) {
  return make_user_error( ns.c_str(), prefix.c_str(), localname.c_str() );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_ERROR_H */
/* vim:set et sw=2 ts=2: */
