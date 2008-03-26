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

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (GENV.getRootStaticContext ().lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) static_cast<function *> (GENV.getRootStaticContext ().lookup_builtin_fn (":" local, 1))
#define LOOKUP_OP2( local ) static_cast<function *> (GENV.getRootStaticContext ().lookup_builtin_fn (":" local, 2))
#define LOOKUP_OP3( local ) static_cast<function *> (GENV.getRootStaticContext ().lookup_builtin_fn (":" local, 3))
#define LOOKUP_OPN( local ) static_cast<function *> (GENV.getRootStaticContext ().lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

#define LOC( expr ) (expr)->get_loc ()
namespace zorba {

typedef rchandle<var_expr> varref_t;

typedef std::set<var_expr *> var_ptr_set;

class VarSetAnnVal : public AnnotationValue {
public:
  var_ptr_set varset;

  VarSetAnnVal () {}
  VarSetAnnVal (var_ptr_set varset_) : varset (varset_) {}
  void add (var_expr *v) { varset.insert (varset.begin (), v); }
};
  
const var_ptr_set &get_varset_annotation (const expr *e, Annotation::key_t k);

int count_variable_uses(expr *root, var_expr *var, int limit);

// copy annotations when wrapping an expression in a new one
inline expr_t fix_annotations (expr_t new_expr, expr *old_expr = NULL) {
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
      set_union (old_set.begin (), old_set.end (), new_set.begin (), new_set.end (), inserter (s, s.begin ()));
      new_expr->put_annotation (k, Annotation::value_ref_t (new VarSetAnnVal (s)));
    } else {
      Annotation::value_ref_t v = old_expr->get_annotation (k);
      
      if (v != NULL)
        new_expr->put_annotation (k, v);
    }
  }
  
  return new_expr;
}

inline expr_t fix_if_annotations (rchandle<if_expr> ite) {
  fix_annotations (&*ite, ite->get_cond_expr ());
  fix_annotations (&*ite, ite->get_then_expr ());
  fix_annotations (&*ite, ite->get_else_expr ());
  return &*ite;
}

}

#endif /* ZORBA_EXPR_TOOLS_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
