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

#include "system/globalenv.h"

#include "functions/VarDecl.h"

#include "compiler/expression/expr.h"

#include "runtime/core/var_iterators.h"
#include "runtime/core/item_iterator.h"

#include "store/api/iterator.h"

namespace zorba
{

PlanIter_t ctx_variable::codegen (
    CompilerCB* /*cb*/,
    short sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann ) const
{
  return new CtxVariableIterator(sctx, loc, argv);
}


PlanIter_t ctx_var_assign::codegen(
    CompilerCB* cb,
    short sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  CtxVarAssignIterator* iter = new CtxVarAssignIterator(sctx, loc, argv);

  static_context* sctxp = cb->getStaticContext(sctx);

  const fo_expr& expr = reinterpret_cast<const fo_expr&>(ann);

  xqtref_t exprType = (expr[1])->return_type(sctxp);

  if (exprType->get_quantifier() == TypeConstants::QUANT_ONE)
    iter->setSingleItem();

  return iter;
}


PlanIter_t ctx_var_declare::codegen (
    CompilerCB* /*cb*/,
    short sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann ) const
{
  return new CtxVarDeclIterator(sctx, loc, argv);
}


PlanIter_t ctx_var_exists::codegen (
    CompilerCB* /*cb*/,
    short sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann ) const
{
  return new CtxVarExistsIterator(sctx, loc, argv);
}

}
