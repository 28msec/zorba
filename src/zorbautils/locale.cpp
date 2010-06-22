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

#ifdef WIN32
# include <windows.h>
# include "zorbautils/fatal.h"
#else
# include <clocale>
# include <cstdlib>                     /* for getenv(3) */
# include "util/stl_util.h"
#endif /* WIN32 */

#include <algorithm>
#include <cstring>

#include "util/less.h"
#include "zorbautils/locale.h"

#define DEF_END()                                     \
  static char const *const *const end =               \
    string_of + sizeof( string_of ) / sizeof( char* );

#define FIND(what) \
  static_cast<type>( find_index( string_of, end, what ) )

using namespace std;

namespace zorba {
namespace locale {

///////////////////////////////////////////////////////////////////////////////

inline int find_index( char const *const *begin, char const *const *end,
                       char const *s ) {
  char const *const *const entry =
    ::lower_bound( begin, end, s, less<char const*>() );
  return entry != end && ::strcmp( s, *entry ) == 0 ? entry - begin : 0;
}

#ifdef WIN32

/**
 * Gets a particular piece of information from the user's default locale.
 *
 * @param constant The constant specifying which piece of locale information to
 * get.
 * @return Returns said information or <code>NULL</code>.
 */
static char* get_win32_locale_info( int constant ) {
  int bytes = ::GetLocaleInfoA( LOCALE_USER_DEFAULT, constant, NULL, 0 );
  ZORBA_FATAL( bytes, "GetLocaleInfoA() failed" );
  char *const info = new char[ bytes ];
  bytes = ::GetLocaleInfoA( LOCALE_USER_DEFAULT, constant, info, bytes );
  ZORBA_FATAL( bytes, "GetLocaleInfoA() failed" );
  return info;
}

#else

/**
 * Gets the environment's locale.
 *
 * @return Returns said locale, e.g., "en_US.UTF-8" or <code>NULL</code>.
 */
static char* get_unix_locale() {
  //
  // Try the environment locale first.
  //
  char const *loc = ::setlocale( LC_ALL, "" );
  if ( loc && (::strcmp( loc, "C" ) == 0 || ::strcmp( loc, "POSIX" ) == 0) ) {
    //
    // These locales aren't useful: ignore them.
    //
    loc = NULL;
  }
  if ( !loc ) {
    //
    // Try the "LANG" environment variable second.
    //
    loc = ::getenv( "LANG" );
  }
  return loc ? new_strdup( loc ) : NULL;
}

#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

namespace iso3166_1 {

char const *const string_of[] = {
  "#UNKNOWN",                           // starts with '#' for sorting
  "AR", // Argnetina
  "AS", // American Samoa
  "AU", // Australia
  "BE", // Belgium
  "BG", // Bulgaria
  "BM", // Bermuda
  "BR", // Brazil
  "BS", // Bahamas
  "CA", // Canada
  "CH", // Switzerland
  "CL", // Chile
  "CO", // Columbia
  "CR", // Costa Rica
  "CV", // Cape Verde
  "CZ", // Czech Republic
  "DE", // Germany
  "DK", // Denmark
  "ES", // Spain
  "FI", // Finland
  "FR", // France
  "GB", // United Kingdom
  "GF", // French Guiana
  "GT", // Guatemala
  "HN", // Honduras
  "HU", // Hungary
  "IE", // Ireland
  "IT", // Italy
  "JM", // Jamaica
  "KY", // Cayman Islands
  "MX", // Mexico
  "NI", // Nicaragua
  "NL", // Netherlands
  "NO", // Norway
  "NZ", // New Sealand
  "PA", // Panama
  "PE", // Peru
  "PF", // French Polynesia
  "PR", // Puerto Rico
  "PT", // Portugal
  "PY", // Paraguay
  "RO", // Romania
  "RU", // Russian Federation
  "SE", // Sweden
  "SV", // El Salvador
  "TF", // French Southern Territories
  "TR", // Turkey
  "UM", // United States Minor Outlying Islands
  "US", // United States
  "UY", // Uruguay
  "VE", // Venezuela
  "VG", // Virgin Islands (British)
  "VI", // Virgin Islands (USA)
  "ZA", // South Africa
};

type find( char const *lang ) {
  DEF_END();
  return FIND( lang );
}

} // namespace iso3166_1

///////////////////////////////////////////////////////////////////////////////

namespace iso639_1 {

char const *const string_of[] = {
  "#UNKNOWN",                           // starts with '#' for sorting
  "da", // Danish
  "de", // German
  "en", // English
  "es", // Spanish
  "fi", // Finnish
  "fr", // French
  "hu", // Hungarian
  "it", // Italian
  "nl", // Dutch
  "no", // Norwegian
  "pt", // Portuguese
  "ro", // Romanian
  "ru", // Russian
  "sv", // Swedish
  "tr", // Turkish
};

type find( char const *lang ) {
  DEF_END();
  return FIND( lang );
}

} // namespace iso639_1

///////////////////////////////////////////////////////////////////////////////

namespace iso639_2 {

char const *const string_of[] = {
  "#UNKNOWN",                           // starts with '#' for sorting
  "dan",  // Danish
  "deu",  // German (T)
  "dut",  // Dutch (B)
  "eng",  // English
  "fin",  // Finnish
  "fra",  // French (T)
  "fre",  // French (B)
  "ger",  // German (B)
  "hun",  // Hungarian
  "ita",  // Italian
  "nld",  // Dutch (T)
  "nor",  // Norwegian
  "por",  // Portuguese
  "ron",  // Romanian (T)
  "rum",  // Romanian (B)
  "rus",  // Russian
  "spa",  // Spanish
  "swe",  // Swedish
  "tur",  // Turkish
};

type find( char const *lang ) {
  DEF_END();
  return FIND( lang );
}

} // namespace iso639_2

///////////////////////////////////////////////////////////////////////////////

iso639_1::type find_lang( char const *lang ) {
  using namespace iso639_1;

  if ( type const code_639_1 = iso639_1::find( lang ) )
    return code_639_1;

  static type const iso639_2_to_639_1[] = {
    unknown,
    da, // dan
    de, // deu
    nl, // dut
    en, // eng
    fi, // fin
    fr, // fra
    fr, // fre
    de, // ger
    hu, // hun
    it, // ita
    nl, // nld
    no, // nor
    pt, // por
    ro, // ron
    ro, // rum
    ru, // rus
    es, // spa
    sv, // swe
    tr, // tur
  };
  return iso639_2_to_639_1[ iso639_2::find( lang ) ];
}

iso3166_1::type get_host_country() {
  //
  // ICU's Locale::getDefault().getLanguage() should be used here, but it
  // sometimes returns "root" which isn't useful.
  //
  static char *country;
  static iso3166_1::type country_code;

  if ( !country ) {
#   ifdef WIN32
    country = get_win32_locale_info( LOCALE_SISO3166CTRYNAME );
#   else
    country = get_unix_locale();
    if ( country ) {
      if ( char *const sep = ::strchr( country, '.' ) )
        *sep = '\0';
      if ( char *const sep = ::strpbrk( country, "_-" ) )
        country = sep + 1;
    }
#   endif /* WIN32 */
    if ( country ) {
      if ( iso3166_1::type const found_code = iso3166_1::find( country ) )
        country_code = found_code;
    }
  }
  return country_code;
}

iso639_1::type get_host_lang() {
  //
  // ICU's Locale::getDefault().getLanguage() should be used here, but it
  // sometimes returns "root" which isn't useful.
  //
  static char *lang_name;
  static iso639_1::type lang_code = iso639_1::en;

  if ( !lang_name ) {
#   ifdef WIN32
    lang_name = get_win32_locale_info( LOCALE_SISO639LANGNAME );
#   else
    lang_name = get_unix_locale();
    if ( lang_name ) {
      if ( char *const sep = ::strpbrk( lang_name, "-_" ) )
        *sep = '\0';
    }
#   endif /* WIN32 */
    if ( lang_name ) {
      if ( iso639_1::type const found_code = find_lang( lang_name ) )
        lang_code = found_code;
    }
  }
  return lang_code;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace locale
} // namespace zorba
/* vim:set et sw=2 ts=2: */
