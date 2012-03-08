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

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/rewriter/tools/dataflow_annotations.h"
#include "compiler/rewriter/framework/rule_driver.h"

#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/json_exprs.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/expr_iter.h"

#include "types/typeimpl.h"
#include "types/typeops.h"

#include "functions/func_node_sort_distinct.h"
#include "functions/udf.h"

#include "diagnostics/assert.h"


namespace zorba 
{


/*******************************************************************************
  If the ignore-sorted-nodes annotation of the target expr is not set to false
  already, set it to the value of the ignore-sorted-nodes annotations of the
  source expr.
********************************************************************************/
static void pushdown_ignores_sorted_nodes(expr* src, expr* target) 
{
  if (target->getIgnoresSortedNodes() != ANNOTATION_FALSE)
    target->setIgnoresSortedNodes(src->getIgnoresSortedNodes());
}


/*******************************************************************************
  If the ignore-sorted-nodes annotation of the target expr is not set to false
  already, set it to the given value.
********************************************************************************/
static void set_ignores_sorted_nodes(expr* target, BoolAnnotationValue v) 
{
  if (target->getIgnoresSortedNodes() != ANNOTATION_FALSE)
    target->setIgnoresSortedNodes(v);
}


/*******************************************************************************
  If the ignore-duplicates-nodes annotation of the target expr is not set to
  false already, set it to the value of the ignore-duplicate-nodes annotations
  of the source expr.
********************************************************************************/
static void pushdown_ignores_duplicate_nodes(expr* src, expr* target) 
{
  if (target->getIgnoresDuplicateNodes() != ANNOTATION_FALSE)
    target->setIgnoresDuplicateNodes(src->getIgnoresDuplicateNodes());
}


/*******************************************************************************
  If the ignore-duplicates-nodes annotation of the target expr is not set to
  false already, set it to the given value.
********************************************************************************/
static void set_ignores_duplicate_nodes(expr* target, BoolAnnotationValue v) 
{
  if (target->getIgnoresDuplicateNodes() != ANNOTATION_FALSE)
    target->setIgnoresDuplicateNodes(v);
}


/*******************************************************************************
  Compute the ignores-sorted-nodes and ignores-duplicate-nodes annotations of
  the current expr.

  ignores-sorted-nodes : tells whether the expr needs to produce nodes in doc
  order or not (because its consumers care about doc order or not).

  ignores-duplicate-nodes : tells whether the expr needs to produce distinct
  nodes or not (because its consumers care about duplicate nodes or not).

  The rule works in a top-down fashion, first setting the annotations of an
  expression e and then moving down to the children of e.
********************************************************************************/
expr_t MarkConsumerNodeProps::apply(
    RewriterContext& rCtx,
    expr* node,
    bool& modified)
{
  bool saveInOrderedMode = false;

  if (!rCtx.theIsInOrderedMode)
  {
    set_ignores_sorted_nodes(node, ANNOTATION_TRUE);
  }

  switch (node->get_expr_kind())
  {
  case order_expr_kind :
  {
    saveInOrderedMode = rCtx.theIsInOrderedMode;
      
    order_expr* orderExpr = static_cast<order_expr *>(node);

    rCtx.theIsInOrderedMode = (orderExpr->get_type() == order_expr::ordered ?
                               true : false);
    break;
  }

  case block_expr_kind :
  {
    block_expr* seqExpr = static_cast<block_expr *>(node);
    csize numChildren = seqExpr->size();

    for (csize i = 0; i < numChildren-1; ++i)
    {
      expr* child = (*seqExpr)[i];
      set_ignores_sorted_nodes(child, ANNOTATION_TRUE);
      set_ignores_duplicate_nodes(child, ANNOTATION_TRUE);
    }

    expr* child = (*seqExpr)[numChildren-1];
    pushdown_ignores_sorted_nodes(node, child);
    pushdown_ignores_duplicate_nodes(node, child);

    // TODO: go through the children again, and for each child that is a
    // var_decl_expr, push down the annotation of the associated var_expr
    // to the associated init_expr (if any) and then apply the rule to the
    // init_expr.
    break;
  }

  case apply_expr_kind :
  {
    apply_expr* exp = static_cast<apply_expr *>(node);

    if (exp->discardsXDM())
    {
      set_ignores_sorted_nodes(exp->get_expr(), ANNOTATION_TRUE);
      set_ignores_duplicate_nodes(exp->get_expr(), ANNOTATION_TRUE);
    }
    else
    {
      pushdown_ignores_sorted_nodes(node, exp->get_expr());
      pushdown_ignores_duplicate_nodes(node, exp->get_expr());
    }

    break;
  }

  case var_decl_expr_kind :
  case var_set_expr_kind :
  {
    break;
  }

  case exit_catcher_expr_kind :
  {
    exit_catcher_expr* e = static_cast<exit_catcher_expr*>(node);
    pushdown_ignores_sorted_nodes(node, e->get_expr());
    pushdown_ignores_duplicate_nodes(node, e->get_expr());
    break;
  }

  case flwor_expr_kind: 
  {
    flwor_expr* flwor = static_cast<flwor_expr *>(node);

    // no need to do anything for the where expr or the orderby exprs because
    // they don't produce nodes.
    
    // The annotations for the return expr are the same as those of its
    // containing flwor expr.
    pushdown_ignores_sorted_nodes(node, flwor->get_return_expr());
    pushdown_ignores_duplicate_nodes(node, flwor->get_return_expr());
    
    // apply the rule recursively on the return expr
    apply(rCtx, flwor->get_return_expr(), modified);

    // Process the clauses in reverse order so that by the time we reach the
    // definition of a LET var, we know if the LET var sequence must be in
    // doc order and/or without duplicates.
    csize i = flwor->num_clauses();
    for (; i > 0; --i)
    {
      flwor_clause* clause = flwor->get_clause(i-1);

      if (clause->get_kind() == flwor_clause::let_clause)
      {
        let_clause* lc = static_cast<let_clause*>(clause);
        expr* domainExpr = lc->get_expr();
        var_expr* var = lc->get_var();
        
        // The annotations for the domain expr are the same as those of its
        // associated LET var.
        domainExpr->setIgnoresSortedNodes(var->getIgnoresSortedNodes());
        domainExpr->setIgnoresDuplicateNodes(var->getIgnoresDuplicateNodes());
        
        // apply the rule recursively on the domainExpr
        apply(rCtx, domainExpr, modified);
      }
      else if (clause->get_kind() == flwor_clause::for_clause)
      {
        for_clause* fc = static_cast<for_clause*>(clause);
        expr* domainExpr = fc->get_expr();
        var_expr* posVar = fc->get_pos_var();
        assert(posVar == NULL || posVar->get_kind() == var_expr::pos_var); 
        
        // If a flwor expr does not need to care about producing nodes in doc
        // order, then the domain expr of a FOR variable does not need to care
        // either, unless there is a POS variable associated with the FOR var.
        // On the other hand, if the flwor does need to produce nodes in doc
        // order, then we conservatively mark each FOR domain expr as needing
        // to produce nodes in doc order as well.
        if (posVar == NULL)
        {
          domainExpr->setIgnoresSortedNodes(flwor->getIgnoresSortedNodes());
        }
        else if (rCtx.theIsInOrderedMode)
        {
          domainExpr->setIgnoresSortedNodes(ANNOTATION_FALSE);
        }
        
        // apply the rule recursively on the domainExpr
        apply(rCtx, domainExpr, modified);
      }
      else if (clause->get_kind() == flwor_clause::where_clause)
      {
        // apply the rule recursively on the whereExpr
        where_clause* wc = static_cast<where_clause*>(clause);
        apply(rCtx, wc->get_expr(), modified);
      }
      else if (clause->get_kind() == flwor_clause::order_clause)
      {
        // apply the rule recursively on the orderby exprs
        orderby_clause* oc = static_cast<orderby_clause*>(clause);
      
        csize numExprs = oc->num_columns();
      
        for (csize i = 0; i < numExprs; ++i)
        {
          apply(rCtx, oc->get_column_expr(i), modified);
        }
      }
    }
    return NULL;
  }
  
  case if_expr_kind: 
  {
    if_expr* ite = static_cast<if_expr *>(node);
    pushdown_ignores_sorted_nodes(node, ite->get_then_expr());
    pushdown_ignores_sorted_nodes(node, ite->get_else_expr());
    pushdown_ignores_duplicate_nodes(node, ite->get_then_expr());
    pushdown_ignores_duplicate_nodes(node, ite->get_else_expr());
    break;
  }

  case wrapper_expr_kind : 
  {
    wrapper_expr* we = static_cast<wrapper_expr *>(node);
    pushdown_ignores_sorted_nodes(node, we->get_expr());
    pushdown_ignores_duplicate_nodes(node, we->get_expr());
    break;
  }    
  
  case function_trace_expr_kind :
  {
    function_trace_expr* fte = static_cast<function_trace_expr*>(node);
    pushdown_ignores_sorted_nodes(node, fte->get_expr());
    pushdown_ignores_duplicate_nodes(node, fte->get_expr());
    break;
  }

  case relpath_expr_kind : 
  {
    expr_t arg = (*static_cast<relpath_expr *>(node))[0];
    pushdown_ignores_sorted_nodes(node, arg);
    pushdown_ignores_duplicate_nodes(node, arg);
    break;
  }

  case cast_expr_kind :
  case castable_expr_kind :
  case instanceof_expr_kind :
  {
    cast_or_castable_base_expr* curExpr = 
    static_cast<cast_or_castable_base_expr*>(node);

    expr* arg = curExpr->get_input();

    xqtref_t targetType = curExpr->get_target_type();
    TypeConstants::quantifier_t q = targetType->get_quantifier();
    
    set_ignores_sorted_nodes(arg, ANNOTATION_TRUE);

    if (targetType->is_empty()) 
    {
      set_ignores_duplicate_nodes(arg, ANNOTATION_TRUE);
    }
    else if (q == TypeConstants::QUANT_STAR ||
             (q == TypeConstants::QUANT_PLUS &&
              arg->get_return_type()->min_card() >= 1))
    {
      set_ignores_duplicate_nodes(arg, ANNOTATION_TRUE);
    }
    else
    {
      set_ignores_duplicate_nodes(arg, ANNOTATION_FALSE);
    }
    
    break;
  }
  
  case promote_expr_kind :
  case treat_expr_kind :
  {
    cast_base_expr* curExpr = static_cast<cast_base_expr*>(node);

    expr* arg = curExpr->get_input();
      
    xqtref_t targetType = curExpr->get_target_type();
    TypeConstants::quantifier_t q = targetType->get_quantifier();

    if (targetType->is_empty()) 
    {
      set_ignores_sorted_nodes(arg, ANNOTATION_TRUE);
      set_ignores_duplicate_nodes(arg, ANNOTATION_TRUE);
    }
    else
    {
      if (q == TypeConstants::QUANT_ONE || q == TypeConstants::QUANT_QUESTION) 
      {
        set_ignores_sorted_nodes(arg, ANNOTATION_TRUE);
      }
      else
      {
        pushdown_ignores_sorted_nodes(curExpr, arg);
      }
      
      if (curExpr->getIgnoresDuplicateNodes() == ANNOTATION_TRUE &&
          (q == TypeConstants::QUANT_STAR ||
           (q == TypeConstants::QUANT_PLUS &&
            arg->get_return_type()->min_card() >= 1)))
      {
        set_ignores_duplicate_nodes(arg, ANNOTATION_TRUE);
      }
      else
      {
        set_ignores_duplicate_nodes(arg, ANNOTATION_FALSE);
      }
    }
    
    break;
  }
  
  case fo_expr_kind : 
  {
    fo_expr* fo = static_cast<fo_expr *>(node);
    function* f = fo->get_func();
    
    FunctionConsts::FunctionKind fkind = f->getKind();
    
    csize numArgs = fo->num_args();
    
    for (csize i = 0; i < numArgs; ++i)
    {
      expr* arg = fo->get_arg(i);
        
      set_ignores_sorted_nodes(arg, f->ignoresSortedNodes(node, i));
      
      set_ignores_duplicate_nodes(arg, f->ignoresDuplicateNodes(node, i));
    }
      
    if (fkind == FunctionConsts::FN_ZERO_OR_ONE_1 ||
        fkind == FunctionConsts::FN_EXACTLY_ONE_1)
    {
      // If these functions are over a duplicate elimination function, the 
      // duplicate elimination is pulled up into the runtime iterators for
      // fn:zero-or-one or fn:exactly-one.
      expr_t arg = fo->get_arg(0);
      
      if (arg->get_expr_kind() == fo_expr_kind)
      {
        const fo_expr* fo = static_cast<fo_expr *>(arg.getp());
        const function* argFunc = fo->get_func();
        
        if (argFunc->isNodeDistinctFunction())
        {
          set_ignores_duplicate_nodes(arg, ANNOTATION_TRUE);
          f->setFlag(FunctionConsts::DoDistinct);
        }
      }
    }
    
    break;
  }
  
#ifdef ZORBA_WITH_JSON
  case json_object_expr_kind :
  {
    json_object_expr* e = static_cast<json_object_expr *>(node);
    set_ignores_duplicate_nodes(e->get_expr(), ANNOTATION_TRUE);
    break;
  }
  case json_array_expr_kind :
  {
    json_array_expr* e = static_cast<json_array_expr *>(node);
    e->get_expr()->setIgnoresDuplicateNodes(ANNOTATION_FALSE);
    break;
  }
#endif

  case attr_expr_kind :
  case elem_expr_kind :
  case pi_expr_kind :
  case text_expr_kind :
  case doc_expr_kind :

  case extension_expr_kind :  // TODO
  case flowctl_expr_kind :    // TODO
  case gflwor_expr_kind :     // TODO
  case name_cast_expr_kind :  // TODO
  case trycatch_expr_kind :   // TODO
  case validate_expr_kind :   // TODO
  case var_expr_kind :

#ifndef ZORBA_NO_FULL_TEXT
  case ft_expr_kind :         // TODO
#endif

  case insert_expr_kind :     // TODO
  case delete_expr_kind :     // TODO
  case rename_expr_kind :     // TODO
  case replace_expr_kind :    // TODO
  case transform_expr_kind :  // TODO

  case while_expr_kind :      // TODO
  case exit_expr_kind :       // TODO

  case eval_expr_kind :       // TODO
  case debugger_expr_kind :   // TODO
  case dynamic_function_invocation_expr_kind : // TODO
  case function_item_expr_kind : // TODO
  {
    ExprIterator iter(node);
    while (!iter.done()) 
    {
      if (rCtx.theIsInOrderedMode)
        (*iter)->setIgnoresSortedNodes(ANNOTATION_FALSE);

      (*iter)->setIgnoresDuplicateNodes(ANNOTATION_TRUE);
      
      iter.next();
    }

    break;
  }

  case const_expr_kind :
  case axis_step_expr_kind :
  case match_expr_kind :
  {
    return NULL;
  }

  default:
  {
    ZORBA_ASSERT(false);
  }
  }
  
  ExprIterator iter(node);
  while (!iter.done())
  {
    apply(rCtx, *iter, modified);
    iter.next();
  }
 
  if (node->get_expr_kind() == order_expr_kind)
     rCtx.theIsInOrderedMode = saveInOrderedMode;

  return NULL;
}


/*******************************************************************************
  
********************************************************************************/
expr_t MarkProducerNodeProps::apply(
    RewriterContext& rCtx,
    expr* node,
    bool& modified)
{
  DataflowAnnotationsComputer computer;
  computer.compute(node);
  modified = false;
  return NULL;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(EliminateNodeOps)
{
  fo_expr* fo = dynamic_cast<fo_expr *>(node);

  if (fo != NULL) 
  {
    const function* f = fo->get_func();

    // ????
    if (f->getKind() == FunctionConsts::FN_UNORDERED_1)
      return fo->get_arg(0);

    const op_node_sort_distinct_base* nsdf;
    nsdf = dynamic_cast<const op_node_sort_distinct_base*>(f);

    if (nsdf != NULL) 
    {
      expr* argExpr = fo->get_arg(0);

      function* fmin = nsdf->optimize(node, argExpr);

      if (fmin != f)
      {
        if (fmin != NULL) 
        {
          fo->set_func(fmin);
          return fo;
        }
        else 
        {
          return fo->get_arg(0);
        }
      }
    }
  }

  return NULL;
}


RULE_REWRITE_POST(EliminateNodeOps) 
{
  return NULL; 
}


/*******************************************************************************

********************************************************************************/
expr_t MarkNodeCopyProps::apply(
    RewriterContext& rCtx,
    expr* node,
    bool& modified)
{
  modified = false;

  theSourceFinder = new SourceFinder;

  try
  {
    if (rCtx.theCCB->theConfig.for_serialization_only)
    {
      static_context* sctx = node->get_sctx();
      if (sctx->preserve_mode() == StaticContextConsts::preserve_ns &&
          sctx->inherit_mode() == StaticContextConsts::inherit_ns)
      {
        markForSerialization(rCtx.theRoot);
      }
      else
      {
        std::vector<expr*> sources;
        UDFCallChain dummyUdfCaller;
        theSourceFinder->findNodeSources(rCtx.theRoot, &dummyUdfCaller, sources);
        markSources(sources);
      }
    }
    else
    {
      std::vector<expr*> sources;
      UDFCallChain dummyUdfCaller;
      theSourceFinder->findNodeSources(rCtx.theRoot, &dummyUdfCaller, sources);
      markSources(sources);
    }

    UDFCallChain dummyUdfCaller;
    applyInternal(rCtx, node, dummyUdfCaller);
  }
  catch (...)
  {
    delete theSourceFinder;
    theSourceFinder = NULL;

    throw;
  }

  delete theSourceFinder;
  theSourceFinder = NULL;

  return NULL;
}


/*******************************************************************************

********************************************************************************/
void MarkNodeCopyProps::applyInternal(
    RewriterContext& rCtx,
    expr* node,
    UDFCallChain& udfCaller)
{
  switch (node->get_expr_kind()) 
  {
  case const_expr_kind:
  case var_expr_kind:
  {
    return;
  }

  case doc_expr_kind:
  case elem_expr_kind:
  case attr_expr_kind:
  case text_expr_kind:
  case pi_expr_kind:
  {
    break;
  }

#ifdef ZORBA_WITH_JSON
  case json_object_expr_kind:
  {
    break;
  }
  case json_array_expr_kind:
  {
    // For now, assume that nodes to appear as pair values must be copied first.
    // TODO improve this
    json_array_expr* e = static_cast<json_array_expr *>(node);

    static_context* sctx = e->get_sctx();

    if (sctx->preserve_mode() != StaticContextConsts::no_preserve_ns)
    {
      std::vector<expr*> sources;
      theSourceFinder->findNodeSources(e->get_expr(), &udfCaller, sources);
      markSources(sources);
    }

    break;
  }
#if 0
  case json_pair_expr_kind:
  {
    // For now, assume that nodes to appear as pair values must be copied first.
    // TODO improve this
    json_pair_expr* e = static_cast<json_pair_expr *>(node);

    static_context* sctx = e->get_sctx();

    if (sctx->preserve_mode() != StaticContextConsts::no_preserve_ns)
    {
      std::vector<expr*> sources;
      theSourceFinder->findNodeSources(e->get_value_expr(), &udfCaller, sources);
      markSources(sources);
    }

    break;
  }
#endif
#endif

  case relpath_expr_kind:
  {
    relpath_expr* e = static_cast<relpath_expr *>(node);

    if (e->willBeSerialized())
    {
      std::vector<expr*> sources;
      theSourceFinder->findNodeSources((*e)[0],  &udfCaller, sources);
      markSources(sources);
    }
    else
    {
      std::vector<expr_t>::const_iterator ite = e->begin();
      std::vector<expr_t>::const_iterator end = e->end();

      for (++ite; ite != end; ++ite)
      {
        axis_step_expr* axisExpr = static_cast<axis_step_expr*>((*ite).getp());
        axis_kind_t axisKind = axisExpr->getAxis();

        if (axisKind != axis_kind_child &&
            axisKind != axis_kind_descendant &&
            axisKind != axis_kind_self &&
            axisKind != axis_kind_attribute)
        {
          std::vector<expr*> sources;
          theSourceFinder->findNodeSources((*e)[0],  &udfCaller, sources);
          markSources(sources);
          break;
        }
      }
    }

    applyInternal(rCtx, (*e)[0], udfCaller);

    return;
  }

  case gflwor_expr_kind:
  case flwor_expr_kind:
  case if_expr_kind:
  case trycatch_expr_kind:
  {
    break;
  }

  case fo_expr_kind:
  {
    fo_expr* e = static_cast<fo_expr *>(node);
    function* f = e->get_func();

    if (f->isUdf())
    {
      user_function* udf = static_cast<user_function*>(f);

#if 0
      UdfCalls::iterator ite = std::find(theUdfCallPath.begin(), theUdfCallPath.end(), e);

      if (ite == theUdfCallPath.end())
      {
        theUdfCallPath.push_back(e);

        UDFCallChain nextUdfCall(e, &udfCaller);

        applyInternal(rCtx, udf->getBody(), nextUdfCall);

        theUdfCallPath.pop_back();
      }
#else
      UdfCalls::iterator ite = theProcessedUDFCalls.find(e);

      if (ite == theProcessedUDFCalls.end())
      {
        theProcessedUDFCalls.insert(e);

        UDFCallChain nextUdfCall(e, &udfCaller);

        applyInternal(rCtx, udf->getBody(), nextUdfCall);
      }
      else
      {
        csize numArgs = e->num_args();
        for (csize i = 0; i < numArgs; ++i)
        {
          var_expr* argVar = udf->getArgVar(i);

          if (theSourceFinder->theVarSourcesMap.find(argVar) !=
              theSourceFinder->theVarSourcesMap.end())
          {
            std::vector<expr*> sources;
            theSourceFinder->findNodeSources(e->get_arg(i), &udfCaller, sources);
            markSources(sources);
          }
        }
      }
#endif
    } // f->isUdf()
    else
    {
      csize numArgs = e->num_args();
      for (csize i = 0; i < numArgs; ++i)
      {
        if (f->mustCopyInputNodes(e, i))
        {
          std::vector<expr*> sources;
          theSourceFinder->findNodeSources(e->get_arg(i), &udfCaller, sources);
          markSources(sources);
        }
      }
    }

    break;
  }

  case castable_expr_kind:
  case cast_expr_kind:
  case instanceof_expr_kind:
  case name_cast_expr_kind:
  case promote_expr_kind:
  case treat_expr_kind:
  case order_expr_kind:
  case wrapper_expr_kind:
  case function_trace_expr_kind:
  case extension_expr_kind:
  {
    break;
  }

  case validate_expr_kind:
  {
    validate_expr* e = static_cast<validate_expr *>(node);
    std::vector<expr*> sources;
    theSourceFinder->findNodeSources(e->get_expr(), &udfCaller, sources);
    markSources(sources);
    break;
  }

  case delete_expr_kind:
  case rename_expr_kind:
  case insert_expr_kind:
  case replace_expr_kind:
  {
    update_expr_base* e = static_cast<update_expr_base*>(node);

    std::vector<expr*> sources;
    theSourceFinder->findNodeSources(e->getTargetExpr(), &udfCaller, sources);
    markSources(sources);

    static_context* sctx = e->get_sctx();

    if (e->getSourceExpr() != NULL &&
        (e->get_expr_kind() == insert_expr_kind ||
         static_cast<replace_expr*>(e)->getType() == store::UpdateConsts::NODE) &&
        (sctx->inherit_mode() != StaticContextConsts::no_inherit_ns ||
         sctx->preserve_mode() != StaticContextConsts::no_preserve_ns))
    {
      std::vector<expr*> sources;
      theSourceFinder->findNodeSources(e->getSourceExpr(), &udfCaller, sources);
      markSources(sources);
    }

    break;
  }

  case transform_expr_kind:
  {
    transform_expr* e = static_cast<transform_expr *>(node);

    static_context* sctx = e->get_sctx();

    if (sctx->preserve_mode() != StaticContextConsts::no_preserve_ns)
    {
      std::vector<copy_clause_t>::const_iterator ite = e->begin();
      std::vector<copy_clause_t>::const_iterator end = e->end();

      for (; ite != end; ++ite)
      {
        std::vector<expr*> sources;
        theSourceFinder->findNodeSources((*ite)->getExpr(), &udfCaller, sources);
        markSources(sources);
      }
    }

    break;
  }

  case var_decl_expr_kind:
  case var_set_expr_kind:
  case apply_expr_kind:
  case while_expr_kind:
  case flowctl_expr_kind:
  case exit_expr_kind:
  case exit_catcher_expr_kind: 
  {
    break;
  }

  case block_expr_kind:
  {
    block_expr* e = static_cast<block_expr *>(node);

    if (e->is_sequential())
    {
      csize numChildren = e->size();
      bool haveUpdates = false;

      for (csize i = numChildren; i > 0; --i)
      {
        expr* child = (*e)[i-1];

        if (haveUpdates)
        {
          std::vector<expr*> sources;
          theSourceFinder->findNodeSources(child, &udfCaller, sources);
          markSources(sources);
        }
        else
        {
          short scriptingKind = child->get_scripting_detail();

          if (scriptingKind & APPLYING_EXPR || 
              scriptingKind & EXITING_EXPR ||
              scriptingKind & SEQUENTIAL_FUNC_EXPR)
          {
            haveUpdates = true;
          }
        }
      }
    }

    break;
  }

  case eval_expr_kind:
  {
    eval_expr* e = static_cast<eval_expr*>(node);

    // Conservatively assume that, when executed, the eval query will apply
    // a "node-id-sensitive" operation on each of the in-scope variables, so
    // these variables must be bound to statndalone trees.
    csize numEvalVars = e->var_count();

    for (csize i = 0; i < numEvalVars; ++i)
    {
      expr* arg = e->get_arg_expr(i);

      std::vector<expr*> sources;
      theSourceFinder->findNodeSources(arg, &udfCaller, sources);
      markSources(sources);
    }

    std::vector<var_expr_t> globalVars;
    node->get_sctx()->getVariables(globalVars, false, true);
  
    FOR_EACH(std::vector<var_expr_t>, ite, globalVars)
    {
      var_expr* globalVar = (*ite).getp();

      std::vector<expr*> sources;
      theSourceFinder->findNodeSources(globalVar, &udfCaller, sources);
      markSources(sources);
    }

    break;
  }

  case debugger_expr_kind:
  {
    break;
  }

#ifndef ZORBA_NO_FULL_TEXT
  case ft_expr_kind:
  {
    ftcontains_expr* e = static_cast<ftcontains_expr*>(node);

    std::vector<expr*> sources;
    theSourceFinder->findNodeSources(e->get_range(), &udfCaller, sources);
    markSources(sources);

    break;
  }
#endif

  case dynamic_function_invocation_expr_kind:
  {
    // Conservatively assume that the function item that is going to be executed
    // requires stand-alone trees as inputs, so find and mark the sources in the
    // arguments. TODO: look for function_item_expr in the subtree to check if
    // this assumption is really true. 
    dynamic_function_invocation_expr* e = 
    static_cast<dynamic_function_invocation_expr*>(node);

    const std::vector<expr_t>& args = e->get_args();

    FOR_EACH(std::vector<expr_t>, ite, args)
    {
      std::vector<expr*> sources;
      theSourceFinder->findNodeSources((*ite).getp(), &udfCaller, sources);
      markSources(sources);
    }

    break;
  }

  case function_item_expr_kind:
  {
    function_item_expr* e = static_cast<function_item_expr*>(node);

    user_function* udf = static_cast<user_function*>(e->get_function());

    UDFCallChain dummyUdfCaller;

    applyInternal(rCtx, udf->getBody(), dummyUdfCaller);

    return;
  }

  case axis_step_expr_kind:
  case match_expr_kind:
  default:
    ZORBA_ASSERT(false);
  }

  ExprIterator iter(node);
  while(!iter.done()) 
  {
    expr* child = (*iter).getp();
    if (child != NULL) 
    {
      applyInternal(rCtx, child, udfCaller);
    }
    iter.next();
  }

  return;
}


/*******************************************************************************

********************************************************************************/
void MarkNodeCopyProps::markSources(const std::vector<expr*>& sources)
{
  std::vector<expr*>::const_iterator ite = sources.begin();
  std::vector<expr*>::const_iterator end = sources.end();
  for (; ite != end; ++ite)
  {
    expr* source = (*ite);
    
    switch (source->get_expr_kind())
    {
    case doc_expr_kind:
    {
      doc_expr* e = static_cast<doc_expr*>(source);
      e->setCopyInputNodes();
      break;
    }
    case elem_expr_kind:
    {
      elem_expr* e = static_cast<elem_expr*>(source);
      e->setCopyInputNodes();
      break;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }
}


/*******************************************************************************

********************************************************************************/
void MarkNodeCopyProps::markForSerialization(expr* node)
{
  TypeManager* tm = node->get_type_manager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t retType = node->get_return_type();

  if (TypeOps::is_subtype(tm, *retType, *rtm.ANY_ATOMIC_TYPE_STAR))
    return;

  switch (node->get_expr_kind()) 
  {
  case const_expr_kind:
  {
    return;
  }
  case var_expr_kind:
  {
    var_expr* e = static_cast<var_expr*>(node);

    switch (e->get_kind())
    {
    case var_expr::for_var:
    case var_expr::let_var:
    case var_expr::win_var:
    case var_expr::wincond_out_var:
    case var_expr::wincond_in_var:
    case var_expr::groupby_var:
    case var_expr::non_groupby_var:
    {
      if (!e->willBeSerialized())
      {
        e->setWillBeSerialized(ANNOTATION_TRUE);
        markForSerialization(e->get_domain_expr());
      }
      return;
    }

    case var_expr::copy_var:
    case var_expr::catch_var:
    {
      return;
    }

    case var_expr::arg_var:
    {
      e->setWillBeSerialized(ANNOTATION_TRUE);
      return;
    }

    case var_expr::prolog_var: 
    case var_expr::local_var:
    {
      if (!e->willBeSerialized())
      {
        e->setWillBeSerialized(ANNOTATION_TRUE);

        std::vector<expr*>::const_iterator ite = e->setExprsBegin();
        std::vector<expr*>::const_iterator end = e->setExprsEnd();

        for (; ite != end; ++ite)
        {
          expr* setExpr = *ite;

          if (setExpr->get_expr_kind() == var_decl_expr_kind)
          {
            markForSerialization(static_cast<var_decl_expr*>(setExpr)->get_init_expr());
          }
          else
          {
            assert(setExpr->get_expr_kind() == var_set_expr_kind);

            markForSerialization(static_cast<var_set_expr*>(setExpr)->get_expr());
          }
        }
      }
      return;
    }

    case var_expr::wincond_in_pos_var:
    case var_expr::wincond_out_pos_var:
    case var_expr::pos_var:
    case var_expr::score_var:
    case var_expr::count_var:
    case var_expr::eval_var:
    default:
    {
      ZORBA_ASSERT(false);
      return;
    }
    }
  }

  case doc_expr_kind:
  case elem_expr_kind:
  case attr_expr_kind:
  case text_expr_kind:
  case pi_expr_kind:
  {
    break;
  }

#ifdef ZORBA_WITH_JSON
  case json_object_expr_kind:
  case json_array_expr_kind:
    //case json_pair_expr_kind:
  {
    break;
  }
#endif

  case relpath_expr_kind:
  {
    relpath_expr* e = static_cast<relpath_expr *>(node);
    e->setWillBeSerialized(ANNOTATION_TRUE);
    markForSerialization((*e)[0]);
    return;
  }

  case gflwor_expr_kind:
  case flwor_expr_kind:
  {
    flwor_expr* e = static_cast<flwor_expr *>(node);
    e->setWillBeSerialized(ANNOTATION_TRUE);
    markForSerialization(e->get_return_expr());
    return;
  }

  case if_expr_kind:
  case trycatch_expr_kind:
  {
    break;
  }

  case fo_expr_kind:
  {
    fo_expr* e = static_cast<fo_expr *>(node);
    function* f = e->get_func();

    e->setWillBeSerialized(ANNOTATION_TRUE);

    if (f->isUdf())
    {
      user_function* udf = static_cast<user_function*>(f);
      expr* body = udf->getBody();

      if (!body->willBeSerialized())
      {
        markForSerialization(body);
      }

      std::vector<var_expr_t>::const_iterator ite = udf->getArgVars().begin();
      std::vector<var_expr_t>::const_iterator end = udf->getArgVars().end();
      for (; ite != end; ++ite)
      {
        expr* argVar = (*ite).getp();
        if (argVar->willBeSerialized())
        {
          expr* argExpr = e->get_arg(ite - udf->getArgVars().begin());
          markForSerialization(argExpr);
        }
      }
    } // f->isUdf()
    else
    {
      csize numArgs = e->num_args();
      for (csize i = 0; i < numArgs; ++i)
      {
        if (f->propagatesInputNodes(e, i))
        {
          markForSerialization(e->get_arg(i));
        }
      }
    }

    return;
  }

  case promote_expr_kind:
  case treat_expr_kind:
  case order_expr_kind:
  case wrapper_expr_kind:
  case function_trace_expr_kind:
  case extension_expr_kind:
  {
    break;
  }

  case validate_expr_kind:
  {
    node->setWillBeSerialized(ANNOTATION_TRUE);
    return;
  }

  case transform_expr_kind:
  {
    transform_expr* e = static_cast<transform_expr *>(node);
    e->setWillBeSerialized(ANNOTATION_TRUE);
    markForSerialization(e->getReturnExpr());
    return;
  }

  case block_expr_kind:
  {
    block_expr* e = static_cast<block_expr *>(node);
    e->setWillBeSerialized(ANNOTATION_TRUE);
    expr* lastChild = (*e)[e->size()-1];
    markForSerialization(lastChild);
    return;
  }

  case var_decl_expr_kind:
  case var_set_expr_kind:
  {
    return;
  }

  case apply_expr_kind:
  {
    break;
  }

  case exit_catcher_expr_kind: 
  {
    exit_catcher_expr* e = static_cast<exit_catcher_expr*>(node);

    std::vector<expr*>::const_iterator ite = e->exitExprsBegin();
    std::vector<expr*>::const_iterator end = e->exitExprsEnd();

    for (; ite != end; ++ite)
    {
      exit_expr* ex = static_cast<exit_expr*>(*ite);

      markForSerialization(ex->get_expr());
    }

    break;
  }


  case eval_expr_kind:
  {
    eval_expr* e = static_cast<eval_expr*>(node);

    csize numVars = e->var_count();

    for (csize i = 0; i < numVars; ++i)
    {
      markForSerialization(e->get_arg_expr(i));
    }

    std::vector<var_expr_t> globalVars;
    e->get_sctx()->getVariables(globalVars, true, true);
  
    FOR_EACH(std::vector<var_expr_t>, ite, globalVars)
    {
      var_expr* globalVar = (*ite).getp();
      markForSerialization(globalVar);
    }

    return;
  }

  case debugger_expr_kind:
  {
    break;
  }

  case dynamic_function_invocation_expr_kind:
  {
    dynamic_function_invocation_expr* e = 
    static_cast<dynamic_function_invocation_expr*>(node);

    const std::vector<expr_t>& args = e->get_args();

    FOR_EACH(std::vector<expr_t>, ite, args)
    {
      markForSerialization((*ite).getp());
    }

    break;
  }

  case function_item_expr_kind:
  {
    function_item_expr* e = static_cast<function_item_expr*>(node);

    user_function* udf = static_cast<user_function*>(e->get_function());

    UDFCallChain dummyUdfCaller;

    markForSerialization(udf->getBody());

    return;
  }

  case castable_expr_kind:
  case cast_expr_kind:
  case instanceof_expr_kind:
  case name_cast_expr_kind:
  case axis_step_expr_kind:
  case match_expr_kind:
  case delete_expr_kind:
  case rename_expr_kind:
  case insert_expr_kind:
  case replace_expr_kind:
  case while_expr_kind:
  case flowctl_expr_kind:
  case exit_expr_kind:
#ifndef ZORBA_NO_FULL_TEXT
  case ft_expr_kind:
#endif
  default:
    ZORBA_ASSERT(false);
  }

  node->setWillBeSerialized(ANNOTATION_TRUE);

  ExprIterator iter(node);
  while(!iter.done()) 
  {
    expr* child = (*iter).getp();
    if (child != NULL) 
    {
      markForSerialization(child);
    }
    iter.next();
  }

  return;
}


}
/* vim:set et sw=2 ts=2: */
