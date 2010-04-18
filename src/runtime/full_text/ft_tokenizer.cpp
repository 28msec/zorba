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

#include "runtime/full_text/ft_tokenizer.h"
#include "runtime/full_text/icu_tokenizer.h"

namespace zorba {

ft_tokenizer::ft_tokenizer() {
  token_no_ = sent_no_ = para_no_ = 0;
}

ft_tokenizer::~ft_tokenizer() {
  // do nothing
}

ft_tokenizer* ft_tokenizer::create() {
  return new icu_tokenizer;
}

ft_tokenizer::callback::~callback() {
  // do nothing
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
