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

#ifndef ZORBA_FULL_TEXT_FT_TOKENIZER_H
#define ZORBA_FULL_TEXT_FT_TOKENIZER_H

#include <string>

#include "runtime/full_text/ft_token.h"

namespace zorba {

class ft_tokenizer {
public:
  ~ft_tokenizer();

  void inc_para() {
    ++para_no_;
  }

  static ft_tokenizer* create();

  virtual void tokenize( std::string const &utf8, ft_tokens &result )
    const = 0;

protected:
  ft_tokenizer();

  int token_no_;
  int sent_no_;
  int para_no_;
};

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_TOKENIZER_H */
/* vim:set et sw=2 ts=2: */
