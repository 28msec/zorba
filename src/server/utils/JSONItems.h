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
#ifndef ZORBA_SERVER_UTILS_JSONOBJECT_H_
#define ZORBA_SERVER_UTILS_JSONOBJECT_H_

#include <map>
#include <vector>

#include "zorba/item.h"
#include "zorba/item_factory.h"

#include "request_handler.h"


namespace zorba
{
namespace server
{
namespace utils
{
  typedef std::pair<zorba::Item, zorba::Item> ObjectPair;
  typedef std::vector<ObjectPair> ObjectPairs;

  class JSONArray;

  class JSONObject
  {
    public:
    JSONObject();

    void addField(const std::string& aFieldName, const std::string& aFieldValue);
    void addField(const std::string& aFieldName, long aFieldValue);
    void addField(const std::string& aFieldName, double aFieldValue);
    void addField(const std::string& aFieldName, utils::JSONObject& aFieldValue);
    void addField(const std::string& aFieldName, utils::JSONArray& aFieldValue);

    zorba::Item getAsItem();

    private:
    zorba::ItemFactory& theItemFactory;
    ObjectPairs thePairs;
  };

  class JSONArray
  {
  public:
    JSONArray();

    void addMember(const std::string& aFieldValue);
    void addMember(long aFieldValue);
    void addMember(double aFieldValue);
    void addMember(utils::JSONObject& aFieldValue);
    void addMember(utils::JSONArray& aFieldValue);

    zorba::Item getAsItem();

  private:
    zorba::ItemFactory& theItemFactory;
    std::vector<zorba::Item> theItems;
  };
}
}
}

#endif
