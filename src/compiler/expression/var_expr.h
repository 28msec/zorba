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
#ifndef ZORBA_COMPILER_VAR_EXPR_H
#define ZORBA_COMPILER_VAR_EXPR_H

#include "compiler/expression/expr_base.h"

#include "zorbaserialization/class_serializer.h"

namespace zorba {

class flwor_clause;
class forletwin_clause;
class for_clause;
class copy_clause;
class var_expr;

typedef rchandle<var_expr> varref_t;
typedef rchandle<var_expr> var_expr_t;


/******************************************************************************

  var_expr represents a variable. There is one var_expr for each distinct
  variable declared anywhere inside a query body or prolog. 

  var_expr represents both the var declaration and all references of the var.
  However, each distinct reference to a var is wrapped in wrapper_expr. For
  example, the exprs F($x) and G($x) are modelled in the expr tree as:

       F               G
       |               |
   wrapper_expr    wrapper_expr 
         \             /
          \           /
           var_expr($x)
  

  For context vars with a defining expr, the mapping between the var qname and
  the defining expr is explicitly stored by creating an 
  fn:ctxvar-assign(qname_expr, def_expr) expr (see method
  wrap_in_globalvar_assign() in translator.cpp).

  For vars declared in FOR, LET, or WINDOW clauses, their defining expr is
  stored in the associated clause (see theForletClause data member below).

  theKind        : The kind of the variable (see var_kind enum below)
  theVarName     : The fully expanded qname of the var (qname item) 
  theStaticType  : The static type of the variable
  theFlworClause : If this is a var declared in flwor clause, theFlworClause
                   points to the defining clause. That clause also contains
                   the defining expr for the var and a pointer back to this
                   var_exr. 
  theCopyClause  : If this is a var declared in a copy clause of a transform
                   expr, theCopyClause points to that clause. That clause 
                   contains the defining expr for the var and a pointer back
                   to this var_exr. 
*******************************************************************************/
class var_expr : public expr 
{
  friend class expr;

public:
  enum var_kind 
  {
    eval_var,

    for_var,
    let_var,
    pos_var,
    win_var,
    score_var,
    wincond_out_var,
    wincond_out_pos_var,
    wincond_in_var,
    wincond_in_pos_var,
    count_var,
    groupby_var,
    non_groupby_var,

    copy_var,

    catch_var,
    
    prolog_var,

    local_var,

    arg_var,

    unknown_var  // TODO: get rid
  };

protected:
  static ulong   theVarCounter;

  ulong          theUniqueId;

  var_kind       theKind;
  store::Item_t  theName;
  xqtref_t       theDeclaredType;

  flwor_clause * theFlworClause;
  copy_clause  * theCopyClause;

public:
  SERIALIZABLE_CLASS(var_expr)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(var_expr, expr)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  static std::string decode_var_kind(enum var_kind);

public:
  var_expr(
        static_context* sctx,
        const QueryLoc& loc,
        var_kind k,
        store::Item* name);

  ulong get_unique_id() const { return theUniqueId; }

  store::Item* get_name() const;

  var_kind get_kind() const { return theKind; }

  void set_kind(var_kind k) { theKind = k; }

  xqtref_t get_type() const;

  void set_type(xqtref_t t);

  void set_flwor_clause(flwor_clause* c) { theFlworClause = c; }

  flwor_clause* get_flwor_clause() const { return theFlworClause; }

  forletwin_clause* get_forletwin_clause() const;

  for_clause* get_for_clause() const;

  copy_clause* get_copy_clause() const { return theCopyClause; }

  void set_copy_clause(copy_clause* c) { theCopyClause = c; }

  expr* get_domain_expr() const;

  const var_expr* get_pos_var() const;

  void compute_scripting_kind();

  expr_t clone(substitution_t& subst) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


struct global_binding : public std::pair<varref_t, expr_t>,
                        public ::zorba::serialization::SerializeBaseClass
{
  bool ext;

public:
  SERIALIZABLE_CLASS(global_binding)
  SERIALIZABLE_CLASS_CONSTRUCTOR(global_binding)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  global_binding() : ext(false) {}

  global_binding(varref_t v, expr_t e, bool ext_)
    :
    std::pair<varref_t, expr_t> (v, e),
    ext (ext_)
  {
  }

  virtual ~global_binding() {}

  bool is_extern() const { return ext; }
};

}

#endif  // ZORBA_VAR_EXPR_H

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
