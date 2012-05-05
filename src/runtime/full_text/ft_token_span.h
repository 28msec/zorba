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
#ifndef ZORBA_FULL_TEXT_FT_TOKEN_SPAN_H
#define ZORBA_FULL_TEXT_FT_TOKEN_SPAN_H

#ifndef NDEBUG
#include <iostream>
#endif /* NDEBUG */
#include <vector>

#include "zorbatypes/ft_token.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %ft_token_span represents a contiguous collection of tokens from an XML
 * document.
 */
struct ft_token_span {
  typedef FTToken::int_t int_t;

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

/**
 * An %ft_token_spans contains zero or more ft_token_span objects.
 */
typedef std::vector<ft_token_span> ft_token_spans;

////////// Comparison operators ///////////////////////////////////////////////

inline bool operator<( ft_token_span const &tsi, ft_token_span const &tsj ) {
  return  tsi.pos.start < tsj.pos.start ||
          (tsi.pos.start == tsj.pos.start && tsi.pos.end < tsj.pos.end);
}

inline bool operator>( ft_token_span const &tsi, ft_token_span const &tsj ) {
  return  tsi.pos.start > tsj.pos.start ||
          (tsi.pos.start == tsj.pos.start && tsi.pos.end > tsj.pos.end);
}

////////// Insertion operators ////////////////////////////////////////////////

#ifndef NDEBUG
inline std::ostream& operator<<( std::ostream &o,
                                 ft_token_span::start_end const &se ) {
  return o << '[' << se.start << ',' << se.end << ']';
}

inline std::ostream& operator<<( std::ostream &o, ft_token_span const &ts ) {
  return  o << "{TS: pos=" << ts.pos
            << " sent=" << ts.sent
            << " para=" << ts.para << '}';
}
#endif /* NDEBUG */

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_TOKEN_SPAN_H */
/* vim:set et sw=2 ts=2: */
