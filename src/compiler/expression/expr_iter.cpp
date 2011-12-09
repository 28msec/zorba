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

#include <zorba/config.h>

#include "compiler/expression/expr_iter.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/json_exprs.h"
#include "compiler/expression/update_exprs.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/function_item_expr.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#include "compiler/expression/ftnode_visitor.h"
#endif /* ZORBA_NO_FULL_TEXT */

#include "diagnostics/assert.h"


namespace zorba
{

#define EXPR_ITER_BEGIN() switch (theState) { case 0:

#define EXPR_ITER_END()   theCurrentChild = expr::iter_done; }

#define EXPR_ITER_NEXT(subExprHandle)                               \
do                                                                  \
{                                                                   \
  theState = __LINE__;                                              \
  theCurrentChild = reinterpret_cast<expr_t*>(&(subExprHandle));    \
                                                                    \
  if ((subExprHandle) != NULL)                                      \
  {                                                                 \
    return;                                                         \
  }                                                                 \
                                                                    \
case __LINE__:;                                                     \
                                                                    \
} while (0)


#define EXPR_ITER_NEXT2(subExprHandleP)                             \
do                                                                  \
{                                                                   \
  theState = __LINE__;                                              \
  theCurrentChild = (subExprHandleP);                               \
                                                                    \
  if (*(subExprHandleP) != NULL)                                    \
  {                                                                 \
    return;                                                         \
  }                                                                 \
                                                                    \
case __LINE__:;                                                     \
                                                                    \
} while (0)



ExprIterator::ExprIterator(expr* e)
  :
  theExpr(e),
  theCurrentChild(NULL),
  theState(0)
{
#ifndef ZORBA_NO_FULL_TEXT
  if (e->get_expr_kind() == ft_expr_kind)
  {
    ftcontains_expr* ftExpr = static_cast<ftcontains_expr*>(e);

    FTNodeExprCollector exprCollector;
    ftExpr->get_ftselection()->accept(exprCollector);

    theFTSelectionExprs.swap(exprCollector.get_expr_list());
  }
#endif /* ZORBA_NO_FULL_TEXT */

  next();
}


void ExprIterator::next()
{
  flwor_clause* c;
  window_clause* wc;
  orderby_clause* oc;
  group_clause* gc;
  flwor_wincond* wincond;

  switch (theExpr->get_expr_kind())
  {
  case flwor_expr_kind:
  case gflwor_expr_kind:
  {
    flwor_expr* flworExpr = static_cast<flwor_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    theClausesBegin = flworExpr->theClauses.begin();
    theClausesIter = flworExpr->theClauses.begin();
    theClausesEnd = flworExpr->theClauses.end();

    for (; theClausesIter != theClausesEnd; ++(theClausesIter))
    {
      c = (theClausesIter)->getp();

      if (c->get_kind() == flwor_clause::for_clause)
      {
        EXPR_ITER_NEXT(static_cast<for_clause *>(c)->theDomainExpr);
      }

      else if (c->get_kind() == flwor_clause::let_clause)
      {
        EXPR_ITER_NEXT(static_cast<let_clause *>(c)->theDomainExpr);
      }

      else if (c->get_kind() == flwor_clause::window_clause)
      {
        for (theWincondIter = 0; theWincondIter < 2; ++theWincondIter)
        {
          wc = static_cast<window_clause *>(theClausesIter->getp());

          wincond = (theWincondIter == 0 ?
                     wc->theWinStartCond.getp() :
                     wc->theWinStopCond.getp());

          if (wincond != 0)
            EXPR_ITER_NEXT(wincond->theCondExpr);
        }

        wc = static_cast<window_clause *>(theClausesIter->getp());

        EXPR_ITER_NEXT(wc->theDomainExpr);
      }

      else if (c->get_kind() == flwor_clause::where_clause)
      {
        EXPR_ITER_NEXT(static_cast<where_clause *>(c)->theWhereExpr);
      }

      else if (c->get_kind() == flwor_clause::group_clause)
      {
        gc = static_cast<group_clause *>(c);

        theGroupVarsIter = gc->theGroupVars.begin();
        theGroupVarsEnd = gc->theGroupVars.end();
        theNonGroupVarsIter = gc->theNonGroupVars.begin();
        theNonGroupVarsEnd = gc->theNonGroupVars.end();

        for (; theGroupVarsIter != theGroupVarsEnd; ++theGroupVarsIter)
        {
          EXPR_ITER_NEXT((*theGroupVarsIter).first);
        }

        for (;
             theNonGroupVarsIter != theNonGroupVarsEnd;
             ++theNonGroupVarsIter)
        {
          EXPR_ITER_NEXT((*theNonGroupVarsIter).first);
        }
      }

      else if (c->get_kind() == flwor_clause::order_clause)
      {
        oc = static_cast<orderby_clause *>(c);

        theArgsIter = oc->theOrderingExprs.begin();
        theArgsEnd = oc->theOrderingExprs.end();

        for (; theArgsIter != theArgsEnd; ++theArgsIter)
        {
          EXPR_ITER_NEXT(*theArgsIter);
        }
      }

      if (theClausesEnd != flworExpr->theClauses.end())
      {
        ulong pos = (ulong)(theClausesIter - theClausesBegin);
        if (pos >= flworExpr->num_clauses())
          break;

        theClausesEnd = flworExpr->theClauses.end();
        theClausesIter = flworExpr->theClauses.begin() + pos;
      }
    }

    EXPR_ITER_NEXT(flworExpr->theReturnExpr);

    EXPR_ITER_END();
    break;
  }

  case relpath_expr_kind:
  {
    relpath_expr* pathExpr = static_cast<relpath_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    theArgsIter = pathExpr->theSteps.begin();
    theArgsEnd = pathExpr->theSteps.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    break;
  }

  case axis_step_expr_kind:
  {
    axis_step_expr* axisExpr = static_cast<axis_step_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(axisExpr->theNodeTest);

    EXPR_ITER_END();
    break;
  }

  case match_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_END();
    break;
  }

  case var_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_END();
    break;
  }

  case wrapper_expr_kind:
  {
    wrapper_expr* wrapperExpr = static_cast<wrapper_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(wrapperExpr->theWrappedExpr);

    EXPR_ITER_END();
    break;
  }

  case const_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_END();
    break;
  }


  case fo_expr_kind:
  {
    fo_expr* foExpr = static_cast<fo_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    theArgsIter = foExpr->theArgs.begin();
    theArgsEnd = foExpr->theArgs.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    break;
  }

  case cast_expr_kind:
  case treat_expr_kind:
  case promote_expr_kind:
  case instanceof_expr_kind:
  case castable_expr_kind:
  {
    cast_or_castable_base_expr* castExpr =
    static_cast<cast_or_castable_base_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(castExpr->theInputExpr);

    EXPR_ITER_END();
    break;
  }

  case name_cast_expr_kind:
  {
    name_cast_expr* nameCastExpr = static_cast<name_cast_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(nameCastExpr->theInputExpr);

    EXPR_ITER_END();
    break;
  }

  case doc_expr_kind:
  {
    doc_expr* docExpr = static_cast<doc_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(docExpr->theContent);

    EXPR_ITER_END();
    break;
  }

  case elem_expr_kind:
  {
    elem_expr* elemExpr = static_cast<elem_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(elemExpr->theQNameExpr);
    EXPR_ITER_NEXT(elemExpr->theAttrs);
    EXPR_ITER_NEXT(elemExpr->theContent);

    EXPR_ITER_END();
    break;
  }

  case attr_expr_kind:
  {
    attr_expr* attrExpr = static_cast<attr_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(attrExpr->theQNameExpr);
    EXPR_ITER_NEXT(attrExpr->theValueExpr);

    EXPR_ITER_END();
    break;
  }

  case text_expr_kind:
  {
    text_expr* textExpr = static_cast<text_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(textExpr->theContentExpr);

    EXPR_ITER_END();
    break;
  }

  case pi_expr_kind:
  {
    pi_expr* piExpr = static_cast<pi_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(piExpr->theTargetExpr);
    EXPR_ITER_NEXT(piExpr->theContentExpr);

    EXPR_ITER_END();
    break;
  }

#ifdef ZORBA_WITH_JSON
  case json_pair_expr_kind:
  {
    json_pair_expr* e = static_cast<json_pair_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(e->theNameExpr);
    EXPR_ITER_NEXT(e->theValueExpr);

    EXPR_ITER_END();
    break;
  }

  case json_object_expr_kind:
  {
    json_object_expr* e = static_cast<json_object_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(e->theContentExpr);

    EXPR_ITER_END();
    break;
  }

  case json_array_expr_kind:
  {
    json_array_expr* e = static_cast<json_array_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(e->theContentExpr);

    EXPR_ITER_END();
    break;
  }
#endif

  case if_expr_kind:
  {
    if_expr* ifExpr = static_cast<if_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(ifExpr->theCondExpr);
    EXPR_ITER_NEXT(ifExpr->theThenExpr);
    EXPR_ITER_NEXT(ifExpr->theElseExpr);

    EXPR_ITER_END();
    break;
  }

  case order_expr_kind:
  {
    order_expr* ordExpr = static_cast<order_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(ordExpr->theExpr);

    EXPR_ITER_END();
    break;
  }

  case validate_expr_kind:
  {
    validate_expr* valExpr = static_cast<validate_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(valExpr->theExpr);

    EXPR_ITER_END();
    break;
  }

  case extension_expr_kind:
  {
    extension_expr* extExpr = static_cast<extension_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(extExpr->theExpr);

    EXPR_ITER_END();
    break;
  }

  case trycatch_expr_kind:
  {
    trycatch_expr* tcExpr = static_cast<trycatch_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(tcExpr->theTryExpr);

    theArgsIter = tcExpr->theCatchExprs.begin();
    theArgsEnd = tcExpr->theCatchExprs.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    break;
  }

  case function_item_expr_kind:
  {
    function_item_expr* fiExpr = static_cast<function_item_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    theArgsIter = fiExpr->theScopedVariables.begin();
    theArgsEnd = fiExpr->theScopedVariables.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    break;
  }

  case dynamic_function_invocation_expr_kind:
  {
    dynamic_function_invocation_expr* dfiExpr =
    static_cast<dynamic_function_invocation_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(dfiExpr->theExpr);

    theArgsIter = dfiExpr->theArgs.begin();
    theArgsEnd = dfiExpr->theArgs.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    break;
  }

  case insert_expr_kind:
  {
    insert_expr* insExpr = static_cast<insert_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(insExpr->theSourceExpr);
    EXPR_ITER_NEXT(insExpr->theTargetExpr);

    EXPR_ITER_END();
    break;
  }

  case delete_expr_kind:
  {
    delete_expr* delExpr = static_cast<delete_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(delExpr->theTargetExpr);

    EXPR_ITER_END();
    break;
  }

  case replace_expr_kind:
  {
    replace_expr* repExpr = static_cast<replace_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(repExpr->theTargetExpr);
    EXPR_ITER_NEXT(repExpr->theReplaceExpr);

    EXPR_ITER_END();
    break;
  }

  case rename_expr_kind:
  {
    rename_expr* renExpr = static_cast<rename_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(renExpr->theTargetExpr);
    EXPR_ITER_NEXT(renExpr->theNameExpr);

    EXPR_ITER_END();
    break;
  }

  case transform_expr_kind:
  {
    transform_expr* trfExpr = static_cast<transform_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    theCopyClauseIter = trfExpr->theCopyClauses.begin();
    theCopyClauseEnd = trfExpr->theCopyClauses.end();
    for (; theCopyClauseIter != theCopyClauseEnd; ++theCopyClauseIter)
    {
      EXPR_ITER_NEXT((*theCopyClauseIter)->theExpr);
    }

    EXPR_ITER_NEXT(trfExpr->theModifyExpr);
    EXPR_ITER_NEXT(trfExpr->theReturnExpr);

    EXPR_ITER_END();
    break;
  }

  case block_expr_kind:
  {
    block_expr* seqExpr = static_cast<block_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    theArgsIter = seqExpr->theArgs.begin();
    theArgsEnd = seqExpr->theArgs.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    break;
  }

  case apply_expr_kind:
  {
    apply_expr* applyExpr = static_cast<apply_expr*>(theExpr);
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(applyExpr->theExpr);
    EXPR_ITER_END();
    break;
  }

  case var_decl_expr_kind:
  {
    var_decl_expr* varDeclExpr = static_cast<var_decl_expr*>(theExpr);
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(varDeclExpr->theInitExpr);
    EXPR_ITER_END();
    break;
  }

  case var_set_expr_kind:
  {
    var_set_expr* varSetExpr = static_cast<var_set_expr*>(theExpr);
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(varSetExpr->theExpr);
    EXPR_ITER_END();
    break;
  }

  case flowctl_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_END();
    break;
  }

  case while_expr_kind:
  {
    while_expr* whileExpr = static_cast<while_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(whileExpr->theBody);

    EXPR_ITER_END();
    break;
  }

  case exit_expr_kind:
  {
    exit_expr* exitExpr = static_cast<exit_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(exitExpr->theExpr);

    EXPR_ITER_END();
    break;
  }

  case exit_catcher_expr_kind:
  {
    exit_catcher_expr* catcherExpr = static_cast<exit_catcher_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(catcherExpr->theExpr);

    EXPR_ITER_END();
    break;
  }

#ifndef ZORBA_NO_FULL_TEXT
  case ft_expr_kind:
  {
    ftcontains_expr* ftExpr = static_cast<ftcontains_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(ftExpr->range_);

    theFTSelectionExprsIter = theFTSelectionExprs.begin();
    theFTSelectionExprsEnd = theFTSelectionExprs.end();
    for (; theFTSelectionExprsIter != theFTSelectionExprsEnd; ++theFTSelectionExprsIter)
    {
      EXPR_ITER_NEXT2(*theFTSelectionExprsIter);
    }

    EXPR_ITER_NEXT(ftExpr->ftignore_);

    EXPR_ITER_END();
    break;
  }
#endif /* ZORBA_NO_FULL_TEXT */

  case eval_expr_kind:
  {
    eval_expr* evalExpr = static_cast<eval_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(evalExpr->theExpr);

    theArgsIter = evalExpr->theArgs.begin();
    theArgsEnd = evalExpr->theArgs.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    break;
  }

#ifdef ZORBA_WITH_DEBUGGER
  case debugger_expr_kind:
  {
    debugger_expr* debuggerExpr = static_cast<debugger_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(debuggerExpr->theExpr);

    theArgsIter = debuggerExpr->theArgs.begin();
    theArgsEnd = debuggerExpr->theArgs.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    break;
  }
#endif

  case function_trace_expr_kind:
  {
    function_trace_expr* dummyExpr = static_cast<function_trace_expr*>(theExpr);
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(dummyExpr->theExpr);
    EXPR_ITER_END();
    break;
  }

  default:
  {
    ZORBA_ASSERT(false);
  }
  }
}


}

/* vim:set et sw=2 ts=2: */
