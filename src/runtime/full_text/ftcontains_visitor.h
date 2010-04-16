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

#include "compiler/expression/ftexpr_visitor.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/full_text/ft_matches.h"

namespace zorba {

class ftcontains_visitor : public ftexpr_visitor {
public:
  ftcontains_visitor( ft_tokens const&, PlanState& );
  ~ftcontains_visitor();

  bool ftcontains() const;

  expr_visitor& get_expr_visitor();

  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftand_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftextension_selection_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftmild_not_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftor_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftprimary_with_options_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftrange_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftselection_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftunary_not_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwords_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwords_times_expr );

  // FTPosFilters
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftcontent_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftdistance_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftorder_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftscope_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwindow_filter );

  // FTMatchOptions
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftcase_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftdiacritics_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftextension_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftlanguage_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftmatch_options );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstem_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstop_word_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstop_words );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftthesaurus_id );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftthesaurus_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwild_card_option );

private:
  std::stack<ft_all_matches*> eval_stack_;
  PlanState plan_state_;

  void push( ft_all_matches *m ) {
    eval_stack_.push( m );
  }

  ft_all_matches* pop() {
    ft_all_matches *const m = top();
    eval_stack_.pop();
    return m;
  }

  ft_all_matches* top() const {
    return eval_stack_.top();
  }
};

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_EVAL_VISITOR_H */
/* vim:set et sw=2 ts=2: */
