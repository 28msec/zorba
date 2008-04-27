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
#include "store/api/update_consts.h"

namespace zorba { namespace store {

static const char* theUpdateKindStrings[] =
{
  "insert_before",
  "insert_after",
  "insert_into",
  "insert_into_first",
  "insert_into_last",
  "insert_attributes",
  "delete",
  "replace_node",
  "replace_content",
  "replace_value",
  "rename"
};


static const char* theUpdPrimKindStrings[] =
{
  "delete",
  "insert_into",
  "insert_into_first",
  "insert_into_last",
  "insert_before",
  "insert_after",
  "insert_attributes",
  "replace_child",
  "replace_attribute",
  "replace_content",
  "replace_attr_value",
  "replace_text_value",
  "replace_pi_value",
  "replace_comment_value",
  "rename_elem",
  "rename_attr",
  "rename_pi"
};


std::string UpdateConsts::toString(UpdateKind k)
{
  return theUpdateKindStrings[k];
}


std::string UpdateConsts::toString(UpdPrimKind k)
{
  return theUpdPrimKindStrings[k];
}


bool UpdateConsts::isRename(UpdPrimKind k)
{
  return (k == UP_RENAME_ELEM || k == UP_RENAME_ATTR || k == UP_RENAME_PI);
}


bool UpdateConsts::isReplaceValue(UpdPrimKind k)
{
  return (k == UP_REPLACE_ATTR_VALUE ||
          k == UP_REPLACE_TEXT_VALUE ||
          k == UP_REPLACE_PI_VALUE ||
          k == UP_REPLACE_COMMENT_VALUE);
}


bool UpdateConsts::isReplaceNode(UpdPrimKind k)
{
  return (k == UP_REPLACE_CHILD ||
          k == UP_REPLACE_ATTRIBUTE);
}


} // namespace store
} // namespace zorba
