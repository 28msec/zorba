
#ifndef ZORBA_STORE_PUL_H
#define ZORBA_STORE_PUL_H

#include "common/shared_types.h"

namespace zorba { namespace store {

class XmlNode;

/*******************************************************************************

********************************************************************************/
class PUL
{
public:
  typedef enum 
  {
    INSER_BEFORE,
    INSERT_AFTER,
    INSERT_INTO,
    INSERT_INTO_FIRST,
    INSERT_INTO_LAST,
    INSET_ATTRIBUTE,
    DELETE,
    REPLACE_NODE,
    REPLACE_VALUE,
    REPLACE_CONTENT,
    RENAME
  }
  UpdateKind;

public:
  virtual ~PUL() { }

  virtual void addRename(Item* node, Item* name) = 0;
  virtual void addDelete(Item* node) = 0;

  virtual void applyUpdates() = 0;

  virtual void merge(const PUL& other) = 0;
};


}
}

#endif
