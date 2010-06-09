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
 
#ifndef ZORBA_LANG_H
#define ZORBA_LANG_H

namespace zorba {
  namespace lang {

    namespace iso639_1 {
      enum type {
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

        unknown
      };

      /**
       * Finds the ISO 639-1 language code enumeration from the given string.
       *
       * @param lang The string literal for an ISO 639-1 langauge code.
       * @return Returns said enumeration or <code>unknown</code>.
       */
      type find( char const *lang );
    }

    namespace iso639_2 {
      enum type {
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

        unknown
      };

      /**
       * Finds the ISO 639-2 language code enumeration from the given string.
       *
       * @param lang The string literal for an ISO 639-2 langauge code.
       * @return Returns said enumeration or <code>unknown</code>.
       */
      type find( char const *lang );
    }

    /**
     * Finds the ISO 639-1 language code enumeration from the given string.
     *
     * @param lang The string literal for either an ISO 639-1 or an ISO 639-2
     * langauge code.
     * @return Returns said enumeration or <code>unknown</code>.
     */
    iso639_1::type find( char const *lang );

  } // namespace lang
}
#endif  /* ZORBA_LANG_H */
/* vim:set et sw=2 ts=2: */
