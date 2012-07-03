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
#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/expr_iter.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/expression/expr_manager.h"

#include "functions/function.h"
#include "functions/library.h"
#include "functions/func_errors_and_diagnostics.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "system/globalenv.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"


namespace zorba
{


#define DEBUG_RT(e, t) t

#ifndef DEBUG_RT
#define DEBUG_RT(e, t) print_expr_and_type(e, t)

static xqtref_t print_expr_and_type(expr* e, xqtref_t t)
{
  if (Properties::instance()->printStaticTypes())
  {
    std::cout << "Return type for " << e << ":\n";
    e->put(std::cout);
    std::cout << " => " << t->toString() << std::endl;
  }
  return t;
}

#endif


typedef std::set<const var_expr *> var_ptr_set;


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Base expr class                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************

********************************************************************************/
expr_t expr::iter_end_expr = NULL;

expr_t* expr::iter_done = &expr::iter_end_expr;


/*******************************************************************************

********************************************************************************/
bool expr::is_sequential(unsigned short theScriptingKind)
{
  return (theScriptingKind & (VAR_SETTING_EXPR |
                              APPLYING_EXPR |
                              EXITING_EXPR |
                              BREAKING_EXPR |
                              SEQUENTIAL_FUNC_EXPR)) != 0;
}


void expr::checkNonUpdating(const expr* e)
{
  if (e != 0 && e->is_updating())
  {
    throw XQUERY_EXCEPTION(err::XUST0001,
                           ERROR_PARAMS(ZED(XUST0001_Generic)),
                           ERROR_LOC(e->get_loc()));
  }
}


void expr::checkSimpleExpr(const expr* e)
{
  if (e != 0 && e->is_updating())
  {
    throw XQUERY_EXCEPTION(err::XUST0001,
                           ERROR_PARAMS(ZED(XUST0001_Generic)),
                           ERROR_LOC(e->get_loc()));
  }

  if (e != 0 && e->is_sequential())
  {
    throw XQUERY_EXCEPTION(zerr::XSST0006, ERROR_LOC(e->get_loc()));
  }
}


/*******************************************************************************

********************************************************************************/
expr::expr(ExprManager* expMan, static_context* sctx, const QueryLoc& loc, expr_kind_t k)
  :
  theSctx(sctx),
  theLoc(loc),
  theKind(k),
  theFlags1(0),
  theExprManager(expMan)
{
  theScriptingKind = UNKNOWN_SCRIPTING_KIND;

  // This is the default. The constructors for certain exprs set different values.
  setNonDiscardable(ANNOTATION_FALSE);
  setUnfoldable(ANNOTATION_FALSE);
}


/*******************************************************************************

********************************************************************************/
expr::~expr()
{
}


/*******************************************************************************

********************************************************************************/
TypeManager* expr::get_type_manager() const
{
  return theSctx->get_typemanager();
}


/*******************************************************************************

********************************************************************************/
bool expr::is_updating() const
{
  assert(theScriptingKind != UNKNOWN_SCRIPTING_KIND);

  return (theScriptingKind & UPDATING_EXPR) != 0;
}


bool expr::is_sequential() const
{
  assert(theScriptingKind != UNKNOWN_SCRIPTING_KIND);

  return is_sequential(theScriptingKind);
}


bool expr::is_vacuous() const
{
  assert(theScriptingKind != UNKNOWN_SCRIPTING_KIND);

  return theScriptingKind == VACUOUS_EXPR;
}


bool expr::is_simple() const
{
  assert(theScriptingKind != UNKNOWN_SCRIPTING_KIND);

  return theScriptingKind == SIMPLE_EXPR;
}


bool expr::is_updating_or_vacuous() const
{
  return (is_updating() || is_vacuous());
}


/*******************************************************************************

********************************************************************************/
void expr::set_not_exiting()
{
  theScriptingKind &= ~EXITING_EXPR;

  if (theScriptingKind == UNKNOWN_SCRIPTING_KIND)
  {
    theScriptingKind = SIMPLE_EXPR;
  }
}


/*******************************************************************************

********************************************************************************/
void expr::checkScriptingKind() const
{
  if (is_updating() && is_sequential())
  {
    throw XQUERY_EXCEPTION(zerr::XSST0005,  ERROR_LOC(get_loc()));
  }

#ifndef NDEBUG
  assert(theScriptingKind != UNKNOWN_SCRIPTING_KIND);

  if (theScriptingKind & VACUOUS_EXPR)
    assert(theScriptingKind == VACUOUS_EXPR);

  if (theScriptingKind & SIMPLE_EXPR)
    assert(theScriptingKind == SIMPLE_EXPR);

  if (theScriptingKind & UPDATING_EXPR)
    assert(theScriptingKind == UPDATING_EXPR);
#endif
}


/*******************************************************************************

********************************************************************************/
expr_t expr::clone() const
{
  substitution_t subst;
  return clone(subst);
}


expr_t expr::clone(substitution_t& subst) const
{
  throw XQUERY_EXCEPTION(zerr::ZXQP0003_INTERNAL_ERROR, ERROR_LOC(get_loc()));
}


/*******************************************************************************

********************************************************************************/
void expr::accept_children(expr_visitor& v)
{
  ExprIterator iter(this);
  while (!iter.done())
  {
    if (*iter != NULL)
      (*iter)->accept(v);

    iter.next();
  }
}


/*******************************************************************************

********************************************************************************/
std::string expr::toString() const
{
  std::ostringstream oss;
  put(oss);
  return oss.str();
}


/*******************************************************************************

********************************************************************************/
void expr::setFreeVars(FreeVars& s)
{
  theFreeVars.swap(s);
}


/*******************************************************************************

********************************************************************************/
void expr::clear_annotations()
{
  theFreeVars.clear();

  if (getProducesSortedNodes() != ANNOTATION_TRUE_FIXED)
    setProducesSortedNodes(ANNOTATION_UNKNOWN);

  if (getProducesDistinctNodes() != ANNOTATION_TRUE_FIXED)
    setProducesDistinctNodes(ANNOTATION_UNKNOWN);

  if (getIgnoresSortedNodes() != ANNOTATION_TRUE_FIXED)
    setIgnoresSortedNodes(ANNOTATION_UNKNOWN);

  if (getIgnoresDuplicateNodes() != ANNOTATION_TRUE_FIXED)
    setIgnoresDuplicateNodes(ANNOTATION_UNKNOWN);

  if (getNonDiscardable() != ANNOTATION_TRUE_FIXED)
    setNonDiscardable(ANNOTATION_UNKNOWN);

  if (getUnfoldable() != ANNOTATION_TRUE_FIXED)
    setUnfoldable(ANNOTATION_UNKNOWN);

  //theFlags1 = 0;
  //setNonDiscardable(ANNOTATION_FALSE);
  //setUnfoldable(ANNOTATION_FALSE);

  ExprIterator iter(this);
  while (!iter.done())
  {
    (*iter)->clear_annotations();
    iter.next();
  }
}



/*******************************************************************************
  Returns true if the expr contains a nondeterministic function call
********************************************************************************/
bool expr::is_nondeterministic() const
{
  if (get_expr_kind() == fo_expr_kind)
  {
    const fo_expr* fo = static_cast<const fo_expr*>(this);
    if (!fo->get_func()->isDeterministic())
      return true;
  }

  ExprConstIterator iter(this);
  while(!iter.done())
  {
    const expr* ce = iter.get_expr();
    if (ce != NULL && ce->is_nondeterministic())
        return true;

    iter.next();
  }

  return false;
}


/*******************************************************************************
  Annotation : produces-sorted-nodes
  Tells whether the expression produces nodes in document order or not.
********************************************************************************/
BoolAnnotationValue expr::getProducesSortedNodes() const
{
  return (BoolAnnotationValue)(theFlags1 & PRODUCES_SORTED_NODES_MASK);
}


void expr::setProducesSortedNodes(BoolAnnotationValue v)
{
  theFlags1 &= ~PRODUCES_SORTED_NODES_MASK;
  theFlags1 |= v;
}


bool expr::producesSortedNodes() const
{
  return (getProducesSortedNodes() == ANNOTATION_TRUE);
}


/*******************************************************************************
  Annotation : produces-distinct-nodes
  Tells whether the expression produces distinct nodes or not.
********************************************************************************/
BoolAnnotationValue expr::getProducesDistinctNodes() const
{
  return (BoolAnnotationValue)
         ((theFlags1 & PRODUCES_DISTINCT_NODES_MASK) >> PRODUCES_DISTINCT_NODES);
}


void expr::setProducesDistinctNodes(BoolAnnotationValue v)
{
  theFlags1 &= ~PRODUCES_DISTINCT_NODES_MASK;
  theFlags1 |= (v << PRODUCES_DISTINCT_NODES);
}


bool expr::producesDistinctNodes() const
{
  return (getProducesDistinctNodes() == ANNOTATION_TRUE);
}


/*******************************************************************************
  Annotation : ignores-sorted-nodes
  Tells whether the expression  needs to produce nodes in doc order or not.
********************************************************************************/
BoolAnnotationValue expr::getIgnoresSortedNodes() const
{
  return (BoolAnnotationValue)
         ((theFlags1 & IGNORES_SORTED_NODES_MASK) >> IGNORES_SORTED_NODES);
}


void expr::setIgnoresSortedNodes(BoolAnnotationValue v)
{
  theFlags1 &= ~IGNORES_SORTED_NODES_MASK;
  theFlags1 |= (v << IGNORES_SORTED_NODES);
}


bool expr::ignoresSortedNodes() const
{
  return (getIgnoresSortedNodes() == ANNOTATION_TRUE);
}


/*******************************************************************************
  Annotation : ignores-duplicates-nodes
  Tells whether the expression needs to produce distinct nodes or not.
********************************************************************************/
BoolAnnotationValue expr::getIgnoresDuplicateNodes() const
{
  return (BoolAnnotationValue)
         ((theFlags1 & IGNORES_DUPLICATE_NODES_MASK) >> IGNORES_DUPLICATE_NODES);
}


void expr::setIgnoresDuplicateNodes(BoolAnnotationValue v)
{
  theFlags1 &= ~IGNORES_DUPLICATE_NODES_MASK;
  theFlags1 |= (v << IGNORES_DUPLICATE_NODES);
}


bool expr::ignoresDuplicateNodes() const
{
  return (getIgnoresDuplicateNodes() == ANNOTATION_TRUE);
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue expr::getNonDiscardable() const
{
  return (BoolAnnotationValue)
         ((theFlags1 & NON_DISCARDABLE_MASK) >> NON_DISCARDABLE);
}


void expr::setNonDiscardable(BoolAnnotationValue v)
{
  theFlags1 &= ~NON_DISCARDABLE_MASK;
  theFlags1 |= (v << NON_DISCARDABLE);
}


bool expr::isNonDiscardable() const
{
  BoolAnnotationValue v = getNonDiscardable();
  return (v == ANNOTATION_TRUE || v == ANNOTATION_TRUE_FIXED);
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue expr::getUnfoldable() const
{
  return (BoolAnnotationValue)
         ((theFlags1 & UNFOLDABLE_MASK) >> UNFOLDABLE);
}


void expr::setUnfoldable(BoolAnnotationValue v)
{
  theFlags1 &= ~UNFOLDABLE_MASK;
  theFlags1 |= (v << UNFOLDABLE);
}


bool expr::isUnfoldable() const
{
  BoolAnnotationValue v = getUnfoldable();
  return (v == ANNOTATION_TRUE || v == ANNOTATION_TRUE_FIXED);
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue expr::getContainsRecursiveCall() const
{
  return (BoolAnnotationValue)
         ((theFlags1 & CONTAINS_RECURSIVE_CALL_MASK) >> CONTAINS_RECURSIVE_CALL);
}


void expr::setContainsRecursiveCall(BoolAnnotationValue v)
{
  theFlags1 &= ~CONTAINS_RECURSIVE_CALL_MASK;
  theFlags1 |= (v << CONTAINS_RECURSIVE_CALL);
}


bool expr::containsRecursiveCall() const
{
  BoolAnnotationValue v = getContainsRecursiveCall();
  return (v == ANNOTATION_TRUE || v == ANNOTATION_TRUE_FIXED);
}


/*******************************************************************************

********************************************************************************/
BoolAnnotationValue expr::getWillBeSerialized() const
{
  return (BoolAnnotationValue)
         ((theFlags1 & WILL_BE_SERIALIZED_MASK) >> WILL_BE_SERIALIZED);
}


void expr::setWillBeSerialized(BoolAnnotationValue v)
{
  theFlags1 &= ~WILL_BE_SERIALIZED_MASK;
  theFlags1 |= (v << WILL_BE_SERIALIZED);
}


bool expr::willBeSerialized() const
{
  BoolAnnotationValue v = getWillBeSerialized();
  return (v == ANNOTATION_TRUE || v == ANNOTATION_TRUE_FIXED);
}


/*******************************************************************************
  This annotation tells whether the expr must produce nodes that belong to
  "standalone" trees or not. A tree is standalone if it does not contain
  references to other trees. Such references are created when the optimizer
  decides that it is ok to avoid copying the referenced subtree (as would be
  required by required by a strict implementation of the spec, eg., during
  node construction).
********************************************************************************/
BoolAnnotationValue expr::getMustCopyNodes() const
{
  return (BoolAnnotationValue)
         ((theFlags1 & MUST_COPY_NODES_MASK) >> MUST_COPY_NODES);
}


void expr::setMustCopyNodes(BoolAnnotationValue v)
{
  theFlags1 &= ~MUST_COPY_NODES_MASK;
  theFlags1 |= (v << MUST_COPY_NODES);
}


/*******************************************************************************
  Return true if the expr does not reference any variables.
********************************************************************************/
bool expr::is_constant() const
{
  if (get_expr_kind() == var_expr_kind)
  {
    return false;
  }

  ExprConstIterator iter(this);
  while (!iter.done())
  {
    if (!iter.get_expr()->is_constant())
    {
      return false;
    }

    iter.next();
  }

  return true;
}


/*******************************************************************************
  Replace all references to "oldExpr" inside "e" with references to "newExpr".
********************************************************************************/
void expr::replace_expr(const expr* oldExpr, const expr* newExpr)
{
  ExprIterator iter(this);
  while (!iter.done())
  {
    if ((*iter).getp() == oldExpr)
    {
      (*iter) = newExpr;
    }
    else
    {
      (*iter)->replace_expr(oldExpr, newExpr);
    }

    iter.next();
  }
}


/*******************************************************************************
  Return true if the given expr is a subexpr of "this".
********************************************************************************/
bool expr::contains_expr(const expr* e) const
{
  ExprConstIterator iter(this);
  while (!iter.done())
  {
    if (iter.get_expr() == e)
    {
      return true;
    }
    else if (iter.get_expr()->contains_expr(e))
    {
      return true;
    }

    iter.next();
  }

  return false;
}


/*******************************************************************************
  Check if the expr tree rooted at e contains any node-constructor expr. If so,
  e cannot be hoisted.
********************************************************************************/
bool expr::contains_node_construction() const
{
  expr_kind_t kind = get_expr_kind();

  if (kind == elem_expr_kind ||
      kind == attr_expr_kind ||
      kind == text_expr_kind ||
      kind == doc_expr_kind  ||
      kind == pi_expr_kind)
  {
    return true;
  }

  ExprConstIterator iter(this);
  while(!iter.done())
  {
    const expr* ce = iter.get_expr();
    if (ce)
    {
      if (ce->contains_node_construction())
      {
        return true;
      }
    }
    iter.next();
  }
  return false;
}


/*******************************************************************************

********************************************************************************/
void expr::get_exprs_of_kind(
    expr_kind_t kind,
    bool deep,
    std::vector<expr*>& exprs) const
{
  if (kind == get_expr_kind())
  {
    exprs.push_back(const_cast<expr*>(this));

    if (!deep)
      return;
  }

  ExprConstIterator iter(this);
  while(!iter.done())
  {
    const expr* ce = iter.get_expr();
    if (ce)
    {
      ce->get_exprs_of_kind(kind, deep, exprs);
    }

    iter.next();
  }
}


/*******************************************************************************

********************************************************************************/
void expr::get_fo_exprs_of_kind(
    FunctionConsts::FunctionKind kind,
    bool deep,
    std::vector<expr*>& exprs) const
{
  if (get_expr_kind() == fo_expr_kind)
  {
    if (static_cast<const fo_expr*>(this)->get_func()->getKind() == kind)
    {
      exprs.push_back(const_cast<expr*>(this));

      if (!deep)
        return;
    }
  }

  ExprConstIterator iter(this);
  while(!iter.done())
  {
    const expr* ce = iter.get_expr();
    if (ce)
    {
      ce->get_fo_exprs_of_kind(kind, deep, exprs);
    }

    iter.next();
  }
}


/*******************************************************************************
  If "this" is a var_expr or a wrapper_expr over a var_expr, return the var_expr;
  otherwise return NULL.
********************************************************************************/
const var_expr* expr::get_var() const
{
  expr_kind_t kind = get_expr_kind();
  const expr* currExpr = this;

  while (kind == wrapper_expr_kind)
  {
    const wrapper_expr* wrapperExpr = static_cast<const wrapper_expr*>(currExpr);
    currExpr = wrapperExpr->get_expr();
    kind = currExpr->get_expr_kind();
  }

  if (kind == var_expr_kind)
    return static_cast<const var_expr*>(currExpr);

  return NULL;
}


/*******************************************************************************
  This method tries to see if "this" is a map with respect to the given expr.

  Let E1 be an expr and E2 be a sub-expr of E1, Then, E1 is a map w.r.t. E2 iff

  for each value v2 of E2 with a cardinality N >= 1:

  v1 == CONCATENATE { v1i, i = 1, ..., N }, where

  v1 is the value of E1 when E2 is bound to v2 and
  v1i is the value of E1 when E2 is bound to the i-th item in v2

  If the method returns true, then "this" is guaranteed to be a map. If it
  returns false, it may still be a map, but this algorithm could not determine
  that.
********************************************************************************/
bool expr::is_map(expr* e, static_context* sctx) const
{
  if (is_updating())
    return false;

  xqtref_t type = e->get_return_type();
  TypeConstants::quantifier_t q = type->get_quantifier();

  if (q == TypeConstants::QUANT_ONE || q == TypeConstants::QUANT_QUESTION)
    return true;

  bool found = false;

  return is_map_internal(e, found);
}


bool expr::is_map_internal(const expr* e, bool& found) const
{
  if (found)
    return true;

  if (this == e)
  {
    found = true;
    return true;
  }

  switch(get_expr_kind())
  {
#ifdef ZORBA_WITH_DEBUGGER
  case debugger_expr_kind:
  {
    const debugger_expr* debugExpr = static_cast<const debugger_expr *>(this);
    return debugExpr->get_expr()->is_map_internal(e, found);
  }
#endif

  case order_expr_kind:
  {
    const order_expr* orderExpr = static_cast<const order_expr *>(this);
    return orderExpr->get_expr()->is_map_internal(e, found);
  }

  case wrapper_expr_kind:
  {
    const wrapper_expr* wrapperExpr = static_cast<const wrapper_expr *>(this);
    return wrapperExpr->get_expr()->is_map_internal(e, found);
  }

  case const_expr_kind:
  case var_expr_kind:
    return true;

  case fo_expr_kind:
  {
    const fo_expr* foExpr = static_cast<const fo_expr *>(this);
    const function* func = foExpr->get_func();
    csize numArgs = foExpr->num_args();

    for (csize i = 0; i < numArgs; ++i)
    {
      const expr* argExpr = foExpr->get_arg(i);

      if (func->isMap(i))
      {
        if (argExpr->is_map_internal(e, found) && found)
        {
          return true;
        }
        else if (found)
        {
          return false;
        }
      }
      else if (argExpr->contains_expr(e))
      {
        return false;
      }
    }

    return true;
  }

  case flwor_expr_kind:
  case gflwor_expr_kind:
  {
    const flwor_expr* flworExpr = static_cast<const flwor_expr *>(this);
    bool haveOrderBy = false;
    csize numClauses = flworExpr->num_clauses();

    for (csize i = 0; i < numClauses; ++i)
    {
      const flwor_clause* clause = flworExpr->get_clause(i);

      switch (clause->get_kind())
      {
      case flwor_clause::for_clause:
      {
        if (found)
          break;

        if (clause->get_expr()->is_map_internal(e, found) && found)
        {
          break;
        }
        else if (found)
        {
          return false;
        }

        break;
      }
      case flwor_clause::let_clause:
      case flwor_clause::where_clause:
      {
        if (found)
          break;

        if (clause->get_expr()->contains_expr(e))
          return false;

        break;
      }
      case flwor_clause::window_clause:
      {
        if (found)
          break;

        if (clause->get_expr()->contains_expr(e))
          return false;

        const window_clause* wc = static_cast<const window_clause*>(clause);
        flwor_wincond* startCond = wc->get_win_start();
        flwor_wincond* stopCond = wc->get_win_stop();

        if (startCond && startCond->get_cond()->contains_expr(e))
          return false;

        if (stopCond && stopCond->get_cond()->contains_expr(e))
          return false;

        break;
      }
      case flwor_clause::group_clause:
      case flwor_clause::count_clause:
      {
        if (found)
          return false;

        break;
      }
      case flwor_clause::order_clause:
      {
        if (found)
          return false;

        const orderby_clause* obc = static_cast<const orderby_clause*>(clause);

        csize numColumns = obc->num_columns();
        for (csize k = 0; k < numColumns; ++k)
        {
          if (obc->get_column_expr(k)->contains_expr(e))
            return false;
        }

        haveOrderBy = true;
        break;
      }
      default:
        ZORBA_ASSERT(false);
      }
    } // for each clause

    if (found)
    {
      return true;
    }
    else
    {
      const expr* retExpr = flworExpr->get_return_expr();

      if (retExpr->is_map_internal(e, found) && found && !haveOrderBy)
      {
        // TODO: actually we should return true only if the ordering mode for
        // the return expr is unordered.
        return true;
      }
      else if (!found)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }

  case if_expr_kind:
  {
    const if_expr* ifExpr = static_cast<const if_expr*>(this);

    if (ifExpr->get_cond_expr()->contains_expr(e))
      return false;

    if (ifExpr->get_then_expr()->is_map_internal(e, found) &&
        ifExpr->get_else_expr()->is_map_internal(e, found))
      return true;

    return false;
  }

  case relpath_expr_kind:
  {
    const relpath_expr* pathExpr = static_cast<const relpath_expr*>(this);
    return (*pathExpr)[0]->is_map_internal(e, found);
  }

  case treat_expr_kind:
  {
    const treat_expr* treatExpr = static_cast<const treat_expr*>(this);
    TypeConstants::quantifier_t q = treatExpr->get_target_type()->get_quantifier();

    if (q == TypeConstants::QUANT_STAR || q == TypeConstants::QUANT_PLUS)
    {
      const expr* argExpr = treatExpr->get_input();
      return argExpr->is_map_internal(e, found);
    }

    return false;
  }

  case promote_expr_kind:
  {
    const promote_expr* promoteExpr = static_cast<const promote_expr*>(this);
    TypeConstants::quantifier_t q = promoteExpr->get_target_type()->get_quantifier();

    if (q == TypeConstants::QUANT_STAR || q == TypeConstants::QUANT_PLUS)
    {
      const expr* argExpr = promoteExpr->get_input();
      return argExpr->is_map_internal(e, found);
    }

    return false;
  }

  case instanceof_expr_kind:
  case castable_expr_kind:
  case name_cast_expr_kind:
  case cast_expr_kind:
  case validate_expr_kind:
  {
    return !contains_expr(e);
  }

  case doc_expr_kind:
  case elem_expr_kind:
  case attr_expr_kind:
  case text_expr_kind:
  case pi_expr_kind:
#ifdef ZORBA_WITH_JSON
  case json_object_expr_kind:
  case json_direct_object_expr_kind:
  case json_array_expr_kind:
#endif
  {
    return !contains_expr(e);
  }

  case trycatch_expr_kind:
  case extension_expr_kind:
  {
    return !contains_expr(e);
  }

  case transform_expr_kind:
  {
    const transform_expr* transformExpr = static_cast<const transform_expr*>(this);

    if (transformExpr->getReturnExpr()->is_map_internal(e, found) && found)
      return true;

    return !contains_expr(e);
  }

  case eval_expr_kind:
    return false; // TODO

  case var_decl_expr_kind:
  case var_set_expr_kind:
  {
    return !contains_expr(e);
  }

  case apply_expr_kind:
    return false;

  case block_expr_kind:
  case exit_expr_kind:
  case flowctl_expr_kind:
  case while_expr_kind:
    return false; // TODO

  case exit_catcher_expr_kind:
  {
    const exit_catcher_expr* catcherExpr = static_cast<const exit_catcher_expr*>(this);
    return catcherExpr->get_expr()->is_map_internal(e, found);
  }

  case insert_expr_kind:
  case delete_expr_kind:
  case rename_expr_kind:
  case replace_expr_kind:
    ZORBA_ASSERT(false);

  default:
    ZORBA_ASSERT(false);
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
FunctionConsts::FunctionKind expr::get_function_kind() const
{
  if (get_expr_kind() == fo_expr_kind)
  {
    return static_cast<const fo_expr*>(this)->get_func()->getKind();
  }

  return FunctionConsts::FN_UNKNOWN;
}


/*******************************************************************************
  If "this" is a const expr that returns a qname, evaluate and return this
  qname. This method is used to extract the qname from the expression that is
  given as an arg to collection and index related functions.
********************************************************************************/
const store::Item* expr::getQName(static_context* sctx) const
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  TypeManager* tm = sctx->get_typemanager();

  const const_expr* qnameExpr = dynamic_cast<const const_expr*>(this);

  if (qnameExpr != NULL)
  {
    xqtref_t valueType = tm->create_value_type(qnameExpr->get_val());

    if (TypeOps::is_subtype(tm, *valueType, *rtm.QNAME_TYPE_ONE, get_loc()))
    {
      return qnameExpr->get_val();
    }
  }
  else if (get_expr_kind() == promote_expr_kind)
  {
    // We get here if the optimizer is turned off.

    const promote_expr* promoteExpr = static_cast<const promote_expr*>(this);

    const expr* argExpr = promoteExpr->get_input();
    const fo_expr* dataExpr = dynamic_cast<const fo_expr*>(argExpr);

    if (dataExpr != NULL &&
        dataExpr->get_func()->getKind() == FunctionConsts::FN_DATA_1)
    {
      argExpr = dataExpr->get_arg(0);
      const const_expr* qnameExpr = dynamic_cast<const const_expr*>(argExpr);

      if (qnameExpr != NULL)
      {
        xqtref_t valueType = tm->create_value_type(qnameExpr->get_val());

        if (TypeOps::is_subtype(tm, *valueType, *rtm.QNAME_TYPE_ONE, get_loc()))
        {
          return qnameExpr->get_val();
        }
      }
    }
  }

  return NULL;
}



/*******************************************************************************

********************************************************************************/
xqtref_t expr::get_return_type_with_empty_input(const expr* input) const
{
  expr_t emptyExpr = theExprManager->create_fo_expr(input->get_sctx(),
                                 QueryLoc::null,
                                 GET_BUILTIN_FUNCTION(OP_CONCATENATE_N));
  expr::substitution_t subst;
  subst[input] = emptyExpr;

  expr_t cloneExpr = clone(subst);

  return cloneExpr->get_return_type();
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
