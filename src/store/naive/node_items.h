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
  Item_t  * theNodes;

public:
  NodeVector() : theNodes(NULL) { }

  NodeVector(unsigned long size);

  ~NodeVector();

  NodeVector& operator=(const NodeVector& v);

  unsigned long size() const;
  bool empty() const { return theNodes == 0; }

  void clear();
  void resize(unsigned long size);
  void truncate();
  void move(NodeVector* v);

  void push_back(const Item_t& item, unsigned long index);

  const Item_t& operator[](unsigned long i) const { return theNodes[i+1]; } 
  Item_t& operator[](unsigned long i)             { return theNodes[i+1]; } 

private:
  NodeVector(const NodeVector& v);
};


/*******************************************************************************

********************************************************************************/
class NodeImpl : public Item
{
  friend class DocumentNodeImpl;
  friend class ElementNodeImpl;

public:
  enum NodeFlags
  {
    IsConstructed     =  1,
    IsCopy            =  2,
    TypePreserve      =  4,
    NsPreserve        =  8,
    NsInherit         = 16,
    HaveLocalBindings = 32
  };

protected:
  OrdPath    theId;
  Item     * theParent;   // Pointer to avoid cyclic smart pointers

public:
  NodeImpl(bool assignId);

  virtual ~NodeImpl() { }

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
  Item * getParentPtr() const          { return theParent; }
  void setParent(const Item_t& p)      { theParent = p.get_ptr(); }

  void initId();
  unsigned long getTreeId() const      { return theId.getTreeId(); }
  const OrdPath& getId() const         { return theId; }
  void setId(const OrdPathStack& id)   { theId = id; }
  void setId(const OrdPath& id)        { theId = id; }
  void appendIdComponent(long value)   { theId.appendComp(value); } 

  virtual NsBindingsContext_t getNsBindingsCtx() const { return NULL; }

  virtual bool haveLocalBindings() const { Assert(0); return false; }
  virtual bool isConstructed() const     { Assert(0); return false; }
  virtual bool isCopy() const            { Assert(0); return false; }
  virtual bool typePreserve() const      { Assert(0); return false; }
  virtual bool nsPreserve() const        { Assert(0); return false; }
  virtual bool nsInherit() const         { Assert(0); return false; }
};


/*******************************************************************************

********************************************************************************/
class DocumentNodeImpl : public NodeImpl
{
 private:
  xqpStringStore_t   theBaseURI;
  xqpStringStore_t   theDocURI;

  NodeVector         theChildren;
  uint32_t           theFlags;

 public:
  DocumentNodeImpl(
        const xqpStringStore_t& baseURI,
        const xqpStringStore_t& documentURI);

  DocumentNodeImpl(
        const xqpStringStore_t& baseURI,
        const xqpStringStore_t& documentURI,
        const Iterator_t&       children,
        bool                    assignId);

  DocumentNodeImpl(const DocumentNodeImpl* src);

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

  bool isConstructed() const        { return theFlags & NodeImpl::IsConstructed; }
  bool isCopy() const               { return theFlags & NodeImpl::IsCopy; }
};


/*******************************************************************************
  For xquery node constructors, the current implementation performs eager
  evaluation of the attributes and children of each element node. 

  One way to implement lazy evaluation is the following: "theChildren" data
  member becomes a union type between a NodeVector and a TempSeq_t. The temp
  sequence wraps the plan iterator that actually produces the children. Initially,
  the active member of this union is the temp seq. Every time getChildren() is
  called, it computes a number of child nodes and stores them in the temp seq.
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
  NodeVector             theAttributes;
  NsBindingsContext_t    theNsBindings;
  uint32_t               theFlags;

public:
  ElementNodeImpl(
        const QNameItem_t&       name,
        const QNameItem_t&       type,
        const NamespaceBindings& nsBindings);

  ElementNodeImpl(
			  const QNameItem_t&       name,
        const QNameItem_t&       type,
        Iterator_t&              childrenIte,
        Iterator_t&              attributesIte,
        Iterator_t&              namespacesIte,
        const NamespaceBindings& nsBindings,
        bool                     typePreserve,
        bool                     assignId);

  ElementNodeImpl(
        const ElementNodeImpl* src,
        bool                   typePreserve,
        bool                   nsPreserve,
        bool                   isRoot);

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
  NodeVector& attributes()  { return theAttributes; }

  bool isConstructed() const     { return theFlags & NodeImpl::IsConstructed; }
  bool isCopy() const            { return theFlags & NodeImpl::IsCopy; }

  bool typePreserve() const      { return theFlags & NodeImpl::TypePreserve; }
  bool nsPreserve() const        { return theFlags & NodeImpl::NsPreserve; }
  bool nsInherit() const         { return theFlags & NodeImpl::NsInherit; }

  bool haveLocalBindings() const { return theFlags & NodeImpl::HaveLocalBindings; }

  NsBindingsContext_t getNsBindingsCtx() const { return theNsBindings; }

  void setNsBindingsCtx(NsBindingsContext* parentCtx);

private:
  //disable default copy constructor
  ElementNodeImpl(const ElementNodeImpl& src);
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

  AttributeNodeImpl(
        const AttributeNodeImpl* src,
        bool                     typePreserve);

  virtual ~AttributeNodeImpl() { }

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::attributeNode; }

  QNameItem_t getType() const { return theType; }

  QNameItem_t getNodeName() const { return theName; }

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringProperty() const;
  xqp_string getStringValue() const;

  bool isId() const     { return theIsId; }
  bool isIdrefs() const { return theIsIdrefs; }

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

  TextNodeImpl(const TextNodeImpl* src);

  virtual ~TextNodeImpl() { }
  
  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::textNode; }

  virtual QNameItem_t getType() const;

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const  { return theContent; }
  virtual xqp_string getStringValue() const     { return theContent; }
			
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

  PiNodeImpl(const PiNodeImpl* src);

  virtual ~PiNodeImpl() { }

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::piNode; }

  QNameItem_t getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringProperty() const { return theData; }
  xqp_string getStringValue() const    { return theData; }

  xqp_string getTarget() const { return theTarget; }

  xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class CommentNodeImpl : public NodeImpl
{
private:
  xqpStringStore_t theContent;

public:
  CommentNodeImpl(const xqpStringStore_t& content, bool assignId);

  CommentNodeImpl(const CommentNodeImpl* src);

  virtual ~CommentNodeImpl() { }

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::commentNode; }

  QNameItem_t getType() const;

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const { return theContent; }
  virtual xqp_string getStringValue() const    { return theContent; }

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

  NodeVector&         theChildNodes;

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

  NodeVector&         theChildNodes;

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

  const NamespaceBindings& getBindings() const    { return theBindings; }

  void setParentContext(NsBindingsContext* p)     { theParentContext = p; }
  NsBindingsContext* getParentContext() const     { return theParentContext.get_ptr(); } 
};

}

#endif
