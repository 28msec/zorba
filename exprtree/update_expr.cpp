/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: update_expr.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "update_expr.h"

using namespace std;
namespace xqp {
  
/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Update productions                                                 //
//  [http://www.w3.org/TR/xqupdate/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

// [242] [http://www.w3.org/TR/xqupdate/#prod-xquery-InsertExpr]

insert_expr::insert_expr(
	yy::location const& loc,
	context * ctx,
	rchandle<expr> _source_expr_h,
	rchandle<expr> _target_expr_h)
:
	expr(loc,ctx),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

insert_expr::~insert_expr()
{
}

ostream& insert_expr::put(ostream& os) const
{
	return os << "insert_expr[]\n";
}



// [243] [http://www.w3.org/TR/xqupdate/#prod-xquery-DeleteExpr]

delete_expr::delete_expr(
	yy::location const& loc,
	context * ctx,
	rchandle<expr> _target_expr_h)
:
	expr(loc,ctx),
	target_expr_h(_target_expr_h)
{
}

delete_expr::~delete_expr()
{
}

ostream& delete_expr::put(ostream& os) const
{
	return os << "delete_expr[]\n";
}



// [244] [http://www.w3.org/TR/xqupdate/#prod-xquery-ReplaceExpr]

replace_expr::replace_expr(
	yy::location const& loc,
	context * ctx,
	rchandle<expr> _source_expr_h,
	rchandle<expr> _target_expr_h)
:
	expr(loc,ctx),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

replace_expr::~replace_expr()
{
}

ostream& replace_expr::put(ostream& os) const
{
	return os << "replace_expr[]\n";
}



// [245] [http://www.w3.org/TR/xqupdate/#prod-xquery-RenameExpr]

rename_expr::rename_expr(
	yy::location const& loc,
	context * ctx,
	rchandle<expr> _source_expr_h,
	rchandle<expr> _target_expr_h)
:
	expr(loc,ctx),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

rename_expr::~rename_expr()
{
}

ostream& rename_expr::put(ostream& os) const
{
	return os << "rename_expr[]\n";
}



// [249] [http://www.w3.org/TR/xqupdate/#prod-xquery-TransformExpr]

transform_expr::transform_expr(
	yy::location const& loc,
	context * ctx,
	rchandle<expr> _source_expr_h,
	rchandle<expr> _target_expr_h)
:
	expr(loc,ctx),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

transform_expr::~transform_expr()
{
}

ostream& transform_expr::put(ostream& os) const
{
	return os << "transform_expr[]\n";
}

  
} /* namespace xqp */

