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
#ifndef ZORBA_FULL_TEXT_ICU_TOKENIZER_H
#define ZORBA_FULL_TEXT_ICU_TOKENIZER_H

#include <unicode/rbbi.h>               /* for RuleBasedBreakIterator */

#include <zorba/internal/cxx_util.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/locale.h>
#include <zorba/tokenizer.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %ICU_Tokenizer is-a Tokenizer that uses the ICU (International Components
 * for Unicode) library.
 */
class ICU_Tokenizer : public Tokenizer {
public:

  /**
   * Constructs an %ICU_Tokenizer.
   *
   * @param lang The language of the text that the tokenizer will tokenize.
   * @param state The State to use.
   */
  ICU_Tokenizer( locale::iso639_1::type lang, State &state );

  ~ICU_Tokenizer();

  // inherited
  void destroy() const;
  void properties( Properties* ) const;
  void tokenize_string( char const*, size_type, locale::iso639_1::type, bool,
                        Callback&, Item const* );

private:
  typedef std::unique_ptr<RuleBasedBreakIterator> rbbi_ptr;

  locale::iso639_1::type const lang_;
  rbbi_ptr word_it_;
  rbbi_ptr sent_it_;
};

///////////////////////////////////////////////////////////////////////////////

class ICU_TokenizerProvider : public TokenizerProvider {
public:
  ICU_TokenizerProvider() { }           // needed to work-around compiler bug

  // inherited
  bool getTokenizer( locale::iso639_1::type, Tokenizer::State* = 0,
                     Tokenizer::ptr* = 0 ) const;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_ICU_TOKENIZER_H */
/* vim:set et sw=2 ts=2: */
