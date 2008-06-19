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

#include "common/common.h"

namespace zorba { namespace simplestore {


class XmlNode;
class ConstrNodeVector;


/*******************************************************************************

********************************************************************************/
class NodeVector
{
  friend class XmlNode;
  friend class LoadedNodeVector;
  friend class ConstrNodeVector;

public:
  enum { LOADED, CONSTRUCTED };

protected:
  std::vector<XmlNode*> theNodes;

public:
  NodeVector() { }
  NodeVector(ulong size) : theNodes(size) { }

  virtual ~NodeVector() { }

  bool empty() const            { return theNodes.empty(); }
  ulong size() const            { return theNodes.size(); }

  XmlNode* get(ulong pos) const { return theNodes[pos]; } 
  ulong find(XmlNode* n);

  virtual void set(XmlNode* n, ulong pos, bool shared) = 0;
  virtual void push_back(XmlNode* n, bool shared) = 0;
  virtual void insert(XmlNode* n, ulong i, bool shared) = 0;

  virtual void remove(ulong i) = 0;
  virtual bool remove(XmlNode* n) = 0;

  virtual void clear() = 0;
  virtual void resize(ulong size) = 0;
  virtual void copy(ConstrNodeVector& dest) = 0;
  virtual void compact() = 0;
};


/*******************************************************************************

********************************************************************************/
class LoadedNodeVector : public NodeVector
{
public:
  LoadedNodeVector() : NodeVector() { }
  LoadedNodeVector(ulong size) : NodeVector(size) { }

  ~LoadedNodeVector() { }

  void set(XmlNode* n, ulong pos, bool ) { theNodes[pos] = n; }
  void push_back(XmlNode* n, bool )      { theNodes.push_back(n); }
  void insert(XmlNode* n, ulong i, bool shared);
  void remove(ulong i);
  bool remove(XmlNode* n);

  void clear()                           { theNodes.clear(); }
  void resize(ulong size)                { theNodes.resize(size); }
  void copy(ConstrNodeVector& dest);
  void compact();

private:
  LoadedNodeVector(const LoadedNodeVector& v);
  LoadedNodeVector& operator=(const LoadedNodeVector& v);
};


/*******************************************************************************

********************************************************************************/
class ConstrNodeVector : public NodeVector
{
  friend class LoadedNodeVector;

private:
  std::vector<bool> theBitmap;

public:
  ConstrNodeVector() : NodeVector() { }
  ConstrNodeVector(ulong size);

  ~ConstrNodeVector()  { clear(); }

  void set(XmlNode* n, ulong pos, bool shared);
  void push_back(XmlNode* n, bool shared);
  void insert(XmlNode* n, ulong i, bool shared);
  void remove(ulong i);
  bool remove(XmlNode* n);

  void clear();
  void resize(ulong size);
  void copy(ConstrNodeVector& dest);
  void copy(LoadedNodeVector& dest)  { dest.theNodes = theNodes; }
  void compact();

private:
  ConstrNodeVector(const ConstrNodeVector& v);
  ConstrNodeVector& operator=(const ConstrNodeVector& v);
};


}
}

#endif
