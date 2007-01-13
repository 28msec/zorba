/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: ft_expr.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_FTEXPR_H
#define XQP_FTEXPR_H

#include "exprnodes.h"

namespace xqp {

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  Full-text productions                                              //
//  [http://www.w3.org/TR/xquery-full-text/]                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

class ft_or_expr;

//[344] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTSelection]
class ft_expr : public expr
/*______________________________________________________________________
|	::=	 FTOr  FTMatchOptionProximityList?  ("weight"  FTRangeExpr)?
|_______________________________________________________________________*/
{
protected:
	rchandle<ft_expr> ft_or_h;
	rchandle<ft_options> ft_opt_h;

public:
	ft_expr(
		yy::location const&,
		rchandle<ft_expr>,
		rchandle<ft_options>);

	~ft_expr();

public:
	rchandle<ft_expr> get_ft_or() const { return ft_or_h; }
	rchandle<ft_options> get_ft_options() const { return ft_opt_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[345] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTOr]
class ft_or_expr : public expr
/*______________________________________________________________________
|	::=	FTAnd ( "||" FTAnd )*
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<ft_expr> > ft_and_expr_hv;

public:
	ft_or_expr(yy::location const&);
	~ft_or_expr();

public:
	uint32_t size() const
		{ return ft_and_expr_hv.size(); }
	void add(rchandle<ft_expr> ft_h)
		{ ft_and_expr_hv.push_back(ft_h); }

	rchandle<ft_expr> & operator[](int i)
		{ return ft_and_expr_hv[i]; }
	rchandle<ft_expr> const& operator[](int i) const
		{ return ft_and_expr_hv[i]; }

	std::vector<rchandle<ft_expr> >::const_iterator begin() const
		{ return ft_and_expr_hv.begin(); }
	std::vector<rchandle<ft_expr> >::const_iterator end() const
		{ return ft_and_expr_hv.end(); }

public:
	std::ostream& put(std::ostream&) const;

};



//[346] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTAnd]
class ft_and_expr : public expr
/*______________________________________________________________________
|	::=	FTMildnot ( '&&' FTMildNot )*
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<ft_expr> > ft_mildnot_expr_hv;

public:
	ft_and_expr(yy::location const&);
	~ft_and_expr();

public:
	uint32_t size() const
		{ return ft_mildnot_expr_hv.size(); }
	void add(rchandle<ft_expr> ft_h)
		{ ft_mildnot_expr_hv.push_back(ft_h); }

	rchandle<ft_expr> & operator[](int i)
		{ return ft_mildnot_expr_hv[i]; }
	rchandle<ft_expr> const& operator[](int i) const
		{ return ft_mildnot_expr_hv[i]; }

	std::vector<rchandle<ft_expr> >::const_iterator begin() const
		{ return ft_mildnot_expr_hv.begin(); }
	std::vector<rchandle<ft_expr> >::const_iterator end() const
		{ return ft_mildnot_expr_hv.end(); }

public:
	std::ostream& put(std::ostream&) const;

};



//[347] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTMildnot]
class ft_mildnot_expr : public expr
/*______________________________________________________________________
|	::=	FTUnaryNot ( "not" "in" FTUnaryNot )*
|_______________________________________________________________________*/
{
protected:
	std::vector<rchandle<ft_expr> > ft_unary_expr_hv;

public:
	ft_mildnot_expr(yy::location const&);
	~ft_mildnot_expr();

public:
	uint32_t size() const
		{ return ft_unary_expr_hv.size(); }
	void add(rchandle<ft_expr> ft_h)
		{ ft_unary_expr_hv.push_back(ft_h); }

	rchandle<ft_expr> & operator[](int i)
		{ return ft_unary_expr_hv[i]; }
	rchandle<ft_expr> const& operator[](int i) const
		{ return ft_unary_expr_hv[i]; }

	std::vector<rchandle<ft_expr> >::const_iterator begin() const
		{ return ft_unary_expr_hv.begin(); }
	std::vector<rchandle<ft_expr> >::const_iterator end()
		{ return ft_unary_expr_hv.end(); }

public:
	std::ostream& put(std::ostream&) const;

};



//[350] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWords]
class ft_words_expr : public expr
/*______________________________________________________________________
|	::=	FTWordsValue  FTAnyallOption?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> words_expr_h;
	ft_anyall_option_t anyall_opt;

public:
	ft_words_expr(
		yy::location const&,
		rchandle<expr>,
		ft_anyall_option_t);

	~ft_words_expr();

public:
	rchandle<expr> get_words_expr() const
		{ return words_expr_h; }
	ft_anyall_option_t get_anyall_option() const
		{ return anyall_opt; }

public:
	std::ostream& put(std::ostream&) const;

};



//[349] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWordsSelection]
class ft_words_selection_expr : public expr
/*______________________________________________________________________
|	::=	FTWords	 FTTimes?
|			| LPAR  FTSelection  RPAR
|_______________________________________________________________________*/
{
protected:
	rchandle<ft_words_expr> words_h;
	rchandle<expr> src_h;
	rchandle<expr> dst_h;
	ft_range_mode_t range_mode;
	rchandle<ft_expr> selection_h;

public:
	ft_words_selection_expr(
		yy::location const&,
		rchandle<ft_words_expr>,
		rchandle<expr> src_h,
		rchandle<expr> dst_h,
		ft_range_mode_t range_mode);

	ft_words_selection_expr(
		yy::location const&,
		rchandle<ft_expr>);
	
	~ft_words_selection_expr();

public:
	rchandle<ft_words_expr> get_words() const { return words_h; }
	rchandle<expr> get_src() const { return src_h; }
	rchandle<expr> get_dst() const { return dst_h; }
	ft_range_mode_t get_range_mode() const { return range_mode; }
	rchandle<ft_expr> get_selection() const { return selection_h; }

public:
	std::ostream& put(std::ostream&) const;

};



//[348] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTUnaryNot]

class ft_unarynot_expr : public expr
/*______________________________________________________________________
|	::=	("!")? FTWordsSelection
|_______________________________________________________________________*/
{
protected:
	rchandle<ft_words_selection_expr> words_selection_h;
	bool not_b;

public:
	ft_unarynot_expr(
		yy::location const&,
		rchandle<ft_words_selection_expr>,
		bool not_b);

	~ft_unarynot_expr();

public:
	rchandle<ft_words_selection_expr> get_words_selection() const
		{ return words_selection_h; }
	bool get_not_bit() const
		{ return not_b; }

public:
	std::ostream& put(std::ostream&) const;

};


} /* namespace xqp */
#endif /* XQP_FTEXPR_H */


