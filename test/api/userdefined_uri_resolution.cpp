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

#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/uri_resolvers.h>
#include <zorba/error_list.h>

using namespace zorba;

class MySchemaURIMapper : public URIMapper
{
  public:

  virtual ~MySchemaURIMapper() {}

  virtual URIMapper::Kind mapperKind() throw() { return URIMapper::CANDIDATE; }

  virtual void mapURI(const zorba::String aUri,
    Resource::EntityType aEntityType,
    std::vector<zorba::String>& oUris) throw ()
  {
    if (aEntityType != Resource::SCHEMA) {
      return;
    }
    if(aUri == "http://www.zorba-xquery.com/helloworld") {
      oUris.push_back("http://zorba-xquery.com/tutorials/helloworld.xsd");
    }
  }
};

class MyModuleURIMapper : public URIMapper
{
  public:

  virtual ~MyModuleURIMapper() {}

  virtual URIMapper::Kind mapperKind() throw() { return URIMapper::COMPONENT; }

  virtual void mapURI(const zorba::String aUri,
    Resource::EntityType aEntityType,
    std::vector<zorba::String>& oUris) throw ()
  {
    if (aEntityType != Resource::MODULE) {
      return;
    }
    if(aUri == "http://www.zorba-xquery.com/mymodule") {
      oUris.push_back("http://www.zorba-xquery.com/mymodule/mod1");
      oUris.push_back("http://www.zorba-xquery.com/mymodule/mod2");
    }
  }
};

class MyModuleURLResolver : public URLResolver
{
  public:
  virtual ~MyModuleURLResolver() {}

  virtual Resource* resolveURL(
        const String& aUrl,
        Resource::EntityType aEntityType)
  {
    static char mod1[] =
      "module namespace lm = 'http://www.zorba-xquery.com/mymodule'; "
      "declare function lm:foo1() { 'foo1' };";
    static char mod2[] =
      "module namespace lm = 'http://www.zorba-xquery.com/mymodule'; "
      "declare function lm:foo2() { 'foo2' };";

    // we have two library modules with the same namespace, that can
    // work together as components of a full module
    if (aEntityType != Resource::MODULE) {
      return NULL;
    }

    if (aUrl == "http://www.zorba-xquery.com/mymodule/mod1") {
      return new StreamResource
        (std::auto_ptr<std::istream>(new std::istringstream(mod1)));
    }
    else if (aUrl == "http://www.zorba-xquery.com/mymodule/mod2") {
      return new StreamResource
        (std::auto_ptr<std::istream>(new std::istringstream(mod2)));
    }
    else {
      return NULL;
    }
  }
};

class FoobarModuleURLResolver : public URLResolver
{
  public:
  virtual ~FoobarModuleURLResolver() {}

  virtual Resource* resolveURL(
        const String& aUrl,
        Resource::EntityType aEntityType)
  {
    // we have only one module
    if (aEntityType == Resource::MODULE &&
      aUrl == "http://www.zorba-xquery.com/foobar") 
    {
      return new StreamResource
        (std::auto_ptr<std::istream>(
          new std::istringstream
          ("module namespace lm = 'http://www.zorba-xquery.com/foobar'; "
            "declare function lm:foo() { 'foo' };")));
    }
    else {
      return NULL;
    }
  }
};

bool test_module_uri(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  FoobarModuleURLResolver lResolver;

  lContext->registerURLResolver(&lResolver);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import module namespace lm='http://www.zorba-xquery.com/foobar'; "
        "lm:foo()", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

bool test_unresolved_module_uri(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  FoobarModuleURLResolver lResolver;

  lContext->registerURLResolver(&lResolver);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import module namespace lm='http://www.zorba-xquery.com/foobar3'; "
        "lm:foo()", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
    if (e.error() == err::XQST0059) {
      return true;
    }
  }
  return false;
}

bool test_component_module_uri(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MyModuleURIMapper lMapper;
  MyModuleURLResolver lResolver;

  lContext->registerURIMapper(&lMapper);
  lContext->registerURLResolver(&lResolver);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import module namespace my='http://www.zorba-xquery.com/mymodule'; "
        "my:foo1(), my:foo2()", lContext);
    std::cout << lQuery << std::endl;
  }
  catch (ZorbaException& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

bool test_schema_uri(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MySchemaURIMapper lMapper;

  lContext->registerURIMapper(&lMapper);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import schema namespace lm="
        "'http://www.zorba-xquery.com/helloworld'; "
        "validate{ <p>Hello World!</p> }", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  return true;
}

bool test_unresolved_schema_uri(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MySchemaURIMapper lMapper;

  lContext->registerURIMapper(&lMapper);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import schema namespace lm="
        "'http://www.zorba-xquery.com/schemas/helloworld3'; "
        "validate{ <p>Hello World!</p> }", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
    if (e.error() == err::XQST0059) {
      return true;
    }
  }

  return false;
}


#ifndef ZORBA_NO_FULL_TEXT
/** FullText Resolver */
class MyFullTextURIMapper: public URIMapper
{
  public:
  virtual ~MyFullTextURIMapper(){}

  virtual URIMapper::Kind mapperKind() throw() { return URIMapper::CANDIDATE; }

  virtual void mapURI(const zorba::String aUri,
    Resource::EntityType aEntityType,
    std::vector<zorba::String>& oUris) throw ()
  {
    if (aEntityType != Resource::THESAURUS) {
      return;
    }
    if(aUri == "http://bstore1.example.com/UsabilityThesaurus.xml") {
      oUris.push_back("default");
    }
  }
};

bool 
thesaurus_resolver_example_1(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MyFullTextURIMapper lMapper;

  lContext->registerURIMapper(&lMapper);

  try {
    std::ostringstream lStr;
    lStr << "<books/>" << std::endl
      << "/books/book[./content contains text 'people' using" << std::endl
      << "thesaurus at 'http://bstore1.example.com/UsabilityThesaurus.xml'" << std::endl
      << "relationship 'NT' at most 2 levels]";

    XQuery_t lQuery = aZorba->compileQuery(lStr.str(), lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}
#endif

/**
 * Main test entry point
 */
int userdefined_uri_resolution(int argc, char* argv[])
{
  void* lStore = StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore); 

  int retval = 0;

  std::cout << "test_module_uri" << std::endl;
  if(!test_module_uri(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }

  std::cout << "test_unresolved_module_uri" << std::endl;
  if(!test_unresolved_module_uri(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }

  std::cout << "test_component_module_uri" << std::endl;
  if (!test_component_module_uri(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }

  std::cout << "test_schema_uri" << std::endl;
  if(!test_schema_uri(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }

  std::cout << "test_unresolved_schema_uri" << std::endl;
  if(!test_unresolved_schema_uri(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }

#ifndef ZORBA_NO_FULL_TEXT
  std::cout << "executing thesaurus uri resolver example test 1" << std::endl;
  if(!thesaurus_resolver_example_1(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }
#endif

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return retval;
}
