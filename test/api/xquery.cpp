/*
 * Copyright 2013 FLWOR Foundation.
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
#include <zorba/module_info.h>

using namespace zorba;

int
xquery_test_lib(Zorba* zorba)
{
  std::stringstream lQueryString;
  lQueryString
    << "module namespace foo = 'foo:bar';" << std::endl;

  XQuery_t lQuery = zorba->createQuery();

  ModuleInfo_t lInfo;
  lQuery->parse(lQueryString, lInfo);

  if (lInfo->getTargetNamespace() != "foo:bar")
    return 1;
  else
    return 0;
}

int
xquery_test_main(Zorba* zorba)
{
  std::stringstream lQueryString;
  lQueryString << "1+1" << std::endl;

  XQuery_t lQuery = zorba->createQuery();

  ModuleInfo_t lInfo;
  lQuery->parse(lQueryString, lInfo);

  if (lInfo->isLibraryModule())
    return 1;
  else
    return 0;
}

int
xquery_test_error(Zorba* zorba)
{
  try
  {
    std::stringstream lQueryString;
    lQueryString << "1+" << std::endl;

    XQuery_t lQuery = zorba->createQuery();

    ModuleInfo_t lInfo;
    lQuery->parse(lQueryString, lInfo);

    return 1;
  } catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 0;
  }
}

int
xquery(int argc, char* argv[]) 
{
  Zorba* zorba = NULL;
  void* store = NULL;

  store = zorba::StoreManager::getStore();
  zorba = Zorba::getInstance(store);

  try
  {
    if (xquery_test_lib(zorba))
      return 1;

    if (xquery_test_main(zorba))
      return 2;

    if (xquery_test_error(zorba))
      return 3;

  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return 4;
  }

  return 0;
}

