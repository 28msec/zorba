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

#include "store/naive/shared_types.h"
#include "store/naive/text_node_content.h"
#include "store/naive/item_vector.h"
#include "store/naive/ordpath.h"
#include "store/naive/node_vector.h"
#include "store/naive/store_config.h"
#include "store/naive/nsbindings.h" // TODO remove by introducing explicit destructors

#ifndef ZORBA_NO_FULL_TEXT
#include "store/naive/naive_ft_token_iterator.h"
#include "zorbautils/locale.h"
#endif /* ZORBA_NO_FULL_TEXT */

#ifdef ZORBA_STORE_MSDOM
#include "msdom_addon/msdom_node_items.h"
#else

#include "store/api/item.h"

#include "zorbaerrors/Assert.h"
#include "zorbautils/fatal.h"
#include "zorbautils/tokenizer.h"


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

class SimpleCollection;

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

  theRefCount    : It is the sum of theRefCounts of all the nodes belonging to
                   this tree. Individual nodes are not destroyed when their
                   refCount goes to 0. Instead, nodes belonging to a tree are all
                   destroyed together when theRefCount of the tree goes to 0
                   (i.e. when there are no refs to any of the nodes in the tree).
  theRCLock      : Protects theRefCount

  theId          : An internally generated id for the tree. The id uniquely
                   identifies the tree within its containing collection (see
                   SimpleCollection::createTreeId() method). Trees that do not
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

protected:
  mutable long              theRefCount;
  SYNC_CODE(mutable RCLock  theRCLock;)

  ulong                     theId;
  ulong                     thePos;

  xqpStringStore_t          theDocUri;
  xqpStringStore_t          theBaseUri;

  SimpleCollection        * theCollection;

  XmlNode                 * theRootNode;

  GuideNode               * theDataGuideRootNode;

  bool                      theIsValidated;
  bool                      theIsRecursive;

  // make sure that only created by the factory
  friend class NodeFactory;
  XmlTree(XmlNode* root, ulong id);

#ifndef ZORBA_NO_FULL_TEXT
public:
  typedef NaiveFTTokenIterator::FTTokens FTTokens;
  typedef FTTokens::size_type FTTokenIndex_t;

protected:
  FTTokens                  theTokens;

  FTTokens& getTokens() { return theTokens; }
#endif /* ZORBA_NO_FULL_TEXT */

public:
  XmlTree();

  ~XmlTree() { theRootNode = 0; }

  void free() throw();

  long getRefCount() const { return theRefCount; }
  long& getRefCount()      { return theRefCount; }
  void addReference()      { ++theRefCount; }
  void removeReference()   { --theRefCount; }

  SYNC_CODE(RCLock& getRCLock() const { return theRCLock; })

  void setId(ulong id) { theId = id; }

  ulong getId() const { return theId; }

  xqpStringStore* getDocUri() const { return theDocUri.getp(); }

  void setDocUri(const xqpStringStore_t& uri) { theDocUri = uri; }

  xqpStringStore* getBaseUri() const { return theBaseUri.getp(); }

  void setBaseUri(const xqpStringStore_t& uri) { theBaseUri = uri; }

  ulong getCollectionId() const;

  const SimpleCollection* getCollection() const { return theCollection; }

  void setCollection(SimpleCollection* coll, ulong pos);

  void setPosition(ulong pos) { thePos = pos; }

  ulong getPosition() const { return thePos; }

  XmlNode* getRoot() const { return theRootNode; }

  void setRoot(XmlNode* root) { theRootNode = root; }

  bool isValidated() const { return theIsValidated; }

  void markValidated() { theIsValidated = true; }

  void setRecursive() { theIsRecursive = true; }

  bool isRecursive() const { return theIsRecursive; }

  GuideNode* getDataGuide() const { return theDataGuideRootNode; }

  void setDataGuide(GuideNode* root) { theDataGuideRootNode = root; }
};


#ifndef ZORBA_NO_FULL_TEXT
/**
 * An <code>XmlNodeTokenizer</code> is-a Tokenizer::Callback TODO
 */
class XmlNodeTokenizer : public Tokenizer::Callback {
public:
  typedef XmlTree::FTTokens FTTokens;

  XmlNodeTokenizer( Tokenizer &tokenizer, FTTokens &tokens,
                    locale::iso639_1::type lang ) :
    tokenizer_( tokenizer ),
    tokens_( tokens )
  {
    push_lang( lang );
  }

  void operator()( char const *utf8_s, int utf8_len,
                   int pos, int sent, int para, void* );

  void beginTokenization( XmlNode& );
  void endTokenization( XmlNode& );

  void inc_para() {
    tokenizer_.inc_para();
  }

  void push_element( ElementNode *element ) {
    element_stack_.push( element );
  }

  void pop_element() {
    element_stack_.pop();
  }

  void push_lang( locale::iso639_1::type lang ) {
    lang_stack_.push( lang );
  }

  void pop_lang() {
    lang_stack_.pop();
  }

  void tokenize( char const *utf8_s, int len );

private:
  typedef std::stack<locale::iso639_1::type> lang_stack_t;
  typedef std::stack<ElementNode*> element_stack_t;

  ElementNode* get_element() const {
    return element_stack_.top();
  }

  locale::iso639_1::type get_lang() const {
    return lang_stack_.top();
  }

  Tokenizer &tokenizer_;
  FTTokens &tokens_;
  element_stack_t element_stack_;
  lang_stack_t lang_stack_;
};
#endif /* ZORBA_NO_FULL_TEXT */

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
    NodeKindMask      =   0x7,
    IsId              =   0x8,
    IsIdRefs          =   0x10,
    HaveTypedValue    =   0x20,    // for element nodes only
    HaveEmptyValue    =   0x40,    // for element nodes only
    IsTyped           =   0x80,    // for text nodes only
    HaveListValue     =   0x100,   // for text and attribute nodes only

    HaveLocalBindings =   0x200,   // for element nodes only
    HaveBaseUri       =   0x400,   // for element nodes only
    IsBaseUri         =   0x800,   // for attribute nodes only
    IsHidden          =   0x1000,  // for attribute nodes only
    IsInSubstGroup    =   0x2000,  // for element nodes only

    IsRecursive       =   0x4000   // for element nodes only
  };

protected:
  OrdPath           theOrdPath;
  InternalNode    * theParent;
  uint32_t          theFlags;

  XmlNode(store::StoreConsts::NodeKind nodeKind)
    :
    Item(),
    theParent(NULL)
  {
    theFlags = (uint32_t)nodeKind;
#ifndef ZORBA_NO_FULL_TEXT
    initTokens();
#endif /* ZORBA_NO_FULL_TEXT */
  }

  XmlNode(
        XmlTree*                     tree,
        InternalNode*                parent,
        long                         pos,
        store::StoreConsts::NodeKind nodeKind);

  XmlNode()
    :
    theParent(0)
  {
#ifndef ZORBA_NO_FULL_TEXT
    initTokens();
#endif /* ZORBA_NO_FULL_TEXT */
  }

#ifndef ZORBA_NO_FULL_TEXT
  mutable XmlTree::FTTokenIndex_t theBeginTokenIndex;
  mutable XmlTree::FTTokenIndex_t theEndTokenIndex;

  friend class XmlNodeTokenizer;

  void initTokens() 
  {
    theBeginTokenIndex = theEndTokenIndex = 0;
  }

  bool hasTokens() const 
  {
    return theBeginTokenIndex != theEndTokenIndex;
  }
#endif /* ZORBA_NO_FULL_TEXT */


public:
#ifndef NDEBUG
  virtual ~XmlNode();
#else
  virtual ~XmlNode() {}
#endif

  void free() { if (getTree() != NULL) getTree()->free(); }

  //
  // Item methods
  //

  bool isNode() const     { return true; }
  bool isAtomic() const   { return false; }
  bool isPul() const      { return false; }
  bool isTuple() const    { return false; }
  bool isError() const    { return false; }
  bool isFunction() const { return false; }

  store::StoreConsts::NodeKind getNodeKind() const
  {
    return (store::StoreConsts::NodeKind)(theFlags & NodeKindMask);
  }

  const store::Collection* getCollection() const 
  {
    return reinterpret_cast<const store::Collection*>(getTree()->getCollection()); 
  }

  virtual xqpStringStore* getDocumentURI() const { return 0; }

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

  inline long compare2(const XmlNode* other) const;

  store::Item_t getEBV() const;

  store::Item* copy(
        store::Item* parent,
        long pos,
        const store::CopyMode& copymode) const;

  virtual store::Item_t getNilled() const { return 0; }

  virtual bool isId() const { return false; }

  virtual bool isIdRefs() const { return false; }

  bool isValidated() const { return getTree()->isValidated(); }

  void markValidated() { getTree()->markValidated(); }

  virtual void finalizeNode() { return; }

  //
  // SimpleStore Methods
  //

  void setTree(const XmlTree* t);

  XmlTree* getTree() const { return (XmlTree*)theTreeRCPtr; }

  ulong getTreeId() const { return getTree()->getId(); }

  XmlNode* getRoot() const { return getTree()->getRoot(); }

  void setCollection(SimpleCollection* coll, ulong pos) 
  {
    getTree()->setCollection(coll, pos);
  }

  ulong getCollectionId() const { return getTree()->getCollectionId(); }

  const OrdPath& getOrdPath() const { return theOrdPath; }

  OrdPath& getOrdPath() { return theOrdPath; }

  void setId(XmlTree* tree, const OrdPathStack* op);

  void setOrdPath(
        InternalNode* parent,
        long pos,
        store::StoreConsts::NodeKind nodeKind);

  void setParent(InternalNode* p) { theParent = p; }

  GuideNode* getDataGuide() const   { return getTree()->getDataGuide(); }

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

  uint32_t getFlags() const { return theFlags; }

  void setFlags(uint32_t flags) { theFlags = flags; }

#ifndef ZORBA_NO_FULL_TEXT
  FTTokenIterator_t
  getDocumentTokens( locale::iso639_1::type = locale::iso639_1::unknown ) const;
#endif /* ZORBA_NO_FULL_TEXT */

protected:
  virtual xqpStringStore_t getBaseURIInternal(bool& local) const;

  void attach(InternalNode* parent, long pos);

  void detach() throw();

  void destroy() throw();

  long disconnect() throw();

  void connect(InternalNode* node, ulong pos) throw();

#ifndef ZORBA_NO_FULL_TEXT
  virtual void tokenize( XmlNodeTokenizer& );
#endif /* ZORBA_NO_FULL_TEXT */

private:
  void destroyInternal() throw();
};


/*******************************************************************************
  Base class for element and document nodes
********************************************************************************/
class InternalNode : public XmlNode
{
  friend class XmlNode;
  friend class UpdPut;

protected:
  NodeVector  theChildren;
  NodeVector  theAttributes;

  // make sure that only created by subclasses
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

  InternalNode() {}

public:
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

#ifndef ZORBA_NO_FULL_TEXT
  void tokenize( XmlNodeTokenizer& );
#endif /* ZORBA_NO_FULL_TEXT */
};


/*******************************************************************************

********************************************************************************/
class DocumentNode : public InternalNode
{
  friend class NodeFactory;

protected:
  DocumentNode(
        XmlTree*                tree,
        const xqpStringStore_t& baseUri,
        const xqpStringStore_t& docUri);

  DocumentNode();

public:
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

  bool isRecursive() const { return getTree()->isRecursive(); }

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

  void finalizeNode() { theChildren.compact(); }

protected:
  xqpStringStore_t getBaseURIInternal(bool& local) const;
};


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
  store::Item_t         theTypeName;
  NsBindingsContext_t   theNsContext;

protected:

  ElementNode(
        store::Item_t& nodeName,
        ulong          numBindings,
        ulong          numAttributes);

  ElementNode(
        XmlTree*                    tree,
        InternalNode*               parent,
        long                        pos,
        store::Item_t&              nodeName,
        store::Item_t&              typeName,
        bool                        haveTypedValue,
        bool                        haveEmptyValue,
        bool                        isInSubstGroup,
        const store::NsBindings*    localBindings,
        xqpStringStore_t&           baseUri);

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

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  store::Item_t getNilled() const;

  store::Iterator_t getAttributes() const;

  store::Iterator_t getChildren() const;

  void getNamespaceBindings(
        store::NsBindings& bindings,
        store::StoreConsts::NsScoping scope = store::StoreConsts::ALL_NAMESPACES) const;

  bool isInSubstitutionGroup() const { return (theFlags & IsInSubstGroup) != 0; }

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

  void setInSubstGroup()        { theFlags |= IsInSubstGroup; }
  void resetInSubstGroup()      { theFlags &= ~IsInSubstGroup; }

  bool isRecursive() const      { return (theFlags & IsRecursive) != 0; }
  void resetRecursive()         { theFlags &= ~IsRecursive; }

  void setRecursive()           
  {
    theFlags |= IsRecursive;
    getTree()->setRecursive(); 
  }

  bool haveLocalBindings() const
  {
    return (theFlags & HaveLocalBindings) != 0;
  }

  void finalizeNode()
  {
    theChildren.compact();
    theAttributes.compact();
  }

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

#ifndef ZORBA_NO_FULL_TEXT
  void tokenize( XmlNodeTokenizer& );
#endif /* ZORBA_NO_FULL_TEXT */

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
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class UpdSetAttributeType;
  friend class NodeFactory;

protected:
  store::Item_t   theName;
  store::Item_t   theTypeName;
  store::Item_t   theTypedValue;

  AttributeNode(store::Item_t&  attrName);

  AttributeNode(
        XmlTree*                    tree,
        ElementNode*                parent,
        long                        pos,
        store::Item_t&              attrName,
        store::Item_t&              typeName,
        store::Item_t&              typedValue,
        bool                        isListValue,
        bool                        hidden);

  AttributeNode() {}

public:
  //
  // Item methods
  //

  store::Item* getNodeName() const { return theName.getp(); }

  store::Item* getType() const;

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
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class UpdInsertChildren;
  friend class UpdSetElementType;
  friend class NodeFactory;

protected:
  TextNodeContent theContent;

protected:
  TextNode(xqpStringStore_t& content);

  TextNode(
        XmlTree*          tree,
        InternalNode*     parent,
        long              pos,
        xqpStringStore_t& content);

  TextNode(
        InternalNode*     parent,
        store::Item_t&    content,
        bool              isListValue);

  TextNode() {}

public:
  ~TextNode()
  {
    if (isTyped())
    {
      theContent.setValue(NULL);
    }
    else
    {
      theContent.setText(NULL);
    }
  }

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

#ifndef ZORBA_NO_FULL_TEXT
  void tokenize( XmlNodeTokenizer& );
#endif /* ZORBA_NO_FULL_TEXT */
};


/*******************************************************************************

********************************************************************************/
class PiNode : public XmlNode
{
  friend class XmlNode;
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class NodeFactory;

protected:
  xqpStringStore_t theTarget;
  xqpStringStore_t theContent;

  store::Item_t    theName;

protected:
  PiNode(xqpStringStore_t& target, xqpStringStore_t& content);

  PiNode(
        XmlTree*          tree,
        InternalNode*     parent,
        long              pos,
        xqpStringStore_t& target,
        xqpStringStore_t& content);

  PiNode() {}

public:
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

  store::Item* getNodeName() const           { return theName.getp(); }
  xqpStringStore* getTarget() const          { return theTarget.getp(); }

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
  friend class FastXmlLoader;
  friend class DtdXmlLoader;
  friend class NodeFactory;

protected:
  xqpStringStore_t theContent;

protected:
  CommentNode(xqpStringStore_t& content);

  CommentNode(
        XmlTree*          tree,
        InternalNode*     parent,
        long              pos,
        xqpStringStore_t& content);

  CommentNode() {}

public:
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

      if (tree1 == tree2 && this->getOrdPath() < other->getOrdPath())
        return -1;
    }
    else
    {
      ulong pos1 = this->getTree()->getPosition();
      ulong pos2 = other->getTree()->getPosition();

      if (pos1 < pos2)
        return -1;

      if (pos1 == pos2 && this->getOrdPath() < other->getOrdPath())
        return -1;
    }
  }

  return 1;
}

} // namespace store
} // namespace zorba

#endif//#ifdef ZORBA_STORE_MSDOM

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
