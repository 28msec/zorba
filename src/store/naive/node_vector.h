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
public:
  typedef std::vector<XmlNode*>::iterator iterator;

public:
  std::vector<XmlNode*> theNodes;

public:
  NodeVector() { }

  NodeVector(vsize_t size) : theNodes(size) { }

  bool empty() const { return theNodes.empty(); }

  void clear() { theNodes.clear(); }

  vsize_t size() const { return theNodes.size(); }

  void resize(vsize_t size) { theNodes.resize(size); }

  XmlNode* get(vsize_t pos) const { return theNodes[pos]; } 

  void set(XmlNode* n, vsize_t pos) { theNodes[pos] = n; }

  void push_back(XmlNode* n) { theNodes.push_back(n); }

  void insert(XmlNode* n, vsize_t pos);

  void remove(vsize_t pos);

  iterator remove(XmlNode* n);

  void compact();

private:
  NodeVector(const NodeVector& v);
  NodeVector& operator=(const NodeVector& v);
};


}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
