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

#ifndef ZORBA_GFLWOR_EXPR_H
#define ZORBA_GFLWOR_EXPR_H

#include "compiler/expression/expr_base.h"
#include "compiler/expression/flwor_expr.h"

namespace zorba {

class gflwor_clause : public flwor_clause {
public:
  typedef std::vector<std::pair <varref_t, varref_t> > rebind_list_t;

protected:
  QueryLoc loc;

public:
  gflwor_clause (const QueryLoc &loc_) : loc (loc_) {}
  const QueryLoc &get_loc () const { return loc; }
};

class forletwin_gclause;

class flwor_wincond {
public:
  struct vars {
    varref_t posvar, curr, prev, next;
    void set_forlet_clause (forletwin_gclause *c);

    std::ostream& put(std::ostream&) const;
  };
protected:
  friend class gflwor_expr;

  bool isOnly;
  vars in_vars, out_vars;
  expr_t cond;

public:
  flwor_wincond (bool isOnly_, vars in_vars_, vars out_vars_, expr_t cond_)
    : isOnly (isOnly_), in_vars (in_vars_), out_vars (out_vars_), cond (cond_)
  {}
  expr_t get_cond() const { return cond; }
  bool is_only () const { return isOnly; }

  const vars &get_in_vars () const { return in_vars; }
  const vars &get_out_vars () const { return out_vars; }

  void set_forlet_clause (forletwin_gclause *);

  std::ostream& put(std::ostream&) const;
};

class forletwin_gclause : public flwor_initial_clause {
  friend class gflwor_expr;

public:
  enum forlet_t {
    for_clause,
    let_clause,
    win_clause
  };

  typedef enum { tumbling_window, sliding_window } window_t;

public: // state
  enum forlet_t type;
  window_t wintype;
  varref_t pos_var_h;
  varref_t score_var_h;
  std::auto_ptr<flwor_wincond> win_start, win_stop;
  bool outer;

public: // ctor,dtor
  forletwin_gclause(enum forlet_t _type,
                    varref_t _var_h,
                    expr_t _expr_h,
                    varref_t _pos_var_h = NULL,
                    varref_t _score_var_h = NULL,
                    window_t wintype_ = tumbling_window,
                    std::auto_ptr<flwor_wincond> win_start_ = std::auto_ptr<flwor_wincond> (NULL),
                    std::auto_ptr<flwor_wincond> win_stop_ = std::auto_ptr<flwor_wincond> (NULL));
  ~forletwin_gclause() {
    if (win_start.get () != NULL)
      win_start->set_forlet_clause (NULL);
    if (win_stop.get () != NULL)
      win_stop->set_forlet_clause (NULL);
  }

public: // accessors
  enum forlet_t get_type() const { return type; }
  window_t get_wintype() const { return wintype; }
  varref_t get_pos_var() const { return pos_var_h; }
  varref_t get_score_var() const { return score_var_h; }
  bool is_outer () const { return outer; }
  const flwor_wincond *get_win_start () const { return win_start.get (); }
  const flwor_wincond *get_win_stop () const { return win_stop.get (); }

  void set_type(enum forlet_t v) { type = v; }
  void set_outer (bool outer_) { outer = outer_; }
  void set_pos_var(varref_t v) { pos_var_h = v; if (pos_var_h != NULL) { pos_var_h->set_forlet_clause(this); } }
  void set_score_var(varref_t v) { score_var_h = v; if (score_var_h != NULL) { score_var_h->set_forlet_clause(this); } }

public:
  std::ostream& put(std::ostream&) const;
};

class where_gclause : public gflwor_clause {
  friend class gflwor_expr;

  expr_t where;

public:
  where_gclause (const QueryLoc &loc_, expr_t where_) : gflwor_clause (loc_), where (where_) {}
  expr_t get_where () const { return where; }
  void set_where (expr_t where_) { where = where_; }
};

class count_gclause : public gflwor_clause {
  varref_t var;

public:
  count_gclause (const QueryLoc &loc_, varref_t var_) : gflwor_clause (loc_), var (var_)
  {}
  varref_t get_var () const { return var; }
};

class orderby_gclause : public gflwor_clause {

protected:
  friend class gflwor_expr;

  ParseConstants::dir_spec_t dir;
  StaticContextConsts::order_empty_mode_t empty_mode;
  std::string collation;
  bool stable;
  expr_t order;

  rebind_list_t rebind_list;

public:
  orderby_gclause (const QueryLoc &loc_, ParseConstants::dir_spec_t _dir, StaticContextConsts::order_empty_mode_t _empty_mode, std::string _collation, bool stable_, expr_t order_)
    : gflwor_clause (loc_), dir (_dir), empty_mode (_empty_mode), collation (_collation), stable (stable_),
      order (order_)
  {}
  ParseConstants::dir_spec_t get_dir () const { return dir; }
  StaticContextConsts::order_empty_mode_t get_empty_mode () const { return empty_mode; }
  std::string get_collation () const { return collation; }
  bool is_stable () const { return stable; }
  expr_t get_expr () { return order; }
  void set_expr (expr_t e_) { order = e_; }
  const rebind_list_t &get_rebind () const { return rebind_list; }
  void init_clauses ();
  void set_rebind (const rebind_list_t &rebind_list_) {
    rebind_list = rebind_list_;
  }

public:
  std::ostream& put(std::ostream&) const;
};

class group_gclause : public gflwor_clause {
  friend class gflwor_expr;

protected:
  rebind_list_t inner_rebind, outer_rebind;
  std::vector<std::string> theCollations;

public:
  group_gclause(const QueryLoc &loc_, const rebind_list_t &inner_rebind_, rebind_list_t outer_rebind_, const std::vector<std::string> &aCollations_)
    : gflwor_clause (loc_), inner_rebind (inner_rebind_), outer_rebind (outer_rebind_), theCollations(aCollations_) {}

  const std::vector<std::string> &getCollations() const { return theCollations; }
  const rebind_list_t &get_inner_rebind () const { return inner_rebind; }
  const rebind_list_t &get_outer_rebind () const { return outer_rebind; }
  
public:
  std::ostream& put(std::ostream&) const;

  // TODO clone?
};

class gflwor_expr : public expr {
public:
  typedef std::vector<rchandle<flwor_clause> > clause_list_t;
protected:
  clause_list_t clauses;
  expr_t retval_h;

public:
  int size () const { return clauses.size (); }
  rchandle<flwor_clause> operator[] (int i) { return clauses [i]; }
  const flwor_clause *operator[] (int i) const { return clauses [i].getp (); }
  void push_back (rchandle<flwor_clause> c);

public:
  gflwor_expr (const QueryLoc &loc_, expr_t retval_) : expr (loc_), retval_h (retval_) {}
  clause_list_t::const_iterator clause_begin () const { return clauses.begin (); }
  clause_list_t::const_iterator clause_end () const { return clauses.end (); }

  expr_iterator_data *make_iter ();
  void next_iter (expr_iterator_data&);
  void accept (expr_visitor&);
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
