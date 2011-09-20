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
//#include <zorba/function.h>
#include <zorba/serialization_callback.h>
#include <zorba/empty_sequence.h>
#include <zorba/xquery_exception.h>
#include <zorba/diagnostic_list.h>

#include "system/properties.h"


using namespace zorba;

/**
 * Test if the lifetime of a stream contained in a streamable string item
 * survives the livetime of its ItemSequence implementation. The streamDestroyer
 * parameter passed to the createStreamableString factory functions takes
 * care of that. The function refererred to by the function pointer is invoked
 * once the item is destroyed.
 */
int
streamable_string(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  try 
  {
    Item lContent;
    {
      std::ifstream lIn("streamable_string_query_1.xq");
      assert(lIn.good());

      XQuery_t lQuery = lZorba->compileQuery(lIn);
      Iterator_t lIter = lQuery->iterator();
      lIter->open();
      if (!lIter->next(lContent)) {
        std::cerr << "query didn't produce a result" << std::endl;
        return 2;
      }
    }
    {
      std::ifstream lIn("streamable_string_query_2.xq");
      assert(lIn.good());

      XQuery_t lQuery = lZorba->compileQuery(lIn);

      DynamicContext* lCtx = lQuery->getDynamicContext();
      String lVarName = "content";
      lCtx->setVariable(lVarName, lContent);

      std::cout << lQuery << std::endl;
    }
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 1;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
/* vim:set et sw=2 ts=2: */
