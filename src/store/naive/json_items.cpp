/*
 * Copyright 2006-2011 The FLWOR Foundation.
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

#include "json_items.h"
#include "simple_item_factory.h"
#include "simple_store.h"
#include "item_iterator.h"

#include "store/api/copymode.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include "util/mem_sizeof.h"

namespace zorba
{

namespace simplestore
{

namespace json
{

/******************************************************************************

*******************************************************************************/
store::Item* JSONNull::getType() const
{
  return GET_STORE().JDM_NULL_QNAME;
}


/******************************************************************************

*******************************************************************************/
bool JSONNull::equals(
    const store::Item* other,
    long /* timezone */,
    const XQPCollator* /* collation */) const
{
  return other->getTypeCode() == store::JDM_NULL;
}


/******************************************************************************

*******************************************************************************/
uint32_t JSONNull::hash(long /* tmz */, const XQPCollator* /* collation */) const
{
  const void* tmp = this; // there is only one instance in the store
  return hashfun::h32(&tmp, sizeof(void*), FNV_32_INIT);
}


/******************************************************************************

*******************************************************************************/
void JSONNull::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  iter = NULL;
  val = this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  JSON Item                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/******************************************************************************

*******************************************************************************/
JSONItem::~JSONItem()
{
  delete theTree;
}


/******************************************************************************

*******************************************************************************/
void JSONItem::free()
{
  destroy();
}


/******************************************************************************

*******************************************************************************/
void JSONItem::destroy()
{
  delete this;
}


/******************************************************************************

*******************************************************************************/
const simplestore::Collection* JSONItem::getCollection() const
{
  if (theTree == NULL)
  {
    return NULL;
  }
  return theTree->getCollection();
}


/******************************************************************************
  Should only to be called if item is in a collection.
*******************************************************************************/
const TreeId& JSONItem::getTreeId() const
{
  ZORBA_ASSERT(theTree);
  return theTree->getTreeId();
}


/******************************************************************************
  Should only to be called if item is in a collection.
*******************************************************************************/
JSONItem* JSONItem::getRoot() const
{
  ZORBA_ASSERT(theTree);
  return theTree->getRoot();
}


/*******************************************************************************

********************************************************************************/
void JSONItem::attachToCollection(Collection* aCollection, const TreeId& aTreeId)
{
  ASSERT_INVARIANT();
  
  assert(aCollection);

  // Attach
  assert(getTree() == NULL);
  setTree(new JSONTree());
  getTree()->setRoot(this);
  getTree()->setCollection(aCollection);
  getTree()->setTreeId(aTreeId);
  
  ASSERT_INVARIANT();
}

/*******************************************************************************

********************************************************************************/
void JSONItem::detachFromCollection()
{
  ASSERT_INVARIANT();
  
  JSONTree* lTree = getTree();
  // Detach
  assert(lTree);
  delete lTree;
  setTree(NULL);

  ASSERT_INVARIANT();
}

#ifndef NDEBUG
/******************************************************************************

*******************************************************************************/
void JSONItem::assertInvariant() const
{
  if (theTree != NULL)
  {
    assert(theTree->getCollection() != NULL);
    assert(theTree->getRoot() != NULL);
    assert(isThisTreeOfAllDescendants(theTree));
    assert(theTree->getRoot()->isThisJSONItemInDescendance(this));
  }
}
#endif


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Object                                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
store::Item* JSONObject::getType() const
{
  return GET_STORE().JDM_OBJECT_QNAME;
}


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::~SimpleJSONObject()
{
  ASSERT_INVARIANT();
  for (Pairs::iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lName = lIter->first;
    store::Item* lChild = lIter->second;
    if (getCollection() != NULL && lChild->isJSONItem())
    {
      assert(dynamic_cast<JSONItem*>(lChild));
      JSONItem* lJSONItem = static_cast<JSONItem*>(lChild);
      lJSONItem->setTree(NULL);
    }
    lName->removeReference();
    lChild->removeReference();
  }
  theKeys.clear();
  thePairs.clear();
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/

size_t SimpleJSONObject::alloc_size() const
{
  return  ztd::alloc_sizeof( theKeys )
        + ztd::alloc_sizeof( thePairs );
}

/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONObject::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
  ASSERT_INVARIANT();
  SimpleJSONObject* lNewObject = const_cast<SimpleJSONObject*>(this);
 
 if (copymode.theDoCopy)
  {
    lNewObject = new SimpleJSONObject();

    for (Pairs::const_iterator lIter = thePairs.begin();
         lIter != thePairs.end();
         ++lIter)
    {
      store::Item_t lKey = lIter->first;
      store::Item_t lValue = lIter->second;
      
      if (lValue->isJSONObject() ||
          lValue->isJSONArray() ||
          lValue->isNode())
      {
        store::Item_t lCopiedValue = lValue->copy(NULL, copymode);
        lNewObject->add(lKey, lCopiedValue, false);
      }
      else
      {
        lNewObject->add(lKey, lValue, false);
      }
    }
  }

  if (parent)
  {
    assert(parent->isJSONArray());
    assert(dynamic_cast<JSONArray*>(parent));
    JSONArray* a = static_cast<JSONArray*>(parent);

    a->push_back(lNewObject);
  }
  
  return lNewObject;
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::add(
    const store::Item_t& aName,
    const store::Item_t& aValue,
    bool accumulate)
{
  ASSERT_INVARIANT();
  zstring lName = aName->getStringValue();

  Keys::iterator ite = theKeys.find(lName);

  if (ite == theKeys.end())
  {
    store::Item* lValue = aValue.getp();

    if (getCollection() != NULL && aValue->isJSONItem())
    {
      assert(dynamic_cast<JSONItem*>(aValue.getp()));
      JSONItem* lJSONItem = static_cast<JSONItem*>(aValue.getp());
      lJSONItem->setTree(getTree());
    }
    
    csize lPosition = thePairs.size();
    theKeys.insert(lName, lPosition);
    thePairs.push_back(std::make_pair(aName.getp(), lValue));
    aName->addReference();
    lValue->addReference();

    ASSERT_INVARIANT();
    return true;
  }
  else if (accumulate)
  {
    csize lPosition = ite.getValue();

    assert(thePairs[lPosition].first->getStringValue() == lName);

    store::Item* lValue = thePairs[lPosition].second;

    if (lValue->isJSONArray())
    {
      static_cast<SimpleJSONArray*>(lValue)->push_back(aValue);
    }
    else
    {
      SimpleJSONArray_t array = new SimpleJSONArray();
      array->push_back(lValue);
      array->push_back(aValue);

      if (getCollection() != NULL)
      {
        array->setTree(getTree());
      }

      lValue->removeReference();
      array->addReference();
      thePairs[lPosition].second = array;
    }
    ASSERT_INVARIANT();
    return true;
  }

  ASSERT_INVARIANT();
  return false;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::remove(const store::Item_t& aName)
{
  ASSERT_INVARIANT();

  zstring lName = aName->getStringValue();
  csize lPosition = 0;
  store::Item_t lValue;

  if (!theKeys.get(lName, lPosition))
  {
    ASSERT_INVARIANT();
    return 0;
  }
  
  store::Item* lKey;

  lKey = thePairs[lPosition].first;
  lValue = thePairs[lPosition].second;

  if (getCollection() != NULL && lValue->isJSONItem())
  {
    assert(dynamic_cast<JSONItem*>(lValue.getp()));
    JSONItem* lJSONItem = static_cast<JSONItem*>(lValue.getp());
    lJSONItem->setTree(NULL);
  }

  lKey->removeReference();
  lValue->removeReference();

  thePairs.erase(thePairs.begin() + lPosition);
  theKeys.erase(lName);

  if (lPosition < thePairs.size())
  {
    Keys::iterator lKeysIte = theKeys.begin();
    Keys::iterator lKeysEnd = theKeys.end();
    for (; lKeysIte != lKeysEnd; ++lKeysIte)
    {
      csize lPos = lKeysIte.getValue();
      if (lPos > lPosition)
      {
        lKeysIte.setValue(lPos - 1);
      }
    }
  }

  ASSERT_INVARIANT();
  return lValue;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::setValue(
    const store::Item_t& aName,
    const store::Item_t& aValue)
{
  ASSERT_INVARIANT();
  zstring lName = aName->getStringValue();
  csize lPosition = 0;

  if (!theKeys.get(lName, lPosition))
  {
    ASSERT_INVARIANT();
    return NULL;
  }

  assert(thePairs[lPosition].first->getStringValue() == lName);

  store::Item_t lOldValue = thePairs[lPosition].second;

  if (getCollection() != NULL)
  {
    if (lOldValue->isJSONItem())
    {
      assert(dynamic_cast<JSONItem*>(lOldValue.getp()));
      JSONItem* lJSONItem = static_cast<JSONItem*>(lOldValue.getp());
      lJSONItem->setTree(NULL);
    }

    if (aValue->isJSONItem())
    {
      assert(dynamic_cast<JSONItem*>(aValue.getp()));
      JSONItem* lJSONItem = static_cast<JSONItem*>(aValue.getp());
      lJSONItem->setTree(getTree());
    }
  }

  lOldValue->removeReference();
  aValue->addReference();
  thePairs[lPosition].second = aValue.getp();

  ASSERT_INVARIANT();
  return lOldValue;
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::rename(
    const store::Item_t& aName,
    const store::Item_t& aNewName)
{
  ASSERT_INVARIANT();
  zstring lName = aName->getStringValue();
  zstring lNewName = aNewName->getStringValue();

  if (theKeys.exists(lNewName))
  {
    ASSERT_INVARIANT();
    return false;
  }

  Keys::iterator ite = theKeys.find(lName);

  if (ite == theKeys.end())
  {
    ASSERT_INVARIANT();
    return false;
  }

  csize lPosition = ite.getValue();
  assert(thePairs[lPosition].first->getStringValue() == lName);
  
  thePairs[lPosition].first->removeReference();
  aNewName->addReference();
  thePairs[lPosition].first = aNewName.getp();
  theKeys.erase(ite);
  theKeys.insert(lNewName, lPosition);

  ASSERT_INVARIANT();
  return true;
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::setTree(JSONTree* aTree)
{
  theTree = aTree;

  for (Pairs::iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    if (lValue->isJSONItem())
    {
      assert(dynamic_cast<JSONItem*>(lValue));
      JSONItem* lJSONItem = static_cast<JSONItem*>(lValue);
      lJSONItem->setTree(aTree);
    }
  }
}


/******************************************************************************

*******************************************************************************/
zstring SimpleJSONObject::getStringValue() const
{
  ASSERT_INVARIANT();
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::getStringValue2(zstring& val) const
{
  ASSERT_INVARIANT();
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::appendStringValue(zstring& buf) const
{
  ASSERT_INVARIANT();
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  ASSERT_INVARIANT();
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::getObjectValue(const store::Item_t& aKey) const
{
  ASSERT_INVARIANT();
  zstring lName = aKey->getStringValue();

  csize lPosition = 0;
  if (!theKeys.get(lName, lPosition))
  {
    return NULL;
  }

  assert(thePairs[lPosition].first->equals(aKey));
  return thePairs[lPosition].second;
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t SimpleJSONObject::getObjectKeys() const
{
  ASSERT_INVARIANT();
  return new KeyIterator(const_cast<SimpleJSONObject*>(this));
}


#ifndef NDEBUG

/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::assertInvariant() const
{
  JSONItem::assertInvariant();
  assert(theKeys.size() == thePairs.size());

  for(Keys::iterator lIter = theKeys.begin();
      lIter != theKeys.end();
      ++lIter)
  {
    csize lPosition = lIter.getValue();
    assert(lPosition < thePairs.size());
    assert(thePairs[lPosition].first != NULL);
    assert(thePairs[lPosition].first->isAtomic());
    assert(thePairs[lPosition].first->getStringValue() == lIter.getKey());
    assert(thePairs[lPosition].second != NULL);
  }
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::isThisTreeOfAllDescendants(const JSONTree* aTree) const
{
  if (theTree != aTree)
  {
    return false;
  }

  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    const JSONItem* lJSONItem = dynamic_cast<const JSONItem*>(lValue);
    if (lJSONItem != NULL && (!lJSONItem->isThisTreeOfAllDescendants(aTree)))
    {
      return false;
    }
  }
  return true;
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::isThisJSONItemInDescendance(const store::Item* anItem) const
{
  if (this == anItem)
  {
    return true;
  }

  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    store::Item* lValue = lIter->second;
    const SimpleJSONObject* lObject =
      dynamic_cast<const SimpleJSONObject*>(lValue);
    const SimpleJSONArray* lArray =
      dynamic_cast<const SimpleJSONArray*>(lValue);
 
    if (lObject != NULL && lObject->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
    else if (lArray != NULL && lArray->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
  }
  return false;
}
#endif // NDEBUG


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::KeyIterator::~KeyIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::open()
{
  theIter = theObject->thePairs.begin();
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::KeyIterator::next(store::Item_t& res)
{
  if (theIter != theObject->thePairs.end())
  {
    res = theIter->first;
    ++theIter;
    return true;
  }
  else
  {
    return false;
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::KeyIterator::close()
{
  theIter = theObject->thePairs.end();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Array                                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
store::Item* JSONArray::getType() const
{
  return GET_STORE().JDM_ARRAY_QNAME;
}


/******************************************************************************

*******************************************************************************/
SimpleJSONArray::~SimpleJSONArray()
{
  ASSERT_INVARIANT();
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    if (getCollection() != NULL && (*lIter)->isJSONItem())
    {
      assert(dynamic_cast<JSONItem*>(*lIter));
      JSONItem* lJSONItem = static_cast<JSONItem*>(*lIter);
      lJSONItem->setTree(NULL);
    }
    (*lIter)->removeReference();
  }
}


/******************************************************************************

*******************************************************************************/

size_t SimpleJSONArray::alloc_size() const
{
  return ztd::alloc_sizeof( theContent );
}

/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_back(const store::Item_t& aValue)
{
  ASSERT_INVARIANT();

  if (getCollection() != NULL && aValue->isJSONItem())
  {
    assert(dynamic_cast<JSONItem*>(aValue.getp()));
    JSONItem* lJSONItem = static_cast<JSONItem*>(aValue.getp());
    lJSONItem->setTree(getTree());
  }

  aValue->addReference();
  theContent.push_back(aValue.getp());

  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_back(const std::vector<store::Item_t>& members)
{
  ASSERT_INVARIANT();
  theContent.reserve(theContent.size() + members.size());
  add(theContent.size(), members);
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::push_front(const std::vector<store::Item_t>& members)
{
  ASSERT_INVARIANT();
  theContent.reserve(theContent.size() + members.size());
  add(0, members);
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_before(
    const xs_integer& pos,
    const store::Item_t& member)
{
  ASSERT_INVARIANT();

  if (getCollection() != NULL && member->isJSONItem())
  {
    assert(dynamic_cast<JSONItem*>(member.getp()));
    JSONItem* lJSONItem = static_cast<JSONItem*>(member.getp());
    lJSONItem->setTree(getTree());
  }

  member->addReference();
  theContent.insert(theContent.begin() + (cast(pos) - 1), member.getp());

  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_before(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
  ASSERT_INVARIANT();
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos) - 1, members);

  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::insert_after(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
  ASSERT_INVARIANT();
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos), members);
  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::add(
    uint64_t aTargetPos,
    const std::vector<store::Item_t>& aNewMembers)
{
  ASSERT_INVARIANT();
  for (size_t i = 0; i < aNewMembers.size(); ++i)
  {
    store::Item* lItem = aNewMembers[i].getp();

    if (getCollection() != NULL && lItem->isJSONItem())
    {
      assert(dynamic_cast<JSONItem*>(lItem));
      JSONItem* lJSONItem = static_cast<JSONItem*>(lItem);
      lJSONItem->setTree(getTree());
    }

    lItem->addReference();
    theContent.insert(theContent.begin() + aTargetPos + i, lItem);
  }

  ASSERT_INVARIANT();
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::remove(const xs_integer& aPos)
{
  ASSERT_INVARIANT();
  store::Item_t lItem = getArrayValue(aPos);

  if (getCollection() != NULL && lItem->isJSONItem())
  {
    assert(dynamic_cast<JSONItem*>(lItem.getp()));
    JSONItem* lJSONItem = static_cast<JSONItem*>(lItem.getp());
    lJSONItem->setTree(NULL);
  }

  lItem->removeReference();
  uint64_t lPosStartingZero = cast(aPos) - 1;
  theContent.erase(theContent.begin() + lPosStartingZero);

  ASSERT_INVARIANT();
  return lItem;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::replace(
    const xs_integer& aPos,
    const store::Item_t& value)
{
  ASSERT_INVARIANT();
  store::Item_t lItem = getArrayValue(aPos);

  if (getCollection() != NULL && lItem->isJSONItem())
  {
    assert(dynamic_cast<JSONItem*>(lItem.getp()));
    JSONItem* lJSONItem = static_cast<JSONItem*>(lItem.getp());
    lJSONItem->setTree(NULL);
  }

  uint64_t pos = cast(aPos) - 1;

  if (getCollection() != NULL && value->isJSONItem())
  {
    assert(dynamic_cast<JSONItem*>(value.getp()));
    JSONItem* lJSONItem = static_cast<JSONItem*>(value.getp());
    lJSONItem->setTree(getTree());
  }

  theContent[pos]->removeReference();
  value->addReference();
  theContent[pos] = value.getp();
  
  ASSERT_INVARIANT();
  return lItem;
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::setTree(JSONTree* aTree)
{
  theTree = aTree;

  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    store::Item* lValue = *lIter;
    if (lValue->isJSONItem())
    {
      assert(dynamic_cast<JSONItem*>(lValue));
      JSONItem* lJSONItem = static_cast<JSONItem*>(lValue);
      lJSONItem->setTree(aTree);
    }
  }
}


/******************************************************************************

*******************************************************************************/
uint64_t SimpleJSONArray::cast(const xs_integer& i)
{
  try 
  {
    return to_xs_unsignedLong(i);
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONArray::getArrayValue(const xs_integer& aPosition) const
{
  ASSERT_INVARIANT();
  uint64_t lPos = cast(aPosition);

  if (lPos == 0 || lPos > theContent.size())
  {
    return 0;
  }
  else
  {
    return theContent[lPos-1];
  }
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t SimpleJSONArray::getArrayValues() const
{
  ASSERT_INVARIANT();
  return new ValuesIterator(const_cast<SimpleJSONArray*>(this));
}


/******************************************************************************

*******************************************************************************/
xs_integer SimpleJSONArray::getArraySize() const
{
  ASSERT_INVARIANT();
  store::Item_t lRes;
  xs_integer lSize(theContent.size());
  return lSize;
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONArray::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
  ASSERT_INVARIANT();
  SimpleJSONArray* lNewArray = const_cast<SimpleJSONArray*>(this);

  if (copymode.theDoCopy)
  {
    lNewArray = new SimpleJSONArray();
    lNewArray->theContent.reserve(theContent.size());

    for (Members::const_iterator lIter = theContent.begin();
         lIter != theContent.end();
         ++lIter)
    {
      store::Item_t lValue = *lIter;

      if (lValue->isJSONObject() ||
          lValue->isJSONArray() ||
          lValue->isNode())
      {
        lValue = lValue->copy(NULL, copymode);
      }

      lNewArray->push_back(lValue);
    }
  }

  if (parent)
  {
    assert(parent->isJSONArray());
    JSONArray* a = static_cast<JSONArray*>(parent);
    a->push_back(lNewArray);
  }

  return lNewArray;
}


/******************************************************************************

*******************************************************************************/
zstring SimpleJSONArray::getStringValue() const
{
  ASSERT_INVARIANT();
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("array"));
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::getStringValue2(zstring& val) const
{
  ASSERT_INVARIANT();
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::appendStringValue(zstring& buf) const
{
  ASSERT_INVARIANT();
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  ASSERT_INVARIANT();
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("array"));
}


#ifndef NDEBUG

/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::isThisTreeOfAllDescendants(const JSONTree* aTree) const
{
  if (getTree() != aTree)
  {
    return false;
  }

  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    store::Item* lValue = (*lIter);
    const JSONItem* lJSONItem = dynamic_cast<const JSONItem*>(lValue);
    if (lJSONItem != NULL && (!lJSONItem->isThisTreeOfAllDescendants(aTree)))
    {
      return false;
    }
  }
  return true;
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::isThisJSONItemInDescendance(const store::Item* anItem) const
{
  if(this == anItem)
  {
    return true;
  }
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(*lIter);
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(*lIter);
    if (lObject != NULL && lObject->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
    else if (lArray != NULL && lArray->isThisJSONItemInDescendance(anItem))
    {
      return true;
    }
  }
  return false;
}

#endif // NDEBUG


/******************************************************************************

*******************************************************************************/
SimpleJSONArray::ValuesIterator::~ValuesIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::open()
{
  theIter = theArray->theContent.begin();
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::ValuesIterator::next(store::Item_t& res)
{
  if (theIter != theArray->theContent.end())
  {
    res = *theIter;
    ++theIter;
    return true;
  }
  else
  {
    return false;
  }
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::ValuesIterator::close()
{
  theIter = theArray->theContent.end();
}




} // namespace json
} // namespace simplestore
} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
