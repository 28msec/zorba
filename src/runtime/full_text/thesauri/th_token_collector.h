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

#ifndef ZORBA_FT_TH_TOKEN_COLLECTOR
#define ZORBA_FT_TH_TOKEN_COLLECTOR

#include "zorbautils/tokenizer.h"

#include "../ft_token_seq_iterator.h"

namespace zorba {

class th_token_collector : public Tokenizer::Callback {
public:
  th_token_collector( int token_no, int sent_no, locale::iso639_1::type lang,
                      FTTokenSeqIterator::FTTokens& );

  void operator()( char const*, int, int, int, int, void* );
private:
  FTTokenSeqIterator::FTTokens &tokens_;
  int const token_no_, sent_no_;
  locale::iso639_1::type const lang_;
};

} // namespace zorba
#endif  /* ZORBA_FT_TH_TOKEN_COLLECTOR */
/* vim:set et sw=2 ts=2: */
