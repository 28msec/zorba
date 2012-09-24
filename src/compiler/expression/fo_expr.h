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
  friend class ExprManager;

protected:
  checked_vector<expr*>    theArgs;
  function               * theFunction;

public:

protected:
  static fo_expr* create_seq(CompilerCB* ccb, static_context* sctx, const QueryLoc&);

protected:
  fo_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    expr* arg);

  fo_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    expr* arg1,
    expr* arg2);

  fo_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const std::vector<expr*>& args);

public:
  function* get_func() const { return theFunction; }

  void set_func(function* f) { theFunction = f; }

  const signature& get_signature() const;

  const store::Item* get_fname() const;

  csize num_args() const { return theArgs.size(); }

  expr* get_arg(csize i) const { return theArgs[i]; }

  const std::vector<expr*>& get_args() const { return theArgs; }

  void set_arg(csize i, expr* e) { theArgs[i] = e; }

  void add_arg(expr* e);

  void add_args(const std::vector<expr*>& args);

  void remove_arg(csize i);

  void compute_scripting_kind();

  expr* clone(substitution_t& s) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;

private:
  fo_expr(CompilerCB* ccb, static_context* sctx, const QueryLoc& loc, const function* f);
};


////////// The following expressions in the AST "decay" into an fo_expr ///////

typedef fo_expr additive_expr;

typedef fo_expr and_expr;

typedef fo_expr comparison_expr;

typedef fo_expr enclosed_expr;

typedef fo_expr intersect_except_expr;

typedef fo_expr multiplicative_expr;

typedef fo_expr or_expr;

typedef fo_expr quantified_expr;

typedef fo_expr range_expr;

typedef fo_expr unary_expr;

typedef fo_expr union_expr;

} // namespace zorba

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
