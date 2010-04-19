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

#ifndef ZORBA_FTEXPR_VISITOR_H
#define ZORBA_FTEXPR_VISITOR_H

#include "compiler/expression/expr_base.h"
#include "compiler/expression/expr_classes.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/expression/ftexpr_classes.h"

namespace zorba {

/**
 * An ftexpr_visitor is used to visit the nodes of an ftexpr tree.
 */
class ftexpr_visitor {
public:
  virtual ~ftexpr_visitor();

  virtual expr_visitor& get_expr_visitor() = 0;

# define DECL_FTEXPR_VISITOR_VISIT_MEM_FNS(C)           \
  virtual ft_visit_result::type begin_visit( C& ) = 0;  \
  virtual void end_visit( C& ) = 0

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

# undef DECL_FTEXPR_VISITOR_VISIT_MEM_FNS
# define DECL_FTEXPR_VISITOR_VISIT_MEM_FNS(C) \
  ft_visit_result::type begin_visit( C& );    \
  void end_visit( C& )

# define DEF_FTEXPR_VISITOR_BEGIN_VISIT(V,C)    \
  ft_visit_result::type V::begin_visit( C& ) {  \
    return ft_visit_result::proceed;            \
  }

# define DEF_FTEXPR_VISITOR_END_VISIT(V,C)  \
  void V::end_visit( C& ) {                 \
  }

# define DEF_FTEXPR_VISITOR_VISIT_MEM_FNS(V,C)  \
  DEF_FTEXPR_VISITOR_BEGIN_VISIT(V,C)           \
  DEF_FTEXPR_VISITOR_END_VISIT(V,C)

protected:
  ftexpr_visitor() { }
};

/**
 * A pass_thru_expr_visitor is-an expr_visitor that does nothing except passes
 * an ftexpr_visitor through it to sub-ftexprs.
 */
class pass_thru_expr_visitor : public expr_visitor {
public:
  pass_thru_expr_visitor( ftexpr_visitor &v ) : ftexpr_visitor_( v ) { }

  ftexpr_visitor& get_ftexpr_visitor();

  DECL_EXPR_VISITOR_VISIT_MEM_FNS( attr_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( axis_step_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( castable_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( cast_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( const_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( debugger_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( delete_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( doc_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( dynamic_function_invocation_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( elem_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( eval_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( exit_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( extension_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( flowctl_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( flwor_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( fo_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( ftcontains_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( function_item_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( if_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( insert_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( instanceof_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( match_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( name_cast_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( order_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( pi_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( promote_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( relpath_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( rename_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( replace_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( sequential_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( text_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( transform_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( treat_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( trycatch_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( validate_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( var_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( while_expr );
  DECL_EXPR_VISITOR_VISIT_MEM_FNS( wrapper_expr );

private:
  ftexpr_visitor &ftexpr_visitor_;
};

} // namespace zorba
#endif /* ZORBA_FTEXPR_VISITOR_H */
/* vim:set et sw=2 ts=2: */
