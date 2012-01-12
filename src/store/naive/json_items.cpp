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
store::Item*
JSONObject::getType() const
{
  return GET_STORE().JDM_OBJECT_QNAME;
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
store::Item*
JSONObjectPair::getType() const
{
  return GET_STORE().JDM_PAIR_QNAME;
}


/******************************************************************************

*******************************************************************************/
bool
SimpleJSONObject::JSONObjectPairComparator::operator()(
    const store::Item* lhs,
    const store::Item* rhs) const
{
  return lhs->getStringValue().compare(rhs->getStringValue());
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
  try {
    lIndex = to_xs_unsignedLong(aPos);
  } catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(
        zerr::ZSTR0060_RANGE_EXCEPTION,
        ERROR_PARAMS(
          BUILD_STRING("access out of bounds " << e.what() << ")")
        )
      );
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

} // namespace json
} // namespace simplestore
} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
