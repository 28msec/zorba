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

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/serialization_callback.h>
#include <zorba/uri_resolvers.h>
#include <zorba/zorba_exception.h>
#include <zorba/internal/unique_ptr.h>

using namespace zorba;

/** Schema Resolver */
class MySchemaURIMapper: public URIMapper
{
  public:

  virtual ~MySchemaURIMapper() {}

  virtual void mapURI(const zorba::String aUri,
    EntityData const* aEntityData,
    std::vector<zorba::String>& oUris) throw ()
  {
    if (aEntityData->getKind() != EntityData::SCHEMA) {
      return;
    }
    if(aUri == "http://zorba.io/helloworld") {
      oUris.push_back("http://zorbatest.28.io:8080/tutorial/helloworld.xsd");
    }
  }
};


static void
releaseStream(std::istream* aStream)
{
  delete aStream;
}

// Call this MyModuleURLResolver2 to avoid conflicts with
// MyModuleURLResolver in external_functions.cpp
class MyModuleURLResolver2 : public URLResolver
{
  public:
  virtual ~MyModuleURLResolver2() {}

  virtual Resource* resolveURL(
        const String& aUrl,
        EntityData const* aEntityData)
  {
    if (aEntityData->getKind() == EntityData::MODULE &&
      aUrl == "http://zorba.io/mymodule") 
    {
      // we have only one module
      std::unique_ptr<std::istream> lModule
          (new std::istringstream
           ("module namespace lm = 'http://zorba.io/mymodule'; "
            "declare function lm:foo() { 'foo' };"));
      return StreamResource::create(lModule.release(), &releaseStream);
    }
    else {
      return NULL;
    }
  }
};

// QQQ this is NOT really much of a test of the SerializationCallback feature
class URIResolverSerializationCallback : public SerializationCallback
{
  public:
    virtual URLResolver*
    getURLResolver(size_t /*i*/) const
    {
      return 0;
    }
};


bool 
resolver_example_1(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MyModuleURLResolver2 lResolver;

  lContext->registerURLResolver(&lResolver);

  try {
    XQuery_t lQuery = aZorba->compileQuery("import module namespace lm='http://zorba.io/mymodule'; lm:foo()", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  // test if an error is raised if a module uri resolver is not
  // available using the serialization callback
  try {
    XQuery_t lQuery = aZorba->compileQuery("import module namespace lm='http://zorba.io/mymodule'; lm:foo()", lContext); 

    std::stringstream lSerializedQuery;
    lQuery->saveExecutionPlan(lSerializedQuery);

    URIResolverSerializationCallback lCallback; 
    XQuery_t lQuery2 = aZorba->createQuery();
    lQuery2->loadExecutionPlan(lSerializedQuery, &lCallback);
    std::cout << lQuery2 << std::endl;
    return false;
  } catch (ZorbaException& e) {
    std::cerr << e.what() << std::endl;
    return true;
  }
}

bool 
resolver_example_2(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MySchemaURIMapper lMapper;

  lContext->registerURIMapper(&lMapper);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import schema namespace lm="
        "'http://zorba.io/helloworld'; "
        "validate{ <p>Hello World!</p> }", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  return true;
}

int 
uri_resolvers(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << std::endl  << "executing uri resolver example test 1" << std::endl;
  res = resolver_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << std::endl  << "executing uri resolver example test 2" << std::endl;
  res = resolver_example_2(lZorba);
  if (!res) return 2; 
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
