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

#ifndef ZORBA_SIMPLE_STORE_NODE_VECTOR
#define ZORBA_SIMPLE_STORE_NODE_VECTOR

#include <vector>

#include "store/naive/shared_types.h"

namespace zorba 
{

namespace simplestore 
{


class XmlNode;


/*******************************************************************************
  NodeVector is used to store the children or the attributes of element and
  document nodes.
********************************************************************************/
class NodeVector
{
protected:
  std::vector<XmlNode*> theNodes;

public:
  NodeVector() { }
  NodeVector(ulong size) : theNodes(size) { }

  bool empty() const { return theNodes.empty(); }

  void clear() { theNodes.clear(); }

  ulong size() const { return theNodes.size(); }

  void resize(ulong size) { theNodes.resize(size); }

  XmlNode* get(ulong pos) const { return theNodes[pos]; } 

  ulong find(XmlNode* n);

  void set(XmlNode* n, ulong pos) { theNodes[pos] = n; }

  void push_back(XmlNode* n)  { theNodes.push_back(n); }

  void insert(XmlNode* n, long pos);

  void remove(ulong pos);

  bool remove(XmlNode* n);

  void copy(NodeVector& dest) const;

  void compact();

private:
  NodeVector(const NodeVector& v);
  NodeVector& operator=(const NodeVector& v);
};


}
}

#endif
