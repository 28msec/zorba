
#ifndef ZORBA_SIMPLE_STORE_NODE_VECTOR
#define ZORBA_SIMPLE_STORE_NODE_VECTOR

#include <vector>

#include "common/common.h"
#include "errors/fatal.h"

namespace zorba { namespace store {


class XmlNode;


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
  virtual void copy(const NodeVector& v) = 0;
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
  void copy(const NodeVector& v)         { ZORBA_FATAL(0, ""); }

private:
  LoadedNodeVector(const LoadedNodeVector& v);
  LoadedNodeVector& operator=(const LoadedNodeVector& v);
};


/*******************************************************************************

********************************************************************************/
class ConstrNodeVector : public NodeVector
{
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
  void copy(const NodeVector& v);

private:
  ConstrNodeVector(const ConstrNodeVector& v);
  ConstrNodeVector& operator=(const ConstrNodeVector& v);
};


}
}

#endif
