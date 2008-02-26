/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: update_expr.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_UPDATE_EXPR_H
#define XQP_UPDATE_EXPR_H

#include "compiler/expression/expr.h"

#include <iostream>

namespace xqp {

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Update expressions                                                 //
//  [http://www.w3.org/TR/xqupdate/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// [242] [http://www.w3.org/TR/xqupdate/#prod-xquery-InsertExpr]
class insert_expr : public expr
/*______________________________________________________________________
|	::= DO_INSERT  ExprSingle  INTO  ExprSingle
|			|	DO_INSERT  ExprSingle  AS  FIRST_INTO  ExprSingle
|			|	DO_INSERT  ExprSingle  AS  LAST_INTO  ExprSingle
|			| DO_INSERT  ExprSingle  AFTER  ExprSingle
|			| DO_INSERT  ExprSingle  BEFORE  ExprSingle
|_______________________________________________________________________*/
{
protected:
	expr_t source_expr_h;
	expr_t target_expr_h;

public:
	insert_expr(
		const QueryLoc&,
		expr_t,
		expr_t);
	~insert_expr();

public:
	expr_t get_source_expr() const { return source_expr_h; }
	expr_t get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [243] [http://www.w3.org/TR/xqupdate/#prod-xquery-DeleteExpr]
class delete_expr : public expr
/*______________________________________________________________________
|	::= DO_DELETE  expr
|_______________________________________________________________________*/
{
protected:
	expr_t target_expr_h;

public:
	delete_expr(
		const QueryLoc&,
		expr_t);
	~delete_expr();

public:
	expr_t get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [244] [http://www.w3.org/TR/xqupdate/#prod-xquery-ReplaceExpr]
class replace_expr : public expr
/*______________________________________________________________________
|	::= DO_REPLACE  expr  WITH  expr
|			| DO_REPLACE  VALUE_OF  expr  WITH  expr
|_______________________________________________________________________*/
{
protected:
	expr_t source_expr_h;
	expr_t target_expr_h;

public:
	replace_expr(
		const QueryLoc&,
		expr_t source_expr_h,
		expr_t target_expr_h);
	~replace_expr();

public:
	expr_t get_source_expr() const { return source_expr_h; }
	expr_t get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [245] [http://www.w3.org/TR/xqupdate/#prod-xquery-RenameExpr]
class rename_expr : public expr
/*______________________________________________________________________
|	::= DO_RENAME  expr  AS  expr
|_______________________________________________________________________*/
{
protected:
	expr_t source_expr_h;
	expr_t target_expr_h;

public:
	rename_expr(
		const QueryLoc&,
		expr_t source_expr_h,
		expr_t target_expr_h);
	~rename_expr();

public:
	expr_t get_source_expr() const { return source_expr_h; }
	expr_t get_target_expr() const { return target_expr_h; }

public:
	std::ostream& put(std::ostream&) const;

};



// [249] [http://www.w3.org/TR/xqupdate/#prod-xquery-TransformExpr]
class transform_expr : public expr
/*______________________________________________________________________
|	::= TRANSFORM_COPY_DOLLAR  VarNameList
|				MODIFY  expr  RETURN  expr
|_______________________________________________________________________*/
{
public:
	typedef rchandle<var_expr> varref_t;

protected:
	std::vector<varref_t> vref_hv;
	expr_t source_expr_h;
	expr_t target_expr_h;

public:
	transform_expr(
		const QueryLoc&,
		expr_t source_expr_h,
		expr_t target_expr_h);
	~transform_expr();

public:
	expr_t get_source_expr() const { return source_expr_h; }
	expr_t get_target_expr() const { return target_expr_h; }

public:
	void add(varref_t vref_h)
		{ vref_hv.push_back(vref_h); }

	varref_t & operator[](int i)
		{ return vref_hv[i]; }
	varref_t const& operator[](int i) const
		{ return vref_hv[i]; }

	std::vector<varref_t>::const_iterator begin() const
		{ return vref_hv.begin(); }
	std::vector<varref_t>::const_iterator end() const
		{ return vref_hv.end(); }
	uint32_t size() const
		{ return vref_hv.size(); }

public:
	std::ostream& put(std::ostream&) const;

};


} /* namespace xqp */
#endif /* XQP_UPDATE_EXPR_H */

