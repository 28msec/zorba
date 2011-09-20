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
#include <zorba/zorba_exception.h>

using namespace zorba;

bool
test_1()
{
  for (int i = 0; i < 4; ++i) {
    Zorba* lZorba = Zorba::getInstance(StoreManager::getStore());
    try {
      std::ostringstream q;
      q << "<a>Hello World</a>";

      XQuery_t lQuery = lZorba->compileQuery(q.str());
      std::cout << lQuery << std::endl;
    } catch (ZorbaException const &e) {
      std::cerr << "an exception occured: " << e  << std::endl;
      return false;
    }
    lZorba->shutdown();
    zorba::StoreManager::shutdownStore(zorba::StoreManager::getStore());
  }
  return true;
}

bool
test_2()
{
  for (int i = 0; i < 4; ++i) {
    Zorba* lZorba = Zorba::getInstance(StoreManager::getStore());
    try {
      std::ostringstream q;
      if (i % 2 == 0) 
        q << "for $i in 1 to 10";
      else 
        q << "<a>Hello World</a>";

      XQuery_t lQuery = lZorba->compileQuery(q.str());
      std::cout << lQuery << std::endl;
    } catch (ZorbaException const& e) {
      std::cerr << "an exception occured: " << e << std::endl;
      if ( e.diagnostic().kind() != diagnostic::XQUERY_STATIC )
        return false;
      std::cerr << "this is on purpose" << std::endl;
    }
    lZorba->shutdown();
    zorba::StoreManager::shutdownStore(zorba::StoreManager::getStore());
  }
  return true;
} 

int
multiple_runs(int argc, char* argv[]) 
{
  if (!test_1())
    return 1;

  if (!test_2())
    return 2;

  return 0;
}
/* vim:set et sw=2 ts=2: */
