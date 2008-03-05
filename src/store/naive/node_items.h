
#ifndef ZORBA_DEFAULT_STORE_NODES
#define ZORBA_DEFAULT_STORE_NODES


#include <zorba/common/common.h>
#include <zorba/item.h>

#include "util/Assert.h"
#include "store/naive/ordpath.h"

typedef unsigned long ulong;


namespace zorba
{

class XmlNode;
class ElementNode;
class AttributeNode;
class NsBindingsContext;
class QNameItemImpl;
class ConstrNodeVector;

template <class Object> class rchandle;

typedef rchandle<class Item> Item_t;
typedef rchandle<class XmlNode> XmlNode_t;
typedef rchandle<class ElementNode> ElementNode_t;

typedef rchandle<class TempSeq> TempSeq_t;

typedef rchandle<class NsBindingsContext> NsBindingsContext_t;

extern ConstrNodeVector dummyVector;


/*******************************************************************************

********************************************************************************/
class XmlTree
{
protected:
  long       theRefCount;
  RCSync     theRCSyncObject;

  ulong      theId;
  XmlNode  * theRootNode;

public:
  XmlTree(XmlNode* root, ulong id);

  ~XmlTree() { theRootNode = 0; }

  void free();
  long getRefCount() const    { return theRefCount; }
  void addReference()         { ++theRefCount; }
  void removeReference()      { --theRefCount; }
  RCSync& getRCSyncObject()   { return theRCSyncObject; }

  ulong getId() const         { return theId; }
  XmlNode* getRoot() const    { return theRootNode; }
  void setRoot(XmlNode* root) { theRootNode = root; }
};


/*******************************************************************************

********************************************************************************/
class NodeVector
{
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

  virtual void set(ulong pos, XmlNode* n, bool shared) = 0;
  virtual void push_back(XmlNode* n, bool shared) = 0;

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

  void set(ulong pos, XmlNode* n, bool shared) { theNodes[pos] = n; }
  void push_back(XmlNode* n, bool shared)      { theNodes.push_back(n); }

  void clear()                                 { theNodes.clear(); }
  void resize(ulong size)                      { theNodes.resize(size); }
  void copy(const NodeVector& v)               { Assert(0); }

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

  void set(ulong pos, XmlNode* n, bool shared);
  void push_back(XmlNode* n, bool shared);

  void clear();
  void resize(ulong size);
  void copy(const NodeVector& v);

private:
  ConstrNodeVector(const ConstrNodeVector& v);
  ConstrNodeVector& operator=(const ConstrNodeVector& v);
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
    IsIdRef           = 128,
    IsNillable        = 256
  };

protected:
  //XmlTree  * theTree;
  OrdPath      theOrdPath;
  XmlNode    * theParent;

public:
  XmlNode() : Item(), theParent(0) { }

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
  virtual uint32_t hash() const     { Assert(0); return 0; }

  virtual xqp_string getBaseURI() const;
  virtual xqp_string getDocumentURI() const;

  Item_t getEBV() const;

  //
  // SimpleStore Methods
  //

  XmlTree* getTree() const          { return (XmlTree*)theRefCounterPtr; }
  void setTree(const XmlTree* t)    { theRefCounterPtr = (long*)t; }
  bool hasId() const                { return getTree() != 0; }
  ulong getTreeId() const           { return getTree()->getId(); }
  const OrdPath& getOrdPath() const { return theOrdPath; }

  void setId(XmlTree* tree, const OrdPathStack* op);

  XmlNode* getParentP() const       { return theParent; }
  void setParent(XmlNode* p)        { theParent = p; }

  void appendChild(XmlNode* child);

  void deleteTree();

  virtual XmlNode* copy(XmlNode* parent, ulong pos) = 0;

  virtual void checkUniqueAttr(Item* qn) const { Assert(0); }

  virtual ulong numAttributes() const          { Assert(0); return 0; }
  virtual XmlNode* getAttr(ulong i) const      { Assert(0); return NULL; }
  virtual NodeVector& attributes()             { Assert(0); return dummyVector; }
  virtual const NodeVector& attributes() const { Assert(0); return dummyVector; }

  virtual ulong numChildren() const            { Assert(0); return 0; }
  virtual XmlNode* getChild(ulong i) const     { Assert(0); return NULL; }
  virtual NodeVector& children()               { Assert(0); return dummyVector; }
  virtual const NodeVector& children() const   { Assert(0); return dummyVector; }

  virtual NsBindingsContext* getNsContext() const   { Assert(0); return NULL; }
  virtual void setNsContext(NsBindingsContext* ctx) { Assert(0); }

  virtual bool haveLocalBindings() const { Assert(0); return false; }

  virtual bool isConstructed() const     { Assert(0); return false; }
  virtual bool isCopy() const            { Assert(0); return false; }
  virtual bool typePreserve() const      { Assert(0); return false; }
  virtual bool nsPreserve() const        { Assert(0); return false; }
  virtual bool nsInherit() const         { Assert(0); return false; }
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
  DocumentNode(
        XmlTree*        tree,
        xqpStringStore* baseUri,
        xqpStringStore* docUri);

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

  XmlNode* copy(XmlNode* parent, ulong pos) { Assert(0); return 0; }

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
  LoadedDocumentNode(
        xqpStringStore* baseUri, 
        xqpStringStore* documentUri);

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
public:
  Item_t                theName;
  Item_t                theTypeName;
  NsBindingsContext_t   theNsContext;
  uint32_t              theFlags;

public:
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
private:
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

 private:
  Item_t   theName;
  Item_t   theTypeName;
  Item_t   theTypedValue;
  bool     theIsId;
  bool     theIsIdrefs;
  
 public:
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

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const;

  bool isId() const     { return theIsId; }
  bool isIdrefs() const { return theIsIdrefs; }

  virtual xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class TextNode : public XmlNode
{
  friend class ConstrDocumentNode;
  friend class ConstrElementNode;

protected:
  xqpStringStore_t theContent;

public:
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
 private:
  xqpStringStore_t theTarget;
  xqpStringStore_t theData;

public:
  PiNode(
        XmlTree*        tree,
        XmlNode*        parent,
        ulong           pos,
        xqpStringStore* target,
        xqpStringStore* data);

  ~PiNode();

  XmlNode* copy(XmlNode* parent, ulong  pos);

  StoreConsts::NodeKind getNodeKind() const { return StoreConsts::piNode; }

  Item_t getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const    { return theData.getp(); }

  xqp_string getTarget() const { return theTarget.getp(); }

  xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class CommentNode : public XmlNode
{
private:
  xqpStringStore_t theContent;

public:
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


}

#endif
