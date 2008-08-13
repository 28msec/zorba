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
#ifndef ZORBA_STORE_PUL_H
#define ZORBA_STORE_PUL_H

#include "common/shared_types.h"

#include "store/api/update_consts.h"
#include "store/api/item.h"


namespace zorba { namespace store {

class XmlNode;
class CopyMode;

/*******************************************************************************

************************************** ******************************************/
class PUL : public Item
{
public:
  virtual ~PUL() { }

  bool isNode() const   { return false; }
  bool isAtomic() const { return false; }
  bool isPul() const    { return true; }

  virtual void addDelete(Item_t& node) = 0;

  virtual void addInsertInto(
        Item_t&              target,
        std::vector<Item_t>& children,
        const CopyMode&      copymode) = 0;

  virtual void addInsertFirst(
        Item_t&              target,
        std::vector<Item_t>& children,
        const CopyMode&      copymode) = 0;

  virtual void addInsertLast(
        Item_t&              target,
        std::vector<Item_t>& children,
        const CopyMode&      copymode) = 0;

  virtual void addInsertBefore(
        Item_t&              target,
        std::vector<Item_t>& siblings,
        const CopyMode&      copymode) = 0;

  virtual void addInsertAfter(
        Item_t&              target,
        std::vector<Item_t>& siblings,
        const CopyMode&      copymode) = 0;
  
  virtual void addInsertAttributes(
        Item_t&              target,
        std::vector<Item_t>& attrs,
        const CopyMode&      copymode) = 0;

  virtual void addReplaceNode(
        Item_t&              target,
        std::vector<Item_t>& replacementNodes,
        const CopyMode&      copymode) = 0;

  virtual void addReplaceContent(
        Item_t&              target,
        Item_t&              newTextChild,
        const CopyMode&      copymode) = 0;

  virtual void addReplaceValue(
        Item_t&              target,
        xqpStringStore_t&    newValue) = 0;

  virtual void addRename(
        Item_t&              target,
        Item_t&              newName) = 0;

  virtual void addSetElementType(
        Item_t&              target,
        Item_t&              typeName,
        Item_t&              typedValue,
        bool                 haveTypedValue,
        bool                 haveEmptyValue,
        bool                 isId,
        bool                 isIdRefs) = 0;

  virtual void addSetElementType(
        Item_t&              target,
        Item_t&              typeName,
        std::vector<Item_t>&  typedValue,
        bool                 haveTypedValue,
        bool                 haveEmptyValue,
        bool                 isId,
        bool                 isIdRefs) = 0;

  virtual void addSetAttributeType(
        Item_t&              target,
        Item_t&              typeName,
        Item_t&              typedValue,
        bool                 isId,
        bool                 isIdRefs) = 0;

  virtual void addSetAttributeType(
        Item_t&              target,
        Item_t&              typeName,
        std::vector<Item_t>& typedValue,
        bool                 isId,
        bool                 isIdRefs) = 0;

  //virtual void applyUpdates();

  //virtual void serializeUpdates(serializer ser&, std::ostream& os);

  virtual void mergeUpdates(Item* other) = 0;

  virtual void checkTransformUpdates(const std::vector<Item*>& rootNodes) const = 0;
};


}
}

#endif
