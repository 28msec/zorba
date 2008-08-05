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
#include <simplestore/simplestore.h>

#include <zorba/uri_resolvers.h>

using namespace zorba;

/** Document Resolver */
class MyDocumentURIResolverResult : public DocumentURIResolverResult
{
  public:
    virtual Item
    getDocument() const
    {
      return theDocument;
    }

  protected:
    friend class MyDocumentURIResolver;
    Item theDocument;
};

class MyDocumentURIResolver : public  DocumentURIResolver
{
  public:
    virtual ~MyDocumentURIResolver() {}

    virtual std::auto_ptr<DocumentURIResolverResult>
    resolve(const Item& aURI, StaticContext* aStaticContext, XmlDataManager* aXmlDataManager)
    {
      std::auto_ptr<MyDocumentURIResolverResult> lResult(new MyDocumentURIResolverResult());
      if (aURI.getStringValue() == "mydoc.xml") {
        // we have only one document
        lResult->theDocument = aXmlDataManager->getDocument(aURI.getStringValue());
        lResult->setError(URIResolverResult::UR_NOERROR);
      } else {
        lResult->setError(URIResolverResult::UR_FODC0002);
        std::stringstream lErrorStream;
        lErrorStream << "Document could not be found " << aURI.getStringValue();
        lResult->setErrorDescription(lErrorStream.str());
      }
      return std::auto_ptr<DocumentURIResolverResult>(lResult.release()); 
    }
};

bool 
resolver_example_1(Zorba* aZorba)
{
  // load one document into the store
  {
    std::stringstream lDocStream;
    lDocStream << "<mydoc><a>1</a></mydoc>";

    XmlDataManager* lDataManager = aZorba->getXmlDataManager();

    lDataManager->loadDocument("mydoc.xml", lDocStream);
  }

  StaticContext_t lContext = aZorba->createStaticContext();

  MyDocumentURIResolver lResolver;

  lContext->setDocumentURIResolver(&lResolver);

  try {
    XQuery_t lQuery = aZorba->compileQuery("fn:doc('mydoc.xml')", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.getDescription() << std::endl;
  }


	return true;
}

/** Collection Resolver */
class MyCollectionURIResolverResult : public CollectionURIResolverResult
{
  public:
    virtual Collection_t
    getCollection() const
    {
      return theCollection;
    }

  protected:
    friend class MyCollectionURIResolver;
    Collection_t theCollection;
};

class MyCollectionURIResolver : public  CollectionURIResolver
{
  public:
    virtual ~MyCollectionURIResolver() {}

    virtual std::auto_ptr<CollectionURIResolverResult>
    resolve(const Item& aURI, StaticContext* aStaticContext, XmlDataManager* aXmlDataManager)
    {
      std::auto_ptr<MyCollectionURIResolverResult> lResult(new MyCollectionURIResolverResult());
      if (aURI.getStringValue() == "mycollection.xml") {
        // we have only one document
        lResult->theCollection = aXmlDataManager->getCollection(aURI.getStringValue());
        lResult->setError(URIResolverResult::UR_NOERROR);
      } else {
        lResult->setError(URIResolverResult::UR_FODC0002);
        std::stringstream lErrorStream;
        lErrorStream << "Collection could not be found " << aURI.getStringValue();
        lResult->setErrorDescription(lErrorStream.str());
      }
      return std::auto_ptr<CollectionURIResolverResult>(lResult.release()); 
    }
};

bool 
resolver_example_2(Zorba* aZorba)
{
  // load one document into the store
  {
    XmlDataManager* lDataManager = aZorba->getXmlDataManager();

    Collection_t lCol = lDataManager->createCollection("mycollection.xml");

    std::stringstream lDoc;
    lDoc << "<mydoc><b>1</b></mydoc>";
    lCol->addDocument(lDoc);
  }

  StaticContext_t lContext = aZorba->createStaticContext();

  MyCollectionURIResolver lResolver;

  lContext->setCollectionURIResolver(&lResolver);

  try {
    XQuery_t lQuery = aZorba->compileQuery("fn:collection('mycollection.xml')", lContext); 
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e.getDescription() << std::endl;
  }

	return true;
}

int 
uri_resolvers(int argc, char* argv[])
{
  simplestore::SimpleStore* lStore = simplestore::SimpleStoreManager::getStore();
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
  simplestore::SimpleStoreManager::shutdownStore(lStore);
  return 0;
}
