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

class QueryLoc;

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

  virtual void addDelete(
      const QueryLoc* aQueryLoc,
      Item_t& node) = 0;

  virtual void addInsertInto(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        std::vector<Item_t>& children) = 0;

  virtual void addInsertFirst(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        std::vector<Item_t>& children) = 0;

  virtual void addInsertLast(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        std::vector<Item_t>& children) = 0;

  virtual void addInsertBefore(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        std::vector<Item_t>& siblings) = 0;

  virtual void addInsertAfter(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        std::vector<Item_t>& siblings) = 0;
  
  virtual void addInsertAttributes(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        std::vector<Item_t>& attrs) = 0;

  virtual void addReplaceNode(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        std::vector<Item_t>& replacementNodes) = 0;

  virtual void addReplaceContent(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        Item_t& newTextChild) = 0;

  virtual void addReplaceValue(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        zstring& newValue) = 0;

  virtual void addRename(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        Item_t& newName) = 0;

  virtual void addSetElementType(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        Item_t& typeName,
        Item_t& typedValue,
        bool haveValue,
        bool haveEmptyValue,
        bool haveTypedValue,
        bool isInSubstitutionGroup) = 0;

  virtual void addSetElementType(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        Item_t& typeName,
        std::vector<Item_t>& typedValue,
        bool haveValue,
        bool haveEmptyValue,
        bool haveTypedValue,
        bool isInSubstitutionGroup) = 0;

  virtual void addSetAttributeType(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        Item_t& typeName,
        Item_t& typedValue) = 0;

  virtual void addSetAttributeType(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        Item_t& typeName,
        std::vector<Item_t>& typedValue) = 0;

  virtual void addRevalidate(
          const QueryLoc* aQueryLoc,
          Item_t& target) = 0;

  virtual void addPut(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        Item_t& uri) = 0;

  // functions to add primitives for updating collection functions

  virtual void addCreateCollection(
        const QueryLoc* aQueryLoc,
        Item_t& name,
        const std::vector<Annotation_t>& annotations,
        const Item_t& nodeType, // can be null if not a schema type
        bool isDynamic,
        bool isJSONIQ) = 0;

  virtual void addDeleteCollection(
        const QueryLoc* aQueryLoc,
        Item_t& name,
        bool isDynamic,
        bool isJSONIQ) = 0;

  virtual void addInsertIntoCollection(
        const QueryLoc* aQueryLoc,
        Item_t& name,
        std::vector<Item_t>& nodes,
        bool isDynamic,
        bool isJSONIQ) = 0;

  virtual void addInsertFirstIntoCollection(
        const QueryLoc* aQueryLoc,
        Item_t& name,
        std::vector<Item_t>& nodes,
        bool isDynamic,
        bool isJSONIQ) = 0;

  virtual void addInsertLastIntoCollection(
        const QueryLoc* aQueryLoc,
        Item_t& name,
        std::vector<Item_t>& nodes,
        bool isDynamic,
        bool isJSONIQ) = 0;

  virtual void addInsertBeforeIntoCollection(
        const QueryLoc* aQueryLoc,
        Item_t& name,
        Item_t& target,
        std::vector<Item_t>& nodes,
        bool isDynamic,
        bool isJSONIQ) = 0;

  virtual void addInsertAfterIntoCollection(
        const QueryLoc* aQueryLoc,
        Item_t& name,
        Item_t& target,
        std::vector<Item_t>& nodes,
        bool isDynamic,
        bool isJSONIQ) = 0;

  virtual void addDeleteFromCollection(
        const QueryLoc* aQueryLoc,
        Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isLast,
        bool isDynamic,
        bool isJSONIQ) = 0;

  // functions to add primitives for indexes

  virtual void addCreateIndex(
        const QueryLoc* aQueryLoc,
        const Item_t& qname,
        const IndexSpecification& spec,
        Iterator* sourceIter) = 0;

  virtual void addDeleteIndex(
        const QueryLoc* aQueryLoc,
        const Item_t& qname) = 0;

  virtual void addRefreshIndex(
        const QueryLoc* aQueryLoc,
        const Item_t& qname,
        Iterator* sourceIter) = 0;

  // functions to add primitives for integrity constraints

  virtual void addActivateIC(
        const QueryLoc* aQueryLoc,
        const Item_t& qname,
        const Item_t& aCollectionName) = 0;

  virtual void addActivateForeignKeyIC(
        const QueryLoc* aQueryLoc,
        const Item_t& qname,
        const Item_t& aFromCollectionName,
        const Item_t& aToCollectionName) = 0;

  virtual void addDeActivateIC(
        const QueryLoc* aQueryLoc,
        const Item_t& qname) = 0;

  // functions to add primitives for documents 

  virtual void addCreateDocument(
        const QueryLoc* aQueryLoc,
        const Item_t& uri,
        Item_t& doc) = 0;

  virtual void addDeleteDocument(
        const QueryLoc* aQueryLoc,
        const Item_t& uri) = 0;

  // functions to add primitives for hash maps

  virtual void addCreateHashMap(
        const QueryLoc* aQueryLoc,
        const Item_t& aQName,
        const std::vector<Item_t>& aKeyTypes,
        const std::vector<zstring>& aCollations,
        long  aTimezone) = 0;

  virtual void addDestroyHashMap(
        const QueryLoc* aQueryLoc,
        const Item_t& aQName) = 0;

  virtual void addInsertIntoHashMap(
        const QueryLoc* aQueryLoc,
        const Item_t& aQName,
        const std::vector<Item_t>& aKey,
        const Iterator_t& aValue) = 0;

  virtual void addRemoveFromHashMap(
        const QueryLoc* aQueryLoc,
        const Item_t& aQName,
        const std::vector<Item_t>& aKey) = 0;

#ifdef ZORBA_WITH_JSON
  // functions to add primitives for jsoniq items

  virtual void addJSONObjectInsert(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        std::vector<Item_t>& names,
        std::vector<store::Item_t>& values) = 0;

  virtual void addJSONObjectDelete(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& name) = 0;

  virtual void addJSONObjectReplaceValue(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& name,
      store::Item_t& newValue) = 0;

  virtual void addJSONObjectRename(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& name,
      store::Item_t& newName) = 0;

  virtual void addJSONArrayInsert(
        const QueryLoc* aQueryLoc,
        Item_t& target,
        xs_integer& pos,
        std::vector<Item_t>& members) = 0;

  virtual void addJSONArrayDelete(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      xs_integer& pos) = 0;

  virtual void addJSONArrayReplaceValue(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      xs_integer& pos,
      store::Item_t& newValue) = 0;
#endif

  //

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
