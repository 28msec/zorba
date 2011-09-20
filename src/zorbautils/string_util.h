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
#ifndef ZORBA_UTILS_STRING_UTIL_H
#define ZORBA_UTILS_STRING_UTIL_H

#include <cstring>

#include <zorba/config.h>

#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/collation_manager.h"

#include "util/regex.h"
#include "util/unicode_util.h"
#include "util/utf8_util.h"

namespace zorba {
namespace utf8 {

////////// find with collation ////////////////////////////////////////////////

size_t find( char const *s, size_t s_len, char const *ss, size_t ss_len,
             XQPCollator const *collator );

size_t rfind( char const *s, size_t s_len, char const *ss, size_t ss_len,
              XQPCollator const *collator );

inline size_t find( char const *s, char const *ss,
                    XQPCollator const *collator ) {
  return find( s, std::strlen( s ), ss, std::strlen( ss ), collator );
}

template<class StringType,class SubstringType> inline
size_t find( StringType const &s, SubstringType const &ss,
             XQPCollator const *collator ) {
  return find( s.c_str(), s.size(), ss.c_str(), ss.size(), collator );
}

template<class StringType> inline
size_t find( StringType const &s, char const *ss, XQPCollator const *collator ) {
  return find( s.c_str(), s.size(), ss, std::strlen( ss ), collator );
}

template<class SubstringType> inline
size_t find( char const *s, SubstringType const &ss,
             XQPCollator const *collator ) {
  return find( s, std::strlen( s ), ss.c_str(), ss.size(), collator );
}

////////// ends with //////////////////////////////////////////////////////////

template<class StringType, class SubstringType> inline
bool ends_with(
    const StringType& s,
    const SubstringType& suffix,
    XQPCollator const* collator)
{
  size_t pos = ((collator == NULL || collator->doMemCmp())?
                rfind(s.c_str(), s.size(), suffix.c_str(), suffix.size(), NULL):
                rfind(s.c_str(), s.size(), suffix.c_str(), suffix.size(), collator));

  return (pos != StringType::npos &&
          (pos + utf8::length(suffix.c_str()) == utf8::length(s.c_str())));
}

////////// regular expression matching ////////////////////////////////////////

bool match_part( char const *in, char const *pattern, char const *flags = "" );

template<class InputStringType> inline
bool match_part( InputStringType const &in, char const *pattern,
                 char const *flags = "" ) {
  return match_part( in.c_str(), pattern, flags );
}

template<class InputStringType,class PatternStringType> inline
bool match_part( InputStringType const &in, PatternStringType const &pattern,
                 char const *flags = "" ) {
  return match_part( in.c_str(), pattern.c_str(), flags );
}

template<
  class InputStringType,
  class PatternStringType,
  class FlagsStringType
> inline
bool match_part( InputStringType const &in, PatternStringType const &pattern,
                 FlagsStringType const &flags ) {
  return match_part( in.c_str(), pattern.c_str(), flags.c_str() );
}

bool match_whole( char const *in, char const *pattern, char const *flags = "" );

template<class InputStringType> inline
bool match_whole( InputStringType const &in, char const *pattern,
                  char const *flags = "" ) {
  return match_whole( in.c_str(), pattern, flags );
}

template<class InputStringType,class PatternStringType> inline
bool match_whole( InputStringType const &in, PatternStringType const &pattern,
                  char const *flags = "" ) {
  return match_whole( in.c_str(), pattern.c_str(), flags );
}

template<
  class InputStringType,
  class PatternStringType,
  class FlagsStringType
> inline
bool match_whole( InputStringType const &in, PatternStringType const &pattern,
                  FlagsStringType const &flags ) {
  return match_whole( in.c_str(), pattern.c_str(), flags.c_str() );
}

////////// regular expression replacement /////////////////////////////////////

/**
 * Replaces all occurrences of a substring that matches the given regular
 * expression pattern.
 *
 * @tparam OutputStringType The output string type.
 * @param in The input string encoded in UTF-8.
 * @param pattern The regular expression pattern encoded in UTF-8.
 * @param flags The regular expression flags.
 * @param replacement The replacement string encoded in UTF-8.
 * @param out The output string.
 * @return Returns \c true only if the replacement and conversion to UTF-8
 * succeeded.
 */
template<class OutputStringType> inline
bool replace_all( char const *in, char const *pattern, char const *flags,
                  char const *replacement, OutputStringType *out ) {
  unicode::regex re;
  re.compile( pattern, flags );
#ifndef ZORBA_NO_UNICODE
  unicode::string u_out;
  return  re.replace_all( in, replacement, &u_out ) &&
          utf8::to_string( u_out.getBuffer(), u_out.length(), out );
#else
  return re.replace_all( in, replacement, out );
#endif /* ZORBA_NO_UNICODE */
}

/**
 * Replaces all occurrences of a substring that matches the given regular
 * expression pattern.
 *
 * @tparam InputStringType The input string type.
 * @tparam ReplacementStringType The replacement string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string encoded in UTF-8.
 * @param pattern The regular expression pattern encoded in UTF-8.
 * @param flags The regular expression flags.
 * @param replacement The replacement string encoded in UTF-8.
 * @param out The output string.  It may be the same as the input string.
 * @return Returns \c true only if the replacement and conversion to UTF-8
 * succeeded.
 */
template<
  class InputStringType,
  class ReplacementStringType,
  class OutputStringType
> inline
bool replace_all( InputStringType const &in, char const *pattern,
                  char const *flags, ReplacementStringType const &replacement, 
                  OutputStringType *out ) {
  unicode::regex re;
  re.compile( pattern, flags );
#ifndef ZORBA_NO_UNICODE
  unicode::string u_out;
  return  re.replace_all( in, replacement, &u_out ) &&
          utf8::to_string( u_out.getBuffer(), u_out.length(), out );
#else
  return re.replace_all( in, replacement, out );
#endif /* ZORBA_NO_UNICODE */
}

/**
 * Replaces all occurrences of a substring that matches the given regular
 * expression pattern.
 *
 * @tparam InputStringType The input string type.
 * @tparam PatternStringType The pattern string type.
 * @tparam ReplacementStringType The replacement string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string encoded in UTF-8.
 * @param pattern The regular expression pattern encoded in UTF-8.
 * @param flags The regular expression flags.
 * @param replacement The replacement string encoded in UTF-8.
 * @param out The output string.  It may be the same as the input string.
 * @return Returns \c true only if the replacement and conversion to UTF-8
 * succeeded.
 */
template<
  class InputStringType,
  class PatternStringType,
  class ReplacementStringType,
  class OutputStringType
> inline
bool replace_all( InputStringType const &in, PatternStringType const &pattern,
                  char const *flags, ReplacementStringType const &replacement,
                  OutputStringType *out ) {
  unicode::regex re;
  re.compile( pattern, flags );
#ifndef ZORBA_NO_UNICODE
  unicode::string u_out;
  return  re.replace_all( in, replacement, &u_out ) &&
          utf8::to_string( u_out.getBuffer(), u_out.length(), out );
#else
  return re.replace_all( in, replacement, out );
#endif /* ZORBA_NO_UNICODE */
}

///////////////////////////////////////////////////////////////////////////////

} // namespace utf8
} // namespace zorba
#endif  /* ZORBA_UTILS_STRING_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
