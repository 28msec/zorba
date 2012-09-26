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


#include "rbkt/testdriverconfig.h"

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
    Iterator_t varsIte;
    lQuery->getExternalVariables(varsIte);

    varsIte->open();
    Item temp;
    while(varsIte->next(temp))
      lVars.push_back(temp);
    varsIte->close();

    if (lVars.size() != 2)
    {
      std::cout << "Expected 2 variables but got " << lVars.size() << std::endl;
      return false;
    }

    std::vector<Item>::iterator lIte = lVars.begin();
    std::vector<Item>::iterator lEnd = lVars.end();
    
    for (; lIte != lEnd; ++lIte) 
    {
      String name = lIte->getStringValue();

      if (name != "a" && name != "b")
        return false;
    }
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
cxx_api_changes_test4(Zorba* aZorba)
{
  try
  {
    std::ifstream lIn("cxx_api_ch4.xq");
    assert(lIn.good());

    StaticContext_t lStaticContext = aZorba->createStaticContext();
    std::vector<String> lModulePaths;
    lModulePaths.push_back(zorba::CMAKE_BINARY_DIR+"/TEST_URI_PATH/");
    lStaticContext->setModulePaths(lModulePaths);
    
    XQuery_t lQuery = aZorba->compileQuery(lIn, lStaticContext);
    std::vector<Item> lVars;
    Iterator_t varsIte;
    lQuery->getExternalVariables(varsIte);

    varsIte->open();
    Item temp;
    while(varsIte->next(temp))
      lVars.push_back(temp);
    varsIte->close();

    if (lVars.size() != 3)
      return false;

    std::ostringstream lOut;
    std::vector<Item>::const_iterator lIte = lVars.begin();
    std::vector<Item>::const_iterator lEnd = lVars.end();
    
    for (; lIte != lEnd; ++lIte)
    {
      lOut << lIte->getStringValue() << " ";
    }

    std::string out = lOut.str();

    if (out != "testGetExtVarA:ext a testGetExtVarB:ext " &&
        out != "testGetExtVarB:ext a testGetExtVarA:ext " &&
        out != "a testGetExtVarA:ext testGetExtVarB:ext " &&
        out != "a testGetExtVarB:ext testGetExtVarA:ext " &&
        out != "testGetExtVarA:ext testGetExtVarB:ext a " &&
        out != "testGetExtVarB:ext testGetExtVarA:ext a ")
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
cxx_api_changes_test5(Zorba* aZorba)
{
  try
  {
    
    std::string lIn = "declare variable $a external; 1+1";
    
    XQuery_t lQuery = aZorba->compileQuery(lIn);

    std::vector<Item> lVars;
    Iterator_t varsIte;
    lQuery->getExternalVariables(varsIte);

    varsIte->open();
    Item temp;
    while(varsIte->next(temp))
      lVars.push_back(temp);
    varsIte->close();

    std::vector<Item>::const_iterator lIte = lVars.begin();
    std::vector<Item>::const_iterator lEnd = lVars.end();

    Item item = aZorba->getItemFactory()->createInt(4);
    

    bool isBound1;
    bool isBound2;

    for(; lIte != lEnd; ++lIte)
    {
      Item qname = *lIte;
      isBound1 = lQuery->getDynamicContext()->isBoundExternalVariable(qname.getNamespace(), qname.getLocalName());
      Item value = aZorba->getItemFactory()->createString("foo");
      lQuery->getDynamicContext()->setVariable(qname.getStringValue(), value);
      isBound2 = lQuery->getDynamicContext()->isBoundExternalVariable(qname.getNamespace(), qname.getLocalName());
    }

    if (!isBound1 && isBound2)
      return true;
     
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
cxx_api_changes_test6(Zorba* aZorba)
{
  try
  {
    
    std::string lIn = "1+1";
    
    XQuery_t lQuery = aZorba->compileQuery(lIn);

    bool isBound1;
    bool isBound2;

    isBound1 = lQuery->getDynamicContext()->isBoundContextItem();

    Item lContextItem = aZorba->getItemFactory()->createString("foo");
    lQuery->getDynamicContext()->setContextItem(lContextItem);
    isBound2 = lQuery->getDynamicContext()->isBoundContextItem();

    if (!isBound1 && isBound2)
      return true;
     
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

  std::cout << "executing cxx_api_changes_test4" << std::endl;
  if (!cxx_api_changes_test4(lZorba))
  {
    return 4;
  }

  std::cout << "executing cxx_api_changes_test5" << std::endl;
  if (!cxx_api_changes_test5(lZorba))
  {
    return 5;
  }

  std::cout << "executing cxx_api_changes_test6" << std::endl;
  if (!cxx_api_changes_test6(lZorba))
  {
    return 6;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
