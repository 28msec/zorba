#ifndef ZORBA_EXPR_TOOLS_H
#define ZORBA_EXPR_TOOLS_H

#include "common/shared_types.h"

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (rCtx.getStaticContext()->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) static_cast<function *> (rCtx.getStaticContext()->lookup_builtin_fn (":" local, 1))

namespace zorba {

int count_variable_uses(expr *root, var_expr *var);

}

#endif /* ZORBA_EXPR_TOOLS_H */
/* vim:set ts=2 sw=2: */
