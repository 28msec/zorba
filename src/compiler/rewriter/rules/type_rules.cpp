#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "types/root_typemanager.h"
#include "types/typemanager.h"
#include "system/globalenv.h"

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (rCtx.getStaticContext()->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) static_cast<function *> (rCtx.getStaticContext()->lookup_builtin_fn (":" local, 1))

namespace zorba {

RULE_REWRITE_PRE(EliminateTypeEnforcingOperations)
{
  fo_expr *fo;
  if ((fo = dynamic_cast<fo_expr *>(node)) != NULL) {
    function *fnboolen = LOOKUP_FN("fn", "boolean", 1);
    if (fo->get_func() == fnboolen) {
      expr_t arg = (*fo)[0];
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (rCtx.getStaticContext()->get_typemanager()->is_subtype(*arg_type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)) {
        return arg;
      }
    }
    function *fndata = LOOKUP_FN("fn", "data", 1);
    if (fo->get_func() == fndata) {
      expr_t arg = (*fo)[0];
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (rCtx.getStaticContext()->get_typemanager()->is_subtype(*arg_type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR)) {
        return arg;
      }
    }
  }
  cast_base_expr *pe;
  if ((pe = dynamic_cast<cast_base_expr *>(node)) != NULL) {
    expr_t arg = pe->get_input();
    xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
    if (rCtx.getStaticContext()->get_typemanager()->is_subtype(*arg_type, *pe->get_target_type())) {
      return arg;
    }
  }
  return NULL;
}

RULE_REWRITE_POST(EliminateTypeEnforcingOperations)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
