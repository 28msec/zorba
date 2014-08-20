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

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <limits>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/api_shared_types.h>
#include <zorba/item_sequence.h>



using namespace zorba;


void
testMultipleJsonDataMgrInitilizations()
{

  Zorba* zorba = NULL;
  void* store = NULL;

  store = zorba::StoreManager::getStore();
  zorba = Zorba::getInstance(store);

  {
    JsonDataManager_t mgr = zorba->getJsonDataManager();

    std::stringstream lObj;
    lObj << "{\"a\":1}";
    mgr->parseJSON(lObj);
  }

  zorba->shutdown();
  zorba::StoreManager::shutdownStore(store);

  store = zorba::StoreManager::getStore();
  zorba = Zorba::getInstance(store);

  {
    JsonDataManager_t mgr = zorba->getJsonDataManager();
    std::stringstream lObj;
    lObj << "{\"a\":1}";
    mgr->parseJSON(lObj);
  }

  zorba->shutdown();
  zorba::StoreManager::shutdownStore(store);
}


int
jsondatamanager(int argc, char* argv[])
{
  try
  {
    testMultipleJsonDataMgrInitilizations();
  }
  catch (ZorbaException &e)
  {
    std::cerr << e << std::endl;
    return 1;
  }

  return 0;
}
