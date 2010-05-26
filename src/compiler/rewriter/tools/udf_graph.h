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
  Maps a user_function ptr to the node that represents that udf in the graph.
*******************************************************************************/
class UDFGraph 
{
  typedef HashMap<user_function*, UDFNode*, UDFHashMapCmp> UDFMap;

protected:
  UDFMap     theNodes;
  UDFNode  * theRoot;
  ulong      theVisitId;

public:
  UDFGraph() 
    :
    theNodes(32, false),
    theRoot(NULL),
    theVisitId(0)
  {
  }

  ~UDFGraph();

  void build(const expr* e);

  void optimizeUDFs(CompilerCB* ccb);

  void display(std::ostream& o);

protected:
  void build(const expr* curExpr, std::vector<user_function*>& callChain);

  void addEdge(user_function* caller, user_function* callee);

  void optimizeUDFs(CompilerCB* ccb, UDFNode* node, ulong visit);

  void display(std::ostream& o, UDFNode* node);
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
