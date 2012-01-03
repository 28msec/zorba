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
#ifndef ZORBA_COMPILER_FO_EXPR
#define ZORBA_COMPILER_FO_EXPR

#include "zorbautils/checked_vector.h"

#include "compiler/expression/expr_base.h"

#include "zorbaserialization/class_serializer.h"


namespace zorba
{

class function;
class signature;


/*******************************************************************************
  first-order expressions
********************************************************************************/
class fo_expr : public expr
{
  friend class ExprIterator;
  friend class expr;

protected:
  checked_vector<expr_t>   theArgs;
  function               * theFunction;

public:
  SERIALIZABLE_CLASS(fo_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(fo_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  static fo_expr* create_seq(static_context* sctx, const QueryLoc &);

public:
  fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg);

  fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg1,
    const expr* arg2);

  fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const std::vector<expr_t>& args);

  function* get_func() const { return theFunction; }

  void set_func(function* f) { theFunction = f; }

  const signature& get_signature() const;

  const store::Item* get_fname() const;

  csize num_args() const { return theArgs.size(); }

  expr* get_arg(csize i) const { return theArgs[i].getp(); }

  const std::vector<expr_t>& get_args() const {return theArgs;}

  void set_arg(csize i, expr* e) { theArgs[i] = e; }

  void add_arg(expr_t e);

  void add_args(const std::vector<expr_t> &args);

  void compute_scripting_kind();

  expr_t clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;

private:
  fo_expr(static_context* sctx, const QueryLoc& loc, const function* f);
};

////////// The following expressions in the AST "decay" into an fo_expr ///////

typedef fo_expr additive_expr;
typedef rchandle<additive_expr> additive_expr_t;

typedef fo_expr and_expr;
typedef rchandle<and_expr> and_expr_t;

typedef fo_expr comparison_expr;
typedef rchandle<comparison_expr> comparison_expr_t;

typedef fo_expr enclosed_expr;
typedef rchandle<enclosed_expr> enclosed_expr_t;

typedef fo_expr intersect_except_expr;
typedef rchandle<intersect_except_expr> intersect_except_expr_t;

typedef fo_expr multiplicative_expr;
typedef rchandle<multiplicative_expr> multiplicative_expr_t;

typedef fo_expr or_expr;
typedef rchandle<or_expr> or_expr_t;

typedef fo_expr quantified_expr;
typedef rchandle<quantified_expr> quantified_expr_t;

typedef fo_expr range_expr;
typedef rchandle<range_expr> range_expr_t;

typedef fo_expr unary_expr;
typedef rchandle<unary_expr> unary_expr_t;

typedef fo_expr union_expr;
typedef rchandle<union_expr> union_expr_t;

} // namespace zorba

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
