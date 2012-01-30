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
store::Item*
JSONObject::getType() const
{
  return GET_STORE().JDM_OBJECT_QNAME;
}


/******************************************************************************

*******************************************************************************/
bool
SimpleJSONObject::JSONObjectPairComparator::operator()(
    const store::Item* lhs,
    const store::Item* rhs) const
{
  return lhs->getStringValue().compare(rhs->getStringValue()) < 0;
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::add(const JSONObjectPair_t& p)
{
  store::Item* lName = p->getName();
  thePairs.insert(std::make_pair<store::Item*, JSONObjectPair_t>(lName, p));
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::remove(const store::Item_t& aName)
{
  PairsIter lIter = thePairs.find(aName.getp());
  if (lIter == thePairs.end())
  {
    RAISE_ERROR_NO_LOC(zerr::JSDY0061,
        ERROR_PARAMS(aName->getStringValue())
      );
  }
  thePairs.erase(lIter);
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

    for (PairsConstIter lIter = thePairs.begin();
         lIter != thePairs.end();
         ++lIter)
    {
      SimpleJSONObjectPair* lNewPair = static_cast<SimpleJSONObjectPair*>(
          lIter->second->copy(NULL, copymode)
        );
      lNewObject->add(lNewPair);
    }
  }

  if (parent)
  {
    if (parent->isJSONArray())
    {
      JSONArray* a = static_cast<JSONArray*>(parent);
      a->push_back(lNewObject);
    }
    else if (parent->isJSONPair())
    {
      JSONObjectPair* p = static_cast<JSONObjectPair*>(parent);
      p->setValue(lNewObject);
    }
  }

  return lNewObject;
}


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::PairIterator::~PairIterator() 
{
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::PairIterator::open()
{
  theIter = theObject->thePairs.begin();
}


/******************************************************************************

*******************************************************************************/
bool
SimpleJSONObject::PairIterator::next(store::Item_t& res)
{
  if (theIter != theObject->thePairs.end())
  {
    JSONObjectPair_t lPair = theIter->second;
    res = lPair;
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
SimpleJSONObject::PairIterator::reset()
{
  open();
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::PairIterator::close()
{
  theIter = theObject->thePairs.end();
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t
SimpleJSONObject::getPairs() const
{
  return new PairIterator(const_cast<SimpleJSONObject*>(this));
}


/******************************************************************************

*******************************************************************************/
store::Item*
SimpleJSONObject::getPair(const store::Item_t& name) const
{
  PairsConstIter lIter = thePairs.find(name.getp());
  if (lIter == thePairs.end())
  {
    return 0;
  }
  else
  {
    JSONObjectPair_t lPair = lIter->second;
    return lPair.getp();
  }
}


/******************************************************************************

*******************************************************************************/
store::Item*
JSONArray::getType() const
{
  return GET_STORE().JDM_ARRAY_QNAME;
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::push_back(const store::Item_t& aValue)
{
  theContent.push_back(aValue);
}


/******************************************************************************

*******************************************************************************/
const store::Item*
SimpleJSONArray::operator[](xs_integer& aPos) const
{
  uint64_t lIndex;
  try 
  {
    lIndex = to_xs_unsignedLong(aPos);
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }
  return theContent[lIndex].getp();
}


/******************************************************************************

*******************************************************************************/
store::Iterator_t
SimpleJSONArray::getMembers() const
{
  return new ValuesIterator(const_cast<SimpleJSONArray*>(this));
}


/******************************************************************************

*******************************************************************************/
store::Item*
SimpleJSONArray::getMember(const store::Item_t& aPosition) const
{
  uint64_t lIndex;
  try 
  {
    lIndex = to_xs_unsignedLong(aPosition->getIntegerValue());
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }

  if (lIndex == 0 || lIndex > theContent.size())
  {
    return 0;
  }
  else
  {
    return theContent[lIndex-1].getp();
  }
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
    lNewArray->theContent.resize(theContent.size());
    for (MembersConstIter lIter = theContent.begin();
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
    if (parent->isJSONArray())
    {
      JSONArray* a = static_cast<JSONArray*>(parent);
      a->push_back(lNewArray);
    }
    else if (parent->isJSONPair())
    {
      JSONObjectPair* p = static_cast<JSONObjectPair*>(parent);
      p->setValue(lNewArray);
    }
  }

  return lNewArray;
}


/******************************************************************************

*******************************************************************************/
store::Item*
JSONObjectPair::getType() const
{
  return GET_STORE().JDM_PAIR_QNAME;
}


/******************************************************************************

*******************************************************************************/
store::Item* SimpleJSONObjectPair::copy(
    store::Item* parent,
    const store::CopyMode& copymode) const
{
  SimpleJSONObjectPair* lNewPair = const_cast<SimpleJSONObjectPair*>(this);
  if (copymode.theDoCopy)
  {
    store::Item_t lNewValue;
    if (theValue->isJSONObject() ||
        theValue->isJSONArray() ||
        theValue->isNode())
    {
      lNewValue = theValue->copy(NULL, copymode);
    }
    else
    {
      lNewValue = theValue;
    }
    lNewPair = new SimpleJSONObjectPair(theName, lNewValue);
  }

  if (parent)
  {
    assert(parent->isJSONObject());

    JSONObject* p = static_cast<JSONObject*>(parent);
    
    p->add(lNewPair);
  }
  return lNewPair;
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
