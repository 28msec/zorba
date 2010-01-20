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
  duplicate delete, rename, replaveValue, replaceContent, or replaceNode updates.
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

public:

  typedef std::vector<std::pair<store::Item_t, store::IndexKey*> > IndexDelta;

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

  std::vector<IndexDelta>            theBeforeIndexDeltas;
  std::vector<IndexDelta>            theAfterIndexDeltas;

public:
  CollectionPul(PULImpl* pul, SimpleCollection* collection);

  ~CollectionPul();

  void applyUpdates();

  void finalizeUpdates();

  void undoUpdates();

  void computeIndexDeltas(std::vector<IndexDelta>& deltas);

  void refreshIndices();

  void setAdjustTreePositions() { theAdjustTreePositions = true; }
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
    UP_LIST_CREATE_COLLECTION
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

  // Revalidation
  store::SchemaValidator           * theValidator;

  std::vector<UpdatePrimitive*>      theValidationList;


public:
  PULImpl();

  ~PULImpl();

  // XQUF primitives
  void addDelete(store::Item_t& n);

  void addInsertInto(
        store::Item_t& target,
        std::vector<store::Item_t>& children);

  void addInsertFirst(
        store::Item_t& target,
        std::vector<store::Item_t>& children);

  void addInsertLast(
        store::Item_t& target,
        std::vector<store::Item_t>& children);

  void addInsertBefore(
        store::Item_t& target,
        std::vector<store::Item_t>& siblings);

  void addInsertAfter(
        store::Item_t& target,
        std::vector<store::Item_t>& siblings);

  void addInsertAttributes(
        store::Item_t& target,
        std::vector<store::Item_t>& attrs);

  void addReplaceNode(
        store::Item_t& target,
        std::vector<store::Item_t>& replacementNodes);

  void addReplaceContent(
        store::Item_t& target,
        store::Item_t& newTextChild);

  void addReplaceValue(
        store::Item_t& target,
        xqpStringStore_t& newValue);

  void addRename(
        store::Item_t& target,
        store::Item_t& newName);

  void addPut(
        store::Item_t& node,
        store::Item_t& uri);

  // Revalidation primitives
  void addSetElementType(
        store::Item_t&               target,
        store::Item_t&               typeName,
        store::Item_t&               value,
        bool                         haveValue,
        bool                         haveEmptyValue,
        bool                         haveTypedValue,
        bool                         isInSubstitutionGroup);

  void addSetElementType(
        store::Item_t&               target,
        store::Item_t&               typeName,
        std::vector<store::Item_t>&  value,
        bool                         haveValue,
        bool                         haveEmptyValue,
        bool                         haveTypedValue,
        bool                         isInSubstitutionGroup);

  void addSetAttributeType(
        store::Item_t&               target,
        store::Item_t&               typeName,
        store::Item_t&               typedValue);

  void addSetAttributeType(
        store::Item_t&              target,
        store::Item_t&              typeName,
        std::vector<store::Item_t>& typedValue);

  // Collection primitives
  void addCreateCollection(
        store::Item_t& name);

  void addDeleteCollection(
        store::Item_t& name);

  void addInsertIntoCollection(
        store::Item_t& name,
        std::vector<store::Item_t>& nodes);

  void addInsertFirstIntoCollection(
        store::Item_t& name,
        std::vector<store::Item_t>& nodes);

  void addInsertLastIntoCollection(
        store::Item_t& name,
        std::vector<store::Item_t>& nodes);

  void addInsertBeforeIntoCollection(
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes);

  void addInsertAfterIntoCollection(
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes);

  void addDeleteFromCollection(
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isLast);

  // Index primitives
  void addCreateIndex(
        const store::Item_t& qname,
        const store::IndexSpecification& spec,
        store::Iterator* sourceIter);

  void addDeleteIndex(
        const store::Item_t& qname);

  void addRefreshIndex(
        const store::Item_t& qname,
        store::Iterator* sourceIter);

  virtual void addActivateIC(
        const store::Item_t& qname,
        const store::Item_t& aCollectionName);

  virtual void addActivateForeignKeyIC(
        const store::Item_t& qname,
        const store::Item_t& aFromCollectionName,
        const store::Item_t& aToCollectionName);

  virtual void addDeActivateIC(
        const store::Item_t& qname);

  // merge
  void mergeUpdates(store::Item* other);

  // apply
  void applyUpdates();

  // utils
  void checkTransformUpdates(const std::vector<store::Item*>& rootNodes) const;

  void getIndicesToRefresh(std::vector<store::Index*>& indices);

  void addIndexEntryCreator(
        const store::Item* collectionName,
        store::Index* idx,
        store::IndexEntryCreator* creator);

  void setValidator(store::SchemaValidator* validator);

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
