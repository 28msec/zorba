#ifndef ZORBA_MINIMAL_STORE_PUL
#define ZORBA_MINIMAL_STORE_PUL

#include <vector>

#include "store/api/pul.h"
#include "store/api/copymode.h"
//#include "store/util/handle_hashset_item.h"
#include "util/hashfun.h"
#include "store/util/hashmap.h"
#include "store/minimal/min_node_vector.h"
#include "store/minimal/min_node_updates.h"


namespace zorba { 
  namespace store {

class XmlNode;
class UpdatePrimitive;


typedef std::vector<UpdatePrimitive*> NodeUpdates;



/*******************************************************************************

********************************************************************************/
class NodeToUpdatesMap : public HashMap<XmlNode*, NodeUpdates, NodeToUpdatesMap>
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
    HashMap<XmlNode*, NodeUpdates, NodeToUpdatesMap>(8)
   {
   }
};


/*******************************************************************************
  theDoFirstList : insertInto, insertAttributes, replaceValue, rename
  theInsertList  : insertBefore, insertAfter, insertIntoFirst, insertIntoLast 
********************************************************************************/
class PULImpl : public PUL
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

  void addDelete(Item_t& n);

  void addInsertInto(
        Item_t&              target,
        std::vector<Item_t>& children,
        bool                 copy,
        const CopyMode&      copymode);

  void addInsertFirst(
        Item_t&              target,
        std::vector<Item_t>& children,
        bool                 copy,
        const CopyMode&      copymode);

  void addInsertLast(
        Item_t&              target,
        std::vector<Item_t>& children,
        bool                 copy,
        const CopyMode&      copymode);

  void addInsertBefore(
        Item_t&              target,
        std::vector<Item_t>& siblings,
        bool                 copy,
        const CopyMode&      copymode);

  void addInsertAfter(
        Item_t&              target,
        std::vector<Item_t>& siblings,
        bool                 copy,
        const CopyMode&      copymode);
  
  void addInsertAttributes(
        Item_t&              target,
        std::vector<Item_t>& attrs,
        bool                 copy,
        const CopyMode&      copymode);

  void addReplaceNode(
        Item_t&              target,
        std::vector<Item_t>& replacementNodes,
        bool                 copy,
        const CopyMode&      copymode);

  void addReplaceContent(
        Item_t&              target,
        Item_t&              newTextChild,
        bool                 copy,
        const CopyMode&      copymode);

  void addReplaceValue(
        Item_t&              target,
        xqpStringStore*      newValue);

  void addRename(
        Item_t&              target,
        Item_t&              newName);

  void applyUpdates();

  void serializeUpdates(serializer& ser, std::ostream& os);

  void mergeUpdates(Item* other);

  void checkTransformUpdates(const std::vector<Item*>& rootNodes) const;

protected:
  void undoUpdates();

  void addInsertChildren(
        UpdateConsts::UpdPrimKind kind,
        Item_t&                   target,
        std::vector<Item_t>&      children,
        bool                      copy,
        const CopyMode&           copymode);

  void addInsertSiblings(
        UpdateConsts::UpdPrimKind kind,
        Item_t&                   target,
        std::vector<Item_t>&      siblings,
        bool                      copy,
        const CopyMode&           copymode);

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
  Item_t        theTarget;
  bool          theIsApplied;
  bool          theRemoveType;
  TypeUndoList  theTypeUndoList;

public:
 UpdatePrimitive(Item_t& target) : theIsApplied(false), theRemoveType(false)
  {
    theTarget.transfer(target);
  }

  virtual ~UpdatePrimitive() { }

  virtual UpdateConsts::UpdPrimKind getKind() = 0;

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
  UpdDelete(Item_t& target) : UpdatePrimitive(target) { }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_DELETE; }

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
  UpdateConsts::UpdPrimKind theKind;
  std::vector<Item_t>       theChildren;
  bool                      theDoCopy;
  CopyMode                  theCopyMode;

public:
  UpdInsertChildren(
        UpdateConsts::UpdPrimKind kind,
        Item_t&                   target,
        std::vector<Item_t>&      children,
        bool                      copy,
        const CopyMode&           copymode);

  UpdateConsts::UpdPrimKind getKind() { return theKind; }

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
  UpdateConsts::UpdPrimKind theKind;
  std::vector<Item_t>       theSiblings;
  bool                      theDoCopy;
  CopyMode                  theCopyMode;

public:
  UpdInsertSiblings(
        UpdateConsts::UpdPrimKind kind,
        Item_t&                   target,
        std::vector<Item_t>&      siblings,
        bool                      copy,
        const CopyMode&           copymode);

  UpdateConsts::UpdPrimKind getKind() { return theKind; }

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
  std::vector<Item_t>  theAttributes;
  bool                 theDoCopy;
  CopyMode             theCopyMode;

public:
  UpdInsertAttributes(
        Item_t&               target,
        std::vector<Item_t>&  attrs,
        bool                  copy,
        const CopyMode&       copymode);

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_INSERT_ATTRIBUTES; }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceChild : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  Item_t               theChild;
  std::vector<Item_t>  theNewChildren;
  bool                 theDoCopy;
  CopyMode             theCopyMode;

public:
  UpdReplaceChild(
        Item_t&              target,
        Item_t&              child,
        std::vector<Item_t>& newChildren,
        bool                 copy,
        const CopyMode&      copymode);

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_CHILD; }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceAttribute : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  Item_t               theAttr;
  std::vector<Item_t>  theNewAttrs;
  bool                 theDoCopy;
  CopyMode             theCopyMode;

public:
  UpdReplaceAttribute(
        Item_t&              target,
        Item_t&              attr,
        std::vector<Item_t>& newAttrs,
        bool                 copy,
        const CopyMode&      copymode);

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_ATTRIBUTE; }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdReplaceContent : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  Item_t            theNewChild;
  ConstrNodeVector  theOldChildren;
  bool              theDoCopy;
  CopyMode          theCopyMode;

public:
  UpdReplaceContent(
        Item_t&         target,
        Item_t&         newChild, 
        bool            copy,
        const CopyMode& copymode)
    :
    UpdatePrimitive(target),
    theDoCopy(copy),
    theCopyMode(copymode)
  {
    theNewChild.transfer(newChild);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_CONTENT; }

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
  xqpStringStore_t    theOldValue;

public:
  UpdReplaceAttrValue(Item_t& t, xqpStringStore* newValue) : UpdatePrimitive(t)
  {
    theNewValue = newValue;
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_ATTR_VALUE; }

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
  UpdReplaceTextValue(Item_t& t, xqpStringStore* newValue)
    :
    UpdatePrimitive(t)
  {
    theNewValue = newValue;
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_TEXT_VALUE; }

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
  UpdReplacePiValue(Item_t& t, xqpStringStore* newValue)
    :
    UpdatePrimitive(t)
  {
    theNewValue = newValue;
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_PI_VALUE; }

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
  UpdReplaceCommentValue(Item_t& t, xqpStringStore* newValue)
    :
    UpdatePrimitive(t)
  {
    theNewValue = newValue;
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_COMMENT_VALUE; }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdRenameElem : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  Item_t   theNewName;
  Item_t   theOldName;

public:
  UpdRenameElem(Item_t& t, Item_t& newName) : UpdatePrimitive(t)
  {
    theNewName.transfer(newName);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_RENAME_ELEM; }

  void apply();
  void undo();
};


/*******************************************************************************

********************************************************************************/
class UpdRenameAttr : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  Item_t   theNewName;
  Item_t   theOldName;

public:
  UpdRenameAttr(Item_t& t, Item_t& newName) : UpdatePrimitive(t)
  {
    theNewName.transfer(newName);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_RENAME_ATTR; }

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
  UpdRenamePi(Item_t& t, xqpStringStore_t& newName) : UpdatePrimitive(t)
  {
    theNewName.transfer(newName);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_RENAME_PI; }

  void apply();
  void undo();
};


}
}

#endif
