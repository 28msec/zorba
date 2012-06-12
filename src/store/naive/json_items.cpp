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


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::~SimpleJSONObject()
{
  thePairs.clear();
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONObject::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
  SimpleJSONObject* lNewObject = const_cast<SimpleJSONObject*>(this);
  if (copymode.theDoCopy)
  {
    lNewObject = new SimpleJSONObject();

    for (Pairs::iterator lIter = thePairs.begin();
         lIter != thePairs.end();
         ++lIter)
    {
      store::Item_t lName = lIter.getKey();
      store::Item_t lCopiedValue = lIter.getValue()->copy(NULL, copymode);

      lNewObject->add(lName, lCopiedValue, false);
    }
  }

  if (parent)
  {
    JSONArray* a = dynamic_cast<JSONArray*>(parent);
    assert(a != NULL);
    a->push_back(lNewObject);
  }
  
  return lNewObject;
}


/*******************************************************************************

********************************************************************************/
void
SimpleJSONObject::setCollection(SimpleCollection* collection, xs_integer /*pos*/)
{
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
}


/******************************************************************************

*******************************************************************************/
bool
SimpleJSONObject::add(
      const store::Item_t& aName,
      const store::Item_t& aValue,
      bool accumulate)
{
  Pairs::iterator lIterator = thePairs.find(aName);

  if (lIterator != thePairs.end())
  {  
    store::Item_t lValue = aValue;
    thePairs.insert(aName, lValue);
    return true;
  }
  else if (accumulate)
  {
    store::Item* value = lIterator.getValue().getp();

    if (value->isJSONArray())
    {
      static_cast<SimpleJSONArray*>(value)->push_back(aValue);
    }
    else
    {
      SimpleJSONArray_t array = new SimpleJSONArray();
      array->push_back(value);
      array->push_back(aValue);

      lIterator.setValue(array);
    }
    return true;
  }

  return false;
}


/******************************************************************************

*******************************************************************************/
const store::Item_t
SimpleJSONObject::remove(const store::Item_t& aName)
{
  Pairs::iterator lIter = thePairs.find(aName);
  if (lIter == thePairs.end())
  {
    return 0;
  }
  
  store::Item_t lRes = lIter.getValue();

  thePairs.erase(aName.getp());

  return lRes;
}


/******************************************************************************

*******************************************************************************/
const store::Item_t SimpleJSONObject::setValue(
    const store::Item_t& aName,
    const store::Item_t& aValue)
{
  Pairs::iterator lIter = thePairs.find(aName);
  if (lIter == thePairs.end()) {
    return NULL;
  }

  store::Item_t lRes = lIter.getValue();
  lIter.setValue(aValue);
  return lRes;
}

/******************************************************************************

*******************************************************************************/
bool SimpleJSONObject::rename(
    const store::Item_t& aName,
    const store::Item_t& aNewName)
{
  Pairs::iterator lIter = thePairs.find(aNewName);
  if (lIter != thePairs.end()) {
    return false;
  }
  
  lIter = thePairs.find(aName);
  if (lIter == thePairs.end()) {
    return false;
  }
  store::Item_t lValue = lIter.getValue();

  thePairs.erase(aName.getp());
  
  thePairs.insert(aNewName, lValue);

  return true;
}

/******************************************************************************

*******************************************************************************/
zstring
SimpleJSONObject::getStringValue() const
{
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::getStringValue2(zstring& val) const
{
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::appendStringValue(zstring& buf) const
{
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("object"));
}


/******************************************************************************

*******************************************************************************/
const store::Iterator_t
SimpleJSONObject::getObjectKeys() const
{
  return new KeyIterator(const_cast<SimpleJSONObject*>(this));
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
    res = theIter.getValue();
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
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::push_back(const store::Item_t& aValue)
{
  theContent.push_back(aValue.getp());
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::push_back(const std::vector<store::Item_t>& members)
{
  theContent.reserve(theContent.size() + members.size());
  add(theContent.size(), members);
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::push_front(const std::vector<store::Item_t>& members)
{
  theContent.reserve(theContent.size() + members.size());
  add(0, members);
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::insert_before(const xs_integer& pos, const store::Item_t& member)
{
  theContent.insert(theContent.begin() + (cast(pos) - 1), member.getp());
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::insert_before(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos) - 1, members);
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::insert_after(
    const xs_integer& aPos,
    const std::vector<store::Item_t>& members)
{
  // need to reserve at the beginning because reserve invalidates
  // existing iterators
  theContent.reserve(theContent.size() + members.size());

  add(cast(aPos), members);
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::add(
    uint64_t aTargetPos,
    const std::vector<store::Item_t>& aNewMembers)
{
  for (size_t i = 0; i < aNewMembers.size(); ++i)
  {
    store::Item* lItem = aNewMembers[i].getp();
    theContent.insert(theContent.begin() + aTargetPos + i, lItem);
  }

}


/******************************************************************************

*******************************************************************************/
store::Item_t
SimpleJSONArray::remove(const xs_integer& aPos)
{
  store::Item_t lPosition;
  GET_FACTORY().createInteger(lPosition, aPos);
  store::Item_t lItem = (getArrayValue(lPosition));

  uint64_t lPosStartingZero = cast(aPos) - 1;
  theContent.erase(theContent.begin() + lPosStartingZero);

  return lItem;
}


/******************************************************************************

*******************************************************************************/
store::Item_t
SimpleJSONArray::replace(const xs_integer& aPos, const store::Item_t& value)
{
  store::Item_t lPosition;
  GET_FACTORY().createInteger(lPosition, aPos);
  store::Item_t lItem = (getArrayValue(lPosition));

  uint64_t pos = cast(aPos) - 1;
  theContent[pos] = value.getp();
  
  return lItem;
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
const store::Item_t
SimpleJSONArray::getArrayValue(const store::Item_t& aPosition) const
{
  uint64_t lPos = cast(aPosition->getIntegerValue());
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
const store::Iterator_t
SimpleJSONArray::getArrayValues() const
{
  return new ValuesIterator(const_cast<SimpleJSONArray*>(this));
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONArray::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
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
  throw ZORBA_EXCEPTION(jerr::JNTY0003, ERROR_PARAMS("array"));
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::getStringValue2(zstring& val) const
{
  val = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::appendStringValue(zstring& buf) const
{
  buf = getStringValue();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  throw ZORBA_EXCEPTION(jerr::JNTY0004, ERROR_PARAMS("array"));
}


/*******************************************************************************

********************************************************************************/
void
SimpleJSONArray::setCollection(SimpleCollection* collection, xs_integer /*pos*/)
{
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
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
