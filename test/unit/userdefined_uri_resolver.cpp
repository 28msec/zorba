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

#include <zorba/uri_resolvers.h>

using namespace zorba;

class MyModuleURIResolverResult : public ModuleURIResolverResult
{
  friend class MyModuleURIResolver1;
  friend class MyModuleURIResolver2;

protected:
  std::istream             * theModule;
  std::vector<std::string>   theComponentURIs;

public:
  virtual std::istream* getModuleStream() const 
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


class MyModuleURIResolver1 : public ModuleURIResolver
{
public:
  virtual ~MyModuleURIResolver1() {}

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
      lResult->theModule = new std::istringstream("module namespace lm = 'http://www.zorba-xquery.com/mymodule'; declare function lm:foo() { 'foo' };");
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

class MyModuleURIResolver2 : public ModuleURIResolver
{
public:
  virtual ~MyModuleURIResolver2() {}

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

    if (aURI == "http://www.zorba-xquery.com/foobar") 
    {
      // we have only one module
      lResult->theModule = new std::istringstream("module namespace lm = 'http://www.zorba-xquery.com/foobar'; declare function lm:foo() { 'foo' };");
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

bool test_unresolved_uri(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MyModuleURIResolver1 lResolver1;
  MyModuleURIResolver2 lResolver2;

  lContext->addModuleURIResolver(&lResolver1);
  lContext->addModuleURIResolver(&lResolver2);

  try {
    XQuery_t lQuery = aZorba->compileQuery("import module namespace lm='http://www.zorba-xquery.com/foobar'; lm:foo()", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.getDescription() << std::endl;
    return false;
  }
  return true;
};

int userdefined_uri_resolver(int argc, char* argv[])
{
  void* lStore = StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore); 
  if(!test_unresolved_uri(lZorba)) {
    return 1;
  } 
  return 0;
};
