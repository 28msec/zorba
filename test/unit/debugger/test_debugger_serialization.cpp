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
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/serialization_callback.h>
#include <zorba/store_manager.h>
#include <zorba/xquery_exception.h>
#include <zorba/diagnostic_list.h>

#ifdef WIN32
#  include <direct.h>
#else
#  include <unistd.h>
#  include <stdlib.h>
#endif

using namespace zorba;

bool
debugger_serialization_example_1(Zorba* aZorba)
{
  try {
    // the stringstream used for query materialization
    std::stringstream lExecutionPlan;

    {
      XQuery_t lQuery = aZorba->createQuery();
      lQuery->setDebugMode(true);
      lQuery->compile("declare function local:foo() { let $i := 1 return ()}; ()"); 
      lQuery->saveExecutionPlan(lExecutionPlan, ZORBA_USE_BINARY_ARCHIVE);
      std::cout << lQuery << std::endl;
    }

    {
      XQuery_t lQuery = aZorba->createQuery();
      lQuery->loadExecutionPlan(lExecutionPlan);
      std::cout << lQuery << std::endl;
    }

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
debugger_serialization_example_2(Zorba* aZorba)
{
  try {
    // the stringstream used for query materialization
    std::stringstream lExecutionPlan;
    std::ostringstream lQueryStream;

#ifdef UNIX
    char* lCWD = getcwd(0, 0);
    std::cout << "blub " << lCWD << std::endl;
#else
    char* lCWD = _getcwd(0, 256);
#endif
    std::string lStr(lCWD);
    free(lCWD);

#ifdef WIN32
    size_t lStart, lEnd = 0;
    while ((lStart = lStr.find("\\", lEnd)) != std::string::npos) {
      lEnd = lStart + 1;
      lStr.replace(lStart, 1, "/");
    }
#endif

    lQueryStream
      << "import module namespace g = 'http://www.28msec.com/template/guestbook/guestbook'"
      << " at 'file:///" << lStr << "/guestbook.xq"
      << "';" << std::endl
      << "g:add()";


    {
      XQuery_t lQuery = aZorba->createQuery();
      lQuery->setDebugMode(true);
      std::cout << lQueryStream.str() << std::endl;
      lQuery->compile(lQueryStream.str()); 
      lQuery->saveExecutionPlan(lExecutionPlan, ZORBA_USE_BINARY_ARCHIVE);
      std::cout << lQuery << std::endl;
    }

    {
      XQuery_t lQuery = aZorba->createQuery();
      lQuery->loadExecutionPlan(lExecutionPlan);
      std::cout << lQuery << std::endl;
    }

  } catch (XQueryException& qe) {
    // error "Collection guestbook:entries does not exist." is OK
    if (qe.diagnostic() != zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST) {
      std::cerr << qe << std::endl;
      return false;
    }
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

int test_debugger_serialization( int argc, char * argv[] )
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << "executing debugger serialization example 1" << std::endl;
  res = debugger_serialization_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing debugger serialization example 2" << std::endl;
  res = debugger_serialization_example_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}

/* vim:set et sw=2 ts=2: */
