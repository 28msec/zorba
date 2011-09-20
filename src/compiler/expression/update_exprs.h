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
#ifndef ZORBA_COMPILER_UPDATE_EXPRS
#define ZORBA_COMPILER_UPDATE_EXPRS

#include "store/api/update_consts.h"

#include "compiler/expression/expr_base.h"


namespace zorba 
{


/////////////////////////////////////////////////////////////////////////
//                                                                     //
//	Update expressions                                                 //
//  [http://www.w3.org/TR/xqupdate/]                                   //
//                                                                     //
/////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
class insert_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  store::UpdateConsts::InsertType theType;
	expr_t                          theSourceExpr;
	expr_t                          theTargetExpr;

public:
  SERIALIZABLE_CLASS(insert_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(insert_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	insert_expr(
    static_context* sctx,
		const QueryLoc&,
    store::UpdateConsts::InsertType,
		expr_t aSourceExpr,
		expr_t aTargetExpr);

  store::UpdateConsts::InsertType getType() const { return theType; }

	expr* getSourceExpr() const { return theSourceExpr.getp(); }

	expr* getTargetExpr() const { return theTargetExpr.getp(); }
  
  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class delete_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
	expr_t theTargetExpr;

public:
  SERIALIZABLE_CLASS(delete_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(delete_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	delete_expr(static_context* sctx, const QueryLoc&, expr_t);

	expr* getTargetExpr() const { return theTargetExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class replace_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  store::UpdateConsts::ReplaceType theType;
	expr_t                           theTargetExpr;
	expr_t                           theReplaceExpr;

public:
  SERIALIZABLE_CLASS(replace_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(replace_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	replace_expr(
    static_context* sctx,
		const QueryLoc&,
    store::UpdateConsts::ReplaceType aType,
		expr_t,
		expr_t);

  store::UpdateConsts::ReplaceType getType() const { return theType; }

	expr* getTargetExpr() const { return theTargetExpr.getp(); }

	expr* getReplaceExpr() const { return theReplaceExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************

********************************************************************************/
class rename_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
	expr_t             theTargetExpr;
	expr_t             theNameExpr;

public:
  SERIALIZABLE_CLASS(rename_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(rename_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	rename_expr(
        static_context* sctx,
        const QueryLoc&,
        expr_t,
        expr_t);

	expr* getTargetExpr() const { return theTargetExpr.getp(); }

	expr* getNameExpr() const { return theNameExpr.getp(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  TransformExpr ::= "copy" "$" VarName ":=" ExprSingle
                    ("," "$" VarName ":=" ExprSingle)*
                    "modify"  ExprSingle "return" ExprSingle
********************************************************************************/
class copy_clause;
typedef rchandle<copy_clause> copy_clause_t;

class copy_clause : public SimpleRCObject
{
  friend class expr;
  friend class transform_expr;
  friend class ExprIterator;

private:
  var_expr_t theVar;
  expr_t     theExpr;

public:
  SERIALIZABLE_CLASS(copy_clause)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(copy_clause, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  copy_clause(var_expr_t aVar, expr_t aExpr);

  ~copy_clause();

  var_expr* getVar()  const { return theVar.getp(); }

  expr* getExpr() const { return theExpr.getp(); }

  copy_clause_t clone(expr::substitution_t& s) const;

  std::ostream& put(std::ostream&) const;
};


class transform_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
	std::vector<copy_clause_t> theCopyClauses;
	expr_t                     theModifyExpr;
	expr_t                     theReturnExpr;

public:
  SERIALIZABLE_CLASS(transform_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(transform_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
	transform_expr(static_context* sctx, const QueryLoc& loc);

	expr_t getModifyExpr() const { return theModifyExpr; }

	expr_t getReturnExpr() const { return theReturnExpr; }

  void setModifyExpr(expr* e);

  void setReturnExpr(expr* e);

	void add_back(copy_clause_t c);

	copy_clause_t const& operator[](int i) const { return theCopyClauses[i]; }

	std::vector<copy_clause_t>::const_iterator begin() const
  { return theCopyClauses.begin(); }

	std::vector<copy_clause_t>::const_iterator end() const
  { return theCopyClauses.end(); }

	size_t size() const { return theCopyClauses.size(); }

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

	std::ostream& put(std::ostream&) const;
};



}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
