
#ifndef ZORBA_STORE_PUL_H
#define ZORBA_STORE_PUL_H

#include "common/shared_types.h"

#include "store/api/update_consts.h"
#include "store/api/item.h"


namespace zorba { namespace store {

class XmlNode;
class CopyMode;

/*******************************************************************************

************************************** ******************************************/
class PUL : public Item
{
public:
  virtual ~PUL() { }

  bool isNode() const   { return false; }
  bool isAtomic() const { return false; }
  bool isPul() const    { return true; }

  virtual void addDelete(Item_t& node) = 0;

  virtual void addInsertInto(
        Item_t&              target,
        std::vector<Item_t>& children,
        bool                 copy,
        const CopyMode&      copymode) = 0;

  virtual void addInsertFirst(
        Item_t&              target,
        std::vector<Item_t>& children,
        bool                 copy,
        const CopyMode&      copymode) = 0;

  virtual void addInsertLast(
        Item_t&              target,
        std::vector<Item_t>& children,
        bool                 copy,
        const CopyMode&      copymode) = 0;

  virtual void addInsertBefore(
        Item_t&              target,
        std::vector<Item_t>& siblings,
        bool                 copy,
        const CopyMode&      copymode) = 0;

  virtual void addInsertAfter(
        Item_t&              target,
        std::vector<Item_t>& siblings,
        bool                 copy,
        const CopyMode&      copymode) = 0;
  
  virtual void addInsertAttributes(
        Item_t&              target,
        std::vector<Item_t>& attrs,
        bool                 copy,
        const CopyMode&      copymode) = 0;

  virtual void addReplaceNode(
        Item_t&              target,
        std::vector<Item_t>& replacementNodes,
        bool                 copy,
        const CopyMode&      copymode) = 0;

  virtual void addReplaceContent(
        Item_t&              target,
        Item_t&              newTextChild,
        bool                 copy,
        const CopyMode&      copymode) = 0;

  virtual void addReplaceValue(
        Item_t&              target,
        xqpStringStore*      newValue) = 0;

  virtual void addRename(
        Item_t&              target,
        Item_t&              newName) = 0;

  //virtual void applyUpdates();

  //virtual void serializeUpdates(serializer ser&, std::ostream& os);

  virtual void mergeUpdates(Item* other) = 0;
};


}
}

#endif
