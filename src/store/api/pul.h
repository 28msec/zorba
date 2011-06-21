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
#ifndef ZORBA_STORE_PUL
#define ZORBA_STORE_PUL

#include <set>

#include <zorba/config.h>

#include "store/api/shared_types.h"
#include "store/api/update_consts.h"
#include "store/api/item.h"


namespace zorba 
{ 

class static_context;

typedef std::pair<const store::Item*, store::Index_t> IndexBinding;


namespace store 
{

class XmlNode;
class Iterator;
class IndexSpecification;
class IndexEntryCreator;
class Index;
class SchemaValidator;


/*******************************************************************************

********************************************************************************/
class PUL : public Item
{
protected:
  PUL() : Item(Item::PUL) { }

public:
  virtual ~PUL() { }

  virtual void addDelete(Item_t& node) = 0;

  virtual void addInsertInto(
        Item_t& target,
        std::vector<Item_t>& children) = 0;

  virtual void addInsertFirst(
        Item_t& target,
        std::vector<Item_t>& children) = 0;

  virtual void addInsertLast(
        Item_t& target,
        std::vector<Item_t>& children) = 0;

  virtual void addInsertBefore(
        Item_t& target,
        std::vector<Item_t>& siblings) = 0;

  virtual void addInsertAfter(
        Item_t& target,
        std::vector<Item_t>& siblings) = 0;
  
  virtual void addInsertAttributes(
        Item_t& target,
        std::vector<Item_t>& attrs) = 0;

  virtual void addReplaceNode(
        Item_t& target,
        std::vector<Item_t>& replacementNodes) = 0;

  virtual void addReplaceContent(
        Item_t& target,
        Item_t& newTextChild) = 0;

  virtual void addReplaceValue(
        Item_t& target,
        zstring& newValue) = 0;

  virtual void addRename(
        Item_t& target,
        Item_t& newName) = 0;

  virtual void addSetElementType(
        Item_t& target,
        Item_t& typeName,
        Item_t& typedValue,
        bool haveValue,
        bool haveEmptyValue,
        bool haveTypedValue,
        bool isInSubstitutionGroup) = 0;

  virtual void addSetElementType(
        Item_t& target,
        Item_t& typeName,
        std::vector<Item_t>& typedValue,
        bool haveValue,
        bool haveEmptyValue,
        bool haveTypedValue,
        bool isInSubstitutionGroup) = 0;

  virtual void addSetAttributeType(
        Item_t& target,
        Item_t& typeName,
        Item_t& typedValue) = 0;

  virtual void addSetAttributeType(
        Item_t& target,
        Item_t& typeName,
        std::vector<Item_t>& typedValue) = 0;


  virtual void addPut(
        Item_t& target,
        Item_t& uri) = 0;

  // functions to add primitives for updating collection functions

  virtual void addCreateCollection(
        Item_t& name,
        bool dyn_collection = false) = 0;

  virtual void addDeleteCollection(
        Item_t& name,
        bool dyn_collection = false) = 0;

  virtual void addInsertIntoCollection(
        Item_t& name,
        std::vector<Item_t>& nodes,
        bool dyn_collection = false) = 0;

  virtual void addInsertFirstIntoCollection(
        Item_t& name,
        std::vector<Item_t>& nodes,
        bool dyn_collection = false) = 0;

  virtual void addInsertLastIntoCollection(
        Item_t& name,
        std::vector<Item_t>& nodes,
        bool dyn_collection = false) = 0;

  virtual void addInsertBeforeIntoCollection(
        Item_t& name,
        Item_t& target,
        std::vector<Item_t>& nodes,
        bool dyn_collection = false) = 0;

  virtual void addInsertAfterIntoCollection(
        Item_t& name,
        Item_t& target,
        std::vector<Item_t>& nodes,
        bool dyn_collection = false) = 0;

  virtual void addDeleteFromCollection(
        Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isLast,
        bool dyn_collection = false) = 0;

  // functions to add primitives for indexes

  virtual void addCreateIndex(
        const Item_t& qname,
        const IndexSpecification& spec,
        Iterator* sourceIter) = 0;

  virtual void addDeleteIndex(
        const Item_t& qname) = 0;

  virtual void addRefreshIndex(
        const Item_t& qname,
        Iterator* sourceIter) = 0;

  // functions to add primitives for integrity constraints

  virtual void addActivateIC(
        const Item_t& qname,
        const Item_t& aCollectionName) = 0;

  virtual void addActivateForeignKeyIC(
        const Item_t& qname,
        const Item_t& aFromCollectionName,
        const Item_t& aToCollectionName) = 0;

  virtual void addDeActivateIC(
        const Item_t& qname) = 0;

  // functions to add primitives for documents 

  virtual void addCreateDocument(
        const Item_t& uri,
        Item_t& doc) = 0;

  virtual void addDeleteDocument(
        const Item_t& uri) = 0;

  // functions to add primitives for hash maps

  virtual void addCreateHashMap(
        const Item_t& aQName,
        const std::vector<Item_t>& aKeyTypes,
        const std::vector<zstring>& aCollations,
        long  aTimezone) = 0;

  virtual void addDestroyHashMap(
        const Item_t& aQName) = 0;

  virtual void addInsertIntoHashMap(
        const Item_t& aQName,
        const std::vector<Item_t>& aKey,
        const Iterator_t& aValue) = 0;

  virtual void addRemoveFromHashMap(
        const Item_t& aQName,
        const std::vector<Item_t>& aKey) = 0;

  virtual void mergeUpdates(Item* other) = 0;

  virtual void applyUpdates(bool inheritNSBindings) = 0;

  virtual void checkTransformUpdates(
        const std::vector<Item*>& rootNodes) const = 0;

  // utils
  virtual void getIndicesToRefresh(
        std::vector<Index*>& indices) = 0;

  virtual void addIndexEntryCreator(
        const Item* collectionName, 
        Index* idx,
        IndexEntryCreator* creator) = 0;

  virtual void setValidator(
        SchemaValidator* validator) = 0;

  virtual store::SchemaValidator* getValidator() const = 0;
  
  virtual void setICChecker(ICChecker* icChecker) = 0;
};


}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
