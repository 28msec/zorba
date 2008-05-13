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

#include <iostream>
#include <vector>
#include <stack>

#include "util/properties.h"
#include "context/static_context_consts.h"

#include "compiler/codegen/plan_visitor.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/parser/parse_constants.h"

#include "system/globalenv.h"
#include "util/Assert.h"

#include "context/namespace_context.h"
#include "context/static_context.h"

#include "runtime/sequences/SequencesImpl.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/constructors.h"
#include "runtime/core/path_iterators.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/trycatch.h"
#include "runtime/fncontext/FnContextImpl.h"
#include "runtime/misc/MiscImpl.h"
#include "runtime/update/update.h"
#include "runtime/visitors/printervisitor.h"
#include "runtime/visitors/iterprinter.h"

#include "functions/function.h"

#include "util/tracer.h"
#include "util/stl_extra.h"
#include "util/hashmap.h"

#ifdef ZORBA_DEBUGGER
#include <zorba/debugger_server.hpp>
#include "runtime/debug/zorba_debugger_iterators.hpp"
#endif

#include "types/typeops.h"

#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"


#ifndef NDEBUG
#define CODEGEN_TRACE(msg)                      \
  if (Properties::instance()->traceCodegen())   \
    cout << (msg) << TRACE << endl;
#define CODEGEN_TRACE_IN( msg )  \
  CODEGEN_TRACE (string (++depth, ' ') + msg)
#define CODEGEN_TRACE_OUT( msg ) \
  CODEGEN_TRACE (string (depth--, ' ') + msg)
#else
#define CODEGEN_TRACE(msg)
#define CODEGEN_TRACE_IN(msg)
#define CODEGEN_TRACE_OUT(msg)
#endif

#define DOT_VAR "$$dot"
#define DOT_POS_VAR "$$pos"
#define LAST_IDX_VAR "$$last-idx"

using namespace std;
namespace zorba 
{

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

template <typename T> T pop_stack (stack<T> &stk) {
    assert (! stk.empty ());
    T x = stk.top ();
    stk.pop ();
    return x;
  }


template<class T> T &peek_stack (stack<T> &stk) {
    ZORBA_ASSERT (! stk.empty ());
    return stk.top ();
  }


template <typename V>
struct vector_destroyer {
    void operator()(const struct hash64map<vector<V> *>::entry& entry)
    {
        delete (const_cast<struct hash64map<vector<V> *>::entry&>(entry)).val;
    }
};


/*******************************************************************************

********************************************************************************/
class plan_visitor : public expr_visitor
{
public:

  typedef rchandle<expr> expr_h_t;
  typedef rchandle<ForVarIterator> ForVarIter_t;
  typedef rchandle<LetVarIterator> LetVarIter_t;

protected:
  uint32_t depth;
  
  stack<PlanIter_t>                      itstack;

  stack<expr*>                           theConstructorsStack;
  stack<bool>                            theAttrContentStack;

  namespace_context                    * theLastNSCtx;
  stack<namespace_context *>             theNSCtxStack;
  stack<namespace_context::bindings_t>   theFlatBindingsStack;

  hash64map<vector<ForVarIter_t> *>      fvar_iter_map;
  hash64map<vector<ForVarIter_t> *>      pvar_iter_map;
  hash64map<vector<LetVarIter_t> *>      lvar_iter_map;
  hash64map<vector<LetVarIter_t> *>    * param_var_iter_map;
  hash64map<vector<LetVarIter_t> *>      catchvar_iter_map;
  hash64map<vector<ForVarIter_t> *>      copy_var_iter_map;
  hash64map<vector<ForVarIter_t> *>      group_var_iter_map;
  hash64map<vector<LetVarIter_t> *>      non_group_var_iter_map;

  CompilerCB                           * ccb;

#define LOOKUP_OP1( local ) static_cast<function *> (ccb->m_sctx->lookup_builtin_fn (":" local, 1))

public:

#ifdef ZORBA_DEBUGGER
          PlanIter_t debugIterator(PlanIter_t aStoppableIterator){
            if ( ZorbaDebugger::getInstance()->isEnabled() )
            {
              std::vector<PlanIter_t> lChildren;
              lChildren.push_back(aStoppableIterator);
              return new FnDebugIterator(aStoppableIterator->loc, lChildren);
            }
            return aStoppableIterator;
          }
#endif

	plan_visitor(CompilerCB *ccb_, hash64map<vector<LetVarIter_t> *> *param_var_map = NULL)
    :
    depth (0),
    theLastNSCtx(NULL), 
    param_var_iter_map(param_var_map),
    ccb (ccb_)
  {
  }

	~plan_visitor()
  {
    for_each(fvar_iter_map.begin(), fvar_iter_map.end(), vector_destroyer<ForVarIter_t>());
    for_each(pvar_iter_map.begin(), pvar_iter_map.end(), vector_destroyer<ForVarIter_t>());
    for_each(lvar_iter_map.begin(), lvar_iter_map.end(), vector_destroyer<LetVarIter_t>());
    for_each(catchvar_iter_map.begin(), catchvar_iter_map.end(), vector_destroyer<LetVarIter_t>());
    for_each(copy_var_iter_map.begin(), copy_var_iter_map.end(), vector_destroyer<ForVarIter_t>());
    for_each(group_var_iter_map.begin(), group_var_iter_map.end(), vector_destroyer<ForVarIter_t>());
    for_each(non_group_var_iter_map.begin(), non_group_var_iter_map.end(), vector_destroyer<LetVarIter_t>());
  }

public:
	PlanIter_t pop_itstack()
	{
    return pop_stack (itstack);
	}

  bool is_enclosed_expr(expr* e)
  {
    fo_expr* foe = dynamic_cast<fo_expr*>(e);
    if (foe != NULL &&
        foe->get_fname()->getLocalName()->byteEqual(":enclosed-expr", 14))
      return true;

    return false;
  }


bool begin_visit(expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}

bool begin_visit(sequential_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(sequential_expr& v)
{
  CODEGEN_TRACE_OUT("");
  checked_vector<PlanIter_t> argv;
  for (unsigned i = 0; i < v.size (); i++)
    argv.push_back (pop_itstack ());
  reverse (argv.begin (), argv.end ());
  itstack.push (new SequentialIterator (v.get_loc (), argv));
}

bool begin_visit(var_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(var_expr& v)
{
  CODEGEN_TRACE_OUT("");
  const QueryLoc &loc = v.get_loc ();

  switch (v.kind) 
  {

  case var_expr::for_var: {
    vector<ForVarIter_t> *map = NULL;
    bool bound = fvar_iter_map.get ((uint64_t) &v, map);
    
    ZORBA_ASSERT (bound);
    ForVarIterator *v_p = new ForVarIterator(v.get_varname()->getLocalName(),
            loc,
            (void *) &v);
    map->push_back (v_p);
#ifdef ZORBA_DEBUGGER
                  itstack.push(debugIterator(v_p));
#else
                  itstack.push(v_p);
#endif
    break;
  }

  case var_expr::pos_var: {
    vector<ForVarIter_t> *map = NULL;
    bool bound = pvar_iter_map.get ((uint64_t) &v, map);

    ZORBA_ASSERT (bound);
    ForVarIterator *v_p = new ForVarIterator(v.get_varname ()->getLocalName(),
            loc,
            (void *) &v);
    map->push_back (v_p);
    itstack.push(v_p);
    break;
  }

  case var_expr::let_var: {
    vector<LetVarIter_t> *map = NULL;
    bool bound = lvar_iter_map.get ((uint64_t) &v, map);
      
    ZORBA_ASSERT (bound);
    LetVarIterator *v_p = new LetVarIterator(v.get_varname()->getLocalName(),
            loc,
            (void *) &v);
    map->push_back (v_p);
    itstack.push(v_p);
    break;
  }

  case var_expr::param_var: {
    vector<LetVarIter_t> *map = NULL;    
    ZORBA_ASSERT (param_var_iter_map->get ((uint64_t) &v, map));
    LetVarIterator *v_p = new LetVarIterator(v.get_varname()->getLocalName(),
                                             loc,
                                             (void *) &v);
    
    map->push_back (v_p);
    itstack.push(v_p);
    break;
  }

  case var_expr::context_var: {
    xqpString varname = v.get_varname()->getStringValue().getp();
    if (varname == DOT_VAR) {
      vector<PlanIter_t> ctx_args;
      ctx_args.push_back (new SingletonIterator (loc, ITEM_FACTORY->createQName ("", "", ".")));
      itstack.push (new CtxVariableIterator (loc, ctx_args));
    } else if (varname == DOT_POS_VAR) {
      itstack.push (new SingletonIterator (
        loc, ITEM_FACTORY->createInteger (Integer::parseInt((int32_t)1))
      ));
    } else if (varname == LAST_IDX_VAR) {
      itstack.push (new SingletonIterator (
        loc, ITEM_FACTORY->createInteger (Integer::parseInt((int32_t)1))
      ));
    } else {
      expr_t lookup_expr = new fo_expr (v.get_loc (), LOOKUP_OP1 ("ctxvariable"), new const_expr (v.get_loc (), v.get_varname ()));
      lookup_expr->accept (*this);
    }
 
    break;
  }

  case var_expr::catch_var:
  {
    vector<LetVarIter_t> *map = NULL;
    bool bound = catchvar_iter_map.get ((uint64_t) &v, map);
      
    ZORBA_ASSERT (bound);
    LetVarIterator *v_p = new LetVarIterator(v.get_varname()->getLocalName(),
            loc,
            (void *) &v);
    map->push_back (v_p);
    itstack.push(v_p);
  }
  break;
  case var_expr::copy_var:
  {
    vector<ForVarIter_t> *map = NULL;
    uint64_t k = (uint64_t) &v;
    bool bound = copy_var_iter_map.get (k, map);
      
    ZORBA_ASSERT (bound);
    ForVarIterator* v_p = new ForVarIterator(v.get_varname()->getLocalName(),
                                             loc,
                                             (void *) &v);
    map->push_back (v_p);
    itstack.push(v_p);
  }
  break;
  case var_expr::groupby_var:
  {
    vector<ForVarIter_t> *map = NULL;
    uint64_t k = (uint64_t) &v;
    bool bound = group_var_iter_map.get (k, map);
      
    ZORBA_ASSERT (bound);
    ForVarIterator *v_p = new ForVarIterator(v.get_varname()->getLocalName(),
            loc,
            (void *) &v);
    map->push_back (v_p);
    itstack.push(v_p);
  }
  break;
  case var_expr::non_groupby_var:
  {
    vector<LetVarIter_t> *map = NULL;
    uint64_t k = (uint64_t) &v;
    bool bound = non_group_var_iter_map.get (k, map);
      
    ZORBA_ASSERT (bound);
    LetVarIterator *v_p = new LetVarIterator(v.get_varname()->getLocalName(),
            loc,
            (void *) &v);
    map->push_back (v_p);
    itstack.push(v_p);
  }
  break;
  case var_expr::unknown_var:
    assert (false);
    break;
  default:
    assert (false);
    break;
  }
}

bool begin_visit(order_modifier& /*v*/)
{
  CODEGEN_TRACE_IN("");
  // not implemented, but this is a performance, not a conformance issue
  return true;
}

void end_visit(order_modifier& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}

bool begin_visit(flwor_expr& v)
{
  CODEGEN_TRACE_IN("");
  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it) 
  {
    rchandle<var_expr> var = (*it)->var_h;
    uint64_t k = (uint64_t) &*var;

    if (var->kind == var_expr::for_var)
    {
      fvar_iter_map.put(k, new vector<ForVarIter_t>());
      var_expr* pos_var = (*it)->get_pos_var().getp();
      if (pos_var != NULL)
        pvar_iter_map.put((uint64_t)pos_var, new vector<ForVarIter_t>());
    }
    else if (var->kind == var_expr::let_var)
    {
      lvar_iter_map.put(k, new vector<LetVarIter_t>());
    }
    else
      ZORBA_ASSERT (false);
  }
  
  for(flwor_expr::group_list_t::const_iterator it = v.group_begin();
      it != v.group_end();
      ++it)
  {
    rchandle<var_expr> var = (*it)->getInnerVar();
    uint64_t k = (uint64_t) &*var;
    group_var_iter_map.put(k, new vector<ForVarIter_t>());
  }

  for(flwor_expr::group_list_t::const_iterator it = v.non_group_begin();
      it != v.non_group_end();
      ++it)
  {
    rchandle<var_expr> var = (*it)->getInnerVar();
    uint64_t k = (uint64_t) &*var;
    non_group_var_iter_map.put(k, new vector<LetVarIter_t>());
  }

  return true;
}



void end_visit(flwor_expr& v)
{
  CODEGEN_TRACE_OUT("");

  PlanIter_t ret = pop_itstack ();

  vector<FLWORIterator::OrderSpec> orderSpecs;
  for (flwor_expr::orderspec_list_t::reverse_iterator i = v.orderspec_rbegin ();
       i != v.orderspec_rend ();
       i++) 
  {
    flwor_expr::orderspec_t spec = *i;
    orderSpecs.push_back(FLWORIterator::OrderSpec(pop_itstack(),
                         spec.second->empty_mode == StaticContextConsts::empty_least,
                         spec.second->dir == ParseConstants::dir_descending, spec.second->collation));
  }
  reverse (orderSpecs.begin (), orderSpecs.end ());

  auto_ptr<FLWORIterator::OrderByClause> orderby(orderSpecs.empty() ? NULL : new FLWORIterator::OrderByClause(orderSpecs, v.get_order_stable ()));
  
  PlanIter_t group_where = 0;
  if (v.get_group_where() != 0)
    group_where = pop_itstack();
  
  vector<FLWORIterator::GroupingOuterVar> nonGroupBys;
  for(flwor_expr::group_list_t::reverse_iterator i = v.non_group_rbegin();
      i != v.non_group_rend();
      ++i)
  {
    rchandle<group_clause> group = *i;
    vector<LetVarIter_t>* lInnerVars = 0;
    var_expr* lVar = group->getInnerVar();
    ZORBA_ASSERT(non_group_var_iter_map.get((uint64_t)lVar, lInnerVars));

    PlanIter_t lInput = pop_itstack();

    nonGroupBys.push_back(FLWORIterator::GroupingOuterVar(lInput, *lInnerVars));
  }

  vector<FLWORIterator::GroupingSpec> groupBys;
  for(flwor_expr::group_list_t::reverse_iterator i = v.group_rbegin();
      i != v.group_rend();
      ++i)
  {
    rchandle<group_clause> group = *i;
    vector<ForVarIter_t>* lInnerVars = 0;
    var_expr* lVar = group->getInnerVar();
    ZORBA_ASSERT(group_var_iter_map.get((uint64_t)lVar, lInnerVars));

    PlanIter_t lInput = pop_itstack();

    xqp_string lCollation = group->getCollation();
    
    groupBys.push_back(FLWORIterator::GroupingSpec(lInput, *lInnerVars, lCollation));
  }
  
  auto_ptr<FLWORIterator::GroupByClause> groupby(
    groupBys.empty() 
  ? NULL 
  : new FLWORIterator::GroupByClause(groupBys, nonGroupBys, group_where));

  PlanIter_t where = NULL;
  if (v.get_where () != NULL)
  {
    where = pop_itstack ();
  }

  vector<FLWORIterator::ForLetClause> clauses;
  stack<PlanIter_t> inputs;
  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it)
  {
    inputs.push(pop_itstack());
  }

  for (vector<rchandle<forlet_clause> >::const_iterator it = v.clause_begin ();
       it != v.clause_end();
       ++it) 
  {
    PlanIter_t input = pop_stack(inputs);

    if ((*it)->type == forlet_clause::for_clause)
    {
      vector<ForVarIter_t> *var_iters = NULL, *pvar_iters = NULL;
      var_expr* var = (*it)->var_h.getp();
      var_expr* pos_var = (*it)->get_pos_var().getp();
      ZORBA_ASSERT( fvar_iter_map.get((uint64_t)var, var_iters) );
      if (pos_var == NULL)
      {
        clauses.push_back(FLWORIterator::ForLetClause(var, *var_iters, input));
      }
      else 
      {
        ZORBA_ASSERT( pvar_iter_map.get((uint64_t) pos_var, pvar_iters) );
        clauses.push_back(FLWORIterator::ForLetClause(var, *var_iters, *pvar_iters, input));
      }
    }
    else if ((*it)->type == forlet_clause::let_clause)
    {
      vector<LetVarIter_t> *var_iters = NULL;
      var_expr* var = (*it)->var_h;
      ZORBA_ASSERT( lvar_iter_map.get((uint64_t)var, var_iters) );
      clauses.push_back(FLWORIterator::ForLetClause(var, *var_iters, input, true));
    }
  }

  FLWORIterator *iter = new FLWORIterator(
      v.get_loc(), clauses, where, groupby.release(), 
      orderby.release(), ret, v.isUpdating());
  itstack.push(iter);
}


bool begin_visit(case_clause& /*v*/)
{
  CODEGEN_TRACE_IN("");
  // TODO: Not implemented
  return true;
}


void end_visit(case_clause& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}

bool begin_visit(promote_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(promote_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  // TODO: Currently we use cast. Promotion may be more efficient.
  itstack.push(new PromoteIterator(v.get_loc(), lChild, v.get_target_type()));
}

bool begin_visit(trycatch_expr& v)
{
  CODEGEN_TRACE_IN("");
  for(int i = v.clause_count() - 1; i >= 0; --i) {
    catch_clause *cc = &*v[i];
    if (cc->get_errorcode_var_h() != NULL) {
      catchvar_iter_map.put((uint64_t)&*cc->get_errorcode_var_h(), new vector<LetVarIter_t>());
    }
    if (cc->get_errordesc_var_h() != NULL) {
      catchvar_iter_map.put((uint64_t)&*cc->get_errordesc_var_h(), new vector<LetVarIter_t>());
    }
    if (cc->get_errorobj_var_h() != NULL) {
      catchvar_iter_map.put((uint64_t)&*cc->get_errorobj_var_h(), new vector<LetVarIter_t>());
    }
  }
  return true;
}

void end_visit(trycatch_expr& v)
{
  CODEGEN_TRACE_OUT("");
  std::vector<LetVarIter_t> *vec = NULL;
  std::vector<TryCatchIterator::CatchClause> rev_ccs;
  for(int i = v.clause_count() - 1; i >= 0; --i) {
    catch_clause *cc = &*v[i];
    TryCatchIterator::CatchClause rcc;
    rcc.node_name = cc->get_nametest_h();
    rcc.catch_expr = pop_itstack();
    if (cc->get_errorcode_var_h() != NULL) {
      bool bound = catchvar_iter_map.get((uint64_t)&*cc->get_errorcode_var_h(), vec);
      ZORBA_ASSERT(bound);
      rcc.errorcode_var = *vec;
    }
    if (cc->get_errordesc_var_h() != NULL) {
      bool bound = catchvar_iter_map.get((uint64_t)&*cc->get_errordesc_var_h(), vec);
      ZORBA_ASSERT(bound);
      rcc.errordesc_var = *vec;
    }
    if (cc->get_errorobj_var_h() != NULL) {
      bool bound = catchvar_iter_map.get((uint64_t)&*cc->get_errorobj_var_h(), vec);
      ZORBA_ASSERT(bound);
      rcc.errorobj_var = *vec;
    }
    rev_ccs.push_back(rcc);
  }
  std::vector<TryCatchIterator::CatchClause> ccs(rev_ccs.rbegin(), rev_ccs.rend());
  PlanIter_t lChild = pop_itstack();
  itstack.push(new TryCatchIterator(v.get_loc(), lChild, ccs));
}

bool begin_visit (eval_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (eval_expr& v) {
  CODEGEN_TRACE_OUT("");
  checked_vector<PlanIter_t> argv;
  checked_vector<store::Item_t> varnames;
  checked_vector<xqtref_t> vartypes;
  for (unsigned i = 0; i < v.var_count (); i++) {
    varnames.push_back (v.var_at (i).varname);
    argv.push_back (pop_itstack ());
  }
  argv.push_back (pop_itstack ());
  reverse (argv.begin (), argv.end ());
  itstack.push (new EvalIterator (v.get_loc (), varnames, vartypes, argv));
}

bool begin_visit(typeswitch_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  ZORBA_NOT_IMPLEMENTED ("typeswitch codegen");
  return true;
}

void end_visit(typeswitch_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}


bool begin_visit(if_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(if_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t iterElse = pop_itstack();
  PlanIter_t iterThen = pop_itstack();
  PlanIter_t iterCond = pop_itstack();
  PlanIter_t iterIfThenElse = new IfThenElseIterator(
    v.get_loc(), iterCond, iterThen, iterElse, v.isUpdating());
  itstack.push(&*iterIfThenElse);
}


bool begin_visit(insert_expr& v)
{
  CODEGEN_TRACE_IN("");

  expr_t targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(ccb->m_sctx);

  if (v.getType() == store::UpdateConsts::AFTER ||
      v.getType() == store::UpdateConsts::BEFORE)
  {
    if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.UNTYPED_TYPE) ||
        TypeOps::is_subtype(*GENV_TYPESYSTEM.ELEMENT_TYPE_ONE, *targetType) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ELEMENT_TYPE_ONE) ||
        TypeOps::is_subtype(*GENV_TYPESYSTEM.TEXT_TYPE_ONE, *targetType) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.TEXT_TYPE_ONE) ||
        TypeOps::is_subtype(*GENV_TYPESYSTEM.PI_TYPE_ONE, *targetType) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.PI_TYPE_ONE) ||
        TypeOps::is_subtype(*GENV_TYPESYSTEM.COMMENT_TYPE_ONE, *targetType) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.COMMENT_TYPE_ONE))
      return true;

    if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.EMPTY_TYPE))
      ZORBA_ERROR_LOC(XUDY0027, v.get_loc());
    else
      ZORBA_ERROR_LOC(XUTY0006, v.get_loc());
  }
  else
  {
    if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.UNTYPED_TYPE) ||
        TypeOps::is_subtype(*GENV_TYPESYSTEM.ELEMENT_TYPE_ONE, *targetType) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ELEMENT_TYPE_ONE) ||
        TypeOps::is_subtype(*GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE, *targetType) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE))
      return true;

    if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.EMPTY_TYPE))
      ZORBA_ERROR_LOC(XUDY0027, v.get_loc());
    else
      ZORBA_ERROR_LOC(XUTY0005, v.get_loc());
  }

  return true;
}

void end_visit(insert_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lSource = pop_itstack();
  PlanIter_t lInsert = new InsertIterator(v.get_loc(), v.getType(), lSource, lTarget); 
  itstack.push(&*lInsert);
}

bool begin_visit(delete_expr& v)
{
  CODEGEN_TRACE_IN("");

  expr_t targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(ccb->m_sctx);

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.UNTYPED_TYPE) ||
      TypeOps::is_subtype(*GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR))
    return true;

  ZORBA_ERROR_LOC(XUTY0007, v.get_loc());

  return true;
}

void end_visit(delete_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lDelete = new DeleteIterator(v.get_loc(), lTarget);
  itstack.push(&*lDelete);
}

bool begin_visit(replace_expr& v)
{
  CODEGEN_TRACE_IN("");

  expr_t targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(ccb->m_sctx);

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.UNTYPED_TYPE) ||
      TypeOps::is_subtype(*GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE))
    return true;

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.EMPTY_TYPE))
    ZORBA_ERROR_LOC(XUDY0027, v.get_loc());
  else
    ZORBA_ERROR_LOC(XUTY0008, v.get_loc());

  return true;
}

void end_visit(replace_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lReplacement = pop_itstack();
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lReplace = new ReplaceIterator(v.get_loc(),
                                            v.getType(),
                                            lTarget,
                                            lReplacement);
  itstack.push(&*lReplace);
}

bool begin_visit(rename_expr& v)
{
  CODEGEN_TRACE_IN("");

  expr_t targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(ccb->m_sctx);

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.UNTYPED_TYPE) ||
      TypeOps::is_subtype(*GENV_TYPESYSTEM.ELEMENT_TYPE_ONE, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ELEMENT_TYPE_ONE) ||
      TypeOps::is_subtype(*GENV_TYPESYSTEM.ATTRIBUTE_TYPE_ONE, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ATTRIBUTE_TYPE_ONE) ||
      TypeOps::is_subtype(*GENV_TYPESYSTEM.PI_TYPE_ONE, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.PI_TYPE_ONE))
    return true;

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.EMPTY_TYPE))
    ZORBA_ERROR_LOC(XUDY0027, v.get_loc());
  else
    ZORBA_ERROR_LOC(XUTY0012, v.get_loc());

  return true;
}

void end_visit(rename_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lName = pop_itstack();
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lRename = new RenameIterator(v.get_loc(), lTarget, lName);
  itstack.push(&*lRename);
}

bool begin_visit(transform_expr& v)
{
  CODEGEN_TRACE_IN("");

  vector<rchandle<copy_clause> >::const_iterator lIter = v.begin();
  vector<rchandle<copy_clause> >::const_iterator lEnd  = v.end();
  for (; lIter != lEnd; ++lIter)
  {
    rchandle<var_expr> var = (*lIter)->getVar();
    uint64_t k = (uint64_t) &*var;
    copy_var_iter_map.put(k, new vector<ForVarIter_t>());
  }
  return true;
}

void end_visit(transform_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lReturn = pop_itstack();
  PlanIter_t lModify = pop_itstack();

  vector<CopyClause> lClauses;
  stack<PlanIter_t> lInputs;
  size_t lSize = v.size();
  for (size_t i = 0; i < lSize; ++i)
  {
    lInputs.push(pop_itstack());  
  }

  vector<rchandle<copy_clause> >::const_iterator lIter = v.begin();
  vector<rchandle<copy_clause> >::const_iterator lEnd  = v.end();
  for(;lIter!=lEnd;++lIter)
  {
    PlanIter_t lInput = pop_stack(lInputs);
    vector<ForVarIter_t>* lVarIters = 0;
    var_expr* lVar = (*lIter)->getVar();
    ZORBA_ASSERT(copy_var_iter_map.get((uint64_t)lVar, lVarIters));
    lClauses.push_back(CopyClause (*lVarIters, lInput));
  }

  TransformIterator* lTransform = new TransformIterator(v.get_loc(), lClauses, lModify, lReturn); 
  itstack.push(lTransform);
}


bool begin_visit(fo_expr& v)
{
  CODEGEN_TRACE_IN ("");

  // If the function is an enclosed expression, push it in the constructors
  // stack to "hide" the current constructor context, if any. This way, a new
  // constructor context can be started if a node constructor exists inside
  // the enclosed expr.
  if (is_enclosed_expr(&v))
    theConstructorsStack.push(&v);

	return true;
}


void end_visit(fo_expr& v) 
{
  CODEGEN_TRACE_OUT("");

  const function* func = v.get_func();
  ZORBA_ASSERT (func != NULL);

  vector<PlanIter_t> argv (v.size ());
  generate (argv.rbegin (), argv.rend (), stack_to_generator (itstack));

  const QueryLoc& loc = v.get_loc ();

  if (func->validate_args (argv))
  {
    PlanIter_t iter = func->codegen (loc, argv, v);
    ZORBA_ASSERT(iter != NULL);
    itstack.push(iter);

    if (is_enclosed_expr(&v))
    {
      expr *e = pop_stack(theConstructorsStack);
      ZORBA_ASSERT(e == &v);

      if (!theAttrContentStack.empty() && theAttrContentStack.top() == true)
        dynamic_cast<EnclosedIterator*>(iter.getp())->setAttrContent();
    }
  }
  else 
  {
    ZORBA_ERROR_LOC_PARAM(XPST0017, loc,
                          func->get_signature().get_name()->getStringValue(),
                          argv.size());
  }
}


bool begin_visit(ft_select_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

bool begin_visit(ft_contains_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

bool begin_visit(instanceof_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(instanceof_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t p = pop_itstack ();
  itstack.push (new InstanceOfIterator (v.get_loc (), p, v.get_target_type ()));
}

bool begin_visit(treat_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(treat_expr& v)
{
  CODEGEN_TRACE_OUT("");
  std::vector<PlanIter_t> argv;
  argv.push_back (pop_itstack ());
  itstack.push (new TreatIterator (v.get_loc (), argv, v.get_target_type (), v.get_check_prime (), v.get_err ()));
}

bool begin_visit(castable_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(castable_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  itstack.push(new CastableIterator(v.get_loc(), lChild, v.get_target_type()));
}

bool begin_visit(cast_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(cast_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  itstack.push(new CastIterator(v.get_loc(), lChild, v.get_target_type()));
}

bool begin_visit(name_cast_expr& v)
{
  CODEGEN_TRACE_IN("");

  expr_t targetExpr = v.get_input();
  xqtref_t targetType = targetExpr->return_type(ccb->m_sctx);

  if (TypeOps::is_subtype(*GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE) ||
      TypeOps::is_subtype(*GENV_TYPESYSTEM.QNAME_TYPE_ONE, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.QNAME_TYPE_ONE) ||
      TypeOps::is_subtype(*GENV_TYPESYSTEM.NCNAME_TYPE_ONE, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.NCNAME_TYPE_ONE) ||
      TypeOps::is_subtype(*GENV_TYPESYSTEM.STRING_TYPE_ONE, *targetType) ||
      TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
    return true;

  ZORBA_ERROR_LOC(XPTY0004, v.get_loc());

  return true;
}

void end_visit(name_cast_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  itstack.push(new NameCastIterator(v.get_loc(), lChild, v.getNamespaceContext()));
}

bool begin_visit(validate_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

bool begin_visit(extension_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}


/*******************************************************************************

********************************************************************************/
bool begin_visit(relpath_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  // Done in axis itself
  return true;
}


void end_visit(relpath_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool begin_visit(axis_step_expr& v)
{
  CODEGEN_TRACE_IN("");

  bool result = true;

  PlanIter_t input = pop_itstack();

  ZORBA_ASSERT(input != NULL);

  PlanIter_t axisIte;

  switch (v.getAxis())
  {
  case axis_kind_self:
  {
    axisIte = new SelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_child:
  {
    axisIte = new ChildAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_parent:
  {
    axisIte = new ParentAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_descendant:
  {
    axisIte = new DescendantAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_descendant_or_self:
  {
    axisIte = new DescendantSelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_ancestor:
  {
    axisIte = new AncestorAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_ancestor_or_self:
  {
    axisIte = new AncestorSelfAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_following_sibling:
  {
    axisIte = new RSiblingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_following:
  {
    axisIte = new FollowingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_preceding_sibling:
  {
    axisIte = new LSiblingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_preceding:
  {
    axisIte = new PrecedingAxisIterator(v.get_loc(), input);
    break;
  }
  case axis_kind_attribute:
  {
    if (v.getTest()->getTestKind() == match_name_test ||
        v.getTest()->getTestKind() == match_attr_test ||
        v.getTest()->getTestKind() == match_xs_attr_test ||
        v.getTest()->getTestKind() == match_anykind_test)
    {
      axisIte = new AttributeAxisIterator(v.get_loc(), input);
    }
    else
    {
      axisIte = new EmptyIterator(v.get_loc());
      result = false;
    }

    break;
  }
  default:
    ZORBA_ASSERT (false && "Unknown axis kind");
  }

  itstack.push(axisIte);

  return result;
}


void end_visit(axis_step_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool begin_visit(match_expr& v)
{
  CODEGEN_TRACE_IN ("");

  PlanIter_t axisIte = pop_itstack();
  AxisIteratorHelper* axisItep = dynamic_cast<AxisIteratorHelper*>(&*axisIte);
  ZORBA_ASSERT(axisItep != NULL);

  PlanIter_t matchIte;
  store::Item_t qname;
  store::Item_t tname;

  store::ItemFactory& iFactory = *(GENV.getStore().getItemFactory());

  if (v.getTestKind() == match_name_test)
  {
    // Note: the attribute axis iterator does not do any filtering based on
    // the node kind, so it is ok to set the principal node kind to elementNode
    // in all cases.
    axisItep->setNodeKind(store::StoreConsts::elementNode);

    match_wild_t wildKind = v.getWildKind();

    if (wildKind == match_no_wild)
    {
      matchIte = new NameTestIterator(v.get_loc(), axisIte, v.getQName(), wildKind);
    }
    else if (wildKind == match_prefix_wild)
    {
      qname = iFactory.createQName("", "wildcard", v.getWildName().c_str());

      matchIte = new NameTestIterator(v.get_loc(), axisIte, qname, wildKind);
    }
    else if (wildKind == match_name_wild)
    {
      matchIte = new NameTestIterator(v.get_loc(), axisIte, v.getQName(), wildKind);
    }
    else
    {
      matchIte = axisIte;
    }
  }
  else
  {
    axisItep->setNodeKind(v.getNodeKind());

    matchIte = new KindTestIterator(v.get_loc(), axisIte,
                                    v.getQName(), v.getTypeName(),
                                    v.getTestKind(), v.getDocTestKind(),
                                    v.getNilledAllowed());
  }

  itstack.push(matchIte);

  return true;
}


void end_visit(match_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

  Node Constructors

********************************************************************************/

bool begin_visit(doc_expr& v)
{
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(false);

  return true;
}


void end_visit(doc_expr& v)
{
  CODEGEN_TRACE_OUT("");
  
  PlanIter_t lContent = pop_itstack();
  PlanIter_t lContIter = new DocumentContentIterator(v.get_loc(), lContent);
  PlanIter_t lDocIter = new DocumentIterator(v.get_loc(), lContIter);
  itstack.push(lDocIter);

  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e == &v);
}


bool begin_visit(elem_expr& v)
{
  CODEGEN_TRACE_IN ("");

  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top()))
  {
    if (theConstructorsStack.empty())
      theLastNSCtx = v.getNSCtx()->get_parent().getp();

    theNSCtxStack.push(theLastNSCtx);
    theLastNSCtx = v.getNSCtx().getp();
  }

  theConstructorsStack.push(&v);
  theAttrContentStack.push(false);

  return true;
}


void end_visit(elem_expr& v)
{
  CODEGEN_TRACE_OUT ("");

  PlanIter_t lQNameIter = 0;
  PlanIter_t lContentIter = 0;
  PlanIter_t lAttrsIter = 0;

  if ( v.getContent() != 0 )
  {
    lContentIter = pop_itstack();
    vector<PlanIter_t> lArgs;
    lArgs.push_back(lContentIter);
    lContentIter = new ElementContentIterator(v.get_loc(), lArgs);
  }

  if ( v.getAttrs() != 0 )
    lAttrsIter = pop_itstack();

  lQNameIter = pop_itstack();

  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e == &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top()))
  {
    isRoot = true;
    theLastNSCtx = theNSCtxStack.top();
    theNSCtxStack.pop();
  }

	PlanIter_t iter = new ElementIterator(v.get_loc(),
                                        lQNameIter,
                                        lAttrsIter,
                                        lContentIter,
                                        v.getNSCtx().getp(),
                                        isRoot);
  itstack.push(iter);
}


bool begin_visit(attr_expr& v)
{
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(true);

	return true;
}


void end_visit(attr_expr& v)
{
  CODEGEN_TRACE_OUT("");

  PlanIter_t lQNameIter = 0;
  PlanIter_t lVarIter = 0;
  PlanIter_t lContentIter = 0;
  
  if (v.getValueExpr() != 0) {
    lVarIter = pop_itstack();
  }
  else
  {
    lVarIter = new EmptyIterator(v.get_loc());
  }
  
  PlanIter_t lAttrIter = 0;
  lQNameIter = pop_itstack();
  
  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top()))
  {
    isRoot = true;
  }

  lAttrIter = new AttributeIterator(v.get_loc(), lQNameIter, lVarIter, isRoot);
  
  itstack.push(lAttrIter);
}


bool begin_visit(text_expr& v)
{
  CODEGEN_TRACE_IN ("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(true);

	return true;
}


void end_visit(text_expr& v)
{
  CODEGEN_TRACE_OUT ("");

  PlanIter_t content = pop_itstack ();

  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top()))
  {
    isRoot = true;
  }

  switch (v.get_type ()) {
  case text_expr::text_constructor:
    itstack.push (new TextIterator(v.get_loc(), content, isRoot));
    break;

  case text_expr::comment_constructor:
    itstack.push (new CommentIterator (v.get_loc(), content, isRoot));
    break;

  default:
    break;
  }
}


bool begin_visit(pi_expr& v)
{
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(true);

  return true;
}


void end_visit(pi_expr& v)
{
  CODEGEN_TRACE_OUT("");

  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top()))
  {
    isRoot = true;
  }

  PlanIter_t content = pop_itstack ();
  PlanIter_t target = pop_itstack ();
  itstack.push (new PiIterator (v.get_loc (), target, content, isRoot));
}


bool begin_visit(function_def_expr& /*v*/) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (function_def_expr &v) {
  CODEGEN_TRACE_OUT("");
}


bool begin_visit(const_expr& /*v*/)
{
  CODEGEN_TRACE_IN ("");
  return true;
}

void end_visit(const_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t it = new SingletonIterator (v.get_loc (), v.get_val ());
  itstack.push (it);
}


bool begin_visit(order_expr& /*v*/)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(order_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************


********************************************************************************/

/*..........................................
 :  end visit                              :
 :.........................................*/

void end_visit(ft_select_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}

void end_visit(ft_contains_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}

void end_visit(validate_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}

void end_visit(extension_expr& /*v*/)
{
  CODEGEN_TRACE_OUT("");
}


};



/*******************************************************************************

********************************************************************************/
PlanIter_t codegen(
    const char *descr,
    expr *root,
    CompilerCB *ccb,
    hash64map<vector<LetVarIter_t> *> *param_var_map)
{
  plan_visitor c(ccb, param_var_map);
  root->accept (c);
  PlanIter_t result = c.pop_itstack ();

  // HACK: print only main query if no-tree-id's is active.
  // When that happens, we are comparing iterator plans.
  if (result != NULL && descr != NULL && Properties::instance()->printIteratorTree()
      && (xqp_string ("main query") == descr || ! Properties::instance()->noTreeIds())) 
  {
    cout << "Iterator tree for " << descr << ":\n";
    XMLIterPrinter vp (cout);
    print_iter_plan (vp, result);
    cout << endl;
  }
	
  return result;
}



} /* namespace zorba */
