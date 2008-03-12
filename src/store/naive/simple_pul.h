#ifndef ZORBA_SIMPLE_STORE_PUL
#define ZORBA_SIMPLE_STORE_PUL

#include <vector>

#include "store/api/pul.h"
#include "store/util/handle_hashset_item.h"
#include "store/util/pointer_hashmap.h"


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
                    NodeUpdates>(128, 0.6)
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

  ItemHandleHashSet               theTreeRoots;

public:
  void addReplaceContent(Item* target, Item* newChild);
  void addRename(Item* node, Item* newName);
  void addDelete(Item* n);

  void applyUpdates();

  void mergeUpdates(const PUL& other);

protected:
  void verify();
};


/*******************************************************************************

********************************************************************************/
class UpdatePrimitive
{
  friend class PULImpl;

protected:
  XmlNode    * theTarget;

public:
  UpdatePrimitive(XmlNode* target) : theTarget(target) { }

  virtual ~UpdatePrimitive() { }

  virtual UpdateConsts::UpdateKind getKind() = 0;

  virtual void apply() = 0;
};


/*******************************************************************************

********************************************************************************/
class DeletePrimitive : public UpdatePrimitive
{
  friend class PULImpl;

public:
  DeletePrimitive(XmlNode* target) : UpdatePrimitive(target) { }

  UpdateConsts::UpdateKind getKind() { return UpdateConsts::PUL_DELETE; }

  void apply();
};


/*******************************************************************************

********************************************************************************/
class ReplaceContentPrimitive : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  XmlNode                * theNewChild;
  std::vector<XmlNode*>    theOldChildren;

public:
  ReplaceContentPrimitive(XmlNode* target, XmlNode* newChild)
    :
    UpdatePrimitive(target),
    theNewChild(newChild)
  {
  }

  UpdateConsts::UpdateKind getKind() { return UpdateConsts::REPLACE_CONTENT; }

  void apply();
};


/*******************************************************************************

********************************************************************************/
class RenamePrimitive : public UpdatePrimitive
{
  friend class PULImpl;

protected:
  QNameItemImpl   * theNewName;
  Item_t            theOldName;

public:
  RenamePrimitive(XmlNode* target, QNameItemImpl* name)
    :
    UpdatePrimitive(target),
    theNewName(name)
  {
  }

  UpdateConsts::UpdateKind getKind() { return UpdateConsts::RENAME; }

  void apply();
};


}
}

#endif
