
#ifndef ZORBA_SIMPLE_STORE_NODE_ITEMS
#define ZORBA_SIMPLE_STORE_NODE_ITEMS

#include <zorba/error.h>
#include "common/common.h"
#include "store/api/item.h"
#include "common/shared_types.h"
#include "errors/fatal.h"
#include "store/naive/ordpath.h"
#include "store/naive/node_vector.h"
#include "store/naive/node_updates.h"

namespace zorba { namespace store {

class CopyMode;

extern ConstrNodeVector dummyVector;


#define NODE_STOP \
  ZORBA_FATAL(0, "Invalid method invocation on " \
              << StoreConsts::toString(getNodeKind()))


/*******************************************************************************

********************************************************************************/
class XmlTree
{
protected:
  mutable long              theRefCount;
  SYNC_CODE(mutable RCLock  theRCLock;)

  ulong             theId;
  XmlNode         * theRootNode;

public:
  XmlTree(XmlNode* root, ulong id);

  ~XmlTree() { theRootNode = 0; }

  void free() throw();

  long getRefCount() const      { return theRefCount; }
  long& getRefCount()           { return theRefCount; }
  void addReference()           { ++theRefCount; }
  void removeReference()        { --theRefCount; }

  SYNC_CODE(RCLock& getRCLock() const { return theRCLock; })

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
  friend class ConstrDocumentNode;
  friend class ElementNode;
  friend class ConstrElementNode;
  friend class UpdDelete;
  friend class UpdInsertSiblings;
  friend class UpdReplaceChild;
  friend class UpdReplaceContent;
  friend class UpdReplaceAttribute;
  friend class UpdReplaceAttrValue;
  friend class UpdReplaceTextValue;
  friend class XmlLoader;

public:
  enum NodeFlags
  {
    HaveLocalBindings =   2,
    IsId              =   4,
    IsIdRefs          =   8,
    IsNillable        =  16,
    IsBaseUri         =  32,
    IsHidden          =  64
  };

protected:
  //XmlTree  * theTree;
  OrdPath      theOrdPath;
  XmlNode    * theParent;

public:
  XmlNode();

  XmlNode(
        XmlTree*              tree,
        bool                  assignIds);

  XmlNode(
        XmlNode*              parent,
        ulong                 pos,
        StoreConsts::NodeKind nodeKind);

  XmlNode(
        XmlNode*              parent,
        StoreConsts::NodeKind nodeKind);

  virtual ~XmlNode();

  void free() { if (getTree() != NULL) getTree()->free(); }

  //
  // Item methods
  //

  bool isNode() const               { return true; }
  bool isAtomic() const             { return false; }
  bool isPul() const                { return false; }

  Item* getParent() const           { return theParent; }

  bool equals(
        const Item* other,
        RuntimeCB* aRuntimeCB,
        XQPCollator* aCollation = 0) const { return this == other; }

  uint32_t hash(
        RuntimeCB* aRuntimeCB,
        XQPCollator* aCollation = 0) const;

  xqpStringStore_t getBaseURI() const
  {
    bool local = false;
    return getBaseURIInternal(local);
  }

  virtual xqpStringStore* getDocumentURI() const { return 0; }

  Item_t getEBV() const;

  virtual Item_t getNilled() const { return 0; }

  Item* copyXmlTree(const CopyMode& copymode) const;

  //
  // SimpleStore Methods
  //

  void setParent(XmlNode* p)        { theParent = p; }

  void setTree(const XmlTree* t);
  XmlTree* getTree() const          { return (XmlTree*)theTreeRCPtr; }
  ulong getTreeId() const           { return getTree()->getId(); }
  const OrdPath& getOrdPath() const { return theOrdPath; }
  OrdPath& getOrdPath()             { return theOrdPath; }

  void setId(XmlTree* tree, const OrdPathStack* op);

  void setOrdPath(XmlNode* parent, ulong pos, StoreConsts::NodeKind nodeKind);

  void switchTree(
        XmlNode* parent,
        ulong pos,
        const CopyMode& copymode) throw();

  void deleteTree() throw();

  void setToUntyped();
  void removeType(TypeUndoList& undoList);
  void restoreType(const TypeUndoList& undoList);
  void revalidate();

  void removeChildren(
        ulong  pos,
        ulong  numChildren);

  void insertChildren(
        std::vector<Item_t>& newChildren,
        ulong                pos,
        bool                 copy,
        const CopyMode&      copymode);
  
  void insertChildrenFirst(
        std::vector<Item_t>& newChildren,
        bool                 copy,
        const CopyMode&      copymode);

  void insertChildrenLast(
        std::vector<Item_t>& newChildren,
        bool                 copy,
        const CopyMode&      copymode);

  void insertSiblingsBefore(
        std::vector<Item_t>& siblings,
        bool                 copy,
        const CopyMode&      copymode);

  void insertSiblingsAfter(
        std::vector<Item_t>& siblings,
        bool                 copy,
        const CopyMode&      copymode);

  void replaceChild(
        std::vector<Item_t>& newChildren,
        ulong                pos,
        bool                 copy,
        const CopyMode&      copymode);

  virtual XmlNode* copy(
        XmlNode* rootParent,
        XmlNode* parent,
        ulong pos,
        const CopyMode& copyMode) const = 0;

  virtual ulong numAttributes() const          { return 0; }
  virtual AttributeNode* getAttr(ulong i) const{ NODE_STOP; return NULL; }
  virtual NodeVector& attributes()             { NODE_STOP; return dummyVector; }
  virtual const NodeVector& attributes() const { NODE_STOP; return dummyVector; }

  virtual ulong numChildren() const            { return 0; }
  virtual XmlNode* getChild(ulong i) const     { NODE_STOP; return NULL; }
  virtual NodeVector& children()               { NODE_STOP; return dummyVector; }
  virtual const NodeVector& children() const   { NODE_STOP; return dummyVector; }

  virtual NsBindingsContext* getNsContext() const   { NODE_STOP; return NULL; }
  virtual void setNsContext(NsBindingsContext* ctx) { NODE_STOP; }

  virtual bool haveLocalBindings() const { NODE_STOP; return false; }

  virtual bool isId() const              { NODE_STOP; return false; }
  virtual bool isIdRefs() const          { NODE_STOP; return false; }

  virtual bool isConstructed() const     { NODE_STOP; return false; }

protected:
  virtual xqpStringStore_t getBaseURIInternal(bool& local) const;

  ulong disconnect() throw();
  void connect(XmlNode* node, ulong pos) throw();
  void removeChild(ulong pos);
  bool removeChild(XmlNode* child);
  void removeAttr(ulong pos);
  bool removeAttr(XmlNode* attr);
};


/*******************************************************************************

********************************************************************************/
class DocumentNode : public XmlNode
{
protected:
  xqpStringStore_t    theBaseUri;
  xqpStringStore_t    theDocUri;

public:
  DocumentNode(
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri);

  DocumentNode(
        XmlTree*          tree,
        bool              assignIds,
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri);

  virtual ~DocumentNode();

  //
  // Item methods
  //

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::documentNode; }

  Item* getType() const; 

  xqpStringStore* getDocumentURI() const { return theDocUri.getp(); }

  Iterator_t getChildren() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  XmlNode* copy(
        XmlNode* rootParent,
        XmlNode* parent,
        ulong pos,
        const CopyMode& copyMode) const;

  NsBindingsContext* getNsContext() const                { return NULL; }
  xqpStringStore* findBinding(xqpStringStore* pre) const { return NULL; }

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;
};


/*******************************************************************************

********************************************************************************/
class LoadedDocumentNode : public DocumentNode
{
private:
  LoadedNodeVector theChildren;

public:
  LoadedDocumentNode(
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri);

  LoadedDocumentNode(
        XmlTree*          tree,
        bool              assignIds,
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri);

  ulong numChildren() const          { return theChildren.size(); }
  NodeVector& children()             { return theChildren; }
  const NodeVector& children() const { return theChildren; }
  XmlNode* getChild(ulong i) const   { return theChildren.get(i); }

  bool isConstructed() const         { return false; }
};


/*******************************************************************************

********************************************************************************/
class ConstrDocumentNode : public DocumentNode
{
protected:
  ConstrNodeVector theChildren;

public:
  ConstrDocumentNode(
        XmlTree*          tree,
        bool              assignIds,
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri);
        
  void constructSubtree(
        Iterator*       children,
        bool            copy,
        const CopyMode& copymode);

  ulong numChildren() const          { return theChildren.size(); }
  NodeVector& children()             { return theChildren; }
  const NodeVector& children() const { return theChildren; }
  XmlNode* getChild(ulong i) const   { return theChildren.get(i); }

  bool isConstructed() const         { return true; }
};


/*******************************************************************************

********************************************************************************/
class ElementNode : public XmlNode
{
  friend class XmlNode;
  friend class LoadedElementNode;
  friend class AttributeNode;

protected:
  Item_t                theName;
  Item_t                theTypeName;
  NsBindingsContext_t   theNsContext;
  uint32_t              theFlags;

public:
  ElementNode(
        Item_t& nodeName,
        Item_t& typeName);

  ElementNode(
        XmlTree* tree,
        bool     assignIds,
        Item_t&  nodeName,
        Item_t&  typeName);

  ElementNode(
        XmlNode* parent,
        ulong    pos,
        Item_t&  nodeName,
        Item_t&  typeName);

  ElementNode(
        XmlNode* parent,
        Item_t&  nodeName,
        Item_t&  typeName);

  virtual ~ElementNode();

  //
  // Item methods
  //

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::elementNode; }
  Item* getType() const                     { return theTypeName.getp(); }
  Item* getNodeName() const                 { return theName.getp(); }

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const;
  Item_t getNilled() const;

  Iterator_t getAttributes() const;
  Iterator_t getChildren() const;

  void getNamespaceBindings(
        NsBindings& bindings,
        StoreConsts::NsScoping ns_scoping = StoreConsts::ALL_NAMESPACES) const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  bool isId() const             { return (theFlags & XmlNode::IsId) != 0; }
  void resetIsId()              { theFlags &= ~XmlNode::IsId; }
  bool isIdRefs() const         { return (theFlags & XmlNode::IsIdRefs) != 0; }
  void resetIsIdRefs()          { theFlags &= ~XmlNode::IsIdRefs; }

  bool haveLocalBindings() const{ return (theFlags & XmlNode::HaveLocalBindings) != 0; }

  NsBindingsContext* getNsContext() const { return theNsContext.getp(); }

  void setNsContext(NsBindingsContext* ctx);
  xqpStringStore* findBinding(const xqpStringStore* prefix) const;
  const NsBindings& getLocalBindings() const;
  void addLocalBinding(xqpStringStore* prefix, xqpStringStore* ns);
  void addBindingForQName(Item* qname);

  void checkNamespaceConflict(
        const Item*           qname,
        ZorbaError::ErrorCode ecode) const;

  void checkUniqueAttr(const Item* attrName) const;

  XmlNode* copy(
        XmlNode*        rootParent,
        XmlNode*        parent,
        ulong           pos,
        const CopyMode& copymode) const;

  void removeAttributes(
        ulong  pos,
        ulong  numAttributes);

  void insertAttributes(
        std::vector<Item_t>&  newAttrs,
        bool                  copy,
        const CopyMode&       copymode);

  void replaceAttribute(
        std::vector<Item_t>& newAttrs,
        ulong                pos,
        bool                 copy,
        const CopyMode&      copymode);

  void replaceContent(
        XmlNode*          newText,
        ConstrNodeVector& oldChildren,
        bool              copy,
        const CopyMode&   copymode);

  void rename(Item_t& newname, Item_t& oldName);

protected:
  void addBaseUriProperty(
        xqpStringStore_t& absUri,
        xqpStringStore_t& relUri);

  void adjustBaseUriProperty(
        AttributeNode*    attr,
        xqpStringStore_t& absUri,
        xqpStringStore_t& relUri);
};


/*******************************************************************************

********************************************************************************/
class LoadedElementNode : public ElementNode
{
  friend class ElementNode;
  friend class UpdReplaceContent;

protected:
  LoadedNodeVector  theChildren;
  LoadedNodeVector  theAttributes;

public:
  LoadedElementNode(
        Item_t& nodeName,
        Item_t& typeName,
        ulong   numBindings,
        ulong   numAttributes);

  LoadedElementNode(
        XmlTree*  tree,
        bool      assgignIds,
        Item_t&   nodeName,
        Item_t&   typeName);

  LoadedElementNode(
        XmlNode*  parent,
        ulong     pos,
        Item_t&   nodeName,
        Item_t&   typeName);

  LoadedElementNode(
        XmlNode*  parent,
        Item_t&   nodeName,
        Item_t&   typeName);

  ulong numAttributes() const          { return theAttributes.size(); }
  NodeVector& attributes()             { return theAttributes; }
  const NodeVector& attributes() const { return theAttributes; }

  AttributeNode* getAttr(ulong i) const
  {
    return reinterpret_cast<AttributeNode*>(theAttributes.get(i));
  }

  ulong numChildren() const            { return theChildren.size(); }
  NodeVector& children()               { return theChildren; }
  const NodeVector& children() const   { return theChildren; }
  XmlNode* getChild(ulong i) const     { return theChildren.get(i); }

  bool isConstructed() const           { return false; }

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;

private:
  //disable default copy constructor
  LoadedElementNode(const LoadedElementNode& src);
};


/*******************************************************************************

********************************************************************************/
class ConstrElementNode : public ElementNode
{
  friend class UpdReplaceContent;

protected:
  ConstrNodeVector  theChildren;
  ConstrNodeVector  theAttributes;

public:
  ConstrElementNode(
        XmlTree*  tree,
        bool      assgignIds,
			  Item_t&   nodeName,
        Item_t&   typeName);

  ConstrElementNode(
        XmlNode*  parent,
        Item_t&   nodeName,
        Item_t&   typeName);

  void constructSubtree(
        Iterator*         attributesIte,
        Iterator*         childrenIte,
        const NsBindings& nsBindings,
        xqpStringStore_t& staticBaseUri,
        bool              isRoot,
        bool              copy,
        const CopyMode&   copymode);

  ulong numAttributes() const          { return theAttributes.size(); }
  NodeVector& attributes()             { return theAttributes; }
  const NodeVector& attributes() const { return theAttributes; }

  AttributeNode* getAttr(ulong i) const
  {
    return reinterpret_cast<AttributeNode*>(theAttributes.get(i)); 
  }

  ulong numChildren() const            { return theChildren.size(); }
  NodeVector& children()               { return theChildren; }
  const NodeVector& children() const   { return theChildren; }
  XmlNode* getChild(ulong i) const     { return theChildren.get(i); }

  bool isConstructed() const           { return true; }

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;

  void addAttribute(
        AttributeNode*    cnode,
        bool              copy,
        const CopyMode&   copymode,
        xqpStringStore_t& staticBaseUri,
        bool&             isBaseUri);

  void addChild(
        XmlNode*        cnode,
        bool            copy,
        const CopyMode& copymode);

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
  friend class ElementNode;
  friend class ConstrElementNode;

protected:
  Item_t   theName;
  Item_t   theTypeName;
  Item_t   theTypedValue;
  uint32_t theFlags;

public:
  AttributeNode(
        Item_t&  attrName,
        Item_t&  typeName,
        bool     isIdrefs);

  AttributeNode(
        XmlTree* tree,
        bool     assignIds,
        Item_t&  attrName,
        Item_t&  typeName,
        Item_t&  typedValue,
        bool     isIdrefs);

  AttributeNode(
        XmlNode*  parent,
        ulong     pos,
        Item_t&   attrName,
        Item_t&   typeName,
        Item_t&   typedValue,
        bool      isIdrefs);

  AttributeNode(
        XmlNode*  parent,
        Item_t&   attrName,
        Item_t&   typeName,
        Item_t&   typedValue,
        bool      isIdrefs);

  virtual ~AttributeNode();

  XmlNode* copy(
        XmlNode*        rootParent,
        XmlNode*        parent,
        ulong           pos,
        const CopyMode& copymode) const;

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::attributeNode; }

  Item* getType() const       { return theTypeName.getp(); }

  Item* getNodeName() const   { return theName.getp(); }

  bool isId() const           { return (theFlags & XmlNode::IsId) != 0; }
  void resetIsId()            { theFlags &= ~XmlNode::IsId; }

  bool isIdRefs() const       { return (theFlags & XmlNode::IsIdRefs) != 0; }
  void resetIsIdRefs()        { theFlags &= ~XmlNode::IsIdRefs; }

  bool isHidden() const       { return (theFlags & XmlNode::IsHidden) != 0; }
  void setHidden()            { theFlags |= XmlNode::IsHidden; }

  bool isBaseUri() const      { return (theFlags & XmlNode::IsBaseUri) != 0; }

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const;

  xqp_string show() const;

  void replaceValue(xqpStringStore_t& newValue, xqpStringStore_t& oldValue);

  void rename(Item_t& newname, Item_t& oldName);
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
  TextNode(xqpStringStore_t& content);

  TextNode(
        XmlTree*          tree,
        bool              assignIds,
        xqpStringStore_t& content);

  TextNode(
        XmlNode*          parent,
        ulong             pos,
        xqpStringStore_t& content);

  TextNode(
        XmlNode*          parent,
        xqpStringStore_t& content);

  virtual ~TextNode();

  XmlNode* copy(
        XmlNode*        rootParent,
        XmlNode*        parent,
        ulong           pos,
        const CopyMode& copymode) const;

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::textNode; }

  Item* getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const   { return theContent; }
  xqpStringStore* getStringValueP()         { return theContent.getp(); }
			
  xqp_string show() const;

  void replaceValue(xqpStringStore_t& newValue, xqpStringStore_t& oldValue);
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
  PiNode(xqpStringStore_t& target, xqpStringStore_t& content);

  PiNode(
        XmlTree*          tree,
        bool              assignIds,
        xqpStringStore_t& target,
        xqpStringStore_t& content);

  PiNode(
        XmlNode*          parent,
        ulong             pos,
        xqpStringStore_t& target,
        xqpStringStore_t& content);

  PiNode(
        XmlNode*          parent,
        xqpStringStore_t& target,
        xqpStringStore_t& content);

  ~PiNode();

  XmlNode* copy(
        XmlNode*        rootParent,
        XmlNode*        parent,
        ulong           pos,
        const CopyMode& copymode) const;

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::piNode; }

  Item* getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const    { return theContent; }

  xqpStringStore* getTarget() const { return theTarget.getp(); }

  xqp_string show() const;

  void replaceValue(xqpStringStore_t& newValue, xqpStringStore_t& oldValue);

  void rename(xqpStringStore_t& newName, xqpStringStore_t& oldName);
};


/*******************************************************************************

********************************************************************************/
class CommentNode : public XmlNode
{
  friend class XmlNode;

protected:
  xqpStringStore_t theContent;

public:
  CommentNode(xqpStringStore_t& content);

  CommentNode(
        XmlTree*          tree,
        bool              assignIds,
        xqpStringStore_t& content);

  CommentNode(
        XmlNode*          parent,
        ulong             pos,
        xqpStringStore_t& content);

  CommentNode(
        XmlNode*          parent,
        xqpStringStore_t& content);

  ~CommentNode();

  XmlNode* copy(
        XmlNode*        rootParent,
        XmlNode*        parent,
        ulong           pos,
        const CopyMode& copymode) const;

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::commentNode; }

  Item* getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const   { return theContent; }
  xqpStringStore* getStringValueP()   { return theContent.getp(); }

  xqp_string show() const;

  void replaceValue(xqpStringStore_t& newValue, xqpStringStore_t& oldValue);
};


} // namespace store
} // namespace zorba

#endif
