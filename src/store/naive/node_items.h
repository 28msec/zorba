/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf (david.graf@28msec.com), Markos Zaharioudakis
 *
 *  Info: This file contains the class declarations of all nodes defined in
 * [http://www.w3.org/TR/xpath-datamodel/#Nodes].
 */

#ifndef XQP_DEFAULT_STORE_NODES
#define XQP_DEFAULT_STORE_NODES

#include <vector>
#include <string>

#include "util/Assert.h"
#include "store/api/item.h"
#include "store/naive/ordpath.h"
#include "store/util/handle_set.h"

namespace xqp
{

class NodeImpl;
class ElementNodeImpl;
class NsBindingsContext;

template <class Object> class rchandle;

typedef rchandle<class Item> Item_t;
typedef rchandle<class NodeImpl> NodeImpl_t;
typedef rchandle<class ElementNodeImpl> ElementNodeImpl_t;

typedef rchandle<class TempSeq> TempSeq_t;

typedef rchandle<class NsBindingsContext> NsBindingsContext_t;


/*******************************************************************************

********************************************************************************/
class NodeVector
{
protected:
  std::vector<Item_t> theNodes;

public:
  NodeVector() { }
  NodeVector(unsigned long size) : theNodes(size) { }

  ~NodeVector() { }

  unsigned long size() const { return theNodes.size(); }
  bool empty() const { return theNodes.empty(); }

  void push_back(const Item_t& item) { theNodes.push_back(item); }

  void resize(unsigned long size) { theNodes.resize(size); }

  const Item_t& operator[](unsigned long i) const { return theNodes[i]; } 
  Item_t& operator[](unsigned long i)             { return theNodes[i]; } 
};


/*******************************************************************************

********************************************************************************/
class NodeImpl : public Item
{
protected:
  OrdPath    theId;
  Item     * theParent;   // Pointer to avoid cyclic smart pointers

public:
  NodeImpl(bool assignId);

  ~NodeImpl() { }

  //
  // Item methods
  //

  bool isNode() const                  { return true; }
  bool isAtomic() const                { return false; }

  Item_t getParent() const             { return theParent; }

  virtual bool equals(Item_t) const;
  virtual uint32_t hash() const        { return 0; }

  virtual xqp_string getBaseURI() const;
  virtual xqp_string getDocumentURI() const;

  virtual Item_t getEBV() const;

  //
  // SimpleStore Methods
  // 

  unsigned long getTreeId() const      { return theId.getTreeId(); }
  const OrdPath& getId() const         { return theId; }
  void setId(const OrdPathStack& id)   { theId = id; }
  void setId(const OrdPath& id)        { theId = id; }
  void appendIdComponent(long value)   { theId.appendComp(value); } 

  void setParent(const Item_t& p)      { theParent = p.get_ptr(); }

  virtual NsBindingsContext_t getNsBindingsContext() const { return NULL; }
};


/*******************************************************************************

********************************************************************************/
class DocumentNodeImpl : public NodeImpl
{
 private:
  xqpStringStore_t   theBaseURI;
  xqpStringStore_t   theDocURI;

  NodeVector         theChildren;

 public:
  DocumentNodeImpl(
        const xqpStringStore_t& baseURI,
        const xqpStringStore_t& documentURI);

  DocumentNodeImpl(
        const xqpStringStore_t& baseURI,
        const xqpStringStore_t& documentURI,
        const Iterator_t&       children,
        bool                    assignId);

  ~DocumentNodeImpl();

  //
  // Item methods
  //

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::documentNode; }

  QNameItem_t getType() const; 

  xqp_string getBaseURI() const     { return theBaseURI; }
  xqp_string getDocumentURI() const { return theDocURI; }

  Iterator_t getChildren() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringProperty() const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  NodeVector& children()            { return theChildren; }
};


/*******************************************************************************
  For xquery node constructors, the current implementation performs eager
  evaluation of the attributes and children of each element node. 

  One way to implement lazy evaluation is the following: "theChildren" data
  member becomes a union type between a NodeVector and an Iterator_t. Initially,
  the active member of this union is the iterator. Every time the iterator is
  used, it computes a number of child nodes and stores them in some local vector.
  If the iterator ever computes all the children, then the iterator is released
  and its local vector is copied to "theChildren", making the NodeVector be the
  active member of the union from now on.
********************************************************************************/
class ElementNodeImpl : public NodeImpl
{
 private:
  QNameItem_t            theName;
  QNameItem_t            theType;
  NodeVector             theChildren;
  NodeVector           * theAttributes;
  NsBindingsContext_t    theNsBindings;

public:
  ElementNodeImpl(
			  const QNameItem_t&       name,
        const QNameItem_t&       type,
        Iterator_t&              childrenIte,
        Iterator_t&              attributesIte,
        Iterator_t&              namespacesIte,
        const NamespaceBindings& nsBindings,
        bool                     copy,
        bool                     newTypes,
        bool                     assignId);
			
  ElementNodeImpl(
        const QNameItem_t&       name,
        const QNameItem_t&       type,
        const NamespaceBindings& nsBindings);

  ~ElementNodeImpl();

  //
  // Item methods
  //

  StoreConsts::NodeKind_t getNodeKind() const  { return StoreConsts::elementNode; }
  QNameItem_t getType() const                  { return theType; }
  QNameItem_t getNodeName() const              { return theName; }

  Iterator_t getAttributes() const;
  Iterator_t getChildren() const;
  NamespaceBindings getNamespaceBindings() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringProperty() const;
  bool getNilled() const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  unsigned long numAttributes() const;

  NodeVector& children()    { return theChildren; }
  NodeVector*& attributes() { return theAttributes; }

  NsBindingsContext_t getNsBindingsContext() const { return theNsBindings; }

  void setNsBindingsContext(const NsBindingsContext_t& parentCtx);
};


/*******************************************************************************

********************************************************************************/
class AttributeNodeImpl : public NodeImpl
{
 private:
  QNameItem_t  theName;
  QNameItem_t  theType;
  Item_t       theLexicalValue;
  Item_t       theTypedValue;

  bool         theIsId;
  bool         theIsIdrefs;
  
 public:
  AttributeNodeImpl (
			  const QNameItem_t& name,
        const QNameItem_t& type,
        const Item_t& lexicalValue,
        const Item_t& typedValue,
        bool isId,
        bool isIdrefs,
        bool assignId);
			
  virtual ~AttributeNodeImpl();

  virtual StoreConsts::NodeKind_t getNodeKind() const;
  QNameItem_t getType() const;

  virtual QNameItem_t getNodeName() const;

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const;
  virtual xqp_string getStringValue() const;

  virtual bool isId() const;
  virtual bool isIdrefs() const;

  virtual xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class TextNodeImpl : public NodeImpl
{
 private:
  xqpStringStore_t theContent;

 public:
  TextNodeImpl(const xqpStringStore_t& content, bool assignId);

  virtual ~TextNodeImpl();
  
  virtual StoreConsts::NodeKind_t getNodeKind() const;
  virtual QNameItem_t getType() const;

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const;
  virtual xqp_string getStringValue() const;
			
  virtual xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class PiNodeImpl : public NodeImpl
{
 private:
  xqpStringStore_t theTarget;
  xqpStringStore_t theData;

public:
  PiNodeImpl(
        const xqpStringStore_t& target,
        const xqpStringStore_t& data,
        bool assignId);

  virtual ~PiNodeImpl();

  virtual StoreConsts::NodeKind_t getNodeKind() const;
  virtual QNameItem_t getType() const;

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const;
  virtual xqp_string getStringValue() const;

  virtual xqp_string getTarget() const;

  virtual xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class CommentNodeImpl : public NodeImpl
{
private:
  xqpStringStore_t theContent;

public:
  CommentNodeImpl(const xqpStringStore_t& content, bool assignId);

  virtual ~CommentNodeImpl();

  virtual StoreConsts::NodeKind_t getNodeKind() const;
  virtual QNameItem_t getType() const;

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const;
  virtual xqp_string getStringValue() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  This iterator is used during the getChildren() method to set the parent
  pointer and the nodeid in each child node of "this" node.
********************************************************************************/
class ChildrenIterator : public Iterator
{
protected:
  NodeImpl_t          theParentNode;
  unsigned long       theStartingId;
  unsigned long       theCurrentPos;

  const NodeVector*   theChildNodes;

public:
  ChildrenIterator(NodeImpl* parent, unsigned long startid);

  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This iterator is used during the getAttributes() method to set the parent
  pointer and the nodeid in each attribute node of "this" node.
********************************************************************************/
class AttributesIterator : public Iterator
{
protected:
  ElementNodeImpl_t   theParentNode;
  unsigned long       theCurrentPos;

  const NodeVector*   theChildNodes;

public:
  AttributesIterator(ElementNodeImpl* parent);

  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This iterator is used to eliminated duplicate nodes in the multiset of nodes
  produced by another iterator.

  theInput     : This is actually a PlanIterWrapper object that wraps the actual
                 runtime iterator that produces the node multiset.
  theHandleSet : A hash-based set used to do the duplicate elimination. The
                 elimination is done based on the values of the pointers that
                 point to the input nodes.
********************************************************************************/
class StoreNodeDistinctIterator : public Iterator
{
protected:
  Iterator_t       theInput;
  HandleSet<Item>  theNodeSet;

public:
  StoreNodeDistinctIterator(const Iterator_t& input) : theInput(input) { }

  ~StoreNodeDistinctIterator() { }

  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This iterator is used to sort by document order the nodes produced by another
  iterator.

  theInput  : This is actually a PlanIterWrapper object that wraps the actual
              runtime iterator that produces the input nodes.
  theNodes  : A vector that stores rchandles to the nodes.
                 elimination is done based on the values of the pointers that
                 point to the input nodes.
********************************************************************************/
class StoreNodeSortIterator : public Iterator
{
protected:
  class ComparisonFunction
  {
  protected:
    bool theAscending;

  public:
    ComparisonFunction(bool asc = true) : theAscending(asc) { }

    bool operator()(const NodeImpl_t& n1, const NodeImpl_t& n2) const
    {
      return (theAscending ?
              n1->getId() < n2->getId() : 
              n1->getId() > n2->getId());
    }
  };

protected:
  Iterator_t               theInput;
  bool                     theAscendant;
  bool                     theDistinct;

  std::vector<NodeImpl_t>  theNodes;
  long                     theCurrentNode;

public:
  StoreNodeSortIterator(const Iterator_t& input,
                        bool ascendant,
                        bool distinct)
    :
    theInput(input),
    theAscendant(ascendant),
    theDistinct(distinct),
    theCurrentNode(-1)
  {
  }

  ~StoreNodeSortIterator() { }

  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************

********************************************************************************/
class NsBindingsContext : public rcobject
{
 private:
  NamespaceBindings    theBindings;
  NsBindingsContext_t  theParentContext;

public:
  NsBindingsContext() {}

  NsBindingsContext(const NamespaceBindings& bindings)
    :
    theBindings(bindings)
  {
  }

  const NamespaceBindings& getBindings() const        { return theBindings; }

  void setParentContext(const NsBindingsContext_t& p) { theParentContext = p; }
  NsBindingsContext_t getParentContext() const        { return theParentContext; } 
};

}

#endif
