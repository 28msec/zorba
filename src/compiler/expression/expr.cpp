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

#include <typeinfo>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "system/globalenv.h"

#include "context/static_context_consts.h"
#include "context/namespace_context.h"
#include "context/dynamic_context.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "compiler/expression/expr.h"
#include "compiler/semantic_annotations/tsv_annotation.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/expression/expr_visitor.h"

#include "functions/function.h"

#include "util/tracer.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

using namespace std;

namespace zorba 
{
SERIALIZABLE_CLASS_VERSIONS(global_binding)
END_SERIALIZABLE_CLASS_VERSIONS(global_binding)

SERIALIZABLE_CLASS_VERSIONS(AnnotationHolder)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationHolder)

SERIALIZABLE_CLASS_VERSIONS(expr)
END_SERIALIZABLE_CLASS_VERSIONS(expr)

SERIALIZABLE_CLASS_VERSIONS(sequential_expr)
END_SERIALIZABLE_CLASS_VERSIONS(sequential_expr)

SERIALIZABLE_CLASS_VERSIONS(constructor_expr)
END_SERIALIZABLE_CLASS_VERSIONS(constructor_expr)

SERIALIZABLE_CLASS_VERSIONS(catch_clause)
END_SERIALIZABLE_CLASS_VERSIONS(catch_clause)

SERIALIZABLE_CLASS_VERSIONS(trycatch_expr)
END_SERIALIZABLE_CLASS_VERSIONS(trycatch_expr)

SERIALIZABLE_CLASS_VERSIONS(eval_expr::eval_var)
END_SERIALIZABLE_CLASS_VERSIONS(eval_expr::eval_var)

SERIALIZABLE_CLASS_VERSIONS(eval_expr)
END_SERIALIZABLE_CLASS_VERSIONS(eval_expr)

SERIALIZABLE_CLASS_VERSIONS(wrapper_expr)
END_SERIALIZABLE_CLASS_VERSIONS(wrapper_expr)

SERIALIZABLE_CLASS_VERSIONS(cast_or_castable_base_expr)
END_SERIALIZABLE_CLASS_VERSIONS(cast_or_castable_base_expr)

SERIALIZABLE_CLASS_VERSIONS(cast_base_expr)
END_SERIALIZABLE_CLASS_VERSIONS(cast_base_expr)

SERIALIZABLE_CLASS_VERSIONS(promote_expr)
END_SERIALIZABLE_CLASS_VERSIONS(promote_expr)

SERIALIZABLE_CLASS_VERSIONS(castable_base_expr)
END_SERIALIZABLE_CLASS_VERSIONS(castable_base_expr)

SERIALIZABLE_CLASS_VERSIONS(instanceof_expr)
END_SERIALIZABLE_CLASS_VERSIONS(instanceof_expr)

SERIALIZABLE_CLASS_VERSIONS(treat_expr)
END_SERIALIZABLE_CLASS_VERSIONS(treat_expr)

SERIALIZABLE_CLASS_VERSIONS(castable_expr)
END_SERIALIZABLE_CLASS_VERSIONS(castable_expr)

SERIALIZABLE_CLASS_VERSIONS(cast_expr)
END_SERIALIZABLE_CLASS_VERSIONS(cast_expr)

SERIALIZABLE_CLASS_VERSIONS(name_cast_expr)
END_SERIALIZABLE_CLASS_VERSIONS(name_cast_expr)

SERIALIZABLE_CLASS_VERSIONS(if_expr)
END_SERIALIZABLE_CLASS_VERSIONS(if_expr)

SERIALIZABLE_CLASS_VERSIONS(function_def_expr)
END_SERIALIZABLE_CLASS_VERSIONS(function_def_expr)

SERIALIZABLE_CLASS_VERSIONS(fo_expr)
END_SERIALIZABLE_CLASS_VERSIONS(fo_expr)

SERIALIZABLE_CLASS_VERSIONS(validate_expr)
END_SERIALIZABLE_CLASS_VERSIONS(validate_expr)

SERIALIZABLE_CLASS_VERSIONS(pragma)
END_SERIALIZABLE_CLASS_VERSIONS(pragma)

SERIALIZABLE_CLASS_VERSIONS(extension_expr)
END_SERIALIZABLE_CLASS_VERSIONS(extension_expr)

SERIALIZABLE_CLASS_VERSIONS(relpath_expr)
END_SERIALIZABLE_CLASS_VERSIONS(relpath_expr)

SERIALIZABLE_CLASS_VERSIONS(axis_step_expr)
END_SERIALIZABLE_CLASS_VERSIONS(axis_step_expr)

SERIALIZABLE_CLASS_VERSIONS(match_expr)
END_SERIALIZABLE_CLASS_VERSIONS(match_expr)

SERIALIZABLE_CLASS_VERSIONS(const_expr)
END_SERIALIZABLE_CLASS_VERSIONS(const_expr)

SERIALIZABLE_CLASS_VERSIONS(order_expr)
END_SERIALIZABLE_CLASS_VERSIONS(order_expr)

SERIALIZABLE_CLASS_VERSIONS(elem_expr)
END_SERIALIZABLE_CLASS_VERSIONS(elem_expr)

SERIALIZABLE_CLASS_VERSIONS(doc_expr)
END_SERIALIZABLE_CLASS_VERSIONS(doc_expr)

SERIALIZABLE_CLASS_VERSIONS(attr_expr)
END_SERIALIZABLE_CLASS_VERSIONS(attr_expr)

SERIALIZABLE_CLASS_VERSIONS(text_expr)
END_SERIALIZABLE_CLASS_VERSIONS(text_expr)

SERIALIZABLE_CLASS_VERSIONS(pi_expr)
END_SERIALIZABLE_CLASS_VERSIONS(pi_expr)

SERIALIZABLE_CLASS_VERSIONS(insert_expr)
END_SERIALIZABLE_CLASS_VERSIONS(insert_expr)

SERIALIZABLE_CLASS_VERSIONS(delete_expr)
END_SERIALIZABLE_CLASS_VERSIONS(delete_expr)

SERIALIZABLE_CLASS_VERSIONS(replace_expr)
END_SERIALIZABLE_CLASS_VERSIONS(replace_expr)

SERIALIZABLE_CLASS_VERSIONS(rename_expr)
END_SERIALIZABLE_CLASS_VERSIONS(rename_expr)

SERIALIZABLE_CLASS_VERSIONS(copy_clause)
END_SERIALIZABLE_CLASS_VERSIONS(copy_clause)

SERIALIZABLE_CLASS_VERSIONS(transform_expr)
END_SERIALIZABLE_CLASS_VERSIONS(transform_expr)

SERIALIZABLE_CLASS_VERSIONS(exit_expr)
END_SERIALIZABLE_CLASS_VERSIONS(exit_expr)

SERIALIZABLE_CLASS_VERSIONS(flowctl_expr)
END_SERIALIZABLE_CLASS_VERSIONS(flowctl_expr)

SERIALIZABLE_CLASS_VERSIONS(while_expr)
END_SERIALIZABLE_CLASS_VERSIONS(while_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_select_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_select_expr)

SERIALIZABLE_CLASS_VERSIONS(ft_contains_expr)
END_SERIALIZABLE_CLASS_VERSIONS(ft_contains_expr)

SERIALIZABLE_CLASS_VERSIONS(var_expr)
END_SERIALIZABLE_CLASS_VERSIONS(var_expr)

//SERIALIZABLE_CLASS_VERSIONS(gflwor_clause)
//END_SERIALIZABLE_CLASS_VERSIONS(gflwor_clause)
//
//SERIALIZABLE_CLASS_VERSIONS(where_gclause)
//END_SERIALIZABLE_CLASS_VERSIONS(where_gclause)
//
//SERIALIZABLE_CLASS_VERSIONS(count_gclause)
//END_SERIALIZABLE_CLASS_VERSIONS(count_gclause)
//
//SERIALIZABLE_CLASS_VERSIONS(orderby_gclause)
//END_SERIALIZABLE_CLASS_VERSIONS(orderby_gclause)
//
//SERIALIZABLE_CLASS_VERSIONS(group_gclause)
//END_SERIALIZABLE_CLASS_VERSIONS(group_gclause)
//
//SERIALIZABLE_CLASS_VERSIONS(gflwor_expr)
//END_SERIALIZABLE_CLASS_VERSIONS(gflwor_expr)

SERIALIZABLE_CLASS_VERSIONS(flwor_clause)
END_SERIALIZABLE_CLASS_VERSIONS(flwor_clause)

SERIALIZABLE_CLASS_VERSIONS(forletwin_clause)
END_SERIALIZABLE_CLASS_VERSIONS(forletwin_clause)

SERIALIZABLE_CLASS_VERSIONS(for_clause)
END_SERIALIZABLE_CLASS_VERSIONS(for_clause)

SERIALIZABLE_CLASS_VERSIONS(let_clause)
END_SERIALIZABLE_CLASS_VERSIONS(let_clause)

SERIALIZABLE_CLASS_VERSIONS(window_clause)
END_SERIALIZABLE_CLASS_VERSIONS(window_clause)

SERIALIZABLE_CLASS_VERSIONS(group_clause)
END_SERIALIZABLE_CLASS_VERSIONS(group_clause)

SERIALIZABLE_CLASS_VERSIONS(orderby_clause)
END_SERIALIZABLE_CLASS_VERSIONS(orderby_clause)

SERIALIZABLE_CLASS_VERSIONS(count_clause)
END_SERIALIZABLE_CLASS_VERSIONS(count_clause)

SERIALIZABLE_CLASS_VERSIONS(where_clause)
END_SERIALIZABLE_CLASS_VERSIONS(where_clause)

SERIALIZABLE_CLASS_VERSIONS(flwor_expr)
END_SERIALIZABLE_CLASS_VERSIONS(flwor_expr)


SERIALIZABLE_CLASS_VERSIONS(OrderModifier)
END_SERIALIZABLE_CLASS_VERSIONS(OrderModifier)


/*******************************************************************************

********************************************************************************/
#define DEF_ACCEPT( type )             \
void type::accept(expr_visitor& v)     \
{                                      \
  if (v.begin_visit(*this))            \
    accept_children(v);                \
                                       \
  v.end_visit(*this);                  \
}


DEF_ACCEPT (expr)
DEF_ACCEPT (debugger_expr)
DEF_ACCEPT (wrapper_expr)
DEF_ACCEPT (sequential_expr)
DEF_ACCEPT (var_expr)
DEF_ACCEPT (flwor_expr)
DEF_ACCEPT (promote_expr)
DEF_ACCEPT (trycatch_expr)
DEF_ACCEPT (eval_expr)
DEF_ACCEPT (if_expr)
DEF_ACCEPT (function_def_expr)
DEF_ACCEPT (fo_expr)
DEF_ACCEPT (ft_contains_expr)
DEF_ACCEPT (instanceof_expr)
DEF_ACCEPT (treat_expr)
DEF_ACCEPT (castable_expr)
DEF_ACCEPT (cast_expr)
DEF_ACCEPT (name_cast_expr)
DEF_ACCEPT (validate_expr)
DEF_ACCEPT (extension_expr)
DEF_ACCEPT (relpath_expr)
DEF_ACCEPT (axis_step_expr)
DEF_ACCEPT (match_expr)
DEF_ACCEPT (const_expr)
DEF_ACCEPT (order_expr)
DEF_ACCEPT (elem_expr)
DEF_ACCEPT (doc_expr)
DEF_ACCEPT (attr_expr)
DEF_ACCEPT (text_expr)
DEF_ACCEPT (pi_expr)
DEF_ACCEPT (insert_expr)
DEF_ACCEPT (delete_expr)
DEF_ACCEPT (rename_expr)
DEF_ACCEPT (replace_expr)
DEF_ACCEPT (transform_expr)
DEF_ACCEPT (exit_expr)
DEF_ACCEPT (flowctl_expr)
DEF_ACCEPT (while_expr)

#undef DEF_ACCEPT


static inline void checkNonUpdating(const expr* e)
{
  if (e != 0 && e->is_updating())
    ZORBA_ERROR_LOC(XUST0001, e->get_loc());
}


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


#define CLONE( e, s ) ((e) == NULL ? NULL : (e)->clone (s))


/*******************************************************************************
  Iterator macros
********************************************************************************/

static expr_t dummy_expr;
static expr_t* expr_iter_done = &dummy_expr;

#define BEGIN_EXPR_ITER() switch (v.theState) { case 0:


#define BEGIN_EXPR_ITER2( type )                                       \
  type##_iterator_data &vv = dynamic_cast<type##_iterator_data &>(v);  \
  BEGIN_EXPR_ITER()

#define END_EXPR_ITER()   v.theCurrentChild = expr_iter_done; }


#define ITER( m )                                                \
do                                                               \
{                                                                \
  v.theState = __LINE__;                                         \
  v.theCurrentChild = reinterpret_cast<expr_t*>(&(m));           \
                                                                 \
  if ((m) != NULL) { invalidate(); return; }                     \
                                                                 \
  case __LINE__:;                                                \
                                                                 \
} while (0)


#define ITER_FOR_EACH( iter, begin, end, expr )                  \
for (vv.iter = (begin); vv.iter != (end); ++(vv.iter))           \
{                                                                \
  ITER(expr);                                                    \
}


/*******************************************************************************
  Class expr_iterator
********************************************************************************/
expr_iterator::expr_iterator(const expr_iterator& other) 
  :
  iter(new expr_iterator_data(*other.iter)) 
{
}


expr_iterator::~expr_iterator() 
{
  delete iter; 
}


expr_iterator& expr_iterator::operator=(const expr_iterator& other) 
{
  if (this != &other) 
  {
    delete iter;
    iter = new expr_iterator_data(*other.iter);
  }
  return *this;
}


expr_iterator& expr_iterator::operator++()
{
  iter->next();
  return *this; 
}


expr_iterator expr_iterator::operator++(int)
{
  expr_iterator old;
  old = *this;
  ++*this;
  return old;
}


expr_t& expr_iterator::operator*()
{
  return *(iter->theCurrentChild);
}


bool expr_iterator::done() const 
{
  return iter->done();
}


/*******************************************************************************
  Class expr_iterator_data
********************************************************************************/
bool expr_iterator_data::done() const 
{
  return theCurrentChild == expr_iter_done;
}


/*******************************************************************************
  Specific expr_iterator_data classes
********************************************************************************/
class fo_expr_iterator_data : public expr_iterator_data 
{
public:
  std::vector<expr_t>::iterator arg_iter;
  
public:
  fo_expr_iterator_data (expr* e) : expr_iterator_data(e) {}
};


class trycatch_expr_iterator_data : public expr_iterator_data 
{
public:
  std::vector<trycatch_expr::clauseref_t>::const_iterator clause_iter;

  trycatch_expr_iterator_data (expr* e) : expr_iterator_data(e) {}
};


class relpath_expr_iterator_data : public expr_iterator_data 
{
public:
  std::vector<expr_t>::iterator step_iter;

  relpath_expr_iterator_data (expr* e) : expr_iterator_data(e) {}
};


class axis_step_expr_iterator_data : public expr_iterator_data 
{
public:
  std::vector<expr_t>::iterator pred_iter;

  axis_step_expr_iterator_data (expr* e) : expr_iterator_data(e) {}
};


class transform_expr_iterator_data : public expr_iterator_data 
{
public:
  std::vector<rchandle<copy_clause> >::iterator clause_iter;
  transform_expr_iterator_data (expr* e) : expr_iterator_data(e) {}
};


class eval_expr_iterator_data : public expr_iterator_data 
{
public:
  checked_vector<eval_expr::eval_var>::iterator var_iter;

  eval_expr_iterator_data (expr* e) : expr_iterator_data(e) {}
};


class debugger_expr_iterator_data: public expr_iterator_data 
{
public:
  checked_vector<eval_expr::eval_var>::iterator var_iter;
  
  debugger_expr_iterator_data (expr* e) : expr_iterator_data(e) {}
};


class sequential_expr_iterator_data : public expr_iterator_data 
{
public:
  checked_vector<expr_t>::iterator iter;

  sequential_expr_iterator_data(expr* e) : expr_iterator_data(e) {}
};




/*******************************************************************************
  Base expr class
********************************************************************************/

expr::expr(short sctx, const QueryLoc& _loc) : theSctxId(sctx), loc(_loc) 
{
  invalidate();
  theCache.type.sctx = NULL;
  theCache.upd_seq_kind.kind = VACUOUS_EXPR;
}

  
expr::~expr() 
{
}


void expr::serialize(::zorba::serialization::Archiver& ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  serialize_baseclass(ar, (AnnotationHolder*)this);
  ar & theSctxId;
  ar & loc;
  ar & theCache.type.valid;
  ar & theCache.type.t;
  ar & theCache.type.sctx;
  ar & theCache.upd_seq_kind.valid;
  SERIALIZE_ENUM(expr_update_t, theCache.upd_seq_kind.kind);
}


expr_update_t expr::get_update_type() const 
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
  if (! theCache.upd_seq_kind.valid)
    compute_upd_seq_kind();

  return theCache.upd_seq_kind.kind == UPDATE_EXPR;
}

  
bool expr::is_sequential() const 
{
  if (! theCache.upd_seq_kind.valid)
    compute_upd_seq_kind();

  return theCache.upd_seq_kind.kind == SEQUENTIAL_EXPR;
}
  

bool expr::is_vacuous() const 
{
  if (! theCache.upd_seq_kind.valid)
    compute_upd_seq_kind();

  return theCache.upd_seq_kind.kind == VACUOUS_EXPR;
}


bool expr::is_simple() const 
{
  if (! theCache.upd_seq_kind.valid)
    compute_upd_seq_kind();

  return theCache.upd_seq_kind.kind == SIMPLE_EXPR;
}


bool expr::is_updating_or_vacuous() const 
{
  if (! theCache.upd_seq_kind.valid)
    compute_upd_seq_kind();

  return (theCache.upd_seq_kind.kind == UPDATE_EXPR ||
          theCache.upd_seq_kind.kind == VACUOUS_EXPR);
}


void expr::compute_upd_seq_kind() const 
{
  theCache.upd_seq_kind.kind = SIMPLE_EXPR;
  theCache.upd_seq_kind.valid = true;
}


expr_update_t expr::update_type_anding(
    expr_update_t type1, 
    expr_update_t type2, 
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
  

xqtref_t expr::return_type(static_context* sctx) 
{
  if (! cache_compliant())
    return DEBUG_RT(this, return_type_impl(sctx));

  if (! theCache.type.valid ||
      (theCache.type.sctx != sctx && // ????
       ! TypeOps::is_subtype(*theCache.type.t, *GENV_TYPESYSTEM.ANY_SIMPLE_TYPE)))
  {
    theCache.type.t = DEBUG_RT(this, return_type_impl(sctx));
    theCache.type.sctx = sctx;
    theCache.type.valid = true;
  }

  return theCache.type.t;
}


xqtref_t expr::return_type_impl(static_context* sctx)
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


expr_iterator expr::expr_begin() 
{
  invalidate();
  expr_iterator_data* iter_data = make_iter();
  iter_data->next();
  return expr_iterator(iter_data);
}

  
void expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ZORBA_ASSERT (false);
  END_EXPR_ITER();
}


expr_iterator_data* expr::make_iter()
{
  return new expr_iterator_data(this);
}
  

expr_t expr::clone() 
{
  substitution_t subst;
  return clone(subst);
}


expr_t expr::clone(substitution_t& subst) 
{
  ZORBA_ERROR_LOC(XQP0019_INTERNAL_ERROR, get_loc());
  return NULL;
}


void expr::accept_children(expr_visitor& v)
{
  for (expr_iterator i = expr_begin(); ! i.done(); ++i) 
  {
    if (*i != NULL)
      (*i)->accept(v);
  }
}


string expr::toString() const 
{
  ostringstream oss;
  put(oss);
  return oss.str();
}


/*******************************************************************************

********************************************************************************/
void sequential_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & sequence;
}


void sequential_expr::compute_upd_seq_kind() const 
{
  theCache.upd_seq_kind.kind = SIMPLE_EXPR;
  bool vacuous = true;

  ulong numChildren = sequence.size();

  for (ulong i = 0; i < numChildren; ++i)
  {
    expr_update_t kind = sequence[i]->get_update_type();

    if (kind == SEQUENTIAL_EXPR || kind == UPDATE_EXPR)
    {
      theCache.upd_seq_kind.kind = SEQUENTIAL_EXPR;
      vacuous = false;
      break;
    }
    else if (kind == SIMPLE_EXPR)
    {
      vacuous = false;
    }
  }

  if (vacuous)
    theCache.upd_seq_kind.kind = VACUOUS_EXPR;

  theCache.upd_seq_kind.valid = true;
}


xqtref_t sequential_expr::return_type_impl(static_context *sctx)
{
  return sequence[sequence.size() - 1]->return_type(sctx);
}


expr_iterator_data* sequential_expr::make_iter() 
{
  return new sequential_expr_iterator_data(this);
}


void sequential_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER2(sequential_expr);

  ITER_FOR_EACH(iter, sequence.begin(), sequence.end(), (*vv.iter));

  END_EXPR_ITER();
}


expr_t sequential_expr::clone(substitution_t& subst) 
{
  vector<expr_t> seq2;
  for (unsigned i = 0; i < sequence.size(); i++)
    seq2.push_back(sequence [i]->clone(subst));

  return new sequential_expr(theSctxId, get_loc(), seq2);
}


/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
if_expr::if_expr(
  short sctxid,
  const QueryLoc& loc,
  static_context* sctx,
  expr_t condExpr,
  expr_t thenExpr,
  expr_t elseExpr)
  :
  expr(sctxid, loc),
  theThenExpr(thenExpr),
  theElseExpr(elseExpr)
{
  checkNonUpdating(condExpr);

  if (sctx != NULL &&
      !TypeOps::is_equal(*condExpr->return_type(sctx),
                         *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
  {
    fo_expr* boolExpr = new fo_expr(sctxid,
                                    loc,
                                    sctx->lookup_fn("fn", "boolean", 1),
                                    condExpr);
    condExpr = boolExpr;
  }

  theCondExpr = condExpr;

  compute_upd_seq_kind();
}


void if_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theCondExpr;
  ar & theThenExpr;
  ar & theElseExpr;
}
  

void if_expr::compute_upd_seq_kind() const 
{
  expr_update_t thenKind = theThenExpr->get_update_type();
  expr_update_t elseKind = theElseExpr->get_update_type();
  theCache.upd_seq_kind.kind = expr::update_type_anding(thenKind, elseKind, loc);
  theCache.upd_seq_kind.valid = true;
}


xqtref_t if_expr::return_type_impl(static_context* sctx) 
{
  return TypeOps::union_type(*theThenExpr->return_type(sctx),
                             *theElseExpr->return_type(sctx));
}


expr_t if_expr::clone(substitution_t& subst) 
{
  return new if_expr(theSctxId,
                     get_loc(),
                     NULL,
                     get_cond_expr()->clone(subst),
                     get_then_expr()->clone(subst),
                     get_else_expr()->clone(subst));
}


void if_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();

  ITER(theCondExpr);
  ITER(theThenExpr);
  ITER(theElseExpr);

  END_EXPR_ITER();
}


/*******************************************************************************
  Base for cast, treat, promote, castable, instanceof
********************************************************************************/
cast_or_castable_base_expr::cast_or_castable_base_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type)
  :
  expr(sctx, loc),
  theInputExpr(input),
  theTargetType(type)
{
  assert(type != NULL);
  assert(input != NULL);

  compute_upd_seq_kind();
}


void cast_or_castable_base_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theInputExpr;
  ar & theTargetType;
}


xqtref_t cast_or_castable_base_expr::get_target_type() const 
{
  return theTargetType;
}

void cast_or_castable_base_expr::set_target_type(xqtref_t target) 
{
  invalidate();
  theTargetType = target;
}


void cast_or_castable_base_expr::compute_upd_seq_kind() const 
{
  theCache.upd_seq_kind.kind = SIMPLE_EXPR;
  theCache.upd_seq_kind.valid = true;

  checkNonUpdating(theInputExpr);
}


/***************************************************************************//**
  Base for cast, treat, promote
********************************************************************************/
cast_base_expr::cast_base_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type)
  : 
  cast_or_castable_base_expr(sctx, loc, input, type)
{
}


void cast_base_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_or_castable_base_expr*)this);
}


xqtref_t cast_base_expr::return_type_impl(static_context* sctx) 
{
  TypeConstants::quantifier_t q =
  TypeOps::intersect_quant(TypeOps::quantifier(*theInputExpr->return_type(sctx)),
                           TypeOps::quantifier(*theTargetType));

  return sctx->get_typemanager()->create_type(*theTargetType, q);
}


/***************************************************************************//**
  CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
cast_expr::cast_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    xqtref_t type)
  :
  cast_base_expr(sctx, loc, inputExpr, type)
{
  assert(type->get_quantifier() == TypeConstants::QUANT_ONE ||
         type->get_quantifier() == TypeConstants::QUANT_QUESTION);
}


void cast_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_base_expr*)this);
}


bool cast_expr::is_optional() const 
{
  return TypeOps::quantifier(*theTargetType) == TypeConstants::QUANT_QUESTION; 
}


void cast_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
}


expr_t cast_expr::clone (substitution_t& subst) 
{
  return new cast_expr(theSctxId,
                       get_loc(),
                       get_input()->clone(subst), 
                       get_target_type());
}


/***************************************************************************//**
	TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?
********************************************************************************/
treat_expr::treat_expr(
  short sctx,
  const QueryLoc& loc,
  expr_t inputExpr,
  xqtref_t type,
  XQUERY_ERROR err,
  bool check_prime_)
:
  cast_base_expr(sctx, loc, inputExpr, type),
  theError(err),
  check_prime(check_prime_)
{
}


void treat_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_base_expr*)this);
  SERIALIZE_ENUM(XQUERY_ERROR, theError);
  ar & check_prime;
}


void treat_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
}


expr_t treat_expr::clone (substitution_t& subst) 
{
  return new treat_expr(theSctxId,
                        get_loc(),
                        get_input()->clone(subst), 
                        get_target_type(),
                        get_err(),
                        get_check_prime());
}


/***************************************************************************//**

********************************************************************************/
promote_expr::promote_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type)
  :
  cast_base_expr(sctx, loc, input, type)
{
}


void promote_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
}


expr_t promote_expr::clone(substitution_t& subst) 
{
  return new promote_expr(theSctxId, 
                          get_loc(),
                          get_input()->clone(subst),
                          get_target_type());
}


/***************************************************************************//**
  Base for castable, instanceof
********************************************************************************/
castable_base_expr::castable_base_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t input,
    xqtref_t type)
  :
  cast_or_castable_base_expr(sctx, loc, input, type)
{
}


void castable_base_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (cast_or_castable_base_expr*)this);
}


xqtref_t castable_base_expr::return_type_impl(static_context* sctx) 
{
  return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
}


/***************************************************************************//**
  CastableExpr ::= CastExpr ( "castable" "as" SingleType )?

  SingleType ::= AtomicType "?"?
********************************************************************************/
castable_expr::castable_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    xqtref_t type)
  :
  castable_base_expr (sctx, loc, inputExpr, type)
{
}


void castable_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (castable_base_expr*)this);
}


bool castable_expr::is_optional() const 
{
  return TypeOps::quantifier(*theTargetType) == TypeConstants::QUANT_QUESTION; 
}


void castable_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
}


expr_t castable_expr::clone (substitution_t& subst) 
{
  return new castable_expr(theSctxId, 
                           get_loc(),
                           get_input()->clone(subst),
                           get_target_type());
}


/***************************************************************************//**
	InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
instanceof_expr::instanceof_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    xqtref_t type)
  :
  castable_base_expr(sctx, loc, inputExpr, type)
{
}


void instanceof_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (castable_base_expr*)this);
}


void instanceof_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();  
}


expr_t instanceof_expr::clone (substitution_t& subst) 
{
  return new instanceof_expr(theSctxId,
                             get_loc(),
                             get_input()->clone(subst),
                             get_target_type());
}


/***************************************************************************//**

********************************************************************************/
name_cast_expr::name_cast_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t inputExpr,
    NamespaceContext_t aNCtx)
  :
  expr(sctx, loc),
  theInputExpr(inputExpr),
  theNCtx(aNCtx) 
{
}


void name_cast_expr::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theInputExpr;
  ar & theNCtx;
}


void name_cast_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theInputExpr);
  END_EXPR_ITER();
}

rchandle<namespace_context> name_cast_expr::getNamespaceContext() 
{
  return theNCtx;
}


expr_t name_cast_expr::clone(substitution_t& subst) 
{
  return new name_cast_expr(theSctxId,
                            get_loc(),
                            get_input()->clone(subst),
                            getNamespaceContext());
}


/*******************************************************************************
  first-order expressions. Represents function invocations as well as:

  OrExpr, AndExpr, ComparisonExpr, RangeExpr, AdditiveExpr, MultiplicativeExpr,
  UnionExpr, and IntersectExceptExpr.
********************************************************************************/

fo_expr* fo_expr::create_seq(short sctx, const QueryLoc& loc) 
{
  auto_ptr<fo_expr> fo(new fo_expr(sctx,
                                   loc,
                                   GENV.getRootStaticContext().lookup_builtin_fn(":" "concatenate", VARIADIC_SIG_SIZE)));

  return fo.release();
}


void fo_expr::serialize(::zorba::serialization::Archiver &ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & theArgs;
  SERIALIZE_FUNCTION((function*&)theFunction);
}


const signature& fo_expr::get_signature() const 
{
  return theFunction->get_signature();
}


store::Item_t fo_expr::get_fname() const
{ 
  return theFunction->get_fname(); 
}


expr_iterator_data* fo_expr::make_iter() 
{ 
  return new fo_expr_iterator_data(this); 
}


void fo_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER2(fo_expr);
  ITER_FOR_EACH(arg_iter, begin(), end(), *vv.arg_iter);
  END_EXPR_ITER();
}


void fo_expr::compute_upd_seq_kind() const 
{
  const function* func = get_func();
  ulong numArgs = size();

  if (func->getKind() == FunctionConsts::FN_CONCATENATE)
  {
    expr_update_t kind = VACUOUS_EXPR;

    for (ulong i = 0; i < numArgs; ++i) 
    {
      expr_update_t argKind = theArgs[i]->get_update_type();

      kind = update_type_anding(kind, argKind, theArgs[i]->get_loc());
    }

    theCache.upd_seq_kind.kind = kind;
  }
  else if (func->getKind() == FunctionConsts::FN_VAR_ASSIGN)
  {
    for (ulong i = 0; i < numArgs; ++i) 
    {
      expr_update_t argKind = theArgs[i]->get_update_type();
      
      if (argKind == UPDATE_EXPR)
      {
        ZORBA_ERROR_LOC(XUST0001, theArgs[i]->get_loc());
      }
    }
  }
  else
  {
    theCache.upd_seq_kind.kind = func->getUpdateType();

    for (ulong i = 0; i < numArgs; ++i) 
    {
      expr_update_t argKind = theArgs[i]->get_update_type();
      
      if (argKind == UPDATE_EXPR || argKind == SEQUENTIAL_EXPR)
      {
        ZORBA_ERROR_LOC(XUST0001, theArgs[i]->get_loc());
      }
    }
  }

  theCache.upd_seq_kind.valid = true;
}


xqtref_t fo_expr::return_type_impl(static_context* sctx)
{
  vector<xqtref_t> types;
  for (vector<expr_t>::const_iterator i = theArgs.begin(); i != theArgs.end(); ++i)
    types.push_back((*i)->return_type(sctx));

  return theFunction->return_type(types);
}


expr_t fo_expr::clone(substitution_t& subst) 
{
  std::auto_ptr<fo_expr> fo(new fo_expr(theSctxId, get_loc(), get_func()));

  for (unsigned i = 0; i < theArgs.size (); i++)
    fo->theArgs.push_back(theArgs[i]->clone(subst));

  return fo.release();
}


/*******************************************************************************
  Normally, it is used to wrap a var_expr in order to represent a var reference
  (see var_expr.h). But it may wrap any other kind of expr as well.
********************************************************************************/
void wrapper_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  ITER(theWrappedExpr);
  END_EXPR_ITER();
}


expr_t wrapper_expr::clone(substitution_t& subst) 
{
  expr_t e = theWrappedExpr->clone(subst);

  if (theWrappedExpr->get_expr_kind() == var_expr_kind &&
      e->get_expr_kind() != var_expr_kind)
    return e;
  else
    return new wrapper_expr(theSctxId, get_loc(), e);
}


xqtref_t wrapper_expr::return_type_impl(static_context* sctx) 
{
  return theWrappedExpr->return_type(sctx);
}


/*******************************************************************************

********************************************************************************/
void flwor_expr::compute_upd_seq_kind() const 
{
  expr* ret = get_return_expr();
  theCache.upd_seq_kind.kind = ret->get_update_type();
  theCache.upd_seq_kind.valid = true;
}


expr_iterator_data* debugger_expr::make_iter() 
{
  return new debugger_expr_iterator_data(this);
}

void debugger_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER2 (debugger_expr);
  ITER (expr_h);
  ITER_FOR_EACH (var_iter, vars.begin (), vars.end (), vv.var_iter->val);
  END_EXPR_ITER ();
}  


void var_expr::serialize(::zorba::serialization::Archiver &ar)
{
  serialize_baseclass(ar, (expr*)this);
  SERIALIZE_ENUM(var_kind, theKind);
  ar & theName;
  ar & theDeclaredType;
  //+ar & theFlworClause;
  //+ar & theCopyClause;
  if(!ar.is_serializing_out())
  {
    theFlworClause = NULL;
    theCopyClause = NULL;
  }
  ar & unique_id;
}

int var_expr::var_expr_count = 0;//used for giving var_exprs unique ids

string var_expr::decode_var_kind(enum var_kind k)
{
  switch (k) {
  case for_var: return "FOR"; break;
  case let_var: return "LET"; break;
  case win_var: return "WIN"; break;
  case pos_var: return "POS"; break;
  case wincond_out_var: return "WINCOND"; break;
  case wincond_in_var: return "WINCOND IN"; break;
  case wincond_out_pos_var: return "WINCOND POS"; break;
  case wincond_in_pos_var: return "WINCOND IN POS"; break;
  case count_var: return "CNT"; break;
  case score_var: return "SCORE"; break;
  case quant_var: return "QUANT"; break;
  case prolog_var: return "PROLOG"; break;
  case local_var: return "LOCAL"; break;
  case catch_var: return "CATCH"; break;
  case copy_var: return "COPY"; break;
  case groupby_var: return "GROUPBY"; break;
  case non_groupby_var: return "NON-GROUPBY"; break;
  case arg_var: return "ARG"; break;
  default: return "???";
  }
}


var_expr::var_expr(short sctx, const QueryLoc& loc, var_kind k, store::Item_t name)
  :
  expr(sctx, loc),
  theKind(k),
  theName(name),
  theDeclaredType(NULL),
  theFlworClause(NULL),
  theCopyClause(NULL)
{
  unique_id = var_expr_count++;
}


store::Item_t var_expr::get_varname() const 
{
  return theName;
}


xqtref_t var_expr::get_type() const 
{
  return theDeclaredType;
}


void var_expr::set_type(xqtref_t t) 
{
  theDeclaredType = t;
}


var_expr* var_expr::get_pos_var() const 
{
  if (theKind == for_var) {
    return reinterpret_cast<for_clause*>(theFlworClause)->get_pos_var();
  } else {
    return NULL;
  }
}


expr* var_expr::get_domain_expr() const
{
  if (theFlworClause)
  {
    if (theKind == for_var ||
        theKind == let_var ||
        theKind == win_var ||
        theKind == wincond_in_var ||
        theKind == wincond_out_var)
    {
      return reinterpret_cast<forletwin_clause*>(theFlworClause)->get_expr();
    }
    else if (theKind == groupby_var)
    {
      return reinterpret_cast<group_clause*>(theFlworClause)->
             get_input_for_group_var(this);
    }
    else if (theKind == non_groupby_var)
    {
      return reinterpret_cast<group_clause*>(theFlworClause)->
             get_input_for_nongroup_var(this);
    }
  }
  else if (theCopyClause)
  {
    return theCopyClause->getExpr();
  }

  return NULL;
}


forletwin_clause* var_expr::get_forletwin_clause() const 
{
  return dynamic_cast<forletwin_clause*>(theFlworClause);
}


for_clause* var_expr::get_for_clause() const 
{
  return dynamic_cast<for_clause*>(theFlworClause);
}


void var_expr::next_iter(expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}


expr::expr_t var_expr::clone(expr::substitution_t& subst) 
{
  expr::subst_iter_t i = subst.find(this);

  if (i == subst.end()) 
    return this;

  return i->second->clone(subst);
}


/*******************************************************************************

********************************************************************************/
forletwin_clause::forletwin_clause(
    short sctx,
    const QueryLoc& loc,
    flwor_clause::ClauseKind kind,
    varref_t varExpr,
    expr_t domainExpr)
  :
  flwor_clause(sctx, loc, kind),
  theVarExpr(varExpr),
  theDomainExpr(domainExpr)
{
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(this);
}


forletwin_clause::~forletwin_clause() 
{
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(NULL);
}


/*******************************************************************************

********************************************************************************/
for_clause::for_clause(
    short sctx,
    const QueryLoc& loc,
    varref_t varExpr,
    expr_t domainExpr,
    varref_t posVarExpr,
    varref_t scoreVarExpr,
    bool isOuter)
  :
  forletwin_clause(sctx, loc, flwor_clause::for_clause, varExpr, domainExpr),
  thePosVarExpr(posVarExpr),
  theScoreVarExpr(scoreVarExpr),
  theIsOuter(isOuter)
{
  if (thePosVarExpr != NULL)
    thePosVarExpr->set_flwor_clause(this);

  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);
}


for_clause::~for_clause() 
{
  if (thePosVarExpr != NULL)
    thePosVarExpr->set_flwor_clause(NULL);

  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(NULL);
}


flwor_clause_t for_clause::clone(expr::substitution_t& subst) 
{
  expr_t domainCopy = theDomainExpr->clone(subst);

  varref_t varCopy(new var_expr(*theVarExpr));
  subst[theVarExpr.getp()] = varCopy.getp();

  varref_t posvarCopy;
  var_expr *pos_var_ptr = thePosVarExpr.getp();
  if (pos_var_ptr) 
  {
    posvarCopy = new var_expr(*pos_var_ptr);
    subst[pos_var_ptr] = posvarCopy.getp();
  }

  varref_t scorevarCopy;
  var_expr* score_var_ptr = theScoreVarExpr.getp();
  if (score_var_ptr) 
  {
    scorevarCopy = new var_expr(*score_var_ptr);
    subst[score_var_ptr] = scorevarCopy.getp();
  }

  return new for_clause(theContext,
                        get_loc(),
                        varCopy,
                        domainCopy,
                        posvarCopy,
                        scorevarCopy,
                        theIsOuter);
}


/*******************************************************************************

********************************************************************************/
let_clause::let_clause(
    short sctx,
    const QueryLoc& loc,
    varref_t varExpr,
    expr_t domainExpr,
    varref_t scoreVarExpr)
  :
  forletwin_clause(sctx, loc, flwor_clause::let_clause, varExpr, domainExpr),
  theScoreVarExpr(scoreVarExpr)
{
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(this);
}


let_clause::~let_clause() {
  if (theScoreVarExpr != NULL)
    theScoreVarExpr->set_flwor_clause(NULL);
}


flwor_clause_t let_clause::clone(expr::substitution_t& subst) 
{
  expr_t domainCopy = theDomainExpr->clone(subst);

  varref_t varCopy(new var_expr(*theVarExpr));
  subst[theVarExpr.getp()] = varCopy.getp();

  varref_t scorevarCopy;
  var_expr* score_var_ptr = theScoreVarExpr.getp();
  if (score_var_ptr) 
  {
    scorevarCopy = new var_expr(*score_var_ptr);
    subst[score_var_ptr] = scorevarCopy.getp();
  }

  return new let_clause(theContext, get_loc(), varCopy, domainCopy, scorevarCopy);
}


/*******************************************************************************

********************************************************************************/
window_clause::window_clause(
    short sctx,
    const QueryLoc& loc,
    window_t winKind,
    varref_t varExpr,
    expr_t domainExpr,
    flwor_wincond_t winStart,
    flwor_wincond_t winStop)
  :
  forletwin_clause(sctx, loc, flwor_clause::window_clause, varExpr, domainExpr),
  theWindowKind(winKind),
  theWinStartCond(winStart),
  theWinStopCond(winStop)
{
  if (theWinStartCond != NULL)
    theWinStartCond->set_flwor_clause(this);

  if (theWinStopCond != NULL)
    theWinStopCond->set_flwor_clause(this);
}


window_clause::~window_clause() 
{
  if (theWinStartCond != NULL)
    theWinStartCond->set_flwor_clause(NULL);

  if (theWinStopCond != NULL)
    theWinStopCond->set_flwor_clause(NULL);
}


void window_clause::set_win_start(flwor_wincond* cond)
{
  theWinStartCond = cond;
  if (theWinStartCond != NULL)
    theWinStartCond->set_flwor_clause(this);
}


void window_clause::set_win_stop(flwor_wincond* cond)
{
  theWinStopCond = cond;
  if (theWinStopCond != NULL)
    theWinStopCond->set_flwor_clause(this);
}


flwor_clause_t window_clause::clone(expr::substitution_t& subst) 
{
  expr_t domainCopy = theDomainExpr->clone(subst);

  varref_t varCopy(new var_expr(*theVarExpr));
  subst[theVarExpr.getp()] = varCopy.getp();

  flwor_wincond_t cloneStartCond;
  flwor_wincond_t cloneStopCond;

  if (theWinStartCond != NULL)
    cloneStartCond = theWinStartCond->clone(subst);

  if (theWinStopCond != NULL)
    cloneStopCond = theWinStopCond->clone(subst);

  return new window_clause(theContext,
                           get_loc(),
                           theWindowKind,
                           varCopy,
                           domainCopy,
                           cloneStartCond,
                           cloneStopCond);
}


/*******************************************************************************

********************************************************************************/
flwor_wincond::flwor_wincond(
    static_context* sctx,
    bool isOnly,
    const vars& in_vars,
    const vars& out_vars,
    expr_t cond)
  :
  theIsOnly(isOnly),
  theInputVars(in_vars),
  theOutputVars(out_vars),
  theCondExpr(cond)
{
  xqtref_t condType = theCondExpr->return_type(sctx);

  if (sctx != NULL &&
      !TypeOps::is_equal(*condType, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
  {
    theCondExpr = new fo_expr(theCondExpr->get_sctx_id(),
                              theCondExpr->get_loc(),
                              sctx->lookup_fn("fn", "boolean", 1),
                              theCondExpr);
  }
}


void flwor_wincond::vars::set_flwor_clause(flwor_clause* c) 
{
  if (posvar != NULL) posvar->set_flwor_clause(c);
  if (curr != NULL) curr->set_flwor_clause(c);
  if (prev != NULL) prev->set_flwor_clause(c);
  if (next != NULL) next->set_flwor_clause(c);
}


void flwor_wincond::vars::clone(
    flwor_wincond::vars& cloneVars,
    expr::substitution_t& subst) 
{
  if (posvar != NULL) {
    varref_t varCopy(new var_expr(*posvar));
    subst[posvar.getp()] = varCopy.getp();
    cloneVars.posvar = varCopy;
  }
 
  if (curr != NULL) {
    varref_t varCopy(new var_expr(*curr));
    subst[curr.getp()] = varCopy.getp();
    cloneVars.curr = varCopy;
  }

  if (prev != NULL) {
    varref_t varCopy(new var_expr(*prev));
    subst[prev.getp()] = varCopy.getp();
    cloneVars.prev = varCopy;
  }

  if (next != NULL) {
    varref_t varCopy(new var_expr(*next));
    subst[next.getp()] = varCopy.getp();
    cloneVars.next = varCopy;
  }
}


void flwor_wincond::set_flwor_clause(flwor_clause* c) 
{
  theInputVars.set_flwor_clause(c);
  theOutputVars.set_flwor_clause(c);
}


flwor_wincond_t flwor_wincond::clone(expr::substitution_t& subst) 
{
  flwor_wincond::vars cloneInVars;
  flwor_wincond::vars cloneOutVars;

  theInputVars.clone(cloneInVars, subst);
  theOutputVars.clone(cloneOutVars, subst);

  expr_t cloneCondExpr = theCondExpr->clone(subst);

  return new flwor_wincond(NULL, theIsOnly, cloneInVars, cloneOutVars, cloneCondExpr);
}


/*******************************************************************************

********************************************************************************/
group_clause::group_clause(
     short sctx,
     const QueryLoc& loc,
     const rebind_list_t& gvars,
     rebind_list_t ngvars,
     const std::vector<std::string>& collations)
  :
  flwor_clause(sctx, loc, flwor_clause::group_clause),
  theGroupVars(gvars),
  theNonGroupVars(ngvars),
  theCollations(collations)
{
  ulong numGVars = theGroupVars.size();
  ulong numNGVars = theNonGroupVars.size();
  
  for (ulong i = 0; i < numGVars; ++i)
    theGroupVars[i].second->set_flwor_clause(this);

  for (ulong i = 0; i < numNGVars; ++i)
    theNonGroupVars[i].second->set_flwor_clause(this);
}


group_clause::~group_clause() 
{
  ulong numGVars = theGroupVars.size();
  ulong numNGVars = theNonGroupVars.size();
  
  for (ulong i = 0; i < numGVars; ++i)
    theGroupVars[i].second->set_flwor_clause(NULL);

  for (ulong i = 0; i < numNGVars; ++i)
    theNonGroupVars[i].second->set_flwor_clause(NULL);
}


expr* group_clause::get_input_for_group_var(const var_expr* var)
{
  ulong numVars = theGroupVars.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    if (theGroupVars[i].second.getp() == var)
      return theGroupVars[i].first.getp();
  }

  return NULL;
}


expr* group_clause::get_input_for_nongroup_var(const var_expr* var)
{
  ulong numVars = theNonGroupVars.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    if (theNonGroupVars[i].second.getp() == var)
      return theNonGroupVars[i].first.getp();
  }

  return NULL;
}


flwor_clause_t group_clause::clone(expr::substitution_t& subst) 
{
  ulong numGroupVars = theGroupVars.size();
  ulong numNonGroupVars = theNonGroupVars.size();

  rebind_list_t cloneGroupVars(numGroupVars);
  rebind_list_t cloneNonGroupVars(numNonGroupVars);

  for (ulong i = 0; i < numGroupVars; ++i) 
  {
    cloneGroupVars[i].first = theGroupVars[i].first->clone(subst);
    cloneGroupVars[i].second = new var_expr(*theGroupVars[i].second);
    subst[theGroupVars[i].second.getp()] = cloneGroupVars[i].second.getp();
  }

  for (ulong i = 0; i < numNonGroupVars; ++i) 
  {
    cloneNonGroupVars[i].first = theNonGroupVars[i].first->clone(subst);
    cloneNonGroupVars[i].second = new var_expr(*theNonGroupVars[i].second);
    subst[theNonGroupVars[i].second.getp()] = cloneNonGroupVars[i].second.getp();
  }

  return new group_clause(theContext, get_loc(), cloneGroupVars, cloneNonGroupVars, theCollations);
}


/*******************************************************************************

********************************************************************************/
flwor_clause_t orderby_clause::clone(expr::substitution_t& subst) 
{
  ulong numColumns = num_columns();

  std::vector<expr_t> cloneExprs(numColumns);

  for (ulong i = 0; i < numColumns; ++i)
  {
    cloneExprs[i] = theOrderingExprs[i]->clone(subst);
  }

  return new orderby_clause(theContext,
                            get_loc(),
                            theStableOrder,
                            theModifiers,
                            cloneExprs);
}


/*******************************************************************************

********************************************************************************/
count_clause::~count_clause() {
  if (theVarExpr != NULL)
    theVarExpr->set_flwor_clause(NULL);
}


flwor_clause_t count_clause::clone(expr::substitution_t& subst) {
  varref_t cloneVar = new var_expr(*theVarExpr);
  subst[theVarExpr.getp()] = cloneVar;

  return new count_clause(theContext, get_loc(), cloneVar);
}


/*******************************************************************************

********************************************************************************/
flwor_clause_t where_clause::clone(expr::substitution_t& subst) 
{
  expr_t cloneExpr = theWhereExpr->clone(subst);

  return new where_clause(theContext, get_loc(), cloneExpr);
}


/*******************************************************************************

********************************************************************************/
class flwor_expr_iterator_data : public expr_iterator_data 
{
public:
  flwor_expr::clause_list_t::iterator    theClausesIter;
  flwor_expr::clause_list_t::iterator    theClausesEnd;
  std::vector<expr_t>::iterator          theOrderExprsIter;
  std::vector<expr_t>::iterator          theOrderExprsEnd;
  flwor_clause::rebind_list_t::iterator  theGroupVarsIter;
  flwor_clause::rebind_list_t::iterator  theGroupVarsEnd;
  flwor_clause::rebind_list_t::iterator  theNonGroupVarsIter;
  flwor_clause::rebind_list_t::iterator  theNonGroupVarsEnd;
  int                                    theWincondIter;

public:
  flwor_expr_iterator_data(expr* e) : expr_iterator_data(e), theWincondIter(0) {}
};


/*******************************************************************************

********************************************************************************/
void flwor_expr::add_clause(flwor_clause* c) 
{
  theClauses.push_back(c);
}


void flwor_expr::add_clause(ulong pos, flwor_clause* c) 
{
  theClauses.insert(theClauses.begin() + pos, c);
}


void flwor_expr::add_where(expr_t e) 
{
  where_clause* whereClause = new where_clause(theSctxId, e->get_loc(), e);

  theClauses.push_back(whereClause);
}


expr* flwor_expr::get_where() const 
{
  unsigned numClauses = num_clauses();
  for (unsigned i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::where_clause)
      return reinterpret_cast<where_clause*>(theClauses[i].getp())->get_where();
  }

  return NULL;
}


void flwor_expr::set_where(expr* e) 
{
  ZORBA_ASSERT(e != NULL);

  unsigned numClauses = num_clauses();
  unsigned i;

  for (i = 0; i < numClauses; ++i) {
    if (theClauses[i]->get_kind() != flwor_clause::for_clause &&
        theClauses[i]->get_kind() != flwor_clause::let_clause)
    {
      break;
    }
  }

  if (i == numClauses) {
    add_where(e);
    return;
  }

  if (theClauses[i]->get_kind() == flwor_clause::where_clause) {
    where_clause* wc = reinterpret_cast<where_clause*>(theClauses[i].getp());
    wc->set_where(e);
    return;
  }

  where_clause* wc = new where_clause(theSctxId, e->get_loc(), e);
  theClauses.insert(theClauses.begin() + i, wc);
}


void flwor_expr::remove_where_clause() 
{
  unsigned numClauses = num_clauses();
  for (unsigned i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::where_clause)
    {
      theClauses.erase(theClauses.begin() + i);
      return;
    }
  }
}


group_clause* flwor_expr::get_group_clause() const 
{
  ulong numClauses = num_clauses();
  for (ulong i = 0; i < numClauses; ++i)
  {
    if (theClauses[i]->get_kind() == flwor_clause::group_clause)
      return reinterpret_cast<group_clause*>(theClauses[i].getp());
  }

  return NULL;
}


ulong flwor_expr::num_forlet_clauses() 
{
  ulong num = 0;
  ulong numClauses = num_clauses();
  for (ulong i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = theClauses[i];
    
    if (c->get_kind() == flwor_clause::for_clause ||
        c->get_kind() == flwor_clause::let_clause)
    {
      ++num;
    }
  }

  return num;
}


void flwor_expr::remove_clause(ulong pos) 
{
  theClauses.erase(theClauses.begin() + pos);
}


long flwor_expr::defines_variable(const var_expr* v, const flwor_clause* limit) const
{
  ulong numClauses = theClauses.size();

  for (ulong i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = theClauses[i];

    if (v->get_flwor_clause() == limit)
      break;

    if (c->get_kind() == flwor_clause::for_clause)
    {
      const for_clause* fc = static_cast<const for_clause *>(c);

      if (fc->get_var() == v || fc->get_pos_var() == v)
        return i;
    }
    else if (c->get_kind() == flwor_clause::let_clause)
    {
      const let_clause* lc = static_cast<const let_clause *>(c);

      if (lc->get_var() == v)
        return i;
    }
    else if (c->get_kind() == flwor_clause::window_clause)
    {
      const window_clause* wc = static_cast<const window_clause *>(c);

      if (wc->get_var() == v)
        return i;

      const flwor_wincond* startCond = wc->get_win_start();
      const flwor_wincond* stopCond = wc->get_win_stop();
      const flwor_wincond::vars& startVars = startCond->get_out_vars();
      const flwor_wincond::vars& stopVars = stopCond->get_out_vars();

      if (startVars.posvar.getp() == v) return i;
      if (startVars.curr.getp() == v) return i;
      if (startVars.prev.getp() == v) return i;
      if (startVars.next.getp() == v) return i;

      if (stopVars.posvar.getp() == v) return i;
      if (stopVars.curr.getp() == v) return i;
      if (stopVars.prev.getp() == v) return i;
      if (stopVars.next.getp() == v) return i;
    }
    else if (c->get_kind() == flwor_clause::group_clause) 
    {
      const group_clause* gc = static_cast<const group_clause *>(c);

      const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
      ulong numGroupVars = gvars.size();

      for (ulong k = 0; k < numGroupVars; ++k) {
        if (gvars[k].second.getp() == v)
          return i;
      }

      const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
      ulong numNonGroupVars = ngvars.size();

      for (ulong k = 0; k < numNonGroupVars; ++k) {
        if (ngvars[k].second.getp() == v)
          return i;
      }
    }
  }

  return -1;
}


void flwor_expr::get_vars_defined(std::vector<var_expr*>& varExprs)
{
  // put in the given the var_exprs for the variables defined by this flwor expr

  ulong numClauses = theClauses.size();

  for (ulong i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = theClauses[i];

    if (c->get_kind() == flwor_clause::for_clause)
    {
      const for_clause* fc = static_cast<const for_clause *>(c);

      varExprs.push_back(fc->get_var());

      if (fc->get_pos_var())
        varExprs.push_back(fc->get_pos_var());;
    }
    else if (c->get_kind() == flwor_clause::let_clause)
    {
      const let_clause* lc = static_cast<const let_clause *>(c);

      varExprs.push_back(lc->get_var());
    }
    else if (c->get_kind() == flwor_clause::window_clause)
    {
      const window_clause* wc = static_cast<const window_clause *>(c);

      varExprs.push_back(wc->get_var());

      const flwor_wincond* startCond = wc->get_win_start();
      const flwor_wincond* stopCond = wc->get_win_stop();
      const flwor_wincond::vars& startVars = startCond->get_out_vars();
      const flwor_wincond::vars& stopVars = stopCond->get_out_vars();

      if (startVars.posvar) varExprs.push_back(startVars.posvar.getp());
      if (startVars.curr) varExprs.push_back(startVars.curr.getp());
      if (startVars.prev) varExprs.push_back(startVars.prev.getp());
      if (startVars.next) varExprs.push_back(startVars.next.getp());

      if (stopVars.posvar) varExprs.push_back(stopVars.posvar.getp());
      if (stopVars.curr) varExprs.push_back(stopVars.curr.getp());
      if (stopVars.prev) varExprs.push_back(stopVars.prev.getp());
      if (stopVars.next) varExprs.push_back(stopVars.next.getp());
    }
  }
}


expr_t flwor_expr::clone(substitution_t& subst) 
{
  ulong numClauses = num_clauses();

  flwor_expr_t cloneFlwor = new flwor_expr(theSctxId, get_loc(), theIsGeneral);

  for (ulong i = 0; i < numClauses; ++i) {
    flwor_clause_t cloneClause = theClauses[i]->clone(subst);

    cloneFlwor->add_clause(cloneClause.getp());
  }

  cloneFlwor->set_return_expr(theReturnExpr->clone(subst));

  return cloneFlwor.getp();
}


void flwor_expr::accept_children(expr_visitor& v) 
{
  ulong numClauses = num_clauses();

  for (ulong i = 0; i < numClauses; ++i) 
  {
    const flwor_clause* c = theClauses[i];

    switch (c->get_kind()) {

    case flwor_clause::for_clause: {
      v.visit_flwor_clause(c, theIsGeneral);

      const for_clause* fc = reinterpret_cast<const for_clause*>(c);
      fc->get_expr()->accept(v);
      break;
    }

    case flwor_clause::let_clause: {
      v.visit_flwor_clause(c, theIsGeneral);

      const for_clause* fc = reinterpret_cast<const for_clause*>(c);
      fc->get_expr()->accept(v);
      break;
    }

    case flwor_clause::window_clause: {
      v.visit_flwor_clause(c, theIsGeneral);

      const window_clause* wc = reinterpret_cast<const window_clause*>(c);

      flwor_wincond* startCond = wc->get_win_start();
      flwor_wincond* stopCond = wc->get_win_stop();

      if (startCond)
        startCond->get_cond()->accept(v);

      if (stopCond)
        stopCond->get_cond()->accept(v);

      wc->get_expr()->accept(v);

      break;
    }

    case flwor_clause::group_clause: {
      const group_clause* gc = reinterpret_cast<const group_clause*>(c);

      const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
      const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
      
      for (ulong i = 0; i < gvars.size(); ++i)
      {
        gvars[i].first->accept(v);
      }

      for (ulong i = 0; i < ngvars.size(); ++i)
      {
        ngvars[i].first->accept(v);
      }

      v.visit_flwor_clause(c, theIsGeneral);

      break;
    }

    case flwor_clause::order_clause: {
      const orderby_clause* oc = reinterpret_cast<const orderby_clause*>(c);

      ulong numCols = oc->num_columns();
      for (ulong i = 0; i < numCols; ++i)
      {
        oc->get_column_expr(i)->accept(v);
      }

      v.visit_flwor_clause(c, theIsGeneral);

      break;
    }

    case flwor_clause::count_clause: {
      v.visit_flwor_clause(c, theIsGeneral);
      break;
    }

    case flwor_clause::where_clause: {
      const where_clause* wc = reinterpret_cast<const where_clause*>(c);
      wc->get_where()->accept(v);
      break;
    }
    default:
      ZORBA_ASSERT(false);
    }
  }

  theReturnExpr->accept(v);
}


expr_iterator_data* flwor_expr::make_iter() 
{
  return new flwor_expr_iterator_data(this);
}


void flwor_expr::next_iter(expr_iterator_data& v) 
{
  flwor_clause* c = NULL;
  window_clause* wc = NULL;
  flwor_wincond* wincond = NULL;
  orderby_clause* oc = NULL;
  group_clause* gc = NULL;

  flwor_expr_iterator_data& iter = dynamic_cast<flwor_expr_iterator_data &>(v);

  BEGIN_EXPR_ITER();

  iter.theClausesIter = theClauses.begin();
  iter.theClausesEnd = theClauses.end();

  for (; iter.theClausesIter != iter.theClausesEnd; ++(iter.theClausesIter))
  {
    c = (iter.theClausesIter)->getp();

    if (c->get_kind() == flwor_clause::for_clause) {
      ITER(static_cast<for_clause *>(c)->theDomainExpr);
    }

    else if (c->get_kind() == flwor_clause::let_clause) {
      ITER(static_cast<let_clause *>(c)->theDomainExpr);
    }

    else if (c->get_kind() == flwor_clause::window_clause) {
      for (iter.theWincondIter = 0; iter.theWincondIter < 2; iter.theWincondIter++) 
      {
        wc = static_cast<window_clause *>((iter.theClausesIter)->getp());

        wincond = (iter.theWincondIter == 0 ?
                   wc->theWinStartCond.getp() :
                   wc->theWinStopCond.getp());

        if (wincond != 0)
          ITER(wincond->theCondExpr);
      }

      wc = static_cast<window_clause *>((iter.theClausesIter)->getp());

      ITER(wc->theDomainExpr);
    }

    else if (c->get_kind() == flwor_clause::where_clause) {
      ITER(static_cast<where_clause *>(c)->theWhereExpr);
    }

    else if (c->get_kind() == flwor_clause::group_clause) {
      gc = static_cast<group_clause *>(c);

      iter.theGroupVarsIter = gc->theGroupVars.begin();
      iter.theGroupVarsEnd = gc->theGroupVars.end();
      iter.theNonGroupVarsIter = gc->theNonGroupVars.begin();
      iter.theNonGroupVarsEnd = gc->theNonGroupVars.end();

      for (; iter.theGroupVarsIter != iter.theGroupVarsEnd; ++iter.theGroupVarsIter)
      {
        ITER((*iter.theGroupVarsIter).first);
      }

      for (;
           iter.theNonGroupVarsIter != iter.theNonGroupVarsEnd;
           ++iter.theNonGroupVarsIter)
      {
        ITER((*iter.theNonGroupVarsIter).first);
      }
    }

    else if (c->get_kind() == flwor_clause::order_clause) {
      oc = static_cast<orderby_clause *>(c);

      iter.theOrderExprsIter = oc->theOrderingExprs.begin();
      iter.theOrderExprsEnd = oc->theOrderingExprs.end();

      for (; iter.theOrderExprsIter != iter.theOrderExprsEnd; ++iter.theOrderExprsIter)
      {
        ITER(*iter.theOrderExprsIter);
      }
    }
  }

  ITER(theReturnExpr);
  
  END_EXPR_ITER(); 
}


catch_clause::catch_clause()
  : catch_expr_h(NULL)
{
}

expr_iterator_data *trycatch_expr::make_iter() 
{
  return new trycatch_expr_iterator_data(this);
}

trycatch_expr::trycatch_expr(short sctx,
                             const QueryLoc& loc)
  : expr(sctx, loc) {}

void trycatch_expr::next_iter(expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (trycatch_expr);
  ITER (try_expr_h);
  for (vv.clause_iter = begin (); vv.clause_iter != end (); ++(vv.clause_iter)) {
    ITER ((*vv.clause_iter)->catch_expr_h);
  }
  END_EXPR_ITER ();
}


expr_iterator_data *eval_expr::make_iter () 
{
  return new eval_expr_iterator_data (this);
}

void eval_expr::next_iter (expr_iterator_data& v) 
{
  BEGIN_EXPR_ITER2 (eval_expr);
  ITER (expr_h);
  ITER_FOR_EACH (var_iter, vars.begin (), vars.end (), vv.var_iter->val);
  END_EXPR_ITER ();
}

eval_expr::eval_var::eval_var (var_expr *ve, expr_t val_)
  : varname (ve->get_varname ()),
    var_key (dynamic_context::var_key (ve)), type(ve->get_type()), val (val_)
{
}


// [48a] [http://www.w3.org/TR/xquery-full-text/#prod-xquery-FTContainsExpr]

ft_contains_expr::ft_contains_expr(
    short sctx,
    const QueryLoc& loc,
    expr_t _range_h,
    expr_t _ft_select_h,
    expr_t _ft_ignore_h)
  :
  expr(sctx, loc),
  range_h(_range_h),
  ft_select_h(_ft_select_h),
  ft_ignore_h(_ft_ignore_h)
{
}


void ft_contains_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (range_h);
  ITER (ft_select_h);
  ITER (ft_ignore_h);
  END_EXPR_ITER ();
}


// [63] [http://www.w3.org/TR/xquery/#prod-xquery-ValidateExpr]

validate_expr::validate_expr(
  short sctx,
  const QueryLoc& loc,
  enum ParseConstants::validation_mode_t _valmode,
  store::Item_t aTypeName,
  expr_t _expr_h, rchandle<TypeManager> typemgr_)
:
  expr(sctx, loc),
  valmode(_valmode),
  typeName(aTypeName),
  typemgr (typemgr_),
  expr_h(_expr_h)
{}


void validate_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (expr_h);
  END_EXPR_ITER ();
}

expr_t validate_expr::clone(substitution_t &subst) {
  return new validate_expr (theSctxId,
                            get_loc (),
                            get_valmode (),
                            get_type_name (),
                            get_expr ()->clone (subst),
                            get_typemgr ());
}


// [65] [http://www.w3.org/TR/xquery/#prod-xquery-ExtensionExpr]

extension_expr::extension_expr(
  short sctx,
  const QueryLoc& loc)
:
  expr(sctx, loc)
{}

extension_expr::extension_expr(
  short sctx,
  const QueryLoc& loc,
  expr_t _expr_h)
:
  expr(sctx, loc),
  expr_h(_expr_h)
{}


void extension_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (expr_h);
  END_EXPR_ITER ();
}


/*******************************************************************************

 [69] [http://www.w3.org/TR/xquery/#prod-xquery-RelativePathExpr]

  RelativPathExpr ::= "/" | ("/" | "//")?  StepExpr (("/" | "//") StepExpr)*

********************************************************************************/
relpath_expr::relpath_expr(short sctx, const QueryLoc& loc)
  :
  expr(sctx, loc)
{}

expr_iterator_data *relpath_expr::make_iter () { return new relpath_expr_iterator_data (this); }

void relpath_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER2 (relpath_expr);

  ITER_FOR_EACH (step_iter, begin (), end (), *vv.step_iter);

  END_EXPR_ITER();
}

/*******************************************************************************

  [71] [http://www.w3.org/TR/xquery/#prod-xquery-AxisStep]

  AxisStep ::= Axis NodeTest Predicate*

********************************************************************************/
axis_step_expr::axis_step_expr(short sctx, const QueryLoc& loc)
  :
  expr(sctx, loc)
{}

expr_iterator_data *axis_step_expr::make_iter () {
  return new axis_step_expr_iterator_data (this);
}

void axis_step_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();

  ITER (theNodeTest);

  END_EXPR_ITER();
}


bool axis_step_expr::is_reverse_axis(axis_kind_t k) 
{
  return (k == axis_kind_ancestor ||
          k == axis_kind_ancestor_or_self ||
          k == axis_kind_parent ||
          k == axis_kind_preceding ||
          k == axis_kind_preceding_sibling);
}


/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

  [79] NameTest ::= QName | Wildcard
  [80] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [123] KindTest ::= DocumentTest | ElementTest | AttributeTest |
                     SchemaElementTest | SchemaAttributeTest |
                     PITest | CommentTest | TextTest | AnyKindTest

********************************************************************************/
match_expr::match_expr(short sctx, const QueryLoc& loc)
  :
  expr(sctx, loc),
  theDocTestKind(match_no_test),
  theWildKind(match_no_wild),
  theQName(NULL),
  theTypeName(NULL),
  theNilledAllowed(false)
{
}


void match_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}


store::StoreConsts::NodeKind match_expr::getNodeKind() const
{
  switch (theTestKind)
  {
  case match_name_test:
    return store::StoreConsts::elementNode;
  case match_doc_test:
    return store::StoreConsts::documentNode;
  case match_elem_test:
    return store::StoreConsts::elementNode;
  case match_xs_elem_test:
    return store::StoreConsts::elementNode;
  case match_attr_test:
    return store::StoreConsts::attributeNode;
  case match_xs_attr_test:
    return store::StoreConsts::attributeNode;
  case match_pi_test:
    return store::StoreConsts::piNode;
  case match_text_test:
    return store::StoreConsts::textNode;
  case match_comment_test:
    return store::StoreConsts::commentNode;
  case match_anykind_test:
    return store::StoreConsts::anyNode;
  default:
    ZORBA_ASSERT (false && "Unknown node test kind");
  }
  return store::StoreConsts::anyNode;
}

// [84] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]


// [85] [http://www.w3.org/TR/xquery/#prod-xquery-PrimaryExpr]

const_expr::const_expr(short sctx, const QueryLoc& loc, xqpString v)
  :
  expr(sctx, loc)
{
  xqpStringStore_t tmp = v.getStore();
  GENV_ITEMFACTORY->createString(val, tmp); 
}

const_expr::const_expr(short sctx, const QueryLoc& loc, xqp_integer v)
  :
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createInteger(val, v);
}

const_expr::const_expr(
  short sctx,
  const QueryLoc& loc,
  xqp_decimal v)
:
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createDecimal(val, v);
}

const_expr::const_expr(
  short sctx,
  const QueryLoc& loc,
  xqp_double v)
:
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createDouble(val, v);
}

const_expr::const_expr(
  short sctx,
  const QueryLoc& loc,
  xqp_boolean v)
:
  expr(sctx, loc)
{
  GENV_ITEMFACTORY->createBoolean(val, v);
}

const_expr::const_expr(
    short sctx,
    const QueryLoc& loc,
    store::Item_t v)
  :
  expr(sctx, loc),
  val(v)
{
}

const_expr::const_expr(
    short sctx,
    const QueryLoc& aLoc, 
    const char* aNamespace,
    const char* aPrefix, 
    const char* aLocal)
  :
  expr(sctx, aLoc)
{
  GENV_ITEMFACTORY->createQName(val, aNamespace, aPrefix, aLocal);
}


void const_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}


// [91] [http://www.w3.org/TR/xquery/#prod-xquery-OrderedExpr]

order_expr::order_expr(
  short sctx,
  const QueryLoc& loc,
  order_type_t _type,
  expr_t _expr_h)
:
  expr(sctx, loc),
  type(_type),
  expr_h(_expr_h)
{}


void order_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (expr_h);
  END_EXPR_ITER ();
}


expr_t order_expr::clone(substitution_t& subst) {
  return new order_expr (theSctxId, get_loc (), get_type (), get_expr ()->clone (subst));
}


// [93] [http://www.w3.org/TR/xquery/#prod-xquery-FunctionCall]

// [96] [http://www.w3.org/TR/xquery/#doc-exquery-DirElemConstructor]
elem_expr::elem_expr (
    short sctx,
    const QueryLoc& aLoc,
    expr_t aQNameExpr,
    expr_t aAttrs,
    expr_t aContent,
    rchandle<namespace_context> aNSCtx)
    :
    constructor_expr ( sctx, aLoc ),
    theQNameExpr ( aQNameExpr ),
    theAttrs ( aAttrs ),
    theContent ( aContent ),
    theNSCtx(aNSCtx)
{}

elem_expr::elem_expr (
    short sctx,
    const QueryLoc& aLoc,
    expr_t aQNameExpr,
    expr_t aContent,
    rchandle<namespace_context> aNSCtx)
    :
    constructor_expr ( sctx, aLoc ),
    theQNameExpr ( aQNameExpr ),
    theAttrs ( 0 ),
    theContent ( aContent ),
    theNSCtx(aNSCtx)
{}
  

rchandle<namespace_context> elem_expr::getNSCtx() { return theNSCtx; }

void elem_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER (theQNameExpr);
  ITER (theAttrs);
  ITER (theContent);
  END_EXPR_ITER();
}

expr_t elem_expr::clone(substitution_t& subst) {
  return new elem_expr (theSctxId, get_loc (),
                        CLONE (getQNameExpr (), subst),
                        CLONE (getAttrs (), subst),
                        CLONE (getContent (), subst),
                        getNSCtx ());
}


// [110] [http://www.w3.org/TR/xquery/#prod-xquery-CompDocConstructor]

doc_expr::doc_expr(
  short sctx,
  const QueryLoc& loc,
  expr_t aContent)
:
  constructor_expr(sctx, loc),
  theContent(aContent)
{}


void doc_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER(theContent);
  END_EXPR_ITER();
}

expr_t doc_expr::clone(substitution_t& subst) {
  return new doc_expr (theSctxId, get_loc (), CLONE (getContent (), subst));
}


// [111] [http://www.w3.org/TR/xquery/#prod-xquery-CompElemConstructor]


// [113] [http://www.w3.org/TR/xquery/#prod-xquery-CompAttrConstructor]

attr_expr::attr_expr(
  short sctx,
  const QueryLoc& loc,
  expr_t aQNameExpr,
  expr_t aValueExpr)
:
  constructor_expr(sctx, loc),
  theQNameExpr(aQNameExpr),
  theValueExpr(aValueExpr)
{}


store::Item* attr_expr::getQName() const
{
  const_expr* qnExpr =  dynamic_cast<const_expr*>(theQNameExpr.getp());
  if (qnExpr != 0)
    return qnExpr->get_val().getp();

  return 0;
}


void attr_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER (theQNameExpr);
  ITER (theValueExpr);
  END_EXPR_ITER();
}

expr_t attr_expr::clone(substitution_t& subst) {
  return new attr_expr (theSctxId, get_loc (),
                        CLONE (getQNameExpr (), subst), CLONE (getValueExpr (), subst));
}

// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompTextConstructor]

text_expr::text_expr(
  short sctx,
  const QueryLoc& loc,
  text_constructor_type type_arg,
  expr_t text_arg)
:
  constructor_expr(sctx, loc),
  type (type_arg),
  text(text_arg)
{}


void text_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER();
  ITER (text);
  END_EXPR_ITER();
}

expr_t text_expr::clone(substitution_t& subst) {
  return new text_expr (theSctxId, get_loc (), get_type (), CLONE (get_text (), subst));
}

// [115] [http://www.w3.org/TR/xquery/#prod-xquery-CompCommentConstructor]


// [114] [http://www.w3.org/TR/xquery/#prod-xquery-CompPIConstructor]

pi_expr::pi_expr(
  short sctx,
  const QueryLoc& loc,
  expr_t _target_expr_h,
  expr_t _content_expr_h)
:
  text_expr(sctx, loc, text_expr::pi_constructor, _content_expr_h),
  target_expr_h(_target_expr_h)
{}


void pi_expr::next_iter (expr_iterator_data& v) {
  BEGIN_EXPR_ITER ();
  ITER (target_expr_h);
  ITER (text);
  END_EXPR_ITER ();
}


void function_def_expr::next_iter (expr_iterator_data& v) {}

expr_t pi_expr::clone(substitution_t& subst) {
  return new pi_expr (theSctxId, get_loc (),
                      CLONE (get_target_expr (), subst), CLONE (get_text (), subst));
}


void function_def_expr::serialize(::zorba::serialization::Archiver &ar)
{
  serialize_baseclass(ar, (expr*)this);
  ar & name;
  ar & params;
  ar & body;
  if(ar.is_serializing_out())
  {
    signature *psig = sig.get();
    ar & psig;
  }
  else
  {
    signature *psig;
    ar & psig;
    sig = auto_ptr<signature>(psig);
  }
}

function_def_expr::function_def_expr (short sctx,
                                      const QueryLoc& loc,
                                      store::Item_t name_,
                                      std::vector<rchandle<var_expr> > &params_,
                                      xqtref_t return_type_impl)
  : expr (sctx, loc), name (name_)
{
  assert (return_type_impl != NULL);
  params.swap (params_);
  vector<xqtref_t> args;
  // TODO: copy param types into sig
  for (unsigned i = 0; i < param_size (); i++)
    args.push_back (GENV_TYPESYSTEM.ITEM_TYPE_STAR);
  sig = auto_ptr<signature> (new signature (get_name (), args, GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}

// [242] [http://www.w3.org/TR/xqupdate/#prod-xquery-InsertExpr]

insert_expr::insert_expr(
  short sctx,
	const QueryLoc& loc,
  store::UpdateConsts::InsertType aType,
	expr_t aSourceExpr,
	expr_t aTargetExpr)
:
	expr(sctx, loc),
  theType(aType),
	theSourceExpr(aSourceExpr),
	theTargetExpr(aTargetExpr)
{}

void insert_expr::compute_upd_seq_kind () const 
{
  theCache.upd_seq_kind.kind = UPDATE_EXPR;
  theCache.upd_seq_kind.valid = true;
}

void 
insert_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theSourceExpr);
  ITER(theTargetExpr);
  END_EXPR_ITER(); 
}

expr_t insert_expr::clone (substitution_t& subst) {
  return new insert_expr (theSctxId, get_loc (), getType (), getSourceExpr ()->clone (subst), getTargetExpr ()->clone (subst));
}

// [243] [http://www.w3.org/TR/xqupdate/#prod-xquery-DeleteExpr]

delete_expr::delete_expr(
  short sctx,
	const QueryLoc& loc,
	expr_t aTargetExpr)
:
	expr(sctx, loc),
	theTargetExpr(aTargetExpr)
{}


void delete_expr::compute_upd_seq_kind () const 
{
  theCache.upd_seq_kind.kind = UPDATE_EXPR;
  theCache.upd_seq_kind.valid = true;
}

void delete_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  END_EXPR_ITER(); 
}

expr_t delete_expr::clone (substitution_t& subst) {
  return new delete_expr (theSctxId, get_loc (), getTargetExpr ()->clone (subst));
}


// [244] [http://www.w3.org/TR/xqupdate/#prod-xquery-ReplaceExpr]

replace_expr::replace_expr(
  short sctx,
	const QueryLoc& loc,
  store::UpdateConsts::ReplaceType aType,
	expr_t aTargetExpr,
	expr_t aReplaceExpr)
:
	expr(sctx, loc),
  theType(aType),
	theTargetExpr(aTargetExpr),
	theReplaceExpr(aReplaceExpr)
{}

void replace_expr::compute_upd_seq_kind () const {
  theCache.upd_seq_kind.kind = UPDATE_EXPR;
  theCache.upd_seq_kind.valid = true;
}

void replace_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  ITER(theReplaceExpr);
  END_EXPR_ITER();
}

expr_t replace_expr::clone (substitution_t& subst) {
  return new replace_expr (theSctxId, get_loc (), getType (), getTargetExpr ()->clone (subst), getReplaceExpr ()->clone (subst));
}

// [245] [http://www.w3.org/TR/xqupdate/#prod-xquery-RenameExpr]

rename_expr::rename_expr(
  short sctx,
	const QueryLoc& loc,
	expr_t aTargetExpr,
	expr_t aNameExpr)
:
	expr(sctx, loc),
	theTargetExpr(aTargetExpr),
	theNameExpr(aNameExpr)
{}

void rename_expr::compute_upd_seq_kind () const 
{
  theCache.upd_seq_kind.kind = UPDATE_EXPR;
  theCache.upd_seq_kind.valid = true;
}

void rename_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(theTargetExpr);
  ITER(theNameExpr);
  END_EXPR_ITER();
}

expr_t rename_expr::clone (substitution_t& subst) 
{
  return new rename_expr (theSctxId, get_loc (), getTargetExpr ()->clone (subst), getNameExpr ()->clone (subst));
}


copy_clause::copy_clause(rchandle<var_expr> aVar, expr_t aExpr)
  :
  theVar(aVar),
  theExpr(aExpr)
{
  theVar->set_copy_clause(this);
}


transform_expr::transform_expr(
    short sctx,
	  const QueryLoc& loc,
    expr_t aModifyExpr,
    expr_t aReturnExpr)
  :
	expr(sctx, loc),
	theModifyExpr(aModifyExpr),
	theReturnExpr(aReturnExpr)
{
}

expr_iterator_data *transform_expr::make_iter () { return new transform_expr_iterator_data(this); }

void transform_expr::next_iter(expr_iterator_data& v)
{
  BEGIN_EXPR_ITER2 (transform_expr);
  ITER_FOR_EACH(clause_iter, theCopyClauses.begin(), theCopyClauses.end(),
                (*vv.clause_iter)->theExpr);
  ITER(theModifyExpr);
  ITER(theReturnExpr);
  END_EXPR_ITER();
} 

void exit_expr::next_iter (expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER(val);
  END_EXPR_ITER();
}

expr_t exit_expr::clone (substitution_t& subst) {
  return new exit_expr (theSctxId, get_loc (), get_value ()->clone (subst));
}

void flowctl_expr::next_iter (expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  END_EXPR_ITER();
}

expr_t flowctl_expr::clone (substitution_t& subst) {
  return new flowctl_expr (theSctxId, get_loc (), get_action ());
}

void while_expr::next_iter (expr_iterator_data& v)
{
  BEGIN_EXPR_ITER();
  ITER (body);
  END_EXPR_ITER();
}

expr_t while_expr::clone (substitution_t& subst) {
  return new while_expr (theSctxId, get_loc (), get_body ()->clone (subst));
}

expr_t const_expr::clone (substitution_t&) {
  return new const_expr (theSctxId, get_loc (), get_val ());
}



expr_t match_expr::clone (substitution_t& subst) {
  match_expr *me = new match_expr (theSctxId, get_loc ());
  me->setTestKind (getTestKind ());
  me->setDocTestKind (getDocTestKind ());
  me->setWildName (getWildName ());
  me->setWildKind (getWildKind ());
  me->setQName (getQName ());
  me->setTypeName (getTypeName ());
  me->setNilledAllowed (getNilledAllowed ());
  return me;
}

expr_t axis_step_expr::clone (substitution_t& subst) {
  axis_step_expr *ae = new axis_step_expr (theSctxId, get_loc ());
  ae->setAxis (getAxis ());
  ae->setTest (getTest ());
  return ae;
}

expr_t relpath_expr::clone (substitution_t& subst) {
  auto_ptr<relpath_expr> re (new relpath_expr (theSctxId, get_loc ()));
  for (unsigned i = 0; i < size (); i++)
    re->add_back ((*this) [i]->clone (subst));
  return re.release ();
}



} /* namespace zorba */
/* vim:set ts=2 sw=2: */
