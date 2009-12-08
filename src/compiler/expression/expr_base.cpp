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

#include "compiler/expression/expr_base.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/expr_visitor.h"

#include "functions/function.h"

#include "types/root_typemanager.h"

#include "system/globalenv.h"

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "zorbaserialization/serialization_engine.h"


namespace zorba 
{


#define DEBUG_RT(e, t) t

#ifndef DEBUG_RT
#define DEBUG_RT(e, t) print_expr_and_type(e, t)

static xqtref_t print_expr_and_type(expr *e, xqtref_t t) 
{
  if (Properties::instance()->printStaticTypes ()) {
    std::cout << "Return type for " << e << ":\n";
    e->put(std::cout);
    std::cout << " => " << t->toString() << std::endl;
  }
  return t;
}

#endif


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  expr iteration                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Class expr_iterator
********************************************************************************/
expr_iterator::expr_iterator(const expr_iterator& other) 
  :
  theIter(new expr_iterator_data(*other.theIter)) 
{
}


expr_iterator::~expr_iterator() 
{
  delete theIter; 
}


expr_iterator& expr_iterator::operator=(const expr_iterator& other) 
{
  if (this != &other) 
  {
    delete theIter;
    theIter = new expr_iterator_data(*other.theIter);
  }
  return *this;
}


expr_iterator& expr_iterator::operator++()
{
  theIter->next();
  return *this; 
}

#if 0
expr_iterator expr_iterator::operator++(int)
{
  expr_iterator old;
  old = *this;
  ++*this;
  return old;
}
#endif

expr_t& expr_iterator::operator*()
{
  return *(theIter->theCurrentChild);
}


bool expr_iterator::done() const 
{
  return theIter->done();
}


/*******************************************************************************
  Class const_expr_iterator
********************************************************************************/
const_expr_iterator::const_expr_iterator(const const_expr_iterator& other) 
  :
  theIter(new expr_iterator_data(*other.theIter)) 
{
}


const_expr_iterator::~const_expr_iterator() 
{
  delete theIter; 
}


const_expr_iterator& const_expr_iterator::operator=(const const_expr_iterator& other) 
{
  if (this != &other)
  {
    delete theIter;
    theIter = new expr_iterator_data(*other.theIter);
  }
  return *this;
}


const_expr_iterator& const_expr_iterator::operator++()
{
  theIter->next();
  return *this; 
}


const expr* const_expr_iterator::operator*()
{
  return theIter->theCurrentChild->getp();
}


bool const_expr_iterator::done() const 
{
  return theIter->done();
}


/*******************************************************************************
  Class expr_iterator_data
********************************************************************************/
bool expr_iterator_data::done() const 
{
  return theCurrentChild == expr::iter_done;
}


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
expr::expr(short sctx, const QueryLoc& loc) 
  :
  theSctxId(sctx),
  theLoc(loc) 
{
  invalidate();
  theCache.type.valid = false;
  theCache.scripting_kind.valid = false;
  theCache.scripting_kind.kind = VACUOUS_EXPR;
}


/*******************************************************************************

********************************************************************************/
expr::~expr() 
{
}


/*******************************************************************************

********************************************************************************/
void expr::serialize(::zorba::serialization::Archiver& ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  serialize_baseclass(ar, (AnnotationHolder*)this);
  ar & theSctxId;
  ar & theLoc;
  ar & theCache.type.valid;
  ar & theCache.type.t;
  ar & theCache.scripting_kind.valid;
  SERIALIZE_ENUM(expr_script_kind_t, theCache.scripting_kind.kind);
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

  for(const_expr_iterator i = expr_begin_const(); !i.done(); ++i) 
  {
    if (!(*i)->is_constant()) 
    {
      return false;
    }
  }
  return true;
}


/*******************************************************************************

********************************************************************************/
expr_script_kind_t expr::get_scripting_kind() const 
{
  if (is_vacuous())
    return VACUOUS_EXPR;

  else if (is_updating())
    return UPDATE_EXPR;

  else if (is_sequential())
    return SEQUENTIAL_EXPR;

  else
    return SIMPLE_EXPR;
}


bool expr::is_updating() const 
{
  if (! theCache.scripting_kind.valid)
    compute_scripting_kind();

  return theCache.scripting_kind.kind == UPDATE_EXPR;
}

  
bool expr::is_sequential() const 
{
  if (! theCache.scripting_kind.valid)
    compute_scripting_kind();

  return theCache.scripting_kind.kind == SEQUENTIAL_EXPR;
}
  

bool expr::is_vacuous() const 
{
  if (! theCache.scripting_kind.valid)
    compute_scripting_kind();

  return theCache.scripting_kind.kind == VACUOUS_EXPR;
}


bool expr::is_simple() const 
{
  if (! theCache.scripting_kind.valid)
    compute_scripting_kind();

  return theCache.scripting_kind.kind == SIMPLE_EXPR;
}


bool expr::is_updating_or_vacuous() const 
{
  if (! theCache.scripting_kind.valid)
    compute_scripting_kind();

  return (theCache.scripting_kind.kind == UPDATE_EXPR ||
          theCache.scripting_kind.kind == VACUOUS_EXPR);
}


expr_script_kind_t expr::scripting_kind_anding(
    expr_script_kind_t type1, 
    expr_script_kind_t type2, 
    const QueryLoc& loc)
{
  switch(type1)
  {
  case VACUOUS_EXPR:
  {
    switch(type2) 
    {
    case VACUOUS_EXPR:
      return VACUOUS_EXPR;

    case SIMPLE_EXPR:
      return SIMPLE_EXPR;

    case UPDATE_EXPR:
      return UPDATE_EXPR;

    case SEQUENTIAL_EXPR:
      return SEQUENTIAL_EXPR;
    }

    break;
  }
  case SIMPLE_EXPR:
  {
    switch(type2) 
    {
    case VACUOUS_EXPR:
      return SIMPLE_EXPR;

    case SIMPLE_EXPR:
      return SIMPLE_EXPR;

    case UPDATE_EXPR:
      ZORBA_ERROR_LOC(XUST0001, loc);
      break;

    case SEQUENTIAL_EXPR:
      return SEQUENTIAL_EXPR;
    }

    break;
  }
  case UPDATE_EXPR:
  {
    switch(type2) 
    {
    case VACUOUS_EXPR:
      return UPDATE_EXPR;

    case SIMPLE_EXPR:
      ZORBA_ERROR_LOC(XUST0001, loc);
      break;

    case UPDATE_EXPR:
      return UPDATE_EXPR;

    case SEQUENTIAL_EXPR:
      ZORBA_ERROR_LOC(XUST0001, loc);
      break;
    }

    break;
  }
  case SEQUENTIAL_EXPR:
  {
    switch(type2) 
    {
    case VACUOUS_EXPR:
      return SEQUENTIAL_EXPR;

    case SIMPLE_EXPR:
      return SEQUENTIAL_EXPR;

    case UPDATE_EXPR:
      ZORBA_ERROR_LOC(XUST0001, loc);
      break;

    case SEQUENTIAL_EXPR:
      return SEQUENTIAL_EXPR;
    }

    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }

  return SIMPLE_EXPR;
}
  

/*******************************************************************************

********************************************************************************/
xqtref_t expr::return_type(static_context* sctx) const
{
  if (! cache_compliant())
    return DEBUG_RT(this, return_type_impl(sctx));

  if (! theCache.type.valid)
  {
    theCache.type.t = DEBUG_RT(this, return_type_impl(sctx));
    theCache.type.valid = true;
  }

  return theCache.type.t;
}


xqtref_t expr::return_type_impl(static_context* sctx) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


/*******************************************************************************

********************************************************************************/
expr_iterator expr::expr_begin(bool invalidate) 
{
  if (invalidate)
    this->invalidate();

  expr_iterator_data* iter_data = make_iter();
  iter_data->set_invalidate(invalidate);
  iter_data->next();

  return expr_iterator(iter_data);
}


const_expr_iterator expr::expr_begin_const() const 
{
  expr_iterator_data* iter_data = const_cast<expr*>(this)->make_iter();
  iter_data->set_invalidate(false);
  iter_data->next();

  return const_expr_iterator(iter_data);
}


expr_iterator_data* expr::make_iter()
{
  return new expr_iterator_data(this);
}

 
void expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ZORBA_ASSERT(false);
  END_EXPR_ITER();
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
  ZORBA_ERROR_LOC(XQP0019_INTERNAL_ERROR, get_loc());
  return NULL;
}


/*******************************************************************************

********************************************************************************/
DEF_EXPR_ACCEPT (expr)


/*******************************************************************************

********************************************************************************/
void expr::accept_children(expr_visitor& v) 
{
  for (expr_iterator i = expr_begin(); ! i.done(); ++i) 
  {
    if (*i != NULL)
      (*i)->accept(v);
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
  Replace all references to "oldExpr" inside "e" with references to "newExpr".
********************************************************************************/
void expr::replace_expr(const expr* oldExpr, const expr* newExpr)
{
  expr_iterator iter = expr_begin();
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

    ++iter;
  }
}


/*******************************************************************************
  Return true if the given expr is a subexpr of "this".
********************************************************************************/
bool expr::contains_expr(const expr* e) const
{
  const_expr_iterator iter = expr_begin_const();
  while (!iter.done())
  {
    if ((*iter) == e)
    {
      return true;
    }
    else if ((*iter)->contains_expr(e))
    {
      return true;
    }

    ++iter;
  }

  return false;
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
bool expr::is_map(const expr* e, static_context* sctx) const
{
  if (is_updating())
    return false;

  xqtref_t type = e->return_type(sctx);
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
  case debugger_expr_kind:
  {
    const debugger_expr* debugExpr = static_cast<const debugger_expr *>(this);
    return debugExpr->get_expr()->is_map_internal(e, found);
  }

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
    ulong numArgs = foExpr->num_args();
    
    for (ulong i = 0; i < numArgs; ++i)
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
    ulong numClauses = flworExpr->num_clauses();

    for (ulong i = 0; i < numClauses; ++i)
    {
      const flwor_clause* clause = (*flworExpr)[i];

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

        ulong numColumns = obc->num_columns();
        for (ulong k = 0; k < numColumns; ++k)
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
    }

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

  case sequential_expr_kind:
  case exit_expr_kind:
  case flowctl_expr_kind:
  case while_expr_kind:
    return false; // TODO

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



}

