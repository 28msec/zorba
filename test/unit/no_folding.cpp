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

#include "system/properties.h"


using namespace zorba;

namespace zorba { namespace nofolding {

bool lCalledBlockFolding = false;

  
class FoldingFunction : public ContextualExternalFunction
{
public:
  String getURI() const { return "http://www.zorba-xquery.com/mod2"; }
  
  String getLocalName() const { return "bar"; }
  
  ItemSequence_t evaluate(
        const ExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const 
  {
    lCalledBlockFolding = true; // must not be reached because query is only compiled and not executed
    return ItemSequence_t(new EmptySequence());
  }
};

  
class FoldingModule : public ExternalModule
{
protected:
  FoldingFunction lFunc;
  
public:
  String getURI() const { return "http://www.zorba-xquery.com/mod2"; }
  
  ExternalFunction* getExternalFunction(const String& aLocalname)
  {
    return const_cast<FoldingFunction*>(&lFunc);
  }
};


} /* namespace nofolding */ } /* namespace zorba */


int
no_folding(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  zorba::Properties::load(0, NULL);

  try 
  {
    // test the sausalito use case
    // serialize a query and afterwards execute it
    // by calling a dynamic function (i.e. using eval) 
    {
      std::ifstream lIn("fold_main.xq");
      assert(lIn.good());
      std::ostringstream lOut;
      nofolding::FoldingModule lMod;

      {
        StaticContext_t lSctx = lZorba->createStaticContext();
        lSctx->registerModule(&lMod);

        XQuery_t lQuery = lZorba->compileQuery(lIn, lSctx);

        // constant folding must not happen during saving the plan
        lQuery->saveExecutionPlan(lOut, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);

        // make sure constant folding doesn't happen, i.e. the function is not evaluated
        // not even when serializing the plan
        if (nofolding::lCalledBlockFolding) 
        {
          std::cerr << "Test failed !" << std::endl;
          return 1;
        }
      }
    }
  } catch (XQueryException& qe) {
    std::cerr << qe << std::endl;
    return 3;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 4;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
/* vim:set et sw=2 ts=2: */
