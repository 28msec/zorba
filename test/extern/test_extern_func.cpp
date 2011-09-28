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
#include <map>
#include <fstream>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>
#include <zorba/external_module.h>
#include <zorba/function.h>
#include <zorba/empty_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/uri_resolvers.h>
#include <zorba/store_manager.h>
#include <zorba/singleton_item_sequence.h>

#include "system/properties.h"

using namespace zorba;

class MySimpleExternalFunction;

/*******************************************************************************
  External module with target namespace "urn:extern"
********************************************************************************/
class TestExternalModule : public ExternalModule
{
protected:
  class ltstr
  {
    public:
      bool operator()(const String& s1, const String& s2) const
      {
        return s1.compare(s2) < 0;
      }
  };

protected:
  static ItemFactory* theFactory;
  typedef std::map<String, ExternalFunction*, ltstr> FuncMap_t;
  FuncMap_t theFunctions;

public:
  TestExternalModule() { }

  virtual ~TestExternalModule()
  {
    for (FuncMap_t::const_iterator lIter = theFunctions.begin(); lIter != theFunctions.end(); ++lIter)
      delete lIter->second;
    theFunctions.clear();
  }

  String getURI() const { return "urn:extern"; }

  ExternalFunction* getExternalFunction(const String& aLocalname);

  static ItemFactory* getItemFactory()
  {
    if(!theFactory)
      theFactory = Zorba::getInstance(0)->getItemFactory();
    return theFactory;
  }
};

ItemFactory* TestExternalModule::theFactory = NULL;


/*******************************************************************************
  External function bar()
********************************************************************************/
class BarExternalFunction : public ContextualExternalFunction
{
protected:
  const TestExternalModule* theModule;

public:
  BarExternalFunction(const TestExternalModule* aModule)
    :
    theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "bar"; }

  ItemSequence_t evaluate(
        const ExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const
  {
    SingletonItemSequence* seq = new SingletonItemSequence(theModule->getItemFactory()->createString(sctx->getNamespaceURIByPrefix("ns2")));
    return ItemSequence_t(seq);
  }
};

/*******************************************************************************
  External function nondeterm()
********************************************************************************/
class NondetermExternalFunction : public ContextualExternalFunction
{
protected:
  static int counter;

protected:
  const TestExternalModule* theModule;

public:
  NondetermExternalFunction(const TestExternalModule* aModule)
    :
    theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "nondeterm"; }

  ItemSequence_t evaluate(const ExternalFunction::Arguments_t& args,
                          const StaticContext* sctx,
                          const DynamicContext* dctx) const
  {
    counter++;

    return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createInt(counter)));
  }
};

int NondetermExternalFunction::counter = 0;


/*******************************************************************************
  TestExternalModule::getExternalFunction
********************************************************************************/
ExternalFunction* TestExternalModule::getExternalFunction(const String& aLocalname)
{
  ExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (aLocalname == "bar") {
      lFunc = new BarExternalFunction(this);
    } else if (aLocalname == "nondeterm") {
      lFunc = new NondetermExternalFunction(this);
    }
  }
  return lFunc;
}


/*******************************************************************************

  Tests

********************************************************************************/
std::string load_file(const char* filename)
{
  // read the input file
  std::ifstream in(filename);
  if (!in.is_open())
  {
    std::cerr << "Error: could not open input file \"" << filename << "\"" << std::endl;
    return "";
  }

  char c;
  std::string str;
  while (in.get(c))
    str += c;

  return str;
}

int test1(const char* filename)
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  std::string str = load_file(filename);
  try
  {
    StaticContext_t sctx = lZorba->createStaticContext();
    TestExternalModule module;
    sctx->registerModule(&module);

    std::ostringstream queryText;
    queryText << str;

    XQuery_t query = lZorba->compileQuery(queryText.str(), sctx);
    std::cout << query << std::endl;

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 1;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);

  return 0;
}

int test2(const char* module_filename)
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  try
  {
    StaticContext_t sctx = lZorba->createStaticContext();
    TestExternalModule module;
    sctx->registerModule(&module);

    std::ostringstream queryText;
    queryText << "import module namespace extern = \"urn:extern\" at \"" << module_filename << "\";"
              << "extern:test() " << std::endl;

    XQuery_t query = lZorba->compileQuery(queryText.str(), sctx);
    std::cout << query << std::endl;

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 1;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);

  return 0;
}

int test_nondeterm(const char* filename)
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  zorba::Properties::load(0, NULL);

  std::string str = load_file(filename);
  try
  {
    StaticContext_t sctx = lZorba->createStaticContext();
    TestExternalModule module;
    sctx->registerModule(&module);

    std::ostringstream queryText;
    queryText << str;

    XQuery_t query = lZorba->compileQuery(queryText.str(), sctx);
    std::cout << query << std::endl;

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 1;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);

  return 0;
}


int main(int argc, char** argv)
{
  if (argc <= 1)
    return 0;

  if (strcmp (argv[1], "--test1") == 0 && argc>=3) {
    test1(argv[2]);
  } else if (strcmp (argv[1], "--test2") == 0 && argc>=3) {
    test2(argv[2]);
  } else if (strcmp (argv[1], "--nondeterm") == 0 && argc>=3) {
    test_nondeterm(argv[2]);
  }

  return 0;
}
