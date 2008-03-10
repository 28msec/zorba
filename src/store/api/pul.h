
#ifndef ZORBA_STORE_PUL_H
#define ZORBA_STORE_PUL_H

#include "common/shared_types.h"

namespace zorba { namespace store {

class XmlNode;

/*******************************************************************************

********************************************************************************/
class PendingUpdateList
{
protected:

public:
};


/*******************************************************************************

********************************************************************************/
class UpdatePrimitive
{
public:

  enum 
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
  } UpdateKind;

protected:
  XmlNode    * theNode;

public:
  virtual ~UpdatePrimitive() { }

  UpdateKind getKind() = 0;
};


}
}

#endif
