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

    namespace iso639_1 {
      enum type {
        unknown,
        aa,   // Afar
        ab,   // Abkhazian
        ae,   // Avestan
        af,   // Afrikaans
        ak,   // Akan
        am,   // Amharic
        an,   // Aragonese
        ar,   // Arabic
        as,   // Assamese
        av,   // Avaric
        ay,   // Aymara
        az,   // Azerbaijani
        ba,   // Bashkir
        be,   // Byelorussian
        bg,   // Bulgarian
        bh,   // Bihari
        bi,   // Bislama
        bn,   // Bengali; Bangla
        bo,   // Tibetan
        br,   // Breton
        ca,   // Catalan
        co,   // Corsican
        cs,   // Czech
        cy,   // Welsh
        da,   // Danish
        de,   // German
        dz,   // Bhutani
        el,   // Greek
        en,   // English
        eo,   // Esperanto
        es,   // Spanish
        et,   // Estonian
        eu,   // Basque
        fa,   // Persian
        fi,   // Finnish
        fj,   // Fiji
        fo,   // Faroese
        fr,   // French
        fy,   // Frisian
        ga,   // Irish
        gd,   // Scots Gaelic
        gl,   // Galician
        gn,   // Guarani
        gu,   // Gujarati
        ha,   // Hausa
        he,   // Hebrew (formerly iw)
        hi,   // Hindi
        hr,   // Croatian
        hu,   // Hungarian
        hy,   // Armenian
        ia,   // Interlingua
        id,   // Indonesian (formerly in)
        ie,   // Interlingue
        ik,   // Inupiak
        is,   // Icelandic
        it,   // Italian
        iu,   // Inuktitut
        ja,   // Japanese
        jw,   // Javanese
        ka,   // Georgian
        kk,   // Kazakh
        kl,   // Greenlandic
        km,   // Cambodian
        kn,   // Kannada
        ko,   // Korean
        ks,   // Kashmiri
        ku,   // Kurdish
        ky,   // Kirghiz
        la,   // Latin
        ln,   // Lingala
        lo,   // Laothian
        lt,   // Lithuanian
        lv,   // Latvian, Lettish
        mg,   // Malagasy
        mi,   // Maori
        mk,   // Macedonian
        ml,   // Malayalam
        mn,   // Mongolian
        mo,   // Moldavian
        mr,   // Marathi
        ms,   // Malay
        mt,   // Maltese
        my,   // Burmese
        na,   // Nauru
        ne,   // Nepali
        nl,   // Dutch
        no,   // Norwegian
        oc,   // Occitan
        om,   // (Afan) Oromo
        or_,  // Oriya
        pa,   // Punjabi
        pl,   // Polish
        ps,   // Pashto, Pushto
        pt,   // Portuguese
        qu,   // Quechua
        rm,   // Rhaeto-Romance
        rn,   // Kirundi
        ro,   // Romanian
        ru,   // Russian
        rw,   // Kinyarwanda
        sa,   // Sanskrit
        sd,   // Sindhi
        sg,   // Sangho
        sh,   // Serbo-Croatian
        si,   // Sinhalese
        sk,   // Slovak
        sl,   // Slovenian
        sm,   // Samoan
        sn,   // Shona
        so,   // Somali
        sq,   // Albanian
        sr,   // Serbian
        ss,   // Siswati
        st,   // Sesotho
        su,   // Sundanese
        sv,   // Swedish
        sw,   // Swahili
        ta,   // Tamil
        te,   // Telugu
        tg,   // Tajik
        th,   // Thai
        ti,   // Tigrinya
        tk,   // Turkmen
        tl,   // Tagalog
        tn,   // Setswana
        to,   // Tonga
        tr,   // Turkish
        ts,   // Tsonga
        tt,   // Tatar
        tw,   // Twi
        ug,   // Uighur
        uk,   // Ukrainian
        ur,   // Urdu
        uz,   // Uzbek
        vi,   // Vietnamese
        vo,   // Volapuk
        wo,   // Wolof
        xh,   // Xhosa
        yi,   // Yiddish (formerly ji)
        yo,   // Yoruba
        za,   // Zhuang
        zh,   // Chinese
        zu,   // Zulu
        NUM_ENTRIES
      };
    }

    /////////////////////////////////////////////////////////////////////////// 

  } // namespace locale
} // namespace zorba

#endif  /* ZORBA_LOCALE_API_H */
/* vim:set et sw=2 ts=2: */
