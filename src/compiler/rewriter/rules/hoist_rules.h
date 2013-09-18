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
#ifndef ZORBA_COMPILER_REWRITER_HOIST_RULES
#define ZORBA_COMPILER_REWRITER_HOIST_RULES

#include "compiler/rewriter/rules/rule_base.h"
#include "compiler/rewriter/tools/expr_tools.h"


namespace zorba
{

class RewriterContext;


/*******************************************************************************

********************************************************************************/
class HoistRule : public RewriteRule
{
protected:
  expr_tools::VarIdMap    theVarIdMap;

  expr_tools::ExprVarsMap theExprVarsMap;

public:
  HoistRule() : RewriteRule(RewriteRule::HoistExprsOutOfLoops, "Hoist") {}

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);

protected:
  bool hoistChildren(RewriterContext&, expr*, struct PathHolder*);

  expr* hoistExpr(RewriterContext&, expr*, struct PathHolder*);

  bool contains_var(var_expr* v, const DynamicBitset& varset);
};


}
#endif
