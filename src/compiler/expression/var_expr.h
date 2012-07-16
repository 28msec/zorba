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
#ifndef ZORBA_COMPILER_VAR_EXPR
#define ZORBA_COMPILER_VAR_EXPR

#include "compiler/expression/expr_base.h"

namespace zorba
{

class flwor_clause;
class forletwin_clause;
class for_clause;
class copy_clause;
class var_expr;

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

  theUniqueId:
  ------------
  A unique numeric id for variales whose value is stored in the dynamic context,
  ie, prolog and local vars. It is used as an index into an array that stores
  the values.

  theKind:
  --------
  The kind of the variable (see var_kind enum below)

  theVarName:
  -----------
  The fully expanded qname of the var (qname item)

  theDeclaredType:
  ----------------
  The type, if any, specified in the declaration of the variable

  theFlworClause:
  ---------------
  If this is a var declared in flwor clause, theFlworClause points to the
  defining clause. That clause also contains the defining expr for the var
  and a pointer back to this var_exr.

  theCopyClause:
  --------------
  If this is a var declared in a copy clause of a transform expr, theCopyClause
  points to that clause. That clause contains the defining expr for the var and
  a pointer back to this var_exr.

  theParamPos:
  ------------
  For arg vars, it is the position, within the param list, of parameter that is
  bound to this arg var.

  theUDF:
  -------
  For arg vars, the corresponding UDF.

  theSetExprs:
  ------------
  For global and local vars, this vector contains a pointer to the var_decl_expr
  for the variable and to each var_set_expr for the same var.

  theIsExternal:
  --------------
  Whether this is an external variable or not (for prolog vars only).

  theIsPrivate:
  -------------
  Whether this is a private variable or not (for prolog vars only).

  theIsMutable:
  -------------
  Whether this is a mutable variable or not (for prolog and local vars).

  theHasInitializer:
  ------------------
   Whether the variable has an initializing expr or not (for prolog vars only).
*******************************************************************************/
class var_expr : public expr
{
  friend class expr;
  friend class ExprManager;

public:
  enum var_kind
  {
    eval_var = 0,

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
  ulong                 theUniqueId;

  var_kind              theVarKind;

  store::Item_t         theName;

  xqtref_t              theDeclaredType;

  flwor_clause        * theFlworClause;

  copy_clause         * theCopyClause;

  csize                 theParamPos;

  user_function       * theUDF;

  std::vector<expr*>    theSetExprs;

  bool                  theIsExternal;

  bool                  theIsPrivate;

  bool                  theIsMutable;

  bool                  theHasInitializer;

public:
  void serialize(::zorba::serialization::Archiver& ar);

  void serialize_internal(::zorba::serialization::Archiver& ar);

  serialization::TypeCode get_serializer_type_code() const
  {
    return serialization::TYPE_var_expr;
  }

  class class_factory : public ::zorba::serialization::ClassDeserializer
  {
  public:
    class_factory()
    {
      serialization::ClassSerializer::getInstance()->
      register_class_factory(serialization::TYPE_var_expr, this);
    }

    serialization::SerializeBaseClass* create_new(serialization::Archiver& ar);
  };

  static class_factory g_class_factory;

public:
  static std::string decode_var_kind(enum var_kind);

protected:
  var_expr(
      CompilerCB* ccb,
      static_context* sctx,
      const QueryLoc& loc,
      var_kind k,
      store::Item* name);

  var_expr(const var_expr& source);

  var_expr(::zorba::serialization::Archiver& ar);

public:
  ulong get_unique_id() const { return theUniqueId; }

  void set_unique_id(ulong v) { assert(theUniqueId == 0); theUniqueId = v; }

  store::Item* get_name() const;

  var_kind get_kind() const { return theVarKind; }

  void set_kind(var_kind k) { theVarKind = k; }

  bool is_private() const { return theIsPrivate; }

  void set_private(bool v) { theIsPrivate = v; }

  bool is_external() const { return theIsExternal; }

  void set_external(bool v) { theIsExternal = v; }

  bool hasInitializer() const { return theHasInitializer; }

  void setHasInitializer(bool v) { theHasInitializer = v; }

  bool is_mutable() const { return theIsMutable; }

  void set_mutable(bool v) { theIsMutable = v; }

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

  csize get_param_pos() const { return theParamPos; }

  void set_param_pos(csize pos) { theParamPos = pos; }

  user_function* get_udf() const { return theUDF; }

  void set_udf(const user_function* udf) { theUDF = const_cast<user_function*>(udf); }

  void add_set_expr(expr* e) { theSetExprs.push_back(e); }

  void remove_set_expr(expr* e);

  std::vector<expr*>::const_iterator setExprsBegin() const { return theSetExprs.begin(); }

  std::vector<expr*>::const_iterator setExprsEnd() const { return theSetExprs.end(); }

  bool is_context_item() const;

  void compute_scripting_kind();

  expr* clone(substitution_t& subst) const;

  void accept(expr_visitor&);

  std::ostream& put(std::ostream&) const;
};


struct GlobalBinding
{
  var_expr*  theVar;
  expr*      theExpr;
  bool        theIsExternal;

public:
  GlobalBinding() : theIsExternal(false) {}

  GlobalBinding(var_expr* v, expr* e, bool external)
    :
    theVar(v),
    theExpr(e),
    theIsExternal(external)
  {
  }

  virtual ~GlobalBinding() {}

  bool is_extern() const { return theIsExternal; }
};


}

#endif  // ZORBA_VAR_EXPR_H

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
