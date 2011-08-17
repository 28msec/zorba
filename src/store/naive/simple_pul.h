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
#ifndef ZORBA_SIMPLE_STORE_PUL
#define ZORBA_SIMPLE_STORE_PUL

#include <vector>

#include "store/naive/shared_types.h"

#include "store/api/pul.h"
#include "store/api/index.h"

#include "zorbautils/hashfun.h"
#include "zorbautils/hashmap.h"


namespace zorba 
{ 

namespace store
{
  class SchemaValidator;
}


namespace simplestore 
{

class UpdatePrimitive;
class IndexKey;
class PULImpl;
class QNameItem;
class SimpleCollection;


typedef std::vector<UpdatePrimitive*> NodeUpdates;


/*******************************************************************************
  A map that maps each target node N to the update primitives having N as their
  target. This map is a data member of each PUL. The map contains target nodes
  that appear in the following kinds of primitives:

  UpdDelete,
  UpdRenameElem, UpdRenameAttr, UpdRenamePi,
  UpdInsertChildren, UpdInsertAttributes, UpdReplaceChild,
  UpdReplaceAttribute, UpdReplaceElemContent, 
  UpdReplaceAttrValue, UpdReplacePiValue, UpdReplaceTextValue, UpdReplaceCommentValue, 

  It is used to check that, for certain kinds of updates, there are no duplicate
  updates of that kind on the same target node. In particular, there can be no
  duplicate rename, replaveValue, replaceContent, or replaceNode updates.
********************************************************************************/
class NodeToUpdatesMap
{
public:

  class CompareFunction
  {
  public:
    static bool equal(const XmlNode* n1, const XmlNode* n2)
    {
      return n1 == n2;
    }

    static uint32_t hash(const XmlNode* n)
    {
      return hashfun::h32((void*)(&n), sizeof(void*), FNV_32_INIT);
    }
  };

  typedef HashMap<XmlNode*, NodeUpdates*, CompareFunction>::iterator iterator;

private:

  HashMap<XmlNode*, NodeUpdates*, CompareFunction> theMap;

public:
  NodeToUpdatesMap() : theMap(8, false)
  {
  }

  ~NodeToUpdatesMap();

  iterator begin() const { return theMap.begin(); }

  iterator end() const { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  bool get(XmlNode* key, NodeUpdates*& value) { return theMap.get(key, value); }

  bool insert(XmlNode* key, NodeUpdates* value) { return theMap.insert(key, value); }

  bool remove(XmlNode* key) { return theMap.remove(key); }

  void clear() { theMap.clear(); }
};


/*******************************************************************************
  Class storing all update primitives involving a single collection, or no
  collection at all.

  theDoFirstList : insertInto, insertAttributes, replaceValue, rename
  theInsertList  : insertBefore, insertAfter, insertIntoFirst, insertIntoLast 
********************************************************************************/
class CollectionPul
{
  friend class PULImpl;
  friend class UpdatePrimitive;
  friend class ElementNode;
  friend class AttributeNode;

protected:
  // Bookeeping
  SimpleCollection                 * theCollection;

  PULImpl                          * thePul;

  NodeToUpdatesMap                   theNodeToUpdatesMap;

  std::vector<UpdatePrimitive*>      thePrimitivesToRecheck;

  std::set<store::Item*>             theValidationNodes;

  bool                               theAdjustTreePositions;

  bool                               theIsApplied;

  // XQUF update primitives
  std::vector<UpdatePrimitive*>      theDoFirstList;
  std::vector<UpdatePrimitive*>      theInsertList;
  std::vector<UpdatePrimitive*>      theReplaceNodeList;
  std::vector<UpdatePrimitive*>      theReplaceContentList;
  std::vector<UpdatePrimitive*>      theDeleteList;

  // Update primitives for collection functions
  std::vector<UpdatePrimitive*>      theCreateCollectionList;
  std::vector<UpdatePrimitive*>      theInsertIntoCollectionList;
  std::vector<UpdatePrimitive*>      theDeleteFromCollectionList;
  std::vector<UpdatePrimitive*>      theDeleteCollectionList;

  // Index Maintenance
  std::set<XmlNode*>                 theModifiedDocs;
  std::vector<XmlNode*>              theInsertedDocs;
  std::vector<XmlNode*>              theDeletedDocs;

  std::vector<IndexImpl*>            theIncrementalIndices;

  std::vector<IndexEntryCreator_t>   theIndexEntryCreators;

  std::vector<store::IndexDelta>     theBeforeIndexDeltas;
  std::vector<store::IndexDelta>     theAfterIndexDeltas;
  std::vector<store::IndexDelta>     theInsertedDocsIndexDeltas;
  std::vector<store::IndexDelta>     theDeletedDocsIndexDeltas;

public:
  CollectionPul(PULImpl* pul, SimpleCollection* collection);

  ~CollectionPul();

  void switchPul(PULImpl* pul);

  void applyUpdates();

  void finalizeUpdates();

  void undoUpdates();

  void computeIndexBeforeDeltas();

  void computeIndexAfterDeltas();

  void refreshIndices();

  void setAdjustTreePositions() { theAdjustTreePositions = true; }

protected:
  void switchPulInPrimitivesList(std::vector<UpdatePrimitive*>& list);

  void computeIndexDeltas(std::vector<store::IndexDelta>& deltas);
};


/*******************************************************************************
  theCollectionPuls  :
  theNoCollectionPul : Pointer to the CollectionPul that contains the XQUF
                       primitives for the trees that do not belong to any
                       collection. Note: theCollectionPuls contains a pointer
                       to this CollectionPul as well, with NULL as the associated
                       QName item.
  theLastPul         :
  theLastCollection  :

  thePutList         :
  theCreateIndexList :
  theDeleteIndexList :
  theRefreshIndexList:

  theValidator       :
  theValidationList  : If this list is non-empty, then all the other lists are
                       empty and vice-versa.

  theICChecker       : The object that invokes the check Iterator
********************************************************************************/
class PULImpl : public store::PUL
{
  friend class CollectionPul;

public:
  enum UpdListKind
  {
    UP_LIST_NONE,
    UP_LIST_DO_FIRST,
    UP_LIST_REPLACE_NODE,
    UP_LIST_REPLACE_CONTENT,
    UP_LIST_DELETE,
    UP_LIST_PUT,
    UP_LIST_CREATE_COLLECTION,
    UP_LIST_CREATE_INDEX
  };

  typedef std::map<const QNameItem*, CollectionPul*> CollectionPulMap;

protected:
  // XQUF and collection primitives, grouped by the collection that is being updated.
  CollectionPulMap                   theCollectionPuls;
  CollectionPul                    * theNoCollectionPul;
  CollectionPul                    * theLastPul;
  const QNameItem                  * theLastCollection;

  // fn:put primitives
  std::vector<UpdatePrimitive*>      thePutList;

  // Index primitives
  std::vector<UpdatePrimitive*>      theCreateIndexList;
  std::vector<UpdatePrimitive*>      theDeleteIndexList;
  std::vector<UpdatePrimitive*>      theRefreshIndexList;

  // Integrity constrint
  std::vector<UpdatePrimitive*>      theICActivationList;
  store::ICChecker                 * theICChecker;

  // Document primitives
  std::vector<UpdatePrimitive*>      theCreateDocumentList;
  std::vector<UpdatePrimitive*>      theDeleteDocumentList;

  // Hashmap primitives
  // ddl
  std::vector<UpdatePrimitive*>      theCreateHashMapList;
  std::vector<UpdatePrimitive*>      theDestroyHashMapList;
  // dml
  std::vector<UpdatePrimitive*>      theInsertIntoHashMapList;
  std::vector<UpdatePrimitive*>      theRemoveFromHashMapList;

  // Revalidation
  store::SchemaValidator           * theValidator;

  std::vector<UpdatePrimitive*>      theValidationList;

  bool                               theInheritNSBindings;

public:
  PULImpl();

  ~PULImpl();

  // XQUF primitives
  void addDelete(
      const QueryLoc* aQueryLoc,
      store::Item_t& n);

  void addInsertInto(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        std::vector<store::Item_t>& children);

  void addInsertFirst(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        std::vector<store::Item_t>& children);

  void addInsertLast(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        std::vector<store::Item_t>& children);

  void addInsertBefore(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        std::vector<store::Item_t>& siblings);

  void addInsertAfter(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        std::vector<store::Item_t>& siblings);

  void addInsertAttributes(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        std::vector<store::Item_t>& attrs);

  void addReplaceNode(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        std::vector<store::Item_t>& replacementNodes);

  void addReplaceContent(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        store::Item_t& newTextChild);

  void addReplaceValue(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        zstring& newValue);

  void addRename(
        const QueryLoc* aQueryLoc,
        store::Item_t& target,
        store::Item_t& newName);

  void addPut(
        const QueryLoc* aQueryLoc,
        store::Item_t& node,
        store::Item_t& uri);

  // Revalidation primitives
  void addSetElementType(
        const QueryLoc* aQueryLoc,
        store::Item_t&               target,
        store::Item_t&               typeName,
        store::Item_t&               value,
        bool                         haveValue,
        bool                         haveEmptyValue,
        bool                         haveTypedValue,
        bool                         isInSubstitutionGroup);

  void addSetElementType(
        const QueryLoc* aQueryLoc,
        store::Item_t&               target,
        store::Item_t&               typeName,
        std::vector<store::Item_t>&  value,
        bool                         haveValue,
        bool                         haveEmptyValue,
        bool                         haveTypedValue,
        bool                         isInSubstitutionGroup);

  void addSetAttributeType(
        const QueryLoc* aQueryLoc,
        store::Item_t&               target,
        store::Item_t&               typeName,
        store::Item_t&               typedValue);

  void addSetAttributeType(
        const QueryLoc* aQueryLoc,
        store::Item_t&              target,
        store::Item_t&              typeName,
        std::vector<store::Item_t>& typedValue);

  // Collection primitives
  void addCreateCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        uint32_t flags,
        const store::Item_t& nodeType,
        bool dyn_collection = false);

  void addDeleteCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        bool dyn_collection = false);

  void addInsertIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool dyn_collection = false);

  void addInsertFirstIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool dyn_collection = false);

  void addInsertLastIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool dyn_collection = false);

  void addInsertBeforeIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes,
        bool dyn_collection = false);

  void addInsertAfterIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes,
        bool dyn_collection = false);

  void addDeleteFromCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isLast,
        bool dyn_collection = false);

  // Index primitives
  void addCreateIndex(
        const QueryLoc* aQueryLoc,
        const store::Item_t& qname,
        const store::IndexSpecification& spec,
        store::Iterator* sourceIter);

  void addDeleteIndex(
        const QueryLoc* aQueryLoc,
        const store::Item_t& qname);

  void addRefreshIndex(
        const QueryLoc* aQueryLoc,
        const store::Item_t& qname,
        store::Iterator* sourceIter);

  virtual void addActivateIC(
        const QueryLoc* aQueryLoc,
        const store::Item_t& qname,
        const store::Item_t& aCollectionName);

  virtual void addActivateForeignKeyIC(
        const QueryLoc* aQueryLoc,
        const store::Item_t& qname,
        const store::Item_t& aFromCollectionName,
        const store::Item_t& aToCollectionName);

  virtual void addDeActivateIC(
        const QueryLoc* aQueryLoc,
        const store::Item_t& qname);

  // document primitives
  virtual void addCreateDocument(
        const QueryLoc* aQueryLoc,
        const store::Item_t& uri,
        store::Item_t& doc);

  virtual void addDeleteDocument(
        const QueryLoc* aQueryLoc,
        const store::Item_t& uri);

  // hash map primitives

  virtual void addCreateHashMap(
        const QueryLoc* aQueryLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKeyTypes,
        const std::vector<zstring>& aCollations,
        long  aTimezone);

  virtual void addDestroyHashMap(
        const QueryLoc* aQueryLoc,
        const store::Item_t& aQName);

  virtual void addInsertIntoHashMap(
        const QueryLoc* aQueryLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKey,
        const store::Iterator_t& aValue);

  virtual void addRemoveFromHashMap(
        const QueryLoc* aQueryLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKey);

  // merge
  void mergeUpdates(store::Item* other);

  // apply
  void applyUpdates(bool inheritNSBindings);

  // utils
  void checkTransformUpdates(const std::vector<store::Item*>& rootNodes) const;

  void getIndicesToRefresh(std::vector<store::Index*>& indices);

  void addIndexEntryCreator(
        const store::Item* collectionName,
        store::Index* idx,
        store::IndexEntryCreator* creator);

  void setValidator(store::SchemaValidator* validator);
  store::SchemaValidator* getValidator() const { return theValidator; }

  bool inheritNSBindings() const { return theInheritNSBindings; }

  // integrity constraints related
  void setICChecker(store::ICChecker* icChecker);

  void checkIC(const store::Item* collName);


protected:
  void mergeUpdateList(
        CollectionPul* myPul,
        std::vector<UpdatePrimitive*>& myList,
        std::vector<UpdatePrimitive*>& otherList,
        UpdListKind listKind);

  void addInsertChildren(
        const QueryLoc* aQueryLoc,
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t& target,
        store::Item_t& sibling,
        std::vector<store::Item_t>& children);

  CollectionPul* getCollectionPul(const store::Item* target);

  void undoUpdates();
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
