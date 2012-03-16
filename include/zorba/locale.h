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
        jw,   ///< Javanese
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

    /////////////////////////////////////////////////////////////////////////// 

  } // namespace locale
} // namespace zorba

#endif  /* ZORBA_LOCALE_API_H */
/* vim:set et sw=2 ts=2: */
