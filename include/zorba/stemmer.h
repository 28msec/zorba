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

#ifndef ZORBA_STEMMER_API_H
#define ZORBA_STEMMER_API_H

#include <zorba/config.h>

#ifndef ZORBA_NO_FULL_TEXT

#include <zorba/internal/unique_ptr.h>
#include <zorba/internal/ztd.h>
#include <zorba/locale.h>
#include <zorba/zorba_string.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %Stemmer is used to obtain the "stem" (root) word of of some word.  For
 * example the stem of "flavoring" is "flavor".  A %Stemmer is used by the
 * XQuery Full Text feature.
 */
class ZORBA_DLL_PUBLIC Stemmer {
public:
  typedef std::unique_ptr<Stemmer,internal::ztd::destroy_delete<Stemmer> > ptr;

  /**
   * Destroys this %Stemmer.
   * This function is called by Zorba when the %Stemmer is no longer needed.
   *
   * If your StemmerProvider dynamically allocates %Stemmer objects, then the
   * implementation can simply be (and usually is) <code>delete this</code>.
   *
   * If your StemmerProvider returns a pointer to a static %Stemmer object,
   * then the implementation should do nothing.
   */
  virtual void destroy() const = 0;

  /**
   * Stems the given word.
   *
   * @param word The word to stem.
   * @param lang The language of the word.
   * @param result The stemmed word (or the original word if either it and its
   * stem are the same word or the stemmer doesn't know how to stem it).
   */
  virtual void stem( String const &word, locale::iso639_1::type lang,
                     String *result ) const = 0;
protected:
  virtual ~Stemmer();
};

/**
 * A %StemmerProvider, given an language, provies a stemmer for it.
 */
class ZORBA_DLL_PUBLIC StemmerProvider {
public:
  virtual ~StemmerProvider();

  /**
   * Gets a Stemmer for the given language.
   *
   * @param lang The language to get a Stemmer for.
   * @return The relevant Stemmer or \c NULL if no stemmer for the given
   * language is available.
   */
  virtual Stemmer::ptr getStemmer( locale::iso639_1::type lang ) const = 0;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_NO_FULL_TEXT */
#endif /* ZORBA_STEMMER_API_H */
/* vim:set et sw=2 ts=2: */
