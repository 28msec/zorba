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


using namespace zorba;

bool lCalled = false;

class MySimpleExternalFunction : public ContextualExternalFunction
{
public:
  String getURI() const { return "http://www.zorba-xquery.com/m"; }

  String getLocalName() const { return "bar"; }

  ItemSequence_t evaluate(
        const ExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const 
  {
    lCalled = true; // must not be reached because query is only compiled and not executed
    return ItemSequence_t(new EmptySequence());
  }
};

class MySimpleExternalFunction2 : public ContextualExternalFunction
{
public:
  String getURI() const { return "http://www.zorba-xquery.com/m"; }

  String getLocalName() const { return "bar2"; }

  ItemSequence_t evaluate(
        const ExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const 
  {
    return ItemSequence_t(new EmptySequence());
  }
};

class MyExternalModule : public ExternalModule
{
protected:
  MySimpleExternalFunction           bar;
  MySimpleExternalFunction2          bar2;

public:
  String getURI() const { return "http://www.zorba-xquery.com/m"; }

  ExternalFunction* getExternalFunction(const String& aLocalname)
  {
    if (aLocalname == "bar")
        return const_cast<MySimpleExternalFunction*>(&bar);
    else
        return const_cast<MySimpleExternalFunction2*>(&bar2);
  }
};

class MySerializationCallback : public SerializationCallback
{
  protected:
    MyExternalModule theMod;

  public:
    virtual ExternalModule*
    getExternalModule(const String& aURI) const
    {
      return const_cast<MyExternalModule*>(&theMod);
    }
};

int
external_function(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  try {
    // test the sausalito use case
    // serialize a query and afterwards execute it
    // by calling a dynamic function (i.e. using eval) 
    {
      std::ifstream lIn("ext_main.xq");
      assert(lIn.good());
      std::ostringstream lOut;
      MyExternalModule lMod;

      {
        StaticContext_t lSctx = lZorba->createStaticContext();
        lSctx->registerModule(&lMod);

        XQuery_t lQuery = lZorba->compileQuery(lIn, lSctx);
        lQuery->saveExecutionPlan(lOut, ZORBA_USE_BINARY_ARCHIVE, SAVE_UNUSED_FUNCTIONS);

        zorba::DynamicContext* lDynContext = lQuery->getDynamicContext();
        lDynContext->setVariable("local:foo",
                                 lZorba->getItemFactory()->createString("foo")); 
        // make sure constant folding doesn't happen, i.e. the function is not evaluated
        if (lCalled) {
          return 1;
        }
        
        // evaluate the function and check if it was really called
        std::cout << lQuery << std::endl;
        if (!lCalled) {
          return 2;
        }

      }

      {
        MySerializationCallback lCallback;

        // load the query saved above
        // this tests if, when loaded, the functions of the static context
        // that have not yet been compiled, can be compiled properly
        std::istringstream lIn(lOut.str());
        XQuery_t lQuery = lZorba->createQuery();
        lQuery->loadExecutionPlan(lIn, &lCallback);

        // set the parameter for evaluating a different dynamic function then
        // in the test above
        zorba::DynamicContext* lDynContext = lQuery->getDynamicContext();
        lDynContext->setVariable("local:foo",
                                 lZorba->getItemFactory()->createString("foo2")); 

        // evaluate the query
        std::cout << lQuery << std::endl;
      }
    }
  } catch (XQueryException& qe) {
    std::cerr << qe << std::endl;
    return 1;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 2;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
/* vim:set et sw=2 ts=2: */
