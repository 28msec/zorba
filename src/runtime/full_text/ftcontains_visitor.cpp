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

#include <limits>

#include "compiler/expression/ftexpr.h"
#include "runtime/full_text/apply.h"
#include "runtime/full_text/ftcontains_visitor.h"
#include "runtime/full_text/stl_helpers.h"

using namespace std;

namespace zorba {

//for Windows build
#undef max
#undef min


ftcontains_visitor::ftcontains_visitor( ft_item_tokens const &tokens,
                                        PlanState &state ) :
  plan_state_( state )
{
  // do nothing
}

ftcontains_visitor::~ftcontains_visitor() {
  // do nothing
}

bool ftcontains_visitor::ftcontains() const {
  if ( eval_stack_.empty() )
    return false;
  ft_all_matches const &am = *top();
  if ( am.empty() )
    return false;
  //
  // See spec section 4.3.
  //
  FOR_EACH( ft_all_matches, m, am )
    if ( m->excludes.empty() )
      return true;
  return false;
}
/*
expr_visitor& ftcontains_visitor::get_expr_visitor() {
  // TODO
}
*/
///////////////////////////////////////////////////////////////////////////////

#define V ftcontains_visitor

ft_visit_result::type V::begin_visit( ftand_expr &e ) {
  push( NULL ); // sentinel
  return ft_visit_result::proceed;
}

void V::end_visit( ftand_expr &e ) {
  while ( true ) {
    ft_all_matches *const ami = pop();
    if ( !ami )
      break;
    ft_all_matches *const amj = pop();
    ft_all_matches *const result = new ft_all_matches;
    apply_ftand( *ami, *amj, *result );
    push( result );
    delete ami;
    delete amj;
  }
}

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftextension_selection_expr )

ft_visit_result::type V::begin_visit( ftmild_not_expr &e ) {
  push( NULL ); // sentinel
  return ft_visit_result::proceed;
}

void V::end_visit( ftmild_not_expr &e ) {
  while ( true ) {
    ft_all_matches *const ami = pop();
    if ( !ami )
      break;
    ft_all_matches *const amj = pop();
    ft_all_matches *const result = new ft_all_matches;
    apply_ftmild_not( *ami, *amj, *result );
    push( result );
    delete ami;
    delete amj;
  }
}

ft_visit_result::type V::begin_visit( ftor_expr &e ) {
  push( NULL ); // sentinel
  return ft_visit_result::proceed;
}

void V::end_visit( ftor_expr &e ) {
  while ( true ) {
    ft_all_matches *const ami = pop();
    if ( !ami )
      break;
    ft_all_matches *const amj = pop();
    ft_all_matches *const result = new ft_all_matches;
    apply_ftor( *ami, *amj, *result );
    push( result );
    delete ami;
    delete amj;
  }
}

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftprimary_with_options_expr )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftrange_expr )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftselection_expr )

DEF_FTEXPR_VISITOR_BEGIN_VISIT( V, ftunary_not_expr )

void V::end_visit( ftunary_not_expr& ) {
  apply_ftunary_not( *top() );
}

ft_visit_result::type V::begin_visit( ftwords_expr &e ) {
  return ft_visit_result::proceed;
}

void V::end_visit( ftwords_expr &e ) {
  store::Item_t item;
  PlanIterator::consumeNext( item, e.get_plan_iter(), plan_state_ );
  /* TODO
  item->
  */
  ft_tokens search_ctx;
  ft_query_tokens qtokens;
  ft_query_token::int_t query_pos = 0;
  ft_all_matches *const result = new ft_all_matches;
  apply_ftwords( search_ctx, qtokens, query_pos, e.get_mode(), *result );
  push( result );
}

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftwords_times_expr )

////////// FTPosFilters ///////////////////////////////////////////////////////

DEF_FTEXPR_VISITOR_BEGIN_VISIT( V, ftcontent_filter )

void V::end_visit( ftcontent_filter &f ) {
  apply_ftcontent( *top(), f.get_mode() );
}

DEF_FTEXPR_VISITOR_BEGIN_VISIT( V, ftdistance_filter )

void V::end_visit( ftdistance_filter &f ) {
  ftrange_expr const *const range = f.get_range();

  store::Item_t item1;
  PlanIterator::consumeNext( item1, range->get_plan_iter1(), plan_state_ );

  int at_least = 0;
  int at_most = numeric_limits<int>::max();

  switch ( range->get_mode() ) {
    case ft_range_mode::at_least:
      at_least = item1->getIntValue();
      break;
    case ft_range_mode::at_most:
      at_most = item1->getIntValue();
      break;
    case ft_range_mode::exactly:
      at_least = at_most = item1->getIntValue();
      break;
    case ft_range_mode::from_to:
      at_least = item1->getIntValue();
      store::Item_t item2;
      PlanIterator::consumeNext( item2, range->get_plan_iter2(), plan_state_ );
      at_most = item2->getIntValue();
      break;
  }

  ft_all_matches *const am = pop();
  ft_all_matches *const result = new ft_all_matches;
  apply_ftdistance( *am, at_least, at_most, f.get_unit(), *result );
  push( result );
  delete am;
}

DEF_FTEXPR_VISITOR_BEGIN_VISIT( V, ftorder_filter )

void V::end_visit( ftorder_filter &f ) {
  apply_ftorder( *top() );
}

DEF_FTEXPR_VISITOR_BEGIN_VISIT( V, ftscope_filter )

void V::end_visit( ftscope_filter &f ) {
  ft_all_matches *const am = pop();
  ft_all_matches *const result = new ft_all_matches;
  apply_ftscope( *am, f.get_scope(), f.get_unit(), *result );
  push( result );
  delete am;
}

DEF_FTEXPR_VISITOR_BEGIN_VISIT( V, ftwindow_filter )

void V::end_visit( ftwindow_filter &f ) {
  store::Item_t item;
  PlanIterator::consumeNext( item, f.get_plan_iter(), plan_state_ );
  ft_all_matches *const am = pop();
  ft_all_matches *const result = new ft_all_matches;
  apply_ftwindow( *am, item->getIntValue(), f.get_unit(), *result );
  push( result );
  delete am;
}

////////// FTMatchOptions /////////////////////////////////////////////////////

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftcase_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftdiacritics_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftextension_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftlanguage_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftmatch_options )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstem_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstop_word_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstop_words )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_id )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftwild_card_option )

#undef V

} // namespace zorba
/* vim:set et sw=2 ts=2: */
