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
    (*lIter)->accept(v);
  }

  v->end(this);
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArray::push_back(const JSONArrayPair_t& aPair)
{
  store::Item_t lPos;
  GET_FACTORY().createInteger(lPos, theContent.size() + 1);
  aPair->setPosition(lPos);

  theContent.push_back(aPair);
}


/******************************************************************************

*******************************************************************************/
void
SimpleJSONArrayPair::accept(JSONVisitor* v) const
{
  xs_integer lSize = theContainer->size();
  v->begin(this, lSize == getPosition()->getIntegerValue());
  v->end(this, lSize == getPosition()->getIntegerValue());
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
