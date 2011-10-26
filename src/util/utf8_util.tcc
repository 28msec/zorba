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

#ifndef ZORBA_UTF8_UTIL_TCC
#define ZORBA_UTF8_UTIL_TCC

#ifndef ZORBA_UTF8_UTIL_H
#error "This file is not meant to be included directly."
#endif /* ZORBA_UTF8_UTIL_H */

#include <cctype>

#include "util/string/string_traits.h"

namespace zorba {
namespace utf8 {

///////////////////////////////////////////////////////////////////////////////

template<class StringType> back_html_uri_insert_iterator<StringType>&
back_html_uri_insert_iterator<StringType>::operator=( value_type c ) {
  char const dec2hex[] = "0123456789ABCDEF";
  unsigned u = c & 0xFF;
  if ( !isprint( u ) ) {
    utf8::encoded_char_type ec;
    utf8::size_type const bytes = utf8::encode( c, ec );
    for ( size_type i = 0; i < bytes; ++i ) {
      u = ec[i] & 0xFF;
      buf_[1] = dec2hex[ u >> 4 ];
      buf_[2] = dec2hex[ u & 0x0F ];
      this->container->append( buf_, 3 );
    }
  } else {
    this->container->push_back( c );
  }
  return *this;
}

template<class StringType> back_iri_insert_iterator<StringType>&
back_iri_insert_iterator<StringType>::operator=( value_type c ) {
  char const dec2hex[] = "0123456789ABCDEF";
  unsigned u = c & 0xFF;
  if ( unicode::is_ucschar( c ) || unicode::is_iprivate( c ) ||
       unicode::is_invalid_in_iri( c ) ) {
    utf8::encoded_char_type ec;
    utf8::size_type const bytes = utf8::encode( c, ec );
    for ( size_type i = 0; i < bytes; ++i ) {
      u = ec[i] & 0xFF;;
      buf_[1] = dec2hex[ u >> 4 ];
      buf_[2] = dec2hex[ u & 0x0F ];
      this->container->append( buf_, 3 );
    }
  } else {
    this->container->push_back( c );
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////////////

template<class OctetIterator>
unicode::code_point next_char( OctetIterator &i ) {
  unicode::code_point c = *i & 0xFFu;   // prevents sign-extension
  if ( c < 0x80 )                       // special-case ASCII
    ++i;
  else {
    size_type const len = char_length( c );
    unsigned m = (0x7F >> len) & 0x1F;  // mask
    c = unicode::code_point( 0 );
    switch ( len ) {
      case 6: c |= ((*i & m   ) << 30); ++i; m = 0x3F;
      case 5: c |= ((*i & m   ) << 24); ++i; m = 0x3F;
      case 4: c |= ((*i & m   ) << 18); ++i; m = 0x3F;
      case 3: c |= ((*i & m   ) << 12); ++i; m = 0x3F;
      case 2: c |= ((*i & m   ) <<  6); ++i;
              c |=  (*i & 0x3F)       ; ++i;
    }
  }
  return c;
}

template<class OctetIterator>
unicode::code_point prev_char( OctetIterator &oi ) {
  while ( !is_start_byte( *--oi ) ) ;
  OctetIterator temp( oi );
  return next_char( temp );
}

#ifndef ZORBA_NO_ICU

template<class InputStringType,class OutputStringType>
bool normalize( InputStringType const &in, unicode::normalization::type n,
                OutputStringType *out ) {
  unicode::string u_in;
  if ( !unicode::to_string( in, &u_in ) )
    return false;
  unicode::string u_out;
  if ( !unicode::normalize( u_in, n, &u_out ) )
    return false;
  storage_type *temp;
  size_type temp_len;
  if ( !utf8::to_string( u_out.getBuffer(), u_out.length(), &temp, &temp_len ) )
    return false;
  out->assign( temp, temp_len );
  if ( !string_traits<OutputStringType>::takes_pointer_ownership )
    delete[] temp;
  return true;
}

template<class InputStringType,class OutputStringType>
void strip_diacritics( InputStringType const &in, OutputStringType *out ) {
  InputStringType in_normalized;
#ifndef ZORBA_NO_ICU
  normalize( in, unicode::normalization::NFKD, &in_normalized );
#else
  in_normalized = in.c_str();
#endif /* ZORBA_NO_ICU */
  out->clear();
  out->reserve( in_normalized.size() );
  std::copy(
    in_normalized.begin(), in_normalized.end(),
    ascii::back_ascii_inserter( *out )
  );
}

template<class StringType>
bool to_string( unicode::char_type const *in, size_type in_len,
                StringType *out ) {
  storage_type *temp;
  size_type temp_len;
  if ( to_string( in, in_len, &temp, &temp_len ) ) {
    out->assign( temp, temp_len );
    if ( !string_traits<StringType>::takes_pointer_ownership )
      delete[] temp;
    return true;
  }
  return false;
}

#ifndef WIN32
template<class StringType>
bool to_string( wchar_t const *in, size_type in_len, StringType *out ) {
  storage_type *temp;
  size_type temp_len;
  if ( utf8::to_string( in, in_len, &temp, &temp_len ) ) {
    out->assign( temp, temp_len );
    if ( !string_traits<StringType>::takes_pointer_ownership )
      delete[] temp;
    return true;
  }
  return false;
}
#endif /* WIN32 */

#endif /* ZORBA_NO_ICU */

template<class InputStringType,class OutputStringType>
void to_lower( InputStringType const &in, OutputStringType *out ) {
  typename utf8_stringify<InputStringType const>::type const u_in( in );
  typename utf8_stringify<OutputStringType>::type u_out( *out );
  out->clear(); // TODO: should this be here?
  std::transform(
    u_in.begin(), u_in.end(), std::back_inserter( u_out ), unicode::to_lower
  );
}

template<class InputStringType,class OutputStringType>
void to_upper( InputStringType const &in, OutputStringType *out ) {
  typename utf8_stringify<InputStringType const>::type const u_in( in );
  typename utf8_stringify<OutputStringType>::type u_out( *out );
  out->clear(); // TODO: should this be here?
  std::transform(
    u_in.begin(), u_in.end(), std::back_inserter( u_out ), unicode::to_upper
  );
}

} // namespace utf8
} // namespace zorba

#endif /* ZORBA_UTF8_UTIL_TCC */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
