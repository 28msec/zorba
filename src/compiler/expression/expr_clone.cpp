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
#include "compiler/expression/expr_base.h"
#include "compiler/expression/update_exprs.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/json_exprs.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#include "compiler/expression/expr_manager.h"

#include "compiler/api/compilercb.h"

#include "functions/function.h"
#include "functions/udf.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

namespace zorba
{

#define CLONE(e, udf, subst) ((e) == NULL ? NULL : (e)->clone(udf, subst))


/*******************************************************************************

********************************************************************************/
expr* expr::clone(user_function* udf) const
{
  substitution_t subst;
  return clone(udf, subst);
}


expr* expr::clone(user_function* udf, substitution_t& subst) const
{
  expr* newExpr = NULL;

  switch (get_expr_kind())
  {
  case const_expr_kind:
  {
    const const_expr* e = static_cast<const const_expr*>(this);

    newExpr = theCCB->theEM->
    create_const_expr(theSctx, udf, theLoc, e->theValue);

    break;
  }
  case var_expr_kind:
  {
    expr::subst_iter_t i = subst.find(this);

    if (i == subst.end())
      newExpr = const_cast<expr*>(this);
    else
      newExpr = i->second;

    break;
  }
  case doc_expr_kind:
  {
    const doc_expr* e = static_cast<const doc_expr*>(this);

    newExpr = theCCB->theEM->
    create_doc_expr(theSctx,
                    udf,
                    theLoc,
                    CLONE(e->getContent(), udf, subst),
                    e->theCopyInputNodes);
    break;
  }
  case elem_expr_kind:
  {
    const elem_expr* e = static_cast<const elem_expr*>(this);

    newExpr = theCCB->theEM->
    create_elem_expr(theSctx,
                     udf,
                     theLoc,
                     CLONE(e->getQNameExpr(), udf, subst),
                     CLONE(e->getAttrs(), udf, subst),
                     CLONE(e->getContent(), udf, subst),
                     e->getNSCtx(),
                     e->theCopyInputNodes);
    break;
  }
  case attr_expr_kind:
  {
    const attr_expr* e = static_cast<const attr_expr*>(this);

    newExpr = theCCB->theEM->
    create_attr_expr(theSctx,
                     udf,
                     theLoc,
                     CLONE(e->getQNameExpr(), udf, subst),
                     CLONE(e->getValueExpr(), udf, subst));
    break;
  }
  case text_expr_kind:
  {
    const text_expr* e = static_cast<const text_expr*>(this);

    newExpr = theCCB->theEM->
    create_text_expr(theSctx,
                     udf,
                     theLoc,
                     e->get_type(),
                     CLONE(e->get_text(), udf, subst));
    break;
  }
  case pi_expr_kind:
  {
    const pi_expr* e = static_cast<const pi_expr*>(this);

    newExpr = theCCB->theEM->
    create_pi_expr(theSctx,
                   udf,
                   theLoc,
                   CLONE(e->get_target_expr(), udf, subst),
                   CLONE(e->get_content_expr(), udf, subst));
    break;
  }
#ifdef ZORBA_WITH_JSON
  case json_direct_object_expr_kind:
  {
    const json_direct_object_expr* e = static_cast<const json_direct_object_expr*>(this);

    std::vector<expr*> names;
    std::vector<expr*> values;

    names.reserve(e->theNames.size());
    values.reserve(e->theValues.size());

    std::vector<expr*>::const_iterator ite = e->theNames.begin();
    std::vector<expr*>::const_iterator end = e->theNames.end();
    for (; ite != end; ++ite)
    {
      names.push_back((*ite)->clone(udf, subst));
    }

    ite = e->theValues.begin();
    end = e->theValues.end();
    for (; ite != end; ++ite)
    {
      values.push_back((*ite)->clone(udf, subst));
    }

    newExpr = theCCB->theEM->
    create_json_direct_object_expr(theSctx, udf, theLoc, names, values);

    break;
  }
  case json_object_expr_kind:
  {
    const json_object_expr* e = static_cast<const json_object_expr*>(this);

    newExpr = theCCB->theEM->
    create_json_object_expr(theSctx,
                            udf,
                            theLoc,
                            (e->theContentExpr ?
                             e->theContentExpr->clone(udf, subst) : NULL),
                            e->theAccumulate);

    break;
  }
  case json_array_expr_kind:
  {
    const json_array_expr* e = static_cast<const json_array_expr*>(this);

    newExpr = theCCB->theEM->
    create_json_array_expr(theSctx,
                           udf,
                           theLoc,
                           e->theContentExpr->clone(udf, subst));

    break;
  }
#endif

  case relpath_expr_kind:
  {
    const relpath_expr* e = static_cast<const relpath_expr*>(this);

    relpath_expr* cloneExpr = theCCB->theEM->
    create_relpath_expr(theSctx, udf, theLoc);

    for (csize i = 0; i < e->size(); ++i)
    {
      cloneExpr->add_back((*e)[i]->clone(udf, subst));
    }

    newExpr = cloneExpr;
    break;
  }
  case axis_step_expr_kind:
  {
    const axis_step_expr* e = static_cast<const axis_step_expr*>(this);

    axis_step_expr* cloneExpr = theCCB->theEM->
    create_axis_step_expr(theSctx, udf, theLoc);

    cloneExpr->setAxis(e->getAxis());
    cloneExpr->setTest(static_cast<match_expr*>(CLONE(e->getTest(), udf, subst)));
    cloneExpr->theReverseOrder = e->theReverseOrder;

    newExpr = cloneExpr;
    break;
  }
  case match_expr_kind:
  {
    const match_expr* e = static_cast<const match_expr*>(this);

    match_expr* cloneExpr = theCCB->theEM->
    create_match_expr(theSctx, udf, theLoc);

    cloneExpr->setTestKind(e->getTestKind());
    cloneExpr->setDocTestKind(e->getDocTestKind());
    cloneExpr->setWildName(e->getWildName());
    cloneExpr->setWildKind(e->getWildKind());
    cloneExpr->setQName(e->getQName());
    cloneExpr->setTypeName(e->getTypeName());
    cloneExpr->setNilledAllowed(e->getNilledAllowed());

    newExpr = cloneExpr;
    break;
  }

  case flwor_expr_kind:
  case gflwor_expr_kind:
  {
    const flwor_expr* e = static_cast<const flwor_expr*>(this);

    flwor_expr* cloneExpr = theCCB->theEM->
    create_flwor_expr(theSctx, udf, theLoc, e->is_general());

    csize numClauses = e->num_clauses();

    for (csize i = 0; i < numClauses; ++i)
    {
      flwor_clause* cloneClause = e->theClauses[i]->clone(udf, subst);

      cloneExpr->add_clause(cloneClause, false);
    }

    cloneExpr->set_return_expr(e->theReturnExpr->clone(udf, subst));

    newExpr = cloneExpr;
    break;
  }
  case if_expr_kind:
  {
    const if_expr* e = static_cast<const if_expr*>(this);

    newExpr = theCCB->theEM->
    create_if_expr(theSctx,
                   udf,
                   theLoc,
                   e->get_cond_expr()->clone(udf, subst),
                   e->get_then_expr()->clone(udf, subst),
                   e->get_else_expr()->clone(udf, subst));
    break;
  }
  case trycatch_expr_kind:
  {
    const trycatch_expr* e = static_cast<const trycatch_expr*>(this);

    trycatch_expr* cloneExpr = theCCB->theEM->
    create_trycatch_expr(theSctx, udf, theLoc, e->theTryExpr->clone(udf, subst));

    for (std::vector<expr*>::const_iterator ite = e->theCatchExprs.begin();
         ite != e->theCatchExprs.end();
         ++ite)
    {
      cloneExpr->add_catch_expr((*ite)->clone(udf, subst));
    }

    for (csize i = 0; i < e->clause_count(); ++i)
    {
      cloneExpr->add_clause(e->theCatchClauses[i]->clone(subst));
    }

    newExpr = cloneExpr;
    break;
  }
  case fo_expr_kind:
  {
    const fo_expr* e = static_cast<const fo_expr*>(this);

    if (e->get_func()->getKind() == FunctionConsts::STATIC_COLLECTIONS_DML_COLLECTION_1)
    {
      expr::subst_iter_t i = subst.find(this);

      if (i != subst.end())
      {
        newExpr = i->second;
        break;
      }
    }

    fo_expr* cloneExpr = theCCB->theEM->
    create_fo_expr(theSctx, udf, theLoc, e->get_func());

    cloneExpr->theArgs.reserve(e->theArgs.size());

    for (csize i = 0; i < e->theArgs.size(); ++i)
      cloneExpr->theArgs.push_back(e->theArgs[i]->clone(udf, subst));

    cloneExpr->theScriptingKind  = e->theScriptingKind;

    newExpr = cloneExpr;
    break;
  }
  case dynamic_function_invocation_expr_kind:
  {
    const dynamic_function_invocation_expr* e =
    static_cast<const dynamic_function_invocation_expr*>(this);

    checked_vector<expr*> newArgs;
    for (checked_vector<expr*>::const_iterator ite = e->theArgs.begin();
         ite != e->theArgs.end();
         ++ite)
    {
      newArgs.push_back((*ite)->clone(udf, subst));
    }
    
    checked_vector<expr*> newDotVars;
    for (checked_vector<expr*>::const_iterator ite = e->theDotVars.begin();
         ite != e->theDotVars.end();
         ++ite)
    {
      newDotVars.push_back((*ite)->clone(udf, subst));
    }

    newExpr = theCCB->theEM->
    create_dynamic_function_invocation_expr(theSctx,
                                            udf,
                                            theLoc,
                                            e->theExpr->clone(udf, subst),
                                            newArgs,
                                            newDotVars);
    break;
  }
  case argument_placeholder_expr_kind:
  {
    newExpr = theCCB->theEM->create_argument_placeholder_expr(theSctx, udf, theLoc);
    break;
  }
  case function_item_expr_kind:
  {
    const function_item_expr* e = static_cast<const function_item_expr*>(this);

    function_item_expr* cloneExpr = theCCB->theEM->
    create_function_item_expr(theSctx,
                              udf,
                              get_loc(),
                              e->theDynamicFunctionInfo->theClosureSctx,
                              e->theDynamicFunctionInfo->theFunction,
                              e->theDynamicFunctionInfo->theFunction->getName(),
                              e->theDynamicFunctionInfo->theArity,
                              e->is_inline(),
                              e->needs_context_item());

    std::vector<expr*>::const_iterator varIter = e->theDynamicFunctionInfo->theScopedVarsValues.begin();
    std::vector<var_expr*>::const_iterator substVarIter = e->theDynamicFunctionInfo->theSubstVarsValues.begin();
    std::vector<store::Item_t>::const_iterator nameIter = e->theDynamicFunctionInfo->theScopedVarsNames.begin();
    std::vector<int>::const_iterator isGlobalIter = e->theDynamicFunctionInfo->theIsGlobalVar.begin();
    for (; varIter != e->theDynamicFunctionInfo->theScopedVarsValues.end(); ++varIter, ++substVarIter, ++nameIter, ++isGlobalIter)
    {
      cloneExpr->add_variable((*varIter) ? (*varIter)->clone(udf, subst) : NULL,
                              (*substVarIter) ? static_cast<var_expr*>((*substVarIter)->clone(udf, subst)) : NULL,
                              *nameIter,
                              *isGlobalIter);
    }

    newExpr = cloneExpr;
    break;
  }
  case castable_expr_kind:
  {
    const castable_expr* e = static_cast<const castable_expr*>(this);

    newExpr = theCCB->theEM->
    create_castable_expr(theSctx,
                         udf,
                         theLoc,
                         e->get_input()->clone(udf, subst),
                         e->get_target_type(),
                         e->allows_empty_input());

    break;
  }
  case cast_expr_kind:
  {
    const cast_expr* e = static_cast<const cast_expr*>(this);

    newExpr = theCCB->theEM->
    create_cast_expr(theSctx,
                     udf,
                     theLoc,
                     e->get_input()->clone(udf, subst),
                     e->get_target_type(),
                     e->allows_empty_input());
    break;
  }
  case instanceof_expr_kind:
  {
    const instanceof_expr* e = static_cast<const instanceof_expr*>(this);

    newExpr = theCCB->theEM->
    create_instanceof_expr(theSctx,
                           udf,
                           theLoc,
                           e->get_input()->clone(udf, subst),
                           e->get_target_type());
    break;
  }
  case treat_expr_kind:
  {
    const treat_expr* e = static_cast<const treat_expr*>(this);

    newExpr = theCCB->theEM->
    create_treat_expr(theSctx,
                      udf,
                      theLoc,
                      e->get_input()->clone(udf, subst),
                      e->get_target_type(),
                      e->get_err(),
                      e->get_check_prime(),
                      e->get_qname());
    break;
  }
  case promote_expr_kind:
  {
    const promote_expr* e = static_cast<const promote_expr*>(this);

    newExpr = theCCB->theEM->
    create_promote_expr(theSctx,
                        udf,
                        theLoc,
                        e->get_input()->clone(udf, subst),
                        e->get_target_type(),
                        e->theErrorKind,
                        e->theQName.getp());
    break;
  }
  case name_cast_expr_kind:
  {
    const name_cast_expr* e = static_cast<const name_cast_expr*>(this);

    newExpr = theCCB->theEM->
    create_name_cast_expr(theSctx,
                          udf,
                          theLoc,
                          e->get_input()->clone(udf, subst),
                          e->getNSCtx(),
                          e->theIsAttrName);
    break;
  }
  case validate_expr_kind:
  {
    const validate_expr* e = static_cast<const validate_expr*>(this);

    newExpr = theCCB->theEM->
    create_validate_expr(theSctx,
                         udf,
                         theLoc,
                         e->get_valmode(),
                         const_cast<store::Item*>(e->get_type_name()),
                         e->get_input()->clone(udf, subst),
                         e->get_typemgr());

    break;
  }
  case extension_expr_kind:
  {
    const extension_expr* e = static_cast<const extension_expr*>(this);

    extension_expr* cloneExpr;
    if(e->theExpr == 0)
    {
      cloneExpr = theCCB->theEM->create_extension_expr(theSctx, udf, theLoc);
    }
    else
    {
      cloneExpr = theCCB->theEM->
      create_extension_expr(theSctx, udf, theLoc, e->theExpr->clone(udf, subst));
    }

    // pragma doesn't contain expressions. Thus, it is not cloned.
    for (std::vector<pragma*>::const_iterator lIter = e->thePragmas.begin();
         lIter != e->thePragmas.end();
         ++lIter)
    {
      cloneExpr->add(*lIter);
    }

    newExpr = cloneExpr;
    break;
  }
  case order_expr_kind:
  {
    const order_expr* e = static_cast<const order_expr*>(this);

    newExpr = theCCB->theEM->
    create_order_expr(theSctx,
                      udf,
                      theLoc,
                      e->get_type(),
                      e->get_input()->clone(udf, subst));
    break;
  }
#ifndef ZORBA_NO_FULL_TEXT
  case ft_expr_kind:
  {
    const ftcontains_expr* e = static_cast<const ftcontains_expr*>(this);

    newExpr = theCCB->theEM->
    create_ftcontains_expr(theSctx,
                           udf,
                           theLoc,
                           e->range_->clone(udf, subst),
                           e->ftselection_->clone(udf, subst).release(),
                           (e->ftignore_ == NULL ? 0 : e->ftignore_->clone(udf, subst)));

    break;
  }
#endif /* ZORBA_NO_FULL_TEXT */

  case delete_expr_kind:
  {
    const delete_expr* e = static_cast<const delete_expr*>(this);

    newExpr = theCCB->theEM->
    create_delete_expr(theSctx, udf, theLoc, e->getTargetExpr()->clone(udf, subst));

    break;
  }
  case insert_expr_kind:
  {
    const insert_expr* e = static_cast<const insert_expr*>(this);

    newExpr = theCCB->theEM->
    create_insert_expr(theSctx,
                       udf,
                       theLoc,
                       e->getType(),
                       e->getSourceExpr()->clone(udf, subst),
                       e->getTargetExpr()->clone(udf, subst));
    break;
  }
  case rename_expr_kind:
  {
    const rename_expr* e = static_cast<const rename_expr*>(this);

    newExpr = theCCB->theEM->
    create_rename_expr(theSctx,
                       udf,
                       theLoc,
                       e->getTargetExpr()->clone(udf, subst),
                       e->getNameExpr()->clone(udf, subst));
    break;
  }
  case replace_expr_kind:
  {
    const zorba::replace_expr* e = static_cast<const zorba::replace_expr*>(this);

    newExpr = theCCB->theEM->
    create_replace_expr(theSctx,
                        udf,
                        theLoc,
                        e->getType(),
                        e->getTargetExpr()->clone(udf, subst),
                        e->getReplaceExpr()->clone(udf, subst));
    break;
  }
  case transform_expr_kind:
  {
    const transform_expr* e = static_cast<const transform_expr*>(this);

    ZORBA_ASSERT(e->theModifyExpr && e->theReturnExpr);

    transform_expr* cloneExpr = theCCB->theEM->
    create_transform_expr(theSctx, udf, theLoc);

    for (std::vector<copy_clause*>::const_iterator ite = e->theCopyClauses.begin();
         ite != e->theCopyClauses.end();
         ++ite)
    {
      cloneExpr->add_back((*ite)->clone(udf, subst));
    }

    cloneExpr->setModifyExpr(e->theModifyExpr->clone(udf, subst));
    cloneExpr->setReturnExpr(e->theReturnExpr->clone(udf, subst));

    newExpr = cloneExpr;
    break;
  }

  case block_expr_kind:
  {
    const block_expr* e = static_cast<const block_expr*>(this);

    checked_vector<expr*> seq2;
    for (csize i = 0; i < e->theArgs.size(); ++i)
    {
      seq2.push_back(e->theArgs[i]->clone(udf, subst));

      if (e->theArgs[i]->get_expr_kind() == var_decl_expr_kind)
      {
        var_decl_expr* varDeclExpr = static_cast<var_decl_expr*>(e->theArgs[i]);
        var_expr* varExpr = varDeclExpr->get_var_expr();
        varExpr->set_block_expr(e);
      }
    }

    newExpr = theCCB->theEM->
    create_block_expr(theSctx, udf, theLoc, true, seq2, NULL);

    break;
  }
  case var_decl_expr_kind:
  {
    const var_decl_expr* e = static_cast<const var_decl_expr*>(this);

    var_expr* varCopy = theCCB->theEM->create_var_expr(udf, *e->theVarExpr);
    subst[e->theVarExpr] = varCopy;

    newExpr = theCCB->theEM->
    create_var_decl_expr(theSctx,
                         udf,
                         theLoc,
                         varCopy,
                         (e->theExpr ? e->theExpr->clone(udf, subst) : NULL));
    
    break;
  }
  case var_set_expr_kind:
  {
    const var_set_expr* e = static_cast<const var_set_expr*>(this);

    expr* varClone = e->theVarExpr->clone(udf, subst);

    ZORBA_ASSERT(varClone->get_expr_kind() == var_expr_kind);

    newExpr = theCCB->theEM->
    create_var_set_expr(theSctx,
                        udf,
                        theLoc,
                        static_cast<var_expr*>(varClone),
                        e->theExpr->clone(udf, subst));
    break;
  }
  case apply_expr_kind:
  {
    const apply_expr* e = static_cast<const apply_expr*>(this);

    newExpr = theCCB->theEM->
    create_apply_expr(theSctx,
                      udf,
                      theLoc,
                      e->theExpr->clone(udf, subst),
                      e->theDiscardXDM);

    break;
  }
  case exit_expr_kind:
  {
    const exit_expr* e = static_cast<const exit_expr*>(this);

    newExpr = theCCB->theEM->
    create_exit_expr(theSctx, udf, theLoc, e->get_expr()->clone(udf, subst));

    subst[this] = newExpr;

    break;
  }
  case exit_catcher_expr_kind:
  {
    const exit_catcher_expr* e = static_cast<const exit_catcher_expr*>(this);

    expr* clonedInput = e->get_expr()->clone(udf, subst);

    std::vector<expr*> clonedExits;
    std::vector<expr*>::const_iterator ite = e->theExitExprs.begin();
    std::vector<expr*>::const_iterator end = e->theExitExprs.end();
    for (; ite != end; ++ite)
    {
      assert(subst.find(*ite) != subst.end());

      clonedExits.push_back(subst[*ite]);
    }

    newExpr = theCCB->theEM->
    create_exit_catcher_expr(theSctx, udf, theLoc, clonedInput, clonedExits);

    break;
  }
  case flowctl_expr_kind:
  {
    const flowctl_expr* e = static_cast<const flowctl_expr*>(this);

    newExpr = theCCB->theEM->
    create_flowctl_expr(theSctx, udf, theLoc, e->get_action());

    break;
  }
  case while_expr_kind:
  {
    const while_expr* e = static_cast<const while_expr*>(this);

    newExpr = theCCB->theEM->
    create_while_expr(theSctx, udf, theLoc, e->get_body()->clone(udf, subst));

    break;
  }
  case eval_expr_kind:
  {
    const eval_expr* e = static_cast<const eval_expr*>(this);

    newExpr = theCCB->theEM->
    create_eval_expr(theSctx,
                     udf,
                     theLoc,
                     e->theExpr->clone(udf, subst),
                     e->theInnerScriptingKind,
                     e->theNSCtx.getp());

    eval_expr* newEval = static_cast<eval_expr*>(newExpr);

    newEval->setNodeCopy(e->theDoNodeCopy);

    newEval->theOuterVarNames = e->theOuterVarNames;
    newEval->theOuterVarTypes = e->theOuterVarTypes;

    csize numVars = e->theOuterVarNames.size();

    newEval->theArgs.resize(numVars);

    for (csize i = 0; i < numVars; ++i)
    {
      newEval->theArgs[i] = e->theArgs[i]->clone(udf, subst);
    }

    break;
  }
  case wrapper_expr_kind:
  {
    const wrapper_expr* e = static_cast<const wrapper_expr*>(this);

    expr* wrappedClone = e->theInput->clone(udf, subst);

    if (e->theInput->get_expr_kind() == var_expr_kind &&
        wrappedClone->get_expr_kind() != var_expr_kind)
    {
      newExpr = wrappedClone;
    }
    else
    {
      newExpr = theCCB->theEM->create_wrapper_expr(theSctx, udf, theLoc, wrappedClone);
    }

    break;
  }
  case function_trace_expr_kind:
  {
    const function_trace_expr* e = static_cast<const function_trace_expr*>(this);

    function_trace_expr* cloneExpr = theCCB->theEM->
    create_function_trace_expr(udf, e->theInput->clone(udf, subst));

    cloneExpr->theFunctionName = e->theFunctionName;
    cloneExpr->theFunctionLocation = e->theFunctionLocation;
    cloneExpr->theFunctionCallLocation = e->theFunctionCallLocation;
    cloneExpr->theFunctionArity = e->theFunctionArity;

    newExpr = cloneExpr;
    break;
  }
  case debugger_expr_kind:
  default:
  {
    RAISE_ERROR(zerr::ZXQP0003_INTERNAL_ERROR, theLoc,
    ERROR_PARAMS(ZED(CloneNotImplemented)));
  }
  }

  if (containsPragma())
  {
    newExpr->setContainsPragma(ANNOTATION_TRUE);

    std::vector<pragma*> pragmas;
    theCCB->lookup_pragmas(this, pragmas);

    for (csize i = 0; i < pragmas.size(); ++i)
    {
      theCCB->add_pragma(newExpr, pragmas[i]);
    }
  }

  return newExpr;
}

}
