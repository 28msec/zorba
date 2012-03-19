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
#ifndef ZORBA_CORE_LOCALE_H
#define ZORBA_CORE_LOCALE_H

#include <iostream>

#include <zorba/locale.h>

namespace zorba {
  namespace locale {

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso3166_1 {
      enum type {
        unknown,
        AD,   ///< Andorra
        AE,   ///< United Arab Emirates
        AF,   ///< Afghanistan
        AG,   ///< Antigua and Barbuda
        AI,   ///< Anguilla
        AL,   ///< Albania
        AM,   ///< Armenia
        AN,   ///< Netherlands Antilles
        AO,   ///< Angola
        AQ,   ///< AntarcticA
        AR,   ///< ArgentinA
        AS,   ///< American Samoa
        AT,   ///< Austria
        AU,   ///< Australia
        AW,   ///< Aruba
        AX,   ///< Aland Islands
        AZ,   ///< Azerbaijan
        BA,   ///< Bosnia and Herzegovina
        BB,   ///< Barbados
        BD,   ///< Bangladesh
        BE,   ///< Belgium
        BF,   ///< Burkina Faso
        BG,   ///< Bulgaria
        BH,   ///< Bahrain
        BI,   ///< Burundi
        BJ,   ///< Benin
        BL,   ///< Saint Barthelemy
        BM,   ///< Bermuda
        BN,   ///< Brunei Darussalam
        BO,   ///< Bolivia
        BR,   ///< Brazil
        BS,   ///< Bahamas
        BT,   ///< Bhutan
        BV,   ///< Bouvet Island
        BW,   ///< Botswana
        BY,   ///< Belarus
        BZ,   ///< Belize
        CA,   ///< Canada
        CC,   ///< Cocos Islands
        CD,   ///< Congo
        CF,   ///< Central African Republic
        CG,   ///< Congo
        CH,   ///< Switzerland
        CI,   ///< Cote D'Ivoire
        CK,   ///< Cook Islands
        CL,   ///< Chile
        CM,   ///< Cameroon
        CN,   ///< China
        CO,   ///< Colombia
        CR,   ///< Costa Rica
        CU,   ///< Cuba
        CV,   ///< Cape Verde
        CX,   ///< Christmas Island
        CY,   ///< Cyprus
        CZ,   ///< Czech Republic
        DE,   ///< Germany
        DJ,   ///< Djibouti
        DK,   ///< Denmark
        DM,   ///< Dominica
        DO,   ///< Dominican Republic
        DZ,   ///< Algeria
        EC,   ///< Ecuador
        EE,   ///< Estonia
        EG,   ///< Egypt
        EH,   ///< Western Sahara
        ER,   ///< Eritrea
        ES,   ///< Spain
        ET,   ///< Ethiopia
        FI,   ///< Finland
        FJ,   ///< Fiji
        FK,   ///< Falkland Islands
        FM,   ///< Micronesia
        FO,   ///< Faroe Islands
        FR,   ///< France
        GA,   ///< Gabon
        GB,   ///< United Kingdom
        GD,   ///< Grenada
        GE,   ///< Georgia
        GF,   ///< French Guiana
        GG,   ///< Guernsey
        GH,   ///< Ghana
        GI,   ///< Gibraltar
        GL,   ///< Greenland
        GM,   ///< Gambia
        GN,   ///< Guinea
        GP,   ///< Guadeloupe
        GQ,   ///< Equatorial Guinea
        GR,   ///< Greece
        GS,   ///< South Georgia and the South Sandwich Islands
        GT,   ///< Guatemala
        GU,   ///< Guam
        GW,   ///< Guinea-Bissau
        GY,   ///< Guyana
        HK,   ///< Hong Kong
        HM,   ///< Heard Island and Mcdonald Islands
        HN,   ///< Honduras
        HR,   ///< Croatia
        HT,   ///< Haiti
        HU,   ///< Hungary
        ID,   ///< Indonesia
        IE,   ///< Ireland
        IL,   ///< Israel
        IM,   ///< Isle of Man
        IN_,  ///< India [without '_', it clashes with an identifier on Windows]
        IO,   ///< British Indian Ocean Territory
        IQ,   ///< Iraq
        IR,   ///< Iran
        IS,   ///< Iceland
        IT,   ///< Italy
        JE,   ///< Jersey
        JM,   ///< Jamaica
        JO,   ///< Jordan
        JP,   ///< Japan
        KE,   ///< Kenya
        KG,   ///< Kyrgyzstan
        KH,   ///< Cambodia
        KI,   ///< Kiribati
        KM,   ///< Comoros
        KN,   ///< Saint Kitts and Nevis
        KP,   ///< Korea (Democratic People's Republic)
        KR,   ///< Korea
        KW,   ///< Kuwait
        KY,   ///< Cayman Islands
        KZ,   ///< Kazakhstan
        LA,   ///< Lao
        LB,   ///< Lebanon
        LC,   ///< Saint Lucia
        LI,   ///< Liechtenstein
        LK,   ///< Sri Lanka
        LR,   ///< Liberia
        LS,   ///< Lesotho
        LT,   ///< Lithuania
        LU,   ///< Luxembourg
        LV,   ///< Latvia
        LY,   ///< Libyan Arab Jamahiriya
        MA,   ///< Morocco
        MC,   ///< Monaco
        MD,   ///< Moldova
        ME,   ///< Montenegro
        MF,   ///< Saint Martin
        MG,   ///< Madagascar
        MH,   ///< Marshall Islands
        MK,   ///< Macedonia
        ML,   ///< Mali
        MM,   ///< Myanmar
        MN,   ///< Mongolia
        MO,   ///< Macao
        MP,   ///< Northern Mariana Islands
        MQ,   ///< Martinique
        MR,   ///< Mauritania
        MS,   ///< Montserrat
        MT,   ///< Malta
        MU,   ///< Mauritius
        MV,   ///< Maldives
        MW,   ///< Malawi
        MX,   ///< Mexico
        MY,   ///< Malaysia
        MZ,   ///< Mozambique
        NA,   ///< Namibia
        NC,   ///< New Caledonia
        NE,   ///< Niger
        NF,   ///< Norfolk Island
        NG,   ///< Nigeria
        NI,   ///< Nicaragua
        NL,   ///< Netherlands
        NO,   ///< Norway
        NP,   ///< Nepal
        NR,   ///< Nauru
        NU,   ///< Niue
        NZ,   ///< New Zealand
        OM,   ///< Oman
        PA,   ///< Panama
        PE,   ///< Peru
        PF,   ///< French Polynesia
        PG,   ///< Papua New Guinea
        PH,   ///< Philippines
        PK,   ///< Pakistan
        PL,   ///< Poland
        PM,   ///< Saint Pierre and Miquelon
        PN,   ///< Pitcairn
        PR,   ///< Puerto Rico
        PS,   ///< Palestinian Territory
        PT,   ///< Portugal
        PW,   ///< Palau
        PY,   ///< Paraguay
        QA,   ///< Qatar
        RE,   ///< Reunion
        RO,   ///< Romania
        RS,   ///< Serbia
        RU,   ///< Russian Federation
        RW,   ///< Rwanda
        SA,   ///< Saudi Arabia
        SB,   ///< Solomon Islands
        SC,   ///< Seychelles
        SD,   ///< Sudan
        SE,   ///< Sweden
        SG,   ///< Singapore
        SH,   ///< Saint Helena
        SI,   ///< Slovenia
        SJ,   ///< Svalbard and Jan Mayen
        SK,   ///< Slovakia
        SL,   ///< Sierra Leone
        SM,   ///< San Marino
        SN,   ///< Senegal
        SO,   ///< Somalia
        SR,   ///< Suriname
        ST,   ///< Sao Tome and Principe
        SV,   ///< El Salvador
        SY,   ///< Syria
        SZ,   ///< Swaziland
        TC,   ///< Turks and Caicos Islands
        TD,   ///< Chad
        TF,   ///< French Southern Territories
        TG,   ///< Togo
        TH,   ///< Thailand
        TJ,   ///< Tajikistan
        TK,   ///< Tokelau
        TL,   ///< Timor-Leste
        TM,   ///< Turkmenistan
        TN,   ///< Tunisia
        TO,   ///< Tonga
        TR,   ///< Turkey
        TT,   ///< Trinidad and Tobago
        TV,   ///< Tuvalu
        TW,   ///< Taiwan
        TZ,   ///< Tanzania
        UA,   ///< Ukraine
        UG,   ///< Uganda
        UM,   ///< United states Minor Outlying Islands
        US,   ///< United States
        UY,   ///< Uruguay
        UZ,   ///< Uzbekistan
        VA,   ///< Vatican
        VC,   ///< Saint Vincent and the Grenadines
        VE,   ///< Venezuela
        VG,   ///< Virgin Islands (British)
        VI,   ///< Virgin Islands (USA)
        VN,   ///< Viet Nam
        VU,   ///< Vanuatu
        WF,   ///< Wallis and Futuna
        WS,   ///< Samoa
        YE,   ///< Yemen
        YT,   ///< Mayotte
        ZA,   ///< South Africa
        ZM,   ///< Zambia
        ZW,   ///< Zimbabwe
        NUM_ENTRIES
      };
      extern char const *const string_of[];

      /**
       * Emits an iso3166_1::type to an ostream.
       *
       * @param o The ostream to emit to.
       * @param t The type to emit.
       * @return Returns \a o.
       */
      inline std::ostream& operator<<( std::ostream &o, type t ) {
        return o << string_of[ t ];
      }

      /**
       * Finds the ISO 3166-1 country code enumeration from the given string.
       *
       * @param country An ISO 3166-1 country code.
       * @return Returns said enumeration or <code>unknown</code>.
       */
      type find( char const *country );
    }

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso639_1 {
      extern char const *const string_of[];

      /**
       * Emits an iso639_1::type to an ostream.
       *
       * @param o The ostream to emit to.
       * @param t The type to emit.
       * @return Returns \a o.
       */
      inline std::ostream& operator<<( std::ostream &o, type t ) {
        return o << string_of[ t ];
      }

      /**
       * Finds the ISO 639-1 language code enumeration from the given string.
       *
       * @param lang An ISO 639-1 langauge code.
       * @return Returns said enumeration or <code>unknown</code>.
       */
      type find( char const *lang );
    }

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso639_2 {
      enum type {
        unknown,
        aar,  ///< Afar
        abk,  ///< Abkhazian
        afr,  ///< Afrikaans
        aka,  ///< Akan
        alb,  ///< Albanian
        amh,  ///< Amharic
        ara,  ///< Arabic
        arg,  ///< Aragonese
        arm,  ///< Armenian
        asm_, ///< Assamese [without '_', it's a C++ keyword]
        ava,  ///< Avaric
        ave,  ///< Avestan
        aym,  ///< Aymara
        aze,  ///< Azerbaijani
        bak,  ///< Bashkir
        bam,  ///< Bambara
        baq,  ///< Basque
        bel,  ///< Belarusian
        ben,  ///< Bengali
        bih,  ///< Bihari
        bis,  ///< Bislama
        bos,  ///< Bosnian
        bre,  ///< Breton
        bul,  ///< Bulgarian
        bur,  ///< Burmese
        cat,  ///< Catalan
        cha,  ///< Chamorro
        che,  ///< Chechen
        chi,  ///< Chinese
        chu,  ///< Church Slavic; Old Slavonic; Church Slavonic
        dan,  ///< Danish
        deu,  ///< German (T)
        dut,  ///< Dutch (B)
        eng,  ///< English
        fin,  ///< Finnish
        fra,  ///< French (T)
        fre,  ///< French (B)
        ger,  ///< German (B)
        hun,  ///< Hungarian
        ita,  ///< Italian
        khm,  ///< Central Khmer
        mya,  ///< Burmese
        nld,  ///< Dutch (T)
        nor,  ///< Norwegian
        nya,  ///< Chichewa; Chewa; Nyanja
        por,  ///< Portuguese
        ron,  ///< Romanian (T)
        rum,  ///< Romanian (B)
        rus,  ///< Russian
        spa,  ///< Spanish
        swe,  ///< Swedish
        tur,  ///< Turkish
        zha,  ///< Zhuang; Chuang
        zho,  ///< Chinese
        NUM_ENTRIES
      };
      extern char const *const string_of[];

      /**
       * Emits an iso639_2::type to an ostream.
       *
       * @param o The ostream to emit to.
       * @param t The type to emit.
       * @return Returns \a o.
       */
      inline std::ostream& operator<<( std::ostream &o, type t ) {
        return o << string_of[ t ];
      }

      /**
       * Finds the ISO 639-2 language code enumeration from the given string.
       *
       * @param lang An ISO 639-2 langauge code.
       * @return Returns said enumeration or <code>unknown</code>.
       */
      type find( char const *lang );
    }

    /////////////////////////////////////////////////////////////////////////// 

    /**
     * Finds the ISO 639-1 language code enumeration from the given string.
     *
     * @param lang Either an ISO 639-1 or an ISO 639-2 langauge code.
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

    ///////////////////////////////////////////////////////////////////////////

  } // namespace locale
} // namespace zorba

#undef DEF_OSTREAM_INSERT_OPERATOR

#endif  /* ZORBA_CORE_LOCALE_H */
/* vim:set et sw=2 ts=2: */
