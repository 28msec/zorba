/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf (david.graf@28msec.com), Markos Zaharioudakis
 *
 *  Info: This file contains the class declarations of all nodes defined in
 * [http://www.w3.org/TR/xpath-datamodel/#Nodes].
 */

#ifndef XQP_DEFAULT_STORE_NODES
#define XQP_DEFAULT_STORE_NODES


#include "util/Assert.h"
#include "store/api/item.h"
#include "store/naive/ordpath.h"
//#include "store/util/handle_set.h"

namespace xqp
{

class NodeImpl;
class ElementNodeImpl;
class NsBindingsContext;
class QNameItemImpl;

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
  //void move(NodeVector* v);

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

  bool isNode() const                    { return true; }
  bool isAtomic() const                  { return false; }

  Item_t getParent() const               { return theParent; }

  virtual bool equals(Item_t) const;
  virtual uint32_t hash() const          { Assert(0); return 0; }

  virtual xqp_string getBaseURI() const;
  virtual xqp_string getDocumentURI() const;

  virtual Item_t getEBV() const;

  //
  // SimpleStore Methods
  // 
  Item * getParentPtr() const            { return theParent; }
  void setParent(const Item_t& p)        { theParent = p.get_ptr(); }

  void initId();
  unsigned long getTreeId() const        { return theId.getTreeId(); }
  const OrdPath& getId() const           { return theId; }
  void setId(const OrdPathStack& id)     { theId = id; }
  void setId(const OrdPath& id)          { theId = id; }
  void appendIdComponent(long value)     { theId.appendComp(value); } 

  virtual NsBindingsContext* getNsContext() const { Assert(0); return NULL; }

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

  DocumentNodeImpl(
        const DocumentNodeImpl* src,
        bool           typePreserve,
        bool           nsPreserve);

  ~DocumentNodeImpl();

  //
  // Item methods
  //

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::documentNode; }

  Item_t getType() const; 

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

  NodeVector& children()         { return theChildren; }

  bool isConstructed() const     { return theFlags & NodeImpl::IsConstructed; }
  bool isCopy() const            { return theFlags & NodeImpl::IsCopy; }
  bool typePreserve() const      { return theFlags & NodeImpl::TypePreserve; }
  bool nsPreserve() const        { return theFlags & NodeImpl::NsPreserve; }

  NsBindingsContext* getNsContext() const { return NULL; }
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
  Item_t                theName;
  Item_t                theTypeName;
  NodeVector            theChildren;
  NodeVector            theAttributes;
  NsBindingsContext_t   theNsContext;
  uint32_t              theFlags;

public:
  ElementNodeImpl(
        Item*         name,
        Item*         type,
        unsigned long numBindings,
        unsigned long numAttributes);

  ElementNodeImpl(
			  const Item_t&            name,
        const Item_t&            type,
        Iterator_t&              childrenIte,
        Iterator_t&              attributesIte,
        Iterator_t&              namespacesIte,
        const NamespaceBindings& nsBindings,
        bool                     typePreserve,
        bool                     assignId);

  ElementNodeImpl(
        const NodeImpl*        parent,
        const ElementNodeImpl* src,
        bool                   typePreserve,
        bool                   nsPreserve);

  ~ElementNodeImpl();

  //
  // Item methods
  //

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::elementNode; }
  Item_t getType() const                      { return theTypeName; }
  Item_t getNodeName() const                  { return theName; }

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

  NsBindingsContext* getNsContext() const { return theNsContext.get_ptr(); }

  void setNsContext(NsBindingsContext* ctx);

private:
  //disable default copy constructor
  ElementNodeImpl(const ElementNodeImpl& src);
};


/*******************************************************************************

********************************************************************************/
class AttributeNodeImpl : public NodeImpl
{
 private:
  Item_t   theName;
  Item_t   theTypeName;
  Item_t   theLexicalValue;
  Item_t   theTypedValue;

  bool     theIsId;
  bool     theIsIdrefs;
  
 public:
  AttributeNodeImpl (
			  const Item_t& name,
        const Item_t& type,
        const Item_t& lexicalValue,
        const Item_t& typedValue,
        bool          isId,
        bool          isIdrefs,
        bool          assignId);

  AttributeNodeImpl(
        const NodeImpl*          parent,
        const AttributeNodeImpl* src,
        bool                     typePreserve);

  virtual ~AttributeNodeImpl() { }

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::attributeNode; }

  Item_t getType() const { return theTypeName; }

  Item_t getNodeName() const { return theName; }

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
  TextNodeImpl(
        const xqpStringStore_t& content,
        bool                    assignId);

  TextNodeImpl(
        const NodeImpl*     parent,
        const TextNodeImpl* src);

  virtual ~TextNodeImpl() { }
  
  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::textNode; }

  virtual Item_t getType() const;

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
        bool                    assignId);

  PiNodeImpl(const NodeImpl* parent, const PiNodeImpl* src);

  virtual ~PiNodeImpl() { }

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::piNode; }

  Item_t getType() const;

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

  CommentNodeImpl(const NodeImpl* parent, const CommentNodeImpl* src);

  virtual ~CommentNodeImpl() { }

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::commentNode; }

  Item_t getType() const;

  virtual Iterator_t getTypedValue() const;
  virtual Item_t getAtomizationValue() const;
  virtual xqp_string getStringProperty() const { return theContent; }
  virtual xqp_string getStringValue() const    { return theContent; }

  virtual xqp_string show() const;
};


}

#endif
