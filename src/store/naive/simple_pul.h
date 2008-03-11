#ifndef ZORBA_SIMPLE_STORE_PUL_H
#define ZORBA_SIMPLE_STORE_PUL_H

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

  ItemHashSet                     theTreeRoots;

public:
  void addRename(Item* node, Item* newName);
  void addDelete(Item* n);

  void apply();

  void merge(const PUL& other);
};


/*******************************************************************************

********************************************************************************/
class UpdatePrimitive
{
protected:
  XmlNode    * theTarget;

public:
  UpdatePrimitive(XmlNode* n) : theTarget(n) { }

  virtual ~UpdatePrimitive() { }

  virtual PUL::UpdateKind getKind() = 0;
};


/*******************************************************************************

********************************************************************************/
class DeletePrimitive : public UpdatePrimitive
{
public:
  DeletePrimitive(XmlNode* n) : UpdatePrimitive(n) { }

  PUL::UpdateKind getKind() { return PUL::DELETE; }
};


/*******************************************************************************

********************************************************************************/
class RenamePrimitive : public UpdatePrimitive
{
protected:
  QNameItemImpl   * theNewName;
  Item_t            theOldName;

public:
  RenamePrimitive(XmlNode* n, QNameItemImpl* name)
    :
    UpdatePrimitive(n),
    theNewName(name)
  {
  }

  PUL::UpdateKind getKind() { return PUL::RENAME; }
};


}
}

#endif
