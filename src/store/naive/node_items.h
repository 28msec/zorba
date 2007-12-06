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
class NsBindingsContext;

template <class Object> class rchandle;

typedef rchandle<class Item> Item_t;
typedef rchandle<class NodeImpl> NodeImpl_t;

typedef rchandle<class TempSeq> TempSeq_t;

typedef rchandle<class NsBindingsContext> NsBindingsContext_t;


/*******************************************************************************

********************************************************************************/
class NodeImpl : public Item
{
protected:
  Item     * theParent;   // Pointer to avoid cyclic smart pointers

  OrdPath    theId;

public:
  NodeImpl() : theParent(NULL) {}

  explicit NodeImpl(const Item_t& parent) : theParent(parent.get_ptr()) {}

  ~NodeImpl() { }

  virtual bool isNode() const             { return true; }
  virtual bool isAtomic() const           { return false; }

  const OrdPath& getId() const            { return theId; }
  void setId(const OrdPathStack& id)      { theId = id; }

  virtual bool equals(Item_t) const;
  virtual uint32_t hash() const           { return 0; }

  virtual Item_t getParent() const        { return theParent; }
  virtual void setParent(const Item_t& p) { theParent = p.get_ptr(); }

  virtual void setChildren(const TempSeq_t& seq) { Assert(0); }

  virtual NsBindingsContext_t getNsBindingsContext() const { return NULL; }

  virtual xqp_string getBaseURI() const;
  virtual xqp_string getDocumentURI() const;

  virtual Item_t getEBV() const;
};


/*******************************************************************************

********************************************************************************/
class DocumentNodeImpl : public NodeImpl
{
 private:
  xqpStringStore_t theBaseURI;
  xqpStringStore_t theDocURI;

  TempSeq_t        theChildren;

 public:
  DocumentNodeImpl(
        const xqpStringStore_t& baseURI,
        const xqpStringStore_t& documentURI);

  DocumentNodeImpl(
        const xqpStringStore_t& baseURI,
        const xqpStringStore_t& documentURI,
        const TempSeq_t& children);

  virtual ~DocumentNodeImpl();

  virtual StoreConsts::NodeKind_t getNodeKind() const;
  QNameItem_t getType() const;

  virtual xqp_string getBaseURI() const;
  virtual xqp_string getDocumentURI() const;

  virtual Iterator_t getChildren() const;
  virtual void setChildren(const TempSeq_t& seq);

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const;

  virtual xqp_string show() const;

  // Used when zorba supports DTD
  // xqp_string getUnparsedEntityPublicId() const;
  // xqp_string getunparsedEntitySystemId() const;
};


/*******************************************************************************

********************************************************************************/
class ElementNodeImpl : public NodeImpl
{
 private:
  QNameItem_t          theName;
  QNameItem_t          theType;
  TempSeq_t            theChildren;
  TempSeq_t            theAttributes;
  TempSeq_t            theNsUris;
  NsBindingsContext_t  theNsBindings;

 public:
  ElementNodeImpl(
        const QNameItem_t& name,
        const QNameItem_t& type,
        TempSeq_t& seqAttributes,
        const NamespaceBindings& nsBindings);

  ElementNodeImpl(
			  const QNameItem_t& name,
        const QNameItem_t& type,
        TempSeq_t& seqChildren,
        TempSeq_t& seqAttributes,
        TempSeq_t& seqNsUris,
        const NamespaceBindings& nsBindings,
        bool copy,
        bool newTypes);
			
  virtual ~ElementNodeImpl();

  virtual StoreConsts::NodeKind_t getNodeKind() const;
  QNameItem_t getType() const;

  virtual QNameItem_t getNodeName() const;

  virtual Iterator_t getAttributes() const;
  virtual Iterator_t getChildren() const;
  virtual void setChildren(const TempSeq_t& seq);

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const;

  virtual bool getNilled() const;

  virtual NamespaceBindings getNamespaceBindings() const;

  NsBindingsContext_t getNsBindingsContext() const { return theNsBindings; }

  void setNsBindingsContext(const NsBindingsContext_t& parentCtx);

  virtual xqp_string show() const;
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
        bool isIdrefs);
			
  AttributeNodeImpl(
			  const Item_t& parent,
        const QNameItem_t& name,
        const QNameItem_t& type,
        const Item_t& lexicalValue,
        const Item_t& typedValue,
        bool isId,
        bool isIdrefs);
			
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
  TextNodeImpl(const xqpStringStore_t& content);
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
  PiNodeImpl(const xqpStringStore_t& target, const xqpStringStore_t& data);

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
  CommentNodeImpl(const xqpStringStore_t& content);
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
  This iterator is used during the getChildren() or getAttributes() methods
  to set the parent pointer to each child or attribute node of "this" node.
********************************************************************************/
class ChildrenIterator : public Iterator
{
protected:
  Iterator_t  theInput;
  NodeImpl_t  theParentNode;

public:
  ChildrenIterator(const Iterator_t& input, NodeImpl* parent)
    :
    theInput(input),
    theParentNode(parent)
  {
  }

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
  Iterator_t           theInput;
  std::vector<Item_t>  theNodes;

public:
  StoreNodeSortIterator(const Iterator_t& input) : theInput(input) { }

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

} /* namespace xqp */

#endif /* XQP_NODE_ITEMS_H */
