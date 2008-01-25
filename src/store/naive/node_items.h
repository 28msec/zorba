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


namespace xqp
{

class XmlNode;
class ElementNode;
class AttributeNode;
class NsBindingsContext;
class QNameItemImpl;

template <class Object> class rchandle;

typedef rchandle<class Item> Item_t;
typedef rchandle<class XmlNode> XmlNode_t;
typedef rchandle<class ElementNode> ElementNode_t;

typedef rchandle<class TempSeq> TempSeq_t;

typedef rchandle<class NsBindingsContext> NsBindingsContext_t;

typedef unsigned long ulong;

/*******************************************************************************

********************************************************************************/
class XmlTree : public rcobject
{
protected:
  unsigned long   theId;
  XmlNode       * theRootNode;

public:
  XmlTree(XmlNode* root, unsigned long id);

  ~XmlTree() { theRootNode = 0; }

  unsigned long getId() const { return theId; }
  XmlNode* getRoot() const    { return theRootNode; }
  void setRoot(XmlNode* root) { theRootNode = root; }

  void free();
};


/*******************************************************************************

********************************************************************************/
class XmlNodeVector
{
  friend class LoadedXmlNodeVector;
  friend class ConstrXmlNodeVector;

public:
  enum { LOADED, CONSTRUCTED };

protected:
  XmlNode  ** theNodes;

public:
  XmlNodeVector() : theNodes(NULL) { }

  XmlNodeVector(unsigned long size);

  virtual ~XmlNodeVector() { }

  bool empty() const                    { return theNodes == 0; }

  XmlNode* get(unsigned long pos) const { return theNodes[pos+1]; } 

  unsigned long size() const;
  void truncate();

  virtual long getKind() const = 0;

  virtual void set(unsigned long pos, XmlNode* n, bool shared) = 0;
  virtual void push_back(unsigned long pos, XmlNode* n, bool shared) = 0;
  virtual void clear() = 0;
  virtual void resize(unsigned long size) = 0;
  virtual void copy(const XmlNodeVector& v) = 0;
};


/*******************************************************************************

********************************************************************************/
class LoadedXmlNodeVector : public XmlNodeVector
{
public:
  LoadedXmlNodeVector() : XmlNodeVector() { }

  LoadedXmlNodeVector(unsigned long size) : XmlNodeVector(size) { }

  ~LoadedXmlNodeVector() { clear(); }

  long getKind() const { return XmlNodeVector::LOADED; }

  void set(unsigned long pos, XmlNode* n, bool shared) { theNodes[pos+1] = n; }

  void push_back(unsigned long pos, XmlNode* n, bool shared);

  void clear();
  void resize(unsigned long size);

  void copy(const XmlNodeVector& v) { Assert(0); }

private:
  LoadedXmlNodeVector(const LoadedXmlNodeVector& v);
  LoadedXmlNodeVector& operator=(const LoadedXmlNodeVector& v);
};


/*******************************************************************************

********************************************************************************/
class ConstrXmlNodeVector : public XmlNodeVector
{
private:
  std::vector<bool> theBitmap;

public:
  ConstrXmlNodeVector() : XmlNodeVector() { }

  ConstrXmlNodeVector(unsigned long size);

  ~ConstrXmlNodeVector()  { clear(); }

  long getKind() const { return XmlNodeVector::CONSTRUCTED; }

  void set(unsigned long pos, XmlNode* n, bool shared);

  void push_back(unsigned long pos, XmlNode* n, bool shared);

  void clear();
  void resize(unsigned long size);

  void copy(const XmlNodeVector& v);

private:
  ConstrXmlNodeVector(const ConstrXmlNodeVector& v);
  ConstrXmlNodeVector& operator=(const ConstrXmlNodeVector& v);
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
  XmlTree    * theTree;
  OrdPath      theOrdPath;
  XmlNode    * theParent;

public:
  XmlNode(bool isRoot);

  virtual ~XmlNode() { }

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

  Item_t getEBV() const;

  //
  // SimpleStore Methods
  //

  void addReference();
  void removeReference();

  bool hasId() const                { return theTree != 0; }
  unsigned long getTreeId() const   { return theTree->getId(); }
  XmlTree* getTree() const          { return theTree; }
  const OrdPath& getOrdPath() const { return theOrdPath; }

  void createId(unsigned long tid, const OrdPathStack& op);
  void setId(XmlTree* tree, const OrdPathStack& op);

   XmlNode* getParentPtr() const    { return theParent; }
  void setParent(XmlNode* p)        { theParent = p; }

  void constructTree(XmlTree* t, unsigned long childPos);
  void deleteTree();

  virtual XmlNode* copy(const XmlNode* parent, unsigned long pos) const = 0;

  virtual unsigned long numAttributes() const       { Assert(0); return 0; }
  virtual XmlNode* getAttr(unsigned long i) const   { Assert(0); return NULL; }
  virtual void setAttr(ulong i, XmlNode* n, bool s) { Assert(0); }

  virtual unsigned long numChildren() const         { Assert(0); return 0; }
  virtual XmlNode* getChild(unsigned long i) const  { Assert(0); return NULL; }
  virtual void setChild(ulong i, XmlNode* n, bool s){ Assert(0); }

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
  xqpStringStore_t    theBaseURI;
  xqpStringStore_t    theDocURI;

  uint32_t            theFlags;

public:
  DocumentNode(
        xqpStringStore* baseURI,
        xqpStringStore* documentURI,
        bool            isRoot);

  virtual ~DocumentNode();

  //
  // Item methods
  //

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::documentNode; }

  Item_t getType() const; 

  xqp_string getBaseURI() const     { return theBaseURI.get_ptr(); }
  xqp_string getDocumentURI() const { return theDocURI.get_ptr(); }

  Iterator_t getChildren() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  XmlNode* copy(const XmlNode* parent, unsigned long pos) const { Assert(0); return 0; }

  unsigned long numAttributes() const { return 0; }

  virtual XmlNodeVector& children() = 0;

  bool isConstructed() const { return (theFlags & XmlNode::IsConstructed) != 0; }
  bool isCopy() const        { return (theFlags & XmlNode::IsCopy) != 0; }
  bool typePreserve() const  { return (theFlags & XmlNode::TypePreserve) != 0; }
  bool nsPreserve() const    { return (theFlags & XmlNode::NsPreserve) != 0; }  
  bool nsInherit() const     { return false; }

  NsBindingsContext* getNsContext() const { return NULL; }

  xqpStringStore* findBinding(xqpStringStore* prefix) const { return NULL; }
};


/*******************************************************************************

********************************************************************************/
class LoadedDocumentNode : public DocumentNode
{
private:
  LoadedXmlNodeVector theChildren;

public:
  LoadedDocumentNode(
        xqpStringStore* baseURI,
        xqpStringStore* documentURI);

  unsigned long numChildren() const        { return theChildren.size(); }
  XmlNodeVector& children()                { return theChildren; }
  XmlNode* getChild(unsigned long i) const { return theChildren.get(i); }
};


/*******************************************************************************

********************************************************************************/
class ConstrDocumentNode : public DocumentNode
{
private:
  ConstrXmlNodeVector theChildren;

public:
  ConstrDocumentNode(
        xqpStringStore* baseURI,
        xqpStringStore* documentURI,
        Iterator*       children,
        bool            isRoot,
        bool            copy,
        bool            typePreserve,
        bool            nsPreserve,
        bool            nsInherit);

  unsigned long numChildren() const          { return theChildren.size(); }
  XmlNodeVector& children()                  { return theChildren; }
  XmlNode* getChild(unsigned long i) const   { return theChildren.get(i); }

  void setChild(ulong i, XmlNode* n, bool shared)
  {
    theChildren.set(i, n, shared);
  }

  void addChild(
        XmlNode*      childNode,
        unsigned long pos,
        bool          isRoot,
        bool          copy);
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
  ElementNode(const Item* nodeName, bool isRoot);

  virtual ~ElementNode();

  //
  // Item methods
  //

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::elementNode; }
  Item_t getType() const                      { return theTypeName; }
  Item_t getNodeName() const                  { return theName; }

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

  XmlNode* copy(const XmlNode* parent, unsigned long pos) const;

  virtual XmlNodeVector& children() = 0;
  virtual XmlNodeVector& attributes() = 0;
  virtual const XmlNodeVector& children() const = 0;
  virtual const XmlNodeVector& attributes() const = 0;

  bool isConstructed() const     { return (theFlags & XmlNode::IsConstructed) != 0; }
  bool isCopy() const            { return (theFlags & XmlNode::IsCopy) != 0; }
  bool typePreserve() const      { return (theFlags & XmlNode::TypePreserve) != 0; }
  bool nsPreserve() const        { return (theFlags & XmlNode::NsPreserve) != 0; }
  bool nsInherit() const         { return (theFlags & XmlNode::NsInherit) != 0; }

  bool haveLocalBindings() const { return (theFlags & XmlNode::HaveLocalBindings) != 0; }

  NsBindingsContext* getNsContext() const { return theNsContext.get_ptr(); }

  void setNsContext(NsBindingsContext* ctx);

  xqpStringStore* findBinding(xqpStringStore* prefix) const;

  const NsBindings& getLocalBindings() const;
};


/*******************************************************************************

********************************************************************************/
class LoadedElementNode : public ElementNode
{
protected:
  LoadedXmlNodeVector  theChildren;
  LoadedXmlNodeVector  theAttributes;

public:
  LoadedElementNode(
        const Item*   nodeName,
        const Item*   typeName,
        unsigned long numBindings,
        unsigned long numAttributes);

  unsigned long numAttributes() const      { return theAttributes.size(); }
  XmlNodeVector& attributes()              { return theAttributes; }
  const XmlNodeVector& attributes() const  { return theAttributes; }
  XmlNode* getAttr(unsigned long i) const  { return theAttributes.get(i); }

  unsigned long numChildren() const        { return theChildren.size(); }
  XmlNodeVector& children()                { return theChildren; }
  const XmlNodeVector& children() const    { return theChildren; }
  XmlNode* getChild(unsigned long i) const { return theChildren.get(i); }

  bool isConstructed() const               { return false; }
  bool isCopy() const                      { return false; }

private:
  //disable default copy constructor
  LoadedElementNode(const LoadedElementNode& src);
};


/*******************************************************************************

********************************************************************************/
class ConstrElementNode : public ElementNode
{
private:
  ConstrXmlNodeVector  theChildren;
  ConstrXmlNodeVector  theAttributes;

public:
  ConstrElementNode(
			  Item*             nodeName,
        Item*             typeName,
        Iterator*         childrenIte,
        Iterator*         attributesIte,
        Iterator*         namespacesIte,
        const NsBindings& nsBindings,
        bool              isRoot,
        bool              copy,
        bool              typePreserve,
        bool              nsPreserve,
        bool              nsInherit);

  ConstrElementNode(Item* nodeName, bool isRoot);

  void addChild(
        XmlNode*      childNode,
        unsigned long pos,
        bool          isRoot,
        bool          copy);

  void addAttribute(
        XmlNode*      attrNode,
        unsigned long pos,
        bool          isRoot,
        bool          copy);

  unsigned long numAttributes() const        { return theAttributes.size(); }
  XmlNodeVector& attributes()                { return theAttributes; }
  const XmlNodeVector& attributes() const    { return theAttributes; }
  XmlNode* getAttr(unsigned long i) const    { return theAttributes.get(i); }

  void setAttr(ulong i, XmlNode* n, bool shared)
  {
    theAttributes.set(i, n, shared);
  }

  unsigned long numChildren() const          { return theChildren.size(); }
  XmlNodeVector& children()                  { return theChildren; }
  const XmlNodeVector& children() const      { return theChildren; }
  XmlNode* getChild(unsigned long i) const   { return theChildren.get(i); }

  void setChild(ulong i, XmlNode* n, bool shared)
  {
    theChildren.set(i, n, shared);
  }

  bool isConstructed() const   { return true; }
  bool isCopy() const          { return theFlags & XmlNode::IsCopy; }

  bool typePreserve() const    { return theFlags & XmlNode::TypePreserve; }
  bool nsPreserve() const      { return theFlags & XmlNode::NsPreserve; }
  bool nsInherit() const       { return theFlags & XmlNode::NsInherit; }

private:
  //disable default copy constructor
  ConstrElementNode(const ConstrElementNode& src);
};


/*******************************************************************************

********************************************************************************/
class AttributeNode : public XmlNode
{
 private:
  Item_t   theName;
  Item_t   theTypeName;
  Item_t   theTypedValue;
  bool     theIsId;
  bool     theIsIdrefs;
  
 public:
  AttributeNode(
			  const Item* name,
        const Item* type,
        const Item* typedValue,
        bool  isId,
        bool  isIdrefs,
        bool  isRoot);

  AttributeNode(const Item* name, bool isRoot);

  virtual ~AttributeNode() { }

  XmlNode* copy(const XmlNode* parent, unsigned long pos) const;

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::attributeNode; }

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
 private:
  xqpStringStore_t theContent;

 public:
  TextNode(const xqpStringStore* content, bool isRoot);

  ~TextNode() { }
  
  XmlNode* copy(const XmlNode* parent, unsigned long pos) const;

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::textNode; }

  Item_t getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const   { return theContent.get_ptr(); }
  xqpStringStore* getStringValueP()   { return theContent.get_ptr(); }
			
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
        const xqpStringStore* target,
        const xqpStringStore* data,
        bool                  isRoot);

  ~PiNode() { }

  XmlNode* copy(const XmlNode* parent, unsigned long  pos) const;

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::piNode; }

  Item_t getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const    { return theData.get_ptr(); }

  xqp_string getTarget() const { return theTarget.get_ptr(); }

  xqp_string show() const;
};


/*******************************************************************************

********************************************************************************/
class CommentNode : public XmlNode
{
private:
  xqpStringStore_t theContent;

public:
  CommentNode(const xqpStringStore* content, bool isRoot);

  ~CommentNode() { }

  XmlNode* copy(const XmlNode* parent, unsigned long pos) const;

  StoreConsts::NodeKind_t getNodeKind() const { return StoreConsts::commentNode; }

  Item_t getType() const;

  Iterator_t getTypedValue() const;
  Item_t getAtomizationValue() const;
  xqp_string getStringValue() const   { return theContent.get_ptr(); }
  xqpStringStore* getStringValueP()   { return theContent.get_ptr(); }

  xqp_string show() const;
};


}

#endif
