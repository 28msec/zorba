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
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string.h>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/uri_resolvers.h>
#include <zorba/iterator.h>
#include <zorba/zorba_exception.h>

using namespace zorba;

/** Schema Resolver */
class ValidationTestSchemaURIMapper: public URIMapper
{
public:

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

bool
item_validation(Zorba* aZorba)
{
  try {
    StaticContext_t lContext = aZorba->createStaticContext();

    ValidationTestSchemaURIMapper lMapper;

    lContext->registerURIMapper(&lMapper);

    std::ostringstream lQueryStream;

    lQueryStream << "import schema namespace h = 'http://www.zorba-xquery.com/helloworld';"
                 << std::endl
                 << "<p>Hello World!</p>";

    XQuery_t lQuery = aZorba->compileQuery(lQueryStream.str(), lContext);
  
    Iterator_t lIterator = lQuery->iterator();
    lIterator->open();

    Item lItem;
    while (lIterator->next(lItem)) {
      Item lValidatedItem;
      if (!lContext->validate(lItem, lValidatedItem)) {
        return false;
      }
    }
    lIterator->close();

  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}

bool
item_validation_with_error(Zorba* aZorba)
{
  try {
    StaticContext_t lContext = aZorba->createStaticContext();

    ValidationTestSchemaURIMapper lMapper;

    lContext->registerURIMapper(&lMapper);

    std::ostringstream lQueryStream;

    lQueryStream << "import schema namespace h = 'http://www.zorba-xquery.com/helloworld';"
                 << std::endl
                 << "3";

    XQuery_t lQuery = aZorba->compileQuery(lQueryStream.str(), lContext);
  
    Iterator_t lIterator = lQuery->iterator();
    lIterator->open();

    Item lItem;
    while (lIterator->next(lItem)) {
      Item lValidatedItem;
      if (!lContext->validate(lItem, lValidatedItem)) {
        return true; // atomic types can not be validated
      }
    }
    lIterator->close();

  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return false;
  }
  return false;
}

bool
item_validation_with_error2(Zorba* aZorba)
{
  try {
    StaticContext_t lContext = aZorba->createStaticContext();

    ValidationTestSchemaURIMapper lMapper;

    lContext->registerURIMapper(&lMapper);

    std::ostringstream lQueryStream;

    lQueryStream << "import schema namespace h = 'http://www.zorba-xquery.com/helloworld';"
                 << std::endl
                 << "<h:foo><bar/></h:foo>";

    XQuery_t lQuery = aZorba->compileQuery(lQueryStream.str(), lContext);
  
    Iterator_t lIterator = lQuery->iterator();
    lIterator->open();

    Item lItem;
    while (lIterator->next(lItem)) {
      Item lValidatedItem;
      if (!lContext->validate(lItem, lValidatedItem)) {
        return false;
      }
    }
    lIterator->close();

  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return true;
  }
  return false;
}

int
validate(int argc, char* argv[]) 
{
  Zorba* lZorba = Zorba::getInstance(zorba::StoreManager::getStore());

  int retval = 0;

  std::cout << "item_validation()" << std::endl;
  if (!item_validation(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }

  std::cout << "item_validation_with_error()" << std::endl;
  if (!item_validation_with_error(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }

  std::cout << "item_validatio_nwith_error2()" << std::endl;
  if (!item_validation_with_error2(lZorba)) {
    retval = 1;
    std::cout << "  ...failed!" << std::endl;
  }

  return retval;
}

