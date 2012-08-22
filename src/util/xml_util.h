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
#ifndef ZORBA_XML_UTIL_H
#define ZORBA_XML_UTIL_H

#include <iostream>

#include <zorba/internal/ztd.h>

#include "unicode_util.h"
#include "utf8_util.h"

namespace zorba {
namespace xml {

////////// types //////////////////////////////////////////////////////////////

/**
 * XML versions.
 */
enum version {
  v1_0,
  v1_1
};
extern char const *const version_string_of[];

inline std::ostream& operator<<( std::ostream &o, version v ) {
  return o << version_string_of[ v ];
}

////////// XML name handing ///////////////////////////////////////////////////

/**
 * Attempts to extract the local name from a "universal name".
 * See: http://www.jclark.com/xml/xmlns.htm
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param uname The universal name.
 * @param local A pointer to the string to receive the local name.
 * @return Returns \c true only if the extraction was successful.
 */
template<class InputStringType,class OutputStringType> inline
bool clark_localname( InputStringType const &uname, OutputStringType *local ) {
  typename InputStringType::size_type const rbrace = uname.find( '}' );
  if ( rbrace != InputStringType::npos && rbrace + 1 < uname.size() ) {
    *local = uname.substr( rbrace + 1 );
    return true;
  }
  return false;
}

/**
 * Attempts to extract the URI from a "universal name".
 * See: http://www.jclark.com/xml/xmlns.htm
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param uname The universal name.
 * @param uri A pointer to the string to receive the URI.
 * @return Returns \c true only if the extraction was successful.
 */
template<class InputStringType,class OutputStringType> inline
bool clark_uri( InputStringType const &uname, OutputStringType *uri ) {
  if ( uname.size() > 2 && uname[0] == '{' ) {
    typename InputStringType::size_type const rbrace = uname.find( '}', 1 );
    if ( rbrace != InputStringType::npos ) {
      *uri = uname.substr( 1, rbrace - 1 );
      return true;
    }
  }
  return false;
}

/**
 * Splits an XML name at a \c : if present.
 *
 * @tparam InputStringType The input string type.
 * @tparam PrefixStringType The output prefix string type.
 * @tparam LocalStringType The output local string type.
 * @param name The XML name to be split.
 * @param prefix The prefix is put here, if any.
 * @param local The local name is put here.
 * @return If \a name contains a \c : and either \a prefix or \a local strings
 * become empty, returns \c false; otherwise returns \a true.
 */
template<class InputStringType,class PrefixStringType,class LocalStringType>
inline bool split_name( InputStringType const &name, PrefixStringType *prefix,
                        LocalStringType *local ) {
  typename InputStringType::size_type const colon = name.find( ':' );
  if ( colon != InputStringType::npos ) {
    prefix->assign( name, 0, colon );
    local->assign( name, colon + 1, LocalStringType::npos );
    return !( prefix->empty() || local->empty() );
  } else {
    prefix->clear();
    *local = name;
    return true;
  }
}

////////// Character validity /////////////////////////////////////////////////

/**
 * Checks whether the given code-point is valid for the given XML version.
 *
 * @tparam CodePointType The integral Unicode code-point type.
 * @param v The XML version to use.
 * @return Returns \c true only if the code-point is valid.
 */
template<typename CodePointType> inline
typename std::enable_if<ZORBA_TR1_NS::is_integral<CodePointType>::value,
                        bool>::type
is_valid( CodePointType c, version v = v1_0 ) {
  //
  // See "Extensible Markup Language (XML) 1.0 (Fifth Edition)" and
  // "Extensible Markup Language (XML) 1.1 (Second Edition)", section 2.2,
  // "Characters", [2] Char.
  //
  return  (c >= 0x000020 && c <= 0x00D7FF)  // common case first
      ||  (c == 0x9 || c == 0xA || c == 0xD)
      ||  (c >= 0x00E000 && c <= 0x00FFFD)
      ||  (c >= 0x010000 && c <= 0x10FFFF)
      ||  (v == v1_1 && c >= 0x01 && c <= 0x1F);
}

////////// XML character escaping /////////////////////////////////////////////

/**
 * A %back_xml_insert_iterator can be used to append characters to a string
 * ensuring that illegal characters in XML ('"', '&', '\'', '<', and '>') are
 * replace by their respective character entity references.
 *
 * @tparam StringType The string type.
 */
template<class StringType>
class back_xml_insert_iterator :
  public
    ztd::back_insert_iterator_base<
      StringType, back_xml_insert_iterator<StringType>
    >
{
  typedef ztd::back_insert_iterator_base<
    StringType, back_xml_insert_iterator<StringType>
  > base_type;
public:
  typedef typename base_type::container_type container_type;
  typedef typename StringType::value_type value_type;

  /**
   * Constructs a %back_xml_insert_iterator.
   *
   * @param s The string to append to.
   */
  explicit back_xml_insert_iterator( StringType &s ) : base_type( s ) {
    buf_[0] = '&';
    buf_[1] = '#';
  }

  back_xml_insert_iterator& operator=( value_type c );

private:
  char buf_[5]; // &#xx; -- no need for null at end
};

/**
 * This is a convenience function to create a back_xml_insert_iterator.
 *
 * @tparam StringType The string type.
 * @param out The output string.
 */
template<class StringType> inline back_xml_insert_iterator<StringType>
back_xml_inserter( StringType &out ) {
  return back_xml_insert_iterator<StringType>( out );
}

/**
 * Escapes characters in the string for XML, specfically '"', '&', '\'', '<',
 * and '>'.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are appended to.
 */
template<class InputStringType,class OutputStringType> inline
void escape( InputStringType const &in, OutputStringType *out ) {
  std::copy( in.begin(), in.end(), back_xml_inserter( *out ) );
}

/**
 * Escapes characters in the string for XML, specfically '"', '&', '\'', '<',
 * and '>'.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void escape( StringType &s ) {
  StringType temp;
  std::copy( s.begin(), s.end(), back_xml_inserter( temp ) );
  s = temp;
}

////////// XML entity reference parsing ///////////////////////////////////////

/**
 * Parses an XML entity reference.
 *
 * @param ref The C string pointing to the start of the entity reference.
 * @param c A pointer to the code-point result.
 * @return If successful, returns the number of characters parsed; otherwise
 * returns -1.
 */
int parse_entity( char const *ref, unicode::code_point *c );

/**
 * Parses an XML entity reference.
 *
 * @tparam StringType The input string type.
 * @param ref The string pointing to the start of the entity reference.
 * @param c A pointer to the code-point result.
 * @return If successful, returns the number of characters parsed; otherwise
 * returns -1.
 */
template<class StringType> inline
int parse_entity( StringType const &ref, unicode::code_point *c ) {
  return parse_entity( ref.c_str(), c );
}

/**
 * Parses an XML entity reference and appends the UTF-8 encoding of the
 * resulting code-point to the given string.
 *
 * @tparam StringType The output string type.
 * @param ref The C string pointing to the start of the entity reference.
 * @param out A string to append to.
 * @return If successful, returns the number of characters parsed; otherwise
 * returns -1.
 */
template<class StringType> inline
int parse_entity( char const *ref, StringType *out ) {
  unicode::code_point c;
  int const result = parse_entity( ref, &c );
  if ( result != -1 )
    utf8::encode( c, out );
  return result;
}

/**
 * Parses an XML entity reference and appends the UTF-8 encoding of the
 * resulting code-point to the given string.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param ref The string pointing to the start of the entity reference.
 * @param out A string to append to.
 * @return If successful, returns the number of characters parsed; otherwise
 * returns -1.
 */
template<class InputStringType,class OutputStringType> inline
int parse_entity( InputStringType const &ref, OutputStringType *out ) {
  return parse_entity( ref.c_str(), out );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace xml
} // namespace zorba

#include "xml_util.tcc"

#endif /* ZORBA_XML_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
