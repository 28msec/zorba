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


using namespace zorba;


int
test_static_context(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  {
    StaticContext_t lSctx1 = lZorba->createStaticContext();
    StaticContext_t lSctx2 = lZorba->createStaticContext();
 
    Item lQName = lZorba->getItemFactory()->createQName(
                  "http://www.w3.org/2005/xpath-functions",
                  "current-dateTime");

    lSctx1->disableFunction(lQName, 0);
 
    // test if function is disabled in static context 1
    try 
    {
      XQuery_t lQuery = lZorba->compileQuery("fn:current-dateTime()", lSctx1);
      return 1; // must raise a function not found exception
    }
    catch (QueryException& e)
    {
      if (e.getErrorCode() != XPST0017)
      { // raise error if any other exception
        std::cerr << e << std::endl;
        return 2;
      }
    }

    // test if function exists in static context 2
    try 
    {
      XQuery_t lQuery = lZorba->compileQuery("fn:current-dateTime()", lSctx2);
    }
    catch (ZorbaException& e)
    {
      std::cerr << e << std::endl;
      return 3;
    }
  }

  return 0;
}
