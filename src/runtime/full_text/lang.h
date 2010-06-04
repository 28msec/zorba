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
    enum iso639_1 {
      da, // Danish
      de, // German
      en, // English
      es, // Spanish
      fi, // Finnish
      fr, // French
      hu, // Hungarian
      it, // Italian
      nl, // Dutch
      no, // Norwegian
      pt, // Portuguese
      ro, // Romanian
      ru, // Russian
      sv, // Swedish
      tr, // Turkish

      unknown_639_1
    };

    iso639_1 find( char const *lang );
  }

}
#endif  /* ZORBA_LANG_H */
/* vim:set et sw=2 ts=2: */
