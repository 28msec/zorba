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
#include <memory>

#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#include "runtime/full_text/ftcontains_visitor.h"
#include "system/properties.h"
#include "zorbatypes/numconversions.h"
#include "zorbautils/indent.h"
#include "zorbautils/stl_util.h"

using namespace std;

namespace zorba {

#ifdef WIN32
// Windows annoyingly defines these as macros.
#undef max
#undef min
#endif

////////// Inlines ////////////////////////////////////////////////////////////

inline ft_int to_ft_int( xqp_integer const &i ) {
  ft_int result;
  if ( !NumConversions::integerToUInt( i, result ) ) {
    // TODO
  }
  return result;
}

inline void ftcontains_visitor::push_matches( ft_all_matches *am ) {
  matches_stack_.push( am );
}

inline ft_all_matches* ftcontains_visitor::top_matches() const {
  return matches_stack_.top();
}

inline ft_all_matches* ftcontains_visitor::pop_matches() {
  ft_all_matches *const am = top_matches();
  matches_stack_.pop();
  return am;
}

inline void ftcontains_visitor::push_options( ftmatch_options const *mo ) {
  options_stack_.push( mo );
}

inline ftmatch_options const* ftcontains_visitor::top_options() const {
  return options_stack_.top();
}

inline ftmatch_options const* ftcontains_visitor::pop_options() {
  ftmatch_options const *const mo = top_options();
  options_stack_.pop();
  return mo;
}

////////// PUSH/POP macros ////////////////////////////////////////////////////

#ifndef NDEBUG

#define DOUT Properties::instance()->debug_out()
#define TRACE_FULL_TEXT Properties::instance()->traceFulltext()

inline void pop_helper( char const *what, int line ) {
  if ( TRACE_FULL_TEXT )
    DOUT << indent << "(pop " << what << " @ line " << line << ")\n";
}

#define PUSH(WHAT,OBJ) \
  if ( !TRACE_FULL_TEXT ) ; else                                    \
  DOUT << indent << "(push " #WHAT " @ line " << __LINE__ << ")\n"; \
  push_##WHAT(OBJ)

#define POP(WHAT) \
  ( pop_helper( #WHAT, __LINE__ ), pop_##WHAT() )

#else /* NDEBUG */

#define PUSH(WHAT,OBJ)  push_##WHAT(OBJ)
#define POP(WHAT)       pop_##WHAT()

#endif /* NDEBUG */

#define PUSH_MATCHES(M) PUSH(matches,M)
#define POP_MATCHES()   POP(matches)

#define PUSH_OPTIONS(O) PUSH(options,O)
#define POP_OPTIONS()   POP(options)

///////////////////////////////////////////////////////////////////////////////

ftcontains_visitor::ftcontains_visitor( FTTokenIterator_t &search_ctx,
                                        PlanState &state ) :
  search_ctx_( search_ctx ),
  plan_state_( state )
{
  // do nothing
}

ftcontains_visitor::~ftcontains_visitor() {
  while ( !matches_stack_.empty() )
    delete pop_matches();
}

void ftcontains_visitor::eval_ftrange( ftrange const &range,
                                       ft_int *at_least, ft_int *at_most ) {
  store::Item_t item1;
  PlanIterator::consumeNext( item1, range.get_plan_iter1(), plan_state_ );

  *at_least = 0;
  *at_most = numeric_limits<ft_int>::max();

  switch ( range.get_mode() ) {
    case ft_range_mode::at_least:
      *at_least = to_ft_int( item1->getIntegerValue() );
      break;
    case ft_range_mode::at_most:
      *at_most = to_ft_int( item1->getIntegerValue() );
      break;
    case ft_range_mode::exactly:
      *at_least = *at_most = to_ft_int( item1->getIntegerValue() );
      break;
    case ft_range_mode::from_to:
      *at_least = to_ft_int( item1->getIntegerValue() );
      store::Item_t item2;
      PlanIterator::consumeNext( item2, range.get_plan_iter2(), plan_state_ );
      *at_most = to_ft_int( item2->getIntegerValue() );
      break;
  }
}

bool ftcontains_visitor::ftcontains() const {
  if ( matches_stack_.empty() )
    return false;
  ft_all_matches const &am = *top_matches();
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

expr_visitor* ftcontains_visitor::get_expr_visitor() {
  return NULL;
}

////////// Visit macros ///////////////////////////////////////////////////////

#ifndef NDEBUG

#define BEGIN_VISIT(LABEL) \
  cout << indent << "BEGIN " #LABEL << endl << inc_indent

#define END_VISIT(LABEL) \
  cout << dec_indent << indent << "END " #LABEL << endl

#undef DEF_FTNODE_VISITOR_BEGIN_VISIT
#define DEF_FTNODE_VISITOR_BEGIN_VISIT(V,C)     \
  ft_visit_result::type V::begin_visit( C& ) {  \
    BEGIN_VISIT(C);                             \
    return ft_visit_result::proceed;            \
  }

#undef DEF_FTNODE_VISITOR_END_VISIT
#define DEF_FTNODE_VISITOR_END_VISIT(V,C)   \
  void V::end_visit( C& ) {                 \
    END_VISIT(C);                           \
  }

#else /* NDEBUG */

#define BEGIN_VISIT(LABEL)  /* nothing */
#define END_VISIT(LABEL)    /* nothing */

#endif /* NDEBUG */

///////////////////////////////////////////////////////////////////////////////

#define V ftcontains_visitor

ft_visit_result::type V::begin_visit( ftand& ) {
  BEGIN_VISIT( ftand );
  PUSH_MATCHES( NULL ); // sentinel
  return ft_visit_result::proceed;
}

void V::end_visit( ftand& ) {
  while ( true ) {
    // the popping order is significant
    auto_ptr<ft_all_matches> am_right( POP_MATCHES() );
    auto_ptr<ft_all_matches> am_left( POP_MATCHES() );
    if ( !am_left.get() ) {
      PUSH_MATCHES( am_right.release() );
      break;
    }
    auto_ptr<ft_all_matches> result( new ft_all_matches );
    apply_ftand( *am_left, *am_right, *result );
    PUSH_MATCHES( result.release() );
  }
  END_VISIT( ftand );
}

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftextension_selection )

ft_visit_result::type V::begin_visit( ftmild_not& ) {
  BEGIN_VISIT( ftmild_not );
  PUSH_MATCHES( NULL ); // sentinel
  return ft_visit_result::proceed;
}

void V::end_visit( ftmild_not& ) {
  while ( true ) {
    // the popping order is significant
    auto_ptr<ft_all_matches> am_right( POP_MATCHES() );
    auto_ptr<ft_all_matches> am_left( POP_MATCHES() );
    if ( !am_left.get() ) {
      PUSH_MATCHES( am_right.release() );
      break;
    }
    auto_ptr<ft_all_matches> result( new ft_all_matches );
    apply_ftmild_not( *am_left, *am_right, *result );
    PUSH_MATCHES( result.release() );
  }
  END_VISIT( ftmild_not );
}

ft_visit_result::type V::begin_visit( ftor& ) {
  BEGIN_VISIT( ftor );
  PUSH_MATCHES( NULL ); // sentinel
  return ft_visit_result::proceed;
}

void V::end_visit( ftor& ) {
  while ( true ) {
    // the popping order is significant
    auto_ptr<ft_all_matches> am_right( POP_MATCHES() );
    auto_ptr<ft_all_matches> am_left( POP_MATCHES() );
    if ( !am_left.get() ) {
      PUSH_MATCHES( am_right.release() );
      break;
    }
    auto_ptr<ft_all_matches> result( new ft_all_matches );
    apply_ftor( *am_left, *am_right, *result );
    PUSH_MATCHES( result.release() );
  }
  END_VISIT( ftor );
}

ft_visit_result::type V::begin_visit( ftprimary_with_options &pwo ) {
  BEGIN_VISIT( ftprimary_with_options );
  PUSH_OPTIONS( pwo.get_match_options() );
  return ft_visit_result::proceed;
}
void V::end_visit( ftprimary_with_options& ) {
  POP_OPTIONS();
  END_VISIT( ftprimary_with_options );
}

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftrange )

ft_visit_result::type V::begin_visit( ftselection& ) {
  BEGIN_VISIT( ftselection );
  query_pos_ = 0;
  return ft_visit_result::proceed;
}
DEF_FTNODE_VISITOR_END_VISIT( V, ftselection )

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftunary_not )
void V::end_visit( ftunary_not& ) {
  apply_ftunary_not( *top_matches() );
  END_VISIT( ftunary_not );
}

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftwords )
void V::end_visit( ftwords &w ) {
  ftmatch_options const &options = *top_options();
  if ( ftwild_card_option const *const wc = options.get_wild_card_option() ) {
    if ( wc->get_mode() == ft_wild_card_mode::with ) {
      // TODO: affects query tokenization
    }
  }

  store::Item_t item;
  FTQueryItemSeq query_items;
  while ( PlanIterator::consumeNext( item, w.get_plan_iter(), plan_state_ ) ) {
    FTQueryItem const qi( item->getQueryTokens() );
    if ( !qi->empty() )
      query_items.push_back( qi );
  }

  if ( !query_items.empty() ) {
    auto_ptr<ft_all_matches> result( new ft_all_matches );
    apply_ftwords(
      search_ctx_, query_items, ++query_pos_, w.get_mode(), options, *result
    );
    PUSH_MATCHES( result.release() );
  }
  END_VISIT( ftwords );
}

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftwords_times )
void V::end_visit( ftwords_times &wt ) {
  if ( ftrange const *const range = wt.get_times() ) {
    ft_int at_least, at_most;
    eval_ftrange( *range, &at_least, &at_most );
    auto_ptr<ft_all_matches> const am( POP_MATCHES() );
    auto_ptr<ft_all_matches> result( new ft_all_matches );
    apply_fttimes( *am, range->get_mode(), at_least, at_most, *result );
    PUSH_MATCHES( result.release() );
  }
  END_VISIT( ftwords_times );
}

////////// FTPosFilters ///////////////////////////////////////////////////////

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftcontent_filter )
void V::end_visit( ftcontent_filter &f ) {
  apply_ftcontent(
    *top_matches(), f.get_mode(), search_ctx_->begin(), search_ctx_->end() - 1
  );
  END_VISIT( ftcontent_filter );
}

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftdistance_filter )
void V::end_visit( ftdistance_filter &f ) {
  ft_int at_least, at_most;
  eval_ftrange( *f.get_range(), &at_least, &at_most );
  auto_ptr<ft_all_matches> const am( POP_MATCHES() );
  auto_ptr<ft_all_matches> result( new ft_all_matches );
  apply_ftdistance( *am, at_least, at_most, f.get_unit(), *result );
  PUSH_MATCHES( result.release() );
  END_VISIT( ftdistance_filter );
}

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftorder_filter )
void V::end_visit( ftorder_filter& ) {
  auto_ptr<ft_all_matches> const am( POP_MATCHES() );
  auto_ptr<ft_all_matches> result( new ft_all_matches );
  apply_ftorder( *am, *result );
  PUSH_MATCHES( result.release() );
  END_VISIT( ftorder_filter );
}

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftscope_filter )
void V::end_visit( ftscope_filter &f ) {
  auto_ptr<ft_all_matches> const am( POP_MATCHES() );
  auto_ptr<ft_all_matches> result( new ft_all_matches );
  apply_ftscope( *am, f.get_scope(), f.get_unit(), *result );
  PUSH_MATCHES( result.release() );
  END_VISIT( ftscope_filter );
}

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftwindow_filter )
void V::end_visit( ftwindow_filter &f ) {
  store::Item_t item;
  PlanIterator::consumeNext( item, f.get_plan_iter(), plan_state_ );
  auto_ptr<ft_all_matches> const am( POP_MATCHES() );
  auto_ptr<ft_all_matches> result( new ft_all_matches );
  apply_ftwindow(
    *am, to_ft_int( item->getIntegerValue() ), f.get_unit(), *result
  );
  PUSH_MATCHES( result.release() );
  END_VISIT( ftwindow_filter );
}

////////// FTMatchOptions /////////////////////////////////////////////////////

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftcase_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftdiacritics_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftextension_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftlanguage_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftmatch_options )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstem_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstop_word_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstop_words )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_id )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftwild_card_option )

#undef V

} // namespace zorba
/* vim:set et sw=2 ts=2: */
