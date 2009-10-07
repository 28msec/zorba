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
#ifndef ZORBA_SIMPLE_STORE_PUL
#define ZORBA_SIMPLE_STORE_PUL

#include <vector>

#include "zorbautils/hashfun.h"
#include "zorbautils/hashmap.h"

#include "store/api/pul.h"
#include "store/api/copymode.h"
#include "store/naive/node_vector.h"


namespace zorba { namespace simplestore {

class XmlNode;
class UpdatePrimitive;


typedef std::vector<UpdatePrimitive*> NodeUpdates;


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
  uint32_t            theFlags;
  uint32_t            theChildFlags;

  NodeTypeInfo() : theFlags(0), theChildFlags(0) { }

  NodeTypeInfo(const NodeTypeInfo& other);

  ~NodeTypeInfo();

  void transfer(NodeTypeInfo& other);

  NodeTypeInfo& operator=(const NodeTypeInfo&);
};


/*******************************************************************************

********************************************************************************/
typedef std::vector<NodeTypeInfo> TypeUndoList;


/*******************************************************************************
  A map that maps each target node N to the update primitives having N as their
  target. This map is a data member of each PUL. 

  It is used to check that, for certain kinds of updates, there are no duplicate
  updates of that kind on the same target node. In particular, there can be no
  duplicate delete, rename, replaveValue, replaceContent, or replaceNode updates.
********************************************************************************/
class NodeToUpdatesMap
{
public:

  class CompareFunction
  {
  public:
    static bool equal(const XmlNode* n1, const XmlNode* n2)
    {
      return n1 == n2;
    }

    static uint32_t hash(const XmlNode* n)
    {
      return hashfun::h32((void*)(&n), sizeof(void*), FNV_32_INIT);
    }
  };

  typedef HashMap<XmlNode*, NodeUpdates*, CompareFunction>::iterator iterator;

private:

  HashMap<XmlNode*, NodeUpdates*, CompareFunction> theMap;

public:
 NodeToUpdatesMap() : theMap(8, false)
  {
  }

  ~NodeToUpdatesMap();

  iterator begin() const { return theMap.begin(); }
  iterator end() const { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  bool get(XmlNode* key, NodeUpdates*& value) { return theMap.get(key, value); }

  bool insert(XmlNode* key, NodeUpdates* value) { return theMap.insert(key, value); }

  bool remove(XmlNode* key) { return theMap.remove(key); }

  void clear() { theMap.clear(); }
};


/*******************************************************************************
  theDoFirstList : insertInto, insertAttributes, replaceValue, rename
  theInsertList  : insertBefore, insertAfter, insertIntoFirst, insertIntoLast 
********************************************************************************/
class PULImpl : public store::PUL
{
  friend class UpdatePrimitive;
  friend class ElementNode;
  friend class AttributeNode;

protected:
  std::vector<UpdatePrimitive*>      theDoFirstList;
  std::vector<UpdatePrimitive*>      theInsertList;
  std::vector<UpdatePrimitive*>      theReplaceNodeList;
  std::vector<UpdatePrimitive*>      theReplaceContentList;
  std::vector<UpdatePrimitive*>      theDeleteList;

  std::vector<UpdatePrimitive*>      theValidationList;

  // update primitives for collection functions
  std::vector<UpdatePrimitive*>      theCreateCollectionList;
  std::vector<UpdatePrimitive*>      theInsertIntoCollectionList;
  std::vector<UpdatePrimitive*>      theDeleteFromCollectionList;
  std::vector<UpdatePrimitive*>      theDeleteCollectionList;

  // index primitives
  std::vector<UpdatePrimitive*>      theCreateIndexList;
  std::vector<UpdatePrimitive*>      theDropIndexList;

  NodeToUpdatesMap                   theNodeToUpdatesMap;

  std::set<zorba::store::Item*>    * theValidationNodes;

  std::vector<UpdatePrimitive*>      thePrimitivesToRecheck;

public:
  PULImpl() : theValidationNodes(NULL) {}

  ~PULImpl();

  void addDelete(store::Item_t& n);

  void addInsertInto(
        store::Item_t&              target,
        std::vector<store::Item_t>& children,
        const store::CopyMode&      copymode);

  void addInsertFirst(
        store::Item_t&              target,
        std::vector<store::Item_t>& children,
        const store::CopyMode&      copymode);

  void addInsertLast(
        store::Item_t&              target,
        std::vector<store::Item_t>& children,
        const store::CopyMode&      copymode);

  void addInsertBefore(
        store::Item_t&              target,
        std::vector<store::Item_t>& siblings,
        const store::CopyMode&      copymode);

  void addInsertAfter(
        store::Item_t&              target,
        std::vector<store::Item_t>& siblings,
        const store::CopyMode&      copymode);
  
  void addInsertAttributes(
        store::Item_t&              target,
        std::vector<store::Item_t>& attrs,
        const store::CopyMode&      copymode);

  void addReplaceNode(
        store::Item_t&              target,
        std::vector<store::Item_t>& replacementNodes,
        const store::CopyMode&      copymode);

  void addReplaceContent(
        store::Item_t&              target,
        store::Item_t&              newTextChild,
        const store::CopyMode&      copymode);

  void addReplaceValue(
        store::Item_t&              target,
        xqpStringStore_t&           newValue);

  void addRename(
        store::Item_t&              target,
        store::Item_t&              newName);

  void addSetElementType(
        store::Item_t&               target,
        store::Item_t&               typeName,
        store::Item_t&               value,
        bool                         haveValue,
        bool                         haveEmptyValue,
        bool                         haveTypedValue,
        bool                         isInSubstitutionGroup);

  void addSetElementType(
        store::Item_t&               target,
        store::Item_t&               typeName,
        std::vector<store::Item_t>&  value,
        bool                         haveValue,
        bool                         haveEmptyValue,
        bool                         haveTypedValue,
        bool                         isInSubstitutionGroup);

  void addSetAttributeType(
        store::Item_t&               target,
        store::Item_t&               typeName,
        store::Item_t&               typedValue);

  void addSetAttributeType(
        store::Item_t&              target,
        store::Item_t&              typeName,
        std::vector<store::Item_t>& typedValue);

  // collection functions
  void addCreateCollection(
        static_context*      aStaticContext,
        xqpStringStore_t&    resolvedURI);

  void addDeleteCollection(
        static_context*      aStaticContext,
        store::Item_t&              resolvedURI);

  void addInsertIntoCollection(
        static_context*             aStaticContext,
        store::Item_t&              resolvedURI,
        store::Item_t&              node);

  void addInsertFirstIntoCollection(
        static_context*             aStaticContext,
        store::Item_t&              resolvedURI,
        std::vector<store::Item_t>& nodes);

  void addInsertLastIntoCollection(
        static_context*             aStaticContext,
        store::Item_t&              resolvedURI,
        std::vector<store::Item_t>& nodes);

  void addInsertBeforeIntoCollection(
        static_context*             aStaticContext,
        store::Item_t&              resolvedURI,
        store::Item_t&              target,
        std::vector<store::Item_t>& nodes);

  void addInsertAfterIntoCollection(
        static_context*             aStaticContext,
        store::Item_t&              resolvedURI,
        store::Item_t&              target,
        std::vector<store::Item_t>& nodes);

  void addInsertAtIntoCollection(
        static_context*             aStaticContext,
        store::Item_t&              resolvedURI,
        ulong                       pos,
        std::vector<store::Item_t>& nodes);

  void addRemoveFromCollection(
        static_context*             aStaticContext,
        store::Item_t&              resolvedURI,
        std::vector<store::Item_t>& nodes);

  void addRemoveAtFromCollection(
        static_context*      aStaticContext,
        store::Item_t&       resolvedURI,
        ulong                pos);

  // Index primitives
  void addCreateIndex(
        const store::Item_t& qname,
        const store::IndexSpecification& spec,
        store::Iterator* sourceIter);

  void addDropIndex(
        const store::Item_t& qname);

  // apply
  void applyUpdates(std::set<zorba::store::Item*>& validationNodes);

  void mergeUpdates(store::Item* other);

  void checkTransformUpdates(const std::vector<store::Item*>& rootNodes) const;

  void getCreatedIndices(std::vector<IndexBinding>& indices) const;

  void getDropedIndices(std::vector<const store::Item*>& indices) const;

protected:
  void undoUpdates();

  void addInsertChildren(
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t&                   target,
        store::Item_t&                   sibling,
        std::vector<store::Item_t>&      children,
        const store::CopyMode&           copymode);

  void mergeUpdateList(
        std::vector<UpdatePrimitive*>& myList,
        std::vector<UpdatePrimitive*>& otherList,
        bool                           checkRename,
        bool                           checkReplaceValue,
        bool                           checkReplaceNode,
        bool                           checkReplaceContent,
        bool                           checkDelete);
};


/*******************************************************************************

********************************************************************************/
class UpdatePrimitive
{
  friend class PULImpl;
  friend class XmlNode;
  friend class InternalNode;

protected:
  PULImpl       * thePul;

  store::Item_t   theTarget;
  bool            theIsApplied;
  bool            theRemoveType;
  TypeUndoList    theTypeUndoList;

public:
 UpdatePrimitive(PULImpl* pul, store::Item_t& target)
   :
   thePul(pul),
   theIsApplied(false),
   theRemoveType(false)
  {
    theTarget.transfer(target);
  }

 UpdatePrimitive(PULImpl* pul)
   :
   thePul(pul),
   theTarget(NULL),
   theIsApplied(false),
   theRemoveType(false)
  {
  }

  virtual ~UpdatePrimitive() 
  { 
  }

  void addNodeForValidation(zorba::store::Item* node)
  {
    thePul->theValidationNodes->insert(node);
  }

  virtual store::UpdateConsts::UpdPrimKind getKind() const = 0;

  virtual void apply() = 0;
  virtual void undo() = 0;

  virtual void check() {}

  bool isApplied() const { return theIsApplied; }
};


/*******************************************************************************

********************************************************************************/
class UpdDelete : public UpdatePrimitive
{
  friend class PULImpl;
  friend class XmlNode;
  friend class InternalNode;

protected:
  InternalNode   * theParent;
  ulong            thePos;
  store::Item_t    theRightSibling;
  xqpStringStore_t theLeftContent;

public:
  UpdDelete(PULImpl* pul, store::Item_t& target)
    :
    UpdatePrimitive(pul, target)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_DELETE; 
  }

  void apply();
  void undo();
};


/*******************************************************************************
  InsertInto, InsertIntoFirst, InsertIntoLast, InsertBefore, InsertAfter

  theTarget      : Inherited from UpdatePrimitive: The parent node under which
                   the new nodes will be inserted.
  theNewChildren : The list of new nodes to insert as children of theTarget.
                   The list does not contain any consecutive text nodes (see
                   UpdInsertChildren constructor).
  theSibling     : If theKind is InsertBefore or InsertAfter, theSibling is the
                   child node of theTarget next to which the new nodes will be
                   inserted. 

  theNumApplied  : The number of new children that were actually inserted during
                   the apply() method. It is needed by the undo() method to
                   handle the case where an error occured in the middle of the
                   apply() method, before all the new children were inserted.
  theMergedNode  : If either the 1st or the last node in theNewChildren is a
                   text node that needs to be merged with an existing text child
                   N of theTarget, then N is first saved in theMergedNode, then
                   removed as a child of theTarget, and finally its text content
                   is merged with the content of the 1st or last node in  
                   theNewChildren. If the apply must be undone, the undo()
                   method will restore N in its original position.
********************************************************************************/
class UpdInsertChildren : public UpdatePrimitive
{
  friend class PULImpl;
  friend class XmlNode;
  friend class InternalNode;

protected:
  store::UpdateConsts::UpdPrimKind theKind;
  std::vector<store::Item_t>       theNewChildren;
  store::Item_t                    theSibling;
  store::CopyMode                  theCopyMode;

  long                             theNumApplied;
  store::Item_t                    theMergedNode;

public:
  UpdInsertChildren(
        PULImpl*                         pul,
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t&                   target,
        store::Item_t&                   sibling,
        std::vector<store::Item_t>&      children,
        const store::CopyMode&           copymode);

  store::UpdateConsts::UpdPrimKind getKind() const { return theKind; }

  void apply();
  void undo();
};


/*******************************************************************************

  theNewAtrs :     The list of new attrs to insert as attributes of theTarget.

  theNumApplied  : The number of new children that were actually inserted during
                   the apply() method. It is needed by the undo() method to
                   handle the case where an error occured in the middle of the
                   apply() method, before all the new children were inserted.
  theNewBindings :
********************************************************************************/
class UpdInsertAttributes : public UpdatePrimitive
{
  friend class PULImpl;
  friend class ElementNode;

protected:
  std::vector<store::Item_t>  theNewAttrs;
  store::CopyMode             theCopyMode;

  ulong                       theNumApplied;
  std::vector<store::Item*>   theNewBindings;

public:
  UpdInsertAttributes(
        PULImpl*                     pul,
        store::Item_t&               target,
        std::vector<store::Item_t>&  attrs,
        const store::CopyMode&       copymode);

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_INSERT_ATTRIBUTES;
  }

  void apply();
  void undo();
  void check();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceAttribute : public UpdatePrimitive
{
  friend class PULImpl;
  friend class ElementNode;

protected:
  store::Item_t               theAttr;
  std::vector<store::Item_t>  theNewAttrs;
  store::CopyMode             theCopyMode;

  ulong                       theNumApplied;
  std::vector<store::Item*>   theNewBindings;

public:
  UpdReplaceAttribute(
        PULImpl*                    pul,
        store::Item_t&              target,
        store::Item_t&              attr,
        std::vector<store::Item_t>& newAttrs,
        const store::CopyMode&      copymode);

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_REPLACE_ATTRIBUTE;
  }

  void apply();
  void undo();
  void check();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceChild : public UpdatePrimitive
{
  friend class PULImpl;
  friend class XmlNode;
  friend class InternalNode;

protected:
  store::Item_t               theChild;
  std::vector<store::Item_t>  theNewChildren;
  store::CopyMode             theCopyMode;

  ulong                       theNumApplied;
  store::Item_t               theLeftMergedNode;
  store::Item_t               theRightMergedNode;
  bool                        theIsTyped;

public:
  UpdReplaceChild(
        PULImpl*                    pul,
        store::Item_t&              target,
        store::Item_t&              child,
        std::vector<store::Item_t>& newChildren,
        const store::CopyMode&      copymode);

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_REPLACE_CHILD; 
  }

  void apply();
  void undo();
};


/*******************************************************************************
  Replace all the children of a target element node with a new child that is
  a text node.
********************************************************************************/
class UpdReplaceElemContent : public UpdatePrimitive
{
  friend class PULImpl;
  friend class ElementNode;

protected:
  store::Item_t     theNewChild;
  store::CopyMode   theCopyMode;

  NodeVector        theOldChildren;
  bool              theIsTyped;

public:
  UpdReplaceElemContent(
        PULImpl*               pul,
        store::Item_t&         target,
        store::Item_t&         newChild, 
        const store::CopyMode& copymode)
    :
    UpdatePrimitive(pul, target),
    theCopyMode(copymode),
    theIsTyped(false)
  {
    theNewChild.transfer(newChild);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_REPLACE_CONTENT; 
  }

  void apply();
  void undo();
};


/*******************************************************************************
  theNewBinding :  Whether the update resulted in a new ns bindings added
                   among the ns bindings of the target. If true, this new
                   binding must be removed during undo.
********************************************************************************/
class UpdRenameElem : public UpdatePrimitive
{
  friend class PULImpl;
  friend class ElementNode;

protected:
  store::Item_t   theNewName;

  store::Item_t   theOldName;
  bool            theNewBinding;
  bool            theRestoreParentType;

public:
  UpdRenameElem(PULImpl* pul, store::Item_t& target, store::Item_t& newName) 
    :
    UpdatePrimitive(pul, target),
    theNewBinding(false),
    theRestoreParentType(false)
  {
    theNewName.transfer(newName);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_RENAME_ELEM; 
  }

  void apply();
  void undo();
};


/*******************************************************************************
  theHaveValue      : True if the target element node has a typed value. The only
                      case when an element node does not have a typed value is
                      when the type of the node is complex with complex content,
                      but with no mixed content allowed.
  theHaveEmptyValue : True if the target element node has a complex type with
                      empty content.
  theHaveTypedValue : True if the target element node has a typed value whose
                      type is not untypedAtomic. Note: This can happen only if
                      the type of the target element node has simple content.
  theHaveListValue  : True if theHaveTypedValue is true, and the type of the
                      typed value is a list type. 
********************************************************************************/
class UpdSetElementType : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::Item_t            theTypeName;
  store::Item_t            theTypedValue;
  bool                     theHaveValue;
  bool                     theHaveEmptyValue;
  bool                     theHaveTypedValue;
  bool                     theHaveListValue;
  bool                     theIsInSubstitutionGroup;

public:
  UpdSetElementType(
        PULImpl*       pul,
        store::Item_t& target,
        store::Item_t& typeName,
        store::Item_t& typedValue,
        bool           haveValue,
        bool           haveEmptyValue,
        bool           haveTypedValue,
        bool           haveListValue,
        bool           isInSubstitutionGroup)
    :
    UpdatePrimitive(pul, target),
    theHaveValue(haveValue),
    theHaveEmptyValue(haveEmptyValue),
    theHaveTypedValue(haveTypedValue),
    theHaveListValue(haveListValue),
    theIsInSubstitutionGroup(isInSubstitutionGroup)
  {
    theTypeName.transfer(typeName);
    theTypedValue.transfer(typedValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_SET_ELEMENT_TYPE; 
  }

  void apply();
  void undo() {}
};


/*******************************************************************************
  A target node cannot have more than 1 UpdReplaceAttrValue primitives
********************************************************************************/
class UpdReplaceAttrValue : public UpdatePrimitive
{
  friend class PULImpl;
  friend class AttributeNode;

protected:
  xqpStringStore_t theNewValue;

  store::Item_t   theOldValue;

public:
  UpdReplaceAttrValue(PULImpl* pul, store::Item_t& target, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(pul, target)
  {
    theNewValue.transfer(newValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_REPLACE_ATTR_VALUE;
  }

  void apply();
  void undo();
};


/*******************************************************************************
  theOldValue   : Renaming an attribute also removes its type and removing the
                  type implies that the current typed value V of the attribute
                  must be replaced with a new value V' that is equal to the
                  string value of V as an instance of untyped atomic. So, we must
                  save V here so that we can perform undo.
  theNewBinding : Whether the update resulted in a new ns bindings added among
                  the ns bindings of the parent of the target. If true, this
                  new binding must be removed during undo.
********************************************************************************/
class UpdRenameAttr : public UpdatePrimitive
{
  friend class PULImpl;
  friend class AttributeNode;

protected:
  store::Item_t   theNewName;

  store::Item_t   theOldValue;
  store::Item_t   theOldName;
  bool            theNewBinding;

public:
  UpdRenameAttr(PULImpl* pul, store::Item_t& target, store::Item_t& newName)
    :
    UpdatePrimitive(pul, target),
    theNewBinding(false)
  {
    theNewName.transfer(newName);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_RENAME_ATTR; 
  }

  void apply();
  void undo();
  void check();
};


/*******************************************************************************

********************************************************************************/
class UpdSetAttributeType : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::Item_t            theTypeName;
  store::Item_t            theTypedValue;
  bool                     theHaveListValue;

public:
  UpdSetAttributeType(
        PULImpl*       pul,
        store::Item_t& target,
        store::Item_t& typeName,
        store::Item_t& typedValue,
        bool           haveListValue)
    :
    UpdatePrimitive(pul, target),
    theHaveListValue(haveListValue)
  {
    theTypeName.transfer(typeName);
    theTypedValue.transfer(typedValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_SET_ATTRIBUTE_TYPE; 
  }

  void apply();
  void undo() {}
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceTextValue : public UpdatePrimitive
{
  friend class PULImpl;
  friend class TextNode;

protected:
  xqpStringStore_t   theNewContent;

  store::Item_t      theOldNode;
  ulong              theOldPos;
  TextNodeContent    theOldContent;
  bool               theIsTyped;

public:
  UpdReplaceTextValue(PULImpl* pul, store::Item_t& target, xqpStringStore_t& newValue) 
    :
    UpdatePrimitive(pul, target),
    theIsTyped(false)
  {
    theNewContent.transfer(newValue);
  }

  ~UpdReplaceTextValue();

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_REPLACE_TEXT_VALUE;
  }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdReplacePiValue : public UpdatePrimitive
{
  friend class PULImpl;
  friend class PiNode;

protected:
  xqpStringStore_t   theNewValue;
  xqpStringStore_t   theOldValue;

public:
  UpdReplacePiValue(PULImpl* pul, store::Item_t& target, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(pul, target)
  {
    theNewValue.transfer(newValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_REPLACE_PI_VALUE;
  }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdRenamePi : public UpdatePrimitive
{
  friend class PULImpl;
  friend class PiNode;

protected:
  xqpStringStore_t   theNewName;
  xqpStringStore_t   theOldName;

public:
  UpdRenamePi(PULImpl* pul, store::Item_t& target, xqpStringStore_t& newName) 
    :
    UpdatePrimitive(pul, target)
  {
    theNewName.transfer(newName);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_RENAME_PI; 
  }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceCommentValue : public UpdatePrimitive
{
  friend class PULImpl;
  friend class CommentNode;

protected:
  xqpStringStore_t   theNewValue;
  xqpStringStore_t   theOldValue;

public:
  UpdReplaceCommentValue(PULImpl* pul, store::Item_t& target, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(pul, target)
  {
    theNewValue.transfer(newValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_REPLACE_COMMENT_VALUE;
  }

  void apply();
  void undo();
};


/*******************************************************************************
  UpdatePrimitives for collection functions
********************************************************************************/
class UpdCreateCollection : public UpdatePrimitive
{
protected:
  static_context*    theStaticContext;
  xqpStringStore_t   theCollectionUri;

public:
  UpdCreateCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        xqpStringStore_t& collectionUri)
    :
    UpdatePrimitive(pul),
    theStaticContext(aStaticContext),
    theCollectionUri(collectionUri)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_CREATE_COLLECTION;
  }

  void apply();
  void undo();
};


// base class for other collection functions
class UpdCollection : public UpdatePrimitive
{
protected:
  static_context*    theStaticContext;
  store::Item_t      theTargetCollectionUri;

public:
  UpdCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        store::Item_t& targetCollectionUri)
    :
    UpdatePrimitive(pul),
    theStaticContext(aStaticContext),
    theTargetCollectionUri(targetCollectionUri)
  {
  }

  UpdCollection(
        PULImpl* pul,
        static_context* aStaticContext, 
        store::Item_t& target,
        store::Item_t& targetCollectionUri)
    :
    UpdatePrimitive(pul, target),
    theStaticContext(aStaticContext),
    theTargetCollectionUri(targetCollectionUri)
  {
  }
};


class UpdDeleteCollection : public UpdCollection
{
protected:
  std::vector<store::Item_t> theSavedItems; // only used for undo

public:
  UpdDeleteCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        store::Item_t& targetCollectionUri)
    :
    UpdCollection(pul, aStaticContext, targetCollectionUri)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_DELETE_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdInsertIntoCollection : public UpdCollection
{
protected:
  store::Item_t  theNode;

public:
  UpdInsertIntoCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        store::Item_t& targetCollectionUri, 
        store::Item_t& node)
      :
      UpdCollection(pul, aStaticContext, targetCollectionUri),
      theNode(node)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_INSERT_INTO_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdInsertFirstIntoCollection : public  UpdCollection
{
protected:
  std::vector<store::Item_t>  theNodes;

public:
  UpdInsertFirstIntoCollection(
      PULImpl* pul,
      static_context* aStaticContext,
      store::Item_t& targetCollectionUri,
      std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, aStaticContext, targetCollectionUri),
    theNodes(nodes)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_INSERT_FIRST_INTO_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdInsertLastIntoCollection : public  UpdCollection
{
protected:
  std::vector<store::Item_t>  theNodes;

public:
  UpdInsertLastIntoCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        store::Item_t& targetCollectionUri,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, aStaticContext, targetCollectionUri),
    theNodes(nodes)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_INSERT_LAST_INTO_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdInsertBeforeIntoCollection : public  UpdCollection
{
protected:
  std::vector<store::Item_t>  theNodes;

public:
  UpdInsertBeforeIntoCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        store::Item_t& targetCollectionUri,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, aStaticContext, target, targetCollectionUri),
    theNodes(nodes)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_INSERT_BEFORE_INTO_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdInsertAfterIntoCollection : public  UpdCollection
{
protected:
  std::vector<store::Item_t>  theNodes;

public:
  UpdInsertAfterIntoCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        store::Item_t& targetCollectionUri,
        store::Item_t&    target,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, aStaticContext, target, targetCollectionUri),
    theNodes(nodes)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_INSERT_AFTER_INTO_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdInsertAtIntoCollection : public  UpdCollection
{
protected:
  std::vector<store::Item_t>  theNodes;
  ulong                       thePos;

public:
  UpdInsertAtIntoCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        store::Item_t& targetCollectionUri,
        ulong                       pos,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, aStaticContext, targetCollectionUri),
    theNodes(nodes),
    thePos(pos)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_INSERT_AT_INTO_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdRemoveNodesFromCollection: public  UpdCollection
{
protected:
  std::vector<store::Item_t>  theNodesToDelete;

public:
  UpdRemoveNodesFromCollection(
        PULImpl* pul,
        static_context* aStaticContext,
        store::Item_t& targetCollectionUri,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, aStaticContext, targetCollectionUri),
    theNodesToDelete(nodes)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_REMOVE_FROM_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdRemoveNodeAtFromCollection: public  UpdCollection
{
protected:
  ulong thePos;
  store::Item_t theNode; // used for undo only

public:
  UpdRemoveNodeAtFromCollection(
      PULImpl* pul,
      static_context* aStaticContext,
      store::Item_t& targetCollectionUri,
      ulong pos)
    :
    UpdCollection(pul, aStaticContext, targetCollectionUri),
    thePos(pos)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_REMOVE_AT_FROM_COLLECTION;
  }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdCreateIndex : public  UpdatePrimitive
{
  friend class PULImpl;

protected:
  const store::Item_t               theQName;
  const store::IndexSpecification   theSpec;
  store::Iterator_t                 theSourceIter;

  store::Index_t                    theIndex;

public:
  UpdCreateIndex(
        PULImpl* pul,
        const store::Item_t& qname,
        const store::IndexSpecification& spec,
        store::Iterator* sourceIter)
    :
    UpdatePrimitive(pul),
    theQName(qname),
    theSpec(spec),
    theSourceIter(sourceIter)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_CREATE_INDEX;
  }

  void apply();
  void undo();
};


class UpdDropIndex : public  UpdatePrimitive
{
  friend class PULImpl;

protected:
  const store::Item_t  theQName;

  store::Index_t       theIndex;

public:
  UpdDropIndex(
        PULImpl* pul,
        const store::Item_t& qname)
    :
    UpdatePrimitive(pul),
    theQName(qname)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_DROP_INDEX;
  }

  void apply();
  void undo();
};



}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
