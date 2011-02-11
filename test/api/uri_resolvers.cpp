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

#include <zorba/uri_resolvers.h>

using namespace zorba;

#ifndef ZORBA_NO_FULL_TEXT
/** FullText Resolver */
class MyFullTextURIResolverResult: public FullTextURIResolverResult
{
  public:
    virtual String getResolvedFullText() const { return theFullText; }

  protected:
    friend class MyFullTextURIResolver;
    String theFullText;
};

class MyFullTextURIResolver: public FullTextURIResolver
{
  public:
    virtual ~MyFullTextURIResolver(){}

    virtual std::auto_ptr<FullTextURIResolverResult>
    resolve(
      const Item& aURI,
      StaticContext* aStaticContext)
    {
      std::auto_ptr<MyFullTextURIResolverResult> lResult(new MyFullTextURIResolverResult());
      if(aURI.getStringValue() == "http://bstore1.example.com/UsabilityThesaurus.xml")
      {
        lResult->theFullText = "default";
        lResult->setError(URIResolverResult::UR_NOERROR);
      } 
      return std::auto_ptr<FullTextURIResolverResult>(lResult.release());
    };
};

bool 
thesaurus_resolver_example_1(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  MyFullTextURIResolver lResolver;

  lContext->addThesaurusURIResolver(&lResolver);

  try {
    std::ostringstream lStr;
    lStr << "<books/>" << std::endl
      << "/books/book[./content contains text 'people' using" << std::endl
      << "thesaurus at 'http://bstore1.example.com/UsabilityThesaurus.xml'" << std::endl
      << "relationship 'NT' at most 2 levels]";

    XQuery_t lQuery = aZorba->compileQuery(lStr.str(), lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.getDescription() << std::endl;
    return false;
  }
  return true;
}
#endif

int 
uri_resolvers(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

#ifndef ZORBA_NO_FULL_TEXT
  std::cout << std::endl  << "executing thesaurus uri resolver example test 1" << std::endl;
  res = thesaurus_resolver_example_1(lZorba);
#endif

  if (!res) return 1; 
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
