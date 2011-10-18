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

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cassert>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/external_module.h>
#include <zorba/function.h>
#include <zorba/serialization_callback.h>
#include <zorba/empty_sequence.h>
#include <zorba/xquery_exception.h>

using namespace zorba;

bool 
cxx_api_changes_test1 (Zorba* aZorba)
{
  try
  {
    //test the use of the isSequential function in the c++ API
    std::ifstream lIn("cxx_api_ch1.xq");
    assert(lIn.good());
    
    XQuery_t lQuery = aZorba->compileQuery(lIn);

    if(!lQuery->isSequential())
      return false;
  }
  catch (XQueryException& qe)
  {
    std::cerr << qe << std::endl;
    return false;
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}

bool 
cxx_api_changes_test2 (Zorba* aZorba)
{
  try
  {
    //test the use of the isSequential function in the c++ API
    std::ifstream lIn("cxx_api_ch2.xq");
    assert(lIn.good());
    
    XQuery_t lQuery = aZorba->compileQuery(lIn);

    if(lQuery->isSequential())
      return false;
  }
  catch (XQueryException& qe)
  {
    std::cerr << qe << std::endl;
    return false;
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}

bool
cxx_api_changes_test3(Zorba* aZorba)
{
  try
  {
    //tests the use of getExternalVariables
    std::ifstream lIn("cxx_api_ch3.xq");
    assert(lIn.good());

    XQuery_t lQuery = aZorba->compileQuery(lIn);
    std::vector<Item> lVars;
    lQuery->getDynamicContext()->getExternalVariables(lVars);

    std::ostringstream lOut;
    std::vector<Item>::iterator lIte = lVars.begin();
    std::vector<Item>::iterator lEnd = lVars.end();
    
    for (; lIte != lEnd; ++lIte) 
    {
      lOut << lIte->getStringValue() << " ";
    }

    if(lOut.str().compare("a b "))
      return false;
  }
  catch (XQueryException& qe)
  {
    std::cerr << qe << std::endl;
    return false;
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}

int
cxx_api_changes (int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  std::cout << "executing cxx_api_changes_test1" << std::endl;
  if (!cxx_api_changes_test1(lZorba))
  {
    return 1;
  }

  std::cout << "executing cxx_api_changes_test2" << std::endl;
  if (!cxx_api_changes_test2(lZorba))
  {
    return 2;
  }

  std::cout << "executing cxx_api_changes_test3" << std::endl;
  if (!cxx_api_changes_test3(lZorba))
  {
    return 3;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}