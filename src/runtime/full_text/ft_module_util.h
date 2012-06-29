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

#ifndef ZORBA_FT_MODULE_UTIL_H
#define ZORBA_FT_MODULE_UTIL_H

//
// The reason this header (and related .cpp) are necessary (instead of just
// puting this code into ft_module.h/.cpp directly) is because this header
// needs to be #include'd into the .cpp generated from the ft_module.xml file.
//

#include <zorba/tokenizer.h>

#include <deque>

#include "store/api/item.h"
#include "util/cxx_util.h"
#include "zorbatypes/ft_token.h"

#include "ft_module_util.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %TokenizeNodesCallback is-a Tokenizer::Callback that's used exclusively by
 * the TokenizeNodesIterator that implements the ft:tokenize-nodes() full-text
 * module function.
 */
class TokenizeNodesCallback : public Tokenizer::Callback {
public:
  TokenizeNodesCallback() : tokens_( nullptr ) { }
  TokenizeNodesCallback( std::deque<FTToken> &tokens ) : tokens_( &tokens ) { }

  void set_tokens( std::deque<FTToken> &tokens ) {
    tokens_ = &tokens;
  }

  // inherited
  void token( char const *utf8_s, size_type utf8_len,
              locale::iso639_1::type lang, size_type token_no,
              size_type sent_no, size_type para_no, Item const *item = 0 );

private:
  std::deque<FTToken> *tokens_;
};

///////////////////////////////////////////////////////////////////////////////

struct TokenQNames {
  store::Item_t token;
  store::Item_t lang;
  store::Item_t paragraph;
  store::Item_t sentence;
  store::Item_t value;
  store::Item_t node_ref;

  TokenQNames();
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_FT_MODULE_UTIL_H */
/* vim:set et sw=2 ts=2: */
