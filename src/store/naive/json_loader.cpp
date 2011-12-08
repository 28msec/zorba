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
#include "json_loader.h"
#include "util/json_parser.h"
#include "json_items.h"
#include "simple_item_factory.h"
#include "store_defs.h"
#include "simple_store.h"
#include <cassert>
#include <vector>

namespace zorba
{

namespace simplestore
{

namespace json
{


/******************************************************************************

*******************************************************************************/
JSONLoader::JSONLoader(std::istream& s)
  : in(s)
{
}


/******************************************************************************

*******************************************************************************/
JSONLoader::~JSONLoader()
{
}


/******************************************************************************

*******************************************************************************/
store::Item_t
JSONLoader::next( )
{
  using namespace zorba::json;
  using namespace zorba::simplestore;
  using namespace zorba::simplestore::json;

  in.peek();
  if (in.eof())
  {
    return NULL;
  }

  try
  {
    BasicItemFactory& lFactory = GET_FACTORY();

    JSONItem_t lRootItem;

    // stack of objects, arrays, and object pairs
    std::vector<JSONItem_t> lStack;

    parser lParser(in);

    token lToken;

    while (lParser.next(&lToken))
    {
      switch (lToken.get_type())
      {
        case token::begin_array:
          lStack.push_back(new SimpleJSONArray());
          break;

        case token::begin_object:
          lStack.push_back(new SimpleJSONObject());
          break;

        case token::end_array:
        case token::end_object:
          {
            JSONItem_t lItem = lStack.back();

            lStack.pop_back();

            if (lStack.empty())
            {
              lRootItem = lItem;
            }
            else
            {
              JSONObjectPair* lOPair = cast<JSONObjectPair>(lStack.back());
              lOPair->setValue(lItem);
              lStack.pop_back();
            }

            break;
          }
        case token::name_separator:
        case token::value_separator:
            break;
        case token::string:
          {
            store::Item_t lValue;
            zstring s = lToken.get_value();
            lFactory.createString(lValue, s);

            addValue(lStack, lValue);
            break;
          }
        case token::number:
          {
            store::Item_t lValue;
            zstring s = lToken.get_value();
            lFactory.createJSONNumber(lValue, s);
            // todo check return type
            addValue(lStack, lValue);
            break;
          }
        case token::json_false:
          {
            store::Item_t lValue;
            lFactory.createBoolean(lValue, false);
            addValue(lStack, lValue);
            break;
          }
        case token::json_true:
          {
            store::Item_t lValue;
            lFactory.createBoolean(lValue, true);
            addValue(lStack, lValue);
            break;
          }
        case token::json_null:
          {
            store::Item_t lValue;
            lFactory.createJSONNull(lValue);
            addValue(lStack, lValue);
            break;
          }
        default:
          assert(false);
      }
    }
    return lRootItem;
  }
  catch (zorba::json::exception& e)
  {
    std::cerr << e.what() << " at " << e.get_loc() << std::endl;
  }
  return NULL;
}

void
JSONLoader::addValue(
  std::vector<JSONItem_t>& aStack,
  const store::Item_t& aValue)
{
  JSONItem_t lLast = aStack.back();

  JSONObject* lObject = dynamic_cast<JSONObject*>(lLast.getp());

  if (lObject)
  {
    // if the top of the stack is an object, then
    // the value must be a string which is the name
    // of the object's name value pair
    JSONObjectPair_t lOPair = new SimpleJSONObjectPair();
    lOPair->setName(aValue);
    lObject->add(lOPair);
    aStack.push_back(lOPair);

    return;
  }

  JSONObjectPair* lOPair = dynamic_cast<JSONObjectPair*>(lLast.getp());
  if (lOPair)
  {
    lOPair->setValue(aValue);
    aStack.pop_back();

    return;
  }

  JSONArray* lArray  = dynamic_cast<JSONArray*>(lLast.getp());
  assert(lArray);

  JSONArrayPair_t lArrayPair(
      new SimpleJSONArrayPair(
        aValue,
        lArray
      )
    );
  lArray->push_back(lArrayPair);
  
}

template<typename T> T*
JSONLoader::cast(const JSONItem_t& j)
{
#ifndef NDEBUG
  T* t = dynamic_cast<T*>(j.getp());
  assert(t);
#else
  T* t = static_cast<T*>(j.getp());
#endif
  return t;
}

} /* namespace json */

} /* namespace simplestore */

} /* namespace zorba */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

