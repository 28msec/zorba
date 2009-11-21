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
#ifndef ZORBA_SIMPLE_STORE_PUL_PRIMITIVES
#define ZORBA_SIMPLE_STORE_PUL_PRIMITIVES

#include "store/api/index.h"

#include "store/naive/shared_types.h"

#include "store/naive/node_items.h"


namespace zorba { namespace simplestore {


class PULImpl;


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

  void addNodeForValidation(zorba::store::Item* node);

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

********************************************************************************/
class UpdPut : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::Item_t theTargetUri;

  store::Item_t theOldDocument;

public:
  UpdPut(PULImpl* pul, store::Item_t& target, store::Item_t& uri)
    :
    UpdatePrimitive(pul, target)
  {
    theTargetUri.transfer(uri);
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_PUT;
  }

  void apply();
  void undo();
};


/*******************************************************************************
  base class for other collection functions
********************************************************************************/ 
class UpdCollection : public UpdatePrimitive
{
protected:
  store::Item_t               theCollectionName;
  std::vector<store::Item_t>  theNodes;

public:
  UpdCollection(
        PULImpl* pul,
        store::Item_t& name)
    :
    UpdatePrimitive(pul),
    theCollectionName(name)
  {
  }

  UpdCollection(
        PULImpl* pul,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes)
    :
    UpdatePrimitive(pul),
    theCollectionName(name),
    theNodes(nodes)
  {
  }

  UpdCollection(
        PULImpl* pul,
        store::Item_t& target,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes)
    :
    UpdatePrimitive(pul, target),
    theCollectionName(name),
    theNodes(nodes)
  {
  }

  const store::Item* getName() const { return theCollectionName.getp(); }

  ulong numNodes() const { return theNodes.size(); }

  store::Item* getNode(ulong i) const { return theNodes[i].getp(); }
};


class UpdCreateCollection : public UpdCollection
{
public:
  UpdCreateCollection(
        PULImpl* pul,
        store::Item_t& name)
    :
    UpdCollection(pul, name)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  {
    return store::UpdateConsts::UP_CREATE_COLLECTION;
  }

  void apply();
  void undo();
};


class UpdDropCollection : public UpdCollection
{
protected:
  std::vector<store::Item_t> theSavedItems; // only used for undo

public:
  UpdDropCollection(
        PULImpl* pul,
        store::Item_t& name)
    :
    UpdCollection(pul, name)
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
public:
  UpdInsertIntoCollection(
        PULImpl* pul,
        store::Item_t& name, 
        store::Item_t& node)
      :
      UpdCollection(pul, name)
  {
    theNodes.resize(1);
    theNodes[0].transfer(node);
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
public:
  UpdInsertFirstIntoCollection(
      PULImpl* pul,
      store::Item_t& name,
      std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, name, nodes)
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
public:
  UpdInsertLastIntoCollection(
        PULImpl* pul,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, name, nodes)
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
public:
  UpdInsertBeforeIntoCollection(
        PULImpl* pul,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, target, name, nodes)
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
public:
  UpdInsertAfterIntoCollection(
        PULImpl* pul,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, target, name, nodes)
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
  ulong  thePos;

public:
  UpdInsertAtIntoCollection(
        PULImpl* pul,
        store::Item_t& name,
        ulong pos,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, name, nodes),
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
public:
  UpdRemoveNodesFromCollection(
        PULImpl* pul,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes)
    :
    UpdCollection(pul, name, nodes)
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
  ulong         thePos;
  store::Item_t theNode; // used for undo only

public:
  UpdRemoveNodeAtFromCollection(
      PULImpl* pul,
      store::Item_t& name,
      ulong pos)
    :
    UpdCollection(pul, name),
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
        store::Iterator* sourceIter);

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
  UpdDropIndex(PULImpl* pul, const store::Item_t& qname)
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


class UpdRebuildIndex : public  UpdatePrimitive
{
  friend class PULImpl;

protected:
  const store::Item_t  theQName;
  store::Iterator_t    theSourceIter;

  store::Index_t       theIndex;

public:
  UpdRebuildIndex(
        PULImpl* pul,
        const store::Item_t& qname,
        store::Iterator* sourceIter)
    :
    UpdatePrimitive(pul),
    theQName(qname),
    theSourceIter(sourceIter)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() const
  { 
    return store::UpdateConsts::UP_REBUILD_INDEX;
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
