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
#ifndef ZORBA_COMPILER_JSON_EXPRS
#define ZORBA_COMPILER_JSON_EXPRS

#include <string>
#include <vector>

#include <zorba/store_consts.h>

#include "compiler/expression/expr_base.h"

#ifdef ZORBA_WITH_JSON


namespace zorba
{

/*******************************************************************************
  ArrayConstructor ::= "[" Expr? "]"
********************************************************************************/
class json_array_expr : public expr
{
  friend class ExprIterator;
  friend class ExprManager;

protected:
  expr * theContentExpr;

protected:
  json_array_expr(
      CompilerCB* ccb,
      static_context* sctx,
      const QueryLoc& loc,
      expr* content);

public:
  expr* get_expr() const { return theContentExpr.getp(); }

  void compute_scripting_kind();

  expr* clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  SimpleObjectUnion ::= "{|" Expr? "|}"

  AccumulatorObjectUnion ::= "{[" Expr? "]}"

  The Expr must return a sequence of zero or more objects
********************************************************************************/
class json_object_expr : public expr
{
  friend class ExprIterator;
  friend class ExprManager;

protected:
  expr  * theContentExpr;
  bool    theAccumulate;

protected:
  json_object_expr(
      CompilerCB* ccb,
      static_context* sctx,
      const QueryLoc& loc,
      expr* content,
      bool accumulate);

public:
  expr* get_expr() const { return theContentExpr.getp(); }

  bool is_accumulating() const { return theAccumulate; }

  void compute_scripting_kind();

  expr* clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


/*******************************************************************************
  DirectObjectConstructor ::= "{" PairConstructor ("," PairConstructor )* "}"

  PairConstructor ::= ExprSingle ":" ExprSingle

  The 1st ExprSingle must return exactly one string.
  The 2nd ExprSingle must contain exactly one item of any kind.
********************************************************************************/
class json_direct_object_expr : public expr
{
  friend class ExprIterator;
  friend class ExprManager;

protected:
  std::vector<expr*>  theNames;
  std::vector<expr*>  theValues;

protected:
  json_direct_object_expr(
      CompilerCB* ccb,
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<expr*>& names,
      std::vector<expr*>& values);

public:
  csize num_pairs() const { return theNames.size(); }

  expr* get_value_expr(csize i) const { return theValues[i].getp(); }

  expr* get_name_expr(csize i) const { return theNames[i].getp(); }

  void compute_scripting_kind();

  expr* clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};



}

#endif // ZORBA_WITH_JSON

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
