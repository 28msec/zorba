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

#ifndef ZORBA_FULL_TEXT_EVAL_VISITOR_H
#define ZORBA_FULL_TEXT_EVAL_VISITOR_H

#include <stack>

#include "compiler/expression/ftnode_visitor.h"
#include "context/static_context.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/full_text/apply.h"    /* for ft_int */
#include "runtime/full_text/ft_match.h"

namespace zorba {

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

  void push_matches( ft_all_matches* );
  ft_all_matches* pop_matches();
  ft_all_matches* top_matches() const;

  typedef std::stack<ftmatch_options const*> options_stack_t;
  options_stack_t options_stack_;

  void push_options( ftmatch_options const* );
  ftmatch_options const* pop_options();
  ftmatch_options const* top_options() const;

  void eval_ftrange( ftrange const&, ft_int *at_least, ft_int *at_most );
  ft_int get_int( PlanIter_t );

  FTTokenIterator_t &search_ctx_;
  static_context const &static_ctx_;
  store::Item const *const ignore_item_;
  PlanState &plan_state_;
  FTToken::int_t query_pos_;
};

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_EVAL_VISITOR_H */
/* vim:set et sw=2 ts=2: */
