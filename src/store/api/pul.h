
#ifndef ZORBA_STORE_PUL_H
#define ZORBA_STORE_PUL_H

#include "common/shared_types.h"

#include "store/api/update_consts.h"

namespace zorba { namespace store {

class XmlNode;
class CopyMode;

/*******************************************************************************

********************************************************************************/
class PUL
{
public:
  virtual ~PUL() { }

  virtual void addInsertAttributes(
        Item*                target,
        std::vector<Item_t>& attrs,
        bool                 copy,
        const CopyMode&      copymode) = 0;

  virtual void addDelete(Item* node) = 0;

  virtual void addReplaceContent(Item* target, Item_t& newChild) = 0;

  virtual void addReplaceValue(Item* target, xqpStringStore_t& newValue) = 0;

  virtual void addRename(Item* node, Item_t& name) = 0;

  virtual void applyUpdates() = 0;

  virtual void mergeUpdates(const PUL& other) = 0;
};


}
}

#endif
