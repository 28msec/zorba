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
JSONTree::JSONTree()
  : theRoot(0)
{
}


/******************************************************************************

*******************************************************************************/
void
JSONTree::free()
{
  delete theRoot;

  delete this;
}


/******************************************************************************

*******************************************************************************/
bool
JSONObject::JSONObjectPairComparator::operator()(
    const JSONObjectPair_t& lhs,
    const JSONObjectPair_t& rhs) const
{
  return lhs->getName()->getStringValue().compare(rhs->getName()->getStringValue());
}


/******************************************************************************

*******************************************************************************/
void
JSONObject::add(const JSONObjectPair_t& p)
{
  thePairs.insert(p);
}


/******************************************************************************

*******************************************************************************/
void
JSONObject::accept(JSONVisitor* v) const
{
  v->begin(this);

  for (PairsConstIter lIter = thePairs.begin(); lIter != thePairs.end(); ++lIter)
  {
    v->begin(*lIter);

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

    v->end(*lIter);
  }

  v->end(this);
}


/******************************************************************************

*******************************************************************************/
void
JSONArray::accept(JSONVisitor* v) const
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
JSONArray::push_back(const JSONArrayPair_t& aPair)
{
  store::Item_t lPos;
  GET_FACTORY().createInteger(lPos, theContent.size() + 1);
  aPair->setPosition(lPos);

  theContent.push_back(aPair);
}


/******************************************************************************

*******************************************************************************/
void
JSONObjectPair::accept(JSONVisitor* v) const
{
  v->begin(this);
  v->end(this);
}


/******************************************************************************

*******************************************************************************/
void
JSONArrayPair::accept(JSONVisitor* v) const
{
  v->begin(this);
  v->end(this);
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
