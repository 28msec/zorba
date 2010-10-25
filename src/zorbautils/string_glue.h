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

#ifndef ZORBA_STRING_GLUE_H
#define ZORBA_STRING_GLUE_H

#include "zorbatypes/xqpstring.h"

//
// This is a temporary file to be used only during the xqpStringStore to
// zstring transition.
//

namespace zorba {

template<class StringType> inline
xqpString to_xqpString( StringType const &s ) {
  return xqpString( s.c_str() );
}

template<class StringType> inline
xqpStringStore to_xqpStringStore( StringType const &s ) {
  return xqpStringStore( s.data(), s.size() );
}

template<class StringType> inline
xqpStringStore_t to_xqpStringStore_t( StringType const &s ) {
  return xqpStringStore_t( new xqpStringStore( s.data(), s.size() ) );
}

} // namespace

#endif
/* vim:set et sw=2 ts=2: */
