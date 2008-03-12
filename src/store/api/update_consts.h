
#ifndef ZORBA_STORE_PUL_CONSTS_H
#define ZORBA_STORE_PUL_CONSTS_H

#include <string>

namespace zorba { namespace store {

/*******************************************************************************

********************************************************************************/
class UpdateConsts
{
public:
  typedef enum 
  {
    INSER_BEFORE,
    INSERT_AFTER,
    INSERT_INTO,
    INSERT_INTO_FIRST,
    INSERT_INTO_LAST,
    INSERT_ATTRIBUTE,
    PUL_DELETE,
    REPLACE_NODE,
    REPLACE_VALUE,
    REPLACE_CONTENT,
    RENAME
  }
  UpdateKind;

  static std::string toString(UpdateKind k);
};


}
}

#endif
