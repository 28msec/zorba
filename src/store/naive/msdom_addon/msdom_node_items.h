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

#ifndef ZORBA_SIMPLE_STORE_MSDOM_NODE_ITEMS
#define ZORBA_SIMPLE_STORE_MSDOM_NODE_ITEMS

#include <windows.h>
#include <msxml.h>

#include <zorba/error.h>

#include "common/shared_types.h"
#include "zorbamisc/config/platform.h"
#include "zorbautils/fatal.h"
#include "store/api/item.h"
#include "store/naive/item_vector.h"
#include "store/naive/ordpath.h"
#include "store/naive/node_vector.h"
#include "store/naive/store_config.h"

#define ZORBA_MSDOM_IN_NATIVE_STORE_CACHING

namespace zorba 
{ 

namespace store
{
  class CopyMode;
}


namespace simplestore 
{

class AttributeNode;
class NsBindingsContext;
class GuideNode;

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

typedef rchandle<NsBindingsContext> NsBindingsContext_t;

extern ConstrNodeVector dummyVector;


#define NODE_STOP \
  ZORBA_FATAL(0, "Invalid method invocation on " \
              << store::StoreConsts::toString(getNodeKind()))


/*******************************************************************************

********************************************************************************/
/*******************************************************************************
  A helper class to model the content of text nodes, which can be either a
  string or an item representing a simple-typed value.
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
  IXMLDOMText     *theDOMText;

public:
  TextNodeContent() 
  {
    theContent.text = NULL;
    theDOMText = NULL;
  }

  ~TextNodeContent()
  {
    assert(theContent.text == NULL);
  }

  xqpStringStore* getText() const;

  xqpStringStore* transferText()
  {
    xqpStringStore* tmp = theContent.text;
    theContent.text = NULL;
    return tmp; 
  }

  void setText(xqpStringStore_t& text, bool update_DOM = true);
  void setText(xqpStringStore* text, bool update_DOM = true);


  store::Item* getValue() const
  {
    return theContent.value; 
  }

  store::Item* transferValue()
  {
    store::Item* tmp = theContent.value;
    theContent.value = NULL;
    return tmp; 
  }

  void setValue(store::Item_t& val, bool update_DOM = true);
  void setValue(store::Item* val, bool update_DOM = true);
};


/*******************************************************************************
  A class to store the type-related info of a node. Used during node updates to
  implement the undo of updates.
********************************************************************************/
class NodeTypeInfo
{
public:
  XmlNode           * theNode;

  store::Item_t       theTypeName;
  TextNodeContent     theTextContent;
  bool                theIsTyped;
  uint16_t            theFlags;

  NodeTypeInfo() : theIsTyped(false), theFlags(0) { }

  ~NodeTypeInfo()
  {
    if (theIsTyped)
      theTextContent.setValue(NULL);
    else
      theTextContent.setText(NULL);
  }
};


/*******************************************************************************

********************************************************************************/
typedef std::vector<NodeTypeInfo> TypeUndoList;


/*******************************************************************************

********************************************************************************/
class XmlTree
{
protected:
  mutable long              theRefCount;
  SYNC_CODE(mutable RCLock  theRCLock;)

  ulong                     theId;

  XmlNode                 * theRootNode;

  GuideNode               * theDataGuideRootNode;

  IXMLDOMDocument         * theDOMcreator;
public:
  bool                    during_import_DOM;//set true during import DOM

public:
  XmlTree(XmlNode* root, ulong id);

  ~XmlTree() { theRootNode = 0; }

  void free() throw();

  long getRefCount() const      { return theRefCount; }
  long& getRefCount()           { return theRefCount; }
  void addReference()           { ++theRefCount; }
  void removeReference()        { --theRefCount; }

  SYNC_CODE(RCLock& getRCLock() const { return theRCLock; })

  ulong getId() const                { return theId; }
  XmlNode* getRoot() const           { return theRootNode; }
  void setRoot(XmlNode* root);

  GuideNode* getDataGuide() const    { return theDataGuideRootNode; }
  void setDataGuide(GuideNode* root) { theDataGuideRootNode = root; }

  IXMLDOMDocument   *getDOMcreator();
  void setDOMcreator(IXMLDOMDocument *theDOMdoc);

};



/*******************************************************************************

  Note: No synchronization is required for access to theTree and theOrdPath data
  members, because once set, their value cannot change again, and furthermore,
  the setting of these data members occurs within the thread that created the
  node, before the node becomes visible to any other thread.

********************************************************************************/
class XmlNode : public store::Item
{
  friend class DocumentNode;
  friend class ElementNode;
  friend class ElementTreeNode;
  friend class ElementDagNode;
  friend class AttributeNode;
  friend class TextNode;
  friend class PiNode;
  friend class CommentNode;
  friend class UpdDelete;
  friend class UpdInsertSiblings;
  friend class UpdReplaceChild;
  friend class UpdReplaceContent;
  friend class UpdReplaceAttribute;
  friend class UpdReplaceAttrValue;
  friend class UpdReplaceTextValue;
  friend class BasicItemFactory;
  
public:
  enum NodeFlags
  {
    IsId              =   1,
    IsIdRefs          =   2,
    HaveValue         =   4,
    HaveEmptyValue    =   8,
    HaveTypedValue    =   16, // 1001 0000
    HaveListValue     =   32,
    HaveLocalBindings =   64,  // for element nodes only
    HaveBaseUri       =   128, // for element nodes only
    IsBaseUri         =   256, // for attribute nodes only
    IsHidden          =   512  // for attribute nodes only
  };

protected:
  //XmlTree  * theTree;
  OrdPath      theOrdPath;
  XmlNode    * theParent;

public:
  XmlNode() : Item(), theParent(NULL) { }

  //-XmlNode(
  //-      XmlTree*                     tree,
  //-      XmlNode*                     parent,
  //-      long                         pos,
  //-      store::StoreConsts::NodeKind nodeKind);
  XmlNode(
    XmlTree*              tree,
    XmlNode*              parent);

  virtual ~XmlNode();

  void free() { if (getTree() != NULL) getTree()->free(); }

  //
  // Item methods
  //

  bool isNode() const       { return true; }
  bool isAtomic() const     { return false; }
  bool isPul() const        { return false; }
  bool isTuple() const      { return false; }

  store::Item* getParent() const   { return theParent; }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        XQPCollator* aCollation = 0) const
  {
    return this == other;
  }

  uint32_t hash(
        long timezone = 0,
        XQPCollator* aCollation = 0) const;

  store::Item* copy(
        store::Item*           parent,
        long                   pos,
        const store::CopyMode& copymode) const
  {
    return copy2(static_cast<XmlNode*>(parent),
                 static_cast<XmlNode*>(parent),
                 pos,
                 copymode);
  }

  store::Item_t getEBV() const;

  xqpStringStore_t getBaseURI() const
  {
    bool local = false;
    return getBaseURIInternal(local);
  }

  virtual xqpStringStore* getDocumentURI() const { return 0; }

  virtual store::Item_t getNilled() const { return 0; }

  virtual void finalizeNode() { return; }

  //
  // SimpleStore Methods
  //

  GuideNode* getDataGuide() const   { return getTree()->getDataGuide(); }
  
  void setParent(
                  XmlTree*              tree,
                  XmlNode*              parent,
                  long                  pos,
                  store::StoreConsts::NodeKind nodeKind);

/*-
  void setParent(XmlNode* p)        
  {
    theParent = p; 
    IXMLDOMNode   *parentDOM = p->GetDOMNode();
    IXMLDOMNode   *thisDOM = GetDOMNode();
    ...
  }
*/
  IXMLDOMNode   *GetDOMNode2() {return GetDOMNode();}
  virtual IXMLDOMNode   *GetDOMNode() = 0;
  virtual IXMLDOMAttribute   *GetDOMAttribute() {return NULL;}
  virtual IXMLDOMElement   *GetDOMElement() {return NULL;}

  void setTree(const XmlTree* t, XmlNode*  parent);
  XmlTree* getTree() const          { return (XmlTree*)theTreeRCPtr; }
  ulong getTreeId() const           { return getTree()->getId(); }
  const OrdPath& getOrdPath() const { return theOrdPath; }
  OrdPath& getOrdPath()             { return theOrdPath; }

  void setId(XmlTree* tree, const OrdPathStack* op);

  void setOrdPath(
        XmlNode* parent,
        long pos,
        store::StoreConsts::NodeKind nodeKind);

  void switchTree(
        XmlNode*               parent,
        ulong                  pos,
        const store::CopyMode& copymode) throw();

  void deleteTree() throw();

  void setToUntyped();
  void removeType(UpdatePrimitive& upd);
  void restoreType(TypeUndoList& undoList);

  void removeChildren(ulong pos, ulong numChildren);

  void insertChildren(UpdInsertChildren& upd, ulong pos);
  void undoInsertChildren(UpdInsertChildren& upd);
  
  void insertSiblingsBefore(UpdInsertChildren& upd);
  void insertSiblingsAfter(UpdInsertChildren& upd);

  void replaceChild(UpdReplaceChild& upd);
  void restoreChild(UpdReplaceChild& upd);

  virtual XmlNode* copy2(
        XmlNode*               rootParent,
        XmlNode*               parent,
        long                   pos,
        const store::CopyMode& copyMode) const = 0;

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

protected:
  virtual xqpStringStore_t getBaseURIInternal(bool& local) const;

  ulong disconnect() throw();
  void connect(XmlNode* node, ulong pos) throw();
  void removeChild(ulong pos);
  bool removeChild(XmlNode* child);
  void removeAttr(ulong pos);
  bool removeAttr(XmlNode* attr);


  store::Item_t QNameFromDOM() const;
  void add_attribute(AttributeNode *attr, ulong pos, bool shared);
  void add_child(XmlNode *child, ulong pos, bool shared);
};


/*******************************************************************************

********************************************************************************/
class DocumentNode : public XmlNode
{
protected:
  xqpStringStore_t    theBaseUri;
  xqpStringStore_t    theDocUri;

  IXMLDOMDocument         * theDOMdoc;
  IXMLDOMDocumentFragment * theDOMfragment;

public:
/*  DocumentNode(
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri);
*/
  DocumentNode(
        XmlTree*          tree,
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri,
        IXMLDOMDocument *dom_doc = NULL,
        IXMLDOMDocumentFragment * dom_fragment = NULL);

  virtual ~DocumentNode();

  //
  // Item methods
  //

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return store::StoreConsts::documentNode;
  }

  store::Item* getType() const; 

  xqpStringStore* getDocumentURI() const { return theDocUri.getp(); }

  store::Iterator_t getChildren() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const;

  xqp_string show() const;

  //
  // SimpleStore Methods
  // 

  XmlNode* copy2(
        XmlNode*        rootParent,
        XmlNode*        parent,
        long            pos,
        const store::CopyMode& copyMode) const;

  NsBindingsContext* getNsContext() const                { return NULL; }
  xqpStringStore* findBinding(xqpStringStore* pre) const { return NULL; }

  virtual IXMLDOMNode    *GetDOMNode() { if(theDOMfragment) return theDOMfragment; else return theDOMdoc; }
/*  virtual IXMLDOMElement *GetDOMElement()
  {
    if(!theDOMdoc)
      return NULL;
    IXMLDOMElement   *dom_element = NULL;
    if(SUCCEEDED(theDOMdoc->QueryInterface(IID_IXMLDOMElement, (void**)&dom_element)))
    {
      dom_element->Release();
      return dom_element;
    }
    else
      return NULL;
  }
*/

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;
};


/*******************************************************************************

********************************************************************************/
class DocumentTreeNode : public DocumentNode
{
  

private:
  LoadedNodeVector theChildren;

public:
/*  DocumentTreeNode(
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri);
*/
  DocumentTreeNode(
        XmlTree*          tree,
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri,
        IXMLDOMDocument *dom_doc = NULL,
        IXMLDOMDocumentFragment * dom_fragment = NULL);

  ulong numChildren() const          { return theChildren.size(); }
  NodeVector& children()             { return theChildren; }
  const NodeVector& children() const { return theChildren; }
  XmlNode* getChild(ulong i) const   { return theChildren.get(i); }

  void finalizeNode()                { theChildren.compact(); }
};


/*******************************************************************************

********************************************************************************/
class DocumentDagNode : public DocumentNode
{
protected:
  ConstrNodeVector theChildren;

public:
  DocumentDagNode(
        XmlTree*          tree,
        xqpStringStore_t& baseUri,
        xqpStringStore_t& docUri);
        
  ulong numChildren() const          { return theChildren.size(); }
  NodeVector& children()             { return theChildren; }
  const NodeVector& children() const { return theChildren; }
  XmlNode* getChild(ulong i) const   { return theChildren.get(i); }

  void finalizeNode()                { theChildren.compact(); }
};


/*******************************************************************************

********************************************************************************/
class ElementNode : public XmlNode
{
  friend class XmlNode;
  friend class ElementTreeNode;
  friend class AttributeNode;
  friend class UpdSetElementType;

protected:
  IXMLDOMElement        * theDOMElement;
#ifdef ZORBA_MSDOM_IN_NATIVE_STORE_CACHING
  store::Item_t         theName;
#endif
  store::Item_t         theTypeName;
//#ifdef ZORBA_MSDOM_IN_NATIVE_STORE_CACHING
  NsBindingsContext_t   theNsContext;
//#endif
  uint16_t              theFlags;

public:
  ElementNode(
        XmlTree*                 tree,
        XmlNode*                 parent,
        long                     pos,
        store::Item_t&           nodeName,
        store::Item_t&           typeName,
        bool                     haveTypedValue,
        bool                     haveEmptyValue,
        bool                     isId,
        bool                     isIdRefs,
        const store::NsBindings* localBindings,
        IXMLDOMElement        * dom_element = NULL);

  virtual ~ElementNode();

  //
  // Item methods
  //

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return store::StoreConsts::elementNode; 
  }

  store::Item* getType() const     { return theTypeName.getp(); }
  store::Item* getNodeName() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const;
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

  bool isId() const             { return (theFlags & IsId) != 0; }
  void setIsId()                { theFlags |= IsId; }
  void resetIsId()              { theFlags &= ~IsId; }
  bool isIdRefs() const         { return (theFlags & IsIdRefs) != 0; }
  void setIsIdRefs()            { theFlags |= IsIdRefs; }
  void resetIsIdRefs()          { theFlags &= ~IsIdRefs; }
  bool haveBaseUri() const      { return (theFlags & HaveBaseUri) != 0; }
  void setHaveBaseUri()         { theFlags |= HaveBaseUri; }
  void resetHaveBaseUri()       { theFlags &= ~HaveBaseUri; }
  void setHaveValue()           { theFlags |= HaveValue; }
  void resetHaveValue()         { theFlags &= ~HaveValue; }
  bool haveValue() const        { return (theFlags & HaveValue) != 0; }
  void setHaveEmptyValue()      { theFlags |= HaveEmptyValue; }
  void resetHaveEmptyValue()    { theFlags &= ~HaveEmptyValue; }
  bool haveEmptyValue() const   { return (theFlags & HaveEmptyValue) != 0; }
  void setHaveTypedValue()      { theFlags |= HaveTypedValue; }
  void resetHaveTypedValue()    { theFlags &= ~HaveTypedValue; }
  bool haveTypedValue() const   { return (theFlags & HaveTypedValue) != 0; }
  bool haveListValue() const    { return (theFlags & HaveListValue) != 0; }
  void resetHaveListValue()     { theFlags &= ~HaveListValue; }
  void setHaveListValue()       { theFlags |= HaveListValue; }
  bool haveLocalBindings() const{ return (theFlags & HaveLocalBindings) != 0; }

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
        const store::Item* qname,
        XQUERY_ERROR       ecode) const;

  void checkUniqueAttr(const store::Item* attrName) const;

  XmlNode* copy2(
        XmlNode*               rootParent,
        XmlNode*               parent,
        long                   pos,
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

  void add_ns_bindings_to_DOM(const store::NsBindings* localBindings);
  void addLocalBinding_DOM(xqpStringStore* prefix, xqpStringStore* ns);

  virtual IXMLDOMNode     *GetDOMNode()         { return theDOMElement; }
  virtual IXMLDOMElement  *GetDOMElement()      { return theDOMElement; }
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
class ElementTreeNode : public ElementNode
{
  friend class ElementNode;
  friend class UpdReplaceContent;
  

protected:
  LoadedNodeVector  theChildren;
  LoadedNodeVector  theAttributes;

public:

  ElementTreeNode(
        XmlTree*                    tree,
        XmlNode*                    parent,
        long                        pos,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        bool                        haveValue,
        bool                        haveEmptyValue,
        bool                        isId,
        bool                        isIdRefs,
        const store::NsBindings*    localBindings,
        xqpStringStore_t&           baseUri,
        IXMLDOMElement        * dom_element = NULL);

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

  void finalizeNode()
  {
    theChildren.compact();
    theAttributes.compact();
  }

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;

private:
  //disable default copy constructor
  ElementTreeNode(const ElementTreeNode& src);
};


/*******************************************************************************

********************************************************************************/
class ElementDagNode : public ElementNode
{
  friend class ElementNode;
  friend class UpdReplaceContent;

protected:
  ConstrNodeVector  theChildren;
  ConstrNodeVector  theAttributes;

public:
  ElementDagNode(
        XmlTree*                    tree,
        XmlNode*                    parent,
        long                        pos,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        bool                        haveTypedValue,
        bool                        haveEmptyValue,
        bool                        isId,
        bool                        isIdRefs,
        const store::NsBindings*    localBindings,
        xqpStringStore_t&           baseUri);

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

  void finalizeNode()
  {
    theChildren.compact();
    theAttributes.compact();
  }

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;

private:
  //disable default copy constructor
  ElementDagNode(const ElementDagNode& src);
};


/*******************************************************************************

********************************************************************************/
class AttributeNode : public XmlNode
{
  friend class XmlNode;
  friend class ElementNode;
  friend class UpdSetAttributeType;
  

protected:
  IXMLDOMAttribute    * theDOMAttribute;
#ifdef ZORBA_MSDOM_IN_NATIVE_STORE_CACHING
  store::Item_t   theName;
#endif
  store::Item_t   theTypeName;
  store::Item_t   theTypedValue;
  uint16_t        theFlags;

public:
  AttributeNode(
        XmlTree*                    tree,
        XmlNode*                    parent,
        long                        pos,
        store::Item_t&              attrName,
        store::Item_t&              typeName,
        store::Item_t&              typedValue,
        bool                        isListValue,
        bool                        isId = false,
        bool                        isIdRef = false,
        bool                        hidden = false,
        IXMLDOMAttribute    * dom_attribute = NULL);

  virtual ~AttributeNode();

  XmlNode* copy2(
        XmlNode*               rootParent,
        XmlNode*               parent,
        long                   pos,
        const store::CopyMode& copymode) const;

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return store::StoreConsts::attributeNode;
  }

  store::Item* getType() const     { return theTypeName.getp(); }

  store::Item* getNodeName() const;

  bool isId() const           { return (theFlags & IsId) != 0; }
  void setIsId()              { theFlags |= IsId; }
  void resetIsId()            { theFlags &= ~IsId; }

  bool isIdRefs() const       { return (theFlags & IsIdRefs) != 0; }
  void setIsIdRefs()          { theFlags |= IsIdRefs; }
  void resetIsIdRefs()        { theFlags &= ~IsIdRefs; }

  bool haveListValue() const  { return (theFlags & HaveListValue) != 0; }
  void resetHaveListValue()   { theFlags &= ~HaveListValue; }
  void setHaveListValue()     { theFlags |= HaveListValue; }

  bool isHidden() const       { return (theFlags & IsHidden) != 0; }
  void setHidden()            { theFlags |= IsHidden; }

  bool isBaseUri() const      { return (theFlags & IsBaseUri) != 0; }

  void setTypedValue(store::Item_t& val);
  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  xqpStringStore_t getStringValue() const;
  store::Item_t getAtomizationValue() const;

  xqp_string show() const;

  void replaceValue(UpdReplaceAttrValue& upd);
  void restoreValue(UpdReplaceAttrValue& upd);

  void replaceName(UpdRenameAttr& upd);
  void restoreName(UpdRenameAttr& upd);
  virtual IXMLDOMNode   *GetDOMNode()   { return theDOMAttribute; }
  virtual IXMLDOMAttribute   *GetDOMAttribute() {return theDOMAttribute; }

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
  friend class DocumentDagNode;
  friend class ElementNode;
  friend class BasicItemFactory;
  friend class UpdSetElementType;
  

public:

protected:
  TextNodeContent theContent;
  bool  is_cdata;

public:
  TextNode(
        XmlTree*          tree,
        XmlNode*          parent,
        long              pos,
        xqpStringStore_t& content,
        bool              is_cdata,
        IXMLDOMText       *dom_text = NULL);

  TextNode(
        XmlNode*          parent,
        store::Item_t&    content,
        bool              isListValue,
        IXMLDOMText       *dom_text = NULL);

  virtual ~TextNode();

  XmlNode* copy2(
        XmlNode*               rootParent,
        XmlNode*               parent,
        long                   pos,
        const store::CopyMode& copymode) const;

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return store::StoreConsts::textNode;
  }

  store::Item* getType() const;

  bool isTyped() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const;
			
  xqp_string show() const;

  void replaceValue(UpdReplaceTextValue& upd);
  void restoreValue(UpdReplaceTextValue& upd);

  virtual IXMLDOMNode   *GetDOMNode()   { return theContent.theDOMText; }
protected:
  xqpStringStore* getText() const      { return theContent.getText(); }

  void setText(xqpStringStore_t& text) { theContent.setText(text, !getTree()->during_import_DOM); }
  void setText(xqpStringStore* text)   { theContent.setText(text, !getTree()->during_import_DOM); }

  store::Item* getValue() const        { return theContent.getValue(); }

  void setValue(store::Item_t& val)    { theContent.setValue(val, !getTree()->during_import_DOM); }
  void setValue(store::Item* val)      { theContent.setValue(val, !getTree()->during_import_DOM); }
};


/*******************************************************************************

********************************************************************************/
class PiNode : public XmlNode
{
  friend class XmlNode;
  

 protected:
  IXMLDOMProcessingInstruction    *theDOMpi;
#ifdef ZORBA_MSDOM_IN_NATIVE_STORE_CACHING
  xqpStringStore_t theTarget;
  xqpStringStore_t theContent;
#else
  xqpStringStore_t  temp_xqpTarget;
  xqpStringStore_t  temp_xqpString;
#endif

public:
  PiNode(
        XmlTree*          tree,
        XmlNode*          parent,
        long              pos,
        xqpStringStore_t& target,
        xqpStringStore_t& content,
        IXMLDOMProcessingInstruction    *theDOMpi = NULL);

  virtual ~PiNode();

  XmlNode* copy2(
        XmlNode*               rootParent,
        XmlNode*               parent,
        long                   pos,
        const store::CopyMode& copymode) const;

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return store::StoreConsts::piNode;
  }

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const;
  xqpStringStore* getStringValueP() const    { return theContent.getp();}

  xqpStringStore* getTarget() const          { return theTarget.getp(); }

  xqp_string show() const;

  void replaceValue(UpdReplacePiValue& upd);
  void restoreValue(UpdReplacePiValue& upd);

  void replaceName(UpdRenamePi& upd);
  void restoreName(UpdRenamePi& upd);

  virtual IXMLDOMNode   *GetDOMNode()   { return theDOMpi; }
};


/*******************************************************************************

********************************************************************************/
class CommentNode : public XmlNode
{
  friend class XmlNode;
  

protected:
  IXMLDOMComment    *theDOMComment;
#ifdef ZORBA_MSDOM_IN_NATIVE_STORE_CACHING
  xqpStringStore_t theContent;
#else
  xqpStringStore_t  temp_xqpString;
#endif

public:
  CommentNode(
        XmlTree*          tree,
        XmlNode*          parent,
        long              pos,
        xqpStringStore_t& content,
        IXMLDOMComment    *theDOMComment = NULL);

  virtual ~CommentNode();

  XmlNode* copy2(
        XmlNode*               rootParent,
        XmlNode*               parent,
        long                   pos,
        const store::CopyMode& copymode) const;

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return store::StoreConsts::commentNode;
  }

  store::Item* getType() const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;
  store::Item_t getAtomizationValue() const;
  xqpStringStore_t getStringValue() const;
  xqpStringStore* getStringValueP() const;

  xqp_string show() const;

  void replaceValue(UpdReplaceCommentValue& upd);
  void restoreValue(UpdReplaceCommentValue& upd);

  virtual IXMLDOMNode   *GetDOMNode()   { return theDOMComment; }
};


} // namespace store
} // namespace zorba

#endif

