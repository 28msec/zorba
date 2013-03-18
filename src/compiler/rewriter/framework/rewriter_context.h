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
#ifndef ZORBA_REWRITER_CONTEXT_H
#define ZORBA_REWRITER_CONTEXT_H

#include <map>
#include <vector>

#include "common/shared_types.h"

#include "util/dynamic_bitset.h"

#include "compiler/expression/var_expr.h"
#include "compiler/expression/expr_manager.h"

namespace zorba
{

class user_function;


/*******************************************************************************

  theRoot:
  --------
  The root node of the expr DAG that is going to be optimized using this context.

********************************************************************************/
class RewriterContext
{
public:
  CompilerCB                 * theCCB;

  ExprManager                * theEM;

  expr                       * theRoot;

  user_function              * theUDF;

  zstring                      theMessage;

  int                          m_tempvarCounter;

  bool                         theForSerializationOnly;

  bool                         theIsInOrderedMode;

public:
  RewriterContext(
      CompilerCB* cb,
      expr* root,
      user_function* udf,
      const zstring& msg,
      bool orderedMode);

  ~RewriterContext();

  CompilerCB* getCompilerCB() const { return theCCB; }

  expr* getRoot() const;

  void setRoot(expr* root);

  void setForSerializationOnly(bool v) { theForSerializationOnly = v; }

  var_expr* createTempVar(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr::var_kind kind);
};


}

#endif /* ZORBA_REWRITER_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
