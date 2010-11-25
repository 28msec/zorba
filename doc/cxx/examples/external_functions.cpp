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
#include <iostream>
#include <sstream>
#include <cassert>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/empty_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/uri_resolvers.h>
#include <zorba/store_manager.h>


using namespace zorba;


class MySimpleExternalFunction;
class MyLazySimpleExternalFunction;
class MyErrorReportingExternalFunction;
class MyParametrizedExternalFunction;


/***************************************************************************//**
  External module with target namespace "urn:foo", storing 4 external function
  objects.
********************************************************************************/
class MyExternalModule : public ExternalModule
{
protected:
  MySimpleExternalFunction           * bar1;
  MyLazySimpleExternalFunction       * bar2;
  MyErrorReportingExternalFunction   * bar3;
  MyParametrizedExternalFunction     * bar4;

public:
  MyExternalModule()
    :
    bar1(0),
    bar2(0),
    bar3(0),
    bar4(0)
  {
  }
  
  ~MyExternalModule();
  
  String getURI() const { return "urn:foo"; }

  StatelessExternalFunction* getExternalFunction(const String& aLocalname);
};


/***************************************************************************//**
  An example that shows that an external module cannot be registered more than
  once.
********************************************************************************/
bool func_example_0(Zorba* aZorba)
{
  try 
  {
    StaticContext_t lContext = aZorba->createStaticContext();

    MyExternalModule lModule;
    
    lContext->registerModule(&lModule);
    lContext->registerModule(&lModule); // only allowed to register it once
  }
  catch (ZorbaException &e) 
  {
    std::cerr << "some exception " << e << std::endl;
    return true;
  }

	return false;
}


/***************************************************************************//**
  A first simple external function. 

  declare function bar1($a1, $a2) external

  The function implements a concatenation of two sequences passed as arguments.
  The concatenation is done eagerly, i.e. the result is fully materialized before
  any of its items are returned.
********************************************************************************/
class MySimpleExternalFunction : public NonePureStatelessExternalFunction
{
protected:
  const ExternalModule* theModule;

public:
  MySimpleExternalFunction(const ExternalModule* aModule)
    :
    theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "bar1"; }

  ItemSequence_t evaluate(
        const StatelessExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const 
  {
    std::cout << "namespace " << sctx->getNamespaceURIByPrefix("foo") << std::endl
              << "current datetime " << dctx->getCurrentDateTime().getStringValue()
              << std::endl; 

    ItemVector vec;
    for (int i = 0; i < 2; ++i) 
    {
      ItemSequence* iseq = args[i];
      Item item;
      while(iseq->next(item))
      {
        vec.push_back(item);
      }
    }

    // transfer ownership of the IteratorBackedItemSequence to Zorba (using an auto_ptr)
    return ItemSequence_t(new IteratorBackedItemSequence(vec));
  }
  
private:
  typedef std::vector<Item> ItemVector;
  typedef ItemVector::iterator ItemVectorIte;

  class IteratorBackedItemSequence : public ItemSequence
  {
  private:
    ItemVector     theItems;
    ItemVectorIte  theIte;
    ItemVectorIte  theEnd;

  public:
    IteratorBackedItemSequence(ItemVector& vec)
      :
      theItems(vec),
      theIte(theItems.begin()),
      theEnd(theItems.end())
    {
    }
    
    bool next(Item& val)
    {
      if (theIte == theEnd) 
      {
        return false;
      }
      val = *theIte;
      ++theIte;
      return true;
    }
  };
};


bool func_example_1(Zorba* aZorba)
{
	StaticContext_t sctx = aZorba->createStaticContext();

  MyExternalModule module;
  sctx->registerModule(&module);

  std::ostringstream queryText;
  queryText << "declare namespace foo=\"urn:foo\";" << std::endl
            << "declare function foo:bar1($a1, $a2) external;" << std::endl
            << "foo:bar1((1,2,3), (4,5,6))" << std::endl;

	XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 
  std::cout << query << std::endl;

	return true;
}


/***************************************************************************//**
  A second simple external function. 

  declare function bar2($a1, $a2) external

  The function implements a concatenation of two sequences passed as arguments.
  The concatenation is done lazily, i.e. the result is computed on the fly.
********************************************************************************/
class MyLazySimpleExternalFunction : public PureStatelessExternalFunction
{
protected:
  const ExternalModule* theModule;

public:
  MyLazySimpleExternalFunction(const ExternalModule* aModule)
    :
    theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "bar2"; }

  ItemSequence_t evaluate(const Arguments_t& args) const
  {
    // transfer ownership of the IteratorBackedItemSequence to Zorba (using an auto_ptr)
    return ItemSequence_t(new LazyConcatItemSequence(args));
  }

private:
  class LazyConcatItemSequence : public ItemSequence 
  {
  private:
    Arguments_t theArgs;
    size_t      theCurrentArg;

  public:
    LazyConcatItemSequence(const StatelessExternalFunction::Arguments_t& args)
      : 
      theArgs(args),
      theCurrentArg(0)
    {
    }

    bool next(Item& result)
    {
      while(theCurrentArg < 2 && !theArgs[theCurrentArg]->next(result)) 
      {
        ++theCurrentArg;
      }
      return !result.isNull();
    }
  };
};


bool func_example_2_1(Zorba* aZorba)
{
  StaticContext_t sctx = aZorba->createStaticContext();

  MyExternalModule module;
  sctx->registerModule(&module);

  std::ostringstream queryText;
  queryText << "declare namespace foo=\"urn:foo\";" << std::endl
            << "declare function foo:bar2($a1, $a2) external;" << std::endl
            << "foo:bar2((1,2,3), (4,5,6))" << std::endl;

	XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 

  std::cout << query << std::endl;

	return true;
}


bool func_example_2_2(Zorba* aZorba)
{
	StaticContext_t lContext = aZorba->createStaticContext();

  MyExternalModule lModule;
  
  lContext->registerModule(&lModule);

  std::ostringstream lText;
  lText << "declare namespace foo=\"urn:foo\";" << std::endl
        << "declare function foo:bar2($a1, $a2) external;" << std::endl
        << "let $s1 := (1,2,3)" << std::endl
        << "let $s2 := (4,5,6)" << std::endl
        << "for $x in 1 to 6 return (foo:bar2($s1, $s2)[7-$x])" << std::endl;

	XQuery_t lQuery = aZorba->compileQuery(lText.str(), lContext); 

  std::cout << lQuery << std::endl;

	return true;
}


/***************************************************************************//**
  A third simple external function. 

  declare function bar3($a) external;

  The function takes a single argument and checks if that argument is the empty
  sequence. If so, it raises an error. Otherwise, it returns back the argument.
********************************************************************************/
class MyErrorReportingExternalFunction : public PureStatelessExternalFunction
{
protected:
  const ExternalModule* theModule;

public:
  MyErrorReportingExternalFunction(const ExternalModule* aModule)
    :
    theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "bar3"; }

  ItemSequence_t evaluate(const StatelessExternalFunction::Arguments_t& args) const
  {
    // transfer ownership of the IteratorBackedItemSequence to Zorba (using an auto_ptr)
    return ItemSequence_t(new LazyErrorReportingItemSequence(args));
  }

private:
  class LazyErrorReportingItemSequence : public ItemSequence 
  {
  private:
    StatelessExternalFunction::Arguments_t  theArgs;
    bool                                    theIsEmpty;

  public:
    LazyErrorReportingItemSequence(const StatelessExternalFunction::Arguments_t& args)
      :
      theArgs(args),
      theIsEmpty(true)
    {
    }
    
    bool next(Item& result)
    {
      bool done = !theArgs[0]->next(result);
      if (done && theIsEmpty)
      {
        throw ExternalFunctionData::createZorbaException(
                  XPTY0004,
                  "Argument must not be the empty sequence.",
                  __FILE__, __LINE__);
      }
      theIsEmpty = false;
      return !done;
    }
  };
};


bool func_example_3_1(Zorba* aZorba)
{
	StaticContext_t sctx = aZorba->createStaticContext();

  MyExternalModule module;
  sctx->registerModule(&module);

  std::ostringstream queryText;
  queryText << "declare namespace foo=\"urn:foo\";" << std::endl
            << "declare function foo:bar3($a1) external;" << std::endl
            << "let $s1 := ()" << std::endl
            << "for $x in 1 to 6 return (foo:bar3($s1))" << std::endl;
    
	XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 

  try 
  {
    std::cout << query << std::endl;
  }
  catch (TypeException& te) 
  {
    std::cerr << te << std::endl;
    return true;
  }
  catch (ZorbaException& ex) 
  {
    std::cerr << ex << std::endl;
    return false; // type exception expected
  }

	return false;
}


/***************************************************************************//**

********************************************************************************/
class MyParametrizedExternalFunction : public NonePureStatelessExternalFunction
{
protected:
  const ExternalModule* theModule;
  
public:
  MyParametrizedExternalFunction(const ExternalModule* aModule)
    :
    theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "bar4"; }

  ItemSequence_t evaluate(
        const StatelessExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const 
  {
    void* lParam;
    std::string lParamName("myparam");

    if (!dctx->getExternalFunctionParam(lParamName, lParam)) 
    {
      assert(false); 
    }
    std::cout << "the function param: " << *static_cast<std::string*>(lParam)
              << std::endl;

    return ItemSequence_t(new EmptySequence());
  }
};


bool func_example_4_1(Zorba* aZorba)
{
	StaticContext_t sctx = aZorba->createStaticContext();

  MyExternalModule module;
  sctx->registerModule(&module);

  std::ostringstream queryText;
  queryText << "declare namespace foo=\"urn:foo\";" << std::endl
            << "declare function foo:bar4() external;" << std::endl
            << "for $x in 1 to 6 return (foo:bar4())" << std::endl;
    
	XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 

  DynamicContext* lDynContext = query->getDynamicContext();

  std::string lFunctionParam("foo:bar");

  lDynContext->addExternalFunctionParam("myparam", &lFunctionParam);

  try
  {
    std::cout << query << std::endl;
  }
  catch (StaticException& te) 
  {
    std::cerr << te << std::endl;
    return true;
  }
  catch (ZorbaException& ex) 
  {
    std::cerr << ex << std::endl;
    return false; // type exception expected
  }

	return true;
}


/***************************************************************************//**

********************************************************************************/
MyExternalModule::~MyExternalModule()
{
  delete bar1;
  delete bar2;
  delete bar3;
  delete bar4;
}


StatelessExternalFunction* MyExternalModule::getExternalFunction(const String& aLocalname)
{
  if (aLocalname.equals("bar1")) 
  {
    if (!bar1) 
    {
      bar1 = new MySimpleExternalFunction(this);
    } 
    return bar1;
  }
  else if (aLocalname.equals("bar2"))
  {
    if (!bar2) 
    {
      bar2 = new MyLazySimpleExternalFunction(this);
    } 
    return bar2;
  }
  else if (aLocalname.equals("bar3"))
  {
    if (!bar3) 
    {
      bar3 = new MyErrorReportingExternalFunction(this);
    } 
    return bar3;
  }
  else if (aLocalname.equals("bar4")) 
  {
    if (!bar3) 
    {
      bar4 = new MyParametrizedExternalFunction(this);
    } 
    return bar4;
  }
  return 0;
}


/***************************************************************************//**

********************************************************************************/
class MyModuleURIResolverResult : public ModuleURIResolverResult
{
  friend class MyModuleURIResolver2;

protected:
  std::istream             * theModule;
  std::vector<std::string>   theComponentURIs;

public:
  std::istream* getModuleStream() const 
  {
    return theModule;
  }

  void getModuleURL(std::string& url) const
  {
  }

  void getComponentURIs(std::vector<std::string>& uris) const 
  {
    uris = theComponentURIs;
  }
};


class MyModuleURIResolver2 : public ModuleURIResolver
{
public:
  ~MyModuleURIResolver2() {}

  std::auto_ptr<ModuleURIResolverResult> resolveTargetNamespace(
        const String& aTargetNamespaceURI,
        const StaticContext& aStaticContext)
  {
    std::auto_ptr<MyModuleURIResolverResult>
    lResult(new MyModuleURIResolverResult());

    std::string compURI = aTargetNamespaceURI.c_str();
    lResult->theComponentURIs.push_back(compURI);

    return std::auto_ptr<ModuleURIResolverResult>(lResult.release());
  }

  std::auto_ptr<ModuleURIResolverResult> resolve(
        const String& aURI,
        const StaticContext& aStaticContext)
  {
    std::auto_ptr<MyModuleURIResolverResult> lResult(new MyModuleURIResolverResult());

    if (aURI == "http://www.zorba-xquery.com/mymodule") 
    {
      // we have only one module
      lResult->theModule = new std::istringstream(
      "module namespace lm = 'http://www.zorba-xquery.com/mymodule'; \
       declare function lm:foo() { 'foo' }; \
       declare function lm:ext() external;");

      lResult->setError(URIResolverResult::UR_NOERROR);
    } 
    else
    {
      lResult->setError(URIResolverResult::UR_XQST0046);
      std::stringstream lErrorStream;
      lErrorStream << "Module not found " << aURI;
      lResult->setErrorDescription(lErrorStream.str());
    }

    return std::auto_ptr<ModuleURIResolverResult>(lResult.release());
  }
};


class MyModuleExternalFunction;


class MyModuleExternal : public ExternalModule
{
protected:
  Zorba                    * theZorba;
  MyModuleExternalFunction * theExtFunc;

public:
  MyModuleExternal(Zorba* aZorba) : theZorba(aZorba), theExtFunc(NULL) {}
  
  ~MyModuleExternal() {}
  
  ItemFactory* getItemFactory() const { return theZorba->getItemFactory(); }

  String getURI() const 
  {
    return "http://www.zorba-xquery.com/mymodule";
  }

  void setExternalFunction(MyModuleExternalFunction* f)
  {
    theExtFunc = f;
  }

  StatelessExternalFunction* getExternalFunction(const String& aLocalname)
  {
    if (aLocalname.equals("ext")) 
    {
      return reinterpret_cast<StatelessExternalFunction*>(theExtFunc);
    }
    return NULL;
  }
};


class MyModuleExternalFunction : public PureStatelessExternalFunction
{
protected:
  MyModuleExternal    * theModule;
  std::vector<Item>     theItems;

public:
  MyModuleExternalFunction(MyModuleExternal* aModule)
    :
    theModule(aModule)
  {
    Item item = aModule->getItemFactory()->createString("ext");
      
    theItems.push_back(item);

    theModule->setExternalFunction(this);
  }

  String getURI() const
  {
    return theModule->getURI();
  }

  String getLocalName() const
  {
    return "ext";
  }

  ItemSequence_t evaluate(const StatelessExternalFunction::Arguments_t& args) const
  {
    // transfer ownership of the IteratorBackedItemSequence to Zorba (using an auto_ptr)
    return ItemSequence_t(new VectorItemSequence(theItems));
  }
};


bool func_example_5(Zorba* aZorba)
{
	StaticContext_t sctx = aZorba->createStaticContext();

  MyModuleURIResolver2 moduleResolver;
  sctx->addModuleURIResolver(&moduleResolver);

  MyModuleExternal lExternalModule(aZorba);
  sctx->registerModule(&lExternalModule);

  MyModuleExternalFunction lExtFunc(&lExternalModule);

  std::ostringstream queryText;
  queryText << "import module namespace lm=\"http://www.zorba-xquery.com/mymodule\";"
            << "concat(lm:foo(), lm:ext())" << std::endl;

  try
  {    
    XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 

    std::cout << query << std::endl;
  }
  catch (StaticException& te) 
  {
    std::cerr << te << std::endl;
    return false;
  }
  catch (ZorbaException& ex) 
  {
    std::cerr << ex << std::endl;
    return false; // type exception expected
  }

	return true;
}


/***************************************************************************//**

********************************************************************************/
int external_functions(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << std::endl  << "executing simple external function test 0" << std::endl;
  res = func_example_0(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 1.1" << std::endl;
  res = func_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 2.1" << std::endl;
  res = func_example_2_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 2.2" << std::endl;
  res = func_example_2_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 3.1" << std::endl;
  res = func_example_3_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;
  
  std::cout << std::endl  << "executing simple external function test 4.1" << std::endl;
  res = func_example_4_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing simple external function test 5" << std::endl;
  res = func_example_5(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;


  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}

