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
#ifndef ZORBA_REWRITER_EXPR_TOOLS_H
#define ZORBA_REWRITER_EXPR_TOOLS_H

#include "common/shared_types.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/rewriter/framework/rewriter_context.h"

#include "functions/function.h"

#include "store/api/item_factory.h"
#include "system/globalenv.h"

#include <set>
#include <algorithm>

#define LOOKUP_FN( pfx, local, arity ) \
(GENV.getRootStaticContext().lookup_fn (pfx, local, arity))

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

#define LOC(expr) (expr)->get_loc ()



namespace zorba
{

namespace expr_tools
{

int count_variable_uses(
    const expr* root,
    const var_expr* var,
    RewriterContext* rCtx,
    int limit);


/*******************************************************************************

********************************************************************************/
expr* fix_annotations(expr* new_expr, const expr* old_expr = NULL);


/*******************************************************************************
  Util functions used by rules: HoistExprsOutOfLoops and IndexJoin.
********************************************************************************/

void index_flwor_vars(const expr*, ulong&, VarIdMap&, IdVarMap*);

void build_expr_to_vars_map(expr*, const VarIdMap&, DynamicBitset&, ExprVarsMap&);

void replace_var(expr*, const var_expr* oldVar, var_expr* newVar);


/*******************************************************************************

********************************************************************************/
inline bool is_data(expr* e)
{
  return (e->get_expr_kind() == fo_expr_kind &&
          static_cast<fo_expr *>(e)->get_func()->getKind() == FunctionConsts::FN_DATA_1);
}


}
}

#endif /* ZORBA_EXPR_TOOLS_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
