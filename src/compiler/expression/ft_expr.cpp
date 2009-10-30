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
#include "compiler/expression/ft_expr.h"

using namespace std;

namespace zorba 
{
  
SERIALIZABLE_CLASS_VERSIONS(ft_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_or_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_or_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_and_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_and_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_mildnot_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_mildnot_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_words_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_words_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_words_selection_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_words_selection_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_unarynot_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_unarynot_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_select_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_select_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_contains_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_contains_expr)


#if 0
/*******************************************************************************

********************************************************************************/
#define DEF_ACCEPT( type )             \
void type::accept(expr_visitor& v)     \
{                                      \
  if (v.begin_visit(*this))            \
    accept_children(v);                \
                                       \
  v.end_visit(*this);                  \
}


DEF_ACCEPT (ft_contains_expr)
#endif


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  Full-text productions                                              //
//  [http://www.w3.org/TR/xquery-full-text/]                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

//[344] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTSelection]

ft_expr::ft_expr(
  short sctx,
	const QueryLoc& loc,
	rchandle<ft_expr> _ft_or_h,
	rchandle<ft_options> _ft_opt_h)
:
	expr(sctx, loc),
	ft_or_h(_ft_or_h),
	ft_opt_h(_ft_opt_h)
{
}

ft_expr::~ft_expr()
{
}

ostream& ft_expr::put(ostream& os) const
{
	return os << "ft_expr[]\n";
}



//[345] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTOr]

ft_or_expr::ft_or_expr(
  short sctx,
	const QueryLoc& loc)
:
	expr(sctx, loc)
{
}

ft_or_expr::~ft_or_expr()
{
}

ostream& ft_or_expr::put(ostream& os) const
{
	return os << "ft_or_expr[]\n";
}



//[346] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTAnd]

ft_and_expr::ft_and_expr(
  short sctx,
	const QueryLoc& loc)
:
	expr(sctx, loc)
{
}

ft_and_expr::~ft_and_expr()
{
}

ostream& ft_and_expr::put(ostream& os) const
{
	return os << "ft_and_expr[]\n";
}



//[347] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTMildnot]

ft_mildnot_expr::ft_mildnot_expr(
  short sctx,
	const QueryLoc& loc)
:
	expr(sctx, loc)
{
}

ft_mildnot_expr::~ft_mildnot_expr()
{
}

ostream& ft_mildnot_expr::put(ostream& os) const
{
	return os << "ft_mildnot_expr[]\n";
}



//[348] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTUnaryNot]

ft_unarynot_expr::ft_unarynot_expr(
  short sctx,
	const QueryLoc& loc,
	rchandle<ft_words_selection_expr> _words_selection_h,
	bool _not_b)
:
	expr(sctx, loc),
	words_selection_h(_words_selection_h),
	not_b(_not_b)
{
}

ft_unarynot_expr::~ft_unarynot_expr()
{
}

ostream& ft_unarynot_expr::put(ostream& os) const
{
	return os << "ft_unarynot_expr[]\n";
}



//[349] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWordsSelection]

ft_words_selection_expr::ft_words_selection_expr(
  short sctx,
	const QueryLoc& loc,
	rchandle<ft_words_expr> _words_h,
	rchandle<expr> _src_h,
	rchandle<expr> _dst_h,
	ParseConstants::ft_range_mode_t _range_mode)
:
	expr(sctx, loc),
	words_h(_words_h),
	src_h(_src_h),
	dst_h(_dst_h),
	range_mode(_range_mode)
{
}

ft_words_selection_expr::ft_words_selection_expr(
  short sctx,
	const QueryLoc& loc,
	rchandle<ft_expr> _selection_h)
:
	expr(sctx, loc),
	selection_h(_selection_h)
{
}

ft_words_selection_expr::~ft_words_selection_expr()
{
}

ostream& ft_words_selection_expr::put(ostream& os) const
{
	return os << "ft_words_selection_expr[]\n";
}



//[350] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWords]

ft_words_expr::ft_words_expr(
  short sctx,
	const QueryLoc& loc,
	rchandle<expr> _words_expr_h,
	ParseConstants::ft_anyall_option_t _anyall_opt)
:
	expr(sctx, loc),
	words_expr_h(_words_expr_h),
	anyall_opt(_anyall_opt)
{
}

ft_words_expr::~ft_words_expr()
{
}

ostream& ft_words_expr::put(ostream& os) const
{
	return os << "ft_words_expr[]\n";
}


/*******************************************************************************

********************************************************************************/
ft_contains_expr::ft_contains_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t _range_h,
    expr_t _ft_select_h,
    expr_t _ft_ignore_h)
  :
  expr(sctx, loc),
  range_h(_range_h),
  ft_select_h(_ft_select_h),
  ft_ignore_h(_ft_ignore_h)
{
}

#if 0
void ft_contains_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER ();
  ITER (range_h);
  ITER (ft_select_h);
  ITER (ft_ignore_h);
  END_EXPR_ITER ();
}


ostream& ft_contains_expr::put( ostream& os) const
{
  BEGIN_EXPR (ft_contains_expr);
  range_h->put(os) << endl;
  os << "ft_contains\n";
  ft_select_h->put(os) << endl;
  if (ft_ignore_h!=NULL) ft_ignore_h->put(os);
  CLOSE_EXPR;
}
#endif

} /* namespace zorba */

