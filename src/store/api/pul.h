
#ifndef ZORBA_STORE_PUL_H
#define ZORBA_STORE_PUL_H

#include "common/shared_types.h"

#include "store/api/pul_consts.h"

namespace zorba { namespace store {

class XmlNode;

/*******************************************************************************

********************************************************************************/
class PUL
{
public:
  virtual ~PUL() { }

  virtual void addRename(Item* node, Item* name) = 0;
  virtual void addDelete(Item* node) = 0;

  virtual void applyUpdates() = 0;

  virtual void mergeUpdates(const PUL& other) = 0;
};


}
}

#endif
