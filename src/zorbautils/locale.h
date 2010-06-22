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
 
#ifndef ZORBA_LOCALE_H
#define ZORBA_LOCALE_H

namespace zorba {
  namespace locale {

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso3166_1 {
      enum type {
        unknown,
        AR,   // Argnetina
        AS,   // American Samoa
        AU,   // Australia
        BE,   // Belgium
        BG,   // Bulgaria
        BM,   // Bermuda
        BR,   // Brazil
        BS,   // Bahamas
        CA,   // Canada
        CH,   // Switzerland
        CL,   // Chile
        CO,   // Columbia
        CR,   // Costa Rica
        CV,   // Cape Verde
        CZ,   // Czech Republic
        DE,   // Germany
        DK,   // Denmark
        ES,   // Spain
        FI,   // Finland
        FR,   // France
        GB,   // United Kingdom
        GF,   // French Guiana
        GT,   // Guatemala
        HN,   // Honduras
        HU,   // Hungary
        IE,   // Ireland
        IT,   // Italy
        JM,   // Jamaica
        KY,   // Cayman Islands
        MX,   // Mexico
        NI,   // Nicaragua
        NL,   // Netherlands
        NO,   // Norway
        NZ,   // New Sealand
        PA,   // Panama
        PE,   // Peru
        PF,   // French Polynesia
        PR,   // Puerto Rico
        PT,   // Portugal
        PY,   // Paraguay
        RO,   // Romania
        RU,   // Russian Federation
        SE,   // Sweden
        SV,   // El Salvador
        TF,   // French Southern Territories
        TR,   // Turkey
        UM,   // United States Minor Outlying Islands
        US,   // United States
        UY,   // Uruguay
        VE,   // Venezuela
        VG,   // Virgin Islands (British)
        VI,   // Virgin Islands (USA)
        ZA,   // South Africa
        NUM_ENTRIES
      };
      extern char const *const string_of[];

      /**
       * Finds the ISO 3166-1 country code enumeration from the given string.
       *
       * @param country The string literal for an ISO 3166-1 country code.
       * @return Returns said enumeration or <code>unknown</code>.
       */
      type find( char const *country );
    }

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso639_1 {
      enum type {
        unknown,
        da,   // Danish
        de,   // German
        en,   // English
        es,   // Spanish
        fi,   // Finnish
        fr,   // French
        hu,   // Hungarian
        it,   // Italian
        nl,   // Dutch
        no,   // Norwegian
        pt,   // Portuguese
        ro,   // Romanian
        ru,   // Russian
        sv,   // Swedish
        tr,   // Turkish
        NUM_ENTRIES
      };
      extern char const *const string_of[];

      /**
       * Finds the ISO 639-1 language code enumeration from the given string.
       *
       * @param lang The string literal for an ISO 639-1 langauge code.
       * @return Returns said enumeration or <code>unknown</code>.
       */
      type find( char const *lang );
    }

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso639_2 {
      enum type {
        unknown,
        dan,  // Danish
        deu,  // German (T)
        dut,  // Dutch (B)
        eng,  // English
        fin,  // Finnish
        fra,  // French (T)
        fre,  // French (B)
        ger,  // German (B)
        hun,  // Hungarian
        ita,  // Italian
        nld,  // Dutch (T)
        nor,  // Norwegian
        por,  // Portuguese
        ron,  // Romanian (T)
        rum,  // Romanian (B)
        rus,  // Russian
        spa,  // Spanish
        swe,  // Swedish
        tur,  // Turkish
        NUM_ENTRIES
      };
      extern char const *const string_of[];

      /**
       * Finds the ISO 639-2 language code enumeration from the given string.
       *
       * @param lang The string literal for an ISO 639-2 langauge code.
       * @return Returns said enumeration or <code>unknown</code>.
       */
      type find( char const *lang );
    }

    /////////////////////////////////////////////////////////////////////////// 

    /**
     * Finds the ISO 639-1 language code enumeration from the given string.
     *
     * @param lang The string literal for either an ISO 639-1 or an ISO 639-2
     * langauge code.
     * @return Returns said enumeration or <code>unknown</code>.
     */
    iso639_1::type find_lang( char const *lang );

    /**
     * Gets the ISO 3166-1 country code enumeration for the host system.
     *
     * @return Returns said enumeration or <code>unknown</code>.
     */
    iso3166_1::type get_host_country();

    /**
     * Gets the ISO 639-1 language code enumeration for the host system.
     *
     * @return Returns said enumeration defaulting to <code>en</code>.
     */
    iso639_1::type get_host_lang();

  } // namespace locale
} // namespace zorba
#endif  /* ZORBA_LOCALE_H */
/* vim:set et sw=2 ts=2: */
