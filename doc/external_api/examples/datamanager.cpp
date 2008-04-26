/**
 *
 */
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>

using namespace zorba;

bool
datamanager_example_1(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    std::stringstream lInStream("<books><book>Book 1</book><book>Book 2</book></books>");

    aDataManager->loadDocument("books.xml", lInStream);

	  XQuery_t lQuery = aZorba->compileQuery("doc('books.xml')//book"); 

    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
datamanager_example_2(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    Collection_t lCollection = 
      aDataManager->createCollection("http://www.flworfound.org/collections/mybooks");

    std::cout << "URI "  << lCollection->getUri().getStringValue() << std::endl;

    for (int i = 0; i < 10; ++i) {
      std::stringstream lInStream;
      lInStream << "<book>Book " << i << "</book>";
      lCollection->addDocument(lInStream);
    }

	  XQuery_t lQuery = aZorba->compileQuery("for $i in fn:collection()[3] return $i//book"); 

    Item lDefaultCollection = aZorba->getItemFactory()
      ->createAnyURI("http://www.flworfound.org/collections/mybooks");

    // set the default collection for this query
    lQuery->getDynamicContext()->setDefaultCollection(lDefaultCollection);

    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
datamanager_example_3(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    Collection_t lCollection = 
      aDataManager->getCollection("http://www.flworfound.org/collections/mybooks");

    std::stringstream lInStream;
    lInStream << "<book>Book";
    lCollection->addDocument(lInStream);

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

bool
datamanager_example_4(Zorba* aZorba, XmlDataManager* aDataManager)
{
  try {
    // error if the collection already exists
    Collection_t lCollection = 
      aDataManager->createCollection("http://www.flworfound.org/collections/mybooks");

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

int 
datamanager(int argc, char* argv[])
{
#ifndef NDEBUG
  Zorba* lZorba = Zorba::getInstance();
  XmlDataManager* lDataManager = lZorba->getXmlDataManager();

  std::cout << "executing example 1" << std::endl;
	assert(datamanager_example_1(lZorba, lDataManager)); 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
	assert(datamanager_example_2(lZorba, lDataManager)); 
  std::cout << std::endl;
  
  std::cout << "executing example 3" << std::endl;
	assert(datamanager_example_3(lZorba, lDataManager)); 
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
	assert(datamanager_example_4(lZorba, lDataManager)); 
  std::cout << std::endl;
#endif

  return 0;
}
