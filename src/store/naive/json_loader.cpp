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
#include "diagnostics/diagnostic.h"
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
JSONLoader::JSONLoader(
    std::istream& s,
    internal::diagnostic::location* relative_error_loc
  )
  : in(s),
    theRelativeLoc(relative_error_loc)
{
}


/******************************************************************************

*******************************************************************************/
JSONLoader::~JSONLoader()
{
}

#define RAISE_JSON_ERROR_NO_PARAM(msg) \
  if (theRelativeLoc) \
  { \
    throw XQUERY_EXCEPTION( \
        jerr::JNDY0021, \
        ERROR_PARAMS( \
          ZED(msg), \
          "" \
        ), \
        ERROR_LOC(e.get_loc()) \
     ); \
  } \
  else \
  { \
    throw ZORBA_EXCEPTION( \
        jerr::JNDY0021, \
        ERROR_PARAMS( \
          ZED(msg), \
          BUILD_STRING(e.get_loc().line(), ", ", e.get_loc().column()) \
        ) \
     ); \
  } 

#define RAISE_JSON_ERROR_WITH_PARAM(msg, param) \
  if (theRelativeLoc) \
  { \
    throw XQUERY_EXCEPTION( \
        jerr::JNDY0021, \
        ERROR_PARAMS( \
          ZED(msg), \
          param,  \
          "" \
        ), \
        ERROR_LOC(e.get_loc()) \
     ); \
  } \
  else \
  { \
    throw ZORBA_EXCEPTION( \
        jerr::JNDY0021, \
        ERROR_PARAMS( \
          ZED(msg), \
          param, \
          BUILD_STRING(e.get_loc().line(), ", ", e.get_loc().column()) \
        ) \
     ); \
  } 

/******************************************************************************

*******************************************************************************/
store::Item_t
JSONLoader::next( )
{
  using namespace zorba::json;
  using namespace zorba::simplestore;
  using namespace zorba::simplestore::json;

  try
  {
    BasicItemFactory& lFactory = GET_FACTORY();

    JSONItem_t lRootItem;

    // stack of objects, arrays, and object pairs
    std::vector<store::Item_t> lStack;

    parser lParser(in);
    if (theRelativeLoc)
    {
      lParser.set_loc(theRelativeLoc->file(), theRelativeLoc->line(), theRelativeLoc->column()+1);
    }

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
            store::Item_t lItem = lStack.back();

            lStack.pop_back();

            if (lStack.empty())
            {
              lRootItem = lItem.cast<JSONItem>();
            }
            else
            {
              addValue(lStack, lItem);
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
  catch (zorba::json::unterminated_string& e)
  {
    RAISE_JSON_ERROR_NO_PARAM(JSON_UNTERMINATED_STRING)
  }
  catch (zorba::json::unexpected_token& e)
  {
    RAISE_JSON_ERROR_WITH_PARAM(JSON_UNEXPECTED_TOKEN, e.get_token())
  }
  catch (zorba::json::illegal_number& e)
  {
    RAISE_JSON_ERROR_NO_PARAM(JSON_ILLEGAL_NUMBER)
  }
  catch (zorba::json::illegal_literal& e)
  {
    RAISE_JSON_ERROR_NO_PARAM(JSON_ILLEGAL_LITERAL)
  }
  catch (zorba::json::illegal_escape& e)
  {
    RAISE_JSON_ERROR_WITH_PARAM(JSON_ILLEGAL_ESCAPE, e.get_escape())
  }
  catch (zorba::json::illegal_codepoint& e)
  {
    RAISE_JSON_ERROR_WITH_PARAM(JSON_ILLEGAL_CODEPOINT, e.get_codepoint())
  }
  catch (zorba::json::illegal_character& e)
  {
    RAISE_JSON_ERROR_WITH_PARAM(JSON_ILLEGAL_CHARACTER, e.get_char())
  }
  return NULL;
}
#undef RAISE_JSON_ERROR_WITH_PARAM
#undef RAISE_JSON_ERROR_NO_PARAM

void
JSONLoader::addValue(
  std::vector<store::Item_t>& aStack,
  const store::Item_t& aValue)
{
  store::Item_t lLast = aStack.back();

  JSONObject* lObject = dynamic_cast<JSONObject*>(lLast.getp());

  if (lObject)
  {
    // if the top of the stack is an object, then
    // the value must be a string which is the name
    // of the object's next name/value pair
    aStack.push_back(aValue);
    return;
  }

  JSONArray* lArray  = dynamic_cast<JSONArray*>(lLast.getp());
  if (lArray)
  {
    // if the top of the stack is an array, then
    // the value must be appended to it
    lArray->push_back(aValue);
    return;
  }

  // Otherwise, the top of the stack must be a string, which means
  // that the second-to-top must be an object awaiting a value associated with
  // this name.
  store::Item_t lString = aStack.back();
  aStack.pop_back();
  
  lLast = aStack.back();

  lObject = dynamic_cast<JSONObject*>(lLast.getp());

  assert(lObject);
  lObject->add(lString, aValue, false);
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

