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

namespace zorba
{

namespace simplestore
{

namespace json
{

/******************************************************************************

*******************************************************************************/
store::Item*
JSONNull::getType() const
{
  return GET_STORE().JDM_NULL_QNAME;
}


/******************************************************************************

*******************************************************************************/
bool
JSONNull::equals(
      const store::Item* other,
      long /* timezone */,
      const XQPCollator* /* collation */) const
{
  return other->getTypeCode() == store::JDM_NULL;
}


/******************************************************************************

*******************************************************************************/
uint32_t
JSONNull::hash(long /* timezone */, const XQPCollator* /* aCollation */) const
{
  const void* tmp = this; // there is only one instance in the store
  return hashfun::h32(&tmp, sizeof(void*), FNV_32_INIT);
}


/******************************************************************************

*******************************************************************************/
void
JSONNull::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  iter = NULL;
  val = this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Object                                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
store::Item*
JSONObject::getType() const
{
  return GET_STORE().JDM_OBJECT_QNAME;
}

void setJSONRoot(const store::Item_t& aJSONItem, const JSONItem* aRoot)
{
    SimpleJSONObject* lObject =
        dynamic_cast<SimpleJSONObject*>(aJSONItem.getp());
    SimpleJSONArray* lArray =
        dynamic_cast<SimpleJSONArray*>(aJSONItem.getp());
    if (lObject != NULL)
    {
      ZORBA_ASSERT(aRoot == lObject ||
                   lObject->theRoot == lObject);
      lObject->setRoot(aRoot);
    }
    else if (lArray != NULL)
    {
      ZORBA_ASSERT(aRoot == lArray ||
                   lArray->theRoot == lArray);
      lArray->setRoot(aRoot);
    }
}

/******************************************************************************

*******************************************************************************/
SimpleJSONObject::~SimpleJSONObject()
{
#ifndef NDEBUG
  assertInvariant();
#endif
  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    if (lIter->second->isJSONItem()) {
      JSONItem* lJSONItem = dynamic_cast<JSONItem*>(lIter->second.getp());
      ZORBA_ASSERT(lJSONItem != NULL);
      setJSONRoot(lIter->second, lJSONItem);
    }
  }
  thePairs.clear();
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONObject::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  SimpleJSONObject* lNewObject = const_cast<SimpleJSONObject*>(this);
  if (copymode.theDoCopy)
  {
    lNewObject = new SimpleJSONObject();

    for (Pairs::const_iterator lIter = thePairs.begin();
         lIter != thePairs.end();
         ++lIter)
    {
      zstring lName = lIter->first;
      store::Item_t lValue = lIter->second;
      if (copymode.theDoCopy &&
          (lValue->isJSONObject() ||
           lValue->isJSONArray() ||
           lValue->isNode()))
      {
        store::Item_t lCopiedValue = lValue->copy(NULL, copymode);
        lNewObject->add(lName, lCopiedValue, false);
      } else {
        lNewObject->add(lName, lValue, false);
      }
    }
  }

  if (parent)
  {
    JSONArray* a = dynamic_cast<JSONArray*>(parent);
    ZORBA_ASSERT(a != NULL);
    a->push_back(lNewObject);
  }
  
  return lNewObject;
}


/*******************************************************************************

********************************************************************************/
void
SimpleJSONObject::setCollection(SimpleCollection* collection, xs_integer /*pos*/)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
bool
SimpleJSONObject::add(
      const zstring& aName,
      const store::Item_t& aValue,
      bool accumulate)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  Pairs::iterator lIterator = thePairs.find(aName);

  if (lIterator == thePairs.end())
  {  
    store::Item_t lValue = aValue;
    setJSONRoot(aValue, theRoot);
    thePairs.insert(make_pair(aName, lValue));
#ifndef NDEBUG
    assertInvariant();
#endif
    return true;
  }
  else if (accumulate)
  {
    store::Item* value = lIterator->second.getp();

    if (value->isJSONArray())
    {
      static_cast<SimpleJSONArray*>(value)->push_back(aValue);
    }
    else
    {
      SimpleJSONArray_t array = new SimpleJSONArray();
      array->push_back(value);
      array->push_back(aValue);

      setJSONRoot(array, theRoot);
      lIterator->second = array;
    }
#ifndef NDEBUG
    assertInvariant();
#endif
    return true;
  }

#ifndef NDEBUG
  assertInvariant();
#endif
  return false;
}


/******************************************************************************

*******************************************************************************/
store::Item_t
SimpleJSONObject::remove(const zstring& aName)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  Pairs::iterator lIter = thePairs.find(aName);
  if (lIter == thePairs.end())
  {
#ifndef NDEBUG
    assertInvariant();
#endif
    return 0;
  }
  
  store::Item_t lRes = lIter->second;
  if (lRes->isJSONItem()) {
    JSONItem* lJSONItem = dynamic_cast<JSONItem*>(lRes.getp());
    ZORBA_ASSERT(lJSONItem != NULL);
    setJSONRoot(lRes, lJSONItem);
  }
  thePairs.erase(aName);

#ifndef NDEBUG
  assertInvariant();
#endif
  return lRes;
}


/******************************************************************************

*******************************************************************************/
store::Item_t SimpleJSONObject::setValue(
    const zstring& aName,
    const store::Item_t& aValue)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  Pairs::iterator lIter = thePairs.find(aName);
  if (lIter == thePairs.end()) {
#ifndef NDEBUG
    assertInvariant();
#endif
    return NULL;
  }

  store::Item_t lRes = lIter->second;
  if (lRes->isJSONItem()) {
    JSONItem* lJSONItem = dynamic_cast<JSONItem*>(lRes.getp());
    ZORBA_ASSERT(lJSONItem != NULL);
    setJSONRoot(lRes, lJSONItem);
  }
  setJSONRoot(aValue, theRoot);
  lIter->second = aValue;
#ifndef NDEBUG
  assertInvariant();
#endif
  return lRes;
}

/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::rename(
    const zstring& aName,
    const zstring& aNewName)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  Pairs::iterator lIter = thePairs.find(aNewName);
  if (lIter != thePairs.end()) {
#ifndef NDEBUG
    assertInvariant();
#endif
    return false;
  }
  
  lIter = thePairs.find(aName);
  if (lIter == thePairs.end()) {
#ifndef NDEBUG
    assertInvariant();
#endif
    return false;
  }
  store::Item_t lValue = lIter->second;
  if (lValue->isJSONItem()) {
    JSONItem* lJSONItem = dynamic_cast<JSONItem*>(lValue.getp());
    ZORBA_ASSERT(lJSONItem != NULL);
    setJSONRoot(lValue, lJSONItem);
  }
  thePairs.erase(aName);
  
  thePairs.insert(make_pair(aNewName, lValue));

#ifndef NDEBUG
  assertInvariant();
#endif
  return true;
}

/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::setRoot(const JSONItem* aRoot)
{
  theRoot = aRoot;
  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    SimpleJSONObject* lObject =
        dynamic_cast<SimpleJSONObject*>(lIter->second.getp());
    SimpleJSONArray* lArray =
        dynamic_cast<SimpleJSONArray*>(lIter->second.getp());
    if (lObject != NULL)
    {
      lObject->setRoot(aRoot);
    }
    else if (lArray != NULL)
    {
      lArray->setRoot(aRoot);
    }
  }
}


/******************************************************************************

*******************************************************************************/
zstring
SimpleJSONObject::getStringValue() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::getStringValue2(zstring& val) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::appendStringValue(zstring& buf) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
store::Item_t
SimpleJSONObject::getObjectValue(const zstring& aKey) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  Pairs::const_iterator lIter = thePairs.find(aKey);
  if (lIter == thePairs.end())
  {
    return NULL;
  }
  return lIter->second;
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t
SimpleJSONObject::getObjectKeys() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  return new KeyIterator(const_cast<SimpleJSONObject*>(this));
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONObject::assertInvariant() const
{
  ZORBA_ASSERT(theRoot != NULL);
  const SimpleJSONObject* lObject = dynamic_cast<const SimpleJSONObject*>(theRoot);
  const SimpleJSONArray* lArray = dynamic_cast<const SimpleJSONArray*>(theRoot);
  ZORBA_ASSERT(lObject != NULL || lArray != NULL);
  if (lObject != NULL) {
    ZORBA_ASSERT(lObject->isThisRootOfAllDescendants(theRoot));
    ZORBA_ASSERT(lObject->isThisJSONItemInDescendance(this));
  } else {
    ZORBA_ASSERT(lArray->isThisRootOfAllDescendants(theRoot));
    ZORBA_ASSERT(lArray->isThisJSONItemInDescendance(this));
  }
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::isThisRootOfAllDescendants(const store::Item* aRoot) const
{
  if(theRoot != aRoot)
  {
    return false;
  }
  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(lIter->second.getp());
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(lIter->second.getp());
    if (lObject != NULL && (!lObject->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
    else if (lArray != NULL && (!lArray->isThisRootOfAllDescendants(aRoot)))
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
  if(this == anItem)
  {
    return true;
  }
  for (Pairs::const_iterator lIter = thePairs.begin();
       lIter != thePairs.end();
       ++lIter)
  {
    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(lIter->second.getp());
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(lIter->second.getp());
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


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::KeyIterator::~KeyIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::KeyIterator::open()
{
  theIter = theObject->thePairs.begin();
}


/******************************************************************************

*******************************************************************************/
bool
SimpleJSONObject::KeyIterator::next(store::Item_t& res)
{
  if (theIter != theObject->thePairs.end())
  {
    zstring lKey = theIter->first;
    GET_FACTORY().createString(res, lKey);
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
void
SimpleJSONObject::KeyIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::KeyIterator::close()
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
store::Item*
JSONArray::getType() const
{
  return GET_STORE().JDM_ARRAY_QNAME;
}


/******************************************************************************

*******************************************************************************/
SimpleJSONArray::~SimpleJSONArray()
{
#ifndef NDEBUG
  assertInvariant();
#endif
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    if ((*lIter)->isJSONItem()) {
      JSONItem* lJSONItem = dynamic_cast<JSONItem*>((*lIter).getp());
      ZORBA_ASSERT(lJSONItem != NULL);
      setJSONRoot(*lIter, lJSONItem);
    }
  }
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::push_back(const store::Item_t& aValue)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  setJSONRoot(aValue, theRoot);
  theContent.push_back(aValue.getp());
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::push_back(const std::vector<store::Item_t>& members)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  theContent.reserve(theContent.size() + members.size());
  add(theContent.size(), members);
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::push_front(const std::vector<store::Item_t>& members)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  theContent.reserve(theContent.size() + members.size());
  add(0, members);
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::insert_before(const xs_integer& pos, const store::Item_t& member)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  setJSONRoot(member, theRoot);
  theContent.insert(theContent.begin() + (cast(pos) - 1), member.getp());
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::insert_before(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos) - 1, members);
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::insert_after(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos), members);
#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::add(
    uint64_t aTargetPos,
    const std::vector<store::Item_t>& aNewMembers)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  for (size_t i = 0; i < aNewMembers.size(); ++i)
  {
    store::Item* lItem = aNewMembers[i].getp();
    setJSONRoot(lItem, theRoot);
    theContent.insert(theContent.begin() + aTargetPos + i, lItem);
  }

#ifndef NDEBUG
  assertInvariant();
#endif
}


/******************************************************************************

*******************************************************************************/
store::Item_t
SimpleJSONArray::remove(const xs_integer& aPos)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  store::Item_t lItem = getArrayValue(aPos);
  if (lItem->isJSONItem()) {
    JSONItem* lJSONItem = dynamic_cast<JSONItem*>(lItem.getp());
    ZORBA_ASSERT(lJSONItem != NULL);
    setJSONRoot(lItem, lJSONItem);
  }
  uint64_t lPosStartingZero = cast(aPos) - 1;
  theContent.erase(theContent.begin() + lPosStartingZero);

#ifndef NDEBUG
  assertInvariant();
#endif
  return lItem;
}


/******************************************************************************

*******************************************************************************/
store::Item_t
SimpleJSONArray::replace(const xs_integer& aPos, const store::Item_t& value)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  store::Item_t lItem = getArrayValue(aPos);
  if (lItem->isJSONItem()) {
    JSONItem* lJSONItem = dynamic_cast<JSONItem*>(lItem.getp());
    ZORBA_ASSERT(lJSONItem != NULL);
    setJSONRoot(lItem, lJSONItem);
  }
  uint64_t pos = cast(aPos) - 1;
  setJSONRoot(value, theRoot);
  theContent[pos] = value;
  
#ifndef NDEBUG
  assertInvariant();
#endif
  return lItem;
}


/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::setRoot(const JSONItem* aRoot)
{
  theRoot = aRoot;
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    SimpleJSONObject* lObject =
        dynamic_cast<SimpleJSONObject*>(lIter->getp());
    SimpleJSONArray* lArray =
        dynamic_cast<SimpleJSONArray*>(lIter->getp());
    if (lObject != NULL)
    {
      lObject->setRoot(aRoot);
    }
    else if (lArray != NULL)
    {
      lArray->setRoot(aRoot);
    }
  }
}


/******************************************************************************

*******************************************************************************/
uint64_t
SimpleJSONArray::cast(const xs_integer& i)
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
store::Item_t
SimpleJSONArray::getArrayValue(const xs_integer& aPosition) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
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
store::Iterator_t
SimpleJSONArray::getArrayValues() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  return new ValuesIterator(const_cast<SimpleJSONArray*>(this));
}


/******************************************************************************

*******************************************************************************/
store::Item_t
SimpleJSONArray::getArraySize() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  store::Item_t lRes;
  xs_integer lSize(theContent.size());
  GET_FACTORY().createInteger(lRes, lSize);  
  return lRes;
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONArray::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
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
zstring
SimpleJSONArray::getStringValue() const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("array"));
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::getStringValue2(zstring& val) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::appendStringValue(zstring& buf) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
#ifndef NDEBUG
  assertInvariant();
#endif
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("array"));
}


/*******************************************************************************

********************************************************************************/
void
SimpleJSONArray::setCollection(SimpleCollection* collection, xs_integer /*pos*/)
{
#ifndef NDEBUG
  assertInvariant();
#endif
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
#ifndef NDEBUG
  assertInvariant();
#endif
}

/******************************************************************************

*******************************************************************************/
void SimpleJSONArray::assertInvariant() const
{
  ZORBA_ASSERT(theRoot != NULL);
  const SimpleJSONObject* lObject = dynamic_cast<const SimpleJSONObject*>(theRoot);
  const SimpleJSONArray* lArray = dynamic_cast<const SimpleJSONArray*>(theRoot);
  ZORBA_ASSERT(lObject != NULL || lArray != NULL);
  if (lObject != NULL) {
    ZORBA_ASSERT(lObject->isThisRootOfAllDescendants(theRoot));
    ZORBA_ASSERT(lObject->isThisJSONItemInDescendance(this));
  } else {
    ZORBA_ASSERT(lArray->isThisRootOfAllDescendants(theRoot));
    ZORBA_ASSERT(lArray->isThisJSONItemInDescendance(this));
  }
}


/******************************************************************************

*******************************************************************************/
bool SimpleJSONArray::isThisRootOfAllDescendants(const store::Item* aRoot) const
{
  if(theRoot != aRoot)
  {
    return false;
  }
  for (Members::const_iterator lIter = theContent.begin();
       lIter != theContent.end();
       ++lIter)
  {
    const SimpleJSONObject* lObject =
        dynamic_cast<const SimpleJSONObject*>(lIter->getp());
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(lIter->getp());
    if (lObject != NULL && (!lObject->isThisRootOfAllDescendants(aRoot)))
    {
      return false;
    }
    else if (lArray != NULL && (!lArray->isThisRootOfAllDescendants(aRoot)))
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
        dynamic_cast<const SimpleJSONObject*>(lIter->getp());
    const SimpleJSONArray* lArray =
        dynamic_cast<const SimpleJSONArray*>(lIter->getp());
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


/******************************************************************************

*******************************************************************************/
SimpleJSONArray::ValuesIterator::~ValuesIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::ValuesIterator::open()
{
  theIter = theArray->theContent.begin();
}


/******************************************************************************

*******************************************************************************/
bool
SimpleJSONArray::ValuesIterator::next(store::Item_t& res)
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
void
SimpleJSONArray::ValuesIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::ValuesIterator::close()
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
