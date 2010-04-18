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
#include <list>
#include <stack>
#include <vector>

#include "zorbaerrors/Assert.h"

#include "util/tracer.h"
#include "util/stl_extra.h"
#include "util/hashmap32.h"

#include "system/globalenv.h"
#include "system/properties.h"

#include "compiler/api/compilercb.h"
#include "compiler/codegen/plan_visitor.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/ftexpr.h"
#include "compiler/expression/ftexpr_visitor.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/parser/parse_constants.h"

#include "context/namespace_context.h"
#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/dynamic_context.h"

#include "runtime/visitors/printer_visitor_api.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/constructors.h"
#include "runtime/core/apply_updates.h"
#include "runtime/core/path_iterators.h"
//#include "runtime/core/path.h"
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
#include "runtime/full_text/full_text.h"
#include "runtime/schema/schema.h"
#include "runtime/scripting/scripting.h"
#include "runtime/util/flowctl_exception.h"
#include "runtime/update/update.h"
#include "runtime/indexing/index_ddl.h"
#include "runtime/debug/zorba_debug_iterator.h"
#include "runtime/eval/eval.h"
#include "runtime/collections/collections.h"
#include "runtime/function_item/function_item.h"
#include "runtime/function_item/function_item_iter.h"
#include "runtime/function_item/dynamic_fncall_iterator.h"

#include "debugger/zorba_debugger_commons.h"

#include "functions/function.h"
#include "functions/library.h"

#include "types/typeops.h"

#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"


//#define XQUF_STATIC_TYPING_STRICT 1
#define XQUF_STATIC_TYPING_SAFE 1

#define QLOCDECL const QueryLoc &qloc = v.get_loc(); (void) qloc

#define SCTXDECL static_context* sctx = get_sctx(v.get_sctx_id()); (void)sctx;

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

/******************************************************************************

 ******************************************************************************/

class plan_ftexpr_visitor;

class plan_visitor : public expr_visitor
{
  friend class plan_ftexpr_visitor;
protected:
  static vector<PlanIter_t>              no_var_iters;

protected:
  uint32_t                               depth;

  stack<PlanIter_t>                      itstack;

  stack<expr*>                           theConstructorsStack;
  stack<bool>                            theAttrContentStack;

  hash64map<vector<LetVarIter_t> *>    * arg_var_iter_map;
  hash64map<vector<LetVarIter_t> *>      catchvar_iter_map;
  hash64map<vector<ForVarIter_t> *>      copy_var_iter_map;

  std::vector<FlworClauseVarMap_t>       theClauseStack;

  CompilerCB                           * theCCB;

  short                                  theLastSctxId;
  static_context                       * theLastSctx;

  std::stack<ZorbaDebugIterator*>        theDebuggerStack;

  plan_ftexpr_visitor                   *plan_ftexpr_visitor_;

public:

plan_visitor(CompilerCB*, hash64map<vector<LetVarIter_t>*>* = NULL);

~plan_visitor();

ftexpr_visitor& get_ftexpr_visitor();

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


static_context* get_sctx(short sctx)
{
  if (sctx != theLastSctxId)
  {
    theLastSctxId = sctx;
    theLastSctx = theCCB->getStaticContext(sctx);
  }

  return theLastSctx;
}


bool is_enclosed_expr(expr* e)
{
  fo_expr* foExpr = dynamic_cast<fo_expr*>(e);
  if (foExpr != NULL &&
      foExpr->get_func()->getKind() == FunctionConsts::OP_ENCLOSED_1)
    return true;

  return false;
}


bool begin_visit (expr& v) 
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (expr& v) 
{
  CODEGEN_TRACE_OUT("");
}


bool begin_visit (function_item_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(function_item_expr& v)
{
  CODEGEN_TRACE_OUT("");
  store::Item_t lQName = v.get_qname();
  store::Item_t lFItem;

  bool isInline = (lQName == 0);

  if (!isInline) 
  {
    // literal function item
    lFItem = new FunctionItem(theCCB, sctx, &v); 
  }
  else
  {
    // inline function
    vector<PlanIter_t> lVariableValues;
    size_t lSize = v.get_vars().size();
    for (size_t i = 0; i < lSize; ++i) 
    {
      lVariableValues.push_back(pop_itstack());
    }
    lFItem = new FunctionItem(theCCB, sctx, &v, lVariableValues);
  }

  push_itstack(new SingletonIterator (sctx, qloc, lFItem));
}


bool begin_visit(dynamic_function_invocation_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(dynamic_function_invocation_expr& v)
{
  CODEGEN_TRACE_OUT("");

  ulong numArgs = v.get_args().size() + 1;

  std::vector<PlanIter_t> argIters(numArgs);

  for (size_t i = 1; i < numArgs; ++i) 
  {
    argIters[i] = pop_itstack();
  }
  
  argIters[0] = pop_itstack();
  
  push_itstack(new DynamicFnCallIterator(sctx, qloc, argIters));
}


bool begin_visit (debugger_expr& v)
{
  CODEGEN_TRACE_IN("");

  // already create the debugger iterator here
  // because it's used for connecting all debugger
  // iterators in the tree (see end_visit below)
  std::vector<PlanIter_t> aTmpVec;
  theDebuggerStack.push(new ZorbaDebugIterator(sctx, qloc, aTmpVec));
  return true;
}

void end_visit (debugger_expr& v)
{
  CODEGEN_TRACE_OUT("");
  checked_vector<store::Item_t> varnames;
  checked_vector<string> var_keys;
  checked_vector<xqtref_t> vartypes;
  std::vector<PlanIter_t> argvEvalIter;
  std::vector<PlanIter_t> argv;
  for (unsigned i = 0; i < v.var_count (); i++)
  {
    varnames.push_back (v.var_at (i).varname);
    var_keys.push_back (v.var_at (i).var_key);
    vartypes.push_back (v.var_at (i).type);
    argvEvalIter.push_back (pop_itstack());
  }

  //create the eval iterator children
  argvEvalIter.push_back(new DebuggerSingletonIterator(sctx,
                                                       qloc,
                                                       theCCB->theDebuggerCommons->getEvalItem()));
  reverse (argvEvalIter.begin(), argvEvalIter.end());

  // get the debugger iterator from the debugger stack
  std::auto_ptr<ZorbaDebugIterator> aDebugIterator(theDebuggerStack.top());
  theDebuggerStack.pop();

  // set the child of the debugger iterator
  argv.push_back(pop_itstack ());
  argv.push_back(new EvalIterator(sctx, qloc, argvEvalIter, varnames, var_keys,
    vartypes));
  aDebugIterator->setChildren(&argv);

  aDebugIterator->setVariables(varnames, var_keys, vartypes);

  // link all debugger iterators in the tree
  if (!theDebuggerStack.empty()) {
    theDebuggerStack.top()->addChild(aDebugIterator.get());
    aDebugIterator->setParent(theDebuggerStack.top());
  }
  push_itstack(aDebugIterator.release());
}


bool begin_visit (wrapper_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (wrapper_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t iter = pop_itstack ();
  iter->setLocation (v.get_loc ());
  push_itstack(iter);
}


bool begin_visit(sequential_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(sequential_expr& v)
{
  CODEGEN_TRACE_OUT("");

  ulong numArgs = v.size();
  checked_vector<PlanIter_t> args(numArgs);

  for (long i = numArgs-1; i >= 0; --i)
  {
    PlanIter_t arg = pop_itstack();

    if (v[i]->is_updating())
      args[i] = new ApplyIterator(sctx, arg->loc, arg);
    else
      args[i] = arg;
  }

  push_itstack(new SequentialIterator(sctx, qloc, args));
}


/*******************************************************************************
  VarRef expr
********************************************************************************/

bool begin_visit(var_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(var_expr& v)
{
  CODEGEN_TRACE_OUT("");

  general_var_codegen(v);
}


template<class Iter>
PlanIter_t base_var_codegen(
    const var_expr& var,
    hash64map<vector<rchandle<Iter> > *>& varMap)
{
  vector<rchandle<Iter> >* varRefs = NULL;
  bool bound = varMap.get((uint64_t) &var, varRefs);
  ZORBA_ASSERT(bound);

  Iter* iter = new Iter(get_sctx(var.get_sctx_id()),
                        var.get_loc(),
                        var.get_name());

  varRefs->push_back(iter);

  return iter;
}


PlanIter_t create_var_iter(const var_expr& var, bool forvar)
{
  PlanIter_t iter;
  if (forvar)
  {
    iter = new ForVarIterator(get_sctx(var.get_sctx_id()),
                              var.get_loc(),
                              var.get_name());
  }
  else
  {
    iter = new LetVarIterator(get_sctx(var.get_sctx_id()),
                              var.get_loc(),
                              var.get_name());
  }
  return iter;
}


void general_var_codegen(const var_expr& var)
{
  const QueryLoc& qloc = var.get_loc();
  static_context* sctx = get_sctx(var.get_sctx_id());

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
    xqpString varname = var.get_name()->getStringValue().getp();
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
      expr_t lookup_expr = new fo_expr(var.get_sctx_id(),
                                       qloc,
                                       GET_BUILTIN_FUNCTION(OP_VAR_REF_1),
                                       new const_expr(var.get_sctx_id(),
                                                      qloc,
                                                      dynamic_context::var_key(&var)));
      lookup_expr->accept(*this);
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

  bool isGeneral = v.is_general();

  ulong numClauses = v.num_clauses();

  for (ulong i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = v[i];

    switch (c->get_kind())
    {

    case flwor_clause::for_clause:
    {
      visit_flwor_clause(c, isGeneral);

      const for_clause* fc = reinterpret_cast<const for_clause*>(c);
      fc->get_expr()->accept(*this);
      break;
    }

    case flwor_clause::let_clause:
    {
      visit_flwor_clause(c, isGeneral);

      const for_clause* fc = reinterpret_cast<const for_clause*>(c);
      fc->get_expr()->accept(*this);
      break;
    }

    case flwor_clause::window_clause:
    {
      visit_flwor_clause(c, isGeneral);

      const window_clause* wc = reinterpret_cast<const window_clause*>(c);

      flwor_wincond* startCond = wc->get_win_start();
      flwor_wincond* stopCond = wc->get_win_stop();

      if (startCond)
        startCond->get_cond()->accept(*this);

      if (stopCond)
        stopCond->get_cond()->accept(*this);

      wc->get_expr()->accept(*this);

      break;
    }

    case flwor_clause::group_clause:
    {
      const group_clause* gc = reinterpret_cast<const group_clause*>(c);

      const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
      const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();

      for (ulong i = 0; i < gvars.size(); ++i)
      {
        gvars[i].first->accept(*this);
      }

      for (ulong i = 0; i < ngvars.size(); ++i)
      {
        ngvars[i].first->accept(*this);
      }

      visit_flwor_clause(c, isGeneral);

      break;
    }

    case flwor_clause::order_clause:
    {
      const orderby_clause* oc = reinterpret_cast<const orderby_clause*>(c);

      ulong numCols = oc->num_columns();
      for (ulong i = 0; i < numCols; ++i)
      {
        oc->get_column_expr(i)->accept(*this);
      }

      visit_flwor_clause(c, isGeneral);

      break;
    }

    case flwor_clause::count_clause:
    {
      visit_flwor_clause(c, isGeneral);
      break;
    }

    case flwor_clause::where_clause:
    {
      const where_clause* wc = reinterpret_cast<const where_clause*>(c);
      wc->get_expr()->accept(*this);
      break;
    }
    default:
      ZORBA_ASSERT(false);
    }
  }

  v.get_return_expr(false)->accept(*this);

  // Do not visit the children of this flwor expr; this was done already by
  // this method
  return false;
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


bool nativeColumnSort(expr* colExpr)
{
  static_context* sctx = get_sctx(colExpr->get_sctx_id());
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t colType = colExpr->return_type(sctx);

  if (TypeOps::is_subtype(*colType, *rtm.STRING_TYPE_STAR) ||
      TypeOps::is_subtype(*colType, *rtm.DOUBLE_TYPE_STAR) ||
      TypeOps::is_subtype(*colType, *rtm.FLOAT_TYPE_STAR) ||
      TypeOps::is_subtype(*colType, *rtm.LONG_TYPE_STAR) ||
      TypeOps::is_subtype(*colType, *rtm.UNSIGNED_LONG_TYPE_STAR) ||
      TypeOps::is_equal(*TypeOps::prime_type(*colType), *rtm.DECIMAL_TYPE_ONE) ||
      TypeOps::is_equal(*TypeOps::prime_type(*colType), *rtm.INTEGER_TYPE_ONE) ||
      TypeOps::is_subtype(*colType, *rtm.DATE_TYPE_STAR) ||
      TypeOps::is_subtype(*colType, *rtm.TIME_TYPE_STAR) ||
      TypeOps::is_subtype(*colType, *rtm.DATETIME_TYPE_STAR))
    return true;

  return false;
}


PlanIter_t gflwor_codegen(flwor_expr& flworExpr, int currentClause)
{
#define PREV_ITER gflwor_codegen(flworExpr, currentClause - 1)

  const QueryLoc& qloc = flworExpr.get_loc();

  static_context* sctx = get_sctx(flworExpr.get_sctx_id());

  if (currentClause < 0)
  {
    return new flwor::TupleSourceIterator(sctx, qloc);
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
    PlanIter_t input = PREV_ITER;
    return new flwor::WhereIterator(sctx, c.get_loc(), input, where);
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
      return new flwor::ForIterator(sctx,
                                    var->get_loc(),
                                    var->get_name(),
                                    PREV_ITER,
                                    domainIter,
                                    varRefs,
                                    *posVarRefs);
    }
    else
    {
      ZORBA_ASSERT(fc->get_pos_var() == NULL);

      return new flwor::OuterForIterator(sctx,
                                         var->get_loc(),
                                         var->get_name(),
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

    return new flwor::LetIterator(sctx,
                                  var->get_loc(),
                                  var->get_name(),
                                  PREV_ITER,
                                  domainIter,
                                  varRefs,
                                  lc->lazyEval(),
                                  true);  // materilize
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

    return new flwor::WindowIterator(sctx,
                                     var->get_loc(),
                                     wc->get_winkind() == window_clause::tumbling_window ? flwor::WindowIterator::TUMBLING : flwor::WindowIterator::SLIDING,
                                     PREV_ITER,
                                     domainIter,
                                     var->get_name(),
                                     varRefs,
                                     *start_clause,
                                     *end_clause,
                                     wc->lazyEval());
  }

  //
  // COUNT
  //
  else if (c.get_kind() == flwor_clause::count_clause)
  {
    varref_t var = static_cast<const count_clause *>(&c)->get_var();

    ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

    vector<PlanIter_t>& var_iters = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

    return new flwor::CountIterator(sctx,
                                    var->get_loc(),
                                    var->get_name(),
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
    vector<vector<PlanIter_t> > outputForVarsRefs(numVars);
    vector<vector<PlanIter_t> > outputLetVarsRefs(numVars);

    for (ulong i = 0; i < numVars; ++i)
    {
      VarRebind* varRebind = clauseVarMap->theVarRebinds[i].getp();

      ForVarIterator* forIter = dynamic_cast<ForVarIterator*>
                                (varRebind->theInputVar.getp());

      if (forIter != NULL)
      {
        inputForVars[numForVars] = forIter;

        outputForVarsRefs[numForVars] = varRebind->theOutputVarRefs;
        ++numForVars;
      }
      else
      {
        LetVarIterator* letIter = dynamic_cast<LetVarIterator*>
                                (varRebind->theInputVar.getp());
        ZORBA_ASSERT(letIter != NULL);

        inputLetVars[numLetVars] = letIter;

        outputLetVarsRefs[numLetVars] = varRebind->theOutputVarRefs;
        ++numLetVars;
      }
    }

    inputForVars.resize(numForVars);
    outputForVarsRefs.resize(numForVars);
    inputLetVars.resize(numLetVars);
    outputLetVarsRefs.resize(numLetVars);

    const orderby_clause* obc = static_cast<const orderby_clause *>(&c);
    ulong numColumns = obc->num_columns();
    const std::vector<OrderModifier>& modifiers = obc->get_modifiers();

    std::vector<flwor::OrderSpec> orderSpecs(numColumns);

    for (long i = numColumns - 1; i >= 0; --i)
    {
      bool emptyLeast = modifiers[i].theEmptyLeast;
      bool descending = !modifiers[i].theAscending;

      orderSpecs[i] = flwor::OrderSpec(pop_itstack(),
                                       emptyLeast,
                                       descending,
                                       nativeColumnSort(obc->get_column_expr(i)),
                                       modifiers[i].theCollation);
    }

    return new flwor::OrderByIterator(sctx,
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
    vector<flwor::NonGroupingSpec> ngspecs;

    generate_groupby(clauseVarMap, gspecs, ngspecs);

    return new flwor::GroupByIterator(sctx, c.get_loc(), PREV_ITER, gspecs, ngspecs);
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
      const std::vector<OrderModifier>& modifiers = obc->get_modifiers();

      vector<flwor::OrderSpec> orderSpecs(numColumns);

      for (int i = numColumns - 1; i >= 0; --i)
      {
        bool emptyLeast = modifiers[i].theEmptyLeast;
        bool descending = !modifiers[i].theAscending;

        orderSpecs[i] = flwor::OrderSpec(pop_itstack(),
                                         emptyLeast,
                                         descending,
                                         nativeColumnSort(obc->get_column_expr(i)),
                                         modifiers[i].theCollation);
      }

      orderClause.reset(new flwor::OrderByClause(obc->get_loc(),
                                                 orderSpecs,
                                                 obc->is_stable()));
    }

    //
    // GROUPBY
    //
    else if (c.get_kind() == flwor_clause::group_clause)
    {
      vector<flwor::GroupingSpec> gspecs;
      vector<flwor::NonGroupingSpec> ngspecs;

      generate_groupby(clauseVarMap, gspecs, ngspecs);

      groupClause.reset(new flwor::GroupByClause(c.get_loc(), gspecs, ngspecs));
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

        forletClauses.push_back(flwor::ForLetClause(var->get_name(),
                                                    varRefs,
                                                    posVarRefs,
                                                    domainIter));
      }
      else
      {
        ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

        forletClauses.push_back(flwor::ForLetClause(var->get_name(),
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

      forletClauses.push_back(flwor::ForLetClause(var->get_name(),
                                                  varRefs,
                                                  domainIter,
                                                  lc->lazyEval(),
                                                  true)); // materialize
    }

    else
    {
      ZORBA_ASSERT(false);
    }
  }

  std::reverse(forletClauses.begin(), forletClauses.end());

  flworIter = new flwor::FLWORIterator(get_sctx(flworExpr.get_sctx_id()),
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
    vector<flwor::NonGroupingSpec>& ngspecs)
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

    ngspecs.push_back(flwor::NonGroupingSpec(pop_itstack(), varRefs));
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

bool begin_visit(promote_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (promote_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  // TODO: Currently we use cast. Promotion may be more efficient.
  push_itstack(new PromoteIterator(sctx, qloc, lChild, v.get_target_type()));
}


bool begin_visit(trycatch_expr& v)
{
  CODEGEN_TRACE_IN("");

  for(int i = v.clause_count() - 1; i >= 0; --i)
  {
    catch_clause* cc = &*v[i];
    if (cc->get_error_code_var() != NULL)
    {
      catchvar_iter_map.put((uint64_t)&*cc->get_error_code_var(), new vector<LetVarIter_t>());
    }
    if (cc->get_error_desc_var() != NULL)
    {
      catchvar_iter_map.put((uint64_t)&*cc->get_error_desc_var(), new vector<LetVarIter_t>());
    }
    if (cc->get_error_item_var() != NULL)
    {
      catchvar_iter_map.put((uint64_t)&*cc->get_error_item_var(), new vector<LetVarIter_t>());
    }
  }
  return true;
}

void end_visit(trycatch_expr& v)
{
  CODEGEN_TRACE_OUT("");
  vector<LetVarIter_t> *vec = NULL;
  vector<TryCatchIterator::CatchClause> rev_ccs;
  for(int i = v.clause_count() - 1; i >= 0; --i)
  {
    catch_clause* cc = &*v[i];
    TryCatchIterator::CatchClause rcc;
    rcc.node_names = cc->get_nametests();
    rcc.catch_expr = pop_itstack();
    if (cc->get_error_code_var() != NULL)
    {
      bool bound = catchvar_iter_map.get((uint64_t)&*cc->get_error_code_var(), vec);
      ZORBA_ASSERT(bound);
      rcc.errorcode_var = *vec;
    }
    if (cc->get_error_desc_var() != NULL)
    {
      bool bound = catchvar_iter_map.get((uint64_t)&*cc->get_error_desc_var(), vec);
      ZORBA_ASSERT(bound);
      rcc.errordesc_var = *vec;
    }
    if (cc->get_error_item_var() != NULL)
    {
      bool bound = catchvar_iter_map.get((uint64_t)&*cc->get_error_item_var(), vec);
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
  push_itstack (new EvalIterator (sctx, qloc, argv, varnames, var_keys, vartypes));
}


bool begin_visit (if_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit (if_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t iterElse = pop_itstack();
  PlanIter_t iterThen = pop_itstack();
  PlanIter_t iterCond = pop_itstack();
  PlanIter_t iterIfThenElse = new IfThenElseIterator(
    sctx, qloc, iterCond, iterThen, iterElse, v.is_updating());
  push_itstack(&*iterIfThenElse);
}


bool begin_visit (insert_expr& v)
{
  CODEGEN_TRACE_IN("");

  store::UpdateConsts::InsertType kind  = v.getType();

  const expr* targetExpr = v.getTargetExpr();
  const expr* sourceExpr = v.getSourceExpr();
  xqtref_t targetType = targetExpr->return_type(sctx);
  xqtref_t sourceType = sourceExpr->return_type(sctx);

  if (TypeOps::is_equal(*targetType, *GENV_TYPESYSTEM.EMPTY_TYPE))
    ZORBA_ERROR_LOC(XUDY0027, qloc);

#if XQUF_STATIC_TYPING_SAFE

  if (kind == store::UpdateConsts::INTO ||
      kind == store::UpdateConsts::AS_FIRST_INTO ||
      kind == store::UpdateConsts::AS_LAST_INTO)
  {
    if (TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.DOCUMENT_TYPE_STAR) &&
        TypeOps::is_subtype(*sourceType, *GENV_TYPESYSTEM.ATTRIBUTE_TYPE_STAR))
    {
      ZORBA_ERROR_LOC(XUTY0022, qloc);
    }

    if (TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ANY_SIMPLE_TYPE))
    {
      ZORBA_ERROR_LOC(XUTY0005, qloc);
    }

    if (TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ATTRIBUTE_TYPE_STAR) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.TEXT_TYPE_STAR) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.COMMENT_TYPE_STAR) ||
        TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.PI_TYPE_STAR))
    {
      ZORBA_ERROR_LOC(XUTY0005, qloc);
    }
  }
  else
  {
  }

#elif XQUF_STATIC_TYPING_STRICT

  if (kind == store::UpdateConsts::INTO ||
      kind == store::UpdateConsts::AS_FIRST_INTO ||
      kind == store::UpdateConsts::AS_LAST_INTO)
  {
    if (TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.DOCUMENT_TYPE_STAR) &&
        TypeOps::is_subtype(*sourceType, *GENV_TYPESYSTEM.ATTRIBUTE_TYPE_STAR))
    {
      ZORBA_ERROR_LOC(XUTY0022, qloc);
    }

    if (!TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.DOCUMENT_TYPE_STAR) &&
        !TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ELEMENT_TYPE_STAR))
    {
      ZORBA_ERROR_LOC(XUTY0005, qloc);
    }
  }
  else
  {
    if (!TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.ELEMENT_TYPE_STAR) &&
        !TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.TEXT_TYPE_STAR) &&
        !TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.COMMENT_TYPE_STAR) &&
        !TypeOps::is_subtype(*targetType, *GENV_TYPESYSTEM.PI_TYPE_STAR))
    {
      ZORBA_ERROR_LOC(XUTY0006, qloc);
    }
  }
#endif

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

  const expr* targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(sctx);

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

  const expr* targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->return_type(sctx);

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
    xqtref_t sourceType = sourceExpr->return_type(sctx);

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

  PlanIter_t returnIter = pop_itstack();
  PlanIter_t modifyIter = pop_itstack();

  vector<CopyClause> lClauses;
  stack<PlanIter_t> lInputs;
  size_t lSize = v.size();
  for (size_t i = 0; i < lSize; ++i)
  {
    lInputs.push(pop_itstack());
  }

  // Create a FOR var iterator into which the PUL produced by the modify
  // iterator will be bound.
  store::Item_t pulVarName;
  GENV_ITEMFACTORY->createQName(pulVarName, "", "", "pulHolder");
  PlanIter_t pulHolderIter = new ForVarIterator(sctx, modifyIter->loc, pulVarName);

  // Create an ApplyIterator to apply the above PUL
  PlanIter_t applyIter = new ApplyIterator(sctx, modifyIter->loc, pulHolderIter);

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

  TransformIterator* transformIter = new TransformIterator(sctx,
                                                           qloc,
                                                           lClauses,
                                                           modifyIter,
                                                           pulHolderIter,
                                                           applyIter,
                                                           returnIter);
  push_itstack(transformIter);
}


bool begin_visit (exit_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (exit_expr& v) {
  CODEGEN_TRACE_OUT("");
  checked_vector<PlanIter_t> argv;
  argv.push_back (pop_itstack ());
  push_itstack (new FlowCtlIterator (sctx, qloc, argv, FlowCtlException::EXIT));
}

bool begin_visit (flowctl_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (flowctl_expr& v) {
  CODEGEN_TRACE_OUT("");
  enum FlowCtlException::action a;
  switch (v.get_action ()) {
  case flowctl_expr::BREAK:
    a = FlowCtlException::BREAK;
    break;
  case flowctl_expr::CONTINUE:
    a = FlowCtlException::CONTINUE;
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


bool begin_visit (fo_expr& v)
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
  ZORBA_ASSERT(func != NULL);

  vector<PlanIter_t> argv(v.num_args());
  generate (argv.rbegin(), argv.rend(), stack_to_generator(itstack));

  const QueryLoc& loc = qloc;

  if (func->validate_args(argv))
  {
    if (func->getKind() == FunctionConsts::OP_CREATE_INTERNAL_INDEX_2)
    {
      const const_expr* qnameExpr = static_cast<const const_expr*>(v.get_arg(0));
      const store::Item* qname = qnameExpr->get_val();

      PlanIter_t buildIter = argv[1];

      PlanIter_t iter = new CreateInternalIndexIterator(sctx,
                                                        loc,
                                                        buildIter,
                                                        const_cast<store::Item*>(qname));
      push_itstack(iter);
    }
    else
    {
      PlanIter_t iter = func->codegen(theCCB, sctx, loc, argv, v);
      ZORBA_ASSERT(iter != NULL);
      push_itstack(iter);

      if (is_enclosed_expr(&v))
      {
        expr* e = pop_stack(theConstructorsStack);
        ZORBA_ASSERT(e == &v);

        if (!theAttrContentStack.empty() && theAttrContentStack.top() == true)
          dynamic_cast<EnclosedIterator*>(iter.getp())->setAttrContent();
      }
    }
  }
  else
  {
    ZORBA_ERROR_LOC_PARAM(XPST0017, loc,
                          func->get_signature().get_name()->getStringValue(),
                          argv.size());
  }
}


bool begin_visit(instanceof_expr& v)
{
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


bool begin_visit(name_cast_expr& v)
{
  CODEGEN_TRACE_IN("");

  const expr* targetExpr = v.get_input();
  xqtref_t targetType = targetExpr->return_type(sctx);

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

void end_visit(name_cast_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t child = pop_itstack();
  push_itstack(new NameCastIterator(sctx,
                                    qloc,
                                    child,
                                    v.get_namespace_context()));
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
  push_itstack (new ValidateIterator(sctx,
                                     qloc,
                                     lChild,
                                     v.get_valmode(),
                                     v.get_typemgr(),
                                     const_cast<store::Item*>(v.get_type_name())));
#else
  //no schema support
  ZORBA_ERROR_LOC(XQST0009, qloc);
#endif
}


bool begin_visit (extension_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (extension_expr& v)
{
  CODEGEN_TRACE_OUT("");
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
bool begin_visit (axis_step_expr& v)
{
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
      prd->setType(sctx->get_typemanager()->create_named_type(typeName));
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
    else if (wildKind == match_prefix_wild) 
    {
      iFactory.createQName(qname, "", "wildcard", v.getWildName()->c_str());

      axisItep->setQName(qname);
    }
    else if (wildKind == match_name_wild) 
    {
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
      axisItep->setType(sctx->get_typemanager()->create_named_type(typeName));
    }
    axisItep->setNilledAllowed(v.getNilledAllowed());
  }

  push_itstack(axisIte);
  return true;
}


void end_visit (match_expr& v) 
{
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


bool begin_visit(elem_expr& v)
{
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theAttrContentStack.push(false);

  return true;
}


void end_visit(elem_expr& v)
{
  CODEGEN_TRACE_OUT("");

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
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top()))
  {
    isRoot = true;
  }

	PlanIter_t iter = new ElementIterator(sctx,
                                        qloc,
                                        lQNameIter,
                                        lAttrsIter,
                                        lContentIter,
                                        v.getNSCtx(),
                                        isRoot);
  push_itstack(iter);
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

  PlanIter_t valueIter = 0;

  if (v.getValueExpr() != 0) 
  {
    valueIter = pop_itstack();
  }
  else
  {
    valueIter = new EmptyIterator(sctx, qloc);
  }

  PlanIter_t qnameIter;
  store::Item_t qname;
  const const_expr* qnameExpr = dynamic_cast<const const_expr*>(v.getQNameExpr());
  if (qnameExpr != NULL)
  {
    qname = qnameExpr->get_val();
    (void)pop_itstack();
  }
  else
  {
    qnameIter = pop_itstack();
  }

  bool isRoot = false;
  theAttrContentStack.pop();
  expr* e = pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);

  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top())) 
  {
    isRoot = true;
  }

  PlanIter_t attrIter = new AttributeIterator(sctx,
                                              qloc,
                                              qname,
                                              qnameIter,
                                              valueIter,
                                              isRoot);

  push_itstack(attrIter);
}


bool begin_visit(text_expr& v) 
{
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


void end_visit (pi_expr& v)
{
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
  push_itstack(new PiIterator(sctx, qloc, target, content, isRoot));
}


bool begin_visit (const_expr& v)
{
  CODEGEN_TRACE_IN ("");
  return true;
}

void end_visit (const_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t it = new SingletonIterator(sctx, qloc, v.get_val());
  push_itstack (it);
}


bool begin_visit (order_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit (order_expr& v)
{
  CODEGEN_TRACE_OUT("");
}

/******************************************************************************

 ******************************************************************************/

PlanIter_t result()
{
  PlanIter_t res = pop_itstack();
  ZORBA_ASSERT(itstack.empty());
  return res;
}

bool begin_visit (ftcontains_expr&);
void end_visit (ftcontains_expr&);

};


/******************************************************************************

 ******************************************************************************/

class plan_ftexpr_visitor : public ftexpr_visitor {
public:
  typedef list<PlanIter_t> PlanIter_list_t;

  plan_ftexpr_visitor( plan_visitor &v ) : plan_visitor_( v ) { }

  expr_visitor& get_expr_visitor();
  PlanIter_list_t& get_sub_iters() { return sub_iters_; }

protected:
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftand_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftextension_selection_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftmild_not_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftor_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftprimary_with_options_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftrange_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftselection_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftunary_not_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwords_expr );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwords_times_expr );

  // FTPosFilters
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftcontent_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftdistance_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftorder_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftscope_filter );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwindow_filter );

  // FTMatchOptions
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftcase_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftdiacritics_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftextension_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftlanguage_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftmatch_options );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstem_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstop_word_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftstop_words );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftthesaurus_id );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftthesaurus_option );
  DECL_FTEXPR_VISITOR_VISIT_MEM_FNS( ftwild_card_option );

private:
  plan_visitor &plan_visitor_;
  list<PlanIter_t> sub_iters_;
};

expr_visitor& plan_ftexpr_visitor::get_expr_visitor() {
  return plan_visitor_;
}

#define V plan_ftexpr_visitor

#define ACCEPT( EXPR, V )                   \
  if ( !(EXPR) ) ; else (EXPR)->accept( V )

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftand_expr )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftextension_selection_expr )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftmild_not_expr )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftor_expr )

ft_visit_result::type V::begin_visit( ftprimary_with_options_expr &e ) {
  ACCEPT( e.get_weight(), plan_visitor_ );
  PlanIter_t it = plan_visitor_.pop_itstack();
  ZORBA_ASSERT( plan_visitor_.itstack.empty() );
  e.set_plan_iter( it );
  sub_iters_.push_back( it );
  return ft_visit_result::no_end;
}
DEF_FTEXPR_VISITOR_END_VISIT( V, ftprimary_with_options_expr )

ft_visit_result::type V::begin_visit( ftrange_expr &e ) {
  PlanIter_t it2 = NULL;
  ACCEPT( e.get_expr1(), plan_visitor_ );
  if ( e.get_expr2() ) {
    e.get_expr2()->accept( plan_visitor_ );
    it2 = plan_visitor_.pop_itstack();
  }
  PlanIter_t it1 = plan_visitor_.pop_itstack();
  ZORBA_ASSERT( plan_visitor_.itstack.empty() );
  e.set_plan_iters( it1, it2 );
  sub_iters_.push_back( it1 );
  sub_iters_.push_back( it2 );
  return ft_visit_result::no_end;
}
DEF_FTEXPR_VISITOR_END_VISIT( V, ftrange_expr )

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftselection_expr )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftunary_not_expr )

ft_visit_result::type V::begin_visit( ftwords_expr &e ) {
  ACCEPT( e.get_expr(), plan_visitor_ );
  PlanIter_t it = plan_visitor_.pop_itstack();
  ZORBA_ASSERT( plan_visitor_.itstack.empty() );
  e.set_plan_iter( it );
  sub_iters_.push_back( it );
  return ft_visit_result::no_end;
}
DEF_FTEXPR_VISITOR_END_VISIT( V, ftwords_expr )

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftwords_times_expr )

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftcontent_filter )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftdistance_filter )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftorder_filter )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftscope_filter )

ft_visit_result::type V::begin_visit( ftwindow_filter &f ) {
  ACCEPT( f.get_window(), plan_visitor_ );
  PlanIter_t it = plan_visitor_.pop_itstack();
  ZORBA_ASSERT( plan_visitor_.itstack.empty() );
  f.set_plan_iter( it );
  sub_iters_.push_back( it );
  return ft_visit_result::no_end;
}
DEF_FTEXPR_VISITOR_END_VISIT( V, ftwindow_filter )

DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftcase_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftdiacritics_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftextension_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftlanguage_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftmatch_options )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstem_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstop_word_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftstop_words )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_id )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_option )
DEF_FTEXPR_VISITOR_VISIT_MEM_FNS( V, ftwild_card_option )

#undef V


/******************************************************************************

 ******************************************************************************/

plan_visitor::plan_visitor(
    CompilerCB* ccb,
    hash64map<vector<LetVarIter_t>*>* arg_var_map)
  :
  depth(0),
  arg_var_iter_map(arg_var_map),
  theCCB(ccb),
  theLastSctxId(-1),
  theLastSctx(NULL)
{
  plan_ftexpr_visitor_ = new plan_ftexpr_visitor( *this );
}


plan_visitor::~plan_visitor()
{
  for_each(
    catchvar_iter_map.begin(),
    catchvar_iter_map.end(),
    vector_destroyer<LetVarIter_t>()
  );
  for_each(
    copy_var_iter_map.begin(),
    copy_var_iter_map.end(),
    vector_destroyer<ForVarIter_t>()
  );
  delete plan_ftexpr_visitor_;
}


bool plan_visitor::begin_visit (ftcontains_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void plan_visitor::end_visit (ftcontains_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t ftignore_it = pop_itstack();
  PlanIter_t ftrange_it = pop_itstack();
  PlanIter_t ftcontains_it = new FTContainsIterator(
    sctx, qloc, ftrange_it, ftignore_it, v.get_ftselection(),
    plan_ftexpr_visitor_->get_sub_iters()
  );
  push_itstack( ftcontains_it );
}


ftexpr_visitor& plan_visitor::get_ftexpr_visitor() 
{
  return *plan_ftexpr_visitor_;
}


/******************************************************************************

 ******************************************************************************/

PlanIter_t codegen(
    const char* descr,
    expr* root,
    CompilerCB* ccb,
    hash64map<vector<LetVarIter_t> *>* arg_var_map)
{
  plan_visitor c(ccb, arg_var_map);
  root->accept(c);
  PlanIter_t result = c.result();

  if (root->is_updating())
  {
    result = new ApplyIterator(result->theSctx, result->loc, result);
  }

  if (result != NULL &&
      descr != NULL &&
      Properties::instance()->printIteratorTree() &&
      (xqp_string ("main query") == descr || ! Properties::instance()->iterPlanTest()))
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

} // namespace zorba
/* vim:set et sw=2 ts=2: */
