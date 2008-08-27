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
    UP_SET_ELEMENT_TYPE
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

  static std::string toString(UpdateKind k)
  {
    switch(k) {
      case INSERT_BEFORE:
        return "insert_before";
      case INSERT_AFTER:
        return "insert_after";
      case INSERT_INTO:
        return "insert_into";
      case INSERT_INTO_FIRST:
        return "insert_into_first";
      case INSERT_INTO_LAST:
        return "insert_into_last";
      case INSERT_ATTRIBUTES:
        return "insert_attributes";
      case REMOVE:
        return "delete";
      case REPLACE_NODE:
        return "replace_node";
      case REPLACE_CONTENT:
        return "replace_content";
      case REPLACE_VALUE:
        return "replace_value";
      case RENAME:
        return "rename";
      default:
        return "<unknown UpdateKind>";
    }
  }

  static std::string toString(UpdPrimKind k)
  {
    switch(k) {
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
      default:
        return "<unknown UpdPrimKind>";
    }
  }
};


}
}

#endif
