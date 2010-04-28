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

#ifndef ZORBA_FULL_TEXT_FT_TOKEN_H
#define ZORBA_FULL_TEXT_FT_TOKEN_H

#include <list>
#include <string>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An ft_query_token is the identity of a token inside a query string.
 */
struct ft_query_token {
  typedef int int_t;

  std::string word;
  int_t pos;
};

/**
 * An ft_query_tokens is a sequence of ft_query_token representing the
 * collection of tokens derived from tokenizing one query string.
 */
typedef std::list<ft_query_token> ft_query_tokens;

///////////////////////////////////////////////////////////////////////////////

/**
 * An ft_item_token is a token in the search context.
 */
struct ft_item_token : ft_query_token {
  int_t sent;
  int_t para;
};

typedef std::list<ft_item_token> ft_item_tokens;

///////////////////////////////////////////////////////////////////////////////

/**
 * An ft_token_span represents a contiguous collection of tokens from an XML
 * document.
 */
struct ft_token_span {
  typedef int int_t;

  struct start_end {
    int_t start;
    int_t end;
  };

  start_end pos;
  start_end sent;
  start_end para;

  typedef start_end const ft_token_span::*start_end_ptr;
  typedef int_t const ft_token_span::start_end::*int_ptr;
};

inline bool operator<( ft_token_span const &tsi, ft_token_span const &tsj ) {
  return  tsi.pos.start < tsj.pos.start ||
          (tsi.pos.start == tsj.pos.start && tsi.pos.end < tsj.pos.end);
}

inline bool operator>( ft_token_span const &tsi, ft_token_span const &tsj ) {
  return  tsi.pos.start > tsj.pos.start ||
          (tsi.pos.start == tsj.pos.start && tsi.pos.end > tsj.pos.end);
}

typedef std::list<ft_token_span> ft_tokens;

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_TOKEN_H */
/* vim:set et sw=2 ts=2: */
