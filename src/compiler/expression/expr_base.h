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
#ifndef ZORBA_EXPR_BASE_H
#define ZORBA_EXPR_BASE_H

#include "common/common.h"
#include "common/shared_types.h"

#include "context/static_context_consts.h"

#include "compiler/parser/query_loc.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/expression/expr_consts.h"
#include "compiler/semantic_annotations/annotation_holder.h"

namespace zorba {

enum expr_kind_t {
  expr_kind,
  wrapper_expr_kind,
  sequential_expr_kind,
  exit_expr_kind,
  flowctl_expr_kind,
  while_expr_kind,
  constructor_expr_kind,
  var_expr_kind,
  flwor_expr_kind,
  trycatch_expr_kind,
  promote_expr_kind,
  typeswitch_expr_kind,
  if_expr_kind,
  function_def_expr_kind,
  fo_expr_kind,
  ft_contains_expr_kind,
  instanceof_expr_kind,
  treat_expr_kind,
  castable_expr_kind,
  cast_expr_kind,
  name_cast_expr_kind,
  validate_expr_kind,
  extension_expr_kind,
  relpath_expr_kind,
  axis_step_expr_kind,
  match_expr_kind,
  const_expr_kind,
  order_expr_kind,
  elem_expr_kind,
  doc_expr_kind,
  attr_expr_kind,
  text_expr_kind,
  pi_expr_kind,
  unknown_expr_kind
};

class expr_visitor;

class expr_iterator_data;
class expr_iterator {
  // should be an auto_ptr, but older gcc's don't like auto_ptr w/ forward decl
  expr_iterator_data *iter;
  // comparisson forbidden; use done()
  bool operator== (const expr_iterator &other) { return false; }

public:
  expr_iterator () : iter (0) {}
  expr_iterator (expr_iterator_data *iter_) : iter (iter_) {}
  expr_iterator (const expr_iterator &other);
  ~expr_iterator ();
  expr_iterator &operator= (const expr_iterator &other);

  expr_iterator &operator++ ();
  expr_iterator operator++ (int);
  expr_t &operator* ();
  bool done () const;
};


/*______________________________________________________________________
 |  
 | base class for the expression tree node hierarchy
 |_______________________________________________________________________*/

class expr : public SimpleRCObject, public AnnotationHolder {
public:
  virtual expr_kind_t get_expr_kind () { return expr_kind; }
  typedef rchandle<expr> expr_t;
  typedef std::map<var_expr *, expr_t> substitution_t;
  typedef substitution_t::iterator subst_iter_t;

protected:
  QueryLoc loc;

  // Pitfall when using the cache -- AVOID THIS SCENARIO:
  // (1) obtain a non-const ptr to a child expression (cache is invalidated)
  // (2) call an operation P() that caches its result
  // (3) modify the child expr (cache is NOT invalidated)
  // (4) call P() again and get (possibly wrong) cached result
  struct {
    struct {
      bool valid;
      xqtref_t t;
      static_context *sctx;
    } type;
  } cache;
  void invalidate () { cache.type.valid = false; }
  // Returns true if all modifiers, as well as all accessors that permit future
  // modifications of child expressions, call invalidate(). Note that expr
  // iterators are compliant.
  virtual bool cache_compliant () { return false; }

protected:
  virtual expr_iterator_data *make_iter ();
  
public:
  expr(const QueryLoc&);
  virtual ~expr();

public:
  const QueryLoc &get_loc() const { return loc; }
  void set_loc(const QueryLoc& aLoc) { loc = aLoc; }

public:
  virtual expr_iterator expr_begin ();
  virtual void accept(expr_visitor&);
  virtual void accept_children(expr_visitor &v);
  virtual void next_iter (expr_iterator_data &) = 0;
  virtual std::ostream& put(std::ostream&) const = 0;
  virtual std::string toString () const;

  virtual xqtref_t return_type(static_context *sctx);
  virtual xqtref_t return_type_impl(static_context *sctx);

  expr_t clone();
  virtual expr_t clone(substitution_t& substitution);

  virtual bool is_updating() { return false; }
};

typedef rchandle<expr> expr_t;

class expr_iterator_data {
protected:
  expr *e;
  
public:
  expr_t *i;
  int state;
  
public:
  expr_iterator_data (expr *e_) : e (e_), i (NULL), state (0) {}
  virtual ~expr_iterator_data () {}
  virtual void next () {
    e->next_iter (*this);
  }
  bool done () const;
};

} /* namespace zorba */
#endif  /*  ZORBA_EXPR_BASE_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
