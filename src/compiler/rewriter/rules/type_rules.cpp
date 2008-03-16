#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "types/root_typemanager.h"
#include "types/typemanager.h"
#include "system/globalenv.h"

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (rCtx.getStaticContext()->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) static_cast<function *> (rCtx.getStaticContext()->lookup_builtin_fn (":" local, 1))

using namespace std;

namespace zorba {

RULE_REWRITE_PRE(EliminateTypeEnforcingOperations)
{
  TypeManager *ts = rCtx.getStaticContext()->get_typemanager();
  fo_expr *fo;

  if ((fo = dynamic_cast<fo_expr *>(node)) != NULL) {
    function *fnboolean = LOOKUP_FN("fn", "boolean", 1);
    if (fo->get_func() == fnboolean) {
      expr_t arg = (*fo)[0];
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (ts->is_subtype(*arg_type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
        return arg;
      else return NULL;
    }
    function *fndata = LOOKUP_FN("fn", "data", 1);
    if (fo->get_func() == fndata) {
      expr_t arg = (*fo)[0];
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (ts->is_subtype(*arg_type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
        return arg;
      else return NULL;
    }
  }
  cast_base_expr *pe;
  if ((pe = dynamic_cast<cast_base_expr *>(node)) != NULL) {
    expr_t arg = pe->get_input();
    xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
    if (ts->is_subtype(*arg_type, *pe->get_target_type()))
      return arg;
    else return NULL;
  }
  castable_base_expr *cbe;
  if ((cbe = dynamic_cast<castable_base_expr *>(node)) != NULL) {
    expr_t arg = cbe->get_expr();
    xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
    if (ts->is_subtype(*arg_type, *cbe->get_type()))
      return new const_expr (node->get_loc (), true);
    else return NULL;
  }

  return NULL;
}

RULE_REWRITE_POST(EliminateTypeEnforcingOperations)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
