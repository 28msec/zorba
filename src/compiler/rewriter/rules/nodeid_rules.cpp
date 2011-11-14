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
#include "compiler/expression/expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/expr_iter.h"

#include "types/typeops.h"

#include "functions/func_node_sort_distinct.h"

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
    ulong numChildren = seqExpr->size();

    for (ulong i = 0; i < numChildren-1; ++i)
    {
      expr_t& child = (*seqExpr)[i];
      set_ignores_sorted_nodes(child.getp(), ANNOTATION_TRUE);
      set_ignores_duplicate_nodes(child.getp(), ANNOTATION_TRUE);
    }

    expr_t& child = (*seqExpr)[numChildren-1];
    pushdown_ignores_sorted_nodes(node, child.getp());
    pushdown_ignores_duplicate_nodes(node, child.getp());

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
    ulong i = flwor->num_clauses();
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
      
        ulong numExprs = oc->num_columns();
      
        for (ulong i = 0; i < numExprs; ++i)
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

    TypeManager* tm = curExpr->get_type_manager();
    xqtref_t targetType = curExpr->get_target_type();
    TypeConstants::quantifier_t q = TypeOps::quantifier(*targetType);
    
    set_ignores_sorted_nodes(arg, ANNOTATION_TRUE);

    if (TypeOps::is_empty(tm, *targetType)) 
    {
      set_ignores_duplicate_nodes(arg, ANNOTATION_TRUE);
    }
    else if (q == TypeConstants::QUANT_STAR ||
             (q == TypeConstants::QUANT_PLUS &&
              TypeOps::type_min_cnt(tm, *arg->get_return_type()) >= 1))
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
      
    TypeManager* tm = curExpr->get_type_manager();
    xqtref_t targetType = curExpr->get_target_type();
    TypeConstants::quantifier_t q = TypeOps::quantifier(*targetType);

    if (TypeOps::is_empty(tm, *targetType)) 
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
            TypeOps::type_min_cnt(tm, *arg->get_return_type()) >= 1)))
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
    
    ulong numArgs = fo->num_args();
    
    for (ulong i = 0; i < numArgs; ++i)
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
  
  case attr_expr_kind :
  case elem_expr_kind :
  case pi_expr_kind :
  case text_expr_kind :
  case doc_expr_kind :

  case axis_step_expr_kind :
  case const_expr_kind :
  case extension_expr_kind :  // TODO
  case flowctl_expr_kind :    // TODO
  case gflwor_expr_kind :     // TODO
  case match_expr_kind :
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

      (*iter)->setIgnoresDuplicateNodes(ANNOTATION_FALSE);
      
      iter.next();
    }

    break;
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
RULE_REWRITE_PRE(MarkProducerNodeProps)
{
  if (rCtx.getRoot().getp() == node) 
  {
    DataflowAnnotationsComputer computer;
    computer.compute(node);
  }
  return NULL;
}


RULE_REWRITE_POST(MarkProducerNodeProps)
{
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
void MarkNodeCopyProps::apply(
    RewriterContext* rCtx,
    expr* inExpr,
    bool& modified)
{
  switch(inExpr->get_expr_kind()) 
  {
  case const_expr_kind:
  {
    return NULL;
  }
#if 0
  case var_expr_kind:
  {
    var_expr* e = static_cast<var_expr*>(inExpr);

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
      VarSourcesMap::iterator ite = rCtx->theVarSourcesMap.find(e);

      if (ite == rCtx->theVarSourcesMap.end())
      {
        std::vector<expr*> varSources;
        findNodeSources(rCtx, e->get_domain_expr(), varSources, currentUdf);

        ite = (rCtx->theVarSourcesMap.insert(VarSourcesPair(e, varSources))).first;
      }

      sources.insert(sources.end(), (*ite).second.begin(), (*ite).second.end());
      return;
    }

    case var_expr::wincond_in_pos_var:
    case var_expr::wincond_out_pos_var:
    case var_expr::pos_var:
    case var_expr::score_var:
    case var_expr::count_var:
    {
      return;
    }

    case var_expr::copy_var:
    {
      // A copy var holds a standalone copy of the node produced by its domain
      // expr. Although such a copy is a constructed tree, it was not constructed
      // by node-constructor exprs, and as a resylt, a copy var is not a source.
      return;
    }

    case var_expr::arg_var:
    {
      sources.push_back(inExpr);
      return;
    }

    case var_expr::prolog_var: 
    case var_expr::local_var:
    {
      // Assumption: all the assingment exprs on this var that may be executed
      // before e, have been encountered and processed already. 
      VarSourcesMap::iterator ite = rCtx->theVarSourcesMap.find(e);

      if (ite != rCtx->theVarSourcesMap.end())
        sources.insert(sources.end(), (*ite).second.begin(), (*ite).second.end());

      return;
    }

    case var_expr::catch_var:
    {
      // If in the try clause there is an fn:error that generates nodes, it will 
      // be (conservatively) treated as a "must copy" function, so all of those
      // nodes will be in standalone trees.
      return;
    }

    case var_expr::eval_var: // TODO
    default:
    {
      ZORBA_ASSERT(false);
    }
    }

    break;
  }

  case doc_expr_kind:
  case elem_expr_kind:
  case attr_expr_kind:
  case text_expr_kind:
  case pi_expr_kind:
  {
    sources.push_back(inExpr);
    return;
  }

  case relpath_expr_kind:
  {
    relpath_expr* e = static_cast<relpath_expr *>(inExpr);
    findNodeSources(rCtx, (*e)[0], sources, currentUdf);
    return;
  }

  case gflwor_expr_kind:
  case flwor_expr_kind:
  {
    flwor_expr* e = static_cast<flwor_expr *>(inExpr);

    if (e->has_sequential_clauses())
    {
      // no clause should be skipped, beacuase a clause may contain var 
      // assingment exprs.
      break;
    }
    else
    {
      // We don't need to drill down to the domain exprs of variables that
      // are not referenced in the return clause.
      findNodeSources(rCtx, e->get_return_expr(), sources, currentUdf);
      return;
    }
    break;
  }

  case if_expr_kind:
  {
    if_expr* e = static_cast<if_expr *>(inExpr);
    findNodeSources(rCtx, e->get_then_expr(), sources, currentUdf);
    findNodeSources(rCtx, e->get_else_expr(), sources, currentUdf);
    return;
  }

  case trycatch_expr_kind:
  {
    break;
  }

  case fo_expr_kind:
  {
    fo_expr* e = static_cast<fo_expr *>(inExpr);
    function* f = e->get_func();

    if (f->isUdf())
    {
      user_function* udf = static_cast<user_function*>(f);
 
      bool recursive = currentUdf->isMutuallyRecursiveWith(udf);

      UdfSourcesMap::iterator ite = rCtx->theUdfSourcesMap.find(udf);

      if (ite == rCtx->theUdfSourcesMap.end() ||
          (recursive &&
           std::find(rCtx->theUdfCallPath.begin(), rCtx->theUdfCallPath.end(), e) ==
           rCtx->theUdfCallPath.end()))
      {
        if (recursive)
          rCtx->theUdfCallPath.push_back(e);

        std::vector<expr*> udfSources;
        ite = (rCtx->theUdfSourcesMap.insert(UdfSourcesPair(udf, udfSources))).first;

        findNodeSources(rCtx, udf->getBody(), (*ite).second, udf);

        if (recursive)
          rCtx->theUdfCallPath.pop_back();
      }

      std::vector<expr*>& udfSources = (*ite).second;

      std::vector<expr*>::const_iterator ite2 = udfSources.begin();
      std::vector<expr*>::const_iterator end2 = udfSources.end();
      for (; ite2 != end2; ++ite2)
      {
        expr* source = (*ite2);

        if (source->get_expr_kind() == var_expr_kind)
        {
          var_expr* argVar = static_cast<var_expr*>(source);

          ZORBA_ASSERT(argVar->get_kind() == var_expr::arg_var);

          expr* argExpr = e->get_arg(argVar->get_param_pos());

          xqtref_t argType = argExpr->get_return_type();

          if (!TypeOps::is_subtype(tm, *argType, *rtm.ANY_ATOMIC_TYPE_STAR))
          {
            findNodeSources(rCtx, argExpr, sources, currentUdf);
          }
        }
        else
        {
          sources.push_back(source);
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
          findNodeSources(rCtx, e->get_arg(i), sources, currentUdf);
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

  case var_decl_expr_kind:
  {
    var_decl_expr* e = static_cast<var_decl_expr*>(inExpr);

    var_expr* varExpr = e->get_var_expr();
    expr* initExpr = e->get_init_expr();

    if (initExpr == NULL)
      return;

    assert(rCtx->theVarSourcesMap.find(varExpr) == rCtx->theVarSourcesMap.end());

    VarSourcesMap::iterator ite;
    std::vector<expr*> varSources;
    ite = (rCtx->theVarSourcesMap.insert(VarSourcesPair(varExpr, varSources))).first;

    findNodeSources(rCtx, initExpr, (*ite).second, currentUdf);
    
    return;
  }

#if 0
  case block_expr_kind:
    compute_block_expr(static_cast<block_expr *>(e));
    break;

  case apply_expr_kind:
  {
    apply_expr* exp = static_cast<apply_expr *>(e);

    if (exp->discardsXDM())
    {
      SORTED_NODES(exp);
      DISTINCT_NODES(exp);
    }
    else
    {
      default_walk(e);
      PROPOGATE_SORTED_NODES(exp->get_expr(), exp);
      PROPOGATE_DISTINCT_NODES(exp->get_expr(), exp);
    }

    break;
  }

  case exit_catcher_expr_kind: 
  {
    default_walk(e);
    generic_compute(e);
    break;
  }

  case exit_expr_kind:
  {
    default_walk(e);
    SORTED_NODES(e);
    DISTINCT_NODES(e);
    break;
  }

  case flowctl_expr_kind:       // TODO
  case while_expr_kind:         // TODO
    break;

  case validate_expr_kind:
    compute_validate_expr(static_cast<validate_expr *>(e));
    break;

  case dynamic_function_invocation_expr_kind: // TODO
  case function_item_expr_kind: // TODO
  case transform_expr_kind:     // TODO
#ifndef ZORBA_NO_FULL_TEXT
  case ft_expr_kind:            // TODO
#endif
  case eval_expr_kind:          // TODO
  case debugger_expr_kind:      // TODO
    break;
#endif
    
  case castable_expr_kind:
  case cast_expr_kind:
  case instanceof_expr_kind:
  case name_cast_expr_kind:
  case axis_step_expr_kind:
  case match_expr_kind:
  case delete_expr_kind:
  case insert_expr_kind:
  case rename_expr_kind:
  case replace_expr_kind:

#endif
  default:
    ZORBA_ASSERT(false);
  }

  ExprIterator iter(inExpr);
  while(!iter.done()) 
  {
    expr* child = (*iter).getp();
    if (child != NULL) 
    {
      apply(rCtx, child, modified);
    }
    iter.next();
  }

  return NULL;
}


}
/* vim:set et sw=2 ts=2: */
