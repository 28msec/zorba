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
protected:
  checked_vector<expr_t>   theArgs;
  function               * theFunction;
  substitution_t           theSubst;

public:
  SERIALIZABLE_CLASS(fo_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(fo_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  static fo_expr* create_seq(short sctx, const QueryLoc &);

public:
  fo_expr(short sctx, const QueryLoc& loc, const function* f);

  fo_expr(
        short sctx,
        const QueryLoc& loc,
        const function* f,
        const expr* arg);

  fo_expr(
        short sctx,
        const QueryLoc& loc,
        const function* f,
        const expr* arg1,
        const expr* arg2);

  fo_expr(
        short sctx,
        const QueryLoc& loc,
        const function* f,
        const std::vector<expr_t>& args);

  expr_kind_t get_expr_kind() const { return fo_expr_kind; }

  bool cache_compliant() const { return true; }

  const function* get_func() const { return theFunction; }

  function* get_func(bool inv) { if (inv) invalidate(); return theFunction; }

  void set_func(function* f) { theFunction = f; invalidate(); }

  const signature& get_signature() const;

  const store::Item* get_fname() const;

  ulong num_args() const { return theArgs.size(); }

  const expr* get_arg(ulong i) const { return theArgs[i]; }

  expr* get_arg(ulong i, bool inv) { if (inv) invalidate(); return theArgs[i]; }

  void set_arg(ulong i, expr* e) { theArgs[i] = e; invalidate(); }

  xqtref_t return_type_impl(static_context*) const;

  void compute_scripting_kind() const;

  expr_t clone(substitution_t& s) const;

  substitution_t get_substitution() const { return theSubst; }

  expr_iterator_data* make_iter();

  void next_iter(expr_iterator_data&);

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
/* vim:set ts=2 sw=2: */

