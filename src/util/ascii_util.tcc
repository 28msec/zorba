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

#ifndef ZORBA_STRING_UTIL_ASCII_UTIL_TCC
#define ZORBA_STRING_UTIL_ASCII_UTIL_TCC

#ifndef ZORBA_STRING_UTIL_ASCII_UTIL_H
#error "This file is not meant to be included directly."
#endif /* ZORBA_STRING_UTIL_ASCII_UTIL_H */

namespace zorba {
namespace ascii {

///////////////////////////////////////////////////////////////////////////////

template<class StringType> back_uri_insert_iterator<StringType>&
back_uri_insert_iterator<StringType>::operator=( value_type c ) {
  char const dec2hex[] = "0123456789ABCDEF";
  unsigned const u = c & 0xFF;
  if ( uri_safe[ u ] || (c == '/' && !encode_slash_) )
    this->container->push_back( c );
  else {
    buf_[1] = dec2hex[ u >> 4 ];
    buf_[2] = dec2hex[ u & 0x0F ];
    this->container->append( buf_, 3 );
  }
  return *this;
}

template<class StringType> back_xml_insert_iterator<StringType>&
back_xml_insert_iterator<StringType>::operator=( value_type c ) {
  switch ( c ) {
    case '"':
    case '&':
    case '\'':
    case '<':
    case '>':
      itoa( c, buf_ + 2 /* skip over "&#" */ );
      buf_[4] = ';'; // because it gets overwritten with null by itoa()
      this->container->append( buf_, 5 );
      break;
    default:
      this->container->push_back( c );
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////////////

template<class InputStringType,class OutputStringType>
void normalize_whitespace( InputStringType const &in, OutputStringType *out ) {
  typedef typename InputStringType::const_iterator const_iterator;
  const_iterator i( in.begin() );
  const_iterator const j( in.end() );
  out->clear();
  bool was = true;
  for ( ; i != j; ++i ) {
    typename InputStringType::value_type const c = *i;
    bool const is = is_space( c );
    if ( !is || (is && !was) )
      out->push_back( is ? ' ' : c );
    was = is;
  }

  typename OutputStringType::size_type pos = out->find_last_not_of( ' ' );
  if ( pos != OutputStringType::npos && ++pos < out->size() )
    out->erase( pos );
}

template<class StringType>
void replace_all( StringType &s, char from, char to ) {
  for ( typename StringType::size_type pos = 0; pos < s.size(); ++pos ) {
    if ( (pos = s.find( from, pos )) == StringType::npos )
      break;
    s.replace( pos, 1, 1, to );
  }
}

template<class StringType>
void replace_all( StringType &s,
                  char const *from, typename StringType::size_type from_len,
                  char const *to, typename StringType::size_type to_len ) {
  for ( typename StringType::size_type pos = 0;
        pos + from_len < s.size(); pos += to_len ) {
    if ( (pos = s.find( from, pos, from_len )) == StringType::npos )
      break;
    s.replace( pos, from_len, to, to_len );
  }
}

template<class InputStringType,class OutputStringType>
void trim_start( InputStringType const &in, char const *chars,
           OutputStringType *out ) {
  *out = in;
  typename OutputStringType::size_type pos = out->find_first_not_of( chars );
  out->erase( 0, pos );
}

template<class InputStringType,class OutputStringType>
void trim_end( InputStringType const &in, char const *chars,
           OutputStringType *out ) {
  *out = in;
  typename OutputStringType::size_type pos = out->find_last_not_of( chars );
  if ( pos != OutputStringType::npos && ++pos < out->size() )
    out->erase( pos );
}

template<class InputStringType,class OutputStringType>
void trim( InputStringType const &in, char const *chars,
           OutputStringType *out ) {
  *out = in;
  typename OutputStringType::size_type pos = out->find_first_not_of( chars );
  out->erase( 0, pos );
  pos = out->find_last_not_of( chars );
  if ( pos != OutputStringType::npos && ++pos < out->size() )
    out->erase( pos );
}

template<class InputStringType,class OutputStringType>
void uri_decode( InputStringType const &in, OutputStringType *out ) {
  extern signed char const hex2dec[];

  typedef typename InputStringType::const_iterator const_iterator;
  const_iterator i( in.begin() );
  const_iterator const j( in.end() );

  out->reserve( out->size() + in.size() );
  for ( ; i != j; ++i ) {
    char c = *i;
    if ( c == '%' ) {
      const_iterator k = i;
      do {
        if ( ++k == j )
          break;
        signed char const c1 = hex2dec[ static_cast<unsigned>( *k ) & 0xFF ];
        if ( c1 == -1 || ++k == j )
          break;
        signed char const c2 = hex2dec[ static_cast<unsigned>( *k ) & 0xFF ];
        if ( c2 == -1 )
          break;
        c = static_cast<char>( (c1 << 4) | c2 );
        i = k;
      } while ( false );
    }
    out->push_back( c );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ascii
} // namespace zorba

#endif /* ZORBA_STRING_UTIL_ASCII_UTIL_TCC */

/*
 * Local variables:
 * mode: c++
 * End:
 */

/* vim:set et sw=2 ts=2: */
