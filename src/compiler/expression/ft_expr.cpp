/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: ft_expr.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "compiler/expression/ft_expr.h"

using namespace std;
namespace xqp {
  
  
/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  Full-text productions                                              //
//  [http://www.w3.org/TR/xquery-full-text/]                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

//[344] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTSelection]

ft_expr::ft_expr(
	const QueryLoc& loc,
	rchandle<ft_expr> _ft_or_h,
	rchandle<ft_options> _ft_opt_h)
:
	expr(loc),
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
	const QueryLoc& loc)
:
	expr(loc)
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
	const QueryLoc& loc)
:
	expr(loc)
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
	const QueryLoc& loc)
:
	expr(loc)
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
	const QueryLoc& loc,
	rchandle<ft_words_selection_expr> _words_selection_h,
	bool _not_b)
:
	expr(loc),
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
	const QueryLoc& loc,
	rchandle<ft_words_expr> _words_h,
	rchandle<expr> _src_h,
	rchandle<expr> _dst_h,
	ft_range_mode_t _range_mode)
:
	expr(loc),
	words_h(_words_h),
	src_h(_src_h),
	dst_h(_dst_h),
	range_mode(_range_mode)
{
}

ft_words_selection_expr::ft_words_selection_expr(
	const QueryLoc& loc,
	rchandle<ft_expr> _selection_h)
:
	expr(loc),
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
	const QueryLoc& loc,
	rchandle<expr> _words_expr_h,
	ft_anyall_option_t _anyall_opt)
:
	expr(loc),
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



} /* namespace xqp */

