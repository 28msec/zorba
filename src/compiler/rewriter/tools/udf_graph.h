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
#ifndef ZORBA_REWRITER_TOOLS_UDF_GRAPH
#define ZORBA_REWRITER_TOOLS_UDF_GRAPH

#include "common/shared_types.h"

#include "zorbautils/hashmap.h"


namespace zorba
{

class user_function;


/******************************************************************************

*******************************************************************************/
class UDFNode
{
  friend class UDFGraph;

protected:
  user_function         * theUDF;
  std::vector<UDFNode*>   theParents;
  std::vector<UDFNode*>   theChildren;
  ulong                   theVisitId;

public:
  UDFNode(user_function* udf) 
    :
    theUDF(udf),
    theVisitId(0)
  {
  }
};


/*******************************************************************************

********************************************************************************/
class UDFHashMapCmp
{
public:

  static bool equal(const user_function* n1, const user_function* n2)
  {
    return n1 == n2;
  }

  static uint32_t hash(const user_function* n)
  {
    return static_cast<uint32_t>(reinterpret_cast<uint64_t>(n));
  }
};


/******************************************************************************
  UDFGraph represents the call-graph among all the UDFs that may be invoked 
  during the evaluation of a given expr E. We call this graph the "call-graph
  of E".

  theExpr    : The expr whose call graph is represented by "this".
  theNodes   : Maps a user_function ptr to the node that represents that udf in
               the graph.
  theRoot    : A "dummy" udf node representing theExpr 
  theVisitId : During a traversal of the graph, we need to know if we reach at
               a node that we have visited already in the same traversal. This
               is done as follows: Every time we start a new traversal, we 
               increment theVisitId, and pass its value to the traversal 
               method(s). Each node has a "visit id" data member. When a
               traversal reaches a node, we check whether the visit id of the
               node is == to the traversal visit id. If true, we know that the
               node has been visited already by the current traversal. Otherwise,
               we set its visit id to the visit id of the traversal.   
*******************************************************************************/
class UDFGraph 
{
  typedef HashMap<user_function*, UDFNode*, UDFHashMapCmp> UDFMap;

protected:
  expr_t     theExpr;
  UDFMap     theNodes;
  UDFNode  * theRoot;
  ulong      theVisitId;

public:
  UDFGraph(expr* e);

  ~UDFGraph();

  void build(const expr* e);

  void optimizeUDFs(CompilerCB* ccb);

  void inferDeterminism();

  void display(std::ostream& o);

protected:
  void build(const expr* curExpr, std::vector<user_function*>& callChain);

  void addEdge(user_function* caller, user_function* callee);

  void optimizeUDFs(CompilerCB* ccb, UDFNode* node, ulong visit);

  bool inferDeterminism(UDFNode* node, ulong visit);

  void display(std::ostream& o, UDFNode* node);
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */


/* vim:set et sw=2 ts=2: */
