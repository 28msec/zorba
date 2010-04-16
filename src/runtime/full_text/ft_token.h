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
  std::string word;
  int query_pos;
};

/**
 * An ft_query_tokens is a sequence of ft_query_token representing the
 * collection of tokens derived from tokenizing one query string.
 */
typedef std::list<ft_query_token> ft_query_tokens;

///////////////////////////////////////////////////////////////////////////////

/**
 * An ft_token represents a contiguous collection of tokens from an XML
 * document.
 */
struct ft_token {
  typedef int int_t;

  struct start_end {
    int_t start;
    int_t end;
  };

  start_end pos;
  start_end sent;
  start_end para;

  typedef start_end const ft_token::*start_end_ptr;
  typedef int_t const ft_token::start_end::*int_ptr;
};

inline bool operator<( ft_token const &ti, ft_token const &tj ) {
  return  ti.pos.start < tj.pos.start ||
          ti.pos.start == tj.pos.start && ti.pos.end < tj.pos.end;
}

inline bool operator>( ft_token const &ti, ft_token const &tj ) {
  return  ti.pos.start > tj.pos.start ||
          ti.pos.start == tj.pos.start && ti.pos.end > tj.pos.end;
}

typedef std::list<ft_token> ft_tokens;

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_TOKEN_H */
/* vim:set et sw=2 ts=2: */
