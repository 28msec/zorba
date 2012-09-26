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
#include <fstream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/uri_resolvers.h>
#include <zorba/xquery_exception.h>
#include <zorba/diagnostic_list.h>


using namespace zorba;

bool
context_test_1(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery(".");

  ItemFactory* lFactory = aZorba->getItemFactory();
  Item lItem = lFactory->createInteger(4);

  DynamicContext* lDCtx = lQuery->getDynamicContext();
  bool result;

  try 
  {
    result = lDCtx->setContextPosition(lItem);
    Item rItem;
    result = lDCtx->getContextPosition(rItem);
    if (rItem.getStringValue()!="4") 
      result = false;
  }
  catch (ZorbaException &e)
  {
    std::cerr << e << std::endl;
    return false;
  }

  return result;
}


bool
context_test_2(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery(".");

  ItemFactory* lFactory = aZorba->getItemFactory();
  Item lItem = lFactory->createInteger(4);

  DynamicContext* lDCtx = lQuery->getDynamicContext();
  bool result;

  try
  {
    result = lDCtx->setContextSize(lItem);
    Item rItem;
    result = lDCtx->getContextSize(rItem);
    if (rItem.getStringValue()!="4") 
      result = false;
  }
  catch (ZorbaException &e)
  {
    std::cerr << e << std::endl;
    return false;
  }

  return result;
}


bool
context_test_3(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery("declare variable $x := 2; $x + position()");

  ItemFactory* lFactory = aZorba->getItemFactory();

  Item lItem = lFactory->createInteger(4);

  DynamicContext* lDCtx = lQuery->getDynamicContext();

  try 
  {
    (void)lDCtx->setContextPosition(lItem);

    std::ostringstream stream;
    stream << lQuery;

    std::string result = stream.str();

    if (result != "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n6")
    {
      std::cout << result << std::endl;
      return false;
    }
  }
  catch (ZorbaException &e)
  {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}


bool
context_test_4(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery(".");

  ItemFactory* lFactory = aZorba->getItemFactory();
  Item lItem = lFactory->createString("4");

  DynamicContext* lDCtx = lQuery->getDynamicContext();
  bool result;

  try
  {
    result = lDCtx->setContextSize(lItem);
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;

    if (e.diagnostic() == zerr::ZAPI0025_NON_INTEGER_CONTEXT_SIZE_VALUE)
    {
      return true;
    }

    return false;
  }

  return result;
}


int
test_dynamic_context(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();

  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << "executing Context Position test 1" << std::endl;
  res = context_test_1(lZorba);
  if (!res) return 1;
  std::cout << "Passed" << std::endl;

  std::cout << "executing Context Size test 2" << std::endl;
  res = context_test_2(lZorba);
  if (!res) return 1;
  std::cout << "Passed" << std::endl;

  std::cout << "executing Context Size test 3" << std::endl;
  res = context_test_3(lZorba);
  if (!res) return 1;
  std::cout << "Passed" << std::endl;

  std::cout << "executing Context Size test 4" << std::endl;
  res = context_test_4(lZorba);
  if (!res) return 1;
  std::cout << "Passed" << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
