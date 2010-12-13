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

using namespace zorba;

/** Schema Resolver */
class ValidationTestSchemaURIResolverResult: public SchemaURIResolverResult
{
  public:
    virtual String getSchema() const { return theSchema; }

  protected:
    friend class ValidationTestSchemaURIResolver;
    String theSchema;
};

class ValidationTestSchemaURIResolver: public SchemaURIResolver
{
  public:
    virtual ~ValidationTestSchemaURIResolver(){}

    virtual std::auto_ptr<SchemaURIResolverResult>
    resolve(
      const Item& aURI,
      StaticContext* aStaticContext,
      std::vector<Item>& aLocationHints,
      String* aFileURI
    )
    {
      std::auto_ptr<ValidationTestSchemaURIResolverResult> lResult(
          new ValidationTestSchemaURIResolverResult());

      if(aURI.getStringValue() == "http://www.zorba-xquery.com/helloworld")
      {
        lResult->theSchema = "http://zorba-xquery.com/tutorials/helloworld.xsd";
        lResult->setError(URIResolverResult::UR_NOERROR);
      } else {
        lResult->setError(URIResolverResult::UR_XQST0057);
        std::stringstream lErrorStream;
        lErrorStream << "Schema could not be found " << aURI.getStringValue();
        lResult->setErrorDescription(lErrorStream.str());
      }

      return std::auto_ptr<SchemaURIResolverResult>(lResult.release());
    };
};

bool
item_validation(Zorba* aZorba)
{
  try {
    StaticContext_t lContext = aZorba->createStaticContext();

    ValidationTestSchemaURIResolver lResolver;

    lContext->addSchemaURIResolver(&lResolver);

    std::ostringstream lQueryStream;

    lQueryStream << "import schema namespace h = 'http://www.zorba-xquery.com/helloworld';"
                 << std::endl
                 << "<h:p>Hello World!</h:p>";

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

    ValidationTestSchemaURIResolver lResolver;

    lContext->addSchemaURIResolver(&lResolver);

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

    ValidationTestSchemaURIResolver lResolver;

    lContext->addSchemaURIResolver(&lResolver);

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

  if (!item_validation(lZorba)) {
    return 1;
  }

  if (!item_validation_with_error(lZorba)) {
    return 2;
  }

  if (!item_validation_with_error2(lZorba)) {
    return 2;
  }

  return 0;
}

