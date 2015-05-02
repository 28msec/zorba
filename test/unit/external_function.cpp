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
bool lGotParam = false;
bool lDestroyedParam = false;

class MyExternalFunctionParameter : public ExternalFunctionParameter
{
  public:
    virtual void
    destroy() throw()
    {
      lDestroyedParam = true;
      delete this;
    }
};


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
    ExternalFunctionParameter* lParam = 0;
    if ( (lParam = dctx->getExternalFunctionParameter("myparam")) )
    {
      if (dynamic_cast<MyExternalFunctionParameter*>(lParam))
      {
        lGotParam = true;
      }
    }
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


class MySimpleExternalFunction3 : public NonContextualExternalFunction
{
public:
  String getURI() const { return "http://www.zorba-xquery.com/m"; }

  String getLocalName() const { return "bar3"; }

  ItemSequence_t evaluate(const ExternalFunction::Arguments_t& args) const
  {
    Item item;
    int64_t sum1 = 0;
    int64_t sum2 = 0;

    Iterator_t iter = args[0]->getIterator();
    iter->open();
    while (iter->next(item))
      sum1 += item.getLongValue();
    iter->close();

    //iter = args[0]->getIterator();
    iter->open();
    while (iter->next(item))
      sum2 += item.getLongValue();
    iter->close();

    if (sum1 != sum2)
    {
      std::cerr << "sum1 = " << sum1 << "  sum2 = " << sum2 << std::endl;
      throw std::exception();
    }

    return ItemSequence_t(new EmptySequence());
  }
};

class MySimpleExternalFunction4 : public NonContextualExternalFunction
{
public:
  String getURI() const { return "http://www.zorba-xquery.com/m"; }

  String getLocalName() const { return "bar4"; }

  ItemSequence_t evaluate(const ExternalFunction::Arguments_t& args) const
  {
    return args[0];
  }
};

class MySimpleExternalFunction5 : public NonContextualExternalFunction
{
public:
  String getURI() const { return "http://www.zorba-xquery.com/m"; }

  String getLocalName() const { return "bar5"; }

  ItemSequence_t evaluate(const ExternalFunction::Arguments_t& args) const
  {
    throw std::exception();
  }
};

class MyExternalModule : public ExternalModule
{
protected:
  MySimpleExternalFunction           bar;
  MySimpleExternalFunction2          bar2;
  MySimpleExternalFunction3          bar3;
  MySimpleExternalFunction4          bar4;
  MySimpleExternalFunction5          bar5;

public:
  String getURI() const { return "http://www.zorba-xquery.com/m"; }

  ExternalFunction* getExternalFunction(const String& aLocalname)
  {
    if (aLocalname == "bar")
        return const_cast<MySimpleExternalFunction*>(&bar);
    else if (aLocalname == "bar3")
        return const_cast<MySimpleExternalFunction3*>(&bar3);
    else if (aLocalname == "bar4")
        return const_cast<MySimpleExternalFunction4*>(&bar4);
    else if (aLocalname == "bar5")
        return const_cast<MySimpleExternalFunction5*>(&bar5);
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


bool
external_function_test_1(Zorba* aZorba)
{
  try 
  {
    // test the sausalito use case
    // serialize a query and afterwards execute it
    // by calling a dynamic function (i.e. using eval) 
    {
      std::ifstream lIn("ext_main.xq");
      assert(lIn.good());
      std::ostringstream lOut;
      MyExternalModule lMod;

      {
        StaticContext_t lSctx = aZorba->createStaticContext();
        lSctx->registerModule(&lMod);

        XQuery_t lQuery = aZorba->compileQuery(lIn, lSctx);
        lQuery->saveExecutionPlan(lOut);

        zorba::DynamicContext* lDynContext = lQuery->getDynamicContext();
        lDynContext->setVariable("local:foo",
                                 aZorba->getItemFactory()->createString("foo")); 
        // make sure constant folding doesn't happen, i.e. the function is not evaluated
        if (lCalled) {
          return false;
        }
        
        // evaluate the function and check if it was really called
        std::cout << lQuery << std::endl;
        if (!lCalled) {
          return false;
        }
      }

      {
        MySerializationCallback lCallback;

        // load the query saved above
        // this tests if, when loaded, the functions of the static context
        // that have not yet been compiled, can be compiled properly
        std::istringstream lIn(lOut.str());
        XQuery_t lQuery = aZorba->createQuery();
        lQuery->loadExecutionPlan(lIn, &lCallback);

        // set the parameter for evaluating a different dynamic function then
        // in the test above
        zorba::DynamicContext* lDynContext = lQuery->getDynamicContext();
        lDynContext->setVariable("local:foo",
                                 aZorba->getItemFactory()->createString("foo2")); 

        // evaluate the query
        std::cout << lQuery << std::endl;
      }
    }
  }
  catch (XQueryException& qe)
  {
    std::cerr << qe << std::endl;
    return false;
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}


bool
external_function_test_2(Zorba* aZorba)
{
  try 
  {
    std::ifstream lIn("ext_main.xq");
    assert(lIn.good());
    std::ostringstream lOut;
    MyExternalModule lMod;

    StaticContext_t lSctx = aZorba->createStaticContext();
    lSctx->registerModule(&lMod);
    {
      XQuery_t lQuery = aZorba->compileQuery(lIn, lSctx);

      zorba::DynamicContext* lDynContext = lQuery->getDynamicContext();

      // must be released in MyExternalFunctionParameter::destroy
      MyExternalFunctionParameter* lParam1 = new MyExternalFunctionParameter();
      MyExternalFunctionParameter* lParam2 = new MyExternalFunctionParameter();

      lDynContext->addExternalFunctionParameter("myparam", lParam1);
      lDynContext->addExternalFunctionParameter("myparam", lParam2);

      // make sure that destroy is invoked if the first parameter is overwritten
      if (!lDestroyedParam)
      {
        return false;
      }
      else
      {
        lDestroyedParam = false;
      }

      lDynContext->setVariable("local:foo",
                               aZorba->getItemFactory()->createString("foo")); 

      std::cout << lQuery << std::endl;
    }

    // destroy is called if the XQuery object is destroyed
    return lGotParam && lDestroyedParam;

  } 
  catch (XQueryException& qe) 
  {
    std::cerr << qe << std::endl;
    return false;
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}


bool
external_function_test_3(Zorba* aZorba)
{
  try 
  {
    std::ifstream lIn("ext_main2.xq");
    assert(lIn.good());
    std::ostringstream lOut;
    MyExternalModule lMod;

    StaticContext_t lSctx = aZorba->createStaticContext();
    lSctx->registerModule(&lMod);

    {
      XQuery_t lQuery = aZorba->compileQuery(lIn, lSctx);

      std::cout << lQuery << std::endl;
    }
  } 
  catch (XQueryException& qe) 
  {
    std::cerr << qe << std::endl;
    return false;
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return false;
  }
  catch (...)
  {
    return false;
  }
  return true;
}

bool
external_function_test_4(Zorba* aZorba)
{
  try 
  {
    std::ifstream lIn("ext_main3.xq");
    assert(lIn.good());
    std::ostringstream lOut;
    MyExternalModule lMod;

    StaticContext_t lSctx = aZorba->createStaticContext();
    lSctx->registerModule(&lMod);

    {
      XQuery_t lQuery = aZorba->compileQuery(lIn, lSctx);

      std::cout << lQuery << std::endl;
    }
  } 
  catch (XQueryException& qe) 
  {
    std::cerr << qe << std::endl;
    return false;
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return false;
  }
  catch (...)
  {
    return false;
  }
  return true;
}

bool
external_function_test_5(Zorba* aZorba)
{
  try 
  {
    std::ifstream lIn("ext_main4.xq");
    assert(lIn.good());
    std::ostringstream lOut;
    MyExternalModule lMod;

    StaticContext_t lSctx = aZorba->createStaticContext();
    lSctx->registerModule(&lMod);

    {
      XQuery_t lQuery = aZorba->compileQuery(lIn, lSctx);

      std::cout << lQuery << std::endl;
    }
  } 
  catch (XQueryException& qe) 
  {
    if (std::string("ZXQP0001") == qe.diagnostic().qname().localname())
    {
      std::cerr << qe << std::endl;
      return true;
    } else {
      std::cerr << qe << std::endl;
      return false;
    }
  }
  catch (...)
  {
    return false;
  }
  return false;
}

int
external_function(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  std::cout << "executing external_function_test_1" << std::endl;
  if (!external_function_test_1(lZorba))
  {
    return 1;
  }

  std::cout << "executing external_function_test_2" << std::endl;
  if (!external_function_test_2(lZorba))
  {
    return 2;
  }

  std::cout << "executing external_function_test_3" << std::endl;
  if (!external_function_test_3(lZorba))
  {
    return 3;
  }

  std::cout << "executing external_function_test_4" << std::endl;
  if (!external_function_test_4(lZorba))
  {
    return 4;
  }

  std::cout << "executing external_function_test_5" << std::endl;
  if (!external_function_test_5(lZorba))
  {
    return 4;
  }


  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
/* vim:set et sw=2 ts=2: */
