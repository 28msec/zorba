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
#include <fstream>
#include <iostream>

#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/xquery.h>
#include <zorba/xquery_exception.h>


int collection(int argc, char* argv[])
{
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* z = zorba::Zorba::getInstance(store);

  std::ifstream lIn("collection1.xq");
  assert(lIn.good());
  zorba::XQuery_t lQuery = z->createQuery();
  Zorba_CompilerHints lHints;
  lQuery->compile(lIn, lHints);
  std::cout << lQuery << std::endl;

  try
  {
    {
      std::ifstream lIn("collection2.xq");
      zorba::XQuery_t lQuery = z->createQuery();
      Zorba_CompilerHints lHints;
      lQuery->compile(lIn, lHints);
      std::cout << lQuery << std::endl;
    }
  }
  catch (zorba::XQueryException &e)
  {
    // catch collection not declared error (it's expected)
    std::cerr << "Error: " << e << std::endl;
    return 0;
  }
  catch (zorba::ZorbaException &e)
  {
    std::cerr << "Error: " << e << std::endl;
    return 1;
  }

  return 1;
}
/* vim:set et sw=2 ts=2: */
