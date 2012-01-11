/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#include <zorba/vector_item_sequence.h>
#include <zorba/xquery_exception.h>
#include <zorba/diagnostic_list.h>

#include "system/properties.h"

using namespace zorba;

namespace zorba { namespace main_sequential {
  
class FoldingFunction : public ContextualExternalFunction
{
public:
  String getURI() const { return "http://nonamespace.com"; }
  
  String getLocalName() const { return "bar"; }
  
  ItemSequence_t evaluate(
        const ExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const 
  {
    zorba::ItemFactory* itemFactory = Zorba::getInstance(0)->getItemFactory();
    std::vector<zorba::Item> res(10);
    for (int i = 0; i < 10; ++i) {
      res[i] = itemFactory->createInteger(i);
    }
    return ItemSequence_t(new zorba::VectorItemSequence(res));
  }
};

class FoldingModule : public ExternalModule
{
protected:
  FoldingFunction lFunc;
  
public:
  String getURI() const { return "http://nonamespace.com"; }
  
  ExternalFunction* getExternalFunction(const String& aLocalname)
  {
    return const_cast<FoldingFunction*>(&lFunc);
  }
};


} /* namespace nofolding */ } /* namespace zorba */

int
main_sequential(int argc, char* argv[]) 
{
  using namespace zorba::main_sequential;
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  zorba::Properties::load(0, NULL);

  try 
  {
    // test the sausalito use case
    // serialize a query and afterwards execute it
    // by calling a dynamic function (i.e. using eval) 
    {
      std::ifstream lIn("main_sequential.xq");
      assert(lIn.good());
      std::ostringstream lOut;
      FoldingModule lMod;

      {
        StaticContext_t lSctx = lZorba->createStaticContext();
        lSctx->registerModule(&lMod);
        XQuery_t lQuery = lZorba->compileQuery(lIn, lSctx);

        Zorba_SerializerOptions lSerOptions;
        lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
        lQuery->execute(lOut, &lSerOptions);
      }
      assert(lOut.str() == "blubb");
    }
  }
  catch (XQueryException& qe) 
  {
    if (qe.diagnostic() != err::XPTY0004)
    {
      std::cerr << qe << std::endl;
      return 3;
    }
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 4;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
/* vim:set et sw=2 ts=2: */
