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
#include <zorba/diagnostic_list.h>

#include "system/properties.h"


using namespace zorba;

namespace zorba { namespace ext_in_opt_ns {

bool theGetExtFuncParamDidntWork = false;


class ExtFunction : public ContextualExternalFunction
{
public:
  String getURI() const { return "http://www.zorba-xquery.com/mod2"; }
  
  String getLocalName() const { return "bar"; }
  
  ItemSequence_t evaluate(
        const ExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const 
  {
    void* lParam;
    // testing if the function paramegter num is available or not
    if (!dctx->getExternalFunctionParam("num", lParam))
      theGetExtFuncParamDidntWork = true;

    int* lNum = static_cast<int*>(lParam);
    std::cout << "ExtFunction::evaluate: " << *lNum << std::endl;

    return ItemSequence_t(new EmptySequence());
  }
};

  
class ExtModule : public ExternalModule
{
protected:
  ExtFunction lFunc;
  
public:
  String getURI() const { return "http://www.zorba-xquery.com/mod2"; }
  
  ExternalFunction* getExternalFunction(const String& aLocalname)
  {
    return const_cast<ExtFunction*>(&lFunc);
  }
};


class MySerializationCallback : public SerializationCallback
{
protected:
  ExtModule theMod;
  
public:
  virtual ExternalModule*
  getExternalModule(const String& aURI) const
  {
    return const_cast<ExtModule*>(&theMod);
  }
};


} /* namespace nofolding */ } /* namespace zorba */




int
ext_in_opt(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool lCorrectError = false;

  zorba::Properties::load(0, NULL);

  try 
  {
    std::ifstream lIn("ext_in_opt.xq");
    assert(lIn.good());
    std::ostringstream lOut;
    ext_in_opt_ns::ExtModule lMod;

    {
      StaticContext_t lSctx = lZorba->createStaticContext();
      lSctx->registerModule(&lMod);

      XQuery_t lQuery = lZorba->compileQuery(lIn, lSctx);

      // value to pass to an external function
      int lNum = 1000;

      zorba::DynamicContext* lDynContext = lQuery->getDynamicContext();
      lDynContext->setVariable("local:foo",
                               lZorba->getItemFactory()->createString("default")); 
      lDynContext->addExternalFunctionParam("num", &lNum);
      std::cout << lQuery << std::endl;
    }
  }
  catch (XQueryException& qe)
  {
    if (qe.diagnostic() == err::XPTY0004)
    {
      // the error XPTY0004 is the correct result of the query
      lCorrectError = true;
    }
    else
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

  if (ext_in_opt_ns::theGetExtFuncParamDidntWork)
    // the external function parameter "num" was not available
    return 5;
  else if (!lCorrectError)
    // query didn't end with the correct error code
    return 6;
  else
    return 0;
}

/* vim:set et sw=2 ts=2: */
