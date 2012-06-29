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

protected:
  expr_t  theContentExpr;

public:
  SERIALIZABLE_CLASS(json_array_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(json_array_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  json_array_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& content);

  expr* get_expr() const { return theContentExpr.getp(); }

  void compute_scripting_kind();

  expr_t cloneImpl(substitution_t& s) const;

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

protected:
  expr_t  theContentExpr;
  bool    theAccumulate;

public:
  SERIALIZABLE_CLASS(json_object_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(json_object_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  json_object_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& content,
      bool accumulate);

  expr* get_expr() const { return theContentExpr.getp(); }

  bool is_accumulating() const { return theAccumulate; }

  void compute_scripting_kind();

  expr_t cloneImpl(substitution_t& s) const;

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

protected:
  std::vector<expr_t>  theNames;
  std::vector<expr_t>  theValues;

public:
  SERIALIZABLE_CLASS(json_direct_object_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(json_direct_object_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  json_direct_object_expr(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<expr_t>& names,
      std::vector<expr_t>& values);

  csize num_pairs() const { return theNames.size(); }

  expr* get_value_expr(csize i) const { return theValues[i].getp(); }

  expr* get_name_expr(csize i) const { return theNames[i].getp(); }

  void compute_scripting_kind();

  expr_t cloneImpl(substitution_t& s) const;

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
