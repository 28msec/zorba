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

#include "compiler/translator/prolog_graph.h"

#include "context/static_context.h"

#include "util/string_util.h"

#include "zorbatypes/zstring.h"

#include "diagnostics/xquery_exception.h"
#include "diagnostics/dict.h"
#include "diagnostics/util_macros.h"

namespace zorba 
{


/*******************************************************************************

********************************************************************************/
void PrologGraph::reportCycle(const QueryLoc& loc, const PrologGraphVertex* v)
{
  std::string moduleNS = theModuleSctx->get_module_namespace();
  zstring varName;
  if ( v )
    varName = BUILD_STRING('$', v->getVarExpr()->get_name()->getStringValue());

  RAISE_ERROR(err::XQST0054, loc, ERROR_PARAMS(varName));
}


/*******************************************************************************

********************************************************************************/
void PrologGraph::addEdge(const PrologGraphVertex& v1, const PrologGraphVertex& v2)
{
  if (v1.isVar() && v2.isVar() && v1.getVarExpr() == v2.getVarExpr())
  {
    zstring varName = '$' + v1.getVarExpr()->get_name()->getStringValue();

    RAISE_ERROR(err::XPST0008, v2.getVarExpr()->get_loc(),
    ERROR_PARAMS(varName, ZED(VariabledUndeclared)));
  }

  addEdge(theGraph, v1, v2);
}


/*******************************************************************************
  This method is part of the mechanism for detecting cycles in the dependency
  graph among prolog variables. The method does not actually detect the cycles
  but re-orders the declarations of prolog vars (i.e., reorders theGlobalVars
  list) so that if var v2 depends on var v1, then v1 appears before v2 in the
  list (and as a result, v1 will be evaluated before v2 during runtime).

  Circular dependencies among prolog vars can appear only when udfs are involved.
  Here is an example:

  declare variable $var := local:func1();

  declare function local:func1()
  {
    local:func2()
  };

  declare function local:func2()
  {
    local:func3()
  };

  declare variable $var2 := local:func2();

  declare function local:func3()
  {
    $var2
  };

  boolean($var)


  In this query, the following cycle exists : var2 --> func2 --> func3 --> var2
********************************************************************************/
void PrologGraph::reorder_globals(std::list<GlobalBinding>& prologVarBindings)
{
  GraphImpl::const_iterator g_ite;
  GraphImpl::const_iterator g_end = theGraph.end();

  std::vector<const var_expr*>::const_iterator v_ite;
  std::vector<const var_expr*>::const_iterator v_end = theVarDecls.end();

  std::vector<const function*>::const_iterator fend = theFuncDecls.end();

  // STEP 1: Floyd-Warshall transitive closure of edges starting from functions
  // At each substep we are adding fn2 -> fn1 -> var/fn dependencies. The resulting
  // graph has the following property: If there is a path P in the original graph
  // such that P starts at a udf node F, ends at a var node V and contains only
  // udf nodes in between, then in the augmented graph there is a direct edge
  // F --> V. As a result, to go from one variable to another, we never need to
  // cross 2 or more consequtive udf nodes.

  std::vector<const function*>::const_iterator f1_ite;
  std::vector<const function*>::const_iterator f2_ite;

  for (f1_ite = theFuncDecls.begin(); f1_ite != fend; ++f1_ite)
  {
    const function* f1 = *f1_ite;
    GraphImpl::iterator f1_graph_entry = theGraph.find(f1);

    if (f1_graph_entry == g_end)
      continue;

    for (f2_ite = theFuncDecls.begin(); f2_ite != fend; ++f2_ite)
    {
      const function* f2 = *f2_ite;
      GraphImpl::const_iterator f2_graph_entry = theGraph.find(f2);

      // if f2 depends on f1, then f2 depends on every var/udf that f1 depends on.

      // If f2 does not depend on anything, skip it
      if (f2_graph_entry == g_end)
        continue;

      VSet* f1_vset = f1_graph_entry->second;
      VSet* f2_vset = f2_graph_entry->second;

      // If f2 does not depend on f1, skip it
      if (f2_vset->find(f1) == f2_vset->end())
        continue;

      f2_vset->insert(f1_vset->begin(), f1_vset->end());
    }
  }

  // STEP 2: Add "1-step" var -> fn -> var/fn dependencies. Steps 1 & 2 together
  // guarantee that if there is a path P from variable v1 to variable v2 in the
  // original graph, then in the augmented graph there is a path P' from v1 to
  // v2 such that P' does not contain any udfs. Therefore, the augmented graph
  // contains a subgraph VG that consists of edges among variables only and which
  // which reflects the same (direct and transitive) dependencies among vars as
  // the original graph.

  for (v_ite = theVarDecls.begin(); v_ite != v_end; ++v_ite)
  {
    const var_expr* v1 = *v_ite;
    GraphImpl::const_iterator v1_graph_entry = theGraph.find(v1);

    if (v1_graph_entry == g_end)
      continue;

    VSet* v1_vset = v1_graph_entry->second;
    VSet::const_iterator v1_vset_ite = v1_vset->begin();
    VSet::const_iterator v1_vset_end = v1_vset->end();

    for (; v1_vset_ite != v1_vset_end; ++v1_vset_ite)
    {
      const PrologGraphVertex& f = *v1_vset_ite;

      if (f.getKind() == PrologGraphVertex::FUN)
      {
        GraphImpl::iterator f_graph_entry = theGraph.find(f);

        if (f_graph_entry == g_end)
          continue;

        VSet* f_vset = f_graph_entry->second;
        VSet::const_iterator f_vset_ite = f_vset->begin();
        VSet::const_iterator f_vset_end = f_vset->end();

        for (; f_vset_ite != f_vset_end; ++f_vset_ite)
        {
          const PrologGraphVertex& v2 = *f_vset_ite;

          if (v2.getKind() == PrologGraphVertex::VAR)
          {
            if (v2 == v1)
            {
              reportCycle(v2.getVarExpr()->get_loc(), &v2);
            }

            addEdge(v1, v2);
          }
        }
      }
    }
  }

  // STEP 3 Check for cycles. First we extract graph VG from the original graph.
  // We also make a copy of theVarDecls vector into varDels. Then we repeat the
  // following steps until varDecls gets empty:
  // 1. We look for a var V in varDecls that does not depend on any other var.
  // 2. If no such var is found, a cycle exists, and we raise an error.
  // 3. We remove V from varDecls and from each dependency set that V appears in.
  // (TODO: use faster algorithm)

  GraphImpl v_graph;
  std::set<const var_expr*> varDecls;

  for (g_ite = theGraph.begin(); g_ite != g_end; ++g_ite)
  {
    const PrologGraphVertex& v1 = (*g_ite).first;

    if (v1.getKind() == PrologGraphVertex::VAR)
    {
      VSet* v1_vset = (*g_ite).second;
      VSet::const_iterator v1_vset_ite = v1_vset->begin();
      VSet::const_iterator v1_vset_end = v1_vset->end();

      for (; v1_vset_ite != v1_vset_end; ++v1_vset_ite)
      {
        const PrologGraphVertex& v2 = *v1_vset_ite;

        if (v2.getKind() == PrologGraphVertex::VAR)
        {
          PrologGraph::addEdge(v_graph, v1, v2);
          varDecls.insert(v1.getVarExpr());
          varDecls.insert(v2.getVarExpr());
        }
      }
    }
  }

  g_end = v_graph.end();

  while (!varDecls.empty())
  {
    const var_expr* var = NULL;

    std::set<const var_expr*>::iterator v_ite = varDecls.begin();
    std::set<const var_expr*>::iterator v_end = varDecls.end();

    for (; v_ite != v_end; ++v_ite)
    {
      GraphImpl::iterator v_graph_entry = v_graph.find(*v_ite);
      if (v_graph_entry == g_end ||
          v_graph_entry->second->empty())
      {
        var = *v_ite;
        varDecls.erase(v_ite);
        break;
      }
    }

    if (var == NULL)
    {
      for (g_ite = v_graph.begin(); g_ite != g_end; ++g_ite)
      {
        delete (*g_ite).second;
      }

      reportCycle((*varDecls.begin())->get_loc(), 0);
    }

    for (g_ite = v_graph.begin(); g_ite != g_end; ++g_ite)
    {
      VSet* vset = (*g_ite).second;
      VSet::iterator vset_entry = vset->find(var);

      if (vset_entry != vset->end())
      {
        vset->erase(vset_entry);
      }
    }
  }

  for (g_ite = v_graph.begin(); g_ite != g_end; ++g_ite)
  {
    delete (*g_ite).second;
  }

  // STEP 4: topologically sort global vars.
  // Implemented using non-recursive (stack-based) DFS traversal. This algorithm
  // unfortunately does not detect cycles.
  // Note that steps 1 & 2 are required: we cannot sort the entire set of prolog
  // vars + udfs, because functions are allowed to be mutually recursive.

  g_end = theGraph.end();

  std::vector<const var_expr*> topsorted_vars;  // dependencies first
  std::set<const var_expr*> visited;

  std::stack<std::pair<ulong, const var_expr*> > todo;  // format: action code + var_expr
  // need to declare the reverse end iterator here because of a bug in older gcc's
  // (see http://gcc.gnu.org/bugzilla/show_bug.cgi?id=11729)
  std::vector<const var_expr*>::const_reverse_iterator  lEnd = theVarDecls.rend();
  for (std::vector<const var_expr*>::const_reverse_iterator it = theVarDecls.rbegin();
       it != lEnd;
       ++it)
  {
    todo.push(std::pair<ulong, const var_expr*>(1, (*it)));
  }

  while (! todo.empty())
  {
    const var_expr* var = todo.top().second;
    ulong action = todo.top().first;
    todo.pop();

    switch (action)
    {
    case 0:  // finish notification
    {
      topsorted_vars.push_back(var);
      break;
    }
    case 1:  // visit request
    {
      if (visited.find(var) == visited.end())
      {
        visited.insert(var);
        todo.push(std::pair<ulong, const var_expr*>(0, var));

        GraphImpl::const_iterator var_graph_entry = theGraph.find(var);

        if (var_graph_entry != g_end)
        {
          VSet* var_vset = var_graph_entry->second;

          VSet::const_iterator var_vset_ite = var_vset->begin();
          VSet::const_iterator var_vset_end = var_vset->end();
          for (; var_vset_ite != var_vset_end; ++var_vset_ite)
          {
            if (var_vset_ite->getKind() == PrologGraphVertex::VAR)
            {
              todo.push(std::pair<ulong, const var_expr*>(1, var_vset_ite->getVarExpr()));
            }
          }
        }
      }
      break;
    }
    default:
      assert(false);
    }
  }

  // STEP 5: reorder thePrologVars according to topological order
  std::map<const var_expr*, GlobalBinding> gvmap;
  std::list<GlobalBinding>::iterator bindIte = prologVarBindings.begin();
  for (; bindIte != prologVarBindings.end(); ++bindIte)
  {
    gvmap[(*bindIte).theVar] = *bindIte;
  }

  prologVarBindings.clear();

  for (std::vector<const var_expr*>::iterator i = topsorted_vars.begin();
       i != topsorted_vars.end(); ++i)
  {
    std::map<const var_expr*, GlobalBinding>::iterator p = gvmap.find(*i);

    if (p != gvmap.end())
      prologVarBindings.push_back((*p).second);
  }
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
