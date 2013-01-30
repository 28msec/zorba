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
#ifndef ZORBA_COMPILER_FTNODE_VISITOR_H
#define ZORBA_COMPILER_FTNODE_VISITOR_H

#include "compiler/expression/expr_base.h"
#include "compiler/expression/ftnode_classes.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class ftnode_visitor {
public:
  virtual ~ftnode_visitor();

  virtual expr_visitor* get_expr_visitor() = 0;

# define DECL_FTNODE_VISITOR_VISIT_MEM_FNS(C)           \
  virtual ft_visit_result::type begin_visit( C& ) = 0;  \
  virtual void end_visit( C& ) = 0

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

#undef DECL_FTNODE_VISITOR_VISIT_MEM_FNS
#define DECL_FTNODE_VISITOR_VISIT_MEM_FNS(C)  \
  ft_visit_result::type begin_visit( C& );    \
  void end_visit( C& )

#define DEF_FTNODE_VISITOR_BEGIN_VISIT(V,C)     \
  ft_visit_result::type V::begin_visit( C& ) {  \
    return ft_visit_result::proceed;            \
  }

#define DEF_FTNODE_VISITOR_END_VISIT(V,C)   \
  void V::end_visit( C& ) {                 \
  }

#define DEF_FTNODE_VISITOR_VISIT_MEM_FNS(V,C)   \
  DEF_FTNODE_VISITOR_BEGIN_VISIT(V,C)           \
  DEF_FTNODE_VISITOR_END_VISIT(V,C)

protected:
  ftnode_visitor() { }
};

///////////////////////////////////////////////////////////////////////////////

/**
 * An FTNodeExprCollector is-an ftnode_visitor that collects all nested expr
 * nodes into a single collection.
 */
class FTNodeExprCollector : public ftnode_visitor {
public:
  typedef std::vector<expr**> expr_list_t;

  expr_visitor* get_expr_visitor();

  expr_list_t& get_expr_list() {
    return expr_list_;
  }

protected:
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
  void push_back( expr** e ) {
    expr_list_.push_back( e );
  }

  expr_list_t expr_list_;
};

} // namespace zorba
#endif /* ZORBA_FTNODE_VISITOR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
