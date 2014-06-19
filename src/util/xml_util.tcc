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

#ifndef ZORBA_XML_UTIL_TCC
#define ZORBA_XML_UTIL_TCC

#ifndef ZORBA_XML_UTIL_H
# error "This file is not meant to be included directly."
#endif /* ZORBA_XML_UTIL_H */

#include "ascii_util.h"

namespace zorba {
namespace xml {

///////////////////////////////////////////////////////////////////////////////

template<class StringType> back_xml_insert_iterator<StringType>&
back_xml_insert_iterator<StringType>::operator=( value_type c ) {
  switch ( c ) {
    case '"':
    case '&':
    case '\'':
    case '<':
    case '>':
      ascii::itoa( c, buf_ + 2 /* skip over "&#" */ );
      buf_[4] = ';'; // because it gets overwritten with null by itoa()
      this->container->append( buf_, 5 );
      break;
    default:
      this->container->push_back( c );
  }
  return *this;
}

template<class StringType>
typename std::enable_if<ZORBA_IS_STRING(StringType),bool>::type
is_NCName( StringType const &s ) {
  typedef typename utf8_stringify<StringType const>::type U_StringType;
  typedef typename U_StringType::const_iterator const_iterator;

  U_StringType const u( s );
  const_iterator i( u.begin() );
  const_iterator const end( u.end() );

  if ( i == end || !is_NameStartChar( *i ) )
    return false;
  while ( ++i != end )
    if ( !is_NameChar( *i ) )
      return false;
  return true;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace xml
} // namespace zorba

#endif /* ZORBA_XML_UTIL_TCC */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
