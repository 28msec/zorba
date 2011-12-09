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

#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/update_exprs.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/expr_iter.h"

#include "compiler/rewriter/tools/dataflow_annotations.h"
#include "compiler/rewriter/framework/rewriter_context.h"

#include "types/typeops.h"

#include "functions/function.h"
#include "functions/udf.h"
#include "functions/library.h"

#include "diagnostics/assert.h"


namespace zorba 
{


#define SORTED_NODES(e) \
e->setProducesSortedNodes(ANNOTATION_TRUE)

#define PROPOGATE_SORTED_NODES(src, tgt) \
tgt->setProducesSortedNodes(src->getProducesSortedNodes())

#define DISTINCT_NODES(e) \
e->setProducesDistinctNodes(ANNOTATION_TRUE)

#define PROPOGATE_DISTINCT_NODES(src, tgt) \
tgt->setProducesDistinctNodes(src->getProducesDistinctNodes())


/*******************************************************************************
  Determine whether an expr produces sorted and/or distinct nodes or not.
********************************************************************************/
void DataflowAnnotationsComputer::compute(expr* e)
{
  switch(e->get_expr_kind()) 
  {
  case var_decl_expr_kind:
    compute_var_decl_expr(static_cast<var_decl_expr*>(e));
    break;

  case var_set_expr_kind:
    compute_var_set_expr(static_cast<var_set_expr*>(e));
    break;

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

  case wrapper_expr_kind:
    compute_wrapper_expr(static_cast<wrapper_expr *>(e));
    break;

  case function_trace_expr_kind:
  {
    default_walk(e);
    function_trace_expr* fte = static_cast<function_trace_expr*>(e);
    PROPOGATE_SORTED_NODES(fte->get_expr(), e);
    PROPOGATE_DISTINCT_NODES(fte->get_expr(), e);
    break;
  }

  case var_expr_kind:
    compute_var_expr(static_cast<var_expr *>(e));
    break;

  case gflwor_expr_kind:
  case flwor_expr_kind:
    compute_flwor_expr(static_cast<flwor_expr *>(e));
    break;

  case trycatch_expr_kind:
    compute_trycatch_expr(static_cast<trycatch_expr *>(e));
    break;
    
  case promote_expr_kind:
    compute_promote_expr(static_cast<promote_expr *>(e));
    break;

  case if_expr_kind:
    compute_if_expr(static_cast<if_expr *>(e));
    break;

  case fo_expr_kind:
    compute_fo_expr(static_cast<fo_expr *>(e));
    break;

  case instanceof_expr_kind:
    compute_instanceof_expr(static_cast<instanceof_expr *>(e));
    break;

  case treat_expr_kind:
    compute_treat_expr(static_cast<treat_expr *>(e));
    break;

  case castable_expr_kind:
    compute_castable_expr(static_cast<castable_expr *>(e));
    break;

  case cast_expr_kind:
    compute_cast_expr(static_cast<cast_expr *>(e));
    break;

  case name_cast_expr_kind:
    compute_name_cast_expr(static_cast<name_cast_expr *>(e));
    break;

  case validate_expr_kind:
    compute_validate_expr(static_cast<validate_expr *>(e));
    break;

  case extension_expr_kind:
    compute_extension_expr(static_cast<extension_expr *>(e));
    break;

  case relpath_expr_kind:
    compute_relpath_expr(static_cast<relpath_expr *>(e));
    break;
    
  case axis_step_expr_kind:
    compute_axis_step_expr(static_cast<axis_step_expr *>(e));
    break;
    
  case match_expr_kind:
    compute_match_expr(static_cast<match_expr *>(e));
    break;

  case const_expr_kind:
    compute_const_expr(static_cast<const_expr *>(e));
    break;
    
  case order_expr_kind:
    compute_order_expr(static_cast<order_expr *>(e));
    break;

  case elem_expr_kind:
    compute_elem_expr(static_cast<elem_expr *>(e));
    break;
    
  case doc_expr_kind:
    compute_doc_expr(static_cast<doc_expr *>(e));
    break;
    
  case attr_expr_kind:
    compute_attr_expr(static_cast<attr_expr *>(e));
    break;
    
  case text_expr_kind:
    compute_text_expr(static_cast<text_expr *>(e));
    break;
    
  case pi_expr_kind:
    compute_pi_expr(static_cast<pi_expr *>(e));
    break;
    
  case dynamic_function_invocation_expr_kind: // TODO
  case function_item_expr_kind: // TODO
  case delete_expr_kind:        // TODO
  case insert_expr_kind:        // TODO
  case rename_expr_kind:        // TODO
  case replace_expr_kind:       // TODO
  case transform_expr_kind:     // TODO
#ifndef ZORBA_NO_FULL_TEXT
  case ft_expr_kind:            // TODO
#endif
  case eval_expr_kind:          // TODO
  case debugger_expr_kind:      // TODO
    break;
    
  default:
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::default_walk(expr* e)
{
  ExprIterator iter(e);
  while(!iter.done()) 
  {
    expr* child = (*iter).getp();
    if (child != NULL) 
    {
      compute(child);
    }
    iter.next();
  }
}


/*******************************************************************************
  Return true if the given expr does not produce duplicate nodes and returns
  all nodes in document order.

  Without any info about the kind of the expr, the only thing we can do here
  is checks whether the expression has a return type with a quantifier of ONE
  or QUESTION. If so, the expression cannot have dup nodes or nodes out of sorted
  order.
********************************************************************************/
bool DataflowAnnotationsComputer::generic_compute(expr* e)
{
  xqtref_t rt = e->get_return_type();
  TypeConstants::quantifier_t quant = TypeOps::quantifier(*rt);

  if (quant == TypeConstants::QUANT_ONE || quant == TypeConstants::QUANT_QUESTION) 
  {
    SORTED_NODES(e);
    DISTINCT_NODES(e);
    return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_var_decl_expr(var_decl_expr* e)
{
  generic_compute(e);
  default_walk(e);
  
  var_expr* varExpr = e->get_var_expr();
  expr* initExpr = e->get_init_expr();

  if (initExpr != NULL && !varExpr->is_mutable())
  {
    PROPOGATE_SORTED_NODES(initExpr, varExpr);
    PROPOGATE_DISTINCT_NODES(initExpr, varExpr);
  }
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_var_set_expr(var_set_expr* e)
{
  generic_compute(e);
  default_walk(e);
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_block_expr(block_expr* e)
{
  default_walk(e);
  if (!generic_compute(e) && e->size() > 0)
  {
    PROPOGATE_SORTED_NODES((*e)[e->size()-1], e);
    PROPOGATE_DISTINCT_NODES((*e)[e->size()-1], e);
  }
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_wrapper_expr(wrapper_expr* e)
{
  default_walk(e);
  PROPOGATE_SORTED_NODES(e->get_expr(), e);
  PROPOGATE_DISTINCT_NODES(e->get_expr(), e);
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_var_expr(var_expr* e)
{
  if (!generic_compute(e)) 
  {
    if (e->get_kind() == var_expr::let_var) 
    {
      PROPOGATE_SORTED_NODES(e->get_forletwin_clause()->get_expr(), e);
      PROPOGATE_DISTINCT_NODES(e->get_forletwin_clause()->get_expr(), e);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_flwor_expr(flwor_expr* e)
{
  default_walk(e);

  if (! generic_compute(e) && !e->is_general())
  {
    flwor_expr::clause_list_t::const_iterator ite = e->clause_begin();
    flwor_expr::clause_list_t::const_iterator end = e->clause_end();

    const forletwin_clause* fc = NULL;
    ulong numForClauses = 0;

    for (; ite != end; ++ite)
    {
      const flwor_clause* clause = *ite;

      switch (clause->get_kind())
      {
      case flwor_clause::for_clause:
      {
        const forletwin_clause* flc = static_cast<const forletwin_clause*>(clause);

        expr* domainExpr = flc->get_expr();
        xqtref_t domainType = domainExpr->get_return_type();
        TypeConstants::quantifier_t domainQuant = domainType->get_quantifier();

        if (domainQuant != TypeConstants::QUANT_ONE &&
            domainQuant != TypeConstants::QUANT_QUESTION)
        {
          fc = flc;
          ++numForClauses;
        }

        break;
      }
      case flwor_clause::let_clause:
      case flwor_clause::where_clause:
      {
        break;
      }
      case flwor_clause::order_clause:
      case flwor_clause::group_clause:
      {
        return;
      }
      default:
      {
        ZORBA_ASSERT(false);
      }
      }
    }

    if (numForClauses == 1)
    {
      expr* retExpr = e->get_return_expr();

      const var_expr* var = retExpr->get_var();

      if (var != NULL && var == fc->get_var())
      {
        PROPOGATE_SORTED_NODES(fc->get_expr(), e);
        PROPOGATE_DISTINCT_NODES(fc->get_expr(), e);
      }
    }
    else if (numForClauses == 0)
    {
      expr* retExpr = e->get_return_expr();

      PROPOGATE_SORTED_NODES(retExpr, e);
      PROPOGATE_DISTINCT_NODES(retExpr, e);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_trycatch_expr(trycatch_expr* e)
{
  default_walk(e);
  generic_compute(e);
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_promote_expr(promote_expr* e)
{
  default_walk(e);
  PROPOGATE_SORTED_NODES(e->get_input(), e);
  PROPOGATE_DISTINCT_NODES(e->get_input(), e);
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_if_expr(if_expr* e)
{
  default_walk(e);
  generic_compute(e);
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_fo_expr(fo_expr* e)
{
  default_walk(e);

  if (!generic_compute(e)) 
  {
    const function* f = e->get_func();

    ulong nArgs = e->num_args();

    FunctionConsts::AnnotationValue sorted = f->producesSortedNodes();

    if (sorted == FunctionConsts::YES)
    {
      SORTED_NODES(e);
    }
    else if (sorted == FunctionConsts::NO)
    {
      e->setProducesSortedNodes(ANNOTATION_FALSE);
    } 
    else 
    {
      BoolAnnotationValue sorted = ANNOTATION_FALSE;

      for (ulong i = 0; i < nArgs; ++i) 
      {
        if (f->propagatesSortedNodes(i))
        {
          sorted = e->get_arg(i)->getProducesSortedNodes();
          break;
        }
      }

      e->setProducesSortedNodes(sorted);
    }

    FunctionConsts::AnnotationValue distinct = f->producesDistinctNodes();

    if (distinct == FunctionConsts::YES) 
    {
      DISTINCT_NODES(e);
    }
    else if (distinct == FunctionConsts::NO) 
    {
      e->setProducesDistinctNodes(ANNOTATION_FALSE);
    }
    else
    {
      BoolAnnotationValue distinct = ANNOTATION_FALSE;

      for (ulong i = 0; i < nArgs; ++i) 
      {
        if (f->propagatesDistinctNodes(i)) 
        {
          distinct = e->get_arg(i)->getProducesDistinctNodes();
          break;
        }
      }

      e->setProducesDistinctNodes(distinct);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_instanceof_expr(instanceof_expr *e)
{
  default_walk(e);
  PROPOGATE_SORTED_NODES(e->get_input(), e);
  PROPOGATE_DISTINCT_NODES(e->get_input(), e);
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_treat_expr(treat_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) 
  {
    PROPOGATE_SORTED_NODES(e->get_input(), e);
    PROPOGATE_DISTINCT_NODES(e->get_input(), e);
  }
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_castable_expr(castable_expr *e)
{
  default_walk(e);
  PROPOGATE_SORTED_NODES(e->get_input(), e);
  PROPOGATE_DISTINCT_NODES(e->get_input(), e);
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_cast_expr(cast_expr* e)
{
  default_walk(e);
  if (!generic_compute(e)) 
  {
    PROPOGATE_SORTED_NODES(e->get_input(), e);
    PROPOGATE_DISTINCT_NODES(e->get_input(), e);
  }
}

void DataflowAnnotationsComputer::compute_name_cast_expr(name_cast_expr* e)
{
  default_walk(e);
  if (!generic_compute(e)) 
  {
    PROPOGATE_SORTED_NODES(e->get_input(), e);
    PROPOGATE_DISTINCT_NODES(e->get_input(), e);
  }
}

void DataflowAnnotationsComputer::compute_validate_expr(validate_expr* e)
{
  default_walk(e);
  if (!generic_compute(e))
  {
    PROPOGATE_SORTED_NODES(e->get_expr(), e);
    PROPOGATE_DISTINCT_NODES(e->get_expr(), e);
  }
}

void DataflowAnnotationsComputer::compute_extension_expr(extension_expr* e)
{
  default_walk(e);
  if (!generic_compute(e)) 
  {
    PROPOGATE_SORTED_NODES(e->get_expr(), e);
    PROPOGATE_DISTINCT_NODES(e->get_expr(), e);
  }
}


/*******************************************************************************

********************************************************************************/
void DataflowAnnotationsComputer::compute_relpath_expr(relpath_expr* e)
{
  default_walk(e);

  if (!generic_compute(e)) 
  {
    TypeManager* tm = e->get_type_manager();

    ulong num_steps = (ulong)e->size();
    bool only_child_axes = true;
    ulong num_desc_axes = 0;
    ulong num_following_axes = 0;
    bool reverse_axes = false;

    for (ulong i = 1; i < num_steps; ++i) 
    {
      axis_step_expr* ase = dynamic_cast<axis_step_expr *>((*e)[i]);
      assert(ase != NULL);

      reverse_axes = reverse_axes || ase->is_reverse_axis();

      axis_kind_t axis = ase->getAxis();

      if (axis == axis_kind_descendant || axis == axis_kind_descendant_or_self)
        num_desc_axes++;

      if (axis == axis_kind_following || axis == axis_kind_following_sibling)
        num_following_axes++;

      if (axis != axis_kind_child && axis != axis_kind_attribute)
      {
        if (only_child_axes && i == num_steps - 1 && num_desc_axes == 1)
        {
          // no sort/distinct needed if path expr consists of a number of child
          // axes and a single descendant axis as the last step in the path.
          ;
        }
        else
        {
          only_child_axes = false;
        }
      }
    }

    if (only_child_axes) 
    {
      PROPOGATE_SORTED_NODES((*e)[0], e);
      PROPOGATE_DISTINCT_NODES((*e)[0], e);
    }
    else
    {
      xqtref_t crt = (*e)[0]->get_return_type();

      if (TypeOps::type_max_cnt(tm, *crt) <= 1) 
      {
        bool sorted = false;
        bool distinct = false;
        if (num_steps == 2) 
        {
          distinct = true;
          sorted = true;
        }
        else if (only_child_axes)
        {
          sorted = true;
          distinct = true;
        }
        else
        {
          if (reverse_axes == false &&
              num_desc_axes <= 1 &&
              num_following_axes == 0) 
          {
            distinct = true;
          }
        }

        e->setProducesSortedNodes((sorted ?
                                   ANNOTATION_TRUE :
                                   ANNOTATION_FALSE));

        e->setProducesDistinctNodes((distinct ?
                                     ANNOTATION_TRUE :
                                     ANNOTATION_FALSE));
      }
    }
  }
}


void DataflowAnnotationsComputer::compute_axis_step_expr(axis_step_expr* e)
{
  return;
}


void DataflowAnnotationsComputer::compute_match_expr(match_expr* e)
{
  ZORBA_ASSERT(false);
}


void DataflowAnnotationsComputer::compute_const_expr(const_expr* e)
{
  default_walk(e);
  generic_compute(e);
}


void DataflowAnnotationsComputer::compute_order_expr(order_expr* e)
{
  default_walk(e);
  generic_compute(e);
}


void DataflowAnnotationsComputer::compute_elem_expr(elem_expr* e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}


void DataflowAnnotationsComputer::compute_doc_expr(doc_expr* e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}


void DataflowAnnotationsComputer::compute_attr_expr(attr_expr* e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}


void DataflowAnnotationsComputer::compute_text_expr(text_expr* e)
{
 default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}


void DataflowAnnotationsComputer::compute_pi_expr(pi_expr* e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


SourceFinder::~SourceFinder()
{
  UdfSourcesMap::iterator ite = theUdfSourcesMap.begin();
  UdfSourcesMap::iterator end = theUdfSourcesMap.end();
  for (; ite != end; ++ite)
  {
    delete ite->second;
  }
}


/*******************************************************************************
  If the result of the given expr may contain costructed nodes, find the node-
  constructor exprs where such nodes may come from. 

  If "node" is inside a UDF, "udfCaller" contains the fo expr that invoked that
  UDF.
********************************************************************************/
void SourceFinder::findNodeSources(
    expr* node,
    UDFCallChain* udfCaller,
    std::vector<expr*>& sources)
{
  findNodeSourcesRec(node, sources, NULL);

  for (csize i = 0; i < sources.size(); ++i)
  {
    expr* source = sources[i];

    if (source->get_expr_kind() == var_expr_kind)
    {
      var_expr* varExpr = static_cast<var_expr*>(source);

      ZORBA_ASSERT(udfCaller != NULL);
      ZORBA_ASSERT(varExpr->get_kind() == var_expr::arg_var);

      sources.erase(sources.begin() + i);
      --i;

      // If this method is called to find the sources of an expr within the
      // body of a function_item. then udfCaller->theFo will be NULL. 
      if (udfCaller->theFo)
      {
        ZORBA_ASSERT(varExpr->get_udf() == udfCaller->theFo->get_func());

        fo_expr* foExpr = udfCaller->theFo;
        expr* foArg = foExpr->get_arg(varExpr->get_param_pos());
        std::vector<expr*> argSources;
        findNodeSources(foArg, udfCaller->thePrev, argSources);

        sources.insert(sources.end(), argSources.begin(), argSources.end());
      }
    }
    else
    {
      ZORBA_ASSERT(source->get_expr_kind() == doc_expr_kind ||
                   source->get_expr_kind() == elem_expr_kind);
    }
  }
}


void SourceFinder::findNodeSourcesRec(
    expr* node,
    std::vector<expr*>& sources,
    user_function* currentUdf)
{
  TypeManager* tm = node->get_type_manager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t retType = node->get_return_type();

  if (TypeOps::is_subtype(tm, *retType, *rtm.ANY_ATOMIC_TYPE_STAR, node->get_loc()))
    return;

  switch(node->get_expr_kind()) 
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
      VarSourcesMap::iterator ite = theVarSourcesMap.find(e);

      if (ite == theVarSourcesMap.end())
      {
        std::vector<expr*> varSources;
        findNodeSourcesRec(e->get_domain_expr(), varSources, currentUdf);

        ite = (theVarSourcesMap.insert(VarSourcesPair(e, varSources))).first;
      }

      std::vector<expr*>::iterator ite2 = (*ite).second.begin();
      std::vector<expr*>::iterator end2 = (*ite).second.end();
      for (; ite2 != end2; ++ite2)
      {
        if (std::find(sources.begin(), sources.end(), *ite2) == sources.end())
          sources.push_back(*ite2);
      }

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
      if (std::find(sources.begin(), sources.end(), node) == sources.end())
        sources.push_back(node);

      return;
    }

    case var_expr::prolog_var: 
    case var_expr::local_var:
    {
      VarSourcesMap::iterator ite = theVarSourcesMap.find(e);

      if (ite == theVarSourcesMap.end())
      {
        std::vector<expr*> varSources;
        theVarSourcesMap.insert(VarSourcesPair(e, varSources));

        std::vector<expr*>::const_iterator ite2 = e->setExprsBegin();
        std::vector<expr*>::const_iterator end2 = e->setExprsEnd();

        for (; ite2 != end2; ++ite2)
        {
          expr* setExpr = *ite2;

          if (setExpr->get_expr_kind() == var_decl_expr_kind)
          {
            findNodeSourcesRec(static_cast<var_decl_expr*>(setExpr)->get_init_expr(),
                               varSources,
                               currentUdf);
          }
          else
          {
            assert(setExpr->get_expr_kind() == var_set_expr_kind);

            findNodeSourcesRec(static_cast<var_set_expr*>(setExpr)->get_expr(),
                               varSources,
                               currentUdf);
          }
        }

        ite = theVarSourcesMap.find(e);
        
        (*ite).second.insert((*ite).second.end(), varSources.begin(), varSources.end());
      }

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
  {
    if (std::find(sources.begin(), sources.end(), node) == sources.end())
      sources.push_back(node);

    std::vector<expr*> enclosedExprs;
    node->get_fo_exprs_of_kind(FunctionConsts::OP_ENCLOSED_1, false, enclosedExprs);

    std::vector<expr*>::const_iterator ite = enclosedExprs.begin();
    std::vector<expr*>::const_iterator end = enclosedExprs.end();
    for (; ite != end; ++ite)
    {
      fo_expr* fo = static_cast<fo_expr*>(*ite);

      assert(fo->get_func()->getKind() == FunctionConsts::OP_ENCLOSED_1);

      findNodeSourcesRec(fo, sources, currentUdf);
    }

    return;
  }

  case attr_expr_kind:
  case text_expr_kind:
  case pi_expr_kind:
  {
    return;
  }

  case relpath_expr_kind:
  {
    relpath_expr* e = static_cast<relpath_expr *>(node);
    findNodeSourcesRec((*e)[0], sources, currentUdf);
    return;
  }

  case gflwor_expr_kind:
  case flwor_expr_kind:
  {
    flwor_expr* e = static_cast<flwor_expr *>(node);

    // We don't need to drill down to the domain exprs of variables that
    // are not referenced in the return clause.
    findNodeSourcesRec(e->get_return_expr(), sources, currentUdf);
    return;
  }

  case if_expr_kind:
  {
    if_expr* e = static_cast<if_expr *>(node);
    findNodeSourcesRec(e->get_then_expr(), sources, currentUdf);
    findNodeSourcesRec(e->get_else_expr(), sources, currentUdf);
    return;
  }

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
 
      bool recursive = (currentUdf ? currentUdf->isMutuallyRecursiveWith(udf) : false);

      UdfSourcesMap::iterator ite = theUdfSourcesMap.find(udf);

      std::vector<expr*>* udfSources;

      if (ite == theUdfSourcesMap.end() ||
          (recursive &&
           std::find(theUdfCallPath.begin(), theUdfCallPath.end(), e) ==
           theUdfCallPath.end()))
      {
        if (recursive)
          theUdfCallPath.push_back(e);

        // must do this before calling findNodeSourcesRec in order to break
        // recursion cycle
        if (ite == theUdfSourcesMap.end())
        {
          udfSources = new std::vector<expr*>;
          theUdfSourcesMap.insert(UdfSourcesPair(udf, udfSources));
        }
        else
        {
          udfSources = (*ite).second;
        }

        findNodeSourcesRec(udf->getBody(), *udfSources, udf);

        if (recursive)
          theUdfCallPath.pop_back();
      }
      else
      {
        udfSources = (*ite).second;
      }

      csize numUdfSources = udfSources->size();

      for (csize i = 0; i < numUdfSources; ++i)
      {
        expr* source = (*udfSources)[i];

        if (source->get_expr_kind() == var_expr_kind)
        {
          var_expr* argVar = static_cast<var_expr*>(source);

          ZORBA_ASSERT(argVar->get_kind() == var_expr::arg_var);

          expr* argExpr = e->get_arg(argVar->get_param_pos());

          findNodeSourcesRec(argExpr, sources, currentUdf);
        }
        else
        {
          if (std::find(sources.begin(), sources.end(), source) == sources.end())
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
          findNodeSourcesRec(e->get_arg(i), sources, currentUdf);
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
  case validate_expr_kind:
  {
    break;
  }

  case transform_expr_kind:
  {
    transform_expr* e = static_cast<transform_expr*>(node);

    findNodeSourcesRec(e->getReturnExpr(), sources, currentUdf);

    return;
  }

  case block_expr_kind:
  {
    block_expr* e = static_cast<block_expr*>(node);

    findNodeSourcesRec((*e)[e->size()-1], sources, currentUdf);

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

      findNodeSourcesRec(ex->get_expr(), sources, currentUdf);
    }

    break;
  }

  case eval_expr_kind:
  {
    eval_expr* e = static_cast<eval_expr*>(node);
    e->setNodeCopy(true);
    return;
  }

  case dynamic_function_invocation_expr_kind:
  {
    // Conservatively assume that the function item that is going to be executed
    // is going to propagate its inputs, so find the sources in the arguments.
    // TODO: look for function_item_expr in the subtree to check if this assumption
    // is really true. 
    dynamic_function_invocation_expr* e = 
    static_cast<dynamic_function_invocation_expr*>(node);

    const std::vector<expr_t>& args = e->get_args();

    FOR_EACH(std::vector<expr_t>, ite, args)
    {
      std::vector<expr*> sources;
      findNodeSourcesRec((*ite).getp(), sources, currentUdf);
    }

    break;
  }

  case function_item_expr_kind:
  {
    //function_item_expr* e = static_cast<function_item_expr*>(node);
    // TODO
    return;
  }

#if 0
  case debugger_expr_kind:
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
  case while_expr_kind:
  case exit_expr_kind:
  case flowctl_expr_kind:
#ifndef ZORBA_NO_FULL_TEXT
  case ft_expr_kind:
#endif
  default:
    ZORBA_ASSERT(false);
  }

  ExprIterator iter(node);
  while(!iter.done()) 
  {
    expr* child = (*iter).getp();
    if (child != NULL) 
    {
      findNodeSourcesRec(child, sources, currentUdf);
    }
    iter.next();
  }
}

}
/* vim:set et sw=2 ts=2: */
