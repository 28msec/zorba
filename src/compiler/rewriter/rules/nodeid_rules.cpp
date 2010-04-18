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
#include "context/static_context.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/rewriter/tools/dataflow_annotations.h"
#include "compiler/rewriter/framework/rule_driver.h"

#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/path_expr.h"

#include "types/typeops.h"

#include "functions/nodeid_internal.h"


namespace zorba 
{


/*******************************************************************************

********************************************************************************/
static void pushdown_ignore_props(expr* src, expr* target) 
{
  Annotations::Key k;

  k = Annotations::IGNORES_SORTED_NODES;
  TSVAnnotationValue::update_annotation(target, k, src->get_annotation(k));

  k = Annotations::IGNORES_DUP_NODES;
  TSVAnnotationValue::update_annotation(target, k, src->get_annotation(k));
}


/*******************************************************************************
  If the result of a FLWOR ignores node order, than the sources of all FOR
  variables do too. This does not hold for dup nodes:
  (let $a := <u><v>1</v></u> let $x := ($a, $a) for $y in $x return <a>{$y}</a>)//u
********************************************************************************/
static void mark_for_vars_ignoring_sort(flwor_expr* flwor) 
{
  Annotations::Key k = Annotations::IGNORES_SORTED_NODES;

  AnnotationValue_t v = flwor->get_annotation(k);

  for (flwor_expr::clause_list_t::const_iterator it = flwor->clause_begin();
       it != flwor->clause_end();
       ++it)
  {
    const flwor_clause& c = *(*it);

    if (c.get_kind() != flwor_clause::for_clause)
      continue;

    const for_clause* fc = static_cast<const for_clause *>(&c);

    const var_expr* pos_var = fc->get_pos_var();
    assert(pos_var == NULL || pos_var->get_kind() == var_expr::pos_var); 

    TSVAnnotationValue::update_annotation(fc->get_expr(),
                                          k,
                                          (pos_var == NULL ?
                                           v : TSVAnnotationValue::FALSE_VAL));
  }
}


/*******************************************************************************
  Assume all LET var values could ignore sort order and duplicate nodes,
  and allow expressions further down the tree to challenge this assumption.
********************************************************************************/
static void init_let_vars_consumer_props(flwor_expr* flwor) 
{
  for (flwor_expr::clause_list_t::const_iterator it = flwor->clause_begin();
       it != flwor->clause_end();
       ++it)
  {
    const flwor_clause& c = *(*it);

    if (c.get_kind() != flwor_clause::let_clause)
      continue;

    const forletwin_clause* lc = static_cast<const forletwin_clause *>(&c);

    int todo = 0;
    var_expr_t var = lc->get_var();
    assert(var->get_kind() == var_expr::let_var);

    for (int j = 0; j < 2; j++) 
    {
      Annotations::Key k = (j == 0 ?
                             Annotations::IGNORES_SORTED_NODES :
                             Annotations::IGNORES_DUP_NODES);

      AnnotationValue_t v = var->get_annotation(k);

      TSVAnnotationValue::update_annotation(lc->get_expr(), k, v);

      if (v != TSVAnnotationValue::TRUE_VAL)
      {
        var->put_annotation(k, TSVAnnotationValue::TRUE_VAL);
        todo |= (1 << j);
      }
    }

    if (todo != 0)
      var->put_annotation(Annotations::LET_VAR_NODEID_ANALYSIS,
                           AnnotationValue_t(new IntAnnotationValue(todo)));
  }
}


/*******************************************************************************
  If no expression involving a LET var cares about sort order / dup nodes,
  mark the domain expr accordingly.
********************************************************************************/
static bool analyze_let_vars_consumer_props (flwor_expr* flwor) 
{
  bool modified = false;

  Annotations::Key analysisKey = Annotations::LET_VAR_NODEID_ANALYSIS;

  for (flwor_expr::clause_list_t::const_iterator it = flwor->clause_begin();
       it != flwor->clause_end();
       ++it)
  {
    const flwor_clause& c = *(*it);

    if (c.get_kind() != flwor_clause::let_clause)
      continue;

    const forletwin_clause* lc = static_cast<const forletwin_clause *>(&c);

    varref_t var = lc->get_var();

    for (int j = 0; j < 2; j++) 
    {
      Annotations::Key k = (j == 0 ?
                             Annotations::IGNORES_SORTED_NODES :
                             Annotations::IGNORES_DUP_NODES);
      
      AnnotationValue_t analysisVal = var->get_annotation(analysisKey);

      if (analysisVal != NULL &&
          0 != ((1 << j) & static_cast<IntAnnotationValue*>(analysisVal.getp())->theValue))
      {
        AnnotationValue_t v = var->get_annotation(k);

        TSVAnnotationValue::update_annotation(lc->get_expr(), k, v);

        if (v.getp() == TSVAnnotationValue::TRUE_VAL.getp())
          modified = true;
      }

    }

    var->remove_annotation(analysisKey);
  }
    
  return modified;
}


/*******************************************************************************

********************************************************************************/
static void mark_casts(
    const cast_or_castable_base_expr* node,
    expr* input,
    static_context* sctx) 
{
  xqtref_t target = node->get_target_type();

  if (TypeOps::is_empty(*target)) 
  {
    TSVAnnotationValue::update_annotation(input,
                                          Annotations::IGNORES_SORTED_NODES,
                                          TSVAnnotationValue::TRUE_VAL);
    TSVAnnotationValue::update_annotation(input,
                                          Annotations::IGNORES_DUP_NODES,
                                          TSVAnnotationValue::TRUE_VAL);
    return;
  }

  bool is_cast = dynamic_cast<cast_base_expr *>(input) != NULL;

  TypeConstants::quantifier_t q = TypeOps::quantifier(*target);

  if (! is_cast ||
      q == TypeConstants::QUANT_ONE ||
      q == TypeConstants::QUANT_QUESTION) 
  {
    TSVAnnotationValue::update_annotation(input,
                                          Annotations::IGNORES_SORTED_NODES,
                                          TSVAnnotationValue::TRUE_VAL);
  }
  else if (is_cast) 
  {
    TSVAnnotationValue::update_annotation(input,
                                          Annotations::IGNORES_SORTED_NODES,
                                          TSVAnnotationValue::from_bool(node->get_annotation(Annotations::IGNORES_DUP_NODES).getp() == TSVAnnotationValue::TRUE_VAL.getp()));
  }

  bool ignores_dups = (q == TypeConstants::QUANT_STAR ||
                       (q == TypeConstants::QUANT_PLUS &&
                        TypeOps::type_min_cnt(*input->return_type(sctx)) >= 1));

  if (is_cast)
  {
    ignores_dups = (ignores_dups &&
                    node->get_annotation(Annotations::IGNORES_DUP_NODES).getp() ==
                    TSVAnnotationValue::TRUE_VAL.getp());
  }

  TSVAnnotationValue::update_annotation(input,
                                        Annotations::IGNORES_DUP_NODES,
                                        TSVAnnotationValue::from_bool (ignores_dups));
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(MarkConsumerNodeProps)
{
  switch (node->get_expr_kind()) 
  {
  case fo_expr_kind: 
  {
    fo_expr* fo = static_cast<fo_expr *>(node);
    function* f = fo->get_func(false);

    FunctionConsts::FunctionKind fkind = f->getKind();

    if (fkind == FunctionConsts::FN_EMPTY_1 ||
        fkind == FunctionConsts::FN_EXISTS_1 ||
        fkind == FunctionConsts::FN_MAX_1 ||
        fkind == FunctionConsts::FN_MAX_2 ||
        fkind == FunctionConsts::FN_MIN_1 ||
        fkind == FunctionConsts::FN_MIN_2 ||
        fkind == FunctionConsts::FN_BOOLEAN_1)
    {
      expr_t arg = fo->get_arg(0, false);
      TSVAnnotationValue::update_annotation(arg,
                                            Annotations::IGNORES_SORTED_NODES,
                                            TSVAnnotationValue::TRUE_VAL);
      TSVAnnotationValue::update_annotation(arg,
                                            Annotations::IGNORES_DUP_NODES,
                                            TSVAnnotationValue::TRUE_VAL);
    }
    else if (fkind == FunctionConsts::FN_ZERO_OR_ONE_1 ||
             fkind == FunctionConsts::FN_EXACTLY_ONE_1)
    {
      // If these functions are over a duplicate elimination function, the 
      // duplicate elimination is pulled up into the runtime iterators for
      // fn:zero-or-one or fn:exactly-one.
      bool ignoresDups = false;
      expr_t arg = fo->get_arg(0, false);

      if (arg->get_expr_kind() == fo_expr_kind)
      {
        const fo_expr* fo = static_cast<fo_expr *>(arg.getp());
        const function* argFunc = fo->get_func();

        if (argFunc->isNodeDistinctFunction())
        {
          ignoresDups = true;
          f->setFlag(FunctionConsts::DoDistinct);
        }
      }

      TSVAnnotationValue::update_annotation(arg,
                                            Annotations::IGNORES_DUP_NODES,
                                            TSVAnnotationValue::from_bool(ignoresDups));

      TSVAnnotationValue::update_annotation(arg,
                                            Annotations::IGNORES_SORTED_NODES,
                                            TSVAnnotationValue::TRUE_VAL);
    }
    else if (fkind == FunctionConsts::FN_UNORDERED_1 ||
             fkind == FunctionConsts::FN_COUNT_1 ||
             fkind == FunctionConsts::FN_SUM_1 ||
             fkind == FunctionConsts::FN_SUM_2 ||
             fkind == FunctionConsts::FN_AVG_1 ||
             fkind == FunctionConsts::OP_EXACTLY_ONE_NORAISE_1)
    {
      expr_t arg = fo->get_arg(0, false);
      TSVAnnotationValue::update_annotation(arg,
                                            Annotations::IGNORES_SORTED_NODES,
                                            TSVAnnotationValue::TRUE_VAL);
      TSVAnnotationValue::update_annotation(arg,
                                            Annotations::IGNORES_DUP_NODES,
                                            TSVAnnotationValue::FALSE_VAL);
    }
    else
    {
      std::vector <AnnotationHolder *> args;
      ulong numArgs = fo->num_args();

      for (ulong i = 0; i < numArgs; ++i)
        args.push_back(static_cast<AnnotationHolder*>(fo->get_arg(i, false)));

      f->compute_annotation(node, args, Annotations::IGNORES_DUP_NODES);
      f->compute_annotation(node, args, Annotations::IGNORES_SORTED_NODES);
    }
    break;
  }

  case if_expr_kind: 
  {
    if_expr* ite = static_cast<if_expr *> (node);
    pushdown_ignore_props(node, ite->get_then_expr(false));
    pushdown_ignore_props(node, ite->get_else_expr(false));
    break;
  }

  case flwor_expr_kind: 
  {
    flwor_expr* flwor = static_cast<flwor_expr *> (node);
    init_let_vars_consumer_props(flwor);
    mark_for_vars_ignoring_sort(flwor);
    pushdown_ignore_props(node, flwor->get_return_expr(false));
    break;
  }

  case relpath_expr_kind: 
  {
    expr_t arg = (*static_cast<relpath_expr *> (node)) [0];
    TSVAnnotationValue::update_annotation(arg,
                                          Annotations::IGNORES_SORTED_NODES,
                                          TSVAnnotationValue::TRUE_VAL);
    TSVAnnotationValue::update_annotation(arg,
                                          Annotations::IGNORES_DUP_NODES,
                                          TSVAnnotationValue::TRUE_VAL);
    break;
  }

  case wrapper_expr_kind: 
  {
    wrapper_expr* we = static_cast<wrapper_expr *> (node);
    pushdown_ignore_props(node, we->get_expr(false));
    break;
  }    

  default:
  {
    cast_or_castable_base_expr* ce = dynamic_cast<cast_base_expr *> (node);
    if (ce != NULL) 
    {
      expr* input = ce->get_input(false);
      mark_casts(ce, input, node->get_sctx());
      break;
    }
    else
    {
      for(expr_iterator i = node->expr_begin(); !i.done(); ++i) 
      {
        TSVAnnotationValue::update_annotation(*i,
                                              Annotations::IGNORES_SORTED_NODES,
                                              TSVAnnotationValue::FALSE_VAL);
        TSVAnnotationValue::update_annotation(*i,
                                              Annotations::IGNORES_DUP_NODES,
                                              TSVAnnotationValue::FALSE_VAL);
      }
    }

    break;
  }
  }

  return NULL;
}


RULE_REWRITE_POST(MarkConsumerNodeProps) 
{
  switch (node->get_expr_kind ()) 
  {
  case flwor_expr_kind:
    return analyze_let_vars_consumer_props(static_cast<flwor_expr *>(node)) ? node : NULL;

  default:
    break;
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(MarkProducerNodeProps)
{
  if (rCtx.getRoot().getp() == node) 
  {
    DataflowAnnotationsComputer computer(node->get_sctx());
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
  static_context* sctx = node->get_sctx();

  fo_expr* fo = dynamic_cast<fo_expr *>(node);

  if (fo != NULL) 
  {
    const function* f = fo->get_func();

    // ????
    if (f->getKind() == FunctionConsts::FN_UNORDERED_1)
      return fo->get_arg(0, true);

    const op_node_sort_distinct* nsdf = dynamic_cast<const op_node_sort_distinct*>(f);

    if (nsdf != NULL) 
    {
      const expr* argExpr = fo->get_arg(0);

      function* fmin = nsdf->optimize(sctx, node, argExpr);

      if (fmin != f)
      {
        if (fmin != NULL) 
        {
          fo->set_func(fmin);
          return fo;
        }
        else 
        {
          return fo->get_arg(0, true);
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


}
/* vim:set ts=2 sw=2: */
