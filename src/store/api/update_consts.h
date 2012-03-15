  /*
   * Copyright 2006-2008 The FLWOR Foundation.
   * 
   * Licensed under the Apache License, Version 2.0 (the "License");
   * you may not use this file except in compliance with the License.
   * You may obtain a copy of the License at
   * 
   * http://www.apache.org/licenses/LICENSE-2.0
   * 
   * Unless required by applicable law or agreed to in writing, software
   * distributed under the License is distributed on an "AS IS" BASIS,
   * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   * See the License for the specific language governing permissions and
   * limitations under the License.
   */
#ifndef ZORBA_STORE_UPDATE_CONSTS_H
#define ZORBA_STORE_UPDATE_CONSTS_H

#include <string>
#include <zorba/config.h>

namespace zorba { namespace store {

/*******************************************************************************

********************************************************************************/
class UpdateConsts
{
public:
  typedef enum
  {
    INTO,
    AS_FIRST_INTO,
    AS_LAST_INTO,
    AFTER,
    BEFORE
  }
  InsertType;

  typedef enum
  {
    VALUE_OF_NODE,
    NODE
  }
  ReplaceType;
    

  enum UpdPrimKind 
  {
    UP_DELETE,
    UP_INSERT_INTO,
    UP_INSERT_INTO_FIRST,
    UP_INSERT_INTO_LAST,
    UP_INSERT_BEFORE,
    UP_INSERT_AFTER,
    UP_INSERT_ATTRIBUTES,
    UP_REPLACE_CHILD,
    UP_REPLACE_ATTRIBUTE,
    UP_REPLACE_CONTENT,
    UP_REPLACE_ATTR_VALUE,
    UP_REPLACE_TEXT_VALUE,
    UP_REPLACE_PI_VALUE,
    UP_REPLACE_COMMENT_VALUE,
    UP_RENAME_ELEM,
    UP_RENAME_ATTR,
    UP_RENAME_PI,
    UP_SET_ATTRIBUTE_TYPE,
    UP_SET_ELEMENT_TYPE,
    UP_REVALIDATE,
    UP_PUT,

    // collection primitives
    UP_CREATE_COLLECTION,
    UP_COLLECTION,
    UP_DELETE_COLLECTION,
    UP_INSERT_INTO_COLLECTION,
    UP_INSERT_FIRST_INTO_COLLECTION,
    UP_INSERT_LAST_INTO_COLLECTION,
    UP_INSERT_BEFORE_INTO_COLLECTION,
    UP_INSERT_AFTER_INTO_COLLECTION,
    UP_INSERT_AT_INTO_COLLECTION,
    UP_REMOVE_FROM_COLLECTION,
    UP_REMOVE_AT_FROM_COLLECTION,
    UP_TRUNCATE_COLLECTION,

    // index primitives
    UP_CREATE_INDEX,
    UP_DROP_INDEX,
    UP_REBUILD_INDEX,

    // ic primitives
    UP_ACTIVATE_IC,
    UP_ACTIVATE_FOREIGN_KEY_IC,
    UP_DEACTIVATE_IC,

    // doc primitives
    UP_CREATE_DOCUMENT,
    UP_DELETE_DOCUMENT,

    // hashmap primitives
    UP_CREATE_HASHMAP,
    UP_DESTROY_HASHMAP,
    UP_INSERT_INTO_HASHMAP,
    UP_REMOVE_FROM_HASHMAP
  };

  static bool isRename(UpdPrimKind k)
  {
    return (k == UP_RENAME_ELEM || k == UP_RENAME_ATTR || k == UP_RENAME_PI);
  }

  static bool isReplaceValue(UpdPrimKind k)
  {
    return (k == UP_REPLACE_ATTR_VALUE ||
          k == UP_REPLACE_TEXT_VALUE ||
          k == UP_REPLACE_PI_VALUE ||
          k == UP_REPLACE_COMMENT_VALUE);
  }

  static bool isReplaceNode(UpdPrimKind k)
  {
    return (k == UP_REPLACE_CHILD ||
          k == UP_REPLACE_ATTRIBUTE);
  }


static std::string toString(UpdPrimKind k)
{
  switch(k) 
  {
    case UP_DELETE:
      return "delete";
    case UP_INSERT_INTO:
      return "insertInto";
    case UP_INSERT_INTO_FIRST:
      return "insertIntoAsFirst";
    case UP_INSERT_INTO_LAST:
      return "insertIntoAsLast";
    case UP_INSERT_BEFORE:
      return "insertBefore";
    case UP_INSERT_AFTER:
      return "insertAfter";
    case UP_INSERT_ATTRIBUTES:
      return "insertAttributes";
    case UP_REPLACE_CHILD:
    case UP_REPLACE_ATTRIBUTE:
      return "replaceNode";
    case UP_REPLACE_CONTENT:
      return "replaceElementContent";
    case UP_REPLACE_ATTR_VALUE:
    case UP_REPLACE_TEXT_VALUE:
    case UP_REPLACE_PI_VALUE:
    case UP_REPLACE_COMMENT_VALUE:
      return "replaceValue";
    case UP_RENAME_ELEM:
    case UP_RENAME_ATTR:
    case UP_RENAME_PI:
      return "rename";
    case UP_PUT:
      return "put";
    case UP_CREATE_COLLECTION:
      return "createCollection";
    case UP_COLLECTION:
      return "updateCollection";
    case UP_DELETE_COLLECTION:
      return "deleteCollection";
    case UP_INSERT_INTO_COLLECTION:
      return "insertIntoCollection";
    case UP_INSERT_FIRST_INTO_COLLECTION:
      return "insertFirstIntoCollection";
    case UP_INSERT_LAST_INTO_COLLECTION:
      return "insertLastIntoCollection";
    case UP_INSERT_BEFORE_INTO_COLLECTION:
      return "insertBeforeIntoCollection";
    case UP_INSERT_AFTER_INTO_COLLECTION:
      return "insertAfterIntoCollection";
    case UP_INSERT_AT_INTO_COLLECTION:
      return "insertAtIntoCollection";
    case UP_REMOVE_FROM_COLLECTION:
      return "removeFromCollection";
    case UP_TRUNCATE_COLLECTION:
      return "truncateCollection";
    case UP_REMOVE_AT_FROM_COLLECTION:
      return "removeAtFromCollection";
    case UP_CREATE_INDEX:
      return "createIndex";
    case UP_DROP_INDEX:
      return "dropIndex";
    case UP_REBUILD_INDEX:
      return "rebuildIndex";
    case UP_ACTIVATE_IC:
      return "activateIC";
    case UP_ACTIVATE_FOREIGN_KEY_IC:
      return "activateForeignKeyIC";
    case UP_DEACTIVATE_IC:
      return "deactivateIC";
    case UP_CREATE_DOCUMENT:
      return "createDocument";
    case UP_DELETE_DOCUMENT:
      return "deleteDocument";
    case UP_CREATE_HASHMAP:
      return "createHashmap";
    case UP_DESTROY_HASHMAP:
      return "destroyHashmap";
    case UP_INSERT_INTO_HASHMAP:
      return "insertIntoHashmap";
    case UP_REMOVE_FROM_HASHMAP:
      return "removeFromHashmap";
    case UP_SET_ATTRIBUTE_TYPE:
      return "setAttributeType";
    case UP_SET_ELEMENT_TYPE:
      return "setElementType";
    case UP_REVALIDATE:
      return "revalidate";
    default:
      return "unknownUpdatePrimitive";
  }
}
};


}
}

#endif
/* vim:set et sw=2 ts=2: */
