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

#ifndef ZORBA_FULL_TEXT_ICU_TOKENIZER_H
#define ZORBA_FULL_TEXT_ICU_TOKENIZER_H

#include <unicode/rbbi.h>

#include "runtime/full_text/tokenizer.h"

namespace zorba {

/**
 * An icu_tokenizer is-a Tokenizer that uses the ICU (International Components
 * for Unicode) library.
 */
class icu_tokenizer : public Tokenizer {
public:
  icu_tokenizer();
  ~icu_tokenizer();

  void tokenize( std::string const &utf8_s, Callback& );

private:
  U_NAMESPACE_QUALIFIER RuleBasedBreakIterator *word_it_;
  U_NAMESPACE_QUALIFIER RuleBasedBreakIterator *sent_it_;
};

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_ICU_TOKENIZER_H */
/* vim:set et sw=2 ts=2: */
