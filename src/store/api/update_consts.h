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
class  UpdateConsts
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
    return "insert_into";
  case UP_INSERT_INTO_FIRST:
    return "insert_into_first";
  case UP_INSERT_INTO_LAST:
    return "insert_into_last";
  case UP_INSERT_BEFORE:
    return "insert_before";
  case UP_INSERT_AFTER:
    return "insert_after";
  case UP_INSERT_ATTRIBUTES:
    return "insert_attributes";
  case UP_REPLACE_CHILD:
    return "replace_child";
  case UP_REPLACE_ATTRIBUTE:
    return "replace_attribute";
  case UP_REPLACE_CONTENT:
    return "replace_content";
  case UP_REPLACE_ATTR_VALUE:
    return "replace_attr_value";
  case UP_REPLACE_TEXT_VALUE:
    return "replace_text_value";
  case UP_REPLACE_PI_VALUE:
    return "replace_pi_value";
  case UP_REPLACE_COMMENT_VALUE:
    return "replace_comment_value";
  case UP_RENAME_ELEM:
    return "rename_elem";
  case UP_RENAME_ATTR:
    return "rename_attr";
  case UP_RENAME_PI:
    return "rename_pi";
  case UP_PUT:
    return "put";
  case UP_CREATE_COLLECTION:
    return "create_collection";
  case UP_COLLECTION:
    return "update_collection";
  case UP_DELETE_COLLECTION:
    return "delete_collection";
  case UP_INSERT_INTO_COLLECTION:
    return "insert_into_coll";
  case UP_INSERT_FIRST_INTO_COLLECTION:
    return "insert_first_into_collection";
  case UP_INSERT_LAST_INTO_COLLECTION:
    return "insert_last_into_collection";
  case UP_INSERT_BEFORE_INTO_COLLECTION:
    return "insert_before_into_collection";
  case UP_INSERT_AFTER_INTO_COLLECTION:
    return "insert_after_into_collection";
  case UP_INSERT_AT_INTO_COLLECTION:
    return "insert_at_into_collection";
  case UP_REMOVE_FROM_COLLECTION:
    return "remove_from_collection";
  case UP_REMOVE_AT_FROM_COLLECTION:
    return "remove_at_from_collection";
  case UP_CREATE_INDEX:
    return "create index";
  case UP_DROP_INDEX:
    return "drop index";
  case UP_REBUILD_INDEX:
    return "refresh index";
  case UP_ACTIVATE_IC:
    return "activate integrity constraint";
  case UP_ACTIVATE_FOREIGN_KEY_IC:
    return "activate foreign key integrity constraint";
  case UP_DEACTIVATE_IC:
    return "deactivate integrity constraint";
  case UP_CREATE_DOCUMENT:
    return "create document";
  case UP_DELETE_DOCUMENT:
    return "delete document";
  case UP_CREATE_HASHMAP:
    return "create hashmap";
  case UP_DESTROY_HASHMAP:
    return "destroy hashmap";
  case UP_INSERT_INTO_HASHMAP:
    return "inserto_into_hashmap";
  case UP_REMOVE_FROM_HASHMAP:
    return "remove_from_hashmap";
  default:
    return "<unknown UpdPrimKind>";
  }
}
};


}
}

#endif
/* vim:set et sw=2 ts=2: */
