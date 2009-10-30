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
        expr_t arg);

  fo_expr(
        short sctx,
        const QueryLoc& loc,
        const function* f,
        expr_t arg1,
        expr_t arg2);

  fo_expr(
        short sctx,
        const QueryLoc& loc,
        const function* f,
        const std::vector<expr_t>& args);

  expr_kind_t get_expr_kind() const { return fo_expr_kind; }

  bool cache_compliant() const { return true; }

  const function* get_func() const { return theFunction; }

  function* get_func() { invalidate(); return theFunction; }

  void set_func(function* f) { invalidate(); theFunction = f; }

  const signature& get_signature() const;

  const store::Item* get_fname() const;

  uint32_t num_args() const { return theArgs.size(); }

  expr_t& operator[](int i) { invalidate(); return theArgs[i]; }

  const expr_t& operator[](int i) const { return theArgs[i]; }

  std::vector<expr_t>::const_iterator begin() const { return theArgs.begin(); }

  std::vector<expr_t>::const_iterator end() const { return theArgs.end(); }

  expr_iterator_data* make_iter();

  void next_iter(expr_iterator_data&);

  xqtref_t return_type_impl(static_context*) const;

  void compute_scripting_kind() const;

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
/* vim:set ts=2 sw=2: */

