
#ifndef ZORBA_STORE_NODE_ITEMS_H
#define ZORBA_STORE_NODE_ITEMS_H


#include <zorba/common/common.h>
#include <zorba/item.h>
#include "common/shared_types.h"
#include "errors/fatal.h"
#include "store/naive/ordpath.h"
#include "store/naive/node_vector.h"
#include "store/naive/node_updates.h"

namespace zorba { namespace store {


extern ConstrNodeVector dummyVector;


/*******************************************************************************

********************************************************************************/
class XmlTree
{
protected:
  long              theRefCount;
  SYNC_CODE(RCLock  theRCLock;)

  ulong             theId;
  XmlNode         * theRootNode;

public:
  XmlTree(XmlNode* root, ulong id);

  ~XmlTree() { theRootNode = 0; }

  void free() throw();

  long getRefCount() const      { return theRefCount; }
  void setRefCount(ulong c)     { theRefCount = c; }
  void addReference()           { ++theRefCount; }
  void removeReference()        { --theRefCount; }

  void removeReferences(ulong count) throw();

  SYNC_CODE(RCLock& getRCLock() { return theRCLock; })

  ulong getId() const           { return theId; }
  XmlNode* getRoot() const      { return theRootNode; }
  void setRoot(XmlNode* root)   { theRootNode = root; }
};



/*******************************************************************************

  Note: No synchronization is required for access to theTree and theOrdPath data
  members, because once set, their value cannot change again, and furthermore,
  the setting of these data members occurs within the thread that created the
  node, before the node becomes visible to any other thread.

********************************************************************************/
class XmlNode : public Item
{
  friend class DocumentNode;
  friend class ElementNode;
  friend class XmlLoader;

public:
  enum NodeFlags
  {
    IsConstructed     =   1,
    IsCopy            =   2,
    TypePreserve      =   4,
    NsPreserve        =   8,
    NsInherit         =  16,
    HaveLocalBindings =  32,
    IsId              =  64,
    IsIdRefs          = 128,
    IsNillable        = 256
  };

protected:
  //XmlTree  * theTree;
  OrdPath      theOrdPath;
  XmlNode    * theParent;

public:
  XmlNode();

  XmlNode(
        XmlTree*              tree,
        XmlNode*              parent,
        ulong                 pos,
        StoreConsts::NodeKind nodeKind);

  virtual ~XmlNode();

  void free() { if (getTree() != NULL) getTree()->free(); }

  //
  // Item methods
  //

  bool isNode() const               { return true; }
  bool isAtomic() const             { return false; }

  Item_t getParent() const          { return theParent; }

  virtual bool equals(Item_t) const;
  virtual uint32_t hash() const     { ZORBA_FATAL(""); return 0; }

  virtual xqp_string getBaseURI() const;
  virtual xqp_string getDocumentURI() const;

  Item_t getEBV() const;

  //
  // SimpleStore Methods
  //

  XmlTree* getTree() const          { return (XmlTree*)theTreeRCPtr; }
  void setTree(const XmlTree* t)    { theTreeRCPtr = (long*)t; }
  bool hasId() const                { return getTree() != 0; }
  ulong getTreeId() const           { return getTree()->getId(); }
  const OrdPath& getOrdPath() const { return theOrdPath; }

  void setId(XmlTree* tree, const OrdPathStack* op);

  XmlNode* getParentP() const       { return theParent; }
  void setParent(XmlNode* p)        { theParent = p; }

  void appendChild(XmlNode* child);
  void removeChild(ulong pos);
  bool removeChild(XmlNode* child);
  bool removeAttr(XmlNode* attr);

  void deleteTree() throw();

  void setToUntyped();
  void removeType(TypeUndoList& undoList);
  void revalidate();

  void insertBefore(std::vector<XmlNode*>& nodes);
  void insertAttributes(std::vector<XmlNode*>& attrs);
  void disconnect() throw();
  void switchTree() throw();
  void replaceValue(xqpStringStore* newValue, xqpStringStore_t& oldValue);
  void replaceElementContent(XmlNode* newText, std::vector<XmlNode*>& children);
  void rename(QNameItemImpl* newname, Item_t& oldName);
  void renamePi(xqpStringStore* newName,  xqpStringStore_t& oldName);
  void checkQName(QNameItemImpl* newName);

  virtual XmlNode* copy(XmlNode* parent, ulong pos) = 0;

  virtual void checkUniqueAttr(Item* qn) const { ZORBA_FATAL(""); }

  virtual ulong numAttributes() const          { return 0; }
  virtual XmlNode* getAttr(ulong i) const      { ZORBA_FATAL(""); return NULL; }
  virtual NodeVector& attributes()             { ZORBA_FATAL(""); return dummyVector; }
  virtual const NodeVector& attributes() const { ZORBA_FATAL(""); return dummyVector; }

  virtual ulong numChildren() const            { return 0; }
  virtual XmlNode* getChild(ulong i) const     { ZORBA_FATAL(""); return NULL; }
  virtual NodeVector& children()               { ZORBA_FATAL(""); return dummyVector; }
  virtual const NodeVector& children() const   { ZORBA_FATAL(""); return dummyVector; }

  virtual NsBindingsContext* getNsContext() const   { ZORBA_FATAL(""); return NULL; }
  virtual void setNsContext(NsBindingsContext* ctx) { ZORBA_FATAL(""); }

  virtual bool haveLocalBindings() const { ZORBA_FATAL(""); return false; }

  virtual bool isId() const              { ZORBA_FATAL(""); return false; }
  virtual bool isIdRefs() const          { ZORBA_FATAL(""); return false; }

  virtual bool isConstructed() const     { ZORBA_FATAL(""); return false; }
  virtual bool isCopy() const            { ZORBA_FATAL(""); return false; }
  virtual bool typePreserve() const      { ZORBA_FATAL(""); return false; }
  virtual bool nsPreserve() const        { ZORBA_FATAL(""); return false; }
  virtual bool nsInherit() const         { ZORBA_FATAL(""); return false; }
};


/*******************************************************************************

********************************************************************************/
class DocumentNode : public XmlNode
{
protected:
  xqpStringStore_t    theBaseUri;
  xqpStringStore_t    theDocUri;

  uint32_t            theFlags;

public:
  DocumentNode(xqpStringStore* baseUri, xqpStringStore* docUri);

  DocumentNode(XmlTree* tree, xqpStringStore* baseUri, xqpStringStore* docUri);

  virtual ~DocumentNode();

  //
  // Item methods
  //

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::documentNode; }

  Item_t getType() const; 

  xqp_string getBaseURI() const     { return theBaseUri.getp(); }
  xqp_string getDocumentURI() const { return theDocUri.getp(); }

  Iterator_t getChildren() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  XmlNode* copy(XmlNode* parent, ulong pos) { ZORBA_FATAL(""); return 0; }

  ulong numAttributes() const { return 0; }

  bool isConstructed() const  { return (theFlags & XmlNode::IsConstructed) != 0; }
  bool isCopy() const         { return (theFlags & XmlNode::IsCopy) != 0; }
  bool typePreserve() const   { return (theFlags & XmlNode::TypePreserve) != 0; }
  bool nsPreserve() const     { return (theFlags & XmlNode::NsPreserve) != 0; }  
  bool nsInherit() const      { return false; }

  NsBindingsContext* getNsContext() const { return NULL; }

  xqpStringStore* findBinding(xqpStringStore* prefix) const { return NULL; }
};


/*******************************************************************************

********************************************************************************/
class LoadedDocumentNode : public DocumentNode
{
private:
  LoadedNodeVector theChildren;

public:
  LoadedDocumentNode(xqpStringStore* baseUri, xqpStringStore* documentUri);

  ulong numChildren() const          { return theChildren.size(); }
  NodeVector& children()             { return theChildren; }
  const NodeVector& children() const { return theChildren; }
  XmlNode* getChild(ulong i) const   { return theChildren.get(i); }
};


/*******************************************************************************

********************************************************************************/
class ConstrDocumentNode : public DocumentNode
{
private:
  ConstrNodeVector theChildren;

public:
  ConstrDocumentNode(
        XmlTree*        tree,
        xqpStringStore* baseUri,
        xqpStringStore* docUri,
        bool            typePreserve,
        bool            nsPreserve,
        bool            nsInherit);

  void constructSubtree(Iterator* children, bool copy);

  ulong numChildren() const          { return theChildren.size(); }
  NodeVector& children()             { return theChildren; }
  const NodeVector& children() const { return theChildren; }
  XmlNode* getChild(ulong i) const   { return theChildren.get(i); }
};


/*******************************************************************************

********************************************************************************/
class ElementNode : public XmlNode
{
  friend class XmlNode;

public:
  Item_t                theName;
  Item_t                theTypeName;
  NsBindingsContext_t   theNsContext;
  uint32_t              theFlags;

public:
  ElementNode(Item* nodeName);

  ElementNode(
        XmlTree*  tree,
        XmlNode*  parent,
        ulong     pos,
        Item*     nodeName);

  virtual ~ElementNode();

  //
  // Item methods
  //

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::elementNode; }
  Item_t getType() const                    { return theTypeName; }
  Item_t getNodeName() const                { return theName; }

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const;
  bool getNilled() const;

  Iterator_t getAttributes() const;
  Iterator_t getChildren() const;
  void getNamespaceBindings(NsBindings& bindings) const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  XmlNode* copy(XmlNode* parent, ulong pos);

  void checkUniqueAttr(Item* attrName) const;

  bool isId() const             { return (theFlags & XmlNode::IsId) != 0; }
  void resetIsId()              { theFlags &= ~XmlNode::IsId; }

  bool isIdRefs() const         { return (theFlags & XmlNode::IsIdRefs) != 0; }
  void resetIsIdRefs()          { theFlags &= ~XmlNode::IsIdRefs; }

  bool isConstructed() const    { return (theFlags & XmlNode::IsConstructed) != 0; }
  bool isCopy() const           { return (theFlags & XmlNode::IsCopy) != 0; }
  bool typePreserve() const     { return (theFlags & XmlNode::TypePreserve) != 0; }
  bool nsPreserve() const       { return (theFlags & XmlNode::NsPreserve) != 0; }
  bool nsInherit() const        { return (theFlags & XmlNode::NsInherit) != 0; }

  bool haveLocalBindings() const{ return (theFlags & XmlNode::HaveLocalBindings) != 0; }

  NsBindingsContext* getNsContext() const { return theNsContext.getp(); }

  void setNsContext(NsBindingsContext* ctx);
  xqpStringStore* findBinding(xqpStringStore* prefix) const;
  const NsBindings& getLocalBindings() const;
  void addLocalBinding(xqpStringStore* prefix, xqpStringStore* ns);
};


/*******************************************************************************

********************************************************************************/
class LoadedElementNode : public ElementNode
{
protected:
  LoadedNodeVector  theChildren;
  LoadedNodeVector  theAttributes;

public:
  LoadedElementNode(
        Item*   nodeName,
        Item*   typeName,
        ulong   numBindings,
        ulong   numAttributes);

  ulong numAttributes() const          { return theAttributes.size(); }
  NodeVector& attributes()             { return theAttributes; }
  const NodeVector& attributes() const { return theAttributes; }
  XmlNode* getAttr(ulong i) const      { return theAttributes.get(i); }

  ulong numChildren() const            { return theChildren.size(); }
  NodeVector& children()               { return theChildren; }
  const NodeVector& children() const   { return theChildren; }
  XmlNode* getChild(ulong i) const     { return theChildren.get(i); }

  bool isConstructed() const           { return false; }
  bool isCopy() const                  { return false; }

private:
  //disable default copy constructor
  LoadedElementNode(const LoadedElementNode& src);
};


/*******************************************************************************

********************************************************************************/
class ConstrElementNode : public ElementNode
{
protected:
  ConstrNodeVector  theChildren;
  ConstrNodeVector  theAttributes;

public:
  ConstrElementNode(
        XmlTree*  tree,
        XmlNode*  parent,
        ulong     pos,
			  Item*     nodeName,
        Item*     typeName,
        bool      typePreserve,
        bool      nsPreserve,
        bool      nsInherit);

  void constructSubtree(
        Iterator*         attributesIte,
        Iterator*         childrenIte,
        const NsBindings& nsBindings,
        bool              copy);

  ulong numAttributes() const          { return theAttributes.size(); }
  NodeVector& attributes()             { return theAttributes; }
  const NodeVector& attributes() const { return theAttributes; }
  XmlNode* getAttr(ulong i) const      { return theAttributes.get(i); }

  ulong numChildren() const            { return theChildren.size(); }
  NodeVector& children()               { return theChildren; }
  const NodeVector& children() const   { return theChildren; }
  XmlNode* getChild(ulong i) const     { return theChildren.get(i); }

  bool isConstructed() const   { return true; }
  bool isCopy() const          { return (theFlags & XmlNode::IsCopy) != 0; }

  bool typePreserve() const    { return (theFlags & XmlNode::TypePreserve) != 0; }
  bool nsPreserve() const      { return (theFlags & XmlNode::NsPreserve) != 0; }
  bool nsInherit() const       { return (theFlags & XmlNode::NsInherit) != 0; }

private:
  //disable default copy constructor
  ConstrElementNode(const ConstrElementNode& src);
};


/*******************************************************************************

********************************************************************************/
class AttributeNode : public XmlNode
{
  friend class XmlLoader;
  friend class XmlNode;

protected:
  Item_t   theName;
  Item_t   theTypeName;
  Item_t   theTypedValue;
  uint32_t theFlags;

public:
  AttributeNode(
        Item*    attrName,
        Item*    typeName,
        bool     isId,
        bool     isIdrefs);

  AttributeNode(
        XmlTree* tree,
        XmlNode* parent,
        ulong    pos,
        Item*    attrName,
        Item*    typeName,
        bool     isId,
        bool     isIdrefs);

  virtual ~AttributeNode();

  void constructValue(Iterator* valueIter);

  XmlNode* copy(XmlNode* parent, ulong pos);

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::attributeNode; }

  Item_t getType() const     { return theTypeName; }

  Item_t getNodeName() const { return theName; }

  bool isId() const          { return (theFlags & XmlNode::IsId) != 0; }
  void resetIsId()           { theFlags &= ~XmlNode::IsId; }

  bool isIdrefs() const      { return (theFlags & XmlNode::IsIdRefs) != 0; }
  void resetIsIdRefs()       { theFlags &= ~XmlNode::IsIdRefs; }

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const;

  virtual xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class TextNode : public XmlNode
{
  friend class XmlNode;
  friend class ConstrDocumentNode;
  friend class ConstrElementNode;

protected:
  xqpStringStore_t theContent;

public:
  TextNode(xqpStringStore* content);

  TextNode(
        XmlTree*        tree,
        XmlNode*        parent,
        ulong           pos,
        xqpStringStore* content);

  TextNode();

  ~TextNode();

  XmlNode* copy(XmlNode* parent, ulong pos);

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::textNode; }

  Item_t getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const   { return theContent.getp(); }
  xqpStringStore* getStringValueP()   { return theContent.getp(); }
			
  xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class PiNode : public XmlNode
{
  friend class XmlNode;

 protected:
  xqpStringStore_t theTarget;
  xqpStringStore_t theContent;

public:
  PiNode(xqpStringStore* target, xqpStringStore* content);

  PiNode(
        XmlTree*        tree,
        XmlNode*        parent,
        ulong           pos,
        xqpStringStore* target,
        xqpStringStore* content);

  ~PiNode();

  XmlNode* copy(XmlNode* parent, ulong  pos);

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::piNode; }

  Item_t getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const    { return theContent.getp(); }

  xqp_string getTarget() const { return theTarget.getp(); }

  xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class CommentNode : public XmlNode
{
  friend class XmlNode;

protected:
  xqpStringStore_t theContent;

public:
  CommentNode(xqpStringStore* content);

  CommentNode(
        XmlTree*        tree,
        XmlNode*        parent,
        ulong           pos,
        xqpStringStore* content);

  ~CommentNode();

  XmlNode* copy(XmlNode* parent, ulong pos);

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::commentNode; }

  Item_t getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const   { return theContent.getp(); }
  xqpStringStore* getStringValueP()   { return theContent.getp(); }

  xqp_string show() const;
};


} // namespace store
} // namespace zorba

#endif
