#ifndef ZORBA_SIMPLE_STORE_PUL
#define ZORBA_SIMPLE_STORE_PUL

#include <vector>

#include "store/api/pul.h"
#include "store/api/copymode.h"
#include "store/util/handle_hashset_item.h"
#include "store/util/pointer_hashmap.h"
#include "store/naive/node_vector.h"

namespace zorba { namespace store {

class XmlNode;
class UpdatePrimitive;


typedef std::vector<UpdatePrimitive*> NodeUpdates;



/*******************************************************************************

********************************************************************************/
class NodeToUpdatesMap : public PointerHashMap<XmlNode,
                                               NodeToUpdatesMap,
                                               NodeUpdates>
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
    PointerHashMap<XmlNode,
                   NodeToUpdatesMap,
                   NodeUpdates>(8, 0.6)
   {
   }
};


/*******************************************************************************

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
        xqpStringStore_t&    newValue);

  void addRename(
        Item_t&              target,
        Item_t&              newName);

  void applyUpdates();

  void mergeUpdates(const PUL& other);

protected:
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
};


/*******************************************************************************

********************************************************************************/
class UpdatePrimitive
{
  friend class PULImpl;

protected:
  Item_t  theTarget;

public:
  UpdatePrimitive(Item_t& target) { theTarget.transfer(target); }

  virtual ~UpdatePrimitive() { }

  virtual UpdateConsts::UpdPrimKind getKind() = 0;

  virtual void apply() = 0;
};


/*******************************************************************************

********************************************************************************/
class UpdDelete : public UpdatePrimitive
{
  friend class PULImpl;

public:
  UpdDelete(Item_t& target) : UpdatePrimitive(target) { }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_DELETE; }

  void apply();
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
        const CopyMode&           copymode)
    :
    UpdatePrimitive(target),
    theKind(kind),
    theDoCopy(copy),
    theCopyMode(copymode)
  {
    ulong numChildren = children.size();
    theChildren.resize(numChildren);
    for (ulong i = 0; i < numChildren; i++)
      theChildren[i].transfer(children[i]);
  }

  UpdateConsts::UpdPrimKind getKind() { return theKind; }

  void apply();
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
        const CopyMode&           copymode)
    :
    UpdatePrimitive(target),
    theKind(kind),
    theDoCopy(copy),
    theCopyMode(copymode)
  {
    ulong numSiblings = siblings.size();
    theSiblings.resize(numSiblings);
    for (ulong i = 0; i < numSiblings; i++)
      theSiblings[i].transfer(siblings[i]);
  }

  UpdateConsts::UpdPrimKind getKind() { return theKind; }

  void apply();
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
        const CopyMode&       copymode)
    :
    UpdatePrimitive(target),
    theDoCopy(copy),
    theCopyMode(copymode)
  {
    ulong numAttrs = attrs.size();
    theAttributes.resize(numAttrs);
    for (ulong i = 0; i < numAttrs; i++)
      theAttributes[i].transfer(attrs[i]);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_INSERT_ATTRIBUTES; }

  void apply();
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
  ulong                thePos;

public:
  UpdReplaceChild(
        Item_t&              target,
        Item_t&              child,
        std::vector<Item_t>& newChildren,
        bool                 copy,
        const CopyMode&      copymode)
    :
    UpdatePrimitive(target),
    theDoCopy(copy),
    theCopyMode(copymode)
  {
    theChild.transfer(child);

    ulong numChildren = newChildren.size();
    theNewChildren.resize(numChildren);
    for (ulong i = 0; i < numChildren; i++)
      theNewChildren[i].transfer(newChildren[i]);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_CHILD; }

  void apply();
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
  ulong                thePos;

public:
  UpdReplaceAttribute(
        Item_t&              target,
        Item_t&              attr,
        std::vector<Item_t>& newAttrs,
        bool                 copy,
        const CopyMode&      copymode)
    :
    UpdatePrimitive(target),
    theDoCopy(copy),
    theCopyMode(copymode)
  {
    theAttr.transfer(attr);

    ulong numAttrs = newAttrs.size();
    theNewAttrs.resize(numAttrs);
    for (ulong i = 0; i < numAttrs; i++)
      theNewAttrs[i].transfer(newAttrs[i]);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_ATTRIBUTE; }

  void apply();
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
    UpdatePrimitive(target)
  {
    theNewChild.transfer(newChild);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_CONTENT; }

  void apply();
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
  UpdReplaceAttrValue(Item_t& t, xqpStringStore_t& newValue) : UpdatePrimitive(t)
  {
    theNewValue.transfer(newValue);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_ATTR_VALUE; }

  void apply();
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
  UpdReplaceTextValue(Item_t& t, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(t)
  {
    theNewValue.transfer(newValue);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_TEXT_VALUE; }

  void apply();
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
  UpdReplacePiValue(Item_t& t, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(t)
  {
    theNewValue.transfer(newValue);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_PI_VALUE; }

  void apply();
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
  UpdReplaceCommentValue(Item_t& t, xqpStringStore_t& newValue)
    :
    UpdatePrimitive(t)
  {
    theNewValue.transfer(newValue);
  }

  UpdateConsts::UpdPrimKind getKind() { return UpdateConsts::UP_REPLACE_COMMENT_VALUE; }

  void apply();
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
};


}
}

#endif
