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

#ifndef ZORBA_CMD_UTIL_H
#define ZORBA_CMD_UTIL_H

#include <string>
#include <vector>

///////////////////////////////////////////////////////////////////////////////

template<class InStringType,class OutStringType>
void tokenize( InStringType const &s, char delim,
               std::vector<OutStringType> *tokens ) {
  typename InStringType::size_type last_pos = s.find_first_not_of( delim, 0 );
  typename InStringType::size_type pos = s.find_first_of( delim, last_pos );

  while ( pos != InStringType::npos || last_pos != InStringType::npos ) {
    tokens->push_back( s.substr( last_pos, pos - last_pos ).c_str() );
    last_pos = s.find_first_not_of( delim, pos );
    pos = s.find_first_of( delim, last_pos );
  }
}

///////////////////////////////////////////////////////////////////////////////

#endif /* ZORBA_CMD_UTIL_H */
/* vim:set et sw=2 ts=2: */
