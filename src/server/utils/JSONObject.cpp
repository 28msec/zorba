/*
 * Copyright 2015 Federico Cavalieri.
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
#include "zorba/zorba_string.h"

#include "JSONObject.h"

namespace zorba
{
namespace server
{
namespace utils
{
  JSONObject::JSONObject() :
      theItemFactory(RequestHandler::getInstance().getItemFactory())
  {

  }

  void JSONObject::addField(const std::string& aFieldName, const std::string& aFieldValue)
  {
    zorba::Item lName = theItemFactory.createString(zorba::String(aFieldName));
    zorba::Item lValue = theItemFactory.createString(zorba::String(aFieldValue));
    thePairs.push_back(std::pair<zorba::Item, zorba::Item>(lName, lValue));
  }

  void JSONObject::addField(const std::string& aFieldName, long aFieldValue)
  {
    zorba::Item lName = theItemFactory.createString(zorba::String(aFieldName));
    zorba::Item lValue = theItemFactory.createInteger(aFieldValue);
    thePairs.push_back(std::pair<zorba::Item, zorba::Item>(lName, lValue));
  }

  void JSONObject::addField(const std::string& aFieldName, double aFieldValue)
  {
    zorba::Item lName = theItemFactory.createString(aFieldName);
    zorba::Item lValue = theItemFactory.createDouble(aFieldValue);
    thePairs.push_back(std::pair<zorba::Item, zorba::Item>(lName, lValue));
  }

  void JSONObject::addField(const std::string& aFieldName, utils::JSONObject& aFieldValue)
  {
    zorba::Item lName = theItemFactory.createString(aFieldName);
    zorba::Item lValue = aFieldValue.getAsItem();
    thePairs.push_back(std::pair<zorba::Item, zorba::Item>(lName, lValue));
  }

  zorba::Item JSONObject::getAsItem()
  {
    return theItemFactory.createJSONObject(thePairs);
  }

}
}
}
