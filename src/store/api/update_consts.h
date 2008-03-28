
#ifndef ZORBA_STORE_UPDATE_CONSTS_H
#define ZORBA_STORE_UPDATE_CONSTS_H

#include <string>

namespace zorba { namespace store {

/*******************************************************************************

********************************************************************************/
class UpdateConsts
{
public:
  typedef enum 
  {
    INSERT_BEFORE,
    INSERT_AFTER,
    INSERT_INTO,
    INSERT_INTO_FIRST,
    INSERT_INTO_LAST,
    INSERT_ATTRIBUTES,
    REMOVE,
    REPLACE_NODE,
    REPLACE_CONTENT,
    REPLACE_VALUE,
    RENAME
  }
  UpdateKind;

  typedef enum
  {
    INTO,
    AS_FIRST_INTO,
    AS_LAST_INTO,
    AFTER,
    BEFORE
  } InsertType;

  typedef enum
  {
    VALUE_OF_NODE,
    NODE
  } ReplaceType;
    

  enum UpdPrimKind 
  {
    UP_INSERT_BEFORE,
    UP_INSERT_AFTER,
    UP_INSERT_INTO,
    UP_INSERT_INTO_FIRST,
    UP_INSERT_INTO_LAST,
    UP_INSERT_ATTRIBUTES,
    UP_DELETE,
    UP_REPLACE_NODE,
    UP_REPLACE_CONTENT,
    UP_REPLACE_ATTR_VALUE,
    UP_REPLACE_TEXT_VALUE,
    UP_REPLACE_PI_VALUE,
    UP_REPLACE_COMMENT_VALUE,
    UP_RENAME_ELEM,
    UP_RENAME_ATTR,
    UP_RENAME_PI
  };

  static bool isRename(UpdPrimKind k);
  static bool isReplaceValue(UpdPrimKind k);
  static std::string toString(UpdateKind k);
  static std::string toString(UpdPrimKind k);
};


}
}

#endif
