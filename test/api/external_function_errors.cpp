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
#include <zorba/user_exception.h>
#include <zorba/external_module.h>
#include <zorba/function.h>
#include <zorba/empty_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba_exception.h>
#include <zorba/diagnostic_list.h>
#include <zorba/uri_resolvers.h>
#include <zorba/store_manager.h>


using namespace zorba;

class MyErrorReportingFunction1;
class MyErrorReportingFunction2;
class MyErrorReportingFunction3;
class MyErrorReportingFunction4;

class MyExternalModule : public ExternalModule
{
protected:
  MyErrorReportingFunction1   *theErrorFunc1;
  MyErrorReportingFunction2   *theErrorFunc2;
  MyErrorReportingFunction3   *theErrorFunc3;
  MyErrorReportingFunction4   *theErrorFunc4;
  ItemFactory                         *theItemFactory;

public:
  MyExternalModule(ItemFactory* aItemFactory)
    :
    theErrorFunc1(0),
    theErrorFunc2(0),
    theErrorFunc3(0),
    theErrorFunc4(0),
    theItemFactory(aItemFactory)
  {
  }
  
  ~MyExternalModule();
  
  String getURI() const { return "urn:foo"; }

  ExternalFunction* getExternalFunction(const String& aLocalname);

  ItemFactory*
  getItemFactory() { return theItemFactory; }
};


class MyErrorReportingFunction1 : public NonContextualExternalFunction
{
protected:
  MyExternalModule* theModule;

public:
  MyErrorReportingFunction1(MyExternalModule* aModule)
    : theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "func1"; }

  ItemSequence_t
  evaluate(const ExternalFunction::Arguments_t& args) const
  {
    // test raising an error with noqname (i.e. will be defaulted to FOER0000)
    throw DEFAULT_USER_EXCEPTION();
    return ItemSequence_t(0);
  }

};

class MyErrorReportingFunction2 : public NonContextualExternalFunction
{
protected:
  MyExternalModule* theModule;

public:
  MyErrorReportingFunction2(MyExternalModule* aModule)
    : theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "func2"; }

  ItemSequence_t
  evaluate(const ExternalFunction::Arguments_t& args) const
  {
    String lNamespace = "http://www.zorba-xquery.com/";
    String lLocalname = "myerror";
    Item lQName = theModule->getItemFactory()->createQName(
          lNamespace, lLocalname);
    throw USER_EXCEPTION(lQName);
    return ItemSequence_t(0);
  }

};

class MyErrorReportingFunction3 : public NonContextualExternalFunction
{
protected:
  MyExternalModule* theModule;

public:
  MyErrorReportingFunction3(MyExternalModule* aModule)
    : theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "func3"; }

  ItemSequence_t
  evaluate(const ExternalFunction::Arguments_t& args) const
  {
    // test raising an error with an empty qname (i.e. will be defaulted to FOER0000)
    // and a description
    Item lQName;
    throw USER_EXCEPTION(lQName, "test error description");
    return ItemSequence_t(0);
  }

};

class MyErrorReportingFunction4 : public NonContextualExternalFunction
{
protected:
  MyExternalModule* theModule;

public:
  MyErrorReportingFunction4(MyExternalModule* aModule)
    : theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "func4"; }

  ItemSequence_t
  evaluate(const ExternalFunction::Arguments_t& args) const
  {
    // test raising an error with a given qname, a description, and an error object
    String lNamespace = "http://www.zorba-xquery.com/";
    String lLocalname = "myerror";
    Item lQName = theModule->getItemFactory()->createQName(
          lNamespace, lLocalname);

    String lErrorObjectString = "error object";
    Item lErrorObject = theModule->getItemFactory()->createString(lErrorObjectString);
    ItemSequence_t tmp( new SingletonItemSequence(lErrorObject));
    throw USER_EXCEPTION(lQName, "test error description", tmp);
    return ItemSequence_t(0);
  }

};

ExternalFunction* MyExternalModule::getExternalFunction(const String& aLocalname)
{
  if (aLocalname == "func1") 
  {
    if (!theErrorFunc1) 
    {
      theErrorFunc1 = new MyErrorReportingFunction1(const_cast<MyExternalModule*>(this));
    } 
    return theErrorFunc1;
  }
  else if (aLocalname == "func2")
  {
    if (!theErrorFunc2) 
    {
      theErrorFunc2 = new MyErrorReportingFunction2(const_cast<MyExternalModule*>(this));
    } 
    return theErrorFunc2;
  }
  else if (aLocalname == "func3")
  {
    if (!theErrorFunc3) 
    {
      theErrorFunc3 = new MyErrorReportingFunction3(const_cast<MyExternalModule*>(this));
    } 
    return theErrorFunc3;
  }
  else if (aLocalname == "func4") 
  {
    if (!theErrorFunc4) 
    {
      theErrorFunc4 = new MyErrorReportingFunction4(const_cast<MyExternalModule*>(this));
    } 
    return theErrorFunc4;
  }
  return 0;
}

MyExternalModule::~MyExternalModule()
{
  delete theErrorFunc1;
  delete theErrorFunc2;
  delete theErrorFunc3;
  delete theErrorFunc4;
}

bool
external_function_errors_1(Zorba* aZorba)
{
  StaticContext_t sctx = aZorba->createStaticContext();

  MyExternalModule module(aZorba->getItemFactory());
  sctx->registerModule(&module);

  std::ostringstream queryText;
  queryText << "declare namespace foo=\"urn:foo\";" << std::endl
            << "declare function foo:func1() external;" << std::endl
            << "foo:func1()" << std::endl;
    
  XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 

  try 
  {
    std::cout << query << std::endl;
  }
  catch (ZorbaException& ex) 
  {
    std::cerr << ex << std::endl;
    if (!(ex.diagnostic() == err::FOER0000))
      return false;
    return true; // type exception expected
  }

  return false;
}

bool
external_function_errors_2(Zorba* aZorba)
{
  StaticContext_t sctx = aZorba->createStaticContext();

  MyExternalModule module(aZorba->getItemFactory());
  sctx->registerModule(&module);

  std::ostringstream queryText;
  queryText << "declare namespace foo=\"urn:foo\";" << std::endl
            << "declare function foo:func2() external;" << std::endl
            << "foo:func2()" << std::endl;
    
  XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 

  try 
  {
    std::cout << query << std::endl;
  }
  catch (ZorbaException& ex) 
  {
    std::cerr << ex << std::endl;
    return true; // type exception expected
  }

  return false;
}

bool
external_function_errors_3(Zorba* aZorba)
{
  StaticContext_t sctx = aZorba->createStaticContext();

  MyExternalModule module(aZorba->getItemFactory());
  sctx->registerModule(&module);

  std::ostringstream queryText;
  queryText << "declare namespace foo=\"urn:foo\";" "\n"
            << "declare function foo:func3() external;" "\n"
            << "try {" "\n"
            << "foo:func3()" "\n"
            << "} catch * ($errcode, $errdesc) {" "\n"
            << "  $errcode, $errdesc" "\n"
            << "}" "\n";
    
  XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 

  std::ostringstream lResult;
  lResult << query << std::endl;
  std::string lResultString = lResult.str();
  std::cout << lResultString << std::endl;

  return (lResultString.find("err:FOER0000 test error description") != std::string::npos);
}


bool
external_function_errors_4(Zorba* aZorba)
{
  StaticContext_t sctx = aZorba->createStaticContext();

  MyExternalModule module(aZorba->getItemFactory());
  sctx->registerModule(&module);

  std::ostringstream queryText;
  queryText << "declare namespace foo=\"urn:foo\";" "\n"
            << "declare function foo:func4() external;" "\n"
            << "try {" "\n"
            << "foo:func4()" "\n"
            << "} catch * ($errcode, $errdesc, $errval) {" "\n"
            << "  $errcode, $errdesc, $errval" "\n"
            << "}" "\n";
    
  XQuery_t query = aZorba->compileQuery(queryText.str(), sctx); 

  std::ostringstream lResult;
  lResult << query << std::endl;
  std::string lResultString = lResult.str();
  std::cout << lResultString << std::endl;

  return (lResultString.find("myerror test error description error object") != std::string::npos);
}


/***************************************************************************//**

********************************************************************************/
int
external_function_errors(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << std::endl  << "executing external function error test 1" << std::endl;
  res = external_function_errors_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing external function error test 2" << std::endl;
  res = external_function_errors_2(lZorba);
  if (!res) return 2; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing external function error test 3" << std::endl;
  res = external_function_errors_3(lZorba);
  if (!res) return 3; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing external function error test 4" << std::endl;
  res = external_function_errors_4(lZorba);
  if (!res) return 4; 
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
