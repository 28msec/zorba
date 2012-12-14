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
#pragma once
#ifndef ZORBA_COMPILER_PROLOG_GRAPH
#define ZORBA_COMPILER_PROLOG_GRAPH

#include <map>
#include <list>
#include <set>
#include <cassert>

#include "common/shared_types.h"

#include "compiler/expression/var_expr.h"


namespace zorba 
{


class function;
class var_expr;


/*******************************************************************************
  Class to represent a vertex in the dependency graph among var and udfs decls
  in the prolog of a module. A vertex is represented as a pointer to either a
  var_expr (if var decl) or a function obj (if udf decl).
********************************************************************************/
class PrologGraphVertex
{
public:
  typedef enum { VAR, FUN } Kind;

  typedef union
  {
    const var_expr* var;
    const function* fun;
  } Key;

public:
  Key   theKey;
  Kind  theKind;

public:
  PrologGraphVertex() : theKind(VAR)
  {
    theKey.var = NULL;
  }

  PrologGraphVertex(const var_expr* v) : theKind(VAR)
  {
    theKey.var = v;
  }

  PrologGraphVertex(const function* f) : theKind(FUN)
  {
    theKey.fun = f;
  }

  bool isNull() const { return theKey.var == NULL; }

  void setNull() { theKey.var = NULL; }

  Kind getKind() const { return theKind; }

  bool isVar() const { return theKind == VAR; }

  bool isUDF() const { return theKind == FUN; }

  const function* getFunction() const
  {
    assert(theKind == FUN);
    return theKey.fun;
  }

  const var_expr* getVarExpr() const
  {
    assert(theKind == VAR);
    return theKey.var;
  }

  bool operator==(const PrologGraphVertex& other) const
  {
    return (theKey.var == other.theKey.var);
  }

  bool operator<(const PrologGraphVertex& other) const
  {
    return (theKey.var < other.theKey.var);
  }
};


/*******************************************************************************

********************************************************************************/
class PrologGraph
{
  typedef std::set<PrologGraphVertex> VSet;

  typedef std::map<PrologGraphVertex, VSet*> GraphImpl;

private:
  static_context               * theModuleSctx;

  GraphImpl                      theGraph;

  std::vector<const var_expr*>   theVarDecls;
  std::vector<const function*>   theFuncDecls;

public:
  static void addEdge(
        GraphImpl& graph,
        const PrologGraphVertex& v1,
        const PrologGraphVertex& v2)
  {
    GraphImpl::iterator ite = graph.find(v1);

    if (ite == graph.end())
    {
      VSet* vset = new VSet;
      vset->insert(v2);

      graph[v1] = vset;

      //std::cout << "Allocated new vset : " << vset << std::endl << std::endl;
    }
    else
    {
      (*ite).second->insert(v2);
    }
  }

public:
  PrologGraph(static_context* sctx) : theModuleSctx(sctx) { }

  ~PrologGraph()
  {
    GraphImpl::iterator ite = theGraph.begin();
    GraphImpl::iterator end = theGraph.end();
    for (; ite != end; ++ite)
    {
      //std::cout << "De-allocated vset : " << (*ite).second << std::endl << std::endl;

      delete (*ite).second;
    }
  }

  void addVarVertex(const var_expr* v)
  {
    theVarDecls.push_back(v);
  }

  void addFuncVertex(const function* v)
  {
    theFuncDecls.push_back(v);
  }

  void addEdge(const PrologGraphVertex& v1, const PrologGraphVertex& v2);

  void reorder_globals(std::list<GlobalBinding>& prologVarBindings);

private:
  void reportCycle(const QueryLoc& loc, const PrologGraphVertex* v);
};


}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
