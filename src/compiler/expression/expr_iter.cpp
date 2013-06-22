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

#define EXPR_ITER_END()   theIsDone = true; }

#define EXPR_ITER_NEXT(subExprHandle)                               \
do                                                                  \
{                                                                   \
  theState = __LINE__;                                              \
  theCurrentChild = reinterpret_cast<expr**>(&(subExprHandle));     \
                                                                    \
  return;                                                           \
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
  return;                                                           \
                                                                    \
case __LINE__:;                                                     \
                                                                    \
} while (0)



ExprIterator::ExprIterator(expr* e)
  :
  theExpr(e),
  theCurrentChild(NULL),
  theState(0),
  theIsDone(false)
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
  switch (theExpr->get_expr_kind())
  {
  case flwor_expr_kind:
  {
    flwor_expr* flworExpr = static_cast<flwor_expr*>(theExpr);

#if 0
    switch (theState)
    {
    case 0:
    {
      theClausesIter = flworExpr->theClauses.begin();
      theClausesEnd = flworExpr->theClauses.end();

      if (theClausesIter == theClausesEnd)
      {
        theIsDone = true;
        theState = 10;
        return;
      }

      flwor_clause* c = *theClausesIter;

      switch (c->get_kind())
      {
      case flwor_clause::for_clause:
      case flwor_clause::let_clause:
      {
        theCurrentChild = &(static_cast<forletwin_clause *>(c)->theDomainExpr);

        ++theClausesIter;
        theState = 1;
        return;
      }
      case flwor_clause::window_clause:
      {
        theCurrentChild = &(static_cast<forletwin_clause *>(c)->theDomainExpr);

        theWincondIter = 0;
        theState = 2;
        return;
      }
      case flwor_clause::where_clause:
      {
        theCurrentChild = &(static_cast<where_clause *>(c)->theWhereExpr);

        ++theClausesIter;
        theState = 1;
        return;
      }
      case flwor_clause::count_clause:
      {
        ++theClausesIter;
        break;
      }
      default:
        ZORBA_ASSERT(false);
      }
    }
    case 1:
    {
nextclause:

      while(theClausesIter != theClausesEnd)
      {
        flwor_clause* c = *theClausesIter;

        switch (c->get_kind())
        {
        case flwor_clause::for_clause:
        case flwor_clause::let_clause:
        {
          theCurrentChild = &(static_cast<forletwin_clause *>(c)->theDomainExpr);
          ++theClausesIter;
          return;
        }
        case flwor_clause::window_clause:
        {
          window_clause* wc = static_cast<window_clause *>(*theClausesIter);

          theCurrentChild = &(wc->theDomainExpr);

          theState = 2;
          theWincondIter = 0;
          return;
        }

        case flwor_clause::where_clause:
        {
          theCurrentChild = &(static_cast<where_clause *>(c)->theWhereExpr);
          ++theClausesIter;
          return;
        }

        case flwor_clause::orderby_clause:
        {
          orderby_clause* oc = static_cast<orderby_clause *>(c);

          theArgsIter = oc->theOrderingExprs.begin();
          theArgsEnd = oc->theOrderingExprs.end();

          theCurrentChild = &(*theArgsIter);

          ++theArgsIter;
          theState = 3;
          return;
        }

        case flwor_clause::groupby_clause:
        {
          groupby_clause* gc = static_cast<groupby_clause *>(c);

          theGroupVarsIter = gc->theGroupVars.begin();
          theGroupVarsEnd = gc->theGroupVars.end();
          theNonGroupVarsIter = gc->theNonGroupVars.begin();
          theNonGroupVarsEnd = gc->theNonGroupVars.end();

          theCurrentChild = &((*theGroupVarsIter).first);

          ++theGroupVarsIter;
          theState = 4;
          return;
        }

        case flwor_clause::count_clause:
        {
          ++theClausesIter;
          break;
        }

        default:
        {
          ZORBA_ASSERT(false);
        }
        }
      } // while

      theCurrentChild = &(flworExpr->theReturnExpr);
      theState = 10;
      return;
    }

    case 2:
    {
      while (theWincondIter < 2)
      {
        window_clause* wc = static_cast<window_clause *>(*theClausesIter);

        flwor_wincond* wincond = (theWincondIter == 0 ?
                                  wc->theWinStartCond :
                                  wc->theWinStopCond );
        if (wincond != 0)
        {
          theCurrentChild = &(wincond->theCondExpr);
          ++theWincondIter;
          return;
        }

        ++theWincondIter;
      }

      theState = 1;
      ++theClausesIter;
      goto nextclause;
    }

    case 3:
    {
      while (theArgsIter != theArgsEnd)
      {
        theCurrentChild = &(*theArgsIter);
        ++theArgsIter;
        return;
      }

      theState = 1;
      ++theClausesIter;
      goto nextclause;
    }

    case 4:
    {
      while (theGroupVarsIter != theGroupVarsEnd)
      {
        theCurrentChild = &((*theGroupVarsIter).first);

        ++theGroupVarsIter;
        return;
      }

      theState = 5;
    }

    case 5:
    {
      while (theNonGroupVarsIter != theNonGroupVarsEnd)
      {
        theCurrentChild = &((*theNonGroupVarsIter).first);

        ++theNonGroupVarsIter;
        return;
      }

      theState = 1;
      ++theClausesIter;
      goto nextclause;
    }

    default:
    {
      theIsDone = true;
      return;
    }
    }

#else

    flwor_clause* c = NULL;
    window_clause* wc = NULL;
    orderby_clause* oc = NULL;
    groupby_clause* gc = NULL;
    flwor_wincond* wincond = NULL;

    EXPR_ITER_BEGIN();

    theClausesBegin = flworExpr->theClauses.begin();
    theClausesIter = flworExpr->theClauses.begin();
    theClausesEnd = flworExpr->theClauses.end();

    for (; theClausesIter != theClausesEnd; ++(theClausesIter))
    {
      c = *theClausesIter;

      if (c->get_kind() == flwor_clause::for_clause)
      {
        EXPR_ITER_NEXT(static_cast<for_clause *>(c)->theDomainExpr);
      }

      else if (c->get_kind() == flwor_clause::let_clause)
      {
        EXPR_ITER_NEXT(static_cast<let_clause *>(c)->theDomainExpr);
      }

      else if (c->get_kind() == flwor_clause::where_clause)
      {
        EXPR_ITER_NEXT(static_cast<where_clause *>(c)->theWhereExpr);
      }

      else if (c->get_kind() == flwor_clause::window_clause)
      {
        wc = static_cast<window_clause *>(*theClausesIter);

        EXPR_ITER_NEXT(wc->theDomainExpr);

        for (theWincondIter = 0; theWincondIter < 2; ++theWincondIter)
        {
          wc = static_cast<window_clause *>(*theClausesIter);

          wincond = (theWincondIter == 0 ?
                     wc->theWinStartCond :
                     wc->theWinStopCond );

          if (wincond != 0)
            EXPR_ITER_NEXT(wincond->theCondExpr);
        }
      }

      else if (c->get_kind() == flwor_clause::groupby_clause)
      {
        gc = static_cast<groupby_clause *>(c);

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

      else if (c->get_kind() == flwor_clause::orderby_clause)
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
        ZORBA_ASSERT(0);
        csize pos = (theClausesIter - theClausesBegin);
        if (pos >= flworExpr->num_clauses())
          break;

        theClausesEnd = flworExpr->theClauses.end();
        theClausesIter = flworExpr->theClauses.begin() + pos;
      }
    }

    EXPR_ITER_NEXT(flworExpr->theReturnExpr);

    EXPR_ITER_END();
#endif
    return;
  }

  case relpath_expr_kind:
  {
    EXPR_ITER_BEGIN();

    theArgsIter = static_cast<relpath_expr*>(theExpr)->theSteps.begin();
    theArgsEnd = static_cast<relpath_expr*>(theExpr)->theSteps.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    return;
  }

  case axis_step_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(static_cast<axis_step_expr*>(theExpr)->theNodeTest);
    EXPR_ITER_END();
    return;
  }

  case match_expr_kind:
  case var_expr_kind:
  case const_expr_kind:
  case flowctl_expr_kind:
  {
    theIsDone = true;
    return;
  }

  case fo_expr_kind:
  {
    EXPR_ITER_BEGIN();

    theArgsIter = static_cast<fo_expr*>(theExpr)->theArgs.begin();
    theArgsEnd = static_cast<fo_expr*>(theExpr)->theArgs.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    return;
  }

  case cast_expr_kind:
  case treat_expr_kind:
  case promote_expr_kind:
  case instanceof_expr_kind:
  case castable_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(static_cast<cast_or_castable_base_expr*>(theExpr)->theInput);
    EXPR_ITER_END();
    return;
  }

  case wrapper_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(static_cast<wrapper_expr*>(theExpr)->theInput);
    EXPR_ITER_END();
    return;
  }

  case function_trace_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(static_cast<function_trace_expr*>(theExpr)->theInput);
    EXPR_ITER_END();
    return;
  }

  case order_expr_kind:
  {
    if (theState == 0)
    {
      theCurrentChild = &(static_cast<order_expr*>(theExpr)->theInput);
      theState = 1;
      return;
    }

    theIsDone = true;
    return;
  }

  case validate_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(static_cast<validate_expr*>(theExpr)->theInput);
    EXPR_ITER_END();
    return;
  }

  case name_cast_expr_kind:
  {
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(static_cast<name_cast_expr*>(theExpr)->theInputExpr);
    EXPR_ITER_END();
    return;
  }

  case doc_expr_kind:
  {
    doc_expr* docExpr = static_cast<doc_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    if (docExpr->theContent)
      EXPR_ITER_NEXT(docExpr->theContent);

    EXPR_ITER_END();
    return;
  }

  case elem_expr_kind:
  {
    elem_expr* elemExpr = static_cast<elem_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(elemExpr->theQNameExpr);

    if (elemExpr->theAttrs)
      EXPR_ITER_NEXT(elemExpr->theAttrs);

    if (elemExpr->theContent)
      EXPR_ITER_NEXT(elemExpr->theContent);

    EXPR_ITER_END();
    return;
  }

  case attr_expr_kind:
  {
    attr_expr* attrExpr = static_cast<attr_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(attrExpr->theQNameExpr);

    if (attrExpr->theValueExpr)
      EXPR_ITER_NEXT(attrExpr->theValueExpr);

    EXPR_ITER_END();
    return;
  }

  case namespace_expr_kind:
  {
    namespace_expr* nsExpr = static_cast<namespace_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(nsExpr->thePrefixExpr);
    EXPR_ITER_NEXT(nsExpr->theUriExpr);

    EXPR_ITER_END();
    return;
  }

  case text_expr_kind:
  {
    text_expr* textExpr = static_cast<text_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(textExpr->theContentExpr);

    EXPR_ITER_END();
    return;
  }

  case pi_expr_kind:
  {
    pi_expr* piExpr = static_cast<pi_expr*>(theExpr);

    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(piExpr->theTargetExpr);
    EXPR_ITER_NEXT(piExpr->theContentExpr);
    EXPR_ITER_END();
    return;
  }

  case json_array_expr_kind:
  {
    json_array_expr* e = static_cast<json_array_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    if (e->theContentExpr)
        EXPR_ITER_NEXT(e->theContentExpr);

    EXPR_ITER_END();
    return;
  }

  case json_object_expr_kind:
  {
    json_object_expr* e = static_cast<json_object_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    if (e->theContentExpr)
        EXPR_ITER_NEXT(e->theContentExpr);

    EXPR_ITER_END();
    return;
  }

  case json_direct_object_expr_kind:
  {
    json_direct_object_expr* e = static_cast<json_direct_object_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    theArgsIter = e->theNames.begin();
    theArgsEnd = e->theNames.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    theArgsIter = e->theValues.begin();
    theArgsEnd = e->theValues.end();
    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    return;
  }

  case if_expr_kind:
  {
    if_expr* ifExpr = static_cast<if_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(ifExpr->theCondExpr);
    EXPR_ITER_NEXT(ifExpr->theThenExpr);
    EXPR_ITER_NEXT(ifExpr->theElseExpr);

    EXPR_ITER_END();
    return;
  }

  case extension_expr_kind:
  {
    extension_expr* extExpr = static_cast<extension_expr*>(theExpr);

    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(extExpr->theExpr);
    EXPR_ITER_END();
    return;
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
    return;
  }

  case function_item_expr_kind:
  {
    function_item_expr* fiExpr = static_cast<function_item_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    theArgsIter = fiExpr->theFunctionItemInfo->theInScopeVarValues.begin();
    theArgsEnd = fiExpr->theFunctionItemInfo->theInScopeVarValues.end();

    for (; theArgsIter != theArgsEnd; ++theArgsIter)
    {
      if ( ! *theArgsIter) 
        continue;

      EXPR_ITER_NEXT(*theArgsIter);
    }

    EXPR_ITER_END();
    return;
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
    return;
  }

  case argument_placeholder_expr_kind:
  {
    theIsDone = true;
    return;
  }

  case insert_expr_kind:
  {
    insert_expr* insExpr = static_cast<insert_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(insExpr->theSourceExpr);
    EXPR_ITER_NEXT(insExpr->theTargetExpr);

    EXPR_ITER_END();
    return;
  }

  case delete_expr_kind:
  {
    delete_expr* delExpr = static_cast<delete_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(delExpr->theTargetExpr);

    EXPR_ITER_END();
    return;
  }

  case replace_expr_kind:
  {
    replace_expr* repExpr = static_cast<replace_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(repExpr->theTargetExpr);
    EXPR_ITER_NEXT(repExpr->theSourceExpr);

    EXPR_ITER_END();
    return;
  }

  case rename_expr_kind:
  {
    rename_expr* renExpr = static_cast<rename_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(renExpr->theTargetExpr);
    EXPR_ITER_NEXT(renExpr->theSourceExpr);

    EXPR_ITER_END();
    return;
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
    return;
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
    return;
  }

  case apply_expr_kind:
  {
    apply_expr* applyExpr = static_cast<apply_expr*>(theExpr);
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(applyExpr->theExpr);
    EXPR_ITER_END();
    return;
  }

  case var_decl_expr_kind:
  {
    var_decl_expr* varDeclExpr = static_cast<var_decl_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    if (varDeclExpr->theExpr)
      EXPR_ITER_NEXT(varDeclExpr->theExpr);

    EXPR_ITER_END();
    return;
  }

  case var_set_expr_kind:
  {
    var_set_expr* varSetExpr = static_cast<var_set_expr*>(theExpr);
    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(varSetExpr->theExpr);
    EXPR_ITER_END();
    return;
  }

  case while_expr_kind:
  {
    while_expr* whileExpr = static_cast<while_expr*>(theExpr);

    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(whileExpr->theBody);
    EXPR_ITER_END();
    return;
  }

  case exit_expr_kind:
  {
    exit_expr* exitExpr = static_cast<exit_expr*>(theExpr);

    EXPR_ITER_BEGIN();
    EXPR_ITER_NEXT(exitExpr->theExpr);
    EXPR_ITER_END();
    return;
  }

  case exit_catcher_expr_kind:
  {
    exit_catcher_expr* catcherExpr = static_cast<exit_catcher_expr*>(theExpr);

    EXPR_ITER_BEGIN();

    EXPR_ITER_NEXT(catcherExpr->theExpr);

    EXPR_ITER_END();
    return;
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
      if (**theFTSelectionExprsIter)
        EXPR_ITER_NEXT2(*theFTSelectionExprsIter);
    }

    if (ftExpr->ftignore_)
      EXPR_ITER_NEXT(ftExpr->ftignore_);

    EXPR_ITER_END();
    return;
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
    return;
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
    return;
  }
#endif

  default:
  {
    ZORBA_ASSERT(false);
  }
  }
}


}

/* vim:set et sw=2 ts=2: */
