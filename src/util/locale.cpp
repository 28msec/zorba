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

// standard
#include <algorithm>
#include <cstring>
#include <stdexcept>
#ifdef WIN32
# include <windows.h>
# include "zorbautils/fatal.h"
#else
# include <clocale>
# include <cstdlib>                     /* for getenv(3) */
# include <langinfo.h>                  /* for nl_langinfo(3) */
# include <xlocale.h>                   /* for newlocale(3) */
#endif /* WIN32 */

// Zorba
#include <zorba/internal/cxx_util.h>
#include <zorba/internal/unique_ptr.h>
#include "util/ascii_util.h"
#include "util/less.h"
#include "util/stl_util.h"
#include "util/string_util.h"

// local
#include "locale.h"

#define DEF_END(CHAR_ARRAY)                             \
  static char const *const *const end =                 \
    CHAR_ARRAY + sizeof( CHAR_ARRAY ) / sizeof( char* )

#define DEF_LENGTH(CHAR_ARRAY) \
  static size_t const length = sizeof( CHAR_ARRAY ) / sizeof( char* )

#define FIND(WHAT) \
  static_cast<type>( find_index( string_of, end, WHAT ) )

using namespace std;

namespace zorba {
namespace locale {

#ifdef WIN32
typedef LCTYPE locale_index_type;
#else
typedef nl_item locale_index_type;
#endif /* WIN32 */

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
 * Gets the name of the locale for the given language and country in the format
 * that Windows expects.
 *
 * @param lang The language to use.
 * @param country The country to use, if any.
 * @return Returns a pointre to the UTF-16 buffer containing the locale name.
 */
static unique_ptr<WCHAR[]> get_wlocale_name( iso639_1::type lang,
                                             iso3166_1::type country ) {
  assert( lang );

  zstring locale_name( iso639_1::str( lang ) );
  if ( country ) {
    locale_name += '-';
    locale_name += iso3166_1::str( country );
  }

  unique_ptr<WCHAR[]> wlocale_name( new WCHAR[ LOCALE_NAME_MAX_LENGTH ] );
  win32::atow(
    locale_name.c_str(), wlocale_name.get(), LOCALE_NAME_MAX_LENGTH
  );
  return wlocale_name;
}

/**
 * Gets a particular piece of information from the user's default locale.
 *
 * @param constant The constant specifying which piece of locale information to
 * get.
 * @return Returns said information or an emptr string.
 */
static zstring get_locale_info( int constant ) {
  int wlen = ::GetLocaleInfo( LOCALE_USER_DEFAULT, constant, NULL, 0 );
  if ( !wlen )
    return zstring();
  unique_ptr<WCHAR[]> winfo( new WCHAR[ wlen ] );
  wlen = ::GetLocaleInfo( LOCALE_USER_DEFAULT, constant, winfo.get(), wlen );
  ZORBA_FATAL( wlen, "GetLocaleInfo() failed" );
  unique_ptr<char[]> const info( win32::wtoa( winfo.get() ) );
  return zstring( info.get() );
}

/**
 * GetLocaleInfoEx() is available only on Windows Vista and later so we can't
 * call it directly since we might be running on Windows XP.  Hence, check to
 * see if it's available and call it indirectly if so.
 */
static int Zorba_GetLocaleInfoEx( LPCWSTR lpLocaleName, LCTYPE LCType,
                                  LPWSTR lpLCData, int cchData ) {
  typedef int (WINAPI *GetLocaleInfoEx_type)( LPCWSTR, LCTYPE, LPWSTR, int );

  static GetLocaleInfoEx_type GetLocaleInfoEx_ptr;
  static bool init;

  if ( !init ) {
    GetLocaleInfoEx_ptr = (GetLocaleInfoEx_type)::GetProcAddress(
      ::GetModuleHandle( TEXT( "kernel32.dll" ) ), "GetLocaleInfoEx"
    );
    init = true;
  }

  return GetLocaleInfoEx_ptr ?
    GetLocaleInfoEx_ptr( lpLocaleName, LCType, lpLCData, cchData ) : 0;
}

/**
 * Gets a particular piece of information from a locale.
 *
 * @param constant The constant specifying which piece of locale information to
 * get.
 * @param lang The language to use, if any.
 * @param country The country to use, if any.
 * @return Returns said information or an empty string.
 */
static zstring get_locale_info( int constant, iso639_1::type lang,
                                iso3166_1::type country ) {
  LPCWSTR wlocale_name;
  unique_ptr<WCHAR[]> wlocale_name_ptr;

  if ( !country )
    country = iso3166_1::get_default( lang );
  if ( lang && country ) {
    wlocale_name_ptr = get_wlocale_name( lang, country );
    wlocale_name = wlocale_name_ptr.get();
  } else
    wlocale_name = LOCALE_NAME_USER_DEFAULT;

  int wlen = Zorba_GetLocaleInfoEx( wlocale_name, constant, NULL, 0 );
  if ( !wlen )
    return zstring();
  unique_ptr<WCHAR[]> winfo( new WCHAR[ wlen ] );
  wlen = Zorba_GetLocaleInfoEx( wlocale_name, constant, winfo.get(), wlen );
  ZORBA_FATAL( wlen, "GetLocaleInfoEx() failed" );

  unique_ptr<char[]> const info( win32::wtoa( winfo.get() ) );
  return zstring( info.get() );
}

/**
 * IsValidLocaleName() is available only on Windows Vista and later so we can't
 * call it directly since we might be running on Windows XP.  Hence, check to
 * see if it's available and call it indirectly if so.
 */
static bool Zorba_IsValidLocaleName( LPCWSTR lpLocaleName ) {
  typedef int (WINAPI *IsValidLocaleName_type)( LPCWSTR );

  static IsValidLocaleName_type IsValidLocaleName_ptr;
  static bool init;

  if ( !init ) {
    IsValidLocaleName_ptr = (IsValidLocaleName_type)::GetProcAddress(
      ::GetModuleHandle( TEXT( "kernel32.dll" ) ), "IsValidLocaleName"
    );
    init = true;
  }

  return IsValidLocaleName_ptr ?
    !!IsValidLocaleName_ptr( lpLocaleName ) : false;
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
static zstring get_unix_locale() {
  //
  // Try the environment locale first.
  //
  char const *loc = filter_useless_locale( ::setlocale( LC_ALL, nullptr ) );
  if ( !loc ) {
    //
    // Try the "LANG" environment variable second.
    //
    loc = filter_useless_locale( ::getenv( "LANG" ) );
  }
  zstring result;
  if ( loc && *loc )
    result = loc;
  return result;
}

/**
 * Gets the locale_t corresponding to the given language and country.  It is
 * the caller's responsibility to call \c freelocale(3) on the result.
 *
 * @param lang The language.
 * @param country The country.
 * @return Returns said \c locale_t or \c (locale_t)0.
 */
static locale_t get_unix_locale_t( iso639_1::type lang,
                                   iso3166_1::type country ) {
  zstring locale_name( iso639_1::str( lang ) );
  if ( country ) {
    locale_name += '_';
    locale_name += iso3166_1::str( country );
  }
  locale_name += ".UTF-8";
  locale_t loc = ::newlocale( LC_TIME_MASK, locale_name.c_str(), nullptr );
  if ( !loc && country ) {              // try it without the country
    locale_name = iso639_1::str( lang );
    locale_name += ".UTF-8";
    loc = ::newlocale( LC_TIME_MASK, locale_name.c_str(), nullptr );
  }
  return loc;
}

/**
 * Gets a particular piece of information from a locale.
 *
 * @param item The constant specifying which piece of locale information to
 * get.
 * @param lang The language to use, if any.
 * @param country The country to use, if any.
 * @return Returns said information or an empty string.
 */
static zstring get_locale_info( nl_item item, iso639_1::type lang,
                                iso3166_1::type country ) {
  if ( lang ) {
    if ( !country )
      country = iso3166_1::get_default( lang );
    if ( locale_t const loc = get_unix_locale_t( lang, country ) ) {
      char const *const info = nl_langinfo_l( item, loc );
      ::freelocale( loc );
      return info;
    }
    return zstring();
  }
  return nl_langinfo( item );
}

#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

namespace iso3166_1 {

static char const *const string_of[] = {
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

type get_default( iso639_1::type lang ) {
  //
  // In cases where a language maps to multiple countries, if the language is
  // the official language of a single country, that country is the one the
  // language is mapped to.
  //
  static type const lang_to_country[] = {
    unknown,
    DJ     , // aa: Afar => Djibouti
    GE     , // ab: Abkhazian => Georgia
    IR     , // ae: Avestan => Iran
    ZA     , // af: Afrikaans => South Africa
    GH     , // ak: Akan => Ghana
    ET     , // am: Amharic => Ethiopia
    ES     , // an: Aragonese => Spain
    unknown, // ar: Arabic => (maps to multiple countries)
    IN_    , // as: Assamese => India
    AZ     , // av: Avaric => Azerbaijan
    BO     , // ay: Aymara => Bolivia
    AZ     , // az: Azerbaijani => Azerbaijan
    RU     , // ba: Bashkir => Russian Federation
    RU     , // be: Byelorussian => Russian Federation
    BG     , // bg: Bulgarian => Bulgaria
    IN_    , // bh: Bihari => India
    VU     , // bi: Bislama => Vanuatu
    ML     , // bm: Bambara => Mali
    BD     , // bn: Bengali; Bangla => Bangladesh
    CN     , // bo: Tibetan => China
    FR     , // br: Breton => France
    BA     , // bs: Bosnian => Bosnia
    AD     , // ca: Catalan => Andorra
    RU     , // ce: Chechen => Russian Federation
    MP     , // ch: Chamorro => Northern Mariana Islands
    FR     , // co: Corsican => France
    US     , // cr: Cree => United States
    CZ     , // cs: Czech => Czech Republic
    RU     , // cu: Church Slavic; Church Slavonic => Russian Federation
    RU     , // cv: Chuvash => Russian Federation
    GB     , // cy: Welsh => United Kingdom
    DK     , // da: Danish => Denmark
    DE     , // de: German => Germany
    MV     , // dv: Divehi => Maldives
    PK     , // dz: Bhutani => Pakistan
    unknown, // ee: Ewe => (maps to multiple countries)
    GR     , // el: Greek => Greece
    US     , // en: English => United States
    unknown, // eo: Esperanto => (constructed language)
    ES     , // es: Spanish => Spain
    EE     , // et: Estonian => Estonia
    ES     , // eu: Basque => Spain
    IR     , // fa: Persian => Iran
    unknown, // ff: Fulah => (maps to multiple countries)
    FI     , // fi: Finnish => Finland
    FJ     , // fj: Fiji => Fiji
    FO     , // fo: Faroese => Faroe Islands
    FR     , // fr: French => France
    NL     , // fy: Frisian => Netherlands
    IE     , // ga: Irish => Ireland
    GB     , // gd: Scots Gaelic => United Kingdom
    ES     , // gl: Galician => Spain
    PY     , // gn: Guarani => Paraguay
    IN_    , // gu: Gujarati => India
    IM     , // gv: Manx => Isle of Man
    unknown, // ha: Hausa => (maps to multiple languages)
    IL     , // he: Hebrew => Israel
    IN_    , // hi: Hindi => India
    PG     , // ho: Hiri Motu => Papua New Guinea
    HR     , // hr: Croatian => Croatia
    HT     , // ht: Haitian Creole => Haiti
    HU     , // hu: Hungarian => Hungary
    AM     , // hy: Armenian => Armenia
    unknown, // hz: Herero => (maps to multiple countries)
    unknown, // ia: Interlingua => (constructed language)
    ID     , // id: Indonesian => Indonesia
    unknown, // ie: Interlingue => (constructed language)
    NG     , // ig: Igbo => Nigeria
    CN     , // ii: Nuosu => China
    US     , // ik: Inupiak => United States
    unknown, // io: Ido => (constructed language)
    IS     , // is: Icelandic => Island
    IT     , // it: Italian => Italy
    CA     , // iu: Inuktitut => Canada
    JP     , // ja: Japanese => Japan
    ID     , // jv: Javanese => Indonesia
    GE     , // ka: Georgian => Georgia
    unknown, // kg: Kongo => (maps to multiple countries)
    KE     , // ki: Gikuyu => Kenya
    unknown, // kj: Kuanyama => (maps to multiple countries)
    KZ     , // kk: Kazakh => Kazakhstan
    GL     , // kl: Greenlandic => Greenland
    KH     , // km: Cambodian => Cambodia
    IN_    , // kn: Kannada => India
    KR     , // ko: Korean => Korea
    unknown, // kr: Kanuri => (maps to multiple countries)
    IN_    , // ks: Kashmiri => India
    IQ     , // ku: Kurdish => Iraq
    RU     , // kv: Komi => Russian Federation
    GB     , // kw: Cornish => United Kingdom
    KG     , // ky: Kirghiz => Kyrgyzstan
    unknown, // la: Latin => (maps to multiple countries)
    LU     , // lb: Letzeburgesch => Luxembourg
    UG     , // lg: Ganda => Uganda
    NL     , // li: Limburgan; Limburger; Limburgish => Netherands
    unknown, // ln: Lingala => (maps to multiple countries)
    LA     , // lo: Laotian => Lao
    LT     , // lt: Lithuanian => Lithuania
    CD     , // lu: Luba-Katanga => Democratic Republic of the Congo
    LV     , // lv: Latvian => Latvia
    MG     , // mg: Malagasy => Madagascar
    MH     , // mh: Marshallese => Marshall Islands
    NZ     , // mi: Maori => New Zealand
    MK     , // mk: Macedonian => Macedonia
    IN_    , // ml: Malayalam => India
    MN     , // mn: Mongolian => Mongolia
    MD     , // mo: Moldavian => Moldova
    IN_    , // mr: Marathi => India
    MY     , // ms: Malay => Malaysia
    MT     , // mt: Maltese => Malta
    MM     , // my: Burmese => Myanmar (Burma)
    NR     , // na: Nauru => Nauru
    NO     , // nb: Norwegian Bokmal => Norway
    ZW     , // nd: Ndebele, North => Zimbabwe
    NP     , // ne: Nepali => Nepal
    NA     , // ng: Ndonga => Namibia
    NL     , // nl: Dutch => Netherlands
    NO     , // nn: Norwegian Nynorsk => Norway
    NO     , // no: Norwegian => Norway
    ZA     , // nr: Ndebele, South => South Africa
    US     , // nv: Navajo; Navaho => United States
    MW     , // ny: Chichewa; Chewa; Nyanja => Malawi
    unknown, // oc: Occitan => (maps to multiple countries)
    CA     , // oj: Ojibwa => Canada
    unknown, // om: Oromo => (maps to multiple countries)
    IN_    , // or: Oriya => India
    unknown, // os: Ossetian; Ossetic => (maps to multiple countries)
    PK     , // pa: Panjabi; Punjabi => Pakistan
    unknown, // pi: Pali => (maps to multiple countries)
    PL     , // pl: Polish => Poland
    AF     , // ps: Pashto, Pushto => Afghanistan
    PT     , // pt: Portuguese => Portugal
    unknown, // qu: Quechua => (maps to multiple countries)
    CH     , // rm: Romansh => Switzerland
    BI     , // rn: Kirundi => Burundi
    RO     , // ro: Romanian => Romania
    RU     , // ru: Russian => Russian Federation
    RW     , // rw: Kinyarwanda => Rwanda
    IN_    , // sa: Sanskrit => India
    IT     , // sc: Sardinian => Italy
    PK     , // sd: Sindhi => Pakistan
    NO     , // se: Northern Sami => Norway
    CF     , // sg: Sangho => Central African Republic
    RS     , // sh: Serbo-Croatian => Serbia
    LK     , // si: Sinhalese => Sri Lanka
    SK     , // sk: Slovak => Slovakia
    SI     , // sl: Slovenian => Slovenia
    AS     , // sm: Samoan => American Samoa
    ZW     , // sn: Shona => Zimbabwe
    SO     , // so: Somali => Somalia
    AL     , // sq: Albanian => Albania
    RS     , // sr: Serbian => Serbia
    SZ     , // ss: Siswati => Swaziland
    LS     , // st: Sesotho => Lesotho
    SD     , // su: Sundanese => Sudan
    SE     , // sv: Swedish => Sweden
    KE     , // sw: Swahili => Kenya
    IN_    , // ta: Tamil => India
    IN_    , // te: Telugu => India
    TJ     , // tg: Tajik => Tajikistan
    TH     , // th: Thai => Thailand
    ER     , // ti: Tigrinya => Eritrea
    TM     , // tk: Turkmen => Turkmenistan
    PH     , // tl: Tagalog => Philippines
    ZA     , // tn: Setswana => South Africa
    TO     , // to: Tonga => Tonga
    TR     , // tr: Turkish => Turkey
    ZA     , // ts: Tsonga => South Africa
    RU     , // tt: Tatar => Russian Federation
    GH     , // tw: Twi => Ghana
    PF     , // ty: Tahitian => French Polynesia
    CN     , // ug: Uighur => China
    UA     , // uk: Ukrainian => Ukrain
    PK     , // ur: Urdu => Pakistan
    UZ     , // uz: Uzbek => Uzbekistan
    ZA     , // ve: Venda => South Africa
    VN     , // vi: Vietnamese => Viet Nam
    DE     , // vo: Volapuk => Germany
    BE     , // wa: Walloon => Belgium
    SN     , // wo: Wolof => Senegal
    ZA     , // xh: Xhosa => South Africa
    IL     , // yi: Yiddish => Israel
    NG     , // yo: Yoruba => Nigeria
    CN     , // za: Zhuang => China
    CN     , // zh: Chinese => China
    ZA     , // zu: Zulu => South Africa
  };
  assert( lang < iso639_1::NUM_ENTRIES );
  return lang_to_country[ lang ];
}

char const* str( type t ) {
  DEF_LENGTH( string_of );
  int const i = static_cast<int>( t );
  return i >= 0 && i < static_cast<int>(length) ? string_of[ i ] : "UNKNOWN";
}

} // namespace iso3166_1

///////////////////////////////////////////////////////////////////////////////

namespace iso639_1 {

static char const *const string_of[] = {
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
  "jv", // Javanese
  "ka", // Georgian
  "kg", // Kongo
  "ki", // Gikuyu
  "kj", // Kuanyama
  "kk", // Kazakh
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

char const* str( type t ) {
  DEF_LENGTH( string_of );
  int const i = static_cast<int>( t );
  return i >= 0 && i < static_cast<int>(length) ? string_of[ i ] : "UNKNOWN";
}

} // namespace iso639_1

///////////////////////////////////////////////////////////////////////////////

namespace iso639_2 {

static char const *const string_of[] = {
  "#UNKNOWN",                           // starts with '#' for sorting
  "aar",  // Afar
  "abk",  // Abkhazian
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
  "bak",  // Bashkir
  "bam",  // Bambara
  "baq",  // Basque
  "bel",  // Belarusian
  "ben",  // Bengali
  "bih",  // Bihari
  "bis",  // Bislama
  "bos",  // Bosnian
  "bre",  // Breton
  "bul",  // Bulgarian
  "bur",  // Burmese
  "cat",  // Catalan
  "cha",  // Chamorro
  "che",  // Chechen
  "chi",  // Chinese
  "chu",  // Church Slavic; Old Slavonic; Church Slavonic
  "cym",  // Welsh
  "dan",  // Danish
  "deu",  // German (T)
  "div",  // Divehi; Dhivehi; Maldivian
  "dut",  // Dutch (B)
  "dzo",  // Dzongkha
  "ell",  // Modern Greek
  "eng",  // English
  "epo",  // Esperanto
  "est",  // Estonian
  "ewe",  // Ewe
  "fao",  // Faroese
  "fij",  // Fijian
  "fin",  // Finnish
  "fra",  // French (T)
  "fre",  // French (B)
  "fry",  // Western Frisian
  "ful",  // Fulah
  "geo",  // Georgian
  "ger",  // German (B)
  "gla",  // Scottish Gaelic; Gaelic
  "gle",  // Irish
  "glg",  // Galician
  "glv",  // Manx
  "gre",  // Modern Greek
  "grn",  // Guarani
  "guj",  // Gujarati
  "hat",  // Haitian Creole; Haitian
  "hau",  // Hausa
  "heb",  // Hebrew
  "her",  // Herero
  "hin",  // Hindi
  "hmo",  // Hiri Motu
  "hrv",  // Croatian
  "hun",  // Hungarian
  "ibo",  // Igbo
  "ice",  // Icelandic
  "ido",  // Ido
  "iku",  // Inuktitut
  "ile",  // Interlingue; Occidental
  "ina",  // Interlingua
  "ind",  // Indonesian
  "ipk",  // Inupiaq
  "isl",  // Icelandic
  "ita",  // Italian
  "jav",  // Javanese
  "jpn",  // Japanese
  "kal",  // Kalaallisut; Greenlandic
  "kan",  // Kannada
  "kas",  // Kashmiri
  "kat",  // Georgian
  "kau",  // Kanuri
  "kaz",  // Kazakh
  "khm",  // Central Khmer
  "kik",  // Kikuyu; Gikuyu
  "kin",  // Kinyarwanda
  "kir",  // Kirghiz; Kyrgyz
  "kom",  // Komi
  "kon",  // Kongo
  "kor",  // Korean
  "kua",  // Kuanyama; Kwanyama
  "kur",  // Kurdish
  "lao",  // Lao
  "lat",  // Latin
  "lav",  // Latvian
  "lim",  // Limburgan; Limburger; Limburgish
  "lin",  // Lingala
  "lit",  // Lithuanian
  "ltz",  // Luxembourgish; Letzeburgesch
  "lib",  // Luba-Katanga
  "mya",  // Burmese
  "nld",  // Dutch (T)
  "nor",  // Norwegian
  "nya",  // Chichewa; Chewa; Nyanja
  "por",  // Portuguese
  "ron",  // Romanian (T)
  "rum",  // Romanian (B)
  "rus",  // Russian
  "spa",  // Spanish
  "swe",  // Swedish
  "tur",  // Turkish
  "vie",  // Vietnamese
  "ven",  // Venda
  "vol",  // Volapuk
  "wel",  // Welsh
  "wln",  // Walloon
  "wol",  // Wolof
  "xho",  // Xhosa
  "yid",  // Yiddish
  "yor",  // Yoruba
  "zha",  // Zhuang; Chuang
  "zho",  // Chinese
  "zul",  // Zulu
};

type find( char const *lang ) {
  DEF_END( string_of );
  return FIND( lang );
}

char const* str( type t ) {
  DEF_LENGTH( string_of );
  int const i = static_cast<int>( t );
  return i >= 0 && i < static_cast<int>(length) ? string_of[ i ] : "UNKNOWN";
}

} // namespace iso639_2

///////////////////////////////////////////////////////////////////////////////

iso639_1::type find_lang( char const *lang ) {
  using namespace iso639_1;

  if ( type const code_639_1 = iso639_1::find( lang ) )
    return code_639_1;

  static type const iso639_2_to_639_1[] = {
    unknown,
    aa, // aar
    ab, // abk
    af, // afr
    ak, // aka
    sq, // alb
    am, // amh
    ar, // ara
    an, // arg
    hy, // arm
    as, // asm
    av, // ava
    ae, // ave
    ay, // aym
    az, // aze
    ba, // bak
    bm, // bam
    eu, // baq
    be, // bel
    bn, // ben
    bh, // bih
    bi, // bis
    bs, // bos
    br, // bre
    br, // bul
    my, // bur
    ca, // cat
    ch, // cha
    ce, // che
    zh, // chi
    cu, // chu
    cy, // cym
    da, // dan
    de, // deu
    dv, // div
    nl, // dut
    dz, // dzo
    el, // ell
    en, // eng
    eo, // epo
    et, // est
    ee, // ewe
    fo, // fao
    fj, // fij
    fi, // fin
    fr, // fra
    fr, // fre
    fy, // fry
    ff, // ful
    ka, // geo
    de, // ger
    gd, // gla
    ga, // gle
    gl, // glg
    gv, // glv
    el, // gre
    gn, // grn
    gu, // guj
    ht, // hat
    ha, // hau
    he, // heb
    hz, // her
    hi, // hin
    ho, // hmo
    hr, // hrv
    hu, // hun
    ig, // ibo
    is, // ice
    io, // ido
    iu, // iku
    ie, // ile
    ia, // ina
    id, // ind
    ik, // ipk
    is, // isl
    it, // ita
    jv, // jav
    ja, // jpn
    kl, // kal
    kn, // kan
    ks, // kas
    ka, // kat
    kr, // kau
    kk, // kaz
    km, // khm
    ki, // kik
    rw, // kin
    ky, // kir
    kv, // kom
    kg, // kon
    ko, // kor
    kj, // kua
    ku, // kur
    lo, // lao
    la, // lat
    lv, // lav
    li, // lim
    ln, // lin
    lt, // lit
    lb, // ltz
    lu, // lub
    my, // mya
    nl, // nld
    no, // nor
    ny, // nya
    pt, // por
    ro, // ron
    ro, // rum
    ru, // rus
    es, // spa
    sv, // swe
    tr, // tur
    ve, // ven
    vi, // vie
    vo, // vol
    cy, // wel
    wa, // wln
    wo, // wol
    xh, // xho
    yi, // yid
    yo, // yor
    za, // zha
    zh, // zho
    zu, // zul
  };
  return iso639_2_to_639_1[ iso639_2::find( lang ) ];
}

zstring get_date_format( iso639_1::type lang, iso3166_1::type country ) {
#ifdef WIN32
  zstring const w32_format(
    get_locale_info( LOCALE_SSHORTDATE, lang, country )
  );
  zstring format;
  //
  // Convert Windows' date format for that used by strptime(3); see:
  // http://msdn.microsoft.com/en-us/library/windows/desktop/dd317787(v=vs.85).aspx
  //
  for ( char const *i = w32_format.c_str(); *i; ++i ) {
    switch ( *i ) {

      case 'd':
        if ( i[1] == 'd' )
          if ( i[2] == 'd' )
            if ( i[3] == 'd' )
              format += "%A", i += 3;   // dddd = full weekday name
            else
              format += "%a", i += 2;   // ddd = abbreviated weekday name
          else
            format += "%d", i += 1;     // dd = day of month: 01-31
        else
          format += "%e";               // d = day of month: 1-31
        break;

      case 'g':                         // period/era
        //
        // There's no equivalent strftime(3) conversion specification: just
        // ignore it and hope for the best.
        //
        if ( i[1] == 'g' )
          ++i;                          // gg = same as g
        break;

      case 'M':
        if ( i[1] == 'M' )
          if ( i[2] == 'M' )
            if ( i[3] == 'M' )
              format += "%B", i += 3;   // MMMM = full month name
            else
              format += "%b", i += 2;   // MMM = abbreviated month name
          else
            format += "%m", i += 1;     // MM = month: 01-12
        else
          format += "%m";               // M = month: 1-12
        break;

      case 'y':
        if ( i[1] == 'y' )
          if ( i[2] == 'y' )
            if ( i[3] == 'y' ) {
              format += "%Y", i += 3;   // yyyy = 4-digit year
              if ( i[3] == 'y' )
                ++i;                    // yyyyy = same as yyyy
            } else
              ;
          else
            format += "%y", i += 1;     // yy = 2-digit year
        else
          format += "%y";               // y = 1-digit year
        break;

      default:
        format += *i;
    } // switch
  } // for
  return format;
#else
  zstring fmt( get_locale_info( D_FMT, lang, country ) );
  if ( fmt.empty() && lang == iso639_1::en )
    fmt = "%d-%b-%Y";                   // dd-Mon-yyyy
  return fmt;
#endif /* WIN32 */
}

zstring get_date_time_format( iso639_1::type lang, iso3166_1::type country ) {
#ifdef WIN32
  //
  // Windows has no equivalent for both date and time, so glue its date and
  // time together and hope for the best.
  //
  return get_date_format( lang, country ) + ' ' +
         get_time_format( lang, country );
#else
  zstring fmt( get_locale_info( D_T_FMT, lang, country ) );
  if ( fmt.empty() && lang == iso639_1::en )
    fmt = "%a %b %e %X %Y";
  return fmt;
#endif /* WIN32 */
}

iso3166_1::type get_host_country() {
  iso3166_1::type country = iso3166_1::unknown;

#ifdef WIN32
  zstring const name( get_locale_info( LOCALE_SISO3166CTRYNAME ) );
  country = iso3166_1::find( name );
#else
  zstring const loc_info( get_unix_locale() );
  parse( loc_info, nullptr, &country );
#endif /* WIN32 */

  return country;
}

iso639_1::type get_host_lang() {
  //
  // ICU's Locale::getDefault().getLanguage() should be used here, but it
  // sometimes returns "root" which isn't useful.
  //
  iso639_1::type lang = iso639_1::unknown;

#ifdef WIN32
  zstring const name( get_locale_info( LOCALE_SISO639LANGNAME ) );
  lang = find_lang( name );
#else
  zstring const loc_info( get_unix_locale() );
  parse( loc_info, &lang );
#endif /* WIN32 */
  if ( !lang )
    lang = iso639_1::en;              // default to English
  
  return lang;
}

zstring get_month_abbr( unsigned month_index, iso639_1::type lang,
                        iso3166_1::type country ) {
  static locale_index_type const month_abbr[] = {
#ifdef WIN32
    LOCALE_SABBREVMONTHNAME1, LOCALE_SABBREVMONTHNAME2,
    LOCALE_SABBREVMONTHNAME3, LOCALE_SABBREVMONTHNAME4,
    LOCALE_SABBREVMONTHNAME5, LOCALE_SABBREVMONTHNAME6,
    LOCALE_SABBREVMONTHNAME7, LOCALE_SABBREVMONTHNAME8,
    LOCALE_SABBREVMONTHNAME9, LOCALE_SABBREVMONTHNAME10,
    LOCALE_SABBREVMONTHNAME11, LOCALE_SABBREVMONTHNAME12
#else
    ABMON_1, ABMON_2, ABMON_3, ABMON_4, ABMON_5, ABMON_6,
    ABMON_7, ABMON_8, ABMON_9, ABMON_10, ABMON_11, ABMON_12
#endif /* WIN32 */
  };

  if ( month_index > 11 )
    throw invalid_argument( BUILD_STRING( month_index, " not in range 0-11" ) );
  zstring abbr( get_locale_info( month_abbr[ month_index ], lang, country ) );
  if ( abbr.empty() && lang == iso639_1::en ) {
    static char const *const abbr_str[] = {
      "Jan", "Feb", "Mar", "Apr", "May", "Jun",
      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    abbr = abbr_str[ month_index ];
  }
  return abbr;
}

zstring get_month_name( unsigned month_index, iso639_1::type lang,
                        iso3166_1::type country ) {
  static locale_index_type const month_name[] = {
#ifdef WIN32
    LOCALE_SMONTHNAME1, LOCALE_SMONTHNAME2, LOCALE_SMONTHNAME3,
    LOCALE_SMONTHNAME4, LOCALE_SMONTHNAME5, LOCALE_SMONTHNAME6,
    LOCALE_SMONTHNAME7, LOCALE_SMONTHNAME8, LOCALE_SMONTHNAME9,
    LOCALE_SMONTHNAME10, LOCALE_SMONTHNAME11, LOCALE_SMONTHNAME12
#else
    MON_1, MON_2, MON_3, MON_4, MON_5, MON_6,
    MON_7, MON_8, MON_9, MON_10, MON_11, MON_12
#endif /* WIN32 */
  };

  if ( month_index > 11 )
    throw invalid_argument( BUILD_STRING( month_index, " not in range 0-11" ) );
  zstring name( get_locale_info( month_name[ month_index ], lang, country ) );
  if ( name.empty() && lang == iso639_1::en ) {
    static char const *const name_str[] = {
      "January", "February", "March", "April", "May", "June",
      "July", "August", "September", "October", "November", "December"
    };
    name = name_str[ month_index ];
  }
  return name;
}

zstring get_time_ampm( bool pm, iso639_1::type lang, iso3166_1::type country ) {
  static locale_index_type const ampm[] = {
#ifdef WIN32
    LOCALE_S1159, LOCALE_S2359
#else
    AM_STR, PM_STR
#endif /* WIN32 */
  };
  zstring s( get_locale_info( ampm[ pm ], lang, country ) );
  if ( s.empty() && lang == iso639_1::en )
    s = pm ? "PM" : "AM";
  return s;
}

zstring get_time_format( iso639_1::type lang, iso3166_1::type country ) {
#ifdef WIN32
  zstring const w32_format(
    get_locale_info( LOCALE_STIMEFORMAT, lang, country )
  );
  zstring format;
  //
  // Convert Windows' time format for that used by strptime(3); see:
  // http://msdn.microsoft.com/en-us/library/windows/desktop/dd318148(v=vs.85).aspx
  //
  for ( char const *i = w32_format.c_str(); *i; ++i ) {
    switch ( *i ) {

      case 'h':
        if ( i[1] == 'h' )
          format += "%I", ++i;
        else
          format += "%l";
        break;

      case 'H':
        if ( i[1] == 'H' )
          format += "%H", ++i;
        else
          format += "%k";
        break;

      case 'm':
        format += "%M";
        if ( i[1] == 'm' )
          ++i;
        break;

      case 's':
        format += "%S";
        if ( i[1] == 's' )
          ++i;
        break;

      case 't':
        format += "%p";
        if ( i[1] == 't' )
          ++i;
        break;

      default:
        format += *i;
    } // switch
  } // for
  return format;
#else
  zstring fmt( get_locale_info( T_FMT, lang, country ) );
  if ( fmt.empty() && lang == iso639_1::en )
    fmt = "%H:%M:%S";
  return fmt;
#endif /* WIN32 */
}

zstring get_weekday_abbr( unsigned day_index, iso639_1::type lang,
                          iso3166_1::type country ) {
  static locale_index_type const weekday_abbr[] = {
#ifdef WIN32
    LOCALE_SABBREVDAYNAME7 /* Sun */,
    LOCALE_SABBREVDAYNAME1 /* Mon */,
    LOCALE_SABBREVDAYNAME2 /* Tue */,
    LOCALE_SABBREVDAYNAME3 /* Wed */,
    LOCALE_SABBREVDAYNAME4 /* Thu */,
    LOCALE_SABBREVDAYNAME5 /* Fri */,
    LOCALE_SABBREVDAYNAME6 /* Sat */
#else
    ABDAY_1, ABDAY_2, ABDAY_3, ABDAY_4, ABDAY_5, ABDAY_6, ABDAY_7
#endif /* WIN32 */
  };

  if ( day_index > 6 )
    throw invalid_argument( BUILD_STRING( day_index, " not in range 0-6" ) );
  zstring abbr( get_locale_info( weekday_abbr[ day_index ], lang, country ) );
  if ( abbr.empty() && lang == iso639_1::en ) {
    static char const *const abbr_str[] = {
      "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    abbr = abbr_str[ day_index ];
  }
  return abbr;
}

zstring get_weekday_name( unsigned day_index, iso639_1::type lang,
                          iso3166_1::type country ) {
  static locale_index_type const weekday_name[] = {
#ifdef WIN32
    LOCALE_SDAYNAME7 /* Sun */,
    LOCALE_SDAYNAME1 /* Mon */,
    LOCALE_SDAYNAME2 /* Tue */,
    LOCALE_SDAYNAME3 /* Wed */,
    LOCALE_SDAYNAME4 /* Thu */,
    LOCALE_SDAYNAME5 /* Fri */,
    LOCALE_SDAYNAME6 /* Sat */
#else
    DAY_1, DAY_2, DAY_3, DAY_4, DAY_5, DAY_6, DAY_7
#endif /* WIN32 */
  };

  if ( day_index > 6 )
    throw invalid_argument( BUILD_STRING( day_index, " not in range 0-6" ) );
  zstring name( get_locale_info( weekday_name[ day_index ], lang, country ) );
  if ( name.empty() && lang == iso639_1::en ) {
    static char const *const name_str[] = {
      "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
      "Saturday"
    };
    name = name_str[ day_index ];
  }
  return name;
}

bool is_supported( iso639_1::type lang, iso3166_1::type country ) {
  if ( !country )
    country = iso3166_1::get_default( lang );
#ifdef WIN32
  unique_ptr<WCHAR[]> const wlocale_name( get_wlocale_name( lang, country ) );
  return Zorba_IsValidLocaleName( wlocale_name.get() );
#else
  if ( lang == iso639_1::en )
    return true;                        // Always support English
  if ( locale_t const loc = get_unix_locale_t( lang, country ) ) {
    ::freelocale( loc );
    return true;
  }
  return false;
#endif /* WIN32 */
}

bool parse( char const *locale_str, iso639_1::type *lang,
            iso3166_1::type *country ) {
  zstring lang_str, country_str;
  char const *p = locale_str;

  if ( !(ascii::is_alpha( *p++ ) && ascii::is_alpha( *p++ )) )
    return false;
  lang_str.assign( locale_str, 2 );
  if ( *p ) {
    if ( ascii::is_alpha( *p ) )        // ISO 639-2 3-letter code
      lang_str += *p++;
    if ( *p ) {
      if ( !(*p == '-' || *p == '_') )
        return false;
      ++p;
      if ( !(ascii::is_alpha( p[0] ) && ascii::is_alpha( p[1] )) )
        return false;
      country_str.assign( p, 2 );
      if ( *(p += 2) && *p != '.' )
        return false;
    }
  }

  if ( lang ) {
    ascii::to_lower( lang_str );
    *lang = find_lang( lang_str );
  }
  if ( country ) {
    ascii::to_upper( country_str );
    *country = country_str.empty() ?
      iso3166_1::unknown : iso3166_1::find( country_str );
  }

  return true;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace locale
} // namespace zorba
/* vim:set et sw=2 ts=2: */
