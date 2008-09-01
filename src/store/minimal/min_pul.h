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
#ifndef ZORBA_MINIMAL_STORE_PUL
#define ZORBA_MINIMAL_STORE_PUL

#include <vector>

#include "zorbautils/hashfun.h"
#include "zorbautils/hashmap.h"
#include "store/api/pul.h"
#include "store/api/copymode.h"
#include "store/minimal/min_node_vector.h"


namespace zorba {  namespace storeminimal {

class XmlNode;
class UpdatePrimitive;


typedef std::vector<UpdatePrimitive*> NodeUpdates;



/*******************************************************************************
  A map that maps each target node N to the update primitives having N as their
  target. This map is a data member of each PUL. 

  It is used to check that, for certain kinds of updates, there are no duplicate
  updates of that kind on the same target node. In particular, there can be no
  duplicate delete, rename, replaveValue, replaceContent, or replaceNode updates.
********************************************************************************/
class NodeToUpdatesMap : public HashMap<XmlNode*,
                                        NodeUpdates*,
                                        NodeToUpdatesMap>
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


 NodeToUpdatesMap() 
   :
   HashMap<XmlNode*, NodeUpdates*, NodeToUpdatesMap>(8, false)
  {
  }

  ~NodeToUpdatesMap();
};


/*******************************************************************************
  theDoFirstList : insertInto, insertAttributes, replaceValue, rename
  theInsertList  : insertBefore, insertAfter, insertIntoFirst, insertIntoLast 
********************************************************************************/
class PULImpl : public store::PUL
{
  friend class UpdatePrimitive;

protected:
  std::vector<UpdatePrimitive*>      theDoFirstList;
  std::vector<UpdatePrimitive*>      theInsertList;
  std::vector<UpdatePrimitive*>      theReplaceNodeList;
  std::vector<UpdatePrimitive*>      theReplaceContentList;
  std::vector<UpdatePrimitive*>      theDeleteList;

  std::vector<UpdatePrimitive*>      theValidationList;

  NodeToUpdatesMap                   theNodeToUpdatesMap;

  std::set<zorba::store::Item*>    * theValidationNodes;

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
        store::Item_t&               typedValue,
        bool                         haveValue,
        bool                         haveEmptyValue,
        bool                         haveTypedValue,
        bool                         isId,
        bool                         isIdRefs);

  void addSetElementType(
        store::Item_t&               target,
        store::Item_t&               typeName,
        std::vector<store::Item_t>&  typedValue,
        bool                         haveValue,
        bool                         haveEmptyValue,
        bool                         haveTypedValue,
        bool                         isId,
        bool                         isIdRefs);

  void addSetAttributeType(
        store::Item_t&               target,
        store::Item_t&               typeName,
        store::Item_t&               typedValue,
        bool                         isId,
        bool                         isIdRefs);

  void addSetAttributeType(
        store::Item_t&              target,
        store::Item_t&              typeName,
        std::vector<store::Item_t>& typedValue,
        bool                        isId,
        bool                        isIdRefs);

  void applyUpdates(std::set<zorba::store::Item*>& validationNodes);

  //void serializeUpdates(serializer& ser, std::ostream& os);

  void mergeUpdates(store::Item* other);

  void checkTransformUpdates(const std::vector<store::Item*>& rootNodes) const;

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

  virtual ~UpdatePrimitive() { }

  void addNodeForValidation(zorba::store::Item* node)
  {
    thePul->theValidationNodes->insert(node);
  }

  virtual store::UpdateConsts::UpdPrimKind getKind() = 0;

  virtual void apply() = 0;
  virtual void undo() = 0;
};


/*******************************************************************************

********************************************************************************/
class UpdDelete : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  XmlNode     * theParent;
  ulong         thePos;

public:
  UpdDelete(PULImpl* pul, store::Item_t& target)
    :
    UpdatePrimitive(pul, target)
  {
  }

  store::UpdateConsts::UpdPrimKind getKind() 
  {
    return store::UpdateConsts::UP_DELETE; 
  }

  void apply();
  void undo();
};


/*******************************************************************************
  InsertInto, InsertIntoFirst, InsertIntoLast, InsertBefore, InsertAfter
********************************************************************************/
class UpdInsertChildren : public UpdatePrimitive
{
  friend class PULImpl;
  friend class XmlNode;

protected:
  store::UpdateConsts::UpdPrimKind theKind;
  std::vector<store::Item_t>       theNewChildren;
  store::Item_t                    theSibling;
  store::CopyMode                  theCopyMode;

  ulong                            theNumApplied;

public:
  UpdInsertChildren(
        PULImpl*                         pul,
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t&                   target,
        store::Item_t&                   sibling,
        std::vector<store::Item_t>&      children,
        const store::CopyMode&           copymode);

  store::UpdateConsts::UpdPrimKind getKind() { return theKind; }

  void apply();
  void undo();
};


/*******************************************************************************

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

  store::UpdateConsts::UpdPrimKind getKind() 
  {
    return store::UpdateConsts::UP_INSERT_ATTRIBUTES;
  }

  void apply();
  void undo();
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
        PULImpl*                     pul,
        store::Item_t&              target,
        store::Item_t&              attr,
        std::vector<store::Item_t>& newAttrs,
        const store::CopyMode&      copymode);

  store::UpdateConsts::UpdPrimKind getKind() 
  {
    return store::UpdateConsts::UP_REPLACE_ATTRIBUTE;
  }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceChild : public UpdatePrimitive
{
  friend class PULImpl;
  friend class XmlNode;

protected:
  store::Item_t               theChild;
  std::vector<store::Item_t>  theNewChildren;
  store::CopyMode             theCopyMode;

  ulong                       theNumApplied;
  bool                        theIsTyped;

public:
  UpdReplaceChild(
        PULImpl*                    pul,
        store::Item_t&              target,
        store::Item_t&              child,
        std::vector<store::Item_t>& newChildren,
        const store::CopyMode&      copymode);

  store::UpdateConsts::UpdPrimKind getKind() 
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

  ConstrNodeVector  theOldChildren;
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

  store::UpdateConsts::UpdPrimKind getKind() 
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
  UpdRenameElem(PULImpl* pul, store::Item_t& t, store::Item_t& newName) 
    :
    UpdatePrimitive(pul, t),
    theNewBinding(false),
    theRestoreParentType(false)
  {
    theNewName.transfer(newName);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
  { 
    return store::UpdateConsts::UP_RENAME_ELEM; 
  }

  void apply();
  void undo();
};


/*******************************************************************************

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
  bool                     theIsId;
  bool                     theIsIdRefs;

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
        bool           isId,
        bool           isIdRefs)
    :
    UpdatePrimitive(pul, target),
    theHaveValue(haveValue),
    theHaveEmptyValue(haveEmptyValue),
    theHaveTypedValue(haveTypedValue),
    theHaveListValue(haveListValue),
    theIsId(isId),
    theIsIdRefs(isIdRefs)
  {
    theTypeName.transfer(typeName);
    theTypedValue.transfer(typedValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
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
  UpdReplaceAttrValue(PULImpl* pul, store::Item_t& t, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(pul, t)
  {
    theNewValue.transfer(newValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
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
  UpdRenameAttr(PULImpl* pul, store::Item_t& t, store::Item_t& newName)
    :
    UpdatePrimitive(pul, t),
    theNewBinding(false)
  {
    theNewName.transfer(newName);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
  {
    return store::UpdateConsts::UP_RENAME_ATTR; 
  }

  void apply();
  void undo();
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
  bool                     theIsId;
  bool                     theIsIdRefs;

public:
  UpdSetAttributeType(
        PULImpl*       pul,
        store::Item_t& target,
        store::Item_t& typeName,
        store::Item_t& typedValue,
        bool           haveListValue,
        bool           isId,
        bool           isIdRefs)
    :
    UpdatePrimitive(pul, target),
    theHaveListValue(haveListValue),
    theIsId(isId),
    theIsIdRefs(isIdRefs)
  {
    theTypeName.transfer(typeName);
    theTypedValue.transfer(typedValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
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
  TextNodeContent    theOldContent;
  xqpStringStore_t   theNewContent;
  bool               theIsTyped;

public:
  UpdReplaceTextValue(PULImpl* pul, store::Item_t& t, xqpStringStore_t& newValue) 
    :
    UpdatePrimitive(pul, t),
    theIsTyped(false)
  {
    theNewContent.transfer(newValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
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
  UpdReplacePiValue(PULImpl* pul, store::Item_t& t, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(pul, t)
  {
    theNewValue.transfer(newValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
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
  UpdRenamePi(PULImpl* pul, store::Item_t& t, xqpStringStore_t& newName) 
    :
    UpdatePrimitive(pul, t)
  {
    theNewName.transfer(newName);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
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
  UpdReplaceCommentValue(PULImpl* pul, store::Item_t& t, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(pul, t)
  {
    theNewValue.transfer(newValue);
  }

  store::UpdateConsts::UpdPrimKind getKind() 
  {
    return store::UpdateConsts::UP_REPLACE_COMMENT_VALUE;
  }

  void apply();
  void undo();
};


}
}

#endif
