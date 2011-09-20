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
#include <zorba/zorba_exception.h>

using namespace zorba;


int
plan_serializer(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  try {
     std::ifstream lIn("guestbook_main.xq");
     std::ostringstream lOut;

     {
       StaticContext_t lSctx = lZorba->createStaticContext();

       XQuery_t lQuery = lZorba->compileQuery(lIn, lSctx);
       lQuery->saveExecutionPlan(lOut, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);
     }


     {
       std::istringstream lIn(lOut.str());
       XQuery_t lQuery = lZorba->createQuery();
       lQuery->loadExecutionPlan(lIn);
       std::cout << lQuery << std::endl;
     }
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 1;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
/* vim:set et sw=2 ts=2: */
