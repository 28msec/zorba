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
#ifndef ZORBA_VAR_EXPR_H
#define ZORBA_VAR_EXPR_H

#include "compiler/expression/expr_base.h"

namespace zorba {

/******************************************************************************

  var_expr represents a variable reference within any kind of expression.

*******************************************************************************/

class forlet_clause;

class var_expr : public expr {
public:
  expr_kind_t get_expr_kind () { return var_expr_kind; }

  enum var_kind {
    eval_var,
    for_var,
    let_var,
    pos_var,
    score_var,
    quant_var,
    context_var,
    param_var,
    catch_var,
    copy_var,
    groupby_var,
    non_groupby_var,
    unknown_var  // TODO: get rid
  };

  var_kind kind;
  store::Item_t varname_h;
  xqtref_t type;

public:
  var_expr(const QueryLoc& loc, store::Item_t name);
  var_expr(const QueryLoc& loc, var_kind k, store::Item_t name);

public:
  store::Item_t get_varname() const;

  var_kind get_kind() const { return kind; }
  void set_kind(var_kind k) { kind = k; }

  xqtref_t get_type() const;
  void set_type(xqtref_t t);

public:
  static std::string decode_var_kind(enum var_kind);

public:
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
  std::ostream& put(std::ostream&) const;

  virtual expr_t clone(substitution_t& substitution);
  virtual xqtref_t return_type_impl (static_context *);

  void set_forlet_clause(forlet_clause *flclause) { m_forlet_clause = flclause; }
  forlet_clause *get_forlet_clause() { return m_forlet_clause; }

protected:
  forlet_clause *m_forlet_clause;
};

  typedef rchandle<var_expr> varref_t;

}

#endif  // ZORBA_VAR_EXPR_H

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
