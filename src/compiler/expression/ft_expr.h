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
#ifndef ZORBA_FTEXPR_H
#define ZORBA_FTEXPR_H

#include "compiler/parser/parse_constants.h"

#include "compiler/expression/expr_base.h"

#include "store/api/fullText/ft_options.h"

namespace zorba {

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//  Full-text productions                                              //
//  [http://www.w3.org/TR/xquery-full-text/]                           //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

class ft_or_expr;
class ft_options;

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
  SERIALIZABLE_ABSTRACT_CLASS(ft_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & ft_or_h;
    ar & ft_opt_h;
  }
public:
	ft_expr(
    short sctx,
		const QueryLoc&,
		rchandle<ft_expr>,
		rchandle<ft_options>);

	~ft_expr();

public:
	rchandle<ft_expr> get_ft_or() const { return ft_or_h; }
	rchandle<ft_options> get_ft_options() const { return ft_opt_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

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
  SERIALIZABLE_ABSTRACT_CLASS(ft_or_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_or_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & ft_and_expr_hv;
  }
public:
	ft_or_expr(short sctx, const QueryLoc&);
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
	virtual std::ostream& put(std::ostream&) const;

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
  SERIALIZABLE_ABSTRACT_CLASS(ft_and_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_and_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & ft_mildnot_expr_hv;
  }
public:
	ft_and_expr(short sctx, const QueryLoc&);
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
	virtual std::ostream& put(std::ostream&) const;

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
  SERIALIZABLE_ABSTRACT_CLASS(ft_mildnot_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_mildnot_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & ft_unary_expr_hv;
  }
public:
	ft_mildnot_expr(short sctx, const QueryLoc&);
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
	virtual std::ostream& put(std::ostream&) const;

};



//[350] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTWords]
class ft_words_expr : public expr
/*______________________________________________________________________
|	::=	FTWordsValue  FTAnyallOption?
|_______________________________________________________________________*/
{
protected:
	rchandle<expr> words_expr_h;
  ParseConstants::ft_anyall_option_t anyall_opt;

public:
  SERIALIZABLE_ABSTRACT_CLASS(ft_words_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_words_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & words_expr_h;
    SERIALIZE_ENUM(ParseConstants::ft_anyall_option_t, anyall_opt);
  }
public:
	ft_words_expr(
    short sctx,
		const QueryLoc&,
		rchandle<expr>,
		ParseConstants::ft_anyall_option_t);

	~ft_words_expr();

public:
	rchandle<expr> get_words_expr() const
		{ return words_expr_h; }
  ParseConstants::ft_anyall_option_t get_anyall_option() const
		{ return anyall_opt; }

public:
	virtual std::ostream& put(std::ostream&) const;

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
  ParseConstants::ft_range_mode_t range_mode;
	rchandle<ft_expr> selection_h;

public:
  SERIALIZABLE_ABSTRACT_CLASS(ft_words_selection_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_words_selection_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & words_h;
    ar & src_h;
    ar & dst_h;
    SERIALIZE_ENUM(ParseConstants::ft_range_mode_t, range_mode);
    ar & selection_h;
  }
public:
	ft_words_selection_expr(
    short sctx,
		const QueryLoc&,
		rchandle<ft_words_expr>,
		rchandle<expr> src_h,
		rchandle<expr> dst_h,
		ParseConstants::ft_range_mode_t range_mode);

	ft_words_selection_expr(
    short sctx,
		const QueryLoc&,
		rchandle<ft_expr>);
	
	~ft_words_selection_expr();

public:
	rchandle<ft_words_expr> get_words() const { return words_h; }
	rchandle<expr> get_src() const { return src_h; }
	rchandle<expr> get_dst() const { return dst_h; }
  ParseConstants::ft_range_mode_t get_range_mode() const { return range_mode; }
	rchandle<ft_expr> get_selection() const { return selection_h; }

public:
	virtual std::ostream& put(std::ostream&) const;

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
  SERIALIZABLE_ABSTRACT_CLASS(ft_unarynot_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ft_unarynot_expr, expr)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (expr*)this);
    ar & words_selection_h;
    ar & not_b;
  }
public:
	ft_unarynot_expr(
    short sctx,
		const QueryLoc&,
		rchandle<ft_words_selection_expr>,
		bool not_b);

	~ft_unarynot_expr();

public:
	rchandle<ft_words_selection_expr> get_words_selection() const
		{ return words_selection_h; }
	bool get_not_bit() const
		{ return not_b; }

public:
	virtual std::ostream& put(std::ostream&) const;

};


} /* namespace zorba */
#endif /* ZORBA_FTEXPR_H */


