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
#include "store/naive/node_updates.h"


namespace zorba { namespace simplestore {

class XmlNode;
class UpdatePrimitive;


typedef std::vector<UpdatePrimitive*> NodeUpdates;



/*******************************************************************************

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
protected:
  std::vector<UpdatePrimitive*>   theDoFirstList;
  std::vector<UpdatePrimitive*>   theInsertList;
  std::vector<UpdatePrimitive*>   theReplaceNodeList;
  std::vector<UpdatePrimitive*>   theReplaceContentList;
  std::vector<UpdatePrimitive*>   theDeleteList;

  NodeToUpdatesMap                theNodeToUpdatesMap;

public:
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

  void applyUpdates();

  //void serializeUpdates(serializer& ser, std::ostream& os);

  void mergeUpdates(store::Item* other);

  void checkTransformUpdates(const std::vector<store::Item*>& rootNodes) const;

protected:
  void undoUpdates();

  void addInsertChildren(
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t&                   target,
        std::vector<store::Item_t>&      children,
        const store::CopyMode&           copymode);

  void addInsertSiblings(
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t&                   target,
        std::vector<store::Item_t>&      siblings,
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

protected:
  store::Item_t theTarget;
  bool          theIsApplied;
  bool          theRemoveType;
  TypeUndoList  theTypeUndoList;

public:
 UpdatePrimitive(store::Item_t& target) : theIsApplied(false), theRemoveType(false)
  {
    theTarget.transfer(target);
  }

  virtual ~UpdatePrimitive() { }

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
  UpdDelete(store::Item_t& target) : UpdatePrimitive(target) { }

  store::UpdateConsts::UpdPrimKind getKind() 
  {
    return store::UpdateConsts::UP_DELETE; 
  }

  void apply();
  void undo();
};


/*******************************************************************************
  InsertInto, InsertIntoFirst, InsertIntoLast
********************************************************************************/
class UpdInsertChildren : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::UpdateConsts::UpdPrimKind theKind;
  std::vector<store::Item_t>       theChildren;
  bool                             theDoCopy;
  store::CopyMode                  theCopyMode;

public:
  UpdInsertChildren(
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t&                   target,
        std::vector<store::Item_t>&      children,
        const store::CopyMode&           copymode);

  store::UpdateConsts::UpdPrimKind getKind() { return theKind; }

  void apply();
  void undo();
};


/*******************************************************************************
  InsertBefore, InsertAfter
********************************************************************************/
class UpdInsertSiblings : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::UpdateConsts::UpdPrimKind theKind;
  std::vector<store::Item_t>       theSiblings;
  bool                             theDoCopy;
  store::CopyMode                  theCopyMode;

public:
  UpdInsertSiblings(
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t&                   target,
        std::vector<store::Item_t>&      siblings,
        const store::CopyMode&           copymode);

  store::UpdateConsts::UpdPrimKind getKind() { return theKind; }

  void apply();
  void undo();
};


/*******************************************************************************
  InsertAttributes
********************************************************************************/
class UpdInsertAttributes : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  std::vector<store::Item_t>  theAttributes;
  bool                        theDoCopy;
  store::CopyMode             theCopyMode;

public:
  UpdInsertAttributes(
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
class UpdReplaceChild : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::Item_t               theChild;
  std::vector<store::Item_t>  theNewChildren;
  bool                        theDoCopy;
  store::CopyMode             theCopyMode;

public:
  UpdReplaceChild(
        store::Item_t&              target,
        store::Item_t&              child,
        std::vector<store::Item_t>& newChildren,
        const store::CopyMode&      copymode);

  store::UpdateConsts::UpdPrimKind getKind() { return store::UpdateConsts::UP_REPLACE_CHILD; }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceAttribute : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::Item_t               theAttr;
  std::vector<store::Item_t>  theNewAttrs;
  bool                        theDoCopy;
  store::CopyMode             theCopyMode;

public:
  UpdReplaceAttribute(
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
class UpdReplaceContent : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::Item_t     theNewChild;
  ConstrNodeVector  theOldChildren;
  bool              theDoCopy;
  store::CopyMode   theCopyMode;

public:
  UpdReplaceContent(
        store::Item_t&         target,
        store::Item_t&         newChild, 
        const store::CopyMode& copymode)
    :
    UpdatePrimitive(target),
    theDoCopy(copymode.theDoCopy),
    theCopyMode(copymode)
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

********************************************************************************/
class UpdReplaceAttrValue : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  xqpStringStore_t    theNewValue;

  store::Item_t       theOldType;
  store::Item_t       theOldValue;
  uint16_t            theOldFlags;

public:
  UpdReplaceAttrValue(store::Item_t& t, xqpStringStore_t& newValue) : UpdatePrimitive(t)
  {
    theNewValue.transfer(newValue);
    theOldValue = NULL;
    theOldFlags = 0;
  }

  ~UpdReplaceAttrValue();

  store::UpdateConsts::UpdPrimKind getKind() 
  {
    return store::UpdateConsts::UP_REPLACE_ATTR_VALUE;
  }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceTextValue : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  xqpStringStore_t   theNewValue;
  xqpStringStore_t   theOldValue;

public:
  UpdReplaceTextValue(store::Item_t& t, xqpStringStore_t& newValue) : UpdatePrimitive(t)
  {
    theNewValue.transfer(newValue);
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

protected:
  xqpStringStore_t   theNewValue;
  xqpStringStore_t   theOldValue;

public:
  UpdReplacePiValue(store::Item_t& t, xqpStringStore_t& newValue) : UpdatePrimitive(t)
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
class UpdReplaceCommentValue : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  xqpStringStore_t   theNewValue;
  xqpStringStore_t   theOldValue;

public:
  UpdReplaceCommentValue(store::Item_t& t, xqpStringStore_t& newValue) : UpdatePrimitive(t)
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


/*******************************************************************************

********************************************************************************/
class UpdRenameElem : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::Item_t   theNewName;
  store::Item_t   theOldName;

public:
  UpdRenameElem(store::Item_t& t, store::Item_t& newName) : UpdatePrimitive(t)
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
class UpdRenameAttr : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  store::Item_t   theNewName;
  store::Item_t   theOldName;

public:
  UpdRenameAttr(store::Item_t& t, store::Item_t& newName) : UpdatePrimitive(t)
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
class UpdRenamePi : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  xqpStringStore_t   theNewName;
  xqpStringStore_t   theOldName;

public:
  UpdRenamePi(store::Item_t& t, xqpStringStore_t& newName) : UpdatePrimitive(t)
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


}
}

#endif
