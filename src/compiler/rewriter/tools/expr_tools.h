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
#ifndef ZORBA_EXPR_TOOLS_H
#define ZORBA_EXPR_TOOLS_H

#include "common/shared_types.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/expression/expr.h"
#include "functions/signature.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "system/globalenv.h"

#include <set>
#include <algorithm>

#define LOOKUP_FN( pfx, local, arity ) (GENV.getRootStaticContext ().lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) (GENV.getRootStaticContext ().lookup_builtin_fn (":" local, 1))
#define LOOKUP_OP2( local ) (GENV.getRootStaticContext ().lookup_builtin_fn (":" local, 2))
#define LOOKUP_OP3( local ) (GENV.getRootStaticContext ().lookup_builtin_fn (":" local, 3))
#define LOOKUP_OPN( local ) (GENV.getRootStaticContext ().lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))
#define LOOKUP_RESOLVED_FN( ns, local, arity ) (GENV.getRootStaticContext().lookup_resolved_fn(ns, local, arity))

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

#define LOC( expr ) (expr)->get_loc ()


namespace zorba 
{

typedef std::set<var_expr *> var_ptr_set;


class VarSetAnnVal : public AnnotationValue 
{
public:
  var_ptr_set varset;

  VarSetAnnVal () {}
  VarSetAnnVal (var_ptr_set varset_) : varset (varset_) {}
  void add (var_expr *v) { varset.insert (varset.begin (), v); }
};
  

const var_ptr_set& get_varset_annotation(const expr *e, Annotation::key_t k);


int count_variable_uses(expr *root, var_expr *var, int limit);


/*******************************************************************************
  copy annotations when wrapping an expression in a new one
********************************************************************************/
inline expr_t fix_annotations (expr_t new_expr, expr *old_expr = NULL) 
{
  if (old_expr == NULL) {
    switch (new_expr->get_expr_kind ()) {
    case fo_expr_kind:
      old_expr = (*new_expr.dyn_cast<fo_expr> ().getp ()) [0];
      break;
    default:
      assert (false); return NULL;
    }
  }
  
  for (Annotation::key_t k = 0; k < AnnotationKey::MAX_ANNOTATION; k++) {
    if (k == AnnotationKey::FREE_VARS) {
      const var_ptr_set & old_set = get_varset_annotation (old_expr, AnnotationKey::FREE_VARS),
        &new_set = get_varset_annotation (old_expr, AnnotationKey::FREE_VARS);
      var_ptr_set s;
      std::set_union (old_set.begin (), old_set.end (), new_set.begin (), new_set.end (), inserter (s, s.begin ()));
      new_expr->put_annotation (k, Annotation::value_ref_t (new VarSetAnnVal (s)));
    } else {
      Annotation::value_ref_t v = old_expr->get_annotation (k);
      
      if (v != NULL)
        new_expr->put_annotation (k, v);
    }
  }
  
  return new_expr;
}


inline expr_t fix_if_annotations (rchandle<if_expr> ite) 
{
  fix_annotations (&*ite, ite->get_cond_expr ());
  fix_annotations (&*ite, ite->get_then_expr ());
  fix_annotations (&*ite, ite->get_else_expr ());
  return &*ite;
}


inline bool is_data(expr *e)
{
  return (e->get_expr_kind() == fo_expr_kind &&
          static_cast<fo_expr *>(e)->get_func() == LOOKUP_FN("fn", "data", 1));
}


inline expr* get_fo_arg(expr* e, int arg_idx)
{
  ZORBA_ASSERT(e != NULL && e->get_expr_kind() == fo_expr_kind);
  return (*static_cast<fo_expr *>(e))[arg_idx];
}

}

#endif /* ZORBA_EXPR_TOOLS_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
