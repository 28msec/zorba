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
#include "util/tracer.h"
#include "util/stl_extra.h"
#include "util/hashmap32.h"

#include "compiler/codegen/plan_visitor.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/parser/parse_constants.h"

#include "system/globalenv.h"

#include "zorbaerrors/Assert.h"

#include "context/namespace_context.h"
#include "context/static_context.h"
#include "context/static_context_consts.h"

#include "runtime/sequences/SequencesImpl.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/constructors.h"
#include "runtime/core/path_iterators.h"
#include "runtime/core/path.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/trycatch.h"
#include "runtime/core/gflwor/common.h"
#include "runtime/core/gflwor/groupby_iterator.h"
#include "runtime/core/gflwor/tuplestream_iterator.h"
#include "runtime/core/gflwor/for_iterator.h"
#include "runtime/core/gflwor/outerfor_iterator.h"
#include "runtime/core/gflwor/let_iterator.h"
#include "runtime/core/gflwor/window_iterator.h"
#include "runtime/core/gflwor/where_iterator.h"
#include "runtime/core/gflwor/count_iterator.h"
#include "runtime/core/gflwor/tuplesource_iterator.h"
#include "runtime/core/gflwor/orderby_iterator.h"
#include "runtime/validate/validate.h"
#include "runtime/fncontext/FnContextImpl.h"
#include "runtime/misc/MiscImpl.h"
#include "runtime/update/update.h"
#include "runtime/visitors/printervisitor.h"
#include "runtime/visitors/iterprinter.h"

#include "functions/function.h"

#include <zorba/zorba.h>
#include "runtime/debug/zorba_debug_iterator.h"
#include "debugger/zorba_debugger_commons.h"

#include "types/typeops.h"

#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"


#define QLOCDECL const QueryLoc &qloc = v.get_loc(); (void) qloc

#define SCTXDECL short sctx = v.get_cur_sctx(); (void) sctx

#ifndef NDEBUG

#define CODEGEN_TRACE(msg)                      \
  QLOCDECL;                                     \
  SCTXDECL;                                     \
  if (Properties::instance()->traceCodegen()) { \
    cout << (msg) << TRACE << ", stk size " << itstack.size () << endl; \
    cout << endl; \
    v.put(cout); \
    cout << "StackTop:" << endl; \
    print_stack(); \
  }

#define CODEGEN_TRACE_IN( msg )  \
  CODEGEN_TRACE (string (++depth, ' ') + msg)

#define CODEGEN_TRACE_OUT( msg ) \
  CODEGEN_TRACE (string (depth--, ' ') + msg)

#else
#define CODEGEN_TRACE(msg) QLOCDECL; SCTXDECL;
#define CODEGEN_TRACE_IN(msg) CODEGEN_TRACE(msg)
#define CODEGEN_TRACE_OUT(msg) CODEGEN_TRACE(msg)
#endif

#define DOT_VAR "$$dot"
#define DOT_POS_VAR "$$pos"
#define LAST_IDX_VAR "$$last-idx"

using namespace std;

namespace zorba 
{

typedef rchandle<ForVarIterator> ForVarIter_t;
typedef rchandle<LetVarIterator> LetVarIter_t;


#define ITEM_FACTORY (GENV.getStore().getItemFactory())

template <typename T> T pop_stack (stack<T> &stk) 
{
  assert (! stk.empty ());
  T x = stk.top ();
  stk.pop ();
  return x;
}


template<class T> T &peek_stack (stack<T> &stk) 
{
  ZORBA_ASSERT (! stk.empty ());
  return stk.top ();
}


template <typename V>
struct vector_destroyer 
{
  void operator()(const struct hash64map<vector<V> *>::entry& entry)
  {
    delete (const_cast<struct hash64map<vector<V> *>::entry&>(entry)).val;
  }
};


/*******************************************************************************

********************************************************************************/
class VarRebind : public SimpleRCObject
{
public:
  PlanIter_t               theInputVar;
  std::vector<PlanIter_t>  theOutputVarRefs;
};


typedef rchandle<VarRebind> VarRebind_t;


/*******************************************************************************

********************************************************************************/
class FlworClauseVarMap : public SimpleRCObject
{
public:
  bool                          theIsGeneral;
  const flwor_clause          * theClause;

  std::vector<const var_expr*>  theVarExprs;
  std::vector<VarRebind_t>      theVarRebinds;

public:
  FlworClauseVarMap(const flwor_clause* cl, bool general)
    :
    theIsGeneral(general),
    theClause(cl) 
  {
  }

  ~FlworClauseVarMap() { }

  long find_var(const var_expr* var) const
  {
    ulong numVars = theVarExprs.size();
    for (ulong i = 0; i < numVars; ++i)
    {
      if (theVarExprs[i] == var)
        return i;
    }

    return -1;
  }
};


typedef rchandle<FlworClauseVarMap> FlworClauseVarMap_t;


/*******************************************************************************

********************************************************************************/
class plan_visitor : public expr_visitor
{
protected:
  static vector<PlanIter_t> no_var_iters;

protected:
  uint32_t depth;
  
  stack<PlanIter_t>                      itstack;

  stack<expr*>                           theConstructorsStack;
  stack<bool>                            theAttrContentStack;

  hash64map<vector<LetVarIter_t> *>    * arg_var_iter_map;
  hash64map<vector<LetVarIter_t> *>      catchvar_iter_map;
  hash64map<vector<ForVarIter_t> *>      copy_var_iter_map;

  std::vector<FlworClauseVarMap_t>       theClauseStack;

  CompilerCB                           * ccb;

  std::stack<ZorbaDebugIterator*>                     theDebuggerStack;

#define LOOKUP_OP1( local ) (ccb->m_sctx->lookup_builtin_fn (":" local, 1))

public:

plan_visitor(CompilerCB *ccb_, hash64map<vector<LetVarIter_t> *> *arg_var_map = NULL)
  :
  depth (0),
  arg_var_iter_map(arg_var_map),
  ccb (ccb_)
{
}


~plan_visitor() 
{
  for_each(catchvar_iter_map.begin(), catchvar_iter_map.end(), vector_destroyer<LetVarIter_t>());
  for_each(copy_var_iter_map.begin(), copy_var_iter_map.end(), vector_destroyer<ForVarIter_t>());
}

public:

PlanIter_t pop_itstack() 
{
  return pop_stack(itstack);
}


void push_itstack(PlanIterator* iter)
{
  itstack.push(iter);
}


void print_stack()
{
  if (itstack.empty()) {
    cout << "EMPTY" << endl;
  } else {
    XMLIterPrinter vp (cout);
    print_iter_plan (vp, peek_stack(itstack));
  }
}


bool is_enclosed_expr(expr* e) 
{
  fo_expr* foe = dynamic_cast<fo_expr*>(e);
  if (foe != NULL &&
      foe->get_fname()->getLocalName()->byteEqual(":enclosed-expr", 14))
    return true;
  
  return false;
}


bool begin_visit (expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (expr& v) {
  CODEGEN_TRACE_OUT("");
}

bool begin_visit (debugger_expr& v) {
  CODEGEN_TRACE_IN("");
  std::vector<PlanIter_t> aTmpVec;
  theDebuggerStack.push(new ZorbaDebugIterator(sctx, qloc, aTmpVec));
  return true;
}

void end_visit (debugger_expr& v) {
  CODEGEN_TRACE_OUT(""); 
  checked_vector<PlanIter_t> argv;
  checked_vector<store::Item_t> varnames;
  checked_vector<string> var_keys;
  checked_vector<global_binding> globals;
  checked_vector<xqtref_t> vartypes;
  for (unsigned i = 0; i < v.var_count (); i++) 
  {
    varnames.push_back (v.var_at (i).varname);
    var_keys.push_back (v.var_at (i).var_key);
    vartypes.push_back (v.var_at (i).type);
    argv.push_back (pop_itstack ());
  }
  list<global_binding> lGlobals = v.getGlobals();
  list<global_binding>::iterator it;
  for ( it = lGlobals.begin(); it != lGlobals.end(); ++it )
  {
    globals.push_back( *it );
  }
  argv.push_back (pop_itstack ());
  reverse (argv.begin (), argv.end ());
  auto_ptr<ZorbaDebugIterator> aDebugIterator(theDebuggerStack.top());
  theDebuggerStack.pop();
  aDebugIterator->setChildren(argv);
  if (!theDebuggerStack.empty()) {
    theDebuggerStack.top()->addChild(aDebugIterator.get());
    aDebugIterator->setParent(theDebuggerStack.top());
  }
  DebugLocation_t lLocation;
  lLocation.theLineNumber = qloc.getLineno();
  lLocation.theFileName = qloc.getFilename();
  /*push_itstack(new FnDebugIterator(this->ccb->m_debugger, 
                                   sctx,
                                   qloc,
                                   varnames,
                                   var_keys,
                                   vartypes,
                                   globals,
                                   argv,
                                   v.isForExpr()));*/
  push_itstack(aDebugIterator.release());
}

bool begin_visit (wrapper_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (wrapper_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t iter = pop_itstack ();
  iter->setLocation (v.get_loc ());
  push_itstack(iter);
}

bool begin_visit (sequential_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (sequential_expr& v) {
  CODEGEN_TRACE_OUT("");
  checked_vector<PlanIter_t> argv;
  size_t lSize = v.size();
  for (unsigned i = 0; i < lSize; i++)
    argv.push_back (pop_itstack ());
  reverse (argv.begin (), argv.end ());

  push_itstack(new SequentialIterator (sctx, qloc, argv, v.is_updating ()));
}


/*******************************************************************************
  VarRef expr
********************************************************************************/

bool begin_visit (var_expr& v) 
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit (var_expr& v) 
{
  CODEGEN_TRACE_OUT("");
  general_var_codegen (v);
}


template<class Iter>
PlanIter_t base_var_codegen(
    const var_expr& var,
    hash64map<vector<rchandle<Iter> > *>& varMap) 
{
  vector<rchandle<Iter> >* varRefs = NULL;
  bool bound = varMap.get((uint64_t) &var, varRefs);
  ZORBA_ASSERT(bound);

  Iter* iter = new Iter(var.get_cur_sctx(), var.get_loc(), var.get_varname());

  varRefs->push_back(iter);

  return iter;
}


PlanIter_t create_var_iter(const var_expr& var, bool forvar)
{
  PlanIter_t iter;
  if (forvar)
  {
    iter = new ForVarIterator(var.get_cur_sctx(), var.get_loc(), var.get_varname());
  }
  else
  {
    iter = new LetVarIterator(var.get_cur_sctx(), var.get_loc(), var.get_varname());
  }
  return iter;
}


void general_var_codegen (const var_expr& var)
{
  const QueryLoc& qloc = var.get_loc();
  short sctx = var.get_cur_sctx();

  bool isForVar = false;

  switch (var.get_kind())
  {
  case var_expr::for_var:
  case var_expr::pos_var:
  case var_expr::wincond_out_var:
  case var_expr::wincond_out_pos_var:
  case var_expr::groupby_var:
  case var_expr::count_var:

  case var_expr::wincond_in_var:
  case var_expr::wincond_in_pos_var:
  {
    isForVar = true;
    // fall through
  }

  case var_expr::let_var:
  case var_expr::win_var:
  case var_expr::non_groupby_var:
  {
    ZORBA_ASSERT(!theClauseStack.empty());

    long stackSize = theClauseStack.size();
    long varPos;
    VarRebind_t varRebind;
    PlanIter_t varIter;

    // Look for the inner-most clause C that knows about this variable. C is
    // either the clause D_C that defines the var, or the inner-most orderby
    // clause the comes after D_C and rebinds the var to its output.
    long i = stackSize - 1;
    while(true)
    {
      if ((varPos = theClauseStack[i]->find_var(&var)) >= 0)
        break;

      --i;
      ZORBA_ASSERT(i >= 0);
    }

    // Create a var iter in the output of C.
    varIter = create_var_iter(var, isForVar);

    theClauseStack[i]->theVarRebinds[varPos]->theOutputVarRefs.push_back(varIter);

    if (theClauseStack[i]->theIsGeneral)
    {
      // For each orderby O after C, bind the var iter created by the previous
      // clause to the input of O, and then create a new var iter and put it to
      // the output of O.
      for (++i; i < stackSize; ++i)
      {
        ZORBA_ASSERT(theClauseStack[i]->find_var(&var) < 0);

        if (theClauseStack[i]->theClause->get_kind() == flwor_clause::order_clause)
        {
          varRebind = new VarRebind;
          varRebind->theInputVar = varIter;
          theClauseStack[i]->theVarExprs.push_back(&var);
          theClauseStack[i]->theVarRebinds.push_back(varRebind);
          
          varIter = create_var_iter(var, isForVar);

          varRebind->theOutputVarRefs.push_back(varIter);
        }
      }
    }

    push_itstack(varIter);
    break;
  }

  case var_expr::arg_var: 
  {
    PlanIter_t iter = base_var_codegen(var, *arg_var_iter_map);
    push_itstack(iter);
    break;
  }

  case var_expr::catch_var:
  {
    PlanIter_t iter = base_var_codegen(var, catchvar_iter_map);
    push_itstack(iter);
    break;
  }

  case var_expr::copy_var:
  {
    PlanIter_t iter = base_var_codegen(var, copy_var_iter_map);
    push_itstack(iter);
    break;
  }

  case var_expr::prolog_var: 
  case var_expr::local_var: 
  {
    xqpString varname = var.get_varname()->getStringValue().getp();
    if (varname == DOT_VAR) 
    {
      vector<PlanIter_t> ctx_args;
      store::Item_t qname;
      xqpStringStore_t dot = new xqpStringStore (".");
      ITEM_FACTORY->createString (qname, dot);
      ctx_args.push_back (new SingletonIterator (sctx, qloc, qname));
      push_itstack(new CtxVariableIterator (sctx, qloc, ctx_args));
    }
    else if (varname == DOT_POS_VAR) 
    {
      store::Item_t i;
      ITEM_FACTORY->createInteger (i, Integer::parseInt((int32_t)1));
      push_itstack(new SingletonIterator (sctx, qloc, i));
    }
    else if (varname == LAST_IDX_VAR) 
    {
      store::Item_t i;
      ITEM_FACTORY->createInteger (i, Integer::parseInt((int32_t)1));
      push_itstack(new SingletonIterator (sctx, qloc, i));
    }
    else 
    {
      expr_t lookup_expr = new fo_expr(sctx,
                                       qloc,
                                       LOOKUP_OP1 ("ctxvariable"),
                                       new const_expr(sctx,
                                                      qloc,
                                                      dynamic_context::var_key(&var)));
      lookup_expr->accept (*this);
    }
 
    break;
  }

  case var_expr::unknown_var:
  default:
    // ZORBA_ASSERT (false);
    break;
  }
}


/*******************************************************************************
  FLWOR expr
********************************************************************************/
bool begin_visit(flwor_expr& v) 
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(flwor_expr& v)
{
  CODEGEN_TRACE_OUT("");

  if (!v.is_general())
  {
    flwor_codegen(v);
  }
  else
  {
    PlanIter_t ret = pop_itstack();

    PlanIter_t gflwor = gflwor_codegen(v, v.num_clauses() - 1);

    push_itstack(new flwor::TupleStreamIterator(sctx, qloc, gflwor, ret, false));
  }
}


void visit_flwor_clause(const flwor_clause* c, bool general)
{
  if (c->get_kind() == flwor_clause::where_clause)
    return;

  FlworClauseVarMap_t clauseVarMap = new FlworClauseVarMap(c, general);

  switch (c->get_kind())
  {
  case flwor_clause::for_clause:
  {
    const for_clause* fc = static_cast<const for_clause *>(c);
    
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(fc->get_var());
    clauseVarMap->theVarRebinds.push_back(varRebind);
      
    if (fc->get_pos_var() != NULL)
    {
      varRebind = new VarRebind;
      clauseVarMap->theVarExprs.push_back(fc->get_pos_var());
      clauseVarMap->theVarRebinds.push_back(varRebind);
    }

    break;
  }

  case flwor_clause::let_clause: 
  {
    const let_clause* lc = static_cast<const let_clause *>(c);
    
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(lc->get_var());
    clauseVarMap->theVarRebinds.push_back(varRebind);

    break;
  }

  case flwor_clause::window_clause: 
  {
    const window_clause* wc = static_cast<const window_clause *>(c);

    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(wc->get_var());
    clauseVarMap->theVarRebinds.push_back(varRebind);

    init_wincond_var_maps(wc->get_win_stop(), clauseVarMap);
    init_wincond_var_maps(wc->get_win_start(), clauseVarMap);

    break;
  }

  case flwor_clause::group_clause: 
  {
    const group_clause* gbc = static_cast<const group_clause *>(c);
    const group_clause::rebind_list_t& grouping_vars = gbc->get_grouping_vars();
    const group_clause::rebind_list_t& nongrouping_vars = gbc->get_nongrouping_vars();

    for (unsigned i = 0; i < grouping_vars.size(); i++)
    {
      VarRebind_t varRebind = new VarRebind;
      clauseVarMap->theVarExprs.push_back(grouping_vars[i].second.getp());
      clauseVarMap->theVarRebinds.push_back(varRebind);
    }
    
    for (unsigned i = 0; i < nongrouping_vars.size(); i++)
    {
      VarRebind_t varRebind = new VarRebind;
      clauseVarMap->theVarExprs.push_back(nongrouping_vars[i].second.getp());
      clauseVarMap->theVarRebinds.push_back(varRebind);
    }

    break;
  }
  
  case flwor_clause::order_clause:
  {
    break;
  }

  case flwor_clause::count_clause:
  {
    const count_clause* cl = static_cast<const count_clause *>(c);
    
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(cl->get_var());
    clauseVarMap->theVarRebinds.push_back(varRebind);

    break;
  }

  default:
    ZORBA_ASSERT(false);
  }

  if (clauseVarMap != NULL)
    theClauseStack.push_back(clauseVarMap);
}


void init_wincond_var_maps(
    const flwor_wincond* cond,
    FlworClauseVarMap* clauseVarMap) 
{
  if (cond == NULL)
    return;

  const flwor_wincond::vars& inVars = cond->get_in_vars();
  const flwor_wincond::vars& outVars = cond->get_out_vars();

  if (inVars.posvar != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(inVars.posvar.getp());
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (inVars.curr != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(inVars.curr.getp());
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (inVars.prev != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(inVars.prev.getp());
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (inVars.next != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(inVars.next.getp());
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (outVars.posvar != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(outVars.posvar.getp());
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (outVars.curr != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(outVars.curr.getp());
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (outVars.prev != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(outVars.prev.getp());
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (outVars.next != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(outVars.next.getp());
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }
}


struct wincond_var_iters 
{
  vector<PlanIter_t> * inPos;
  vector<PlanIter_t> * inCurr;
  vector<PlanIter_t> * inPrev;
  vector<PlanIter_t> * inNext;

  vector<PlanIter_t> * outPos;
  vector<PlanIter_t> * outCurr;
  vector<PlanIter_t> * outPrev;
  vector<PlanIter_t> * outNext;

  wincond_var_iters(
        const flwor_wincond* cond,
        FlworClauseVarMap* clauseVarMap,
        ulong& varPos)
  {
    const flwor_wincond::vars& inVars = cond->get_in_vars();
    const flwor_wincond::vars& outVars = cond->get_out_vars();

    inPos = ((inVars.posvar != NULL) ?
             &clauseVarMap->theVarRebinds[varPos++]->theOutputVarRefs : 
             &plan_visitor::no_var_iters);

    inCurr = (inVars.curr != NULL ?
              &clauseVarMap->theVarRebinds[varPos++]->theOutputVarRefs : 
              &plan_visitor::no_var_iters);

    inPrev = (inVars.prev != NULL ?
              &clauseVarMap->theVarRebinds[varPos++]->theOutputVarRefs : 
              &plan_visitor::no_var_iters);

    inNext = (inVars.next != NULL ?
              &clauseVarMap->theVarRebinds[varPos++]->theOutputVarRefs : 
              &plan_visitor::no_var_iters);

    outPos = (outVars.posvar != NULL ?
              &clauseVarMap->theVarRebinds[varPos++]->theOutputVarRefs : 
              &plan_visitor::no_var_iters);

    outCurr = (outVars.curr != NULL ?
               &clauseVarMap->theVarRebinds[varPos++]->theOutputVarRefs : 
               &plan_visitor::no_var_iters);

    outPrev = (outVars.prev != NULL ?
               &clauseVarMap->theVarRebinds[varPos++]->theOutputVarRefs : 
               &plan_visitor::no_var_iters);

    outNext = (outVars.next != NULL ?
               &clauseVarMap->theVarRebinds[varPos++]->theOutputVarRefs : 
               &plan_visitor::no_var_iters);
  }
};



PlanIter_t gflwor_codegen(flwor_expr& flworExpr, int currentClause) 
{
#define PREV_ITER gflwor_codegen(flworExpr, currentClause - 1)

  const QueryLoc& qloc = flworExpr.get_loc();

  if (currentClause < 0)
  {
    return new flwor::TupleSourceIterator(flworExpr.get_cur_sctx(), qloc);
  }

  const flwor_clause& c = *(flworExpr[currentClause]);

  FlworClauseVarMap_t clauseVarMap;

  if (c.get_kind() != flwor_clause::where_clause) 
  {
    ZORBA_ASSERT(!theClauseStack.empty());
    ulong stackSize = theClauseStack.size();

    clauseVarMap = theClauseStack[stackSize-1];
    theClauseStack.resize(stackSize - 1);

    ZORBA_ASSERT(clauseVarMap->theClause == &c);
  }

  //
  // WHERE
  //
  if (c.get_kind() == flwor_clause::where_clause) 
  {
    PlanIter_t where = pop_itstack();
    return new flwor::WhereIterator(flworExpr.get_cur_sctx(), c.get_loc(), PREV_ITER, where);
  }

  //
  // FOR
  //
  else if (c.get_kind() == flwor_clause::for_clause)
  {
    const for_clause* fc = static_cast<const for_clause *>(&c);

    ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() >= 1);

    var_expr* var = fc->get_var();

    PlanIter_t domainIter = pop_itstack();

    vector<PlanIter_t>& varRefs = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;
    vector<PlanIter_t>* posVarRefs = &no_var_iters;

    if (fc->get_pos_var())
    {
      ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 2);

      posVarRefs = &clauseVarMap->theVarRebinds[1]->theOutputVarRefs;
    }

    if (! fc->is_outer()) 
    {
//#ifdef ZORBA_DEBUGGER
//      if(ccb->m_debugger != 0)
//      {
//        checked_vector<PlanIter_t> argv;
//        checked_vector<store::Item_t> varnames;
//        checked_vector<string> var_keys;
//        checked_vector<global_binding> globals;
//        checked_vector<xqtref_t> vartypes;
//   
//        checked_vector<bound_var> lVars = fc->get_bound_variables();
//        checked_vector<bound_var>::iterator lIter;
//   
//        for ( lIter = lVars.begin(); lIter != lVars.end(); ++lIter )
//        {
//          varnames.push_back (lIter->varname);
//          var_keys.push_back (lIter->var_key);
//          vartypes.push_back (lIter->type);
//          //lIter->var->accept(*this);
//          //argv.push_back(pop_itstack());
//        }
//        reverse(argv.begin(), argv.end());
//        list<global_binding> lGlobals = fc->get_global_variables();
//        list<global_binding>::iterator it;
//        for ( it = lGlobals.begin(); it != lGlobals.end(); ++it )
//        {
//          globals.push_back( *it );
//        }
//        argv.push_back(new flwor::ForIterator(var->get_cur_sctx(),
//                                              var->get_loc (),
//                                              var->get_varname(),
//                                              PREV_ITER,
//                                              domainIter,
//                                              varRefs,
//                                              *posVarRefs));
//        reverse (argv.begin (), argv.end ());
//        return new FnDebugIterator(ccb->m_debugger,
//                                   var->get_cur_sctx(),
//                								   var->get_loc(),
//                                   varnames,
//                                   var_keys,
//                                   vartypes,
//                                   globals,
//                                   argv,
//                                   true);
//      }
//#endif
      return new flwor::ForIterator(var->get_cur_sctx(),
                                    var->get_loc(),
                                    var->get_varname(),
                                    PREV_ITER,
                                    domainIter,
                                    varRefs,
                                    *posVarRefs);
    }
    else
    {
      ZORBA_ASSERT(fc->get_pos_var() == NULL);

      return new flwor::OuterForIterator(var->get_cur_sctx(),
                                         var->get_loc(),
                                         var->get_varname(),
                                         PREV_ITER,
                                         domainIter,
                                         varRefs);
    }
  }

  //
  // LET
  //
  else if (c.get_kind() == flwor_clause::let_clause)
  {
    const let_clause* lc = static_cast<const let_clause *>(&c);

    ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

    var_expr* var = lc->get_var();

    PlanIter_t domainIter = pop_itstack();

    vector<PlanIter_t>& varRefs = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

    return new flwor::LetIterator(var->get_cur_sctx(),
                                  var->get_loc(),
                                  var->get_varname(),
                                  PREV_ITER,
                                  domainIter,
                                  varRefs,
                                  true);
  }

  //
  // WINDOW
  //
  else if (c.get_kind() == flwor_clause::window_clause)
  {
    const window_clause* wc = static_cast<const window_clause *>(&c);

    var_expr* var = wc->get_var();
    PlanIter_t domainIter = pop_itstack();

    vector<PlanIter_t>& varRefs = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

    auto_ptr<flwor::StartClause> start_clause;
    auto_ptr<flwor::EndClause> end_clause;
    const flwor_wincond* cond;
    ulong varPos = 1;

    if (NULL == (cond = wc->get_win_stop()))
    {
      end_clause.reset(new flwor::EndClause);
    }
    else 
    {
      wincond_var_iters wcv(cond, clauseVarMap, varPos);

      flwor::WindowVars wvars(*wcv.inCurr, *wcv.inPrev, *wcv.inNext, *wcv.inPos,
                              *wcv.outCurr, *wcv.outPrev, *wcv.outNext, *wcv.outPos);

      end_clause.reset(new flwor::EndClause(pop_itstack(), wvars, cond->is_only()));
    }

    if (NULL != (cond = wc->get_win_start())) 
    {
      wincond_var_iters wcv(cond, clauseVarMap, varPos);

      flwor::WindowVars wvars(*wcv.inCurr, *wcv.inPrev, *wcv.inNext, *wcv.inPos,
                              *wcv.outCurr, *wcv.outPrev, *wcv.outNext, *wcv.outPos);

      start_clause.reset(new flwor::StartClause(pop_itstack(), wvars));
    }

    return new flwor::WindowIterator(var->get_cur_sctx(),
                                     var->get_loc(),
                                     wc->get_winkind() == window_clause::tumbling_window ? flwor::WindowIterator::TUMBLING : flwor::WindowIterator::SLIDING,
                                     PREV_ITER,
                                     domainIter,
                                     var->get_varname(),
                                     varRefs,
                                     *start_clause,
                                     *end_clause);
  }

  //
  // COUNT
  //
  else if (c.get_kind() == flwor_clause::count_clause) 
  {
    varref_t var = static_cast<const count_clause *>(&c)->get_var();

    ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

    vector<PlanIter_t>& var_iters = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

    return new flwor::CountIterator(var->get_cur_sctx(),
                                    var->get_loc(),
                                    var->get_varname(),
                                    PREV_ITER,
                                    var_iters);
  }

  //
  // ORDERBY
  //
  else if (c.get_kind() == flwor_clause::order_clause) 
  {
    ulong numVars = clauseVarMap->theVarRebinds.size();
    ulong numForVars = 0;
    ulong numLetVars = 0;

    vector<ForVarIter_t> inputForVars(numVars);
    vector<LetVarIter_t> inputLetVars(numVars);
    vector<vector<ForVarIter_t> > outputForVarsRefs(numVars);
    vector<vector<LetVarIter_t> > outputLetVarsRefs(numVars);

    for (ulong i = 0; i < numVars; ++i)
    {
      VarRebind* varRebind = clauseVarMap->theVarRebinds[i].getp();

      ForVarIterator* forIter = dynamic_cast<ForVarIterator*>
                                (varRebind->theInputVar.getp());

      if (forIter != NULL)
      {
        inputForVars[numForVars] = forIter;

        flwor::castIterVector<ForVarIterator>(outputForVarsRefs[numForVars],
                                              varRebind->theOutputVarRefs);
        ++numForVars;
      }
      else
      {
        LetVarIterator* letIter = dynamic_cast<LetVarIterator*>
                                (varRebind->theInputVar.getp());
        ZORBA_ASSERT(letIter != NULL);

        inputLetVars[numLetVars] = letIter;

        flwor::castIterVector<LetVarIterator>(outputLetVarsRefs[numLetVars],
                                              varRebind->theOutputVarRefs);
        ++numLetVars;
      }
    }

    inputForVars.resize(numForVars);
    outputForVarsRefs.resize(numForVars);
    inputLetVars.resize(numLetVars);
    outputLetVarsRefs.resize(numLetVars);

    const orderby_clause* obc = static_cast<const orderby_clause *>(&c);
    ulong numColumns = obc->num_columns();
    const std::vector<order_modifier>& modifiers = obc->get_modifiers();

    std::vector<flwor::OrderSpec> orderSpecs(numColumns);

    for (long i = numColumns - 1; i >= 0; --i)
    {
      bool emptyLeast = (modifiers[i].theEmptyMode == StaticContextConsts::empty_least);
      bool descending = (modifiers[i].theDirection == ParseConstants::dir_descending);

      orderSpecs[i] = flwor::OrderSpec(pop_itstack(), 
                                       emptyLeast,
                                       descending,
                                       modifiers[i].theCollation);
    }

    return new flwor::OrderByIterator(flworExpr.get_cur_sctx(),
                                      c.get_loc(),
                                      obc->is_stable(),
                                      orderSpecs,
                                      PREV_ITER,
                                      inputForVars,
                                      inputLetVars,
                                      outputForVarsRefs,
                                      outputLetVarsRefs);
  }

  //
  // GROUPBY
  //
  else if (c.get_kind() == flwor_clause::group_clause) 
  {
    vector<flwor::GroupingSpec> gspecs;
    vector<flwor::GroupingOuterVar> gouters;

    generate_groupby(clauseVarMap, gspecs, gouters);

    return new flwor::GroupByIterator(flworExpr.get_cur_sctx(), c.get_loc(), PREV_ITER, gspecs, gouters);
  }

  ZORBA_ASSERT (false);
  return NULL;
#undef PREV_ITER
}


void flwor_codegen(const flwor_expr& flworExpr) 
{
  flwor::FLWORIterator* flworIter;
  PlanIter_t returnIter;
  auto_ptr<flwor::OrderByClause> orderClause(NULL);
  auto_ptr<flwor::GroupByClause> groupClause(NULL);
  PlanIter_t whereIter;
  vector<flwor::ForLetClause> forletClauses;

  unsigned numClauses = flworExpr.num_clauses();

  returnIter = pop_itstack();

  for (int it = numClauses - 1; it >= 0; --it)
  {
    const flwor_clause& c = *flworExpr[it];

    FlworClauseVarMap_t clauseVarMap;

    if (c.get_kind() != flwor_clause::where_clause) 
    {
      ZORBA_ASSERT(!theClauseStack.empty());
      ulong stackSize = theClauseStack.size();
      
      clauseVarMap = theClauseStack[stackSize-1];
      theClauseStack.resize(stackSize - 1);
      
      ZORBA_ASSERT(clauseVarMap->theClause == &c);
    }

    //
    // ORDERBY
    //
    if (c.get_kind() == flwor_clause::order_clause)
    {
      const orderby_clause* obc = static_cast<const orderby_clause*>(&c);
      unsigned numColumns = obc->num_columns();
      const std::vector<order_modifier>& modifiers = obc->get_modifiers();

      vector<flwor::OrderSpec> orderSpecs(numColumns);

      for (int i = numColumns - 1; i >= 0; --i)
      {
        bool emptyLeast = (modifiers[i].theEmptyMode == StaticContextConsts::empty_least);
        bool descending = (modifiers[i].theDirection == ParseConstants::dir_descending);

        orderSpecs[i] = flwor::OrderSpec(pop_itstack(),
                                         emptyLeast,
                                         descending,
                                         modifiers[i].theCollation);
      }

      orderClause.reset(new flwor::OrderByClause(orderSpecs, obc->is_stable()));
    }

    //
    // GROUPBY
    //
    else if (c.get_kind() == flwor_clause::group_clause)
    {
      vector<flwor::GroupingSpec> gspecs;
      vector<flwor::GroupingOuterVar> gouters;

      generate_groupby(clauseVarMap, gspecs, gouters);

      groupClause.reset(new flwor::GroupByClause(gspecs, gouters));
    }

    //
    // WHERE
    //
    else if (c.get_kind() == flwor_clause::where_clause)
    {
      whereIter = pop_itstack();
    }

    //
    // FOR
    //
    else if (c.get_kind() == flwor_clause::for_clause)
    {
      const for_clause* fc = static_cast<const for_clause *>(&c);

      ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() >= 1);

      var_expr* var = fc->get_var();

      PlanIter_t domainIter = pop_itstack();

      vector<PlanIter_t>& varRefs = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

      if (fc->get_pos_var())
      {
        ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 2);
        
        vector<PlanIter_t>& posVarRefs = clauseVarMap->theVarRebinds[1]->theOutputVarRefs;

        forletClauses.push_back(flwor::ForLetClause(var->get_varname(),
                                                    varRefs,
                                                    posVarRefs,
                                                    domainIter));
      }
      else
      {
        ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

        forletClauses.push_back(flwor::ForLetClause(var->get_varname(),
                                                    varRefs,
                                                    domainIter));
      }
    }

    //
    // LET
    //
    else if (c.get_kind() == flwor_clause::let_clause)
    {
      const let_clause* lc = static_cast<const let_clause *>(&c);

      ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

      var_expr* var = lc->get_var();

      PlanIter_t domainIter = pop_itstack();

      vector<PlanIter_t>& varRefs = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;
 
      forletClauses.push_back(flwor::ForLetClause(var->get_varname(),
                                                  varRefs,
                                                  domainIter,
                                                  true));
    }

    else
    {
      ZORBA_ASSERT(false);
    }
  }

  std::reverse(forletClauses.begin(), forletClauses.end());

  flworIter = new flwor::FLWORIterator(flworExpr.get_cur_sctx(),
                                       flworExpr.get_loc(),
                                       forletClauses,
                                       whereIter,
                                       groupClause.release(), 
                                       orderClause.release(),
                                       returnIter,
                                       flworExpr.is_updating());
  push_itstack(flworIter);
}


void generate_groupby(
    const FlworClauseVarMap* clauseVarMap,
    vector<flwor::GroupingSpec>& gspecs,
    vector<flwor::GroupingOuterVar>& gouters)
{
  const group_clause* gbc = static_cast<const group_clause*>(clauseVarMap->theClause);
  const group_clause::rebind_list_t& gvars = gbc->get_grouping_vars();
  const group_clause::rebind_list_t& ngvars = gbc->get_nongrouping_vars();
  const vector<string>& collations = gbc->get_collations();
  long numVars = gvars.size() + ngvars.size();
  long numGroupVars = gvars.size();
  long i = numVars - 1;

  for (; i >= numGroupVars; --i) 
  {
    VarRebind* varRebind = clauseVarMap->theVarRebinds[i].getp();
        
    const vector<PlanIter_t>& varRefs = varRebind->theOutputVarRefs;

    gouters.push_back(flwor::GroupingOuterVar(pop_itstack(), varRefs));
  }

  for (; i >= 0; --i) 
  {
    VarRebind* varRebind = clauseVarMap->theVarRebinds[i].getp();
    
    const vector<PlanIter_t>& varRefs = varRebind->theOutputVarRefs;
    
    gspecs.push_back(flwor::GroupingSpec(pop_itstack(), varRefs, collations[i]));
  }
}


/*******************************************************************************

********************************************************************************/

bool begin_visit (promote_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (promote_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  // TODO: Currently we use cast. Promotion may be more efficient.
  push_itstack(new PromoteIterator(sctx, qloc, lChild, v.get_target_type()));
}

bool begin_visit (trycatch_expr& v) {
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

void end_visit (trycatch_expr& v) {
  CODEGEN_TRACE_OUT("");
  vector<LetVarIter_t> *vec = NULL;
  vector<TryCatchIterator::CatchClause> rev_ccs;
  for(int i = v.clause_count() - 1; i >= 0; --i) {
    catch_clause *cc = &*v[i];
    TryCatchIterator::CatchClause rcc;
    rcc.node_names = cc->get_nametests();
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
  vector<TryCatchIterator::CatchClause> ccs(rev_ccs.rbegin(), rev_ccs.rend());
  PlanIter_t lChild = pop_itstack();
  push_itstack(new TryCatchIterator(sctx, qloc, lChild, ccs));
}

bool begin_visit (eval_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (eval_expr& v) {
  CODEGEN_TRACE_OUT("");
  checked_vector<PlanIter_t> argv;
  checked_vector<store::Item_t> varnames;
  checked_vector<string> var_keys;
  checked_vector<xqtref_t> vartypes;
  for (unsigned i = 0; i < v.var_count (); i++) {
    varnames.push_back (v.var_at (i).varname);
    var_keys.push_back (v.var_at (i).var_key);
    argv.push_back (pop_itstack ());
  }
  argv.push_back (pop_itstack ());
  reverse (argv.begin (), argv.end ());
  push_itstack (new EvalIterator (sctx, qloc, varnames, var_keys, vartypes, argv));
}

bool begin_visit (typeswitch_expr& v) {
  CODEGEN_TRACE_IN("");
  ZORBA_NOT_IMPLEMENTED ("typeswitch codegen");
  return true;
}

void end_visit (typeswitch_expr& v) {
  CODEGEN_TRACE_OUT("");
}


bool begin_visit (if_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit (if_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t iterElse = pop_itstack();
  PlanIter_t iterThen = pop_itstack();
  PlanIter_t iterCond = pop_itstack();
  PlanIter_t iterIfThenElse = new IfThenElseIterator(
    sctx, qloc, iterCond, iterThen, iterElse, v.is_updating());
  push_itstack(&*iterIfThenElse);
}


bool begin_visit (insert_expr& v) {
  CODEGEN_TRACE_IN("");

  expr_t targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(ccb->m_sctx);

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.EMPTY_TYPE))
    ZORBA_ERROR_LOC(XUDY0027, qloc);

  return true;
}

void end_visit (insert_expr& v) 
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lSource = pop_itstack();
  PlanIter_t lInsert = new InsertIterator(sctx, qloc, v.getType(), lSource, lTarget); 
  push_itstack(&*lInsert);
}


bool begin_visit (delete_expr& v) 
{
  CODEGEN_TRACE_IN("");

  return true;
}

void end_visit (delete_expr& v) 
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lDelete = new DeleteIterator(sctx, qloc, lTarget);
  push_itstack(&*lDelete);
}


bool begin_visit (replace_expr& v) 
{
  CODEGEN_TRACE_IN("");

  expr_t targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(ccb->m_sctx);

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.EMPTY_TYPE))
    ZORBA_ERROR_LOC(XUDY0027, qloc);

  return true;
}

void end_visit (replace_expr& v) 
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lReplacement = pop_itstack();
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lReplace = new ReplaceIterator(sctx,
                                            qloc,
                                            v.getType(),
                                            lTarget,
                                            lReplacement);
  push_itstack(&*lReplace);
}

bool begin_visit (rename_expr& v) 
{
  CODEGEN_TRACE_IN("");

  expr_t targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(ccb->m_sctx);

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.EMPTY_TYPE))
    ZORBA_ERROR_LOC(XUDY0027, qloc);

  return true;
}

void end_visit (rename_expr& v) 
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lName = pop_itstack();
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lRename = new RenameIterator(sctx, qloc, lTarget, lName);
  push_itstack(&*lRename);
}


bool begin_visit (transform_expr& v) 
{
  CODEGEN_TRACE_IN("");

  vector<rchandle<copy_clause> >::const_iterator lIter = v.begin();
  vector<rchandle<copy_clause> >::const_iterator lEnd  = v.end();
  for (; lIter != lEnd; ++lIter)
  {
    rchandle<var_expr> var = (*lIter)->getVar();
    expr_t sourceExpr = (*lIter)->getExpr();
    xqtref_t sourceType = sourceExpr->return_type(ccb->m_sctx);

    if (TypeOps::is_subtype(*sourceType, *GENV_TYPESYSTEM.ANY_SIMPLE_TYPE))
      ZORBA_ERROR_LOC(XUTY0013, qloc);

    uint64_t k = (uint64_t) &*var;
    copy_var_iter_map.put(k, new vector<ForVarIter_t>());
  }
  return true;
}

void end_visit (transform_expr& v) 
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
  for(; lIter != lEnd; ++lIter)
  {
    PlanIter_t lInput = pop_stack(lInputs);
    vector<ForVarIter_t>* lVarIters = 0;
    var_expr* lVar = (*lIter)->getVar();
    ZORBA_ASSERT(copy_var_iter_map.get((uint64_t)lVar, lVarIters));
    lClauses.push_back(CopyClause (*lVarIters, lInput));
  }

  TransformIterator* lTransform = new TransformIterator(sctx, qloc, lClauses, lModify, lReturn); 
  push_itstack(lTransform);
}


bool begin_visit (exit_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (exit_expr& v) {
  CODEGEN_TRACE_OUT("");
  checked_vector<PlanIter_t> argv;
  argv.push_back (pop_itstack ());
  push_itstack (new FlowCtlIterator (sctx, qloc, argv, FlowCtlIterator::EXIT));
}

bool begin_visit (flowctl_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (flowctl_expr& v) {
  CODEGEN_TRACE_OUT("");
  enum FlowCtlIterator::action a;
  switch (v.get_action ()) {
  case flowctl_expr::BREAK:
    a = FlowCtlIterator::BREAK;
    break;
  case flowctl_expr::CONTINUE:
    a = FlowCtlIterator::CONTINUE;
    break;
  default:
    ZORBA_FATAL(false, "");
  }
  checked_vector<PlanIter_t> argv;
  push_itstack (new FlowCtlIterator (sctx, qloc, argv, a));
}

bool begin_visit (while_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (while_expr& v) {
  CODEGEN_TRACE_OUT("");
  checked_vector<PlanIter_t> argv;
  argv.push_back (pop_itstack ());
  push_itstack (new LoopIterator (sctx, qloc, argv));
}


bool begin_visit (fo_expr& v) {
  CODEGEN_TRACE_IN ("");

  // If the function is an enclosed expression, push it in the constructors
  // stack to "hide" the current constructor context, if any. This way, a new
  // constructor context can be started if a node constructor exists inside
  // the enclosed expr.
  if (is_enclosed_expr(&v))
    theConstructorsStack.push(&v);

	return true;
}


void end_visit (fo_expr& v) 
{
  CODEGEN_TRACE_OUT("");

  const function* func = v.get_func();
  ZORBA_ASSERT (func != NULL);

  vector<PlanIter_t> argv (v.size ());
  generate (argv.rbegin (), argv.rend (), stack_to_generator (itstack));

  const QueryLoc& loc = qloc;

  if (func->validate_args (argv)) 
  {
    PlanIter_t iter = func->codegen (ccb, sctx, loc, argv, v);
    ZORBA_ASSERT(iter != NULL);
    push_itstack(iter);

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


bool begin_visit (ft_select_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

bool begin_visit (ft_contains_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

bool begin_visit (instanceof_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (instanceof_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t p = pop_itstack ();
  push_itstack (new InstanceOfIterator (sctx, qloc, p, v.get_target_type ()));
}

bool begin_visit (treat_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (treat_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t arg;
  arg = pop_itstack();
  push_itstack(new TreatIterator(sctx, qloc, arg, v.get_target_type(), v.get_check_prime(), v.get_err()));
}

bool begin_visit (castable_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (castable_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  push_itstack(new CastableIterator(sctx, qloc, lChild, v.get_target_type()));
}

bool begin_visit (cast_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (cast_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  push_itstack(new CastIterator(sctx, qloc, lChild, v.get_target_type()));
}

bool begin_visit (name_cast_expr& v) {
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

  ZORBA_ERROR_LOC(XPTY0004, qloc);

  return true;
}

void end_visit (name_cast_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  push_itstack(new NameCastIterator(sctx, qloc, lChild, v.getNamespaceContext()));
}


bool begin_visit (validate_expr& v) 
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (validate_expr& v) 
{
  CODEGEN_TRACE_OUT("");

#ifndef ZORBA_NO_XMLSCHEMA
  PlanIter_t lChild = pop_itstack();
  //store::Item_t typeName = v.get_type_name();
  //std::cout << "validate end-visit: type: " << typeName->getLocalName()->c_str() << " @ " << typeName->getNamespace()->c_str() << "\n"; cout.flush();
  push_itstack (new ValidateIterator (sctx,
                                      qloc,
                                      lChild,
                                      v.get_typemgr(),
                                      v.get_type_name(),
                                      v.get_valmode()));
#else
  //no schema support
  ZORBA_ERROR_LOC(XQST0009, qloc);
#endif
}


bool begin_visit (extension_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}


#ifdef PATH_ITERATOR

/*******************************************************************************

********************************************************************************/
bool begin_visit (relpath_expr& v) {
  CODEGEN_TRACE_IN("");

  //PlanIter_t input = pop_itstack();
  //ZORBA_ASSERT(input != NULL);
  //PlanIter_t pathIte(new PathIterator(qloc, input));
  //push_itstack(pathIte);

  return true;
}


void end_visit (relpath_expr& v) {
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool begin_visit (axis_step_expr& v) {
  CODEGEN_TRACE_IN("");

  store::ItemFactory& factory = *(GENV.getStore().getItemFactory());
  store::Item_t qname;

  PlanIter_t& ite = peek_stack(itstack);
  PathIterator* pathIte = dynamic_cast<PathIterator*>(ite.getp());

  if (pathIte == NULL) {
    PlanIter_t inputStep = pop_itstack();
    pathIte = new PathIterator(sctx, qloc, inputStep);
    push_itstack(pathIte);
  }
  //ZORBA_ASSERT(pathIte != NULL);

  rchandle<match_expr> testExpr = v.getTest();

  NodePredicate* prd = new NodePredicate();

  prd->setTestKind(testExpr->getTestKind());

  if (testExpr->getTestKind() == match_name_test) {
    if (v.getAxis() == axis_kind_attribute)
      prd->setNodeKind(store::StoreConsts::attributeNode);
    else
      prd->setNodeKind(store::StoreConsts::elementNode);

    match_wild_t wildKind = testExpr->getWildKind();
    prd->setWildKind(wildKind);

    if (wildKind == match_no_wild) {
      prd->setQName(testExpr->getQName());
    }
    else if (wildKind == match_prefix_wild) {
      factory.createQName(qname, "", "*", testExpr->getWildName().c_str());

      prd->setQName(qname);
    }
    else if (wildKind == match_name_wild) {
      prd->setQName(testExpr->getQName());
    }
  } else {
    prd->setDocTestKind(testExpr->getDocTestKind());
    prd->setNodeKind(testExpr->getNodeKind());
    prd->setQName(testExpr->getQName());
    store::Item *typeName = testExpr->getTypeName();
    if (typeName != NULL) {
      prd->setType(ccb->m_sctx->get_typemanager()->create_named_type(typeName));
    }
    prd->setNilledAllowed(testExpr->getNilledAllowed());
  }

  pathIte->addStep(v.getAxis(), prd);

  return true;
}


void end_visit (axis_step_expr& v) {
  CODEGEN_TRACE_OUT("");
}


bool begin_visit (match_expr& v) {
  CODEGEN_TRACE_IN("");

  return true;
}


void end_visit (match_expr& v) {
  CODEGEN_TRACE_OUT("");
}


#else

/*******************************************************************************

********************************************************************************/
bool begin_visit (relpath_expr& v) {
  CODEGEN_TRACE_IN("");
  // Done in axis itself
  return true;
}


void end_visit (relpath_expr& v) {
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool begin_visit (axis_step_expr& v) {
  CODEGEN_TRACE_IN("");

  bool result = true;

  PlanIter_t input = pop_itstack();

  ZORBA_ASSERT(input != NULL);

  PlanIter_t axisIte;

  switch (v.getAxis())
  {
  case axis_kind_self:
  {
    axisIte = new SelfAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_child:
  {
    axisIte = new ChildAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_parent:
  {
    axisIte = new ParentAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_descendant:
  {
    axisIte = new DescendantAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_descendant_or_self:
  {
    axisIte = new DescendantSelfAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_ancestor:
  {
    axisIte = new AncestorAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_ancestor_or_self:
  {
    axisIte = new AncestorSelfAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_following_sibling:
  {
    axisIte = new RSiblingAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_following:
  {
    axisIte = new FollowingAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_preceding_sibling:
  {
    axisIte = new LSiblingAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_preceding:
  {
    axisIte = new PrecedingAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_attribute:
  {
    if (v.getTest()->getTestKind() == match_name_test ||
        v.getTest()->getTestKind() == match_attr_test ||
        v.getTest()->getTestKind() == match_xs_attr_test ||
        v.getTest()->getTestKind() == match_anykind_test)
    {
      axisIte = new AttributeAxisIterator(sctx, qloc, input);
    }
    else
    {
      axisIte = new EmptyIterator(sctx, qloc);
      result = false;
    }

    break;
  }
  default:
    ZORBA_ASSERT (false && "Unknown axis kind");
  }

  push_itstack(axisIte);

  return result;
}


void end_visit (axis_step_expr& v) {
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool begin_visit (match_expr& v) 
{
  CODEGEN_TRACE_IN ("");

  PlanIter_t axisIte = pop_itstack();
  AxisIteratorHelper* axisItep = dynamic_cast<AxisIteratorHelper*>(axisIte.getp());
  ZORBA_ASSERT(axisItep != NULL);

  store::Item_t qname;

  store::ItemFactory& iFactory = *(GENV.getStore().getItemFactory());

  if (v.getTestKind() == match_name_test) 
  {
    match_wild_t wildKind = v.getWildKind();

    axisItep->setTestKind(match_name_test);
 
    if (dynamic_cast<AttributeAxisIterator*>(axisIte.getp()) != NULL)
      axisItep->setNodeKind(store::StoreConsts::attributeNode);
    else
      axisItep->setNodeKind(store::StoreConsts::elementNode);

    axisItep->setWildKind(wildKind);

    if (wildKind == match_no_wild) {
      axisItep->setQName(v.getQName());
    }
    else if (wildKind == match_prefix_wild) {
      iFactory.createQName(qname, "", "wildcard", v.getWildName().c_str());

      axisItep->setQName(qname);
    }
    else if (wildKind == match_name_wild) {
      axisItep->setQName(v.getQName());
    }
  }
  else 
  {
    axisItep->setTestKind(v.getTestKind());
    axisItep->setDocTestKind(v.getDocTestKind());
    axisItep->setNodeKind(v.getNodeKind());
    axisItep->setQName(v.getQName());
    store::Item *typeName = v.getTypeName();
    if (typeName != NULL) {
      axisItep->setType(ccb->m_sctx->get_typemanager()->create_named_type(typeName));
    }
    axisItep->setNilledAllowed(v.getNilledAllowed());
  }

  push_itstack(axisIte);
  return true;
}


void end_visit (match_expr& v) {
  CODEGEN_TRACE_OUT("");
}

#endif // PATH_ITER


/*******************************************************************************

  Node Constructors

********************************************************************************/

bool begin_visit (doc_expr& v) {
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(false);

  return true;
}


void end_visit (doc_expr& v) {
  CODEGEN_TRACE_OUT("");
  
  PlanIter_t lContent = pop_itstack();
  PlanIter_t lContIter = new DocumentContentIterator(sctx, qloc, lContent);
  PlanIter_t lDocIter = new DocumentIterator(sctx, qloc, lContIter);
  push_itstack(lDocIter);

  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e == &v);
}


bool begin_visit (elem_expr& v) {
  CODEGEN_TRACE_IN ("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(false);

  return true;
}


void end_visit (elem_expr& v) {
  CODEGEN_TRACE_OUT ("");

  PlanIter_t lQNameIter = 0;
  PlanIter_t lContentIter = 0;
  PlanIter_t lAttrsIter = 0;

  if ( v.getContent() != 0 )
    lContentIter = pop_itstack();

  if ( v.getAttrs() != 0 )
    lAttrsIter = pop_itstack();

  lQNameIter = pop_itstack();

  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e == &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top())) {
    isRoot = true;
  }

	PlanIter_t iter = new ElementIterator(sctx,
                                        qloc,
                                        lQNameIter,
                                        lAttrsIter,
                                        lContentIter,
                                        v.getNSCtx().getp(),
                                        isRoot);
  push_itstack(iter);
}


bool begin_visit (attr_expr& v) {
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(true);

	return true;
}


void end_visit (attr_expr& v) {
  CODEGEN_TRACE_OUT("");

  PlanIter_t lQNameIter = 0;
  PlanIter_t lVarIter = 0;
  PlanIter_t lContentIter = 0;
  
  if (v.getValueExpr() != 0) {
    lVarIter = pop_itstack();
  } else {
    lVarIter = new EmptyIterator(sctx, qloc);
  }
  
  PlanIter_t lAttrIter = 0;
  lQNameIter = pop_itstack();
  
  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top())) {
    isRoot = true;
  }

  lAttrIter = new AttributeIterator(sctx, qloc, lQNameIter, lVarIter, isRoot);
  
  push_itstack(lAttrIter);
}


bool begin_visit (text_expr& v) {
  CODEGEN_TRACE_IN ("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(true);

	return true;
}


void end_visit (text_expr& v) {
  CODEGEN_TRACE_OUT ("");

  PlanIter_t content = pop_itstack ();

  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top())) {
    isRoot = true;
  }

  switch (v.get_type ()) {
  case text_expr::text_constructor:
    push_itstack (new TextIterator(sctx, qloc, content, isRoot));
    break;

  case text_expr::comment_constructor:
    push_itstack (new CommentIterator (sctx, qloc, content, isRoot));
    break;

  default:
    break;
  }
}


bool begin_visit (pi_expr& v) {
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(true);

  return true;
}


void end_visit (pi_expr& v) {
  CODEGEN_TRACE_OUT("");

  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top())) {
    isRoot = true;
  }

  PlanIter_t content = pop_itstack ();
  PlanIter_t target = pop_itstack ();
  push_itstack (new PiIterator (sctx, qloc, target, content, isRoot));
}


bool begin_visit(function_def_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (function_def_expr &v) {
  CODEGEN_TRACE_OUT("");
}


bool begin_visit (const_expr& v) {
  CODEGEN_TRACE_IN ("");
  return true;
}

void end_visit (const_expr& v) {
  CODEGEN_TRACE_OUT("");
  PlanIter_t it = new SingletonIterator (sctx, qloc, v.get_val ());
  push_itstack (it);
}


bool begin_visit (order_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (order_expr& v) {
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************


********************************************************************************/

/*..........................................
 :  end visit                              :
 :.........................................*/

void end_visit (ft_select_expr& v) {
  CODEGEN_TRACE_OUT("");
}

void end_visit (ft_contains_expr& v) {
  CODEGEN_TRACE_OUT("");
}

void end_visit (extension_expr& v) {
  CODEGEN_TRACE_OUT("");
}

PlanIter_t result()
{
    PlanIter_t res = pop_itstack();
    ZORBA_ASSERT(itstack.empty());
    return res;
}


};



/*******************************************************************************

********************************************************************************/
PlanIter_t codegen(
    const char *descr,
    expr *root,
    CompilerCB *ccb,
    hash64map<vector<LetVarIter_t> *> *arg_var_map)
{
  plan_visitor c(ccb, arg_var_map);
  root->accept (c);
  PlanIter_t result = c.result();

  if (result != NULL && descr != NULL && Properties::instance()->printIteratorTree()
      && (xqp_string ("main query") == descr || ! Properties::instance()->iterPlanTest ()))
  {
    std::ostream &os = Properties::instance()->iterPlanTest ()
      ? std::cout
      : Properties::instance ()->debug_out ();

    os << "Iterator tree for " << descr << ":\n";
    XMLIterPrinter vp (os);
    print_iter_plan (vp, result);
    os << endl;
  }
	
  return result;
}

vector<PlanIter_t> plan_visitor::no_var_iters;


} /* namespace zorba */
