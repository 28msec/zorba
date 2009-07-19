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
#ifndef ZORBA_MINIMAL_STORE_NODE_ITEMS
#define ZORBA_MINIMAL_STORE_NODE_ITEMS

#include <zorba/error.h>
#include "common/shared_types.h"
#include "zorbamisc/config/platform.h"
#include "zorbautils/fatal.h"
#include "store/api/item.h"
#include "store/minimal/min_item_vector.h"
#include "store/minimal/min_ordpath.h"
#include "store/minimal/min_node_vector.h"
#include "store/minimal/min_loader.h"

namespace zorba 
{  
  
namespace store
{
class CopyMode;
}

namespace storeminimal 
{

class InternalNode;
class AttributeNode;
class NsBindingsContext;

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

typedef std::vector<NodeTypeInfo> TypeUndoList;

typedef rchandle<NsBindingsContext> NsBindingsContext_t;

extern NodeVector dummyVector;


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
  A helper class to model the content of text nodes, which can be either a
  string or an item representing an atomic value or a sequence of atomic values.
********************************************************************************/
class TextNodeContent
{
private:
  union
  {
    xqpStringStore  * text;
    store::Item     * value;
  }
  theContent;

public:
  TextNodeContent() 
  {
    theContent.text = NULL;
  }

  ~TextNodeContent()
  {
    assert(theContent.text == NULL);
  }

  xqpStringStore* getText() const
  {
    return theContent.text;
  }

  xqpStringStore* releaseText()
  {
    xqpStringStore* tmp = theContent.text;
    theContent.text = NULL;
    return tmp; 
  }

  void setText(xqpStringStore_t& text)
  {
    if (theContent.text != NULL)
      theContent.text->removeReference(NULL
                               SYNC_PARAM2(theContent.text->getRCLock()));

    theContent.text = text.transfer();
  }

  void setText(xqpStringStore* text)
  {
    if (theContent.text != NULL)
      theContent.text->removeReference(NULL
                               SYNC_PARAM2(theContent.text->getRCLock()));

    theContent.text = text;
  }

  void copyText(xqpStringStore* text)
  {
    if (theContent.text != NULL)
      theContent.text->removeReference(NULL
                                       SYNC_PARAM2(theContent.text->getRCLock()));

    theContent.text = text;

    if (text)
      theContent.text->addReference(NULL
                                    SYNC_PARAM2(theContent.text->getRCLock()));
  }


  store::Item* getValue() const
  {
    return theContent.value; 
  }

  store::Item* releaseValue()
  {
    store::Item* tmp = theContent.value;
    theContent.value = NULL;
    return tmp; 
  }

  void setValue(store::Item_t& val)
  {
    if (theContent.value != NULL)
      theContent.value->removeReference(
                                NULL
                                SYNC_PARAM2(theContent.value->getRCLock()));

    theContent.value = val.transfer();
  }

  void setValue(store::Item* val)
  {
    if (theContent.value != NULL)
      theContent.value->removeReference(
                                NULL
                                SYNC_PARAM2(theContent.value->getRCLock()));

    theContent.value = val;
  }
  
  void copyValue(store::Item* val)
  {
    if (theContent.value != NULL)
      theContent.value->removeReference(NULL
                                        SYNC_PARAM2(theContent.value->getRCLock()));

    theContent.value = val;

    if (val)
      theContent.value->addReference(NULL
                                     SYNC_PARAM2(theContent.value->getRCLock()));
  }
};


/*******************************************************************************

  theRefCount    : It is the sum of theRefCounts of all the nodes belonging to
                   this tree. Individual nodes are not destroyed when their
                   refCount goes to 0. Instead, nodes belonging to a tree are all
                   destroyed together when theRefCount of the tree goes to 0
                   (i.e. when there are no refs to any of the nodes in the tree).
  theRCLock      : Protects theRefCount
  theId          : An internally generated id for the tree
  theBaseUri     : The base uri property of the tree's root node.
  theDocUri      : A user provided uri for the tree (may be NULL)
  theRootNode    : The root node of the tree.
  theIsValidated : True if the tree has ever undergone schema validation.
********************************************************************************/
class XmlTree
{
protected:
  mutable long              theRefCount;
  SYNC_CODE(mutable RCLock  theRCLock;)

  ulong             theId;
public:

  xqpStringStore_t          theDocUri;
  xqpStringStore_t          theBaseUri;
  XmlNode         * theRootNode;

  bool                      theIsValidated;

  //minNodeVector  xml_nodes;//keep all xml nodes here
  XmlLoader_t   attachedloader;

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

  xqpStringStore* getDocUri() const { return theDocUri.getp(); }

  void setDocUri(const xqpStringStore_t& uri) { theDocUri = uri; }

  xqpStringStore* getBaseUri() const { return theBaseUri.getp(); }

  void setBaseUri(const xqpStringStore_t& uri) { theBaseUri = uri; }

  XmlNode* getRoot() const      { return theRootNode; }

  void setRoot(XmlNode* root)   { theRootNode = root; }

  bool isValidated() const { return theIsValidated; }
  void markValidated()     { theIsValidated = true; }

};



/*******************************************************************************

********************************************************************************/
class XmlNode : public store::Item
{
  friend class XmlTree;

  friend class InternalNode;
  friend class DocumentNode;
  friend class ElementNode;
  friend class AttributeNode;
  friend class TextNode;
  friend class PiNode;
  friend class CommentNode;
  friend class PULImpl;
  friend class UpdDelete;
  friend class UpdInsertSiblings;
  friend class UpdReplaceChild;
  friend class UpdReplaceContent;
  friend class UpdReplaceAttribute;
  friend class UpdReplaceAttrValue;
  friend class UpdReplaceTextValue;
  friend class BasicItemFactory;
  friend class XmlLoader;

public:
  enum NodeFlags
  {
    NodeKindMask      =   7,
    IsId              =   8,
    IsIdRefs          =   16,
    HaveTypedValue    =   32,   // for element nodes only
    HaveEmptyValue    =   64,   // for element nodes only
    IsTyped           =   128,  // for text nodes only
    HaveListValue     =   256,  // for text and attribute nodes only

    HaveLocalBindings =   512,  // for element nodes only
    HaveBaseUri       =   1024, // for element nodes only
    IsBaseUri         =   2048, // for attribute nodes only
    IsHidden          =   4096  // for attribute nodes only
    ,IsNotFullLoaded   =   8192
  };


protected:
  //XmlTree  * theTree;
  OrdPath      theOrdPath;
  InternalNode    * theParent;
  uint32_t      theFlags;

public:
  XmlNode(store::StoreConsts::NodeKind nodeKind)
    :
    Item(),
    theParent(NULL)
  {
    theFlags = (uint32_t)nodeKind;
  }

  XmlNode(
        XmlTree*              tree,
        InternalNode*         parent,
        long                  pos,
        store::StoreConsts::NodeKind nodeKind);

  virtual ~XmlNode();

  void free() { if (getTree() != NULL) getTree()->free(); }

  //
  // Item methods
  //

  bool isNode() const       { return true; }
  bool isAtomic() const     { return false; }
  bool isPul() const        { return false; }
  bool isTuple() const      { return false; }
  bool isError() const      { return false; }


  store::StoreConsts::NodeKind getNodeKind() const
  {
    return (store::StoreConsts::NodeKind)(theFlags & NodeKindMask);
  }

  virtual xqpStringStore* getDocumentURI() const 
  {
    return 0; 
  }

  xqpStringStore_t getBaseURI() const
  {
    bool local = false;
    return getBaseURIInternal(local);
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
    return this == other;
  }

  uint32_t hash(
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  store::Item_t getEBV() const;

  store::Item* copy(
        store::Item*           parent,
        const store::CopyMode& copymode) const;

  virtual store::Item_t getNilled() const { return 0; }

  virtual bool isId() const { return false; }

  virtual bool isIdRefs() const { return false; }

  bool isValidated() const { return getTree()->isValidated(); }

  void markValidated()     { getTree()->markValidated(); }

  virtual void finalizeNode() { return; }

  //
  // SimpleStore Methods
  //

  void setTree(const XmlTree* t);
  XmlTree* getTree() const          { return (XmlTree*)theTreeRCPtr; }

  ulong getTreeId() const           { return getTree()->getId(); }

  const OrdPath& getOrdPath() const { return theOrdPath; }
  OrdPath& getOrdPath()             { return theOrdPath; }

  void setId(XmlTree* tree, const OrdPathStack* op);

  void setOrdPath(
    InternalNode* parent, 
    long pos,
    store::StoreConsts::NodeKind nodeKind);

  void setParent(InternalNode* p) { theParent = p; }

  //GuideNode* getDataGuide() const   { return getTree()->getDataGuide(); }

  xqpStringStore* getBaseUri() const { return getTree()->getBaseUri(); }

  void setBaseUri(const xqpStringStore_t& uri) { getTree()->setBaseUri(uri); }

  xqpStringStore* getDocUri() const { return getTree()->getDocUri(); }

  void setDocUri(const xqpStringStore_t& uri) { getTree()->setDocUri(uri); }

  virtual XmlNode* copyInternal(
        InternalNode*          rootParent,
        InternalNode*          parent,
        long                   pos,
        const XmlNode*         rootCopy,
        const store::CopyMode& copyMode) const = 0;

  void setToUntyped();
  void removeType(UpdatePrimitive& upd);
  void restoreType(TypeUndoList& undoList);

  void insertSiblingsBefore(UpdInsertChildren& upd);
  void insertSiblingsAfter(UpdInsertChildren& upd);


  //virtual XmlLoader_t hasLoaderAttached() const         {return NULL;}
  virtual unsigned short        getDepth()  {return 0;}         //depth is usefull only for loaded element nodes
  virtual bool isFullLoaded() const              {return !(theFlags&IsNotFullLoaded);}
  void setIsFullLoaded(bool is_loaded) 
  {
    if(is_loaded)
      theFlags &= ~IsNotFullLoaded;
    else
      theFlags |= IsNotFullLoaded;
  }

protected:
  virtual xqpStringStore_t getBaseURIInternal(bool& local) const;

  void attach(InternalNode* parent, long pos);

  void detach() throw();

  void destroy() throw();

  long disconnect() throw();

  void connect(InternalNode* node, ulong pos) throw();

private:
  void destroyInternal() throw();
};

/*******************************************************************************
  Base class for element and document nodes
********************************************************************************/
class InternalNode : public XmlNode
{
  friend class XmlNode;

protected:
  NodeVector  theChildren;
  NodeVector  theAttributes;

public:
  InternalNode(store::StoreConsts::NodeKind nodeKind) : XmlNode(nodeKind) { }

  InternalNode(
        XmlTree*                     tree,
        InternalNode*                parent,
        long                         pos,
        store::StoreConsts::NodeKind nodeKind)
    :
    XmlNode(tree, parent, pos, nodeKind)
  {
  }

  //
  // SimpleStore Methods
  // 

  ulong numChildren() const          { return theChildren.size(); }
  NodeVector& children()             { return theChildren; }
  const NodeVector& children() const { return theChildren; }
  XmlNode* getChild(ulong i) const   { return theChildren.get(i); }

  ulong numAttributes() const          { return theAttributes.size(); }
  NodeVector& attributes()             { return theAttributes; }
  const NodeVector& attributes() const { return theAttributes; }

  AttributeNode* getAttr(ulong i) const
  {
    return reinterpret_cast<AttributeNode*>(theAttributes.get(i));
  }

  virtual NsBindingsContext* getNsContext() const = 0;

  void deleteChild(UpdDelete& upd);
  void restoreChild(UpdDelete& upd);

  void insertChildren(UpdInsertChildren& upd, ulong pos);
  void undoInsertChildren(UpdInsertChildren& upd);

  void replaceChild(UpdReplaceChild& upd);
  void restoreChild(UpdReplaceChild& upd);

protected:
  void insertChild(XmlNode* child, ulong pos);
  bool removeChild(ulong pos);
  bool removeChild(XmlNode* child);

  void removeChildren(ulong pos, ulong numChildren);

  void removeAttr(ulong pos);
  bool removeAttr(XmlNode* attr);
};

/*******************************************************************************

********************************************************************************/
class DocumentNode : public InternalNode
{
public:
  DocumentNode();

  DocumentNode(
        XmlTree*          tree,
        const xqpStringStore_t& baseUri,
        const xqpStringStore_t& docUri);

  virtual ~DocumentNode();

  //
  // Item methods
  //

  store::Item* getType() const; 

  xqpStringStore* getDocumentURI() const { return getDocUri(); }

  store::Iterator_t getChildren() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;
  
  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  store::Item* getNodeName() const { return NULL; }

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  XmlNode* copyInternal(
        InternalNode*          rootParent,
        InternalNode*          parent,
        long                   pos,
        const XmlNode*         rootCopy,
        const store::CopyMode& copyMode) const;

  NsBindingsContext* getNsContext() const                { return NULL; }

  void finalizeNode()                { theChildren.compact(); }

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;
};


/*******************************************************************************

********************************************************************************/
class ElementNode : public InternalNode
{
  friend class XmlNode;
  friend class AttributeNode;
  friend class UpdSetElementType;
  friend class UpdReplaceContent;

  friend class XmlLoader;

public:
  store::Item_t                theName;
protected:
  store::Item_t                theTypeName;
  NsBindingsContext_t   theNsContext;

public:
//  XmlLoader_t   attachedloader;//for documents and elements might be false. Means it is full loaded
  unsigned short           depth;
public:
  ElementNode(
        store::Item_t& nodeName,
        //ulong          numBindings,
        store::NsBindings *nsbindings,
        ulong          numAttributes);

  ElementNode(
        XmlTree*                    tree,
        InternalNode*               parent,
        long                        pos,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        bool                        haveTypedValue,
        bool                        haveEmptyValue,
        const store::NsBindings*    localBindings,
        xqpStringStore_t&           baseUri,
        bool                        doswap_nsbindings);

  virtual ~ElementNode();

  //
  // Item methods
  //

  store::Item* getNodeName() const { return theName.getp(); }

  store::Item* getType() const { return theTypeName.getp(); }

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  store::Item_t getAtomizationValue() const;

  bool isId() const;

  bool isIdRefs() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  store::Item_t getNilled() const;

  store::Iterator_t getAttributes() const;
  store::Iterator_t getChildren() const;

  void getNamespaceBindings(
        store::NsBindings& bindings,
        store::StoreConsts::NsScoping scope = store::StoreConsts::ALL_NAMESPACES) const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  bool haveBaseUri() const      { return (theFlags & HaveBaseUri) != 0; }
  void setHaveBaseUri()         { theFlags |= HaveBaseUri; }
  void resetHaveBaseUri()       { theFlags &= ~HaveBaseUri; }
  
  void setHaveValue()           { theFlags |= HaveTypedValue; }
  void resetHaveValue()         { theFlags &= ~HaveTypedValue; }
  bool haveValue() const        { return (theFlags & HaveTypedValue) != 0; }
  void setHaveEmptyValue()      { theFlags |= HaveEmptyValue; }
  void resetHaveEmptyValue()    { theFlags &= ~HaveEmptyValue; }
  bool haveEmptyValue() const   { return (theFlags & HaveEmptyValue) != 0; }

  bool haveTypedTypedValue() const;

  bool haveLocalBindings() const{ return (theFlags & HaveLocalBindings) != 0; }

  void finalizeNode()
  {
    theChildren.compact();
    theAttributes.compact();
  }

//  virtual XmlLoader_t hasLoaderAttached() const        {return attachedloader;}
  virtual unsigned short        getDepth()         {return depth;}

  NsBindingsContext* getNsContext() const { return theNsContext.getp(); }

  void setNsContext(NsBindingsContext* ctx);
  xqpStringStore* findBinding(const xqpStringStore* prefix) const;
  const store::NsBindings& getLocalBindings() const;
  void addLocalBinding(xqpStringStore* prefix, xqpStringStore* ns);
  void removeLocalBinding(xqpStringStore* prefix, xqpStringStore* ns);

  bool addBindingForQName(
        store::Item_t& qname,
        bool           isAttr,
        bool           replacePrefix);
  void addBindingForQName2(const store::Item* qname);

  void checkNamespaceConflict(
        const store::Item*           qname,
        XQUERY_ERROR ecode) const;

  void checkUniqueAttr(const store::Item* attrName) const;
  void checkUniqueAttrs() const;

  XmlNode* copyInternal(
        InternalNode*          rootParent,
        InternalNode*          parent,
        long                   pos,
        const XmlNode*         rootCopy,
        const store::CopyMode& copymode) const;

  void removeAttributes(ulong pos, ulong numAttributes);

  void insertAttributes(UpdInsertAttributes& upd);
  void undoInsertAttributes(UpdInsertAttributes& upd);

  void replaceAttribute(UpdReplaceAttribute& upd);
  void restoreAttribute(UpdReplaceAttribute& upd);

  void replaceContent(UpdReplaceElemContent& upd);
  void restoreContent(UpdReplaceElemContent& upd);

  void replaceName(UpdRenameElem& upd);
  void restoreName(UpdRenameElem& upd);

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;

  void addBaseUriProperty(
        xqpStringStore_t& absUri,
        xqpStringStore_t& relUri);

  void adjustBaseUriProperty(
        AttributeNode*    attr,
        xqpStringStore_t& absUri,
        xqpStringStore_t& relUri);
private:
  //disable default copy constructor
  ElementNode(const ElementNode& src);
};


/*******************************************************************************

********************************************************************************/
class AttributeNode : public XmlNode
{
  friend class XmlNode;
  friend class ElementNode;
  friend class XmlLoader;
  friend class UpdSetAttributeType;

protected:
  store::Item_t   theName;
  store::Item_t   theTypeName;
  store::Item_t   theTypedValue;

public:
  AttributeNode(
        store::Item_t&  attrName,
        store::Item_t&  typeName);

  AttributeNode(
        XmlTree*  tree,
        ElementNode*  parent,
        long      pos,
        store::Item_t&   attrName,
        store::Item_t&   typeName,
        store::Item_t&              typedValue,
        bool                        isListValue,
        bool                        hidden);

  virtual ~AttributeNode();


  //
  // Item methods
  //

  store::Item* getNodeName() const { return theName.getp(); }

  store::Item* getType() const     { return theTypeName.getp(); }

  void setTypedValue(store::Item_t& val);
  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  store::Item_t getAtomizationValue() const;

  bool isId() const;

  bool isIdRefs() const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  XmlNode* copyInternal(
        InternalNode*          rootParent,
        InternalNode*          parent,
        long                   pos,
        const XmlNode*         rootCopy,
        const store::CopyMode& copymode) const;

  void setIsIdRefs()          { theFlags |= IsIdRefs; }
  void resetIsIdRefs()        { theFlags &= ~IsIdRefs; }

  bool haveListValue() const  { return (theFlags & HaveListValue) != 0; }
  void resetHaveListValue()   { theFlags &= ~HaveListValue; }
  void setHaveListValue()     { theFlags |= HaveListValue; }

  bool isHidden() const       { return (theFlags & IsHidden) != 0; }
  void setHidden()            { theFlags |= IsHidden; }

  bool isBaseUri() const      { return (theFlags & IsBaseUri) != 0; }

  void replaceValue(UpdReplaceAttrValue& upd);
  void restoreValue(UpdReplaceAttrValue& upd);

  void replaceName(UpdRenameAttr& upd);
  void restoreName(UpdRenameAttr& upd);


protected:
  ItemVector& getValueVector() 
  {
    return *reinterpret_cast<ItemVector*>(theTypedValue.getp()); 
  }

  const ItemVector& getValueVector() const
  {
    return *reinterpret_cast<ItemVector*>(theTypedValue.getp()); 
  }
};
   

/*******************************************************************************

********************************************************************************/
class TextNode : public XmlNode
{
  friend class XmlNode;
  friend class InternalNode;
  friend class DocumentDagNode;
  friend class ElementNode;
  friend class BasicItemFactory;
  friend class UpdInsertChildren;
  friend class UpdSetElementType;
  friend class XmlLoader;

protected:
  TextNodeContent theContent;

public:
  TextNode(xqpStringStore_t& content);

  TextNode(
        XmlTree*          tree,
        InternalNode*     parent,
        long              pos,
        xqpStringStore_t& content);

  TextNode(
        InternalNode*          parent,
        store::Item_t&    content,
        bool              isListValue);

  virtual ~TextNode();

  //
  // Item methods
  //

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  store::Item* getNodeName() const { return NULL; }

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  XmlNode* copyInternal(
        InternalNode*          rootParent,
        InternalNode*          parent,
        long                   pos,
        const XmlNode*         rootCopy,
        const store::CopyMode& copymode) const;

  bool isTyped() const;
  void setTyped(store::Item_t& value);
  void resetTyped();

  bool haveListValue() const { return (theFlags & HaveListValue) != 0; }
  void resetHaveListValue()  { theFlags &= ~HaveListValue; }
  void setHaveListValue()    { theFlags |= HaveListValue; }

  bool isIdInternal() const;

  bool isIdRefsInternal() const;

  void replaceValue(UpdReplaceTextValue& upd);

  void restoreValue(UpdReplaceTextValue& upd);

protected:
  xqpStringStore* getText() const      { return theContent.getText(); }

  void setText(xqpStringStore_t& text) { theContent.setText(text); }
  void setText(xqpStringStore* text)   { theContent.setText(text); }

  store::Item* getValue() const        { return theContent.getValue(); }

  void setValue(store::Item_t& val)    { theContent.setValue(val); }
  void setValue(store::Item* val)      { theContent.setValue(val); }
};


/*******************************************************************************

********************************************************************************/
class PiNode : public XmlNode
{
  friend class XmlNode;

 protected:
  xqpStringStore_t theTarget;
  xqpStringStore_t theContent;

  store::Item_t   theName;
public:
  PiNode(xqpStringStore_t& target, xqpStringStore_t& content);

  PiNode(
        XmlTree*          tree,
        InternalNode*     parent,
        long              pos,
        xqpStringStore_t& target,
        xqpStringStore_t& content);

  ~PiNode();

  XmlNode* copyInternal(
        InternalNode*          rootParent,
        InternalNode*          parent,
        long                   pos,
        const XmlNode*         rootCopy,
        const store::CopyMode& copymode) const;

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const    { return theContent; }
  xqpStringStore* getStringValueP() const    { return theContent.getp(); }
  void getStringValue(xqpStringStore_t& strval) const { strval = theContent; }
  void getStringValue(std::string& buf) const { buf += theContent->str(); }

  store::Item* getNodeName() const { return theName.getp(); }
  xqpStringStore* getTarget() const { return theTarget.getp(); }

  xqp_string show() const;

  void replaceValue(UpdReplacePiValue& upd);
  void restoreValue(UpdReplacePiValue& upd);

  void replaceName(UpdRenamePi& upd);
  void restoreName(UpdRenamePi& upd);
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
        InternalNode*          parent,
        long              pos,
        xqpStringStore_t& content);

  ~CommentNode();

  XmlNode* copyInternal(
        InternalNode*          rootParent,
        InternalNode*          parent,
        long                   pos,
        const XmlNode*         rootCopy,
        const store::CopyMode& copymode) const;

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const   { return theContent; }
  xqpStringStore* getStringValueP() const   { return theContent.getp(); }
  void getStringValue(xqpStringStore_t& strval) const { strval = theContent; }
  void getStringValue(std::string& buf) const { buf += theContent->str(); }

  store::Item* getNodeName() const { return NULL; }

  xqp_string show() const;

  void replaceValue(UpdReplaceCommentValue& upd);
  void restoreValue(UpdReplaceCommentValue& upd);
};


} // namespace storeminimal
} // namespace zorba

#endif
