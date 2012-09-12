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

#include "shared_types.h"

#include "store/api/pul.h"
#include "simple_index.h"

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
class Collection;
class InternalNode;
class TextNode;


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
    static bool equal(const store::Item* n1, const store::Item* n2)
    {
      return n1 == n2;
    }

    static uint32_t hash(const store::Item* n)
    {
      return hashfun::h32((void*)(&n), sizeof(void*), FNV_32_INIT);
    }
  };

  typedef HashMap<store::Item*, NodeUpdates*, CompareFunction> Map;

  typedef Map::iterator iterator;

private:

  Map    theMap;
  csize  theNumDeletes;

public:
  NodeToUpdatesMap() : theMap(8, false), theNumDeletes(0)
  {
  }

  ~NodeToUpdatesMap();

  iterator begin() const { return theMap.begin(); }

  iterator end() const { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  bool get(store::Item* key, NodeUpdates*& value) { return theMap.get(key, value); }

  bool insert(store::Item* key, NodeUpdates* value) { return theMap.insert(key, value); }

  bool remove(store::Item* key) { return theMap.erase(key); }

  void clear() { theMap.clear(); }
};


/*******************************************************************************
  Class storing all update primitives involving a single collection, or no
  collection at all.

  theDoFirstList: 
  ---------------
  insertInto, insertAttributes, replaceValue, rename

  theInsertList:
  --------------
  insertBefore, insertAfter, insertIntoFirst, insertIntoLast

  theMergeToCheckSet:
  -------------------
  Nodes whose children might need to be merged 

********************************************************************************/
class CollectionPul
{
  friend class PULImpl;
  friend class UpdatePrimitive;
  friend class ElementNode;
  friend class AttributeNode;

  struct TextNodeMerge
  {
    InternalNode         * theParent;
    ulong                  thePos;
    std::vector<XmlNode_t> theMergedNodes;

    TextNodeMerge(InternalNode* aParent, ulong aPos)
      :
      theParent(aParent),
      thePos(aPos)
    {
    }
  };

protected:
  // Bookeeping
  Collection                       * theCollection;

  PULImpl                          * thePul;

  NodeToUpdatesMap                   theNodeToUpdatesMap;

  std::set<InternalNode*>            theMergeToCheckSet;
  std::vector<TextNodeMerge>         theMergeList;

  std::vector<UpdatePrimitive*>      thePrimitivesToRecheck;

  std::set<store::Item*>             theValidationNodes;

  store::PUL_t                       theValidationPul;

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
  std::vector<UpdatePrimitive*>      theTruncateCollectionList;
  std::vector<UpdatePrimitive*>      theDeleteCollectionList;

  // Validate in place primitives
  std::vector<UpdatePrimitive*>      theRevalidateList;

  // Index Maintenance
  std::set<store::Item*>             theModifiedDocs;
  std::vector<store::Item*>          theInsertedDocs;
  std::vector<store::Item*>          theDeletedDocs;

  std::vector<IndexImpl*>            theIncrementalIndices;
  std::vector<IndexImpl*>            theTruncatedIndices;

  std::vector<IndexEntryCreator_t>   theIndexEntryCreators;

  std::vector<IndexDeltaImpl>        theBeforeIndexDeltas;
  std::vector<IndexDeltaImpl>        theAfterIndexDeltas;
  std::vector<IndexDeltaImpl>        theInsertedDocsIndexDeltas;
  std::vector<IndexDeltaImpl>        theDeletedDocsIndexDeltas;

#ifdef ZORBA_WITH_JSON
  // jsoniq primitives
  std::vector<UpdatePrimitive*>      theJSONObjectInsertList;
  std::vector<UpdatePrimitive*>      theJSONObjectDeleteList;
  std::vector<UpdatePrimitive*>      theJSONObjectReplaceValueList;
  std::vector<UpdatePrimitive*>      theJSONObjectRenameList;

  std::vector<UpdatePrimitive*>      theJSONArrayInsertList;
  std::vector<UpdatePrimitive*>      theJSONArrayAppendList;
  std::vector<UpdatePrimitive*>      theJSONArrayDeleteList;
  std::vector<UpdatePrimitive*>      theJSONArrayReplaceValueList;
#endif

  std::vector<csize>                 theNumBeforeIndexDeltasApplied;
  std::vector<csize>                 theNumAfterIndexDeltasApplied;
  std::vector<csize>                 theNumInsertedDocsIndexDeltasApplied;
  std::vector<csize>                 theNumDeletedDocsIndexDeltasApplied;

public:
  CollectionPul(PULImpl* pul, Collection* collection);

  ~CollectionPul();

  void switchPul(PULImpl* pul);

  void computeIndexBeforeDeltas();

  void computeIndexAfterDeltas();

  void refreshIndexes();

  void applyUpdates();

  void undoUpdates();

  void finalizeUpdates();

  void setAdjustTreePositions() { theAdjustTreePositions = true; }

  void addToCheckForMerge(InternalNode* parent) { theMergeToCheckSet.insert(parent); }

protected:
  void switchPulInPrimitivesList(std::vector<UpdatePrimitive*>& list);

  void computeIndexDeltas(std::vector<IndexDeltaImpl>& deltas);

  void cleanIndexDeltas();

  void refreshValueIndex(csize idx);

  void refreshGeneralIndex(csize idx);

  void undoValueIndexRefresh(csize idx);

  void undoGeneralIndexRefresh(csize idx);

  void truncateIndexes();

  void undoRefreshIndexes();
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
  friend class UpdRevalidate;

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

  typedef std::vector<CollectionPul*> CollectionPuls;

  typedef std::map<const QNameItem*, csize> CollectionPulMap;

protected:
  // XQUF and collection primitives, grouped by the collection that is being updated.
  CollectionPuls                     theCollectionPuls;
  CollectionPulMap                   theCollectionPulsMap;
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
        store::Item_t& target,
        store::Item_t& typeName,
        store::Item_t& value,
        bool haveValue,
        bool haveEmptyValue,
        bool haveTypedValue,
        bool isInSubstitutionGroup);

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

  void addRevalidate(
          const QueryLoc* aQueryLoc,
          store::Item_t&              target);

  // Collection primitives
  void addCreateCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        const std::vector<store::Annotation_t>& annotations,
        const store::Item_t& nodeType,
        bool isDynamic);

  void addDeleteCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        bool isDynamic);

  void addInsertIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isDynamic);

  void addInsertFirstIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isDynamic);

  void addInsertLastIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isDynamic);

  void addInsertBeforeIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes,
        bool isDynamic);

  void addInsertAfterIntoCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes,
        bool isDynamic);

  void addDeleteFromCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isLast,
        bool isDynamic);

  void addTruncateCollection(
        const QueryLoc* aQueryLoc,
        store::Item_t& name,
        bool isDynamic);

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

#ifdef ZORBA_WITH_JSON
  // jsoniq primitives

  virtual void addJSONObjectInsert(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      std::vector<store::Item_t>& names,
      std::vector<store::Item_t>& values);

  virtual void addJSONObjectDelete(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& name);

  virtual void addJSONObjectReplaceValue(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& name,
      store::Item_t& newValue);

  virtual void addJSONObjectRename(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& name,
      store::Item_t& newName);

  virtual void addJSONArrayInsert(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& pos,
      std::vector<store::Item_t>& members);

  virtual void addJSONArrayAppend(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      std::vector<store::Item_t>& members);

  virtual void addJSONArrayDelete(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& pos);

  virtual void addJSONArrayReplaceValue(
      const QueryLoc* aQueryLoc,
      store::Item_t& target,
      store::Item_t& pos,
      store::Item_t& newValue);
#endif

  // merge
  void mergeUpdates(store::Item* other);

  // apply
  void applyUpdates(bool inheritNSBindings);

  // utils
  void checkTransformUpdates(const std::vector<store::Item*>& rootNodes) const;

  void getIndicesToRefresh(
      std::vector<store::Index*>& indices,
      std::vector<store::Index*>& truncate_indices);

  void addIndexEntryCreator(
        const store::Item* collectionName,
        store::Index* idx,
        store::IndexEntryCreator* creator);

  void addIndexTruncator(
      const store::Item* collectionName,
      store::Index* idx);

  void setValidator(store::SchemaValidator* validator);

  store::SchemaValidator* getValidator() const { return theValidator; }

  bool inheritNSBindings() const { return theInheritNSBindings; }

  // integrity constraints related
  void setICChecker(store::ICChecker* icChecker);

  void checkIC(const store::Item* collName);


protected:
  void mergeTargetedUpdateLists(
      CollectionPul* myPul,
      std::vector<UpdatePrimitive*>& myList,
      std::vector<UpdatePrimitive*>& otherList);

  void mergeCollectionUpdateLists(
      CollectionPul* myPul,
      std::vector<UpdatePrimitive*>& myList,
      std::vector<UpdatePrimitive*>& otherList);
    
  void mergeSimpleUpdateLists(
      std::vector<UpdatePrimitive*>& myList,
      std::vector<UpdatePrimitive*>& otherList);

  void addInsertChildren(
        const QueryLoc* loc,
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t& target,
        store::Item_t& sibling,
        std::vector<store::Item_t>& children);

  CollectionPul* getCollectionPul(const store::Item* target);

  CollectionPul* getCollectionPulByName(const store::Item* name, bool isDynamic);

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
