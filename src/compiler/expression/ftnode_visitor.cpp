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
#include "stdafx.h"

#include "util/cxx_util.h"

#include "expr_visitor.h"
#include "ftnode.h"
#include "ftnode_visitor.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

ftnode_visitor::~ftnode_visitor() {
  // do nothing
}

///////////////////////////////////////////////////////////////////////////////

expr_visitor* FTNodeExprCollector::get_expr_visitor() {
  return nullptr;
}

#define V FTNodeExprCollector

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftand );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftextension_selection );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftmild_not );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftor );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftprimary_with_options );

ft_visit_result::type V::begin_visit( ftrange &r ) {
  push_back( &r.get_expr1() );
  if ( r.get_expr2() )
    push_back( &r.get_expr2() );
  return ft_visit_result::no_end;
}
DEF_FTNODE_VISITOR_END_VISIT( V, ftrange );

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftselection );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftunary_not );

ft_visit_result::type V::begin_visit( ftweight &w ) {
  push_back( &w.get_weight_expr() );
  return ft_visit_result::no_end;
}
DEF_FTNODE_VISITOR_END_VISIT( V, ftweight );

ft_visit_result::type V::begin_visit( ftwords &w ) {
  push_back( &w.get_value_expr() );
  return ft_visit_result::no_end;
}
DEF_FTNODE_VISITOR_END_VISIT( V, ftwords );

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftwords_times );

// FTPosFilters
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftcontent_filter );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftdistance_filter );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftorder_filter );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftscope_filter );

ft_visit_result::type V::begin_visit( ftwindow_filter &wf ) {
  push_back( &wf.get_window_expr() );
  return ft_visit_result::no_end;
}
DEF_FTNODE_VISITOR_END_VISIT( V, ftwindow_filter )

// FTMatchOptions
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftcase_option );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftdiacritics_option );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftextension_option );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftlanguage_option );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftmatch_options );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstem_option );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstop_word_option );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstop_words );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_id );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_option );
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftwild_card_option );

#undef V

} // namespace zorba
/* vim:set et sw=2 ts=2: */
