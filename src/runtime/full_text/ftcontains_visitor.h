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
#ifndef ZORBA_FULL_TEXT_FTCONTAINS_VISITOR_H
#define ZORBA_FULL_TEXT_FTCONTAINS_VISITOR_H

#include <stack>

#include "compiler/expression/ftnode_visitor.h"
#include "context/static_context.h"
#include "runtime/base/plan_iterator.h"
#include "zorbatypes/zstring.h"

#include "ft_query_item.h"
#include "ft_match.h"
#include "ft_util.h"

namespace zorba {

class ft_token_matcher;

class ftcontains_visitor : public ftnode_visitor {
public:
  ftcontains_visitor( FTTokenIterator_t &search_ctx, static_context const&,
                      store::Item const *ignore_item,
                      PlanState& );

  ~ftcontains_visitor();

  bool ftcontains() const;

  expr_visitor* get_expr_visitor();

  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftand );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftextension_selection );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftmild_not );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftor );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftprimary_with_options );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftrange );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftselection );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftunary_not );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftweight );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftwords );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftwords_times );

  // FTPosFilters
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftcontent_filter );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftdistance_filter );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftorder_filter );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftscope_filter );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftwindow_filter );

  // FTMatchOptions
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftcase_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftdiacritics_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftextension_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftlanguage_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftmatch_options );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftstem_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftstop_word_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftstop_words );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftthesaurus_id );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftthesaurus_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftwild_card_option );

private:
  typedef std::stack<ft_all_matches*> matches_stack_t;
  matches_stack_t matches_stack_;

  typedef std::stack<ftmatch_options const*> options_stack_t;
  options_stack_t options_stack_;

  typedef std::stack<double> weight_stack_t;
  weight_stack_t weight_stack_;

  void apply_ftwords( query_item_star_t&, FTToken::int_t, store::Item const*,
                      ft_anyall_mode::type, ftmatch_options const&,
                      ft_all_matches& );

  void apply_ftwords_all( query_item_star_t&,
                          FTToken::int_t, store::Item const*,
                          ftmatch_options const&, ft_token_matcher const&,
                          ft_all_matches& );

  void apply_ftwords_any( query_item_star_t&, FTToken::int_t,
                          store::Item const*, ftmatch_options const&,
                          ft_token_matcher const&, ft_all_matches& );

  void apply_ftwords_phrase( query_item_star_t&, FTToken::int_t,
                             store::Item const*, ftmatch_options const&,
                             ft_token_matcher const&, ft_all_matches& );

  void apply_ftwords_xxx_word( query_item_star_t&, FTToken::int_t,
                               store::Item const*, ftmatch_options const&,
                               ft_token_matcher const&, apply_binary_fn,
                               ft_all_matches& );

  void apply_query_tokens_as_phrase( FTTokenIterator&, FTToken::int_t,
                                     store::Item const*, ftmatch_options const&,
                                     ft_token_matcher const&, ft_all_matches& );

  void apply_thesaurus_option( ftthesaurus_option const*, zstring const&,
                               FTToken const&, query_item_star_t&,
                               bool = true );

  void eval_ftrange( ftrange const&, ft_int *at_least, ft_int *at_most );
  double get_double( PlanIter_t const& );
  ft_int get_int( PlanIter_t const& );

  void lookup_thesaurus( ftthesaurus_id const&, zstring const &query_phrase,
                         FTToken const &qt0, query_item_star_t &result );

  FTTokenIterator_t &search_ctx_;
  static_context const &static_ctx_;
  store::Item const *const ignore_item_;
  PlanState &plan_state_;
  FTToken::int_t query_pos_;
  bool calc_score_;
};

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FTCONTAINS_VISITOR_H */
/* vim:set et sw=2 ts=2: */
