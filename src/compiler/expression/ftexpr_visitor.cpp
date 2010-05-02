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

#include "compiler/expression/expr_visitor.h"
#include "compiler/expression/ftexpr.h"
#include "compiler/expression/ftexpr_visitor.h"

using namespace std;

namespace zorba {


///////////////////////////////////////////////////////////////////////////////

ftselection_visitor::~ftselection_visitor() {
  // do nothing
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  next_iter_ftselection_visitor                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#define V next_iter_ftselection_visitor

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftand_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftextension_selection_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftmild_not_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftor_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftprimary_with_options_expr );

ft_visit_result::type V::begin_visit( ftrange_expr &c ) 
{
  push_back( c.get_expr1().getp() );
  if ( c.get_expr2() )
    push_back( c.get_expr2().getp() );
  return ft_visit_result::no_end;
}

DEF_FTEXPR_VISITOR_END_VISIT( V, ftrange_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftselection_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftunary_not_expr );

ft_visit_result::type V::begin_visit( ftwords_expr &c ) 
{
  push_back( c.get_expr() );
  return ft_visit_result::no_end;
}

DEF_FTEXPR_VISITOR_END_VISIT( V, ftwords_expr );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftwords_times_expr );

// FTPosFilters
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftcontent_filter );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftdistance_filter );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftorder_filter );

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftscope_filter );

ft_visit_result::type V::begin_visit( ftwindow_filter &c ) 
{
  push_back( c.get_window().getp() );
  return ft_visit_result::no_end;
}

DEF_FTEXPR_VISITOR_END_VISIT( V, ftwindow_filter )

// FTMatchOptions
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftcase_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftdiacritics_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftextension_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftlanguage_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftmatch_options );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstem_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstop_word_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstop_words );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_id );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_option );
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftwild_card_option );

#undef V



} // namespace zorba
/* vim:set et sw=2 ts=2: */
