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
#include "json_visitor.h"
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
bool
SimpleJSONObject::JSONObjectPairComparator::operator()(
    const JSONObjectPair_t& lhs,
    const JSONObjectPair_t& rhs) const
{
  return lhs->getName()->getStringValue().compare(rhs->getName()->getStringValue());
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::add(const JSONObjectPair_t& p)
{
  thePairs.insert(p);
}


/******************************************************************************

*******************************************************************************/
SimpleJSONObject::PairIterator::~PairIterator() {}


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
    JSONObjectPair_t lPair = *theIter;
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
SimpleJSONObject::pairs() const
{
  return new PairIterator(const_cast<SimpleJSONObject*>(this));
}

/******************************************************************************

*******************************************************************************/
void
SimpleJSONObject::accept(JSONVisitor* v) const
{
  v->begin(this);

  size_t i = 1;

  for (PairsConstIter lIter = thePairs.begin(); lIter != thePairs.end(); ++i, ++lIter)
  {
    v->begin(*lIter, i == thePairs.size());

    JSONObject* lObject = dynamic_cast<JSONObject*>((*lIter)->getValue());
    JSONArray* lArray = dynamic_cast<JSONArray*>((*lIter)->getValue());
    if (lObject)
    {
      lObject->accept(v);
    }
    else if (lArray)
    {
      lArray->accept(v);
    }
    else
    {
      v->visit((*lIter)->getValue());
    }

    v->end(*lIter, i == thePairs.size());
  }

  v->end(this);
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::accept(JSONVisitor* v) const
{
  v->begin(this);

  for (PairsConstIter lIter = theContent.begin(); lIter != theContent.end(); ++lIter)
  {
    JSONItem* lItem = dynamic_cast<JSONItem*>(lIter->getp());
    if (lItem)
    {
      lItem->accept(v);
    }
    else
    {
      v->visit(lIter->getp());
    }
  }

  v->end(this);
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

store::Iterator_t
SimpleJSONArray::values() const
{
  return new ValuesIterator(const_cast<SimpleJSONArray*>(this));
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
