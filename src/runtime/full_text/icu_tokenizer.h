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

#include <unicode/brkiter.h>

#include "runtime/full_text/ft_tokenizer.h"

namespace zorba {

class icu_tokenizer : public ft_tokenizer {
public:
  ~icu_tokenizer();

  void tokenize( std::string const &utf8_text, ft_tokens &result ) const;

private:
  U_NAMESPACE_QUALIFIER BreakIterator* get_word_it() const;
  U_NAMESPACE_QUALIFIER BreakIterator* get_sent_it() const;

  mutable U_NAMESPACE_QUALIFIER BreakIterator *word_it_;
  mutable U_NAMESPACE_QUALIFIER BreakIterator *sent_it_;
};

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_ICU_TOKENIZER_H */
/* vim:set et sw=2 ts=2: */
