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
#include "stdafx.h"

#ifdef WIN32
# include <windows.h>
# include "zorbautils/fatal.h"
#else
# include <clocale>
# include <cstdlib>                     /* for getenv(3) */
#endif /* WIN32 */

#include <algorithm>
#include <cstring>

#include <zorba/internal/unique_ptr.h>

#include "util/cxx_util.h"
#include "util/less.h"
#include "util/stl_util.h"

#include "locale.h"

#define DEF_END(CHAR_ARRAY)                             \
  static char const *const *const end =                 \
    CHAR_ARRAY + sizeof( CHAR_ARRAY ) / sizeof( char* )

#define FIND(WHAT) \
  static_cast<type>( find_index( string_of, end, WHAT ) )

using namespace std;

namespace zorba {
namespace locale {

///////////////////////////////////////////////////////////////////////////////

/**
 * A less-verbose way to use std::lower_bound.
 */
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
 * @return Returns said information or \c nullptr.
 */
static char* get_win32_locale_info( int constant ) {
  int bytes = ::GetLocaleInfoA( LOCALE_USER_DEFAULT, constant, NULL, 0 );
  ZORBA_FATAL( bytes, "GetLocaleInfoA() failed" );
  unique_ptr<char[]> info = new char[ bytes ];
  bytes = ::GetLocaleInfoA( LOCALE_USER_DEFAULT, constant, info.get(), bytes );
  ZORBA_FATAL( bytes, "GetLocaleInfoA() failed" );
  return info.release();
}

#else /* WIN32 */

/**
 * Checks for and filters-out "useless" locales.
 *
 * @param loc The locale to check.
 * @return If the locale is either useless or \c nullptr, returns \c nullptr;
 * otherwise returns the locale.
 */
inline char const* filter_useless_locale( char const *loc ) {
  if ( loc && (::strcmp( loc, "C" ) == 0 || ::strcmp( loc, "POSIX" ) == 0) )
    return nullptr;
  return loc;
}

/**
 * Gets the environment's locale.
 *
 * @return Returns said locale, e.g., "en_US.UTF-8" or \c nullptr.
 */
static char* get_unix_locale() {
  //
  // Try the environment locale first.
  //
  char const *loc = filter_useless_locale( ::setlocale( LC_ALL, "" ) );
  if ( !loc ) {
    //
    // Try the "LANG" environment variable second.
    //
    loc = filter_useless_locale( ::getenv( "LANG" ) );
  }
  return loc ? ztd::new_strdup( loc ) : nullptr;
}

#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

namespace iso3166_1 {

char const *const string_of[] = {
  "#UNKNOWN",                           // starts with '#' for sorting
  "AD", // Andorra
  "AE", // United Arab Emirates
  "AF", // Afghanistan
  "AG", // Antigua and Barbuda
  "AI", // Anguilla
  "AL", // Albania
  "AM", // Armenia
  "AN", // Netherlands Antilles
  "AO", // Angola
  "AQ", // AntarcticA
  "AR", // Argentina
  "AS", // American Samoa
  "AT", // Austria
  "AU", // Australia
  "AW", // Aruba
  "AX", // Aland Islands
  "AZ", // Azerbaijan
  "BA", // Bosnia and Herzegovina
  "BB", // Barbados
  "BD", // Bangladesh
  "BE", // Belgium
  "BF", // Burkina Faso
  "BG", // Bulgaria
  "BH", // Bahrain
  "BI", // Burundi
  "BJ", // Benin
  "BL", // Saint Barthelemy
  "BM", // Bermuda
  "BN", // Brunei Darussalam
  "BO", // Bolivia
  "BR", // Brazil
  "BS", // Bahamas
  "BT", // Bhutan
  "BV", // Bouvet Island
  "BW", // Botswana
  "BY", // Belarus
  "BZ", // Belize
  "CA", // Canada
  "CC", // Cocos Islands
  "CD", // Congo
  "CF", // Central African Republic
  "CG", // Congo
  "CH", // Switzerland
  "CI", // Cote D'Ivoire
  "CK", // Cook Islands
  "CL", // Chile
  "CM", // Cameroon
  "CN", // China
  "CO", // Colombia
  "CR", // Costa Rica
  "CU", // Cuba
  "CV", // Cape Verde
  "CX", // Christmas Island
  "CY", // Cyprus
  "CZ", // Czech Republic
  "DE", // Germany
  "DJ", // Djibouti
  "DK", // Denmark
  "DM", // Dominica
  "DO", // Dominican Republic
  "DZ", // Algeria
  "EC", // Ecuador
  "EE", // Estonia
  "EG", // Egypt
  "EH", // Western Sahara
  "ER", // Eritrea
  "ES", // Spain
  "ET", // Ethiopia
  "FI", // Finland
  "FJ", // Fiji
  "FK", // Falkland Islands
  "FM", // Micronesia
  "FO", // Faroe Islands
  "FR", // France
  "GA", // Gabon
  "GB", // United Kingdom
  "GD", // Grenada
  "GE", // Georgia
  "GF", // French Guiana
  "GG", // Guernsey
  "GH", // Ghana
  "GI", // Gibraltar
  "GL", // Greenland
  "GM", // Gambia
  "GN", // Guinea
  "GP", // Guadeloupe
  "GQ", // Equatorial Guinea
  "GR", // Greece
  "GS", // South Georgia and the South Sandwich Islands
  "GT", // Guatemala
  "GU", // Guam
  "GW", // Guinea-Bissau
  "GY", // Guyana
  "HK", // Hong Kong
  "HM", // Heard Island and Mcdonald Islands
  "HN", // Honduras
  "HR", // Croatia
  "HT", // Haiti
  "HU", // Hungary
  "ID", // Indonesia
  "IE", // Ireland
  "IL", // Israel
  "IM", // Isle of Man
  "IN", // India
  "IO", // British Indian Ocean Territory
  "IQ", // Iraq
  "IR", // Iran
  "IS", // Iceland
  "IT", // Italy
  "JE", // Jersey
  "JM", // Jamaica
  "JO", // Jordan
  "JP", // Japan
  "KE", // Kenya
  "KG", // Kyrgyzstan
  "KH", // Cambodia
  "KI", // Kiribati
  "KM", // Comoros
  "KN", // Saint Kitts and Nevis
  "KP", // Korea (Democratic People's Republic)
  "KR", // Korea
  "KW", // Kuwait
  "KY", // Cayman Islands
  "KZ", // Kazakhstan
  "LA", // Lao
  "LB", // Lebanon
  "LC", // Saint Lucia
  "LI", // Liechtenstein
  "LK", // Sri Lanka
  "LR", // Liberia
  "LS", // Lesotho
  "LT", // Lithuania
  "LU", // Luxembourg
  "LV", // Latvia
  "LY", // Libyan Arab Jamahiriya
  "MA", // Morocco
  "MC", // Monaco
  "MD", // Moldova
  "ME", // Montenegro
  "MF", // Saint Martin
  "MG", // Madagascar
  "MH", // Marshall Islands
  "MK", // Macedonia
  "ML", // Mali
  "MM", // Myanmar
  "MN", // Mongolia
  "MO", // Macao
  "MP", // Northern Mariana Islands
  "MQ", // Martinique
  "MR", // Mauritania
  "MS", // Montserrat
  "MT", // Malta
  "MU", // Mauritius
  "MV", // Maldives
  "MW", // Malawi
  "MX", // Mexico
  "MY", // Malaysia
  "MZ", // Mozambique
  "NA", // Namibia
  "NC", // New Caledonia
  "NE", // Niger
  "NF", // Norfolk Island
  "NG", // Nigeria
  "NI", // Nicaragua
  "NL", // Netherlands
  "NO", // Norway
  "NP", // Nepal
  "NR", // Nauru
  "NU", // Niue
  "NZ", // New Zealand
  "OM", // Oman
  "PA", // Panama
  "PE", // Peru
  "PF", // French Polynesia
  "PG", // Papua New Guinea
  "PH", // Philippines
  "PK", // Pakistan
  "PL", // Poland
  "PM", // Saint Pierre and Miquelon
  "PN", // Pitcairn
  "PR", // Puerto Rico
  "PS", // Palestinian Territory
  "PT", // Portugal
  "PW", // Palau
  "PY", // Paraguay
  "QA", // Qatar
  "RE", // Reunion
  "RO", // Romania
  "RS", // Serbia
  "RU", // Russian Federation
  "RW", // Rwanda
  "SA", // Saudi Arabia
  "SB", // Solomon Islands
  "SC", // Seychelles
  "SD", // Sudan
  "SE", // Sweden
  "SG", // Singapore
  "SH", // Saint Helena
  "SI", // Slovenia
  "SJ", // Svalbard and Jan Mayen
  "SK", // Slovakia
  "SL", // Sierra Leone
  "SM", // San Marino
  "SN", // Senegal
  "SO", // Somalia
  "SR", // Suriname
  "ST", // Sao Tome and Principe
  "SV", // El Salvador
  "SY", // Syria
  "SZ", // Swaziland
  "TC", // Turks and Caicos Islands
  "TD", // Chad
  "TF", // French Southern Territories
  "TG", // Togo
  "TH", // Thailand
  "TJ", // Tajikistan
  "TK", // Tokelau
  "TL", // Timor-Leste
  "TM", // Turkmenistan
  "TN", // Tunisia
  "TO", // Tonga
  "TR", // Turkey
  "TT", // Trinidad and Tobago
  "TV", // Tuvalu
  "TW", // Taiwan
  "TZ", // Tanzania
  "UA", // Ukraine
  "UG", // Uganda
  "UM", // United States Minor Outlying Islands
  "US", // United States
  "UY", // Uruguay
  "UZ", // Uzbekistan
  "VA", // Vatican
  "VC", // Saint Vincent and the Grenadines
  "VE", // Venezuela
  "VG", // Virgin Islands (British)
  "VI", // Virgin Islands (USA)
  "VN", // Viet Nam
  "VU", // Vanuatu
  "WF", // Wallis and Futuna
  "WS", // Samoa
  "YE", // Yemen
  "YT", // Mayotte
  "ZA", // South Africa
  "ZM", // Zambia
  "ZW", // Zimbabwe
};

type find( char const *country ) {
  DEF_END( string_of );
  return FIND( country );
}

} // namespace iso3166_1

///////////////////////////////////////////////////////////////////////////////

namespace iso639_1 {

char const *const string_of[] = {
  "#UNKNOWN",                           // starts with '#' for sorting
  "aa", // Afar
  "ab", // Abkhazian
  "ae", // Avestan
  "af", // Afrikaans
  "ak", // Akan
  "am", // Amharic
  "an", // Aragonese
  "ar", // Arabic
  "as", // Assamese
  "av", // Avaric
  "ay", // Aymara
  "az", // Azerbaijani
  "ba", // Bashkir
  "be", // Byelorussian
  "bg", // Bulgarian
  "bh", // Bihari
  "bi", // Bislama
  "bm", // Bambara
  "bn", // Bengali; Bangla
  "bo", // Tibetan
  "br", // Breton
  "bs", // Bosnian
  "ca", // Catalan
  "ce", // Chechen
  "ch", // Chamorro
  "co", // Corsican
  "cr", // Cree
  "cs", // Czech
  "cu", // Church Slavic; Church Slavonic
  "cv", // Chuvash
  "cy", // Welsh
  "da", // Danish
  "de", // German
  "dv", // Divehi
  "dz", // Bhutani
  "ee", // Ewe
  "el", // Greek
  "en", // English
  "eo", // Esperanto
  "es", // Spanish
  "et", // Estonian
  "eu", // Basque
  "fa", // Persian
  "ff", // Fulah
  "fi", // Finnish
  "fj", // Fiji
  "fo", // Faroese
  "fr", // French
  "fy", // Frisian
  "ga", // Irish
  "gd", // Scots Gaelic
  "gl", // Galician
  "gl", // Galician
  "gn", // Guarani
  "gu", // Gujarati
  "gv", // Manx
  "ha", // Hausa
  "he", // Hebrew (formerly iw)
  "hi", // Hindi
  "ho", // Hiri Motu
  "hr", // Croatian
  "ht", // Haitian Creole
  "hu", // Hungarian
  "hy", // Armenian
  "hz", // Herero
  "ia", // Interlingua
  "id", // Indonesian (formerly in)
  "ie", // Interlingue
  "ig", // Igbo
  "ii", // Nuosu
  "ik", // Inupiak
  "io", // Ido
  "is", // Icelandic
  "it", // Italian
  "iu", // Inuktitut
  "ja", // Japanese
  "jw", // Javanese
  "ka", // Georgian
  "kg", // Kongo
  "ki", // Gikuyu
  "kj", // Kuanyama
  "kk", // Kazakh
  "kl", // Greenlandic
  "kl", // Greenlandic
  "km", // Cambodian
  "kn", // Kannada
  "ko", // Korean
  "kr", // Kanuri
  "ks", // Kashmiri
  "ku", // Kurdish
  "kv", // Komi
  "kw", // Cornish
  "ky", // Kirghiz
  "la", // Latin
  "lb", // Letzeburgesch
  "lg", // Ganda
  "li", // Limburgan; Limburger; Limburgish
  "ln", // Lingala
  "lo", // Laothian
  "lt", // Lithuanian
  "lu", // Luba-Katanga
  "lv", // Latvian, Lettish
  "mg", // Malagasy
  "mh", // Marshallese
  "mi", // Maori
  "mk", // Macedonian
  "ml", // Malayalam
  "mn", // Mongolian
  "mo", // Moldavian
  "mr", // Marathi
  "ms", // Malay
  "mt", // Maltese
  "my", // Burmese
  "na", // Nauru
  "nb", // Norwegian Bokmal
  "nd", // Ndebele, North
  "ne", // Nepali
  "ng", // Ndonga
  "nl", // Dutch
  "nn", // Norwegian Nynorsk
  "no", // Norwegian
  "nr", // Ndebele, South
  "nv", // Navajo; Navaho
  "ny", // Chichewa; Chewa; Nyanja
  "oc", // Occitan
  "oj", // Ojibwa
  "om", // (Afan) Oromo
  "or", // Oriya
  "os", // Ossetian; Ossetic
  "pa", // Panjabi; Punjabi
  "pi", // Pali
  "pl", // Polish
  "ps", // Pashto; Pushto
  "pt", // Portuguese
  "qu", // Quechua
  "rm", // Romansh
  "rn", // Kirundi
  "ro", // Romanian
  "ru", // Russian
  "rw", // Kinyarwanda
  "sa", // Sanskrit
  "sc", // Sardinian
  "sd", // Sindhi
  "se", // Northern Sami
  "sg", // Sangho
  "sh", // Serbo-Croatian
  "si", // Sinhalese
  "sk", // Slovak
  "sl", // Slovenian
  "sm", // Samoan
  "sn", // Shona
  "so", // Somali
  "sq", // Albanian
  "sr", // Serbian
  "ss", // Siswati
  "st", // Sesotho
  "su", // Sundanese
  "sv", // Swedish
  "sw", // Swahili
  "ta", // Tamil
  "te", // Telugu
  "tg", // Tajik
  "th", // Thai
  "ti", // Tigrinya
  "tk", // Turkmen
  "tl", // Tagalog
  "tn", // Setswana
  "to", // Tonga
  "tr", // Turkish
  "ts", // Tsonga
  "tt", // Tatar
  "tw", // Twi
  "ty", // Tahitian
  "ug", // Uighur
  "uk", // Ukrainian
  "ur", // Urdu
  "uz", // Uzbek
  "ve", // Venda
  "vi", // Vietnamese
  "vo", // Volapuk
  "wa", // Walloon
  "wo", // Wolof
  "xh", // Xhosa
  "yi", // Yiddish (formerly ji)
  "yo", // Yoruba
  "za", // Zhuang
  "zh", // Chinese
  "zu", // Zulu
};

type find( char const *lang ) {
  DEF_END( string_of );
  return FIND( lang );
}

} // namespace iso639_1

///////////////////////////////////////////////////////////////////////////////

namespace iso639_2 {

char const *const string_of[] = {
  "#UNKNOWN",                           // starts with '#' for sorting
  "abk",  // Abkhazian
  "aar",  // Afar
  "afr",  // Afrikaans
  "aka",  // Akan
  "alb",  // Albanian
  "amh",  // Amharic
  "ara",  // Arabic
  "arg",  // Aragonese
  "arm",  // Armenian
  "asm",  // Assamese
  "ava",  // Avaric
  "ave",  // Avestan
  "aym",  // Aymara
  "aze",  // Azerbaijani
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
  DEF_END( string_of );
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
    ab, // abk
    aa, // aar
    af, // arf
    ak, // aka
    sq, // alb
    am, // amh
    ar, // ara
    an, // arg
    ay, // aym
    az, // aze
    hy, // arm
    as, // asm
    av, // ava
    ae, // ave
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
  static unique_ptr<char[]> country_name;
  static iso3166_1::type country_code;

  if ( !country_name ) {
#   ifdef WIN32
    char *loc_info = get_win32_locale_info( LOCALE_SISO3166CTRYNAME );
#   else
    char *loc_info = get_unix_locale();
    if ( loc_info ) {
      //
      // Extract just the country's name from the locale, e.g., convert
      // "en_US.UTF-8" to "US".
      //
      if ( char *const sep = ::strchr( loc_info, '.' ) )
        *sep = '\0';
      if ( char *const sep = ::strpbrk( loc_info, "_-" ) ) {
        //
        // We have to allocate a new string for just the country since
        // unique_ptr can't point to a character that isn't the first otherwise
        // its call to delete[] will be undefined.
        //
        unique_ptr<char[]> const old_loc_info( loc_info );
        loc_info = ztd::new_strdup( sep + 1 );
      }
    }
#   endif /* WIN32 */
    if ( loc_info ) {
      country_name.reset( loc_info );
      if ( iso3166_1::type const found_code = iso3166_1::find( loc_info ) )
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
  static unique_ptr<char[]> lang_name;
  static iso639_1::type lang_code = iso639_1::en;

  if ( !lang_name ) {
#   ifdef WIN32
    char *const loc_info = get_win32_locale_info( LOCALE_SISO639LANGNAME );
#   else
    char *const loc_info = get_unix_locale();
    if ( loc_info ) {
      //
      // Extract just the language from the locale, e.g., convert "en_US.UTF-8"
      // to "en".
      //
      if ( char *const sep = ::strpbrk( loc_info, "-_" ) )
        *sep = '\0';
    }
#   endif /* WIN32 */
    if ( loc_info ) {
      lang_name.reset( loc_info );
      if ( iso639_1::type const found_code = find_lang( loc_info ) )
        lang_code = found_code;
    }
  }
  return lang_code;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace locale
} // namespace zorba
/* vim:set et sw=2 ts=2: */
