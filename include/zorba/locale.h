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
 
#ifndef ZORBA_LOCALE_API_H
#define ZORBA_LOCALE_API_H

namespace zorba {
  namespace locale {

    /////////////////////////////////////////////////////////////////////////// 

    /**
     * Defines constants for all ISO 639-1 language codes.
     */
    namespace iso639_1 {
      enum type {
        unknown,
        aa,   ///< Afar
        ab,   ///< Abkhazian
        ae,   ///< Avestan
        af,   ///< Afrikaans
        ak,   ///< Akan
        am,   ///< Amharic
        an,   ///< Aragonese
        ar,   ///< Arabic
        as,   ///< Assamese
        av,   ///< Avaric
        ay,   ///< Aymara
        az,   ///< Azerbaijani
        ba,   ///< Bashkir
        be,   ///< Byelorussian
        bg,   ///< Bulgarian
        bh,   ///< Bihari
        bi,   ///< Bislama
        bm,   ///< Bambara
        bn,   ///< Bengali; Bangla
        bo,   ///< Tibetan
        br,   ///< Breton
        bs,   ///< Bosnian
        ca,   ///< Catalan
        ce,   ///< Chechen
        ch,   ///< Chamorro
        co,   ///< Corsican
        cr,   ///< Cree
        cs,   ///< Czech
        cu,   ///< Church Slavic; Church Slavonic
        cv,   ///< Chuvash
        cy,   ///< Welsh
        da,   ///< Danish
        de,   ///< German
        dv,   ///< Divehi
        dz,   ///< Bhutani
        ee,   ///< Ewe
        el,   ///< Greek
        en,   ///< English
        eo,   ///< Esperanto
        es,   ///< Spanish
        et,   ///< Estonian
        eu,   ///< Basque
        fa,   ///< Persian
        ff,   ///< Fulah
        fi,   ///< Finnish
        fj,   ///< Fiji
        fo,   ///< Faroese
        fr,   ///< French
        fy,   ///< Frisian
        ga,   ///< Irish
        gd,   ///< Scots Gaelic
        gl,   ///< Galician
        gn,   ///< Guarani
        gu,   ///< Gujarati
        gv,   ///< Manx
        ha,   ///< Hausa
        he,   ///< Hebrew (formerly iw)
        hi,   ///< Hindi
        ho,   ///< Hiri Motu
        hr,   ///< Croatian
        ht,   ///< Haitian Creole
        hu,   ///< Hungarian
        hy,   ///< Armenian
        hz,   ///< Herero
        ia,   ///< Interlingua
        id,   ///< Indonesian (formerly in)
        ie,   ///< Interlingue
        ig,   ///< Igbo
        ii,   ///< Nuosu
        ik,   ///< Inupiak
        io,   ///< Ido
        is,   ///< Icelandic
        it,   ///< Italian
        iu,   ///< Inuktitut
        ja,   ///< Japanese
        jv,   ///< Javanese
        ka,   ///< Georgian
        kg,   ///< Kongo
        ki,   ///< Gikuyu
        kj,   ///< Kuanyama
        kk,   ///< Kazakh
        kl,   ///< Greenlandic
        km,   ///< Cambodian
        kn,   ///< Kannada
        ko,   ///< Korean
        kr,   ///< Kanuri
        ks,   ///< Kashmiri
        ku,   ///< Kurdish
        kv,   ///< Komi
        kw,   ///< Cornish
        ky,   ///< Kirghiz
        la,   ///< Latin
        lb,   ///< Letzeburgesch
        lg,   ///< Ganda
        li,   ///< Limburgan; Limburger; Limburgish
        ln,   ///< Lingala
        lo,   ///< Laothian
        lt,   ///< Lithuanian
        lu,   ///< Luba-Katanga
        lv,   ///< Latvian
        mg,   ///< Malagasy
        mh,   ///< Marshallese
        mi,   ///< Maori
        mk,   ///< Macedonian
        ml,   ///< Malayalam
        mn,   ///< Mongolian
        mo,   ///< Moldavian
        mr,   ///< Marathi
        ms,   ///< Malay
        mt,   ///< Maltese
        my,   ///< Burmese
        na,   ///< Nauru
        nb,   ///< Norwegian Bokmal
        nd,   ///< Ndebele, North
        ne,   ///< Nepali
        ng,   ///< Ndonga
        nl,   ///< Dutch
        nn,   ///< Norwegian Nynorsk
        no,   ///< Norwegian
        nr,   ///< Ndebele, South
        nv,   ///< Navajo; Navaho
        ny,   ///< Chichewa; Chewa; Nyanja
        oc,   ///< Occitan
        oj,   ///< Ojibwa
        om,   ///< Oromo
        or_,  ///< Oriya
        os,   ///< Ossetian; Ossetic
        pa,   ///< Panjabi; Punjabi
        pi,   ///< Pali
        pl,   ///< Polish
        ps,   ///< Pashto, Pushto
        pt,   ///< Portuguese
        qu,   ///< Quechua
        rm,   ///< Romansh
        rn,   ///< Kirundi
        ro,   ///< Romanian
        ru,   ///< Russian
        rw,   ///< Kinyarwanda
        sa,   ///< Sanskrit
        sc,   ///< Sardinian
        sd,   ///< Sindhi
        se,   ///< Northern Sami
        sg,   ///< Sangho
        sh,   ///< Serbo-Croatian
        si,   ///< Sinhalese
        sk,   ///< Slovak
        sl,   ///< Slovenian
        sm,   ///< Samoan
        sn,   ///< Shona
        so,   ///< Somali
        sq,   ///< Albanian
        sr,   ///< Serbian
        ss,   ///< Siswati
        st,   ///< Sesotho
        su,   ///< Sundanese
        sv,   ///< Swedish
        sw,   ///< Swahili
        ta,   ///< Tamil
        te,   ///< Telugu
        tg,   ///< Tajik
        th,   ///< Thai
        ti,   ///< Tigrinya
        tk,   ///< Turkmen
        tl,   ///< Tagalog
        tn,   ///< Setswana
        to,   ///< Tonga
        tr,   ///< Turkish
        ts,   ///< Tsonga
        tt,   ///< Tatar
        tw,   ///< Twi
        ty,   ///< Tahitian
        ug,   ///< Uighur
        uk,   ///< Ukrainian
        ur,   ///< Urdu
        uz,   ///< Uzbek
        ve,   ///< Venda
        vi,   ///< Vietnamese
        vo,   ///< Volapuk
        wa,   ///< Walloon
        wo,   ///< Wolof
        xh,   ///< Xhosa
        yi,   ///< Yiddish
        yo,   ///< Yoruba
        za,   ///< Zhuang
        zh,   ///< Chinese
        zu,   ///< Zulu
        NUM_ENTRIES
      };
    }

    /**
     * Defines constants for all ISO 3166-1 country codes.
     */
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
        AQ,   ///< Antarctica
        AR,   ///< Argentina
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
        UM,   ///< United States Minor Outlying Islands
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
    }

    /////////////////////////////////////////////////////////////////////////// 

  } // namespace locale
} // namespace zorba

#endif  /* ZORBA_LOCALE_API_H */
/* vim:set et sw=2 ts=2: */
