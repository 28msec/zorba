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

#ifndef ZORBA_FULL_TEXT_APPLY_H
#define ZORBA_FULL_TEXT_APPLY_H

#include "compiler/expression/ftnode.h"
#include "compiler/parser/ft_types.h"
#include "runtime/full_text/ft_match.h"
#include "store/api/ft_token_iterator.h"
#include "zorbatypes/numconversions.h"

namespace zorba {

typedef xqp_uint ft_int;

inline ft_int to_ft_int( xqp_integer const &i ) {
  ft_int result;
  if ( !NumConversions::integerToUInt( i, result ) ) {
    // TODO
  }
  return result;
}

void apply_ftand( ft_all_matches const&, ft_all_matches const&,
                  ft_all_matches &result );

void apply_ftcontent( ft_all_matches&, ft_content_mode::type,
                      ft_int lowest_pos, ft_int highest_pos );

void apply_ftdistance( ft_all_matches const&, ft_int at_least, ft_int at_most,
                       ft_unit::type, ft_all_matches &result );

void apply_ftmild_not( ft_all_matches const&, ft_all_matches const&,
                       ft_all_matches &result );

void apply_ftor( ft_all_matches const&, ft_all_matches const&,
                 ft_all_matches &result );

void apply_ftorder( ft_all_matches const&, ft_all_matches &result );

void apply_ftscope( ft_all_matches const&, ft_scope::type, ft_big_unit::type,
                    ft_all_matches &result );

void apply_fttimes( ft_all_matches const&, ft_range_mode::type mode,
                    ft_int at_least, ft_int at_most, ft_all_matches &result );

void apply_ftunary_not( ft_all_matches& );

void apply_ftwindow( ft_all_matches const&, ft_int window_size, ft_unit::type,
                     ft_all_matches &result );

void apply_ftwords( FTTokenIterator_t &search_ctx,
                    FTTokenIterator_t &query_tokens,
                    FTToken::int_t query_pos, ft_anyall_mode::type,
                    ftmatch_options const&, ft_all_matches &result );

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_APPLY_H */
/* vim:set et sw=2 ts=2: */
