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
#include "stdafx.h"

#include <algorithm>

#include "compiler/rewriter/tools/udf_graph.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/expr_iter.h"

#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"

#include "functions/udf.h"

#include "types/typeops.h"

#include "context/static_context.h"

#include "util/indent.h"

#include "diagnostics/util_macros.h"


namespace zorba
{


/*******************************************************************************

********************************************************************************/
UDFGraph::UDFGraph(expr* e)
  :
  theExpr(e),
  theNodes(32, false),
  theRoot(NULL),
  theVisitId(0)
{
  if (e != NULL)
    build(e);
}


/*******************************************************************************

********************************************************************************/
UDFGraph::~UDFGraph()
{
  UDFMap::iterator ite = theNodes.begin();
  UDFMap::iterator end = theNodes.end();
  for (; ite != end; ++ite)
  {
    delete (*ite).second;
  }
}


/*******************************************************************************

********************************************************************************/
void UDFGraph::build(const expr* e)
{
  user_function* dummy = NULL;
  theRoot = new UDFNode(NULL);
  theNodes.insert(dummy, theRoot);

  std::vector<user_function*> callChain;
  callChain.push_back(NULL);

  build(e, callChain);
}


/*******************************************************************************

********************************************************************************/
void UDFGraph::build(const expr* curExpr, std::vector<user_function*>& callChain)
{
  expr_kind_t kind = curExpr->get_expr_kind();

  if (kind == fo_expr_kind || kind == function_item_expr_kind)
  {
    user_function* udf = NULL;

    if (kind == fo_expr_kind)
    {
      const fo_expr* fo = static_cast<const fo_expr*>(curExpr);
      udf = dynamic_cast<user_function*>(fo->get_func());
    }
    else
    {
      const function_item_expr* fi = static_cast<const function_item_expr*>(curExpr);
      udf = dynamic_cast<user_function*>(fi->get_function());
    }

    if (udf != NULL)
    {
      std::vector<user_function*>::const_iterator cycle;

      if ((cycle = std::find(callChain.begin(), callChain.end(), udf)) == callChain.end())
      {
        bool found = theNodes.exists(udf);

        addEdge(callChain.back(), udf);

        callChain.push_back(udf);

        // If this is the first time we see the current udf, do a recursive
        // call on its body expr.
        if (!found && udf->getBody())
        {
          build(udf->getBody(), callChain);
        }

        callChain.pop_back();
      }
      else
      {
        // A recursive function call.
        std::vector<user_function*>::const_iterator ite = cycle;
        std::vector<user_function*>::const_iterator end = callChain.end();
        for (; ite != end; ++ite)
        {
          (*ite)->addMutuallyRecursiveUDFs(callChain, cycle);
        }
      }
    }
  }

  ExprConstIterator iter(curExpr);
  while (!iter.done())
  {
    build(iter.get_expr(), callChain);

    iter.next();
  }
}


/*******************************************************************************

********************************************************************************/
void UDFGraph::addEdge(user_function* caller, user_function* callee)
{
  UDFNode* callerNode = NULL;
  UDFNode* calleeNode = NULL;

  if (!theNodes.get(caller, callerNode))
  {
    callerNode = new UDFNode(caller);
    theNodes.insert(caller, callerNode);
  }

  if (!theNodes.get(callee, calleeNode))
  {
    calleeNode = new UDFNode(callee);
    theNodes.insert(callee, calleeNode);
  }

  callerNode->theChildren.push_back(calleeNode);
  calleeNode->theParents.push_back(callerNode);
}


/*******************************************************************************

********************************************************************************/
void UDFGraph::optimizeUDFs(CompilerCB* ccb)
{
  optimizeUDFs(ccb, theRoot, ++theVisitId);
}


void UDFGraph::optimizeUDFs(CompilerCB* ccb, UDFNode* node, ulong visit)
{
  if (node->theVisitId == visit)
    return;

  node->theVisitId = visit;

  for (ulong i = 0; i < node->theChildren.size(); ++i)
  {
    optimizeUDFs(ccb, node->theChildren[i], visit);
  }

  if (node == theRoot)
    return;

  user_function* udf = node->theUDF;
  expr_t body = udf->getBody();

  // inline functions are optimized during translation.
  if (udf->isOptimized())
    return;

  // Note: the body can be NULL when using Plan Serialization
  while (body != NULL)
  {
    // Set the Optimized flag in advance to prevent an infinte loop (for
    // recursive functions, an optimization could be attempted again)
    udf->setOptimized(true);

    RewriterContext rctx(ccb, body, udf,
                         zstring(),
                         body->get_sctx()->is_in_ordered_mode());
    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rctx);
    body = rctx.getRoot();

    TypeManager* tm = body->get_type_manager();

#if 1
    // Set the return type of the function to the type of its body. But do not
    // do it if the body type is a user-defined type because the udf may be
    // used in another module which does not import the schema that describes 
    // this user-defined type.
    xqtref_t bodyType = body->get_return_type();
    xqtref_t declaredType = udf->getSignature().returnType();
    
    bool udt = (bodyType->type_kind() == XQType::USER_DEFINED_KIND);

    if (bodyType->type_kind() == XQType::NODE_TYPE_KIND)
    {
      const NodeXQType* nodeType = static_cast<const NodeXQType*>(bodyType.getp());
        
      xqtref_t contentType = nodeType->get_content_type();

      udt = (contentType->type_kind() == XQType::USER_DEFINED_KIND);
    }

    if ( !udt &&
         !TypeOps::is_equal(tm, *bodyType, *declaredType, body->get_loc()) &&
         TypeOps::is_subtype(tm, *bodyType, *declaredType, body->get_loc()))
    {
      udf->getSignature().returnType() = bodyType;
      if (!udf->isLeaf())
        continue;
    }
#endif

    udf->setBody(body);
    break;
  }

  if (ccb->theConfig.optimize_cb != NULL)
  {
    if (udf->getName())
    {
      ccb->theConfig.optimize_cb(body, udf->getName()->getStringValue().c_str());
    }
    else
    {
      ccb->theConfig.optimize_cb(body, "inline function");
    }
  }
}


/*******************************************************************************

********************************************************************************/
void UDFGraph::inferDeterminism()
{
  inferDeterminism(theRoot, ++theVisitId);
}


bool UDFGraph::inferDeterminism(UDFNode* node, ulong visit)
{
  if (node->theVisitId == visit)
    return node->theUDF->isDeterministic();

  node->theVisitId = visit;

  bool deterministic = true;

  for (ulong i = 0; i < node->theChildren.size(); ++i)
  {
    if (inferDeterminism(node->theChildren[i], visit) == false)
      deterministic = false;
  }

  if (node != theRoot)
  {
    if (deterministic)
    {
      // Body can be NULL when using Plan Serialization. In this case
      // nondeterministic is already computed
      if (node->theUDF->getBody() != NULL)
      {
        deterministic = !node->theUDF->getBody()->is_nondeterministic();
      }
      else
      {
        deterministic = node->theUDF->isDeterministic();
      }
    }

    if (!deterministic && node->theUDF->isDeterministic())
    {
      RAISE_ERROR(zerr::ZXQP0040_MISSING_NONDETERMINISTIC_ANNOTATION,
                  node->theUDF->getBody()->get_loc(),
                  ERROR_PARAMS(node->theUDF->getName()->getStringValue()));
    }

    node->theUDF->setDeterministic(deterministic);
  }

  return deterministic;
}


/*******************************************************************************

********************************************************************************/
void UDFGraph::display(std::ostream& o)
{
  display(o, theRoot);

  o << std::endl << std::endl;
}


void UDFGraph::display(std::ostream& o, UDFNode* node)
{
  if (node == theRoot)
    o << indent << "Root Node" << std::endl;
  else
    o << indent << node->theUDF->getName()->show() << std::endl;

  o << inc_indent;

  for (ulong i = 0; i < node->theChildren.size(); ++i)
  {
    display(o, node->theChildren[i]);
  }

  o << dec_indent;
}


}
/* vim:set et sw=2 ts=2: */
