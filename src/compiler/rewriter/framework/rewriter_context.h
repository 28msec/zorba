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
#ifndef ZORBA_REWRITER_CONTEXT_H
#define ZORBA_REWRITER_CONTEXT_H

#include <map>
#include <vector>

#include "common/shared_types.h"

#include "util/dynamic_bitset.h"

#include "compiler/expression/var_expr.h"

namespace zorba 
{

typedef std::map<var_expr *, int> VarIdMap;
typedef std::vector<var_expr*> IdVarMap;
typedef std::map<expr *, DynamicBitset> ExprVarsMap;

class RewriterContext 
{
public:
  CompilerCB           * compilerCB;
  static_context       * m_sctx;
  expr_t                 m_root;
  int                    m_tempvarCounter;
  int                    m_tempIndexCounter;

  VarIdMap             * m_varid_map;
  IdVarMap             * m_idvar_map;
  ExprVarsMap          * m_exprvars_map;
  std::vector<expr_t>    m_flwor_exprs;

public:
  RewriterContext(CompilerCB*, expr_t root);

  ~RewriterContext();

  static_context* getStaticContext() { return m_sctx; }

  expr_t getRoot();
  void setRoot(expr_t root);

  CompilerCB* getCompilerCB() { return compilerCB; }

  rchandle<var_expr> createTempVar(short sctx, const QueryLoc& loc, var_expr::var_kind kind);
};

}

#endif /* ZORBA_REWRITER_CONTEXT_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
