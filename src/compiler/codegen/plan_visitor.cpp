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

#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include <zorba/config.h>
#include <zorba/diagnostic_list.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/properties.h>

#include "diagnostics/assert.h"
#include "util/hashmap32.h"
#include "util/indent.h"
#include "util/stl_util.h"
#include "util/tracer.h"

#include "system/globalenv.h"

#include "compiler/expression/expr_manager.h"
#include "compiler/api/compilercb.h"
#include "compiler/codegen/plan_visitor.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/expr_visitor.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/json_exprs.h"
#include "compiler/expression/update_exprs.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#include "compiler/expression/ftnode_visitor.h"
#endif /* ZORBA_NO_FULL_TEXT */
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/var_expr.h"
#include "compiler/parser/parse_constants.h"

#include "context/namespace_context.h"
#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/dynamic_context.h"

#include "runtime/visitors/printer_visitor_api.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/sequences/SequencesImpl.h"
#include "runtime/sequences/sequences.h"
#include "runtime/core/sequencetypes.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/core/constructors.h"
#include "runtime/json/json_constructors.h"
#include "runtime/core/apply_updates.h"
#include "runtime/core/path_iterators.h"
#include "runtime/core/nodeid_iterators.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/trycatch.h"
#include "runtime/errors_and_diagnostics/other_diagnostics.h"
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
#ifdef ZORBA_WITH_DEBUGGER
#include "runtime/debug/debug_iterator.h"
#endif
#include "runtime/eval/eval.h"
#include "runtime/hof/function_item.h"
#include "runtime/hof/function_item_iter.h"
#include "runtime/hof/fn_hof_functions.h"
#include "runtime/hof/dynamic_fncall_iterator.h"
#include "runtime/misc/materialize.h"

#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_commons.h"
#endif

#include "functions/function.h"
#include "functions/udf.h"
#include "functions/external_function.h"
#include "functions/library.h"

#include "types/typeops.h"

#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"

#include <zorba/util/debug.h>


//#define XQUF_STATIC_TYPING_STRICT 1
#define XQUF_STATIC_TYPING_SAFE 1

#define QLOCDECL const QueryLoc& qloc = v.get_loc(); (void) qloc

#define SCTXDECL static_context* sctx = v.get_sctx(); (void)sctx;

#ifndef NDEBUG

#define CODEGEN_TRACE(msg)                                         \
  QLOCDECL;                                                        \
  SCTXDECL;                                                        \
  if (Properties::instance().getTraceCodegen())                    \
  {                                                                \
    std::cout << (msg) << TRACE << ", stk size " << itstack.size() \
              << std::endl << std::endl;                           \
    v.put(std::cout);                                              \
    std::cout << "StackTop:" << std::endl;                         \
    print_stack();                                                 \
  }

#define CODEGEN_TRACE_IN(msg)  \
  CODEGEN_TRACE(std::string(++theDepth, ' ') + msg)

#define CODEGEN_TRACE_OUT(msg) \
  CODEGEN_TRACE(std::string(theDepth--, ' ') + msg)

#else
#define CODEGEN_TRACE(msg) QLOCDECL; SCTXDECL;
#define CODEGEN_TRACE_IN(msg) CODEGEN_TRACE(msg)
#define CODEGEN_TRACE_OUT(msg) CODEGEN_TRACE(msg)
#endif

using namespace std;

namespace zorba
{

class plan_visitor;


typedef rchandle<ForVarIterator> ForVarIter_t;
typedef rchandle<LetVarIterator> LetVarIter_t;


#define ITEM_FACTORY (GENV.getStore().getItemFactory())

namespace plan_visitor_ns
{

template <typename T> T pop_stack(std::stack<T> &stk)
{
  assert (! stk.empty ());
  T x = stk.top ();
  stk.pop ();
  return x;
}

template<class T> T& peek_stack(std::stack<T> &stk)
{
  ZORBA_ASSERT (! stk.empty ());
  return stk.top ();
}

} // namespace plan_visitor_ns


template <typename V>
struct vector_destroyer
{
  void operator()(const struct hash64map<std::vector<V> *>::entry& entry)
  {
    delete (const_cast<struct hash64map<std::vector<V> *>::entry&>(entry)).val;
  }
};


/*******************************************************************************

********************************************************************************/
class VarRebind : public SimpleRCObject
{
public:
  PlanIter_t               theInputVar;
  std::vector<PlanIter_t>  theOutputVarRefs;
  bool                     theIsFakeLetVar;
  bool                     theIsSingleItemLetVar;

public:
  VarRebind() : theIsFakeLetVar(false), theIsSingleItemLetVar(false) {}
};


typedef rchandle<VarRebind> VarRebind_t;


/*******************************************************************************
  A FlworClauseVarMap is created for each flwor clause that defines variables.
  If M is such a clause, then for each variable Vi defined by M, theVarExprs[i]
  and theVarRebinds[i] contain an entry for Vi. theVarExprs[i] contains the
  var_expr representing the Vi definition.
********************************************************************************/
class FlworClauseVarMap : public SimpleRCObject
{
public:
  bool                          theIsGeneral;
  const flwor_clause          * theClause;

  std::vector<var_expr*>        theVarExprs;
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
    csize numVars = theVarExprs.size();
    for (csize i = 0; i < numVars; ++i)
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

#ifndef ZORBA_NO_FULL_TEXT

class plan_ftnode_visitor : public ftnode_visitor
{
public:
  typedef std::vector<PlanIter_t> PlanIter_list_t;

  plan_ftnode_visitor( plan_visitor* v ) : plan_visitor_( v ) { }

  expr_visitor* get_expr_visitor();

  PlanIter_list_t& get_sub_iters() { return sub_iters_; }

protected:
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftand );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftextension_selection );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftmild_not );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftor );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftprimary_with_options );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftrange );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftselection );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftunary_not );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftweight );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftwords );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftwords_times );

  // FTPosFilters
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftcontent_filter );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftdistance_filter );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftorder_filter );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftscope_filter );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftwindow_filter );

  // FTMatchOptions
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftcase_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftdiacritics_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftextension_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftlanguage_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftmatch_options );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftstem_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftstop_word_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftstop_words );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftthesaurus_id );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftthesaurus_option );
  DECL_FTNODE_VISITOR_VISIT_MEM_FNS( ftwild_card_option );

private:
  plan_visitor   * plan_visitor_;
  PlanIter_list_t  sub_iters_;
};

#endif /* ZORBA_NO_FULL_TEXT */


/******************************************************************************

*******************************************************************************/
class plan_visitor : public expr_visitor
{
#ifndef ZORBA_NO_FULL_TEXT
  friend class plan_ftnode_visitor;
#endif /* ZORBA_NO_FULL_TEXT */

  typedef enum
  {
    ELEMENT_CONTENT = 0,
    ATTRIBUTE_CONTENT,
    TEXT_CONTENT,
    UPDATE_CONTEXT
  } EnclosedExprContext;

protected:
  static std::vector<PlanIter_t>             no_var_iters;

protected:
  uint32_t                                   theDepth;

  std::stack<PlanIter_t>                     itstack;

  std::stack<expr*>                          theConstructorsStack;
  std::stack<EnclosedExprContext>            theEnclosedContextStack;
  std::stack<bool>                           theCopyNodesStack;

  ulong                                      theNextDynamicVarId;

  hash64map<std::vector<LetVarIter_t> *>   * arg_var_iter_map;
  hash64map<std::vector<LetVarIter_t> *>     catchvar_iter_map;
  hash64map<std::vector<ForVarIter_t> *>     copy_var_iter_map;

  std::vector<FlworClauseVarMap_t>           theClauseStack;

  CompilerCB                               * theCCB;

#ifdef ZORBA_WITH_DEBUGGER
  std::stack<DebugIterator*>                 theDebuggerStack;
#endif

#ifndef ZORBA_NO_FULL_TEXT
  plan_ftnode_visitor                      * plan_ftnode_visitor_;
#endif /* ZORBA_NO_FULL_TEXT */

public:

plan_visitor(
    CompilerCB* ccb,
    ulong nextDynamicVarId,
    hash64map<std::vector<LetVarIter_t>*>* arg_var_map = NULL)
  :
  theDepth(0),
  theNextDynamicVarId(nextDynamicVarId),
  arg_var_iter_map(arg_var_map),
  theCCB(ccb)
{
#ifndef ZORBA_NO_FULL_TEXT
  plan_ftnode_visitor_ = new plan_ftnode_visitor( this );
#endif /* ZORBA_NO_FULL_TEXT */
}


~plan_visitor()
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
#ifndef ZORBA_NO_FULL_TEXT
  delete plan_ftnode_visitor_;
#endif /* ZORBA_NO_FULL_TEXT */
}


ulong getNextDynamicVarId() const
{
  return theNextDynamicVarId;
}


#ifndef ZORBA_NO_FULL_TEXT
ftnode_visitor* get_ftnode_visitor()
{
  return plan_ftnode_visitor_;
}
#endif /* ZORBA_NO_FULL_TEXT */


PlanIter_t pop_itstack()
{
  return plan_visitor_ns::pop_stack(itstack);
}


void push_itstack(PlanIterator* iter)
{
  itstack.push(iter);
}


void print_stack()
{
  if (itstack.empty())
  {
    std::cout << "EMPTY" << std::endl;
  }
  else
  {
    XMLIterPrinter vp(std::cout);
    print_iter_plan(vp, plan_visitor_ns::peek_stack(itstack));
  }
}


bool is_enclosed_expr(expr* e)
{
  fo_expr* foExpr = dynamic_cast<fo_expr*>(e);
  if (foExpr != NULL &&
      foExpr->get_func()->getKind() == FunctionConsts::OP_ENCLOSED_1)
    return true;

  return false;
}


bool begin_visit(expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(expr& v)
{
  CODEGEN_TRACE_OUT("");
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(function_item_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(function_item_expr& v)
{
  CODEGEN_TRACE_OUT("");

  FunctionItemInfo* fnInfo = v.get_fi_info();
  fnInfo->theCCB = theCCB;
  fnInfo->theLoc = qloc;

  csize numOuterVars = v.get_in_scope_vars().size();

  for (csize i = 0; i < numOuterVars; ++i)
  {      
    fnInfo->theInScopeVarIterators.push_back(pop_itstack());
  }
  
  std::reverse(fnInfo->theInScopeVarIterators.begin(),
               fnInfo->theInScopeVarIterators.end());

  
  for (csize i = 0; i < numOuterVars; ++i)
  {
    fnInfo->theInScopeVars[i]->set_var_info(NULL);

    if (fnInfo->theInScopeVars[i]->get_unique_id() != 0)
    {
      ZORBA_ASSERT(fnInfo->theInScopeVars[i]->get_unique_id() == i+1);
    }
    else
    {
      fnInfo->theInScopeVars[i]->set_unique_id(i+1);
    }

    fnInfo->theInScopeVarIds[i] = fnInfo->theInScopeVars[i]->get_unique_id();
  }

  push_itstack(new FunctionItemIterator(sctx, qloc, fnInfo));
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(dynamic_function_invocation_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(dynamic_function_invocation_expr& v)
{
  CODEGEN_TRACE_OUT("");

  csize numArgs = v.get_args().size();

  std::vector<PlanIter_t> argIters;
  
  bool isPartialApply = false;
  
  for (csize i = 0; i < numArgs; ++i)
  {
    if (v.get_args()[i]->get_expr_kind() == argument_placeholder_expr_kind)
      isPartialApply = true;

    argIters.push_back(pop_itstack());
  }

  argIters.push_back(pop_itstack());

  std::reverse(argIters.begin(), argIters.end());

  if (numArgs > 0 || v.get_input()->get_return_type()->max_card() <= 1)
    push_itstack(new SingleDynamicFnCallIterator(sctx, qloc, argIters, isPartialApply));
  else
    push_itstack(new MultiDynamicFnCallIterator(sctx, qloc, argIters[0]));
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(argument_placeholder_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(argument_placeholder_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t it = new ArgumentPlaceholderIterator(sctx, qloc);
  push_itstack(it);
}

/***************************************************************************//**

********************************************************************************/
bool begin_visit(function_trace_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(function_trace_expr& v)
{
  CODEGEN_TRACE_OUT("");
  std::vector<PlanIter_t> argv;
  argv.push_back(pop_itstack());
  std::unique_ptr<FunctionTraceIterator> lDummyIter(
      new FunctionTraceIterator(sctx, qloc, argv));
  lDummyIter->setFunctionName(v.getFunctionName());
  lDummyIter->setFunctionArity(v.getFunctionArity());
  lDummyIter->setFunctionLocation(v.getFunctionLocation());
  lDummyIter->setFunctionCallLocation(v.getFunctionCallLocation());
  push_itstack(lDummyIter.get());
  lDummyIter.release();
}

bool begin_visit(wrapper_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(wrapper_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t iter = pop_itstack();
  iter->setLocation (v.get_loc());
  push_itstack(iter);
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(block_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(block_expr& v)
{
  CODEGEN_TRACE_OUT("");

  ulong numArgs = v.size();
  checked_vector<PlanIter_t> args(numArgs);

  for (ulong i = numArgs; i > 0; --i)
  {
    PlanIter_t arg = pop_itstack();
    args[i-1] = arg;
  }

  push_itstack(new SequentialIterator(sctx, qloc, args));
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(apply_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(apply_expr& v)
{
  CODEGEN_TRACE_OUT("");

  PlanIter_t arg = pop_itstack();

  push_itstack(new ApplyIterator(sctx, qloc, v.discardsXDM(), arg));
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(var_decl_expr& v)
{
  CODEGEN_TRACE_IN("");

  var_expr* varExpr = v.get_var_expr();
  if (varExpr->get_unique_id() == 0)
    varExpr->set_unique_id(theNextDynamicVarId++);

  return true;
}

void end_visit(var_decl_expr& v)
{
  CODEGEN_TRACE_OUT("");

  var_expr* varExpr = v.get_var_expr();
  expr* initExpr = v.get_init_expr();

  checked_vector<PlanIter_t> args;
  bool singleItem = false;

  if (initExpr != NULL)
  {
    args.push_back(pop_itstack());

    xqtref_t exprType = initExpr->get_return_type();

    if (exprType->get_quantifier() == SequenceType::QUANT_ONE)
      singleItem = true;
  }

  push_itstack(new CtxVarDeclareIterator(sctx,
                                         qloc,
                                         args,
                                         varExpr->get_unique_id(),
                                         varExpr->get_name(),
                                         varExpr->is_external(),
                                         varExpr->get_kind() == var_expr::local_var,
                                         singleItem));
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(var_set_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(var_set_expr& v)
{
  CODEGEN_TRACE_OUT("");

  const var_expr* varExpr = v.get_var_expr();

  xqtref_t exprType = v.get_expr()->get_return_type();

  PlanIter_t exprIter = pop_itstack();

  CtxVarAssignIterator* iter =
  new CtxVarAssignIterator(sctx,
                           qloc,
                           varExpr->get_unique_id(),
                           varExpr->get_name(),
                           (varExpr->get_kind() == var_expr::local_var),
                           exprIter);

  if (exprType->get_quantifier() == SequenceType::QUANT_ONE)
    iter->setSingleItem();

  push_itstack(iter);
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
    hash64map<std::vector<rchandle<Iter> > *>& varMap)
{
  std::vector<rchandle<Iter> >* varRefs = NULL;
  bool bound = varMap.get((uint64_t) &var, varRefs);
  ZORBA_ASSERT(bound);

  Iter* iter = new Iter(var.get_sctx(), var.get_loc(), var.get_name());

  varRefs->push_back(iter);

  return iter;
}


PlanIter_t create_var_iter(const var_expr& var, bool forvar, bool singleItemLetVar)
{
  PlanIter_t iter;
  if (forvar)
  {
    iter = new ForVarIterator(var.get_sctx(), var.get_loc(), var.get_name());
  }
  else
  {
    iter = new LetVarIterator(var.get_sctx(), var.get_loc(), var.get_name());
    
    if (singleItemLetVar)
      static_cast<LetVarIterator*>(iter.getp())->setSingleItem();
  }
  return iter;
}


void general_var_codegen(const var_expr& var)
{
  const QueryLoc& qloc = var.get_loc();
  static_context* sctx = var.get_sctx();

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

    long stackSize = (long)theClauseStack.size();
    long varPos;
    VarRebind_t varRebind;
    PlanIter_t varIter;

    // Look for the inner-most clause C that knows about this variable. C is
    // either the clause D_C that defines the var, or the inner-most orderby
    // or materialize clause the comes after D_C and rebinds the var to its
    // output.
    long i = stackSize - 1;
    while (true)
    {
      if ((varPos = theClauseStack[i]->find_var(&var)) >= 0)
        break;

      --i;
      ZORBA_ASSERT(i >= 0);
    }

    FlworClauseVarMap* clauseVarMap = theClauseStack[i];
    flwor_expr* flworExpr = clauseVarMap->theClause->get_flwor_expr();
    bool fakeLetVar = clauseVarMap->theVarRebinds[varPos]->theIsFakeLetVar;
    bool singleItemLetVar = clauseVarMap->theVarRebinds[varPos]->theIsSingleItemLetVar;

    if (fakeLetVar)
      isForVar = true;

    // Create a var ref iter in the output of C.
    varIter = create_var_iter(var, isForVar, singleItemLetVar);

    clauseVarMap->theVarRebinds[varPos]->theOutputVarRefs.push_back(varIter);

    if (clauseVarMap->theIsGeneral || flworExpr->is_sequential())
    {
      // For each orderby or materialize clause O after C, bind the var iter
      // created by the previous clause to the input of O, and then create a new
      // var iter and put it to the output of O.
      for (++i; i < stackSize; ++i)
      {
        clauseVarMap = theClauseStack[i];

        ZORBA_ASSERT(clauseVarMap->find_var(&var) < 0);

        if (flworExpr == clauseVarMap->theClause->get_flwor_expr() &&
            ((clauseVarMap->theClause->get_kind() == flwor_clause::orderby_clause &&
              flworExpr->is_general()) ||
             clauseVarMap->theClause->get_kind() == flwor_clause::materialize_clause))
        {
          varRebind = new VarRebind;

          clauseVarMap->theVarExprs.push_back(const_cast<var_expr*>(&var));
          clauseVarMap->theVarRebinds.push_back(varRebind);

          varRebind->theInputVar = varIter;
          varRebind->theIsFakeLetVar = fakeLetVar;
          //varRebind->theIsSingleItemLetVar = singleItemLetVar;

          varIter = create_var_iter(var, isForVar, varRebind->theIsSingleItemLetVar);

          varRebind->theOutputVarRefs.push_back(varIter);
        }
      }
    }

    push_itstack(varIter);
    break;
  }

  case var_expr::arg_var:
  {
    ZORBA_ASSERT(arg_var_iter_map != NULL);
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
  {
    push_itstack(new CtxVarIterator(sctx,
                                    qloc,
                                    var.get_unique_id(),
                                    var.get_name(),
                                    false));
    break;
  }
  case var_expr::local_var:
  {
    push_itstack(new CtxVarIterator(sctx,
                                    qloc,
                                    var.get_unique_id(),
                                    var.get_name(),
                                    true));
    break;
  }

  case var_expr::unknown_var:
  case var_expr::eval_var:
  case var_expr::score_var:
  {
    ZORBA_ASSERT(false);
    break;
  }
  }
}


/*******************************************************************************
  FLWOR expr
********************************************************************************/
bool begin_visit(flwor_expr& v)
{
  CODEGEN_TRACE_IN("");

  csize numClauses = v.num_clauses();

  bool isGeneral = v.compute_is_general();

  v.set_general(isGeneral);
    
  if (v.is_sequential())
  {
    pragma* pr = 0;
    theCCB->lookup_pragma(&v, "no-materialization", pr);

    if (!isGeneral)
    {
      if (v.has_sequential_clauses())
      {
        csize numForClauses = 0;

        for (csize i = 0; i < numClauses; ++i)
        {
          const flwor_clause* c = v.get_clause(i);

          if (c->get_kind() == flwor_clause::for_clause)
          {
            ++numForClauses;

            const forlet_clause* fc = static_cast<const forlet_clause*>(c);

            if (fc->get_expr()->is_sequential())
            {
              // TODO: do not convert to general flwor if the whole flwor consists
              // of a single FOR followed by RETURN.
              isGeneral = true;
              v.set_general(true);
              break;
            }
          }
          else if (c->get_kind() == flwor_clause::let_clause)
          {
            const forlet_clause* lc = static_cast<const forlet_clause*>(c);

            if (lc->get_expr()->is_sequential())
            {
              if (numForClauses > 0)
              {
                isGeneral = true;
                v.set_general(true);
                break;
              }
            }
          }
          else
          {
            break;
          }
        }
      }

      // Note: a materialize clause may exist already in case plan serialization
      // is on (see comment in materialize_clause::clone)
      if (!pr && !isGeneral &&
          v.get_return_expr()->is_sequential() &&
          v.get_clause(numClauses-1)->get_kind() != flwor_clause::materialize_clause &&
          (v.get_order_clause() != NULL || v.get_group_clause() == NULL))
      {
        materialize_clause* mat = theCCB->theEM->create_materialize_clause(v.get_sctx(),
                                                 v.get_return_expr()->get_loc());
        v.add_clause(mat);
        ++numClauses;
      }
    } // !isGeneral

    if (isGeneral)
    {
      static_context* sctx = v.get_sctx();
      std::vector<OrderModifier> modifiers;
      std::vector<expr*> orderingExprs;

      csize numForClauses = 0;
      csize i = 0;

      while (i < numClauses)
      {
        const flwor_clause* c = v.get_clause(i);
        flwor_clause::ClauseKind k = c->get_kind();

        switch (k)
        {
        case flwor_clause::for_clause:
        case flwor_clause::let_clause:
        case flwor_clause::window_clause:
        {
          expr* domExpr = static_cast<const forletwin_clause*>(c)->get_expr();

          if (k == flwor_clause::for_clause || k == flwor_clause::window_clause)
          {
            xqtref_t domainType = domExpr->get_return_type();

            if (domainType->get_quantifier() != SequenceType::QUANT_ONE)
              ++numForClauses;
          }

          if (!pr && domExpr->is_sequential() &&
              (k == flwor_clause::for_clause ||
               k == flwor_clause::window_clause ||
               numForClauses > 0))
          {
            if (i > 0 &&
                v.get_clause(i-1)->get_kind() != flwor_clause::orderby_clause &&
                v.get_clause(i-1)->get_kind() != flwor_clause::groupby_clause)
            {
              orderby_clause* mat = theCCB->theEM->
              create_orderby_clause(sctx, c->get_loc(), true, modifiers, orderingExprs);

              v.add_clause(i, mat);
              ++i;
              ++numClauses;
            }

            if (i == numClauses -1 ||
                (i < numClauses - 1 &&
                 v.get_clause(i+1)->get_kind() != flwor_clause::groupby_clause))
            {
              orderby_clause* mat = theCCB->theEM->
              create_orderby_clause(sctx, c->get_loc(), true, modifiers, orderingExprs);

              v.add_clause(i+1, mat);
              ++numClauses;
            }
          }

          break;
        }
        case flwor_clause::where_clause:
        case flwor_clause::groupby_clause:
        case flwor_clause::orderby_clause:
        case flwor_clause::count_clause:
        {
          break;
        }
        default:
          ZORBA_ASSERT_WITH_MSG(false, "ClauseKind = " << k);
        } // switch

        ++i;
      }

      const flwor_clause* lastClause = v.get_clause(v.num_clauses()-1);

      if (v.get_return_expr()->is_sequential() &&
          lastClause->get_kind() != flwor_clause::orderby_clause &&
          lastClause->get_kind() != flwor_clause::groupby_clause)
      {
        orderby_clause* mat = theCCB->theEM->
        create_orderby_clause(sctx,
                              v.get_return_expr()->get_loc(),
                              true,
                              modifiers,
                              orderingExprs);

        v.add_clause(mat);
        ++numClauses;
      }
    }
  }

  for (csize i = 0; i < numClauses; ++i)
  {
    const flwor_clause* c = v.get_clause(i);

    switch (c->get_kind())
    {

    case flwor_clause::for_clause:
    case flwor_clause::let_clause:
    {
      visit_flwor_clause(c, isGeneral);

      const forlet_clause* flc = reinterpret_cast<const forlet_clause*>(c);
      flc->get_expr()->accept(*this);
      break;
    }

    case flwor_clause::window_clause:
    {
      visit_flwor_clause(c, isGeneral);

      const window_clause* wc = reinterpret_cast<const window_clause*>(c);

      flwor_wincond* startCond = wc->get_win_start();
      flwor_wincond* stopCond = wc->get_win_stop();

      if (startCond)
        startCond->get_expr()->accept(*this);

      if (stopCond)
        stopCond->get_expr()->accept(*this);

      wc->get_expr()->accept(*this);

      break;
    }

    case flwor_clause::groupby_clause:
    {
      const groupby_clause* gc = reinterpret_cast<const groupby_clause*>(c);

      const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
      const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();

      for (csize i = 0; i < gvars.size(); ++i)
      {
        gvars[i].first->accept(*this);
      }

      for (csize i = 0; i < ngvars.size(); ++i)
      {
        ngvars[i].first->accept(*this);
      }

      visit_flwor_clause(c, isGeneral);

      break;
    }

    case flwor_clause::orderby_clause:
    {
      const orderby_clause* oc = reinterpret_cast<const orderby_clause*>(c);

      csize numCols = oc->num_columns();
      for (csize i = 0; i < numCols; ++i)
      {
        oc->get_column_expr(i)->accept(*this);
      }

      visit_flwor_clause(c, isGeneral);

      break;
    }

    case flwor_clause::materialize_clause:
    {
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

  v.get_return_expr()->accept(*this);

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
    xqtref_t domType = lc->get_expr()->get_return_type();

    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(lc->get_var());
    clauseVarMap->theVarRebinds.push_back(varRebind);

    if (domType->get_quantifier() == SequenceType::QUANT_ONE)
    {
      //std::cout << "Setting isfakeletvar for " << varRebind->theInputVar->getNameAsString() << std::endl;
      //varRebind->theIsFakeLetVar = true;
    }
    else if (domType->get_quantifier() == SequenceType::QUANT_QUESTION)
    {
    	//std::cout << "Setting issingleitemletvar for " << varRebind->theInputVar->getNameAsString() << std::endl;
      varRebind->theIsSingleItemLetVar = true;
    }

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

  case flwor_clause::groupby_clause:
  {
    const groupby_clause* gbc = static_cast<const groupby_clause *>(c);
    const groupby_clause::rebind_list_t& grouping_vars = gbc->get_grouping_vars();
    const groupby_clause::rebind_list_t& nongrouping_vars = gbc->get_nongrouping_vars();

    for (csize i = 0; i < grouping_vars.size(); ++i)
    {
      VarRebind_t varRebind = new VarRebind;
      clauseVarMap->theVarExprs.push_back(grouping_vars[i].second);
      clauseVarMap->theVarRebinds.push_back(varRebind);
    }

    for (csize i = 0; i < nongrouping_vars.size(); ++i)
    {
      VarRebind_t varRebind = new VarRebind;
      clauseVarMap->theVarExprs.push_back(nongrouping_vars[i].second);
      clauseVarMap->theVarRebinds.push_back(varRebind);
    }

    break;
  }

  case flwor_clause::orderby_clause:
  case flwor_clause::materialize_clause:
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
    clauseVarMap->theVarExprs.push_back(inVars.posvar);
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (inVars.curr != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(inVars.curr);
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (inVars.prev != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(inVars.prev);
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (inVars.next != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(inVars.next);
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (outVars.posvar != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(outVars.posvar);
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (outVars.curr != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(outVars.curr);
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (outVars.prev != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(outVars.prev);
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }

  if (outVars.next != NULL)
  {
    VarRebind_t varRebind = new VarRebind;
    clauseVarMap->theVarExprs.push_back(outVars.next);
    clauseVarMap->theVarRebinds.push_back(varRebind);
  }
}


struct wincond_var_iters
{
  std::vector<PlanIter_t> * inPos;
  std::vector<PlanIter_t> * inCurr;
  std::vector<PlanIter_t> * inPrev;
  std::vector<PlanIter_t> * inNext;

  std::vector<PlanIter_t> * outPos;
  std::vector<PlanIter_t> * outCurr;
  std::vector<PlanIter_t> * outPrev;
  std::vector<PlanIter_t> * outNext;

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
  const QueryLoc& loc = colExpr->get_loc();
  TypeManager* tm = colExpr->get_type_manager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t colType = colExpr->get_return_type();

  if (colType->type_kind() == XQType::NODE_TYPE_KIND)
  {
    colType = static_cast<const NodeXQType*>(colType.getp())->get_content_type();
  }

  if (colType != NULL &&
      TypeOps::is_subtype(tm, *colType, *rtm.ANY_ATOMIC_TYPE_STAR, loc) &&
      !TypeOps::is_equal(tm,
                         *TypeOps::prime_type(tm, *colType),
                         *rtm.ANY_ATOMIC_TYPE_ONE,
                         loc))
  {
    return true;
  }

  return false;
}


PlanIter_t gflwor_codegen(flwor_expr& flworExpr, int currentClause)
{
	//std::cout << "GFLWOR" <<std::endl;
#define PREV_ITER gflwor_codegen(flworExpr, currentClause - 1)

  static_context* sctx = flworExpr.get_sctx();

  if (currentClause < 0)
  {
    return new flwor::TupleSourceIterator(sctx, flworExpr.get_loc());
  }

  const flwor_clause& c = *(flworExpr.get_clause(currentClause));

  const QueryLoc& qloc = c.get_loc();

  FlworClauseVarMap_t clauseVarMap;

  if (c.get_kind() != flwor_clause::where_clause &&
      c.get_kind() != flwor_clause::window_clause)
  {
    ZORBA_ASSERT(!theClauseStack.empty());
    csize stackSize = theClauseStack.size();

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

    std::vector<PlanIter_t>& varRefs = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;
    std::vector<PlanIter_t>* posVarRefs = &no_var_iters;

    if (fc->get_pos_var())
    {
      ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 2);

      posVarRefs = &clauseVarMap->theVarRebinds[1]->theOutputVarRefs;
    }

    if (fc->is_allowing_empty())
      return new flwor::OuterForIterator(sctx, var->get_loc(), var->get_name(),
                                         PREV_ITER, domainIter, varRefs,*posVarRefs);
    else
      return new flwor::ForIterator(sctx, var->get_loc(), var->get_name(),
                                    PREV_ITER, domainIter, varRefs, *posVarRefs);
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

    std::vector<PlanIter_t>& varRefs = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

    if (clauseVarMap->theVarRebinds[0]->theIsFakeLetVar)
    {
      std::vector<PlanIter_t>* posVarRefs = &no_var_iters;

      return new flwor::ForIterator(sctx, var->get_loc(), var->get_name(),
                                    PREV_ITER, domainIter, varRefs, *posVarRefs);
    }
    else
    {
      flwor::LetIterator* letIter =
      new flwor::LetIterator(sctx, var->get_loc(), var->get_name(),
                             PREV_ITER, domainIter, varRefs,
                             lc->lazyEval(), true);  // materialize

      if (clauseVarMap->theVarRebinds[0]->theIsSingleItemLetVar)
        letIter->setSingleItem();

      return letIter;
    }
  }

  //
  // WINDOW
  //
  else if (c.get_kind() == flwor_clause::window_clause)
  {
    const window_clause* wc = static_cast<const window_clause *>(&c);

    var_expr* var = wc->get_var();
    xqtref_t varType = var->get_type();

    PlanIter_t treatIter;

    if (varType != NULL)
    {
      RootTypeManager& rtm = GENV_TYPESYSTEM;
      TypeManager* tm = sctx->get_typemanager();
      xqtref_t domainType = wc->get_expr()->get_return_type();

      if (!TypeOps::is_subtype(tm, *rtm.ITEM_TYPE_STAR, *varType, qloc) &&
          !TypeOps::is_subtype(tm, *domainType, *varType, qloc))
      {
        general_var_codegen(*var);

        PlanIter_t winVarIter = pop_itstack();

        bool checkPrime = true;

        xqtref_t varPType = TypeOps::prime_type(tm, *varType);
        xqtref_t domainPType = TypeOps::prime_type(tm, *domainType);

        if (TypeOps::is_subtype(tm, *domainPType, *varPType, qloc))
        {
          checkPrime = false;
        }

        treatIter = new TreatIterator(sctx, qloc,
                                      winVarIter,
                                      varType,
                                      checkPrime,
                                      TREAT_TYPE_MATCH,
                                      NULL);
      }
    }

    ZORBA_ASSERT(!theClauseStack.empty());
    csize stackSize = theClauseStack.size();

    clauseVarMap = theClauseStack[stackSize-1];
    theClauseStack.resize(stackSize - 1);

    ZORBA_ASSERT(clauseVarMap->theClause == &c);

    std::vector<PlanIter_t>& varRefs = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

    PlanIter_t domainIter = pop_itstack();

    std::unique_ptr<flwor::StartClause> start_clause;
    std::unique_ptr<flwor::EndClause> end_clause;
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

    PlanIter_t winIter =
    new flwor::WindowIterator(sctx,
                              var->get_loc(),
                              (wc->get_winkind() == tumbling_window ?
                               flwor::WindowIterator::TUMBLING :
                               flwor::WindowIterator::SLIDING),
                              PREV_ITER,
                              domainIter,
                              treatIter,
                              var->get_name(),
                              varRefs,
                              *start_clause,
                              *end_clause,
                              wc->lazyEval());

    return winIter;
  }

  //
  // COUNT
  //
  else if (c.get_kind() == flwor_clause::count_clause)
  {
    var_expr* var = static_cast<const count_clause *>(&c)->get_var();

    ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

    std::vector<PlanIter_t>& var_iters = clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

    return new flwor::CountIterator(sctx,
                                    var->get_loc(),
                                    var->get_name(),
                                    PREV_ITER,
                                    var_iters);
  }

  //
  // ORDERBY
  //
  else if (c.get_kind() == flwor_clause::orderby_clause)
  {
    csize numVars = clauseVarMap->theVarRebinds.size();
    csize numForVars = 0;
    csize numLetVars = 0;

    std::vector<ForVarIter_t> inputForVars(numVars);
    std::vector<LetVarIter_t> inputLetVars(numVars);
    std::vector<std::vector<PlanIter_t> > outputForVarsRefs(numVars);
    std::vector<std::vector<PlanIter_t> > outputLetVarsRefs(numVars);

    for (csize i = 0; i < numVars; ++i)
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
  else if (c.get_kind() == flwor_clause::groupby_clause)
  {
    std::vector<flwor::GroupingSpec> gspecs;
    std::vector<flwor::NonGroupingSpec> ngspecs;

    generate_groupby(clauseVarMap, gspecs, ngspecs);

    return new flwor::GroupByIterator(sctx, c.get_loc(), PREV_ITER, gspecs, ngspecs);
  }

  ZORBA_ASSERT (false);
  return NULL;
#undef PREV_ITER
}


void flwor_codegen(const flwor_expr& flworExpr)
{
  //std::cout << "FLWOR" <<std::endl;

  flwor::FLWORIterator* flworIter;
  PlanIter_t returnIter;
  std::unique_ptr<flwor::OrderByClause> orderClause;
  std::unique_ptr<flwor::GroupByClause> groupClause;
  std::unique_ptr<flwor::MaterializeClause> materializeClause;
  PlanIter_t whereIter;
  std::vector<flwor::ForLetClause> forletClauses;

  csize numClauses = flworExpr.num_clauses();

  returnIter = pop_itstack();

  for (int it = numClauses - 1; it >= 0; --it)
  {
    const flwor_clause& c = *flworExpr.get_clause(it);

    FlworClauseVarMap_t clauseVarMap;

    if (c.get_kind() != flwor_clause::where_clause)
    {
      ZORBA_ASSERT(!theClauseStack.empty());
      csize stackSize = theClauseStack.size();

      clauseVarMap = theClauseStack[stackSize-1];
      theClauseStack.resize(stackSize - 1);

      ZORBA_ASSERT(clauseVarMap->theClause == &c);
    }

    switch (c.get_kind())
    {
    //
    // MATERIALIZE
    //
    case flwor_clause::materialize_clause:
    {
      ulong numVars = (ulong)clauseVarMap->theVarRebinds.size();
      ulong numForVars = 0;
      ulong numLetVars = 0;

      std::vector<ForVarIter_t> inputForVars(numVars);
      std::vector<LetVarIter_t> inputLetVars(numVars);
      std::vector<std::vector<PlanIter_t> > outputForVarsRefs(numVars);
      std::vector<std::vector<PlanIter_t> > outputLetVarsRefs(numVars);

      for (ulong i = 0; i < numVars; ++i)
      {
        VarRebind* varRebind = clauseVarMap->theVarRebinds[i];

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

      materializeClause.reset(new flwor::MaterializeClause(c.get_loc(),
                                                           inputForVars,
                                                           inputLetVars,
                                                           outputForVarsRefs,
                                                           outputLetVarsRefs));

      break;
    }

    //
    // ORDERBY
    //
    case flwor_clause::orderby_clause:
    {
      const orderby_clause* obc = static_cast<const orderby_clause*>(&c);
      unsigned numColumns = obc->num_columns();
      const std::vector<OrderModifier>& modifiers = obc->get_modifiers();

      std::vector<flwor::OrderSpec> orderSpecs(numColumns);

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
      break;
    }

    //
    // GROUPBY
    //
    case flwor_clause::groupby_clause:
    {
      std::vector<flwor::GroupingSpec> gspecs;
      std::vector<flwor::NonGroupingSpec> ngspecs;

      generate_groupby(clauseVarMap, gspecs, ngspecs);

      groupClause.reset(new flwor::GroupByClause(c.get_loc(), gspecs, ngspecs));

      break;
    }

    //
    // WHERE
    //
    case flwor_clause::where_clause:
    {
      whereIter = pop_itstack();
      break;
    }

    //
    // FOR
    //
    case flwor_clause::for_clause:
    {
      const for_clause* fc = static_cast<const for_clause *>(&c);

      ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() >= 1);

      var_expr* var = fc->get_var();

      PlanIter_t domainIter = pop_itstack();

      std::vector<PlanIter_t>& varRefs =
      clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

      if (fc->get_pos_var())
      {
        ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 2);

        std::vector<PlanIter_t>& posVarRefs =
        clauseVarMap->theVarRebinds[1]->theOutputVarRefs;

        if (!posVarRefs.empty())
        {
          forletClauses.push_back(flwor::ForLetClause(var->get_name(),
                                                      varRefs,
                                                      posVarRefs,
                                                      domainIter));
        }
        else
        {
          forletClauses.push_back(flwor::ForLetClause(var->get_name(),
                                                      varRefs,
                                                      domainIter));
        }
      }
      else
      {
        ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

        DEBUG_SS("Creating variable (1) " << var->get_name()->show());
        forletClauses.push_back(flwor::ForLetClause(var->get_name(),
                                                    varRefs,
                                                    domainIter));
      }

      break;
    }

    //
    // LET
    //
    case flwor_clause::let_clause:
    {
      const let_clause* lc = static_cast<const let_clause *>(&c);

      ZORBA_ASSERT(clauseVarMap->theVarRebinds.size() == 1);

      var_expr* var = lc->get_var();

      PlanIter_t domainIter = pop_itstack();

      std::vector<PlanIter_t>& varRefs =
    		  clauseVarMap->theVarRebinds[0]->theOutputVarRefs;

      if (clauseVarMap->theVarRebinds[0]->theIsFakeLetVar)
      {
    	//std::cout << "Creating variable (2 BAD) " << var->get_name()->show() << std::endl;

    	flwor::ForLetClause clause(var->get_name(),varRefs,domainIter);
    	//clause.theType = flwor::ForLetClause::LET;
    	forletClauses.push_back(clause);
/*
    	forletClauses.push_back(flwor::ForLetClause(var->get_name(),
    	                                                    varRefs,
    	                                                    domainIter,
    	                                                    true,
    	                                                    true)); // materialize
*/
      }
      else
      {
    	  //std::cout << "Creating variable (3 GOOD) " << var->get_name()->show() << std::endl;
    	  forletClauses.push_back(flwor::ForLetClause(var->get_name(),
                                                    varRefs,
                                                    domainIter,
                                                    lc->lazyEval(),
                                                    true)); // materialize

        if (clauseVarMap->theVarRebinds[0]->theIsSingleItemLetVar)
          forletClauses.back().setSingleItem();
      }
      break;
    }

    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }

  std::reverse(forletClauses.begin(), forletClauses.end());

  flworIter = new flwor::FLWORIterator(flworExpr.get_sctx(),
                                       flworExpr.get_loc(),
                                       forletClauses,
                                       whereIter,
                                       groupClause.get(),
                                       orderClause.get(),
                                       materializeClause.get(),
                                       returnIter);
  groupClause.release();
  orderClause.release();
  materializeClause.release();
  push_itstack(flworIter);
}


void generate_groupby(
    const FlworClauseVarMap* clauseVarMap,
    std::vector<flwor::GroupingSpec>& gspecs,
    std::vector<flwor::NonGroupingSpec>& ngspecs)
{
  const groupby_clause* gbc = static_cast<const groupby_clause*>(clauseVarMap->theClause);

  const groupby_clause::rebind_list_t& gvars = gbc->get_grouping_vars();
  const groupby_clause::rebind_list_t& ngvars = gbc->get_nongrouping_vars();

  const std::vector<std::string>& collations = gbc->get_collations();

  long numVars = (long)(gvars.size() + ngvars.size());
  long numGroupVars = (long)gvars.size();
  long i = numVars - 1;

  for (; i >= numGroupVars; --i)
  {
    VarRebind* varRebind = clauseVarMap->theVarRebinds[i].getp();

    const std::vector<PlanIter_t>& varRefs = varRebind->theOutputVarRefs;

    ngspecs.push_back(flwor::NonGroupingSpec(pop_itstack(), varRefs));
  }

  for (; i >= 0; --i)
  {
    VarRebind* varRebind = clauseVarMap->theVarRebinds[i].getp();

    const std::vector<PlanIter_t>& varRefs = varRebind->theOutputVarRefs;

    bool fastComparison = nativeColumnSort(clauseVarMap->theVarExprs[i]);

    gspecs.push_back(flwor::GroupingSpec(pop_itstack(),
                                         varRefs,
                                         collations[i],
                                         fastComparison));
  }
}


/*******************************************************************************

********************************************************************************/
bool begin_visit(promote_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(promote_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t child = pop_itstack();
  // TODO: Currently we use cast. Promotion may be more efficient.
  push_itstack(new PromoteIterator(sctx,
                                   qloc,
                                   child,
                                   v.get_target_type(),
                                   v.get_err(),
                                   v.get_qname()));
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(trycatch_expr& v)
{
  CODEGEN_TRACE_IN("");

  for(int i = v.clause_count() - 1; i >= 0; --i)
  {
    catch_clause* cc = const_cast<catch_clause*>(v[i]);
    catch_clause::var_map_t& vars = cc->get_vars();

    for (catch_clause::var_map_t::const_iterator lIter = vars.begin();
         lIter != vars.end();
         ++lIter)
    {
      catchvar_iter_map.put((uint64_t)&*(lIter->second), new std::vector<LetVarIter_t>());
    }
  }
  return true;
}

void end_visit(trycatch_expr& v)
{
  CODEGEN_TRACE_OUT("");

  std::vector<LetVarIter_t> *vec = NULL;
  std::vector<TryCatchIterator::CatchClause> rev_ccs;

  for(int i = v.clause_count() - 1; i >= 0; --i)
  {
    catch_clause* cc = const_cast<catch_clause*>(v[i]);
    TryCatchIterator::CatchClause rcc;
    rcc.node_names = cc->get_nametests();
    rcc.catch_expr = pop_itstack();
    catch_clause::var_map_t& vars = cc->get_vars();

    for (catch_clause::var_map_t::const_iterator lIter = vars.begin();
         lIter != vars.end();
         ++lIter)
    {
      bool bound = catchvar_iter_map.get((uint64_t)&*(lIter->second), vec);
      ZORBA_ASSERT(bound);
      catch_clause::var_type var_type = (catch_clause::var_type)lIter->first;

      switch (var_type)
      {
      case catch_clause::err_code:
        rcc.theVars[TryCatchIterator::CatchClause::err_code] = *vec;
        break;
      case catch_clause::err_desc:
        rcc.theVars[TryCatchIterator::CatchClause::err_desc] = *vec;
        break;
      case catch_clause::err_value:
        rcc.theVars[TryCatchIterator::CatchClause::err_value] = *vec;
        break;
      case catch_clause::err_module:
        rcc.theVars[TryCatchIterator::CatchClause::err_module] = *vec;
        break;
      case catch_clause::err_line_no:
        rcc.theVars[TryCatchIterator::CatchClause::err_line_no] = *vec;
        break;
      case catch_clause::err_column_no:
        rcc.theVars[TryCatchIterator::CatchClause::err_column_no] = *vec;
        break;
      case catch_clause::zerr_data_uri:
        rcc.theVars[TryCatchIterator::CatchClause::zerr_data_uri] = *vec;
        break;
      case catch_clause::zerr_data_line_no:
        rcc.theVars[TryCatchIterator::CatchClause::zerr_data_line_no] = *vec;
        break;
      case catch_clause::zerr_data_column_no:
        rcc.theVars[TryCatchIterator::CatchClause::zerr_data_column_no] = *vec;
        break;
      case catch_clause::zerr_line_no_end:
        rcc.theVars[TryCatchIterator::CatchClause::zerr_line_no_end] = *vec;
        break;
      case catch_clause::zerr_column_no_end:
        rcc.theVars[TryCatchIterator::CatchClause::zerr_column_no_end] = *vec;
        break;
      case catch_clause::zerr_stack_trace:
        rcc.theVars[TryCatchIterator::CatchClause::zerr_stack_trace] = *vec;
        break;
      default:
        ZORBA_ASSERT(false);
      }
    }

    rev_ccs.push_back(rcc);
  }

  std::vector<TryCatchIterator::CatchClause> ccs(rev_ccs.rbegin(), rev_ccs.rend());
  PlanIter_t lChild = pop_itstack();

  push_itstack(new TryCatchIterator(sctx, qloc, lChild, ccs));
}


/***************************************************************************//**

********************************************************************************/
bool begin_visit(eval_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(eval_expr& v)
{
  CODEGEN_TRACE_OUT("");

  csize numVars = v.num_vars();

  checked_vector<PlanIter_t> args;
  args.reserve(numVars+1);

  std::vector<int> isGlobalVar(numVars);

  for (csize i = numVars; i > 0; --i)
  {
    isGlobalVar[i-1] = false;

    expr* arg = v.get_arg_expr(i-1);

    if (arg->get_expr_kind() == var_expr_kind)
    {
      var_expr* varArg = static_cast<var_expr*>(arg);

      if (varArg->get_kind() == var_expr::prolog_var)
        isGlobalVar[i-1] = true;
    }

    if (!isGlobalVar[i-1])
    {
      args.push_back(pop_itstack());
    }
    else
    {
      pop_itstack();
    }
  }

  args.push_back(pop_itstack());
  reverse(args.begin(), args.end());

  store::NsBindings localBindings;
  v.getNSCtx()->getAllBindings(localBindings);

  push_itstack(new EvalIterator(sctx,
                                qloc,
                                args,
                                v.get_var_names(),
                                v.get_var_types(),
                                isGlobalVar,
                                v.get_inner_scripting_kind(),
                                localBindings,
                                v.getNodeCopy(),
                                false));
}


#ifdef ZORBA_WITH_DEBUGGER
bool begin_visit(debugger_expr& v)
{
  CODEGEN_TRACE_IN("");

  // already create the debugger iterator here
  // because it's used for connecting all debugger
  // iterators in the tree (see end_visit below)
  std::vector<PlanIter_t> aTmpVec;
  DebugIterator* lIterator = new DebugIterator(sctx, qloc, aTmpVec);
  lIterator->setVarDeclaration(v.isVarDeclaration());
  theDebuggerStack.push(lIterator);
  return true;
}

void end_visit(debugger_expr& v)
{
  CODEGEN_TRACE_OUT("");

  // generate an eval iterator and populate it with the in-scope variables

  std::vector<PlanIter_t> argvEvalIter;

  csize numVars = v.var_count();
  std::vector<store::Item_t> varNames(numVars);
  std::vector<xqtref_t> varTypes(numVars);
  std::vector<int> isGlobalVar(numVars);

  //create the eval iterator children
  for (csize i = 0; i < numVars; i++)
  {
    varNames[i] = v.get_var(i)->get_name();
    varTypes[i] = v.get_var(i)->get_type();
    isGlobalVar[i] = (v.get_var(i)->get_kind() == var_expr::prolog_var);

    argvEvalIter.push_back(pop_itstack());
  }

  argvEvalIter.push_back(new DebuggerSingletonIterator(sctx,
                                                       qloc,
                                                       theCCB->theDebuggerCommons));

  // now reverse them (first the expression, then the variables)
  reverse(argvEvalIter.begin(), argvEvalIter.end());

  // get the debugger iterator from the debugger stack
  std::unique_ptr<DebugIterator> lDebugIterator(theDebuggerStack.top());
  theDebuggerStack.pop();

  // set the children of the debugger iterator
  // child 0: the iterator of the wrapped expression
  // child 1: the eval iterator

  // child 0
  std::vector<PlanIter_t> argv;
  argv.push_back(pop_itstack());

  // child 1
  store::NsBindings localBindings;
  if (v.getNSCtx())
  {
    v.getNSCtx()->getAllBindings(localBindings);
  }

  argv.push_back(new EvalIterator(sctx,
                                  qloc,
                                  argvEvalIter,
                                  varNames,
                                  varTypes,
                                  isGlobalVar,
                                  SEQUENTIAL_FUNC_EXPR,
                                  localBindings,
                                  true,
                                  true));

  lDebugIterator->setChildren(&argv);
  lDebugIterator->setVariables(varNames, varTypes);

  // link all debugger iterators in the tree
  if (!theDebuggerStack.empty())
  {
    theDebuggerStack.top()->addChild(lDebugIterator.get());
    lDebugIterator->setParent(theDebuggerStack.top());
  }

  push_itstack(lDebugIterator.get());
  lDebugIterator.release();
}
#endif


bool begin_visit(if_expr& v)
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

  PlanIter_t iterIfThenElse =
  new IfThenElseIterator(sctx, qloc, iterCond, iterThen, iterElse);

  push_itstack(&*iterIfThenElse);
}


bool begin_visit(exit_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(exit_expr& v)
{
  CODEGEN_TRACE_OUT("");
  push_itstack(new ExitIterator(sctx, qloc, pop_itstack()));
}


bool begin_visit(exit_catcher_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(exit_catcher_expr& v)
{
  CODEGEN_TRACE_OUT("");
  push_itstack(new ExitCatcherIterator(sctx, qloc, pop_itstack()));
}


bool begin_visit(flowctl_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(flowctl_expr& v)
{
  CODEGEN_TRACE_OUT("");
  enum FlowCtlException::action a;
  switch (v.get_action())
  {
  case FLOW_BREAK:
    a = FlowCtlException::BREAK;
    break;
  case FLOW_CONTINUE:
    a = FlowCtlException::CONTINUE;
    break;
  default:
    ZORBA_FATAL(false, "");
  }

  push_itstack(new FlowCtlIterator(sctx, qloc, a));
}


bool begin_visit(while_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(while_expr& v)
{
  CODEGEN_TRACE_OUT("");
  push_itstack(new LoopIterator (sctx, qloc, pop_itstack()));
}


bool begin_visit(fo_expr& v)
{
  CODEGEN_TRACE_IN("");

  const function* func = v.get_func();
  ZORBA_ASSERT(func != NULL);

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

  function* func = v.get_func();

  std::vector<PlanIter_t> argv;

  argv.resize(v.num_args());
  generate(argv.rbegin(), argv.rend(), ztd::stack_to_generator(itstack));

  const QueryLoc& loc = qloc;

  if (v.is_sequential())
  {
    csize numArgs = v.num_args();
    for (csize i = 0; i < numArgs; ++i)
    {
      if (v.get_arg(i)->is_sequential())
      {
        argv[i] = new MaterializeIterator(sctx, v.get_arg(i)->get_loc(), argv[i]);
      }
    }
  }

  if (func->validate_args(argv))
  {
    PlanIter_t iter = func->codegen(theCCB, sctx, loc, argv, v);
    ZORBA_ASSERT(iter != NULL);
    push_itstack(iter);

    if (is_enclosed_expr(&v))
    {
      expr* e = plan_visitor_ns::pop_stack(theConstructorsStack);
      ZORBA_ASSERT(e == &v);

      if (!theEnclosedContextStack.empty())
      {
        EnclosedExprContext ctx = theEnclosedContextStack.top();

        if (ctx == ATTRIBUTE_CONTENT)
          dynamic_cast<EnclosedIterator*>(iter.getp())->setAttrContent();
        else if (ctx == TEXT_CONTENT)
          dynamic_cast<EnclosedIterator*>(iter.getp())->setTextContent();
        else if (ctx == UPDATE_CONTEXT)
          dynamic_cast<EnclosedIterator*>(iter.getp())->setInUpdateExpr();
      }
    }
    else if (func->isUdf())
    {
      // need to computeCacheSettings here for iterprint to work
      user_function* udf = static_cast<user_function*>(func);
      udf->computeCacheSettings(theCCB->theXQueryDiagnostics);
    }
    else if (func->isExternal())
    {
      // need to computeCacheSettings here for iterprint to work
      external_function* extf = static_cast<external_function*>(func);
      extf->computeCacheSettings(theCCB->theXQueryDiagnostics);
    }
  }
  else
  {
    throw XQUERY_EXCEPTION(err::XPST0017,
                           ERROR_PARAMS(func->getName()->getStringValue(),
                                        ZED(FunctionUndeclared_3),
                                        argv.size()),
                           ERROR_LOC(loc));
  }
}


bool begin_visit(instanceof_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(instanceof_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t p = pop_itstack();
  push_itstack (new InstanceOfIterator (sctx, qloc, p, v.get_target_type()));
}


bool begin_visit(treat_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(treat_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t arg;
  arg = pop_itstack();
  push_itstack(new TreatIterator(sctx, qloc, arg,
                                 v.get_target_type(),
                                 v.get_check_prime(),
                                 v.get_err(),
                                 v.get_qname()));
}


bool begin_visit(castable_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(castable_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t lChild = pop_itstack();
  push_itstack(new CastableIterator(sctx,
                                    qloc,
                                    lChild,
                                    v.get_target_type(),
                                    v.allows_empty_input()));
}


bool begin_visit(cast_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(cast_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t child = pop_itstack();
  push_itstack(new CastIterator(sctx,
                                qloc,
                                child,
                                v.get_target_type(),
                                v.allows_empty_input()));
}


bool begin_visit(name_cast_expr& v)
{
  CODEGEN_TRACE_IN("");

  RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = v.get_type_manager();

  expr* targetExpr = v.get_input();
  xqtref_t targetType = targetExpr->get_return_type();

  if (TypeOps::is_subtype(tm, *rtm.UNTYPED_ATOMIC_TYPE_ONE, *targetType, qloc) ||
      TypeOps::is_subtype(tm, *targetType, *rtm.UNTYPED_ATOMIC_TYPE_ONE, qloc) ||
      TypeOps::is_subtype(tm, *rtm.QNAME_TYPE_ONE, *targetType, qloc) ||
      TypeOps::is_subtype(tm, *targetType, *rtm.QNAME_TYPE_ONE, qloc) ||
      TypeOps::is_subtype(tm, *rtm.NCNAME_TYPE_ONE, *targetType, qloc) ||
      TypeOps::is_subtype(tm, *targetType, *rtm.NCNAME_TYPE_ONE, qloc) ||
      TypeOps::is_subtype(tm, *rtm.STRING_TYPE_ONE, *targetType, qloc) ||
      TypeOps::is_subtype(tm, *targetType, *rtm.STRING_TYPE_ONE, qloc))
    return true;

  throw XQUERY_EXCEPTION(
    err::XPTY0004,
    ERROR_PARAMS( ZED( BadType_23o ), *targetType ),
    ERROR_LOC( qloc )
  );
}

void end_visit(name_cast_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t child = pop_itstack();
  push_itstack(new NameCastIterator(sctx,
                                    qloc,
                                    child,
                                    v.getNSCtx(),
                                    v.is_attr_name()));
}


bool begin_visit(validate_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(validate_expr& v)
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
  throw XQUERY_EXCEPTION(err::XQST0009, ERROR_LOC(qloc));
#endif
}


bool begin_visit(extension_expr& v) {
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(extension_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


#ifdef PATH_ITERATOR

/*******************************************************************************

********************************************************************************/
bool begin_visit(relpath_expr& v)
{
  CODEGEN_TRACE_IN("");

  //PlanIter_t input = pop_itstack();
  //ZORBA_ASSERT(input != NULL);
  //PlanIter_t pathIte(new PathIterator(qloc, input));
  //push_itstack(pathIte);

  return true;
}


void end_visit(relpath_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool begin_visit(axis_step_expr& v)
{
  CODEGEN_TRACE_IN("");

  store::ItemFactory& factory = *(GENV.getStore().getItemFactory());
  store::Item_t qname;

  PlanIter_t& ite = plan_visitor_ns::peek_stack(itstack);
  PathIterator* pathIte = dynamic_cast<PathIterator*>(ite.getp());

  if (pathIte == NULL)
  {
    PlanIter_t inputStep = pop_itstack();
    pathIte = new PathIterator(sctx, qloc, inputStep);
    push_itstack(pathIte);
  }
  //ZORBA_ASSERT(pathIte != NULL);

  match_expr* testExpr = v.getTest();

  NodePredicate* prd = new NodePredicate();

  prd->setTestKind(testExpr->getTestKind());

  if (testExpr->getTestKind() == match_name_test)
  {
    if (v.getAxis() == axis_kind_attribute)
      prd->setNodeKind(store::StoreConsts::attributeNode);
    else
      prd->setNodeKind(store::StoreConsts::elementNode);

    match_wild_t wildKind = testExpr->getWildKind();
    prd->setWildKind(wildKind);

    if (wildKind == match_no_wild)
    {
      prd->setQName(testExpr->getQName());
    }
    else if (wildKind == match_prefix_wild)
    {
      factory.createQName(qname, "", "*", testExpr->getWildName().c_str());

      prd->setQName(qname);
    }
    else if (wildKind == match_name_wild)
    {
      prd->setQName(testExpr->getQName());
    }
  }
  else
  {
    prd->setDocTestKind(testExpr->getDocTestKind());
    prd->setNodeKind(testExpr->getNodeKind());
    prd->setQName(testExpr->getQName());
    store::Item* typeName = testExpr->getTypeName();
    if (typeName != NULL)
    {
      prd->setType(sctx->get_typemanager()->create_named_type(typeName,
                                                              SequenceType::QUANT_ONE,
                                                              loc,
                                                              XPTY0004));
    }
    prd->setNilledAllowed(testExpr->getNilledAllowed());
  }

  pathIte->addStep(v.getAxis(), prd);

  return true;
}


void end_visit(axis_step_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


bool begin_visit(match_expr& v)
{
  CODEGEN_TRACE_IN("");

  return true;
}


void end_visit(match_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


#else

/*******************************************************************************

********************************************************************************/
bool begin_visit(relpath_expr& v)
{
  CODEGEN_TRACE_IN("");
  // Done in axis itself
  return true;
}


void end_visit(relpath_expr& v)
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
    if (v.use_reverse_order())
      axisIte = new AncestorReverseAxisIterator(sctx, qloc, input);
    else
      axisIte = new AncestorAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_ancestor_or_self:
  {
    if (v.use_reverse_order())
      axisIte = new AncestorSelfReverseAxisIterator(sctx, qloc, input);
    else
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
    if (v.use_reverse_order())
      axisIte = new LSiblingReverseAxisIterator(sctx, qloc, input);
    else
      axisIte = new LSiblingAxisIterator(sctx, qloc, input);
    break;
  }
  case axis_kind_preceding:
  {
    if (v.use_reverse_order())
      axisIte = new PrecedingReverseAxisIterator(sctx, qloc, input);
    else
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


void end_visit(axis_step_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


/*******************************************************************************

********************************************************************************/
bool begin_visit(match_expr& v)
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

    if (wildKind == match_no_wild)
    {
      axisItep->setQName(v.getQName());
    }
    else if (wildKind == match_prefix_wild)
    {
      iFactory.createQName(qname, "", "wildcard", v.getWildName().c_str());

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
    store::Item* typeName = v.getTypeName();
    if (typeName != NULL)
    {
      axisItep->setType(sctx->get_typemanager()->
                        create_named_type(typeName,
                                          SequenceType::QUANT_ONE,
                                          qloc));
    }
    axisItep->setNilledAllowed(v.getNilledAllowed());
  }

  push_itstack(axisIte);
  return true;
}


void end_visit(match_expr& v)
{
  CODEGEN_TRACE_OUT("");
}

#endif // PATH_ITER


/*******************************************************************************

  Node Constructors

********************************************************************************/

bool begin_visit(doc_expr& v)
{
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theEnclosedContextStack.push(ELEMENT_CONTENT);

  if (v.copyInputNodes())
    theCopyNodesStack.push(true);

  return true;
}


void end_visit(doc_expr& v)
{
  CODEGEN_TRACE_OUT("");

  PlanIter_t lContent = pop_itstack();
  PlanIter_t lDocIter = new DocumentIterator(sctx,
                                             qloc,
                                             lContent,
                                             !theCopyNodesStack.empty());
  push_itstack(lDocIter);

  theEnclosedContextStack.pop();
  expr* e = plan_visitor_ns::pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e == &v);

  if (v.copyInputNodes())
    theCopyNodesStack.pop();
}


bool begin_visit(elem_expr& v)
{
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theEnclosedContextStack.push(ELEMENT_CONTENT);

  if (v.copyInputNodes())
    theCopyNodesStack.push(true);

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
  theEnclosedContextStack.pop();
  expr* e = plan_visitor_ns::pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e == &v);

  // Handling of the special case where the QName expression of a direct element
  // constructor has in itself a direct constructor. In that case the QName
  // expression should have isRoot set to true.
  elem_expr* top_elem_expr = NULL;
  if (!theConstructorsStack.empty())
    top_elem_expr = dynamic_cast<elem_expr*>(theConstructorsStack.top());

  if (theConstructorsStack.empty() ||
      is_enclosed_expr(theConstructorsStack.top()) ||
      (top_elem_expr != NULL && top_elem_expr->getQNameExpr()->contains_expr(e)))
  {
    isRoot = true;
  }

	PlanIter_t iter = new ElementIterator(sctx,
                                        qloc,
                                        lQNameIter,
                                        lAttrsIter,
                                        lContentIter,
                                        v.getNSCtx(),
                                        isRoot,
                                        !theCopyNodesStack.empty());
  push_itstack(iter);

  if (v.copyInputNodes())
    theCopyNodesStack.pop();
}


bool begin_visit(attr_expr& v)
{
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theEnclosedContextStack.push(ATTRIBUTE_CONTENT);

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
  theEnclosedContextStack.pop();
  expr* e = plan_visitor_ns::pop_stack(theConstructorsStack);
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


bool begin_visit(namespace_expr& v)
{
  CODEGEN_TRACE_IN("");
	return true;
}


void end_visit(namespace_expr& v)
{
  CODEGEN_TRACE_OUT("");

  PlanIter_t uri = pop_itstack();
  PlanIter_t prefix = pop_itstack();
  push_itstack(new NamespaceIterator(sctx, qloc, prefix, uri));
}


bool begin_visit(text_expr& v)
{
  CODEGEN_TRACE_IN ("");

  theConstructorsStack.push(&v);

  if (v.get_type() == text_constructor)
    theEnclosedContextStack.push(TEXT_CONTENT);
  else
    theEnclosedContextStack.push(ATTRIBUTE_CONTENT);

	return true;
}


void end_visit(text_expr& v)
{
  CODEGEN_TRACE_OUT("");

  PlanIter_t content = pop_itstack();

  bool isRoot = false;
  theEnclosedContextStack.pop();
  expr* e = plan_visitor_ns::pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);

  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top()))
  {
    isRoot = true;
  }

  switch (v.get_type())
  {
  case text_constructor:
    push_itstack(new TextIterator(sctx, qloc, content, isRoot));
    break;

  case comment_constructor:
    push_itstack(new CommentIterator(sctx, qloc, content, isRoot));
    break;

  default:
    break;
  }
}


bool begin_visit(pi_expr& v)
{
  CODEGEN_TRACE_IN("");

  theConstructorsStack.push(&v);
  theEnclosedContextStack.push(ATTRIBUTE_CONTENT);

  return true;
}


void end_visit(pi_expr& v)
{
  CODEGEN_TRACE_OUT("");

  bool isRoot = false;
  theEnclosedContextStack.pop();
  expr* e = plan_visitor_ns::pop_stack(theConstructorsStack);
  ZORBA_ASSERT(e = &v);
  if (theConstructorsStack.empty() || is_enclosed_expr(theConstructorsStack.top()))
  {
    isRoot = true;
  }

  PlanIter_t content = pop_itstack();
  PlanIter_t target = pop_itstack();
  push_itstack(new PiIterator(sctx, qloc, target, content, isRoot));
}


/*******************************************************************************

  JSON Constructors

********************************************************************************/
bool begin_visit(json_array_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(json_array_expr& v)
{
  CODEGEN_TRACE_OUT("");

  std::vector<PlanIter_t> inputs;

  expr* inputExpr = v.get_expr();

  if (inputExpr != NULL)
  {
    PlanIter_t inputIter = pop_itstack();

    if (dynamic_cast<FnConcatIterator*>(inputIter.getp()) != NULL)
    {
      inputs = static_cast<FnConcatIterator*>(inputIter.getp())->getChildren();
    }
    else
    {
      inputs.push_back(inputIter);
    }
  }

  bool copyInput = true;

  push_itstack(new JSONArrayIterator(sctx, qloc, inputs, copyInput));
}


bool begin_visit(json_object_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(json_object_expr& v)
{
  CODEGEN_TRACE_OUT("");

  std::vector<PlanIter_t> inputs;

  expr* inputExpr = v.get_expr();

  if (inputExpr != NULL)
  {
    PlanIter_t inputIter = pop_itstack();

    if (dynamic_cast<FnConcatIterator*>(inputIter.getp()) != NULL)
    {
      inputs = static_cast<FnConcatIterator*>(inputIter.getp())->getChildren();
    }
    else
    {
      inputs.push_back(inputIter);
    }
  }

  bool copyInput = true;

  push_itstack(new JSONObjectIterator(sctx,
                                      qloc,
                                      inputs,
                                      copyInput,
                                      v.is_accumulating()));
}



bool begin_visit(json_direct_object_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}


void end_visit(json_direct_object_expr& v)
{
  CODEGEN_TRACE_OUT("");

  csize numPairs = v.num_pairs();

  std::vector<PlanIter_t> names(numPairs);
  std::vector<PlanIter_t> values(numPairs);

  for (csize i = numPairs; i > 0; --i)
  {
    values[i-1] = pop_itstack();
  }

  for (csize i = numPairs; i > 0; --i)
  {
    names[i-1] = pop_itstack();
  }

  bool copyInput = true;

  push_itstack(new JSONDirectObjectIterator(sctx, qloc, names, values, copyInput));
}


bool begin_visit(const_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(const_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t it = new SingletonIterator(sctx, qloc, v.get_val());
  push_itstack (it);
}


bool begin_visit(order_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(order_expr& v)
{
  CODEGEN_TRACE_OUT("");
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Updates (XQUF)                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


bool begin_visit(insert_expr& v)
{
  CODEGEN_TRACE_IN("");

  RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = v.get_type_manager();

  store::UpdateConsts::InsertType kind  = v.getType();

  expr* targetExpr = v.getTargetExpr();
  expr* sourceExpr = v.getSourceExpr();
  xqtref_t targetType = targetExpr->get_return_type();
  xqtref_t sourceType = sourceExpr->get_return_type();

  if (TypeOps::is_equal(tm, *targetType, *rtm.EMPTY_TYPE, qloc))
    throw XQUERY_EXCEPTION( err::XUDY0027, ERROR_LOC( qloc ) );

  if (kind == store::UpdateConsts::INTO ||
      kind == store::UpdateConsts::AS_FIRST_INTO ||
      kind == store::UpdateConsts::AS_LAST_INTO)
  {
    if (TypeOps::is_subtype(tm, *targetType, *rtm.DOCUMENT_TYPE_STAR, qloc) &&
        TypeOps::is_subtype(tm, *sourceType, *rtm.ATTRIBUTE_TYPE_STAR, qloc))
    {
      throw XQUERY_EXCEPTION(err::XUTY0022, ERROR_LOC(qloc));
    }

    if (TypeOps::is_subtype(tm, *targetType, *rtm.ANY_SIMPLE_TYPE, qloc))
    {
      throw XQUERY_EXCEPTION( err::XUTY0005, ERROR_LOC( qloc ) );
    }

    if (TypeOps::is_subtype(tm, *targetType, *rtm.ATTRIBUTE_TYPE_STAR, qloc) ||
        TypeOps::is_subtype(tm, *targetType, *rtm.TEXT_TYPE_STAR, qloc) ||
        TypeOps::is_subtype(tm, *targetType, *rtm.COMMENT_TYPE_STAR, qloc) ||
        TypeOps::is_subtype(tm, *targetType, *rtm.PI_TYPE_STAR, qloc))
    {
      throw XQUERY_EXCEPTION( err::XUTY0005, ERROR_LOC( qloc ) );
    }
  }
  else
  {
  }

  theEnclosedContextStack.push(UPDATE_CONTEXT);

  return true;
}


void end_visit(insert_expr& v)
{
  CODEGEN_TRACE_OUT("");

  theEnclosedContextStack.pop();

  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lSource = pop_itstack();
  PlanIter_t lInsert = new InsertIterator(sctx, qloc, v.getType(), lSource, lTarget);
  push_itstack(&*lInsert);
}


bool begin_visit(delete_expr& v)
{
  CODEGEN_TRACE_IN("");

  theEnclosedContextStack.push(UPDATE_CONTEXT);

  return true;
}


void end_visit(delete_expr& v)
{
  CODEGEN_TRACE_OUT("");

  theEnclosedContextStack.pop();

  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lDelete = new DeleteIterator(sctx, qloc, lTarget);
  push_itstack(&*lDelete);
}


bool begin_visit(replace_expr& v)
{
  CODEGEN_TRACE_IN("");

  TypeManager* tm = v.get_type_manager();

  expr* targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->get_return_type();

  if (TypeOps::is_equal(tm, *targetType, *GENV_TYPESYSTEM.EMPTY_TYPE, qloc))
    throw XQUERY_EXCEPTION( err::XUDY0027, ERROR_LOC( qloc ) );

  theEnclosedContextStack.push(UPDATE_CONTEXT);

  return true;
}


void end_visit(replace_expr& v)
{
  CODEGEN_TRACE_OUT("");

  theEnclosedContextStack.pop();

  PlanIter_t lReplacement = pop_itstack();
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lReplace = new ReplaceIterator(sctx,
                                            qloc,
                                            v.getType(),
                                            lTarget,
                                            lReplacement);
  push_itstack(&*lReplace);
}


bool begin_visit(rename_expr& v)
{
  CODEGEN_TRACE_IN("");

  TypeManager* tm = v.get_type_manager();

  expr* targetExpr = v.getTargetExpr();
  xqtref_t targetType = targetExpr->get_return_type();

  if (TypeOps::is_equal(tm, *targetType, *GENV_TYPESYSTEM.EMPTY_TYPE, qloc))
    throw XQUERY_EXCEPTION( err::XUDY0027, ERROR_LOC( qloc ) );

  theEnclosedContextStack.push(UPDATE_CONTEXT);

  return true;
}


void end_visit(rename_expr& v)
{
  CODEGEN_TRACE_OUT("");

  theEnclosedContextStack.pop();

  PlanIter_t lName = pop_itstack();
  PlanIter_t lTarget = pop_itstack();
  PlanIter_t lRename;

  expr* nameExpr = v.getNameExpr();

  if (nameExpr->get_expr_kind() == name_cast_expr_kind)
  {
    name_cast_expr* nameCastExpr = static_cast<name_cast_expr*>(nameExpr);

    lRename = new RenameIterator(sctx,
                                 qloc,
                                 lTarget,
                                 lName,
                                 nameCastExpr->getNSCtx());
  }
  else
  {
    lRename = new RenameIterator(sctx, qloc, lTarget, lName, NULL);
  }

  push_itstack(&*lRename);
}


bool begin_visit(transform_expr& v)
{
  CODEGEN_TRACE_IN("");

  TypeManager* tm = v.get_type_manager();

  std::vector<copy_clause*>::const_iterator lIter = v.begin();
  std::vector<copy_clause*>::const_iterator lEnd  = v.end();
  for (; lIter != lEnd; ++lIter)
  {
    var_expr* var = (*lIter)->getVar();
    expr* sourceExpr = (*lIter)->getExpr();
    xqtref_t sourceType = sourceExpr->get_return_type();

    if (TypeOps::is_subtype(tm, *sourceType, *GENV_TYPESYSTEM.ANY_SIMPLE_TYPE, qloc))
      throw XQUERY_EXCEPTION(err::XUTY0013, ERROR_LOC(qloc));

    uint64_t k = (uint64_t) &*var;
    copy_var_iter_map.put(k, new std::vector<ForVarIter_t>());
  }
  return true;
}

void end_visit(transform_expr& v)
{
  CODEGEN_TRACE_OUT("");

  PlanIter_t returnIter = pop_itstack();
  PlanIter_t modifyIter = pop_itstack();

  std::vector<CopyClause> lClauses;
  std::stack<PlanIter_t> lInputs;
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
  PlanIter_t applyIter = new ApplyIterator(sctx, modifyIter->loc, true, pulHolderIter);

  std::vector<copy_clause*>::const_iterator lIter = v.begin();
  std::vector<copy_clause*>::const_iterator lEnd  = v.end();
  for(; lIter != lEnd; ++lIter)
  {
    PlanIter_t lInput = plan_visitor_ns::pop_stack(lInputs);
    std::vector<ForVarIter_t>* lVarIters = 0;
    var_expr* lVar = (*lIter)->getVar();
    ZORBA_ASSERT(copy_var_iter_map.get((uint64_t)lVar, lVarIters));
    lClauses.push_back(CopyClause(*lVarIters, lInput));
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


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Full Text                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_NO_FULL_TEXT
bool begin_visit(ftcontains_expr& v)
{
  CODEGEN_TRACE_IN("");
  return true;
}

void end_visit(ftcontains_expr& v)
{
  CODEGEN_TRACE_OUT("");
  PlanIter_t ftignore_it = v.get_ignore() ? pop_itstack() : NULL;
  PlanIter_t ftrange_it = pop_itstack();

  PlanIter_t ftcontains_it = new FTContainsIterator(
    sctx, qloc, ftrange_it, ftignore_it, v.get_ftselection(),
    plan_ftnode_visitor_->get_sub_iters()
  );

  push_itstack( ftcontains_it );
}
#endif /* ZORBA_NO_FULL_TEXT */


PlanIter_t result()
{
  PlanIter_t res = pop_itstack();

#ifndef NDEBUG
  if (!itstack.empty())
  {
    std::cout << "\nPlan_visitor stack still contains "
              << itstack.size() << " entries: " << std::endl;
    while (!itstack.empty())
    {
      PlanIter_t top = pop_itstack();
      XMLIterPrinter vp(std::cout);
      print_iter_plan(vp, top);
      std::cout << "=============================" << std::endl;
    }
    ZORBA_ASSERT(0);
  }
#endif

  return res;
}

};

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_NO_FULL_TEXT

#define V plan_ftnode_visitor

//
// This member function is defined here to avoid an improper cast.
//
expr_visitor* V::get_expr_visitor()
{
  return plan_visitor_;
}

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftand )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftextension_selection )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftmild_not )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftor )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftprimary_with_options )

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftrange );
void V::end_visit( ftrange &r ) {
  PlanIter_t it2 = plan_visitor_->pop_itstack();
  PlanIter_t it1;
  if ( *(r.get_expr2()) ) {
    it1 = plan_visitor_->pop_itstack();
  } else {
    it1 = it2;
    it2 = NULL;
  }
  sub_iters_.push_back( it1 );
  if ( it2 )
    sub_iters_.push_back( it2 );
  r.set_plan_iters( it1, it2 );
}

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftselection )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftunary_not )

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftweight );
void V::end_visit( ftweight &w ) {
  PlanIter_t it = plan_visitor_->pop_itstack();
  w.set_weight_iter( it );
  sub_iters_.push_back( it );
}

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftwords );
void V::end_visit( ftwords &w ) {
  PlanIter_t it = plan_visitor_->pop_itstack();
  w.set_plan_iter( it );
  sub_iters_.push_back( it );
}

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftwords_times )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftcontent_filter )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftdistance_filter )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftorder_filter )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftscope_filter )

DEF_FTNODE_VISITOR_BEGIN_VISIT( V, ftwindow_filter );
void V::end_visit( ftwindow_filter &f ) {
  PlanIter_t it = plan_visitor_->pop_itstack();
  f.set_window_iter( it );
  sub_iters_.push_back( it );
}

DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftcase_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftdiacritics_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftextension_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftlanguage_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftmatch_options )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstem_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstop_word_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftstop_words )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_id )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftthesaurus_option )
DEF_FTNODE_VISITOR_VISIT_MEM_FNS( V, ftwild_card_option )

#undef V

#endif /* ZORBA_NO_FULL_TEXT */

/******************************************************************************

******************************************************************************/

PlanIter_t codegen(
    const char* descr,
    expr* root,
    CompilerCB* ccb,
    ulong& nextDynamicVarId,
    hash64map<std::vector<LetVarIter_t> *>* arg_var_map)
{
  plan_visitor c(ccb, nextDynamicVarId, arg_var_map);

  root->accept(c);
  PlanIter_t result = c.result();

  nextDynamicVarId = c.getNextDynamicVarId();

  Zorba_plan_format_t const format = Properties::instance().getPlanFormat();
  if ( result && descr && format ) {
    std::ostream &os = Properties::instance().getDebugStream();
    unique_ptr<IterPrinter> printer;
    switch ( format ) {
      case PLAN_FORMAT_DOT:
        printer.reset( new DOTIterPrinter( os, descr ) );
        break;
      case PLAN_FORMAT_JSON:
        printer.reset( new JSONIterPrinter( os, descr ) );
        break;
      case PLAN_FORMAT_XML:
        printer.reset( new XMLIterPrinter( os, descr ) );
        break;
      default: // to silence warning
        break;
    } // switch
    print_iter_plan( *printer, result );
  }

  return result;
}


std::vector<PlanIter_t> plan_visitor::no_var_iters;

} // namespace zorba
/* vim:set et sw=2 ts=2: */
