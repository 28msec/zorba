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

#ifndef ZORBA_SIMPLE_STORE_NODE_ITEMS
#define ZORBA_SIMPLE_STORE_NODE_ITEMS

#include <stack>
#include <vector>

#include <zorba/config.h>
#include <zorba/error.h>

#include "store_defs.h"
#include "shared_types.h"
#include "text_node_content.h"
#include "item_vector.h"
#include "ordpath.h"
#include "nsbindings.h" // TODO remove by introducing explicit destructors
#include "tree_id.h"
#include "simple_store.h"

// Note: whether the EMBEDED_TYPE is defined or not is done in store_defs.h
#ifndef EMBEDED_TYPE
#include "hashmap_nodep.h"
#endif

#ifndef ZORBA_NO_FULL_TEXT
#include <zorba/locale.h>
#include <zorba/tokenizer.h>
#include "ft_token_store.h"
#endif /* ZORBA_NO_FULL_TEXT */

#include "store/api/item.h"

#include "diagnostics/assert.h"
#include "zorbautils/fatal.h"
#include "zorbautils/hashfun.h"

#include "zorbatypes/zstring.h"


namespace zorba
{

namespace store
{
  class CopyMode;
}


namespace simplestore
{

class AttributeNode;
class CommentNode;
class DocumentNode;
class ElementNode;
class GuideNode;
class InternalNode;
class NsBindingsContext;
class PiNode;
class TextNode;

class UpdatePrimitive;
class UpdDelete;
class UpdInsertChildren;
class UpdInsertSiblings;
class UpdInsertAttributes;
class UpdReplaceChild;
class UpdReplaceAttribute;
class UpdReplaceElemContent;
class UpdRenameElem;
class UpdReplaceAttrValue;
class UpdRenameAttr;
class UpdReplaceTextValue;
class UpdReplacePiValue;
class UpdRenamePi;
class UpdReplaceCommentValue;
class NodeTypeInfo;

class Collection;

typedef std::vector<NodeTypeInfo> TypeUndoList;

typedef rchandle<NsBindingsContext> NsBindingsContext_t;

#ifndef ZORBA_NO_FULL_TEXT
class XmlNodeTokenizerCallback;
#endif /* ZORBA_NO_FULL_TEXT */


#define NODE_STOP \
  ZORBA_FATAL(0, "Invalid method invocation on " \
              << store::StoreConsts::toString(getNodeKind()))


#ifndef NDEBUG

#define NODE_TRACE(level, msg)                \
{                                             \
  if (level <= GET_STORE().getTraceLevel())   \
    std::cout << msg << std::endl;            \
}

#define NODE_TRACE1(msg) NODE_TRACE(1, msg);
#define NODE_TRACE2(msg) NODE_TRACE(2, msg);
#define NODE_TRACE3(msg) NODE_TRACE(3, msg);

#else

#define NODE_TRACE(msg)
#define NODE_TRACE1(msg)
#define NODE_TRACE2(msg)
#define NODE_TRACE3(msg)

#endif


/*******************************************************************************

  theRefCount    : It is the sum of theRefCounts of all the nodes belonging to
                   this tree. Individual nodes are not destroyed when their
                   refCount goes to 0. Instead, nodes belonging to a tree are all
                   destroyed together when theRefCount of the tree goes to 0
                   (i.e. when there are no refs to any of the nodes in the tree).
  theRCLock      : Protects theRefCount

  theId          : An internally generated id for the tree. The id uniquely
                   identifies the tree within its containing collection (see
                   Collection::createTreeId() method). Trees that do not
                   belong to any collection, are considered to belong to a
                   "virtual" collection (with collection id equal to 0), and
                   their id is created by the SimpleStore::createId() method.
                   theId it is guaranteed to be stable during the lifetime of
                   the tree, but may be reused after the tree is destroyed.
                   theId is used in building node URIs that are returned to
                   the application. It is not meant to be used (at least not
                   directly) to sort nodes in doc order.
  thePos         : The position of this tree within its containing collection.
                   After inserting/deleting one or more nodes in/from the middle

  theBaseUri     : The base uri property of the tree's root node.
  theDocUri      : A user provided uri for the tree (may be NULL).

  theCollection  : The collection where this xml tree belongs to, if any. An xml
                   tree may belong to at most one collection at a time.
  theRootNode    : The root node of the tree.

  theIsValidated : True if the tree has ever undergone schema validation.
  theIsRecursive : True if the tree contains at least one pair of element nodes
                   that have the same tag name and are in an ancestor-descendant
                   relationship with each other.
********************************************************************************/
class XmlTree
{
  friend class XmlNode;

  // make sure that only created by the factory
  friend class NodeFactory;

#ifndef EMBEDED_TYPE
  typedef NodePointerHashMap<store::Item_t> NodeTypeMap;
#endif

protected:
  mutable long              theRefCount;
  SYNC_CODE(mutable RCLock  theRCLock;)

  TreeId                    theId;
  xs_integer                thePos;

  Collection              * theCollection;

  XmlNode                 * theRootNode;

#ifdef DATAGUIDE
  GuideNode               * theDataGuideRootNode;
#endif

  bool                      theIsValidated;
  bool                      theIsRecursive;

#ifndef EMBEDED_TYPE
  NodeTypeMap             * theTypesMap;
#endif

#ifndef ZORBA_NO_FULL_TEXT
  FTTokenStore              theTokens;
#endif

protected:
  XmlTree(XmlNode* root, const TreeId& id);

public:
  XmlTree();

  ~XmlTree() { theRootNode = 0; }

  void free();

  long getRefCount() const { return theRefCount; }

  long& getRefCount()      { return theRefCount; }

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  void setId(const TreeId& id) { theId = id; }

  const TreeId& getId() const { return theId; }

  ulong getCollectionId() const;

  const Collection* getCollection() const { return theCollection; }

private:
friend class zorba::simplestore::Collection;
  // Allows a collection to claim ownership of a node it already owns, but
  // which does not have the backpointer yet.
  void claimedByCollection(Collection* coll);
  
public:
  void setCollection(Collection* coll, xs_integer pos);

  void setPosition(xs_integer pos) { thePos = pos; }

  xs_integer getPosition() const { return thePos; }

  XmlNode* getRoot() const { return theRootNode; }

  void setRoot(XmlNode* root) { theRootNode = root; }

  bool isValidated() const { return theIsValidated; }

  void markValidated() { theIsValidated = true; }

  void setRecursive() { theIsRecursive = true; }

  bool isRecursive() const { return theIsRecursive; }

#ifdef DATAGUIDE
  GuideNode* getDataGuide() const { return theDataGuideRootNode; }

  void setDataGuide(GuideNode* root) { theDataGuideRootNode = root; }
#endif

#ifndef EMBEDED_TYPE
  store::Item* getType(const XmlNode* n) const;

  void addType(const XmlNode* n, store::Item_t& type);

  void setType(const XmlNode* n, store::Item_t& type);

  void removeType(const XmlNode* n);

  void copyTypesMap(const XmlTree* source);
#endif

#ifndef ZORBA_NO_FULL_TEXT
  FTTokenStore& getTokenStore() { return theTokens; }
#endif /* ZORBA_NO_FULL_TEXT */
};


/******************************************************************************

  Node identification: A node is uniquely and globally identified by a
  composite key consisting of: the id of the containing collection, the id of
  the containing tree, and the ordpath of the node within its containing tree.

 ******************************************************************************/

class XmlNode : public store::Item
{
  friend class XmlTree;
  friend class NodeFactory;
  friend class InternalNode;
  friend class DocumentNode;
  friend class ElementNode;
  friend class AttributeNode;
  friend class TextNode;
  friend class PiNode;
  friend class CommentNode;
  friend class ConnectorNode;

  friend class PULImpl;
  friend class CollectionPul;
  friend class UpdDelete;
  friend class UpdInsertSiblings;
  friend class UpdReplaceChild;
  friend class UpdReplaceContent;
  friend class UpdReplaceAttribute;
  friend class UpdReplaceAttrValue;
  friend class UpdReplaceTextValue;

  friend class BasicItemFactory;
  friend class FastXmlLoader;
  friend class DtdXmlLoader;

public:
  enum NodeFlags
  {
    // Encodes the kind of the node (document, element, attribute, etc.)
    NodeKindMask          = 0x7,

    // For element nodes only.
    HaveLocalBindings     = 0x80,

    // For element nodes only.
    HaveBaseUri           = 0x10,

    // For element nodes only. Set if the target element node has a typed value.
    // The only case when an element node does not have a typed value is when 
    // the type of the node is complex with complex content, but with no mixed 
    //content allowed.
    HaveTypedValue        = 0x20,

    // For element nodes only. Set if the target element node has a complex 
    // type with empty content. In this case, the typed value of the node is
    // the empty sequence.
    HaveEmptyTypedValue   = 0x40,

    // For text nodes only. Set if the text node is actually used to store the
    // typed value of its parent element node. In such a case, the remaining
    // children (if any) of the parent node can be comment and/or pi nodes only.
    IsTyped               = 0x80,

    // For text and attribute nodes only. Set if the typed value stored in the
    // node is actually a sequence of atomic items.
    HaveListValue         = 0x100,

    // For attribute nodes only.
    IsBaseUri             = 0x800,

    // For attribute nodes only.
    IsHidden              = 0x1000,

    // For element nodes only.
    IsInSubstGroup        = 0x2000,

    // For element nodes only. The flag is set for a node N if there is another
    // node M in its subtree such that N and M have the same name.
    IsRecursive           = 0x4000,

#ifndef EMBEDED_TYPE
    // For element and attribute nodes only. The flag is set if the node has
    // a type other than untyped (for elements) or untypedAtomic (for attributes)
    HaveType              = 0x8000,
#endif

    // For any kind of node. Set if an identifier has been generated for the node
    // (see SimpleStore::getNodeReference() method).
    HaveReference         = 0x10000,

    IsConnectorNode       = 0x20000
  };

protected:
  InternalNode    * theParent;
  uint32_t          theFlags;

private:
#ifndef TEXT_ORDPATH
  static long compareInSameTree(const XmlNode* n1, const XmlNode* n2);
#endif

protected:
  XmlNode() : theParent(NULL)
  {
  }

  XmlNode(store::StoreConsts::NodeKind k) : Item(), theParent(NULL)
  {
    theFlags = (uint32_t)k;
  }

  XmlNode(
      XmlTree* tree,
      InternalNode* parent,
      store::StoreConsts::NodeKind nodeKind);

  virtual void getBaseURIInternal(zstring& uri, bool& local) const;

  void attach(InternalNode* parent, csize pos);

  void detach();

  void destroy(bool removeType);

  bool disconnect(csize& pos);

  void connect(InternalNode* node, csize pos);

#ifndef ZORBA_NO_FULL_TEXT
  virtual void tokenize( XmlNodeTokenizerCallback& );
#endif

private:
  virtual void setTree(const XmlTree* t);

  void destroyInternal(bool removeType);

public:

#ifndef NDEBUG
  virtual ~XmlNode();
#else
  virtual ~XmlNode() {}
#endif

  SYNC_CODE(RCLock* getRCLock() const { return getTree()->getRCLock(); })

  void free()
  {
    if (getTree() != NULL)
      getTree()->free();
  }

  //
  // Item methods
  //

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return (store::StoreConsts::NodeKind)(theFlags & NodeKindMask);
  }

  const store::Collection* getCollection() const
  {
    assert(!isConnectorNode());
    return reinterpret_cast<const store::Collection*>(getTree()->getCollection());
  }

  virtual void getDocumentURI(zstring& uri) const
  {
    ;
  }

  store::Item* getParent() const
  {
    return reinterpret_cast<store::Item*>(theParent);
  }

  bool equals(
      const store::Item* other,
      long timezone = 0,
      const XQPCollator* aCollation = 0) const
  {
    assert(!isConnectorNode());
    return this == other;
  }

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    assert(!isConnectorNode());
    XmlNode* node = const_cast<XmlNode*>(this);
    return hashfun::h32((void*)(&node), sizeof(node), FNV_32_INIT);
  }

  inline long compare2(const XmlNode* other) const;

  void getBaseURI(zstring& uri) const
  {
    assert(!isConnectorNode());
    bool local = false;
    getBaseURIInternal(uri, local);
  }

  bool getEBV() const;

  store::Item* copy(store::Item* parent, const store::CopyMode& copymode) const;

  virtual store::Item_t getNilled() const 
  {
    assert(!isConnectorNode());
    return 0; 
  }

  virtual bool isId() const 
  {
    assert(!isConnectorNode());
    return false;
  }

  virtual bool isIdRefs() const 
  {
    assert(!isConnectorNode());
    return false;
  }

  bool isValidated() const 
  {
    assert(!isConnectorNode());
    return getTree()->isValidated();
  }

  void markValidated()
  {
    assert(!isConnectorNode());
    assert(theParent == NULL);
    getTree()->markValidated();
  }

  virtual void finalizeNode() { }

  //
  // SimpleStore Methods
  //

  XmlTree* getTree() const { return (XmlTree*)theUnion.treeRCPtr; }

  const TreeId& getTreeId() const { return getTree()->getId(); }

  XmlNode* getRoot() const { return getTree()->getRoot(); }

  void setCollection(Collection* coll, xs_integer pos)
  {
    assert(!isConnectorNode());
    getTree()->setCollection(coll, pos);
  }

  ulong getCollectionId() const 
  {
    assert(!isConnectorNode());
    return getTree()->getCollectionId(); 
  }

  void setId(XmlTree* tree, const OrdPathStack* op);

  void setParent(InternalNode* p) { theParent = p; }

#ifdef DATAGUIDE
  GuideNode* getDataGuide() const { return getTree()->getDataGuide(); }
#endif

  virtual XmlNode* copyInternal(
      InternalNode* rootParent,
      InternalNode* parent,
      csize pos,
      const XmlNode* rootCopy,
      const store::CopyMode& copyMode) const = 0;

  void setToUntyped();

  void removeType(UpdatePrimitive& upd);

  void restoreType(TypeUndoList& undoList);

  void insertSiblingsBefore(UpdInsertChildren& upd);

  void insertSiblingsAfter(UpdInsertChildren& upd);

  uint32_t getFlags() const { return theFlags; }

  void setFlags(uint32_t flags) { theFlags = flags; }

  bool haveReference() const { return (theFlags & HaveReference) != 0; }

  void setHaveReference() { theFlags |= HaveReference; }

  void resetHaveReference() { theFlags &= ~HaveReference; }

  bool isConnectorNode() const { return (theFlags & IsConnectorNode) != 0; }

#ifndef ZORBA_NO_FULL_TEXT
  FTTokenIterator_t getTokens( 
      TokenizerProvider const&,
      Tokenizer::Numbers&,
      locale::iso639_1::type,
      bool = false ) const;
#endif /* ZORBA_NO_FULL_TEXT */
};


/******************************************************************************

*******************************************************************************/
class ConnectorNode : public XmlNode
{
  friend class XmlNode;

protected:
  XmlNode_t  theNode;

protected:
  ConnectorNode(
      XmlTree* tree,
      InternalNode* parent,
      const XmlNode* child);

public:
  XmlNode* getNode() const { return theNode.getp(); }

  store::Item* getNodeName() const { return theNode->getNodeName(); }

  store::Item* getType() const { return theNode->getType(); }

  zstring getStringValue() const { return theNode->getStringValue(); }

  void getStringValue2(zstring& val) const { theNode->getStringValue2(val); }

  void appendStringValue(zstring& buf) const { theNode->appendStringValue(buf); }

  XmlNode* copyInternal(
      InternalNode* rootParent,
      InternalNode* parent,
      csize pos,
      const XmlNode* rootCopy,
      const store::CopyMode& copyMode) const;

  zstring show() const;
};


/******************************************************************************

*******************************************************************************/
class OrdPathNode : public XmlNode
{
  friend class XmlTree;
  friend class NodeFactory;

  friend class XmlNode;
  friend class InternalNode;
  friend class DocumentNode;
  friend class ElementNode;
  friend class AttributeNode;
  friend class TextNode;
  friend class PiNode;
  friend class CommentNode;

protected:
  OrdPath           theOrdPath;

protected:
  OrdPathNode() : XmlNode()
  {
  }

  OrdPathNode(store::StoreConsts::NodeKind k) : XmlNode(k)
  {
  }

  OrdPathNode(
      XmlTree* tree,
      InternalNode* parent,
      bool append,
      csize pos,
      store::StoreConsts::NodeKind nodeKind);

  virtual ~OrdPathNode() {}

public:
  const OrdPath& getOrdPath() const { return theOrdPath; }

  OrdPath& getOrdPath() { return theOrdPath; }

  void setOrdPath(
        InternalNode* parent,
        bool append,
        csize pos,
        store::StoreConsts::NodeKind nodeKind);

  // Looks for a descendant node with the ordpath aOrdPath and puts it into the
  // aResult variable. aAttribute specifies whether to look for an attribute or
  // not.
  bool
  getDescendantNodeByOrdPath(
      const OrdPath& aOrdPath,
      store::Item_t& aResult,
      bool aAttribute = false) const;

  virtual bool
  isAncestor(const store::Item_t&) const;

  virtual bool
  isFollowingSibling(const store::Item_t&) const;

  virtual bool
  isFollowing(const store::Item_t&) const;

  virtual bool
  isDescendant(const store::Item_t&) const;

  virtual bool
  isPrecedingSibling(const store::Item_t&) const;

  virtual bool
  isPreceding(const store::Item_t&) const;

  virtual bool
  isChild(const store::Item_t&) const;

  virtual bool
  isParent(const store::Item_t&) const;

  virtual store::Item_t
  getLevel() const;

  virtual store::Item_t
  leastCommonAncestor(const store::Item_t&) const;
};


/*******************************************************************************
  Base class for element and document nodes
********************************************************************************/
class InternalNode : public OrdPathNode
{
  friend class XmlNode;
  friend class OrdPathNode;
  friend class ElementNode;
  friend class AttributeNode;
  friend class TextNode;
  friend class PiNode;
  friend class CommentNode;
  friend class ConnectorNode;
  friend class UpdPut;
  friend class CollectionPul;
  friend class SimpleStore;

public:
  typedef std::vector<XmlNode*> NodeVector;

  typedef std::vector<XmlNode*>::iterator iterator;

  typedef std::vector<XmlNode*>::const_iterator const_iterator;

  typedef std::vector<XmlNode*>::reverse_iterator reverse_iterator;

  typedef std::vector<XmlNode*>::const_reverse_iterator const_reverse_iterator;

protected:
  std::vector<XmlNode*> theNodes;
  csize                 theNumAttrs;
  NsBindingsContext_t   theNsContext;

  InternalNode() {}

  InternalNode(store::StoreConsts::NodeKind nodeKind)
    :
    OrdPathNode(nodeKind),
    theNumAttrs(0)
  {
  }

  InternalNode(
      XmlTree* tree,
      InternalNode* parent,
      bool append,
      csize pos,
      store::StoreConsts::NodeKind nodeKind)
    :
    OrdPathNode(tree, parent, append, pos, nodeKind),
    theNumAttrs(0)
  {
  }

public:
  //
  // SimpleStore Methods
  //

  // To be used by the loader ONLY!
  NodeVector& nodes() { return theNodes; }

  csize numChildren() const { return theNodes.size() - theNumAttrs; }

  iterator childrenBegin() { return theNodes.begin() + theNumAttrs; }

  const_iterator childrenBegin() const { return theNodes.begin() + theNumAttrs; }

  iterator childrenEnd() { return theNodes.end(); }

  const_iterator childrenEnd() const { return theNodes.end(); }

  reverse_iterator childrenRBegin() { return theNodes.rbegin(); }

  const_reverse_iterator childrenRBegin() const { return theNodes.rbegin(); }

  reverse_iterator childrenREnd() { return theNodes.rend() - theNumAttrs; }

  const_reverse_iterator childrenREnd() const { return theNodes.rend() - theNumAttrs; }

  XmlNode* getChild(csize i) const 
  {
    XmlNode* child = theNodes[theNumAttrs + i];

    if (child->isConnectorNode())
      return static_cast<ConnectorNode*>(child)->getNode();

    return child;
  }

  XmlNode* getChild(const_iterator& ite) const
  {
    if ((*ite)->isConnectorNode())
      return static_cast<ConnectorNode*>(*ite)->getNode();

    return *ite;
  }

  csize numAttrs() const { return theNumAttrs; }

  iterator attrsBegin() { return theNodes.begin(); }

  const_iterator attrsBegin() const { return theNodes.begin(); }

  iterator attrsEnd() { return theNodes.begin() + theNumAttrs; }

  const_iterator attrsEnd() const { return theNodes.begin() + theNumAttrs; }

  AttributeNode* getAttr(csize i) const
  {
    XmlNode* attr = theNodes[i];

    if (attr && attr->isConnectorNode())
    {
      return reinterpret_cast<AttributeNode*>
             (static_cast<ConnectorNode*>(attr)->getNode());
    }
    return reinterpret_cast<AttributeNode*>(attr);
  }

  AttributeNode* getAttr(const_iterator& ite) const
  {
    if ((*ite) && (*ite)->isConnectorNode())
    {
      return reinterpret_cast<AttributeNode*>
             (static_cast<ConnectorNode*>(*ite)->getNode());
    }
    return reinterpret_cast<AttributeNode*>(*ite);
  }

  void deleteChild(UpdDelete& upd);

  void restoreChild(UpdDelete& upd);

  void insertChildren(UpdInsertChildren& upd, csize pos);

  void undoInsertChildren(UpdInsertChildren& upd);

  void replaceChild(UpdReplaceChild& upd);

  void restoreChild(UpdReplaceChild& upd);

  NsBindingsContext* getNsContext() const { return theNsContext.getp(); }

  void finalizeNode();

protected:
  csize findChild(const XmlNode* child) const;

  void insertChild(XmlNode* child, csize pos);

  void removeChild(csize pos);

  csize removeChild(XmlNode* child);

  void removeChildren(csize pos, csize numChildren);

  void removeConnector(csize pos);

  csize findAttr(XmlNode* attr) const;

  void insertAttr(XmlNode* child, csize pos);

  void removeAttr(csize pos);

  csize removeAttr(XmlNode* attr);

  const OrdPath* getFirstChildOrdPathAfter(csize pos) const;

  const OrdPath* getFirstChildOrdPathBefore(csize pos) const;

#ifndef ZORBA_NO_FULL_TEXT
  void tokenize( XmlNodeTokenizerCallback& );
#endif /* ZORBA_NO_FULL_TEXT */
};


/*******************************************************************************

********************************************************************************/
class DocumentNode : public InternalNode
{
  friend class NodeFactory;

protected:
  zstring  theBaseUri;
  zstring  theDocUri;

protected:
  DocumentNode(
      XmlTree* tree,
      const zstring& baseUri,
      const zstring& docUri);

  DocumentNode();

public:
  //
  // Item methods
  //

  store::Item* getType() const;

  void getDocumentURI(zstring& uri) const { uri = theDocUri; }

  store::Iterator_t getChildren() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  store::Item_t getAtomizationValue() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  store::Item* getNodeName() const { return NULL; }

  bool isRecursive() const { return getTree()->isRecursive(); }

  zstring show() const;

  //
  // SimpleStore Methods
  //

  XmlNode* copyInternal(
        InternalNode* rootParent,
        InternalNode* parent,
        csize pos,
        const XmlNode* rootCopy,
        const store::CopyMode& copyMode) const;

  const zstring& getBaseUri() const { return theBaseUri; }

  void setBaseUri(const zstring& uri) { theBaseUri = uri; }

  void setDocUri(const zstring& uri) { theDocUri = uri; }

protected:
  void getBaseURIInternal(zstring& uri, bool& local) const;
};

#ifndef EMBEDED_TYPE
#ifndef NDEBUG
// these assertions must hold at any time when entering or leaving an attribute
// or element function that tampers with types:
// 1. If haveType() is true, then the tree must contain a non-null type for this
// node.
#define ATTRIBUTE_ELEMENT_INVARIANT1 assert(!haveType() || \
                                            getTree()->getType(this) != NULL)
// 2. If haveType() is true, then the tree must contain a type for this node
// that is not xs:untyped.
#define ATTRIBUTE_ELEMENT_INVARIANT2 assert( \
    !haveType() || \
    !getTree()->getType(this)->equals( \
        GET_STORE().theSchemaTypeNames[store::XS_UNTYPED_ATOMIC]))
// 3. If haveType() is false, then the tree may not contain type information for
// this node.
#define ATTRIBUTE_ELEMENT_INVARIANT3 assert(haveType() || \
                                            getTree() == NULL || \
                                            getTree()->getType(this) == NULL)
#endif
#endif

/*******************************************************************************

********************************************************************************/
class ElementNode : public InternalNode
{
  friend class XmlNode;
  friend class AttributeNode;
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class NodeFactory;
  friend class UpdSetElementType;
  friend class UpdReplaceContent;

protected:
  store::Item_t         theName;
#ifdef EMBEDED_TYPE
  store::Item_t         theTypeName;
#endif

protected:

  ElementNode(
        store::Item_t& nodeName,
        csize numBindings,
        csize numAttributes);

  ElementNode(
        XmlTree*                  tree,
        InternalNode*             parent,
        bool                      append,
        csize                     pos,
        store::Item_t&            nodeName,
        store::Item_t&            typeName,
        bool                      haveTypedValue,
        bool                      haveEmptyValue,
        bool                      isInSubstGroup,
        const store::NsBindings*  localBindings,
        zstring&                  baseUri);

  ElementNode() {}

public:
  //
  // Item methods
  //
  store::Item* getNodeName() const { return theName.getp(); }

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  store::Item_t getAtomizationValue() const;

  bool isId() const;

  bool isIdRefs() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  store::Item_t getNilled() const;

  store::Iterator_t getAttributes() const;

  store::Iterator_t getChildren() const;

  void getNamespaceBindings(
        store::NsBindings& bindings,
        store::StoreConsts::NsScoping scope = store::StoreConsts::ALL_NAMESPACES) const;

  bool isInSubstitutionGroup() const { return (theFlags & IsInSubstGroup) != 0; }

  zstring show() const;

  //
  // SimpleStore Methods
  //

  bool haveBaseUri() const      { return (theFlags & HaveBaseUri) != 0; }
  void setHaveBaseUri()         { theFlags |= HaveBaseUri; }
  void resetHaveBaseUri()       { theFlags &= ~HaveBaseUri; }

  void setHaveTypedValue()      { theFlags |= HaveTypedValue; }
  void resetHaveTypedValue()    { theFlags &= ~HaveTypedValue; }
  bool haveTypedValue() const   { return (theFlags & HaveTypedValue) != 0; }

  void setHaveEmptyTypedValue()      { theFlags |= HaveEmptyTypedValue; }
  void resetHaveEmptyTypedValue()    { theFlags &= ~HaveEmptyTypedValue; }
  bool haveEmptyTypedValue() const   { return (theFlags & HaveEmptyTypedValue) != 0; }

  bool haveTypedTypedValue(TextNode*&) const;

  TextNode* getUniqueTextChild() const;

  void setInSubstGroup() { theFlags |= IsInSubstGroup; }

  void resetInSubstGroup() { theFlags &= ~IsInSubstGroup; }

#ifndef EMBEDED_TYPE
  void setTree(const XmlTree* t);
  bool haveType() const { return (theFlags & HaveType) != 0; }
  void setHaveType() { theFlags |= HaveType; }
  void resetHaveType() { theFlags &= ~HaveType; }
#endif

  bool isRecursive() const { return (theFlags & IsRecursive) != 0; }

  void resetRecursive() { theFlags &= ~IsRecursive; }

  void setRecursive()
  {
    theFlags |= IsRecursive;
    getTree()->setRecursive();
  }

  bool haveLocalBindings() const
  {
    return (theFlags & HaveLocalBindings) != 0;
  }

  void setNsContext(NsBindingsContext* ctx);

  bool findBinding(const zstring& prefix, zstring& nsuri) const;

  const store::NsBindings& getLocalBindings() const;

  void addLocalBinding(const zstring& prefix, const zstring& ns);

  void removeLocalBinding(const zstring& prefix, const zstring& ns);

  bool addBindingForQName(
      store::Item_t& qname,
      bool           isAttr,
      bool           replacePrefix);

  void addBindingForQName2(const store::Item* qname);

  void checkNamespaceConflict(const store::Item* qname, Error const &ecode) const;

  void uninheritBinding(
      NsBindingsContext* rootNSCtx,
      const zstring& prefix);

  void checkUniqueAttr(const store::Item* attrName) const;

  void checkUniqueAttrs() const;

  XmlNode* copyInternal(
      InternalNode* rootParent,
      InternalNode* parent,
      csize pos,
      const XmlNode* rootCopy,
      const store::CopyMode& copymode) const;

  void removeAttributes(csize pos, csize numAttributes);

  void insertAttributes(UpdInsertAttributes& upd);

  void undoInsertAttributes(UpdInsertAttributes& upd);

  void replaceAttribute(UpdReplaceAttribute& upd);

  void restoreAttribute(UpdReplaceAttribute& upd);

  void replaceContent(UpdReplaceElemContent& upd);

  void restoreContent(UpdReplaceElemContent& upd);

  void replaceName(UpdRenameElem& upd);

  void restoreName(UpdRenameElem& upd);

protected:
  void setType(store::Item_t& type);

  void getBaseURIInternal(zstring& uri, bool& local) const;

  void addBaseUriProperty(zstring& absUri, zstring& relUri);

  void adjustBaseUriProperty(
        AttributeNode* attr,
        zstring& absUri,
        zstring& relUri);

#ifndef ZORBA_NO_FULL_TEXT
  void tokenize( XmlNodeTokenizerCallback& );
#endif /* ZORBA_NO_FULL_TEXT */

private:
  //disable default copy constructor
  ElementNode(const ElementNode& src);
};


/*******************************************************************************

********************************************************************************/
class AttributeNode : public OrdPathNode
{
  friend class XmlNode;
  friend class ElementNode;
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class UpdSetAttributeType;
  friend class NodeFactory;

protected:
  store::Item_t   theName;
#ifdef EMBEDED_TYPE
  store::Item_t   theTypeName;
#endif
  store::Item_t   theTypedValue;

  AttributeNode(store::Item_t&  attrName);

  AttributeNode(
        XmlTree* tree,
        ElementNode* parent,
        bool append,
        csize pos,
        store::Item_t& attrName,
        store::Item_t& typeName,
        store::Item_t& typedValue,
        bool isListValue,
        bool hidden);

  AttributeNode() {}

public:
  //
  // Item methods
  //

  store::Item* getNodeName() const { return theName.getp(); }

  store::Item* getType() const;

  void setTypedValue(store::Item_t& val);

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  store::Item_t getAtomizationValue() const;

  bool isId() const;

  bool isIdRefs() const;

  zstring show() const;

  //
  // SimpleStore Methods
  //

  XmlNode* copyInternal(
        InternalNode* rootParent,
        InternalNode* parent,
        csize pos,
        const XmlNode* rootCopy,
        const store::CopyMode& copymode) const;

  bool haveListValue() const  { return (theFlags & HaveListValue) != 0; }
  void resetHaveListValue()   { theFlags &= ~HaveListValue; }
  void setHaveListValue()     { theFlags |= HaveListValue; }

  bool isHidden() const       { return (theFlags & IsHidden) != 0; }
  void setHidden()            { theFlags |= IsHidden; }

  bool isBaseUri() const      { return (theFlags & IsBaseUri) != 0; }

#ifndef EMBEDED_TYPE
  void setTree(const XmlTree* t);
  bool haveType() const       { return (theFlags & HaveType) != 0; }
  void setHaveType()          { theFlags |= HaveType; }
  void resetHaveType()        { theFlags &= ~HaveType; }
#endif

  void replaceValue(UpdReplaceAttrValue& upd);

  void restoreValue(UpdReplaceAttrValue& upd);

  void replaceName(UpdRenameAttr& upd);

  void restoreName(UpdRenameAttr& upd);

  // override here returning false because following-sibling axes is empty
  // for attribute nodes
  virtual bool
  isFollowingSibling(const store::Item_t&) const { return false; }

  // override here returning false because preceding-sibling axes is empty
  // for attribute nodes
  virtual bool
  isPrecedingSibling(const store::Item_t&) const { return false; }

#ifndef ZORBA_NO_FULL_TEXT
  FTTokenIterator_t getTokens( TokenizerProvider const&, Tokenizer::Numbers&,
                               locale::iso639_1::type, bool = false ) const;
#endif /* ZORBA_NO_FULL_TEXT */

protected:
  void setType(store::Item_t& type);

  ItemVector& getValueVector()
  {
    return *reinterpret_cast<ItemVector*>(theTypedValue.getp());
  }

  const ItemVector& getValueVector() const
  {
    return *reinterpret_cast<ItemVector*>(theTypedValue.getp());
  }

#ifndef ZORBA_NO_FULL_TEXT
  void tokenize( XmlNodeTokenizerCallback& );
#endif
};


/*******************************************************************************

********************************************************************************/
#ifdef TEXT_ORDPATH
class TextNode : public OrdPathNode
#else
class TextNode : public XmlNode
#endif
{
  friend class XmlNode;
  friend class InternalNode;
  friend class DocumentDagNode;
  friend class ElementNode;
  friend class BasicItemFactory;
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class UpdInsertChildren;
  friend class UpdSetElementType;
  friend class NodeFactory;
  friend class CollectionPul;

protected:
  TextNodeContent theContent;

protected:
  TextNode(zstring& content);

  TextNode(
        XmlTree* tree,
        InternalNode* parent,
        bool append,
        csize pos,
        zstring& content);

  TextNode(
        InternalNode*  parent,
        store::Item_t& content,
        bool           isListValue);

  TextNode() {}

public:
  virtual ~TextNode()
  {
    if (isTyped())
    {
      theContent.setValue(NULL);
    }
    else
    {
      theContent.destroyText();
    }
  }

  //
  // Item methods
  //

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  store::Item_t getAtomizationValue() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  store::Item* getNodeName() const { return NULL; }

  zstring show() const;

  //
  // SimpleStore Methods
  //

  XmlNode* copyInternal(
        InternalNode* rootParent,
        InternalNode* parent,
        csize pos,
        const XmlNode* rootCopy,
        const store::CopyMode& copymode) const;

#ifndef TEXT_ORDPATH
  void getOrdPath(OrdPath& ordPath) const;
#endif

  bool isTyped() const;

  void setTypedValue(store::Item_t& value);

  void revertToTextContent();

  bool haveListValue() const { return (theFlags & HaveListValue) != 0; }

  void resetHaveListValue()  { theFlags &= ~HaveListValue; }

  void setHaveListValue()    { theFlags |= HaveListValue; }

  bool isIdInternal() const;

  bool isIdRefsInternal() const;

  void replaceValue(UpdReplaceTextValue& upd);

  void restoreValue(UpdReplaceTextValue& upd);

#ifndef TEXT_ORDPATH
  virtual bool
  isAncestor(const store::Item_t&) const;

  virtual bool
  isFollowingSibling(const store::Item_t&) const;

  virtual bool
  isFollowing(const store::Item_t&) const;

  virtual bool
  isDescendant(const store::Item_t&) const;

  virtual bool
  isPrecedingSibling(const store::Item_t&) const;

  virtual bool
  isPreceding(const store::Item_t&) const;

  virtual bool
  isChild(const store::Item_t&) const;

  virtual bool
  isParent(const store::Item_t&) const;

  virtual store::Item_t
  getLevel() const;

  virtual store::Item_t
  leastCommonAncestor(const store::Item_t&) const;
#endif
  
protected:
  const zstring& getText() const { return theContent.getText(); }

  void setText(zstring& text) { theContent.setText(text); }

  void destroyText() { theContent.destroyText(); }

  store::Item* getValue() const { return theContent.getValue(); }

  void setValue(store::Item_t& val) { theContent.setValue(val); }

  void setValue(store::Item* val) { theContent.setValue(val); }

#ifndef ZORBA_NO_FULL_TEXT
  void tokenize( XmlNodeTokenizerCallback& );
#endif /* ZORBA_NO_FULL_TEXT */
};


/*******************************************************************************

********************************************************************************/
class PiNode : public OrdPathNode
{
  friend class XmlNode;
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class NodeFactory;

protected:
  zstring        theTarget;
  zstring        theContent;

  store::Item_t  theName;

protected:
  PiNode(zstring& target, zstring& content);

  PiNode(
        XmlTree* tree,
        InternalNode* parent,
        bool append,
        csize pos,
        zstring& target,
        zstring& content);

  PiNode() {}

public:
  XmlNode* copyInternal(
        InternalNode* rootParent,
        InternalNode* parent,
        csize pos,
        const XmlNode* rootCopy,
        const store::CopyMode& copymode) const;

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  store::Item_t getAtomizationValue() const;

  zstring getStringValue() const { return theContent; }

  void getStringValue2(zstring& val) const { val = theContent; }

  void appendStringValue(zstring& buf) const { buf += theContent; }

  store::Item* getNodeName() const { return theName.getp(); }

  const zstring& getTarget() const { return theTarget; }

  zstring show() const;

  void replaceValue(UpdReplacePiValue& upd);

  void restoreValue(UpdReplacePiValue& upd);

  void replaceName(UpdRenamePi& upd);

  void restoreName(UpdRenamePi& upd);
};


/*******************************************************************************

********************************************************************************/
class CommentNode : public OrdPathNode
{
  friend class XmlNode;
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class NodeFactory;

protected:
  zstring theContent;

protected:
  CommentNode(zstring& content);

  CommentNode(
        XmlTree* tree,
        InternalNode* parent,
        bool append,
        csize pos,
        zstring& content);

  CommentNode() {}

public:
  XmlNode* copyInternal(
        InternalNode* rootParent,
        InternalNode* parent,
        csize pos,
        const XmlNode* rootCopy,
        const store::CopyMode& copymode) const;

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  store::Item_t getAtomizationValue() const;

  zstring getStringValue() const { return theContent; }

  void getStringValue2(zstring& val) const { val = theContent; }

  void appendStringValue(zstring& buf) const { buf += theContent; }

  store::Item* getNodeName() const { return NULL; }

  zstring show() const;

  void replaceValue(UpdReplaceCommentValue& upd);

  void restoreValue(UpdReplaceCommentValue& upd);
};


#ifdef TEXT_ORDPATH
/*******************************************************************************
  Do a doc-order comparison of "this" nodes and the "other" node. Return -1 if
  this < other, 0, if this == other, or 1 if this > other.
********************************************************************************/
inline long XmlNode::compare2(const XmlNode* other) const
{
  if (this == other)
    return 0;

  ulong col1 = this->getCollectionId();
  ulong col2 = other->getCollectionId();

  if (col1 < col2)
    return -1;

  if (col1 == col2)
  {
    if (col1 == 0)
    {
      ulong tree1 = this->getTreeId();
      ulong tree2 = other->getTreeId();

      if (tree1 < tree2)
        return -1;

      const OrdPathNode* ordThis = static_cast<const OrdPathNode*>(this);
      const OrdPathNode* ordOther = static_cast<const OrdPathNode*>(other);

      if (tree1 == tree2 && ordThis->getOrdPath() < ordOther->getOrdPath())
        return -1;
    }
    else
    {
      xs_integer pos1 = this->getTree()->getPosition();
      xs_integer pos2 = other->getTree()->getPosition();

      if (pos1 < pos2)
        return -1;

      const OrdPathNode* ordThis = static_cast<const OrdPathNode*>(this);
      const OrdPathNode* ordOther = static_cast<const OrdPathNode*>(other);

      if (pos1 == pos2 && ordThis->getOrdPath() < ordOther->getOrdPath())
        return -1;
    }
  }

  return 1;
}
#else
/*******************************************************************************
  Do a doc-order comparison of "this" nodes and the "other" node. Return -1 if
  this < other, 0, if this == other, or 1 if this > other.
********************************************************************************/
inline long XmlNode::compare2(const XmlNode* other) const
{
  if (this == other)
    return 0;

  ulong col1 = this->getCollectionId();
  ulong col2 = other->getCollectionId();

  if (col1 < col2)
    return -1;

  if (col1 == col2)
  {
    if (col1 == 0)
    {
      const TreeId& tree1 = this->getTreeId();
      const TreeId& tree2 = other->getTreeId();

      if (tree1 < tree2)
        return -1;

      if (tree1 == tree2)
        return compareInSameTree(this, other);
    }
    else
    {
      xs_integer pos1 = this->getTree()->getPosition();
      xs_integer pos2 = other->getTree()->getPosition();

      if (pos1 < pos2)
        return -1;

      if (pos1 == pos2)
        return compareInSameTree(this, other);
    }
  }

  return 1;
}
#endif // TEXT_ORDPATH


#ifndef ZORBA_NO_FULL_TEXT
/**
 * An %XmlNodeTokenizerCallback is-a Tokenizer::Callback for tokenizing XML
 * nodes.
 */
class XmlNodeTokenizerCallback : public Tokenizer::Callback
{
public:
  typedef FTTokenStore::container_type container_type;
  typedef FTTokenStore::size_type begin_type;

  XmlNodeTokenizerCallback( TokenizerProvider const &provider,
                            Tokenizer::Numbers &numbers,
                            locale::iso639_1::type lang,
                            FTTokenStore &token_store );

  XmlNodeTokenizerCallback( TokenizerProvider const &provider,
                            Tokenizer::Numbers &numbers,
                            locale::iso639_1::type lang,
                            container_type &tokens );

  ~XmlNodeTokenizerCallback();

  begin_type beginTokenization() const;

  void endTokenization( XmlNode const*, begin_type );

  void push_element( ElementNode *element ) { element_stack_.push( element ); }

  void pop_element() { element_stack_.pop(); }

  void push_lang( locale::iso639_1::type lang );

  void pop_lang();

  void tokenize( char const *utf8_s, size_t len );

  Tokenizer& tokenizer() const { return *tokenizer_stack_.top(); }

  // inherited
  void operator()( char const *utf8_s, size_type utf8_len,
                   size_type pos, size_type sent, size_type para, void* );
private:
  typedef std::stack<ElementNode*> element_stack_t;
  typedef std::stack<locale::iso639_1::type> lang_stack_t;
  typedef std::stack<Tokenizer*> tokenizer_stack_t;

  ElementNode* get_element() const {
    return element_stack_.top();
  }

  locale::iso639_1::type get_lang() const {
    return lang_stack_.top();
  }

  TokenizerProvider const &provider_;
  Tokenizer::Numbers &numbers_;
  FTTokenStore *token_store_;
  container_type &tokens_;
  element_stack_t element_stack_;
  lang_stack_t lang_stack_;
  tokenizer_stack_t tokenizer_stack_;
};
#endif /* ZORBA_NO_FULL_TEXT */


} // namespace store
} // namespace zorba
#endif /* ZORBA_SIMPLE_STORE_NODE_ITEMS */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
