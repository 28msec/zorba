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

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "system/globalenv.h"

#include "types/root_typemanager.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/expr_visitor.h"

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


}

