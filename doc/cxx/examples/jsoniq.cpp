/*
 * Copyright 2006-2008 The FLWOR Foundation.
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

#include <iostream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba_exception.h>

using namespace zorba;

namespace jsoniq_test {

/**
 * Test accessing a JSONArray's members
 */
bool
example_1(Zorba* aZorba)
{
  Iterator_t lIterator;
  XQuery_t lQuery = aZorba->compileQuery("[ 1, 2, 3 ]");
  lIterator = lQuery->iterator();
  lIterator->open();
  Item lItem;
  lIterator->next(lItem);

  // Ensure we got a JSON array
  if (!lItem.isJSONItem() ||
      lItem.getJSONItemKind() != store::StoreConsts::jsonArray) {
    std::cerr << "Item is not JSON Array!" << std::endl;
    return false;
  }

  // Ensure array has 3 integer members
  uint64_t lSize = lItem.getArraySize();
  if (lSize != 3) {
    std::cerr << lSize << " array members returned, expecting 3" << std::endl;
    return false;
  }
  for(int i = 1; i <= lSize; ++i)
  {
    Item lMember = lItem.getArrayValue(i);
    // This will throw an exception if the item isn't an integer
    std::cout << lMember.getLongValue() << std::endl;
  }
  lIterator->close();

  return true;
}


/**
 * Test accessing a JSONArray's members directly by index
 */
bool
example_2(Zorba* aZorba)
{
  Iterator_t lIterator;
  XQuery_t lQuery = aZorba->compileQuery("[ 1, 2, 3 ]");
  lIterator = lQuery->iterator();
  lIterator->open();
  Item lItem;
  lIterator->next(lItem);

  Item lMember;
  for (int i = 1; i <= 3; i++) {
    lMember = lItem.getArrayValue(i);
    std::cout << lMember.getLongValue() << std::endl;
  }

  lIterator->close();

  return true;
}


/**
 * Test accessing a JSONObject's values directly by name
 */
bool
example_3(Zorba* aZorba)
{
  Iterator_t lIterator;
  XQuery_t lQuery = aZorba->compileQuery("{ \"one\" : 1, \"two\" : 2 }");
  lIterator = lQuery->iterator();
  lIterator->open();
  Item lItem;
  lIterator->next(lItem);

  Item lValue;
  lValue = lItem.getObjectValue("one");
  std::cout << lValue.getLongValue() << std::endl;
  lValue = lItem.getObjectValue("two");
  std::cout << lValue.getLongValue() << std::endl;

  lIterator->close();

  return true;
}

/**
 * Test accessing a non-existent JSONArray member
 */
bool
example_4(Zorba* aZorba)
{
  Iterator_t lIterator, lMembers;
  XQuery_t lQuery = aZorba->compileQuery("[ 1, 2, 3 ]");
  lIterator = lQuery->iterator();
  lIterator->open();
  Item lItem;
  lIterator->next(lItem);

  Item lNonMember = lItem.getArrayValue(4);
  lIterator->close();

  if (!lNonMember.isNull()) {
    return false;
  }

  return true;
}

/**
 * Test accessing a non-existent JSONObject pair value
 */
bool
example_5(Zorba* aZorba)
{
  Iterator_t lIterator;
  XQuery_t lQuery = aZorba->compileQuery("{ \"one\" : 1, \"two\" : 2 }");
  lIterator = lQuery->iterator();
  lIterator->open();
  Item lItem;
  lIterator->next(lItem);

  Item lNonValue = lItem.getObjectValue("three");
  lIterator->close();

  if (!lNonValue.isNull()) {
    return false;
  }
  return true;
}

/**
 * Utility function: Given an item, bind that item to a simple query and
 * serialize the result, then ensure the result matches the expected string.
 */
bool
serialize(Zorba* aZorba, Item aItem, std::string aExpected)
{
  Zorba_SerializerOptions lSerialOpt;
  lSerialOpt.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

  XQuery_t lQuery = aZorba->compileQuery("declare variable $i external; $i");

  lQuery->getDynamicContext()->setVariable("i", aItem);

  std::stringstream lStream;
  lQuery->execute(lStream, &lSerialOpt);

  std::string lResult = lStream.str();
  std::cout << lResult << std::endl;
  if (lResult.compare(aExpected) != 0) {
    std::cout << "Wrong value! Expected " << aExpected << std::endl;
    return false;
  }
  return true;
}

/**
 * Test creating a JSON null value.
 */
bool
example_6(Zorba* aZorba)
{
  Item lNull = aZorba->getItemFactory()->createJSONNull();
  return serialize(aZorba, lNull, "null");
}

/**
 * Test creating a JSON array.
 */
bool example_7(Zorba* aZorba)
{
  std::vector<Item> lMembers;
  for (int i = 1; i <= 4; i++) {
    // xs:int is fine for JSON arrays
    lMembers.push_back(aZorba->getItemFactory()->createInt(i));
  }
  Item lArray = aZorba->getItemFactory()->createJSONArray(lMembers);
  return serialize(aZorba, lArray, "[ 1, 2, 3, 4 ]");
}


} /* namespace jsoniq-test */

int 
jsoniq(int argc, char* argv[])
{
  void* lStore = StoreManager::getStore();
  Zorba *lZorba = Zorba::getInstance(lStore);

  bool res = false;

  try {
    std::cout << "executing jsoniq example 1" << std::endl;
    res = jsoniq_test::example_1(lZorba);
    if (!res) return 1;
    std::cout << std::endl;

    std::cout << "executing jsoniq example 2" << std::endl;
    res = jsoniq_test::example_2(lZorba);
    if (!res) return 1;
    std::cout << std::endl;

    std::cout << "executing jsoniq example 3" << std::endl;
    res = jsoniq_test::example_3(lZorba);
    if (!res) return 1;
    std::cout << std::endl;

    std::cout << "executing jsoniq example 4" << std::endl;
    res = jsoniq_test::example_4(lZorba);
    if (!res) return 1;
    std::cout << std::endl;

    std::cout << "executing jsoniq example 5" << std::endl;
    res = jsoniq_test::example_5(lZorba);
    if (!res) return 1;
    std::cout << std::endl;

    std::cout << "executing jsoniq example 6" << std::endl;
    res = jsoniq_test::example_6(lZorba);
    if (!res) return 1;
    std::cout << std::endl;

    std::cout << "executing jsoniq example 9" << std::endl;
    res = jsoniq_test::example_7(lZorba);
    if (!res) return 1;
    std::cout << std::endl;
  }
  catch (ZorbaException& e) {
    std::cout << "ZorbaException raised: " << e.what() << std::endl;
    return 2;
  }

  lZorba->shutdown();
  StoreManager::shutdownStore(lStore);
  return 0;
}
