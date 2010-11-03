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
#include <sstream>
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/expression/expr_base.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"

#ifdef WIN32
// VS2005 requires this include to be able to compile the file
#include "context/static_context.h"
#endif


namespace zorba {

RewriterContext::RewriterContext(CompilerCB* aCompilerCB, expr_t root)
  :
  theCCB(aCompilerCB),
  theRoot(root),
  m_tempvarCounter(0),
  theVarIdMap(NULL),
  theIdVarMap(NULL),
  theExprVarsMap(NULL)
{
}


RewriterContext::~RewriterContext()
{
  delete theVarIdMap;

  delete theIdVarMap;

  delete theExprVarsMap;
}


expr_t RewriterContext::getRoot()
{
  return theRoot;
}


void RewriterContext::setRoot(expr_t root)
{
  theRoot = root;
}


rchandle<var_expr> RewriterContext::createTempVar(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr::var_kind kind)
{
  std::stringstream ss;
  ss << "$$opt_temp_" << (m_tempvarCounter++);
  std::string varname = ss.str();
  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, "", "", varname.c_str());
  rchandle<var_expr> var = new var_expr(sctx, loc, kind, qname);

  return var;
}

}
/* vim:set ts=2 sw=2: */
