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
#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/xquery_exception.h>
#include <zorba/uri_resolvers.h>
#include <zorba/diagnostic_list.h>

using namespace zorba;

static void streamReleaser(std::istream* aStream)
{
  delete aStream;
}

class MySchemaURIMapper : public URIMapper
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
    if(aUri == "http://www.zorba-xquery.com/helloworld") {
      oUris.push_back("http://zorbatest.28.io:8080/tutorial/helloworld.xsd");
    }
  }
};

class MyModuleURIMapper : public URIMapper
{
  public:

  virtual ~MyModuleURIMapper() {}

  virtual URIMapper::Kind mapperKind() throw() { return URIMapper::COMPONENT; }

  virtual void mapURI(const zorba::String aUri,
    EntityData const* aEntityData,
    std::vector<zorba::String>& oUris) throw ()
  {
    if (aEntityData->getKind() != EntityData::MODULE) {
      return;
    }
    if(aUri == "http://www.zorba-xquery.com/mymodule") {
      oUris.push_back("http://www.zorba-xquery.com/mymodule/mod1");
      oUris.push_back("http://www.zorba-xquery.com/mymodule/mod2");
    }
  }
};

class DenyAccessURIMapper : public URIMapper
{
  public:

  virtual ~DenyAccessURIMapper() {}

  virtual void mapURI(const zorba::String aUri,
    EntityData const*,
    std::vector<zorba::String>& oUris) throw ()
  {
    // Deny access to an URI that would otherwise work
    if(aUri == "http://zorbatest.28.io:8080/tutorial/helloworld.xsd" ||
       aUri == "http://zorba.io/modules/fetch" ||
       aUri == "http://expath.org/ns/file") {
      oUris.push_back(URIMapper::DENY_ACCESS);
    }
  }
};

class MyModuleURLResolver : public URLResolver
{
  public:
  virtual ~MyModuleURLResolver() {}

  virtual Resource* resolveURL(
        const String& aUrl,
        EntityData const* aEntityData)
  {
    static char mod1[] =
      "module namespace lm = 'http://www.zorba-xquery.com/mymodule'; "
      "declare function lm:foo1() { 'foo1' };";
    static char mod2[] =
      "module namespace lm = 'http://www.zorba-xquery.com/mymodule'; "
      "declare function lm:foo2() { 'foo2' };";

    // we have two library modules with the same namespace, that can
    // work together as components of a full module
    if (aEntityData->getKind() != EntityData::MODULE) {
      return NULL;
    }

    if (aUrl == "http://www.zorba-xquery.com/mymodule/mod1") {
      return StreamResource::create(new std::istringstream(mod1),
                                    &streamReleaser);
    }
    else if (aUrl == "http://www.zorba-xquery.com/mymodule/mod2") {
      return StreamResource::create(new std::istringstream(mod2),
                                    &streamReleaser);
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
        EntityData const* aEntityData)
  {
    // we have only one module
    if (aEntityData->getKind() == EntityData::MODULE &&
      aUrl == "http://www.zorba-xquery.com/foobar") 
    {
      return StreamResource::create
          (new std::istringstream
           ("module namespace lm = 'http://www.zorba-xquery.com/foobar'; "
            "declare function lm:foo() { 'foo' };"), &streamReleaser);
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
    if (e.diagnostic() == err::XQST0059) {
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
    return false;  }
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
    if (e.diagnostic() == err::XQST0059) {
      return true;
    }
  }

  return false;
}


bool test_deny_internal_module_access(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  DenyAccessURIMapper lMapper;
  lContext->registerURIMapper(&lMapper);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import module namespace fetch = "
        "'http://zorba.io/modules/fetch'; "
        "1 + 1", lContext);
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
    if (e.diagnostic() == zerr::ZXQP0029_URI_ACCESS_DENIED) {
      std::cout << "...the correct exception!" << std::endl;
      return true;
    }
  }
  return false;
}


bool test_deny_external_module_access(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  DenyAccessURIMapper lMapper;
  lContext->registerURIMapper(&lMapper);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import module namespace file = "
        "'http://expath.org/ns/file'; "
        "1 + 1", lContext);
    std::cout << lQuery << std::endl;
  } catch (XQueryException& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
    if (e.diagnostic() == zerr::ZXQP0029_URI_ACCESS_DENIED
        && e.has_source()
        && e.source_line() == 1) {
      std::cout << "...the correct exception!" << std::endl;
      return true;
    }
  } catch (ZorbaException& e) {
    std::cout << "Caught unexpected exception: " << e.what() << std::endl;
  }
  return false;
}

bool test_deny_schema_access(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  DenyAccessURIMapper lMapper;
  lContext->registerURIMapper(&lMapper);

  try {
    XQuery_t lQuery = aZorba->compileQuery
      ("import schema namespace lm="
        "'http://zorbatest.28.io:8080/tutorial/helloworld.xsd'; "
        "validate{ <p>Hello World!</p> }", lContext);
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
    if (e.diagnostic() == zerr::ZXQP0029_URI_ACCESS_DENIED) {
      std::cout << "...the correct exception!" << std::endl;
      return true;
    }
  }
  return false;
}

bool test_deny_access_import(Zorba* aZorba, char* aUriPath)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  DenyAccessURIMapper lMapper;
  lContext->registerURIMapper(&lMapper);

  try {
    // Import a schema which imports the denied URI - need to use StaticContext
    // to set the URI path for this. Merely importing this schema should fail.
    std::vector<zorba::String> lUriPath;
    lUriPath.push_back(aUriPath);
    lContext->setURIPath(lUriPath);
    XQuery_t lQuery = aZorba->compileQuery
      ("import schema namespace lm="
        "'http://www.zorba-xquery.com/import-hello'; "
        "1", lContext);
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
    if (e.diagnostic() == zerr::ZXQP0029_URI_ACCESS_DENIED) {
      std::cout << "...the correct exception!" << std::endl;
      return true;
    }
  }
  return false;
}

/**
 * Main test entry point
 */
int userdefined_uri_resolution(int argc, char* argv[])
{
  if (argc != 2) {
    std::cout << "Incorrect arguments passed to userdefined_uri_resolution()"
              << std::endl;
    return 1;
  }
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

  std::cout << "test_deny_internal_module_access" << std::endl;
  if (!test_deny_internal_module_access(lZorba)) {
    retval = 1;
    std::cout << " ... failed!" << std::endl;
  }

  std::cout << "test_deny_external_module_access" << std::endl;
  if (!test_deny_external_module_access(lZorba)) {
    retval = 1;
    std::cout << " ... failed!" << std::endl;
  }

  std::cout << "test_deny_schema_access" << std::endl;
  if (!test_deny_schema_access(lZorba)) {
    retval = 1;
    std::cout << " ... failed!" << std::endl;
  }

  std::cout << "test_deny_access_import" << std::endl;
  if (!test_deny_access_import(lZorba, argv[1])) {
    retval = 1;
    std::cout << " ... failed!" << std::endl;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return retval;
}
