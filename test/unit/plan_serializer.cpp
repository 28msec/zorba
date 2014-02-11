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

// standard
#include <fstream>
#include <iostream>
#include <sstream>

// Zorba
#include <zorba/store_manager.h>
#include <zorba/zorba.h>

using namespace zorba;

bool
save_and_load(Zorba* aZorba, const char* aQueryFile)
{
  try 
  {
     std::ifstream lIn(aQueryFile);
     std::ostringstream lOut;

     {
       Zorba_CompilerHints_t lHints;
       lHints.opt_level = ZORBA_OPT_LEVEL_O1;

       StaticContext_t lSctx = aZorba->createStaticContext();
       XQuery_t lQuery = aZorba->compileQuery(lIn, lSctx, lHints);
       lQuery->saveExecutionPlan(lOut);
     }

     {
       std::istringstream lIn(lOut.str());
       XQuery_t lQuery = aZorba->createQuery();
       lQuery->loadExecutionPlan(lIn);
       std::cout << lQuery << std::endl;
     }
     return true;
  }
  catch ( ZorbaException const &e ) 
  {
    std::cerr << e << std::endl;
    return false;
  }
}

bool
plan_serializer1(Zorba* aZorba)
{
  return save_and_load(aZorba, "guestbook_main.xq");
}

bool
plan_serializer2(Zorba* aZorba)
{
  return save_and_load(aZorba, "mini_http.xq");
}


bool
plan_serializer3(Zorba* aZorba)
{
  return save_and_load(aZorba, "mini_audit.xq");
}


int
plan_serializer(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  std::cout << "executing test 1" << std::endl;
  if (!plan_serializer1(lZorba))
    return 1;
  std::cout << std::endl;

  std::cout << "executing test 2" << std::endl;
  if (!plan_serializer2(lZorba))
    return 2;

  std::cout << "executing test 3" << std::endl;
  if (!plan_serializer3(lZorba))
    return 3;

  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
/* vim:set et sw=2 ts=2: */
